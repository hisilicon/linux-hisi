/*
 * ACPI GSI IRQ layer
 *
 * Copyright (C) 2015 ARM Ltd.
 * Author: Lorenzo Pieralisi <lorenzo.pieralisi@arm.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <linux/acpi.h>
#include <linux/irq.h>
#include <linux/irqdomain.h>
#include <linux/of.h>

enum acpi_irq_model_id acpi_irq_model;

static struct fwnode_handle *acpi_gsi_domain_id;

/**
 * acpi_gsi_to_irq() - Retrieve the linux irq number for a given GSI
 * @gsi: GSI IRQ number to map
 * @irq: pointer where linux IRQ number is stored
 *
 * irq location updated with irq value [>0 on success, 0 on failure]
 *
 * Returns: linux IRQ number on success (>0)
 *          -EINVAL on failure
 */
int acpi_gsi_to_irq(u32 gsi, unsigned int *irq)
{
	struct irq_domain *d = irq_find_matching_fwnode(acpi_gsi_domain_id,
							DOMAIN_BUS_ANY);

	*irq = irq_find_mapping(d, gsi);
	/*
	 * *irq == 0 means no mapping, that should
	 * be reported as a failure
	 */
	return (*irq > 0) ? *irq : -EINVAL;
}
EXPORT_SYMBOL_GPL(acpi_gsi_to_irq);

/**
 * acpi_register_gsi() - Map a GSI to a linux IRQ number
 * @dev: device for which IRQ has to be mapped
 * @gsi: GSI IRQ number
 * @trigger: trigger type of the GSI number to be mapped
 * @polarity: polarity of the GSI to be mapped
 *
 * Returns: a valid linux IRQ number on success
 *          -EINVAL on failure
 */
int acpi_register_gsi(struct device *dev, u32 gsi, int trigger,
		      int polarity)
{
	struct irq_fwspec fwspec;

	if (WARN_ON(!acpi_gsi_domain_id)) {
		pr_warn("GSI: No registered irqchip, giving up\n");
		return -EINVAL;
	}

	fwspec.fwnode = acpi_gsi_domain_id;
	fwspec.param[0] = gsi;
	fwspec.param[1] = acpi_dev_get_irq_type(trigger, polarity);
	fwspec.param_count = 2;

	return irq_create_fwspec_mapping(&fwspec);
}
EXPORT_SYMBOL_GPL(acpi_register_gsi);

/**
 * acpi_unregister_gsi() - Free a GSI<->linux IRQ number mapping
 * @gsi: GSI IRQ number
 */
void acpi_unregister_gsi(u32 gsi)
{
	struct irq_domain *d = irq_find_matching_fwnode(acpi_gsi_domain_id,
							DOMAIN_BUS_ANY);
	int irq = irq_find_mapping(d, gsi);

	irq_dispose_mapping(irq);
}
EXPORT_SYMBOL_GPL(acpi_unregister_gsi);

/**
 * acpi_get_irq_source_fwhandle() - Retrieve the fwhandle of the given
 *                                  acpi_resource_source which is used
 *                                  as an IRQ domain id
 * @source: acpi_resource_source to use for the lookup
 *
 * Returns: The appropriate IRQ fwhandle domain id
 *          NULL on failure
 */
static struct fwnode_handle *
acpi_get_irq_source_fwhandle(const struct acpi_resource_source *source)
{
	struct fwnode_handle *result;
	struct acpi_device *device;
	acpi_handle handle;
	acpi_status status;

	if (!source->string_length)
		return acpi_gsi_domain_id;

	status = acpi_get_handle(NULL, source->string_ptr, &handle);
	if (ACPI_FAILURE(status)) {
		pr_warn("Could not find handle for %s\n", source->string_ptr);
		return NULL;
	}

	device = acpi_bus_get_acpi_device(handle);
	if (!device) {
		pr_warn("Could not get device for %s\n", source->string_ptr);
		return NULL;
	}

	result = &device->fwnode;
	acpi_bus_put_acpi_device(device);

	return result;
}

/**
 * Context for the resource walk used to lookup IRQ resources.
 */
struct acpi_irq_parse_one_ctx {
	int rc;
	unsigned int index;
	unsigned long *res_flags;
	struct irq_fwspec *fwspec;
};

/**
 * acpi_irq_parse_one_match - Handle a matching IRQ resource
 */
static inline void acpi_irq_parse_one_match(struct fwnode_handle *fwnode,
					    u32 hwirq, u8 triggering,
					    u8 polarity, u8 shareable,
					    struct acpi_irq_parse_one_ctx *ctx)
{
	ctx->rc = 0;
	*ctx->res_flags = acpi_dev_irq_flags(triggering, polarity, shareable);
	ctx->fwspec->fwnode = fwnode;
	ctx->fwspec->param[0] = hwirq;
	ctx->fwspec->param[1] = acpi_dev_get_irq_type(triggering, polarity);
	ctx->fwspec->param_count = 2;
}

/**
 * acpi_irq_parse_one_cb - Handle the given resource
 * @ares: resource to handle
 * @context: context for the walk, contains the lookup index and references
 *           to the flags and fwspec where the result is returned
 *
 * This is called by acpi_walk_resources passing each resource returned by
 * the _CRS method. We only inspect IRQ resources. Since IRQ resources
 * might contain multiple interrupts we check if the index is within this
 * one's interrupt array, otherwise we subtract the current resource IRQ
 * count from the lookup index to prepare for the next resource.
 * Once a match is found we call acpi_irq_parse_one_match to populate
 * the result and end the walk by returning AE_CTRL_TERMINATE.
 *
 * Return AE_OK if the walk should continue, AE_CTRL_TERMINATE if a matching
 * IRQ resource was found.
 */
static acpi_status acpi_irq_parse_one_cb(struct acpi_resource *ares,
					 void *context)
{
	struct acpi_irq_parse_one_ctx *ctx = context;
	struct acpi_resource_irq *irq;
	struct acpi_resource_extended_irq *eirq;
	struct fwnode_handle *fwnode;

	switch (ares->type) {
	case ACPI_RESOURCE_TYPE_IRQ:
		irq = &ares->data.irq;
		if (ctx->index >= irq->interrupt_count) {
			ctx->index -= irq->interrupt_count;
			return AE_OK;
		}
		fwnode = acpi_gsi_domain_id;
		acpi_irq_parse_one_match(fwnode, irq->interrupts[ctx->index],
					 irq->triggering, irq->polarity,
					 irq->sharable, ctx);
		return AE_CTRL_TERMINATE;
	case ACPI_RESOURCE_TYPE_EXTENDED_IRQ:
		eirq = &ares->data.extended_irq;
		if (ctx->index >= eirq->interrupt_count) {
			ctx->index -= eirq->interrupt_count;
			return AE_OK;
		}
		fwnode = acpi_get_irq_source_fwhandle(&eirq->resource_source);
		acpi_irq_parse_one_match(fwnode, eirq->interrupts[ctx->index],
					 eirq->triggering, eirq->polarity,
					 eirq->sharable, ctx);
		return AE_CTRL_TERMINATE;
	}

	return AE_OK;
}

/**
 * acpi_irq_parse_one - Resolve an interrupt for a device
 * @handle: the device whose interrupt is to be resolved
 * @index: index of the interrupt to resolve
 * @fwspec: structure irq_fwspec filled by this function
 * @flags: resource flags filled by this function
 *
 * This function resolves an interrupt for a device by walking its CRS resources
 * to find the appropriate ACPI IRQ resource and populating the given structure
 * which can be used to retrieve a Linux IRQ number.
 *
 * Returns the result stored in ctx.rc by the callback, or -EINVAL if the given
 * index is out of range.
 */
static int acpi_irq_parse_one(acpi_handle handle, unsigned int index,
			      struct irq_fwspec *fwspec, unsigned long *flags)
{
	struct acpi_irq_parse_one_ctx ctx = { -EINVAL, index, flags, fwspec };
	acpi_status status;

	status = acpi_walk_resources(handle, METHOD_NAME__CRS,
				     acpi_irq_parse_one_cb, &ctx);
	if (ACPI_FAILURE(status))
		return -EINVAL;
	return ctx.rc;
}

/**
 * acpi_irq_get - Look for the ACPI IRQ resource with the given index and
 *                use it to initialize the given Linux IRQ resource.
 * @handle ACPI device handle
 * @index  ACPI IRQ resource index to lookup
 * @res    Linux IRQ resource to initialize
 *
 * Return: 0 on success
 *         -EINVAL if an error occurs
 *         -EPROBE_DEFER if the IRQ lookup/conversion failed
 */
int acpi_irq_get(acpi_handle handle, unsigned int index, struct resource *res)
{
	int rc;
	struct irq_fwspec fwspec;
	struct irq_domain *domain;
	unsigned long flags;

	rc = acpi_irq_parse_one(handle, index, &fwspec, &flags);
	if (rc)
		return rc;

	domain = irq_find_matching_fwnode(fwspec.fwnode, DOMAIN_BUS_ANY);
	if (!domain)
		return -EPROBE_DEFER;

	rc = irq_create_fwspec_mapping(&fwspec);
	if (rc <= 0)
		return -EINVAL;

	res->start = rc;
	res->end = rc;
	res->flags = flags;

	return 0;
}
EXPORT_SYMBOL_GPL(acpi_irq_get);

/**
 * acpi_set_irq_model - Setup the GSI irqdomain information
 * @model: the value assigned to acpi_irq_model
 * @fwnode: the irq_domain identifier for mapping and looking up
 *          GSI interrupts
 */
void __init acpi_set_irq_model(enum acpi_irq_model_id model,
			       struct fwnode_handle *fwnode)
{
	acpi_irq_model = model;
	acpi_gsi_domain_id = fwnode;
}
