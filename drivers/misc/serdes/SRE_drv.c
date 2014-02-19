#include "SRE_drv.h"
#include "SRE_memmap.h"
#include "SRE_serdes.h"
#include "SRE_phydrv.h"
#include <asm/io.h>
#include <linux/ioport.h>
#include <uapi/asm-generic/errno-base.h>
#include <asm/string.h>

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

UINT32 g_uwPrintkLevel = MCSS_PRINTK_INFO;

/* 寄存器映射空间 */
// 1
#define MCSS_BMU_SPACE_NAME             "mcss bmu space"
#define MCSS_BMU_REG_BASE               SRE_BMU_REG_BASE_ADDR
#define MCSS_BMU_REG_SIZE               0x400000
// 2
#define MCSS_PPE_TNL_SPACE_NAME         "mcss ppe tnl space"
#define MCSS_PPE_TNL_REG_BASE           SRE_PPE_TNL_BASE
#define MCSS_PPE_TNL_REG_SIZE           0x90000
// 3
#define MCSS_XGE_SPACE_NAME             "mcss xge space"
#define MCSS_XGE_REG_BASE               SRE_XGE_BASE
#define MCSS_XGE_REG_SIZE               0x10000
// 4
#define MCSS_PPE_COMMON_SPACE_NAME      "mcss ppe common space"
#define MCSS_PPE_COMMON_REG_BASE        SRE_PPE_COMMON_BASE
#define MCSS_PPE_COMMON_REG_SIZE        0x10000
// 5
#define MCSS_SERDES1_SPACE_NAME         "mcss serdes1 space"
#define MCSS_SERDES1_REG_BASE           SERDES1_BASE_ADDR
#define MCSS_SERDES1_REG_SIZE           0x10000
// 6
#define MCSS_MDIO_SPACE_NAME            "mcss mdio space"
#define MCSS_MDIO_REG_BASE              MDIO_BASE_ADDR
#define MCSS_MDIO_REG_SIZE              0x2000
// 7
#define MCSS_SERDES0_LOW_SPACE_NAME     "mcss serdes0 low space"
#define MCSS_SERDES0_LOW_REG_BASE       SERDES0_LOW_BASE_ADDR
#define MCSS_SERDES0_LOW_REG_SIZE       0x1000
// 8
#define MCSS_SERDES0_HIGHT_SPACE_NAME   "mcss serdes0 hight space"
#define MCSS_SERDES0_HIGHT_REG_BASE     SERDES0_HIGHT_BASE_ADDR
#define MCSS_SERDES0_HIGHT_REG_SIZE     0x1000
// 9
#define MCSS_IOCTRL0_SPACE_NAME         "mcss ioctrl0 space"
#define MCSS_IOCTRL0_REG_BASE           IOCTRL0_BASE_ADDR
#define MCSS_IOCTRL0_REG_SIZE           0x1000
// 10
#define MCSS_POE_SPACE_NAME             "mcss poe space"
#define MCSS_POE_REG_BASE               SRE_POE_BASE
#define MCSS_POE_REG_SIZE               0x800000
// 11
#if 0
#define MCSS_POE_NORMAL_SPACE_NAME      "mcss poe normal space"
#define MCSS_POE_NORMAL_REG_BASE        SRE_POE_NORMAL_BASE
#define MCSS_POE_NORMAL_REG_SIZE        0x800000
#endif
// 12
#define MCSS_SYS_SPACE_NAME             "mcss sys space"
#define MCSS_SYS_REG_BASE               SRE_SYS_REG_BASEADDR
#define MCSS_SYS_REG_SIZE               0x100000
// 13
#define MCSS_TM_SPACE_NAME              "mcss tm space"
#define MCSS_TM_REG_BASE                SRE_TM_BASE
#define MCSS_TM_REG_SIZE                0x800000
// 14
#define MCSS_GPIO_SPACE_NAME            "mcss gpio space"
#define MCSS_GPIO_REG_BASE              SRE_GPIO_REG_BASE_ADDR
#define MCSS_GPIO_REG_SIZE              0x5000
// 15
#define MCSS_SPI_SPACE_NAME             "mcss spi space"
#define MCSS_SPI_REG_BASE               SPI_REG_BASE_ADDR
#define MCSS_SPI_REG_SIZE               0x2000
// 16
#define MCSS_IOCONFIG_SPACE_NAME        "mcss ioconfig space"
#define MCSS_IOCONFIG_REG_BASE          IOCONFIG_REG_BASE_ADDR
#define MCSS_IOCONFIG_REG_SIZE          0x1000
// 17
#define MCSS_SERDES3_SPACE_NAME         "mcss serdes3 space"
#define MCSS_SERDES3_REG_BASE           SERDES3_BASE_ADDR
#define MCSS_SERDES3_REG_SIZE           0x1000
// 18
#define MCSS_IOCTRL1_SPACE_NAME         "mcss ioctrl1 space"
#define MCSS_IOCTRL1_REG_BASE           IOCTRL1_BASE_ADDR
#define MCSS_IOCTRL1_REG_SIZE           0x1000
// 19
#define MCSS_SERDES2_SPACE_NAME         "mcss serdes2 space"
#define MCSS_SERDES2_REG_BASE           SERDES2_BASE_ADDR
#define MCSS_SERDES2_REG_SIZE           0x10000
// 20
#define MCSS_SRIO_SPACE_NAME            "mcss srio space"
#define MCSS_SRIO_REG_BASE              OS_SRE_SRIO_BASE_ADDR
#define MCSS_SRIO_REG_SIZE              0x1000
// 21
#define MCSS_MPE_SPACE_NAME            "mcss mpe space"
#define MCSS_MPE_REG_BASE              OS_SRE_MPE_BASE_ADDR
#define MCSS_MPE_REG_SIZE              0x1000

#define MCSS_REG_SPACE_NUM  9//10//20//21
typedef struct
{
    UINT32 uwRegBase;
    UINT32 uwSize;
    char*  name;
} MCSS_REG_ADDR_MAP_S;

MCSS_REG_ADDR_MAP_S g_astRegAddrMap[MCSS_REG_SPACE_NUM] =
{
#if 0
    {MCSS_BMU_REG_BASE, MCSS_BMU_REG_SIZE, MCSS_BMU_SPACE_NAME},
    {MCSS_PPE_TNL_REG_BASE, MCSS_PPE_TNL_REG_SIZE, MCSS_PPE_TNL_SPACE_NAME},
    {MCSS_XGE_REG_BASE, MCSS_XGE_REG_SIZE, MCSS_XGE_SPACE_NAME},
    {MCSS_PPE_COMMON_REG_BASE, MCSS_PPE_COMMON_REG_SIZE, MCSS_PPE_COMMON_SPACE_NAME},
#endif
    {MCSS_SERDES1_REG_BASE, MCSS_SERDES1_REG_SIZE, MCSS_SERDES1_SPACE_NAME},
#if 0
    {MCSS_MDIO_REG_BASE, MCSS_MDIO_REG_SIZE, MCSS_MDIO_SPACE_NAME},
#endif
    {MCSS_SERDES0_LOW_REG_BASE, MCSS_SERDES0_LOW_REG_SIZE, MCSS_SERDES0_LOW_SPACE_NAME},
    {MCSS_SERDES0_HIGHT_REG_BASE, MCSS_SERDES0_HIGHT_REG_SIZE, MCSS_SERDES0_HIGHT_SPACE_NAME},
    {MCSS_IOCTRL0_REG_BASE, MCSS_IOCTRL0_REG_SIZE, MCSS_IOCTRL0_SPACE_NAME},
#if 0
    {MCSS_POE_REG_BASE, MCSS_POE_REG_SIZE, MCSS_POE_SPACE_NAME},
    {MCSS_POE_NORMAL_REG_BASE, MCSS_POE_NORMAL_REG_SIZE, MCSS_POE_NORMAL_SPACE_NAME},
#endif
    {MCSS_SYS_REG_BASE, MCSS_SYS_REG_SIZE, MCSS_SYS_SPACE_NAME},
#if 0
    {MCSS_TM_REG_BASE, MCSS_TM_REG_SIZE, MCSS_TM_SPACE_NAME},
    {MCSS_GPIO_REG_BASE, MCSS_GPIO_REG_SIZE, MCSS_GPIO_SPACE_NAME},
    {MCSS_SPI_REG_BASE, MCSS_SPI_REG_SIZE, MCSS_SPI_SPACE_NAME},
    {MCSS_IOCONFIG_REG_BASE, MCSS_IOCONFIG_REG_SIZE, MCSS_IOCONFIG_SPACE_NAME},
#endif
    {MCSS_SERDES3_REG_BASE, MCSS_SERDES3_REG_SIZE, MCSS_SERDES3_SPACE_NAME},
    {MCSS_IOCTRL1_REG_BASE, MCSS_IOCTRL1_REG_SIZE, MCSS_IOCTRL1_SPACE_NAME},
    {MCSS_SERDES2_REG_BASE, MCSS_SERDES2_REG_SIZE, MCSS_SERDES2_SPACE_NAME},
    {MCSS_SRIO_REG_BASE, MCSS_SRIO_REG_SIZE, MCSS_SRIO_SPACE_NAME},
#if 0
    {MCSS_MPE_REG_BASE, MCSS_MPE_REG_SIZE, MCSS_MPE_SPACE_NAME},
#endif
};

UINT32 g_uwRegSpaceNum = 0; /* 当前已映射的寄存器空间数量 */
UINT32 g_uwDdrSpaceNum = 0; /* 当前已映射的DDR空间数量 */

MCSS_ADDR_MAP_ST g_astRegMap[MCSS_REG_SPACE_MAX_NUM];
MCSS_ADDR_MAP_ST g_astDdrMap[MCSS_DDR_SPACE_MAX_NUM];

struct mcss_mana
{
    void __iomem    *reg_iomem[MCSS_REG_SPACE_MAX_NUM];
    struct resource *reg_ioarea[MCSS_REG_SPACE_MAX_NUM];
    void __iomem    *ddr_iomem[MCSS_DDR_SPACE_MAX_NUM];
    struct resource *ddr_ioarea[MCSS_DDR_SPACE_MAX_NUM];
};
static struct  mcss_mana mcss_manager;

INT32 mcss_add_reg_space(UINT32 phy_addr, UINT32 size, const char* name)
{
    INT32 rc = 0;

    if (MCSS_REG_SPACE_MAX_NUM <= g_uwRegSpaceNum)
    {
		printk(": mcss_add_reg_space, reg space full, can not add\n");
        SRE_printf(": mcss_add_reg_space, reg space full, can not add\n");
        return OS_FAIL;
    }

    /* 申请寄存器 io内存 */
    mcss_manager.reg_iomem[g_uwRegSpaceNum] = request_mem_region(phy_addr, size, name);
    if (!mcss_manager.reg_iomem[g_uwRegSpaceNum])
    {
		printk(": Reg region(%d) busy, addr[%#x],size[%d]\n", g_uwRegSpaceNum, phy_addr, size);
        rc = -EBUSY;
        //goto out;//检查资源是否被占用
    }

    mcss_manager.reg_ioarea[g_uwRegSpaceNum] = ioremap(phy_addr, size);
    if (!mcss_manager.reg_ioarea[g_uwRegSpaceNum])
    {
        printk(": could not ioremap MCSS reg%d,addr[%#x],size[%d]\n", g_uwRegSpaceNum, phy_addr, size);
        rc = -ENXIO;
        goto out_mem_region;
    }

    g_astRegMap[g_uwRegSpaceNum].phy_addr = phy_addr;
    g_astRegMap[g_uwRegSpaceNum].size = size;
    g_astRegMap[g_uwRegSpaceNum].vir_addr = mcss_manager.reg_ioarea[g_uwRegSpaceNum];
    g_uwRegSpaceNum++;
    goto out;

out_mem_region:
    release_resource(mcss_manager.reg_iomem[g_uwRegSpaceNum]);
out:
    return rc;
}

void mcss_clear_reg_space(void)
{
    UINT32 loop;

    for (loop = 0; loop < g_uwRegSpaceNum; loop++)
    {
        iounmap(mcss_manager.reg_ioarea[loop]);
        release_resource(mcss_manager.reg_iomem[loop]);
    }
    g_uwRegSpaceNum = 0;
}

INT32 mcss_add_ddr_space(UINT32 phy_addr, UINT32 size, const char* name)
{
    INT32 rc = 0;

    if (MCSS_DDR_SPACE_MAX_NUM <= g_uwDdrSpaceNum)
    {
        SRE_printf(": mcss_add_ddr_space, reg space full, can not add\n");
        return OS_FAIL;
    }

    /* 申请寄存器 io内存 */
    mcss_manager.ddr_iomem[g_uwDdrSpaceNum] = request_mem_region(phy_addr, size, name);
    if (!mcss_manager.ddr_iomem[g_uwDdrSpaceNum])
    {
        SRE_printf(": Ddr region(%d) busy, addr[%#x],size[%d]\n", g_uwDdrSpaceNum, phy_addr, size);
        rc = -EBUSY;
        goto out;
    }

    mcss_manager.ddr_ioarea[g_uwDdrSpaceNum] = ioremap(phy_addr, size);
    if (!mcss_manager.ddr_ioarea[g_uwDdrSpaceNum])
    {
        SRE_printf(": could not ioremap MCSS ddr%d,addr[%#x],size[%d]\n", g_uwDdrSpaceNum, phy_addr, size);
        rc = -ENXIO;
        goto out_mem_region;
    }

    g_astDdrMap[g_uwDdrSpaceNum].phy_addr = phy_addr;
    g_astDdrMap[g_uwDdrSpaceNum].size = size;
    g_astDdrMap[g_uwDdrSpaceNum].vir_addr = mcss_manager.ddr_ioarea[g_uwDdrSpaceNum];
    g_uwDdrSpaceNum++;
    goto out;

out_mem_region:
    release_resource(mcss_manager.ddr_iomem[g_uwDdrSpaceNum]);
out:
    return rc;
}

void mcss_clear_ddr_space(void)
{
    UINT32 loop;

    for (loop = 0; loop < g_uwDdrSpaceNum; loop++)
    {
        iounmap(mcss_manager.ddr_ioarea[loop]);
        release_resource(mcss_manager.ddr_iomem[loop]);
    }
    g_uwDdrSpaceNum = 0;
}


UINT32 SRE_GetCoreID(void)
{
    UINT32 uwTmp;
    __asm volatile(
                "MRC p15, 0, %0, c0, c0, 5"
                    :"=&r"(uwTmp));

    return uwTmp & 0x1f;//core < 2^5=32
}

void SRE_DelayCycle(UINT32 cycle)
{
    volatile UINT32 uwLoop = cycle;
    while (uwLoop > 0)
    {
        uwLoop--;
    }
}
void MCSS_DumpMem(U8 *addr, UINT32 size)
{
    int i;
    for (i=0; i< size; i++)
    {
        MC_PRINTK_WARNING(" 0x%02x", addr[i]);
        if (15 == i%16)
        {
            MC_PRINTK_WARNING("\n");
        }
    }
    MC_PRINTK_WARNING("\n");
}

void MCSS_SetPrintkLevel(UINT32 printlevel)
{
    g_uwPrintkLevel = printlevel;
}

void MCSS_PrintkBuildTime(void)
{
#define	MC_MOD_VERSION "Euler Test"
    printk("mcss_mod version: %s, build time: %s %s\n", MC_MOD_VERSION, __DATE__, __TIME__);
}

UINT32 SRE_IoMemInit(VOID)
{
    int rc = 0;
	int loop = 0;

    /* step1: mmap寄存器 */
    memset(&mcss_manager, 0, sizeof(struct mcss_mana));

    /* 申请寄存器 io内存 */
    for (loop = 0; loop < MCSS_REG_SPACE_NUM; loop++)
    {
        OS_DBG_PRINT("mcss_add_reg_space %#x, %d, %s\n", g_astRegAddrMap[loop].uwRegBase, g_astRegAddrMap[loop].uwSize, g_astRegAddrMap[loop].name);
        rc = mcss_add_reg_space(g_astRegAddrMap[loop].uwRegBase, g_astRegAddrMap[loop].uwSize, g_astRegAddrMap[loop].name);
        if (rc)
        {
            printk(KERN_ERR "mcss_add_reg_space fail, %#x, %d, %s\n", g_astRegAddrMap[loop].uwRegBase, g_astRegAddrMap[loop].uwSize, g_astRegAddrMap[loop].name);
			mcss_clear_reg_space();
        }
    }
	return rc;
}

/*#include <linux/module.h>
#include <linux/kernel.h>
#include "SRE_serdes.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Maroleo");
MODULE_DESCRIPTION("Maroleo's serdes Module");
*/

int serdes_init(void)
{
    unsigned int ret = OS_SUCCESS;
	
	ret = SRE_IoMemInit();

    if (OS_SUCCESS != ret)
    {
        SRE_printf( "SRE_IoMemInit failed at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return -1;
    }
    
/*
	//comment here, replaced by drivers/net/ethernet/hisilicon/hip04_mdio.c
	ret = SRE_StdPhySet(0); 
    if (OS_SUCCESS != ret)
	{
        SRE_printf( "SRE_StdPhySet failed at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
		mcss_clear_reg_space();
		return -1;
	}
*/
	ret =  SRE_SerdesInit();
    if (OS_SUCCESS != ret)
	{
        SRE_printf( "SRE_SerdesInit failed at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
		mcss_clear_reg_space();
		return -1;
	}
	
    return ret;
}

void serdes_exit(void)
{
	mcss_clear_reg_space();
}


subsys_initcall(serdes_init);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */



