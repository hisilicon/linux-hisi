/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
  文 件 名   : mc_iomap_hisilicon.h
  版 本 号   : 初稿
  作    者   : c00111586
  生成日期   : 2009年4月21日
  最近修改   :
  功能描述   : 头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2009年4月21日
    作    者   : c00111586
    修改内容   : 创建文件

******************************************************************************/

#ifndef _SRE_MEMMAP_H
#define _SRE_MEMMAP_H

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/* 头文件包含 ----------------------------------*/

/* 宏定义 --------------------------------------*/
/*获取主频的寄存器地址  */
#if 0  /*h64632*/
#define MC_CLK_REG_ADDR         0xA0000018UL
#else
#define MC_CLK_REG_ADDR         0x13e00100
#endif /*h64632*/

/*SYSTEM CONTROL REGISTER  1380地址，650禁用*/
#define SRE_SYSCTL_REG_BASE_ADDR    (0x20000000 + 0x80000000)

/*poe gmac and so on buffer & cacheable control*/
#define SRE_SC_PERCTRL49_REG              (SRE_SYSCTL_REG_BASE_ADDR + 0x0F0)

/*ar_shaping*/
#define SRE_SC_PERCTRL74_REG              (SRE_SYSCTL_REG_BASE_ADDR + 0x154)

/*SYSTEM CPU VERSION REGISTER*/
#define SRE_SYSCTL_REG_CPU_VER0          (SRE_SYSCTL_REG_BASE_ADDR + 0xEE0)
#define SRE_SYSCTL_REG_CPU_VER1          (SRE_SYSCTL_REG_BASE_ADDR + 0xEE4)
#define SRE_SYSCTL_REG_CPU_VER2          (SRE_SYSCTL_REG_BASE_ADDR + 0xEE8)
#define SRE_SYSCTL_REG_CPU_VER3         (SRE_SYSCTL_REG_BASE_ADDR + 0xEEC)

/*SEC Request*/
#define MC_SEC1_REQ_REG              (SRE_SYSCTL_REG_BASE_ADDR + 0x048)
#define MC_SEC0_REQ_REG              (SRE_SYSCTL_REG_BASE_ADDR + 0x04C)

/* 各个加速模块复位寄存器 */
#define SRE_SC_PERCTRL6_REG           (SRE_SYSCTL_REG_BASE_ADDR + 0x044)
#define SRE_SC_PERCTRL7_REG           (SRE_SYSCTL_REG_BASE_ADDR + 0x048)
#define SRE_SC_PERCTRL8_REG           (SRE_SYSCTL_REG_BASE_ADDR + 0x04C)

/*HDCP Request*/
#define SRE_HDCP_REQ_REG              (SRE_SYSCTL_REG_BASE_ADDR + 0x04C)

/*HDCP Clock*/
#define SRE_HDCP_CLK_ENABLE_REG              (SRE_SYSCTL_REG_BASE_ADDR + 0x400)
#define SRE_HDCP_CLK_DISABLE_REG             (SRE_SYSCTL_REG_BASE_ADDR + 0x404)
#define SRE_HDCP_CLK_STATUS_REG              (SRE_SYSCTL_REG_BASE_ADDR + 0x408)
/*7x3 Master port base*/
/*hi1380 asic*/
#define MC_7x3MASTER_REG_BASE_ADDR     (0x18040000 + 0x80000000)

//******************************************************************************

/* BMU_REG 模块寄存器基地址 */
#if 0     /* z00202052 */
#define SRE_BMU_REG_BASE_ADDR            (0x11400000UL)            /*BMU寄存器基地址*/
#else
#define SRE_BMU_REG_BASE_ADDR            (0xe1400000UL)            /*BMU寄存器基地址*/
#endif    /* z00202052 */


/******************************************************************************/
/*                      BMU BMU_REG 寄存器定义                                */
/******************************************************************************/
#define SRE_BMU_ADDR_P_0_REG                       (SRE_BMU_REG_BASE_ADDR + 0x0)                 /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_1_REG                       (SRE_BMU_REG_BASE_ADDR + 0x4)                 /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_2_REG                       (SRE_BMU_REG_BASE_ADDR + 0x8)                 /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_3_REG                       (SRE_BMU_REG_BASE_ADDR + 0xC)                 /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_4_REG                       (SRE_BMU_REG_BASE_ADDR + 0x10)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_5_REG                       (SRE_BMU_REG_BASE_ADDR + 0x14)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_6_REG                       (SRE_BMU_REG_BASE_ADDR + 0x18)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_7_REG                       (SRE_BMU_REG_BASE_ADDR + 0x1C)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_8_REG                       (SRE_BMU_REG_BASE_ADDR + 0x20)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_9_REG                       (SRE_BMU_REG_BASE_ADDR + 0x24)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_10_REG                      (SRE_BMU_REG_BASE_ADDR + 0x28)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_11_REG                      (SRE_BMU_REG_BASE_ADDR + 0x2C)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_12_REG                      (SRE_BMU_REG_BASE_ADDR + 0x30)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_13_REG                      (SRE_BMU_REG_BASE_ADDR + 0x34)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_14_REG                      (SRE_BMU_REG_BASE_ADDR + 0x38)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_15_REG                      (SRE_BMU_REG_BASE_ADDR + 0x3C)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_16_REG                      (SRE_BMU_REG_BASE_ADDR + 0x40)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_17_REG                      (SRE_BMU_REG_BASE_ADDR + 0x44)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_18_REG                      (SRE_BMU_REG_BASE_ADDR + 0x48)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_19_REG                      (SRE_BMU_REG_BASE_ADDR + 0x4C)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_20_REG                      (SRE_BMU_REG_BASE_ADDR + 0x50)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_21_REG                      (SRE_BMU_REG_BASE_ADDR + 0x54)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_22_REG                      (SRE_BMU_REG_BASE_ADDR + 0x58)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_23_REG                      (SRE_BMU_REG_BASE_ADDR + 0x5C)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_24_REG                      (SRE_BMU_REG_BASE_ADDR + 0x60)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_25_REG                      (SRE_BMU_REG_BASE_ADDR + 0x64)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_26_REG                      (SRE_BMU_REG_BASE_ADDR + 0x68)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_27_REG                      (SRE_BMU_REG_BASE_ADDR + 0x6C)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_28_REG                      (SRE_BMU_REG_BASE_ADDR + 0x70)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_29_REG                      (SRE_BMU_REG_BASE_ADDR + 0x74)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_30_REG                      (SRE_BMU_REG_BASE_ADDR + 0x78)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_ADDR_P_31_REG                      (SRE_BMU_REG_BASE_ADDR + 0x7C)                /* BMU模块各pool的读写接口地址。 */
#define SRE_BMU_SIZE_P_0_REG                       (SRE_BMU_REG_BASE_ADDR + 0x80)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_1_REG                       (SRE_BMU_REG_BASE_ADDR + 0x84)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_2_REG                       (SRE_BMU_REG_BASE_ADDR + 0x88)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_3_REG                       (SRE_BMU_REG_BASE_ADDR + 0x8C)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_4_REG                       (SRE_BMU_REG_BASE_ADDR + 0x90)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_5_REG                       (SRE_BMU_REG_BASE_ADDR + 0x94)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_6_REG                       (SRE_BMU_REG_BASE_ADDR + 0x98)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_7_REG                       (SRE_BMU_REG_BASE_ADDR + 0x9C)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_8_REG                       (SRE_BMU_REG_BASE_ADDR + 0xA0)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_9_REG                       (SRE_BMU_REG_BASE_ADDR + 0xA4)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_10_REG                      (SRE_BMU_REG_BASE_ADDR + 0xA8)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_11_REG                      (SRE_BMU_REG_BASE_ADDR + 0xAC)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_12_REG                      (SRE_BMU_REG_BASE_ADDR + 0xB0)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_13_REG                      (SRE_BMU_REG_BASE_ADDR + 0xB4)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_14_REG                      (SRE_BMU_REG_BASE_ADDR + 0xB8)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_15_REG                      (SRE_BMU_REG_BASE_ADDR + 0xBC)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_16_REG                      (SRE_BMU_REG_BASE_ADDR + 0xC0)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_17_REG                      (SRE_BMU_REG_BASE_ADDR + 0xC4)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_18_REG                      (SRE_BMU_REG_BASE_ADDR + 0xC8)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_19_REG                      (SRE_BMU_REG_BASE_ADDR + 0xCC)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_20_REG                      (SRE_BMU_REG_BASE_ADDR + 0xD0)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_21_REG                      (SRE_BMU_REG_BASE_ADDR + 0xD4)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_22_REG                      (SRE_BMU_REG_BASE_ADDR + 0xD8)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_23_REG                      (SRE_BMU_REG_BASE_ADDR + 0xDC)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_24_REG                      (SRE_BMU_REG_BASE_ADDR + 0xE0)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_25_REG                      (SRE_BMU_REG_BASE_ADDR + 0xE4)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_26_REG                      (SRE_BMU_REG_BASE_ADDR + 0xE8)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_27_REG                      (SRE_BMU_REG_BASE_ADDR + 0xEC)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_28_REG                      (SRE_BMU_REG_BASE_ADDR + 0xF0)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_29_REG                      (SRE_BMU_REG_BASE_ADDR + 0xF4)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_30_REG                      (SRE_BMU_REG_BASE_ADDR + 0xF8)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_SIZE_P_31_REG                      (SRE_BMU_REG_BASE_ADDR + 0xFC)                /* BMU pool的内部SRAM 大小。 */
#define SRE_BMU_WL_P_0_REG                         (SRE_BMU_REG_BASE_ADDR + 0x100)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_1_REG                         (SRE_BMU_REG_BASE_ADDR + 0x104)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_2_REG                         (SRE_BMU_REG_BASE_ADDR + 0x108)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_3_REG                         (SRE_BMU_REG_BASE_ADDR + 0x10C)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_4_REG                         (SRE_BMU_REG_BASE_ADDR + 0x110)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_5_REG                         (SRE_BMU_REG_BASE_ADDR + 0x114)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_6_REG                         (SRE_BMU_REG_BASE_ADDR + 0x118)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_7_REG                         (SRE_BMU_REG_BASE_ADDR + 0x11C)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_8_REG                         (SRE_BMU_REG_BASE_ADDR + 0x120)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_9_REG                         (SRE_BMU_REG_BASE_ADDR + 0x124)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_10_REG                        (SRE_BMU_REG_BASE_ADDR + 0x128)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_11_REG                        (SRE_BMU_REG_BASE_ADDR + 0x12C)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_12_REG                        (SRE_BMU_REG_BASE_ADDR + 0x130)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_13_REG                        (SRE_BMU_REG_BASE_ADDR + 0x134)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_14_REG                        (SRE_BMU_REG_BASE_ADDR + 0x138)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_15_REG                        (SRE_BMU_REG_BASE_ADDR + 0x13C)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_16_REG                        (SRE_BMU_REG_BASE_ADDR + 0x140)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_17_REG                        (SRE_BMU_REG_BASE_ADDR + 0x144)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_18_REG                        (SRE_BMU_REG_BASE_ADDR + 0x148)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_19_REG                        (SRE_BMU_REG_BASE_ADDR + 0x14C)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_20_REG                        (SRE_BMU_REG_BASE_ADDR + 0x150)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_21_REG                        (SRE_BMU_REG_BASE_ADDR + 0x154)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_22_REG                        (SRE_BMU_REG_BASE_ADDR + 0x158)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_23_REG                        (SRE_BMU_REG_BASE_ADDR + 0x15C)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_24_REG                        (SRE_BMU_REG_BASE_ADDR + 0x160)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_25_REG                        (SRE_BMU_REG_BASE_ADDR + 0x164)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_26_REG                        (SRE_BMU_REG_BASE_ADDR + 0x168)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_27_REG                        (SRE_BMU_REG_BASE_ADDR + 0x16C)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_28_REG                        (SRE_BMU_REG_BASE_ADDR + 0x170)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_29_REG                        (SRE_BMU_REG_BASE_ADDR + 0x174)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_30_REG                        (SRE_BMU_REG_BASE_ADDR + 0x178)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_WL_P_31_REG                        (SRE_BMU_REG_BASE_ADDR + 0x17C)               /* BMU pool的内部SRAM 向外部L2/DRAM 的溢出/回读水线。 */
#define SRE_BMU_CTRL_REG                           (SRE_BMU_REG_BASE_ADDR + 0x180)               /* BMU 全局控制寄存器。 */
#define SRE_BMU_POOL_RDEN_REG                      (SRE_BMU_REG_BASE_ADDR + 0x184)               /* BMU模块pool 读写使能保护位。 */
#define SRE_BMU_INT_STS_REG                        (SRE_BMU_REG_BASE_ADDR + 0x188)               /* BMU 中断状态寄存器。 */
#define SRE_BMU_INT_EN_REG                         (SRE_BMU_REG_BASE_ADDR + 0x18C)               /* BMU 中断使能寄存器。 */
#define SRE_BMU_UNALIGN_ERR_PID_REG                (SRE_BMU_REG_BASE_ADDR + 0x190)               /* BMU 非对齐错误Poo ID 寄存器。 */
#define SRE_BMU_ECC_1B_CNT_REG                     (SRE_BMU_REG_BASE_ADDR + 0x194)               /* BMU SRAM ecc 1bit错误统计计数器 */
#define SRE_BMU_CPU_ADD_STATUS_L_REG               (SRE_BMU_REG_BASE_ADDR + 0x198)               /* CPU ADD BMU状态寄存器0~31 虚拟CPU */
#define SRE_BMU_CPU_ADD_STATUS_H_REG               (SRE_BMU_REG_BASE_ADDR + 0x19C)               /* CPU ADD BMU状态寄存器32~63 虚拟CPU */
#define SRE_BMU_CPU_ADD_ERROR_DATA0_REG            (SRE_BMU_REG_BASE_ADDR + 0x1A0)               /* CPU ADD 错误的数据寄存器地位 */
#define SRE_BMU_CPU_ADD_ERROR_DATA1_REG            (SRE_BMU_REG_BASE_ADDR + 0x1A4)               /* CPU ADD 错误的数据寄存器高位 */
#define SRE_BMU_BITMAP_ECC_1B_CNT_REG              (SRE_BMU_REG_BASE_ADDR + 0x1A8)               /* BMU bitmap SRAM ecc 1bit错误统计计数器 */
#define SRE_BMU_PTRNUM_P_0_REG                     (SRE_BMU_REG_BASE_ADDR + 0x200)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_1_REG                     (SRE_BMU_REG_BASE_ADDR + 0x204)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_2_REG                     (SRE_BMU_REG_BASE_ADDR + 0x208)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_3_REG                     (SRE_BMU_REG_BASE_ADDR + 0x20C)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_4_REG                     (SRE_BMU_REG_BASE_ADDR + 0x210)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_5_REG                     (SRE_BMU_REG_BASE_ADDR + 0x214)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_6_REG                     (SRE_BMU_REG_BASE_ADDR + 0x218)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_7_REG                     (SRE_BMU_REG_BASE_ADDR + 0x21C)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_8_REG                     (SRE_BMU_REG_BASE_ADDR + 0x220)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_9_REG                     (SRE_BMU_REG_BASE_ADDR + 0x224)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_10_REG                    (SRE_BMU_REG_BASE_ADDR + 0x228)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_11_REG                    (SRE_BMU_REG_BASE_ADDR + 0x22C)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_12_REG                    (SRE_BMU_REG_BASE_ADDR + 0x230)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_13_REG                    (SRE_BMU_REG_BASE_ADDR + 0x234)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_14_REG                    (SRE_BMU_REG_BASE_ADDR + 0x238)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_15_REG                    (SRE_BMU_REG_BASE_ADDR + 0x23C)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_16_REG                    (SRE_BMU_REG_BASE_ADDR + 0x240)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_17_REG                    (SRE_BMU_REG_BASE_ADDR + 0x244)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_18_REG                    (SRE_BMU_REG_BASE_ADDR + 0x248)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_19_REG                    (SRE_BMU_REG_BASE_ADDR + 0x24C)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_20_REG                    (SRE_BMU_REG_BASE_ADDR + 0x250)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_21_REG                    (SRE_BMU_REG_BASE_ADDR + 0x254)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_22_REG                    (SRE_BMU_REG_BASE_ADDR + 0x258)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_23_REG                    (SRE_BMU_REG_BASE_ADDR + 0x25C)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_24_REG                    (SRE_BMU_REG_BASE_ADDR + 0x260)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_25_REG                    (SRE_BMU_REG_BASE_ADDR + 0x264)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_26_REG                    (SRE_BMU_REG_BASE_ADDR + 0x268)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_27_REG                    (SRE_BMU_REG_BASE_ADDR + 0x26C)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_28_REG                    (SRE_BMU_REG_BASE_ADDR + 0x270)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_29_REG                    (SRE_BMU_REG_BASE_ADDR + 0x274)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_30_REG                    (SRE_BMU_REG_BASE_ADDR + 0x278)               /* BMU pool的地址指针个数。 */
#define SRE_BMU_PTRNUM_P_31_REG                    (SRE_BMU_REG_BASE_ADDR + 0x27C)               /* BMU pool的地址指针个数。 */

#define SRE_BMU_P0_OUT_ADDR_REG                    (SRE_BMU_REG_BASE_ADDR + 0x280)
#define SRE_BMU_P0_OUT_CUR_ADDR_REG                (SRE_BMU_REG_BASE_ADDR + 0x300)
#define SRE_BMU_P0_OUT_LEN_REG                     (SRE_BMU_REG_BASE_ADDR + 0x380)
#define SRE_BMU_BOUND_ERR_ADDR_REG                 (SRE_BMU_REG_BASE_ADDR + 0x400)
#define SRE_BMU_IN_EMTPY_STA_ADDR_REG              (SRE_BMU_REG_BASE_ADDR + 0x404)
#define SRE_BMU_IN_FULL_STA_ADDR_REG               (SRE_BMU_REG_BASE_ADDR + 0x408)
#define SRE_BMU_ALL_EMTPY_STA_ADDR_REG             (SRE_BMU_REG_BASE_ADDR + 0x40c)
#define SRE_BMU_ALL_FULL_STA_ADDR_REG              (SRE_BMU_REG_BASE_ADDR + 0x410)
#define SRE_BMU_ALMST_FULL_STA_ADDR_REG            (SRE_BMU_REG_BASE_ADDR + 0x414)


#define SRE_BMU_BUS_ERR_PID_REG                    (SRE_BMU_REG_BASE_ADDR + 0x418)               /* 当前总线出现错误的pool ID */
#define SRE_BMU_PERR_SRAM_ADDR_REG                 (SRE_BMU_REG_BASE_ADDR + 0x41C)               /* 当前SRAMECC校验2bit错误指针 */
#define SRE_BMU_PERR_LDST_ADDR_REG                 (SRE_BMU_REG_BASE_ADDR + 0x420)

#define SRE_BMU_ECC_PID_REG                        (SRE_BMU_REG_BASE_ADDR + 0x424)               /* Peri错误pool ID */
#define SRE_BMU_TEST_REG                           (SRE_BMU_REG_BASE_ADDR + 0x428)               /* BMU内部状态寄存器 */
#define SRE_BMU_CFG_DLY_REG                        (SRE_BMU_REG_BASE_ADDR + 0x42C)               /* BMU快满后读/写延迟寄存器 */
#define SRE_BMU_VMID_CFG_REG                       (SRE_BMU_REG_BASE_ADDR + 0x430)               /* BMU Master访问MDDRC的VMID的配置 */
#define SRE_BMU_BOUND_ERR_STS_REG                  (SRE_BMU_REG_BASE_ADDR + 0x434)               /* BMU 释放缓存地址边界出错状态寄存器 */
#define SRE_BMU_BOUND_P_0_REG                      (SRE_BMU_REG_BASE_ADDR + 0x438)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_1_REG                      (SRE_BMU_REG_BASE_ADDR + 0x43C)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_2_REG                      (SRE_BMU_REG_BASE_ADDR + 0x440)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_3_REG                      (SRE_BMU_REG_BASE_ADDR + 0x444)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_4_REG                      (SRE_BMU_REG_BASE_ADDR + 0x448)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_5_REG                      (SRE_BMU_REG_BASE_ADDR + 0x44C)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_6_REG                      (SRE_BMU_REG_BASE_ADDR + 0x450)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_7_REG                      (SRE_BMU_REG_BASE_ADDR + 0x454)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_8_REG                      (SRE_BMU_REG_BASE_ADDR + 0x458)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_9_REG                      (SRE_BMU_REG_BASE_ADDR + 0x45C)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_10_REG                     (SRE_BMU_REG_BASE_ADDR + 0x460)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_11_REG                     (SRE_BMU_REG_BASE_ADDR + 0x464)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_12_REG                     (SRE_BMU_REG_BASE_ADDR + 0x468)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_13_REG                     (SRE_BMU_REG_BASE_ADDR + 0x46C)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_14_REG                     (SRE_BMU_REG_BASE_ADDR + 0x470)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_15_REG                     (SRE_BMU_REG_BASE_ADDR + 0x474)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_16_REG                     (SRE_BMU_REG_BASE_ADDR + 0x478)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_17_REG                     (SRE_BMU_REG_BASE_ADDR + 0x47C)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_18_REG                     (SRE_BMU_REG_BASE_ADDR + 0x480)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_19_REG                     (SRE_BMU_REG_BASE_ADDR + 0x484)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_20_REG                     (SRE_BMU_REG_BASE_ADDR + 0x488)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_21_REG                     (SRE_BMU_REG_BASE_ADDR + 0x48C)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_22_REG                     (SRE_BMU_REG_BASE_ADDR + 0x490)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_23_REG                     (SRE_BMU_REG_BASE_ADDR + 0x494)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_24_REG                     (SRE_BMU_REG_BASE_ADDR + 0x498)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_25_REG                     (SRE_BMU_REG_BASE_ADDR + 0x49C)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_26_REG                     (SRE_BMU_REG_BASE_ADDR + 0x4A0)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_27_REG                     (SRE_BMU_REG_BASE_ADDR + 0x4A4)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_28_REG                     (SRE_BMU_REG_BASE_ADDR + 0x4A8)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_29_REG                     (SRE_BMU_REG_BASE_ADDR + 0x4AC)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_30_REG                     (SRE_BMU_REG_BASE_ADDR + 0x4B0)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BOUND_P_31_REG                     (SRE_BMU_REG_BASE_ADDR + 0x4B4)               /* BMU Pool释放缓存地址边界寄存器 */
#define SRE_BMU_BITMAP_BADDR_P0_REG                (SRE_BMU_REG_BASE_ADDR + 0x500)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P1_REG                (SRE_BMU_REG_BASE_ADDR + 0x504)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P2_REG                (SRE_BMU_REG_BASE_ADDR + 0x508)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P3_REG                (SRE_BMU_REG_BASE_ADDR + 0x50C)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P4_REG                (SRE_BMU_REG_BASE_ADDR + 0x510)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P5_REG                (SRE_BMU_REG_BASE_ADDR + 0x514)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P6_REG                (SRE_BMU_REG_BASE_ADDR + 0x518)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P7_REG                (SRE_BMU_REG_BASE_ADDR + 0x51C)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P8_REG                (SRE_BMU_REG_BASE_ADDR + 0x520)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P9_REG                (SRE_BMU_REG_BASE_ADDR + 0x524)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P10_REG               (SRE_BMU_REG_BASE_ADDR + 0x528)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P11_REG               (SRE_BMU_REG_BASE_ADDR + 0x52C)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P12_REG               (SRE_BMU_REG_BASE_ADDR + 0x530)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P13_REG               (SRE_BMU_REG_BASE_ADDR + 0x534)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P14_REG               (SRE_BMU_REG_BASE_ADDR + 0x538)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P15_REG               (SRE_BMU_REG_BASE_ADDR + 0x53C)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P16_REG               (SRE_BMU_REG_BASE_ADDR + 0x540)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P17_REG               (SRE_BMU_REG_BASE_ADDR + 0x544)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P18_REG               (SRE_BMU_REG_BASE_ADDR + 0x548)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P19_REG               (SRE_BMU_REG_BASE_ADDR + 0x54C)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P20_REG               (SRE_BMU_REG_BASE_ADDR + 0x550)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P21_REG               (SRE_BMU_REG_BASE_ADDR + 0x554)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P22_REG               (SRE_BMU_REG_BASE_ADDR + 0x558)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P23_REG               (SRE_BMU_REG_BASE_ADDR + 0x55C)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P24_REG               (SRE_BMU_REG_BASE_ADDR + 0x560)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P25_REG               (SRE_BMU_REG_BASE_ADDR + 0x564)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P26_REG               (SRE_BMU_REG_BASE_ADDR + 0x568)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P27_REG               (SRE_BMU_REG_BASE_ADDR + 0x56C)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P28_REG               (SRE_BMU_REG_BASE_ADDR + 0x570)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P29_REG               (SRE_BMU_REG_BASE_ADDR + 0x574)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P30_REG               (SRE_BMU_REG_BASE_ADDR + 0x578)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_BADDR_P31_REG               (SRE_BMU_REG_BASE_ADDR + 0x57C)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_WIDTH_REG                   (SRE_BMU_REG_BASE_ADDR + 0x580)               /* BMU bitmap的SRAM中各个Pool的起始地址 */
#define SRE_BMU_BITMAP_ST_ERR_INFO_REG             (SRE_BMU_REG_BASE_ADDR + 0x584)               /* BMU bitmap重复释放错误状态寄存器 */
#define SRE_BMU_BITMAP_LD_ERR_INFO_REG             (SRE_BMU_REG_BASE_ADDR + 0x588)               /* BMU bitmap重复申请错误状态寄存器 */
#define SRE_BMU_BITMAP_ERR_STS_REG                 (SRE_BMU_REG_BASE_ADDR + 0x58C)               /* BMU bitmap重复申请错误状态寄存器 */
#define SRE_BMU_PPE_QOS_EN_REG                     (SRE_BMU_REG_BASE_ADDR + 0x590)               /* 送给PPE的QOS水线产生逻辑使能寄存器 */
#define SRE_BMU_CPU_ID_H12_REG                     (SRE_BMU_REG_BASE_ADDR + 0x594)               /* CPU的Master ID 高12位 */
#define SRE_BMU_PPE_QOS_WL_0_REG                   (SRE_BMU_REG_BASE_ADDR + 0x800)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_1_REG                   (SRE_BMU_REG_BASE_ADDR + 0x804)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_2_REG                   (SRE_BMU_REG_BASE_ADDR + 0x808)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_3_REG                   (SRE_BMU_REG_BASE_ADDR + 0x80C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_4_REG                   (SRE_BMU_REG_BASE_ADDR + 0x810)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_5_REG                   (SRE_BMU_REG_BASE_ADDR + 0x814)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_6_REG                   (SRE_BMU_REG_BASE_ADDR + 0x818)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_7_REG                   (SRE_BMU_REG_BASE_ADDR + 0x81C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_8_REG                   (SRE_BMU_REG_BASE_ADDR + 0x820)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_9_REG                   (SRE_BMU_REG_BASE_ADDR + 0x824)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_10_REG                  (SRE_BMU_REG_BASE_ADDR + 0x828)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_11_REG                  (SRE_BMU_REG_BASE_ADDR + 0x82C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_12_REG                  (SRE_BMU_REG_BASE_ADDR + 0x830)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_13_REG                  (SRE_BMU_REG_BASE_ADDR + 0x834)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_14_REG                  (SRE_BMU_REG_BASE_ADDR + 0x838)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_15_REG                  (SRE_BMU_REG_BASE_ADDR + 0x83C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_16_REG                  (SRE_BMU_REG_BASE_ADDR + 0x840)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_17_REG                  (SRE_BMU_REG_BASE_ADDR + 0x844)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_18_REG                  (SRE_BMU_REG_BASE_ADDR + 0x848)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_19_REG                  (SRE_BMU_REG_BASE_ADDR + 0x84C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_20_REG                  (SRE_BMU_REG_BASE_ADDR + 0x850)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_21_REG                  (SRE_BMU_REG_BASE_ADDR + 0x854)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_22_REG                  (SRE_BMU_REG_BASE_ADDR + 0x858)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_23_REG                  (SRE_BMU_REG_BASE_ADDR + 0x85C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_24_REG                  (SRE_BMU_REG_BASE_ADDR + 0x860)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_25_REG                  (SRE_BMU_REG_BASE_ADDR + 0x864)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_26_REG                  (SRE_BMU_REG_BASE_ADDR + 0x868)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_27_REG                  (SRE_BMU_REG_BASE_ADDR + 0x86C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_28_REG                  (SRE_BMU_REG_BASE_ADDR + 0x870)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_29_REG                  (SRE_BMU_REG_BASE_ADDR + 0x874)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_30_REG                  (SRE_BMU_REG_BASE_ADDR + 0x878)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_31_REG                  (SRE_BMU_REG_BASE_ADDR + 0x87C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_32_REG                  (SRE_BMU_REG_BASE_ADDR + 0x880)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_33_REG                  (SRE_BMU_REG_BASE_ADDR + 0x884)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_34_REG                  (SRE_BMU_REG_BASE_ADDR + 0x888)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_35_REG                  (SRE_BMU_REG_BASE_ADDR + 0x88C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_36_REG                  (SRE_BMU_REG_BASE_ADDR + 0x890)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_37_REG                  (SRE_BMU_REG_BASE_ADDR + 0x894)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_38_REG                  (SRE_BMU_REG_BASE_ADDR + 0x898)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_39_REG                  (SRE_BMU_REG_BASE_ADDR + 0x89C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_40_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8A0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_41_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8A4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_42_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8A8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_43_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8AC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_44_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8B0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_45_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8B4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_46_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8B8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_47_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8BC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_48_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8C0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_49_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8C4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_50_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8C8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_51_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8CC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_52_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8D0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_53_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8D4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_54_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8D8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_55_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8DC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_56_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8E0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_57_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8E4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_58_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8E8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_59_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8EC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_60_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8F0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_61_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8F4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_62_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8F8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_63_REG                  (SRE_BMU_REG_BASE_ADDR + 0x8FC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_64_REG                  (SRE_BMU_REG_BASE_ADDR + 0x900)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_65_REG                  (SRE_BMU_REG_BASE_ADDR + 0x904)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_66_REG                  (SRE_BMU_REG_BASE_ADDR + 0x908)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_67_REG                  (SRE_BMU_REG_BASE_ADDR + 0x90C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_68_REG                  (SRE_BMU_REG_BASE_ADDR + 0x910)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_69_REG                  (SRE_BMU_REG_BASE_ADDR + 0x914)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_70_REG                  (SRE_BMU_REG_BASE_ADDR + 0x918)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_71_REG                  (SRE_BMU_REG_BASE_ADDR + 0x91C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_72_REG                  (SRE_BMU_REG_BASE_ADDR + 0x920)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_73_REG                  (SRE_BMU_REG_BASE_ADDR + 0x924)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_74_REG                  (SRE_BMU_REG_BASE_ADDR + 0x928)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_75_REG                  (SRE_BMU_REG_BASE_ADDR + 0x92C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_76_REG                  (SRE_BMU_REG_BASE_ADDR + 0x930)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_77_REG                  (SRE_BMU_REG_BASE_ADDR + 0x934)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_78_REG                  (SRE_BMU_REG_BASE_ADDR + 0x938)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_79_REG                  (SRE_BMU_REG_BASE_ADDR + 0x93C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_80_REG                  (SRE_BMU_REG_BASE_ADDR + 0x940)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_81_REG                  (SRE_BMU_REG_BASE_ADDR + 0x944)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_82_REG                  (SRE_BMU_REG_BASE_ADDR + 0x948)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_83_REG                  (SRE_BMU_REG_BASE_ADDR + 0x94C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_84_REG                  (SRE_BMU_REG_BASE_ADDR + 0x950)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_85_REG                  (SRE_BMU_REG_BASE_ADDR + 0x954)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_86_REG                  (SRE_BMU_REG_BASE_ADDR + 0x958)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_87_REG                  (SRE_BMU_REG_BASE_ADDR + 0x95C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_88_REG                  (SRE_BMU_REG_BASE_ADDR + 0x960)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_89_REG                  (SRE_BMU_REG_BASE_ADDR + 0x964)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_90_REG                  (SRE_BMU_REG_BASE_ADDR + 0x968)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_91_REG                  (SRE_BMU_REG_BASE_ADDR + 0x96C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_92_REG                  (SRE_BMU_REG_BASE_ADDR + 0x970)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_93_REG                  (SRE_BMU_REG_BASE_ADDR + 0x974)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_94_REG                  (SRE_BMU_REG_BASE_ADDR + 0x978)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_95_REG                  (SRE_BMU_REG_BASE_ADDR + 0x97C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_96_REG                  (SRE_BMU_REG_BASE_ADDR + 0x980)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_97_REG                  (SRE_BMU_REG_BASE_ADDR + 0x984)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_98_REG                  (SRE_BMU_REG_BASE_ADDR + 0x988)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_99_REG                  (SRE_BMU_REG_BASE_ADDR + 0x98C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_100_REG                 (SRE_BMU_REG_BASE_ADDR + 0x990)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_101_REG                 (SRE_BMU_REG_BASE_ADDR + 0x994)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_102_REG                 (SRE_BMU_REG_BASE_ADDR + 0x998)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_103_REG                 (SRE_BMU_REG_BASE_ADDR + 0x99C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_104_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9A0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_105_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9A4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_106_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9A8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_107_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9AC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_108_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9B0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_109_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9B4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_110_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9B8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_111_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9BC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_112_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9C0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_113_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9C4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_114_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9C8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_115_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9CC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_116_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9D0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_117_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9D4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_118_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9D8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_119_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9DC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_120_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9E0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_121_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9E4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_122_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9E8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_123_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9EC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_124_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9F0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_125_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9F4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_126_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9F8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_127_REG                 (SRE_BMU_REG_BASE_ADDR + 0x9FC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_128_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA00)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_129_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA04)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_130_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA08)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_131_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA0C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_132_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA10)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_133_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA14)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_134_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA18)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_135_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA1C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_136_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA20)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_137_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA24)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_138_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA28)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_139_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA2C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_140_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA30)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_141_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA34)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_142_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA38)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_143_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA3C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_144_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA40)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_145_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA44)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_146_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA48)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_147_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA4C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_148_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA50)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_149_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA54)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_150_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA58)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_151_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA5C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_152_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA60)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_153_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA64)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_154_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA68)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_155_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA6C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_156_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA70)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_157_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA74)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_158_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA78)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_159_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA7C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_160_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA80)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_161_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA84)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_162_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA88)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_163_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA8C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_164_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA90)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_165_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA94)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_166_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA98)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_167_REG                 (SRE_BMU_REG_BASE_ADDR + 0xA9C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_168_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAA0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_169_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAA4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_170_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAA8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_171_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAAC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_172_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAB0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_173_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAB4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_174_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAB8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_175_REG                 (SRE_BMU_REG_BASE_ADDR + 0xABC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_176_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAC0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_177_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAC4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_178_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAC8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_179_REG                 (SRE_BMU_REG_BASE_ADDR + 0xACC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_180_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAD0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_181_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAD4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_182_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAD8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_183_REG                 (SRE_BMU_REG_BASE_ADDR + 0xADC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_184_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAE0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_185_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAE4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_186_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAE8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_187_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAEC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_188_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAF0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_189_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAF4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_190_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAF8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_191_REG                 (SRE_BMU_REG_BASE_ADDR + 0xAFC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_192_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB00)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_193_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB04)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_194_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB08)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_195_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB0C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_196_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB10)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_197_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB14)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_198_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB18)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_199_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB1C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_200_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB20)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_201_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB24)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_202_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB28)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_203_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB2C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_204_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB30)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_205_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB34)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_206_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB38)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_207_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB3C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_208_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB40)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_209_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB44)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_210_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB48)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_211_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB4C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_212_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB50)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_213_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB54)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_214_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB58)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_215_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB5C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_216_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB60)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_217_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB64)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_218_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB68)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_219_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB6C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_220_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB70)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_221_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB74)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_222_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB78)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_223_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB7C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_224_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB80)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_225_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB84)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_226_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB88)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_227_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB8C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_228_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB90)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_229_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB94)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_230_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB98)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_231_REG                 (SRE_BMU_REG_BASE_ADDR + 0xB9C)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_232_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBA0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_233_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBA4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_234_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBA8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_235_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBAC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_236_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBB0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_237_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBB4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_238_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBB8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_239_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBBC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_240_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBC0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_241_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBC4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_242_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBC8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_243_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBCC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_244_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBD0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_245_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBD4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_246_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBD8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_247_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBDC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_248_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBE0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_249_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBE4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_250_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBE8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_251_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBEC)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_252_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBF0)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_253_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBF4)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_254_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBF8)               /* 送给PPE的QOS水线寄存器。 */
#define SRE_BMU_PPE_QOS_WL_255_REG                 (SRE_BMU_REG_BASE_ADDR + 0xBFC)               /* 送给PPE的QOS水线寄存器。 */


/* Tring相关的IO地址宏定义 */
#define SRE_TRING_REG_BASE_ADDR           (0x10840000)

#define SRE_TIM_CTR_ADDR                   SRE_TRING_REG_BASE_ADDR
#define SRE_TIM_ERR_INT_ADDR              (SRE_TRING_REG_BASE_ADDR +0x4)
#define SRE_TIM_ERR_MASK_ADDR             (SRE_TRING_REG_BASE_ADDR +0x8)
#define SRE_TIM_RING0_BASE_ADDR           (SRE_TRING_REG_BASE_ADDR +0x10)
#define SRE_TIM_RING0_BSIZE_ADDR          (SRE_TRING_REG_BASE_ADDR +0x14)
#define SRE_TIM_RING0_INTERVAL_ADDR       (SRE_TRING_REG_BASE_ADDR +0x18)
#define SRE_TIM_RING0_CSIZE_ADDR          (SRE_TRING_REG_BASE_ADDR +0x1c)
#define SRE_TIM_RING0_POE_ADDR            (SRE_TRING_REG_BASE_ADDR +0x20)
#define SRE_TIM_RING0_POOL_ADDR           (SRE_TRING_REG_BASE_ADDR +0x24)
#define SRE_TIM_RING0_COUNT_ADDR          (SRE_TRING_REG_BASE_ADDR +0x28)
#define SRE_TIM_RING0_BUCKET_ADDR         (SRE_TRING_REG_BASE_ADDR +0x2c)
#define SRE_TIM_RING0_WR_POE_TIMEOUT      (SRE_TRING_REG_BASE_ADDR +0x30)
#define SRE_TIM_RING0_WR_BMU_TIMEOUT      (SRE_TRING_REG_BASE_ADDR +0x34)
#define SRE_TIM_RING0_WR_TIMEOUT_ST       (SRE_TRING_REG_BASE_ADDR +0x38)
#define SRE_TIM_RING0_REL_CHUNK_NUM       (SRE_TRING_REG_BASE_ADDR +0x3C)
#define SRE_TIMEBASE0_INIT_L_ADDR         (SRE_TRING_REG_BASE_ADDR + 0x190)
#define SRE_TIMEBASE0_INIT_H_ADDR         (SRE_TRING_REG_BASE_ADDR + 0x194)
#define SRE_TIMEBASE0_CNT_L_ADDR          (SRE_TRING_REG_BASE_ADDR + 0x198)
#define SRE_TIMEBASE0_CNT_H_ADDR          (SRE_TRING_REG_BASE_ADDR + 0x19C)

#define SRE_MDIO_BASE_ADDR          (0x18000000 + 0x80000000)

/******************************************************************************/
/*                      PhosphorV600 MAC_CORE 寄存器定义                      */
/******************************************************************************/
#if 0     /* z00202052 */
#define SRE_GMAC_BASE_ADDR                                 (0x12800000)
#else
#define SRE_GMAC_BASE_ADDR                                 (0xe2800000)
#endif    /* z00202052 */


#define SRE_GMAC_DUPLEX_TYPE_REG                           (0x0008UL)                          /*全双工半双工模式寄存器 */
#define SRE_GMAC_FD_FC_TYPE_REG                            (0x000CUL)                          /*FD_FC_TYPE为流控帧类型域寄存器。*/
#define SRE_GMAC_FC_TX_TIMER_REG                           (0x001CUL)                          /*FC_TX_TIMER为流控时间参数寄存器。*/
#define SRE_GMAC_FD_FC_ADDR_LOW_REG                        (0x0020UL)                          /*FD_FC_ADDR_LOW为流控帧目的地址寄存器1。*/
#define SRE_GMAC_FD_FC_ADDR_HIGH_REG                       (0x0024UL)                          /*FD_FC_ADDR_HIGH为流控帧目的地址寄存器2。 */
#define SRE_GMAC_IPG_TX_TIMER_REG                          (0x0030UL)                          /*IPG_TX_TIMER为发送帧间隙寄存器。             */
#define SRE_GMAC_PAUSE_THR_REG                             (0x0038UL)                          /*PAUSE_THR为发送流控帧间隙寄存器。         */
#define SRE_GMAC_MAX_FRM_SIZE_REG                          (0x003CUL)                          /*MAX_FRM_SIZE为最大帧长寄存器。                    */
#define SRE_GMAC_PORT_MODE_REG                             (0x0040UL)                          /*PORT_MODE为端口状态寄存器。                          */
#define SRE_GMAC_PORT_EN_REG                               (0x0044UL)                          /*PORT_EN为通道使能寄存器。                                   */
#define SRE_GMAC_PAUSE_EN_REG                              (0x0048UL)                          /*PAUSE_EN为流控使能寄存器。                                */
#define SRE_GMAC_SHORT_RUNTS_THR_REG                       (0x0050UL)                          /*SHORT_RUNTS_THR为超短帧界限寄存器。 */
#define SRE_GMAC_AN_NEG_STATE_REG                          (0x0058UL)                          /*SGMII自协商状态寄存器                                    */
#define SRE_GMAC_TX_LOCAL_PAGE_REG                         (0x005CUL)                          /*自协商本地配置寄存器                                  */
#define SRE_GMAC_TRANSMIT_CONTROL_REG                      (0x0060UL)                          /*TRANSMIT_CONTROL为常用配置寄存器。     */
#define SRE_GMAC_REC_FILT_CONTROL_REG                      (0x0064UL)                          /*REC_FILT_CONTROL为接收帧过滤控制寄存器。 */
#define SRE_GMAC_PTP_CONFIG_REG                            (0x0074UL)                          /*发送方向IPV6的1588报文CHCECKSUM使能和1588的修正域最高位置0使能 */
#define SRE_GMAC_RX_OCTETS_TOTAL_OK_REG                    (0x0080UL)                          /*RX_OCTETS_TOTAL_OK为接收有效帧的字节统计寄存器。*/
#define SRE_GMAC_RX_OCTETS_BAD_REG                         (0x0084UL)                          /*RX_OCTETS_BAD为接收错误帧字节统计寄存器。                     */
#define SRE_GMAC_RX_UC_PKTS_REG                            (0x0088UL)                          /*RX_UC_PKTS为MAC接收单播帧数统计寄存器。                              */
#define SRE_GMAC_RX_MC_PKTS_REG                            (0x008CUL)                          /*RX_MC_PKTS为接收多播帧数统计寄存器。                                     */
#define SRE_GMAC_RX_BC_PKTS_REG                            (0x0090UL)                          /*RX_BC_PKTS为接收的广播帧数统计寄存器。                                 */
#define SRE_GMAC_RX_PKTS_64OCTETS_REG                      (0x0094UL)                          /*RX_PKTS_64OCTETS为接收到帧长为64byte的帧数统计寄存器。*/
#define SRE_GMAC_RX_PKTS_65TO127OCTETS_REG                 (0x0098UL)                          /*RX_PKTS_65TO127OCTETS为接收到帧长为65～127byte的帧数统计寄存器。 */
#define SRE_GMAC_RX_PKTS_128TO255OCTETS_REG                (0x009CUL)                          /*RX_PKTS_128TO255OCTETS为接收到帧长为128～255byte的帧数统计寄存器。 */
#define SRE_GMAC_RX_PKTS_255TO511OCTETS_REG                (0x00A0UL)                          /*RX_PKTS_255TO511OCTETS为接收到帧长为256～511byte的帧数统计寄存器。  */
#define SRE_GMAC_RX_PKTS_512TO1023OCTETS_REG               (0x00A4UL)                          /*RX_PKTS_512TO1023OCTETS为接收到帧长为512～1023byte的帧数统计寄存器。 */
#define SRE_GMAC_RX_PKTS_1024TO1518OCTETS_REG              (0x00A8UL)                          /*RX_PKTS_1024TO1518OCTETS为接收帧长为1024～1518byte的帧数统计寄存器。  */
#define SRE_GMAC_RX_PKTS_1519TOMAXOCTETS_REG               (0x00ACUL)                          /*RX_PKTS_1519TOMAXOCTETS为接收到帧长为1519～最大byte的帧数统计寄存器。 */
#define SRE_GMAC_RX_FCS_ERRORS_REG                         (0x00B0UL)                          /*RX_FCS_ERRORS为接收CRC检验错误的帧数统计寄存器。                                        */
#define SRE_GMAC_RX_TAGGED_REG                             (0x00B4UL)                          /*RX_TAGGED为接收带TAG的帧统计寄存器。                                                    */
#define SRE_GMAC_RX_DATA_ERR_REG                           (0x00B8UL)                          /*RX_DATA_ERR为接收数据错误帧统计寄存器。                                                 */
#define SRE_GMAC_RX_ALIGN_ERRORS_REG                       (0x00BCUL)                          /*RX_ALIGN_ERRORS为接收数据非字节对齐错误帧统计寄存器。                                  */
#define SRE_GMAC_RX_LONG_ERRORS_REG                        (0x00C0UL)                          /*RX_LONG_ERRORS为接收帧长大于允许的最大长度的帧数统计寄存器1。                        */
#define SRE_GMAC_RX_JABBER_ERRORS_REG                      (0x00C4UL)                          /*RX_JABBER_ERRORS为接收帧长大于允许的最大长度的帧数统计寄存器2。                      */
#define SRE_GMAC_RX_PAUSE_MACCONTROL_FRAMCOUNTER_REG       (0x00C8UL)                          /*RX_PAUSE_MACCONTROL_FRAMCOUNTER为接收到的流控帧数统计寄存器。                          */
#define SRE_GMAC_RX_UNKNOWN_MACCONTROL_FRAMCOUNTER_REG     (0x00CCUL)                          /*RX_UNKNOWN_MACCONTROL_FRAMCOUNTER为MAC接收到的非流控控制帧数统计寄存器                */
#define SRE_GMAC_RX_VERY_LONG_ERR_CNT_REG                  (0x00D0UL)                          /*RX_VERY_LONG_ERR_CNT为接收到超长帧统计寄存器。                                          */
#define SRE_GMAC_RX_RUNT_ERR_CNT_REG                       (0x00D4UL)                          /*RX_RUNT_ERR_CNT为接收到帧长小于64byte大于等于short_runts_thr 字节的帧数寄存器。        */
#define SRE_GMAC_RX_SHORT_ERR_CNT_REG                      (0x00D8UL)                          /*RX_SHORT_ERR_CNT为接收帧长小于short_runts_thr字节的帧数统计寄存器。                    */
#define SRE_GMAC_RX_FILT_PKT_CNT_REG                       (0x00E8UL)                          /*接收方向过滤掉的包统计                                                                */
#define SRE_GMAC_RX_OCTETS_TOTAL_FILT_REG                  (0x00ECUL)                          /*接收方向过滤掉的字节统计                                                              */
#define SRE_GMAC_OCTETS_TRANSMITTED_OK_REG                 (0x0100UL)                          /*OCTETS_TRANSMITTED_OK为发送成功的好包字节数统计寄存器。                              */
#define SRE_GMAC_OCTETS_TRANSMITTED_BAD_REG                (0x0104UL)                          /*OCTETS_TRANSMITTED_BAD为发送成功的坏包字节数统计寄存器。                             */
#define SRE_GMAC_TX_UC_PKTS_REG                            (0x0108UL)                          /*TX_UC_PKTS为发送的单播帧数统计寄存器。                                                 */
#define SRE_GMAC_TX_MC_PKTS_REG                            (0x010CUL)                          /*TX_MC_PKTS为发送的多播帧数统计寄存器。                                                 */
#define SRE_GMAC_TX_BC_PKTS_REG                            (0x0110UL)                          /*TX_BC_PKTS为发送的广播帧数统计寄存器。                                                 */
#define SRE_GMAC_TX_PKTS_64OCTETS_REG                      (0x0114UL)                          /*TX_PKTS_64OCTETS为发送帧长为64byte的帧数统计寄存器。                                    */
#define SRE_GMAC_TX_PKTS_65TO127OCTETS_REG                 (0x0118UL)                          /*TX_PKTS_65TO127OCTETS为发送帧长为65～127byte的帧数统计寄存器。                          */
#define SRE_GMAC_TX_PKTS_128TO255OCTETS_REG                (0x011CUL)                          /*TX_PKTS_128TO255OCTETS为发送帧长为128～255byte的帧数统计寄存器。                        */
#define SRE_GMAC_TX_PKTS_255TO511OCTETS_REG                (0x0120UL)                          /*TX_PKTS_255TO511OCTETS为发送帧长为256～511byte的帧数统计寄存器。                        */
#define SRE_GMAC_TX_PKTS_512TO1023OCTETS_REG               (0x0124UL)                          /*TX_PKTS_512TO1023OCTETS为发送帧长为512～1023byte节的帧数统计寄存器。                    */
#define SRE_GMAC_TX_PKTS_1024TO1518OCTETS_REG              (0x0128UL)                          /*TX_PKTS_1024TO1518OCTETS为发送帧长为1024～1518byte的帧数统计寄存器。                    */
#define SRE_GMAC_TX_PKTS_1519TOMAXOCTETS_REG               (0x012CUL)                          /*TX_PKTS_1519TOMAXOCTETS为发送帧长大于1519byte的帧数统计寄存器。                         */
#define SRE_GMAC_TX_EXCESSIVE_LENGTH_DROP_REG              (0x014CUL)                          /*TX_EXCESSIVE_LENGTH_DROP为超过设定的最大帧长导致发送失败次数统计寄存器     。       */
#define SRE_GMAC_TX_UNDERRUN_REG                           (0x0150UL)                          /*TX_UNDERRUN为帧发送过程中发生内部错误而导致发送失败的次数统计。                     */
#define SRE_GMAC_TX_TAGGED_REG                             (0x0154UL)                          /*TX_TAGGED为发送的VLAN帧数统计寄存器。                                                  */
#define SRE_GMAC_TX_CRC_ERROR_REG                          (0x0158UL)                          /*TX_CRC_ERROR为发送帧长正确CRC错误的帧数统计寄存器。                                   */
#define SRE_GMAC_TX_PAUSE_FRAMES_REG                       (0x015CUL)                          /*TX_PAUSE_FRAMES为发送PAUSE帧数统计寄存器。                                             */
#define SRE_GMAC_LED_MOD_REG                               (0x016CUL)                          /*LED_MOD为点灯模式控制寄存器。                                                         */
#define SRE_GMAC_TS_DLY_ESTI_REG                           (0x0170UL)                          /*下行修正延时值                                                                         */
#define SRE_GMAC_CF_ASYM_CRT_HIGH_REG                      (0x0174UL)                          /*非对称延时高32比特                                                                     */
#define SRE_GMAC_CF_ASYM_CRT_LOW_REG                       (0x0178UL)                          /*非对称延时低32比特                                                                     */
#define SRE_GMAC_TIMSTP_INGRESS_REG                        (0x017CUL)                          /*上行修正延时值                                                                         */
#define SRE_GMAC_LINE_LOOP_BACK_REG                        (0x01A8UL)                          /*LINE_LOOP_BACK为MAC线路侧环回寄存器。                                                  */
#define SRE_GMAC_CF_CRC_STRIP_REG                          (0x01B0UL)                          /*CF_CRC_STRIP为CRC剥离使能寄存器。                                                      */
#define SRE_GMAC_MODE_CHANGE_EN_REG                        (0x01B4UL)                          /*MODE_CHANGE_EN为端口模式改变使能寄存器。                                              */
#define SRE_GMAC_SIXTEEN_BIT_CNTR_REG                      (0x01CCUL)                          /*自协商链接时间寄存器                                                                   */
#define SRE_GMAC_LD_LINK_COUNTER_REG                       (0x01D0UL)                          /*自协商链接时间更新寄存器                                                              */
#define SRE_GMAC_LOOP_REG                                  (0x01DCUL)                          /*LOOP_REG为环回补充寄存器。                                                             */
#define SRE_GMAC_RECV_CONTROL_REG                          (0x01E0UL)                          /*RECV_CONTROL为接收控制寄存器。                                                        */
#define SRE_GMAC_VLAN_CODE_REG                             (0x01E8UL)                          /*VLAN_CODE为VLAN Code寄存器。                                                            */
#define SRE_GMAC_RX_OVERRUN_CNT_REG                        (0x01ECUL)                          /*RX_OVERRUN_CNT为FIFO溢出统计寄存器。                                                   */
#define SRE_GMAC_RX_LENGTHFIELD_ERR_CNT_REG                (0x01F4UL)                          /*RX_LENGTHFIELD_ERR_CNT为含PAD帧统计寄存器。                                             */
#define SRE_GMAC_RX_FAIL_COMMA_CNT_REG                     (0x01F8UL)                          /*RX_FAIL_COMMA_CNT为字节定界COMMA统计寄存器。                                           */
#define SRE_GMAC_STATION_ADDR_LOW_0_REG                    (0x0200UL)                          /*STATION_ADDR_LOW为本机MAC地址0寄存器1。                                               */
#define SRE_GMAC_STATION_ADDR_HIGH_0_REG                   (0x0204UL)                          /*STATION_ADDR_HIGH为本机MAC地址0寄存器2。                                              */
#define SRE_GMAC_STATION_ADDR_LOW_1_REG                    (0x0208UL)                          /*STATION_ADDR_LOW为本机MAC地址1寄存器1。                                               */
#define SRE_GMAC_STATION_ADDR_HIGH_1_REG                   (0x020CUL)                          /*STATION_ADDR_HIGH为本机MAC地址1寄存器2。                                              */
#define SRE_GMAC_STATION_ADDR_LOW_2_REG                    (0x0210UL)                          /*STATION_ADDR_LOW为本机MAC地址2寄存器1。                                               */
#define SRE_GMAC_STATION_ADDR_HIGH_2_REG                   (0x0214UL)                          /*STATION_ADDR_HIGH为本机MAC地址2寄存器2。                                              */
#define SRE_GMAC_STATION_ADDR_LOW_3_REG                    (0x0218UL)                          /*STATION_ADDR_LOW为本机MAC地址3寄存器1。                                               */
#define SRE_GMAC_STATION_ADDR_HIGH_3_REG                   (0x021CUL)                          /*STATION_ADDR_HIGH为本机MAC地址3寄存器2。                                              */
#define SRE_GMAC_STATION_ADDR_LOW_4_REG                    (0x0220UL)                          /*STATION_ADDR_LOW为本机MAC地址4寄存器1。                                               */
#define SRE_GMAC_STATION_ADDR_HIGH_4_REG                   (0x0224UL)                          /*STATION_ADDR_HIGH为本机MAC地址4寄存器2。                                              */
#define SRE_GMAC_STATION_ADDR_LOW_5_REG                    (0x0228UL)                          /*STATION_ADDR_LOW为本机MAC地址5寄存器1。                                               */
#define SRE_GMAC_STATION_ADDR_HIGH_5_REG                   (0x022CUL)                          /*STATION_ADDR_HIGH为本机MAC地址5寄存器2。                                              */
#define SRE_GMAC_STATION_ADDR_LOW_MSK_0_REG                (0x0230UL)                          /*STATION_ADDR_LOW为本机MAC地址0寄存器1的掩码。                                        */
#define SRE_GMAC_STATION_ADDR_HIGH_MSK_0_REG               (0x0234UL)                          /*STATION_ADDR_HIGH为本机MAC地址0寄存器2的掩码。                                       */
#define SRE_GMAC_STATION_ADDR_LOW_MSK_1_REG                (0x0238UL)                          /*STATION_ADDR_LOW为本机MAC地址1寄存器1的掩码。                                        */
#define SRE_GMAC_STATION_ADDR_HIGH_MSK_1_REG               (0x023CUL)                          /*STATION_ADDR_HIGH为本机MAC地址1寄存器2的掩码。                                       */
#define SRE_GMAC_MAC_SKIP_LEN_REG                          (0x0240UL)                          /*SKIP_LEN为报文头不解析字段长度。                                                      */
#define SRE_GMAC_DEBUG_RD_DATA_REG                         (0x0244UL)                          /*1588发送方向debug时，抓到包的数据 +mac_num*0x4                                                   */
#define SRE_GMAC_DEBUG_PKT_PTR_REG                         (0x0344UL)                          /*报文指针寄存器                                                                        */
#define SRE_GMAC_DEBUG_EN_REG                              (0x0348UL)                          /*捕获使能                                                                               */
#define SRE_GMAC_INTR_STATE_REG                            (0x034CUL)                          /*中断状态                                                                               */
#define SRE_GMAC_INTR_CLR_REG                              (0x0350UL)                          /*中断清除寄存器                                                                        */
#define SRE_GMAC_INTR_MSK_REG                              (0x0354UL)                          /*中断屏蔽寄存器                                                                        */
#define SRE_GMAC_SEQ_ID_REG                                (0x0358UL)                          /*捕获的sequence ID和时间戳的[79:64]                                                     */
#define SRE_GMAC_STP_63_TO_32_REG                          (0x035CUL)                          /*上报时间戳的[63:32]                                                                     */
#define SRE_GMAC_STP_31_TO_0_REG                           (0x0360UL)                          /*上报时间戳的[31:0]                                                                      */
#define SRE_GMAC_DBG_GRP0_VLD_WORDS_REG                    (0x0364UL)                          /*第一组RAM中捕获的有效字数                                                             */
#define SRE_GMAC_DBG_GRP1_VLD_WORDS_REG                    (0x0368UL)                          /*第二组RAM中捕获的有效字数                                                             */
#define SRE_GMAC_DMAC_EN_REG                               (0x0370UL)                          /*DMAC为共用的32个不带掩码的本地MAC地址使能。                                          */
#define SRE_GMAC_DMAC_WITH_MSK_EN_REG                      (0x0374UL)                          /*DMAC为共用的32个带掩码的本地MAC地址使能。。                                           */
#define SRE_GMAC_TX_LOOP_PKT_PRI_REG                       (0x0378UL)                          /*指定环回报文优先级配置。                                                              */

/******************************************************************************/
/*                      P650 PPE_COMMON 寄存器定义                            */
/******************************************************************************/

#if 0         /* z00202052 */
#define SRE_PPE_COMMON_BASE                                   (0x128c0000)
#else
#define SRE_PPE_COMMON_BASE                                   (0xe28c0000)
#endif        /* z00202052 */

#define SRE_PPE_CFG_WE_ADDR_REG      (SRE_PPE_COMMON_BASE + 0x0)   /* PPE_CFG_WE_ADDR为POE的写地址。 */
#define SRE_PPE_CFG_BMU_ADDR_REG     (SRE_PPE_COMMON_BASE + 0x4)   /* PPE_CFG_BMU_ADDR为BMU申请和释放缓存的基地址。 */
#define SRE_PPE_CFG_RX_BUFF_REQ_TIMER_REG  (SRE_PPE_COMMON_BASE + 0x8)   /* PPE_CFG_RX_BUFFREQ_TIMER为接收缓存申请超时寄存器。 */
#define SRE_PPE_CFG_VMID_REG         (SRE_PPE_COMMON_BASE + 0xC)   /* PPE_CFG_VMID为访问BMU和POE的VMID。 */
#define SRE_PPE_CFG_QOS_DROP_EN_REG  (SRE_PPE_COMMON_BASE + 0x10)  /* PPE_CFG_QOS_DROP_EN是32个POOL的按QoS丢包使能 */
#define SRE_PPE_CFG_TM_ADDR_REG      (SRE_PPE_COMMON_BASE + 0x14)  /* PPE_CFG_TM_ADDR为TM的丢包寄存器地址，向该地址推包，TM完成丢弃。 */
#define SRE_PPE_CFG_REQ_BMU_OUT_DEPTH_REG  (SRE_PPE_COMMON_BASE + 0x18)  /* PPE_CFG_REQ_BMU_OUT_DEPTH为向BMU申请缓存时的outstanding深度。 */
#define SRE_PPE_CFG_CMM_TO_BE_RST_REG  (SRE_PPE_COMMON_BASE + 0x1C)  /* PPE_CFG_CMM_TO_BE_RST为该通道是否将要复位。 */
#define SRE_PPE_CFG_MEM_TIMING_REG   (SRE_PPE_COMMON_BASE + 0x20)  /* PPE_CFG_MEM_TIMING为PPE的MEM时序配置。 */
#define SRE_PPE_CFG_BP_BUS_TIME_REG  (SRE_PPE_COMMON_BASE + 0x24)  /* PPE_CFG_BP_BUS_TIME为PPE的反压总线的超时寄存器配置。 */
#define SRE_PPE_CFG_RX_CFF_ADDR_0_REG  (SRE_PPE_COMMON_BASE + 0x100)  /* PPE_CFG_RX_CFF_ADD是32个POOL的对应FIFO被动分配BUF的地址，0x0100~0x017C依次是POOL0~POOL31的对应FIFO被动分配BUF的地址 */
#define SRE_PPE_CFG_RX_CFF_ADDR_1_REG  (SRE_PPE_COMMON_BASE + 0x104)  /* PPE_CFG_RX_CFF_ADD是32个POOL的对应FIFO被动分配BUF的地址，0x0100~0x017C依次是POOL0~POOL31的对应FIFO被动分配BUF的地址 */
#define SRE_PPE_CFG_RX_BUFF_FIFO_0_THRSLD_0_REG  (SRE_PPE_COMMON_BASE + 0x200)  /* PPE_CFG_RX_BUFF_FIFO_THRSLD为缓存FIFO水线寄存器。
0x0200~0x027C依次是缓存FIFO_0~FIFO_31的水线配置寄存器 */
#define SRE_PPE_CFG_RX_BUFF_FIFO_0_THRSLD_1_REG  (SRE_PPE_COMMON_BASE + 0x204)  /* PPE_CFG_RX_BUFF_FIFO_THRSLD为缓存FIFO水线寄存器。
0x0200~0x027C依次是缓存FIFO_0~FIFO_31的水线配置寄存器 */
#define SRE_PPE_CFG_POOL_GRP_0_REG   (SRE_PPE_COMMON_BASE + 0x300)  /* PPE_CFG_POOL_GRP是32个POOL可以分配给哪些GRP使用，0x0300~0x037C依次是POOL0~POOL31的配置 */
#define SRE_PPE_CFG_POOL_GRP_1_REG   (SRE_PPE_COMMON_BASE + 0x304)  /* PPE_CFG_POOL_GRP是32个POOL可以分配给哪些GRP使用，0x0300~0x037C依次是POOL0~POOL31的配置 */
#define SRE_PPE_CFG_RX_BUFF_FIFO_RX_BUF_SIZE_0_REG  (SRE_PPE_COMMON_BASE + 0x400)  /* PPE_CFG_RX_BUFF_FIFO_RX_BUF_SIZE为缓存FIFO的缓存大小配置寄存器。
0x0400~0x047C依次是缓存FIFO_0~FIFO_31的缓存大小配置寄存器 */
#define SRE_PPE_CFG_RX_BUFF_FIFO_RX_BUF_SIZE_1_REG  (SRE_PPE_COMMON_BASE + 0x404)  /* PPE_CFG_RX_BUFF_FIFO_RX_BUF_SIZE为缓存FIFO的缓存大小配置寄存器。
0x0400~0x047C依次是缓存FIFO_0~FIFO_31的缓存大小配置寄存器 */
#define SRE_PPE_CFG_RX_BUFF_FIFO_SIZE_0_REG  (SRE_PPE_COMMON_BASE + 0x500)  /* PPE_CFG_RX_BUFF_FIFO_SIZE缓存FIFO的大小配置寄存器。
0x0500~0x057C依次是缓存FIFO_0~FIFO_31的大小配置寄存器 */
#define SRE_PPE_CFG_RX_BUFF_FIFO_SIZE_1_REG  (SRE_PPE_COMMON_BASE + 0x504)  /* PPE_CFG_RX_BUFF_FIFO_SIZE缓存FIFO的大小配置寄存器。
0x0500~0x057C依次是缓存FIFO_0~FIFO_31的大小配置寄存器 */
#define SRE_PPE_CFG_TYPE_ITEM_0_REG  (SRE_PPE_COMMON_BASE + 0x2000)  /* PPE_CFG_TYPE_ITEM为需要按类型生成QOS/GRP/VMID的各种报文配置。
0x2000~0x24FC依次是第0种~第255种报文的配置 */
#define SRE_PPE_CFG_TYPE_ITEM_1_REG  (SRE_PPE_COMMON_BASE + 0x2004)  /* PPE_CFG_TYPE_ITEM为需要按类型生成QOS/GRP/VMID的各种报文配置。
0x2000~0x24FC依次是第0种~第255种报文的配置 */
#define SRE_PPE_CFG_TYPE_ITEM_MSK_0_REG  (SRE_PPE_COMMON_BASE + 0x2400)  /* PPE_CFG_TYPE_ITEM0_MSK为需要按类型生成QOS/GRP/VMID的各种报文的掩码配置。
0x2400~0x27FC依次是第0种~第255种报文的配置 */
#define SRE_PPE_CFG_TYPE_ITEM_MSK_1_REG  (SRE_PPE_COMMON_BASE + 0x2404)  /* PPE_CFG_TYPE_ITEM0_MSK为需要按类型生成QOS/GRP/VMID的各种报文的掩码配置。
0x2400~0x27FC依次是第0种~第255种报文的配置 */
#define SRE_PPE_CFG_TYPE_ITEM_QOS_MODE_0_REG  (SRE_PPE_COMMON_BASE + 0x2800)  /* PPE_CFG_TYPE_ITEM_QOS_MODE为需要按类型生成QOS/GRP/VMID的各种报文生成方式配置1。
0x2800~0x2BFC依次是第0种~第255种报文的配置 */
#define SRE_PPE_CFG_TYPE_ITEM_QOS_MODE_1_REG  (SRE_PPE_COMMON_BASE + 0x2804)  /* PPE_CFG_TYPE_ITEM_QOS_MODE为需要按类型生成QOS/GRP/VMID的各种报文生成方式配置1。
0x2800~0x2BFC依次是第0种~第255种报文的配置 */
#define SRE_PPE_CFG_TYPE_ITEM_QOS_OFFSET_0_REG  (SRE_PPE_COMMON_BASE + 0x2C00)  /* PPE_CFG_TYPE_ITEM_QOS_OFFSET为需要按类型生成QOS/GRP/VMID的各种报文生成方式配置2。0x2C00~0x2CFC依次是第0种~第255种报文的配置 */
#define SRE_PPE_CFG_TYPE_ITEM_QOS_OFFSET_1_REG  (SRE_PPE_COMMON_BASE + 0x2C04)  /* PPE_CFG_TYPE_ITEM_QOS_OFFSET为需要按类型生成QOS/GRP/VMID的各种报文生成方式配置2。0x2C00~0x2CFC依次是第0种~第255种报文的配置 */
#define SRE_PPE_CFG_QOS_TBL0_0_REG   (SRE_PPE_COMMON_BASE + 0x4000)  /* PPE_CFG_QOS_TBL0是生成QOS的第0张表。 */
#define SRE_PPE_CFG_QOS_TBL0_1_REG   (SRE_PPE_COMMON_BASE + 0x4004)  /* PPE_CFG_QOS_TBL0是生成QOS的第0张表。 */
#define SRE_PPE_CFG_QOS_TBL1_0_REG   (SRE_PPE_COMMON_BASE + 0x4020)  /* PPE_CFG_QOS_TBL1是生成QOS的第1张表。 */
#define SRE_PPE_CFG_QOS_TBL1_1_REG   (SRE_PPE_COMMON_BASE + 0x4024)  /* PPE_CFG_QOS_TBL1是生成QOS的第1张表。 */
#define SRE_PPE_CFG_QOS_TBL2_0_REG   (SRE_PPE_COMMON_BASE + 0x4040)  /* PPE_CFG_QOS_TBL2是生成QOS的第2张表。 */
#define SRE_PPE_CFG_QOS_TBL2_1_REG   (SRE_PPE_COMMON_BASE + 0x4044)  /* PPE_CFG_QOS_TBL2是生成QOS的第2张表。 */
#define SRE_PPE_CFG_QOS_TBL3_0_REG   (SRE_PPE_COMMON_BASE + 0x4060)  /* PPE_CFG_QOS_TBL3是生成QOS的第3张表。 */
#define SRE_PPE_CFG_QOS_TBL3_1_REG   (SRE_PPE_COMMON_BASE + 0x4064)  /* PPE_CFG_QOS_TBL3是生成QOS的第3张表。 */
#define SRE_PPE_CFG_QOS_TBL4_0_REG   (SRE_PPE_COMMON_BASE + 0x4080)  /* PPE_CFG_QOS_TBL4是生成QOS的第4张表。 */
#define SRE_PPE_CFG_QOS_TBL4_1_REG   (SRE_PPE_COMMON_BASE + 0x4084)  /* PPE_CFG_QOS_TBL4是生成QOS的第4张表。 */
#define SRE_PPE_CFG_QOS_TBL5_0_REG   (SRE_PPE_COMMON_BASE + 0x40A0)  /* PPE_CFG_QOS_TBL5是生成QOS的第5张表。 */
#define SRE_PPE_CFG_QOS_TBL5_1_REG   (SRE_PPE_COMMON_BASE + 0x40A4)  /* PPE_CFG_QOS_TBL5是生成QOS的第5张表。 */
#define SRE_PPE_CFG_QOS_TBL6_0_REG   (SRE_PPE_COMMON_BASE + 0x40C0)  /* PPE_CFG_QOS_TBL6是生成QOS的第6张表。 */
#define SRE_PPE_CFG_QOS_TBL6_1_REG   (SRE_PPE_COMMON_BASE + 0x40C4)  /* PPE_CFG_QOS_TBL6是生成QOS的第6张表。 */
#define SRE_PPE_CFG_QOS_TBL7_0_REG   (SRE_PPE_COMMON_BASE + 0x40E0)  /* PPE_CFG_QOS_TBL7是生成QOS的第7张表。 */
#define SRE_PPE_CFG_QOS_TBL7_1_REG   (SRE_PPE_COMMON_BASE + 0x40E4)  /* PPE_CFG_QOS_TBL7是生成QOS的第7张表。 */
#define SRE_PPE_CFG_QOS_TBL_KEY_EN_0_REG  (SRE_PPE_COMMON_BASE + 0x4104)  /* PPE_CFG_QOS_TBL0_KEY_EN是生成QOS的表的键值产生配置寄存器1。0x4104~0x413C依次是表0~表7的配置 */
#define SRE_PPE_CFG_QOS_TBL_KEY_EN_1_REG  (SRE_PPE_COMMON_BASE + 0x410C)  /* PPE_CFG_QOS_TBL0_KEY_EN是生成QOS的表的键值产生配置寄存器1。0x4104~0x413C依次是表0~表7的配置 */
#define SRE_PPE_CFG_GRP_VMID_TBL_KEY_OFFSET0_0_REG  (SRE_PPE_COMMON_BASE + 0x5D00)  /* PPE_CFG_GRP_VMID_TBL0_KEY_OFFSET0是生成GRP和VMID的表的键值产生配置寄存器0。0x5D00~0x5D50依次是表0~表10的配置 */
#define SRE_PPE_CFG_GRP_VMID_TBL_KEY_OFFSET0_1_REG  (SRE_PPE_COMMON_BASE + 0x5D08)  /* PPE_CFG_GRP_VMID_TBL0_KEY_OFFSET0是生成GRP和VMID的表的键值产生配置寄存器0。0x5D00~0x5D50依次是表0~表10的配置 */
#define SRE_PPE_CFG_GRP_VMID_TBL_KEY_OFFSET1_0_REG  (SRE_PPE_COMMON_BASE + 0x5D04)  /* PPE_CFG_GRP_VMID_TBL_KEY_OFFSET0是生成GRP和VMID的表的键值产生配置寄存器1。0x5D04~0x5D54依次是表0~表10的配置 */
#define SRE_PPE_CFG_GRP_VMID_TBL_KEY_OFFSET1_1_REG  (SRE_PPE_COMMON_BASE + 0x5D0C)  /* PPE_CFG_GRP_VMID_TBL_KEY_OFFSET0是生成GRP和VMID的表的键值产生配置寄存器1。0x5D04~0x5D54依次是表0~表10的配置 */
#define SRE_PPE_CFG_GRP_TBL0_0_REG   (SRE_PPE_COMMON_BASE + 0x5000)  /* PPE_CFG_GRP_TBL0是查表生成GRP的第0张表。 */
#define SRE_PPE_CFG_GRP_TBL0_1_REG   (SRE_PPE_COMMON_BASE + 0x5004)  /* PPE_CFG_GRP_TBL0是查表生成GRP的第0张表。 */
#define SRE_PPE_CFG_GRP_TBL1_0_REG   (SRE_PPE_COMMON_BASE + 0x5100)  /* PPE_CFG_GRP_TBL1是查表生成GRP的第1张表。 */
#define SRE_PPE_CFG_GRP_TBL1_1_REG   (SRE_PPE_COMMON_BASE + 0x5104)  /* PPE_CFG_GRP_TBL1是查表生成GRP的第1张表。 */
#define SRE_PPE_CFG_GRP_TBL2_0_REG   (SRE_PPE_COMMON_BASE + 0x5200)  /* PPE_CFG_GRP_TBL2是查表生成GRP的第2张表。 */
#define SRE_PPE_CFG_GRP_TBL2_1_REG   (SRE_PPE_COMMON_BASE + 0x5204)  /* PPE_CFG_GRP_TBL2是查表生成GRP的第2张表。 */
#define SRE_PPE_CFG_GRP_TBL3_0_REG   (SRE_PPE_COMMON_BASE + 0x5300)  /* PPE_CFG_GRP_TBL3是查表生成GRP的第3张表。 */
#define SRE_PPE_CFG_GRP_TBL3_1_REG   (SRE_PPE_COMMON_BASE + 0x5304)  /* PPE_CFG_GRP_TBL3是查表生成GRP的第3张表。 */
#define SRE_PPE_CFG_GRP_TBL4_0_REG   (SRE_PPE_COMMON_BASE + 0x5400)  /* PPE_CFG_GRP_TBL4是查表生成GRP的第4张表。 */
#define SRE_PPE_CFG_GRP_TBL4_1_REG   (SRE_PPE_COMMON_BASE + 0x5404)  /* PPE_CFG_GRP_TBL4是查表生成GRP的第4张表。 */
#define SRE_PPE_CFG_GRP_TBL5_0_REG   (SRE_PPE_COMMON_BASE + 0x5500)  /* PPE_CFG_GRP_TBL5是查表生成GRP的第5张表。 */
#define SRE_PPE_CFG_GRP_TBL5_1_REG   (SRE_PPE_COMMON_BASE + 0x5504)  /* PPE_CFG_GRP_TBL5是查表生成GRP的第5张表。 */
#define SRE_PPE_CFG_GRP_TBL6_0_REG   (SRE_PPE_COMMON_BASE + 0x5600)  /* PPE_CFG_GRP_TBL6是查表生成GRP的第6张表。 */
#define SRE_PPE_CFG_GRP_TBL6_1_REG   (SRE_PPE_COMMON_BASE + 0x5604)  /* PPE_CFG_GRP_TBL6是查表生成GRP的第6张表。 */
#define SRE_PPE_CFG_GRP_TBL7_0_REG   (SRE_PPE_COMMON_BASE + 0x5700)  /* PPE_CFG_GRP_TBL7是查表生成GRP的第7张表。 */
#define SRE_PPE_CFG_GRP_TBL7_1_REG   (SRE_PPE_COMMON_BASE + 0x5704)  /* PPE_CFG_GRP_TBL7是查表生成GRP的第7张表。 */
#define SRE_PPE_CFG_GRP_TBL8_0_REG   (SRE_PPE_COMMON_BASE + 0x5800)  /* PPE_CFG_GRP_TBL8是查表生成GRP的第8张表。 */
#define SRE_PPE_CFG_GRP_TBL8_1_REG   (SRE_PPE_COMMON_BASE + 0x5804)  /* PPE_CFG_GRP_TBL8是查表生成GRP的第8张表。 */
#define SRE_PPE_CFG_GRP_TBL9_0_REG   (SRE_PPE_COMMON_BASE + 0x5900)  /* PPE_CFG_GRP_TBL9是查表生成GRP的第9张表。 */
#define SRE_PPE_CFG_GRP_TBL9_1_REG   (SRE_PPE_COMMON_BASE + 0x5904)  /* PPE_CFG_GRP_TBL9是查表生成GRP的第9张表。 */
#define SRE_PPE_CFG_GRP_TBL10_0_REG  (SRE_PPE_COMMON_BASE + 0x5A00)  /* PPE_CFG_GRP_TBL10是查表生成GRP的第10张表。 */
#define SRE_PPE_CFG_GRP_TBL10_1_REG  (SRE_PPE_COMMON_BASE + 0x5A04)  /* PPE_CFG_GRP_TBL10是查表生成GRP的第10张表。 */
#define SRE_PPE_CFG_GRP_CMP_TBL_VALUE_0_REG  (SRE_PPE_COMMON_BASE + 0x5B00)  /* PPE_CFG_GRP_CMP_TBL_VALUE是比较方式生成GRP的GRP的配置值 */
#define SRE_PPE_CFG_GRP_CMP_TBL_VALUE_1_REG  (SRE_PPE_COMMON_BASE + 0x5B04)  /* PPE_CFG_GRP_CMP_TBL_VALUE是比较方式生成GRP的GRP的配置值 */
#define SRE_PPE_CFG_GRP_CMP_TBL_VALUE_2_REG  (SRE_PPE_COMMON_BASE + 0x5B20)  /* PPE_CFG_GRP_CMP_TBL_VALUE是比较方式生成GRP的GRP的配置值 */
#define SRE_PPE_CFG_GRP_CMP_TBL_VALUE_3_REG  (SRE_PPE_COMMON_BASE + 0x5B24)  /* PPE_CFG_GRP_CMP_TBL_VALUE是比较方式生成GRP的GRP的配置值 */
#define SRE_PPE_CFG_VMID_TBL0_0_REG  (SRE_PPE_COMMON_BASE + 0x6000)  /* PPE_CFG_VMID_TBL0是生成vmid的第0张表。 */
#define SRE_PPE_CFG_VMID_TBL0_1_REG  (SRE_PPE_COMMON_BASE + 0x6004)  /* PPE_CFG_VMID_TBL0是生成vmid的第0张表。 */
#define SRE_PPE_CFG_VMID_TBL1_0_REG  (SRE_PPE_COMMON_BASE + 0x6080)  /* PPE_CFG_VMID_TBL1是生成vmid的第1张表。 */
#define SRE_PPE_CFG_VMID_TBL1_1_REG  (SRE_PPE_COMMON_BASE + 0x6084)  /* PPE_CFG_VMID_TBL1是生成vmid的第1张表。 */
#define SRE_PPE_CFG_VMID_TBL2_0_REG  (SRE_PPE_COMMON_BASE + 0x6100)  /* PPE_CFG_VMID_TBL2是生成vmid的第2张表。 */
#define SRE_PPE_CFG_VMID_TBL2_1_REG  (SRE_PPE_COMMON_BASE + 0x6104)  /* PPE_CFG_VMID_TBL2是生成vmid的第2张表。 */
#define SRE_PPE_CFG_VMID_TBL3_0_REG  (SRE_PPE_COMMON_BASE + 0x6180)  /* PPE_CFG_VMID_TBL3是生成vmid的第3张表。 */
#define SRE_PPE_CFG_VMID_TBL3_1_REG  (SRE_PPE_COMMON_BASE + 0x6184)  /* PPE_CFG_VMID_TBL3是生成vmid的第3张表。 */
#define SRE_PPE_CFG_VMID_TBL4_0_REG  (SRE_PPE_COMMON_BASE + 0x6200)  /* PPE_CFG_VMID_TBL4是生成vmid的第4张表。 */
#define SRE_PPE_CFG_VMID_TBL4_1_REG  (SRE_PPE_COMMON_BASE + 0x6204)  /* PPE_CFG_VMID_TBL4是生成vmid的第4张表。 */
#define SRE_PPE_CFG_VMID_TBL5_0_REG  (SRE_PPE_COMMON_BASE + 0x6280)  /* PPE_CFG_VMID_TBL5是生成vmid的第5张表。 */
#define SRE_PPE_CFG_VMID_TBL5_1_REG  (SRE_PPE_COMMON_BASE + 0x6284)  /* PPE_CFG_VMID_TBL5是生成vmid的第5张表。 */
#define SRE_PPE_CFG_VMID_TBL6_0_REG  (SRE_PPE_COMMON_BASE + 0x6300)  /* PPE_CFG_VMID_TBL6是生成vmid的第6张表。 */
#define SRE_PPE_CFG_VMID_TBL6_1_REG  (SRE_PPE_COMMON_BASE + 0x6304)  /* PPE_CFG_VMID_TBL6是生成vmid的第6张表。 */
#define SRE_PPE_CFG_VMID_TBL7_0_REG  (SRE_PPE_COMMON_BASE + 0x6380)  /* PPE_CFG_VMID_TBL7是生成vmid的第7张表。 */
#define SRE_PPE_CFG_VMID_TBL7_1_REG  (SRE_PPE_COMMON_BASE + 0x6384)  /* PPE_CFG_VMID_TBL7是生成vmid的第7张表。 */
#define SRE_PPE_CFG_VMID_TBL8_0_REG  (SRE_PPE_COMMON_BASE + 0x6400)  /* PPE_CFG_VMID_TBL8是生成vmid的第8张表。 */
#define SRE_PPE_CFG_VMID_TBL8_1_REG  (SRE_PPE_COMMON_BASE + 0x6404)  /* PPE_CFG_VMID_TBL8是生成vmid的第8张表。 */
#define SRE_PPE_CFG_VMID_TBL9_0_REG  (SRE_PPE_COMMON_BASE + 0x6480)  /* PPE_CFG_VMID_TBL9是生成vmid的第9张表。 */
#define SRE_PPE_CFG_VMID_TBL9_1_REG  (SRE_PPE_COMMON_BASE + 0x6484)  /* PPE_CFG_VMID_TBL9是生成vmid的第9张表。 */
#define SRE_PPE_CFG_VMID_TBL10_0_REG  (SRE_PPE_COMMON_BASE + 0x6500)  /* PPE_CFG_VMID_TBL0是生成vmid的第10张表。 */
#define SRE_PPE_CFG_VMID_TBL10_1_REG  (SRE_PPE_COMMON_BASE + 0x6504)  /* PPE_CFG_VMID_TBL0是生成vmid的第10张表。 */
#define SRE_PPE_CFG_VMID_CMP_TBL_VALUE_0_REG  (SRE_PPE_COMMON_BASE + 0x6580)  /* PPE_CFG_VMID_CMP_TBL_VALUE是比较方式生成VMID的VMID的配置值 */
#define SRE_PPE_CFG_VMID_CMP_TBL_VALUE_1_REG  (SRE_PPE_COMMON_BASE + 0x6584)  /* PPE_CFG_VMID_CMP_TBL_VALUE是比较方式生成VMID的VMID的配置值 */
#define SRE_PPE_CFG_VMID_CMP_TBL_VALUE_2_REG  (SRE_PPE_COMMON_BASE + 0x6590)  /* PPE_CFG_VMID_CMP_TBL_VALUE是比较方式生成VMID的VMID的配置值 */
#define SRE_PPE_CFG_VMID_CMP_TBL_VALUE_3_REG  (SRE_PPE_COMMON_BASE + 0x6594)  /* PPE_CFG_VMID_CMP_TBL_VALUE是比较方式生成VMID的VMID的配置值 */
#define SRE_PPE_CFG_GRP_VMID_CMP_TBL0_0_REG  (SRE_PPE_COMMON_BASE + 0x7000)  /* PPE_CFG_GRP_VMID_CMP_TBL0是比较方式生成GRP_VMID的第0张表。 */
#define SRE_PPE_CFG_GRP_VMID_CMP_TBL1_0_REG  (SRE_PPE_COMMON_BASE + 0x7100)  /* PPE_CFG_GRP_VMID_CMP_TBL1是比较方式生成GRP_VMID的第1张表。 */
#define SRE_PPE_CFG_GRP_VMID_CMP_TBL2_0_REG  (SRE_PPE_COMMON_BASE + 0x7200)  /* PPE_CFG_GRP_VMID_CMP_TBL2是比较方式生成GRP_VMID的第2张表。 */
#define SRE_PPE_CFG_GRP_VMID_CMP_TBL3_0_REG  (SRE_PPE_COMMON_BASE + 0x7300)  /* PPE_CFG_GRP_VMID_CMP_TBL3是比较方式生成GRP_VMID的第3张表。 */
#define SRE_PPE_CFG_GRP_VMID_CMP_TBL0_MSK_0_REG  (SRE_PPE_COMMON_BASE + 0x7B00)  /* PPE_CFG_GRP_VMID_CMP_TBL0_MSK是比较方式生成GRP_VMID的第0张表的掩码值。 */
#define SRE_PPE_CFG_GRP_VMID_CMP_TBL1_MSK_0_REG  (SRE_PPE_COMMON_BASE + 0x7B08)  /* PPE_CFG_GRP_VMID_CMP_TBL1_MSK是比较方式生成GRP_VMID的第1张表的掩码值。 */
#define SRE_PPE_CFG_GRP_VMID_CMP_TBL2_MSK_0_REG  (SRE_PPE_COMMON_BASE + 0x7B10)  /* PPE_CFG_GRP_VMID_CMP_TBL2_MSK是比较方式生成GRP_VMID的第2张表的掩码值。 */
#define SRE_PPE_CFG_GRP_VMID_CMP_TBL3_MSK_0_REG  (SRE_PPE_COMMON_BASE + 0x7B18)  /* PPE_CFG_GRP_VMID_CMP_TBL3_MSK是比较方式生成GRP_VMID的第3张表的掩码值。 */
#define SRE_PPE_INTEN_0_REG          (SRE_PPE_COMMON_BASE + 0x8000)  /* PPE_INTEN_0是使能中断寄存器0。 */
#define SRE_PPE_RINT_0_REG           (SRE_PPE_COMMON_BASE + 0x8004)  /* PPE_RINT_0是原始中断寄存器0。 */
#define SRE_PPE_INTSTS_0_REG         (SRE_PPE_COMMON_BASE + 0x8008)  /* PPE_INTSTS_0是中断状态寄存器0。 */
#define SRE_PPE_INTEN_1_REG          (SRE_PPE_COMMON_BASE + 0x8010)  /* PPE_INTEN_1是使能中断寄存器1。 */
#define SRE_PPE_RINT_1_REG           (SRE_PPE_COMMON_BASE + 0x8014)  /* PPE_RINT_1是原始中断寄存器1。 */
#define SRE_PPE_INTSTS_1_REG         (SRE_PPE_COMMON_BASE + 0x8018)  /* PPE_INTSTS_1是中断状态寄存器1。 */
#define SRE_PPE_INTEN_2_REG          (SRE_PPE_COMMON_BASE + 0x8020)  /* PPE_RINT_2是使能中断寄存器2。 */
#define SRE_PPE_RINT_2_REG           (SRE_PPE_COMMON_BASE + 0x8024)  /* PPE_RINT_2是原始中断寄存器2。 */
#define SRE_PPE_INTSTS_2_REG         (SRE_PPE_COMMON_BASE + 0x8028)  /* PPE_INTSTS_2是中断状态寄存器2。 */
#define SRE_PPE_CFG_STS_MODE_0_REG   (SRE_PPE_COMMON_BASE + 0xA000)  /* PPE_CFG_STS_MODE_0是寄存器属性为为CNT_CYC读清使能寄存器0。 */
#define SRE_PPE_CFG_STS_MODE_1_REG   (SRE_PPE_COMMON_BASE + 0xA004)  /* PPE_CFG_STS_MODE_1是寄存器属性为为CNT_CYC读清使能寄存器1。 */
#define SRE_PPE_HIS_PKT_GRP_CNT_0_REG  (SRE_PPE_COMMON_BASE + 0xA100)  /* PPE_HIS_PKT_GRP_CN是接收报文按GRP的统计。 */
#define SRE_PPE_HIS_PKT_GRP_CNT_1_REG  (SRE_PPE_COMMON_BASE + 0xA104)  /* PPE_HIS_PKT_GRP_CN是接收报文按GRP的统计。 */
#define SRE_PPE_HIS_PKT_QOS_CNT_0_REG  (SRE_PPE_COMMON_BASE + 0xA180)  /* PPE_HIS_PKT_QOS_CN是接收报文按QOS的统计。 */
#define SRE_PPE_HIS_PKT_QOS_CNT_1_REG  (SRE_PPE_COMMON_BASE + 0xA184)  /* PPE_HIS_PKT_QOS_CN是接收报文按QOS的统计。 */
#define SRE_PPE_HIS_DROP_PKT_QOS_CNT_0_REG  (SRE_PPE_COMMON_BASE + 0xA1A0)  /* PPE_HIS_DROP_PKT_QOS_CNT是丢弃报文按QOS的统计。 */
#define SRE_PPE_HIS_DROP_PKT_QOS_CNT_1_REG  (SRE_PPE_COMMON_BASE + 0xA1A4)  /* PPE_HIS_DROP_PKT_QOS_CNT是丢弃报文按QOS的统计。 */
#define SRE_PPE_HIS_MST_WR_CNT_0_REG  (SRE_PPE_COMMON_BASE + 0xA1C0)  /* PPE_HIS_MST_WR_CNT是MASTER写操作的统计。 */
#define SRE_PPE_HIS_MST_WR_CNT_1_REG  (SRE_PPE_COMMON_BASE + 0xA1C4)  /* PPE_HIS_MST_WR_CNT是MASTER写操作的统计。 */
#define SRE_PPE_HIS_MST_RD_CNT_0_REG  (SRE_PPE_COMMON_BASE + 0xA1D8)  /* PPE_HIS_MST_RD_CNT是MASTER写操作的统计。 */
#define SRE_PPE_HIS_MST_RD_CNT_1_REG  (SRE_PPE_COMMON_BASE + 0xA1DC)  /* PPE_HIS_MST_RD_CNT是MASTER写操作的统计。 */
#define SRE_PPE_HIS_REQ_BMU_FAIL_CNT_REG  (SRE_PPE_COMMON_BASE + 0xA1F0)  /* PPE_HIS_REQ_BMU_FAIL_CNT是申请BMU失败的统计。 */
#define SRE_PPE_HIS_REQ_BMU_OK_CNT_REG  (SRE_PPE_COMMON_BASE + 0xA1F4)  /* PPE_HIS_REQ_BMU_OK_CNT是申请BMU成功的统计。 */
#define SRE_PPE_CURR_BUF_CNT_0_REG   (SRE_PPE_COMMON_BASE + 0xA200)  /* PPE_CURR_BUF_CNT。
0xA200~0xA27C依次是缓存pool_0~pool_31的缓存指针个数 */
#define SRE_PPE_CURR_BUF_CNT_1_REG   (SRE_PPE_COMMON_BASE + 0xA204)  /* PPE_CURR_BUF_CNT。
0xA200~0xA27C依次是缓存pool_0~pool_31的缓存指针个数 */
#define SRE_PPE_CURR_CMM_CAN_RST_REG  (SRE_PPE_COMMON_BASE + 0xA300)  /* PPE_CURR_CAN_RST为该通道是否可以复位。 */
#define SRE_PPE_HIS_FIFO_ERR_REG     (SRE_PPE_COMMON_BASE + 0xA304)  /* PPE_HIS_FIFO_ERR是内部FIFO溢出。 */
#define SRE_PPE_CURR_FIFO_0_REG      (SRE_PPE_COMMON_BASE + 0xA308)  /* PPE_CURR_FIFO_0为BMU返回数据FIFO的状态。 */
#define SRE_PPE_CURR_FIFO_1_REG      (SRE_PPE_COMMON_BASE + 0xA30C)  /* PPE_CURR_FIFO_0为BMU申请命令FIFO的状态。 */
#define SRE_PPE_HIS_MST_RD_LAT_0_REG  (SRE_PPE_COMMON_BASE + 0xA310)  /* PPE_HIS_MST_RD_LAT是MASTER读操作的延时统计。 */
#define SRE_PPE_HIS_MST_RD_LAT_1_REG  (SRE_PPE_COMMON_BASE + 0xA314)  /* PPE_HIS_MST_RD_LAT是MASTER读操作的延时统计。 */
#define SRE_PPE_HIS_MST_WR_LAT_0_REG  (SRE_PPE_COMMON_BASE + 0xA328)  /* PPE_HIS_MST_WR_LAT是MASTER写操作的延时统计。 */
#define SRE_PPE_HIS_MST_WR_LAT_1_REG  (SRE_PPE_COMMON_BASE + 0xA32C)  /* PPE_HIS_MST_WR_LAT是MASTER写操作的延时统计。 */
#define SRE_PPE_HIS_MST_RD_STS_1_0_REG  (SRE_PPE_COMMON_BASE + 0xA340)  /* PPE_HIS_MST_RD_STS_1是MASTER读操作的状态1。 */
#define SRE_PPE_HIS_MST_RD_STS_1_1_REG  (SRE_PPE_COMMON_BASE + 0xA344)  /* PPE_HIS_MST_RD_STS_1是MASTER读操作的状态1。 */
#define SRE_PPE_HIS_MST_RD_STS_2_0_REG  (SRE_PPE_COMMON_BASE + 0xA358)  /* PPE_HIS_MST_RD_STS_2是MASTER读操作的状态2。 */
#define SRE_PPE_HIS_MST_RD_STS_2_1_REG  (SRE_PPE_COMMON_BASE + 0xA35C)  /* PPE_HIS_MST_RD_STS_2是MASTER读操作的状态2。 */
#define SRE_PPE_HIS_MST_WR_STS_1_0_REG  (SRE_PPE_COMMON_BASE + 0xA370)  /* PPE_HIS_MST_RD_STS_1是MASTER写操作的状态。 */
#define SRE_PPE_HIS_MST_WR_STS_1_1_REG  (SRE_PPE_COMMON_BASE + 0xA374)  /* PPE_HIS_MST_RD_STS_1是MASTER写操作的状态。 */
#define SRE_PPE_HIS_MST_WR_STS_2_0_REG  (SRE_PPE_COMMON_BASE + 0xA388)  /* PPE_HIS_MST_RD_STS_2是MASTER写操作的状态。 */
#define SRE_PPE_HIS_MST_WR_STS_2_1_REG  (SRE_PPE_COMMON_BASE + 0xA38C)  /* PPE_HIS_MST_RD_STS_2是MASTER写操作的状态。 */
#define SRE_PPE_HIS_MST_WR_STS_3_0_REG  (SRE_PPE_COMMON_BASE + 0xA3A0)  /* PPE_HIS_MST_RD_STS_3是MASTER写操作的状态。 */
#define SRE_PPE_HIS_MST_WR_STS_3_1_REG  (SRE_PPE_COMMON_BASE + 0xA3A4)  /* PPE_HIS_MST_RD_STS_3是MASTER写操作的状态。 */
#define SRE_PPE_HIS_MST_RD_STS_3_0_REG  (SRE_PPE_COMMON_BASE + 0xA3B8)  /* PPE_HIS_MST_RD_STS_3是MASTER写操作的状态。 */
#define SRE_PPE_HIS_MST_RD_STS_3_1_REG  (SRE_PPE_COMMON_BASE + 0xA3BC)  /* PPE_HIS_MST_RD_STS_3是MASTER写操作的状态。 */
#define SRE_PPE_CFG_MST_STS_CLR_0_REG  (SRE_PPE_COMMON_BASE + 0xA3D0)  /* PPE_CFG_MST_STS_CLR是MASTER统计清除寄存器。 */
#define SRE_PPE_CFG_MST_STS_CLR_1_REG  (SRE_PPE_COMMON_BASE + 0xA3D4)  /* PPE_CFG_MST_STS_CLR是MASTER统计清除寄存器。 */
#define SRE_PPE_CFG_OAM_TX_ITEM_STS_0_REG  (SRE_PPE_COMMON_BASE + 0xB000)  /* PPE_CFG_OAM_TX_TIEM是Y.1731发送方向的流匹配统计。 */
#define SRE_PPE_CFG_OAM_TX_ITEM_STS_1_REG  (SRE_PPE_COMMON_BASE + 0xB004)  /* PPE_CFG_OAM_TX_TIEM是Y.1731发送方向的流匹配统计。 */
#define SRE_PPE_CFG_TIME_SYNC_H_REG  (SRE_PPE_COMMON_BASE + 0xC000)  /* 时间同步秒时间高位配置寄存器。 */
#define SRE_PPE_CFG_TIME_SYNC_M_REG  (SRE_PPE_COMMON_BASE + 0xC004)  /* 时间同步秒时间低位配置寄存器。 */
#define SRE_PPE_CFG_TIME_SYNC_L_REG  (SRE_PPE_COMMON_BASE + 0xC008)  /* 时间同步纳秒时间配置寄存器。 */
#define SRE_PPE_CFG_TIME_SYNC_RDY_REG  (SRE_PPE_COMMON_BASE + 0xC00C)  /* 时间同步使能配置寄存器。 */
#define SRE_PPE_CFG_PTP_OFFSET_ADD_RDY_REG  (SRE_PPE_COMMON_BASE + 0xC010)  /* 时间同步偏移使能配置寄存器。 */
#define SRE_PPE_CFG_TIME_CYC_NS_REG  (SRE_PPE_COMMON_BASE + 0xC014)  /* RTC计时时钟周期时间纳秒整数值配置寄存器。 */
#define SRE_PPE_CFG_TIME_CYC_NS_DEC_REG  (SRE_PPE_COMMON_BASE + 0xC018)  /* RTC计时时钟周期时间纳秒小数值配置寄存器。 */
#define SRE_PPE_CFG_SYS_CYC_REG      (SRE_PPE_COMMON_BASE + 0xC01C)  /* 系统时钟周期时间配置寄存器。 */
#define SRE_PPE_CFG_INT_1PPS_EN_REG  (SRE_PPE_COMMON_BASE + 0xC020)  /* 1PPS中断使能寄存器。 */
#define SRE_PPE_CFG_INTS_1PPS_CLR_REG  (SRE_PPE_COMMON_BASE + 0xC024)  /* 1PPS中断清除寄存器。 */
#define SRE_PPE_CFG_INTS_1PPS_REG    (SRE_PPE_COMMON_BASE + 0xC028)  /* 1PPS中断状态寄存器。 */
#define SRE_PPE_CURR_TIME_OUT_H_REG  (SRE_PPE_COMMON_BASE + 0xC02C)  /* 本地时间秒高位输出寄存器。 */
#define SRE_PPE_CURR_TIME_OUT_L_REG  (SRE_PPE_COMMON_BASE + 0xC030)  /* 本地时间秒低位输出寄存器。 */
#define SRE_PPE_CURR_TIME_OUT_NS_REG  (SRE_PPE_COMMON_BASE + 0xC034)  /* 本地时间纳秒输出寄存器。 */
#define SRE_PPE_CFG_TS_CLK_SEL_REG   (SRE_PPE_COMMON_BASE + 0xC038)  /* 本地计时时钟选择寄存器 */
#define SRE_PPE_CFG_SYS_TIME_OFFSET_REG  (SRE_PPE_COMMON_BASE + 0xC03C)  /* 系统时钟采样时间补偿偏移值配置寄存器。 */


/******************************************************************************/
/*                      P650 PPE_TNL 寄存器定义                               */
/******************************************************************************/

#if 0         /* z00202052 */
#define SRE_PPE_TNL_BASE                                   (0x12800000)
#else
#define SRE_PPE_TNL_BASE                                   (0xe2800000)
#endif        /* z00202052 */

#define SRE_PPE_TNL_CFG_TX_FIFO_THRSLD_REG  (SRE_PPE_TNL_BASE + 0x400)  /* PPE_CFG_TX_FIFO_THRSLD为发送FIFO水线寄存器。 */
#define SRE_PPE_TNL_CFG_RX_FIFO_THRSLD_REG  (SRE_PPE_TNL_BASE + 0x404)  /* PPE_CFG_RX_FIFO_THRSLD为接收FIFO水线寄存器。 */
#define SRE_PPE_TNL_CFG_MAX_FRAME_LEN_REG  (SRE_PPE_TNL_BASE + 0x408)  /* MAX_FRAME_LEN为接收超长帧界限寄存器。 */
#define SRE_PPE_TNL_CFG_TX_PAUSE_REG   (SRE_PPE_TNL_BASE + 0x40C)  /* PPE_CFG_TX_PAUSE为发送流控控制寄存器。 */
#define SRE_PPE_TNL_CFG_RX_FIFO_PAUSE_THRSLD_REG  (SRE_PPE_TNL_BASE + 0x410)  /* PPE_CFG_RX_FIFO_PAUSE_THRSLD为接收FIFO的流控制水线寄存器。 */
#define SRE_PPE_TNL_CFG_RX_FIFO_BUS_THRSLD_REG  (SRE_PPE_TNL_BASE + 0x414)  /* PPE_CFG_RX_FIFO_BUS_THRSLD为接收FIFO的反压总线的水线寄存器。 */
#define SRE_PPE_TNL_CFG_TX_BD_ADDR_THRSLD_REG  (SRE_PPE_TNL_BASE + 0x418)  /* PPE_CFG_TX_BD_ADDR_THRSLD为发送描述符地址的FIFO水线寄存器。 */
#define SRE_PPE_TNL_CFG_XGE_MODE_REG   (SRE_PPE_TNL_BASE + 0x41C)  /* PPE_CFG_XGE_MODE配置该通道对接的是GE还是XGE */
#define SRE_PPE_TNL_CFG_TX_PKT_BD_ADDR_REG  (SRE_PPE_TNL_BASE + 0x420)  /* PPE_CFG_TX_PKT_BUF_ADDR为发送描述符的地址。 */
#define SRE_PPE_TNL_CFG_BUS_CTRL_REG   (SRE_PPE_TNL_BASE + 0x424)  /* PPE_CFG_BUS_CTRL为总线控制寄存器 */
#define SRE_PPE_TNL_CFG_RX_CTRL_REG    (SRE_PPE_TNL_BASE + 0x428)  /* PPE_CFG_RX_CTRL为接收控制寄存器。 */
#define SRE_PPE_TNL_CFG_RX_WE_TIMER_REG  (SRE_PPE_TNL_BASE + 0x42C)  /* PPE_CFG_RX_PD_TIMER为接收写work entry失败后的超时寄存器。 */
#define SRE_PPE_TNL_CFG_REL_BMU_TIMER_REG  (SRE_PPE_TNL_BASE + 0x430)  /* PPE_CFG_REL_BMU_TIMER为释放BMU配置寄存器。 */
#define SRE_PPE_TNL_CFG_PAUSE_IDLE_CNT_REG  (SRE_PPE_TNL_BASE + 0x434)  /* PPE_CFG_PAUSE_IDLE_CNT是发送PAUSE帧控制寄存器 */
#define SRE_PPE_TNL_CFG_RX_PKT_MODE_REG  (SRE_PPE_TNL_BASE + 0x438)  /* PPE_CFG_RX_PKT_MODE为接收报文输入模式。 */
#define SRE_PPE_TNL_CFG_RX_VLAN_TAG_REG  (SRE_PPE_TNL_BASE + 0x43C)  /* PPE_CFG_RX_VLAN_TAG是接收报文的2层VLAN的外层tag值 */
#define SRE_PPE_TNL_CFG_TX_DECT_EN_REG  (SRE_PPE_TNL_BASE + 0x440)  /* PPE_CFG_TX_DECT_EN是发送1588DECT使能 */
#define SRE_PPE_TNL_CFG_TX_VLAN_TAG_REG  (SRE_PPE_TNL_BASE + 0x444)  /* 发送DECT检测的VLAN的TAG配置寄存器。 */
#define SRE_PPE_TNL_CFG_TX_PTP_DPN_REG  (SRE_PPE_TNL_BASE + 0x448)  /* 发送DECT检测的PTP报文UDP的目的端口号配置寄存器。 */
#define SRE_PPE_TNL_CFG_QOS_GRP_VMID_GEN_REG  (SRE_PPE_TNL_BASE + 0x500)  /* PPE_CFG_QOS_GRP_VMID_GEN为QOS、GRP、VMID的生成方式寄存器。 */
#define SRE_PPE_TNL_CFG_TAG_TT_GEN_REG  (SRE_PPE_TNL_BASE + 0x504)  /* PPE_CFG_TAG_TT_GEN为TAG、TT的生成方式寄存器 */
#define SRE_PPE_TNL_CFG_PARSE_TAG_REG  (SRE_PPE_TNL_BASE + 0x508)  /* PPE_CFG_PARSE_TAG为解析模式下各元的掩码配置寄存器 */
#define SRE_PPE_TNL_CFG_TAG_OFFSET_REG  (SRE_PPE_TNL_BASE + 0x50C)  /* PPE_CFG_TAG_OFFSET是掩码模式计算tag时选128字节报文的偏移寄存器配置 */
#define SRE_PPE_TNL_CFG_TAG_BYTE_MASK1_REG  (SRE_PPE_TNL_BASE + 0x510)  /* PPE_CFG_TAG_BIT_MASK1是掩码模式计算tag时选128字节报文的第0~31字节掩码配置寄存器。 */
#define SRE_PPE_TNL_CFG_TAG_BYTE_MASK2_REG  (SRE_PPE_TNL_BASE + 0x514)  /* PPE_CFG_TAG_BIT_MASK2是掩码模式计算tag时选128字节报文的第32~63字节字节掩码配置寄存器。 */
#define SRE_PPE_TNL_CFG_TAG_BYTE_MASK3_REG  (SRE_PPE_TNL_BASE + 0x518)  /* PPE_CFG_TAG_BIT_MASK3是掩码模式计算tag时选128字节报文的第64~95字节掩码配置寄存器。 */
#define SRE_PPE_TNL_CFG_TAG_BYTE_MASK4_REG  (SRE_PPE_TNL_BASE + 0x51C)  /* PPE_CFG_TAG_BIT_MASK3是掩码模式计算tag时选128字节报文的第96~127字节掩码配置寄存器。 */
#define SRE_PPE_TNL_CFG_TAG_OTHER_TYPE_REG  (SRE_PPE_TNL_BASE + 0x520)  /* PPE_CFG_TAG_BIT_MASK是解析模式下4种非IP报文ID配置寄存器 */
#define SRE_PPE_TNL_CFG_TAG_BIT_MASK_REG  (SRE_PPE_TNL_BASE + 0x524)  /* PPE_CFG_TAG_BIT_MASK是掩码模式计算tag时选128字节报文中的2个按位掩码字节的配置寄存器。 */
#define SRE_PPE_TNL_CFG_AR_TAG1_CFG_REG  (SRE_PPE_TNL_BASE + 0x528)  /* PPE_CFG_AR_TAG1_CFG是AR的特殊VLAN_ID生成指定TAG的配置。 */
#define SRE_PPE_TNL_CFG_AR_TAG2_CFG_REG  (SRE_PPE_TNL_BASE + 0x52C)  /* PPE_CFG_AR_TAG1_CFG是AR的指定类型报文生成指定TAG的配置。 */
#define SRE_PPE_TNL_CFG_AR_SPE_CFG_REG  (SRE_PPE_TNL_BASE + 0x530)  /* PPE_CFG_AR_SPE_CFG是AR的2种指定TAG。 */
#define SRE_PPE_TNL_CFG_PRO_CHECK_EN_REG  (SRE_PPE_TNL_BASE + 0x534)  /* PPE_CFG_PRO_CHECK_EN是协议检查的使能。 */
#define SRE_PPE_TNL_CFG_RX_PKT_INT_REG  (SRE_PPE_TNL_BASE + 0x538)  /* PPE_CFG_RX_PKT_INT是接收到指定数目报文或接收报文超时上报中断的配置。 */
#define SRE_PPE_TNL_CFG_HEAT_DECT_TIME0_REG  (SRE_PPE_TNL_BASE + 0x53C)  /* *704* */
#define SRE_PPE_TNL_CFG_HEAT_DECT_TIME1_REG  (SRE_PPE_TNL_BASE + 0x540)  /* PPE_CFG_HEAT_DECT_TIME1是状态机心跳检测超时寄存器配置寄存器1 */
#define SRE_PPE_TNL_CFG_TNL_TO_BE_RST_REG  (SRE_PPE_TNL_BASE + 0x544)  /* PPE_CFG_TNL_TO_BE_RST为该通道是否将要复位。 */
#define SRE_PPE_TNL_CFG_DELAY_CLR_REG  (SRE_PPE_TNL_BASE + 0x548)  /* PPE_CFG_DELAY_CLR是读写DDR的最大延时。 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_0_REG  (SRE_PPE_TNL_BASE + 0x580)  /* PPE_CFG_CPU_ADD_ADDR是16个CPU推送发送描述符的地址，0x0580~0x05BC依次是CPU0~CPU15的推送地址 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_1_REG  (SRE_PPE_TNL_BASE + 0x584)  /* PPE_CFG_CPU_ADD_ADDR是16个CPU推送发送描述符的地址，0x0580~0x05BC依次是CPU0~CPU15的推送地址 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL0_REG  (SRE_PPE_TNL_BASE + 0x5C0)  /* PPE_CFG_CPU_ADD_ADDR_FAIL0是CPU0推送发送描述符失败指示 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL1_REG  (SRE_PPE_TNL_BASE + 0x5C4)  /* PPE_CFG_CPU_ADD_ADDR_FAIL1是CPU1推送发送描述符失败指示 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL2_REG  (SRE_PPE_TNL_BASE + 0x5C8)  /* PPE_CFG_CPU_ADD_ADDR_FAIL2是CPU2推送发送描述符失败指示 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL3_REG  (SRE_PPE_TNL_BASE + 0x5CC)  /* PPE_CFG_CPU_ADD_ADDR_FAIL3是CPU3推送发送描述符失败指示 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL4_REG  (SRE_PPE_TNL_BASE + 0x5D0)  /* PPE_CFG_CPU_ADD_ADDR_FAIL4是CPU4推送发送描述符失败指示 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL5_REG  (SRE_PPE_TNL_BASE + 0x5D4)  /* PPE_CFG_CPU_ADD_ADDR_FAIL5是CPU5推送发送描述符失败指示 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL6_REG  (SRE_PPE_TNL_BASE + 0x5D8)  /* PPE_CFG_CPU_ADD_ADDR_FAIL6是CPU6推送发送描述符失败指示 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL7_REG  (SRE_PPE_TNL_BASE + 0x5DC)  /* PPE_CFG_CPU_ADD_ADDR_FAIL7是CPU7推送发送描述符失败指示 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL8_REG  (SRE_PPE_TNL_BASE + 0x5E0)  /* PPE_CFG_CPU_ADD_ADDR_FAIL8是CPU8推送发送描述符失败指示 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL9_REG  (SRE_PPE_TNL_BASE + 0x5E4)  /* PPE_CFG_CPU_ADD_ADDR_FAIL9是CPU9推送发送描述符失败指示 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL10_REG  (SRE_PPE_TNL_BASE + 0x5E8)  /* PPE_CFG_CPU_ADD_ADDR_FAIL10是CPU10推送发送描述符失败指示 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL11_REG  (SRE_PPE_TNL_BASE + 0x5EC)  /* PPE_CFG_CPU_ADD_ADDR_FAIL11是CPU11推送发送描述符失败指示 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL12_REG  (SRE_PPE_TNL_BASE + 0x5F0)  /* PPE_CFG_CPU_ADD_ADDR_FAIL12是CPU12推送发送描述符失败指示 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL13_REG  (SRE_PPE_TNL_BASE + 0x5F4)  /* PPE_CFG_CPU_ADD_ADDR_FAIL13是CPU13推送发送描述符失败指示 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL14_REG  (SRE_PPE_TNL_BASE + 0x5F8)  /* PPE_CFG_CPU_ADD_ADDR_FAIL14是CPU14推送发送描述符失败指示 */
#define SRE_PPE_TNL_CFG_CPU_ADD_ADDR_FAIL15_REG  (SRE_PPE_TNL_BASE + 0x5FC)  /* PPE_CFG_CPU_ADD_ADDR_FAIL15是CPU15推送发送描述符失败指示 */
#define SRE_PPE_TNL_INTEN_REG          (SRE_PPE_TNL_BASE + 0x600)  /* PPE_INTEN是使能中断寄存器。 */
#define SRE_PPE_TNL_RINT_REG           (SRE_PPE_TNL_BASE + 0x604)  /* PPE_RINT是原始中断寄存器。 */
#define SRE_PPE_TNL_INTSTS_REG         (SRE_PPE_TNL_BASE + 0x608)  /* PPE_INTSTS是中断状态寄存器。 */
#define SRE_PPE_TNL_INT_VMID_REG       (SRE_PPE_TNL_BASE + 0x60C)  /* PPE_INT_VMID是中断VMID寄存器。 */
#define SRE_PPE_TNL_CFG_AXI_DBG_REG    (SRE_PPE_TNL_BASE + 0x610)  /* PPE_CFG_AXI_DBG是AXI DEBUG寄存器。 */
#define SRE_PPE_TNL_CFG_STS_MODE_REG   (SRE_PPE_TNL_BASE + 0x700)  /* PPE_CFG_STS_MODE是寄存器属性为为CNT_CYC读清使能寄存器1。 */
#define SRE_PPE_TNL_HIS_RX_PKT_OK_CNT_REG  (SRE_PPE_TNL_BASE + 0x704)  /* PPE_HIS_RX_PKT_OK_CNT是成功接收且添加POE成功的报文统计。 */
#define SRE_PPE_TNL_HIS_RX_PKT_DROP_FUL_CNT_REG  (SRE_PPE_TNL_BASE + 0x708)  /* PPE_HIS_RX_PKT_DROP_FUL_CNT是因FIFO满整包丢弃的统计。 */
#define SRE_PPE_TNL_HIS_RX_PKT_DROP_PRT_CNT_REG  (SRE_PPE_TNL_BASE + 0x70C)  /* PPE_HIS_RX_PKT_DROP_PRT_CNT是因FIFO满报文截断的统计。 */
#define SRE_PPE_TNL_HIS_RX_PKT_LOW_QOS_CNT_REG  (SRE_PPE_TNL_BASE + 0x710)  /* PPE_HIS_RX_PKT_LOW_QOS_CNT是因QOS不足丢弃的报文统计。 */
#define SRE_PPE_TNL_HIS_RX_PKT_NO_BUF_CNT_REG  (SRE_PPE_TNL_BASE + 0x714)  /* PPE_HIS_RX_PKT_NO_BUF_CNT是因没有对应BUF且接收FIFO丢弃报文的统计。 */
#define SRE_PPE_TNL_HIS_TX_PKT_OK_CNT_REG  (SRE_PPE_TNL_BASE + 0x718)  /* PPE_HIS_TX_PKT_OK_CNT是成功发送的报文统计。 */
#define SRE_PPE_TNL_HIS_TX_PKT_EPT_CNT_REG  (SRE_PPE_TNL_BASE + 0x71C)  /* PPE_HIS_TX_PKT_EPT_CNT是发送FIFO空报文截断统计。 */
#define SRE_PPE_TNL_HIS_TX_PKT_CS_FAIL_CNT_REG  (SRE_PPE_TNL_BASE + 0x720)  /* PPE_HIS_TX_PKT_CS_FAIL_CNT是发送计算checksum失败的报文统计。 */
#define SRE_PPE_TNL_HIS_REL_BUF_FAIL_CNT_REG  (SRE_PPE_TNL_BASE + 0x724)  /* PPE_HIS_REL_BUF_FAIL_CNT是发送释放缓存失败的统计。 */
#define SRE_PPE_TNL_HIS_RX_ADD_POE_TM_BMU_FAIL_CNT_REG  (SRE_PPE_TNL_BASE + 0x728)  /* PPE_HIS_RX_ADD_POE_TM_BMU_FAIL_CNT是接收写POE/TM/BMU失败的统计。 */
#define SRE_PPE_TNL_HIS_RX_ADD_TM_BMU_OK_CNT_REG  (SRE_PPE_TNL_BASE + 0x72C)  /* PPE_HIS_RX_ADD_TM_BMU_OK_CNTT是接收写TM/BMU的成功统计统计。 */
#define SRE_PPE_TNL_CURR_CFF_DATA_NUM_REG  (SRE_PPE_TNL_BASE + 0x730)  /* PPE_CURR_DATA_NUM为配置FIFO数据个数寄存器。 */
#define SRE_PPE_TNL_CURR_TNL_CAN_RST_REG  (SRE_PPE_TNL_BASE + 0x734)  /* PPE_CURR_TNL_CAN_RST为该通道是否可以复位。 */
#define SRE_PPE_TNL_HIS_PRO_ERR_REG    (SRE_PPE_TNL_BASE + 0x738)  /* PPE_HIS_PRO_ERR是协议检查曾经检查到的错误。 */
#define SRE_PPE_TNL_HIS_TNL_FIFO_ERR_REG  (SRE_PPE_TNL_BASE + 0x73C)  /* PPE_HIS_TNL_FIFO_ERR是内部FIFO溢出。 */
#define SRE_PPE_TNL_CURR_RX_ST_REG     (SRE_PPE_TNL_BASE + 0x740)  /* PPE_CURR_RX_ST是接收状态机当前状态。 */
#define SRE_PPE_TNL_CURR_TX_ST_REG     (SRE_PPE_TNL_BASE + 0x744)  /* PPE_CURR_TX_ST是接收状态机当前状态。 */
#define SRE_PPE_TNL_CURR_RX_FIFO0_REG  (SRE_PPE_TNL_BASE + 0x748)  /* PPE_CURR_RX_FIFO0是接收FIFO状态0。 */
#define SRE_PPE_TNL_CURR_RX_FIFO1_REG  (SRE_PPE_TNL_BASE + 0x74C)  /* PPE_CURR_RX_FIFO1是接收FIFO状态1。 */
#define SRE_PPE_TNL_CURR_TX_FIFO0_REG  (SRE_PPE_TNL_BASE + 0x750)  /* PPE_CURR_TX_FIFO0是发送FIFO状态0。 */
#define SRE_PPE_TNL_CURR_TX_FIFO1_REG  (SRE_PPE_TNL_BASE + 0x754)  /* PPE_CURR_TX_FIFO1是发送FIFO状态1。 */
#define SRE_PPE_TNL_CURR_DDR_DELAY_REG  (SRE_PPE_TNL_BASE + 0x758)  /* PPE_CURR_DDR_DELAY为读写DDR的最大延时。 */
#define SRE_PPE_TNL_ECO0_REG           (SRE_PPE_TNL_BASE + 0x75C)  /* PPE_ECO0是eco寄存器0。 */
#define SRE_PPE_TNL_ECO1_REG           (SRE_PPE_TNL_BASE + 0x760)  /* PPE_ECO1是eco寄存器1。 */
#define SRE_PPE_TNL_ECO2_REG           (SRE_PPE_TNL_BASE + 0x764)  /* PPE_ECO2是eco寄存器2。 */
#define SRE_PPE_TNL_HIS_RX_MAC_PKT_CNT_REG  (SRE_PPE_TNL_BASE + 0x800)  /* PPE_HIS_RX_MAC_PKT_CNT是接收到MAC侧的报文个数。 */
#define SRE_PPE_TNL_HIS_RX_WR_BD_OK_PKT_CNT_REG  (SRE_PPE_TNL_BASE + 0x804)  /* PPE_HIS_RX_WR_BD_OK_PKT_CNT是成功写入接收描述符的报文个数。 */
#define SRE_PPE_TNL_HIS_TX_BD_ADDR_WR_CNT_REG  (SRE_PPE_TNL_BASE + 0x808)  /* PPE_HIS_TX_BD_ADDR_WR_CNT是被写入发送描述符地址个数。 */
#define SRE_PPE_TNL_HIS_RX_REL_BUF_CNT_REG  (SRE_PPE_TNL_BASE + 0x80C)  /* PPE_HIS_RX_REL_BUF_CNT是接收释放缓存的个数。 */
#define SRE_PPE_TNL_HIS_TX_REL_BUF_CNT_REG  (SRE_PPE_TNL_BASE + 0x810)  /* PPE_HIS_TX_REL_BUF_CNT是发送释放缓存的个数。 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_0_REG  (SRE_PPE_TNL_BASE + 0x1000)  /* PPE_CFG_L3_TYPE_VALUE_0为第0种3层类型配置值 */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_0_REG  (SRE_PPE_TNL_BASE + 0x1004)  /* PPE_CFG_L3_TYPE_VALUE为第0种3层类型配置值的MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_0_REG  (SRE_PPE_TNL_BASE + 0x1008)  /* PPE_CFG_L3_TYPE_VALUE为第0种3层类型的头部协议域偏移值
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_1_REG  (SRE_PPE_TNL_BASE + 0x1010)  /* PPE_CFG_L3_TYPE_VALUE_1为第1种3层类型配置值 */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_1_REG  (SRE_PPE_TNL_BASE + 0x1014)  /* PPE_CFG_L3_TYPE_VALUE为第1种3层类型配置值的MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_1_REG  (SRE_PPE_TNL_BASE + 0x1018)  /* PPE_CFG_L3_TYPE_VALUE为第1种3层类型的头部协议域偏移值
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_2_REG  (SRE_PPE_TNL_BASE + 0x1020)  /* PPE_CFG_L3_TYPE_VALUE_2为第2种3层类型配置值 */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_2_REG  (SRE_PPE_TNL_BASE + 0x1024)  /* PPE_CFG_L3_TYPE_VALUE为第2种3层类型配置值的MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_2_REG  (SRE_PPE_TNL_BASE + 0x1028)  /* PPE_CFG_L3_TYPE_VALUE为第2种3层类型的头部协议域偏移值
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_3_REG  (SRE_PPE_TNL_BASE + 0x1030)  /* PPE_CFG_L3_TYPE_VALUE_3为第3种3层类型配置值 */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_3_REG  (SRE_PPE_TNL_BASE + 0x1034)  /* PPE_CFG_L3_TYPE_VALUE为第3种3层类型配置值的MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_3_REG  (SRE_PPE_TNL_BASE + 0x1038)  /* PPE_CFG_L3_TYPE_VALUE为第3种3层类型的头部协议域偏移值
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_4_REG  (SRE_PPE_TNL_BASE + 0x1040)  /* PPE_CFG_L3_TYPE_VALUE_4为第4种3层类型配置值 */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_4_REG  (SRE_PPE_TNL_BASE + 0x1044)  /* PPE_CFG_L3_TYPE_VALUE为第4种3层类型配置值的MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_4_REG  (SRE_PPE_TNL_BASE + 0x1048)  /* PPE_CFG_L3_TYPE_VALUE为第4种3层类型的头部协议域偏移值
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_5_REG  (SRE_PPE_TNL_BASE + 0x1050)  /* PPE_CFG_L3_TYPE_VALUE_5为第5种3层类型配置值 */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_5_REG  (SRE_PPE_TNL_BASE + 0x1054)  /* PPE_CFG_L3_TYPE_VALUE为第5种3层类型配置值的MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_5_REG  (SRE_PPE_TNL_BASE + 0x1058)  /* PPE_CFG_L3_TYPE_VALUE为第5种3层类型的头部协议域偏移值
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_6_REG  (SRE_PPE_TNL_BASE + 0x1060)  /* PPE_CFG_L3_TYPE_VALUE_6为第6种3层类型配置值 */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_6_REG  (SRE_PPE_TNL_BASE + 0x1064)  /* PPE_CFG_L3_TYPE_VALUE为第6种3层类型配置值的MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_6_REG  (SRE_PPE_TNL_BASE + 0x1068)  /* PPE_CFG_L3_TYPE_VALUE为第7种3层类型的头部协议域偏移值
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_7_REG  (SRE_PPE_TNL_BASE + 0x1070)  /* PPE_CFG_L3_TYPE_VALUE_7为第7种3层类型配置值 */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_7_REG  (SRE_PPE_TNL_BASE + 0x1074)  /* PPE_CFG_L3_TYPE_VALUE为第7种3层类型配置值的MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_7_REG  (SRE_PPE_TNL_BASE + 0x1078)  /* PPE_CFG_L3_TYPE_VALUE为第8种3层类型的头部协议域偏移值
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_8_REG  (SRE_PPE_TNL_BASE + 0x1080)  /* PPE_CFG_L3_TYPE_VALUE_8为第8种3层类型配置值 */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_8_REG  (SRE_PPE_TNL_BASE + 0x1084)  /* PPE_CFG_L3_TYPE_VALUE为第8种3层类型配置值的MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_8_REG  (SRE_PPE_TNL_BASE + 0x1088)  /* PPE_CFG_L3_TYPE_VALUE为第9种3层类型的头部协议域偏移值
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_9_REG  (SRE_PPE_TNL_BASE + 0x1090)  /* PPE_CFG_L3_TYPE_VALUE_9为第9种3层类型配置值 */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_9_REG  (SRE_PPE_TNL_BASE + 0x1094)  /* PPE_CFG_L3_TYPE_VALUE为第9种3层类型配置值的MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_9_REG  (SRE_PPE_TNL_BASE + 0x1098)  /* PPE_CFG_L3_TYPE_VALUE为第9种3层类型的头部协议域偏移值
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_10_REG  (SRE_PPE_TNL_BASE + 0x10A0)  /* PPE_CFG_L3_TYPE_VALUE_10为第10种3层类型配置值 */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_10_REG  (SRE_PPE_TNL_BASE + 0x10A4)  /* PPE_CFG_L3_TYPE_VALUE为第10种3层类型配置值的MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_10_REG  (SRE_PPE_TNL_BASE + 0x10A8)  /* PPE_CFG_L3_TYPE_VALUE为第10种3层类型的头部协议域偏移值
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_11_REG  (SRE_PPE_TNL_BASE + 0x10B0)  /* PPE_CFG_L3_TYPE_VALUE_11为第1种3层类型配置值 */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_11_REG  (SRE_PPE_TNL_BASE + 0x10B4)  /* PPE_CFG_L3_TYPE_VALUE为第11种3层类型配置值的MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_11_REG  (SRE_PPE_TNL_BASE + 0x10B8)  /* PPE_CFG_L3_TYPE_VALUE为第11种3层类型的头部协议域偏移值
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_12_REG  (SRE_PPE_TNL_BASE + 0x10C0)  /* PPE_CFG_L3_TYPE_VALUE_12为第12种3层类型配置值 */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_12_REG  (SRE_PPE_TNL_BASE + 0x10C4)  /* PPE_CFG_L3_TYPE_VALUE为第12种3层类型配置值的MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_12_REG  (SRE_PPE_TNL_BASE + 0x10C8)  /* PPE_CFG_L3_TYPE_VALUE为第12种3层类型的头部协议域偏移值
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_13_REG  (SRE_PPE_TNL_BASE + 0x10D0)  /* PPE_CFG_L3_TYPE_VALUE_13为第13种3层类型配置值 */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_13_REG  (SRE_PPE_TNL_BASE + 0x10D4)  /* PPE_CFG_L3_TYPE_VALUE为第13种3层类型配置值的MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_13_REG  (SRE_PPE_TNL_BASE + 0x10D8)  /* PPE_CFG_L3_TYPE_VALUE为第13种3层类型的头部协议域偏移值
 */
#define SRE_PPE_TNL_CFG_L3_TYPE_VALUE_14_REG  (SRE_PPE_TNL_BASE + 0x10E0)  /* PPE_CFG_L3_TYPE_VALUE_14为第14种3层类型配置值 */
#define SRE_PPE_TNL_CFG_L3_TYPE_MASK_14_REG  (SRE_PPE_TNL_BASE + 0x10E4)  /* PPE_CFG_L3_TYPE_VALUE为第14种3层类型配置值的MASK */
#define SRE_PPE_TNL_CFG_L3_TYPE_OFFSET_14_REG  (SRE_PPE_TNL_BASE + 0x10E8)  /* PPE_CFG_L3_TYPE_VALUE为第14种3层类型的头部协议域偏移值
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_0_REG  (SRE_PPE_TNL_BASE + 0x1100)  /* PPE_CFG_L4_TYPE_VALUE_0为第0种4层类型配置值
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_0_REG  (SRE_PPE_TNL_BASE + 0x1104)  /* PPE_CFG_L4_TYPE_VALUE_0为第0种4层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_0_REG  (SRE_PPE_TNL_BASE + 0x1108)  /* PPE_CFG_L4_SUB_ID_0为第0种4层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_1_REG  (SRE_PPE_TNL_BASE + 0x1110)  /* PPE_CFG_L4_TYPE_VALUE_1为第1种4层类型配置值
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_1_REG  (SRE_PPE_TNL_BASE + 0x1114)  /* PPE_CFG_L4_TYPE_VALUE_1为第1种4层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_1_REG  (SRE_PPE_TNL_BASE + 0x1118)  /* PPE_CFG_L4_SUB_ID_1为第1种4层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_2_REG  (SRE_PPE_TNL_BASE + 0x1120)  /* PPE_CFG_L4_TYPE_VALUE_2为第2种4层类型配置值
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_2_REG  (SRE_PPE_TNL_BASE + 0x1124)  /* PPE_CFG_L4_TYPE_VALUE_2为第2种4层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_2_REG  (SRE_PPE_TNL_BASE + 0x1128)  /* PPE_CFG_L4_SUB_ID_2为第2种4层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_3_REG  (SRE_PPE_TNL_BASE + 0x1130)  /* PPE_CFG_L4_TYPE_VALUE_3为第3种4层类型配置值
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_3_REG  (SRE_PPE_TNL_BASE + 0x1134)  /* PPE_CFG_L4_TYPE_VALUE_3为第3种4层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_3_REG  (SRE_PPE_TNL_BASE + 0x1138)  /* PPE_CFG_L4_SUB_ID_3为第3种4层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_4_REG  (SRE_PPE_TNL_BASE + 0x1140)  /* PPE_CFG_L4_TYPE_VALUE_4为第4种4层类型配置值
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_4_REG  (SRE_PPE_TNL_BASE + 0x1144)  /* PPE_CFG_L4_TYPE_VALUE_4为第4种4层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_4_REG  (SRE_PPE_TNL_BASE + 0x1148)  /* PPE_CFG_L4_SUB_ID_4为第4种4层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_5_REG  (SRE_PPE_TNL_BASE + 0x1150)  /* PPE_CFG_L4_TYPE_VALUE_5为第5种4层类型配置值
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_5_REG  (SRE_PPE_TNL_BASE + 0x1154)  /* PPE_CFG_L4_TYPE_VALUE_5为第5种4层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_5_REG  (SRE_PPE_TNL_BASE + 0x1158)  /* PPE_CFG_L4_SUB_ID_5为第5种4层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_6_REG  (SRE_PPE_TNL_BASE + 0x1160)  /* PPE_CFG_L4_TYPE_VALUE_6为第6种4层类型配置值
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_6_REG  (SRE_PPE_TNL_BASE + 0x1164)  /* PPE_CFG_L4_TYPE_VALUE_6为第6种4层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_6_REG  (SRE_PPE_TNL_BASE + 0x1168)  /* PPE_CFG_L4_SUB_ID_6为第6种4层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_7_REG  (SRE_PPE_TNL_BASE + 0x1170)  /* PPE_CFG_L4_TYPE_VALUE_7为第7种4层类型配置值
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_7_REG  (SRE_PPE_TNL_BASE + 0x1174)  /* PPE_CFG_L4_TYPE_VALUE_7为第7种4层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_7_REG  (SRE_PPE_TNL_BASE + 0x1178)  /* PPE_CFG_L4_SUB_ID_7为第7种4层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_8_REG  (SRE_PPE_TNL_BASE + 0x1180)  /* PPE_CFG_L4_TYPE_VALUE_8为第8种4层类型配置值
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_8_REG  (SRE_PPE_TNL_BASE + 0x1184)  /* PPE_CFG_L4_TYPE_VALUE_8为第8种4层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_8_REG  (SRE_PPE_TNL_BASE + 0x1188)  /* PPE_CFG_L4_SUB_ID_8为第8种4层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_9_REG  (SRE_PPE_TNL_BASE + 0x1190)  /* PPE_CFG_L4_TYPE_VALUE_9为第9种4层类型配置值
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_9_REG  (SRE_PPE_TNL_BASE + 0x1194)  /* PPE_CFG_L4_TYPE_VALUE_9为第9种4层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_9_REG  (SRE_PPE_TNL_BASE + 0x1198)  /* PPE_CFG_L4_SUB_ID_9为第9种4层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_10_REG  (SRE_PPE_TNL_BASE + 0x11A0)  /* PPE_CFG_L4_TYPE_VALUE_10为第10种4层类型配置值
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_10_REG  (SRE_PPE_TNL_BASE + 0x11A4)  /* PPE_CFG_L4_TYPE_VALUE_10为第10种4层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_10_REG  (SRE_PPE_TNL_BASE + 0x11A8)  /* PPE_CFG_L4_SUB_ID_10为第10种4层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_11_REG  (SRE_PPE_TNL_BASE + 0x11B0)  /* PPE_CFG_L4_TYPE_VALUE_11为第11种4层类型配置值
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_11_REG  (SRE_PPE_TNL_BASE + 0x11B4)  /* PPE_CFG_L4_TYPE_VALUE_11为第11种4层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_11_REG  (SRE_PPE_TNL_BASE + 0x11B8)  /* PPE_CFG_L4_SUB_ID_11为第11种4层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_12_REG  (SRE_PPE_TNL_BASE + 0x11C0)  /* PPE_CFG_L4_TYPE_VALUE_12为第12种4层类型配置值
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_12_REG  (SRE_PPE_TNL_BASE + 0x11C4)  /* PPE_CFG_L4_TYPE_VALUE_12为第12种4层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_12_REG  (SRE_PPE_TNL_BASE + 0x11C8)  /* PPE_CFG_L4_SUB_ID_12为第12种4层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_13_REG  (SRE_PPE_TNL_BASE + 0x11D0)  /* PPE_CFG_L4_TYPE_VALUE_13为第13种4层类型配置值
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_13_REG  (SRE_PPE_TNL_BASE + 0x11D4)  /* PPE_CFG_L4_TYPE_VALUE_13为第13种4层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_13_REG  (SRE_PPE_TNL_BASE + 0x11D8)  /* PPE_CFG_L4_SUB_ID_13为第13种4层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_VALUE_14_REG  (SRE_PPE_TNL_BASE + 0x11E0)  /* PPE_CFG_L4_TYPE_VALUE_14为第14种4层类型配置值
 */
#define SRE_PPE_TNL_CFG_L4_TYPE_MASK_14_REG  (SRE_PPE_TNL_BASE + 0x11E4)  /* PPE_CFG_L4_TYPE_VALUE_14为第14种4层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L4_SUB_ID_14_REG  (SRE_PPE_TNL_BASE + 0x11E8)  /* PPE_CFG_L4_SUB_ID_14为第14种4层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_0_REG  (SRE_PPE_TNL_BASE + 0x1200)  /* PPE_CFG_L5_TYPE_VALUE_0为第0种5层类型配置值
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_0_REG  (SRE_PPE_TNL_BASE + 0x1204)  /* PPE_CFG_L5_TYPE_VALUE_0为第0种5层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_0_REG  (SRE_PPE_TNL_BASE + 0x1208)  /* PPE_CFG_L5_SUB_ID_0为第0种5层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_1_REG  (SRE_PPE_TNL_BASE + 0x1210)  /* PPE_CFG_L5_TYPE_VALUE_1为第1种5层类型配置值
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_1_REG  (SRE_PPE_TNL_BASE + 0x1214)  /* PPE_CFG_L5_TYPE_VALUE_1为第1种5层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_1_REG  (SRE_PPE_TNL_BASE + 0x1218)  /* PPE_CFG_L5_SUB_ID_1为第1种5层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_2_REG  (SRE_PPE_TNL_BASE + 0x1220)  /* PPE_CFG_L5_TYPE_VALUE_2为第2种5层类型配置值
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_2_REG  (SRE_PPE_TNL_BASE + 0x1224)  /* PPE_CFG_L5_TYPE_VALUE_2为第2种5层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_2_REG  (SRE_PPE_TNL_BASE + 0x1228)  /* PPE_CFG_L5_SUB_ID_2为第2种5层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_3_REG  (SRE_PPE_TNL_BASE + 0x1230)  /* PPE_CFG_L5_TYPE_VALUE_3为第3种5层类型配置值
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_3_REG  (SRE_PPE_TNL_BASE + 0x1234)  /* PPE_CFG_L5_TYPE_VALUE_3为第3种5层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_3_REG  (SRE_PPE_TNL_BASE + 0x1238)  /* PPE_CFG_L5_SUB_ID_3为第3种5层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_4_REG  (SRE_PPE_TNL_BASE + 0x1240)  /* PPE_CFG_L5_TYPE_VALUE_4为第4种5层类型配置值
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_4_REG  (SRE_PPE_TNL_BASE + 0x1244)  /* PPE_CFG_L5_TYPE_VALUE_4为第4种5层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_4_REG  (SRE_PPE_TNL_BASE + 0x1248)  /* PPE_CFG_L5_SUB_ID_4为第4种5层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_5_REG  (SRE_PPE_TNL_BASE + 0x1250)  /* PPE_CFG_L5_TYPE_VALUE_5为第5种5层类型配置值
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_5_REG  (SRE_PPE_TNL_BASE + 0x1254)  /* PPE_CFG_L5_TYPE_VALUE_5为第5种5层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_5_REG  (SRE_PPE_TNL_BASE + 0x1258)  /* PPE_CFG_L5_SUB_ID_5为第5种5层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_6_REG  (SRE_PPE_TNL_BASE + 0x1260)  /* PPE_CFG_L5_TYPE_VALUE_6为第6种5层类型配置值
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_6_REG  (SRE_PPE_TNL_BASE + 0x1264)  /* PPE_CFG_L5_TYPE_VALUE_6为第6种5层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_6_REG  (SRE_PPE_TNL_BASE + 0x1268)  /* PPE_CFG_L5_SUB_ID_6为第6种5层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_7_REG  (SRE_PPE_TNL_BASE + 0x1270)  /* PPE_CFG_L5_TYPE_VALUE_7为第7种5层类型配置值
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_7_REG  (SRE_PPE_TNL_BASE + 0x1274)  /* PPE_CFG_L5_TYPE_VALUE_7为第7种5层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_7_REG  (SRE_PPE_TNL_BASE + 0x1278)  /* PPE_CFG_L5_SUB_ID_7为第7种5层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_8_REG  (SRE_PPE_TNL_BASE + 0x1280)  /* PPE_CFG_L5_TYPE_VALUE_8为第8种5层类型配置值
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_8_REG  (SRE_PPE_TNL_BASE + 0x1284)  /* PPE_CFG_L5_TYPE_VALUE_8为第8种5层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_8_REG  (SRE_PPE_TNL_BASE + 0x1288)  /* PPE_CFG_L5_SUB_ID_8为第8种5层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_9_REG  (SRE_PPE_TNL_BASE + 0x1290)  /* PPE_CFG_L5_TYPE_VALUE_9为第9种5层类型配置值
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_9_REG  (SRE_PPE_TNL_BASE + 0x1294)  /* PPE_CFG_L5_TYPE_VALUE_9为第9种5层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_9_REG  (SRE_PPE_TNL_BASE + 0x1298)  /* PPE_CFG_L5_SUB_ID_9为第9种5层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_10_REG  (SRE_PPE_TNL_BASE + 0x12A0)  /* PPE_CFG_L5_TYPE_VALUE_10为第10种5层类型配置值
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_10_REG  (SRE_PPE_TNL_BASE + 0x12A4)  /* PPE_CFG_L5_TYPE_VALUE_10为第10种5层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_10_REG  (SRE_PPE_TNL_BASE + 0x12A8)  /* PPE_CFG_L5_SUB_ID_10为第10种5层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_11_REG  (SRE_PPE_TNL_BASE + 0x12B0)  /* PPE_CFG_L5_TYPE_VALUE_11为第11种5层类型配置值
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_11_REG  (SRE_PPE_TNL_BASE + 0x12B4)  /* PPE_CFG_L5_TYPE_VALUE_11为第11种5层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_11_REG  (SRE_PPE_TNL_BASE + 0x12B8)  /* PPE_CFG_L5_SUB_ID_11为第11种5层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_12_REG  (SRE_PPE_TNL_BASE + 0x12C0)  /* PPE_CFG_L5_TYPE_VALUE_12为第12种5层类型配置值
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_12_REG  (SRE_PPE_TNL_BASE + 0x12C4)  /* PPE_CFG_L5_TYPE_VALUE_12为第12种5层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_12_REG  (SRE_PPE_TNL_BASE + 0x12C8)  /* PPE_CFG_L5_SUB_ID_12为第12种5层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_13_REG  (SRE_PPE_TNL_BASE + 0x12D0)  /* PPE_CFG_L5_TYPE_VALUE_13为第13种5层类型配置值
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_13_REG  (SRE_PPE_TNL_BASE + 0x12D4)  /* PPE_CFG_L5_TYPE_VALUE_13为第13种5层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_13_REG  (SRE_PPE_TNL_BASE + 0x12D8)  /* PPE_CFG_L5_SUB_ID_13为第13种5层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_VALUE_14_REG  (SRE_PPE_TNL_BASE + 0x12E0)  /* PPE_CFG_L5_TYPE_VALUE_14为第14种5层类型配置值
 */
#define SRE_PPE_TNL_CFG_L5_TYPE_MASK_14_REG  (SRE_PPE_TNL_BASE + 0x12E4)  /* PPE_CFG_L5_TYPE_VALUE_14为第14种5层类型值的MASK
 */
#define SRE_PPE_TNL_CFG_L5_SUB_ID_14_REG  (SRE_PPE_TNL_BASE + 0x12E8)  /* PPE_CFG_L5_SUB_ID_14为第14种5层的从属类型配置
 */
#define SRE_PPE_TNL_CFG_QOS_TBL_KEY_OFFSET_0_REG  (SRE_PPE_TNL_BASE + 0x4100)  /* PPE_CFG_QOS_TBL0_KEY_OFFSET是生成QOS的表的键值产生配置寄存器0。0x4100~0x4138依次是表0~表7的配置 */
#define SRE_PPE_TNL_CFG_QOS_TBL_KEY_OFFSET_1_REG  (SRE_PPE_TNL_BASE + 0x4108)  /* PPE_CFG_QOS_TBL0_KEY_OFFSET是生成QOS的表的键值产生配置寄存器0。0x4100~0x4138依次是表0~表7的配置 */
#define SRE_PPE_TNL_CFG_GRP_VMID_TBL_KEY_OFFSET0_0_REG  (SRE_PPE_TNL_BASE + 0x5D00)  /* PPE_CFG_GRP_VMID_TBL0_KEY_OFFSET0是生成GRP和VMID的表的键值产生配置寄存器0。0x5D00~0x5D50依次是表0~表10的配置 */
#define SRE_PPE_TNL_CFG_GRP_VMID_TBL_KEY_OFFSET0_1_REG  (SRE_PPE_TNL_BASE + 0x5D08)  /* PPE_CFG_GRP_VMID_TBL0_KEY_OFFSET0是生成GRP和VMID的表的键值产生配置寄存器0。0x5D00~0x5D50依次是表0~表10的配置 */
#define SRE_PPE_TNL_CFG_GRP_VMID_TBL_KEY_OFFSET1_0_REG  (SRE_PPE_TNL_BASE + 0x5D04)  /* PPE_CFG_GRP_VMID_TBL_KEY_OFFSET0是生成GRP和VMID的表的键值产生配置寄存器1。0x5D04~0x5D54依次是表0~表10的配置 */
#define SRE_PPE_TNL_CFG_GRP_VMID_TBL_KEY_OFFSET1_1_REG  (SRE_PPE_TNL_BASE + 0x5D0C)  /* PPE_CFG_GRP_VMID_TBL_KEY_OFFSET0是生成GRP和VMID的表的键值产生配置寄存器1。0x5D04~0x5D54依次是表0~表10的配置 */



/******************************************************************************/
/*                      PhosphorV600 PCU 寄存器定义                           */
/******************************************************************************/
#define SRE_GMAC_CF_TX_FIFO_THRSLD_REG   (0x420)  /* CF_TX_FIFO_THRSLD为发送FIFO水线寄存器。 */
#define SRE_GMAC_CF_RX_FIFO_THRSLD_REG   (0x424)  /* CF_RX_FIFO_THRSLD为接收FIFO水线寄存器。 */
#define SRE_GMAC_CF_CFG_FIFO_THRSLD_REG  (0x428)  /* CF_CFG_FIFO_THRSLD为配置FIFO水线寄存器。 */
#define SRE_GMAC_CF_INTRPT_MSK_REG       (0x42C)  /* CF_INTRPT_MSK为中断屏蔽寄存器。 */
#define SRE_GMAC_CF_FIFO_CLR_REG         (0x430)  /* CF_FIFO_CLR为FIFO清零寄存器。 */
#define SRE_GMAC_CF_INTRPT_STAT_REG      (0x434)  /* CF_INTRPT_STAT为中断状态寄存器。 */
#define SRE_GMAC_CF_INTRPT_CLR_REG       (0x438)  /* CF_INTRPT_CLR为中断清零寄存器。 */
#define SRE_GMAC_BUS_ERR_ADDR_REG        (0x43C)  /* BUS_ERR_ADDR为出错总线地址。 */
#define SRE_GMAC_PCU_MAXFRAME_SIZE_REG   (0x444) /*接收最大帧长设置寄存器*/
#define SRE_GMAC_TX_DROP_CNT_REG         (0x448)  /* TX_DROP_CNT为发送方向因FIFO空而丢弃的包的统计计数器。 */
#define SRE_GMAC_RX_OVER_FLOW_CNT_REG    (0x44C)  /* OVER_FLOW_CNT为因接收FIFO满而丢弃的包的统计计数器。 */
#define SRE_GMAC_DEBUG_ST_MCH_REG        (0x450)  /* DEBUG_ST_MCH状态机上报寄存器。 */
#define SRE_GMAC_FIFO_CURR_STATUS_REG    (0x454)  /* FIFO_CURR_STATUS为FIFO当前状态寄存器。 */
#define SRE_GMAC_FIFO_HIS_STATUS_REG     (0x458)  /* FIFO_HIS_STATUS为FIFO历史状态寄存器。 */
#define SRE_GMAC_CF_CFF_DATA_NUM_REG     (0x45C)  /* CF_CFF_DATA_NUM为配置FIFO数据个数寄存器。 */
#define SRE_GMAC_TX_CS_FAIL_CNT_REG      (0x460)  /* TX_CS_FAIL_CNT为发送添加校验和失败计数器。 */
#define SRE_GMAC_RX_TRANS_PKG_CNT_REG    (0x464)  /* RX_TRANS_PKG_CNT为下行搬运成功的包计数器。 */
#define SRE_GMAC_TX_TRANS_PKG_CNT_REG    (0x468)  /* TX_TRANS_PKG_CNT为上行搬运成功的包计数器。 */
#define SRE_GMAC_RX_ADDR_OVERFLOW_REG    (0x46C)  /* RX_ADDR_OVERFLOW为写下行配置FIFO溢出计数器。 */
#define SRE_GMAC_CF_TX_PAUSE_REG         (0x470)  /* CF_TX_PAUSE为发送流控控制寄存器。 */
#define SRE_GMAC_TX_CFF_ADDR_0_REG       (0x488)  /* TX_CFF_ADDR_0为发送描述符FIFO地址寄存器0。 */
#define SRE_GMAC_TX_CFF_ADDR_1_REG       (0x48C)  /* TX_CFF_ADDR_1为发送描述符FIFO地址寄存器1。 */
#define SRE_GMAC_TX_CFF_ADDR_2_REG       (0x490)  /* TX_CFF_ADDR_2为发送描述符FIFO地址寄存器2。 */
#define SRE_GMAC_TX_CFF_ADDR_3_REG       (0x494)  /* TX_CFF_ADDR_3为发送描述符FIFO地址寄存器3。 */
#define SRE_GMAC_RX_CFF_ADDR_REG         (0x4A0)  /* RX_CFF_ADDR为接收配置FIFO地址寄存器。 */
#define SRE_GMAC_WE_ADDR_REG             (0x4E0)  /* WE_ADDR为报文描述符的写地址。 */
#define SRE_GMAC_RX_BUF_SIZE_REG         (0x4E4)  /* RX_BUF_SIZE为接收缓存大小。 */
#define SRE_GMAC_BUS_CTRL_REG            (0x4E8)  /* BUS_CTRL为总线控制寄存器。 */
#define SRE_GMAC_RX_BUF_REQ_ADDR_REG     (0x4EC)  /* RX_BUF_REQ_ADDR为接收缓存的申请地址。 */
#define SRE_GMAC_RX_CTRL_REG             (0x4F0)  /* RX_CTRL为接收控制寄存器。 */
#define SRE_GMAC_RX_PKT_MODE_REG         (0x4F4)  /* RX_PKT_MODE为接收报文输入模式。 */
#define SRE_GMAC_QOS_MODE_REG            (0x4F8)  /* QOS_MODE为QOS信息的生成模式。 */
#define SRE_GMAC_VLAN_QOS_REG            (0x4FC)  /* VLAN_QOS为vlan帧中优先级到qos的查找表。 */
#define SRE_GMAC_IP_QOS_0_REG            (0x500)  /* IP_QOS_0为IP帧中优先级到qos的查找表0。 */
#define SRE_GMAC_IP_QOS_1_REG            (0x504)  /* IP_QOS_1为IP帧中优先级到qos的查找表11。 */
#define SRE_GMAC_IP_QOS_2_REG            (0x508)  /* IP_QOS_2为IP帧中优先级到qos的查找表22。 */
#define SRE_GMAC_IP_QOS_3_REG            (0x50C)  /* IP_QOS_3为IP帧中优先级到qos的查找表3。 */
#define SRE_GMAC_IP_QOS_4_REG            (0x510)  /* IP_QOS_4为IP帧中优先级到qos的查找表4。 */
#define SRE_GMAC_IP_QOS_5_REG            (0x514)  /* IP_QOS_5为IP帧中优先级到qos的查找表55。 */
#define SRE_GMAC_IP_QOS_6_REG            (0x518)  /* IP_QOS_6为IP帧中优先级到qos的查找表66。 */
#define SRE_GMAC_IP_QOS_7_REG            (0x51C)  /* IP_QOS_6为IP帧中优先级到qos的查找表7。 */
#define SRE_GMAC_GRP_MODE_0_REG          (0x520)  /* GRP_MODE为group信息的生成模式寄存器0。 */
#define SRE_GMAC_GRP_MODE_1_REG          (0x524)  /* GRP_MODE为group信息的生成模式寄存器1。 */
#define SRE_GMAC_TT_MODE_REG             (0x528)  /* TT_MODE为type信息的生成模式。 */
#define SRE_GMAC_TAG_MODE_REG            (0x52C)  /* TAG_MODE为tag信息的生成模式。 */
#define SRE_GMAC_TAG_MASK_0_REG          (0x530)  /* TAG_MASK_0为参与tag计算的报文头部字节掩码表0。 */
#define SRE_GMAC_TAG_MASK_1_REG          (0x534)  /* TAG_MASK_0为参与tag计算的报文头部字节掩码表1。 */
#define SRE_GMAC_MATCH_MASK_0_REG        (0x538)  /* MATCH_MASK_0为参与匹配的报文头部字节掩码表0。 */
#define SRE_GMAC_MATCH_TBL_0_REG         (0x540)  /* MATCH_TBL_0为进行报头匹配的字节表0。 */
#define SRE_GMAC_MATCH_TBL_1_REG         (0x544)  /* MATCH_TBL_1为进行报头匹配的字节表1。 */
#define SRE_GMAC_MATCH_TBL_2_REG         (0x548)  /* MATCH_TBL_2为进行报头匹配的字节表2。 */
#define SRE_GMAC_MATCH_TBL_3_REG         (0x54C)  /* MATCH_TBL_3为进行报头匹配的字节表3。 */
#define SRE_GMAC_MATCH_TBL_4_REG         (0x550)  /* MATCH_TBL_4为进行报头匹配的字节表4。 */
#define SRE_GMAC_MATCH_TBL_5_REG         (0x554)  /* MATCH_TBL_5为进行报头匹配的字节表5。 */
#define SRE_GMAC_MATCH_TBL_6_REG         (0x558)  /* MATCH_TBL_6为进行报头匹配的字节表6。 */
#define SRE_GMAC_MATCH_TBL_7_REG         (0x55C)  /* MATCH_TBL_7为进行报头匹配的字节表7。 */
#define SRE_GMAC_RXBUF_REQ_TIMER_REG     (0x580)  /* RXBUF_REQ_TIMER为接收缓存申请超时寄存器。 */
#define SRE_GMAC_RX_WE_TIMER_REG         (0x584)  /* RX_PD_TIMER为接收写work entry失败后的超时寄存器。 */
#define SRE_GMAC_TX_REL_TIMER_REG        (0x588)  /* TX_REL_TIMER为发送完成释放缓存失败后的超时寄存器。 */
#define SRE_GMAC_RX_BUFRQ_ERR_CNT_REG    (0x58C)  /* RX_BUFRQ_ERR_CNT为接收方向申请缓存错误计数器。 */
#define SRE_GMAC_TX_BUFRL_ERR_CNT_REG    (0x590)  /* RX_BUFRQ_ERR_CNT为发送方向释放缓存错误计数器。 */
#define SRE_GMAC_TX_WE_ERR_CNT_REG       (0x594)  /* TX_WE_ERR_CNT为发送方向写工作描述符错误计数器。 */
#define SRE_GMAC_RX_GRP_TBL_0_REG        (0x598)  /* RX_GRP_TBL_0为group匹配表项0 */
#define SRE_GMAC_RX_GRP_TBL_1_REG        (0x59C)  /* RX_GRP_TBL_1为group匹配表项1 */
#define SRE_GMAC_RX_GRP_TBL_2_REG        (0x5A0)  /* RX_GRP_TBL_2为group匹配表项2 */
#define SRE_GMAC_RX_GRP_TBL_3_REG        (0x5A4)  /* RX_GRP_TBL_3为group匹配表项3 */
#define SRE_GMAC_RX_GRP_TBL_4_REG        (0x5A8)  /* RX_GRP_TBL_4为group匹配表项4 */
#define SRE_GMAC_RX_GRP_TBL_5_REG        (0x5AC)  /* RX_GRP_TBL_5为group匹配表项5 */
#define SRE_GMAC_RX_GRP_TBL_6_REG        (0x5B0)  /* RX_GRP_TBL_6为group匹配表项6 */
#define SRE_GMAC_RX_GRP_TBL_7_REG        (0x5B4)  /* RX_GRP_TBL_7为group匹配表项7 */
#define SRE_GMAC_RX_GRP_RES_REG          (0x5B8)  /* RX_GRP_RES为匹配结果配置寄存器 */
#define SRE_GMAC_RX_GRP_MSK_REG          (0x5BC)  /* RX_GRP_MSK为字节匹配模式下group匹配掩码寄存器 */
#define SRE_GMAC_ADDR_FILT_S0_REG        (0x5C0)  /* ADDR_FILT_S0为地址过滤范围0的起始地址 */
#define SRE_GMAC_ADDR_FILT_E0_REG        (0x5C4)  /* ADDR_FILT_S0为地址过滤范围0的结束地址 */
#define SRE_GMAC_ADDR_FILT_S1_REG        (0x5C8)  /* ADDR_FILT_S1为地址过滤范围1的起始地址 */
#define SRE_GMAC_ADDR_FILT_E1_REG        (0x5CC)  /* ADDR_FILT_S1为地址过滤范围1的结束地址 */
#define SRE_GMAC_ADDR_FILT_S2_REG        (0x5D0)  /* ADDR_FILT_S0为地址过滤范围2的起始地址 */
#define SRE_GMAC_ADDR_FILT_E2_REG        (0x5D4)  /* ADDR_FILT_S0为地址过滤范围2的结束地址 */
#define SRE_GMAC_ADDR_FILT_S3_REG        (0x5D8)  /* ADDR_FILT_S1为地址过滤范围3的起始地址 */
#define SRE_GMAC_ADDR_FILT_E3_REG        (0x5DC)  /* ADDR_FILT_S1为地址过滤范围3的结束地址 */
#define SRE_GMAC_IDLE_CNT_REG            (0x5E0)  /* 发送pause帧控制寄存器 */



/******************************************************************************/
/*                      MC XGEM 寄存器定义                                    */
/******************************************************************************/

#if 0         /* z00202052 */
#define SRE_XGE_BASE                                   (0x128d0000)
#else
#define SRE_XGE_BASE                                   (0xe28d0000)
#endif        /* z00202052 */

#define SRE_XGE_RCI_MODE_CFG_REG                   (0x0)                 /* RCI寄存器模式配置寄存器。 */
#define SRE_XGE_MAC_MODE_CONTRL_REG                (0x4)                 /* 工作模式控制寄存器。 */
#define SRE_XGE_TX_TEST_PATTERN_REG                (0x8)                 /* 发送侧测试模式配置寄存器。 */
#define SRE_XGE_MAC_TX_CONTROL_REG                 (0xC)                 /* XGE发送控制寄存器。 */
#define SRE_XGE_MAC_TX_PRBS31_INSERT_ONCE_REG      (0x10)                /* 发送PRBS31插入一次误码控制寄存器 */
#define SRE_XGE_STP_TX_CONTROL_REG                 (0x18)                /* XGE发送控制寄存器2。 */
#define SRE_XGE_MAC_LONG_FRAME_REG                 (0x24)                /* 超长包长配置寄存器。 */
#define SRE_XGE_MAC_GAP_REG                        (0x28)                /* 包间隙配置寄存器。 */
#define SRE_XGE_MAC_TX_VLAN_TAG_REG                (0x2C)                /* VLAN TAG配置寄存器。 */
#define SRE_XGE_MAC_PAUSE_TIME_REG                 (0x34)                /* 流控时间配置寄存器。 */
#define SRE_XGE_MAC_PAUSE_CONTRL_REG               (0x3C)                /* 流控指示配置寄存器。 */
#define SRE_XGE_MIB_CONTRL_REG                     (0x40)                /* MIB控制配置寄存器 */
#define SRE_XGE_MIB_WR_DATA_REG                    (0x44)                /* MIB写数据寄存器 */
#define SRE_XGE_MIB_WR_DATA1_REG                   (0x48)                /* MIB写数据寄存器1 */
#define SRE_XGE_MIB_RD_DATA_REG                    (0x4C)                /* MIB读数据寄存器 */
#define SRE_XGE_MIB_RD_DATA1_REG                   (0x50)                /* MIB读数据寄存器1 */
#define SRE_XGE_MIB_ADDR_REG                       (0x54)                /* MIB地址配置寄存器 */
#define SRE_XGE_MAC_SOURCE_ADDR0_REG               (0x58)                /* MAC源地址配置寄存器。 */
#define SRE_XGE_MAC_SOURCE_ADDR1_REG               (0x5C)                /* MAC源地址配置寄存器。 */
#define SRE_XGE_MAC_INT_REG                        (0x60)                /* XGE MAC接口中断标志寄存器 */
#define SRE_XGE_MAC_INTMASK_REG                    (0x64)                /* XGE MAC 中断屏蔽寄存器 */
#define SRE_XGE_MAC_STATE_REG                      (0x68)                /* XGE MAC状态寄存器。 */
#define SRE_XGE_MAC_TX_STATE_REG                   (0x6C)                /* XGE MAC状态寄存器。 */
#define SRE_XGE_PCS_PRBS31_INSER_PATTERN_0_REG     (0x94)                /* 10GE PCS PRBS31单次插入误码掩码寄存器0。 */
#define SRE_XGE_PCS_PRBS31_INSER_PATTERN_1_REG     (0x98)                /* 10GE PCS PRBS31单次插入误码掩码寄存器1。 */
#define SRE_XGE_PCS_PRBS31_INSER_CYCLE_REG         (0x9C)                /* 10GE PCS PRBS31多次插入误码配置寄存器（周期与数目）。 */
#define SRE_XGE_TEST_PATTERN_SEED_A_0_REG          (0xA4)                /* 10GE PCS伪随机测试模式随机种子A寄存器0。 */
#define SRE_XGE_TEST_PATTERN_SEED_A_1_REG          (0xA8)                /* 10GE PCS伪随机测试模式随机种子A寄存器1。 */
#define SRE_XGE_TEST_PATTERN_SEED_B_0_REG          (0xAC)                /* 10GE PCS伪随机测试模式随机种子B寄存器0。 */
#define SRE_XGE_TEST_PATTERN_SEED_B_1_REG          (0xB0)                /* 10GE PCS伪随机测试模式随机种子B寄存器0。 */
#define SRE_XGE_TX_FAULT_REG                       (0xB4)                /* 10GE PCS发送通道错误告警寄存器。 */
#define SRE_XGE_TX_STAT_REG                        (0xB8)                /* 10GE PCS发送通道状态寄存器。 */
#define SRE_XGE_MAC_SHORT_FRAME_REG                (0xBC)                /* 最短包长配置寄存器。 */
#define SRE_XGE_DTE_XGXS_TX_CURR_STA_REG           (0xC0)                /* 10GE XGXS发送状态机当前状态寄存器。 */
#define SRE_XGE_TIMESTAMP_ESTI_REG                 (0xC4)                /* 发送时戳延迟估计 */
#define SRE_XGE_ASYM_CRT_HIGH_REG                  (0xC8)                /* 非对称校正值高32位 */
#define SRE_XGE_ASYM_CRT_LOW_REG                   (0xCC)                /* 非对称校正值低32位 */
#define SRE_XGE_SEQID_REG                          (0xD0)                /* 包ID返回值 */
#define SRE_XGE_CF_MSB_REG                         (0xD4)                /* 包ID返回值 */
#define SRE_XGE_TIMESTP_HIGH_REG                   (0xD8)                /* 返回时戳的32到63位 */
#define SRE_XGE_TIMESTP_LOW_REG                    (0xDC)                /* 返回时戳的0到31位 */
#define SRE_XGE_MEM_ADAPT_REG                      (0xE0)                /* memory时序调试信息 */
#define SRE_XGE_RCI_RX_MODE_CFG_REG                (0x2000)              /* RCI寄存器模式配置寄存器。 */
#define SRE_XGE_RX_TEST_PATTERN_REG                (0x2004)              /* 接收侧测试模式配置寄存器。 */
#define SRE_XGE_MAC_RX_CONTROL_REG                 (0x2008)              /* XGE接收控制寄存器 */
#define SRE_XGE_STP_RX_CONTROL_REG                 (0x200C)              /* XGE接收控制寄存器2 */
#define SRE_XGE_MAC_RX_FIFO_REG                    (0x2010)              /* XGE接收侧FIFON配置寄存器 */
#define SRE_XGE_MAC_RX_VLAN_REG                    (0x2014)              /* XGE接收侧VLAN配置寄存器 */
#define SRE_XGE_MAC_INT2_REG                       (0x2018)              /* XGE MAC接口中断标志寄存器 */
#define SRE_XGE_MAC_INTMASK2_REG                   (0x201C)              /* XGE MAC 中断屏蔽寄存器 */
#define SRE_XGE_MAC_STATE1_REG                     (0x202C)              /* XGE MAC状态寄存器。 */
#define SRE_XGE_MAC_TX_STATE1_REG                  (0x2030)              /* XGE MAC状态寄存器。 */
#define SRE_XGE_PCS_PRBS31_THLD_A_REG              (0x2034)              /* PCS PRBS31窗口内误码阈值配置寄存器。 */
#define SRE_XGE_PCS_PRBS31_TB_REG                  (0x2038)              /* PCS PRBS31时间窗口配置寄存器。 */
#define SRE_XGE_PCS_SYNC_LK_CNT_REG                (0x203C)              /* PCS配置SYNC的配置寄存器。 */
#define SRE_XGE_PCS_CONTROL1_REG                   (0x2040)              /* PCS中PRBS31测试模式控制寄存器1。 */
#define SRE_XGE_PCS_SYNC_ERR_REG                   (0x2048)              /* 同步头错误统计寄存器。 */
#define SRE_XGE_PCS_TYPE_STA_2_REG                 (0x2050)              /* 10GE PCS 10GBASE_R_PCS状态寄存器寄存器2。 */
#define SRE_XGE_TEST_PATTERN_ERR_CNT_REG           (0x2058)              /* 10GE PCS测试模式误码计数器。 */
#define SRE_XGE_PCS_ALARM_REG                      (0x205C)              /* PCS告警寄存器。 */
#define SRE_XGE_PCS_STATE_REG                      (0x2060)              /* XGE PCS状态寄存器。 */
#define SRE_XGE_RX_LANE_1_SYNC_CURR_STA_REG        (0x20B8)              /* 10GE XGXS通道0/1同步状态机当前状态寄存器。 */
#define SRE_XGE_RX_LANE_2_SYNC_CURR_STA_REG        (0x20BC)              /* 10GE XGXS通道2/3同步状态机当前状态寄存器。 */
#define SRE_XGE_RX_DESKEW_CURR_STA_REG             (0x20C0)              /* 10GE XGXS通道间DESKEW状态机当前状态寄存器。 */
#define SRE_XGE_DTE_XGXS_STA_1_REG                 (0x20C4)              /* 10GE XGXS状态寄存器1。 */
#define SRE_XGE_DTE_XGXS_RX_LANE0_10B_ERROR_REG    (0x20C8)              /* 10GE XGXS接收LANE0/1误码计数器。 */
#define SRE_XGE_DTE_XGXS_RX_LANE2_10B_ERROR_REG    (0x20CC)              /* 10GE XGXS接收LANE2/3误码计数器。 */
#define SRE_XGE_DTE_XGXS_RX_PRJ_ERROR_REG          (0x20D0)              /* 10GE XGXS接收方向工程需求。 */
#define SRE_XGE_RXCHAN_CTRL_SIGNALS_REG            (0x20E0)              /* 接收通道控制信号补充 */
#define SRE_XGE_UNICAST_ADDR_EN_REG                (0x2290)              /* XGE0接收单播地址过滤使能寄存器。 */
#define SRE_XGE_UNICAST_ADDR_EN_HIGH_REG           (0x2294)              /* XGE0接收单播、多播、广播地址过滤使能寄存器。 */
#define SRE_XGE_TIMESTAMP_INGRESS_REG              (0x2298)              /* XGE0接收时戳延迟估计。 */
#define SRE_XGE_NLST_REG                           (0x229C)              /* XGE0无损环回FIFO */
#define SRE_XGE_BIT_ERR_REG                        (0x22A0)              /* 链路异常统计寄存器 */
#define MC_XGE1_RCI_MODE_CFG_REG                  (0x4000)              /* RCI寄存器模式配置寄存器。 */
#define MC_XGE1_MAC_MODE_CONTRL_REG               (0x4004)              /* 工作模式控制寄存器。 */
#define MC_XGE1_TX_TEST_PATTERN_REG               (0x4008)              /* 发送侧测试模式配置寄存器。 */
#define MC_XGE1_MAC_TX_CONTROL_REG                (0x400C)              /* XGE发送控制寄存器。 */
#define MC_XGE1_MAC_TX_PRBS31_INSERT_ONCE_REG     (0x4010)
#define MC_XGE1_STP_TX_CONTROL_REG                (0x4018)              /* XGE发送控制寄存器2。 */
#define MC_XGE1_MAC_LONG_FRAME_REG                (0x4024)              /* 超长包长配置寄存器。 */
#define MC_XGE1_MAC_GAP_REG                       (0x4028)              /* 包间隙配置寄存器。 */
#define MC_XGE1_MAC_TX_VLAN_TAG_REG               (0x402C)              /* VLAN TAG配置寄存器。 */
#define MC_XGE1_MAC_PAUSE_TIME_REG                (0x4034)              /* 流控时间配置寄存器。 */
#define MC_XGE1_MAC_PAUSE_CONTRL_REG              (0x403C)              /* 流控指示配置寄存器。 */
#define MC_XGE1_MIB_CONTRL_REG                    (0x4040)              /* MIB控制配置寄存器 */
#define MC_XGE1_MIB_WR_DATA_REG                   (0x4044)              /* MIB写数据寄存器 */
#define MC_XGE1_MIB_WR_DATA1_REG                  (0x4048)              /* MIB写数据寄存器1 */
#define MC_XGE1_MIB_RD_DATA_REG                   (0x404C)              /* MIB读数据寄存器 */
#define MC_XGE1_MIB_RD_DATA1_REG                  (0x4050)              /* MIB读数据寄存器1 */
#define MC_XGE1_MIB_ADDR_REG                      (0x4054)              /* MIB地址配置寄存器 */
#define MC_XGE1_MAC_SOURCE_ADDR0_REG              (0x4058)              /* MAC源地址配置寄存器。 */
#define MC_XGE1_MAC_SOURCE_ADDR1_REG              (0x405C)              /* MAC源地址配置寄存器。 */
#define MC_XGE1_MAC_INT_REG                       (0x4060)              /* XGE MAC接口中断标志寄存器 */
#define MC_XGE1_MAC_INTMASK_REG                   (0x4064)              /* XGE MAC 中断屏蔽寄存器 */
#define MC_XGE1_MAC_STATE_REG                     (0x4068)              /* XGE MAC状态寄存器。 */
#define MC_XGE1_MAC_TX_STATE_REG                  (0x406C)              /* XGE MAC状态寄存器。 */
#define MC_XGE1_PCS_PRBS31_INSER_PATTERN_0_REG    (0x4094)              /* 10GE PCS PRBS31单次插入误码掩码寄存器0。 */
#define MC_XGE1_PCS_PRBS31_INSER_PATTERN_1_REG    (0x4098)              /* 10GE PCS PRBS31单次插入误码掩码寄存器1。 */
#define MC_XGE1_PCS_PRBS31_INSER_CYCLE_REG        (0x409C)              /* 10GE PCS PRBS31多次插入误码配置寄存器（周期与数目）。 */
#define MC_XGE1_TEST_PATTERN_SEED_A_0_REG         (0x40A4)              /* 10GE PCS伪随机测试模式随机种子A寄存器0。 */
#define MC_XGE1_TEST_PATTERN_SEED_A_1_REG         (0x40A8)              /* 10GE PCS伪随机测试模式随机种子A寄存器1。 */
#define MC_XGE1_TEST_PATTERN_SEED_B_0_REG         (0x40AC)              /* 10GE PCS伪随机测试模式随机种子B寄存器0。 */
#define MC_XGE1_TEST_PATTERN_SEED_B_1_REG         (0x40B0)              /* 10GE PCS伪随机测试模式随机种子B寄存器0。 */
#define MC_XGE1_TX_FAULT_REG                      (0x40B4)              /* 10GE PCS发送通道错误告警寄存器。 */
#define MC_XGE1_TX_STAT_REG                       (0x40B8)              /* 10GE PCS发送通道状态寄存器。 */
#define MC_XGE1_MAC_SHORT_FRAME_REG               (0x40BC)              /* 最短包长配置寄存器。 */
#define MC_XGE1_DTE_XGXS_TX_CURR_STA_REG          (0x40C0)              /* 10GE XGXS发送状态机当前状态寄存器。 */
#define MC_XGE1_TIMESTAMP_ESTI_REG                (0x40C4)              /* 发送时戳延迟估计 */
#define MC_XGE1_ASYM_CRT_HIGH_REG                 (0x40C8)              /* 非对称校正值高32位 */
#define MC_XGE1_ASYM_CRT_LOW_REG                  (0x40CC)              /* 非对称校正值低32位 */
#define MC_XGE1_SEQID_REG                         (0x40D0)              /* 包ID返回值 */
#define MC_XGE1_CF_MSB_REG                        (0x40D4)              /* 包ID返回值 */
#define MC_XGE1_TIMESTP_HIGH_REG                  (0x40D8)              /* 返回时戳的32到63位 */
#define MC_XGE1_TIMESTP_LOW_REG                   (0x40DC)              /* 返回时戳的0到31位 */
#define MC_XGE1_RCI_RX_MODE_CFG_REG               (0x6000)              /* RCI寄存器模式配置寄存器。 */
#define MC_XGE1_RX_TEST_PATTERN_REG               (0x6004)              /* 接收侧测试模式配置寄存器。 */
#define MC_XGE1_MAC_RX_CONTROL_REG                (0x6008)              /* XGE接收控制寄存器 */
#define MC_XGE1_STP_RX_CONTROL_REG                (0x600C)              /* XGE接收控制寄存器2 */
#define MC_XGE1_MAC_RX_FIFO_REG                   (0x6010)              /* XGE接收侧FIFON配置寄存器 */
#define MC_XGE1_MAC_RX_VLAN_REG                   (0x6014)              /* XGE接收侧VLAN配置寄存器 */
#define MC_XGE1_MAC_INT2_REG                      (0x6018)              /* XGE MAC接口中断标志寄存器 */
#define MC_XGE1_MAC_INTMASK2_REG                  (0x601C)              /* XGE MAC 中断屏蔽寄存器 */
#define MC_XGE1_MAC_STATE1_REG                    (0x602C)              /* XGE MAC状态寄存器。 */
#define MC_XGE1_MAC_TX_STATE1_REG                 (0x6030)              /* XGE MAC状态寄存器。 */
#define MC_XGE1_PCS_PRBS31_THLD_A_REG             (0x6034)              /* PCS PRBS31窗口内误码阈值配置寄存器。 */
#define MC_XGE1_PCS_PRBS31_TB_REG                 (0x6038)              /* PCS PRBS31时间窗口配置寄存器。 */
#define MC_XGE1_PCS_SYNC_LK_CNT_REG               (0x603C)              /* PCS配置SYNC的配置寄存器。 */
#define MC_XGE1_PCS_CONTROL1_REG                  (0x6040)              /* PCS中PRBS31测试模式控制寄存器1。 */
#define MC_XGE1_PCS_SYNC_ERR_REG                  (0x6048)              /* 同步头错误统计寄存器。 */
#define MC_XGE1_PCS_TYPE_STA_2_REG                (0x6050)              /* 10GE PCS 10GBASE_R_PCS状态寄存器寄存器2。 */
#define MC_XGE1_TEST_PATTERN_ERR_CNT_REG          (0x6058)              /* 10GE PCS测试模式误码计数器。 */
#define MC_XGE1_PCS_ALARM_REG                     (0x605C)              /* PCS告警寄存器。 */
#define MC_XGE1_PCS_STATE_REG                     (0x6060)              /* XGE PCS状态寄存器。 */
#define MC_XGE1_RX_LANE_1_SYNC_CURR_STA_REG       (0x60B8)              /* 10GE XGXS通道0/1同步状态机当前状态寄存器。 */
#define MC_XGE1_RX_LANE_2_SYNC_CURR_STA_REG       (0x60BC)              /* 10GE XGXS通道2/3同步状态机当前状态寄存器。 */
#define MC_XGE1_RX_DESKEW_CURR_STA_REG            (0x60C0)              /* 10GE XGXS通道间DESKEW状态机当前状态寄存器。 */
#define MC_XGE1_DTE_XGXS_STA_1_REG                (0x60C4)              /* 10GE XGXS状态寄存器1。 */
#define MC_XGE1_DTE_XGXS_RX_LANE0_10B_ERROR_REG   (0x60C8)              /* 10GE XGXS接收LANE0/1误码计数器。 */
#define MC_XGE1_DTE_XGXS_RX_LANE2_10B_ERROR_REG   (0x60CC)              /* 10GE XGXS接收LANE2/3误码计数器。 */
#define MC_XGE1_DTE_XGXS_RX_PRJ_ERROR_REG         (0x60D0)              /* 10GE XGXS接收方向工程需求。 */
#define SRE_XGE_RXCHAN_CTRL_SIGNALS_1_REG          (0x60E0)              /* 接收通道控制信号补充 */
#define MC_XGE1_UNICAST_ADDR_EN_REG               (0x60E4)              /* XGE1接收单播地址过滤使能寄存器。 */
#define MC_XGE1_UNICAST_ADDR_EN_HIGH_REG          (0x60E8)              /* XGE1接收单播、多播、广播地址过滤使能寄存器。 */
#define MC_XGE1_TIMESTAMP_INGRESS_REG             (0x60EC)              /* XGE1接收时戳延迟估计。 */
#define MC_XGE1_NLST_REG                          (0x60F0)              /* XGE0无损环回FIFO */
#define MC_XGE1_BIT_ERR_REG                       (0x60F4)              /* 链路异常统计寄存器 */
#define MC_XGE2_RCI_MODE_CFG_REG                  (0x8000)              /* RCI寄存器模式配置寄存器。 */
#define MC_XGE2_MAC_MODE_CONTRL_REG               (0x8004)              /* 工作模式控制寄存器。 */
#define MC_XGE2_TX_TEST_PATTERN_REG               (0x8008)              /* 发送侧测试模式配置寄存器。 */
#define MC_XGE2_MAC_TX_CONTROL_REG                (0x800C)              /* XGE发送控制寄存器。 */
#define MC_XGE2_MAC_TX_PRBS31_INSERT_ONCE_REG     (0x8010)
#define MC_XGE2_STP_TX_CONTROL_REG                (0x8018)              /* XGE发送控制寄存器2。 */
#define MC_XGE2_MAC_LONG_FRAME_REG                (0x8024)              /* 超长包长配置寄存器。 */
#define MC_XGE2_MAC_GAP_REG                       (0x8028)              /* 包间隙配置寄存器。 */
#define MC_XGE2_MAC_TX_VLAN_TAG_REG               (0x802C)              /* VLAN TAG配置寄存器。 */
#define MC_XGE2_MAC_PAUSE_TIME_REG                (0x8034)              /* 流控时间配置寄存器。 */
#define MC_XGE2_MAC_PAUSE_CONTRL_REG              (0x803C)              /* 流控指示配置寄存器。 */
#define MC_XGE2_MIB_CONTRL_REG                    (0x8040)              /* MIB控制配置寄存器 */
#define MC_XGE2_MIB_WR_DATA_REG                   (0x8044)              /* MIB写数据寄存器 */
#define MC_XGE2_MIB_WR_DATA1_REG                  (0x8048)              /* MIB写数据寄存器1 */
#define MC_XGE2_MIB_RD_DATA_REG                   (0x804C)              /* MIB读数据寄存器 */
#define MC_XGE2_MIB_RD_DATA1_REG                  (0x8050)              /* MIB读数据寄存器1 */
#define MC_XGE2_MIB_ADDR_REG                      (0x8054)              /* MIB地址配置寄存器 */
#define MC_XGE2_MAC_SOURCE_ADDR0_REG              (0x8058)              /* MAC源地址配置寄存器。 */
#define MC_XGE2_MAC_SOURCE_ADDR1_REG              (0x805C)              /* MAC源地址配置寄存器。 */
#define MC_XGE2_MAC_INT_REG                       (0x8060)              /* XGE MAC接口中断标志寄存器 */
#define MC_XGE2_MAC_INTMASK_REG                   (0x8064)              /* XGE MAC 中断屏蔽寄存器 */
#define MC_XGE2_MAC_STATE_REG                     (0x8068)              /* XGE MAC状态寄存器。 */
#define MC_XGE2_MAC_TX_STATE_REG                  (0x806C)              /* XGE MAC状态寄存器。 */
#define MC_XGE2_PCS_PRBS31_INSER_PATTERN_0_REG    (0x8094)              /* 10GE PCS PRBS31单次插入误码掩码寄存器0。 */
#define MC_XGE2_PCS_PRBS31_INSER_PATTERN_1_REG    (0x8098)              /* 10GE PCS PRBS31单次插入误码掩码寄存器1。 */
#define MC_XGE2_PCS_PRBS31_INSER_CYCLE_REG        (0x809C)              /* 10GE PCS PRBS31多次插入误码配置寄存器（周期与数目）。 */
#define MC_XGE2_TEST_PATTERN_SEED_A_0_REG         (0x80A4)              /* 10GE PCS伪随机测试模式随机种子A寄存器0。 */
#define MC_XGE2_TEST_PATTERN_SEED_A_1_REG         (0x80A8)              /* 10GE PCS伪随机测试模式随机种子A寄存器1。 */
#define MC_XGE2_TEST_PATTERN_SEED_B_0_REG         (0x80AC)              /* 10GE PCS伪随机测试模式随机种子B寄存器0。 */
#define MC_XGE2_TEST_PATTERN_SEED_B_1_REG         (0x80B0)              /* 10GE PCS伪随机测试模式随机种子B寄存器0。 */
#define MC_XGE2_TX_FAULT_REG                      (0x80B4)              /* 10GE PCS发送通道错误告警寄存器。 */
#define MC_XGE2_TX_STAT_REG                       (0x80B8)              /* 10GE PCS发送通道状态寄存器。 */
#define MC_XGE2_MAC_SHORT_FRAME_REG               (0x80BC)              /* 最短包长配置寄存器。 */
#define MC_XGE2_TIMESTAMP_ESTI_REG                (0x80C4)              /* 发送时戳延迟估计 */
#define MC_XGE2_ASYM_CRT_HIGH_REG                 (0x80C8)              /* 非对称校正值高32位 */
#define MC_XGE2_ASYM_CRT_LOW_REG                  (0x80CC)              /* 非对称校正值低32位 */
#define MC_XGE2_SEQID_REG                         (0x80D0)              /* 包ID返回值 */
#define MC_XGE2_CF_MSB_REG                        (0x80D4)              /* 包ID返回值 */
#define MC_XGE2_TIMESTP_HIGH_REG                  (0x80D8)              /* 返回时戳的32到63位 */
#define MC_XGE2_TIMESTP_LOW_REG                   (0x80DC)              /* 返回时戳的0到31位 */
#define MC_XGE2_RCI_RX_MODE_CFG_REG               (0xA000)              /* RCI寄存器模式配置寄存器。 */
#define MC_XGE2_RX_TEST_PATTERN_REG               (0xA004)              /* 接收侧测试模式配置寄存器。 */
#define MC_XGE2_MAC_RX_CONTROL_REG                (0xA008)              /* XGE接收控制寄存器 */
#define MC_XGE2_STP_RX_CONTROL_REG                (0xA00C)              /* XGE接收控制寄存器2 */
#define MC_XGE2_MAC_RX_FIFO_REG                   (0xA010)              /* XGE接收侧FIFON配置寄存器 */
#define MC_XGE2_MAC_RX_VLAN_REG                   (0xA014)              /* XGE接收侧VLAN配置寄存器 */
#define MC_XGE2_MAC_INT2_REG                      (0xA018)              /* XGE MAC接口中断标志寄存器 */
#define MC_XGE2_MAC_INTMASK2_REG                  (0xA01C)              /* XGE MAC 中断屏蔽寄存器 */
#define MC_XGE2_MAC_STATE1_REG                    (0xA02C)              /* XGE MAC状态寄存器。 */
#define MC_XGE2_MAC_TX_STATE1_REG                 (0xA030)              /* XGE MAC状态寄存器。 */
#define MC_XGE2_PCS_PRBS31_THLD_A_REG             (0xA034)              /* PCS PRBS31窗口内误码阈值配置寄存器。 */
#define MC_XGE2_PCS_PRBS31_TB_REG                 (0xA038)              /* PCS PRBS31时间窗口配置寄存器。 */
#define MC_XGE2_PCS_SYNC_LK_CNT_REG               (0xA03C)              /* PCS配置SYNC的配置寄存器。 */
#define MC_XGE2_PCS_CONTROL1_REG                  (0xA040)              /* PCS中PRBS31测试模式控制寄存器1。 */
#define MC_XGE2_PCS_SYNC_ERR_REG                  (0xA048)              /* 同步头错误统计寄存器。 */
#define MC_XGE2_PCS_TYPE_STA_2_REG                (0xA050)              /* 10GE PCS 10GBASE_R_PCS状态寄存器寄存器2。 */
#define MC_XGE2_TEST_PATTERN_ERR_CNT_REG          (0xA058)              /* 10GE PCS测试模式误码计数器。 */
#define MC_XGE2_PCS_ALARM_REG                     (0xA05C)              /* PCS告警寄存器。 */
#define MC_XGE2_PCS_STATE_REG                     (0xA060)              /* XGE PCS状态寄存器。 */
#define SRE_XGE_RXCHAN_CTRL_SIGNALS_2_REG          (0xA0E0)              /* 接收通道控制信号补充 */
#define MC_XGE2_UNICAST_ADDR_EN_REG               (0xA0E4)              /* XGE2接收单播地址过滤使能寄存器。 */
#define MC_XGE2_UNICAST_ADDR_EN_HIGH_REG          (0xA0E8)              /* XGE2接收单播、多播、广播地址过滤使能寄存器。 */
#define MC_XGE2_TIMESTAMP_INGRESS_REG             (0xA0EC)              /* XGE2接收时戳延迟估计。 */
#define MC_XGE2_NLST_REG                          (0xA0F0)              /* XGE0无损环回FIFO */
#define MC_XGE2_BIT_ERR_REG                       (0xA0F4)              /* 链路异常统计寄存器 */
#define MC_XGE3_RCI_MODE_CFG_REG                  (0xC000)              /* RCI寄存器模式配置寄存器。 */
#define MC_XGE3_MAC_MODE_CONTRL_REG               (0xC004)              /* 工作模式控制寄存器。 */
#define MC_XGE3_TX_TEST_PATTERN_REG               (0xC008)              /* 发送侧测试模式配置寄存器。 */
#define MC_XGE3_MAC_TX_CONTROL_REG                (0xC00C)              /* XGE发送控制寄存器。 */
#define MC_XGE3_MAC_TX_PRBS31_INSERT_ONCE_REG     (0xC010)
#define MC_XGE3_STP_TX_CONTROL_REG                (0xC018)              /* XGE发送控制寄存器2。 */
#define MC_XGE3_MAC_LONG_FRAME_REG                (0xC024)              /* 超长包长配置寄存器。 */
#define MC_XGE3_MAC_GAP_REG                       (0xC028)              /* 包间隙配置寄存器。 */
#define MC_XGE3_MAC_TX_VLAN_TAG_REG               (0xC02C)              /* VLAN TAG配置寄存器。 */
#define MC_XGE3_MAC_PAUSE_TIME_REG                (0xC034)              /* 流控时间配置寄存器。 */
#define MC_XGE3_MAC_PAUSE_CONTRL_REG              (0xC03C)              /* 流控指示配置寄存器。 */
#define MC_XGE3_MIB_CONTRL_REG                    (0xC040)              /* MIB控制配置寄存器 */
#define MC_XGE3_MIB_WR_DATA_REG                   (0xC044)              /* MIB写数据寄存器 */
#define MC_XGE3_MIB_WR_DATA1_REG                  (0xC048)              /* MIB写数据寄存器1 */
#define MC_XGE3_MIB_RD_DATA_REG                   (0xC04C)              /* MIB读数据寄存器 */
#define MC_XGE3_MIB_RD_DATA1_REG                  (0xC050)              /* MIB读数据寄存器1 */
#define MC_XGE3_MIB_ADDR_REG                      (0xC054)              /* MIB地址配置寄存器 */
#define MC_XGE3_MAC_SOURCE_ADDR0_REG              (0xC058)              /* MAC源地址配置寄存器。 */
#define MC_XGE3_MAC_SOURCE_ADDR1_REG              (0xC05C)              /* MAC源地址配置寄存器。 */
#define MC_XGE3_MAC_INT_REG                       (0xC060)              /* XGE MAC接口中断标志寄存器 */
#define MC_XGE3_MAC_INTMASK_REG                   (0xC064)              /* XGE MAC 中断屏蔽寄存器 */
#define MC_XGE3_MAC_STATE_REG                     (0xC068)              /* XGE MAC状态寄存器。 */
#define MC_XGE3_MAC_TX_STATE_REG                  (0xC06C)              /* XGE MAC状态寄存器。 */
#define MC_XGE3_PCS_PRBS31_INSER_PATTERN_0_REG    (0xC094)              /* 10GE PCS PRBS31单次插入误码掩码寄存器0。 */
#define MC_XGE3_PCS_PRBS31_INSER_PATTERN_1_REG    (0xC098)              /* 10GE PCS PRBS31单次插入误码掩码寄存器1。 */
#define MC_XGE3_PCS_PRBS31_INSER_CYCLE_REG        (0xC09C)              /* 10GE PCS PRBS31多次插入误码配置寄存器（周期与数目）。 */
#define MC_XGE3_TEST_PATTERN_SEED_A_0_REG         (0xC0A4)              /* 10GE PCS伪随机测试模式随机种子A寄存器0。 */
#define MC_XGE3_TEST_PATTERN_SEED_A_1_REG         (0xC0A8)              /* 10GE PCS伪随机测试模式随机种子A寄存器1。 */
#define MC_XGE3_TEST_PATTERN_SEED_B_0_REG         (0xC0AC)              /* 10GE PCS伪随机测试模式随机种子B寄存器0。 */
#define MC_XGE3_TEST_PATTERN_SEED_B_1_REG         (0xC0B0)              /* 10GE PCS伪随机测试模式随机种子B寄存器0。 */
#define MC_XGE3_TX_FAULT_REG                      (0xC0B4)              /* 10GE PCS发送通道错误告警寄存器。 */
#define MC_XGE3_TX_STAT_REG                       (0xC0B8)              /* 10GE PCS发送通道状态寄存器。 */
#define MC_XGE3_MAC_SHORT_FRAME_REG               (0xC0BC)              /* 最短包长配置寄存器。 */
#define MC_XGE3_TIMESTAMP_ESTI_REG                (0xC0C4)              /* 发送时戳延迟估计 */
#define MC_XGE3_ASYM_CRT_HIGH_REG                 (0xC0C8)              /* 非对称校正值高32位 */
#define MC_XGE3_ASYM_CRT_LOW_REG                  (0xC0CC)              /* 非对称校正值低32位 */
#define MC_XGE3_SEQID_REG                         (0xC0D0)              /* 包ID返回值 */
#define MC_XGE3_CF_MSB_REG                        (0xC0D4)              /* 包ID返回值 */
#define MC_XGE3_TIMESTP_HIGH_REG                  (0xC0D8)              /* 返回时戳的32到63位 */
#define MC_XGE3_TIMESTP_LOW_REG                   (0xC0DC)              /* 返回时戳的0到31位 */
#define MC_XGE3_RCI_RX_MODE_CFG_REG               (0xE000)              /* RCI寄存器模式配置寄存器。 */
#define MC_XGE3_RX_TEST_PATTERN_REG               (0xE004)              /* 接收侧测试模式配置寄存器。 */
#define MC_XGE3_MAC_RX_CONTROL_REG                (0xE008)              /* XGE接收控制寄存器 */
#define MC_XGE3_STP_RX_CONTROL_REG                (0xE00C)              /* XGE接收控制寄存器2 */
#define MC_XGE3_MAC_RX_FIFO_REG                   (0xE010)              /* XGE接收侧FIFON配置寄存器 */
#define MC_XGE3_MAC_RX_VLAN_REG                   (0xE014)              /* XGE接收侧VLAN配置寄存器 */
#define MC_XGE3_MAC_INT2_REG                      (0xE018)              /* XGE MAC接口中断标志寄存器 */
#define MC_XGE3_MAC_INTMASK2_REG                  (0xE01C)              /* XGE MAC 中断屏蔽寄存器 */
#define MC_XGE3_MAC_STATE1_REG                    (0xE02C)              /* XGE MAC状态寄存器。 */
#define MC_XGE3_MAC_TX_STATE1_REG                 (0xE030)              /* XGE MAC状态寄存器。 */
#define MC_XGE3_PCS_PRBS31_THLD_A_REG             (0xE034)              /* PCS PRBS31窗口内误码阈值配置寄存器。 */
#define MC_XGE3_PCS_PRBS31_TB_REG                 (0xE038)              /* PCS PRBS31时间窗口配置寄存器。 */
#define MC_XGE3_PCS_SYNC_LK_CNT_REG               (0xE03C)              /* PCS配置SYNC的配置寄存器。 */
#define MC_XGE3_PCS_CONTROL1_REG                  (0xE040)              /* PCS中PRBS31测试模式控制寄存器1。 */
#define MC_XGE3_PCS_SYNC_ERR_REG                  (0xE048)              /* 同步头错误统计寄存器。 */
#define MC_XGE3_PCS_TYPE_STA_2_REG                (0xE050)              /* 10GE PCS 10GBASE_R_PCS状态寄存器寄存器2。 */
#define MC_XGE3_TEST_PATTERN_ERR_CNT_REG          (0xE058)              /* 10GE PCS测试模式误码计数器。 */
#define MC_XGE3_PCS_ALARM_REG                     (0xE05C)              /* PCS告警寄存器。 */
#define MC_XGE3_PCS_STATE_REG                     (0xE060)              /* XGE PCS状态寄存器。 */
#define SRE_XGE_RXCHAN_CTRL_SIGNALS_3_REG          (0xE0E0)              /* 接收通道控制信号补充 */
#define MC_XGE3_UNICAST_ADDR_EN_REG               (0xE0E4)              /* XGE3接收单播地址过滤使能寄存器。 */
#define MC_XGE3_UNICAST_ADDR_EN_HIGH_REG          (0xE0E8)              /* XGE3接收单播、多播、广播地址过滤使能寄存器。 */
#define MC_XGE3_TIMESTAMP_INGRESS_REG             (0xE0EC)              /* XGE3接收时戳延迟估计。 */
#define MC_XGE3_NLST_REG                          (0xE0F0)              /* XGE0无损环回FIFO */
#define MC_XGE3_BIT_ERR_REG                       (0xE0F4)              /* 链路异常统计寄存器 */

/******************************************************************************/
/*                      MC XGEM_ADDR 寄存器定义                               */
/******************************************************************************/

#define SRE_XGE_UNICAST_ADDR_EN_0_REG              (0x20E4)              /* 接收单播地址过滤使能寄存器。 */
#define SRE_XGE_UNICAST_ADDR_EN_1_REG              (0x20E8)              /* 接收单播地址过滤使能寄存器。 */
#define SRE_XGE_MULTICAST_ADDR_EN_0_REG            (0x20EC)              /* 接收多地址过滤使能寄存器。 */
#define SRE_XGE_UNICAST_ADDR0_REG                  (0x20F0)              /* 接收单播地址0。 */
#define SRE_XGE_UNICAST_ADDR0_HIGH_REG             (0x20F4)              /* 接收单播地址0。 */
#define SRE_XGE_UNICAST_ADDR1_REG                  (0x20F8)              /* 接收单播地址1。 */
#define SRE_XGE_UNICAST_ADDR1_HIGH_REG             (0x20FC)              /* 接收单播地址1。 */
#define SRE_XGE_UNICAST_ADDR2_REG                  (0x2100)              /* 接收单播地址2。 */
#define SRE_XGE_UNICAST_ADDR2_HIGH_REG             (0x2104)              /* 接收单播地址2。 */
#define SRE_XGE_UNICAST_ADDR3_REG                  (0x2108)              /* 接收单播地址3。 */
#define SRE_XGE_UNICAST_ADDR3_HIGH_REG             (0x210C)              /* 接收单播地址3。 */
#define SRE_XGE_UNICAST_ADDR4_REG                  (0x2110)              /* 接收单播地址4。 */
#define SRE_XGE_UNICAST_ADDR4_HIGH_REG             (0x2114)              /* 接收单播地址4。 */
#define SRE_XGE_UNICAST_ADDR5_REG                  (0x2118)              /* 接收单播地址5。 */
#define SRE_XGE_UNICAST_ADDR5_HIGH_REG             (0x211C)              /* 接收单播地址5。 */
#define SRE_XGE_UNICAST_ADDR6_REG                  (0x2120)              /* 接收单播地址6。 */
#define SRE_XGE_UNICAST_ADDR6_HIGH_REG             (0x2124)              /* 接收单播地址6。 */
#define SRE_XGE_UNICAST_ADDR7_REG                  (0x2128)              /* 接收单播地址7。 */
#define SRE_XGE_UNICAST_ADDR7_HIGH_REG             (0x212C)              /* 接收单播地址7。 */
#define SRE_XGE_UNICAST_ADDR8_REG                  (0x2130)              /* 接收单播地址8。 */
#define SRE_XGE_UNICAST_ADDR8_HIGH_REG             (0x2134)              /* 接收单播地址8。 */
#define SRE_XGE_UNICAST_ADDR9_REG                  (0x2138)              /* 接收单播地址9。 */
#define SRE_XGE_UNICAST_ADDR9_HIGH_REG             (0x213C)              /* 接收单播地址9。 */
#define SRE_XGE_UNICAST_ADDR10_REG                 (0x2140)              /* 接收单播地址10。 */
#define SRE_XGE_UNICAST_ADDR10_HIGH_REG            (0x2144)              /* 接收单播地址10。 */
#define SRE_XGE_UNICAST_ADDR11_REG                 (0x2148)              /* 接收单播地址11。 */
#define SRE_XGE_UNICAST_ADDR11_HIGH_REG            (0x214C)              /* 接收单播地址11。 */
#define SRE_XGE_UNICAST_ADDR12_REG                 (0x2150)              /* 接收单播地址12。 */
#define SRE_XGE_UNICAST_ADDR12_HIGH_REG            (0x2154)              /* 接收单播地址12。 */
#define SRE_XGE_UNICAST_ADDR13_REG                 (0x2158)              /* 接收单播地址13。 */
#define SRE_XGE_UNICAST_ADDR13_HIGH_REG            (0x215C)              /* 接收单播地址13。 */
#define SRE_XGE_UNICAST_ADDR14_REG                 (0x2160)              /* 接收单播地址14。 */
#define SRE_XGE_UNICAST_ADDR14_HIGH_REG            (0x2164)              /* 接收单播地址14。 */
#define SRE_XGE_UNICAST_ADDR15_REG                 (0x2168)              /* 接收单播地址15。 */
#define SRE_XGE_UNICAST_ADDR15_HIGH_REG            (0x216C)              /* 接收单播地址15。 */
#define SRE_XGE_UNICAST_ADDR16_REG                 (0x2170)              /* 接收单播地址16。 */
#define SRE_XGE_UNICAST_ADDR16_HIGH_REG            (0x2174)              /* 接收单播地址16。 */
#define SRE_XGE_UNICAST_ADDR17_REG                 (0x2178)              /* 接收单播地址17。 */
#define SRE_XGE_UNICAST_ADDR17_HIGH_REG            (0x217C)              /* 接收单播地址17。 */
#define SRE_XGE_UNICAST_ADDR18_REG                 (0x2180)              /* 接收单播地址18。 */
#define SRE_XGE_UNICAST_ADDR18_HIGH_REG            (0x2184)              /* 接收单播地址18。 */
#define SRE_XGE_UNICAST_ADDR19_REG                 (0x2188)              /* 接收单播地址19。 */
#define SRE_XGE_UNICAST_ADDR19_HIGH_REG            (0x218C)              /* 接收单播地址19。 */
#define SRE_XGE_UNICAST_ADDR20_REG                 (0x2190)              /* 接收单播地址20。 */
#define SRE_XGE_UNICAST_ADDR20_HIGH_REG            (0x2194)              /* 接收单播地址20。 */
#define SRE_XGE_UNICAST_ADDR21_REG                 (0x2198)              /* 接收单播地址21。 */
#define SRE_XGE_UNICAST_ADDR21_HIGH_REG            (0x219C)              /* 接收单播地址21。 */
#define SRE_XGE_UNICAST_ADDR22_REG                 (0x21A0)              /* 接收单播地址22。 */
#define SRE_XGE_UNICAST_ADDR22_HIGH_REG            (0x21A4)              /* 接收单播地址22。 */
#define SRE_XGE_UNICAST_ADDR23_REG                 (0x21A8)              /* 接收单播地址23。 */
#define SRE_XGE_UNICAST_ADDR23_HIGH_REG            (0x21AC)              /* 接收单播地址23。 */
#define SRE_XGE_UNICAST_ADDR24_REG                 (0x21B0)              /* 接收单播地址24。 */
#define SRE_XGE_UNICAST_ADDR24_HIGH_REG            (0x21B4)              /* 接收单播地址24。 */
#define SRE_XGE_UNICAST_ADDR25_REG                 (0x21B8)              /* 接收单播地址25。 */
#define SRE_XGE_UNICAST_ADDR25_HIGH_REG            (0x21BC)              /* 接收单播地址25。 */
#define SRE_XGE_UNICAST_ADDR26_REG                 (0x21C0)              /* 接收单播地址26。 */
#define SRE_XGE_UNICAST_ADDR26_HIGH_REG            (0x21C4)              /* 接收单播地址26。 */
#define SRE_XGE_UNICAST_ADDR27_REG                 (0x21C8)              /* 接收单播地址27。 */
#define SRE_XGE_UNICAST_ADDR27_HIGH_REG            (0x21CC)              /* 接收单播地址27。 */
#define SRE_XGE_UNICAST_ADDR28_REG                 (0x21D0)              /* 接收单播地址28。 */
#define SRE_XGE_UNICAST_ADDR28_HIGH_REG            (0x21D4)              /* 接收单播地址28。 */
#define SRE_XGE_UNICAST_ADDR29_REG                 (0x21D8)              /* 接收单播地址29。 */
#define SRE_XGE_UNICAST_ADDR29_HIGH_REG            (0x21DC)              /* 接收单播地址29。 */
#define SRE_XGE_UNICAST_ADDR30_REG                 (0x21E0)              /* 接收单播地址30。 */
#define SRE_XGE_UNICAST_ADDR30_HIGH_REG            (0x21E4)              /* 接收单播地址30。 */
#define SRE_XGE_UNICAST_ADDR31_REG                 (0x21E8)              /* 接收单播地址31。 */
#define SRE_XGE_UNICAST_ADDR31_HIGH_REG            (0x21EC)              /* 接收单播地址31。 */
#define SRE_XGE_UNICAST_ADDR32_REG                 (0x21F0)              /* 接收单播地址32。 */
#define SRE_XGE_UNICAST_ADDR32_HIGH_REG            (0x21F4)              /* 接收单播地址32。 */
#define SRE_XGE_UNICAST_ADDR33_REG                 (0x21F8)              /* 接收单播地址33。 */
#define SRE_XGE_UNICAST_ADDR33_HIGH_REG            (0x21FC)              /* 接收单播地址33。 */
#define SRE_XGE_UNICAST_ADDR34_REG                 (0x2200)              /* 接收单播地址34。 */
#define SRE_XGE_UNICAST_ADDR34_HIGH_REG            (0x2204)              /* 接收单播地址34。 */
#define SRE_XGE_UNICAST_ADDR35_REG                 (0x2208)              /* 接收单播地址35。 */
#define SRE_XGE_UNICAST_ADDR35_HIGH_REG            (0x220C)              /* 接收单播地址35。 */
#define SRE_XGE_MULTICAST_ADDR0_REG                (0x2210)              /* 接收多播地址0。 */
#define SRE_XGE_MULTICAST_ADDR0_HIGH_REG           (0x2214)              /* 接收多播地址0。 */
#define SRE_XGE_MULTICAST_ADDR1_REG                (0x2218)              /* 接收多播地址1。 */
#define SRE_XGE_MULTICAST_ADDR1_HIGH_REG           (0x221C)              /* 接收多播地址1。 */
#define SRE_XGE_MULTICAST_ADDR2_REG                (0x2220)              /* 接收多播地址2。 */
#define SRE_XGE_MULTICAST_ADDR2_HIGH_REG           (0x2224)              /* 接收多播地址2。 */
#define SRE_XGE_MULTICAST_ADDR3_REG                (0x2228)              /* 接收多播地址3。 */
#define SRE_XGE_MULTICAST_ADDR3_HIGH_REG           (0x222C)              /* 接收多播地址3。 */
#define SRE_XGE_MULTICAST_ADDR4_REG                (0x2230)              /* 接收多播地址4。 */
#define SRE_XGE_MULTICAST_ADDR4_HIGH_REG           (0x2234)              /* 接收多播地址4。 */
#define SRE_XGE_MULTICAST_ADDR5_REG                (0x2238)              /* 接收多播地址5。 */
#define SRE_XGE_MULTICAST_ADDR5_HIGH_REG           (0x223C)              /* 接收多播地址5。 */
#define SRE_XGE_MULTICAST_ADDR6_REG                (0x2240)              /* 接收多播地址6。 */
#define SRE_XGE_MULTICAST_ADDR6_HIGH_REG           (0x2244)              /* 接收多播地址6。 */
#define SRE_XGE_MULTICAST_ADDR7_REG                (0x2248)              /* 接收多播地址7。 */
#define SRE_XGE_MULTICAST_ADDR7_HIGH_REG           (0x224C)              /* 接收多播地址7。 */
#define SRE_XGE_MULTICAST_MSK0_REG                 (0x2250)              /* 接收多播掩码0。 */
#define SRE_XGE_MULTICAST_MSK0_HIGH_REG            (0x2254)              /* 接收多播掩码0。 */
#define SRE_XGE_MULTICAST_MSK1_REG                 (0x2258)              /* 接收多播掩码1。 */
#define SRE_XGE_MULTICAST_MSK1_HIGH_REG            (0x225C)              /* 接收多播掩码1。 */
#define SRE_XGE_MULTICAST_MSK2_REG                 (0x2260)              /* 接收多播掩码2。 */
#define SRE_XGE_MULTICAST_MSK2_HIGH_REG            (0x2264)              /* 接收多播掩码2。 */
#define SRE_XGE_MULTICAST_MSK3_REG                 (0x2268)              /* 接收多播掩码3。 */
#define SRE_XGE_MULTICAST_MSK3_HIGH_REG            (0x226C)              /* 接收多播掩码3。 */
#define SRE_XGE_MULTICAST_MSK4_REG                 (0x2270)              /* 接收多播掩码4。 */
#define SRE_XGE_MULTICAST_MSK4_HIGH_REG            (0x2274)              /* 接收多播掩码4。 */
#define SRE_XGE_MULTICAST_MSK5_REG                 (0x2278)              /* 接收多播掩码5。 */
#define SRE_XGE_MULTICAST_MSK5_HIGH_REG            (0x227C)              /* 接收多播掩码5。 */
#define SRE_XGE_MULTICAST_MSK6_REG                 (0x2280)              /* 接收多播掩码6。 */
#define SRE_XGE_MULTICAST_MSK6_HIGH_REG            (0x2284)              /* 接收多播掩码6。 */
#define SRE_XGE_MULTICAST_MSK7_REG                 (0x2288)              /* 接收多播掩码7。 */
#define SRE_XGE_MULTICAST_MSK7_HIGH_REG            (0x228C)              /* 接收多播掩码7。 */

/*                      SERDES1 寄存器定义              z00202052            */
/******************************************************************************/
#define SERDES1_BASE_ADDR            (0xe28e0000)

/*                      MDIO 寄存器偏移地址定义                          */
/******************************************************************************/
#if 0         /* z00202052 */
#define MDIO_BASE_ADDR               (0x128f0000)
#else
#define MDIO_BASE_ADDR               (0xe28f0000)
#endif        /* z00202052 */

#define MDIO_COMMAND_REG            (0x0)          /* MDIO控制寄存器 */
#define MDIO_ADDR_REG               (0x4)          /* MDIO间接地址寄存器 */
#define MDIO_WDATA_REG              (0x8)          /* MDIO写数据寄存器 */
#define MDIO_RDATA_REG              (0xc)          /* MDIO读数据寄存器 */
#define MDIO_STA_REG                (0x10)         /* MDIO访问状态寄存器 */


/******************************************************************************/
/*                      PhosphorV600 MDIO PCU 寄存器定义                      */
/******************************************************************************/
#define SRE_MDIO_CMD_REG                 (0x0)
#define SRE_MDIO_RD_WR_DATA_REG          (0x4)
#define SRE_MDIO_AUTOSCAN_PHY_ADDR_REG   (0x8)
#define SRE_MDIO_CTROL_REG               (0xC)
#define SRE_MDIO_STAT_REG                (0x10)
#define SRE_MDIO_SOFT_RST_MDIO_REG       (0x14)
#define SRE_MDIO_PHY0_ADDR_REG           (0x18)
#define SRE_MDIO_PHY1_ADDR_REG           (0x1C)
#define SRE_MDIO_PHY2_ADDR_REG           (0x20)
#define SRE_MDIO_PHY3_ADDR_REG           (0x24)
#define SRE_MDIO_PHY4_ADDR_REG           (0x28)
#define SRE_MDIO_PHY_TYPE_REG            (0x2C)
#define SRE_MDIO_PHY0_CONTROL_REG        (0x600)
#define SRE_MDIO_PHY0_STATUS_REG         (0x610)
#define SRE_MDIO_PHY0_ID1_REG            (0x620)
#define SRE_MDIO_PHY0_ID2_REG            (0x630)
#define SRE_MDIO_AN0_ADVERTISEMENT_REG   (0x640)
#define SRE_MDIO_LINK0_BASE_PAGE_REG     (0x650)
#define SRE_MDIO_AN0_EXPANSION_REG       (0x660)
#define SRE_MDIO_AN0_NP_TX_REG           (0x670)
#define SRE_MDIO_PHY1_CONTROL_REG        (0x700)
#define SRE_MDIO_PHY1_STATUS_REG         (0x710)
#define SRE_MDIO_PHY1_ID1_REG            (0x720)
#define SRE_MDIO_PHY1_ID2_REG            (0x730)
#define SRE_MDIO_AN1_ADVERTISEMENT_REG   (0x740)
#define SRE_MDIO_LINK1_BASE_PAGE_REG     (0x750)
#define SRE_MDIO_AN1_EXPANSION_REG       (0x760)
#define SRE_MDIO_AN1_NP_TX_REG           (0x770)
#define SRE_MDIO_PHY2_CONTROL_REG        (0x800)
#define SRE_MDIO_PHY2_STATUS_REG         (0x810)
#define SRE_MDIO_PHY2_ID1_REG            (0x820)
#define SRE_MDIO_PHY2_ID2_REG            (0x830)
#define SRE_MDIO_AN2_ADVERTISEMENT_REG   (0x840)
#define SRE_MDIO_LINK2_BASE_PAGE_REG     (0x850)
#define SRE_MDIO_AN2_EXPANSION_REG       (0x860)
#define SRE_MDIO_AN2_NP_TX_REG           (0x870)
#define SRE_MDIO_PHY3_CONTROL_REG        (0x900)
#define SRE_MDIO_PHY3_STATUS_REG         (0x910)
#define SRE_MDIO_PHY3_ID1_REG            (0x920)
#define SRE_MDIO_PHY3_ID2_REG            (0x930)
#define SRE_MDIO_AN3_ADVERTISEMENT_REG   (0x940)
#define SRE_MDIO_LINK3_BASE_PAGE_REG     (0x950)
#define SRE_MDIO_AN3_EXPANSION_REG       (0x960)
#define SRE_MDIO_AN3_NP_TX_REG           (0x970)
#define SRE_MDIO_PHY4_CONTROL_REG        (0xA00)
#define SRE_MDIO_PHY4_STATUS_REG         (0xA10)
#define SRE_MDIO_PHY4_ID1_REG            (0xA20)
#define SRE_MDIO_PHY4_ID2_REG            (0xA30)
#define SRE_MDIO_AN4_ADVERTISEMENT_REG   (0xA40)
#define SRE_MDIO_LINK4_BASE_PAGE_REG     (0xA50)
#define SRE_MDIO_AN4_EXPANSION_REG       (0xA60)
#define SRE_MDIO_AN4_NP_TX_REG           (0xA70)

/*                      SERDES0_L 寄存器定义            z00202052            */
/******************************************************************************/
#define SERDES0_LOW_BASE_ADDR        (0xe28f2000)

/*                      SERDES0_H 寄存器定义            z00202052            */
/******************************************************************************/
#define SERDES0_HIGHT_BASE_ADDR      (0xe28f3000)

/*                      IOCTRL0 寄存器定义              z00202052            */
/******************************************************************************/
#define IOCTRL0_BASE_ADDR                 (0xe28f4000)

/* PDM 模块寄存器定义 */
#define SRE_PDM_BASE_ADDR                       (0x10820000)
#define SRE_PDM_ENA                             (SRE_PDM_BASE_ADDR + 0x00 )
#define SRE_PDM_GETPOE_STOP                     (SRE_PDM_BASE_ADDR + 0x04 )
#define SRE_PDM_NODE_CODE                       (SRE_PDM_BASE_ADDR + 0x08 )
#define SRE_PDM_CFG_ENDIAN                      (SRE_PDM_BASE_ADDR + 0x0c )
#define SRE_PDM_CACHE_CFG                       (SRE_PDM_BASE_ADDR + 0x10 )
#define SRE_PDM_CFG_BUS_CTRL                    (SRE_PDM_BASE_ADDR + 0x14 )
#define SRE_PDM_CFG_BUS_TIMEOUT_THRSHLD         (SRE_PDM_BASE_ADDR + 0x18 )
#define SRE_PDM_CFG_STS_TIMEOUT_THRSHLD         (SRE_PDM_BASE_ADDR + 0x1c )
#define SRE_PDM_REFCNT_CTRL                     (SRE_PDM_BASE_ADDR + 0x20 )
#define SRE_PDM_ERR_GROUP                       (SRE_PDM_BASE_ADDR + 0x24 )
#define SRE_PDM_ERR_QOS                         (SRE_PDM_BASE_ADDR + 0x28 )
#define SRE_PDM_ERR_TT                          (SRE_PDM_BASE_ADDR + 0x2c )
#define SRE_PDM_ERR_TAG                         (SRE_PDM_BASE_ADDR + 0x30 )
#define SRE_PDM_NULL_GROUP                      (SRE_PDM_BASE_ADDR + 0x34 )
#define SRE_PDM_NULL_QOS                        (SRE_PDM_BASE_ADDR + 0x38 )
#define SRE_PDM_NULL_TT                         (SRE_PDM_BASE_ADDR + 0x3c )
#define SRE_PDM_NULL_TAG                        (SRE_PDM_BASE_ADDR + 0x40 )
#define SRE_PDM_BYP_GROUP                       (SRE_PDM_BASE_ADDR + 0x44 )
#define SRE_PDM_BYP_QOS                         (SRE_PDM_BASE_ADDR + 0x48 )
#define SRE_PDM_GETPKT_ADDR                     (SRE_PDM_BASE_ADDR + 0x4c )
#define SRE_PDM_ADDPKT_ADDR                     (SRE_PDM_BASE_ADDR + 0x50 )
#define SRE_PDM_ADDSPE_BASE_ADDR                (SRE_PDM_BASE_ADDR + 0x54 )
#define SRE_PDM_BYP_SPACE_TIME                  (SRE_PDM_BASE_ADDR + 0x58 )
#define SRE_PDM_MACSDU_PROC_TIMEOUT_THRSHLD     (SRE_PDM_BASE_ADDR + 0x5c )
#define SRE_PDM_BYP_WATERLINE                   (SRE_PDM_BASE_ADDR + 0x60 )
#define SRE_PDM_GETPOE_CONTFAIL                 (SRE_PDM_BASE_ADDR + 0x64 )
#define SRE_PDM_ADDPOE_CONTFAIL                 (SRE_PDM_BASE_ADDR + 0x68 )
#define SRE_PDM_POE_FAIL_WAIT_TIME              (SRE_PDM_BASE_ADDR + 0x6c )
#define SRE_PDM_POE_OK_WAIT_TIME                (SRE_PDM_BASE_ADDR + 0x70 )
#define SRE_PDM_BMU_BASE_ADDR                   (SRE_PDM_BASE_ADDR + 0x74 )
#define SRE_PDM_GETBMU_POOL_VMID                (SRE_PDM_BASE_ADDR + 0x78 )
#define SRE_PDM_GETBMU_CONTFAIL                 (SRE_PDM_BASE_ADDR + 0x7c )
#define SRE_PDM_BMU_GETFAIL_WAIT_TIME           (SRE_PDM_BASE_ADDR + 0x80 )
#define SRE_PDM_MACETT_ADDR                     (SRE_PDM_BASE_ADDR + 0x84 )
#define SRE_PDM_MACETT_SIZE                     (SRE_PDM_BASE_ADDR + 0x88 )
#define SRE_PDM_MACETT_ITEM_SIZE                (SRE_PDM_BASE_ADDR + 0x8c )
#define SRE_PDM_MACETT_OFFSET                   (SRE_PDM_BASE_ADDR + 0x90 )
#define SRE_PDM_RLCETT_ADDR                     (SRE_PDM_BASE_ADDR + 0x94 )
#define SRE_PDM_RLCETT_SIZE                     (SRE_PDM_BASE_ADDR + 0x98 )
#define SRE_PDM_RLCETT_ITEM_SIZE                (SRE_PDM_BASE_ADDR + 0x9c )
#define SRE_PDM_RLCETT_OFFSET                   (SRE_PDM_BASE_ADDR + 0xa0 )
#define SRE_PDM_VBD_SKIP_SIZE                   (SRE_PDM_BASE_ADDR + 0xa4 )
#define SRE_PDM_MAX_MAC_HEAD_SIZE               (SRE_PDM_BASE_ADDR + 0xa8 )
#define SRE_PDM_MAX_SDU_NUM                     (SRE_PDM_BASE_ADDR + 0xac )
#define SRE_PDM_LCID_BEGIN_END                  (SRE_PDM_BASE_ADDR + 0xb0 )
#define SRE_PDM_ACC_VMID                        (SRE_PDM_BASE_ADDR + 0xb4 )
#define SRE_PDM_HIS_CLR_EN                      (SRE_PDM_BASE_ADDR + 0xb8 )
#define SRE_PDM_AXI_TRACE_ENA                   (SRE_PDM_BASE_ADDR + 0xbc )
#define SRE_PDM_AXI_STAT_CLR                    (SRE_PDM_BASE_ADDR + 0xc0 )
#define SRE_PDM_INTMSK_ERR                      (SRE_PDM_BASE_ADDR + 0xc4 )
#define SRE_PDM_RINT_ERR                        (SRE_PDM_BASE_ADDR + 0xc8 )
#define SRE_PDM_INTSTS_ERR                      (SRE_PDM_BASE_ADDR + 0xcc )
#define SRE_PDM_GET_PKT_OK_CNT                  (SRE_PDM_BASE_ADDR + 0xd0 )
#define SRE_PDM_GET_PKT_FAIL_CNT                (SRE_PDM_BASE_ADDR + 0xd4 )
#define SRE_PDM_ADD_PKT_OK_CNT                  (SRE_PDM_BASE_ADDR + 0xd8 )
#define SRE_PDM_ADD_PKT_FAIL_CNT                (SRE_PDM_BASE_ADDR + 0xdc )
#define SRE_PDM_ADD_MCE_OK_CNT                  (SRE_PDM_BASE_ADDR + 0xe0 )
#define SRE_PDM_ADD_MCE_FAIL_CNT                (SRE_PDM_BASE_ADDR + 0xe4 )
#define SRE_PDM_ADD_BYP_OK_CNT                  (SRE_PDM_BASE_ADDR + 0xe8 )
#define SRE_PDM_ADD_BYP_FAIL_CNT                (SRE_PDM_BASE_ADDR + 0xec )
#define SRE_PDM_GET_BUFFOK_CNT                  (SRE_PDM_BASE_ADDR + 0xf0 )
#define SRE_PDM_GET_BUFFFAIL_CNT                (SRE_PDM_BASE_ADDR + 0xf4 )
#define SRE_PDM_RDBD_FAIL_CNT                   (SRE_PDM_BASE_ADDR + 0xf8 )
#define SRE_PDM_MACETT_FAIL_CNT                 (SRE_PDM_BASE_ADDR + 0xfc )
#define SRE_PDM_RLCETT_FAIL_CNT                 (SRE_PDM_BASE_ADDR + 0x100)
#define SRE_PDM_MAC_PDU_OK_CNT                  (SRE_PDM_BASE_ADDR + 0x104)
#define SRE_PDM_MAC_PDU_ERROR_CNT               (SRE_PDM_BASE_ADDR + 0x108)
#define SRE_PDM_BYP_MACSDU_CNT                  (SRE_PDM_BASE_ADDR + 0x10c)
#define SRE_PDM_RLC_PDU_ERROR_CNT               (SRE_PDM_BASE_ADDR + 0x110)
#define SRE_PDM_TM_RLCPDU_CNT                   (SRE_PDM_BASE_ADDR + 0x114)
#define SRE_PDM_AM_UM_RLCPDU_CNT                (SRE_PDM_BASE_ADDR + 0x118)
#define SRE_PDM_CTRL_RLCPDU_CNT                 (SRE_PDM_BASE_ADDR + 0x11c)
#define SRE_PDM_AXI_WR_LATENCY_AVG_STAT         (SRE_PDM_BASE_ADDR + 0x120)
#define SRE_PDM_AXI_RD_LATENCY_AVG_STAT         (SRE_PDM_BASE_ADDR + 0x124)
#define SRE_PDM_AXI_WR_LATENCY_MAX_STAT         (SRE_PDM_BASE_ADDR + 0x128)
#define SRE_PDM_AXI_RD_LATENCY_MAX_STAT         (SRE_PDM_BASE_ADDR + 0x12c)
#define SRE_PDM_AXI_WR_ACC_STAT                 (SRE_PDM_BASE_ADDR + 0x130)
#define SRE_PDM_AXI_RD_ACC_STAT                 (SRE_PDM_BASE_ADDR + 0x134)
#define SRE_PDM_AXI_WCHN0_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x138)
#define SRE_PDM_AXI_WCHN1_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x13c)
#define SRE_PDM_AXI_WCHN2_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x140)
#define SRE_PDM_AXI_WCHN3_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x144)
#define SRE_PDM_AXI_RCHN0_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x148)
#define SRE_PDM_AXI_RCHN1_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x14c)
#define SRE_PDM_AXI_RCHN2_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x150)
#define SRE_PDM_AXI_RCHN3_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x154)
#define SRE_PDM_AXI_RCHN4_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x158)
#define SRE_PDM_AXI_RCHN5_OTSD_CNT              (SRE_PDM_BASE_ADDR + 0x15c)
#define SRE_PDM_PKT_PRERD_STATE                 (SRE_PDM_BASE_ADDR + 0x160)
#define SRE_PDM_MAC_PARSE_STATE                 (SRE_PDM_BASE_ADDR + 0x164)
#define SRE_PDM_RLC_PARSE_STATE                 (SRE_PDM_BASE_ADDR + 0x168)
#define SRE_PDM_BUS_BUSY                        (SRE_PDM_BASE_ADDR + 0x16c)
#define SRE_PDM_PKT_FINISH                      (SRE_PDM_BASE_ADDR + 0x170)


/* POE 模块寄存器基地址 */
#if 0         /* z00202052 */
#define SRE_POE_BASE                               (0x12000000)
#define SRE_POE_NORMAL_BASE                        (0x1E000000)
#else
#define SRE_POE_BASE                               (0xe2000000)
#define SRE_POE_NORMAL_BASE                        (0xee000000)
#endif        /* z00202052 */

/******************************************************************************/
/*                      MC POE 寄存器定义                                     */
/******************************************************************************/
#define SRE_POE_PDM_WORD0_SPE_ADD_0_REG            (SRE_POE_BASE + 0x0)             /* 加速器PDM指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_PDM_WORD0_SPE_ADD_1_REG            (SRE_POE_BASE + 0x20)            /* 加速器PDM指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_PDM_WORD1_SPE_ADD_0_REG            (SRE_POE_BASE + 0x4)             /* 加速器PDM指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_PDM_WORD1_SPE_ADD_1_REG            (SRE_POE_BASE + 0x24)            /* 加速器PDM指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_PDM_WORD2_SPE_ADD_0_REG            (SRE_POE_BASE + 0x8)             /* 加速器PDM指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_PDM_WORD2_SPE_ADD_1_REG            (SRE_POE_BASE + 0x28)            /* 加速器PDM指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_PDM_WORD3_SPE_ADD_0_REG            (SRE_POE_BASE + 0xC)             /* 加速器PDM指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_PDM_WORD3_SPE_ADD_1_REG            (SRE_POE_BASE + 0x2C)            /* 加速器PDM指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_PDM_WORD4_SPE_ADD_0_REG            (SRE_POE_BASE + 0x10)            /* 加速器PDM指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_PDM_WORD4_SPE_ADD_1_REG            (SRE_POE_BASE + 0x30)            /* 加速器PDM指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_PDM_WORD5_SPE_ADD_0_REG            (SRE_POE_BASE + 0x14)            /* 加速器PDM指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_PDM_WORD5_SPE_ADD_1_REG            (SRE_POE_BASE + 0x34)            /* 加速器PDM指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_PDM_WORD6_SPE_ADD_0_REG            (SRE_POE_BASE + 0x18)            /* 加速器PDM指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_PDM_WORD6_SPE_ADD_1_REG            (SRE_POE_BASE + 0x38)            /* 加速器PDM指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_PDM_WORD7_SPE_ADD_0_REG            (SRE_POE_BASE + 0x1C)            /* 加速器PDM指定队列添加核间消息的ADD_SPE_WORK命令寄存器
 */
#define SRE_POE_PDM_WORD7_SPE_ADD_1_REG            (SRE_POE_BASE + 0x3C)            /* 加速器PDM指定队列添加核间消息的ADD_SPE_WORK命令寄存器
 */

#define POE_PROFILE_DEVICE 1      //POE CPU读写命令寄存器 1:0? DEVICE, NORMAL?

#ifdef POE_PROFILE_DEVICE
#define SRE_POE_VCPU_WORD0_WR_CMD_0_REG            (SRE_POE_BASE + 0x2000)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD0_WR_CMD_1_REG            (SRE_POE_BASE + 0x2020)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD1_WR_CMD_0_REG            (SRE_POE_BASE + 0x2004)          /* 逻辑CPU在POE模块中写命令寄存器。CPU添加任务是否成功，需读取VCPU_ADD_ST寄存器进行确认。 */
#define SRE_POE_VCPU_WORD1_WR_CMD_1_REG            (SRE_POE_BASE + 0x2024)          /* 逻辑CPU在POE模块中写命令寄存器。CPU添加任务是否成功，需读取VCPU_ADD_ST寄存器进行确认。 */
#define SRE_POE_VCPU_WORD2_WR_CMD_0_REG            (SRE_POE_BASE + 0x2008)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD2_WR_CMD_1_REG            (SRE_POE_BASE + 0x2028)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD3_WR_CMD_0_REG            (SRE_POE_BASE + 0x200C)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD3_WR_CMD_1_REG            (SRE_POE_BASE + 0x202C)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD4_WR_CMD_0_REG            (SRE_POE_BASE + 0x2010)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD4_WR_CMD_1_REG            (SRE_POE_BASE + 0x2030)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD5_WR_CMD_0_REG            (SRE_POE_BASE + 0x2014)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD5_WR_CMD_1_REG            (SRE_POE_BASE + 0x2034)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD6_WR_CMD_0_REG            (SRE_POE_BASE + 0x2018)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD6_WR_CMD_1_REG            (SRE_POE_BASE + 0x2038)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD7_WR_CMD_0_REG            (SRE_POE_BASE + 0x201C)          /* 逻辑CPU在POE模块中写命令寄存器。 */
#define SRE_POE_VCPU_WORD7_WR_CMD_1_REG            (SRE_POE_BASE + 0x203C)          /* 逻辑CPU在POE模块中写命令寄存器。 */
#else
#define SRE_POE_VCPU_WORD0_WR_CMD_0_REG            (SRE_POE_NORMAL_BASE + 0x2000)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD0_WR_CMD_1_REG            (SRE_POE_NORMAL_BASE + 0x2020)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD1_WR_CMD_0_REG            (SRE_POE_NORMAL_BASE + 0x2004)          /* 逻辑CPU在POE模块中写命令寄存器。CPU添加任务是否成功，需读取VCPU_ADD_ST寄存器进行确认。 */
#define SRE_POE_VCPU_WORD1_WR_CMD_1_REG            (SRE_POE_NORMAL_BASE + 0x2024)          /* 逻辑CPU在POE模块中写命令寄存器。CPU添加任务是否成功，需读取VCPU_ADD_ST寄存器进行确认。 */
#define SRE_POE_VCPU_WORD2_WR_CMD_0_REG            (SRE_POE_NORMAL_BASE + 0x2008)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD2_WR_CMD_1_REG            (SRE_POE_NORMAL_BASE + 0x2028)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD3_WR_CMD_0_REG            (SRE_POE_NORMAL_BASE + 0x200C)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD3_WR_CMD_1_REG            (SRE_POE_NORMAL_BASE + 0x202C)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD4_WR_CMD_0_REG            (SRE_POE_NORMAL_BASE + 0x2010)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD4_WR_CMD_1_REG            (SRE_POE_NORMAL_BASE + 0x2030)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD5_WR_CMD_0_REG            (SRE_POE_NORMAL_BASE + 0x2014)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD5_WR_CMD_1_REG            (SRE_POE_NORMAL_BASE + 0x2034)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD6_WR_CMD_0_REG            (SRE_POE_NORMAL_BASE + 0x2018)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD6_WR_CMD_1_REG            (SRE_POE_NORMAL_BASE + 0x2038)          /* 逻辑CPU在POE模块中写命令寄存器 */
#define SRE_POE_VCPU_WORD7_WR_CMD_0_REG            (SRE_POE_NORMAL_BASE + 0x201C)          /* 逻辑CPU在POE模块中写命令寄存器。 */
#define SRE_POE_VCPU_WORD7_WR_CMD_1_REG            (SRE_POE_NORMAL_BASE + 0x203C)          /* 逻辑CPU在POE模块中写命令寄存器。 */
#endif

#define SRE_POE_ACC_WORD0_ADD_REG                  (SRE_POE_BASE + 0x2800)          /* 加速器向POE模块中添加包任务的ADD_PACKET命令寄存器。域描述以全局数据结构为准。ROHC,SEC,PDM,Tring，AQM，ULHDCP,DLHDCP,IMA加速器添加包任务专用。 */
#define SRE_POE_ACC_WORD1_ADD_REG                  (SRE_POE_BASE + 0x2804)          /* 加速器向POE模块中添加包任务的ADD_PACKET命令寄存器。ROHC,SEC,PDM,Tring，AQM，ULHDCP,DLHDCP,IMA加速器添加包任务专用。 */
#define SRE_POE_ACC_WORD2_ADD_REG                  (SRE_POE_BASE + 0x2808)          /* 加速器向POE模块中添加包任务的ADD_PACKET命令寄存器。ROHC,SEC,PDM,Tring，AQM，ULHDCP,DLHDCP,IMA加速器添加包任务专用。 */
#define SRE_POE_ACC_WORD3_ADD_REG                  (SRE_POE_BASE + 0x280C)          /* 加速器向POE模块中添加包任务的ADD_PACKET命令寄存器。ROHC,SEC,PDM,Tring，AQM，ULHDCP,DLHDCP,IMA加速器添加包任务专用。 */
#define SRE_POE_TM_SPPE_WORD0_ADD_REG              (SRE_POE_BASE + 0x2820)          /* 加速器向POE模块中添加包任务的ADD_PACKET命令寄存器。域描述以全局数据结构为准。SPPE，TM，POE,MPE加速器添加包任务专用。 */
#define SRE_POE_TM_SPPE_WORD1_ADD_REG              (SRE_POE_BASE + 0x2824)          /* 加速器向POE模块中添加包任务的ADD_PACKET命令寄存器。SPPE，TM，POE,MPE加速器添加包任务专用。 */
#define SRE_POE_TM_SPPE_WORD2_ADD_REG              (SRE_POE_BASE + 0x2828)          /* 加速器向POE模块中添加包任务的ADD_PACKET命令寄存器。SPPE，TM，POE,MPE加速器添加包任务专用。 */
#define SRE_POE_TM_SPPE_WORD3_ADD_REG              (SRE_POE_BASE + 0x282C)          /* 加速器向POE模块中添加包任务的ADD_PACKET命令寄存器。SPPE，TM，POE,MPE加速器添加包任务专用。 */
#define SRE_POE_PPE_WORD0_ADD_REG                  (SRE_POE_BASE + 0x2840)          /* 加速器向POE模块中添加包任务的ADD_PACKET命令寄存器。域描述以全局数据结构为准。PPE加速器添加包任务专用。 */
#define SRE_POE_PPE_WORD1_ADD_REG                  (SRE_POE_BASE + 0x2844)          /* 加速器向POE模块中添加包任务的ADD_PACKET命令寄存器。PPE加速器添加包任务专用。 */
#define SRE_POE_PPE_WORD2_ADD_REG                  (SRE_POE_BASE + 0x2848)          /* 加速器向POE模块中添加包任务的ADD_PACKET命令寄存器。PPE加速器添加包任务专用。 */
#define SRE_POE_PPE_WORD3_ADD_REG                  (SRE_POE_BASE + 0x284C)          /* 加速器向POE模块中添加包任务的ADD_PACKET命令寄存器。PPE加速器添加包任务专用。
下面从2860~3FFC地址保留 */

#ifdef POE_PROFILE_DEVICE
#define SRE_POE_VCPU_WORD0_SPE_ADD_0_REG           (SRE_POE_BASE + 0x4000)          /* 逻辑CPU_0指定队列添加核间消息的ADD_SPE_WORK命令寄存器。CPU添加任务是否成功，需读取VCPU_ADD_ST寄存器进行确认。 */
#define SRE_POE_VCPU_WORD0_SPE_ADD_1_REG           (SRE_POE_BASE + 0x4020)          /* 逻辑CPU_0指定队列添加核间消息的ADD_SPE_WORK命令寄存器。CPU添加任务是否成功，需读取VCPU_ADD_ST寄存器进行确认。 */
#define SRE_POE_VCPU_WORD0_SPE_ADD_2_REG           (SRE_POE_BASE + 0x6000)          /* 逻辑CPU_0指定队列添加核间消息的ADD_SPE_WORK命令寄存器。CPU添加任务是否成功，需读取VCPU_ADD_ST寄存器进行确认。 */
#define SRE_POE_VCPU_WORD0_SPE_ADD_3_REG           (SRE_POE_BASE + 0x6020)          /* 逻辑CPU_0指定队列添加核间消息的ADD_SPE_WORK命令寄存器。CPU添加任务是否成功，需读取VCPU_ADD_ST寄存器进行确认。 */
#define SRE_POE_VCPU_WORD1_SPE_ADD_0_REG           (SRE_POE_BASE + 0x4004)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD1_SPE_ADD_1_REG           (SRE_POE_BASE + 0x4024)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD1_SPE_ADD_2_REG           (SRE_POE_BASE + 0x6004)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD1_SPE_ADD_3_REG           (SRE_POE_BASE + 0x6024)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD2_SPE_ADD_0_REG           (SRE_POE_BASE + 0x4008)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD2_SPE_ADD_1_REG           (SRE_POE_BASE + 0x4028)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD2_SPE_ADD_2_REG           (SRE_POE_BASE + 0x6008)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD2_SPE_ADD_3_REG           (SRE_POE_BASE + 0x6028)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD3_SPE_ADD_0_REG           (SRE_POE_BASE + 0x400C)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD3_SPE_ADD_1_REG           (SRE_POE_BASE + 0x402C)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD3_SPE_ADD_2_REG           (SRE_POE_BASE + 0x600C)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD3_SPE_ADD_3_REG           (SRE_POE_BASE + 0x602C)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD4_SPE_ADD_0_REG           (SRE_POE_BASE + 0x4010)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD4_SPE_ADD_1_REG           (SRE_POE_BASE + 0x4030)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD4_SPE_ADD_2_REG           (SRE_POE_BASE + 0x6010)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD4_SPE_ADD_3_REG           (SRE_POE_BASE + 0x6030)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD5_SPE_ADD_0_REG           (SRE_POE_BASE + 0x4014)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD5_SPE_ADD_1_REG           (SRE_POE_BASE + 0x4034)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD5_SPE_ADD_2_REG           (SRE_POE_BASE + 0x6014)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD5_SPE_ADD_3_REG           (SRE_POE_BASE + 0x6034)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD6_SPE_ADD_0_REG           (SRE_POE_BASE + 0x4018)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD6_SPE_ADD_1_REG           (SRE_POE_BASE + 0x4038)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD6_SPE_ADD_2_REG           (SRE_POE_BASE + 0x6018)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD6_SPE_ADD_3_REG           (SRE_POE_BASE + 0x6038)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD7_SPE_ADD_0_REG           (SRE_POE_BASE + 0x401C)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器
以下0x84000~0x84ffc地址保留 */
#define SRE_POE_VCPU_WORD7_SPE_ADD_1_REG           (SRE_POE_BASE + 0x403C)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器
以下0x84000~0x84ffc地址保留 */
#define SRE_POE_VCPU_WORD7_SPE_ADD_2_REG           (SRE_POE_BASE + 0x601C)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器
以下0x84000~0x84ffc地址保留 */
#define SRE_POE_VCPU_WORD7_SPE_ADD_3_REG           (SRE_POE_BASE + 0x603C)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器
以下0x84000~0x84ffc地址保留 */
#else
#define SRE_POE_VCPU_WORD0_SPE_ADD_0_REG           (SRE_POE_NORMAL_BASE + 0x4000)          /* 逻辑CPU_0指定队列添加核间消息的ADD_SPE_WORK命令寄存器。CPU添加任务是否成功，需读取VCPU_ADD_ST寄存器进行确认。 */
#define SRE_POE_VCPU_WORD0_SPE_ADD_1_REG           (SRE_POE_NORMAL_BASE + 0x4020)          /* 逻辑CPU_0指定队列添加核间消息的ADD_SPE_WORK命令寄存器。CPU添加任务是否成功，需读取VCPU_ADD_ST寄存器进行确认。 */
#define SRE_POE_VCPU_WORD0_SPE_ADD_2_REG           (SRE_POE_NORMAL_BASE + 0x6000)          /* 逻辑CPU_0指定队列添加核间消息的ADD_SPE_WORK命令寄存器。CPU添加任务是否成功，需读取VCPU_ADD_ST寄存器进行确认。 */
#define SRE_POE_VCPU_WORD0_SPE_ADD_3_REG           (SRE_POE_NORMAL_BASE + 0x6020)          /* 逻辑CPU_0指定队列添加核间消息的ADD_SPE_WORK命令寄存器。CPU添加任务是否成功，需读取VCPU_ADD_ST寄存器进行确认。 */
#define SRE_POE_VCPU_WORD1_SPE_ADD_0_REG           (SRE_POE_NORMAL_BASE + 0x4004)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD1_SPE_ADD_1_REG           (SRE_POE_NORMAL_BASE + 0x4024)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD1_SPE_ADD_2_REG           (SRE_POE_NORMAL_BASE + 0x6004)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD1_SPE_ADD_3_REG           (SRE_POE_NORMAL_BASE + 0x6024)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD2_SPE_ADD_0_REG           (SRE_POE_NORMAL_BASE + 0x4008)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD2_SPE_ADD_1_REG           (SRE_POE_NORMAL_BASE + 0x4028)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD2_SPE_ADD_2_REG           (SRE_POE_NORMAL_BASE + 0x6008)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD2_SPE_ADD_3_REG           (SRE_POE_NORMAL_BASE + 0x6028)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD3_SPE_ADD_0_REG           (SRE_POE_NORMAL_BASE + 0x400C)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD3_SPE_ADD_1_REG           (SRE_POE_NORMAL_BASE + 0x402C)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD3_SPE_ADD_2_REG           (SRE_POE_NORMAL_BASE + 0x600C)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD3_SPE_ADD_3_REG           (SRE_POE_NORMAL_BASE + 0x602C)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD4_SPE_ADD_0_REG           (SRE_POE_NORMAL_BASE + 0x4010)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD4_SPE_ADD_1_REG           (SRE_POE_NORMAL_BASE + 0x4030)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD4_SPE_ADD_2_REG           (SRE_POE_NORMAL_BASE + 0x6010)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD4_SPE_ADD_3_REG           (SRE_POE_NORMAL_BASE + 0x6030)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD5_SPE_ADD_0_REG           (SRE_POE_NORMAL_BASE + 0x4014)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD5_SPE_ADD_1_REG           (SRE_POE_NORMAL_BASE + 0x4034)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD5_SPE_ADD_2_REG           (SRE_POE_NORMAL_BASE + 0x6014)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD5_SPE_ADD_3_REG           (SRE_POE_NORMAL_BASE + 0x6034)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD6_SPE_ADD_0_REG           (SRE_POE_NORMAL_BASE + 0x4018)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD6_SPE_ADD_1_REG           (SRE_POE_NORMAL_BASE + 0x4038)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD6_SPE_ADD_2_REG           (SRE_POE_NORMAL_BASE + 0x6018)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD6_SPE_ADD_3_REG           (SRE_POE_NORMAL_BASE + 0x6038)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器 */
#define SRE_POE_VCPU_WORD7_SPE_ADD_0_REG           (SRE_POE_NORMAL_BASE + 0x401C)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器
以下0x84000~0x84ffc地址保留 */
#define SRE_POE_VCPU_WORD7_SPE_ADD_1_REG           (SRE_POE_NORMAL_BASE + 0x403C)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器
以下0x84000~0x84ffc地址保留 */
#define SRE_POE_VCPU_WORD7_SPE_ADD_2_REG           (SRE_POE_NORMAL_BASE + 0x601C)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器
以下0x84000~0x84ffc地址保留 */
#define SRE_POE_VCPU_WORD7_SPE_ADD_3_REG           (SRE_POE_NORMAL_BASE + 0x603C)          /* 逻辑CPU指定队列添加核间消息的ADD_SPE_WORK命令寄存器
以下0x84000~0x84ffc地址保留 */
#endif

#define SRE_POE_SEC_WORD0_GET_REG                  (SRE_POE_BASE + 0x85000)         /* POE模块中SEC的GET_POE命令寄存器。 */
#define SRE_POE_SEC_WORD1_GET_REG                  (SRE_POE_BASE + 0x85004)         /* POE模块中SEC的GET_POE命令寄存器。 */
#define SRE_POE_SEC_WORD2_GET_REG                  (SRE_POE_BASE + 0x85008)         /* POE模块中SEC的GET_POE命令寄存器。 */
#define SRE_POE_SEC_WORD3_GET_REG                  (SRE_POE_BASE + 0x8500C)         /* POE模块中SEC的GET_POE命令寄存器。 */
#define SRE_POE_SPPE_WORD0_GET_REG                 (SRE_POE_BASE + 0x85020)         /* POE模块中SPPE的GET_POE命令寄存器。 */
#define SRE_POE_SPPE_WORD1_GET_REG                 (SRE_POE_BASE + 0x85024)         /* POE模块中SPPE的GET_POE命令寄存器。 */
#define SRE_POE_SPPE_WORD2_GET_REG                 (SRE_POE_BASE + 0x85028)         /* POE模块中SPPE的GET_POE命令寄存器。 */
#define SRE_POE_SPPE_WORD3_GET_REG                 (SRE_POE_BASE + 0x8502C)         /* POE模块中SPPE的GET_POE命令寄存器。 */
#define SRE_POE_ROHC_ZIP_WORD0_GET_REG             (SRE_POE_BASE + 0x85040)         /* POE模块中ROHC压缩的GET_POE命令寄存器。 */
#define SRE_POE_ROHC_ZIP_WORD1_GET_REG             (SRE_POE_BASE + 0x85044)         /* POE模块中ROHC压缩的GET_POE命令寄存器。 */
#define SRE_POE_ROHC_ZIP_WORD2_GET_REG             (SRE_POE_BASE + 0x85048)         /* POE模块中ROHC压缩的GET_POE命令寄存器。 */
#define SRE_POE_ROHC_ZIP_WORD3_GET_REG             (SRE_POE_BASE + 0x8504C)         /* POE模块中ROHC压缩的GET_POE命令寄存器。 */
#define SRE_POE_ROHC_UZIP_WORD0_GET_REG            (SRE_POE_BASE + 0x85060)         /* POE模块中ROHC解压缩的GET_POE命令寄存器。 */
#define SRE_POE_ROHC_UZIP_WORD1_GET_REG            (SRE_POE_BASE + 0x85064)         /* POE模块中ROHC解压缩的GET_POE命令寄存器。 */
#define SRE_POE_ROHC_UZIP_WORD2_GET_REG            (SRE_POE_BASE + 0x85068)         /* POE模块中ROHC解压缩的GET_POE命令寄存器。 */
#define SRE_POE_ROHC_UZIP_WORD3_GET_REG            (SRE_POE_BASE + 0x8506C)         /* POE模块中ROHC解压缩的GET_POE命令寄存器。 */
#define SRE_POE_PDM_WORD0_GET_REG                  (SRE_POE_BASE + 0x85080)         /* POE模块中PDM的GET_POE命令寄存器。 */
#define SRE_POE_PDM_WORD1_GET_REG                  (SRE_POE_BASE + 0x85084)         /* POE模块中PDM的GET_POE命令寄存器。 */
#define SRE_POE_PDM_WORD2_GET_REG                  (SRE_POE_BASE + 0x85088)         /* POE模块中PDM的GET_POE命令寄存器。 */
#define SRE_POE_PDM_WORD3_GET_REG                  (SRE_POE_BASE + 0x8508C)         /* POE模块中PDM的GET_POE命令寄存器。 */
#define SRE_POE_ULHDCP_WORD0_GET_REG               (SRE_POE_BASE + 0x850A0)         /* POE模块中HDCP的GET_POE命令寄存器。 */
#define SRE_POE_ULHDCP_WORD1_GET_REG               (SRE_POE_BASE + 0x850A4)         /* POE模块中HDCP的GET_POE命令寄存器。 */
#define SRE_POE_ULHDCP_WORD2_GET_REG               (SRE_POE_BASE + 0x850A8)         /* POE模块中HDCP的GET_POE命令寄存器。 */
#define SRE_POE_ULHDCP_WORD3_GET_REG               (SRE_POE_BASE + 0x850AC)         /* POE模块中HDCP的GET_POE命令寄存器。 */
#define SRE_POE_DLHDCP_WORD0_GET_REG               (SRE_POE_BASE + 0x850C0)         /* POE模块中HDCP的GET_POE命令寄存器。 */
#define SRE_POE_DLHDCP_WORD1_GET_REG               (SRE_POE_BASE + 0x850C4)         /* POE模块中HDCP的GET_POE命令寄存器。 */
#define SRE_POE_DLHDCP_WORD2_GET_REG               (SRE_POE_BASE + 0x850C8)         /* POE模块中HDCP的GET_POE命令寄存器。 */
#define SRE_POE_DLHDCP_WORD3_GET_REG               (SRE_POE_BASE + 0x850CC)         /* POE模块中HDCP的GET_POE命令寄存器。
 */
#define SRE_POE_ACC_WORD0_GET_0_REG                (SRE_POE_BASE + 0x850E0)         /* POE模块中预留加速器ACC_{0~5}的GET_POE命令寄存器。0x0FC~0x10BC */
#define SRE_POE_ACC_WORD0_GET_1_REG                (SRE_POE_BASE + 0x85100)         /* POE模块中预留加速器ACC_{0~5}的GET_POE命令寄存器。0x0FC~0x10BC */
#define SRE_POE_ACC_WORD1_GET_0_REG                (SRE_POE_BASE + 0x850E4)         /* POE模块中预留加速器ACC_{0~5}的GET_POE命令寄存器。 */
#define SRE_POE_ACC_WORD1_GET_1_REG                (SRE_POE_BASE + 0x85104)         /* POE模块中预留加速器ACC_{0~5}的GET_POE命令寄存器。 */
#define SRE_POE_ACC_WORD2_GET_0_REG                (SRE_POE_BASE + 0x850E8)         /* POE模块中预留加速器ACC_{0~5}的GET_POE命令寄存器。 */
#define SRE_POE_ACC_WORD2_GET_1_REG                (SRE_POE_BASE + 0x85108)         /* POE模块中预留加速器ACC_{0~5}的GET_POE命令寄存器。 */
#define SRE_POE_ACC_WORD3_GET_0_REG                (SRE_POE_BASE + 0x850EC)         /* POE模块中预留加速器ACC_{0~5}的GET_POE命令寄存器。
以下0x851a0~0x857fc保留 */
#define SRE_POE_ACC_WORD3_GET_1_REG                (SRE_POE_BASE + 0x8510C)         /* POE模块中预留加速器ACC_{0~5}的GET_POE命令寄存器。
以下0x851a0~0x857fc保留 */
#define SRE_POE_VCPU_WORD0_GET_0_REG               (SRE_POE_BASE + 0x85800)         /* POE模块中逻辑CPU_{0~63}的GET_POE命令寄存器。 */
#define SRE_POE_VCPU_WORD0_GET_1_REG               (SRE_POE_BASE + 0x85820)         /* POE模块中逻辑CPU_{0~63}的GET_POE命令寄存器。 */
#define SRE_POE_VCPU_WORD1_GET_0_REG               (SRE_POE_BASE + 0x85804)         /* POE模块中逻辑CPU_{0~63}的GET_POE命令寄存器。 */
#define SRE_POE_VCPU_WORD1_GET_1_REG               (SRE_POE_BASE + 0x85824)         /* POE模块中逻辑CPU_{0~63}的GET_POE命令寄存器。 */
#define SRE_POE_VCPU_WORD2_GET_0_REG               (SRE_POE_BASE + 0x85808)         /* POE模块中逻辑CPU_{0~63}的GET_POE命令寄存器。 */
#define SRE_POE_VCPU_WORD2_GET_1_REG               (SRE_POE_BASE + 0x85828)         /* POE模块中逻辑CPU_{0~63}的GET_POE命令寄存器。 */
#define SRE_POE_VCPU_WORD3_GET_0_REG               (SRE_POE_BASE + 0x8580C)         /* POE模块中逻辑CPU_{0~63}的GET_POE命令寄存器。 */
#define SRE_POE_VCPU_WORD3_GET_1_REG               (SRE_POE_BASE + 0x8582C)         /* POE模块中逻辑CPU_{0~63}的GET_POE命令寄存器。 */
#define SRE_POE_VCPU_WORD4_GET_0_REG               (SRE_POE_BASE + 0x85810)         /* POE模块中逻辑CPU_{0~63}的GET_POE命令寄存器。 */
#define SRE_POE_VCPU_WORD4_GET_1_REG               (SRE_POE_BASE + 0x85830)         /* POE模块中逻辑CPU_{0~63}的GET_POE命令寄存器。 */
#define SRE_POE_VCPU_WORD5_GET_0_REG               (SRE_POE_BASE + 0x85814)         /* POE模块中逻辑CPU_{0~63}的GET_POE命令寄存器。 */
#define SRE_POE_VCPU_WORD5_GET_1_REG               (SRE_POE_BASE + 0x85834)         /* POE模块中逻辑CPU_{0~63}的GET_POE命令寄存器。 */
#define SRE_POE_VCPU_WORD6_GET_0_REG               (SRE_POE_BASE + 0x85818)         /* POE模块中逻辑CPU_{0~63}的GET_POE命令寄存器。 */
#define SRE_POE_VCPU_WORD6_GET_1_REG               (SRE_POE_BASE + 0x85838)         /* POE模块中逻辑CPU_{0~63}的GET_POE命令寄存器。 */
#define SRE_POE_VCPU_WORD7_GET_0_REG               (SRE_POE_BASE + 0x8581C)         /* POE模块中逻辑CPU_{0~63}的GET_POE命令寄存器。 */
#define SRE_POE_VCPU_WORD7_GET_1_REG               (SRE_POE_BASE + 0x8583C)         /* POE模块中逻辑CPU_{0~63}的GET_POE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD0_GET_0_REG             (SRE_POE_BASE + 0x86000)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD0_GET_1_REG             (SRE_POE_BASE + 0x86020)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD0_GET_2_REG             (SRE_POE_BASE + 0x88000)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD0_GET_3_REG             (SRE_POE_BASE + 0x88020)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD1_GET_0_REG             (SRE_POE_BASE + 0x86004)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD1_GET_1_REG             (SRE_POE_BASE + 0x86024)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD1_GET_2_REG             (SRE_POE_BASE + 0x88004)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD1_GET_3_REG             (SRE_POE_BASE + 0x88024)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD2_GET_0_REG             (SRE_POE_BASE + 0x86008)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD2_GET_1_REG             (SRE_POE_BASE + 0x86028)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD2_GET_2_REG             (SRE_POE_BASE + 0x88008)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD2_GET_3_REG             (SRE_POE_BASE + 0x88028)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD3_GET_0_REG             (SRE_POE_BASE + 0x8600C)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD3_GET_1_REG             (SRE_POE_BASE + 0x8602C)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD3_GET_2_REG             (SRE_POE_BASE + 0x8800C)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD3_GET_3_REG             (SRE_POE_BASE + 0x8802C)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD4_GET_0_REG             (SRE_POE_BASE + 0x86010)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD4_GET_1_REG             (SRE_POE_BASE + 0x86030)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD4_GET_2_REG             (SRE_POE_BASE + 0x88010)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD4_GET_3_REG             (SRE_POE_BASE + 0x88030)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD5_GET_0_REG             (SRE_POE_BASE + 0x86014)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD5_GET_1_REG             (SRE_POE_BASE + 0x86034)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD5_GET_2_REG             (SRE_POE_BASE + 0x88014)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD5_GET_3_REG             (SRE_POE_BASE + 0x88034)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD6_GET_0_REG             (SRE_POE_BASE + 0x86018)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD6_GET_1_REG             (SRE_POE_BASE + 0x86038)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD6_GET_2_REG             (SRE_POE_BASE + 0x88018)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD6_GET_3_REG             (SRE_POE_BASE + 0x88038)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD7_GET_0_REG             (SRE_POE_BASE + 0x8601C)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD7_GET_1_REG             (SRE_POE_BASE + 0x8603C)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD7_GET_2_REG             (SRE_POE_BASE + 0x8801C)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_Q_WORD7_GET_3_REG             (SRE_POE_BASE + 0x8803C)         /* POE模块中，CPU指定队列读取任务的GET_QUEUE命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD0_GET_0_REG           (SRE_POE_BASE + 0x106000)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD0_GET_1_REG           (SRE_POE_BASE + 0x106020)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD0_GET_2_REG           (SRE_POE_BASE + 0x106400)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD0_GET_3_REG           (SRE_POE_BASE + 0x106420)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD1_GET_0_REG           (SRE_POE_BASE + 0x106004)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD1_GET_1_REG           (SRE_POE_BASE + 0x106024)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD1_GET_2_REG           (SRE_POE_BASE + 0x106404)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD1_GET_3_REG           (SRE_POE_BASE + 0x106424)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD2_GET_0_REG           (SRE_POE_BASE + 0x106008)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD2_GET_1_REG           (SRE_POE_BASE + 0x106028)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD2_GET_2_REG           (SRE_POE_BASE + 0x106408)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD2_GET_3_REG           (SRE_POE_BASE + 0x106428)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD3_GET_0_REG           (SRE_POE_BASE + 0x10600C)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD3_GET_1_REG           (SRE_POE_BASE + 0x10602C)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD3_GET_2_REG           (SRE_POE_BASE + 0x10640C)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD3_GET_3_REG           (SRE_POE_BASE + 0x10642C)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD4_GET_0_REG           (SRE_POE_BASE + 0x106010)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD4_GET_1_REG           (SRE_POE_BASE + 0x106030)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD4_GET_2_REG           (SRE_POE_BASE + 0x106410)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD4_GET_3_REG           (SRE_POE_BASE + 0x106430)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD5_GET_0_REG           (SRE_POE_BASE + 0x106014)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD5_GET_1_REG           (SRE_POE_BASE + 0x106034)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD5_GET_2_REG           (SRE_POE_BASE + 0x106414)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD5_GET_3_REG           (SRE_POE_BASE + 0x106434)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD6_GET_0_REG           (SRE_POE_BASE + 0x106018)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD6_GET_1_REG           (SRE_POE_BASE + 0x106038)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD6_GET_2_REG           (SRE_POE_BASE + 0x106418)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD6_GET_3_REG           (SRE_POE_BASE + 0x106438)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。 */
#define SRE_POE_VCPU_GRP_WORD7_GET_0_REG           (SRE_POE_BASE + 0x10601C)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。
以下0x116000~0x3ffffc地址保留。以下是配置寄存器 */
#define SRE_POE_VCPU_GRP_WORD7_GET_1_REG           (SRE_POE_BASE + 0x10603C)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。
以下0x116000~0x3ffffc地址保留。以下是配置寄存器 */
#define SRE_POE_VCPU_GRP_WORD7_GET_2_REG           (SRE_POE_BASE + 0x10641C)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。
以下0x116000~0x3ffffc地址保留。以下是配置寄存器 */
#define SRE_POE_VCPU_GRP_WORD7_GET_3_REG           (SRE_POE_BASE + 0x10643C)        /* POE模块中，CPU指定Group读取任务的GET_GROUP命令寄存器。
以下0x116000~0x3ffffc地址保留。以下是配置寄存器 */
#define SRE_POE_GRP_VCPU_MASK_0_REG                (SRE_POE_BASE + 0x400000)        /* POE模块逻辑CPU的Group掩码寄存器。 */
#define SRE_POE_GRP_VCPU_MASK_1_REG                (SRE_POE_BASE + 0x400004)        /* POE模块逻辑CPU的Group掩码寄存器。 */
#define SRE_POE_GRP_SEC_MASK_REG                   (SRE_POE_BASE + 0x400100)        /* POE模块SEC的Group掩码寄存器。 */
#define SRE_POE_GRP_ROHCZ_MASK_REG                 (SRE_POE_BASE + 0x400104)        /* POE模块"ROHC中压缩功能"的Group掩码寄存器。 */
#define SRE_POE_GRP_ROHCUZ_MASK_REG                (SRE_POE_BASE + 0x400108)        /* POE模块"ROHC中解压功能"的Group掩码寄存器。 */
#define SRE_POE_GRP_SPPE_MASK_REG                  (SRE_POE_BASE + 0x40010C)        /* POE模块SPPE的Group掩码寄存器。 */
#define SRE_POE_GRP_PDM_MASK_REG                   (SRE_POE_BASE + 0x400110)        /* POE模块PDM的Group掩码寄存器。 */
#define SRE_POE_GRP_ULHDCP_MASK_REG                (SRE_POE_BASE + 0x40011C)        /* POE模块ULHDCP的Group掩码寄存器。 */
#define SRE_POE_GRP_DLHDCP_MASK_REG                (SRE_POE_BASE + 0x400120)        /* POE模块DLHDCP的Group掩码寄存器。 */
#define SRE_POE_GRP_ACC_MASK_0_REG                 (SRE_POE_BASE + 0x400124)        /* POE模块预留6个加速器ACC的Group掩码寄存器。
以下0x40013C保留 */
#define SRE_POE_GRP_ACC_MASK_1_REG                 (SRE_POE_BASE + 0x400128)        /* POE模块预留6个加速器ACC的Group掩码寄存器。
以下0x40013C保留 */
#define SRE_POE_GRP_BP_TH_0_REG                    (SRE_POE_BASE + 0x400140)        /* POE模块中Group_{0~31}反压水线配置寄存器。Group的包达到这个配置的水线值时反压所有模块，Group中不再接收任务添加。 */
#define SRE_POE_GRP_BP_TH_1_REG                    (SRE_POE_BASE + 0x400144)        /* POE模块中Group_{0~31}反压水线配置寄存器。Group的包达到这个配置的水线值时反压所有模块，Group中不再接收任务添加。 */
#define SRE_POE_SCH_SEL_CFG_REG                    (SRE_POE_BASE + 0x4001C0)        /* POE模块调度算法选择配置寄存器。 */
#define SRE_POE_GRP_SCH_CFG_0_REG                  (SRE_POE_BASE + 0x4001C4)        /* 基带调度算法（先Group后QoS）时，每个Group选择的调度算法配置寄存器0。 */
#define SRE_POE_GRP_SCH_CFG_1_REG                  (SRE_POE_BASE + 0x4001C8)        /* 基带调度算法（先Group后QoS）时，每个Group选择的调度算法配置寄存器1。 */
#define SRE_POE_WRR_CFG_0_REG                      (SRE_POE_BASE + 0x4001CC)        /* 基带调度算法（先Group后QoS）时，POE模块对Group{0~31}进行PQ+WRR算法配置寄存器。
主控调度算法时，POE进行PQ+WRR算法的配置寄存器。
权重值配置为0时，不参与调度，不会有任务调度出来，
注意：主控调度算法（先QoS后Group）时，QoS0在调度时，无论选择PQ还是WRR，对应的权重必须配置为非零（WRR_CFG{0}寄存器的q0_weight域配置为非零），QoS0中的任务才能调度出，不然QoS0中的任务无法调度出来。
以下地址0x4002CC保留 */
#define SRE_POE_WRR_CFG_1_REG                      (SRE_POE_BASE + 0x4001D0)        /* 基带调度算法（先Group后QoS）时，POE模块对Group{0~31}进行PQ+WRR算法配置寄存器。
主控调度算法时，POE进行PQ+WRR算法的配置寄存器。
权重值配置为0时，不参与调度，不会有任务调度出来，
注意：主控调度算法（先QoS后Group）时，QoS0在调度时，无论选择PQ还是WRR，对应的权重必须配置为非零（WRR_CFG{0}寄存器的q0_weight域配置为非零），QoS0中的任务才能调度出，不然QoS0中的任务无法调度出来。
以下地址0x4002CC保留 */
#define SRE_POE_DDR_VMID_CFG_REG                   (SRE_POE_BASE + 0x4002D0)        /* POE的任务溢出到那个VM的配置寄存器
 */
#define SRE_POE_TM_VMID_CFG_REG                    (SRE_POE_BASE + 0x4002D4)        /* POE推送任务到TM的VM的配置寄存器，TM在哪个VM的空间
 */
#define SRE_POE_TM_ADDR_CFG_REG                    (SRE_POE_BASE + 0x4002D8)        /* POE推送任务到TM的地址配置寄存器，添加到TM的地址
 */
#define SRE_POE_AQM_VMID_CFG_REG                   (SRE_POE_BASE + 0x4002DC)        /* POE推送任务到AQM的VM的配置寄存器，AQM在哪个VM的空间
 */
#define SRE_POE_AQM_ADDR_CFG_REG                   (SRE_POE_BASE + 0x4002E0)        /* POE推送任务到AQM的地址配置寄存器，添加到AQM的地址
 */
#define SRE_POE_MPE_VMID_CFG_REG                   (SRE_POE_BASE + 0x4002E4)        /* POE推送任务到MPE的VM的配置寄存器，MPE在哪个VM的空间
 */
#define SRE_POE_MPE_ADDR_CFG_REG                   (SRE_POE_BASE + 0x4002E8)        /* POE推送任务到MPE的地址配置寄存器，添加到MPE的地址
 */
#define SRE_POE_POE_VMID_CFG_REG                   (SRE_POE_BASE + 0x4002EC)        /* POE推送任务到POE的VM的配置寄存器，POE在哪个VM的空间
 */
#define SRE_POE_POE_ADDR_CFG_REG                   (SRE_POE_BASE + 0x4002F0)        /* POE推送任务到POE的地址配置寄存器，添加到POE的地址
 */
#define SRE_POE_SEND_TRY_CNT_REG                   (SRE_POE_BASE + 0x4002F4)        /* POE模块推送任务到TM/AQM/MPE/POE上报中断的最大重试次数 */
#define SRE_POE_SEND_TRY_INTER_REG                 (SRE_POE_BASE + 0x4002F8)        /* POE模块添加任务到TM/AQM/MPE/POE时，添加失败，再次重试添加的间隔时间，以POE的时钟周期为单位。（时钟周期750M） */
#define SRE_POE_CPU_EVENT_MODE_CFG_REG             (SRE_POE_BASE + 0x4002FC)        /* POE模块将CPU从睡眠状态唤醒的方式选择。 */
#define SRE_POE_CPU_CORE_EVENT_CFG_0_REG           (SRE_POE_BASE + 0x400300)        /* POE模块根据CPU配置发送触发信号event将CPU从睡眠状态唤醒。
 */
#define SRE_POE_CPU_CORE_EVENT_CFG_1_REG           (SRE_POE_BASE + 0x400304)        /* POE模块根据CPU配置发送触发信号event将CPU从睡眠状态唤醒。
 */
#define SRE_POE_SEND_TM_OUT_CNT_CFG_REG            (SRE_POE_BASE + 0x400340)        /* POE模块将推送任务到TM的outstanding个数配置寄存器。最大配置为4 */
#define SRE_POE_SEND_MPE_OUT_CNT_CFG_REG           (SRE_POE_BASE + 0x400344)        /* POE模块将推送任务到MPE的outstanding个数配置寄存器。最大配置为4 */
#define SRE_POE_SEND_POE_OUT_CNT_CFG_REG           (SRE_POE_BASE + 0x400348)        /* POE模块将推送任务到POE的outstanding个数配置寄存器。最大配置为4
以下0x40034C～0x4003D0保留 */
#define SRE_POE_GRP_INT_CNT_CFG_0_REG              (SRE_POE_BASE + 0x4003D4)        /* POE模块Input-queue中断水线配置寄存器。当group{0~31}中的任务个数达到这个设定值的时候，是加速器处理的Group就置有效逻辑线。是CPU处理的Group就上报中断。 */
#define SRE_POE_GRP_INT_CNT_CFG_1_REG              (SRE_POE_BASE + 0x4003D8)        /* POE模块Input-queue中断水线配置寄存器。当group{0~31}中的任务个数达到这个设定值的时候，是加速器处理的Group就置有效逻辑线。是CPU处理的Group就上报中断。 */
#define SRE_POE_INPUT_TMOUT_CFG_REG                (SRE_POE_BASE + 0x400454)        /* POE模块任务缓存队列（input_queue）中，超时配置寄存器，超时上报中断。 */
#define SRE_POE_INFLIGHT_TMOUT_CFG_REG             (SRE_POE_BASE + 0x400458)        /* POE模块in-flight保序队列超时配置寄存器，超时上报中断。 */
#define SRE_POE_DESCH_TMOUT_CFG_REG                (SRE_POE_BASE + 0x40045C)        /* POE模块解绑定任务缓存队列超时配置寄存器，超时上报中断。 */
#define SRE_POE_INIT_RAM_START_REG                 (SRE_POE_BASE + 0x400460)        /* POE模块的初始化寄存器。对POE内部RAM进行初始化 */
#define SRE_POE_INIT_RAM_DONE_REG                  (SRE_POE_BASE + 0x400464)        /* POE模块的初始化结束状态寄存器。 */
#define SRE_POE_GRP_ORDER_EN_0_REG                 (SRE_POE_BASE + 0x400468)        /* POE模块Group是否保序配置寄存器。以下0x4004E8~0x400570保留 */
#define SRE_POE_GRP_ORDER_EN_1_REG                 (SRE_POE_BASE + 0x40046C)        /* POE模块Group是否保序配置寄存器。以下0x4004E8~0x400570保留 */
#define SRE_POE_Q_BP_TH_ST_0_REG                   (SRE_POE_BASE + 0x400574)        /* POE模块中queue高低水线中断状态寄存器。
 */
#define SRE_POE_Q_BP_TH_ST_1_REG                   (SRE_POE_BASE + 0x400578)        /* POE模块中queue高低水线中断状态寄存器。
 */
#define SRE_POE_Q_BP_PARI_ERR_Q_REG                (SRE_POE_BASE + 0x400594)        /* POE模块中Q_BP_TH反压水线的RAM出现奇偶校验错误时，记录错误队列号寄存器。
以下0x400598~0x4006f8保留 */
#define SRE_POE_CORE_MSG_BIT_REG                   (SRE_POE_BASE + 0x4006FC)        /* CPU操作POE的位宽配置寄存器。以128bit还是以256bit操作，不能混合操作。
 */
#define SRE_POE_OVER_BASE_ADDR_GRP_0_REG           (SRE_POE_BASE + 0x400700)        /* POE模块中group溢出基地址配置寄存器。 */
#define SRE_POE_OVER_BASE_ADDR_GRP_1_REG           (SRE_POE_BASE + 0x400704)        /* POE模块中group溢出基地址配置寄存器。 */
#define SRE_POE_OVER_LEN_GRP_0_REG                 (SRE_POE_BASE + 0x400780)        /* POE模块中group溢出空间大小配置寄存器。 */
#define SRE_POE_OVER_LEN_GRP_1_REG                 (SRE_POE_BASE + 0x400784)        /* POE模块中group溢出空间大小配置寄存器。 */
#define SRE_POE_OVER_DDR_INIT_START_REG            (SRE_POE_BASE + 0x400800)        /* POE模块中group溢出基地址的初始化配置寄存器。 */
#define SRE_POE_OVER_DDR_INIT_DONE_REG             (SRE_POE_BASE + 0x400804)        /* POE模块中group溢出基地址配置寄存器。
以下0x400808~4008F4保留 */
#define SRE_POE_INIT_BP_TH_START_REG               (SRE_POE_BASE + 0x4008F8)        /* POE模块的初始化寄存器。对POE内部Q_BP_TH的RAM进行初始化 */
#define SRE_POE_INIT_BP_TH_DONE_REG                (SRE_POE_BASE + 0x4008FC)        /* POE模块的初始化结束状态寄存器。查看Q_BP_TH的RAM是否初始化完成 */
#define SRE_POE_Q_BP_TH_H_0_REG                    (SRE_POE_BASE + 0x400900)        /* POE模块中queue中断高水线。Memory实现。
此寄存器配置前必须先配置INIT_RAM_START初始化内部RAM。不能同时读写此寄存器，如果出现同时读写，写优先，读数据反馈全零。 */
#define SRE_POE_Q_BP_TH_H_1_REG                    (SRE_POE_BASE + 0x400904)        /* POE模块中queue中断高水线。Memory实现。
此寄存器配置前必须先配置INIT_RAM_START初始化内部RAM。不能同时读写此寄存器，如果出现同时读写，写优先，读数据反馈全零。 */
#define SRE_POE_Q_BP_TH_L_0_REG                    (SRE_POE_BASE + 0x400D00)        /* POE模块中queue中断低水线。Memory实现。
此寄存器配置前必须先配置INIT_RAM_START初始化内部RAM。不能同时读写此寄存器，如果出现同时读写，写优先，读数据反馈全零。
 */
#define SRE_POE_Q_BP_TH_L_1_REG                    (SRE_POE_BASE + 0x400D04)        /* POE模块中queue中断低水线。Memory实现。
此寄存器配置前必须先配置INIT_RAM_START初始化内部RAM。不能同时读写此寄存器，如果出现同时读写，写优先，读数据反馈全零。
 */
#define SRE_POE_MEM_TIMING_CFG_REG                 (SRE_POE_BASE + 0x401100)        /* POE模块中Memory时序调整配置寄存器。
 */
#define SRE_POE_CORE_INT_ENABLE_0_REG              (SRE_POE_BASE + 0x401104)        /* POE模块Core{0~15}中断使能寄存器。中断使能后，中断状态才能上报到CPU。 */
#define SRE_POE_CORE_INT_ENABLE_1_REG              (SRE_POE_BASE + 0x401108)        /* POE模块Core{0~15}中断使能寄存器。中断使能后，中断状态才能上报到CPU。 */
#define SRE_POE_CORE_INTS_0_REG                    (SRE_POE_BASE + 0x401204)        /* POE模块Core{0~15}中断状态寄存器，中断状态上报给Core */
#define SRE_POE_CORE_INTS_1_REG                    (SRE_POE_BASE + 0x401208)        /* POE模块Core{0~15}中断状态寄存器，中断状态上报给Core */
#define SRE_POE_COMMON_INT_ENABLE_REG              (SRE_POE_BASE + 0x401304)        /* POE模块的公共中断使能寄存器。中断使能后，中断状态才能上报CPU。 */
#define SRE_POE_COMMON_INTS_REG                    (SRE_POE_BASE + 0x401308)        /* POE模块的公共中断状态寄存器。
 */
#define SRE_POE_CORE_INTS_INFO_0_REG               (SRE_POE_BASE + 0x40130C)        /* POE模块Core{0~15}中断状态信息寄存器，记录中断对应的状态信息 */
#define SRE_POE_CORE_INTS_INFO_1_REG               (SRE_POE_BASE + 0x401310)        /* POE模块Core{0~15}中断状态信息寄存器，记录中断对应的状态信息 */
#define SRE_POE_COMMON_INTS_INFO_1_REG             (SRE_POE_BASE + 0x40140C)        /* POE模块公共中断状态信息寄存器，记录中断对应的状态信息，任务buffer指针。
 */
#define SRE_POE_COMMON_INTS_INFO_2_REG             (SRE_POE_BASE + 0x401410)        /* POE模块公共中断状态信息寄存器，记录中断对应的状态信息，任务在保序队列中的信息。
以下0x401414~41FFFC保留；以下是模块状态寄存器 */
#define SRE_POE_VCPU_INF0_0_REG                    (SRE_POE_BASE + 0x420000)        /* POE模块中逻辑CPU_{0~63}的当前绑定信息寄存器0。 */
#define SRE_POE_VCPU_INF0_1_REG                    (SRE_POE_BASE + 0x420008)        /* POE模块中逻辑CPU_{0~63}的当前绑定信息寄存器0。 */
#define SRE_POE_VCPU_INF1_0_REG                    (SRE_POE_BASE + 0x420004)        /* POE模块中逻辑CPU_{0~63}的当前绑定信息寄存器1。 */
#define SRE_POE_VCPU_INF1_1_REG                    (SRE_POE_BASE + 0x42000C)        /* POE模块中逻辑CPU_{0~63}的当前绑定信息寄存器1。 */
#define SRE_POE_GROUP_CNT_0_REG                    (SRE_POE_BASE + 0x420200)        /* GROUP_{0~31}中的任务个数（包括8个QoS队列）寄存器 */
#define SRE_POE_GROUP_CNT_1_REG                    (SRE_POE_BASE + 0x420204)        /* GROUP_{0~31}中的任务个数（包括8个QoS队列）寄存器 */
#define SRE_POE_RC_EN_CFG_REG                      (SRE_POE_BASE + 0x420280)        /* POE模块中读清寄存器的使能配置寄存器。在使能时，读“读清寄存器”时才清零。 */
#define SRE_POE_ADD_FAIL_CNT_REG                   (SRE_POE_BASE + 0x420284)        /* POE模块中在ADD操作添加失败统计寄存器。 */
#define SRE_POE_ADD_OK_CNT_REG                     (SRE_POE_BASE + 0x420288)        /* POE模块中在ADD操作添加成功统计寄存器。 */
#define SRE_POE_INFLIGHT_FREE_ST_REG               (SRE_POE_BASE + 0x42028C)        /* POE模块中in-flight中的状态寄存器。512个Entry还有多少个没使用，512个保序队列还有多少个没使用。 */
#define SRE_POE_VCPU_ADD_ST_0_REG                  (SRE_POE_BASE + 0x420290)        /* 64个逻辑CPU向POE添加任务的成功/失败状态寄存器
 */
#define SRE_POE_VCPU_ADD_ST_1_REG                  (SRE_POE_BASE + 0x420294)        /* 64个逻辑CPU向POE添加任务的成功/失败状态寄存器
 */
#define SRE_POE_INPUT_Q_GRP_EMP_REG                (SRE_POE_BASE + 0x420390)        /* POE模块中INPUT_Q模块中group的空信号。 */
#define SRE_POE_DES_FIFO_GRP_EMP_REG               (SRE_POE_BASE + 0x420394)        /* POE模块中DESCHEDULE FIFO模块中group的空信号。 */
#define SRE_POE_OV_Q_GRP_EMP_REG                   (SRE_POE_BASE + 0x420398)        /* POE模块中OV_Qbuffer中group的空信号。 */
#define SRE_POE_DDR_GRP_EMP_REG                    (SRE_POE_BASE + 0x42039C)        /* POE模块中DDR溢出空间模块中group的空信号。 */
#define SRE_POE_VCPU_INF2_0_REG                    (SRE_POE_BASE + 0x4203A0)        /* POE模块中逻辑CPU_{0~63}的当前绑定信息寄存器2，buffer地址信息。
以下0x4204A0~0x440000保留 */
#define SRE_POE_VCPU_INF2_1_REG                    (SRE_POE_BASE + 0x4203A4)        /* POE模块中逻辑CPU_{0~63}的当前绑定信息寄存器2，buffer地址信息。
以下0x4204A0~0x440000保留 */
#define SRE_POE_DEBUG_CMD_FIFO_CNT_REG             (SRE_POE_BASE + 0x440000)        /* POE模块的CMD_FIFO中中还有多少个保序命令未执行。 */
#define SRE_POE_DEBUG_SEND_TM_REG                  (SRE_POE_BASE + 0x440004)        /* POE模块的推送任务到TM的debug寄存器。 */
#define SRE_POE_DEBUG_SEND_AQM_REG                 (SRE_POE_BASE + 0x440008)        /* POE模块的推送任务到AQM的debug寄存器。 */
#define SRE_POE_DEBUG_SEND_MPE_REG                 (SRE_POE_BASE + 0x44000C)        /* POE模块的推送任务到MPE的debug寄存器。 */
#define SRE_POE_DEBUG_SEND_POE_REG                 (SRE_POE_BASE + 0x440010)        /* POE模块的推送任务到POE的debug寄存器。 */
#define SRE_POE_DEBUG_SLAVE_ERR_EN_REG             (SRE_POE_BASE + 0x440014)        /* POE模块的slave支持加速器写outstanding反馈机制的使能信号。 */
#define SRE_POE_DEBUG_SLAVE_ERR_SIG_REG            (SRE_POE_BASE + 0x440018)        /* POE模块的slave支持加速器写outstanding反馈机制的观测信号信号。 */
#define SRE_POE_DEBUG_MST_RD_EN_REG                (SRE_POE_BASE + 0x44001C)        /* POE模块的master读通道统计延时、计数的使能寄存器。共8个通道，各通道单独使能。 */
#define SRE_POE_DEBUG_MST_RD_LAY_AVG_REG           (SRE_POE_BASE + 0x440020)        /* POE模块的master读通道的平均延时寄存器 */
#define SRE_POE_DEBUG_MST_RD_LAY_MAX_REG           (SRE_POE_BASE + 0x440024)        /* POE模块的master读通道的最大延时统计寄存器 */
#define SRE_POE_DEBUG_MST_RD_LAY_CLR_REG           (SRE_POE_BASE + 0x440028)        /* POE模块的master读通道延时清零寄存器，清除DEBUG_MST_WR_LAY_AVG和DEBUG_MST_WR_LAY_MAX寄存器值 */
#define SRE_POE_DEBUG_MST_RD_ACC_CNT_REG           (SRE_POE_BASE + 0x44002C)        /* POE模块的master读通道读操作统计寄存器 */
#define SRE_POE_DEBUG_MST_RD_ACC_CLR_REG           (SRE_POE_BASE + 0x440030)        /* POE模块的master读通道操作清零寄存器，清除DEBUG_MST_WR_ACC_CNT寄存器 */
#define SRE_POE_DEBUG_MST_RD_OTD_1_REG             (SRE_POE_BASE + 0x440034)        /* POE模块的master读通道当前发出去的outstanding个数统计寄存器，低32bit */
#define SRE_POE_DEBUG_MST_RD_OTD_2_REG             (SRE_POE_BASE + 0x440038)        /* POE模块的master读通道当前发出去的outstanding个数统计寄存器，高32bit */
#define SRE_POE_DEBUG_MST_WR_EN_REG                (SRE_POE_BASE + 0x44003C)        /* POE模块的master写通道统计延时、计数的使能寄存器。共8个通道，各通道单独使能。 */
#define SRE_POE_DEBUG_MST_WR_LAY_AVG_REG           (SRE_POE_BASE + 0x440040)        /* POE模块的master写通道的平均延时寄存器 */
#define SRE_POE_DEBUG_MST_WR_LAY_MAX_REG           (SRE_POE_BASE + 0x440044)        /* POE模块的master写通道的最大延时统计寄存器 */
#define SRE_POE_DEBUG_MST_WR_LAY_CLR_REG           (SRE_POE_BASE + 0x440048)        /* POE模块的master写通道延时清零寄存器，清除DEBUG_MST_WR_LAY_AVG和DEBUG_MST_WR_LAY_MAX寄存器值 */
#define SRE_POE_DEBUG_MST_WR_ACC_CNT_REG           (SRE_POE_BASE + 0x44004C)        /* POE模块的master写通道写操作统计寄存器 */
#define SRE_POE_DEBUG_MST_WR_ACC_CLR_REG           (SRE_POE_BASE + 0x440050)        /* POE模块的master写通道操作清零寄存器，清除DEBUG_MST_WR_ACC_CNT寄存器 */
#define SRE_POE_DEBUG_MST_WR_OTD_1_REG             (SRE_POE_BASE + 0x440054)        /* POE模块的master写通道当前发出去的outstanding个数统计寄存器，低32bit */
#define SRE_POE_DEBUG_MST_WR_OTD_2_REG             (SRE_POE_BASE + 0x440058)        /* POE模块的master写通道当前发出去的outstanding个数统计寄存器，高32bit */
#define SRE_POE_DEBUG_INFLI_ST_REG                 (SRE_POE_BASE + 0x44005C)        /* POE模块的保序模块处理状态，表示保序模块中有命令处理时间超过20个POE周期 */
#define SRE_POE_DEBUG_INFLI_ST_CNT_REG             (SRE_POE_BASE + 0x440060)        /* POE模块的保序模块处理状态，表示保序模块中处理时间超过20个POE周期的保序命令个数 */
#define SRE_POE_DEBUG_ADD_CNT_REG                  (SRE_POE_BASE + 0x440064)        /* 添加任务到POE的个数 */
#define SRE_POE_DEBUG_GET_CNT_REG                  (SRE_POE_BASE + 0x440068)        /* 从POE模块读取任务的个数 */
#define SRE_POE_DEBUG_OVFL_OUT_CNT_REG             (SRE_POE_BASE + 0x44006C)        /* 溢出到DDR的outstanding个数，一个操作128bit的burst4，只能配置2/3/4 */
#define SRE_POE_DEBUG_RDBK_OUT_CNT_REG             (SRE_POE_BASE + 0x440070)        /* 从DDR或OV_FIFO回读的outstanding个数，一个操作128bit的burst4，只能配置2/3/4 */
#define SRE_POE_SUHAI_RSV_1_REG                    (SRE_POE_BASE + 0x440074)        /* 预留寄存器 */
#define SRE_POE_SUHAI_RSV_2_REG                    (SRE_POE_BASE + 0x440078)        /* 预留寄存器 */
#define SRE_POE_SUHAI_RSV_3_REG                    (SRE_POE_BASE + 0x44007C)        /* 预留寄存器 */
#define SRE_POE_SUHAI_RSV_4_REG                    (SRE_POE_BASE + 0x440080)        /* 预留寄存器 */
#define SRE_POE_SUHAI_RSV_5_REG                    (SRE_POE_BASE + 0x440084)        /* 预留寄存器 */
#define SRE_POE_SUHAI_RSV_6_REG                    (SRE_POE_BASE + 0x440088)        /* 预留寄存器 */
#define SRE_POE_SUHAI_RSV_7_REG                    (SRE_POE_BASE + 0x44008C)        /* 预留寄存器 */
#define SRE_POE_SUHAI_RSV_8_REG                    (SRE_POE_BASE + 0x440090)        /* 预留寄存器 */

/* pou 模块寄存器基地址 */
#define MC_POU_BASE                     (0x100d0000 + 0x80000000)

/******************************************************************************/
/*                      PhosphorV600 pou 寄存器定义                           */
/******************************************************************************/
#define MC_POU_GLOBAL_REG           (MC_POU_BASE + 0x0)   /* POU全局相关寄存器。 */
#define MC_POU_INT_STATUS_REG       (MC_POU_BASE + 0x8)   /* POU中断状态寄存器。 */
#define MC_POU_INT_ENA_REG          (MC_POU_BASE + 0xC)   /* POU中断使能寄存器。 */
#define MC_POU_INT_MASK_REG         (MC_POU_BASE + 0x10)  /* POU中断清除寄存器。 */
#define MC_POU_QOV_ID_REG           (MC_POU_BASE + 0x20)  /* POU输出队列溢出ID。 */
#define MC_POU_QERR_ID_REG          (MC_POU_BASE + 0x24)  /* POU总线数据访问错误输出队列寄存器。 */
#define MC_POU_ATOMIC_REG           (MC_POU_BASE + 0x30)  /* POU原子操作寄存器。 */
#define MC_POU_OQ_EN0_REG           (MC_POU_BASE + 0x40)  /* POU输出队列使能寄存器0。 */
#define MC_POU_OQ_EN1_REG           (MC_POU_BASE + 0x44)  /* POU输出队列使能寄存器1。 */
#define MC_POU_TP_DIS_STAT_REG      (MC_POU_BASE + 0x48)  /* POU 端口禁止状态寄存器*/
#define MC_POU_TP_DIS_STAT_CLR_REG  (MC_POU_BASE + 0x4C)  /* POU 端口禁止状清除寄存器*/
#define MC_POU_GMAC0_ADDR_REG       (MC_POU_BASE + 0x50)  /* POU向GMAC0写地址寄存器。 */
#define MC_POU_GMAC1_ADDR_REG       (MC_POU_BASE + 0x54)  /* POU向GMAC1写地址寄存器。 */
#define MC_POU_GMAC2_ADDR_REG       (MC_POU_BASE + 0x58)  /* POU向GMAC2写地址寄存器。 */
#define MC_POU_GMAC3_ADDR_REG       (MC_POU_BASE + 0x5C)  /* POU向GMAC3写地址寄存器。 */
#define MC_POU_GMAC4_ADDR_REG       (MC_POU_BASE + 0x60)  /* POU向GMAC4写地址寄存器。 */
#define MC_POU_GMAC5_ADDR_REG       (MC_POU_BASE + 0x64)  /* POU向GMAC5写地址寄存器。 */
#define MC_POU_GMAC6_ADDR_REG       (MC_POU_BASE + 0x68)  /* POU向GMAC6写地址寄存器。 */
#define MC_POU_GMAC7_ADDR_REG       (MC_POU_BASE + 0x6C)  /* POU向GMAC7写地址寄存器。 */
#define MC_POU_TP_SHAPING_EN_REG    (MC_POU_BASE + 0x80)  /* POU物理端口流量整形使能寄存器。 */
#define MC_POU_DEBUG0_REG           (MC_POU_BASE + 0x90)  /* POU调试寄存器0。 */
#define MC_POU_DEBUG1_REG           (MC_POU_BASE + 0x94)  /* POU调试寄存器1。 */
#define MC_POU_DEBUG2_REG           (MC_POU_BASE + 0x98)  /* POU调试寄存器2。 */
#define MC_POU_DEBUG3_REG           (MC_POU_BASE + 0x9C)  /* POU调试寄存器3。 */
#define MC_POU_TP_ST_REG            (MC_POU_BASE + 0xA0)  /* POU调试寄存器3。 */
#define MC_POU_TP_DEEP_0_REG        (MC_POU_BASE + 0xB0)  /* POU调试寄存器3。 */
#define MC_POU_TP_DEEP_1_REG        (MC_POU_BASE + 0xB8)  /* POU调试寄存器3。 */
#define MC_POU_TP_DEEP_2_REG        (MC_POU_BASE + 0xC0)  /* POU调试寄存器3。 */
#define MC_POU_TP_DEEP_3_REG        (MC_POU_BASE + 0xC8)  /* POU调试寄存器3。 */
#define MC_POU_TP_DEEP_4_REG        (MC_POU_BASE + 0xD0)  /* POU调试寄存器3。 */
#define MC_POU_TP_DEEP_5_REG        (MC_POU_BASE + 0xD8)  /* POU调试寄存器3。 */
#define MC_POU_TP_DEEP_6_REG        (MC_POU_BASE + 0xE0)  /* POU调试寄存器3。 */
#define MC_POU_TP_DEEP_7_REG        (MC_POU_BASE + 0xE8)  /* POU调试寄存器3。 */
#define MC_POU_TP_CNT_0_REG         (MC_POU_BASE + 0xB4)  /* POU调试寄存器3。 */
#define MC_POU_TP_CNT_1_REG         (MC_POU_BASE + 0xBC)  /* POU调试寄存器3。 */
#define MC_POU_TP_CNT_2_REG         (MC_POU_BASE + 0xC4)  /* POU调试寄存器3。 */
#define MC_POU_TP_CNT_3_REG         (MC_POU_BASE + 0xCC)  /* POU调试寄存器3。 */
#define MC_POU_TP_CNT_4_REG         (MC_POU_BASE + 0xD4)  /* POU调试寄存器3。 */
#define MC_POU_TP_CNT_5_REG         (MC_POU_BASE + 0xDC)  /* POU调试寄存器3。 */
#define MC_POU_TP_CNT_6_REG         (MC_POU_BASE + 0xE4)  /* POU调试寄存器3。 */
#define MC_POU_TP_CNT_7_REG         (MC_POU_BASE + 0xEC)  /* POU调试寄存器3。 */
#define MC_POU_TP_RATE0_0_REG  (MC_POU_BASE + 0x100)  /* POU物理端口的速度配置寄存器0。 */
#define MC_POU_TP_RATE0_1_REG  (MC_POU_BASE + 0x110)  /* POU物理端口的速度配置寄存器0。 */
#define MC_POU_TP_RATE0_2_REG  (MC_POU_BASE + 0x120)  /* POU物理端口的速度配置寄存器0。 */
#define MC_POU_TP_RATE0_3_REG  (MC_POU_BASE + 0x130)  /* POU物理端口的速度配置寄存器0。 */
#define MC_POU_TP_RATE0_4_REG  (MC_POU_BASE + 0x140)  /* POU物理端口的速度配置寄存器0。 */
#define MC_POU_TP_RATE0_5_REG  (MC_POU_BASE + 0x150)  /* POU物理端口的速度配置寄存器0。 */
#define MC_POU_TP_RATE0_6_REG  (MC_POU_BASE + 0x160)  /* POU物理端口的速度配置寄存器0。 */
#define MC_POU_TP_RATE0_7_REG  (MC_POU_BASE + 0x170)  /* POU物理端口的速度配置寄存器0。 */
#define MC_POU_TP_RATE1_0_REG  (MC_POU_BASE + 0x104)  /* POU物理端口的速度配置寄存器1。 */
#define MC_POU_TP_RATE1_1_REG  (MC_POU_BASE + 0x114)  /* POU物理端口的速度配置寄存器1。 */
#define MC_POU_TP_RATE1_2_REG  (MC_POU_BASE + 0x124)  /* POU物理端口的速度配置寄存器1。 */
#define MC_POU_TP_RATE1_3_REG  (MC_POU_BASE + 0x134)  /* POU物理端口的速度配置寄存器1。 */
#define MC_POU_TP_RATE1_4_REG  (MC_POU_BASE + 0x144)  /* POU物理端口的速度配置寄存器1。 */
#define MC_POU_TP_RATE1_5_REG  (MC_POU_BASE + 0x154)  /* POU物理端口的速度配置寄存器1。 */
#define MC_POU_TP_RATE1_6_REG  (MC_POU_BASE + 0x164)  /* POU物理端口的速度配置寄存器1。 */
#define MC_POU_TP_RATE1_7_REG  (MC_POU_BASE + 0x174)  /* POU物理端口的速度配置寄存器1。 */
#define MC_POU_TP_LIMIT_0_REG  (MC_POU_BASE + 0x108)  /* POU物理端口的速度限制寄存器1。 */
#define MC_POU_TP_LIMIT_1_REG  (MC_POU_BASE + 0x118)  /* POU物理端口的速度限制寄存器1。 */
#define MC_POU_TP_LIMIT_2_REG  (MC_POU_BASE + 0x128)  /* POU物理端口的速度限制寄存器1。 */
#define MC_POU_TP_LIMIT_3_REG  (MC_POU_BASE + 0x138)  /* POU物理端口的速度限制寄存器1。 */
#define MC_POU_TP_LIMIT_4_REG  (MC_POU_BASE + 0x148)  /* POU物理端口的速度限制寄存器1。 */
#define MC_POU_TP_LIMIT_5_REG  (MC_POU_BASE + 0x158)  /* POU物理端口的速度限制寄存器1。 */
#define MC_POU_TP_LIMIT_6_REG  (MC_POU_BASE + 0x168)  /* POU物理端口的速度限制寄存器1。 */
#define MC_POU_TP_LIMIT_7_REG  (MC_POU_BASE + 0x178)  /* POU物理端口的速度限制寄存器1。 */
#define MC_POU_OQ_SET_0_REG  (MC_POU_BASE + 0x200)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_1_REG  (MC_POU_BASE + 0x204)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_2_REG  (MC_POU_BASE + 0x208)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_3_REG  (MC_POU_BASE + 0x20C)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_4_REG  (MC_POU_BASE + 0x210)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_5_REG  (MC_POU_BASE + 0x214)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_6_REG  (MC_POU_BASE + 0x218)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_7_REG  (MC_POU_BASE + 0x21C)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_8_REG  (MC_POU_BASE + 0x220)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_9_REG  (MC_POU_BASE + 0x224)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_10_REG  (MC_POU_BASE + 0x228)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_11_REG  (MC_POU_BASE + 0x22C)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_12_REG  (MC_POU_BASE + 0x230)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_13_REG  (MC_POU_BASE + 0x234)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_14_REG  (MC_POU_BASE + 0x238)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_15_REG  (MC_POU_BASE + 0x23C)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_16_REG  (MC_POU_BASE + 0x240)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_17_REG  (MC_POU_BASE + 0x244)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_18_REG  (MC_POU_BASE + 0x248)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_19_REG  (MC_POU_BASE + 0x24C)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_20_REG  (MC_POU_BASE + 0x250)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_21_REG  (MC_POU_BASE + 0x254)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_22_REG  (MC_POU_BASE + 0x258)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_23_REG  (MC_POU_BASE + 0x25C)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_24_REG  (MC_POU_BASE + 0x260)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_25_REG  (MC_POU_BASE + 0x264)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_26_REG  (MC_POU_BASE + 0x268)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_27_REG  (MC_POU_BASE + 0x26C)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_28_REG  (MC_POU_BASE + 0x270)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_29_REG  (MC_POU_BASE + 0x274)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_30_REG  (MC_POU_BASE + 0x278)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_31_REG  (MC_POU_BASE + 0x27C)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_32_REG  (MC_POU_BASE + 0x280)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_33_REG  (MC_POU_BASE + 0x284)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_34_REG  (MC_POU_BASE + 0x288)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_35_REG  (MC_POU_BASE + 0x28C)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_36_REG  (MC_POU_BASE + 0x290)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_37_REG  (MC_POU_BASE + 0x294)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_38_REG  (MC_POU_BASE + 0x298)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_39_REG  (MC_POU_BASE + 0x29C)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_40_REG  (MC_POU_BASE + 0x2A0)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_41_REG  (MC_POU_BASE + 0x2A4)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_42_REG  (MC_POU_BASE + 0x2A8)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_43_REG  (MC_POU_BASE + 0x2AC)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_44_REG  (MC_POU_BASE + 0x2B0)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_45_REG  (MC_POU_BASE + 0x2B4)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_46_REG  (MC_POU_BASE + 0x2B8)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_47_REG  (MC_POU_BASE + 0x2BC)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_48_REG  (MC_POU_BASE + 0x2C0)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_49_REG  (MC_POU_BASE + 0x2C4)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_50_REG  (MC_POU_BASE + 0x2C8)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_51_REG  (MC_POU_BASE + 0x2CC)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_52_REG  (MC_POU_BASE + 0x2D0)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_53_REG  (MC_POU_BASE + 0x2D4)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_54_REG  (MC_POU_BASE + 0x2D8)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_55_REG  (MC_POU_BASE + 0x2DC)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_56_REG  (MC_POU_BASE + 0x2E0)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_57_REG  (MC_POU_BASE + 0x2E4)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_58_REG  (MC_POU_BASE + 0x2E8)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_59_REG  (MC_POU_BASE + 0x2EC)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_60_REG  (MC_POU_BASE + 0x2F0)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_61_REG  (MC_POU_BASE + 0x2F4)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_62_REG  (MC_POU_BASE + 0x2F8)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_SET_63_REG  (MC_POU_BASE + 0x2FC)  /* POU输出队列基本设置寄存器。 */
#define MC_POU_OQ_BASE_0_REG  (MC_POU_BASE + 0x300)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_1_REG  (MC_POU_BASE + 0x304)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_2_REG  (MC_POU_BASE + 0x308)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_3_REG  (MC_POU_BASE + 0x30C)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_4_REG  (MC_POU_BASE + 0x310)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_5_REG  (MC_POU_BASE + 0x314)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_6_REG  (MC_POU_BASE + 0x318)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_7_REG  (MC_POU_BASE + 0x31C)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_8_REG  (MC_POU_BASE + 0x320)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_9_REG  (MC_POU_BASE + 0x324)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_10_REG  (MC_POU_BASE + 0x328)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_11_REG  (MC_POU_BASE + 0x32C)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_12_REG  (MC_POU_BASE + 0x330)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_13_REG  (MC_POU_BASE + 0x334)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_14_REG  (MC_POU_BASE + 0x338)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_15_REG  (MC_POU_BASE + 0x33C)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_16_REG  (MC_POU_BASE + 0x340)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_17_REG  (MC_POU_BASE + 0x344)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_18_REG  (MC_POU_BASE + 0x348)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_19_REG  (MC_POU_BASE + 0x34C)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_20_REG  (MC_POU_BASE + 0x350)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_21_REG  (MC_POU_BASE + 0x354)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_22_REG  (MC_POU_BASE + 0x358)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_23_REG  (MC_POU_BASE + 0x35C)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_24_REG  (MC_POU_BASE + 0x360)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_25_REG  (MC_POU_BASE + 0x364)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_26_REG  (MC_POU_BASE + 0x368)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_27_REG  (MC_POU_BASE + 0x36C)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_28_REG  (MC_POU_BASE + 0x370)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_29_REG  (MC_POU_BASE + 0x374)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_30_REG  (MC_POU_BASE + 0x378)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_31_REG  (MC_POU_BASE + 0x37C)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_32_REG  (MC_POU_BASE + 0x380)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_33_REG  (MC_POU_BASE + 0x384)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_34_REG  (MC_POU_BASE + 0x388)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_35_REG  (MC_POU_BASE + 0x38C)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_36_REG  (MC_POU_BASE + 0x390)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_37_REG  (MC_POU_BASE + 0x394)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_38_REG  (MC_POU_BASE + 0x398)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_39_REG  (MC_POU_BASE + 0x39C)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_40_REG  (MC_POU_BASE + 0x3A0)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_41_REG  (MC_POU_BASE + 0x3A4)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_42_REG  (MC_POU_BASE + 0x3A8)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_43_REG  (MC_POU_BASE + 0x3AC)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_44_REG  (MC_POU_BASE + 0x3B0)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_45_REG  (MC_POU_BASE + 0x3B4)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_46_REG  (MC_POU_BASE + 0x3B8)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_47_REG  (MC_POU_BASE + 0x3BC)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_48_REG  (MC_POU_BASE + 0x3C0)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_49_REG  (MC_POU_BASE + 0x3C4)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_50_REG  (MC_POU_BASE + 0x3C8)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_51_REG  (MC_POU_BASE + 0x3CC)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_52_REG  (MC_POU_BASE + 0x3D0)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_53_REG  (MC_POU_BASE + 0x3D4)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_54_REG  (MC_POU_BASE + 0x3D8)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_55_REG  (MC_POU_BASE + 0x3DC)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_56_REG  (MC_POU_BASE + 0x3E0)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_57_REG  (MC_POU_BASE + 0x3E4)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_58_REG  (MC_POU_BASE + 0x3E8)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_59_REG  (MC_POU_BASE + 0x3EC)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_60_REG  (MC_POU_BASE + 0x3F0)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_61_REG  (MC_POU_BASE + 0x3F4)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_62_REG  (MC_POU_BASE + 0x3F8)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_BASE_63_REG  (MC_POU_BASE + 0x3FC)  /* POU输出队列地址寄存器。 */
#define MC_POU_OQ_DEEP_0_REG  (MC_POU_BASE + 0x400)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_1_REG  (MC_POU_BASE + 0x404)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_2_REG  (MC_POU_BASE + 0x408)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_3_REG  (MC_POU_BASE + 0x40C)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_4_REG  (MC_POU_BASE + 0x410)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_5_REG  (MC_POU_BASE + 0x414)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_6_REG  (MC_POU_BASE + 0x418)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_7_REG  (MC_POU_BASE + 0x41C)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_8_REG  (MC_POU_BASE + 0x420)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_9_REG  (MC_POU_BASE + 0x424)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_10_REG  (MC_POU_BASE + 0x428)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_11_REG  (MC_POU_BASE + 0x42C)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_12_REG  (MC_POU_BASE + 0x430)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_13_REG  (MC_POU_BASE + 0x434)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_14_REG  (MC_POU_BASE + 0x438)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_15_REG  (MC_POU_BASE + 0x43C)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_16_REG  (MC_POU_BASE + 0x440)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_17_REG  (MC_POU_BASE + 0x444)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_18_REG  (MC_POU_BASE + 0x448)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_19_REG  (MC_POU_BASE + 0x44C)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_20_REG  (MC_POU_BASE + 0x450)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_21_REG  (MC_POU_BASE + 0x454)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_22_REG  (MC_POU_BASE + 0x458)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_23_REG  (MC_POU_BASE + 0x45C)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_24_REG  (MC_POU_BASE + 0x460)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_25_REG  (MC_POU_BASE + 0x464)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_26_REG  (MC_POU_BASE + 0x468)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_27_REG  (MC_POU_BASE + 0x46C)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_28_REG  (MC_POU_BASE + 0x470)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_29_REG  (MC_POU_BASE + 0x474)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_30_REG  (MC_POU_BASE + 0x478)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_31_REG  (MC_POU_BASE + 0x47C)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_32_REG  (MC_POU_BASE + 0x480)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_33_REG  (MC_POU_BASE + 0x484)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_34_REG  (MC_POU_BASE + 0x488)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_35_REG  (MC_POU_BASE + 0x48C)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_36_REG  (MC_POU_BASE + 0x490)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_37_REG  (MC_POU_BASE + 0x494)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_38_REG  (MC_POU_BASE + 0x498)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_39_REG  (MC_POU_BASE + 0x49C)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_40_REG  (MC_POU_BASE + 0x4A0)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_41_REG  (MC_POU_BASE + 0x4A4)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_42_REG  (MC_POU_BASE + 0x4A8)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_43_REG  (MC_POU_BASE + 0x4AC)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_44_REG  (MC_POU_BASE + 0x4B0)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_45_REG  (MC_POU_BASE + 0x4B4)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_46_REG  (MC_POU_BASE + 0x4B8)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_47_REG  (MC_POU_BASE + 0x4BC)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_48_REG  (MC_POU_BASE + 0x4C0)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_49_REG  (MC_POU_BASE + 0x4C4)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_50_REG  (MC_POU_BASE + 0x4C8)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_51_REG  (MC_POU_BASE + 0x4CC)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_52_REG  (MC_POU_BASE + 0x4D0)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_53_REG  (MC_POU_BASE + 0x4D4)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_54_REG  (MC_POU_BASE + 0x4D8)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_55_REG  (MC_POU_BASE + 0x4DC)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_56_REG  (MC_POU_BASE + 0x4E0)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_57_REG  (MC_POU_BASE + 0x4E4)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_58_REG  (MC_POU_BASE + 0x4E8)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_59_REG  (MC_POU_BASE + 0x4EC)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_60_REG  (MC_POU_BASE + 0x4F0)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_61_REG  (MC_POU_BASE + 0x4F4)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_62_REG  (MC_POU_BASE + 0x4F8)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_DEEP_63_REG  (MC_POU_BASE + 0x4FC)  /* POU输出队列DEEP设置寄存器。 */
#define MC_POU_OQ_CNT_0_REG  (MC_POU_BASE + 0x500)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_1_REG  (MC_POU_BASE + 0x510)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_2_REG  (MC_POU_BASE + 0x520)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_3_REG  (MC_POU_BASE + 0x530)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_4_REG  (MC_POU_BASE + 0x540)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_5_REG  (MC_POU_BASE + 0x550)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_6_REG  (MC_POU_BASE + 0x560)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_7_REG  (MC_POU_BASE + 0x570)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_8_REG  (MC_POU_BASE + 0x580)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_9_REG  (MC_POU_BASE + 0x590)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_10_REG  (MC_POU_BASE + 0x5A0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_11_REG  (MC_POU_BASE + 0x5B0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_12_REG  (MC_POU_BASE + 0x5C0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_13_REG  (MC_POU_BASE + 0x5D0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_14_REG  (MC_POU_BASE + 0x5E0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_15_REG  (MC_POU_BASE + 0x5F0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_16_REG  (MC_POU_BASE + 0x600)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_17_REG  (MC_POU_BASE + 0x610)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_18_REG  (MC_POU_BASE + 0x620)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_19_REG  (MC_POU_BASE + 0x630)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_20_REG  (MC_POU_BASE + 0x640)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_21_REG  (MC_POU_BASE + 0x650)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_22_REG  (MC_POU_BASE + 0x660)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_23_REG  (MC_POU_BASE + 0x670)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_24_REG  (MC_POU_BASE + 0x680)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_25_REG  (MC_POU_BASE + 0x690)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_26_REG  (MC_POU_BASE + 0x6A0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_27_REG  (MC_POU_BASE + 0x6B0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_28_REG  (MC_POU_BASE + 0x6C0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_29_REG  (MC_POU_BASE + 0x6D0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_30_REG  (MC_POU_BASE + 0x6E0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_31_REG  (MC_POU_BASE + 0x6F0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_32_REG  (MC_POU_BASE + 0x700)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_33_REG  (MC_POU_BASE + 0x710)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_34_REG  (MC_POU_BASE + 0x720)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_35_REG  (MC_POU_BASE + 0x730)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_36_REG  (MC_POU_BASE + 0x740)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_37_REG  (MC_POU_BASE + 0x750)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_38_REG  (MC_POU_BASE + 0x760)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_39_REG  (MC_POU_BASE + 0x770)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_40_REG  (MC_POU_BASE + 0x780)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_41_REG  (MC_POU_BASE + 0x790)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_42_REG  (MC_POU_BASE + 0x7A0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_43_REG  (MC_POU_BASE + 0x7B0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_44_REG  (MC_POU_BASE + 0x7C0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_45_REG  (MC_POU_BASE + 0x7D0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_46_REG  (MC_POU_BASE + 0x7E0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_47_REG  (MC_POU_BASE + 0x7F0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_48_REG  (MC_POU_BASE + 0x800)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_49_REG  (MC_POU_BASE + 0x810)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_50_REG  (MC_POU_BASE + 0x820)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_51_REG  (MC_POU_BASE + 0x830)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_52_REG  (MC_POU_BASE + 0x840)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_53_REG  (MC_POU_BASE + 0x850)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_54_REG  (MC_POU_BASE + 0x860)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_55_REG  (MC_POU_BASE + 0x870)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_56_REG  (MC_POU_BASE + 0x880)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_57_REG  (MC_POU_BASE + 0x890)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_58_REG  (MC_POU_BASE + 0x8A0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_59_REG  (MC_POU_BASE + 0x8B0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_60_REG  (MC_POU_BASE + 0x8C0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_61_REG  (MC_POU_BASE + 0x8D0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_62_REG  (MC_POU_BASE + 0x8E0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT_63_REG  (MC_POU_BASE + 0x8F0)  /* POU输出队列COUNTER设置寄存器。 */
#define MC_POU_OQ_CNT0_0_REG  (MC_POU_BASE + 0x504)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_1_REG  (MC_POU_BASE + 0x514)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_2_REG  (MC_POU_BASE + 0x524)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_3_REG  (MC_POU_BASE + 0x534)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_4_REG  (MC_POU_BASE + 0x544)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_5_REG  (MC_POU_BASE + 0x554)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_6_REG  (MC_POU_BASE + 0x564)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_7_REG  (MC_POU_BASE + 0x574)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_8_REG  (MC_POU_BASE + 0x584)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_9_REG  (MC_POU_BASE + 0x594)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_10_REG  (MC_POU_BASE + 0x5A4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_11_REG  (MC_POU_BASE + 0x5B4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_12_REG  (MC_POU_BASE + 0x5C4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_13_REG  (MC_POU_BASE + 0x5D4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_14_REG  (MC_POU_BASE + 0x5E4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_15_REG  (MC_POU_BASE + 0x5F4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_16_REG  (MC_POU_BASE + 0x604)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_17_REG  (MC_POU_BASE + 0x614)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_18_REG  (MC_POU_BASE + 0x624)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_19_REG  (MC_POU_BASE + 0x634)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_20_REG  (MC_POU_BASE + 0x644)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_21_REG  (MC_POU_BASE + 0x654)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_22_REG  (MC_POU_BASE + 0x664)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_23_REG  (MC_POU_BASE + 0x674)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_24_REG  (MC_POU_BASE + 0x684)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_25_REG  (MC_POU_BASE + 0x694)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_26_REG  (MC_POU_BASE + 0x6A4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_27_REG  (MC_POU_BASE + 0x6B4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_28_REG  (MC_POU_BASE + 0x6C4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_29_REG  (MC_POU_BASE + 0x6D4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_30_REG  (MC_POU_BASE + 0x6E4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_31_REG  (MC_POU_BASE + 0x6F4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_32_REG  (MC_POU_BASE + 0x704)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_33_REG  (MC_POU_BASE + 0x714)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_34_REG  (MC_POU_BASE + 0x724)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_35_REG  (MC_POU_BASE + 0x734)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_36_REG  (MC_POU_BASE + 0x744)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_37_REG  (MC_POU_BASE + 0x754)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_38_REG  (MC_POU_BASE + 0x764)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_39_REG  (MC_POU_BASE + 0x774)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_40_REG  (MC_POU_BASE + 0x784)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_41_REG  (MC_POU_BASE + 0x794)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_42_REG  (MC_POU_BASE + 0x7A4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_43_REG  (MC_POU_BASE + 0x7B4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_44_REG  (MC_POU_BASE + 0x7C4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_45_REG  (MC_POU_BASE + 0x7D4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_46_REG  (MC_POU_BASE + 0x7E4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_47_REG  (MC_POU_BASE + 0x7F4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_48_REG  (MC_POU_BASE + 0x804)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_49_REG  (MC_POU_BASE + 0x814)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_50_REG  (MC_POU_BASE + 0x824)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_51_REG  (MC_POU_BASE + 0x834)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_52_REG  (MC_POU_BASE + 0x844)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_53_REG  (MC_POU_BASE + 0x854)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_54_REG  (MC_POU_BASE + 0x864)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_55_REG  (MC_POU_BASE + 0x874)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_56_REG  (MC_POU_BASE + 0x884)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_57_REG  (MC_POU_BASE + 0x894)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_58_REG  (MC_POU_BASE + 0x8A4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_59_REG  (MC_POU_BASE + 0x8B4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_60_REG  (MC_POU_BASE + 0x8C4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_61_REG  (MC_POU_BASE + 0x8D4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_62_REG  (MC_POU_BASE + 0x8E4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT0_63_REG  (MC_POU_BASE + 0x8F4)  /* POU输出队列的发送数据包个数寄存器0。 */
#define MC_POU_OQ_CNT1_0_REG  (MC_POU_BASE + 0x508)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_1_REG  (MC_POU_BASE + 0x518)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_2_REG  (MC_POU_BASE + 0x528)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_3_REG  (MC_POU_BASE + 0x538)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_4_REG  (MC_POU_BASE + 0x548)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_5_REG  (MC_POU_BASE + 0x558)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_6_REG  (MC_POU_BASE + 0x568)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_7_REG  (MC_POU_BASE + 0x578)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_8_REG  (MC_POU_BASE + 0x588)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_9_REG  (MC_POU_BASE + 0x598)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_10_REG  (MC_POU_BASE + 0x5A8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_11_REG  (MC_POU_BASE + 0x5B8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_12_REG  (MC_POU_BASE + 0x5C8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_13_REG  (MC_POU_BASE + 0x5D8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_14_REG  (MC_POU_BASE + 0x5E8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_15_REG  (MC_POU_BASE + 0x5F8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_16_REG  (MC_POU_BASE + 0x608)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_17_REG  (MC_POU_BASE + 0x618)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_18_REG  (MC_POU_BASE + 0x628)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_19_REG  (MC_POU_BASE + 0x638)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_20_REG  (MC_POU_BASE + 0x648)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_21_REG  (MC_POU_BASE + 0x658)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_22_REG  (MC_POU_BASE + 0x668)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_23_REG  (MC_POU_BASE + 0x678)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_24_REG  (MC_POU_BASE + 0x688)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_25_REG  (MC_POU_BASE + 0x698)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_26_REG  (MC_POU_BASE + 0x6A8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_27_REG  (MC_POU_BASE + 0x6B8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_28_REG  (MC_POU_BASE + 0x6C8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_29_REG  (MC_POU_BASE + 0x6D8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_30_REG  (MC_POU_BASE + 0x6E8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_31_REG  (MC_POU_BASE + 0x6F8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_32_REG  (MC_POU_BASE + 0x708)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_33_REG  (MC_POU_BASE + 0x718)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_34_REG  (MC_POU_BASE + 0x728)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_35_REG  (MC_POU_BASE + 0x738)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_36_REG  (MC_POU_BASE + 0x748)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_37_REG  (MC_POU_BASE + 0x758)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_38_REG  (MC_POU_BASE + 0x768)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_39_REG  (MC_POU_BASE + 0x778)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_40_REG  (MC_POU_BASE + 0x788)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_41_REG  (MC_POU_BASE + 0x798)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_42_REG  (MC_POU_BASE + 0x7A8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_43_REG  (MC_POU_BASE + 0x7B8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_44_REG  (MC_POU_BASE + 0x7C8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_45_REG  (MC_POU_BASE + 0x7D8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_46_REG  (MC_POU_BASE + 0x7E8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_47_REG  (MC_POU_BASE + 0x7F8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_48_REG  (MC_POU_BASE + 0x808)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_49_REG  (MC_POU_BASE + 0x818)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_50_REG  (MC_POU_BASE + 0x828)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_51_REG  (MC_POU_BASE + 0x838)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_52_REG  (MC_POU_BASE + 0x848)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_53_REG  (MC_POU_BASE + 0x858)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_54_REG  (MC_POU_BASE + 0x868)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_55_REG  (MC_POU_BASE + 0x878)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_56_REG  (MC_POU_BASE + 0x888)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_57_REG  (MC_POU_BASE + 0x898)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_58_REG  (MC_POU_BASE + 0x8A8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_59_REG  (MC_POU_BASE + 0x8B8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_60_REG  (MC_POU_BASE + 0x8C8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_61_REG  (MC_POU_BASE + 0x8D8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_62_REG  (MC_POU_BASE + 0x8E8)  /* POU输出队列的发送数据包个数寄存器1。 */
#define MC_POU_OQ_CNT1_63_REG  (MC_POU_BASE + 0x8F8)  /* POU输出队列的发送数据包个数寄存器1。 */

/* CRC 模块寄存器基地址 */
#define SRE_CRC_BASE          				(SRE_SEC_REG_BASE + 0x50000)

/******************************************************************************/
/*                      P650 CRC 寄存器定义                                 */
/******************************************************************************/
#define SRE_CRC_VERSION_REG                (0x0)         /* CRC 版本寄存器。 */
#define SRE_CRC_CFG_REG                    (0x4)         /* CRC全局配置寄存器。 */
#define SRE_CRC_INT_EN_REG                 (0x8)         /* 中断使能寄存器 */
#define SRE_CRC_INT_STS_REG                (0xC)         /* 中断状态寄存器 */
#define SRE_CRC_PATTERN0_REG               (0x10)        /* CRC多项式向量配置0 */
#define SRE_CRC_PATTERN1_REG               (0x14)        /* CRC多项式向量配置1 */
#define SRE_CRC_PATTERN2_REG               (0x18)        /* CRC多项式向量配置2 */
#define SRE_CRC_PATTERN3_REG               (0x1C)        /* CRC多项式向量配置3 */
#define SRE_CRC_PATTERN4_REG               (0x20)        /* CRC多项式向量配置4 */
#define SRE_CRC_PATTERN5_REG               (0x24)        /* CRC多项式向量配置5 */
#define SRE_CRC_PATTERN6_REG               (0x28)        /* CRC多项式向量配置6 */
#define SRE_CRC_PATTERN7_REG               (0x2C)        /* CRC多项式向量配置7 */
#define SRE_CRC_INIT_VAL0_REG              (0x30)        /* CRC计算的初始值配置寄存器0 */
#define SRE_CRC_INIT_VAL1_REG              (0x34)        /* CRC计算的初始值配置寄存器1 */
#define SRE_CRC_INIT_VAL2_REG              (0x38)        /* CRC计算的初始值配置寄存器2 */
#define SRE_CRC_INIT_VAL3_REG              (0x3C)        /* CRC计算的初始值配置寄存器3 */
#define SRE_CRC_INIT_VAL4_REG              (0x40)        /* CRC计算的初始值配置寄存器4 */
#define SRE_CRC_INIT_VAL5_REG              (0x44)        /* CRC计算的初始值配置寄存器5 */
#define SRE_CRC_INIT_VAL6_REG              (0x48)        /* CRC计算的初始值配置寄存器6 */
#define SRE_CRC_INIT_VAL7_REG              (0x4C)        /* CRC计算的初始值配置寄存器7 */
#define SRE_CRC_START_ADDR0_REG            (0x50)        /* CRC计算的数据起始地址寄存器0 */
#define SRE_CRC_START_ADDR1_REG            (0x54)        /* CRC计算的数据起始地址寄存器1 */
#define SRE_CRC_START_ADDR2_REG            (0x58)        /* CRC计算的数据起始地址寄存器2 */
#define SRE_CRC_START_ADDR3_REG            (0x5C)        /* CRC计算的数据起始地址寄存器3 */
#define SRE_CRC_START_ADDR4_REG            (0x60)        /* CRC计算的数据起始地址寄存器4 */
#define SRE_CRC_START_ADDR5_REG            (0x64)        /* CRC计算的数据起始地址寄存器5 */
#define SRE_CRC_START_ADDR6_REG            (0x68)        /* CRC计算的数据起始地址寄存器6 */
#define SRE_CRC_START_ADDR7_REG            (0x6C)        /* CRC计算的数据起始地址寄存器7 */
#define SRE_CRC_START_LEN0_REG             (0x70)        /* CRC计算的数据长度寄存器0 */
#define SRE_CRC_START_LEN1_REG             (0x74)        /* CRC计算的数据长度寄存器1 */
#define SRE_CRC_START_LEN2_REG             (0x78)        /* CRC计算的数据长度寄存器2 */
#define SRE_CRC_START_LEN3_REG             (0x7C)        /* CRC计算的数据长度寄存器3 */
#define SRE_CRC_START_LEN4_REG             (0x80)        /* CRC计算的数据长度寄存器4 */
#define SRE_CRC_START_LEN5_REG             (0x84)        /* CRC计算的数据长度寄存器5 */
#define SRE_CRC_START_LEN6_REG             (0x88)        /* CRC计算的数据长度寄存器6 */
#define SRE_CRC_START_LEN7_REG             (0x8C)        /* CRC计算的数据长度寄存器7 */
#define SRE_CRC_RESULT0_REG                (0x90)        /* CRC计算结果寄存器0 */
#define SRE_CRC_RESULT1_REG                (0x94)        /* CRC计算结果寄存器1 */
#define SRE_CRC_RESULT2_REG                (0x98)        /* CRC计算结果寄存器2 */
#define SRE_CRC_RESULT3_REG                (0x9C)        /* CRC计算结果寄存器3 */
#define SRE_CRC_RESULT4_REG                (0xA0)        /* CRC计算结果寄存器4 */
#define SRE_CRC_RESULT5_REG                (0xA4)        /* CRC计算结果寄存器5 */
#define SRE_CRC_RESULT6_REG                (0xA8)        /* CRC计算结果寄存器6 */
#define SRE_CRC_RESULT7_REG                (0xAC)        /* CRC计算结果寄存器7 */
#define SRE_CRC_RES_LEN0_REG               (0xB0)        /* CRC该次计算总共计算长度统计寄存器0 */
#define SRE_CRC_RES_LEN1_REG               (0xB4)        /* CRC该次计算总共计算长度统计寄存器1 */
#define SRE_CRC_RES_LEN2_REG               (0xB8)        /* CRC该次计算总共计算长度统计寄存器2 */
#define SRE_CRC_RES_LEN3_REG               (0xBC)        /* CRC该次计算总共计算长度统计寄存器3 */
#define SRE_CRC_RES_LEN4_REG               (0xC0)        /* CRC该次计算总共计算长度统计寄存器4 */
#define SRE_CRC_RES_LEN5_REG               (0xC4)        /* CRC该次计算总共计算长度统计寄存器5 */
#define SRE_CRC_RES_LEN6_REG               (0xC8)        /* CRC该次计算总共计算长度统计寄存器6 */
#define SRE_CRC_RES_LEN7_REG               (0xCC)        /* CRC该次计算总共计算长度统计寄存器7 */
#define SRE_CRC_START_REG                  (0xD0)        /* CRC启动寄存器 */
#define SRE_CRC_STS_REG                    (0xD4)        /* CRC状态寄存器 */
#define SRE_CRC_DATA_MODE0_REG             (0xD8)        /* CRC数据接口模式寄存器0 */
#define SRE_CRC_DATA_MODE1_REG             (0xDC)        /* CRC数据接口模式寄存器1 */
#define SRE_CRC_DATA_MODE2_REG             (0xE0)        /* CRC数据接口模式寄存器2 */
#define SRE_CRC_DATA_MODE3_REG             (0xE4)        /* CRC数据接口模式寄存器3 */
#define SRE_CRC_DATA_MODE4_REG             (0xE8)        /* CRC数据接口模式寄存器4 */
#define SRE_CRC_DATA_MODE5_REG             (0xEC)        /* CRC数据接口模式寄存器5 */
#define SRE_CRC_DATA_MODE6_REG             (0xF0)        /* CRC数据接口模式寄存器6 */
#define SRE_CRC_DATA_MODE7_REG             (0xF4)        /* CRC数据接口模式寄存器7 */
#define SRE_CRC_AHBM_ADDRH_CH0_REG         (0x100)       /* CRC AHB Master接口channel0高2位地址 */
#define SRE_CRC_AHBM_ADDRH_CH1_REG         (0x104)       /* CRC AHB Master接口channel1高2位地址 */
#define SRE_CRC_AHBM_ADDRH_CH2_REG         (0x108)       /* CRC AHB Master接口channel2高2位地址 */
#define SRE_CRC_AHBM_ADDRH_CH3_REG         (0x10C)       /* CRC AHB Master接口channel3高2位地址 */
#define SRE_CRC_AHBM_ADDRH_CH4_REG         (0x110)       /* CRC AHB Master接口channel4高2位地址 */
#define SRE_CRC_AHBM_ADDRH_CH5_REG         (0x114)       /* CRC AHB Master接口channel5高2位地址 */
#define SRE_CRC_AHBM_ADDRH_CH6_REG         (0x118)       /* CRC AHB Master接口channel6高2位地址 */
#define SRE_CRC_AHBM_ADDRH_CH7_REG         (0x11C)       /* CRC AHB Master接口channel7高2位地址 */
#define SRE_CRC_WR_ADDR0_REG               (0x2000)      /* CRC Slave模式数据接口寄存器0 */
#define SRE_CRC_WR_ADDR1_REG               (0x2400)      /* CRC Slave模式数据接口寄存器1 */
#define SRE_CRC_WR_ADDR2_REG               (0x2800)      /* CRC Slave模式数据接口寄存器2 */
#define SRE_CRC_WR_ADDR3_REG               (0x2C00)      /* CRC Slave模式数据接口寄存器3 */
#define SRE_CRC_WR_ADDR4_REG               (0x3000)      /* CRC Slave模式数据接口寄存器4 */
#define SRE_CRC_WR_ADDR5_REG               (0x3400)      /* CRC Slave模式数据接口寄存器5 */
#define SRE_CRC_WR_ADDR6_REG               (0x3800)      /* CRC Slave模式数据接口寄存器6 */
#define SRE_CRC_WR_ADDR7_REG               (0x3C00)      /* CRC Slave模式数据接口寄存器7 */


/* DMAC 模块寄存器基地址 */
#define SRE_DMAC_BASE_ADDR          (0xf00d2000)

/******************************************************************************/
/*                      Phosphor DMAC 寄存器定义                              */
/******************************************************************************/
#define SRE_DMAC_INT_1_REG                   (0x0)      	/* DMAC_INT_1为DMAC屏蔽后的中断状态寄存器1。 */
#define SRE_DMAC_ITC_MASK_INT_1_REG          (0x4)      	/* DMAC_ITC_MASK_INT_1为DMAC传输完成中断屏蔽寄存器1。 */
#define SRE_DMAC_IE_MASK_INT_1_REG           (0x8)      	/* DMAC_IE_MASK_INT_1为DMAC传输错误中断屏蔽寄存器1。 */
#define SRE_DMAC_INT_TC_1_REG                (0xC)      	/* DMAC_INT_TC_1为DMAC传输完成中断状态寄存器1。 */
#define SRE_DMAC_INT_ERR_1_REG               (0x10)     	/* DMAC_INT_ERR_1为DMAC传输错误中断状态寄存器1。 */
#define SRE_DMAC_INT_2_REG                   (0x14)     	/* DMAC_INT_2为DMAC屏蔽后的中断状态寄存器2。 */
#define SRE_DMAC_ITC_MASK_INT_2_REG          (0x18)     	/* DMAC_ITC_MASK_INT_2为DMAC传输完成中断屏蔽寄存器2。 */
#define SRE_DMAC_IE_MASK_INT_2_REG           (0x1C)     	/* DMAC_IE_MASK_INT_2为DMAC传输错误中断屏蔽寄存器2。 */
#define SRE_DMAC_INT_TC_2_REG                (0x20)     	/* DMAC_INT_TC_2为DMAC传输完成中断状态寄存器2。 */
#define SRE_DMAC_INT_ERR_2_REG               (0x24)     	/* DMAC_INT_ERR_2为DMAC传输错误中断状态寄存器2。 */
#define SRE_DMAC_INT_3_REG                   (0x28)     	/* DMAC_INT_3为DMAC屏蔽后的中断状态寄存器3。 */
#define SRE_DMAC_ITC_MASK_INT_3_REG          (0x2C)     	/* DMAC_ITC_MASK_INT_3为DMAC传输完成中断屏蔽寄存器3。 */
#define SRE_DMAC_IE_MASK_INT_3_REG           (0x30)     	/* DMAC_IE_MASK_INT_3为DMAC传输错误中断屏蔽寄存器3。 */
#define SRE_DMAC_INT_TC_3_REG                (0x34)     	/* DMAC_INT_TC为DMAC传输完成中断状态寄存器3。 */
#define SRE_DMAC_INT_ERR_3_REG               (0x38)     	/* DMAC_INT_ERR为DMAC传输错误中断状态寄存器3。 */
#define SRE_DMAC_INT_TC_CLR_REG              (0x3C)     	/* DMAC_INT_TC_CLR为DMAC传输完成中断清除寄存器。 */
#define SRE_DMAC_INT_ERR_CLR_REG             (0x40)     	/* DMAC_INT_ERR_CLR为DMAC传输错误中断清除寄存器。 */
#define SRE_DMAC_INT_TC_RAW_REG              (0x44)     	/* DMAC_INT_TC_RAW为DMAC传输完成原始中断状态寄存器。 */
#define SRE_DMAC_INT_ERR_RAW_REG             (0x48)     	/* DMAC_INT_ERR_RAW为DMAC传输错误原始中断状态寄存器。 */
#define SRE_DMAC_EN_CH_STATUS_REG            (0x4C)     	/* DMAC_EN_CH_STATUS为DMAC通道使能状态寄存器。 */
#define SRE_DMAC_BREQ_1_REG                  (0x50)     	/* DMAC_BREQ_1为DMAC通道突发传输请求寄存器1。 */
#define SRE_DMAC_BREQ_2_REG                  (0x54)    	/* DMAC_BREQ_2为DMAC通道突发传输请求寄存器2。 */
#define SRE_DMAC_SREQ_1_REG                  (0x58)     	/* DMAC_SREQ_1为DMAC通道单次传输请求寄存器1。 */
#define SRE_DMAC_SREQ_2_REG                  (0x5C)     	/* DMAC_SREQ_2为DMAC通道单次传输请求寄存器2。 */
#define SRE_DMAC_LBREQ_1_REG                 (0x60)     	/* DMAC_LBREQ_1为DMAC通道末次突发传输请求寄存器1。 */
#define SRE_DMAC_LBREQ_2_REG                 (0x64)     	/* DMAC_LBREQ_2为DMAC通道末次突发传输请求寄存器2。 */
#define SRE_DMAC_LSREQ_1_REG                 (0x68)     	/* DMAC_LSREQ_1为DMAC通道末次单次传输请求寄存器1。 */
#define SRE_DMAC_LSREQ_2_REG                 (0x6C)     	/* DMAC_LSREQ_2为DMAC通道末次单次传输请求寄存器2。 */
#define SRE_DMAC_SECURIRY_READ_REG           (0x70)     	/* DMAC_SECURIRY_READ为DMAC通道安全读访问控制寄存器。 */
#define SRE_SECURIRY_WRITE_REG               (0x74)     	/* SECURIRY_WRITE为DMAC通道安全写访问控制寄存器。 */
#define SRE_DMAC_G_EN_REG                    (0x78)     	/* DMAC_G_EN为DMAC控制寄存器。 */
#define SRE_DMAC_AUDIO_JP_SIZE_REG      		(0x7C)     	/* DMAC_AUDIO_JP_SIZE为音频跳跃搬移寄存器。 */
#define SRE_DMAC_STRID_CH_SIZE_REG      		(0x80)     	/* DMAC_STRID_CH_SIZE为重排序通道的步长设置寄存器。高16位用于某个读通道，低16位用于某个写通道。 */
#define SRE_DMAC_VIDEO_LN_SIZE_REG      		(0x84)     	/* 重排序通道的源或者目的数据块大小设置寄存器。用于设置每搬移多大的数据块之后源或者目的地址增加一个步长。 */
#define SRE_DMAC_CMSRCADDR_0_REG        		(0x100)  	/* 通道m的源地址寄存器。 */
#define SRE_DMAC_CMSRCADDR_1_REG        		(0x110)  	/* 通道m的源地址寄存器。 */
#define SRE_DMAC_CMSRCADDR_2_REG        		(0x120)  	/* 通道m的源地址寄存器。 */
#define SRE_DMAC_CMSRCADDR_3_REG        		(0x130)  	/* 通道m的源地址寄存器。 */
#define SRE_DMAC_CMSRCADDR_4_REG        		(0x140)  	/* 通道m的源地址寄存器。 */
#define SRE_DMAC_CMSRCADDR_5_REG        		(0x150) 	/* 通道m的源地址寄存器。 */
#define SRE_DMAC_CMSRCADDR_6_REG        		(0x160)  	/* 通道m的源地址寄存器。 */
#define SRE_DMAC_CMSRCADDR_7_REG        		(0x170)  	/* 通道m的源地址寄存器。 */
#define SRE_DMAC_CMSRCADDR_8_REG        		(0x180)  	/* 通道m的源地址寄存器。 */
#define SRE_DMAC_CMSRCADDR_9_REG        		(0x190) 	/* 通道m的源地址寄存器。 */
#define SRE_DMAC_CMSRCADDR_10_REG       		(0x1A0)  	/* 通道m的源地址寄存器。 */
#define SRE_DMAC_CMSRCADDR_11_REG       		(0x1B0)  	/* 通道m的源地址寄存器。 */
#define SRE_DMAC_CMSRCADDR_12_REG       		(0x1C0)  	/* 通道m的源地址寄存器。 */
#define SRE_DMAC_CMSRCADDR_13_REG       		(0x1D0)  	/* 通道m的源地址寄存器。 */
#define SRE_DMAC_CMSRCADDR_14_REG       		(0x1E0)  	/* 通道m的源地址寄存器。 */
#define SRE_DMAC_CMSRCADDR_15_REG       		(0x1F0)  	/* 通道m的源地址寄存器。 */
#define SRE_DMAC_CMDESTADDR_0_REG       		(0x104)  	/* 通道m的目标地址寄存器。 */
#define SRE_DMAC_CMDESTADDR_1_REG       		(0x114)  	/* 通道m的目标地址寄存器。 */
#define SRE_DMAC_CMDESTADDR_2_REG       		(0x124)  	/* 通道m的目标地址寄存器。 */
#define SRE_DMAC_CMDESTADDR_3_REG       		(0x134)  	/* 通道m的目标地址寄存器。 */
#define SRE_DMAC_CMDESTADDR_4_REG       		(0x144)  	/* 通道m的目标地址寄存器。 */
#define SRE_DMAC_CMDESTADDR_5_REG       		(0x154)  	/* 通道m的目标地址寄存器。 */
#define SRE_DMAC_CMDESTADDR_6_REG       		(0x164)  	/* 通道m的目标地址寄存器。 */
#define SRE_DMAC_CMDESTADDR_7_REG       		(0x174)  	/* 通道m的目标地址寄存器。 */
#define SRE_DMAC_CMDESTADDR_8_REG       		(0x184)  	/* 通道m的目标地址寄存器。 */
#define SRE_DMAC_CMDESTADDR_9_REG       		(0x194)  	/* 通道m的目标地址寄存器。 */
#define SRE_DMAC_CMDESTADDR_10_REG      		(0x1A4)  	/* 通道m的目标地址寄存器。 */
#define SRE_DMAC_CMDESTADDR_11_REG      		(0x1B4)  	/* 通道m的目标地址寄存器。 */
#define SRE_DMAC_CMDESTADDR_12_REG      		(0x1C4)  	/* 通道m的目标地址寄存器。 */
#define SRE_DMAC_CMDESTADDR_13_REG      		(0x1D4)  	/* 通道m的目标地址寄存器。 */
#define SRE_DMAC_CMDESTADDR_14_REG      		(0x1E4)  	/* 通道m的目标地址寄存器。 */
#define SRE_DMAC_CMDESTADDR_15_REG      		(0x1F4)  	/* 通道m的目标地址寄存器。 */
#define SRE_DMAC_CMLLI_0_REG            		(0x108)  	/* 通道m的链表项寄存器。 */
#define SRE_DMAC_CMLLI_1_REG            		(0x118)  	/* 通道m的链表项寄存器。 */
#define SRE_DMAC_CMLLI_2_REG            		(0x128)  	/* 通道m的链表项寄存器。 */
#define SRE_DMAC_CMLLI_3_REG            		(0x138)  	/* 通道m的链表项寄存器。 */
#define SRE_DMAC_CMLLI_4_REG            		(0x148)  	/* 通道m的链表项寄存器。 */
#define SRE_DMAC_CMLLI_5_REG            		(0x158)  	/* 通道m的链表项寄存器。 */
#define SRE_DMAC_CMLLI_6_REG            		(0x168)  	/* 通道m的链表项寄存器。 */
#define SRE_DMAC_CMLLI_7_REG            		(0x178)  	/* 通道m的链表项寄存器。 */
#define SRE_DMAC_CMLLI_8_REG            		(0x188)  	/* 通道m的链表项寄存器。 */
#define SRE_DMAC_CMLLI_9_REG           		(0x198)  	/* 通道m的链表项寄存器。 */
#define SRE_DMAC_CMLLI_10_REG           		(0x1A8)  	/* 通道m的链表项寄存器。 */
#define SRE_DMAC_CMLLI_11_REG           		(0x1B8)  	/* 通道m的链表项寄存器。 */
#define SRE_DMAC_CMLLI_12_REG           		(0x1C8)  	/* 通道m的链表项寄存器。 */
#define SRE_DMAC_CMLLI_13_REG           		(0x1D8)  	/* 通道m的链表项寄存器。 */
#define SRE_DMAC_CMLLI_14_REG           		(0x1E8)  	/* 通道m的链表项寄存器。 */
#define SRE_DMAC_CMLLI_15_REG           		(0x1F8)  	/* 通道m的链表项寄存器。 */
#define SRE_DMAC_CMCONTROL_0_REG        		(0x10C)  	/* 通道m的控制寄存器。 */
#define SRE_DMAC_CMCONTROL_1_REG        		(0x11C)  	/* 通道m的控制寄存器。 */
#define SRE_DMAC_CMCONTROL_2_REG        		(0x12C)  	/* 通道m的控制寄存器。 */
#define SRE_DMAC_CMCONTROL_3_REG        		(0x13C)  	/* 通道m的控制寄存器。 */
#define SRE_DMAC_CMCONTROL_4_REG        		(0x14C)  	/* 通道m的控制寄存器。 */
#define SRE_DMAC_CMCONTROL_5_REG        		(0x15C)  	/* 通道m的控制寄存器。 */
#define SRE_DMAC_CMCONTROL_6_REG        		(0x16C)  	/* 通道m的控制寄存器。 */
#define SRE_DMAC_CMCONTROL_7_REG        		(0x17C)  	/* 通道m的控制寄存器。 */
#define SRE_DMAC_CMCONTROL_8_REG        		(0x18C)  	/* 通道m的控制寄存器。 */
#define SRE_DMAC_CMCONTROL_9_REG        		(0x19C)  	/* 通道m的控制寄存器。 */
#define SRE_DMAC_CMCONTROL_10_REG       		(0x1AC)  	/* 通道m的控制寄存器。 */
#define SRE_DMAC_CMCONTROL_11_REG       		(0x1BC)  	/* 通道m的控制寄存器。 */
#define SRE_DMAC_CMCONTROL_12_REG       		(0x1CC)  	/* 通道m的控制寄存器。 */
#define SRE_DMAC_CMCONTROL_13_REG       		(0x1DC)  	/* 通道m的控制寄存器。 */
#define SRE_DMAC_CMCONTROL_14_REG       		(0x1EC)  	/* 通道m的控制寄存器。 */
#define SRE_DMAC_CMCONTROL_15_REG       		(0x1FC)  	/* 通道m的控制寄存器。 */
#define SRE_DMAC_CMCONFIG_0_REG         		(0x300)  	/* 通道m的配置寄存器。 */
#define SRE_DMAC_CMCONFIG_1_REG         		(0x304)  	/* 通道m的配置寄存器。 */
#define SRE_DMAC_CMCONFIG_2_REG         		(0x308)  	/* 通道m的配置寄存器。 */
#define SRE_DMAC_CMCONFIG_3_REG         		(0x30C)  	/* 通道m的配置寄存器。 */
#define SRE_DMAC_CMCONFIG_4_REG         		(0x310)  	/* 通道m的配置寄存器。 */
#define SRE_DMAC_CMCONFIG_5_REG         		(0x314)  	/* 通道m的配置寄存器。 */
#define SRE_DMAC_CMCONFIG_6_REG         		(0x318)  	/* 通道m的配置寄存器。 */
#define SRE_DMAC_CMCONFIG_7_REG         		(0x31C)  	/* 通道m的配置寄存器。 */
#define SRE_DMAC_CMCONFIG_8_REG         		(0x320)  	/* 通道m的配置寄存器。 */
#define SRE_DMAC_CMCONFIG_9_REG         		(0x324)  	/* 通道m的配置寄存器。 */
#define SRE_DMAC_CMCONFIG_10_REG        		(0x328)  	/* 通道m的配置寄存器。 */
#define SRE_DMAC_CMCONFIG_11_REG        		(0x32C)  	/* 通道m的配置寄存器。 */
#define SRE_DMAC_CMCONFIG_12_REG        		(0x330)  	/* 通道m的配置寄存器。 */
#define SRE_DMAC_CMCONFIG_13_REG        		(0x334)  	/* 通道m的配置寄存器。 */
#define SRE_DMAC_CMCONFIG_14_REG        		(0x338)  	/* 通道m的配置寄存器。 */
#define SRE_DMAC_CMCONFIG_15_REG        		(0x33C)  	/* 通道m的配置寄存器。 */

/******************************************************************************/
/*                      PhosphorV650 SEC_COMMON 寄存器定义                    */
/******************************************************************************/
#define SRE_SEC_REG_BASE                               (0xe0800000)
#define SRE_SEC_COM_SEC_CLK_EN_REG                     (SRE_SEC_REG_BASE + 0x0)             /* SEC时钟使能控制 */
#define SRE_SEC_COM_SEC_GET_POE_ADDR_REG               (SRE_SEC_REG_BASE + 0x4)             /* GET POE地址寄存器。 */
#define SRE_SEC_COM_SEC_ADD_POE_ADDR_REG               (SRE_SEC_REG_BASE + 0x8)             /* ADD POE地址寄存器 */
#define SRE_SEC_COM_SEC_BD_OFFSET_REG                  (SRE_SEC_REG_BASE + 0xC)             /* SEC BD偏移地址配置寄存器 */
#define SRE_SEC_COM_POE_FAIL_WAIT_TIME_REG             (SRE_SEC_REG_BASE + 0x10)            /* ADD或GET POE失败等待时间寄存器 */
#define SRE_SEC_COM_POE_SUC_WAIT_TIME_REG              (SRE_SEC_REG_BASE + 0x14)            /* ADD或GET POE成功等待时间寄存器 */
#define SRE_SEC_COM_SEC_CONTROL_REG                    (SRE_SEC_REG_BASE + 0x18)            /* SEC全局配置寄存器 */
#define SRE_SEC_COM_POE_ADD_FAIL_CNT_REG               (SRE_SEC_REG_BASE + 0x1C)            /* ADD POE PACKET 失败次数的统计状态寄存器 */
#define SRE_SEC_COM_POE_ADD_SUC_CNT_REG                (SRE_SEC_REG_BASE + 0x20)            /* ADD POE PACKET 成功次数的统计状态寄存器 */
#define SRE_SEC_COM_POE_GET_FAIL_CNT_REG               (SRE_SEC_REG_BASE + 0x24)            /* GET POE PACKET 失败次数的统计状态寄存器 */
#define SRE_SEC_COM_POE_GET_SUC_CNT_REG                (SRE_SEC_REG_BASE + 0x28)            /* GET POE PACKET 成功次数的统计状态寄存器 */
#define SRE_SEC_COM_SEC_BUS_TIMEOUT_THLD_REG           (SRE_SEC_REG_BASE + 0x2C)            /* SEC总线超时门限寄存器 */
#define SRE_SEC_COM_COMMON_RC_EN_CTRL_REG              (SRE_SEC_REG_BASE + 0x30)            /* 读清寄存器读清除使能 */
#define SRE_SEC_COM_SEC_GET_FAIL_THLD_REG              (SRE_SEC_REG_BASE + 0x34)            /* SEC GET POE失败次数门限寄存器 */
#define SRE_SEC_COM_SEC_ADD_FAIL_THLD_REG              (SRE_SEC_REG_BASE + 0x38)            /* SEC ADD POE失败次数门限寄存器 */
#define SRE_SEC_COM_SEC_BD_FIFO_DATA_REG               (SRE_SEC_REG_BASE + 0x3C)            /* BD FIFO模式任务添加寄存器 */
#define SRE_SEC_COM_SEC_TASKIN_FIFO_STATUS_REG         (SRE_SEC_REG_BASE + 0x40)            /* TASK IN FIFO状态寄存器 */
#define SRE_SEC_COM_SEC_ST_SRC_INT_REG                 (SRE_SEC_REG_BASE + 0x44)            /* SEC全局源中断寄存器 */
#define SRE_SEC_COM_SEC_ST_INT_MASK_REG                (SRE_SEC_REG_BASE + 0x48)            /* SEC全局中断屏蔽寄存器 */
#define SRE_SEC_COM_SEC_ST_INT_STATUS_REG              (SRE_SEC_REG_BASE + 0x4C)            /* SEC全局中断状态寄存器 */
#define SRE_SEC_COM_SEC_BD_SRC_INT_REG                 (SRE_SEC_REG_BASE + 0x50)            /* SEC BD解析源中断寄存器 */
#define SRE_SEC_COM_SEC_BD_INT_MASK_REG                (SRE_SEC_REG_BASE + 0x54)            /* SEC BD解析中断屏蔽寄存器 */
#define SRE_SEC_COM_SEC_BD_INT_STATUS_REG              (SRE_SEC_REG_BASE + 0x58)            /* SEC BD解析中断状态寄存器 */
#define SRE_SEC_COM_IPV4_MASK_TABLE_REG                (SRE_SEC_REG_BASE + 0x60)            /* IPV4 MASK表配置寄存器 */
#define SRE_SEC_COM_IPV6_MASK_TABLE_LSB_REG            (SRE_SEC_REG_BASE + 0x64)            /* IPV6 MASK表低32位配置寄存器 */
#define SRE_SEC_COM_IPV6_MASK_TABLE_MSB_REG            (SRE_SEC_REG_BASE + 0x68)            /* IPV6 MASK表高8位配置寄存器 */
#define SRE_SEC_COM_SEC_STOP_REQUST_AND_STATUS_REG     (SRE_SEC_REG_BASE + 0x6C)            /* SEC 停止请求和停止状态寄存器 */
#define SRE_SEC_COM_SEC_STOP_TIMEOUT_THLD_REG          (SRE_SEC_REG_BASE + 0x70)            /* SEC停止超时寄存器 */
#define SRE_SEC_COM_SEC_CONTROL_2_REG                  (SRE_SEC_REG_BASE + 0x74)            /* SEC全局配置寄存器 */
#define SRE_SEC_COM_SEC_SECURE_CONTROL_REG             (SRE_SEC_REG_BASE + 0x80)            /* 系统安全控制寄存器 */
#define SRE_SEC_COM_SEC_SECURE_SRAM_START_ADDR_REG     (SRE_SEC_REG_BASE + 0x84)            /* 安全SRAM起始地址 */
#define SRE_SEC_COM_SEC_SECURE_SRAM_MEM_LEN_REG        (SRE_SEC_REG_BASE + 0x8C)            /* 安全SRAM长度 */
#define SRE_SEC_COM_BD_NUM_CNT_IN_FIFO_REG             (SRE_SEC_REG_BASE + 0x400)           /* 保序模块内FIFO中任务总个数状态寄存器 */
#define SRE_SEC_COM_BD_NUM_CNT_IN_SEC_REG              (SRE_SEC_REG_BASE + 0x404)           /* SEC模块内部BD总个数状态寄存器 */
#define SRE_SEC_COM_SEC_ORDER_FSM_STATUS_REG           (SRE_SEC_REG_BASE + 0x408)           /* 保序模块内状态机状态寄存器 */
#define SRE_SEC_COM_SEC_BD_AXI_DFX_CTRL_REG            (SRE_SEC_REG_BASE + 0x40C)           /* BD AXI端口DFX控制寄存器 */
#define SRE_SEC_COM_SEC_BD_AXI_DFX_LAT_AVG_REG         (SRE_SEC_REG_BASE + 0x410)           /* BD AXI端口读写平均延迟 */
#define SRE_SEC_COM_SEC_BD_AXI_DFX_LAT_MAX_REG         (SRE_SEC_REG_BASE + 0x414)           /* BD AXI端口读写最大延迟 */
#define SRE_SEC_COM_SEC_BD_AXI_WR_ACC_REG              (SRE_SEC_REG_BASE + 0x418)           /* BD AXI端口写累计计数器 */
#define SRE_SEC_COM_SEC_BD_AXI_RD_ACC_REG              (SRE_SEC_REG_BASE + 0x41C)           /* BD AXI端口读累计计数器 */
#define SRE_SEC_COM_SEC_BD_AXI_WR_OTD_1_REG            (SRE_SEC_REG_BASE + 0x420)           /* BD AXI端口写outstanding计数器1 */
#define SRE_SEC_COM_SEC_BD_AXI_WR_OTD_2_REG            (SRE_SEC_REG_BASE + 0x424)           /* BD AXI端口写outstanding计数器2 */
#define SRE_SEC_COM_SEC_BD_AXI_WR_OTD_3_REG            (SRE_SEC_REG_BASE + 0x428)           /* BD AXI端口写outstanding计数器3 */
#define SRE_SEC_COM_SEC_BD_AXI_RD_OTD_1_REG            (SRE_SEC_REG_BASE + 0x42C)           /* BD AXI端口读outstanding计数器1 */
#define SRE_SEC_COM_SEC_BD_AXI_RD_OTD_2_REG            (SRE_SEC_REG_BASE + 0x430)           /* BD AXI端口读outstanding计数器2 */
#define SRE_SEC_COM_SEC_BD_AXI_RD_OTD_3_REG            (SRE_SEC_REG_BASE + 0x434)           /* BD AXI端口读outstanding计数器3 */
#define SRE_SEC_COM_SEC_DATA_AXI1_DFX_CTRL_REG         (SRE_SEC_REG_BASE + 0x438)           /* DATA AXI端口1 DFX控制寄存器 */
#define SRE_SEC_COM_SEC_DATA_AXI1_DFX_LAT_AVG_REG      (SRE_SEC_REG_BASE + 0x43C)           /* DATA AXI端口1读写平均延迟 */
#define SRE_SEC_COM_SEC_DATA_AXI1_DFX_LAT_MAX_REG      (SRE_SEC_REG_BASE + 0x440)           /* DATA AXI端口1读写最大延迟 */
#define SRE_SEC_COM_SEC_DATA_AXI1_WR_ACC_REG           (SRE_SEC_REG_BASE + 0x444)           /* DATA AXI端口1写累计计数器 */
#define SRE_SEC_COM_SEC_DATA_AXI1_RD_ACC_REG           (SRE_SEC_REG_BASE + 0x448)           /* DATA AXI端口1读累计计数器 */
#define SRE_SEC_COM_SEC_DATA_AXI1_WR_OTD_1_REG         (SRE_SEC_REG_BASE + 0x44C)           /* DATA AXI端口1写outstanding计数器1 */
#define SRE_SEC_COM_SEC_DATA_AXI1_WR_OTD_2_REG         (SRE_SEC_REG_BASE + 0x450)           /* DATA AXI端口1写outstanding计数器2 */
#define SRE_SEC_COM_SEC_DATA_AXI1_RD_OTD_1_REG         (SRE_SEC_REG_BASE + 0x454)           /* DATA AXI端口1读outstanding计数器1 */
#define SRE_SEC_COM_SEC_DATA_AXI1_RD_OTD_2_REG         (SRE_SEC_REG_BASE + 0x458)           /* DATA AXI端口1读outstanding计数器2 */
#define SRE_SEC_COM_SEC_DATA_AXI2_DFX_CTRL_REG         (SRE_SEC_REG_BASE + 0x45C)           /* DATA AXI端口2 DFX控制寄存器 */
#define SRE_SEC_COM_SEC_DATA_AXI2_DFX_LAT_AVG_REG      (SRE_SEC_REG_BASE + 0x460)           /* DATA AXI端口2读写平均延迟 */
#define SRE_SEC_COM_SEC_DATA_AXI2_DFX_LAT_MAX_REG      (SRE_SEC_REG_BASE + 0x464)           /* DATA AXI端口2读写最大延迟 */
#define SRE_SEC_COM_SEC_DATA_AXI2_WR_ACC_REG           (SRE_SEC_REG_BASE + 0x468)           /* DATA AXI端口2写累计计数器 */
#define SRE_SEC_COM_SEC_DATA_AXI2_RD_ACC_REG           (SRE_SEC_REG_BASE + 0x46C)           /* DATA AXI端口2读累计计数器 */
#define SRE_SEC_COM_SEC_DATA_AXI2_WR_OTD_1_REG         (SRE_SEC_REG_BASE + 0x470)           /* DATA AXI端口2写outstanding计数器1 */
#define SRE_SEC_COM_SEC_DATA_AXI2_WR_OTD_2_REG         (SRE_SEC_REG_BASE + 0x474)           /* DATA AXI端口2写outstanding计数器2 */
#define SRE_SEC_COM_SEC_DATA_AXI2_RD_OTD_1_REG         (SRE_SEC_REG_BASE + 0x478)           /* DATA AXI端口2读outstanding计数器1 */
#define SRE_SEC_COM_SEC_DATA_AXI2_RD_OTD_2_REG         (SRE_SEC_REG_BASE + 0x47C)           /* DATA AXI端口2读outstanding计数器2 */
#define SRE_SEC_COM_SEC_BD_AXI_TIMEOUT_1_REG           (SRE_SEC_REG_BASE + 0x480)           /* BD AXI端口超时标志寄存器1 */
#define SRE_SEC_COM_SEC_BD_AXI_TIMEOUT_2_REG           (SRE_SEC_REG_BASE + 0x484)           /* BD AXI端口超时标志寄存器2 */
#define SRE_SEC_COM_SEC_DATA_AXI_TIMEOUT_REG           (SRE_SEC_REG_BASE + 0x488)           /* DATA AXI端口超时标志寄存器 */
#define SRE_SEC_COM_SEC_STAT_CLR_REG                   (SRE_SEC_REG_BASE + 0x48C)           /* SEC统计寄存器清零寄存器 */
#define SRE_SEC_COM_SEC_SAA0_ACC_REG                   (SRE_SEC_REG_BASE + 0x490)           /* SAA0累计处理包数寄存器 */
#define SRE_SEC_COM_SEC_SAA1_ACC_REG                   (SRE_SEC_REG_BASE + 0x494)           /* SAA1累计处理包数寄存器 */
#define SRE_SEC_COM_SEC_SAA2_ACC_REG                   (SRE_SEC_REG_BASE + 0x498)           /* SAA2累计处理包数寄存器 */
#define SRE_SEC_COM_SEC_SAA3_ACC_REG                   (SRE_SEC_REG_BASE + 0x49C)           /* SAA3累计处理包数寄存器 */
#define SRE_SEC_COM_SEC_SAA4_ACC_REG                   (SRE_SEC_REG_BASE + 0x4A0)           /* SAA4累计处理包数寄存器 */
#define SRE_SEC_COM_SEC_SAA5_ACC_REG                   (SRE_SEC_REG_BASE + 0x4A4)           /* SAA5累计处理包数寄存器 */
#define SRE_SEC_COM_SEC_SAA6_ACC_REG                   (SRE_SEC_REG_BASE + 0x4A8)           /* SAA6累计处理包数寄存器 */
#define SRE_SEC_COM_SEC_SAA7_ACC_REG                   (SRE_SEC_REG_BASE + 0x4AC)           /* SAA7累计处理包数寄存器 */
#define SRE_SEC_COM_SEC_PKT_LATENCY_REG                (SRE_SEC_REG_BASE + 0x4B0)           /* 单包延迟统计寄存器 */
#define SRE_SEC_COM_RSV_DFX_CONFIG_1_REG               (SRE_SEC_REG_BASE + 0x500)           /* 保留DFX配置寄存器 */
#define SRE_SEC_COM_RSV_DFX_CONFIG_2_REG               (SRE_SEC_REG_BASE + 0x504)           /* 保留DFX配置寄存器 */
#define SRE_SEC_COM_RSV_DFX_CONFIG_3_REG               (SRE_SEC_REG_BASE + 0x508)           /* 保留DFX配置寄存器 */
#define SRE_SEC_COM_RSV_DFX_STATUS_1_REG               (SRE_SEC_REG_BASE + 0x50C)           /* 保留DFX状态寄存器 */
#define SRE_SEC_COM_RSV_DFX_STATUS_2_REG               (SRE_SEC_REG_BASE + 0x510)           /* 保留DFX状态寄存器 */
#define SRE_SEC_COM_RSV_DFX_STATUS_3_REG               (SRE_SEC_REG_BASE + 0x514)           /* 保留DFX状态寄存器 */


#define SRE_SEC_SAA_REG_BASE                        (SRE_SEC_REG_BASE + 0x1000)
#define SRE_SEC_CHANNEL_CURR_BD_REG  	       		(SRE_SEC_SAA_REG_BASE + 0x0)  /* CHANNEL_CURR_BD为SAA的Channel当前使用的BD信息寄存器。 */
#define SRE_SEC_SHADOW_CURR_BD_REG  	            (SRE_SEC_SAA_REG_BASE + 0x200)  /* SHADOW_CURR_BD为SAA的SHADOW状态机当前使用的BD信息寄存器。 */
#define SRE_SEC_CIPHER_IVIN_REG    	                (SRE_SEC_SAA_REG_BASE + 0x400)  /* SAA SHADOW状态机当前使用的CIPHER IVIN值信息寄存器。 */
#define SRE_SEC_CIPHER_KEY_REG     	                (SRE_SEC_SAA_REG_BASE + 0x500)  /* SAA SHADOW状态机当前使用的CIPHER KEY值信息寄存器。 */
#define SRE_SEC_HASH_IVIN_REG      	                (SRE_SEC_SAA_REG_BASE + 0x600)  /* SAA SHADOW状态机当前使用的HASH IVIN值信息寄存器。 */
#define SRE_SEC_HASH_KEY_REG       	                (SRE_SEC_SAA_REG_BASE + 0x700)  /* SAA SHADOW状态机当前使用的HMAC KEY值信息寄存器。 */
#define SRE_SEC_HASH_IVOUT_REG     	                (SRE_SEC_SAA_REG_BASE + 0x800)  /* SAA当前输出的HASH IV OUT值信息寄存器。 */
#define SRE_SEC_CHANNEL_STATUS_REG   	            (SRE_SEC_SAA_REG_BASE + 0x908)  /* CHANNEL_STATUS为Channel状态寄存器。 */
#define SRE_SEC_CHANNEL_TIME_OUT_CNT_REG       		(SRE_SEC_SAA_REG_BASE + 0x90C)  /* CHANNEL状态机智能心跳计数值寄存器 */
#define SRE_SEC_CHANNEL_MAX_CNT_REG  	        	(SRE_SEC_SAA_REG_BASE + 0x910)  /* CHANNEL状态机智能心跳计数上限值配置寄存器 */
#define SRE_SEC_SHADOW_TIME_OUT_CNT_REG        		(SRE_SEC_SAA_REG_BASE + 0x914)  /* SHADOW状态机智能心跳计数值寄存器 */
#define SRE_SEC_SHADOW_MAX_CNT_REG   	        	(SRE_SEC_SAA_REG_BASE + 0x918)  /* SHADOW状态机智能心跳计数上限值配置寄存器 */
#define SRE_SEC_SEC_BD_ERR_ADDR_REG  	            (SRE_SEC_SAA_REG_BASE + 0x91C)  /* 最近一次错误BD地址查询寄存器 */
#define SRE_SEC_SEC_BD_ERR_CNT_REG   	            (SRE_SEC_SAA_REG_BASE + 0x920)  /* SEC BD错误统计寄存器 */
#define SRE_SEC_SAA_GET2ADD_WAIT_TIME_REG    		(SRE_SEC_SAA_REG_BASE + 0x924)  /* 在可以ADD BD时，获取BD的最长等待时间配置寄存器。 */
#define SRE_SEC_SAA_RC_EN_CTRL_REG   	            (SRE_SEC_SAA_REG_BASE + 0x928)  /* 读清寄存器读清除使能 */
#define SRE_SEC_SAA_ADD_DATA_1_REG                  (SRE_SEC_SAA_REG_BASE + 0xD00)  /* 当前SAA ADD DATA总线数据 */
#define SRE_SEC_SAA_ADD_DATA_2_REG                  (SRE_SEC_SAA_REG_BASE + 0xD04)  /* 当前SAA ADD DATA总线数据 */
#define SRE_SEC_SAA_ADD_DATA_3_REG                  (SRE_SEC_SAA_REG_BASE + 0xD08)  /* 当前SAA ADD DATA总线数据 */
#define SRE_SEC_DFX_CONFIG_SEL_REG                  (SRE_SEC_SAA_REG_BASE + 0xD0C)  /* DFX配置寄存器 */
#define SRE_SEC_RSV_DFX_CONFIG_1_REG                (SRE_SEC_SAA_REG_BASE + 0xE00)  /* 保留DFX配置寄存器 */
#define SRE_SEC_RSV_DFX_CONFIG_2_REG                (SRE_SEC_SAA_REG_BASE + 0xE04)  /* 保留DFX配置寄存器 */
#define SRE_SEC_RSV_DFX_CONFIG_3_REG                (SRE_SEC_SAA_REG_BASE + 0xE08)  /* 保留DFX配置寄存器 */
#define SRE_SEC_RSV_DFX_STATUS_1_REG                (SRE_SEC_SAA_REG_BASE + 0xE0C)  /* 保留DFX状态寄存器 */
#define SRE_SEC_RSV_DFX_STATUS_2_REG                (SRE_SEC_SAA_REG_BASE + 0xE10)  /* 保留DFX状态寄存器 */
#define SRE_SEC_RSV_DFX_STATUS_3_REG                (SRE_SEC_SAA_REG_BASE + 0xE14)  /* 保留DFX状态寄存器 */


/******************************************************************************/
/*                      PhosphorV650 rohc Engine 寄存器定义               */
/******************************************************************************/
/* rohc_config 模块寄存器基地址 */
#define SRE_ROHC_CONFIG_BASE                     (0x10810000)

/******************************************************************************/
/*                      MC rohc_config 寄存器定义                   */
/******************************************************************************/
#define SRE_ROHC_CONFIG_ROHC_ENABLE_REG                              (SRE_ROHC_CONFIG_BASE + 0x0)  /* ROHC全局使能控制寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_CONTROL_REG                          (SRE_ROHC_CONFIG_BASE + 0x4)  /* ROHC全局配置寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_COMP_GET_POE_ADDR_REG  (SRE_ROHC_CONFIG_BASE + 0x8)  /* 压缩端GET POE地址寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_COMP_ADD_POE_ADDR_REG  (SRE_ROHC_CONFIG_BASE + 0xC)  /* 压缩端ADD POE地址寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_DECOMP_GET_POE_ADDR_REG  (SRE_ROHC_CONFIG_BASE + 0x10)  /* 解压端GET POE地址寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_DECOMP_ADD_POE_ADDR_REG  (SRE_ROHC_CONFIG_BASE + 0x14)  /* 解压端ADD POE地址寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_PDCP_ADDR_REG                           (SRE_ROHC_CONFIG_BASE + 0x18)  /* PDCP实体地址寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_CRCOPT_PKT_NUM_REG        (SRE_ROHC_CONFIG_BASE + 0x24)  /* 判断报文数量配置寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_FDBACK_PKT_NUM_REG         (SRE_ROHC_CONFIG_BASE + 0x28)  /* 反馈包数量配置寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_POE_FAIL_WAIT_TIME_REG  (SRE_ROHC_CONFIG_BASE + 0x2C)  /* POE GET或ADD任务失败等待寄存器 */
#define SRE_ROHC_CONFIG_ROHC_POE_OK_WAIT_TIME_REG     (SRE_ROHC_CONFIG_BASE + 0x30)  /* POE GET或ADD任务成功等待寄存器 */
#define SRE_ROHC_CONFIG_ROHC_BACK2IRFO_TIME_REG  (SRE_ROHC_CONFIG_BASE + 0x34)  /* 定时回迁寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_IPID_MAX_DELTA_REG  (SRE_ROHC_CONFIG_BASE + 0x38)  /* IPID变化范围寄存器。 */
#define SRE_ROHC_CONFIG_PRF0_STATE_THLD_REG            (SRE_ROHC_CONFIG_BASE + 0x3c)  /* profile0跃迁、回迁门限 */
#define SRE_ROHC_CONFIG_ROHC_FC2SC_N1_REG                (SRE_ROHC_CONFIG_BASE + 0x40)  /* 解压端状态跳转连续解压的总包数配置寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_CTXLIST_ADDR_REG      (SRE_ROHC_CONFIG_BASE + 0x44)  /* ROHC上下文表起始地址配置寄存器。(压缩、解压缩配置寄存器合并） */
#define SRE_ROHC_CONFIG_ROHC_CTX_ADDR_REG              (SRE_ROHC_CONFIG_BASE + 0x48)  /* 上下文空间起始地址配置寄存器。(压缩、解压缩配置寄存器合并） */
#define SRE_ROHC_CONFIG_ROHC_PDCP_ID_OFST_REG      (SRE_ROHC_CONFIG_BASE + 0x4C)  /* PDCP实体ID偏移配置寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_SEC_BD_OFST_REG        (SRE_ROHC_CONFIG_BASE + 0x50)  /* SEC BD在报文缓冲区的偏移。 */
#define SRE_ROHC_CONFIG_SN_WRAP_AROUND_THLD_REG     (SRE_ROHC_CONFIG_BASE + 0x54)  /* 判断SN卷绕门限 */
#define SRE_ROHC_CONFIG_BMU_RELEASE_BASE_ADDR_REG   (SRE_ROHC_CONFIG_BASE + 0x58)  /* 写BMU释放缓存基地址寄存器 */
#define SRE_ROHC_CONFIG_BMU_REQ_ADDR_REG                       (SRE_ROHC_CONFIG_BASE + 0x5C)  /* 读BMU申请缓存地址寄存器 */
#define SRE_ROHC_CONFIG_BMU_WR_FAIL_WATI_TIME_REG   (SRE_ROHC_CONFIG_BASE + 0x60)  /* 写BUM释放缓存失败延迟寄存器 */
#define SRE_ROHC_CONFIG_BMU_RD_FAIL_WAIT_TIME_REG    (SRE_ROHC_CONFIG_BASE + 0x64)  /* 读BUM申请缓存失败延迟寄存器 */
#define SRE_ROHC_CONFIG_BMU_BUF_ADDR0_REG                      (SRE_ROHC_CONFIG_BASE + 0x68)  /* ROHC内部拥有的BMU缓存地址0 */
#define SRE_ROHC_CONFIG_BMU_BUF_ADDR1_REG                      (SRE_ROHC_CONFIG_BASE + 0x6C)  /* ROHC内部拥有的BMU缓存地址1 */
#define SRE_ROHC_CONFIG_BMU_REQ_BUF_CNT_REG                 (SRE_ROHC_CONFIG_BASE + 0x70)  /* 读申请BMU缓存个数统计寄存器 */
#define SRE_ROHC_CONFIG_BMU_RELEASE_BUF_CNT_REG         (SRE_ROHC_CONFIG_BASE + 0x74)  /* 写释放BMU缓存个数统计寄存器 */
#define SRE_ROHC_CONFIG_BMU_REQ_BUF_FAIL_CNT_REG       (SRE_ROHC_CONFIG_BASE + 0x78)  /* 读BMU申请缓存连续失败个数统计计数器 */
#define SRE_ROHC_CONFIG_BMU_RELEASE_BUF_FAIL_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x7C)  /* 写BMU释放缓存连续失败个数统计计数器 */
#define SRE_ROHC_CONFIG_BMU_REQ_BUFFER_REG                       (SRE_ROHC_CONFIG_BASE + 0x80)  /* 反馈包相关 */
#define SRE_ROHC_CONFIG_FBK_GROUP_TT_QOS_REG                  (SRE_ROHC_CONFIG_BASE + 0x84)  /* 反馈包相关*/
#define SRE_ROHC_CONFIG_HBEAT_THLD_REG                                 (SRE_ROHC_CONFIG_BASE + 0x88)  /* 只能心跳阈值*/
#define SRE_ROHC_CONFIG_BMU_INT_THLD_REG                            (SRE_ROHC_CONFIG_BASE + 0x8C)  /* BMU连续失败中断阈值寄存器 */
#define SRE_ROHC_CONFIG_BUT_MAX_TIMEOUT_THLD_REG         (SRE_ROHC_CONFIG_BASE + 0x90)  /* 总线最大延时超时门限 */
#define SRE_ROHC_CONFIG_POE_INT_THLD_REG                             (SRE_ROHC_CONFIG_BASE + 0x94)  /* POE连续失败中断阈值寄存器 */
#define SRE_ROHC_CONFIG_ROHC_SRC_INT_REG                            (SRE_ROHC_CONFIG_BASE + 0x98)  /* ROHC源中断寄存器 */
#define SRE_ROHC_CONFIG_ROHC_INT_MASK_REG                         (SRE_ROHC_CONFIG_BASE + 0x9C)  /* ROHC中断屏蔽寄存器 */
#define SRE_ROHC_CONFIG_ROHC_INTSTS_REG                               (SRE_ROHC_CONFIG_BASE + 0x100)  /* 超时中断状态寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_C_GET_POE_SUC_CNT_REG    (SRE_ROHC_CONFIG_BASE + 0x110)  /* 压缩器GET POE成功次数统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_C_ADD_POE_SUC_CNT_REG    (SRE_ROHC_CONFIG_BASE + 0x114)  /* 压缩器ADD POE成功次数统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_C_GET_POE_FAIL_CNT_REG    (SRE_ROHC_CONFIG_BASE + 0x118)  /* 压缩器GET POE失败次数统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_C_ADD_POE_FAIL_CNT_REG    (SRE_ROHC_CONFIG_BASE + 0x11C)  /* 压缩器ADD POE失败次数统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_D_GET_POE_SUC_CNT_REG     (SRE_ROHC_CONFIG_BASE + 0x120)  /* 解压器GET POE成功次数统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_D_ADD_POE_SUC_CNT_REG     (SRE_ROHC_CONFIG_BASE + 0x124)  /* 解压器ADD POE成功次数统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_D_GET_POE_FAIL_CNT_REG     (SRE_ROHC_CONFIG_BASE + 0x128)  /* 解压器GET POE失败次数统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_D_ADD_POE_FAIL_CNT_REG     (SRE_ROHC_CONFIG_BASE + 0x12C)  /* 解压器ADD POE失败次数统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_C_GET_CONTINUE_FAIL_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x130)  /* 压缩器GET POE连续失败次数统计寄存器 */
#define SRE_ROHC_CONFIG_ROHC_C_ADD_CONTINUE_FAIL_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x134)  /* 压缩器ADD POE连续失败次数统计寄存器 */
#define SRE_ROHC_CONFIG_ROHC_D_GET_CONTINUE_FAIL_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x138)  /* 解压器GET POE连续失败次数统计寄存器 */
#define SRE_ROHC_CONFIG_ROHC_D_ADD_CONTINUE_FAIL_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x13C)  /* 解压器ADD POE连续失败次数统计寄存器 */
#define SRE_ROHC_CONFIG_CNT_RD_LATENCY_AVG_REG                         (SRE_ROHC_CONFIG_BASE + 0x140)  /* 总线读操作平均延时统计寄存器 */
#define SRE_ROHC_CONFIG_CNT_WR_LATENCY_AVG_REG                        (SRE_ROHC_CONFIG_BASE + 0x144)  /* 总线读操作平均延时统计寄存器 */
#define SRE_ROHC_CONFIG_CNT_RD_LATENCY_MAX_REG                        (SRE_ROHC_CONFIG_BASE + 0x148)  /* 总线读操作最大延时统计寄存器 */
#define SRE_ROHC_CONFIG_CNT_WR_LATENCY_MAX_REG                       (SRE_ROHC_CONFIG_BASE + 0x14C)  /* 总线读操作最大延时统计寄存器 */
#define SRE_ROHC_CONFIG_CNT_RD_ACC_REG                      (SRE_ROHC_CONFIG_BASE + 0x150)  /* 总线读访问次数统计寄存器 */
#define SRE_ROHC_CONFIG_CNT_WR_ACC_REG                     (SRE_ROHC_CONFIG_BASE + 0x154)  /* 总线写访问次数统计寄存器 */
#define SRE_ROHC_CONFIG_CNT_RD_OTD_MSB_REG            (SRE_ROHC_CONFIG_BASE + 0x158)  /* 总线读outstanding个数统计高32bit */
#define SRE_ROHC_CONFIG_CNT_RD_OTD_LSB_REG             (SRE_ROHC_CONFIG_BASE + 0x15C)  /* 总线读outstanding个数统计低32bit */
#define SRE_ROHC_CONFIG_CNT_WR_OTD_MSB_REG           (SRE_ROHC_CONFIG_BASE + 0x160)  /* 总线写outstanding个数统计高32bit */
#define SRE_ROHC_CONFIG_CNT_WR_OTD_LSB_REG            (SRE_ROHC_CONFIG_BASE + 0x164)  /* 总线写outstanding个数统计低32bit */
#define SRE_ROHC_CONFIG_ROHC_HOLD_PKT_NUM_REG    (SRE_ROHC_CONFIG_BASE + 0x168)  /* rohc当前hold住的buffer*/
#define SRE_ROHC_CONFIG_ROHC_UL_DECOMP_PKT_CNT_REG   (SRE_ROHC_CONFIG_BASE + 0x200)  /* 上行收到压缩包的数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_DECOMP_FAIL_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x204)  /* 上行解压失败统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_DECOMP_OK_CNT_REG     (SRE_ROHC_CONFIG_BASE + 0x208)  /* 上行解压成功统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_CRC_ERR_CNT_REG           (SRE_ROHC_CONFIG_BASE + 0x20C)  /* 上行解压缩CRC校验错误报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_CRC_OK_CNT_REG             (SRE_ROHC_CONFIG_BASE + 0x210)  /* 上行解压缩CRC校验成功报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_PKTTYP_ERR_CNT_REG    (SRE_ROHC_CONFIG_BASE + 0x214)  /* 上行解压缩压缩包类型错误数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_DL_COMP_PKT_CNT_REG        (SRE_ROHC_CONFIG_BASE + 0x218)  /* 下行压缩使能报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_DL_COMP_ERR_CNT_REG        (SRE_ROHC_CONFIG_BASE + 0x21C)  /* 下行压缩失败报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_DL_COMP_OK_CNT_REG          (SRE_ROHC_CONFIG_BASE + 0x220)  /* 下行压缩成功报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_DL_PROF0_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x234)  /* 下行选择Profile0压缩报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_DL_PROF1_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x238)  /* 下行选择Profile1压缩报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_DL_PROF2_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x23C)  /* 下行选择Profile2压缩报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_DL_PROF3_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x240)  /* 下行选择Profile3压缩报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_DL_PROF4_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x244)  /* 下行选择Profile4压缩报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_DL_PROF6_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x248)  /* 下行选择Profile6压缩报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_PROF0_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x24C)  /* 上行选择Profile0解压报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_PROF1_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x250)  /* 上行选择Profile1解压报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_PROF2_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x254)  /* 上行选择Profile2解压报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_PROF3_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x258)  /* 上行选择Profile3解压报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_PROF4_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x25C)  /* 上行选择Profile4解压报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_PROF6_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x260)  /* 上行选择Profile6解压报文数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_DL_IR_CNT_REG          (SRE_ROHC_CONFIG_BASE + 0x264)  /* 下行压缩采用IR包数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_DL_IRDYN_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x268)  /* 下行压缩采用IRDYN包数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_DL_EX3_CNT_REG        (SRE_ROHC_CONFIG_BASE + 0x278)  /* 下行压缩采用扩展3类型包数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_IR_CNT_REG           (SRE_ROHC_CONFIG_BASE + 0x27C)  /* 上行解压收到IR包数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_IRDYN_CNT_REG   (SRE_ROHC_CONFIG_BASE + 0x280)  /* 上行解压收到IRDYN包数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_TYP0_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x284)  /* 上行解压收到0型包数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_TYP1_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x288)  /* 上行解压收到1型包数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_TYP2_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x28C)  /* 上行解压收到2型包数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_EX3_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x290)  /* 上行解压收到扩展3类型包数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_DL_FBK_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x294)  /* 下行压缩器收到反馈包数量统计寄存器。 */
#define SRE_ROHC_CONFIG_ROHC_UL_FBK_CNT_REG  (SRE_ROHC_CONFIG_BASE + 0x298)  /* 上行解压器产生反馈包数量统计寄存器。 */
#define SRE_ROHC_CONFIG_CNT_CLR_EN_REG0_REG  (SRE_ROHC_CONFIG_BASE + 0x300)  /* 统计计数器清0使能寄存器0。 */
#define SRE_ROHC_CONFIG_CNT_CLR_EN_REG1_REG  (SRE_ROHC_CONFIG_BASE + 0x304)  /* 统计计数器清0使能寄存器1。 */
#define SRE_ROHC_CONFIG_READ_CLR_EN_REG           (SRE_ROHC_CONFIG_BASE + 0x308)  /* 读清使能控制寄存器 */
#define SRE_ROHC_CONFIG_C_CTX_RD_CTRL_REG      (SRE_ROHC_CONFIG_BASE + 0x400)  /* 压缩器上下文读取控制寄存器 */
#define SRE_ROHC_CONFIG_C_CTX_WORD0_REG  (SRE_ROHC_CONFIG_BASE + 0x404)  /* 压缩器上下文数据寄存器0 */
#define SRE_ROHC_CONFIG_C_CTX_WORD1_REG  (SRE_ROHC_CONFIG_BASE + 0x408)  /* 压缩器上下文数据寄存器1 */
#define SRE_ROHC_CONFIG_C_CTX_WORD2_REG  (SRE_ROHC_CONFIG_BASE + 0x40C)  /* 压缩器上下文数据寄存器2 */
#define SRE_ROHC_CONFIG_C_CTX_WORD3_REG  (SRE_ROHC_CONFIG_BASE + 0x410)  /* 压缩器上下文数据寄存器3 */
#define SRE_ROHC_CONFIG_D_CTX_WORD0_REG  (SRE_ROHC_CONFIG_BASE + 0x414)  /* 解压器上下文数据寄存器0 */
#define SRE_ROHC_CONFIG_D_CTX_WORD1_REG  (SRE_ROHC_CONFIG_BASE + 0x418)  /* 解压器上下文数据寄存器1 */
#define SRE_ROHC_CONFIG_D_CTX_WORD2_REG  (SRE_ROHC_CONFIG_BASE + 0x41C)  /* 解压器上下文数据寄存器2 */
#define SRE_ROHC_CONFIG_D_CTX_WORD3_REG  (SRE_ROHC_CONFIG_BASE + 0x420)  /* 解压器上下文数据寄存器3 */
#define SRE_ROHC_CONFIG_PE_INDEX_REG                (SRE_ROHC_CONFIG_BASE + 0x424)  /* 流水线指针状态寄存器 */
#define SRE_ROHC_CONFIG_C_PE1_MAIN_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x500)  /* 压缩器第一级主状态机状态寄存器 */
#define SRE_ROHC_CONFIG_C_PE1_PDCP_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x504)  /* 压缩器第一级PDCP读取状态机状态寄存器 */
#define SRE_ROHC_CONFIG_C_PE1_CID_FSM_REG     (SRE_ROHC_CONFIG_BASE + 0x508)  /* 压缩器第一级CID状态机状态寄存器 */
#define SRE_ROHC_CONFIG_C_PE1_CTX_FSM_REG    (SRE_ROHC_CONFIG_BASE + 0x50C)  /* 压缩器第一级上下文读取状态寄存器 */
#define SRE_ROHC_CONFIG_C_PE2_MAIN_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x510)  /* 压缩器第二级主状态机状态寄存器 */
#define SRE_ROHC_CONFIG_C_PE2_PPS_FSM_REG     (SRE_ROHC_CONFIG_BASE + 0x514)  /* 压缩器第二级包解析状态机状态寄存器 */
#define SRE_ROHC_CONFIG_C_PE2_CRC_FSM_REG    (SRE_ROHC_CONFIG_BASE + 0x518)  /* 压缩器第二级CRC状态机状态寄存器 */
#define SRE_ROHC_CONFIG_C_PE2_ASM_FSM_REG    (SRE_ROHC_CONFIG_BASE + 0x51C)  /* 压缩器第二级组包状态机状态寄存器 */
#define SRE_ROHC_CONFIG_C_PE3_MAIN_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x520)  /* 压缩器第三级主状态机状态寄存器 */
#define SRE_ROHC_CONFIG_C_PE3_PDCP_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x524)  /* 压缩器第三级PDCP回写状态机状态寄存器 */
#define SRE_ROHC_CONFIG_C_PE3_CTX_FSM_REG     (SRE_ROHC_CONFIG_BASE + 0x528)  /* 压缩器第三级上下文回写状态机状态寄存器 */
#define SRE_ROHC_CONFIG_D_PE1_MAIN_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x530)  /* 解压器第一级主状态机状态寄存器 */
#define SRE_ROHC_CONFIG_D_PE1_PDCP_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x534)  /* 解压器第一级PDCP读取状态机状态寄存器 */
#define SRE_ROHC_CONFIG_D_PE1_FBK_FSM_REG     (SRE_ROHC_CONFIG_BASE + 0x538)  /* 解压器第一级反馈状态机状态寄存器 */
#define SRE_ROHC_CONFIG_D_PE1_CTX_FSM_REG    (SRE_ROHC_CONFIG_BASE + 0x53C)  /* 解压器第一级上下文读取状态寄存器 */
#define SRE_ROHC_CONFIG_D_PE2_MAIN_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x540)  /* 解压器第二级主状态机状态寄存器 */
#define SRE_ROHC_CONFIG_D_PE2_EX3_FSM_REG     (SRE_ROHC_CONFIG_BASE + 0x544)  /* 解压器第二级EX3状态机状态寄存器 */
#define SRE_ROHC_CONFIG_D_PE2_CRC_FSM_REG    (SRE_ROHC_CONFIG_BASE + 0x548)  /* 解压器第二级CRC状态机状态寄存器 */
#define SRE_ROHC_CONFIG_D_PE2_STA_FSM_REG    (SRE_ROHC_CONFIG_BASE + 0x54C)  /* 解压器第二级STA状态机状态寄存器 */
#define SRE_ROHC_CONFIG_D_PE2_DYN_FSM_REG    (SRE_ROHC_CONFIG_BASE + 0x550)  /* 解压器第二级DYN状态机状态寄存器 */
#define SRE_ROHC_CONFIG_D_PE3_MAIN_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x554)  /* 解压器第三级主状态机状态寄存器 */
#define SRE_ROHC_CONFIG_D_PE3_PDCP_FSM_REG  (SRE_ROHC_CONFIG_BASE + 0x558)  /* 解压器第三级PDCP回写状态机状态寄存器 */
#define SRE_ROHC_CONFIG_D_PE3_CTX_FSM_REG     (SRE_ROHC_CONFIG_BASE + 0x55C)  /* 解压器第三级上下文回写状态机状态寄存器 */
#define SRE_ROHC_CONFIG_DFX_CONFIG_REG0		(SRE_ROHC_CONFIG_BASE + 0x0600)	/* DFX配置寄存器0                    */
#define SRE_ROHC_CONFIG_DFX_CONFIG_REG1		(SRE_ROHC_CONFIG_BASE + 0x0604)	/* DFX配置寄存器1                    */
#define SRE_ROHC_CONFIG_DFX_CONFIG_REG2		(SRE_ROHC_CONFIG_BASE + 0x0608)	/* DFX配置寄存器2                    */
#define SRE_ROHC_CONFIG_DFX_STATUE_REG0		(SRE_ROHC_CONFIG_BASE + 0x060C)	/* DFX状态寄存器0                    */
#define SRE_ROHC_CONFIG_DFX_STATUE_REG1		(SRE_ROHC_CONFIG_BASE + 0x0610)	/* DFX状态寄存器1                    */
#define SRE_ROHC_CONFIG_DFX_STATUE_REG2		(SRE_ROHC_CONFIG_BASE + 0x0614)	/* DFX状态寄存器2                    */
#define SRE_ROHC_CONFIG_C_POE_DATA_31_0		(SRE_ROHC_CONFIG_BASE + 0x0620)	/* 压缩器获取POE任务数据Word0寄存器  */
#define SRE_ROHC_CONFIG_C_POE_DATA_63_32	(SRE_ROHC_CONFIG_BASE + 0x0624)	/* 压缩器获取POE任务数据Word1寄存器  */
#define SRE_ROHC_CONFIG_C_POE_DATA_95_64	(SRE_ROHC_CONFIG_BASE + 0x0628)	/* 压缩器获取POE任务数据Word2寄存器  */
#define SRE_ROHC_CONFIG_C_POE_DATA_127_96	(SRE_ROHC_CONFIG_BASE + 0x062C)	/* 压缩器获取POE任务数据Word3寄存器  */
#define SRE_ROHC_CONFIG_D_POE_DATA_31_0		(SRE_ROHC_CONFIG_BASE + 0x0630)	/* 解压器获取POE任务数据Word0寄存器  */
#define SRE_ROHC_CONFIG_D_POE_DATA_63_32	(SRE_ROHC_CONFIG_BASE + 0x0634)	/* 解压器获取POE任务数据Word1寄存器  */
#define SRE_ROHC_CONFIG_D_POE_DATA_95_64	(SRE_ROHC_CONFIG_BASE + 0x0638)	/* 解压器获取POE任务数据Word2寄存器  */
#define SRE_ROHC_CONFIG_D_POE_DATA_127_96	(SRE_ROHC_CONFIG_BASE + 0x063C)	/* 解压器获取POE任务数据Word3寄存器  */
#define SRE_ROHC_CONFIG_C_BD_WORD_12		(SRE_ROHC_CONFIG_BASE + 0x0640)	/* 压缩器获取BD Word12寄存器	     */
#define SRE_ROHC_CONFIG_C_BD_WORD_13		(SRE_ROHC_CONFIG_BASE + 0x0644)	/* 压缩器获取BD Word12寄存器	     */
#define SRE_ROHC_CONFIG_C_BD_WORD_14		(SRE_ROHC_CONFIG_BASE + 0x0648)	/* 压缩器获取BD Word14寄存器	     */
#define SRE_ROHC_CONFIG_C_DFX_PAYLOAD		(SRE_ROHC_CONFIG_BASE + 0x064C)	/* 压缩器关键标志位状态寄存器        */
#define SRE_ROHC_CONFIG_D_BD_WORD_12		(SRE_ROHC_CONFIG_BASE + 0x0650)	/* 解压器获取BD Word12寄存器	     */
#define SRE_ROHC_CONFIG_D_BD_WORD_13		(SRE_ROHC_CONFIG_BASE + 0x0654)	/* 解压器获取BD Word12寄存器	     */
#define SRE_ROHC_CONFIG_D_BD_WORD_14		(SRE_ROHC_CONFIG_BASE + 0x0658)	/* 解压器获取BD Word14寄存器	     */
#define SRE_ROHC_CONFIG_D_DFX_PAYLOAD		(SRE_ROHC_CONFIG_BASE + 0x065C)	/* 解压器关键标志位状态寄存器        */
#define SRE_ROHC_CONFIG_CTX_LOCK_DFX_REG	(SRE_ROHC_CONFIG_BASE + 0x0660)	/* 上下文锁状态寄存器		     */
#define SRE_ROHC_CONFIG_C_BD_EEROR_ADDR		(SRE_ROHC_CONFIG_BASE + 0x0664)	/* 压缩器BD错误缓存地址寄存器	     */
#define SRE_ROHC_CONFIG_D_BD_EEROR_ADDR		(SRE_ROHC_CONFIG_BASE + 0x0668)	/* 解压器BD错误缓存地址寄存器	     */
#define SRE_ROHC_CONFIG_C_PDCP_EEROR_ID		(SRE_ROHC_CONFIG_BASE + 0x066C)	/* 压缩器PDCP错误ID寄存器*/
#define SRE_ROHC_CONFIG_D_PDCP_EEROR_ID		(SRE_ROHC_CONFIG_BASE + 0x0670)	/* 解压器PDCP错误ID寄存器*/
#define SRE_ROHC_CONFIG_C_DFX_CTRL_REG		(SRE_ROHC_CONFIG_BASE + 0x0700)	/* 压缩器DFX控制寄存器		     */
#define SRE_ROHC_CONFIG_D_DFX_CTRL_REG		(SRE_ROHC_CONFIG_BASE + 0x0704)	/* 解压器DFX控制寄存器		     */

/* SCH 模块寄存器基地址 */
#define SRE_SCH_BASE                                 (0xe1000000UL)
/******************************************************************************/
/*                      MC SCH 寄存器定义                                     */
/******************************************************************************/
#define SRE_SCH_VMIMO0_CTRL_STOP_REG         (SRE_SCH_BASE + 0x0)       /* cell0 VMIMO运算终止控制寄存器。 */
#define SRE_SCH_VMIMO0_CTRL_START_REG        (SRE_SCH_BASE + 0x4)       /* cell0 VMIMO运算启动控制寄存器。 */
#define SRE_SCH_VMIMO0_ANT_NUM_REG           (SRE_SCH_BASE + 0x8)       /* cell0 VMIMO信道响应矩阵的天线数寄存器。 */
#define SRE_SCH_VMIMO0_USRU_NUM_REG          (SRE_SCH_BASE + 0xC)       /* cell0 VMIMO运算实际U用户数寄存器。 */
#define SRE_SCH_VMIMO0_USRV_NUM_REG          (SRE_SCH_BASE + 0x10)      /* cell0 VMIMO运算实际V用户数寄存器。 */
#define SRE_SCH_VMIMO0_NPWR_NUM_REG          (SRE_SCH_BASE + 0x14)      /* cell0 VMIMO运算噪声功率个数寄存器。 */
#define SRE_SCH_VMIMO0_NPWR_ADDR_REG         (SRE_SCH_BASE + 0x18)      /* cell0 VMIMO运算噪声功率在DDR中的首地址寄存器。 */
#define SRE_SCH_VMIMO0_USRINFO_ADDR_REG      (SRE_SCH_BASE + 0x1C)      /* cell0 VMIMO用户信息在DDR中的首地址寄存器。 */
#define SRE_SCH_VMIMO0_SINR_ADDR_REG         (SRE_SCH_BASE + 0x24)      /* cell0 VMIMO将SINR修正值写入DDR的首地址。 */
#define SRE_SCH_VMIMO0_USRPAIR_NUM_REG       (SRE_SCH_BASE + 0x28)      /* cell0 VMIMO UV用户对数 */
#define SRE_SCH_VMIMO0_RND_MD_REG            (SRE_SCH_BASE + 0x2C)      /* cell0 VMIMO运算结果舍入模式选择控制器 */
#define SRE_SCH_VMIMO0_SINR_AMPLFY_REG       (SRE_SCH_BASE + 0x30)      /* cell0 VMIMO SINR计算结果放大倍数的浮点数 */
#define SRE_SCH_VMIMO0_SINR_MINIFY_REG       (SRE_SCH_BASE + 0x34)      /* cell0 VMIMO SINR计算输入数据缩小倍数的倒数的浮点数 */
#define SRE_SCH_VMIMO0_ENDIAN_MD_REG         (SRE_SCH_BASE + 0x38)      /* cell0 VMIMO访问DDR大小端模式控制寄存器 */
#define SRE_SCH_VMIMO0_STAT_EN_REG           (SRE_SCH_BASE + 0x3C)      /* cell0 VMIMO运算引擎内部状态统计使能控制 */
#define SRE_SCH_VMIMO1_CTRL_STOP_REG         (SRE_SCH_BASE + 0x50)      /* cell1 VMIMO运算终止控制寄存器。 */
#define SRE_SCH_VMIMO1_CTRL_START_REG        (SRE_SCH_BASE + 0x54)      /* cell1 VMIMO运算启动控制寄存器。 */
#define SRE_SCH_VMIMO1_ANT_NUM_REG           (SRE_SCH_BASE + 0x58)      /* cell1 VMIMO信道响应矩阵的天线数寄存器。 */
#define SRE_SCH_VMIMO1_USRU_NUM_REG          (SRE_SCH_BASE + 0x5C)      /* cell1 VMIMO运算实际U用户数寄存器。 */
#define SRE_SCH_VMIMO1_USRV_NUM_REG          (SRE_SCH_BASE + 0x60)      /* cell1 VMIMO运算实际V用户数寄存器。 */
#define SRE_SCH_VMIMO1_NPWR_NUM_REG          (SRE_SCH_BASE + 0x64)      /* cell1 VMIMO运算噪声功率个数寄存器。 */
#define SRE_SCH_VMIMO1_NPWR_ADDR_REG         (SRE_SCH_BASE + 0x68)      /* cell1 VMIMO运算噪声功率在DDR中的首地址寄存器。 */
#define SRE_SCH_VMIMO1_USRINFO_ADDR_REG      (SRE_SCH_BASE + 0x6C)      /* cell1 VMIMO用户信息在DDR中的首地址寄存器。 */
#define SRE_SCH_VMIMO1_SINR_ADDR_REG         (SRE_SCH_BASE + 0x74)      /* cell1 VMIMO将SINR修正值写入DDR的首地址。 */
#define SRE_SCH_VMIMO1_USRPAIR_NUM_REG       (SRE_SCH_BASE + 0x78)      /* cell1 VMIMO UV用户对数 */
#define SRE_SCH_VMIMO1_RND_MD_REG            (SRE_SCH_BASE + 0x7C)      /* cell1 VMIMO运算结果舍入模式选择控制器 */
#define SRE_SCH_VMIMO1_SINR_AMPLFY_REG       (SRE_SCH_BASE + 0x80)      /* cell1 VMIMO SINR计算结果放大倍数的浮点数 */
#define SRE_SCH_VMIMO1_SINR_MINIFY_REG       (SRE_SCH_BASE + 0x84)      /* cell1 VMIMO SINR计算输入数据缩小倍数的倒数的浮点数 */
#define SRE_SCH_VMIMO1_ENDIAN_MD_REG         (SRE_SCH_BASE + 0x88)      /* cell1 VMIMO访问DDR大小端模式控制寄存器 */
#define SRE_SCH_VMIMO1_STAT_EN_REG           (SRE_SCH_BASE + 0x8C)      /* cell1 VMIM运算引擎内部状态统计使能控制 */
#define SRE_SCH_VMIMO2_CTRL_STOP_REG         (SRE_SCH_BASE + 0xA0)      /* cell2 VMIMO运算终止控制寄存器。 */
#define SRE_SCH_VMIMO2_CTRL_START_REG        (SRE_SCH_BASE + 0xA4)      /* cell2 VMIMO运算启动控制寄存器。 */
#define SRE_SCH_VMIMO2_ANT_NUM_REG           (SRE_SCH_BASE + 0xA8)      /* cell2 VMIMO信道响应矩阵的天线数寄存器。 */
#define SRE_SCH_VMIMO2_USRU_NUM_REG          (SRE_SCH_BASE + 0xAC)      /* cell2 VMIMO运算实际U用户数寄存器。 */
#define SRE_SCH_VMIMO2_USRV_NUM_REG          (SRE_SCH_BASE + 0xB0)      /* cell2 VMIMO运算实际V用户数寄存器。 */
#define SRE_SCH_VMIMO2_NPWR_NUM_REG          (SRE_SCH_BASE + 0xB4)      /* cell2 VMIMO运算噪声功率个数寄存器。 */
#define SRE_SCH_VMIMO2_NPWR_ADDR_REG         (SRE_SCH_BASE + 0xB8)      /* cell2 VMIMO运算噪声功率在DDR中的首地址寄存器。 */
#define SRE_SCH_VMIMO2_USRINFO_ADDR_REG      (SRE_SCH_BASE + 0xBC)      /* cell2 VMIMO用户信息在DDR中的首地址寄存器。 */
#define SRE_SCH_VMIMO2_SINR_ADDR_REG         (SRE_SCH_BASE + 0xC4)      /* cell2 VMIMO将SINR修正值写入DDR的首地址。 */
#define SRE_SCH_VMIMO2_USRPAIR_NUM_REG       (SRE_SCH_BASE + 0xC8)      /* cell2 VMIMO UV用户对数 */
#define SRE_SCH_VMIMO2_RND_MD_REG            (SRE_SCH_BASE + 0xCC)      /* cell2 VMIMO运算结果舍入模式选择控制器 */
#define SRE_SCH_VMIMO2_SINR_AMPLFY_REG       (SRE_SCH_BASE + 0xD0)      /* cell2 VMIMO SINR计算结果放大倍数的浮点数 */
#define SRE_SCH_VMIMO2_SINR_MINIFY_REG       (SRE_SCH_BASE + 0xD4)      /* cell2 VMIMO SINR计算输入数据缩小倍数的倒数的浮点数 */
#define SRE_SCH_VMIMO2_ENDIAN_MD_REG         (SRE_SCH_BASE + 0xD8)      /* cell2 VMIMO访问DDR大小端模式控制寄存器 */
#define SRE_SCH_VMIMO2_STAT_EN_REG           (SRE_SCH_BASE + 0xDC)      /* cell2 VMIM运算引擎内部状态统计使能控制 */
#define SRE_SCH_VMIMO3_CTRL_STOP_REG         (SRE_SCH_BASE + 0xF0)      /* cell3 VMIMO运算终止控制寄存器。 */
#define SRE_SCH_VMIMO3_CTRL_START_REG        (SRE_SCH_BASE + 0xF4)      /* cell3 VMIMO运算启动控制寄存器。 */
#define SRE_SCH_VMIMO3_ANT_NUM_REG           (SRE_SCH_BASE + 0xF8)      /* cell3 VMIMO信道响应矩阵的天线数寄存器。 */
#define SRE_SCH_VMIMO3_USRU_NUM_REG          (SRE_SCH_BASE + 0xFC)      /* cell3 VMIMO运算实际U用户数寄存器。 */
#define SRE_SCH_VMIMO3_USRV_NUM_REG          (SRE_SCH_BASE + 0x100)     /* cell3 VMIMO运算实际V用户数寄存器。 */
#define SRE_SCH_VMIMO3_NPWR_NUM_REG          (SRE_SCH_BASE + 0x104)     /* cell3 VMIMO运算噪声功率个数寄存器。 */
#define SRE_SCH_VMIMO3_NPWR_ADDR_REG         (SRE_SCH_BASE + 0x108)     /* cell3 VMIMO运算噪声功率在DDR中的首地址寄存器。 */
#define SRE_SCH_VMIMO3_USRINFO_ADDR_REG      (SRE_SCH_BASE + 0x10C)     /* cell3 VMIMO用户信息在DDR中的首地址寄存器。 */
#define SRE_SCH_VMIMO3_SINR_ADDR_REG         (SRE_SCH_BASE + 0x114)     /* cell3 VMIMO将SINR修正值写入DDR的首地址。 */
#define SRE_SCH_VMIMO3_USRPAIR_NUM_REG       (SRE_SCH_BASE + 0x118)     /* cell3 VMIMO UV用户对数 */
#define SRE_SCH_VMIMO3_RND_MD_REG            (SRE_SCH_BASE + 0x11C)     /* cell3 VMIMO运算结果舍入模式选择控制器 */
#define SRE_SCH_VMIMO3_SINR_AMPLFY_REG       (SRE_SCH_BASE + 0x120)     /* cell3 VMIMO SINR计算结果放大倍数的浮点数 */
#define SRE_SCH_VMIMO3_SINR_MINIFY_REG       (SRE_SCH_BASE + 0x124)     /* cell3 VMIMO SINR计算输入数据缩小倍数的倒数的浮点数 */
#define SRE_SCH_VMIMO3_ENDIAN_MD_REG         (SRE_SCH_BASE + 0x128)     /* cell3 VMIMO访问DDR大小端模式控制寄存器 */
#define SRE_SCH_VMIMO3_STAT_EN_REG           (SRE_SCH_BASE + 0x12C)     /* cell3 VMIMO运算引擎内部状态统计使能控制 */
#define SRE_SCH_VMIMO4_CTRL_STOP_REG         (SRE_SCH_BASE + 0x140)     /* cell4 VMIMO运算终止控制寄存器。 */
#define SRE_SCH_VMIMO4_CTRL_START_REG        (SRE_SCH_BASE + 0x144)     /* cell4 VMIMO运算启动控制寄存器。 */
#define SRE_SCH_VMIMO4_ANT_NUM_REG           (SRE_SCH_BASE + 0x148)     /* cell4 VMIMO信道响应矩阵的天线数寄存器。 */
#define SRE_SCH_VMIMO4_USRU_NUM_REG          (SRE_SCH_BASE + 0x14C)     /* cell4 VMIMO运算实际U用户数寄存器。 */
#define SRE_SCH_VMIMO4_USRV_NUM_REG          (SRE_SCH_BASE + 0x150)     /* cell4 VMIMO运算实际V用户数寄存器。 */
#define SRE_SCH_VMIMO4_NPWR_NUM_REG          (SRE_SCH_BASE + 0x154)     /* cell4 VMIMO运算噪声功率个数寄存器。 */
#define SRE_SCH_VMIMO4_NPWR_ADDR_REG         (SRE_SCH_BASE + 0x158)     /* cell4 VMIMO运算噪声功率在DDR中的首地址寄存器。 */
#define SRE_SCH_VMIMO4_USRINFO_ADDR_REG      (SRE_SCH_BASE + 0x15C)     /* cell4 VMIMO用户信息在DDR中的首地址寄存器。 */
#define SRE_SCH_VMIMO4_SINR_ADDR_REG         (SRE_SCH_BASE + 0x164)     /* cell4 VMIMO将SINR修正值写入DDR的首地址。 */
#define SRE_SCH_VMIMO4_USRPAIR_NUM_REG       (SRE_SCH_BASE + 0x168)     /* cell4 VMIMO UV用户对数 */
#define SRE_SCH_VMIMO4_RND_MD_REG            (SRE_SCH_BASE + 0x16C)     /* cell4 VMIMO运算结果舍入模式选择控制器 */
#define SRE_SCH_VMIMO4_SINR_AMPLFY_REG       (SRE_SCH_BASE + 0x170)     /* cell4 VMIMO SINR计算结果放大倍数的浮点数 */
#define SRE_SCH_VMIMO4_SINR_MINIFY_REG       (SRE_SCH_BASE + 0x174)     /* cell4 VMIMO SINR计算输入数据缩小倍数的倒数的浮点数 */
#define SRE_SCH_VMIMO4_ENDIAN_MD_REG         (SRE_SCH_BASE + 0x178)     /* cell4 VMIMO访问DDR大小端模式控制寄存器 */
#define SRE_SCH_VMIMO4_STAT_EN_REG           (SRE_SCH_BASE + 0x17C)     /* cell4 VMIMO运算引擎内部状态统计使能控制 */
#define SRE_SCH_VMIMO5_CTRL_STOP_REG         (SRE_SCH_BASE + 0x190)     /* cell5 VMIMO运算终止控制寄存器。 */
#define SRE_SCH_VMIMO5_CTRL_START_REG        (SRE_SCH_BASE + 0x194)     /* cell5 VMIMO运算启动控制寄存器。 */
#define SRE_SCH_VMIMO5_ANT_NUM_REG           (SRE_SCH_BASE + 0x198)     /* cell5 VMIMO信道响应矩阵的天线数寄存器。 */
#define SRE_SCH_VMIMO5_USRU_NUM_REG          (SRE_SCH_BASE + 0x19C)     /* cell5 VMIMO运算实际U用户数寄存器。 */
#define SRE_SCH_VMIMO5_USRV_NUM_REG          (SRE_SCH_BASE + 0x1A0)     /* cell5 VMIMO运算实际V用户数寄存器。 */
#define SRE_SCH_VMIMO5_NPWR_NUM_REG          (SRE_SCH_BASE + 0x1A4)     /* cell5 VMIMO运算噪声功率个数寄存器。 */
#define SRE_SCH_VMIMO5_NPWR_ADDR_REG         (SRE_SCH_BASE + 0x1A8)     /* cell5 VMIMO运算噪声功率在DDR中的首地址寄存器。 */
#define SRE_SCH_VMIMO5_USRINFO_ADDR_REG      (SRE_SCH_BASE + 0x1AC)     /* cell5 VMIMO用户信息在DDR中的首地址寄存器。 */
#define SRE_SCH_VMIMO5_SINR_ADDR_REG         (SRE_SCH_BASE + 0x1B4)     /* cell5 VMIMO将SINR修正值写入DDR的首地址。 */
#define SRE_SCH_VMIMO5_USRPAIR_NUM_REG       (SRE_SCH_BASE + 0x1B8)     /* cell5 VMIMO UV用户对数 */
#define SRE_SCH_VMIMO5_RND_MD_REG            (SRE_SCH_BASE + 0x1BC)     /* cell5 VMIMO运算结果舍入模式选择控制器 */
#define SRE_SCH_VMIMO5_SINR_AMPLFY_REG       (SRE_SCH_BASE + 0x1C0)     /* cell5 VMIMO SINR计算结果放大倍数的浮点数 */
#define SRE_SCH_VMIMO5_SINR_MINIFY_REG       (SRE_SCH_BASE + 0x1C4)     /* cell5 VMIMO SINR计算输入数据缩小倍数的倒数的浮点数 */
#define SRE_SCH_VMIMO5_ENDIAN_MD_REG         (SRE_SCH_BASE + 0x1C8)     /* cell5 VMIMO访问DDR大小端模式控制寄存器 */
#define SRE_SCH_VMIMO5_STAT_EN_REG           (SRE_SCH_BASE + 0x1CC)     /* cell5 VMIMO运算引擎内部状态统计使能控制 */
#define SRE_SCH_SCH_AXI_TRACE_ENA_REG        (SRE_SCH_BASE + 0x1E0)     /* SCH AXI性能统计使能控制 */
#define SRE_SCH_SCH_VMID_REG                 (SRE_SCH_BASE + 0x1E4)     /* SCH VMID配置寄存器 */
#define SRE_SCH_SCH_ARUSR_M_CTRL_REG         (SRE_SCH_BASE + 0x1E8)     /* SCH AXI读接口USER信息配置寄存器 */
#define SRE_SCH_SCH_AWUSR_M_CTRL_REG         (SRE_SCH_BASE + 0x1EC)     /* SCH AXI写接口USER信息配置寄存器 */
#define SRE_SCH_SCH_DYN_CLK_GT_MSK_REG       (SRE_SCH_BASE + 0x1F0)     /* SCH动态时钟门控屏蔽寄存器 */
#define SRE_SCH_SCH_AXI_STAT_CLR_REG         (SRE_SCH_BASE + 0x1F4)     /* SCH AXI性能统计清零控制寄存器 */
#define SRE_SCH_SCH_RFS_SP_CFG_REG           (SRE_SCH_BASE + 0x1F8)     /* SCH内部Artisan Memory时序调整控制寄存器 */
#define SRE_SCH_VMIMO0_INTMSK_REG            (SRE_SCH_BASE + 0x200)     /* cell0 VMIMO 中断屏蔽态寄存器。 */
#define SRE_SCH_VMIMO0_RINT_REG              (SRE_SCH_BASE + 0x204)     /* cell0 VMIMO 原始中断寄存器。 */
#define SRE_SCH_VMIMO0_INTSTS_REG            (SRE_SCH_BASE + 0x208)     /* cell0 VMIMO 中断状态寄存器。 */
#define SRE_SCH_VMIMO1_INTMSK_REG            (SRE_SCH_BASE + 0x210)     /* cell1 VMIMO 中断屏蔽寄存器。 */
#define SRE_SCH_VMIMO1_RINT_REG              (SRE_SCH_BASE + 0x214)     /* cell1 VMIMO 原始中断寄存器。 */
#define SRE_SCH_VMIMO1_INTSTS_REG            (SRE_SCH_BASE + 0x218)     /* cell1 VMIMO 中断状态寄存器。 */
#define SRE_SCH_VMIMO2_INTMSK_REG            (SRE_SCH_BASE + 0x220)     /* cell2 VMIMO 中屏蔽态寄存器。 */
#define SRE_SCH_VMIMO2_RINT_REG              (SRE_SCH_BASE + 0x224)     /* cell2 VMIMO 原始中断寄存器。 */
#define SRE_SCH_VMIMO2_INTSTS_REG            (SRE_SCH_BASE + 0x228)     /* cell2 VMIMO 中断状态寄存器。 */
#define SRE_SCH_VMIMO3_INTMSK_REG            (SRE_SCH_BASE + 0x230)     /* cell3 VMIMO 中断屏蔽态寄存器。 */
#define SRE_SCH_VMIMO3_RINT_REG              (SRE_SCH_BASE + 0x234)     /* cell3 VMIMO 原始中断寄存器。 */
#define SRE_SCH_VMIMO3_INTSTS_REG            (SRE_SCH_BASE + 0x238)     /* cell3 VMIMO 中断状态寄存器。 */
#define SRE_SCH_VMIMO4_INTMSK_REG            (SRE_SCH_BASE + 0x240)     /* cell4 VMIMO 中断屏蔽态寄存器。 */
#define SRE_SCH_VMIMO4_RINT_REG              (SRE_SCH_BASE + 0x244)     /* cell4 VMIMO 原始中断寄存器。 */
#define SRE_SCH_VMIMO4_INTSTS_REG            (SRE_SCH_BASE + 0x248)     /* cell4 VMIMO 中断状态寄存器。 */
#define SRE_SCH_VMIMO5_INTMSK_REG            (SRE_SCH_BASE + 0x250)     /* cell5 VMIMO 中断屏蔽态寄存器。 */
#define SRE_SCH_VMIMO5_RINT_REG              (SRE_SCH_BASE + 0x254)     /* cell5 VMIMO 原始中断寄存器。 */
#define SRE_SCH_VMIMO5_INTSTS_REG            (SRE_SCH_BASE + 0x258)     /* cell5 VMIMO 中断状态寄存器。 */
#define SRE_SCH_VMIMO0_STS_REG               (SRE_SCH_BASE + 0x300)     /* cell0 VMIMO运算的状态寄存器。 */
#define SRE_SCH_VMIMO0_RUNTIME_CNT_REG       (SRE_SCH_BASE + 0x304)     /* cell0 VMIMO运行时钟统计 */
#define SRE_SCH_VMIMO0_ACTIVE_CNT_REG        (SRE_SCH_BASE + 0x308)     /* cell0 VMIMO进行有效计算的时钟统计 */
#define SRE_SCH_VMIMO0_ARFSM_STS_REG         (SRE_SCH_BASE + 0x30C)     /* cell0 VMIMO产生读DDR的AR的状态机的状态输出 */
#define SRE_SCH_VMIMO0_ARFSM_CNT_REG         (SRE_SCH_BASE + 0x310)     /* cell0 VMIMO产生读DDR的AR的状态机跳转最大延时统计 */
#define SRE_SCH_VMIMO0_FNSHED_RB_CNT_REG     (SRE_SCH_BASE + 0x314)     /* cell0 VMIMO计算完成的RB数目统计 */
#define SRE_SCH_VMIMO0_FNSHED_USRPAIR_CNT_REG  (SRE_SCH_BASE + 0x318)     /* cell0 VMIMO计算完成的用户对数目统计 */
#define SRE_SCH_VMIMO0_FNSHED_USRU_CNT_REG   (SRE_SCH_BASE + 0x31C)     /* cell0 VMIMO计算完成的U用户数目统计 */
#define SRE_SCH_VMIMO0_FNSHED_USRV_CNT_REG   (SRE_SCH_BASE + 0x320)     /* cell0 VMIMO计算完成的V用户数目统计 */
#define SRE_SCH_VMIMO0_ERR_ARADDR_REG        (SRE_SCH_BASE + 0x32C)     /* cell0 VMIMO产生ERROR响应的读地址请求中读地址 */
#define SRE_SCH_VMIMO0_ERR_AWADDR_REG        (SRE_SCH_BASE + 0x330)     /* cell0 VMIMO产生ERROR响应的写地址请求中写地址 */
#define SRE_SCH_VMIMO0_CURR_USRU_ID_REG      (SRE_SCH_BASE + 0x334)     /* cell0 VMIMO当前运行的U用户ID */
#define SRE_SCH_VMIMO0_CURR_USRV_ID_REG      (SRE_SCH_BASE + 0x338)     /* cell0 VMIMO当前运行的V用户ID */
#define SRE_SCH_VMIMO0_CURR_ERR_RBINFO_REG   (SRE_SCH_BASE + 0x33C)     /* cell0 VMIMO当前运行的发生RB配置错误的U用户的RB信息 */
#define SRE_SCH_VMIMO0_UNALIGNED_CHDADDR_CNT_REG  (SRE_SCH_BASE + 0x340)     /* cell0 VMIMO中信道响应矩阵的DDR首地址非cacheline对齐的个数统计 */
#define SRE_SCH_VMIMO0_UINFO_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x344)     /* cell0 VMIMO中U_INFO_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO0_NPWR_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x348)     /* cell0 VMIMO中NPWR_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO0_VCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x34C)     /* cell0 VMIMO中V_CHDT_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO0_UCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x350)     /* cell0 VMIMO中U_CHDT_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO0_CURR_RBERR_U_ID_REG   (SRE_SCH_BASE + 0x354)     /* cell0 VMIMO当前运行的发生RB配置错误的U用户ID */
#define SRE_SCH_VMIMO0_CAL_FAIL_REG          (SRE_SCH_BASE + 0x358)     /* cell0 VMIMO计算失败指示 */
#define SRE_SCH_VMIMO0_UINFO_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x35C)     /* cell0 VMIMO中U_INFO_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO0_NPWR_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x360)     /* cell0 VMIMO中NPWR_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO0_VCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x364)     /* cell0 VMIMO中V_CHDT_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO0_UCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x368)     /* cell0 VMIMO中U_CHDT_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO1_STS_REG               (SRE_SCH_BASE + 0x380)     /* cell1 VMIMO运算的状态寄存器。 */
#define SRE_SCH_VMIMO1_RUNTIME_CNT_REG       (SRE_SCH_BASE + 0x384)     /* cell1 VMIMO运行时钟统计 */
#define SRE_SCH_VMIMO1_ACTIVE_CNT_REG        (SRE_SCH_BASE + 0x388)     /* cell1 VMIMO进行有效计算的时钟统计 */
#define SRE_SCH_VMIMO1_ARFSM_STS_REG         (SRE_SCH_BASE + 0x38C)     /* cell1 VMIMO产生读DDR的AR的状态机的状态输出 */
#define SRE_SCH_VMIMO1_ARFSM_CNT_REG         (SRE_SCH_BASE + 0x390)     /* cell1 VMIMO产生读DDR的AR的状态机跳转最大延时统计 */
#define SRE_SCH_VMIMO1_FNSHED_RB_CNT_REG     (SRE_SCH_BASE + 0x394)     /* cell1 VMIMO计算完成的RB数目统计 */
#define SRE_SCH_VMIMO1_FNSHED_USRPAIR_CNT_REG  (SRE_SCH_BASE + 0x398)     /* cell1 VMIMO计算完成的用户对数目统计 */
#define SRE_SCH_VMIMO1_FNSHED_USRU_CNT_REG   (SRE_SCH_BASE + 0x39C)     /* cell1 VMIMO计算完成的U用户数目统计 */
#define SRE_SCH_VMIMO1_FNSHED_USRV_CNT_REG   (SRE_SCH_BASE + 0x3A0)     /* cell1 VMIMO计算完成的V用户数目统计 */
#define SRE_SCH_VMIMO1_ERR_ARADDR_REG        (SRE_SCH_BASE + 0x3AC)     /* cell1 VMIMO产生ERROR响应的读地址请求中读地址 */
#define SRE_SCH_VMIMO1_ERR_AWADDR_REG        (SRE_SCH_BASE + 0x3B0)     /* cell1 VMIMO产生ERROR响应的写地址请求中写地址 */
#define SRE_SCH_VMIMO1_CURR_USRU_ID_REG      (SRE_SCH_BASE + 0x3B4)     /* cell1 VMIMO当前运行的U用户ID */
#define SRE_SCH_VMIMO1_CURR_USRV_ID_REG      (SRE_SCH_BASE + 0x3B8)     /* cell1 VMIMO当前运行的V用户ID */
#define SRE_SCH_VMIMO1_CURR_ERR_RBINFO_REG   (SRE_SCH_BASE + 0x3BC)     /* cell1 VMIMO当前运行的发生RB配置错误的U用户的RB信息 */
#define SRE_SCH_VMIMO1_UNALIGNED_CHDADDR_CNT_REG  (SRE_SCH_BASE + 0x3C0)     /* cell1 VMIMO中信道响应矩阵的DDR首地址非cacheline对齐的个数统计 */
#define SRE_SCH_VMIMO1_UINFO_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x3C4)     /* cell1 VMIMO中U_INFO_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO1_NPWR_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x3C8)     /* cell1 VMIMO中NPWR_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO1_VCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x3CC)     /* cell1 VMIMO中V_CHDT_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO1_UCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x3D0)     /* cell1 VMIMO中U_CHDT_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO1_CURR_RBERR_U_ID_REG   (SRE_SCH_BASE + 0x3D4)     /* cell1 VMIMO当前运行的发生RB配置错误的U用户ID */
#define SRE_SCH_VMIMO1_CAL_FAIL_REG          (SRE_SCH_BASE + 0x3D8)     /* cell1 VMIMO计算失败指示 */
#define SRE_SCH_VMIMO1_UINFO_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x3DC)     /* cell1 VMIMO中U_INFO_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO1_NPWR_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x3E0)     /* cell1 VMIMO中NPWR_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO1_VCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x3E4)     /* cell1 VMIMO中V_CHDT_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO1_UCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x3E8)     /* cell1 VMIMO中U_CHDT_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO2_STS_REG               (SRE_SCH_BASE + 0x400)     /* cell2 VMIMO运算的状态寄存器。 */
#define SRE_SCH_VMIMO2_RUNTIME_CNT_REG       (SRE_SCH_BASE + 0x404)     /* cell2 VMIMO运行时钟统计 */
#define SRE_SCH_VMIMO2_ACTIVE_CNT_REG        (SRE_SCH_BASE + 0x408)     /* cell2 VMIMO进行有效计算的时钟统计 */
#define SRE_SCH_VMIMO2_ARFSM_STS_REG         (SRE_SCH_BASE + 0x40C)     /* cell2 VMIMO产生读DDR的AR的状态机的状态输出 */
#define SRE_SCH_VMIMO2_ARFSM_CNT_REG         (SRE_SCH_BASE + 0x410)     /* cell2 VMIMO产生读DDR的AR的状态机跳转最大延时统计 */
#define SRE_SCH_VMIMO2_FNSHED_RB_CNT_REG     (SRE_SCH_BASE + 0x414)     /* cell2 VMIMO计算完成的RB数目统计 */
#define SRE_SCH_VMIMO2_FNSHED_USRPAIR_CNT_REG  (SRE_SCH_BASE + 0x418)     /* cell2 VMIMO计算完成的用户对数目统计 */
#define SRE_SCH_VMIMO2_FNSHED_USRU_CNT_REG   (SRE_SCH_BASE + 0x41C)     /* cell2 VMIMO计算完成的U用户数目统计 */
#define SRE_SCH_VMIMO2_FNSHED_USRV_CNT_REG   (SRE_SCH_BASE + 0x420)     /* cell2 VMIMO计算完成的V用户数目统计 */
#define SRE_SCH_VMIMO2_ERR_ARADDR_REG        (SRE_SCH_BASE + 0x42C)     /* cell2 VMIMO产生ERROR响应的读地址请求中读地址 */
#define SRE_SCH_VMIMO2_ERR_AWADDR_REG        (SRE_SCH_BASE + 0x430)     /* cell2 VMIMO产生ERROR响应的写地址请求中写地址 */
#define SRE_SCH_VMIMO2_CURR_USRU_ID_REG      (SRE_SCH_BASE + 0x434)     /* cell2 VMIMO当前运行的U用户ID */
#define SRE_SCH_VMIMO2_CURR_USRV_ID_REG      (SRE_SCH_BASE + 0x438)     /* cell2 VMIMO当前运行的V用户ID */
#define SRE_SCH_VMIMO2_CURR_ERR_RBINFO_REG   (SRE_SCH_BASE + 0x43C)     /* cell2 VMIMO当前运行的发生RB配置错误的U用户的RB信息 */
#define SRE_SCH_VMIMO2_UNALIGNED_CHDADDR_CNT_REG  (SRE_SCH_BASE + 0x440)     /* cell2 VMIMO中信道响应矩阵的DDR首地址非cacheline对齐的个数统计 */
#define SRE_SCH_VMIMO2_UINFO_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x444)     /* cell2 VMIMO中U_INFO_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO2_NPWR_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x448)     /* cell2 VMIMO中NPWR_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO2_VCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x44C)     /* cell2 VMIMO中V_CHDT_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO2_UCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x450)     /* cell2 VMIMO中U_CHDT_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO2_CURR_RBERR_U_ID_REG   (SRE_SCH_BASE + 0x454)     /* cell2 VMIMO当前运行的发生RB配置错误的U用户ID */
#define SRE_SCH_VMIMO2_CAL_FAIL_REG          (SRE_SCH_BASE + 0x458)     /* cell2 VMIMO计算失败指示 */
#define SRE_SCH_VMIMO2_UINFO_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x45C)     /* cell2 VMIMO中U_INFO_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO2_NPWR_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x460)     /* cell2 VMIMO中NPWR_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO2_VCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x464)     /* cell2 VMIMO中V_CHDT_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO2_UCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x468)     /* cell2 VMIMO中U_CHDT_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO3_STS_REG               (SRE_SCH_BASE + 0x480)     /* cell3 VMIMO运算的状态寄存器。 */
#define SRE_SCH_VMIMO3_RUNTIME_CNT_REG       (SRE_SCH_BASE + 0x484)     /* cell3 VMIMO运行时钟统计 */
#define SRE_SCH_VMIMO3_ACTIVE_CNT_REG        (SRE_SCH_BASE + 0x488)     /* cell3 VMIMO进行有效计算的时钟统计 */
#define SRE_SCH_VMIMO3_ARFSM_STS_REG         (SRE_SCH_BASE + 0x48C)     /* cell3 VMIMO产生读DDR的AR的状态机的状态输出 */
#define SRE_SCH_VMIMO3_ARFSM_CNT_REG         (SRE_SCH_BASE + 0x490)     /* cell3 VMIMO产生读DDR的AR的状态机跳转最大延时统计 */
#define SRE_SCH_VMIMO3_FNSHED_RB_CNT_REG     (SRE_SCH_BASE + 0x494)     /* cell3 VMIMO计算完成的RB数目统计 */
#define SRE_SCH_VMIMO3_FNSHED_USRPAIR_CNT_REG  (SRE_SCH_BASE + 0x498)     /* cell3 VMIMO计算完成的用户对数目统计 */
#define SRE_SCH_VMIMO3_FNSHED_USRU_CNT_REG   (SRE_SCH_BASE + 0x49C)     /* cell3 VMIMO计算完成的U用户数目统计 */
#define SRE_SCH_VMIMO3_FNSHED_USRV_CNT_REG   (SRE_SCH_BASE + 0x4A0)     /* cell3 VMIMO计算完成的V用户数目统计 */
#define SRE_SCH_VMIMO3_ERR_ARADDR_REG        (SRE_SCH_BASE + 0x4AC)     /* cell3 VMIMO产生ERROR响应的读地址请求中读地址 */
#define SRE_SCH_VMIMO3_ERR_AWADDR_REG        (SRE_SCH_BASE + 0x4B0)     /* cell3 VMIMO产生ERROR响应的写地址请求中写地址 */
#define SRE_SCH_VMIMO3_CURR_USRU_ID_REG      (SRE_SCH_BASE + 0x4B4)     /* cell3 VMIMO当前运行的U用户ID */
#define SRE_SCH_VMIMO3_CURR_USRV_ID_REG      (SRE_SCH_BASE + 0x4B8)     /* cell3 VMIMO当前运行的V用户ID */
#define SRE_SCH_VMIMO3_CURR_ERR_RBINFO_REG   (SRE_SCH_BASE + 0x4BC)     /* cell3 VMIMO当前运行的发生RB配置错误的U用户的RB信息 */
#define SRE_SCH_VMIMO3_UNALIGNED_CHDADDR_CNT_REG  (SRE_SCH_BASE + 0x4C0)     /* cell3 VMIMO中信道响应矩阵的DDR首地址非cacheline对齐的个数统计 */
#define SRE_SCH_VMIMO3_UINFO_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x4C4)     /* cell3 VMIMO中U_INFO_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO3_NPWR_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x4C8)     /* cell3 VMIMO中NPWR_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO3_VCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x4CC)     /* cell3 VMIMO中V_CHDT_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO3_UCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x4D0)     /* cell3 VMIMO中U_CHDT_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO3_CURR_RBERR_U_ID_REG   (SRE_SCH_BASE + 0x4D4)     /* cell3 VMIMO当前运行的发生RB配置错误的U用户ID */
#define SRE_SCH_VMIMO3_CAL_FAIL_REG          (SRE_SCH_BASE + 0x4D8)     /* cell3 VMIMO计算失败指示 */
#define SRE_SCH_VMIMO3_UINFO_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x4DC)     /* cell3 VMIMO中U_INFO_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO3_NPWR_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x4E0)     /* cell3 VMIMO中NPWR_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO3_VCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x4E4)     /* cell3 VMIMO中V_CHDT_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO3_UCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x4E8)     /* cell3 VMIMO中U_CHDT_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO4_STS_REG               (SRE_SCH_BASE + 0x500)     /* cell4 VMIMO运算的状态寄存器。 */
#define SRE_SCH_VMIMO4_RUNTIME_CNT_REG       (SRE_SCH_BASE + 0x504)     /* cell4 VMIMO运行时钟统计 */
#define SRE_SCH_VMIMO4_ACTIVE_CNT_REG        (SRE_SCH_BASE + 0x508)     /* cell4 VMIMO进行有效计算的时钟统计 */
#define SRE_SCH_VMIMO4_ARFSM_STS_REG         (SRE_SCH_BASE + 0x50C)     /* cell4 VMIMO产生读DDR的AR的状态机的状态输出 */
#define SRE_SCH_VMIMO4_ARFSM_CNT_REG         (SRE_SCH_BASE + 0x510)     /* cell4 VMIMO产生读DDR的AR的状态机跳转最大延时统计 */
#define SRE_SCH_VMIMO4_FNSHED_RB_CNT_REG     (SRE_SCH_BASE + 0x514)     /* cell4 VMIMO计算完成的RB数目统计 */
#define SRE_SCH_VMIMO4_FNSHED_USRPAIR_CNT_REG  (SRE_SCH_BASE + 0x518)     /* cell4 VMIMO计算完成的用户对数目统计 */
#define SRE_SCH_VMIMO4_FNSHED_USRU_CNT_REG   (SRE_SCH_BASE + 0x51C)     /* cell4 VMIMO计算完成的U用户数目统计 */
#define SRE_SCH_VMIMO4_FNSHED_USRV_CNT_REG   (SRE_SCH_BASE + 0x520)     /* cell4 VMIMO计算完成的V用户数目统计 */
#define SRE_SCH_VMIMO4_ERR_ARADDR_REG        (SRE_SCH_BASE + 0x52C)     /* cell4 VMIMO产生ERROR响应的读地址请求中读地址 */
#define SRE_SCH_VMIMO4_ERR_AWADDR_REG        (SRE_SCH_BASE + 0x530)     /* cell4 VMIMO产生ERROR响应的写地址请求中写地址 */
#define SRE_SCH_VMIMO4_CURR_USRU_ID_REG      (SRE_SCH_BASE + 0x534)     /* cell4 VMIMO当前运行的U用户ID */
#define SRE_SCH_VMIMO4_CURR_USRV_ID_REG      (SRE_SCH_BASE + 0x538)     /* cell4 VMIMO当前运行的V用户ID */
#define SRE_SCH_VMIMO4_CURR_ERR_RBINFO_REG   (SRE_SCH_BASE + 0x53C)     /* cell4 VMIMO当前运行的发生RB配置错误的U用户的RB信息 */
#define SRE_SCH_VMIMO4_UNALIGNED_CHDADDR_CNT_REG  (SRE_SCH_BASE + 0x540)     /* cell4 VMIMO中信道响应矩阵的DDR首地址非cacheline对齐的个数统计 */
#define SRE_SCH_VMIMO4_UINFO_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x544)     /* cell4 VMIMO中U_INFO_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO4_NPWR_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x548)     /* cell4 VMIMO中NPWR_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO4_VCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x54C)     /* cell4 VMIMO中V_CHDT_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO4_UCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x550)     /* cell4 VMIMO中U_CHDT_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO4_CURR_RBERR_U_ID_REG   (SRE_SCH_BASE + 0x554)     /* cell4 VMIMO当前运行的发生RB配置错误的U用户ID */
#define SRE_SCH_VMIMO4_CAL_FAIL_REG          (SRE_SCH_BASE + 0x558)     /* cell4 VMIMO计算失败指示 */
#define SRE_SCH_VMIMO4_UINFO_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x55C)     /* cell4 VMIMO中U_INFO_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO4_NPWR_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x560)     /* cell4 VMIMO中NPWR_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO4_VCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x564)     /* cell4 VMIMO中V_CHDT_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO4_UCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x568)     /* cell4 VMIMO中U_CHDT_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO5_STS_REG               (SRE_SCH_BASE + 0x580)     /* cell5 VMIMO运算的状态寄存器。 */
#define SRE_SCH_VMIMO5_RUNTIME_CNT_REG       (SRE_SCH_BASE + 0x584)     /* cell5 VMIMO运行时钟统计 */
#define SRE_SCH_VMIMO5_ACTIVE_CNT_REG        (SRE_SCH_BASE + 0x588)     /* cell5 VMIMO进行有效计算的时钟统计 */
#define SRE_SCH_VMIMO5_ARFSM_STS_REG         (SRE_SCH_BASE + 0x58C)     /* cell5 VMIMO产生读DDR的AR的状态机的状态输出 */
#define SRE_SCH_VMIMO5_ARFSM_CNT_REG         (SRE_SCH_BASE + 0x590)     /* cell5 VMIMO产生读DDR的AR的状态机跳转最大延时统计 */
#define SRE_SCH_VMIMO5_FNSHED_RB_CNT_REG     (SRE_SCH_BASE + 0x594)     /* cell5 VMIMO计算完成的RB数目统计 */
#define SRE_SCH_VMIMO5_FNSHED_USRPAIR_CNT_REG  (SRE_SCH_BASE + 0x598)     /* cell5 VMIMO计算完成的用户对数目统计 */
#define SRE_SCH_VMIMO5_FNSHED_USRU_CNT_REG   (SRE_SCH_BASE + 0x59C)     /* cell5 VMIMO计算完成的U用户数目统计 */
#define SRE_SCH_VMIMO5_FNSHED_USRV_CNT_REG   (SRE_SCH_BASE + 0x5A0)     /* cell5 VMIMO计算完成的V用户数目统计 */
#define SRE_SCH_VMIMO5_ERR_ARADDR_REG        (SRE_SCH_BASE + 0x5AC)     /* cell5 VMIMO产生ERROR响应的读地址请求中读地址 */
#define SRE_SCH_VMIMO5_ERR_AWADDR_REG        (SRE_SCH_BASE + 0x5B0)     /* cell5 VMIMO产生ERROR响应的写地址请求中写地址 */
#define SRE_SCH_VMIMO5_CURR_USRU_ID_REG      (SRE_SCH_BASE + 0x5B4)     /* cell5 VMIMO当前运行的U用户ID */
#define SRE_SCH_VMIMO5_CURR_USRV_ID_REG      (SRE_SCH_BASE + 0x5B8)     /* cell5 VMIMO当前运行的V用户ID */
#define SRE_SCH_VMIMO5_CURR_ERR_RBINFO_REG   (SRE_SCH_BASE + 0x5BC)     /* cell5 VMIMO当前运行的发生RB配置错误的U用户的RB信息 */
#define SRE_SCH_VMIMO5_UNALIGNED_CHDADDR_CNT_REG  (SRE_SCH_BASE + 0x5C0)     /* cell5 VMIMO中信道响应矩阵的DDR首地址非cacheline对齐的个数统计 */
#define SRE_SCH_VMIMO5_UINFO_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x5C4)     /* cell5 VMIMO中U_INFO_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO5_NPWR_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x5C8)     /* cell5 VMIMO中NPWR_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO5_VCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x5CC)     /* cell5 VMIMO中V_CHDT_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO5_UCHD_SRAM_ERR_CNT_REG  (SRE_SCH_BASE + 0x5D0)     /* cell5 VMIMO中U_CHDT_SRAM奇偶校验错误个数统计 */
#define SRE_SCH_VMIMO5_CURR_RBERR_U_ID_REG   (SRE_SCH_BASE + 0x5D4)     /* cell5 VMIMO当前运行的发生RB配置错误的U用户ID */
#define SRE_SCH_VMIMO5_CAL_FAIL_REG          (SRE_SCH_BASE + 0x5D8)     /* cell5 VMIMO计算失败指示 */
#define SRE_SCH_VMIMO5_UINFO_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x5DC)     /* cell5 VMIMO中U_INFO_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO5_NPWR_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x5E0)     /* cell5 VMIMO中NPWR_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO5_VCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x5E4)     /* cell5 VMIMO中V_CHDT_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_VMIMO5_UCHD_SRAM_ERR_ADDR_REG  (SRE_SCH_BASE + 0x5E8)     /* cell5 VMIMO中U_CHDT_SRAM第一次奇偶校验错误的地址 */
#define SRE_SCH_SCH_AXI_WR_LATENCY_AVG_STAT_REG  (SRE_SCH_BASE + 0x600)     /* SCH AXI总线写通道平均时延统计 */
#define SRE_SCH_SCH_AXI_RD_LATENCY_AVG_STAT_REG  (SRE_SCH_BASE + 0x604)     /* SCH AXI总线读通道平均时延统计 */
#define SRE_SCH_SCH_AXI_WR_LATENCY_MAX_STAT_REG  (SRE_SCH_BASE + 0x608)     /* SCH AXI总线写通道最大时延统计 */
#define SRE_SCH_SCH_AXI_RD_LATENCY_MAX_STAT_REG  (SRE_SCH_BASE + 0x60C)     /* SCH AXI总线读通道最大时延统计 */
#define SRE_SCH_SCH_AXI_WR_ACC_STAT_REG      (SRE_SCH_BASE + 0x610)     /* SCH AXI总线写通道发出的写命令次数统计 */
#define SRE_SCH_SCH_AXI_RD_ACC_STAT_REG      (SRE_SCH_BASE + 0x614)     /* SCH AXI总线读通道发出的读命令次数统计 */
#define SRE_SCH_SCH_AXI_RCHN0_OTSD_CNT_REG   (SRE_SCH_BASE + 0x618)     /* SCH AXI 读通道0 outstanding统计 */
#define SRE_SCH_SCH_AXI_RCHN1_OTSD_CNT_REG   (SRE_SCH_BASE + 0x61C)     /* SCH AXI 读通道1 outstanding统计 */
#define SRE_SCH_SCH_AXI_RCHN2_OTSD_CNT_REG   (SRE_SCH_BASE + 0x620)     /* SCH AXI 读通道2 outstanding统计 */
#define SRE_SCH_SCH_AXI_RCHN3_OTSD_CNT_REG   (SRE_SCH_BASE + 0x624)     /* SCH AXI 读通道3 outstanding统计 */
#define SRE_SCH_SCH_AXI_RCHN4_OTSD_CNT_REG   (SRE_SCH_BASE + 0x628)     /* SCH AXI 读通道4 outstanding统计 */
#define SRE_SCH_SCH_AXI_RCHN5_OTSD_CNT_REG   (SRE_SCH_BASE + 0x62C)     /* SCH AXI 读通道5 outstanding统计 */
#define SRE_SCH_SCH_AXI_WCHN0_OTSD_CNT_REG   (SRE_SCH_BASE + 0x630)     /* SCH AXI 写通道0 outstanding统计 */
#define SRE_SCH_SCH_AXI_WCHN1_OTSD_CNT_REG   (SRE_SCH_BASE + 0x634)     /* SCH AXI 写通道1 outstanding统计 */
#define SRE_SCH_SCH_AXI_WCHN2_OTSD_CNT_REG   (SRE_SCH_BASE + 0x638)     /* SCH AXI 写通道2 outstanding统计 */
#define SRE_SCH_SCH_AXI_WCHN3_OTSD_CNT_REG   (SRE_SCH_BASE + 0x63C)     /* SCH AXI 写通道3 outstanding统计 */
#define SRE_SCH_SCH_AXI_WCHN4_OTSD_CNT_REG   (SRE_SCH_BASE + 0x640)     /* SCH AXI 写通道4 outstanding统计 */
#define SRE_SCH_SCH_AXI_WCHN5_OTSD_CNT_REG   (SRE_SCH_BASE + 0x644)     /* SCH AXI 写通道5 outstanding统计 */
#define SRE_SCH_SCH_CFG_RSV0_REG             (SRE_SCH_BASE + 0x700)     /* SCH 配置保留寄存器0 */
#define SRE_SCH_SCH_CFG_RSV1_REG             (SRE_SCH_BASE + 0x704)     /* SCH 配置保留寄存器1 */
#define SRE_SCH_SCH_CFG_RSV2_REG             (SRE_SCH_BASE + 0x708)     /* SCH 配置保留寄存器2 */
#define SRE_SCH_SCH_STS_RSV0_REG             (SRE_SCH_BASE + 0x720)     /* SCH 状态保留寄存器0 */
#define SRE_SCH_SCH_STS_RSV1_REG             (SRE_SCH_BASE + 0x724)     /* SCH 状态保留寄存器1 */
#define SRE_SCH_SCH_STS_RSV2_REG             (SRE_SCH_BASE + 0x728)     /* SCH 状态保留寄存器2 */



/******************************************************************************/
/*                      PhosphorV600 SYSCTRL nManager 寄存器定义              */
/******************************************************************************/
#if 0         /* z00202052 */
#define SRE_SYS_REG_BASEADDR         (0x13e00000) /* SYSCTRL nManager的寄存器基地址 */
#else
#define SRE_SYS_REG_BASEADDR         (0xe3e00000) /* SYSCTRL nManager的寄存器基地址 */
#endif        /* z00202052 */
#define SRE_SYS_REG_A9_0_1_INT       (SRE_SYS_REG_BASEADDR + 0x0500) /* A9_0发送到A9_1的中断地址 */

#define SRE_SYS_PERCTRL6_REG         (SRE_SYS_REG_BASEADDR + 0x44)   /*外设控制寄存器6*/
#define SRE_SYS_PERCTRL7_REG         (SRE_SYS_REG_BASEADDR + 0x48)   /*外设控制寄存器7*/
#define SRE_SYS_PERCTRL8_REG         (SRE_SYS_REG_BASEADDR + 0x4C)   /*外设控制寄存器8*/
#define SRE_SYS_PERCTRL9_REG         (SRE_SYS_REG_BASEADDR + 0x50)   /*外设控制寄存器9*/
#define SRE_SYS_PERCTRL10_REG        (SRE_SYS_REG_BASEADDR + 0x54)   /*外设控制寄存器10*/
#define SRE_SYS_PERCTRL15_REG        (SRE_SYS_REG_BASEADDR + 0x68)   /*外设控制寄存器10*/

#define SRE_SYS_PERCTRL33_REG        (SRE_SYS_REG_BASEADDR + 0xB0)   /* 外设控制寄存器 33 */
#define SRE_SYS_PERCTRL34_REG        (SRE_SYS_REG_BASEADDR + 0xB4)   /* 外设控制寄存器 34 */
#define SRE_SYS_PERCTRL37_REG        (SRE_SYS_REG_BASEADDR + 0xC0)   /* 外设控制寄存器 37 */
#define SRE_SYS_PERCTRL38_REG        (SRE_SYS_REG_BASEADDR + 0xC4)   /* 外设控制寄存器 38 */
#define SRE_SYS_PERCTRL41_REG        (SRE_SYS_REG_BASEADDR + 0xD0)   /* 外设控制寄存器 41 */
#define SRE_SYS_PERCTRL42_REG        (SRE_SYS_REG_BASEADDR + 0xD4)   /* 外设控制寄存器 42 */
#define SRE_SYS_PERCTRL45_REG        (SRE_SYS_REG_BASEADDR + 0xE0)   /* 外设控制寄存器 45 */
#define SRE_SYS_PERCTRL46_REG        (SRE_SYS_REG_BASEADDR + 0xE4)   /* 外设控制寄存器 46 */

#define SRE_SYS_PERCTRL50_REG        (SRE_SYS_REG_BASEADDR + 0xF4)   /* 外设控制寄存器 50 */
#define SRE_SYS_PERCTRL51_REG        (SRE_SYS_REG_BASEADDR + 0xF8)   /* 外设控制寄存器 51 */
#define SRE_SYS_PERCTRL52_REG        (SRE_SYS_REG_BASEADDR + 0xFC)   /* 外设控制寄存器 52 */
#define SRE_SYS_PERCTRL69_REG        (SRE_SYS_REG_BASEADDR + 0x140)   /* 外设控制寄存器 69 */
#define SRE_SYS_EXTSTATUS1_REG       (SRE_SYS_REG_BASEADDR + 0x40C)   /* 扩展状态寄存器1 */
#define SRE_SYS_EXTSTATUS2_REG       (SRE_SYS_REG_BASEADDR + 0x410)   /* 扩展状态寄存器2 */
#define SRE_SYS_EXTSTATUS3_REG       (SRE_SYS_REG_BASEADDR + 0x414)   /* 扩展状态寄存器3 */

#define SRE_SYSSTAT6_REG             (SRE_SYS_REG_BASEADDR + 0x420)   /* 扩展系统状态寄存器6，SerDes 0 bist状态 */
#define SRE_SYSSTAT7_REG             (SRE_SYS_REG_BASEADDR + 0x424)   /* 扩展系统状态寄存器6，SerDes 1 bist状态 */

#define SRE_SYS_EXTSTATUS17_REG      (SRE_SYS_REG_BASEADDR + 0x44C)   /* 扩展状态寄存器17 */
#define SRE_SYS_DBGREQ_REG           (SRE_SYS_REG_BASEADDR + 0x5E0)   /* A0 DBG寄存器 */

#define SRE_SYS_SEC_RESET_REQ_REG    (SRE_SYS_REG_BASEADDR + 0x0708)  /* SEC软复位请求控制寄存器  */
#define SRE_SYS_SEC_RESET_DREQ_REG   (SRE_SYS_REG_BASEADDR + 0x070C)  /* SEC软复位去请求控制寄存器 */

#define SRE_SYS_HDCP_RESET_REQ_REG   (SRE_SYS_REG_BASEADDR + 0x0748)  /* hdcp软复位请求控制寄存器  */
#define SRE_SYS_HDCP_RESET_DREQ_REG  (SRE_SYS_REG_BASEADDR + 0x074C)  /* hdcp软复位去请求控制寄存器 */


/* BEGIN: Added by h00176630, 2012/6/9 */
#define SRE_SC_CTRL_REG                  (SRE_SYS_REG_BASEADDR + 0x0)       /* SC_CTRL为系统控制寄存器。 */
#define SRE_SC_SYSRST_REG                (SRE_SYS_REG_BASEADDR + 0x4)       /* SC_SYSSTAT为系统软复位寄存器。 */
#define SRE_SC_IMCTRL_REG                (SRE_SYS_REG_BASEADDR + 0x8)       /* SC_IMCTRL为中断模式控制寄存器（保留）。 */
#define SRE_SC_IMSTAT_REG                (SRE_SYS_REG_BASEADDR + 0xC)       /* SC_IMSTAT为中断模式状态寄存器（保留）。 */
#define SRE_SC_XTALCTRL_REG              (SRE_SYS_REG_BASEADDR + 0x10)      /* SC_XTALCTRL为晶振控制寄存器。 */
#define SRE_SC_PLLCTRL_REG               (SRE_SYS_REG_BASEADDR + 0x14)      /* SC_PLLCTRL为PLL控制寄存器。 */
#define SRE_SC_DBG_AUTH_CTRL_REG         (SRE_SYS_REG_BASEADDR + 0x20)      /* 调试模式安全等级授权控制。（注意：1，此寄存器空间必须是安全访问才能成功；2，默认均是打开调试模式，有漏洞，在正常工作时请初始化关闭调试功能） */
#define SRE_SC_PLLFCTRL0_REG             (SRE_SYS_REG_BASEADDR + 0x100)     /* SC_PLLFCTRL0为PLL0控制寄存器0。 */
#define SRE_SC_PLLFCTRL1_REG             (SRE_SYS_REG_BASEADDR + 0x104)     /* SC_PLLFCTRL1为PLL0控制寄存器1。 */
#define SRE_SC_PLLFCTRL2_REG             (SRE_SYS_REG_BASEADDR + 0x108)     /* SC_PLLFCTRL2为PLL1控制寄存器0。 */
#define SRE_SC_PLLFCTRL3_REG             (SRE_SYS_REG_BASEADDR + 0x10C)     /* SC_PLLFCTRL3为PLL1控制寄存器1。 */
#define SRE_SC_PLLFCTRL4_REG             (SRE_SYS_REG_BASEADDR + 0x110)     /* SC_PLLFCTRL4为PLL2控制寄存器0。 */
#define SRE_SC_PLLFCTRL5_REG             (SRE_SYS_REG_BASEADDR + 0x114)     /* SC_PLLFCTRL5为PLL2控制寄存器1。 */
#define SRE_SC_PLLFCTRL6_REG             (SRE_SYS_REG_BASEADDR + 0x118)     /* SC_PLLFCTRL6为PLL3控制寄存器0。 */
#define SRE_SC_PLLFCTRL7_REG             (SRE_SYS_REG_BASEADDR + 0x11C)     /* SC_PLLFCTRL7为PLL3控制寄存器1。 */
#define SRE_SC_PLLFCTRL8_REG             (SRE_SYS_REG_BASEADDR + 0x120)     /* SC_PLLFCTRL8为PLL4控制寄存器0。 */
#define SRE_SC_PLLFCTRL9_REG             (SRE_SYS_REG_BASEADDR + 0x124)     /* SC_PLLFCTRL9为PLL4控制寄存器1。 */
#define SRE_SC_PLL_CLK_BYPASS_REG        (SRE_SYS_REG_BASEADDR + 0x180)     /* PLL相关工作时钟选择 */
#define SRE_SC_CLK_SEL0_REG              (SRE_SYS_REG_BASEADDR + 0x188)     /* 处理器和系统互联时钟频率选择 */
#define SRE_SC_CLK_SEL1_REG              (SRE_SYS_REG_BASEADDR + 0x18C)     /* 网口MAC时钟频率选择 */
#define SRE_SC_CLK_SEL2_REG              (SRE_SYS_REG_BASEADDR + 0x190)     /* 硬件加速器工作时钟频率选择 */
#define SRE_SC_CLK_SEL3_REG              (SRE_SYS_REG_BASEADDR + 0x194)     /* 低速外设接口工作时钟选择 */
#define SRE_SC_TOP_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x200)     /* 顶层全局时钟使能控制 */
#define SRE_SC_TOP_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x204)     /* 顶层全局时钟关闭控制 */
#define SRE_SC_CPU_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x220)     /* 保留 */
#define SRE_SC_CPU_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x224)     /* 保留 */
#define SRE_SC_SERDES_CLK_EN_REG         (SRE_SYS_REG_BASEADDR + 0x280)     /* 保留 */
#define SRE_SC_SERDES_CLK_DIS_REG        (SRE_SYS_REG_BASEADDR + 0x284)     /* 保留 */
#define SRE_SC_GE_CLK_EN_REG             (SRE_SYS_REG_BASEADDR + 0x2A0)     /* GE时钟使能寄存器 */
#define SRE_SC_GE_CLK_DIS_REG            (SRE_SYS_REG_BASEADDR + 0x2A4)     /* GE时钟禁止寄存器 */
#define SRE_SC_XGE_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x2B0)     /* XGE时钟使能寄存器 */
#define SRE_SC_XGE_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x2B4)     /* XGE时钟禁止寄存器 */
#define SRE_SC_PCIE_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x2E0)     /* PCIE时钟使能寄存器 */
#define SRE_SC_PCIE_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x2E4)     /* PCIE时钟禁止寄存器 */
#define SRE_SC_SRIO_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x2F0)     /* SRIO时钟使能寄存器 */
#define SRE_SC_SRIO_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x2F4)     /* SRIO时钟禁止寄存器 */
#define SRE_SC_USB_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x300)     /* USB时钟使能寄存器 */
#define SRE_SC_USB_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x304)     /* USB时钟禁止寄存器 */
#define SRE_SC_SATA_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x310)     /* SATA时钟使能寄存器 */
#define SRE_SC_SATA_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x314)     /* SATA时钟禁止寄存器 */
#define SRE_SC_DDR_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x320)     /* DDR时钟使能寄存器 */
#define SRE_SC_DDR_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x324)     /* DDR时钟禁止寄存器 */
#define SRE_SC_MMC_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x330)     /* MMC时钟使能寄存器 */
#define SRE_SC_MMC_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x334)     /* MMC时钟禁止寄存器 */
#define SRE_SC_SFC_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x338)     /* SFC时钟使能寄存器 */
#define SRE_SC_SFC_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x33C)     /* SFC时钟禁止寄存器 */
#define SRE_SC_NANDC_CLK_EN_REG          (SRE_SYS_REG_BASEADDR + 0x340)     /* NANDC时钟使能寄存器 */
#define SRE_SC_NANDC_CLK_DIS_REG         (SRE_SYS_REG_BASEADDR + 0x344)     /* NANDC时钟禁止寄存器 */
#define SRE_SC_LOCALBUS_CLK_EN_REG       (SRE_SYS_REG_BASEADDR + 0x350)     /* LOCALBUS时钟使能寄存器 */
#define SRE_SC_LOCALBUS_CLK_DIS_REG      (SRE_SYS_REG_BASEADDR + 0x354)     /* LOCALBUS时钟禁止寄存器 */
#define SRE_SC_UART_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x380)     /* UART时钟使能寄存器 */
#define SRE_SC_UART_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x384)     /* UART时钟禁止寄存器 */
#define SRE_SC_I2C_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x388)     /* I2C时钟使能寄存器 */
#define SRE_SC_I2C_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x38C)     /* I2C时钟禁止寄存器 */
#define SRE_SC_MDIO_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x390)     /* MDIO时钟使能寄存器 */
#define SRE_SC_MDIO_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x394)     /* MDIO时钟禁止寄存器 */
#define SRE_SC_SPI_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x398)     /* SPI时钟使能寄存器 */
#define SRE_SC_SPI_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x39C)     /* SPI时钟禁止寄存器 */
#define SRE_SC_GPIO_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x3A0)     /* GPIO时钟使能寄存器 */
#define SRE_SC_GPIO_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x3A4)     /* GPIO时钟禁止寄存器 */
#define SRE_SC_TDM_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x3C0)     /* TDM时钟使能寄存器 */
#define SRE_SC_TDM_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x3C4)     /* TDM时钟禁止寄存器 */
#define SRE_SC_HDLC_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x3C8)     /* HDLC时钟使能寄存器 */
#define SRE_SC_HDLC_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x3CC)     /* HDLC时钟禁止寄存器 */
#define SRE_SC_BOOTROM_CLK_EN_REG        (SRE_SYS_REG_BASEADDR + 0x400)     /* BOOTROM时钟使能寄存器 */
#define SRE_SC_BOOTROM_CLK_DIS_REG       (SRE_SYS_REG_BASEADDR + 0x404)     /* BOOTROM时钟禁止寄存器 */
#define SRE_SC_SEC_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x408)     /* SEC时钟使能寄存器 */
#define SRE_SC_SEC_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x40C)     /* SEC时钟禁止寄存器 */
#define SRE_SC_POE_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x410)     /* POE时钟使能寄存器 */
#define SRE_SC_POE_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x414)     /* POE时钟禁止寄存器 */
#define SRE_SC_BMU_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x418)     /* BMU时钟使能寄存器 */
#define SRE_SC_BMU_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x41C)     /* BMU时钟禁止寄存器 */
#define SRE_SC_PPE_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x420)     /* PPE时钟使能寄存器 */
#define SRE_SC_PPE_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x424)     /* PPE时钟禁止寄存器 */
#define SRE_SC_NP_CLK_EN_REG             (SRE_SYS_REG_BASEADDR + 0x428)     /* SPPE时钟使能寄存器 */
#define SRE_SC_NP_CLK_DIS_REG            (SRE_SYS_REG_BASEADDR + 0x42C)     /* SPPE时钟禁止寄存器 */
#define SRE_SC_CRC_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x430)     /* CRC时钟使能寄存器 */
#define SRE_SC_CRC_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x434)     /* CRC时钟禁止寄存器 */
#define SRE_SC_DMAC_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x438)     /* DMAC时钟使能寄存器 */
#define SRE_SC_DMAC_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x43C)     /* DMAC时钟禁止寄存器 */
#define SRE_SC_ROHC_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x440)     /* ROHC时钟使能寄存器 */
#define SRE_SC_ROHC_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x444)     /* ROHC时钟禁止寄存器 */
#define SRE_SC_HDCP_CLK_EN_REG           (SRE_SYS_REG_BASEADDR + 0x448)     /* HDCP时钟使能寄存器 */
#define SRE_SC_HDCP_CLK_DIS_REG          (SRE_SYS_REG_BASEADDR + 0x44C)     /* HDCP时钟禁止寄存器 */
#define SRE_SC_PDM_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x450)     /* PDM时钟使能寄存器 */
#define SRE_SC_PDM_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x454)     /* PDM时钟禁止寄存器 */
#define SRE_SC_TRING_CLK_EN_REG          (SRE_SYS_REG_BASEADDR + 0x458)     /* TRING时钟使能寄存器 */
#define SRE_SC_TRING_CLK_DIS_REG         (SRE_SYS_REG_BASEADDR + 0x45C)     /* TRING时钟禁止寄存器 */
#define SRE_SC_RNG_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x460)     /* RNG时钟使能寄存器 */
#define SRE_SC_RNG_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x464)     /* RNG时钟禁止寄存器 */
#define SRE_SC_IMA_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x468)     /* IMA时钟使能寄存器 */
#define SRE_SC_IMA_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x46C)     /* IMA时钟禁止寄存器 */
#define SRE_SC_SCH_CLK_EN_REG            (SRE_SYS_REG_BASEADDR + 0x470)     /* SCH时钟使能寄存器 */
#define SRE_SC_SCH_CLK_DIS_REG           (SRE_SYS_REG_BASEADDR + 0x474)     /* SCH时钟禁止寄存器 */
#define SRE_SC_TM_CLK_EN_REG             (SRE_SYS_REG_BASEADDR + 0x478)     /* TM时钟使能寄存器 */
#define SRE_SC_TM_CLK_DIS_REG            (SRE_SYS_REG_BASEADDR + 0x47C)     /* TM时钟禁止寄存器 */
#define SRE_SC_IO_H2X_BRG_WFQCFG_REG     (SRE_SYS_REG_BASEADDR + 0x4A0)
#define SRE_SC_IO_H2X_BRG_CTRL_REG       (SRE_SYS_REG_BASEADDR + 0x4A4)
#define SRE_SC_IO_H2X_BRG_STATCFG_REG    (SRE_SYS_REG_BASEADDR + 0x4A8)
#define SRE_SC_ALG_H2X_BRG_WFQCFG_REG    (SRE_SYS_REG_BASEADDR + 0x4B0)
#define SRE_SC_ALG_H2X_BRG_CTRL_REG      (SRE_SYS_REG_BASEADDR + 0x4B4)
#define SRE_SC_ALG_H2X_BRG_STATCFG_REG   (SRE_SYS_REG_BASEADDR + 0x4B8)
#define SRE_SC_TOP_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x500)     /* 顶层CRG软复位请求控制寄存器 */
#define SRE_SC_TOP_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x504)     /* 顶层CRG软复位去请求控制寄存器 */
#define SRE_SC_CPU_RESET_REQ0_REG        (SRE_SYS_REG_BASEADDR + 0x520)     /* Cluster0内部软复位请求控制寄存器。 */
#define SRE_SC_CPU_RESET_DREQ0_REG       (SRE_SYS_REG_BASEADDR + 0x524)     /* Cluster0内部软复位去请求控制寄存器。 */
#define SRE_SC_CPU_RESET_REQ1_REG        (SRE_SYS_REG_BASEADDR + 0x528)     /* Cluster1内部软复位请求控制寄存器。 */
#define SRE_SC_CPU_RESET_DREQ1_REG       (SRE_SYS_REG_BASEADDR + 0x52C)     /* Cluster1内部软复位去请求控制寄存器。 */
#define SRE_SC_CPU_RESET_REQ2_REG        (SRE_SYS_REG_BASEADDR + 0x530)     /* Cluster2内部软复位请求控制寄存器。 */
#define SRE_SC_CPU_RESET_DREQ2_REG       (SRE_SYS_REG_BASEADDR + 0x534)     /* Cluster2内部软复位去请求控制寄存器。 */
#define SRE_SC_CPU_RESET_REQ3_REG        (SRE_SYS_REG_BASEADDR + 0x538)     /* Cluster3内部软复位请求控制寄存器。 */
#define SRE_SC_CPU_RESET_DREQ3_REG       (SRE_SYS_REG_BASEADDR + 0x53C)     /* Cluster3内部软复位去请求控制寄存器。 */
#define SRE_SC_CACHE_RESET_REQ_REG       (SRE_SYS_REG_BASEADDR + 0x560)     /* l3cache软复位请求控制寄存器 */
#define SRE_SC_CACHE_RESET_DREQ_REG      (SRE_SYS_REG_BASEADDR + 0x564)     /* l3cache软复位去请求控制寄存器 */
#define SRE_SC_SERDES_RESET_REQ0_REG     (SRE_SYS_REG_BASEADDR + 0x580)     /* Serdes软复位请求控制寄存器1 */
#define SRE_SC_SERDES_RESET_DREQ0_REG    (SRE_SYS_REG_BASEADDR + 0x584)     /* Serdes软复位去请求控制寄存器1 */
#define SRE_SC_SERDES_RESET_REQ1_REG     (SRE_SYS_REG_BASEADDR + 0x588)     /* Serdes软复位请求控制寄存器2 */
#define SRE_SC_SERDES_RESET_DREQ1_REG    (SRE_SYS_REG_BASEADDR + 0x58C)     /* Serdes软复位去请求控制寄存器2 */
#define SRE_SC_SERDES_RESET_REQ2_REG     (SRE_SYS_REG_BASEADDR + 0x590)     /* Serdes软复位请求控制寄存器3 */
#define SRE_SC_SERDES_RESET_DREQ2_REG    (SRE_SYS_REG_BASEADDR + 0x594)     /* Serdes软复位去请求控制寄存器3 */
#define SRE_SC_GE_RESET_REQ_REG          (SRE_SYS_REG_BASEADDR + 0x5A0)     /* GE软复位请求控制寄存器 */
#define SRE_SC_GE_RESET_DREQ_REG         (SRE_SYS_REG_BASEADDR + 0x5A4)     /* GE软复位去请求控制寄存器 */
#define SRE_SC_XGE_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x5B0)     /* XGE软复位请求控制寄存器 */
#define SRE_SC_XGE_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x5B4)     /* XGE软复位去请求控制寄存器 */
#define SRE_SC_MAC_CFG_RESET_REQ_REG     (SRE_SYS_REG_BASEADDR + 0x5C0)     /* MAC配置软复位请求控制寄存器 */
#define SRE_SC_MAC_CFG_RESET_DREQ_REG    (SRE_SYS_REG_BASEADDR + 0x5C4)     /* MAC配置软复位去请求控制寄存器 */
#define SRE_SC_MAC_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x5C8)     /* MAC软复位请求控制寄存器 */
#define SRE_SC_MAC_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x5CC)     /* MAC软复位去请求控制寄存器 */
#define SRE_SC_PCIE_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x5E0)     /* PCIE软复位请求控制寄存器 */
#define SRE_SC_PCIE_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x5E4)     /* PCIE软复位去请求控制寄存器 */
#define SRE_SC_SRIO_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x5F0)     /* SRIO软复位请求控制寄存器 */
#define SRE_SC_SRIO_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x5F4)     /* SRIO软复位去请求控制寄存器 */
#define SRE_SC_USB_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x600)     /* USB软复位请求控制寄存器 */
#define SRE_SC_USB_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x604)     /* USB软复位去请求控制寄存器 */
#define SRE_SC_DDR_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x620)     /* DDR软复位请求控制寄存器 */
#define SRE_SC_DDR_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x624)     /* DDR软复位去请求控制寄存器 */
#define SRE_SC_MMC_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x630)     /* MMC软复位请求控制寄存器 */
#define SRE_SC_MMC_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x634)     /* MMC软复位去请求控制寄存器 */
#define SRE_SC_SFC_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x638)     /* SFC软复位请求控制寄存器 */
#define SRE_SC_SFC_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x63C)     /* SFC软复位去请求控制寄存器 */
#define SRE_SC_NANDC_RESET_REQ_REG       (SRE_SYS_REG_BASEADDR + 0x640)     /* NANDC软复位请求控制寄存器 */
#define SRE_SC_NANDC_RESET_DREQ_REG      (SRE_SYS_REG_BASEADDR + 0x644)     /* NANDC软复位去请求控制寄存器 */
#define SRE_SC_LOCALBUS_RESET_REQ_REG    (SRE_SYS_REG_BASEADDR + 0x650)     /* LOCALBUS软复位请求控制寄存器 */
#define SRE_SC_LOCALBUS_RESET_DREQ_REG   (SRE_SYS_REG_BASEADDR + 0x654)     /* LOCALBUS软复位去请求控制寄存器 */
#define SRE_SC_UART_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x680)     /* UART软复位请求控制寄存器 */
#define SRE_SC_UART_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x684)     /* UART软复位去请求控制寄存器 */
#define SRE_SC_I2C_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x688)     /* I2C软复位请求控制寄存器 */
#define SRE_SC_I2C_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x68C)     /* I2C软复位去请求控制寄存器 */
#define SRE_SC_MDIO_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x690)     /* MDIO软复位请求控制寄存器 */
#define SRE_SC_MDIO_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x694)     /* MDIO软复位去请求控制寄存器 */
#define SRE_SC_SPI_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x698)     /* SPI软复位请求控制寄存器 */
#define SRE_SC_SPI_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x69C)     /* SPI软复位去请求控制寄存器 */
#define SRE_SC_GPIO_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x6A0)     /* GPIO软复位请求控制寄存器 */
#define SRE_SC_GPIO_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x6A4)     /* GPIO软复位去请求控制寄存器 */
#define SRE_SC_TDM_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x6C0)     /* TDM软复位请求控制寄存器 */
#define SRE_SC_TDM_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x6C4)     /* TDM软复位去请求控制寄存器 */
#define SRE_SC_HDLC_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x6C8)     /* HDLC软复位请求控制寄存器 */
#define SRE_SC_HDLC_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x6CC)     /* HDLC软复位去请求控制寄存器 */
#define SRE_SC_BOOTROM_RESET_REQ_REG     (SRE_SYS_REG_BASEADDR + 0x700)     /* BOOTROM软复位请求控制寄存器 */
#define SRE_SC_BOOTROM_RESET_DREQ_REG    (SRE_SYS_REG_BASEADDR + 0x704)     /* BOOTROM软复位去请求控制寄存器 */
#define SRE_SC_SEC_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x708)     /* SEC软复位请求控制寄存器 */
#define SRE_SC_SEC_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x70C)     /* SEC软复位去请求控制寄存器 */
#define SRE_SC_POE_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x710)     /* POE软复位请求控制寄存器 */
#define SRE_SC_POE_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x714)     /* POE软复位去请求控制寄存器 */
#define SRE_SC_BMU_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x718)     /* BMU软复位请求控制寄存器 */
#define SRE_SC_BMU_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x71C)     /* BMU软复位去请求控制寄存器 */
#define SRE_SC_PPE_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x720)     /* PPE软复位请求控制寄存器 */
#define SRE_SC_PPE_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x724)     /* PPE软复位去请求控制寄存器 */
#define SRE_SC_NP_RESET_REQ_REG          (SRE_SYS_REG_BASEADDR + 0x728)     /* SPPE软复位请求控制寄存器 */
#define SRE_SC_NP_RESET_DREQ_REG         (SRE_SYS_REG_BASEADDR + 0x72C)     /* SPPE软复位去请求控制寄存器 */
#define SRE_SC_CRC_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x730)     /* CRC软复位请求控制寄存器 */
#define SRE_SC_CRC_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x734)     /* CRC软复位去请求控制寄存器 */
#define SRE_SC_DMAC_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x738)     /* DMAC软复位请求控制寄存器 */
#define SRE_SC_DMAC_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x73C)     /* DMAC软复位去请求控制寄存器 */
#define SRE_SC_ROHC_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x740)     /* ROHC软复位请求控制寄存器 */
#define SRE_SC_ROHC_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x744)     /* ROHC软复位去请求控制寄存器 */
#define SRE_SC_HDCP_RESET_REQ_REG        (SRE_SYS_REG_BASEADDR + 0x748)     /* HDCP软复位请求控制寄存器 */
#define SRE_SC_HDCP_RESET_DREQ_REG       (SRE_SYS_REG_BASEADDR + 0x74C)     /* HDCP软复位去请求控制寄存器 */
#define SRE_SC_PDM_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x750)     /* PDM软复位请求控制寄存器 */
#define SRE_SC_PDM_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x754)     /* PDM软复位去请求控制寄存器 */
#define SRE_SC_TRING_RESET_REQ_REG       (SRE_SYS_REG_BASEADDR + 0x758)     /* TRING软复位请求控制寄存器 */
#define SRE_SC_TRING_RESET_DREQ_REG      (SRE_SYS_REG_BASEADDR + 0x75C)     /* TRING软复位去请求控制寄存器 */
#define SRE_SC_RNG_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x760)     /* RNG软复位请求控制寄存器 */
#define SRE_SC_RNG_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x764)     /* RNG软复位去请求控制寄存器 */
#define SRE_SC_IMA_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x768)     /* IMA软复位请求控制寄存器 */
#define SRE_SC_IMA_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x76C)     /* IMA软复位去请求控制寄存器 */
#define SRE_SC_SCH_RESET_REQ_REG         (SRE_SYS_REG_BASEADDR + 0x770)     /* SCH软复位请求控制寄存器 */
#define SRE_SC_SCH_RESET_DREQ_REG        (SRE_SYS_REG_BASEADDR + 0x774)     /* SCH软复位去请求控制寄存器 */
#define SRE_SC_TM_RESET_REQ_REG          (SRE_SYS_REG_BASEADDR + 0x778)     /* TM软复位请求控制寄存器 */
#define SRE_SC_TM_RESET_DREQ_REG         (SRE_SYS_REG_BASEADDR + 0x77c)     /* TM软复位去请求控制寄存器 */
#define SRE_SC_FUNC_MBIST_MODE_CFG_REG   (SRE_SYS_REG_BASEADDR + 0x800)
#define SRE_SC_FUNC_MBIST_CTRL_CFG_REG   (SRE_SYS_REG_BASEADDR + 0x804)
#define SRE_SC_FUNC_MBIST_MEM_CFG_REG    (SRE_SYS_REG_BASEADDR + 0x808)
#define SRE_SC_FUNC_MBIST_EN0_REG        (SRE_SYS_REG_BASEADDR + 0x810)
#define SRE_SC_FUNC_MBIST_EN1_REG        (SRE_SYS_REG_BASEADDR + 0x814)
#define SRE_SC_TCAM_MBIST_EN_REG         (SRE_SYS_REG_BASEADDR + 0x820)
#define SRE_SC_CPU_CTRL0_REG             (SRE_SYS_REG_BASEADDR + 0x900)
#define SRE_SC_CPU_CTRL1_REG             (SRE_SYS_REG_BASEADDR + 0x904)
#define SRE_SC_CPU_CTRL2_REG             (SRE_SYS_REG_BASEADDR + 0x908)
#define SRE_SC_CPU_CTRL3_REG             (SRE_SYS_REG_BASEADDR + 0x90C)
#define SRE_SC_CPU_CTRL4_REG             (SRE_SYS_REG_BASEADDR + 0x910)
#define SRE_SC_CPU_CTRL5_REG             (SRE_SYS_REG_BASEADDR + 0x914)
#define SRE_SC_CORE0_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x930)     /* 到Core0的Event源头选择使能 */
#define SRE_SC_CORE1_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x934)     /* 到Core1的Event源头选择使能 */
#define SRE_SC_CORE2_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x938)     /* 到Core2的Event源头选择使能 */
#define SRE_SC_CORE3_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x93C)     /* 到Core3的Event源头选择使能 */
#define SRE_SC_CORE4_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x940)     /* 到Core4的Event源头选择使能 */
#define SRE_SC_CORE5_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x944)     /* 到Core5的Event源头选择使能 */
#define SRE_SC_CORE6_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x948)     /* 到Core6的Event源头选择使能 */
#define SRE_SC_CORE7_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x94C)     /* 到Core7的Event源头选择使能 */
#define SRE_SC_CORE8_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x950)     /* 到Core8的Event源头选择使能 */
#define SRE_SC_CORE9_EVENT_EN_REG        (SRE_SYS_REG_BASEADDR + 0x954)     /* 到Core9的Event源头选择使能 */
#define SRE_SC_CORE10_EVENT_EN_REG       (SRE_SYS_REG_BASEADDR + 0x958)     /* 到Core10的Event源头选择使能 */
#define SRE_SC_CORE11_EVENT_EN_REG       (SRE_SYS_REG_BASEADDR + 0x95C)     /* 到Core11的Event源头选择使能 */
#define SRE_SC_CORE12_EVENT_EN_REG       (SRE_SYS_REG_BASEADDR + 0x960)     /* 到Core12的Event源头选择使能 */
#define SRE_SC_CORE13_EVENT_EN_REG       (SRE_SYS_REG_BASEADDR + 0x964)     /* 到Core13的Event源头选择使能 */
#define SRE_SC_CORE14_EVENT_EN_REG       (SRE_SYS_REG_BASEADDR + 0x968)     /* 到Core14的Event源头选择使能 */
#define SRE_SC_CORE15_EVENT_EN_REG       (SRE_SYS_REG_BASEADDR + 0x96C)     /* 到Core15的Event源头选择使能 */
#define SRE_SC_CACHE_CTRL_REG            (SRE_SYS_REG_BASEADDR + 0x9F0)     /* Cache工作模式配置 */
#define SRE_SC_GIC_CTRL_REG              (SRE_SYS_REG_BASEADDR + 0xA00)     /* GIC控制寄存器 */
#define SRE_SC_CS_CTRL_REG               (SRE_SYS_REG_BASEADDR + 0xA40)
#define SRE_SC_DDR_CTRL0_REG             (SRE_SYS_REG_BASEADDR + 0xA80)
#define SRE_SC_DDR_CTRL1_REG             (SRE_SYS_REG_BASEADDR + 0xA84)
#define SRE_SC_EBI_CTRL_REG              (SRE_SYS_REG_BASEADDR + 0xAC0)
#define SRE_SC_USB_CTRL0_REG             (SRE_SYS_REG_BASEADDR + 0xB80)
#define SRE_SC_USB_CTRL1_REG             (SRE_SYS_REG_BASEADDR + 0xB84)
#define SRE_SC_BOOTROM_CTRL_REG          (SRE_SYS_REG_BASEADDR + 0xC00)
#define SRE_SC_TSENSOR_CTRL_REG          (SRE_SYS_REG_BASEADDR + 0xC10)
#define SRE_SC_TSENSOR_TEST_CTRL_REG     (SRE_SYS_REG_BASEADDR + 0xC18)     /* Tsensor测试使用，请正常用户不要配置修改。 */
#define SRE_SC_EMMC_CTRL_REG             (SRE_SYS_REG_BASEADDR + 0xC20)
#define SRE_SC_MDIO_CTRL0_REG            (SRE_SYS_REG_BASEADDR + 0xC30)
#define SRE_SC_MDIO_CTRL1_REG            (SRE_SYS_REG_BASEADDR + 0xC34)
#define SRE_SC_SYNC_ETH0_CTRL_REG        (SRE_SYS_REG_BASEADDR + 0xC40)     /* 同步以太网时钟选择控制寄存器0 */
#define SRE_SC_SYNC_ETH1_CTRL_REG        (SRE_SYS_REG_BASEADDR + 0xC44)     /* 同步以太网时钟选择控制器1 */
#define SRE_SC_MAC_MODE_REG              (SRE_SYS_REG_BASEADDR + 0xC48)     /* 各网口MAC工作模式指示，同步以太网时钟上送功能模块根据此信号确定原始时钟到上送时钟需要进行的分频系数 */
#define SRE_SC_MISC_CTRL_REG             (SRE_SYS_REG_BASEADDR + 0xC80)
#define SRE_SC_IO_DRIVE_CTRL0_REG        (SRE_SYS_REG_BASEADDR + 0xC90)     /* 普通IO管脚驱动电流配置控制0 */
#define SRE_SC_IO_DRIVE_CTRL1_REG        (SRE_SYS_REG_BASEADDR + 0xC94)     /* 普通IO管脚驱动电流配置控制1 */
#define MC_SCITCR_REG                    (SRE_SYS_REG_BASEADDR + 0xF00)
#define MC_SCITIR0_REG                   (SRE_SYS_REG_BASEADDR + 0xF04)
#define MC_SCITIR1_REG                   (SRE_SYS_REG_BASEADDR + 0xF08)
#define MC_SCITOR_REG                    (SRE_SYS_REG_BASEADDR + 0xF0C)
#define MC_SCCNTCTRL_REG                 (SRE_SYS_REG_BASEADDR + 0xF10)
#define MC_SCCNTDATA_REG                 (SRE_SYS_REG_BASEADDR + 0xF14)
#define MC_SCCNTSTEP_REG                 (SRE_SYS_REG_BASEADDR + 0xF18)
#define SRE_SC_TSENSOR_REG               (SRE_SYS_REG_BASEADDR + 0x1080)
#define SRE_SC_BOOT_CFG_REG              (SRE_SYS_REG_BASEADDR + 0x1090)
#define SRE_SC_BOOT_SEL_REG              (SRE_SYS_REG_BASEADDR + 0x1094)
#define SRE_SC_PLL_LOCK_STATUS_REG       (SRE_SYS_REG_BASEADDR + 0x1110)
#define SRE_SC_TOP_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1200)    /* 顶层CRG时钟状态寄存器 */
#define SRE_SC_GE_CLK_ST_REG             (SRE_SYS_REG_BASEADDR + 0x12A0)    /* GE时钟状态寄存器 */
#define SRE_SC_XGE_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x12B0)    /* XGE时钟状态寄存器 */
#define SRE_SC_PCIE_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x12E0)    /* PCIE时钟状态寄存器 */
#define SRE_SC_SRIO_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x12F0)    /* SRIO时钟状态寄存器 */
#define SRE_SC_USB_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1300)    /* USB时钟状态寄存器 */
#define SRE_SC_SATA_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1310)    /* SATA时钟状态寄存器 */
#define SRE_SC_DDR_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1320)    /* DDR时钟状态寄存器 */
#define SRE_SC_MMC_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1330)    /* MMC时钟状态寄存器 */
#define SRE_SC_SFC_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1338)    /* SFC时钟状态寄存器 */
#define SRE_SC_NANDC_CLK_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1340)    /* NANDC时钟状态寄存器 */
#define SRE_SC_LOCALBUS_CLK_ST_REG       (SRE_SYS_REG_BASEADDR + 0x1350)    /* LOCALBUS时钟状态寄存器 */
#define SRE_SC_UART_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1380)    /* UART时钟状态寄存器 */
#define SRE_SC_I2C_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1388)    /* I2C时钟状态寄存器 */
#define SRE_SC_MDIO_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1390)    /* MDIO时钟状态寄存器 */
#define SRE_SC_SPI_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1398)    /* SPI时钟状态寄存器 */
#define SRE_SC_GPIO_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x13A0)    /* GPIO时钟状态寄存器 */
#define SRE_SC_TDM_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x13C0)    /* TDM时钟状态寄存器 */
#define SRE_SC_HDLC_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x13C8)    /* HDLC时钟状态寄存器 */
#define SRE_SC_BOOTROM_CLK_ST_REG        (SRE_SYS_REG_BASEADDR + 0x1400)    /* BOOTROM时钟状态寄存器 */
#define SRE_SC_SEC_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1408)    /* SEC时钟状态寄存器 */
#define SRE_SC_POE_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1410)    /* POE时钟状态寄存器 */
#define SRE_SC_BMU_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1418)    /* BMU时钟状态寄存器 */
#define SRE_SC_PPE_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1420)    /* PPE时钟状态寄存器 */
#define SRE_SC_NP_CLK_ST_REG             (SRE_SYS_REG_BASEADDR + 0x1428)    /* SPPE时钟状态寄存器 */
#define SRE_SC_CRC_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1430)    /* CRC时钟状态寄存器 */
#define SRE_SC_DMAC_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1438)    /* DMAC时钟状态寄存器 */
#define SRE_SC_ROHC_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1440)    /* ROHC时钟状态寄存器 */
#define SRE_SC_HDCP_CLK_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1448)    /* HDCP时钟状态寄存器 */
#define SRE_SC_PDM_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1450)    /* PDM时钟状态寄存器 */
#define SRE_SC_TRING_CLK_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1458)    /* TRING时钟状态寄存器 */
#define SRE_SC_RNG_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1460)    /* RNG时钟状态寄存器 */
#define SRE_SC_IMA_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1468)    /* IMA时钟状态寄存器 */
#define SRE_SC_SCH_CLK_ST_REG            (SRE_SYS_REG_BASEADDR + 0x1470)    /* SCH时钟状态寄存器 */
#define SRE_SC_TM_CLK_ST_REG             (SRE_SYS_REG_BASEADDR + 0x1478)    /* TM时钟状态寄存器 */
#define SRE_SC_TOP_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1500)    /* 顶层CRG软复位状态寄存器 */
#define SRE_SC_CPU_RESET_ST0_REG         (SRE_SYS_REG_BASEADDR + 0x1520)    /* Cluster0内部软复位状态控制寄存器。 */
#define SRE_SC_CPU_RESET_ST1_REG         (SRE_SYS_REG_BASEADDR + 0x1528)    /* Cluster1内部软复位状态控制寄存器。 */
#define SRE_SC_CPU_RESET_ST2_REG         (SRE_SYS_REG_BASEADDR + 0x1530)    /* Cluster2内部软复位状态控制寄存器。 */
#define SRE_SC_CPU_RESET_ST3_REG         (SRE_SYS_REG_BASEADDR + 0x1538)    /* Cluster3内部软复位状态控制寄存器。 */
#define SRE_SC_CACHE_RESET_ST_REG        (SRE_SYS_REG_BASEADDR + 0x1560)    /* l3cache软复位状态控制寄存器 */
#define SRE_SC_SERDES_RESET_ST0_REG      (SRE_SYS_REG_BASEADDR + 0x1580)    /* Serdes软复位状态寄存器1 */
#define SRE_SC_SERDES_RESET_ST1_REG      (SRE_SYS_REG_BASEADDR + 0x1588)    /* Serdes软复位状态寄存器2 */
#define SRE_SC_SERDES_RESET_ST2_REG      (SRE_SYS_REG_BASEADDR + 0x1590)    /* Serdes软复位状态寄存器3 */
#define SRE_SC_GE_RESET_ST_REG           (SRE_SYS_REG_BASEADDR + 0x15A0)    /* GE软复位状态寄存器 */
#define SRE_SC_XGE_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x15B0)    /* XGE软复位状态寄存器 */
#define SRE_SC_MAC_CFG_RESET_ST_REG      (SRE_SYS_REG_BASEADDR + 0x15C0)    /* MAC配置软复位状态寄存器 */
#define SRE_SC_MAC_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x15C8)    /* MAC软复位状态寄存器 */
#define SRE_SC_PCIE_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x15E0)    /* PCIE软复位状态寄存器 */
#define SRE_SC_SRIO_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x15F0)    /* SRIO软复位状态寄存器 */
#define SRE_SC_USB_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1604)    /* USB软复位状态寄存器 */
#define SRE_SC_DDR_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1620)    /* DDR软复位状态控制寄存器 */
#define SRE_SC_MMC_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1630)    /* MMC软复位状态寄存器 */
#define SRE_SC_SFC_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1638)    /* SFC软复位状态寄存器 */
#define SRE_SC_NANDC_RESET_ST_REG        (SRE_SYS_REG_BASEADDR + 0x1640)    /* NANDC软复位状态寄存器 */
#define SRE_SC_LOCALBUS_RESET_ST_REG     (SRE_SYS_REG_BASEADDR + 0x1650)    /* LOCALBUS软复位状态寄存器 */
#define SRE_SC_UART_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x1680)    /* UART软复位状态寄存器 */
#define SRE_SC_I2C_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1688)    /* I2C软复位状态寄存器 */
#define SRE_SC_MDIO_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x1690)    /* MDIO软复位状态寄存器 */
#define SRE_SC_SPI_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1698)    /* SPI软复位状态寄存器 */
#define SRE_SC_GPIO_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x16A0)    /* GPIO软复位状态寄存器 */
#define SRE_SC_TDM_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x16C0)    /* TDM软复位状态寄存器 */
#define SRE_SC_HDLC_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x16C8)    /* HDLC软复位状态寄存器 */
#define SRE_SC_BOOTROM_RESET_ST_REG      (SRE_SYS_REG_BASEADDR + 0x1700)    /* BOOTROM软复位状态寄存器 */
#define SRE_SC_SEC_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1708)    /* SEC软复位状态寄存器 */
#define SRE_SC_POE_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1710)    /* POE软复位状态寄存器 */
#define SRE_SC_BMU_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1718)    /* BMU软复位状态寄存器 */
#define SRE_SC_PPE_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1720)    /* PPE软复位状态寄存器 */
#define SRE_SC_NP_RESET_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1728)    /* SPPE软复位状态寄存器 */
#define SRE_SC_CRC_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1730)    /* CRC软复位状态寄存器 */
#define SRE_SC_DMAC_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x1738)    /* DMAC软复位状态寄存器 */
#define SRE_SC_ROHC_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x1740)    /* ROHC软复位状态寄存器 */
#define SRE_SC_HDCP_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x1748)    /* HDCP软复位状态寄存器 */
#define SRE_SC_PDM_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1750)    /* PDM软复位状态寄存器 */
#define SRE_SC_TRING_RESET_ST_REG        (SRE_SYS_REG_BASEADDR + 0x1758)    /* TRING软复位状态寄存器 */
#define SRE_SC_RNG_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1760)    /* RNG软复位状态寄存器 */
#define SRE_SC_IMA_RESET_ST_REG          (SRE_SYS_REG_BASEADDR + 0x1768)    /* IMA软复位状态寄存器 */
#define SRE_SC_SCH_RESET_ST_REG         (SRE_SYS_REG_BASEADDR + 0x1770)    /* SCH软复位状态寄存器 */
#define SRE_SC_TM_RESET_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1778)    /* TM软复位状态寄存器 */
#define SRE_SC_FUNC_MBIST_DONE0_REG      (SRE_SYS_REG_BASEADDR + 0x1810)
#define SRE_SC_FUNC_MBIST_DONE1_REG      (SRE_SYS_REG_BASEADDR + 0x1814)
#define SRE_SC_FUNC_MBIST_RESULT0_REG    (SRE_SYS_REG_BASEADDR + 0x1820)
#define SRE_SC_FUNC_MBIST_RESULT1_REG    (SRE_SYS_REG_BASEADDR + 0x1824)
#define SRE_SC_CLUSTER0_MBIST_ST0_REG    (SRE_SYS_REG_BASEADDR + 0x1830)    /* Cluster0 MBIST测试状态和结果 */
#define SRE_SC_CLUSTER0_MBIST_ST1_REG    (SRE_SYS_REG_BASEADDR + 0x1834)    /* Cluster0 L1 MBIST测试结果状态 */
#define SRE_SC_CLUSTER1_MBIST_ST0_REG    (SRE_SYS_REG_BASEADDR + 0x1838)    /* Cluster1 MBIST测试状态和结果 */
#define SRE_SC_CLUSTER1_MBIST_ST1_REG    (SRE_SYS_REG_BASEADDR + 0x183C)    /* Cluster1 L1 MBIST测试结果状态 */
#define SRE_SC_CLUSTER2_MBIST_ST0_REG    (SRE_SYS_REG_BASEADDR + 0x1840)    /* Cluster2 MBIST测试状态和结果 */
#define SRE_SC_CLUSTER2_MBIST_ST1_REG    (SRE_SYS_REG_BASEADDR + 0x1844)    /* Cluster2 L1 MBIST测试结果状态 */
#define SRE_SC_CLUSTER3_MBIST_ST0_REG    (SRE_SYS_REG_BASEADDR + 0x1848)    /* Cluster0 MBIST测试状态和结果 */
#define SRE_SC_CLUSTER3_MBIST_ST1_REG    (SRE_SYS_REG_BASEADDR + 0x184C)    /* Cluster0 L1 MBIST测试结果状态 */
#define SRE_SC_TCAM_MBIST_ST_REG         (SRE_SYS_REG_BASEADDR + 0x1860)    /* TCAM MBIST测试结果状态 */
#define SRE_SC_SYNC_ETH_ST_REG           (SRE_SYS_REG_BASEADDR + 0x1900)    /* 同步以太网工作状态 */
#define SRE_SC_DDR_ST_REG                (SRE_SYS_REG_BASEADDR + 0x1A80)
#define SRE_SC_LOGIC_FREEZE_EN_REG       (SRE_SYS_REG_BASEADDR + 0x1E00)    /* 通过此寄存器控制锁定所有逻辑，供同时获取芯片状态， */
#define SRE_SC_LOGIC_FREEZE_SRC_EN_REG   (SRE_SYS_REG_BASEADDR + 0x1E04)    /* 时钟停止源头选择 */
#define SRE_SC_LOGIC_FREEZE_REQ_REG      (SRE_SYS_REG_BASEADDR + 0x1E08)    /* 内部软件请求停止业务通路工作时钟 */
#define SRE_SC_IO_H2X_STAT_REG           (SRE_SYS_REG_BASEADDR + 0x1E40)
#define SRE_SC_ALG_H2X_STAT_REG          (SRE_SYS_REG_BASEADDR + 0x1E44)
#define SRE_SC_NORESET_REC0_REG          (SRE_SYS_REG_BASEADDR + 0x1E80)    /* 无复位寄存器0，可以用于在非掉电复位时，保留复位前的状态。 */
#define SRE_SC_NORESET_REC1_REG          (SRE_SYS_REG_BASEADDR + 0x1E84)    /* 无复位寄存器1，可以用于在非掉电复位时，保留复位前的状态。 */
#define SRE_SC_NORESET_REC2_REG          (SRE_SYS_REG_BASEADDR + 0x1E88)    /* 无复位寄存器2，可以用于在非掉电复位时，保留复位前的状态。 */
#define SRE_SC_NORESET_REC3_REG          (SRE_SYS_REG_BASEADDR + 0x1E8C)    /* 无复位寄存器3，可以用于在非掉电复位时，保留复位前的状态。 */
#define SRE_SC_NORESET_REC4_REG          (SRE_SYS_REG_BASEADDR + 0x1E90)    /* 无复位寄存器4，可以用于在非掉电复位时，保留复位前的状态。 */
#define SRE_SC_NORESET_REC5_REG          (SRE_SYS_REG_BASEADDR + 0x1E94)    /* 无复位寄存器5，可以用于在非掉电复位时，保留复位前的状态。 */
#define SRE_SC_NORESET_REC6_REG          (SRE_SYS_REG_BASEADDR + 0x1E98)    /* 无复位寄存器6，可以用于在非掉电复位时，保留复位前的状态。 */
#define SRE_SC_NORESET_REC7_REG          (SRE_SYS_REG_BASEADDR + 0x1E9C)    /* 无复位寄存器7，可以用于在非掉电复位时，保留复位前的状态。 */
#define SRE_SC_NORESET_REC8_REG          (SRE_SYS_REG_BASEADDR + 0x1EA0)    /* 无复位寄存器8，可以用于在非掉电复位时，保留复位前的状态。 */
#define SRE_SC_NORESET_REC9_REG          (SRE_SYS_REG_BASEADDR + 0x1EA4)    /* 无复位寄存器9，可以用于在非掉电复位时，保留复位前的状态。 */
#define SRE_SC_NORESET_REC10_REG         (SRE_SYS_REG_BASEADDR + 0x1EA8)    /* 无复位寄存器10，可以用于在非掉电复位时，保留复位前的状态。 */
#define SRE_SC_NORESET_REC11_REG         (SRE_SYS_REG_BASEADDR + 0x1EAC)    /* 无复位寄存器11，可以用于在非掉电复位时，保留复位前的状态。 */
#define SRE_SC_NORESET_REC12_REG         (SRE_SYS_REG_BASEADDR + 0x1EB0)    /* 无复位寄存器12，可以用于在非掉电复位时，保留复位前的状态。 */
#define SRE_SC_NORESET_REC13_REG         (SRE_SYS_REG_BASEADDR + 0x1EB4)    /* 无复位寄存器13，可以用于在非掉电复位时，保留复位前的状态。 */
#define SRE_SC_NORESET_REC14_REG         (SRE_SYS_REG_BASEADDR + 0x1EB8)    /* 无复位寄存器14，可以用于在非掉电复位时，保留复位前的状态。 */
#define SRE_SC_NORESET_REC15_REG         (SRE_SYS_REG_BASEADDR + 0x1EBC)    /* 无复位寄存器15，可以用于在非掉电复位时，保留复位前的状态。 */
#define SRE_SYS_SYSID_0_REG                  (SRE_SYS_REG_BASEADDR + 0x1EE0)    /* SYS ID 31~0比特 */
#define SRE_SYS_SYSID_1_REG                  (SRE_SYS_REG_BASEADDR + 0x1EE4)    /* SYS ID 63~32比特 */
#define SRE_SYS_SYSID_2_REG                  (SRE_SYS_REG_BASEADDR + 0x1EE8)    /* SYS ID 95~64比特 */
#define SRE_SYS_SYSID_3_REG                  (SRE_SYS_REG_BASEADDR + 0x1EEC)    /* SYS ID 127~96比特 */
#define SRE_SYS_SYSID_4_REG                  (SRE_SYS_REG_BASEADDR + 0x1EF0)    /* SYS ID 159~128比特 */
#define SRE_SYS_SYSID_5_REG                  (SRE_SYS_REG_BASEADDR + 0x1EF4)    /* SYS ID 191~160比特 */
#define SRE_SYS_SYSID_6_REG                  (SRE_SYS_REG_BASEADDR + 0x1EF8)    /* SYS ID 223~192比特 */
#define SRE_SYS_SYSID_7_REG                  (SRE_SYS_REG_BASEADDR + 0x1EFC)    /* SYS ID 255~224比特 */
/* END:   Added by h00176630, 2012/6/9 */

/******************************************************************************/
/*                      PhosphorV600 GIC 寄存器定义                           */
/******************************************************************************/
#define MC_GIC0_REG_BASEADDR     (0x1A000100 + 0x80000000)   /* GIC0的寄存器基地址 */
#define MC_GIC1_REG_BASEADDR     (0x1B000100 + 0x80000000)   /* GIC1的寄存器基地址 */

/******************************************************************************/
/*                      PhosphorV600 UART0 寄存器定义                         */
/******************************************************************************/
#define MC_URAT0_REG_BASEADDR           0xe4007000   /* URAT0的寄存器基地址 */
#define MC_UART0_REG_DR_DLL          (MC_URAT0_REG_BASEADDR + 0x00 )  /* GIC0的寄存器基地址 */
#define MC_UART0_REG_USR             (MC_URAT0_REG_BASEADDR + 0x7c )  /* GIC0的寄存器基地址 */

/* 看门狗定时器的IO起始基址 */
#define MC_WATCHDOG_IO_BASE        (0x600)
#define MC_WATCHDOG_LOAD_GER       (MC_WATCHDOG_IO_BASE + 0x20)
#define MC_WATCHDOG_COUNT_GER      (MC_WATCHDOG_IO_BASE + 0x24)
#define MC_WATCHDOG_CONTRL_GER     (MC_WATCHDOG_IO_BASE + 0x28)
#define MC_WATCHDOG_INT_STAU_GER   (MC_WATCHDOG_IO_BASE + 0x2C)

/******************************************************************************/
/*                                    GPIO寄存器                              */
/******************************************************************************/
#define MC_GPIO0_REG_BASE           (0x2000a000 + 0x80000000)
#define MC_GPIO0_SWPORT_DR_REG      (MC_GPIO0_REG_BASE + 0x00)
#define MC_GPIO0_SWPORT_DDR_REG     (MC_GPIO0_REG_BASE + 0x04)

/******************************************************************************/
/*                                    IO_CONFIG寄存器                              */
/******************************************************************************/
#define MC_IOCONFIG_REG_BASE        (0x2000d000 + 0x80000000)
#define MC_IOMG012_REG              (MC_IOCONFIG_REG_BASE + 0x30)

/* BEGIN: Added by c00111586, 2010/9/24   问题单号:DTS2010091901574 */
#define MC_PADMG00_REG              (MC_IOCONFIG_REG_BASE + 0x800)
/* END:   Added by c00111586, 2010/9/24 */

/********QMU模块使用的寄存器地址定义************/
#define MC_QMU_REG_BASE            (0x10020000 + 0x80000000)
#define MC_QMU_INT_STATUS_REG      (MC_QMU_REG_BASE + 0x00)
#define MC_QMU_INT_ENA_REG         (MC_QMU_REG_BASE + 0x04)
#define MC_QMU_INT_CLR_REG         (MC_QMU_REG_BASE + 0x08)

#define MC_QMU_CNT_SEL_REG         (MC_QMU_REG_BASE + 0x00E8)
#define MC_QMU_RD_EXPT_RET_REG0    (MC_QMU_REG_BASE + 0x00FC)
#define MC_QMU_RD_EXPT_RET_REG1    (MC_QMU_REG_BASE + 0x0100)
#define MC_QMU_DEBUG_CTR_REG       (MC_QMU_REG_BASE + 0x0104)
#define MC_QMU_DEBUG_STAT_REG      (MC_QMU_REG_BASE + 0x0108)

#define MC_QMU_PQ_BASE_REG         (MC_QMU_REG_BASE + 0x2000)
#define MC_QMU_PQ_CNT_REG          (MC_QMU_REG_BASE + 0x2004)
#define MC_QMU_PQ_RWP_REG          (MC_QMU_REG_BASE + 0x2008)

#define MC_QMU_RQ_BASE_REG         (MC_QMU_REG_BASE + 0x2300)
#define MC_QMU_RQ_CNT_REG          (MC_QMU_REG_BASE + 0x2304)
#define MC_QMU_RQ_RWP_REG          (MC_QMU_REG_BASE + 0x2308)

#define MC_QMU_PQ_CORE0_LDST_REG   (MC_QMU_REG_BASE + 0x4000)
#define MC_QMU_PQ_CORE0_ST_STA_REG (MC_QMU_REG_BASE + 0x6000)

#define MC_QMU_RQ_CORE0_LDST_REG   (MC_QMU_REG_BASE + 0x8000)
#define MC_QMU_RQ_CORE0_ST_STA_REG (MC_QMU_REG_BASE + 0x9000)


/********HDCP 模块使用的寄存器地址定义************/
#define MC_HDCP_REG_BASE            (0x100e0000 + 0x80000000)
#define SRE_HDCP_ENABLE_REG         (MC_HDCP_REG_BASE + 0x0000)
#define HDCP_BMU_CFG_ADDR          (MC_HDCP_REG_BASE + 0x0004)
#define HDCP_POE_CFG_ADDR          (MC_HDCP_REG_BASE + 0x0008)          /**POE ADD 寄存器**/
#define HDCP_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x000c)
#define HDCP_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x0010)

#define HDCP_INT_MASK_REG          (MC_HDCP_REG_BASE + 0x0014)
#define HDCP_INT_STATUS_REG        (MC_HDCP_REG_BASE + 0x0018)
#define HDCP_RAWINT_STATUS_REG     (MC_HDCP_REG_BASE + 0x001C)
#define HDCP_INT_CLR_REG           (MC_HDCP_REG_BASE + 0x0020)

#define HDCP_MEMREQ_FAIL_REG       (MC_HDCP_REG_BASE + 0x0024)
#define HDCP_BMURLS_FAIL_REG       (MC_HDCP_REG_BASE + 0x0028)
#define HDCP_ADDPOE_FAIL_REG       (MC_HDCP_REG_BASE + 0x002C)
#define HDCP_DATA_FAIL_REG         (MC_HDCP_REG_BASE + 0x0030)

#define HDCP_TRANS_CNT_REG         (MC_HDCP_REG_BASE + 0x0034)
#define HDCP_DATA_TIMECNT_REG      (MC_HDCP_REG_BASE + 0x0038)
#define HDCP_MEMRES_CMPL_CNT_REG   (MC_HDCP_REG_BASE + 0x003C)
#define HDCP_MEMREQ_CMPL_CNT_REG   (MC_HDCP_REG_BASE + 0x0040)
#define HDCP_ADDPOE_CMPL_CNT_REG   (MC_HDCP_REG_BASE + 0x0044)


#define HDCP_CH0_ENABLE_REG        (MC_HDCP_REG_BASE + 0x0100)
#define HDCP_CH0_ADD_POE_WDATA2_REG    (MC_HDCP_REG_BASE + 0x0104)
#define HDCP_CH0_SRC_SADDR_REG         (MC_HDCP_REG_BASE + 0x0108)
#define HDCP_CH0_DES_SADDR_REG         (MC_HDCP_REG_BASE + 0x010C)
#define HDCP_CH0_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x0110)
#define HDCP_CH0_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x0114)
#define HDCP_CH0_DEBUG_REG             (MC_HDCP_REG_BASE + 0x0118)

#define HDCP_CH1_ENABLE_REG            (MC_HDCP_REG_BASE + 0x0120)
#define HDCP_CH1_ADD_POE_WDATA2_REG    (MC_HDCP_REG_BASE + 0x0124)
#define HDCP_CH1_SRC_SADDR_REG         (MC_HDCP_REG_BASE + 0x0128)
#define HDCP_CH1_DES_SADDR_REG         (MC_HDCP_REG_BASE + 0x012C)
#define HDCP_CH1_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x0130)
#define HDCP_CH1_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x0134)
#define HDCP_CH1_DEBUG_REG             (MC_HDCP_REG_BASE + 0x0138)

#define HDCP_CH2_ENABLE_REG            (MC_HDCP_REG_BASE + 0x0140)
#define HDCP_CH2_ADD_POE_WDATA2_REG    (MC_HDCP_REG_BASE + 0x0144)
#define HDCP_CH2_SRC_SADDR_REG         (MC_HDCP_REG_BASE + 0x0148)
#define HDCP_CH2_DES_SADDR_REG         (MC_HDCP_REG_BASE + 0x014C)
#define HDCP_CH2_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x0150)
#define HDCP_CH2_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x0154)
#define HDCP_CH2_DEBUG_REG             (MC_HDCP_REG_BASE + 0x0158)

#define HDCP_CH3_ENABLE_REG            (MC_HDCP_REG_BASE + 0x0160)
#define HDCP_CH3_ADD_POE_WDATA2_REG    (MC_HDCP_REG_BASE + 0x0164)
#define HDCP_CH3_SRC_SADDR_REG         (MC_HDCP_REG_BASE + 0x0168)
#define HDCP_CH3_DES_SADDR_REG         (MC_HDCP_REG_BASE + 0x016C)
#define HDCP_CH3_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x0170)
#define HDCP_CH3_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x0174)
#define HDCP_CH3_DEBUG_REG             (MC_HDCP_REG_BASE + 0x0178)

#define HDCP_CH4_ENABLE_REG            (MC_HDCP_REG_BASE + 0x0180)
#define HDCP_CH4_ADD_POE_WDATA2_REG    (MC_HDCP_REG_BASE + 0x0184)
#define HDCP_CH4_SRC_SADDR_REG         (MC_HDCP_REG_BASE + 0x0188)
#define HDCP_CH4_DES_SADDR_REG         (MC_HDCP_REG_BASE + 0x018C)
#define HDCP_CH4_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x0190)
#define HDCP_CH4_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x0194)
#define HDCP_CH4_DEBUG_REG             (MC_HDCP_REG_BASE + 0x0198)

#define HDCP_CH5_ENABLE_REG            (MC_HDCP_REG_BASE + 0x01A0)
#define HDCP_CH5_ADD_POE_WDATA2_REG    (MC_HDCP_REG_BASE + 0x01A4)
#define HDCP_CH5_SRC_SADDR_REG         (MC_HDCP_REG_BASE + 0x01A8)
#define HDCP_CH5_DES_SADDR_REG         (MC_HDCP_REG_BASE + 0x01AC)
#define HDCP_CH5_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x01B0)
#define HDCP_CH5_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x01B4)
#define HDCP_CH5_DEBUG_REG             (MC_HDCP_REG_BASE + 0x01B8)

#define HDCP_CH6_ENABLE_REG            (MC_HDCP_REG_BASE + 0x01C0)
#define HDCP_CH6_ADD_POE_WDATA2_REG    (MC_HDCP_REG_BASE + 0x01C4)
#define HDCP_CH6_SRC_SADDR_REG         (MC_HDCP_REG_BASE + 0x01C8)
#define HDCP_CH6_DES_SADDR_REG         (MC_HDCP_REG_BASE + 0x01CC)
#define HDCP_CH6_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x01D0)
#define HDCP_CH6_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x01D4)
#define HDCP_CH6_DEBUG_REG             (MC_HDCP_REG_BASE + 0x01D8)

#define HDCP_CH7_ENABLE_REG            (MC_HDCP_REG_BASE + 0x01E0)
#define HDCP_CH7_ADD_POE_WDATA2_REG    (MC_HDCP_REG_BASE + 0x01E4)
#define HDCP_CH7_SRC_SADDR_REG         (MC_HDCP_REG_BASE + 0x01E8)
#define HDCP_CH7_DES_SADDR_REG         (MC_HDCP_REG_BASE + 0x01EC)
#define HDCP_CH7_CONFIG0_REG           (MC_HDCP_REG_BASE + 0x01F0)
#define HDCP_CH7_CONFIG1_REG           (MC_HDCP_REG_BASE + 0x01F4)
#define HDCP_CH7_DEBUG_REG             (MC_HDCP_REG_BASE + 0x01F8)

/******************************************************************************/
/*                                    外设TIMER寄存器                         */
/******************************************************************************/
#define MC_GLOBAL_TIMER_BASE      (0x20009000UL + 0x80000000UL)
#define MC_GLOBAL_TIMER0_LOAD     (MC_GLOBAL_TIMER_BASE + 0x00)
#define MC_GLOBAL_TIMER0_VALUE    (MC_GLOBAL_TIMER_BASE + 0x04)
#define MC_GLOBAL_TIMER0_CONTRL   (MC_GLOBAL_TIMER_BASE + 0x08)
#define MC_GLOBAL_TIMER0_INCLR    (MC_GLOBAL_TIMER_BASE + 0x0C)
#define MC_GLOBAL_TIMER0_RIS      (MC_GLOBAL_TIMER_BASE + 0x10)
#define MC_GLOBAL_TIMER0_MIS      (MC_GLOBAL_TIMER_BASE + 0x14)
#define MC_GLOBAL_TIMER0_BGLOAD   (MC_GLOBAL_TIMER_BASE + 0x18)
#define MC_GLOBAL_TIMER1_LOAD     (MC_GLOBAL_TIMER_BASE + 0x20)
#define MC_GLOBAL_TIMER1_VALUE    (MC_GLOBAL_TIMER_BASE + 0x24)
#define MC_GLOBAL_TIMER1_CONTRL   (MC_GLOBAL_TIMER_BASE + 0x28)
#define MC_GLOBAL_TIMER1_INCLR    (MC_GLOBAL_TIMER_BASE + 0x2C)
#define MC_GLOBAL_TIMER1_RIS      (MC_GLOBAL_TIMER_BASE + 0x30)
#define MC_GLOBAL_TIMER1_MIS      (MC_GLOBAL_TIMER_BASE + 0x34)
#define MC_GLOBAL_TIMER1_BGLOAD   (MC_GLOBAL_TIMER_BASE + 0x38)

/* GIC 模块寄存器基地址 */
#if 0
#define SRE_GIC_BASE                               (0x10c00000)
#else
#define SRE_GIC_BASE                               (0xe0c00000)
#endif
/******************************************************************************/
/*                      PhosphorV650 GIC 寄存器定义                           */
/******************************************************************************/
#define OS_GIC_GICD_CTLR_REG                      (SRE_GIC_BASE + 0x1000)          /* Distributor的使能控制 */
#define OS_GIC_GICD_TYPER_REG                     (SRE_GIC_BASE + 0x1004)          /* GIC的配置信息，包括是否使用安全扩展，最大锁定的SPI数，最大支持的中断数等信息 */
#define OS_GIC_GICD_IIDR_REG                      (SRE_GIC_BASE + 0x1008)          /* GIC身份寄存器 */
#define OS_GIC_GICD_IGROUPR0_REG                  (SRE_GIC_BASE + 0x1080)          /* 标识中断分组至Group0或Group1 */
#define OS_GIC_GICD_ISENABLER0_REG                (SRE_GIC_BASE + 0x1100)          /* 单个中断的使能寄存器，决定是否发给Cpu Interface。 */
#define OS_GIC_GICD_ICENABLER0_REG                (SRE_GIC_BASE + 0x1180)          /* 单个中断的清除使能的寄存器，确定是否发给CPU Interface。n的值由GICD_TYPER.ITLinesNumber决定,n=0 */
#define OS_GIC_GICD_ISPENDR0_REG                  (SRE_GIC_BASE + 0x1200)          /* 单个中断设置pending状态的控制信号寄存器。 */
#define OS_GIC_GICD_ICPENDR0_REG                  (SRE_GIC_BASE + 0x1280)          /* 单个中断清除pending状态的控制信号寄存器。 */
#define OS_GIC_GICD_ISACTIVER0_REG                (SRE_GIC_BASE + 0x1300)          /* 单个中断设置active状态的控制信号寄存器。 */
#define OS_GIC_GICD_ICACTIVER0_REG                (SRE_GIC_BASE + 0x1380)          /* 单个中断清除active状态的控制信号寄存器，这些寄存器在需要保存和回复GIC的状态时使用。 */
#define SRE_GIC_GICD_IPRIORITYR0TO3_NS_0_REG       (SRE_GIC_BASE + 0x1400)          /* 每8bit对应一个中断的优先级。x{0,3} */
#define SRE_GIC_GICD_IPRIORITYR0TO3_NS_1_REG       (SRE_GIC_BASE + 0x1404)          /* 每8bit对应一个中断的优先级。x{0,3} */
#define SRE_GIC_GICD_IPRIORITYR0TO3_NS_2_REG       (SRE_GIC_BASE + 0x1408)          /* 每8bit对应一个中断的优先级。x{0,3} */
#define SRE_GIC_GICD_IPRIORITYR0TO3_NS_3_REG       (SRE_GIC_BASE + 0x140C)          /* 每8bit对应一个中断的优先级。x{0,3} */
#define OS_GIC_GICD_IPRIORITYR0TO3_S_0_REG        (SRE_GIC_BASE + 0x1400)          /* 每8bit对应一个中断的优先级。x{0,3} */
#define SRE_GIC_GICD_IPRIORITYR0TO3_S_1_REG        (SRE_GIC_BASE + 0x1404)          /* 每8bit对应一个中断的优先级。x{0,3} */
#define SRE_GIC_GICD_IPRIORITYR0TO3_S_2_REG        (SRE_GIC_BASE + 0x1408)          /* 每8bit对应一个中断的优先级。x{0,3} */
#define SRE_GIC_GICD_IPRIORITYR0TO3_S_3_REG        (SRE_GIC_BASE + 0x140C)          /* 每8bit对应一个中断的优先级。x{0,3} */
#define SRE_GIC_GICD_IPRIORITYR6_NS_REG            (SRE_GIC_BASE + 0x1418)          /* 每8bit对应一个中断的优先级。 */
#define SRE_GIC_GICD_IPRIORITYR6_S_REG             (SRE_GIC_BASE + 0x1418)          /* 每8bit对应一个中断的优先级。 */
#define SRE_GIC_GICD_IPRIORITYR7_NS_REG            (SRE_GIC_BASE + 0x141C)          /* 每8bit对应一个中断的优先级。 */
#define SRE_GIC_GICD_IPRIORITYR7_S_REG             (SRE_GIC_BASE + 0x141C)          /* 每8bit对应一个中断的优先级。 */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_0_REG     (SRE_GIC_BASE + 0x1420)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_1_REG     (SRE_GIC_BASE + 0x1424)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_2_REG     (SRE_GIC_BASE + 0x1428)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_3_REG     (SRE_GIC_BASE + 0x142C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_4_REG     (SRE_GIC_BASE + 0x1430)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_5_REG     (SRE_GIC_BASE + 0x1434)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_6_REG     (SRE_GIC_BASE + 0x1438)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_7_REG     (SRE_GIC_BASE + 0x143C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_8_REG     (SRE_GIC_BASE + 0x1440)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_9_REG     (SRE_GIC_BASE + 0x1444)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_10_REG    (SRE_GIC_BASE + 0x1448)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_11_REG    (SRE_GIC_BASE + 0x144C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_12_REG    (SRE_GIC_BASE + 0x1450)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_13_REG    (SRE_GIC_BASE + 0x1454)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_14_REG    (SRE_GIC_BASE + 0x1458)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_15_REG    (SRE_GIC_BASE + 0x145C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_16_REG    (SRE_GIC_BASE + 0x1460)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_17_REG    (SRE_GIC_BASE + 0x1464)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_18_REG    (SRE_GIC_BASE + 0x1468)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_19_REG    (SRE_GIC_BASE + 0x146C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_20_REG    (SRE_GIC_BASE + 0x1470)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_21_REG    (SRE_GIC_BASE + 0x1474)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_22_REG    (SRE_GIC_BASE + 0x1478)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_23_REG    (SRE_GIC_BASE + 0x147C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_24_REG    (SRE_GIC_BASE + 0x1480)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_25_REG    (SRE_GIC_BASE + 0x1484)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_26_REG    (SRE_GIC_BASE + 0x1488)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_27_REG    (SRE_GIC_BASE + 0x148C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_28_REG    (SRE_GIC_BASE + 0x1490)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_29_REG    (SRE_GIC_BASE + 0x1494)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_30_REG    (SRE_GIC_BASE + 0x1498)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_31_REG    (SRE_GIC_BASE + 0x149C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_32_REG    (SRE_GIC_BASE + 0x14A0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_33_REG    (SRE_GIC_BASE + 0x14A4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_34_REG    (SRE_GIC_BASE + 0x14A8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_35_REG    (SRE_GIC_BASE + 0x14AC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_36_REG    (SRE_GIC_BASE + 0x14B0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_37_REG    (SRE_GIC_BASE + 0x14B4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_38_REG    (SRE_GIC_BASE + 0x14B8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_39_REG    (SRE_GIC_BASE + 0x14BC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_40_REG    (SRE_GIC_BASE + 0x14C0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_41_REG    (SRE_GIC_BASE + 0x14C4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_42_REG    (SRE_GIC_BASE + 0x14C8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_43_REG    (SRE_GIC_BASE + 0x14CC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_44_REG    (SRE_GIC_BASE + 0x14D0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_45_REG    (SRE_GIC_BASE + 0x14D4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_46_REG    (SRE_GIC_BASE + 0x14D8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_47_REG    (SRE_GIC_BASE + 0x14DC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_48_REG    (SRE_GIC_BASE + 0x14E0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_49_REG    (SRE_GIC_BASE + 0x14E4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_50_REG    (SRE_GIC_BASE + 0x14E8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_51_REG    (SRE_GIC_BASE + 0x14EC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_52_REG    (SRE_GIC_BASE + 0x14F0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_53_REG    (SRE_GIC_BASE + 0x14F4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_54_REG    (SRE_GIC_BASE + 0x14F8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_55_REG    (SRE_GIC_BASE + 0x14FC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_56_REG    (SRE_GIC_BASE + 0x1500)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_57_REG    (SRE_GIC_BASE + 0x1504)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_58_REG    (SRE_GIC_BASE + 0x1508)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_59_REG    (SRE_GIC_BASE + 0x150C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_60_REG    (SRE_GIC_BASE + 0x1510)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_61_REG    (SRE_GIC_BASE + 0x1514)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_62_REG    (SRE_GIC_BASE + 0x1518)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_63_REG    (SRE_GIC_BASE + 0x151C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_64_REG    (SRE_GIC_BASE + 0x1520)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_65_REG    (SRE_GIC_BASE + 0x1524)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_66_REG    (SRE_GIC_BASE + 0x1528)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_67_REG    (SRE_GIC_BASE + 0x152C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_68_REG    (SRE_GIC_BASE + 0x1530)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_69_REG    (SRE_GIC_BASE + 0x1534)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_70_REG    (SRE_GIC_BASE + 0x1538)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_71_REG    (SRE_GIC_BASE + 0x153C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_72_REG    (SRE_GIC_BASE + 0x1540)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_73_REG    (SRE_GIC_BASE + 0x1544)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_74_REG    (SRE_GIC_BASE + 0x1548)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_75_REG    (SRE_GIC_BASE + 0x154C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_76_REG    (SRE_GIC_BASE + 0x1550)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_77_REG    (SRE_GIC_BASE + 0x1554)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_78_REG    (SRE_GIC_BASE + 0x1558)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_79_REG    (SRE_GIC_BASE + 0x155C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_80_REG    (SRE_GIC_BASE + 0x1560)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_81_REG    (SRE_GIC_BASE + 0x1564)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_82_REG    (SRE_GIC_BASE + 0x1568)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_83_REG    (SRE_GIC_BASE + 0x156C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_84_REG    (SRE_GIC_BASE + 0x1570)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_85_REG    (SRE_GIC_BASE + 0x1574)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_86_REG    (SRE_GIC_BASE + 0x1578)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_87_REG    (SRE_GIC_BASE + 0x157C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_88_REG    (SRE_GIC_BASE + 0x1580)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_89_REG    (SRE_GIC_BASE + 0x1584)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_90_REG    (SRE_GIC_BASE + 0x1588)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_91_REG    (SRE_GIC_BASE + 0x158C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_92_REG    (SRE_GIC_BASE + 0x1590)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_93_REG    (SRE_GIC_BASE + 0x1594)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_94_REG    (SRE_GIC_BASE + 0x1598)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_95_REG    (SRE_GIC_BASE + 0x159C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_96_REG    (SRE_GIC_BASE + 0x15A0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_97_REG    (SRE_GIC_BASE + 0x15A4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_98_REG    (SRE_GIC_BASE + 0x15A8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_99_REG    (SRE_GIC_BASE + 0x15AC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_100_REG   (SRE_GIC_BASE + 0x15B0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_101_REG   (SRE_GIC_BASE + 0x15B4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_102_REG   (SRE_GIC_BASE + 0x15B8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_103_REG   (SRE_GIC_BASE + 0x15BC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_104_REG   (SRE_GIC_BASE + 0x15C0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_105_REG   (SRE_GIC_BASE + 0x15C4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_106_REG   (SRE_GIC_BASE + 0x15C8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_107_REG   (SRE_GIC_BASE + 0x15CC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_108_REG   (SRE_GIC_BASE + 0x15D0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_109_REG   (SRE_GIC_BASE + 0x15D4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_110_REG   (SRE_GIC_BASE + 0x15D8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_NS_111_REG   (SRE_GIC_BASE + 0x15DC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_0_REG      (SRE_GIC_BASE + 0x1420)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_1_REG      (SRE_GIC_BASE + 0x1424)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_2_REG      (SRE_GIC_BASE + 0x1428)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_3_REG      (SRE_GIC_BASE + 0x142C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_4_REG      (SRE_GIC_BASE + 0x1430)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_5_REG      (SRE_GIC_BASE + 0x1434)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_6_REG      (SRE_GIC_BASE + 0x1438)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_7_REG      (SRE_GIC_BASE + 0x143C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_8_REG      (SRE_GIC_BASE + 0x1440)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_9_REG      (SRE_GIC_BASE + 0x1444)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_10_REG     (SRE_GIC_BASE + 0x1448)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_11_REG     (SRE_GIC_BASE + 0x144C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_12_REG     (SRE_GIC_BASE + 0x1450)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_13_REG     (SRE_GIC_BASE + 0x1454)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_14_REG     (SRE_GIC_BASE + 0x1458)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_15_REG     (SRE_GIC_BASE + 0x145C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_16_REG     (SRE_GIC_BASE + 0x1460)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_17_REG     (SRE_GIC_BASE + 0x1464)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_18_REG     (SRE_GIC_BASE + 0x1468)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_19_REG     (SRE_GIC_BASE + 0x146C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_20_REG     (SRE_GIC_BASE + 0x1470)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_21_REG     (SRE_GIC_BASE + 0x1474)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_22_REG     (SRE_GIC_BASE + 0x1478)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_23_REG     (SRE_GIC_BASE + 0x147C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_24_REG     (SRE_GIC_BASE + 0x1480)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_25_REG     (SRE_GIC_BASE + 0x1484)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_26_REG     (SRE_GIC_BASE + 0x1488)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_27_REG     (SRE_GIC_BASE + 0x148C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_28_REG     (SRE_GIC_BASE + 0x1490)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_29_REG     (SRE_GIC_BASE + 0x1494)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_30_REG     (SRE_GIC_BASE + 0x1498)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_31_REG     (SRE_GIC_BASE + 0x149C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_32_REG     (SRE_GIC_BASE + 0x14A0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_33_REG     (SRE_GIC_BASE + 0x14A4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_34_REG     (SRE_GIC_BASE + 0x14A8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_35_REG     (SRE_GIC_BASE + 0x14AC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_36_REG     (SRE_GIC_BASE + 0x14B0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_37_REG     (SRE_GIC_BASE + 0x14B4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_38_REG     (SRE_GIC_BASE + 0x14B8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_39_REG     (SRE_GIC_BASE + 0x14BC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_40_REG     (SRE_GIC_BASE + 0x14C0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_41_REG     (SRE_GIC_BASE + 0x14C4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_42_REG     (SRE_GIC_BASE + 0x14C8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_43_REG     (SRE_GIC_BASE + 0x14CC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_44_REG     (SRE_GIC_BASE + 0x14D0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_45_REG     (SRE_GIC_BASE + 0x14D4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_46_REG     (SRE_GIC_BASE + 0x14D8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_47_REG     (SRE_GIC_BASE + 0x14DC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_48_REG     (SRE_GIC_BASE + 0x14E0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_49_REG     (SRE_GIC_BASE + 0x14E4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_50_REG     (SRE_GIC_BASE + 0x14E8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_51_REG     (SRE_GIC_BASE + 0x14EC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_52_REG     (SRE_GIC_BASE + 0x14F0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_53_REG     (SRE_GIC_BASE + 0x14F4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_54_REG     (SRE_GIC_BASE + 0x14F8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_55_REG     (SRE_GIC_BASE + 0x14FC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_56_REG     (SRE_GIC_BASE + 0x1500)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_57_REG     (SRE_GIC_BASE + 0x1504)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_58_REG     (SRE_GIC_BASE + 0x1508)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_59_REG     (SRE_GIC_BASE + 0x150C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_60_REG     (SRE_GIC_BASE + 0x1510)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_61_REG     (SRE_GIC_BASE + 0x1514)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_62_REG     (SRE_GIC_BASE + 0x1518)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_63_REG     (SRE_GIC_BASE + 0x151C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_64_REG     (SRE_GIC_BASE + 0x1520)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_65_REG     (SRE_GIC_BASE + 0x1524)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_66_REG     (SRE_GIC_BASE + 0x1528)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_67_REG     (SRE_GIC_BASE + 0x152C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_68_REG     (SRE_GIC_BASE + 0x1530)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_69_REG     (SRE_GIC_BASE + 0x1534)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_70_REG     (SRE_GIC_BASE + 0x1538)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_71_REG     (SRE_GIC_BASE + 0x153C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_72_REG     (SRE_GIC_BASE + 0x1540)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_73_REG     (SRE_GIC_BASE + 0x1544)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_74_REG     (SRE_GIC_BASE + 0x1548)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_75_REG     (SRE_GIC_BASE + 0x154C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_76_REG     (SRE_GIC_BASE + 0x1550)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_77_REG     (SRE_GIC_BASE + 0x1554)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_78_REG     (SRE_GIC_BASE + 0x1558)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_79_REG     (SRE_GIC_BASE + 0x155C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_80_REG     (SRE_GIC_BASE + 0x1560)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_81_REG     (SRE_GIC_BASE + 0x1564)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_82_REG     (SRE_GIC_BASE + 0x1568)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_83_REG     (SRE_GIC_BASE + 0x156C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_84_REG     (SRE_GIC_BASE + 0x1570)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_85_REG     (SRE_GIC_BASE + 0x1574)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_86_REG     (SRE_GIC_BASE + 0x1578)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_87_REG     (SRE_GIC_BASE + 0x157C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_88_REG     (SRE_GIC_BASE + 0x1580)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_89_REG     (SRE_GIC_BASE + 0x1584)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_90_REG     (SRE_GIC_BASE + 0x1588)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_91_REG     (SRE_GIC_BASE + 0x158C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_92_REG     (SRE_GIC_BASE + 0x1590)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_93_REG     (SRE_GIC_BASE + 0x1594)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_94_REG     (SRE_GIC_BASE + 0x1598)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_95_REG     (SRE_GIC_BASE + 0x159C)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_96_REG     (SRE_GIC_BASE + 0x15A0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_97_REG     (SRE_GIC_BASE + 0x15A4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_98_REG     (SRE_GIC_BASE + 0x15A8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_99_REG     (SRE_GIC_BASE + 0x15AC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_100_REG    (SRE_GIC_BASE + 0x15B0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_101_REG    (SRE_GIC_BASE + 0x15B4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_102_REG    (SRE_GIC_BASE + 0x15B8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_103_REG    (SRE_GIC_BASE + 0x15BC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_104_REG    (SRE_GIC_BASE + 0x15C0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_105_REG    (SRE_GIC_BASE + 0x15C4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_106_REG    (SRE_GIC_BASE + 0x15C8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_107_REG    (SRE_GIC_BASE + 0x15CC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_108_REG    (SRE_GIC_BASE + 0x15D0)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_109_REG    (SRE_GIC_BASE + 0x15D4)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_110_REG    (SRE_GIC_BASE + 0x15D8)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define SRE_GIC_GICD_IPRIORITYR8TO119_S_111_REG    (SRE_GIC_BASE + 0x15DC)          /* 每8bit对应一个中断的优先级。n{0,111} */
#define OS_GIC_GICD_ITARGETSRZ_0_REG              (SRE_GIC_BASE + 0x1800)          /* 每16bit对应一个中断的所有相应的CPU Interface。此处的z范围为0～7，即对应的中断是SGIs。z{0,7}。 */
#define SRE_GIC_GICD_ITARGETSRZ_1_REG              (SRE_GIC_BASE + 0x1804)          /* 每16bit对应一个中断的所有相应的CPU Interface。此处的z范围为0～7，即对应的中断是SGIs。z{0,7}。 */
#define SRE_GIC_GICD_ITARGETSRZ_2_REG              (SRE_GIC_BASE + 0x1808)          /* 每16bit对应一个中断的所有相应的CPU Interface。此处的z范围为0～7，即对应的中断是SGIs。z{0,7}。 */
#define SRE_GIC_GICD_ITARGETSRZ_3_REG              (SRE_GIC_BASE + 0x180C)          /* 每16bit对应一个中断的所有相应的CPU Interface。此处的z范围为0～7，即对应的中断是SGIs。z{0,7}。 */
#define SRE_GIC_GICD_ITARGETSRZ_4_REG              (SRE_GIC_BASE + 0x1810)          /* 每16bit对应一个中断的所有相应的CPU Interface。此处的z范围为0～7，即对应的中断是SGIs。z{0,7}。 */
#define SRE_GIC_GICD_ITARGETSRZ_5_REG              (SRE_GIC_BASE + 0x1814)          /* 每16bit对应一个中断的所有相应的CPU Interface。此处的z范围为0～7，即对应的中断是SGIs。z{0,7}。 */
#define SRE_GIC_GICD_ITARGETSRZ_6_REG              (SRE_GIC_BASE + 0x1818)          /* 每16bit对应一个中断的所有相应的CPU Interface。此处的z范围为0～7，即对应的中断是SGIs。z{0,7}。 */
#define SRE_GIC_GICD_ITARGETSRZ_7_REG              (SRE_GIC_BASE + 0x181C)          /* 每16bit对应一个中断的所有相应的CPU Interface。此处的z范围为0～7，即对应的中断是SGIs。z{0,7}。 */
#define SRE_GIC_GICD_ITARGETSR12_REG               (SRE_GIC_BASE + 0x1830)          /* 每16bit对应一个中断的所有相应的CPU Interface。。 */
#define SRE_GIC_GICD_ITARGETSRH_0_REG              (SRE_GIC_BASE + 0x1834)          /* 每16bit对应一个中断的所有相应的CPU Interface。此处的h范围为13～15，即对应的中断是PPIs。h{0,2} */
#define SRE_GIC_GICD_ITARGETSRH_1_REG              (SRE_GIC_BASE + 0x1838)          /* 每16bit对应一个中断的所有相应的CPU Interface。此处的h范围为13～15，即对应的中断是PPIs。h{0,2} */
#define SRE_GIC_GICD_ITARGETSRH_2_REG              (SRE_GIC_BASE + 0x183C)          /* 每16bit对应一个中断的所有相应的CPU Interface。此处的h范围为13～15，即对应的中断是PPIs。h{0,2} */
#define SRE_GIC_GICD_ITARGETSRY_0_REG              (SRE_GIC_BASE + 0x1840)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_1_REG              (SRE_GIC_BASE + 0x1844)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_2_REG              (SRE_GIC_BASE + 0x1848)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_3_REG              (SRE_GIC_BASE + 0x184C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_4_REG              (SRE_GIC_BASE + 0x1850)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_5_REG              (SRE_GIC_BASE + 0x1854)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_6_REG              (SRE_GIC_BASE + 0x1858)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_7_REG              (SRE_GIC_BASE + 0x185C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_8_REG              (SRE_GIC_BASE + 0x1860)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_9_REG              (SRE_GIC_BASE + 0x1864)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_10_REG             (SRE_GIC_BASE + 0x1868)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_11_REG             (SRE_GIC_BASE + 0x186C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_12_REG             (SRE_GIC_BASE + 0x1870)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_13_REG             (SRE_GIC_BASE + 0x1874)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_14_REG             (SRE_GIC_BASE + 0x1878)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_15_REG             (SRE_GIC_BASE + 0x187C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_16_REG             (SRE_GIC_BASE + 0x1880)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_17_REG             (SRE_GIC_BASE + 0x1884)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_18_REG             (SRE_GIC_BASE + 0x1888)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_19_REG             (SRE_GIC_BASE + 0x188C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_20_REG             (SRE_GIC_BASE + 0x1890)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_21_REG             (SRE_GIC_BASE + 0x1894)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_22_REG             (SRE_GIC_BASE + 0x1898)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_23_REG             (SRE_GIC_BASE + 0x189C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_24_REG             (SRE_GIC_BASE + 0x18A0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_25_REG             (SRE_GIC_BASE + 0x18A4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_26_REG             (SRE_GIC_BASE + 0x18A8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_27_REG             (SRE_GIC_BASE + 0x18AC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_28_REG             (SRE_GIC_BASE + 0x18B0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_29_REG             (SRE_GIC_BASE + 0x18B4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_30_REG             (SRE_GIC_BASE + 0x18B8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_31_REG             (SRE_GIC_BASE + 0x18BC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_32_REG             (SRE_GIC_BASE + 0x18C0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_33_REG             (SRE_GIC_BASE + 0x18C4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_34_REG             (SRE_GIC_BASE + 0x18C8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_35_REG             (SRE_GIC_BASE + 0x18CC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_36_REG             (SRE_GIC_BASE + 0x18D0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_37_REG             (SRE_GIC_BASE + 0x18D4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_38_REG             (SRE_GIC_BASE + 0x18D8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_39_REG             (SRE_GIC_BASE + 0x18DC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_40_REG             (SRE_GIC_BASE + 0x18E0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_41_REG             (SRE_GIC_BASE + 0x18E4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_42_REG             (SRE_GIC_BASE + 0x18E8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_43_REG             (SRE_GIC_BASE + 0x18EC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_44_REG             (SRE_GIC_BASE + 0x18F0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_45_REG             (SRE_GIC_BASE + 0x18F4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_46_REG             (SRE_GIC_BASE + 0x18F8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_47_REG             (SRE_GIC_BASE + 0x18FC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_48_REG             (SRE_GIC_BASE + 0x1900)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_49_REG             (SRE_GIC_BASE + 0x1904)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_50_REG             (SRE_GIC_BASE + 0x1908)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_51_REG             (SRE_GIC_BASE + 0x190C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_52_REG             (SRE_GIC_BASE + 0x1910)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_53_REG             (SRE_GIC_BASE + 0x1914)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_54_REG             (SRE_GIC_BASE + 0x1918)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_55_REG             (SRE_GIC_BASE + 0x191C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_56_REG             (SRE_GIC_BASE + 0x1920)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_57_REG             (SRE_GIC_BASE + 0x1924)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_58_REG             (SRE_GIC_BASE + 0x1928)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_59_REG             (SRE_GIC_BASE + 0x192C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_60_REG             (SRE_GIC_BASE + 0x1930)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_61_REG             (SRE_GIC_BASE + 0x1934)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_62_REG             (SRE_GIC_BASE + 0x1938)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_63_REG             (SRE_GIC_BASE + 0x193C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_64_REG             (SRE_GIC_BASE + 0x1940)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_65_REG             (SRE_GIC_BASE + 0x1944)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_66_REG             (SRE_GIC_BASE + 0x1948)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_67_REG             (SRE_GIC_BASE + 0x194C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_68_REG             (SRE_GIC_BASE + 0x1950)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_69_REG             (SRE_GIC_BASE + 0x1954)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_70_REG             (SRE_GIC_BASE + 0x1958)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_71_REG             (SRE_GIC_BASE + 0x195C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_72_REG             (SRE_GIC_BASE + 0x1960)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_73_REG             (SRE_GIC_BASE + 0x1964)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_74_REG             (SRE_GIC_BASE + 0x1968)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_75_REG             (SRE_GIC_BASE + 0x196C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_76_REG             (SRE_GIC_BASE + 0x1970)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_77_REG             (SRE_GIC_BASE + 0x1974)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_78_REG             (SRE_GIC_BASE + 0x1978)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_79_REG             (SRE_GIC_BASE + 0x197C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_80_REG             (SRE_GIC_BASE + 0x1980)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_81_REG             (SRE_GIC_BASE + 0x1984)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_82_REG             (SRE_GIC_BASE + 0x1988)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_83_REG             (SRE_GIC_BASE + 0x198C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_84_REG             (SRE_GIC_BASE + 0x1990)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_85_REG             (SRE_GIC_BASE + 0x1994)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_86_REG             (SRE_GIC_BASE + 0x1998)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_87_REG             (SRE_GIC_BASE + 0x199C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_88_REG             (SRE_GIC_BASE + 0x19A0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_89_REG             (SRE_GIC_BASE + 0x19A4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_90_REG             (SRE_GIC_BASE + 0x19A8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_91_REG             (SRE_GIC_BASE + 0x19AC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_92_REG             (SRE_GIC_BASE + 0x19B0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_93_REG             (SRE_GIC_BASE + 0x19B4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_94_REG             (SRE_GIC_BASE + 0x19B8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_95_REG             (SRE_GIC_BASE + 0x19BC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_96_REG             (SRE_GIC_BASE + 0x19C0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_97_REG             (SRE_GIC_BASE + 0x19C4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_98_REG             (SRE_GIC_BASE + 0x19C8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_99_REG             (SRE_GIC_BASE + 0x19CC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_100_REG            (SRE_GIC_BASE + 0x19D0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_101_REG            (SRE_GIC_BASE + 0x19D4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_102_REG            (SRE_GIC_BASE + 0x19D8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_103_REG            (SRE_GIC_BASE + 0x19DC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_104_REG            (SRE_GIC_BASE + 0x19E0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_105_REG            (SRE_GIC_BASE + 0x19E4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_106_REG            (SRE_GIC_BASE + 0x19E8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_107_REG            (SRE_GIC_BASE + 0x19EC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_108_REG            (SRE_GIC_BASE + 0x19F0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_109_REG            (SRE_GIC_BASE + 0x19F4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_110_REG            (SRE_GIC_BASE + 0x19F8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_111_REG            (SRE_GIC_BASE + 0x19FC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_112_REG            (SRE_GIC_BASE + 0x1A00)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_113_REG            (SRE_GIC_BASE + 0x1A04)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_114_REG            (SRE_GIC_BASE + 0x1A08)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_115_REG            (SRE_GIC_BASE + 0x1A0C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_116_REG            (SRE_GIC_BASE + 0x1A10)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_117_REG            (SRE_GIC_BASE + 0x1A14)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_118_REG            (SRE_GIC_BASE + 0x1A18)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_119_REG            (SRE_GIC_BASE + 0x1A1C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_120_REG            (SRE_GIC_BASE + 0x1A20)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_121_REG            (SRE_GIC_BASE + 0x1A24)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_122_REG            (SRE_GIC_BASE + 0x1A28)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_123_REG            (SRE_GIC_BASE + 0x1A2C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_124_REG            (SRE_GIC_BASE + 0x1A30)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_125_REG            (SRE_GIC_BASE + 0x1A34)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_126_REG            (SRE_GIC_BASE + 0x1A38)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_127_REG            (SRE_GIC_BASE + 0x1A3C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_128_REG            (SRE_GIC_BASE + 0x1A40)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_129_REG            (SRE_GIC_BASE + 0x1A44)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_130_REG            (SRE_GIC_BASE + 0x1A48)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_131_REG            (SRE_GIC_BASE + 0x1A4C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_132_REG            (SRE_GIC_BASE + 0x1A50)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_133_REG            (SRE_GIC_BASE + 0x1A54)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_134_REG            (SRE_GIC_BASE + 0x1A58)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_135_REG            (SRE_GIC_BASE + 0x1A5C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_136_REG            (SRE_GIC_BASE + 0x1A60)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_137_REG            (SRE_GIC_BASE + 0x1A64)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_138_REG            (SRE_GIC_BASE + 0x1A68)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_139_REG            (SRE_GIC_BASE + 0x1A6C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_140_REG            (SRE_GIC_BASE + 0x1A70)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_141_REG            (SRE_GIC_BASE + 0x1A74)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_142_REG            (SRE_GIC_BASE + 0x1A78)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_143_REG            (SRE_GIC_BASE + 0x1A7C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_144_REG            (SRE_GIC_BASE + 0x1A80)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_145_REG            (SRE_GIC_BASE + 0x1A84)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_146_REG            (SRE_GIC_BASE + 0x1A88)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_147_REG            (SRE_GIC_BASE + 0x1A8C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_148_REG            (SRE_GIC_BASE + 0x1A90)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_149_REG            (SRE_GIC_BASE + 0x1A94)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_150_REG            (SRE_GIC_BASE + 0x1A98)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_151_REG            (SRE_GIC_BASE + 0x1A9C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_152_REG            (SRE_GIC_BASE + 0x1AA0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_153_REG            (SRE_GIC_BASE + 0x1AA4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_154_REG            (SRE_GIC_BASE + 0x1AA8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_155_REG            (SRE_GIC_BASE + 0x1AAC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_156_REG            (SRE_GIC_BASE + 0x1AB0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_157_REG            (SRE_GIC_BASE + 0x1AB4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_158_REG            (SRE_GIC_BASE + 0x1AB8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_159_REG            (SRE_GIC_BASE + 0x1ABC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_160_REG            (SRE_GIC_BASE + 0x1AC0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_161_REG            (SRE_GIC_BASE + 0x1AC4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_162_REG            (SRE_GIC_BASE + 0x1AC8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_163_REG            (SRE_GIC_BASE + 0x1ACC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_164_REG            (SRE_GIC_BASE + 0x1AD0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_165_REG            (SRE_GIC_BASE + 0x1AD4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_166_REG            (SRE_GIC_BASE + 0x1AD8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_167_REG            (SRE_GIC_BASE + 0x1ADC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_168_REG            (SRE_GIC_BASE + 0x1AE0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_169_REG            (SRE_GIC_BASE + 0x1AE4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_170_REG            (SRE_GIC_BASE + 0x1AE8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_171_REG            (SRE_GIC_BASE + 0x1AEC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_172_REG            (SRE_GIC_BASE + 0x1AF0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_173_REG            (SRE_GIC_BASE + 0x1AF4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_174_REG            (SRE_GIC_BASE + 0x1AF8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_175_REG            (SRE_GIC_BASE + 0x1AFC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_176_REG            (SRE_GIC_BASE + 0x1B00)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_177_REG            (SRE_GIC_BASE + 0x1B04)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_178_REG            (SRE_GIC_BASE + 0x1B08)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_179_REG            (SRE_GIC_BASE + 0x1B0C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_180_REG            (SRE_GIC_BASE + 0x1B10)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_181_REG            (SRE_GIC_BASE + 0x1B14)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_182_REG            (SRE_GIC_BASE + 0x1B18)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_183_REG            (SRE_GIC_BASE + 0x1B1C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_184_REG            (SRE_GIC_BASE + 0x1B20)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_185_REG            (SRE_GIC_BASE + 0x1B24)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_186_REG            (SRE_GIC_BASE + 0x1B28)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_187_REG            (SRE_GIC_BASE + 0x1B2C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_188_REG            (SRE_GIC_BASE + 0x1B30)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_189_REG            (SRE_GIC_BASE + 0x1B34)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_190_REG            (SRE_GIC_BASE + 0x1B38)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_191_REG            (SRE_GIC_BASE + 0x1B3C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_192_REG            (SRE_GIC_BASE + 0x1B40)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_193_REG            (SRE_GIC_BASE + 0x1B44)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_194_REG            (SRE_GIC_BASE + 0x1B48)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_195_REG            (SRE_GIC_BASE + 0x1B4C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_196_REG            (SRE_GIC_BASE + 0x1B50)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_197_REG            (SRE_GIC_BASE + 0x1B54)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_198_REG            (SRE_GIC_BASE + 0x1B58)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_199_REG            (SRE_GIC_BASE + 0x1B5C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_200_REG            (SRE_GIC_BASE + 0x1B60)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_201_REG            (SRE_GIC_BASE + 0x1B64)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_202_REG            (SRE_GIC_BASE + 0x1B68)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_203_REG            (SRE_GIC_BASE + 0x1B6C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_204_REG            (SRE_GIC_BASE + 0x1B70)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_205_REG            (SRE_GIC_BASE + 0x1B74)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_206_REG            (SRE_GIC_BASE + 0x1B78)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_207_REG            (SRE_GIC_BASE + 0x1B7C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_208_REG            (SRE_GIC_BASE + 0x1B80)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_209_REG            (SRE_GIC_BASE + 0x1B84)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_210_REG            (SRE_GIC_BASE + 0x1B88)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_211_REG            (SRE_GIC_BASE + 0x1B8C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_212_REG            (SRE_GIC_BASE + 0x1B90)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_213_REG            (SRE_GIC_BASE + 0x1B94)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_214_REG            (SRE_GIC_BASE + 0x1B98)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_215_REG            (SRE_GIC_BASE + 0x1B9C)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_216_REG            (SRE_GIC_BASE + 0x1BA0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_217_REG            (SRE_GIC_BASE + 0x1BA4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_218_REG            (SRE_GIC_BASE + 0x1BA8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_219_REG            (SRE_GIC_BASE + 0x1BAC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_220_REG            (SRE_GIC_BASE + 0x1BB0)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_221_REG            (SRE_GIC_BASE + 0x1BB4)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_222_REG            (SRE_GIC_BASE + 0x1BB8)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ITARGETSRY_223_REG            (SRE_GIC_BASE + 0x1BBC)          /* 该寄存器每16bit表示一个中断的所有相应的CPU Interface。此处的y>15。即对应的中断是SPIs。y的范围是y{0，223} */
#define SRE_GIC_GICD_ICFGR0_REG                    (SRE_GIC_BASE + 0x1C00)          /* 该寄存器每2bit表示一个SGI中断是电平敏感还是边沿触发 */
#define SRE_GIC_GICD_ICFGR1_REG                    (SRE_GIC_BASE + 0x1C04)          /* 该寄存器每2bit表示一个PPI中断是电平敏感还是边沿触发 */
#define SRE_GIC_GICD_ICFGR_0_REG                   (SRE_GIC_BASE + 0x1C08)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_1_REG                   (SRE_GIC_BASE + 0x1C0C)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_2_REG                   (SRE_GIC_BASE + 0x1C10)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_3_REG                   (SRE_GIC_BASE + 0x1C14)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_4_REG                   (SRE_GIC_BASE + 0x1C18)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_5_REG                   (SRE_GIC_BASE + 0x1C1C)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_6_REG                   (SRE_GIC_BASE + 0x1C20)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_7_REG                   (SRE_GIC_BASE + 0x1C24)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_8_REG                   (SRE_GIC_BASE + 0x1C28)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_9_REG                   (SRE_GIC_BASE + 0x1C2C)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_10_REG                  (SRE_GIC_BASE + 0x1C30)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_11_REG                  (SRE_GIC_BASE + 0x1C34)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_12_REG                  (SRE_GIC_BASE + 0x1C38)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_13_REG                  (SRE_GIC_BASE + 0x1C3C)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_14_REG                  (SRE_GIC_BASE + 0x1C40)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_15_REG                  (SRE_GIC_BASE + 0x1C44)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_16_REG                  (SRE_GIC_BASE + 0x1C48)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_17_REG                  (SRE_GIC_BASE + 0x1C4C)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_18_REG                  (SRE_GIC_BASE + 0x1C50)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_19_REG                  (SRE_GIC_BASE + 0x1C54)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_20_REG                  (SRE_GIC_BASE + 0x1C58)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_21_REG                  (SRE_GIC_BASE + 0x1C5C)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_22_REG                  (SRE_GIC_BASE + 0x1C60)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_23_REG                  (SRE_GIC_BASE + 0x1C64)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_24_REG                  (SRE_GIC_BASE + 0x1C68)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_25_REG                  (SRE_GIC_BASE + 0x1C6C)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_26_REG                  (SRE_GIC_BASE + 0x1C70)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_ICFGR_27_REG                  (SRE_GIC_BASE + 0x1C74)          /* 该寄存器每2bit表示一个SPI中断是电平敏感还是边沿触发。e的最大值为2*GICD_TYPER.ITLinesNumber。e{0,27} */
#define SRE_GIC_GICD_PPISR_REG                     (SRE_GIC_BASE + 0x1D00)          /* PPI中断输入至Distributor的状态 */
#define SRE_GIC_GICD_SPISR_0_REG                   (SRE_GIC_BASE + 0x1D04)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_1_REG                   (SRE_GIC_BASE + 0x1D08)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_2_REG                   (SRE_GIC_BASE + 0x1D0C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_3_REG                   (SRE_GIC_BASE + 0x1D10)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_4_REG                   (SRE_GIC_BASE + 0x1D14)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_5_REG                   (SRE_GIC_BASE + 0x1D18)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_6_REG                   (SRE_GIC_BASE + 0x1D1C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_7_REG                   (SRE_GIC_BASE + 0x1D20)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_8_REG                   (SRE_GIC_BASE + 0x1D24)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_9_REG                   (SRE_GIC_BASE + 0x1D28)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_10_REG                  (SRE_GIC_BASE + 0x1D2C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_11_REG                  (SRE_GIC_BASE + 0x1D30)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_12_REG                  (SRE_GIC_BASE + 0x1D34)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_13_REG                  (SRE_GIC_BASE + 0x1D38)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_14_REG                  (SRE_GIC_BASE + 0x1D3C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_15_REG                  (SRE_GIC_BASE + 0x1D40)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_16_REG                  (SRE_GIC_BASE + 0x1D44)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_17_REG                  (SRE_GIC_BASE + 0x1D48)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_18_REG                  (SRE_GIC_BASE + 0x1D4C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_19_REG                  (SRE_GIC_BASE + 0x1D50)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_20_REG                  (SRE_GIC_BASE + 0x1D54)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_21_REG                  (SRE_GIC_BASE + 0x1D58)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_22_REG                  (SRE_GIC_BASE + 0x1D5C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_23_REG                  (SRE_GIC_BASE + 0x1D60)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_24_REG                  (SRE_GIC_BASE + 0x1D64)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_25_REG                  (SRE_GIC_BASE + 0x1D68)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_26_REG                  (SRE_GIC_BASE + 0x1D6C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_27_REG                  (SRE_GIC_BASE + 0x1D70)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_28_REG                  (SRE_GIC_BASE + 0x1D74)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_29_REG                  (SRE_GIC_BASE + 0x1D78)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_30_REG                  (SRE_GIC_BASE + 0x1D7C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_31_REG                  (SRE_GIC_BASE + 0x1D80)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_32_REG                  (SRE_GIC_BASE + 0x1D84)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_33_REG                  (SRE_GIC_BASE + 0x1D88)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_34_REG                  (SRE_GIC_BASE + 0x1D8C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_35_REG                  (SRE_GIC_BASE + 0x1D90)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_36_REG                  (SRE_GIC_BASE + 0x1D94)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_37_REG                  (SRE_GIC_BASE + 0x1D98)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_38_REG                  (SRE_GIC_BASE + 0x1D9C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_39_REG                  (SRE_GIC_BASE + 0x1DA0)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_40_REG                  (SRE_GIC_BASE + 0x1DA4)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_41_REG                  (SRE_GIC_BASE + 0x1DA8)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_42_REG                  (SRE_GIC_BASE + 0x1DAC)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_43_REG                  (SRE_GIC_BASE + 0x1DB0)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_44_REG                  (SRE_GIC_BASE + 0x1DB4)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_45_REG                  (SRE_GIC_BASE + 0x1DB8)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_46_REG                  (SRE_GIC_BASE + 0x1DBC)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_47_REG                  (SRE_GIC_BASE + 0x1DC0)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_48_REG                  (SRE_GIC_BASE + 0x1DC4)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_49_REG                  (SRE_GIC_BASE + 0x1DC8)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_50_REG                  (SRE_GIC_BASE + 0x1DCC)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_51_REG                  (SRE_GIC_BASE + 0x1DD0)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_52_REG                  (SRE_GIC_BASE + 0x1DD4)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_53_REG                  (SRE_GIC_BASE + 0x1DD8)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_54_REG                  (SRE_GIC_BASE + 0x1DDC)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_55_REG                  (SRE_GIC_BASE + 0x1DE0)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_56_REG                  (SRE_GIC_BASE + 0x1DE4)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_57_REG                  (SRE_GIC_BASE + 0x1DE8)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_58_REG                  (SRE_GIC_BASE + 0x1DEC)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_59_REG                  (SRE_GIC_BASE + 0x1DF0)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_60_REG                  (SRE_GIC_BASE + 0x1DF4)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_61_REG                  (SRE_GIC_BASE + 0x1DF8)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_62_REG                  (SRE_GIC_BASE + 0x1DFC)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_63_REG                  (SRE_GIC_BASE + 0x1E00)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_64_REG                  (SRE_GIC_BASE + 0x1E04)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_65_REG                  (SRE_GIC_BASE + 0x1E08)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_66_REG                  (SRE_GIC_BASE + 0x1E0C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_67_REG                  (SRE_GIC_BASE + 0x1E10)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_68_REG                  (SRE_GIC_BASE + 0x1E14)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_69_REG                  (SRE_GIC_BASE + 0x1E18)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_70_REG                  (SRE_GIC_BASE + 0x1E1C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_71_REG                  (SRE_GIC_BASE + 0x1E20)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_72_REG                  (SRE_GIC_BASE + 0x1E24)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_73_REG                  (SRE_GIC_BASE + 0x1E28)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_74_REG                  (SRE_GIC_BASE + 0x1E2C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_75_REG                  (SRE_GIC_BASE + 0x1E30)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_76_REG                  (SRE_GIC_BASE + 0x1E34)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_77_REG                  (SRE_GIC_BASE + 0x1E38)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_78_REG                  (SRE_GIC_BASE + 0x1E3C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_79_REG                  (SRE_GIC_BASE + 0x1E40)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_80_REG                  (SRE_GIC_BASE + 0x1E44)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_81_REG                  (SRE_GIC_BASE + 0x1E48)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_82_REG                  (SRE_GIC_BASE + 0x1E4C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_83_REG                  (SRE_GIC_BASE + 0x1E50)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_84_REG                  (SRE_GIC_BASE + 0x1E54)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_85_REG                  (SRE_GIC_BASE + 0x1E58)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_86_REG                  (SRE_GIC_BASE + 0x1E5C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_87_REG                  (SRE_GIC_BASE + 0x1E60)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_88_REG                  (SRE_GIC_BASE + 0x1E64)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_89_REG                  (SRE_GIC_BASE + 0x1E68)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_90_REG                  (SRE_GIC_BASE + 0x1E6C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_91_REG                  (SRE_GIC_BASE + 0x1E70)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_92_REG                  (SRE_GIC_BASE + 0x1E74)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_93_REG                  (SRE_GIC_BASE + 0x1E78)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_94_REG                  (SRE_GIC_BASE + 0x1E7C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_95_REG                  (SRE_GIC_BASE + 0x1E80)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_96_REG                  (SRE_GIC_BASE + 0x1E84)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_97_REG                  (SRE_GIC_BASE + 0x1E88)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_98_REG                  (SRE_GIC_BASE + 0x1E8C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_99_REG                  (SRE_GIC_BASE + 0x1E90)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_100_REG                 (SRE_GIC_BASE + 0x1E94)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_101_REG                 (SRE_GIC_BASE + 0x1E98)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_102_REG                 (SRE_GIC_BASE + 0x1E9C)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_103_REG                 (SRE_GIC_BASE + 0x1EA0)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_104_REG                 (SRE_GIC_BASE + 0x1EA4)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_105_REG                 (SRE_GIC_BASE + 0x1EA8)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_106_REG                 (SRE_GIC_BASE + 0x1EAC)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_107_REG                 (SRE_GIC_BASE + 0x1EB0)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_108_REG                 (SRE_GIC_BASE + 0x1EB4)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_109_REG                 (SRE_GIC_BASE + 0x1EB8)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_110_REG                 (SRE_GIC_BASE + 0x1EBC)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define SRE_GIC_GICD_SPISR_111_REG                 (SRE_GIC_BASE + 0x1EC0)          /* SPI中断输入IRQS至GIC的状态。n的值由实际的外部中断数目决定。n{0,14} */
#define OS_GIC_GICD_SGIR_REG                      (SRE_GIC_BASE + 0x1F00)          /* 控制SGI的产生 */
#define SRE_GIC_GICD_CPENDSGIR_0_REG               (SRE_GIC_BASE + 0x1F40)          /* 每16bit表示单个SGI中断对应的16个CPU Interface清除pending状态。f{0,7} */
#define SRE_GIC_GICD_CPENDSGIR_1_REG               (SRE_GIC_BASE + 0x1F44)          /* 每16bit表示单个SGI中断对应的16个CPU Interface清除pending状态。f{0,7} */
#define SRE_GIC_GICD_CPENDSGIR_2_REG               (SRE_GIC_BASE + 0x1F48)          /* 每16bit表示单个SGI中断对应的16个CPU Interface清除pending状态。f{0,7} */
#define SRE_GIC_GICD_CPENDSGIR_3_REG               (SRE_GIC_BASE + 0x1F4C)          /* 每16bit表示单个SGI中断对应的16个CPU Interface清除pending状态。f{0,7} */
#define SRE_GIC_GICD_CPENDSGIR_4_REG               (SRE_GIC_BASE + 0x1F50)          /* 每16bit表示单个SGI中断对应的16个CPU Interface清除pending状态。f{0,7} */
#define SRE_GIC_GICD_CPENDSGIR_5_REG               (SRE_GIC_BASE + 0x1F54)          /* 每16bit表示单个SGI中断对应的16个CPU Interface清除pending状态。f{0,7} */
#define SRE_GIC_GICD_CPENDSGIR_6_REG               (SRE_GIC_BASE + 0x1F58)          /* 每16bit表示单个SGI中断对应的16个CPU Interface清除pending状态。f{0,7} */
#define SRE_GIC_GICD_CPENDSGIR_7_REG               (SRE_GIC_BASE + 0x1F5C)          /* 每16bit表示单个SGI中断对应的16个CPU Interface清除pending状态。f{0,7} */
#define SRE_GIC_GICD_SPENDSGIR_0_REG               (SRE_GIC_BASE + 0x1F80)          /* 每16bit表示单个SGI中断对应的16个CPU Interface设置pending状态。f{0,7} */
#define SRE_GIC_GICD_SPENDSGIR_1_REG               (SRE_GIC_BASE + 0x1F84)          /* 每16bit表示单个SGI中断对应的16个CPU Interface设置pending状态。f{0,7} */
#define SRE_GIC_GICD_SPENDSGIR_2_REG               (SRE_GIC_BASE + 0x1F88)          /* 每16bit表示单个SGI中断对应的16个CPU Interface设置pending状态。f{0,7} */
#define SRE_GIC_GICD_SPENDSGIR_3_REG               (SRE_GIC_BASE + 0x1F8C)          /* 每16bit表示单个SGI中断对应的16个CPU Interface设置pending状态。f{0,7} */
#define SRE_GIC_GICD_SPENDSGIR_4_REG               (SRE_GIC_BASE + 0x1F90)          /* 每16bit表示单个SGI中断对应的16个CPU Interface设置pending状态。f{0,7} */
#define SRE_GIC_GICD_SPENDSGIR_5_REG               (SRE_GIC_BASE + 0x1F94)          /* 每16bit表示单个SGI中断对应的16个CPU Interface设置pending状态。f{0,7} */
#define SRE_GIC_GICD_SPENDSGIR_6_REG               (SRE_GIC_BASE + 0x1F98)          /* 每16bit表示单个SGI中断对应的16个CPU Interface设置pending状态。f{0,7} */
#define SRE_GIC_GICD_SPENDSGIR_7_REG               (SRE_GIC_BASE + 0x1F9C)          /* 每16bit表示单个SGI中断对应的16个CPU Interface设置pending状态。f{0,7} */
#define SRE_GIC_GICD_PIDR4_REG                     (SRE_GIC_BASE + 0x1FD0)          /* Peripheral ID4身份识别寄存器 */
#define SRE_GIC_GICD_PIDR5_REG                     (SRE_GIC_BASE + 0x1FD4)          /* Peripheral ID5身份识别寄存器 */
#define SRE_GIC_GICD_PIDR6_REG                     (SRE_GIC_BASE + 0x1FD8)          /* Peripheral ID6身份识别寄存器 */
#define SRE_GIC_GICD_PIDR7_REG                     (SRE_GIC_BASE + 0x1FDC)          /* Peripheral ID7身份识别寄存器 */
#define SRE_GIC_GICD_PIDR0_REG                     (SRE_GIC_BASE + 0x1FE0)          /* Peripheral ID0身份识别寄存器 */
#define SRE_GIC_GICD_PIDR1_REG                     (SRE_GIC_BASE + 0x1FE4)          /* Peripheral ID1身份识别寄存器 */
#define SRE_GIC_GICD_PIDR2_REG                     (SRE_GIC_BASE + 0x1FE8)          /* Peripheral ID2身份识别寄存器 */
#define SRE_GIC_GICD_PIDR3_REG                     (SRE_GIC_BASE + 0x1FEC)          /* Peripheral ID3身份识别寄存器 */
#define SRE_GIC_GICD_CIDR0_REG                     (SRE_GIC_BASE + 0x1FF0)          /* Component ID0寄存器 */
#define SRE_GIC_GICD_CIDR1_REG                     (SRE_GIC_BASE + 0x1FF4)          /* Component ID1寄存器 */
#define SRE_GIC_GICD_CIDR2_REG                     (SRE_GIC_BASE + 0x1FF8)          /* Component ID2寄存器 */
#define SRE_GIC_GICD_CIDR3_REG                     (SRE_GIC_BASE + 0x1FFC)          /* Component ID3寄存器 */
#define SRE_GIC_GICC_CTLR_NS_REG                   (SRE_GIC_BASE + 0x2000)          /* CPU Interface使能以及顶层控制寄存器。（特别注意：GICC_CTLR是banked。此寄存器是在secure access下的备份。和在non_secure 的备份的位分配不一样）。 */
#define OS_GIC_GICC_CTLR_S_REG                    (SRE_GIC_BASE + 0x2000)          /* CPU Interface使能以及顶层控制寄存器。（特别注意：此寄存器是在non_secure access下的备份。和在secure 的备份的位分配不一样）。 */
#define OS_GIC_GICC_PMR_S_REG                     (SRE_GIC_BASE + 0x2004)          /* 中断优先级屏蔽寄存器 */
#define SRE_GIC_GICC_PMR_NS_REG                    (SRE_GIC_BASE + 0x2004)          /* 中断优先级屏蔽寄存器 */
#define SRE_GIC_GICC_BPR_NS_REG                    (SRE_GIC_BASE + 0x2008)          /* Group 优先级设置寄存器 */
#define OS_GIC_GICC_BPR_S_REG                     (SRE_GIC_BASE + 0x2008)          /* Group 优先级设置寄存器 */
#define OS_GIC_GICC_IAR_REG                       (SRE_GIC_BASE + 0x200C)          /* 中断确认寄存器 */
#define OS_GIC_GICC_EOIR_REG                      (SRE_GIC_BASE + 0x2010)          /* 中断结束寄存器 */
#define SRE_GIC_GICC_RPR_REG                       (SRE_GIC_BASE + 0x2014)          /* 指示running priority的寄存器 */
#define SRE_GIC_GICC_HPPIR_REG                     (SRE_GIC_BASE + 0x2018)          /* 具有最高优先级pending状态的中断寄存器 */
#define OS_GIC_GICC_ABPR_REG                      (SRE_GIC_BASE + 0x201C)          /* Group优先级设置寄存器 */
#define OS_GIC_GICC_AIAR_REG                      (SRE_GIC_BASE + 0x2020)          /* Group1中断确认寄存器 */
#define SRE_GIC_GICC_AEOIR_REG                     (SRE_GIC_BASE + 0x2024)          /* Group1中断结束寄存器 */
#define SRE_GIC_GICC_AHPPIR_REG                    (SRE_GIC_BASE + 0x2028)          /* 具有最高优先级pending状态的Group1中断寄存器 */
#define SRE_GIC_GICC_APR0_REG                      (SRE_GIC_BASE + 0x20D0)          /* active状态的安全中断优先级寄存器 */
#define SRE_GIC_GICC_NSAPR0_REG                    (SRE_GIC_BASE + 0x20E0)          /* active状态的非安全中断优先级寄存器 */
#define SRE_GIC_GICC_IIDR_REG                      (SRE_GIC_BASE + 0x20FC)          /* CPU interface身份寄存器 */
#define SRE_GIC_GICC_DIR_REG                       (SRE_GIC_BASE + 0x3000)          /* deactive中断寄存器 */
#define SRE_GIC_GICH_HCR_REG                       (SRE_GIC_BASE + 0x4000)          /* Hypervisor控制寄存器 */
#define SRE_GIC_GICH_VTR_REG                       (SRE_GIC_BASE + 0x4004)          /* 记录GIC虚拟化扩展的参数寄存器 */
#define SRE_GIC_GICH_VMCR_REG                      (SRE_GIC_BASE + 0x4008)          /* VM控制寄存器，在VM切换时，使能hypervisor保留和恢复GIC的状态。 */
#define SRE_GIC_GICH_MISR_REG                      (SRE_GIC_BASE + 0x4010)          /* Maintenance中断状态寄存器，标识哪种maintenance interrupt置有效。 */
#define SRE_GIC_GICH_EISR0_REG                     (SRE_GIC_BASE + 0x4020)          /* List register0～31 EOI状态寄存器 */
#define SRE_GIC_GICH_ELSR0_REG                     (SRE_GIC_BASE + 0x4030)          /* List register0～31 空状态寄存器 */
#define SRE_GIC_GICH_APR0_REG                      (SRE_GIC_BASE + 0x4070)          /* active 优先级寄存器。（n=0） */
#define SRE_GIC_GICH_LR_0_REG                      (SRE_GIC_BASE + 0x4080)          /* List register，一个List register记录一个中断的信息，n的值由GICH_VTR.ListRegs域定义。g{0,3} */
#define SRE_GIC_GICH_LR_1_REG                      (SRE_GIC_BASE + 0x4084)          /* List register，一个List register记录一个中断的信息，n的值由GICH_VTR.ListRegs域定义。g{0,3} */
#define SRE_GIC_GICH_LR_2_REG                      (SRE_GIC_BASE + 0x4088)          /* List register，一个List register记录一个中断的信息，n的值由GICH_VTR.ListRegs域定义。g{0,3} */
#define SRE_GIC_GICH_LR_3_REG                      (SRE_GIC_BASE + 0x408C)          /* List register，一个List register记录一个中断的信息，n的值由GICH_VTR.ListRegs域定义。g{0,3} */
#define SRE_GIC_GICV_CTLR_REG                      (SRE_GIC_BASE + 0x6000)          /* Virtual CPU Interface使能以及顶层控制寄存器 */
#define SRE_GIC_GICV_PMR_REG                       (SRE_GIC_BASE + 0x6004)          /* 虚拟中断优先级屏蔽寄存器 */
#define SRE_GIC_GICV_BPR_REG                       (SRE_GIC_BASE + 0x6008)          /* 虚拟中断Group优先级设置寄存器 */
#define SRE_GIC_GICV_IAR_REG                       (SRE_GIC_BASE + 0x600C)          /* 虚拟中断确认寄存器 */
#define SRE_GIC_GICV_EOIR_REG                      (SRE_GIC_BASE + 0x6010)          /* 虚拟中断结束寄存器 */
#define SRE_GIC_GICV_RPR_REG                       (SRE_GIC_BASE + 0x6014)          /* 指示VM中running priority的寄存器 */
#define SRE_GIC_GICV_HPPIR_REG                     (SRE_GIC_BASE + 0x6018)          /* 具有最高优先级pending状态的虚拟中断寄存器 */
#define SRE_GIC_GICV_ABPR_REG                      (SRE_GIC_BASE + 0x601C)          /* 虚拟中断Group优先级设置寄存器 */
#define SRE_GIC_GICV_AIAR_REG                      (SRE_GIC_BASE + 0x6020)          /* 虚拟中断确认寄存器 */
#define SRE_GIC_GICV_AEOIR_REG                     (SRE_GIC_BASE + 0x6024)          /* 虚拟中断结束寄存器 */
#define SRE_GIC_GICV_AHPPIR_REG                    (SRE_GIC_BASE + 0x6028)          /* 具有最高优先级pending状态的虚拟中断寄存器 */
#define SRE_GIC_GICV_APR0_REG                      (SRE_GIC_BASE + 0x60D0)          /* active状态的group0虚拟中断优先级寄存器。(n=0) */
#define SRE_GIC_GICV_IIDR_REG                      (SRE_GIC_BASE + 0x60FC)          /* Virtual CPU Interface身份寄存器 */
#define SRE_GIC_GICV_DIR_REG                       (SRE_GIC_BASE + 0x7000)          /* deactive虚拟中断寄存器 */

/* TMR 模块寄存器基地址 */
#define MC_TMR_BASE                               (0xe3000000)

/******************************************************************************/
/*                      MC TMR 寄存器定义                                     */
/******************************************************************************/
#define MC_TMR_TIMER0_LOAD_REG                    (MC_TMR_BASE + 0x0)             /* TIMER0_LOAD为Timer0计数初值寄存器。 */
#define MC_TMR_TIMER0_VALUE_REG                   (MC_TMR_BASE + 0x4)             /* TIMER0_VALUE为Timer0当前计数值寄存器。 */
#define MC_TMR_TIMER0_CONTROL_REG                 (MC_TMR_BASE + 0x8)             /* TIMER0_CONTROL为Timer0控制寄存器。 */
#define MC_TMR_TIMER0_INTCLR_REG                  (MC_TMR_BASE + 0xC)             /* TIMER0_INTCLR为Timer0中断清除寄存器。 */
#define MC_TMR_TIMER0_RIS_REG                     (MC_TMR_BASE + 0x10)            /* TIMER0_RIS为Timer0中断状态寄存器。 */
#define MC_TMR_TIMER0_MIS_REG                     (MC_TMR_BASE + 0x14)            /* TIMER0_MIS为Timer0屏蔽后中断状态寄存器。 */
#define MC_TMR_TIMER0_BGLOAD_REG                  (MC_TMR_BASE + 0x18)            /* TIMER0_BGLOAD为Timer0循环模式计数初值寄存器。 */
#define MC_TMR_TIMER1_LOAD_REG                    (MC_TMR_BASE + 0x20)            /* TIMER1_LOAD为Timer1计数初值寄存器。 */
#define MC_TMR_TIMER1_VALUE_REG                   (MC_TMR_BASE + 0x24)            /* TIMER1_VALUE为Timer1当前计数值寄存器。 */
#define MC_TMR_TIMER1_CONTROL_REG                 (MC_TMR_BASE + 0x28)            /* TIMER1_CONTROL为Timer1控制寄存器。 */
#define MC_TMR_TIMER1_INTCLR_REG                  (MC_TMR_BASE + 0x2C)            /* TIMER1_INTCLR为Timer1中断清除寄存器。 */
#define MC_TMR_TIMER1_RIS_REG                     (MC_TMR_BASE + 0x30)            /* TIMER1_RIS为Timer1中断状态寄存器。 */
#define MC_TMR_TIMER1_MIS_REG                     (MC_TMR_BASE + 0x34)            /* TIMER1_MIS为Timer1屏蔽后中断状态寄存器。 */
#define MC_TMR_TIMER1_BGLOAD_REG                  (MC_TMR_BASE + 0x38)            /* TIMER1_BGLOAD为Timer1循环模式计数初值寄存器。 */


/*64位定时器*/
#define MC_TIMER64_0_LOAD_L                       (MC_TMR_BASE + 0x10000)
#define MC_TIMER64_0_LOAD_H                       (MC_TMR_BASE + 0x10000 + 0x4)
#define MC_Timer64_0_VALUE_L                      (MC_TMR_BASE + 0x10000 + 0x8)
#define MC_Timer64_0_VALUE_H                      (MC_TMR_BASE + 0x10000 + 0xC)
#define MC_Timer64_0_CONTROL                      (MC_TMR_BASE + 0x10000 + 0x10)
#define MC_Timer64_0_INTCLR                       (MC_TMR_BASE + 0x10000 + 0x14)
#define MC_Timer64_0_RIS                          (MC_TMR_BASE + 0x10000 + 0x18)
#define MC_Timer64_0_MIS                          (MC_TMR_BASE + 0x10000 + 0x1C)
#define MC_Timer64_0_BGLOAD_L                     (MC_TMR_BASE + 0x10000 + 0x20)
#define MC_Timer64_0_BGLOAD_H                     (MC_TMR_BASE + 0x10000 + 0x24)


#define MC_TIMER64_1_LOAD_L                       (MC_TMR_BASE + 0x10000 + 0x40)
#define MC_TIMER64_1_LOAD_H                       (MC_TMR_BASE + 0x10000 + 0x44)
#define MC_Timer64_1_VALUE_L                      (MC_TMR_BASE + 0x10000 + 0x48)
#define MC_Timer64_1_VALUE_H                      (MC_TMR_BASE + 0x10000 + 0x4C)
#define MC_Timer64_1_CONTROL                      (MC_TMR_BASE + 0x10000 + 0x50)
#define MC_Timer64_1_INTCLR                       (MC_TMR_BASE + 0x10000 + 0x54)
#define MC_Timer64_1_RIS                          (MC_TMR_BASE + 0x10000 + 0x58)
#define MC_Timer64_1_MIS                          (MC_TMR_BASE + 0x10000 + 0x5C)
#define MC_Timer64_1_BGLOAD_L                     (MC_TMR_BASE + 0x10000 + 0x60)
#define MC_Timer64_1_BGLOAD_H                     (MC_TMR_BASE + 0x10000 + 0x64)


/* RNG 模块寄存器基地址 */
#define SRE_RNG_BASE                               (0xe40a0000UL)

/******************************************************************************/
/*                      MC RNG 寄存器定义                                     */
/******************************************************************************/
#define SRE_RNG_SEED_REG                       (SRE_RNG_BASE + 0x0)             /* PRBS_SEED为种子值，即产生器的初始状态值 */
#define SRE_RNG_CTRL_REG                       (SRE_RNG_BASE + 0x4)             /* PRBS_CTRL为PRBS工作状态控制寄存器。 */
#define SRE_RNG_RAN_NUM_REG                    (SRE_RNG_BASE + 0x10)            /* LFSR产生的随机数数值 */
#define SRE_RNG_PHY_SEED_REG                   (SRE_RNG_BASE + 0x14)            /* 内部物理反相器震荡环产生的随机数 */
#define SRE_RNG_RELOAD_ERR_REG                 (SRE_RNG_BASE + 0x84)


/* DLHDCP 模块寄存器基地址 */
#if 0         /* z00202052 */
#define SRE_DLHDCP_BASE                              (0x140b0000UL)
#else
#define SRE_DLHDCP_BASE                              (0xe40b0000UL)
#endif        /* z00202052 */

/******************************************************************************/
/*                      MC DLHDCP_CFG 寄存器定义                              */
/******************************************************************************/
#define SRE_DLHDCP_CFG_CTRL_REG         (SRE_DLHDCP_BASE + 0x0)      /* DLHDCP控制寄存器 */
#define SRE_DLHDCP_CFG_BMU_POOL_ID_REG  (SRE_DLHDCP_BASE + 0x4)      /* BMU POOL ID选择寄存器 */
#define SRE_DLHDCP_CFG_CACHEABLE_REG    (SRE_DLHDCP_BASE + 0x8)      /* Allocate配置寄存器 */
#define SRE_DLHDCP_CFG_BMU_REQ_ADDR_REG  (SRE_DLHDCP_BASE + 0xC)      /* 申请BMU的地址 */
#define SRE_DLHDCP_STS_REG              (SRE_DLHDCP_BASE + 0x10)     /* DLHDCP模块状态寄存器 */
#define SRE_DLHDCP_M0_BUS_WR_CNT_REG    (SRE_DLHDCP_BASE + 0x14)     /* MASTER0总线写传输次数统计寄存器 */
#define SRE_DLHDCP_M1_BUS_WR_TRANS_CNT_REG  (SRE_DLHDCP_BASE + 0x18)     /* MASTER1总线写传输次数统计寄存器 */
#define SRE_DLHDCP_M0_BUS_RD_TRANS_CNT_REG  (SRE_DLHDCP_BASE + 0x1C)     /* MASTER0总线读传输次数统计寄存器 */
#define SRE_DLHDCP_M1_BUS_RD_TRANS_CNT_REG  (SRE_DLHDCP_BASE + 0x20)     /* MASTER1总线读传输次数统计寄存器 */
#define SRE_DLHDCP_POE_GET_CNT_REG      (SRE_DLHDCP_BASE + 0x24)     /* POE GET任务总次数寄存器 */
#define SRE_DLHDCP_POE_ADD_CNT_REG      (SRE_DLHDCP_BASE + 0x28)     /* POE ADD任务总次数寄存器 */
#define SRE_DLHDCP_POE_FAIL_CNT_REG     (SRE_DLHDCP_BASE + 0x2C)     /* POE GET和ADD任务失败次数寄存器 */
#define SRE_DLHDCP_BMU_REQ_CNT_REG      (SRE_DLHDCP_BASE + 0x30)     /* BMU申请Buffer次数统计寄存器 */
#define SRE_DLHDCP_BMU_FAIL_CNT_REG     (SRE_DLHDCP_BASE + 0x34)     /* BMU申请Buffer失败次数统计寄存器 */
#define SRE_DLHDCP_M0_MEM_RD_CNT_REG    (SRE_DLHDCP_BASE + 0x38)     /* MASTER0 Memory读次数统计寄存器 */
#define SRE_DLHDCP_M1_MEM_RD_CNT_REG    (SRE_DLHDCP_BASE + 0x3C)     /* MASTER1 Memory读次数统计寄存器 */
#define SRE_DLHDCP_M0_MEM_WR_CNT_REG    (SRE_DLHDCP_BASE + 0x40)     /* MASTER0 Memory写次数统计寄存器 */
#define SRE_DLHDCP_M1_MEM_WR_CNT_REG    (SRE_DLHDCP_BASE + 0x44)     /* MASTER1 Memory写次数统计寄存器 */
#define SRE_DLHDCP_M0_MEM_FAIL_CNT_REG  (SRE_DLHDCP_BASE + 0x48)     /* MASTER0 Memory读写失败次数统计寄存器 */
#define SRE_DLHDCP_M1_MEM_FAIL_CNT_REG  (SRE_DLHDCP_BASE + 0x4C)     /* MASTER1 Memory读写失败次数统计寄存器 */
#define SRE_DLHDCP_RINT_REG             (SRE_DLHDCP_BASE + 0x50)     /* DLHDCP原始中断寄存器 */
#define SRE_DLHDCP_INTMSK_REG           (SRE_DLHDCP_BASE + 0x54)     /* DLHDCP中断屏蔽寄存器 */
#define SRE_DLHDCP_INTSTS_REG           (SRE_DLHDCP_BASE + 0x58)     /* DLHDCP中断状态寄存器 */
#define SRE_DLHDCP_BDERR_ADDR_REG       (SRE_DLHDCP_BASE + 0x5C)     /* 异常DLHDCP_BD对应的HBD首地址 */
#define SRE_DLHDCP_WRMEM_ERR_ADDR_REG   (SRE_DLHDCP_BASE + 0x60)     /* 写L3C/DDR失败时对应的写命令地址 */
#define SRE_DLHDCP_RDMEM_ERR_ADDR_REG   (SRE_DLHDCP_BASE + 0x64)     /* 读L3C/DDR失败时对应的读命令地址 */
#define SRE_DLHDCP_SRIO_ADDR_REG        (SRE_DLHDCP_BASE + 0x68)     /* SRIO任务寄存器地址 */
#define SRE_DLHDCP_POE_GET_ADDR_REG     (SRE_DLHDCP_BASE + 0x6C)     /* 向POE取任务地址 */
#define SRE_DLHDCP_POE_ADDR_ADDR_REG    (SRE_DLHDCP_BASE + 0x70)     /* 往POE添加任务地址 */
#define SRE_DLHDCP_VMID_REG             (SRE_DLHDCP_BASE + 0x74)     /* VMID配置寄存器 */
#define SRE_DLHDCP_NODE_CODE_REG        (SRE_DLHDCP_BASE + 0x78)     /* 任务源设备号 */
#define SRE_DLHDCP_MST_DFX_CTRL_REG     (SRE_DLHDCP_BASE + 0x7C)     /* AXI_MST接口DFX配置寄存器 */
#define SRE_DLHDCP_MST0_AVG_LAT_CNT_REG  (SRE_DLHDCP_BASE + 0x80)     /* AXI_MST_IF0接口读写平均延时统计 */
#define SRE_DLHDCP_MST0_MAX_LAT_CNT_REG  (SRE_DLHDCP_BASE + 0x84)     /* AXI_MST_IFO接口读写最大延时统计 */
#define SRE_DLHDCP_MST0_ACC_RD_REG      (SRE_DLHDCP_BASE + 0x88)     /* MSTO读总次数统计 */
#define SRE_DLHDCP_MST0_ACC_WR_REG      (SRE_DLHDCP_BASE + 0x8C)     /* MSTO写总次数统计 */
#define SRE_DLHDCP_MST1_AVG_LAT_CNT_REG  (SRE_DLHDCP_BASE + 0x90)     /* AXI_MST_IF1接口读写平均延时统计 */
#define SRE_DLHDCP_MST1_MAX_LAT_CNT_REG  (SRE_DLHDCP_BASE + 0x94)     /* AXI_MST_IF1接口读写最大延时统计 */
#define SRE_DLHDCP_MST1_ACC_RD_REG      (SRE_DLHDCP_BASE + 0x98)     /* MST1读写总次数统计 */
#define SRE_DLHDCP_MST1_ACC_WR_REG      (SRE_DLHDCP_BASE + 0x9C)     /* MST1读写总次数统计 */
#define SRE_DLHDCP_RD_OTSD_DEPTH_REG    (SRE_DLHDCP_BASE + 0xA0)     /* 读报文的outstanding深度 */
#define SRE_DLHDCP_M0_BD_RRESP_NOK_STAT_REG  (SRE_DLHDCP_BASE + 0xA4)     /* MST0读BD读响应不正确统计值 */
#define SRE_DLHDCP_MEM_BD_ID_NEQ_STAT0_REG  (SRE_DLHDCP_BASE + 0xA8)     /* MST0读BD读响应ID和读命令ID不匹配统计值 */
#define SRE_DLHDCP_MEM_BD_RLAST_NOK_STAT0_REG  (SRE_DLHDCP_BASE + 0xAC)     /* MST0读BD的rlast不正确统计值 */
#define SRE_DLHDCP_MEM_VBD_BUF_ADDR_NCACHE_STAT0_REG  (SRE_DLHDCP_BASE + 0xB0)     /* MST0读BD的VBD地址没有cacheline对齐的统计 */
#define SRE_DLHDCP_MEM_RBD_BUF_ADDR_NCACHE_STAT0_REG  (SRE_DLHDCP_BASE + 0xB4)     /* MST0读BD的RBD地址没有cacheline对齐的统计 */
#define SRE_DLHDCP_M1_BD_RRESP_NOK_STAT_REG  (SRE_DLHDCP_BASE + 0xB8)     /* MST1读BD读响应不正确统计值 */
#define SRE_DLHDCP_MEM_BD_ID_NEQ_STAT1_REG  (SRE_DLHDCP_BASE + 0xBC)     /* MST1读BD读响应ID和读命令ID不匹配统计值 */
#define SRE_DLHDCP_MEM_BD_RLAST_NOK_STAT1_REG  (SRE_DLHDCP_BASE + 0xC0)     /* MST1读BD的rlast不正确统计值 */
#define SRE_DLHDCP_MEM_VBD_BUF_ADDR_NCACHE_STAT1_REG  (SRE_DLHDCP_BASE + 0xC4)     /* MST1读BD的VBD地址没有cacheline对齐的统计 */
#define SRE_DLHDCP_MEM_RBD_BUF_ADDR_NCACHE_STAT1_REG  (SRE_DLHDCP_BASE + 0xC8)     /* MST1读BD的RBD地址没有cacheline对齐的统计 */
#define SRE_DLHDCP_PKT_LEN_ZERO_STAT0_REG  (SRE_DLHDCP_BASE + 0xCC)     /* 通过MST0读取的描述符报文总长度为0的个数统计 */
#define SRE_DLHDCP_MEM_MSG_RRESP_NOK_STAT0_REG  (SRE_DLHDCP_BASE + 0xD0)     /* MST0读MSG读响应不正确统计值 */
#define SRE_DLHDCP_MEM_MSG_ID_NEQ_STAT0_REG  (SRE_DLHDCP_BASE + 0xD4)     /* MST0读MSG读响应ID和读命令ID不匹配统计值 */
#define SRE_DLHDCP_MEM_MSG_RLAST_NOK_STAT0_REG  (SRE_DLHDCP_BASE + 0xD8)     /* MST0读MSG的rlast不正确统计值 */
#define SRE_DLHDCP_MEM_MSG_BRESP_NOK_STAT_REG  (SRE_DLHDCP_BASE + 0xDC)     /* MST0写MSG写响应不正确统计值 */
#define SRE_DLHDCP_MEM_MSG_BID_NEQ_STAT0_REG  (SRE_DLHDCP_BASE + 0xE0)     /* MST0写MSG写响应ID和写命令ID不匹配统计值 */
#define SRE_DLHDCP_TASK_PRO_AVG_TIME_STAT0_REG  (SRE_DLHDCP_BASE + 0xE4)     /* 通过MST0处理的任务的平均处理时间 */
#define SRE_DLHDCP_TASK_PRO_MAX_TIME_STAT0_REG  (SRE_DLHDCP_BASE + 0xE8)     /* 通过MST0处理的任务的最大处理时间 */
#define SRE_DLHDCP_TASK_PRO_TIME_CNT_OVFL_STAT0_REG  (SRE_DLHDCP_BASE + 0xEC)     /* 通过MST0处理的任务的最大处理时间计数器溢出次数统计 */
#define SRE_DLHDCP_PKT_LEN_ZERO_STAT1_REG  (SRE_DLHDCP_BASE + 0xF0)     /* 通过MST1读取的描述符报文总长度为0的个数统计 */
#define SRE_DLHDCP_MEM_MSG_RRESP_NOK_STAT1_REG  (SRE_DLHDCP_BASE + 0xF4)     /* MST1读MSG读响应不正确统计值 */
#define SRE_DLHDCP_MEM_MSG_ID_NEQ_STAT1_REG  (SRE_DLHDCP_BASE + 0xF8)     /* MST1读MSG读响应ID和读命令ID不匹配统计值 */
#define SRE_DLHDCP_MEM_MSG_RLAST_NOK_STAT1_REG  (SRE_DLHDCP_BASE + 0xFC)     /* MST1读MSG的rlast不正确统计值 */
#define SRE_DLHDCP_MEM_MSG_BRESP_NOK_STAT1_REG  (SRE_DLHDCP_BASE + 0x100)    /* MST1写MSG写响应不正确统计值 */
#define SRE_DLHDCP_MEM_MSG_BID_NEQ_STAT1_REG  (SRE_DLHDCP_BASE + 0x104)    /* MST1写MSG写响应ID和写命令ID不匹配统计值 */
#define SRE_DLHDCP_TASK_PRO_AVG_TIME_STAT1_REG  (SRE_DLHDCP_BASE + 0x108)    /* 通过MST1处理的任务的平均处理时间 */
#define SRE_DLHDCP_TASK_PRO_MAX_TIME_STAT1_REG  (SRE_DLHDCP_BASE + 0x10C)    /* 通过MST1处理的任务的最大处理时间 */
#define SRE_DLHDCP_TASK_PRO_TIME_CNT_OVFL_STAT1_REG  (SRE_DLHDCP_BASE + 0x110)    /* 通过MST1处理的任务的最大处理时间计数器溢出次数统计 */
#define SRE_DLHDCP_BD_PKT_SIZE_ZERO_STAT0_REG  (SRE_DLHDCP_BASE + 0x114)    /* MST0处理的任务的pkt size 为0的任务次数统计 */
#define SRE_DLHDCP_BD_FIFO_OVFL_STAT0_REG  (SRE_DLHDCP_BASE + 0x118)    /* MST0 BD FIFO满写的次数统计 */
#define SRE_DLHDCP_BD_FIFO_UDFL_STAT0_REG  (SRE_DLHDCP_BASE + 0x11C)    /* MSTO BD FIFO空读的次数统计 */
#define SRE_DLHDCP_SHAPING_FIFO_OVFL_STAT0_REG  (SRE_DLHDCP_BASE + 0x120)    /* MST0 SHAPING FIFO满写的次数统计 */
#define SRE_DLHDCP_SHAPING_FIFO_UDFL_STAT0_REG  (SRE_DLHDCP_BASE + 0x124)    /* MST0 SHAPING FIFO空读的次数统计 */
#define SRE_DLHDCP_BD_PKT_SIZE_ZERO_STAT1_REG  (SRE_DLHDCP_BASE + 0x128)    /* MST1处理的任务的pkt size 为0的任务次数统计 */
#define SRE_DLHDCP_BD_FIFO_OVFL_STAT1_REG  (SRE_DLHDCP_BASE + 0x12C)    /* MST1 BD FIFO满写的次数统计 */
#define SRE_DLHDCP_BD_FIFO_UDFL_STAT1_REG  (SRE_DLHDCP_BASE + 0x130)    /* MST1 BD FIFO空读的次数统计 */
#define SRE_DLHDCP_SHAPING_FIFO_OVFL_STAT1_REG  (SRE_DLHDCP_BASE + 0x134)    /* MST1 SHAPING FIFO满写的次数统计 */
#define SRE_DLHDCP_SHAPING_FIFO_UDFL_STAT1_REG  (SRE_DLHDCP_BASE + 0x138)    /* MST1 SHAPING FIFO空读的次数统计 */
#define SRE_DLHDCP_PKT_LEN_NOK_STATO_REG  (SRE_DLHDCP_BASE + 0x13C)    /* MST0报文总长度和各个结点长度的累加值不匹配 */
#define SRE_DLHDCP_PKT_BUF_NUM_NOK_STAT0_REG  (SRE_DLHDCP_BASE + 0x140)    /* MST0 BUF_NUM数量不正确统计 */
#define SRE_DLHDCP_PKT_NXT_BUF_ADDR_NOK_STAT0_REG  (SRE_DLHDCP_BASE + 0x144)    /* MST0 下一结点地址不正确统计 */
#define SRE_DLHDCP_PKT_LEN_NOK_STAT1_REG  (SRE_DLHDCP_BASE + 0x148)    /* MST1报文总长度和各个结点长度的累加值不匹配 */
#define SRE_DLHDCP_PKT_BUF_NUM_NOK_STAT1_REG  (SRE_DLHDCP_BASE + 0x14C)    /* MST1 BUF_NUM数量不正确统计 */
#define SRE_DLHDCP_PKT_NXT_BUF_ADDR_NOK_STAT1_REG  (SRE_DLHDCP_BASE + 0x150)    /* MST1 下一结点地址不正确统计 */
#define SRE_DLHDCP_ABNORM_TYPE0_REG     (SRE_DLHDCP_BASE + 0x154)    /* 异常类型寄存器 */
#define SRE_DLHDCP_ABNORM_INFORMATION0_REG  (SRE_DLHDCP_BASE + 0x158)    /* 异常信息寄存器 */
#define SRE_DLHDCP_ABNORM_TYPE1_REG     (SRE_DLHDCP_BASE + 0x15C)    /* 异常类型寄存器 */
#define SRE_DLHDCP_ABNORM_INFORMATION1_REG  (SRE_DLHDCP_BASE + 0x160)    /* 异常信息寄存器 */
#define SRE_DLHDCP_CFG_RSV0_REG         (SRE_DLHDCP_BASE + 0x164)    /* DLHDCP 配置保留寄存器0 */
#define SRE_DLHDCP_CFG_RSV1_REG         (SRE_DLHDCP_BASE + 0x168)    /* DLHDCP 配置保留寄存器1 */
#define SRE_DLHDCP_CFG_RSV2_REG         (SRE_DLHDCP_BASE + 0x16C)    /* DLHDCP 配置保留寄存器2 */
#define SRE_DLHDCP_STS_RSV0_REG         (SRE_DLHDCP_BASE + 0x170)    /* DLHDCP 状态保留寄存器0 */
#define SRE_DLHDCP_STS_RSV1_REG         (SRE_DLHDCP_BASE + 0x174)    /* DLHDCP 状态保留寄存器1 */
#define SRE_DLHDCP_STS_RSV2_REG         (SRE_DLHDCP_BASE + 0x178)    /* DLHDCP 状态保留寄存器2 */

/* ULHDCP_REG 模块寄存器基地址 */
#define SRE_ULHDCP_REG_BASE             (0x10870000)

/******************************************************************************/
/*                      MC ULHDCP_REG 寄存器定义                   */
/******************************************************************************/
#define SRE_ULHDCP_REG_CFG_ENABLE_REG  (SRE_ULHDCP_REG_BASE + 0x0)  /* ULHDCP使能控制寄存器。 */
#define SRE_ULHDCP_REG_CFG_BMU_POOL_ID_REG  (SRE_ULHDCP_REG_BASE + 0x4)  /* BMU POOL ID选择寄存器。 */
#define SRE_ULHDCP_REG_CFG_BMU_POOL_SIZE_REG  (SRE_ULHDCP_REG_BASE + 0x8)  /* Buffer空间大小配置寄存器。 */
#define SRE_ULHDCP_REG_CFG_BMU_REQ_ADDR_REG  (SRE_ULHDCP_REG_BASE + 0x10)  /* 申请BMU的地址。 */
#define SRE_ULHDCP_REG_MODE_REG  (SRE_ULHDCP_REG_BASE + 0x14)  /* ULHDCP状态寄存器 */
#define SRE_ULHDCP_REG_M0_BUS_WR_TRANS_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x18)  /* MASTER总线写传输次数统计寄存器。 */
#define SRE_ULHDCP_REG_STS_REG   (SRE_ULHDCP_REG_BASE + 0x1C)  /* ULHDCP模块状态寄存器 */
#define SRE_ULHDCP_REG_M0_BUS_RD_TRANS_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x20)  /* MASTER总线读传输次数统计寄存器。 */
#define SRE_ULHDCP_REG_POE_ADD_TRS_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x34)  /* POE ADD任务总次数寄存器。 */
#define SRE_ULHDCP_REG_POE_GET_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x48)  /* POE GET任务总次数寄存器。 */
#define SRE_ULHDCP_REG_POE_ADD_RLS_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x4C)  /* POE ADD任务总次数寄存器。 */
#define SRE_ULHDCP_REG_POE_FAIL_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x50)  /* POE GET或者ADD任务失败次数寄存器。 */
#define SRE_ULHDCP_REG_BMU_REQ_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x60)  /* BMU申请Buffer次数统计寄存器。 */
#define SRE_ULHDCP_REG_BMU_FAIL_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x64)  /* BMU申请Buffer失败次数统计寄存器。 */
#define SRE_ULHDCP_REG_ADD_POE_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x68)  /* ADD POE失败次数统计寄存器。 */
#define SRE_ULHDCP_REG_M0_MEM_RD_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x6C)  /* MASTER Memory读次数统计寄存器。 */
#define SRE_ULHDCP_REG_M0_MEM_WR_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x70)  /* MASTER Memory写次数统计寄存器。 */
#define SRE_ULHDCP_REG_L3CACHE_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x74)  /* ULHDCP模块读写数据时是否经过L3 Cache控制寄存器。 */
#define SRE_ULHDCP_REG_RINT_REG  (SRE_ULHDCP_REG_BASE + 0x78)  /* ULHDCP原始中断寄存器。 */
#define SRE_ULHDCP_REG_INTMSK_REG  (SRE_ULHDCP_REG_BASE + 0x7C)  /* ULHDCP中断屏蔽寄存器。 */
#define SRE_ULHDCP_REG_INTSTS_REG  (SRE_ULHDCP_REG_BASE + 0x80)  /* ULHDCP中断状态寄存器。 */
#define SRE_ULHDCP_REG_POE_GET_ADDR_REG  (SRE_ULHDCP_REG_BASE + 0x98)  /* 向POE取任务地址。 */
#define SRE_ULHDCP_REG_POE_ADDR_ADDR_REG  (SRE_ULHDCP_REG_BASE + 0x9C)  /* 往POE添加任务地址。 */
#define SRE_ULHDCP_REG_VMID_REG  (SRE_ULHDCP_REG_BASE + 0xA0)  /* VMID配置寄存器。 */
#define SRE_ULHDCP_REG_SKIP1_LEN_REG  (SRE_ULHDCP_REG_BASE + 0xD0)  /* ULHDCP模块SKIP1长度配置寄存器。 */
#define SRE_ULHDCP_REG_SKIP2_LEN_REG  (SRE_ULHDCP_REG_BASE + 0xD4)  /* ULHDCP模块SKIP2长度配置寄存器。 */

#define SRE_ULHDCP_REG_ERR_STA_REG  (SRE_ULHDCP_REG_BASE + 0xDC)  /* ULHDCP模块内部告警查询接存器。 */
#define SRE_ULHDCP_REG_PKTLEN_ERR_CNT_REG  (SRE_ULHDCP_REG_BASE + 0xE0)  /* ULHDCP模块处理的长度为0的数据包个数统计计数器。 */
#define SRE_ULHDCP_REG_INVLD_TASK_CNT_REG  (SRE_ULHDCP_REG_BASE + 0xE4)  /* ULHDCP模块处理的无效任务个数统计计数器。 */
#define SRE_ULHDCP_REG_CIPHER_ERR_CNT_REG  (SRE_ULHDCP_REG_BASE + 0xE8)  /* ULHDCP模块搬移的SEC BD的加密范围错误的数据包个数统计计数器。 */
#define SRE_ULHDCP_REG_AUTH_ERR_CNT_REG  (SRE_ULHDCP_REG_BASE + 0xEC)  /* ULHDCP模块搬移的SEC BD的认证范围错误的数据包个数统计计数器。 */
#define SRE_ULHDCP_REG_MAC_ERR_CNT_REG  (SRE_ULHDCP_REG_BASE + 0xF0)  /* ULHDCP模块搬移的SEC BD的认证码地址错误的数据包个数统计计数器。 */
#define SRE_ULHDCP_REG_BIG_ENDIAN_REG  (SRE_ULHDCP_REG_BASE + 0xF4)  /* ULHDCP模块访问DDR时的大小端模式配置寄存器。 */
#define SRE_ULHDCP_REG_NODE_CODE_REG  (SRE_ULHDCP_REG_BASE + 0xF8)  /* ULHDCP模块设备号配置寄存器。 */
#define SRE_ULHDCP_REG_BDERR_ADDR_REG  (SRE_ULHDCP_REG_BASE + 0xFC)  /* ULHDCP模块异常BD对应的VBD首地址 */
#define SRE_ULHDCP_REG_WRMEM_ERR_ADDR_REG  (SRE_ULHDCP_REG_BASE + 0x100)  /* ULHDCP模块写L3C/DDR失败时对应的写命令地址 */
#define SRE_ULHDCP_REG_RDMEM_ERR_ADDR_REG  (SRE_ULHDCP_REG_BASE + 0x104)  /* ULHDCP模块读L3C/DDR失败时对应的读命令地址 */
#define SRE_ULHDCP_REG_MEM_FAIL_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x108)  /* ULHDCP模块读写Memory失败次数统计寄存器 */
#define SRE_ULHDCP_REG_VBD_ERR0_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x10C)  /* ULHDCP模块各VBD错误数据包的个数统计计数器。 */
#define SRE_ULHDCP_REG_VBD_ERR1_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x110)  /* ULHDCP模块各VBD错误数据包的个数统计计数器。 */
#define SRE_ULHDCP_REG_VBD_ERR2_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x114)  /* ULHDCP模块各VBD错误数据包的个数统计计数器。 */
#define SRE_ULHDCP_REG_BMU_REQ_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x17C)  /* ULHDCP模块读BMU配置控制寄存器。 */
#define SRE_ULHDCP_REG_GET_POE_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x180)  /* ULHDCP模块GET POE配置控制寄存器。 */
#define SRE_ULHDCP_REG_ADD_POE_RLS_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x184)  /* ULHDCP模块ADD POE（缓存释放）配置控制寄存器。 */
#define SRE_ULHDCP_REG_ADD_POE_TRS_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x18C)  /* ULHDCP模块ADD POE（报文转发）配置控制寄存器。 */
#define SRE_ULHDCP_REG_BMU_REQ_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x190)  /* ULHDCP模块申请BMU缓存时超时控制寄存器。 */
#define SRE_ULHDCP_REG_POE_GET_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x194)  /* ULHDCP模块GET POE时超时控制寄存器。 */
#define SRE_ULHDCP_REG_VBD_RD_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x198)  /* ULHDCP模块读VBD时超时控制寄存器。 */
#define SRE_ULHDCP_REG_PKT_RD_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x19C)  /* ULHDCP模块读数据包时超时控制寄存器。 */
#define SRE_ULHDCP_REG_POE_ADDTRS_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x1A0)  /* ULHDCP模块ADD POE（报文转发）时超时控制寄存器。 */
#define SRE_ULHDCP_REG_POE_ADDRLS_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x1A4)  /* ULHDCP模块ADD POE（缓存释放）时超时控制寄存器。 */
#define SRE_ULHDCP_REG_BD_WR_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x1A8)  /* ULHDCP模块写copy后的BD时超时控制寄存器。 */
#define SRE_ULHDCP_REG_PKT_WR_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x1AC)  /* ULHDCP模块写copy后的数据包时超时控制寄存器。 */
#define SRE_ULHDCP_REG_RW_RSV0_DFX_REG  (SRE_ULHDCP_REG_BASE + 0x1B0)  /* ULHDCP模块用于DFX的保留寄存器。 */
#define SRE_ULHDCP_REG_RW_RSV1_DFX_REG  (SRE_ULHDCP_REG_BASE + 0x1B4)  /* ULHDCP模块用于DFX的保留寄存器。 */
#define SRE_ULHDCP_REG_RW_RSV2_DFX_REG  (SRE_ULHDCP_REG_BASE + 0x1B8)  /* ULHDCP模块用于DFX的保留寄存器。 */
#define SRE_ULHDCP_REG_RO_RSV0_DFX_REG  (SRE_ULHDCP_REG_BASE + 0x1C0)  /* ULHDCP模块用于DFX的保留寄存器。 */
#define SRE_ULHDCP_REG_RO_RSV1_DFX_REG  (SRE_ULHDCP_REG_BASE + 0x1C4)  /* ULHDCP模块用于DFX的保留寄存器。 */
#define SRE_ULHDCP_REG_RO_RSV2_DFX_REG  (SRE_ULHDCP_REG_BASE + 0x1C8)  /* ULHDCP模块用于DFX的保留寄存器。 */
#define SRE_ULHDCP_REG_AXIRD_DFX_CFG_REG  (SRE_ULHDCP_REG_BASE + 0x1D0)  /* ULHDCP模块AXI总线读命令通道DFX配置寄存器。 */
#define SRE_ULHDCP_REG_AXIWR_DFX_CFG_REG  (SRE_ULHDCP_REG_BASE + 0x1D4)  /* ULHDCP模块AXI总线写命令通道DFX配置寄存器。 */
#define SRE_ULHDCP_REG_AXIRD_DFX_RPT_REG  (SRE_ULHDCP_REG_BASE + 0x1D8)  /* ULHDCP模块AXI总线读命令通道DFX状态上报寄存器。 */
#define SRE_ULHDCP_REG_AXIWR_DFX_RPT_REG  (SRE_ULHDCP_REG_BASE + 0x1DC)  /* ULHDCP模块AXI总线写命令通道DFX状态上报寄存器。 */
#define SRE_ULHDCP_REG_AXIWR_TIMES_RPT_REG  (SRE_ULHDCP_REG_BASE + 0x1E0)  /* ULHDCP模块AXI总线写命令通道写次数状态上报寄存器。 */
#define SRE_ULHDCP_REG_AXIRD_TIMES_RPT_REG  (SRE_ULHDCP_REG_BASE + 0x1E4)  /* ULHDCP模块AXI总线读命令通道写次数状态上报寄存器。 */
#define SRE_ULHDCP_REG_AXI_OTSD_0CNT_REG  (SRE_ULHDCP_REG_BASE + 0x1E8)  /* ULHDCP模块AXI总线读命令通道OutStanding深度上报寄存器。 */
#define SRE_ULHDCP_REG_AXI_OTSD_1CNT_REG  (SRE_ULHDCP_REG_BASE + 0x1EC)  /* ULHDCP模块AXI总线写命令通道写OutStanding深度上报寄存器。 */
#define SRE_ULHDCP_REG_ADDSPE_OVERTIME_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x1F0)  /* ULHDCP模块ADD POE（核间消息）时超时控制寄存器。 */
#define SRE_ULHDCP_REG_POE_SPE_ADDR_REG  (SRE_ULHDCP_REG_BASE + 0x1F4)  /* ULHDCP模块向POE模块ADD核间消息时的基地址配置寄存器。 */
#define SRE_ULHDCP_REG_ROHCBD_ERR_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x1F8)  /* ULHDCP模块搬移的ROHC BD错误的数据包个数统计计数器。 */
#define SRE_ULHDCP_REG_ADDSPE_CNT_REG  (SRE_ULHDCP_REG_BASE + 0x1FC)  /* ULHDCP模块ADD核间消息次数统计计数器。 */
#define SRE_ULHDCP_REG_ADD_POE_SPE_CTRL_REG  (SRE_ULHDCP_REG_BASE + 0x200)  /* ULHDCP模块ADD POE（核间消息）配置控制寄存器。 */



//******************************************************************************

/* SPPE 模块寄存器基地址 */
#define  MC_SPPE_REG_BASE                                 (0x20000000)

/******************************************************************************/
/*                      MC SPPE 寄存器定义                                    */
/******************************************************************************/
#define MC_SAP_OFFSET                                         (0x0007000)

#define MC_SPPE_SAP_THREAD_RBA_REQ_IOOP_0_REG      (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x0)               /* RBA Request的IO操作类型控制 */
#define MC_SPPE_SAP_THREAD_RBA_REQ_ADDR_0_REG      (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x4)               /* RBA Request中LOAD、STORE、LOOKUP指令中CTRL Word中的ADDR域 */
#define MC_SPPE_SAP_THREAD_RBA_REQ_CTRL_0_REG       (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x8)               /* RBA Request中LOAD、STORE、LOOKUP指令中CTRL Word中的CTRL域 */
#define MC_SPPE_SAP_THREAD_RBA_REQ_START_0_REG     (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0xC)               /* RBA Request启动控制 */
#define MC_SPPE_SAP_THREAD_RBA_STATUS_0_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x10)              /* RBA线程控制状态寄存器 */
#define MC_SPPE_SAP_THREAD_RBA_TOUT_TH_0_REG         (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x20)              /* 该寄存器为线程RBA访问Timer计时的阈值 */
#define MC_SPPE_SAP_THREAD_RBA_DATA0_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x40)              /* RBA request或RBA response中的DATA域 */
#define MC_SPPE_SAP_THREAD_RBA_DATA1_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x44)              /* RBA request或RBA response中的DATA域 */
#define MC_SPPE_SAP_THREAD_RBA_DATA2_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x48)              /* RBA request或RBA response中的DATA域 */
#define MC_SPPE_SAP_THREAD_RBA_DATA3_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x4c)              /* RBA request或RBA response中的DATA域 */
#define MC_SPPE_SAP_THREAD_RBA_DATA4_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x50)              /* RBA request或RBA response中的DATA域 */
#define MC_SPPE_SAP_THREAD_RBA_DATA5_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x54)             /* RBA request或RBA response中的DATA域 */
#define MC_SPPE_SAP_THREAD_RBA_DATA6_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x58)             /* RBA request或RBA response中的DATA域 */
#define MC_SPPE_SAP_THREAD_RBA_DATA7_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x5c)             /* RBA request或RBA response中的DATA域 */
#define MC_SPPE_SAP_THREAD_RBA_DATA8_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x60)             /* RBA request或RBA response中的DATA域 */
#define MC_SPPE_SAP_THREAD_RBA_DATA9_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x64)             /* RBA request或RBA response中的DATA域 */
#define MC_SPPE_SAP_THREAD_RBA_DATA10_REG         (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x64)             /* RBA request或RBA response中的DATA域 */
#define MC_SPPE_SAP_THREAD_RBA_DATA11_REG         (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x6c)             /* RBA request或RBA response中的DATA域 */
#define MC_SPPE_SAP_THREAD_RBA_DATA12_REG         (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x70)             /* RBA request或RBA response中的DATA域 */
#define MC_SPPE_SAP_THREAD_RBA_DATA13_REG         (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x74)             /* RBA request或RBA response中的DATA域 */
#define MC_SPPE_SAP_THREAD_RBA_DATA14_REG         (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x78)             /* RBA request或RBA response中的DATA域 */
#define MC_SPPE_SAP_THREAD_RBA_DATA15_REG         (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x7C)             /* RBA request或RBA response中的DATA域 */


#define MC_SPPE_SAP_AVAIL_THREAD_BADDR_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET + 0x800)             /* CPU申请线程基地址寄存器 */
#define MC_SPPE_SAP_RELEASE_THREAD_BADDR_REG         (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x810)             /* CPU释放线程基地址寄存器 */
#define MC_SPPE_SAP_THREAD_ALLOC_FLAG_REG            (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x814)             /* 线程分配状态寄存器 */
#define MC_SPPE_SAP_MEM_INIT_START_REG               (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x820)             /* SAP Memory初始化触发寄存器 */
#define MC_SPPE_SAP_MEM_INIT_STATUS_REG              (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x824)             /* SAP Memory初始化状态寄存器 */
#define MC_SPPE_SAP_INT_RINT_REG                     (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x830)             /* SAP中断原始寄存器 */
#define MC_SPPE_SAP_INT_STATUS_REG                   (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x834)             /* SAP中断状态寄存器 */
#define MC_SPPE_SAP_INT_EN_REG                       (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x838)             /* SAP中断使能寄存器 */
#define MC_SPPE_SAP_BUSY_ACCESS_BADDR_REG            (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x840)             /* busy_access中断发生时，记录重复访问的线程寄存器基地址 */
#define MC_SPPE_SAP_INVALID_REL_BADDR_REG            (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x844)             /* invalid_rel中断发生时，记录被错误写入的线程寄存器基地址 */
#define MC_SPPE_SAP_DUPL_REL_BADDR_REG               (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x848)             /* dupl_rel中断发生时，记录重复释放的线程寄存器基地址 */
#define MC_SPPE_SAP_INVALID_IOOP_BADDR_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x84C)             /* invalid_ioop中断发生时，记录写入IOOP错误的线程寄存器基地址 */
#define MC_SPPE_SAP_INVALID_RESP_BADDR_REG           (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x850)             /* invalid_resp中断发生时，记录错误返回响应的线程ID对应的线程寄存器基地址 */
#define MC_SPPE_SAP_MUTEX_QUEUE_FULL_BADDR_REG       (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x854)             /* Mutex Queue满时，记录A15写入RELEASE_THREAD_BADDR的线程寄存器组基地址 */
#define MC_SPPE_SAP_OE_ACC_ERR_BADDR_REG             (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x858)             /* A15通过SAP错误地发起OE访问时，记录线程寄存器组基地址 */
#define MC_SPPE_SAP_IERR_INSERT_REG                  (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x880)             /* 寄存器允许用户在准备写入SAP内部Memory的数据中插入错误 */
#define MC_SPPE_SAP_IERR_C_INFO_REG                  (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x884)             /* 记录可校正Memory一致性错误的Memory ID */
#define MC_SPPE_SAP_IERR_U_INFO_REG                  (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x888)             /* 记录不可校正Memory一致性错误的Memory ID */
#define MC_SPPE_SAP_IERR_C_CNT_REG                   (MC_SPPE_REG_BASE  +MC_SAP_OFFSET+ 0x88C)             /* 对可校正Memory一致性错误计数，读清。 */
#define MC_SPPE_SAP_IERR_U_CNT_REG                   (MC_SPPE_REG_BASE +MC_SAP_OFFSET+ 0x890)             /* 对不可校正Memory一致性错误计数，读清。 */


#define MC_MASTER_ATOM_CLK_ENABLE         (MC_SPPE_REG_BASE + 0x0003004C)
/******************************************************************************/
/*                      TS 寄存器定义                                    */
/******************************************************************************/
#define MC_SE_EM_INT_STATUS	                 (MC_SPPE_REG_BASE + 0x00010004)
#define MC_SE_EM_INT_ENABLE	                 (MC_SPPE_REG_BASE + 0x00010008)
#define MC_SE_EM_INT_SET	                          (MC_SPPE_REG_BASE + 0x0001000C)
#define MC_SE_DISP_IERR_F_INFO	        (MC_SPPE_REG_BASE + 0x00010020)
#define MC_SE_DISP_IERR_U_CNT	        (MC_SPPE_REG_BASE + 0x00010024)
#define MC_SE_DISP_IERR_U_INFO	        (MC_SPPE_REG_BASE + 0x00010028)
#define MC_SE_DISP_IERR_C_CNT	        (MC_SPPE_REG_BASE + 0x0001002C)
#define MC_SE_DISP_IERR_C_INFO	        (MC_SPPE_REG_BASE + 0x00010030)
#define MC_SE_DISP_BAD_CMD_CNT	        (MC_SPPE_REG_BASE + 0x0001003C)
#define MC_SE_DISP_BAD_CMD_INFO	        (MC_SPPE_REG_BASE + 0x00010040)
#define MC_SE_DISP_FIFO_OVF_CNT	        (MC_SPPE_REG_BASE + 0x0001004C)
#define MC_SE_DISP_FIFO_OVF_INFO	        (MC_SPPE_REG_BASE + 0x00010050)
#define MC_SE_DISP_QUE_LPM_CNT	        (MC_SPPE_REG_BASE + 0x00010060)
#define MC_SE_DISP_QUE_LCAM_CNT	        (MC_SPPE_REG_BASE + 0x00010064)
#define MC_SE_DISP_QUE_EM_SLOW_CNT	(MC_SPPE_REG_BASE + 0x00010068)
#define MC_SE_DISP_QUE_EM_FAST_CNT	(MC_SPPE_REG_BASE + 0x0001006C)
#define MC_SE_DISP_FIFO_STATUS0	        (MC_SPPE_REG_BASE + 0x00010070)
#define MC_SE_EM_DISP_EM_CMD_FIFO_TH	(MC_SPPE_REG_BASE + 0x00010074)
#define MC_SE_EM_DISP_LPM_CMD_FIFO_TH	(MC_SPPE_REG_BASE + 0x00010078)
#define MC_SE_DISP_PROBE0_EN	                 (MC_SPPE_REG_BASE + 0x000100A0)
#define MC_SE_DISP_PROBE0_DONE	        (MC_SPPE_REG_BASE + 0x000100A4)
#define MC_SE_DISP_PROBE0_MSK 	        (MC_SPPE_REG_BASE + 0x000100A8)
#define MC_SE_DISP_PROBE0_MSK16	        (MC_SPPE_REG_BASE + 0x000100E8)
#define MC_SE_DISP_PROBE0_MSK17	        (MC_SPPE_REG_BASE + 0x000100EC)
#define MC_SE_DISP_PROBE0_DAT 	        (MC_SPPE_REG_BASE + 0x000100F0)
#define MC_SE_DISP_PROBE0_DAT16	        (MC_SPPE_REG_BASE + 0x00010130)
#define MC_SE_DISP_PROBE0_DAT17	        (MC_SPPE_REG_BASE + 0x00010134)
#define MC_SE_DISP_PROBE0_RSLT 	        (MC_SPPE_REG_BASE + 0x00010138)
#define MC_SE_DISP_PROBE0_RSLT16	        (MC_SPPE_REG_BASE + 0x00010178)
#define MC_SE_DISP_PROBE0_RSLT17	        (MC_SPPE_REG_BASE + 0x0001017C)
#define MC_SE_DISP_PROBE1_EN	                 (MC_SPPE_REG_BASE + 0x00010180)
#define MC_SE_DISP_PROBE1_DONE	        (MC_SPPE_REG_BASE + 0x00010184)
#define MC_SE_DISP_PROBE1_MSK 	        (MC_SPPE_REG_BASE + 0x00010188)
#define MC_SE_DISP_PROBE1_MSK16	        (MC_SPPE_REG_BASE + 0x000101C8)
#define MC_SE_DISP_PROBE1_DAT 	        (MC_SPPE_REG_BASE + 0x000101CC)
#define MC_SE_DISP_PROBE1_DAT16	        (MC_SPPE_REG_BASE + 0x0001020C)
#define MC_SE_DISP_PROBE1_RSLT 	        (MC_SPPE_REG_BASE + 0x00010210)
#define MC_SE_DISP_PROBE1_RSLT16	        (MC_SPPE_REG_BASE + 0x00010250)
#define MC_SE_DISP_ATOM_HASH_CNT	(MC_SPPE_REG_BASE + 0x00010254)
#define MC_SE_DISP_ATOM_MOD_CNT        (MC_SPPE_REG_BASE + 0x00010258)
#define MC_SE_DISP_ATOM_POP_CNT	        (MC_SPPE_REG_BASE + 0x0001025C)
#define MC_SE_DISP_ATOM_PUSH_CNT	(MC_SPPE_REG_BASE + 0x00010260)
#define MC_SE_DISP_ATOM_LPM_SRCH_CNT	(MC_SPPE_REG_BASE + 0x00010264)
#define MC_SE_DISP_ATOM_LCAM_SRCH_CNT	(MC_SPPE_REG_BASE + 0x00010268)
#define MC_SE_DISP_RBA_DISP_CNT	                  (MC_SPPE_REG_BASE + 0x00010270)
#define MC_SE_DISP_RBA_CNT	                          (MC_SPPE_REG_BASE + 0x00010274)
#define MC_SE_DISP_EM_0_CNT	                          (MC_SPPE_REG_BASE + 0x00010278)
#define MC_SE_DISP_EM_1_CNT	                          (MC_SPPE_REG_BASE + 0x0001027C)
#define MC_SE_DISP_LPM_0_CNT	                          (MC_SPPE_REG_BASE + 0x00010280)
#define MC_SE_DISP_ATOM_READ_CNT	         (MC_SPPE_REG_BASE + 0x00010290)
#define MC_SE_DISP_ATOM_WRITE_CNT	         (MC_SPPE_REG_BASE + 0x00010294)
#define MC_SE_DISP_ATOM_EM_SRCH_CNT	(MC_SPPE_REG_BASE + 0x00010298)
#define MC_SE_DISP_ATOM_LOCK_CNT	         (MC_SPPE_REG_BASE + 0x0001029C)
#define MC_SE_DISP_ATOM_UNLOCK_CNT	         (MC_SPPE_REG_BASE + 0x000102A0)
#define MC_SE_DISP_EM_CFG_TBL 	                  (MC_SPPE_REG_BASE + 0x00010300)
#define MC_SE_DISP_EM_HT1_SIZE 	                  (MC_SPPE_REG_BASE + 0x00010340)
#define MC_SE_DISP_EM_HT1_INDEX_MASK 	(MC_SPPE_REG_BASE + 0x00010380)
#define MC_SE_DISP_CRC_CFG_VALUE        (MC_SPPE_REG_BASE + 0x000103C0)
#define MC_SE_DISP_CRC_INIT_MATRIX	(MC_SPPE_REG_BASE + 0x00010400)
#define MC_SE_DISP_LOCK_TAB_WORD	(MC_SPPE_REG_BASE + 0x00010500)
#define MC_SE_DISP_VQ_DEBUG_MOD	        (MC_SPPE_REG_BASE + 0x00010600)
#define MC_SE_DISP_VQ_DEBUG_REQ	        (MC_SPPE_REG_BASE + 0x00010604)
#define MC_SE_DISP_VQ_DEBUG_DONE	(MC_SPPE_REG_BASE + 0x00010608)
#define MC_SE_DISP_VQ_DEBUG_DATA0	(MC_SPPE_REG_BASE + 0x0001060C)
#define MC_SE_DISP_VQ_DEBUG_DATA1	(MC_SPPE_REG_BASE + 0x00010610)
#define MC_SE_EM_CAM_INIT_DONE	        (MC_SPPE_REG_BASE + 0x00015000)
#define MC_SE_EM_CAM_SCAN_PRD	        (MC_SPPE_REG_BASE + 0x00015004)
#define MC_SE_EM_CAM_SCAN_EN	        (MC_SPPE_REG_BASE + 0x00015008)
#define MC_SE_LPM_CAM_BASE_ADDR	        (MC_SPPE_REG_BASE + 0x0001500C)
#define MC_SE_EM_CAM_BASE_ADDR	        (MC_SPPE_REG_BASE + 0x00015010)
#define MC_SE_EM_CAM_RCL_TH	                         (MC_SPPE_REG_BASE + 0x00015014)
#define MC_SE_EM_CAM_HPTR_L245W	        (MC_SPPE_REG_BASE + 0x00015018)
#define MC_SE_EM_CAM_HPTR_L245R	                 (MC_SPPE_REG_BASE + 0x0001501C)
#define MC_SE_EM_CAM_TPTR_L245W	        (MC_SPPE_REG_BASE + 0x00015020)
#define MC_SE_EM_CAM_TPTR_L245R	                 (MC_SPPE_REG_BASE + 0x00015024)
#define MC_SE_EM_CAM_IDLENTRY_L245W	        (MC_SPPE_REG_BASE + 0x00015028)
#define MC_SE_EM_CAM_IDLENTRY_L245R	        (MC_SPPE_REG_BASE + 0x0001502C)
#define MC_SE_EM_CAM_HPTR_L490W	        (MC_SPPE_REG_BASE + 0x00015030)
#define MC_SE_EM_CAM_HPTR_L490R	                 (MC_SPPE_REG_BASE + 0x00015034)
#define MC_SE_EM_CAM_TPTR_L490W	        (MC_SPPE_REG_BASE + 0x00015038)
#define MC_SE_EM_CAM_TPTR_L490R	                 (MC_SPPE_REG_BASE + 0x0001503C)
#define MC_SE_EM_CAM_IDLENTRY_L490W        (MC_SPPE_REG_BASE + 0x00015040)
#define MC_SE_EM_CAM_IDLENTRY_L490R	        (MC_SPPE_REG_BASE + 0x00015044)
#define MC_SE_EM_CFG_TBL 	                          (MC_SPPE_REG_BASE + 0x00015100)
#define MC_SE_EM_KT_SIZE 	                                   (MC_SPPE_REG_BASE + 0x00015140)
#define MC_SE_EM_HT1_BASE_ADDR 	        (MC_SPPE_REG_BASE + 0x00015180)
#define MC_SE_EM_KT_BASE_ADDR 	        (MC_SPPE_REG_BASE + 0x000151C0)
#define MC_SE_EM_AGE_BASE_ADDR 	        (MC_SPPE_REG_BASE + 0x00015200)
#define MC_SE_EM_FREE_FIFO_UP_TH 	(MC_SPPE_REG_BASE + 0x00015240)
#define MC_SE_EM_FREE_FIFO_LOW_TH      (MC_SPPE_REG_BASE + 0x00015280)
#define MC_SE_EM_KT_HEAD_POINTER 	(MC_SPPE_REG_BASE + 0x000152C0)
#define MC_SE_EM_KT_TAIL_POINTER 	(MC_SPPE_REG_BASE + 0x00015300)
#define MC_SE_LPM_CAM_GMR                       (MC_SPPE_REG_BASE + 0x00015340)
#define MC_SE_LPM_CAM_SEL_GMR	        (MC_SPPE_REG_BASE + 0x00015400)
#define MC_SE_EM_POOL_EN	                 (MC_SPPE_REG_BASE + 0x00015410)
#define MC_SE_EM_TIMEOUT_TH	                 (MC_SPPE_REG_BASE + 0x0001541C)
#define MC_SE_EM_FIFO_OVF_CNT	        (MC_SPPE_REG_BASE + 0x00015434)
#define MC_SE_EM_FIFO_OVF_INFO	        (MC_SPPE_REG_BASE + 0x00015438)
#define MC_SE_EM_TIMEOUT_CNT	        (MC_SPPE_REG_BASE + 0x0001543C)
#define MC_SE_EM_TIMEOUT_INFO	        (MC_SPPE_REG_BASE + 0x00015440)
#define MC_SE_EM_IERR_U_CNT	        (MC_SPPE_REG_BASE + 0x00015444)
#define MC_SE_EM_IERR_U_INFO	        (MC_SPPE_REG_BASE + 0x00015448)
#define MC_SE_EM_IERR_L_CNT	        (MC_SPPE_REG_BASE + 0x0001544C)
#define MC_SE_EM_IERR_L_INFO	        (MC_SPPE_REG_BASE + 0x00015450)
#define MC_SE_EM_IERR_C_CNT	        (MC_SPPE_REG_BASE + 0x00015454)
#define MC_SE_EM_IERR_C_INFO	        (MC_SPPE_REG_BASE + 0x00015458)
#define MC_SE_EM_IERR_F_INFO	        (MC_SPPE_REG_BASE + 0x0001545C)
#define MC_SE_EM_FIFO_STATUS0	        (MC_SPPE_REG_BASE + 0x00015460)
#define MC_SE_EM_KT_RSLT_FIFO_TH	        (MC_SPPE_REG_BASE + 0x0001546C)
#define MC_SE_EM_COMP_RSLT_FIFO_TH	(MC_SPPE_REG_BASE + 0x00015470)
#define MC_SE_EM_READ_ONCE_FIFO_TH	(MC_SPPE_REG_BASE + 0x00015474)
#define MC_SE_EM_KEY_INFO_FIFO_TH	(MC_SPPE_REG_BASE + 0x0001547C)
#define MC_SE_EM_AGE_BP_EN	                 (MC_SPPE_REG_BASE + 0x00015480)
#define MC_SE_ESM_IERR_U_CNT	        (MC_SPPE_REG_BASE + 0x00015484)
#define MC_SE_ESM_IERR_U_INFO	        (MC_SPPE_REG_BASE + 0x00015488)
#define MC_SE_ESM_IERR_C_CNT	        (MC_SPPE_REG_BASE + 0x0001548C)
#define MC_SE_ESM_IERR_C_INFO	        (MC_SPPE_REG_BASE + 0x00015490)
#define MC_SE_ESM_INT_STATUS	                 (MC_SPPE_REG_BASE + 0x00015494)
#define MC_SE_ESM_INT_ENABLE	                 (MC_SPPE_REG_BASE + 0x00015498)
#define MC_SE_ESM_INT_SET	                 (MC_SPPE_REG_BASE + 0x0001549C)
#define MC_SE_ESM_FIFO_OVF_INFO	        (MC_SPPE_REG_BASE + 0x000154A0)
#define MC_SE_ESM_FIFO_OVF_CNT	        (MC_SPPE_REG_BASE + 0x000154A4)
#define MC_SE_ESM_FIFO_STATUS	        (MC_SPPE_REG_BASE + 0x000154A8)
#define MC_SE_ESM_EM_EXTB0_FIFO_AFUL_TH	        (MC_SPPE_REG_BASE + 0x000154AC)
#define MC_SE_ESM_EM_EXTB1_FIFO_AFUL_TH	        (MC_SPPE_REG_BASE + 0x000154B0)
#define MC_SE_ESM_EM_HT_BYPASS_FIFO_AFUL_TH	(MC_SPPE_REG_BASE + 0x000154B4)
#define MC_SE_ESM_EM_HT_INFO_FIFO_AFUL_TH	(MC_SPPE_REG_BASE + 0x000154B8)
#define MC_SE_ESM_EM_DMC_HT_FIFO_AFUL_TH	(MC_SPPE_REG_BASE + 0x000154BC)
#define MC_SE_ESM_EM_KT_BYPASS_FIFO_AFUL_TH	(MC_SPPE_REG_BASE + 0x000154C0)
#define MC_SE_ESM_EM_KT_INFO_FIFO_AFUL_TH	(MC_SPPE_REG_BASE + 0x000154C4)
#define MC_SE_ESM_EM_DMC_KT_FIFO_AFUL_TH	(MC_SPPE_REG_BASE + 0x000154C8)
#define MC_SE_EM_SEARCH_CNT	                                  (MC_SPPE_REG_BASE + 0x00015500)
#define MC_SE_EM_RD_CAM_IDX_CNT	                         (MC_SPPE_REG_BASE + 0x00015504)
#define MC_SE_EM_WR_CAM_IDX_CNT	                (MC_SPPE_REG_BASE + 0x00015508)
#define MC_SE_EM_RD_CAM_CNT	                                  (MC_SPPE_REG_BASE + 0x00015510)
#define MC_SE_EM_WR_CAM_CNT	                         (MC_SPPE_REG_BASE + 0x0001551C)
#define MC_SE_EM_RD_HT1_CNT	                                  (MC_SPPE_REG_BASE + 0x00015520)
#define MC_SE_EM_WR_HT1_CNT	                                  (MC_SPPE_REG_BASE + 0x00015524)
#define MC_SE_LPM_SEARCH_CNT	                         (MC_SPPE_REG_BASE + 0x00015528)
#define MC_SE_EM_RD_KT_CNT	                                  (MC_SPPE_REG_BASE + 0x0001553C)
#define MC_SE_EM_WR_KT_CNT	                                  (MC_SPPE_REG_BASE + 0x00015540)
#define MC_SE_EM_PUSH_CAM_CNT	                (MC_SPPE_REG_BASE + 0x00015544)
#define MC_SE_EM_POP_CAM_CNT	                (MC_SPPE_REG_BASE + 0x00015548)
#define MC_SE_EM_PUSH_KT_CNT	                (MC_SPPE_REG_BASE + 0x0001554C)
#define MC_SE_EM_POP_KT_CNT	                        (MC_SPPE_REG_BASE + 0x00015550)
#define MC_SE_EM_AGE_REQ_CNT	                (MC_SPPE_REG_BASE + 0x00015554)
#define MC_SE_EM_HT1_RSLT_CNT	                (MC_SPPE_REG_BASE + 0x0001555C)
#define MC_SE_EM_KT_RSLT_CNT	                (MC_SPPE_REG_BASE + 0x00015560)
#define MC_SE_EM_CKEY_RD_CNT	                (MC_SPPE_REG_BASE + 0x00015564)
#define MC_SE_EM_HT1_REQ_CNT	                (MC_SPPE_REG_BASE + 0x00015568)
#define MC_SE_EM_KT_REQ_CNT	                        (MC_SPPE_REG_BASE + 0x0001556C)
#define MC_SE_EM_POOL_KT_REQ_CNT	        (MC_SPPE_REG_BASE + 0x00015574)
#define MC_SE_EM_POOL_KT_RSLT_CNT	        (MC_SPPE_REG_BASE + 0x00015578)
#define MC_SE_EM_AGE_DROP_CNT	                (MC_SPPE_REG_BASE + 0x0001557C)
#define MC_SE_EM_FLIST_DEBUG_REQ	        (MC_SPPE_REG_BASE + 0x00015600)
#define MC_SE_EM_FLIST_DEBUG_DONE	        (MC_SPPE_REG_BASE + 0x00015604)
#define MC_SE_EM_FLIST_DEBUG_DATA	        (MC_SPPE_REG_BASE + 0x00015608)
#define MC_SE_DISP_EM_DISP_0_CNT	                (MC_SPPE_REG_BASE + 0x00015800)
#define MC_SE_DISP_EM_DISP_1_CNT	                 (MC_SPPE_REG_BASE + 0x00015804)
#define MC_SE_DISP_LPM_DISP_1_CNT	        (MC_SPPE_REG_BASE + 0x00015808)
#define MC_SE_DISP_LCAM_DISP_1_CNT	        (MC_SPPE_REG_BASE + 0x0001580C)
#define MC_SE_DISP_LPM_RSP_FIFO_AFUL_TH	        (MC_SPPE_REG_BASE + 0x00015810)
#define MC_SE_DISP_LCAM_RSP_FIFO_AFUL_TH	(MC_SPPE_REG_BASE + 0x00015814)
#define MC_SE_DISP_EM_RSP_FIFO_AFUL_TH	        (MC_SPPE_REG_BASE + 0x00015818)
#define MC_SE_DISP_FIFO_STATUS1	                          (MC_SPPE_REG_BASE + 0x00015820)

/*LCAM*/
#define MC_LCAM_OFFSET                       (0x0c000)
#define MC_LCAM_INT_STATUS	         (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000004)
#define MC_LCAM_INT_ENABLE              (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000008)
#define MC_LCAM_CORE_INT_STATUS  (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000020)
#define MC_LCAM_CORE_INT_ENABLE  (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000024)
#define MC_LCAM_CORE_INT_SET         (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000028)
#define MC_LCAM_RAM_INIT_START    (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000030)
#define MC_LCAM_RAM_INIT_STATUS  (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000034)
#define MC_LCAM_BG_SCAN                    (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000038)
#define MC_LCAM_RM_TRANS0               (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000048)
#define MC_LCAM_TCAM_PROFILE         (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000100)
#define MC_LCAM_TCAM_GMR                (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000140)
#define MC_LCAM_RBA_ABORT               (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x000001E0)
#define MC_LCAM_REQ_TCAM_CNT	 (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x000001E4)
#define MC_LCAM_RSP_TCAM_CNT	 (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000220)
#define MC_LCAM_IERR_C_INFO            (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000230)
#define MC_LCAM_IERR_U_INFO            (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000234)
#define MC_LCAM_IERR_C_TCAM_INFO   (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000238)
#define MC_LCAM_IERR_U_TCAM_INFO   (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x0000023C)
#define MC_LCAM_BAD_CMD_AA0_INFO   (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000240)
#define MC_LCAM_IERR_C_CNT                 (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x0000024C)
#define MC_LCAM_IERR_U_CNT                 (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000250)
#define MC_LCAM_IERR_C_TCAM_CNT     (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000254)
#define MC_LCAM_IERR_U_TCAM_CNT     (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000258)
#define MC_LCAM_TEST_DBG_CFG	    (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000600)
#define MC_LCAM_CORE_CLK_DBG_CFG  (MC_SPPE_REG_BASE + MC_LCAM_OFFSET+ 0x00000604)

/* CACHE 模块寄存器基地址 */
#define MC_CACHE_BASE                             (0x1302b000)

/******************************************************************************/
/*                      MC CACHE 寄存器定义                                   */
/******************************************************************************/
#define MC_CACHE_L3_CTRL_REG                      (MC_CACHE_BASE + 0x0)           /* L3_CTRL为L3 Cache的控制寄存器。 */
#define MC_CACHE_L3_AUCTRL_REG                    (MC_CACHE_BASE + 0x4)           /* L3_AUCTRL为L3 Cache的辅助控制寄存器。 */
#define MC_CACHE_L3_TIMEOUT_REG                   (MC_CACHE_BASE + 0x8)           /* L3_TIMEOUT为L3 Cache的命令timeout配置寄存器。 */
#define MC_CACHE_L3_STATUS_REG                    (MC_CACHE_BASE + 0xC)           /* L3_STATUS为L3 Cache的状态寄存器。 */
#define MC_CACHE_L3_CA_START_REG                  (MC_CACHE_BASE + 0x10)          /* L3_CA_START为L3 Cache的Cacheable空间的起始地址。 */
#define MC_CACHE_L3_CA_END_REG                    (MC_CACHE_BASE + 0x14)          /* L3_CA_END为L3 Cache的Cacheable空间的结束地址。 */
#define MC_CACHE_L3_ARAM_START_REG                (MC_CACHE_BASE + 0x18)          /* L3_ARAM_START为L3 Cache中Sram的安全存储空间起始地址。 */
#define MC_CACHE_L3_ARAM_END_REG                  (MC_CACHE_BASE + 0x1C)          /* L3_ARAM_END为L3 Cache中Sram的安全存储空间结束地址。 */
#define MC_CACHE_L3_SYNC_REG                      (MC_CACHE_BASE + 0x20)          /* L3_SYNC为L3 Cache的同步寄存器。 */
#define MC_CACHE_L3_MAINT_CTRL_REG                (MC_CACHE_BASE + 0x24)          /* L3_MAINT_CTRL为L3 Cache 按地址 clean/invalidate操作的配置寄存器。 */
#define MC_CACHE_L3_MAINT_ADDR_REG                (MC_CACHE_BASE + 0x28)          /* L3_MAINT_ADDR为L3 Cache 按地址 clean/invalidate操作的配置寄存器。 */
#define MC_CACHE_L3_LOCKDOWN_REG                  (MC_CACHE_BASE + 0x2C)          /* L3_LOCKDOWN为L3 Cache的锁定Way配置寄存器。 */
#define MC_L3_PREFETCH_REG                        (MC_CACHE_BASE + 0x30)          /* L3_PREFECTH为L3 Cache的硬件预取操作配置寄存器。 */
#define MC_L3_ALLOC_FREQ_REG                      (MC_CACHE_BASE + 0x34)          /* L3_PREFECTH为L3 Cache的控制allocate发生频度的配置寄存器。 */
#define MC_CACHE_L3_BANK0_INTM_REG                (MC_CACHE_BASE + 0x100)         /* L3_BANK0_INTM为BANK0的中断屏蔽寄存器。 */
#define MC_CACHE_L3_BANK0_RINT_REG                (MC_CACHE_BASE + 0x104)         /* L3_BANK0_RINT为BANK0的原始中断状态寄存器。 */
#define MC_CACHE_L3_BANK0_INTS_REG                (MC_CACHE_BASE + 0x108)         /* L3_BANK0_INTS为BANK0的屏蔽后的中断状态寄存器。 */
#define MC_CACHE_L3_BANK0_INTC_REG                (MC_CACHE_BASE + 0x10C)         /* L3_BANK0_INTC为BANK0的中断清除寄存器。 */
#define MC_CACHE_L3_BANK1_INTM_REG                (MC_CACHE_BASE + 0x110)         /* L3_BANK1_INTM为BANK1的中断屏蔽寄存器。 */
#define MC_CACHE_L3_BANK1_RINT_REG                (MC_CACHE_BASE + 0x114)         /* L3_BANK1_RINT为BANK1的原始中断状态寄存器。 */
#define MC_CACHE_L3_BANK1_INTS_REG                (MC_CACHE_BASE + 0x118)         /* L3_BANK1_INTS为BANK1的屏蔽后的中断状态寄存器。 */
#define MC_CACHE_L3_BANK1_INTC_REG                (MC_CACHE_BASE + 0x11C)         /* L3_BANK1_INTC为BANK1的中断清除寄存器。 */
#define MC_CACHE_L3_BANK2_INTM_REG                (MC_CACHE_BASE + 0x120)         /* L3_BANK2_INTM为BANK2的中断屏蔽寄存器。 */
#define MC_CACHE_L3_BANK2_RINT_REG                (MC_CACHE_BASE + 0x124)         /* L3_BANK2_RINT为BANK2的原始中断状态寄存器。 */
#define MC_CACHE_L3_BANK2_INTS_REG                (MC_CACHE_BASE + 0x128)         /* L3_BANK2_INTS为BANK2的屏蔽后的中断状态寄存器。 */
#define MC_CACHE_L3_BANK2_INTC_REG                (MC_CACHE_BASE + 0x12C)         /* L3_BANK2_INTC为BANK2的中断清除寄存器。 */
#define MC_CACHE_L3_BANK3_INTM_REG                (MC_CACHE_BASE + 0x130)         /* L3_BANK3_INTM为BANK3的中断屏蔽寄存器。 */
#define MC_CACHE_L3_BANK3_RINT_REG                (MC_CACHE_BASE + 0x134)         /* L3_BANK3_RINT为BANK3的原始中断状态寄存器。 */
#define MC_CACHE_L3_BANK3_INTS_REG                (MC_CACHE_BASE + 0x138)         /* L3_BANK3_INTS为BANK3的屏蔽后的中断状态寄存器。 */
#define MC_CACHE_L3_BANK3_INTC_REG                (MC_CACHE_BASE + 0x13C)         /* L3_BANK3_INTC为BANK3的中断清除寄存器。 */
#define MC_CACHE_L3_BANK4_INTM_REG                (MC_CACHE_BASE + 0x140)         /* L3_BANK4_INTM为BANK4的中断屏蔽寄存器。 */
#define MC_CACHE_L3_BANK4_RINT_REG                (MC_CACHE_BASE + 0x144)         /* L3_BANK4_RINT为BANK4的原始中断状态寄存器。 */
#define MC_CACHE_L3_BANK4_INTS_REG                (MC_CACHE_BASE + 0x148)         /* L3_BANK4_INTS为BANK4的屏蔽后的中断状态寄存器。 */
#define MC_CACHE_L3_BANK4_INTC_REG                (MC_CACHE_BASE + 0x14C)         /* L3_BANK4_INTC为BANK4的中断清除寄存器。 */
#define MC_CACHE_L3_BANK5_INTM_REG                (MC_CACHE_BASE + 0x150)         /* L3_BANK5_INTM为BANK5的中断屏蔽寄存器。 */
#define MC_CACHE_L3_BANK5_RINT_REG                (MC_CACHE_BASE + 0x154)         /* L3_BANK5_RINT为BANK5的原始中断状态寄存器。 */
#define MC_CACHE_L3_BANK5_INTS_REG                (MC_CACHE_BASE + 0x158)         /* L3_BANK5_INTS为BANK5的屏蔽后的中断状态寄存器。 */
#define MC_CACHE_L3_BANK5_INTC_REG                (MC_CACHE_BASE + 0x15C)         /* L3_BANK5_INTC为BANK5的中断清除寄存器。 */
#define MC_CACHE_L3_BANK6_INTM_REG                (MC_CACHE_BASE + 0x160)         /* L3_BANK6_INTM为BANK6的中断屏蔽寄存器。 */
#define MC_CACHE_L3_BANK6_RINT_REG                (MC_CACHE_BASE + 0x164)         /* L3_BANK6_RINT为BANK6的原始中断状态寄存器。 */
#define MC_CACHE_L3_BANK6_INTS_REG                (MC_CACHE_BASE + 0x168)         /* L3_BANK6_INTS为BANK6的屏蔽后的中断状态寄存器。 */
#define MC_CACHE_L3_BANK6_INTC_REG                (MC_CACHE_BASE + 0x16C)         /* L3_BANK6_INTC为BANK6的中断清除寄存器。 */
#define MC_CACHE_L3_BANK7_INTM_REG                (MC_CACHE_BASE + 0x170)         /* L3_BANK7_INTM为BANK7的中断屏蔽寄存器。 */
#define MC_CACHE_L3_BANK7_RINT_REG                (MC_CACHE_BASE + 0x174)         /* L3_BANK7_RINT为BANK7的原始中断状态寄存器。 */
#define MC_CACHE_L3_BANK7_INTS_REG                (MC_CACHE_BASE + 0x178)         /* L3_BANK7_INTS为BANK7的屏蔽后的中断状态寄存器。 */
#define MC_CACHE_L3_BANK7_INTC_REG                (MC_CACHE_BASE + 0x17C)         /* L3_BANK7_INTC为BANK7的中断清除寄存器。 */
#define MC_CACHE_L3_BANK0_EVENT_TYPE_REG          (MC_CACHE_BASE + 0x180)         /* L3_BANK0_CNT_TYPE为BANK0的事件类型配置寄存器。 */
#define MC_CACHE_L3_BANK1_EVENT_TYPE_REG          (MC_CACHE_BASE + 0x190)         /* L3_BANK1_CNT_TYPE为BANK1的事件类型配置寄存器。 */
#define MC_CACHE_L3_BANK2_EVENT_TYPE_REG          (MC_CACHE_BASE + 0x1A0)         /* L3_BANK2_CNT_TYPE为BANK2的事件类型配置寄存器。 */
#define MC_CACHE_L3_BANK3_EVENT_TYPE_REG          (MC_CACHE_BASE + 0x1B0)         /* L3_BANK3_CNT_TYPE为BANK3的事件类型配置寄存器。 */
#define MC_CACHE_L3_BANK4_EVENT_TYPE_REG          (MC_CACHE_BASE + 0x1C0)         /* L3_BANK4_CNT_TYPE为BANK4的事件类型配置寄存器。 */
#define MC_CACHE_L3_BANK5_EVENT_TYPE_REG          (MC_CACHE_BASE + 0x1D0)         /* L3_BANK5_CNT_TYPE为BANK5的事件类型配置寄存器。 */
#define MC_CACHE_L3_BANK6_EVENT_TYPE_REG          (MC_CACHE_BASE + 0x1E0)         /* L3_BANK6_CNT_TYPE为BANK6的事件类型配置寄存器。 */
#define MC_CACHE_L3_BANK7_EVENT_TYPE_REG          (MC_CACHE_BASE + 0x1F0)         /* L3_BANK7_CNT_TYPE为BANK7的事件类型配置寄存器。 */
#define MC_CACHE_L3_BANK0_EVENT_CNT0_REG          (MC_CACHE_BASE + 0x200)         /* L3_BANK0_INT_CNT0为BANK0的事件统计寄存器0。 */
#define MC_CACHE_L3_BANK0_EVENT_CNT1_REG          (MC_CACHE_BASE + 0x204)         /* L3_BANK0_INT_CNT1为BANK0的事件统计寄存器1。 */
#define MC_CACHE_L3_BANK0_EVENT_CNT2_REG          (MC_CACHE_BASE + 0x208)         /* L3_BANK0_INT_CNT2为BANK0的事件统计寄存器2。 */
#define MC_CACHE_L3_BANK0_EVENT_CNT3_REG          (MC_CACHE_BASE + 0x20C)         /* L3_BANK0_INT_CNT3为BANK0的事件统计寄存器3。 */
#define MC_CACHE_L3_BANK1_EVENT_CNT0_REG          (MC_CACHE_BASE + 0x210)         /* L3_BANK1_INT_CNT0为BANK1的事件统计寄存器0。 */
#define MC_CACHE_L3_BANK1_EVENT_CNT1_REG          (MC_CACHE_BASE + 0x214)         /* L3_BANK1_INT_CNT1为BANK1的事件统计寄存器1。 */
#define MC_CACHE_L3_BANK1_EVENT_CNT2_REG          (MC_CACHE_BASE + 0x218)         /* L3_BANK1_INT_CNT2为BANK1的事件统计寄存器2。 */
#define MC_CACHE_L3_BANK1_EVENT_CNT3_REG          (MC_CACHE_BASE + 0x21C)         /* L3_BANK1_INT_CNT3为BANK1的事件统计寄存器3。 */
#define MC_CACHE_L3_BANK2_EVENT_CNT0_REG          (MC_CACHE_BASE + 0x220)         /* L3_BANK2_INT_CNT0为BANK2的事件统计寄存器0。 */
#define MC_CACHE_L3_BANK2_EVENT_CNT1_REG          (MC_CACHE_BASE + 0x224)         /* L3_BANK2_INT_CNT1为BANK2的事件统计寄存器1。 */
#define MC_CACHE_L3_BANK2_EVENT_CNT2_REG          (MC_CACHE_BASE + 0x228)         /* L3_BANK2_INT_CNT2为BANK2的事件统计寄存器2。 */
#define MC_CACHE_L3_BANK2_EVENT_CNT3_REG          (MC_CACHE_BASE + 0x22C)         /* L3_BANK2_INT_CNT3为BANK2的事件统计寄存器3。 */
#define MC_CACHE_L3_BANK3_EVENT_CNT0_REG          (MC_CACHE_BASE + 0x230)         /* L3_BANK3_INT_CNT0为BANK3的事件统计寄存器0。 */
#define MC_CACHE_L3_BANK3_EVENT_CNT1_REG          (MC_CACHE_BASE + 0x234)         /* L3_BANK3_INT_CNT1为BANK3的事件统计寄存器1。 */
#define MC_CACHE_L3_BANK3_EVENT_CNT2_REG          (MC_CACHE_BASE + 0x238)         /* L3_BANK3_INT_CNT2为BANK3的事件统计寄存器2。 */
#define MC_CACHE_L3_BANK3_EVENT_CNT3_REG          (MC_CACHE_BASE + 0x23C)         /* L3_BANK3_INT_CNT3为BANK3的事件统计寄存器3。 */
#define MC_CACHE_L3_BANK4_EVENT_CNT0_REG          (MC_CACHE_BASE + 0x240)         /* L3_BANK4_INT_CNT0为BANK4的事件统计寄存器0。 */
#define MC_CACHE_L3_BANK4_EVENT_CNT1_REG          (MC_CACHE_BASE + 0x244)         /* L3_BANK4_INT_CNT1为BANK4的事件统计寄存器1。 */
#define MC_CACHE_L3_BANK4_EVENT_CNT2_REG          (MC_CACHE_BASE + 0x248)         /* L3_BANK4_INT_CNT2为BANK4的事件统计寄存器2。 */
#define MC_CACHE_L3_BANK4_EVENT_CNT3_REG          (MC_CACHE_BASE + 0x24C)         /* L3_BANK4_INT_CNT3为BANK4的事件统计寄存器3。 */
#define MC_CACHE_L3_BANK5_EVENT_CNT0_REG          (MC_CACHE_BASE + 0x250)         /* L3_BANK5_INT_CNT0为BANK5的事件统计寄存器0。 */
#define MC_CACHE_L3_BANK5_EVENT_CNT1_REG          (MC_CACHE_BASE + 0x254)         /* L3_BANK5_INT_CNT1为BANK5的事件统计寄存器1。 */
#define MC_CACHE_L3_BANK5_EVENT_CNT2_REG          (MC_CACHE_BASE + 0x258)         /* L3_BANK5_INT_CNT2为BANK5的事件统计寄存器2。 */
#define MC_CACHE_L3_BANK5_EVENT_CNT3_REG          (MC_CACHE_BASE + 0x25C)         /* L3_BANK5_INT_CNT3为BANK5的事件统计寄存器3。 */
#define MC_CACHE_L3_BANK6_EVENT_CNT0_REG          (MC_CACHE_BASE + 0x260)         /* L3_BANK6_INT_CNT0为BANK6的事件统计寄存器0。 */
#define MC_CACHE_L3_BANK6_EVENT_CNT1_REG          (MC_CACHE_BASE + 0x264)         /* L3_BANK6_INT_CNT1为BANK6的事件统计寄存器1。 */
#define MC_CACHE_L3_BANK6_EVENT_CNT2_REG          (MC_CACHE_BASE + 0x268)         /* L3_BANK6_INT_CNT2为BANK6的事件统计寄存器2。 */
#define MC_CACHE_L3_BANK6_EVENT_CNT3_REG          (MC_CACHE_BASE + 0x26C)         /* L3_BANK6_INT_CNT3为BANK6的事件统计寄存器3。 */
#define MC_CACHE_L3_BANK7_EVENT_CNT0_REG          (MC_CACHE_BASE + 0x270)         /* L3_BANK7_INT_CNT0为BANK7的事件统计寄存器0。 */
#define MC_CACHE_L3_BANK7_EVENT_CNT1_REG          (MC_CACHE_BASE + 0x274)         /* L3_BANK7_INT_CNT1为BANK7的事件统计寄存器1。 */
#define MC_CACHE_L3_BANK7_EVENT_CNT2_REG          (MC_CACHE_BASE + 0x278)         /* L3_BANK7_INT_CNT2为BANK7的事件统计寄存器2。 */
#define MC_CACHE_L3_BANK7_EVENT_CNT3_REG          (MC_CACHE_BASE + 0x27C)         /* L3_BANK7_INT_CNT3为BANK7的事件统计寄存器3。 */
#define MC_CACHE_L3_BANK0_TRAM_ECC_REG            (MC_CACHE_BASE + 0x300)         /* L3_BANK0_TRAM_ECC为BANK0 Tag Ram最近一次ECC出错位置信息。 */
#define MC_CACHE_L3_BANK0_DRAM_ECC_REG            (MC_CACHE_BASE + 0x304)         /* L3_BANK0_DRAM_ECC为 BANK0 Data Ram最近一次ECC出错位置信息。 */
#define MC_CACHE_L3_BANK0_ECC_INJECT_REG          (MC_CACHE_BASE + 0x308)         /* L3_BANK0_ECC_INJECT为BANK0的ECC错误注入寄存器。 */
#define MC_CACHE_L3_BANK1_TRAM_ECC_REG            (MC_CACHE_BASE + 0x310)         /* L3_BANK1_TRAM_ECC为BANK1 Tag Ram最近一次ECC出错位置信息。 */
#define MC_CACHE_L3_BANK1_DRAM_ECC_REG            (MC_CACHE_BASE + 0x314)         /* L3_BANK1_DRAM_ECC为 BANK1 Data Ram最近一次ECC出错位置信息。 */
#define MC_CACHE_L3_BANK1_ECC_INJECT_REG          (MC_CACHE_BASE + 0x318)         /* L3_BANK1_ECC_INJECT为BANK1的ECC错误注入寄存器。 */
#define MC_CACHE_L3_BANK2_TRAM_ECC_REG            (MC_CACHE_BASE + 0x320)         /* L3_BANK2_TRAM_ECC为BANK2 Tag Ram最近一次ECC出错位置信息。 */
#define MC_CACHE_L3_BANK2_DRAM_ECC_REG            (MC_CACHE_BASE + 0x324)         /* L3_BANK2_DRAM_ECC为 BANK2 Data Ram最近一次ECC出错位置信息。 */
#define MC_CACHE_L3_BANK2_ECC_INJECT_REG          (MC_CACHE_BASE + 0x328)         /* L3_BANK2_ECC_INJECT为BANK2的ECC错误注入寄存器。 */
#define MC_CACHE_L3_BANK3_TRAM_ECC_REG            (MC_CACHE_BASE + 0x330)         /* L3_BANK3_TRAM_ECC为BANK3 Tag Ram最近一次ECC出错位置信息。 */
#define MC_CACHE_L3_BANK3_DRAM_ECC_REG            (MC_CACHE_BASE + 0x334)         /* L3_BANK3_DRAM_ECC为 BANK3 Data Ram最近一次ECC出错位置信息。 */
#define MC_CACHE_L3_BANK3_ECC_INJECT_REG          (MC_CACHE_BASE + 0x338)         /* L3_BANK3_ECC_INJECT为BANK3的ECC错误注入寄存器。 */
#define MC_CACHE_L3_BANK4_TRAM_ECC_REG            (MC_CACHE_BASE + 0x340)         /* L3_BANK4_TRAM_ECC为BANK4 Tag Ram最近一次ECC出错位置信息。 */
#define MC_CACHE_L3_BANK4_DRAM_ECC_REG            (MC_CACHE_BASE + 0x344)         /* L3_BANK4_DRAM_ECC为 BANK4 Data Ram最近一次ECC出错位置信息。 */
#define MC_CACHE_L3_BANK4_ECC_INJECT_REG          (MC_CACHE_BASE + 0x348)         /* L3_BANK4_ECC_INJECT为BANK4的ECC错误注入寄存器。 */
#define MC_CACHE_L3_BANK5_TRAM_ECC_REG            (MC_CACHE_BASE + 0x350)         /* L3_BANK5_TRAM_ECC为BANK5 Tag Ram最近一次ECC出错位置信息。 */
#define MC_CACHE_L3_BANK5_DRAM_ECC_REG            (MC_CACHE_BASE + 0x354)         /* L3_BANK5_DRAM_ECC为 BANK5 Data Ram最近一次ECC出错位置信息。 */
#define MC_CACHE_L3_BANK5_ECC_INJECT_REG          (MC_CACHE_BASE + 0x358)         /* L3_BANK5_ECC_INJECT为BANK5的ECC错误注入寄存器。 */
#define MC_CACHE_L3_BANK6_TRAM_ECC_REG            (MC_CACHE_BASE + 0x360)         /* L3_BANK6_TRAM_ECC为BANK6 Tag Ram最近一次ECC出错位置信息。 */
#define MC_CACHE_L3_BANK6_DRAM_ECC_REG            (MC_CACHE_BASE + 0x364)         /* L3_BANK6_DRAM_ECC为 BANK6 Data Ram最近一次ECC出错位置信息。 */
#define MC_CACHE_L3_BANK6_ECC_INJECT_REG          (MC_CACHE_BASE + 0x368)         /* L3_BANK6_ECC_INJECT为BANK6的ECC错误注入寄存器。 */
#define MC_CACHE_L3_BANK7_TRAM_ECC_REG            (MC_CACHE_BASE + 0x370)         /* L3_BANK7_TRAM_ECC为BANK7 Tag Ram最近一次ECC出错位置信息。 */
#define MC_CACHE_L3_BANK7_DRAM_ECC_REG            (MC_CACHE_BASE + 0x374)         /* L3_BANK7_DRAM_ECC为 BANK7 Data Ram最近一次ECC出错位置信息。 */
#define MC_CACHE_L3_BANK7_ECC_INJECT_REG          (MC_CACHE_BASE + 0x378)         /* L3_BANK7_ECC_INJECT为BANK7的ECC错误注入寄存器。 */


/*LMEM 寄存器配置*/

#define MC_LMEM_OFFSET  (0x4000)

#define MC_LMEM_CFG_128BIT0_WORD0     (MC_SPPE_REG_BASE  + 0x04000000)
#define MC_LMEM_CFG_128BIT0_WORD1     (MC_SPPE_REG_BASE  + 0x04000004)
#define MC_LMEM_CFG_128BIT0_WORD2     (MC_SPPE_REG_BASE  + 0x04000008)
#define MC_LMEM_CFG_128BIT0_WORD3     (MC_SPPE_REG_BASE  + 0x0400000C)

#define MC_LMEM_GP_32BIT_RW0          (MC_SPPE_REG_BASE  + 0x05200000)
#define MC_LMEM_GP_32BIT_CAR0         (MC_SPPE_REG_BASE  + 0x05400000)
#define MC_LMEM_GP_64BIT_RW0_WORD0    (MC_SPPE_REG_BASE  + 0x05600000)
#define MC_LMEM_GP_64BIT_RW0_WORD1    (MC_SPPE_REG_BASE  + 0x05600004)

#define MC_LMEM_GP_64BIT_CAR0_WORD0   (MC_SPPE_REG_BASE  + 0x05800000)

#define MC_LMEM_GP_128BIT_RW0_WORD0   (MC_SPPE_REG_BASE  + 0x05A00000)
#define MC_LMEM_GP_128BIT_RW0_WORD1   (MC_SPPE_REG_BASE  + 0x05A00004)
#define MC_LMEM_GP_128BIT_RW0_WORD2   (MC_SPPE_REG_BASE  + 0x05A00008)
#define MC_LMEM_GP_128BIT_RW0_WORD3   (MC_SPPE_REG_BASE  + 0x05A0000C)

#define MC_LMEM_GP_128BIT_CAR_WORD0   (MC_SPPE_REG_BASE  + 0x05C00000)


#define MC_LMEM_INT_ENABLE               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000808)
#define MC_LMEM_INT_STATUS               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000804)
#define MC_LMEM_INT_SET                  (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x0000080C)
#define MC_LMEM_IERR_F_INFO              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000820)
#define MC_LMEM_IERR_L_INFO              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000824)
#define MC_LMEM_IERR_U_INFO              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000828)
#define MC_LMEM_IERR_C_INFO              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x0000082C)
#define MC_LMEM_BAD_CMD_INFO             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000830)
#define MC_LMEM_PH_ERR_INFO              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000834)
#define MC_LMEM_FS_ERR_INFO              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000838)
#define MC_LMEM_Q_OVFL_INFO              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x0000083C)
#define MC_LMEM_NCP_OVFL_INFO            (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000840)
#define MC_LMEM_IERR_L_CNT               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000850)
#define MC_LMEM_IERR_U_CNT               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000854)
#define MC_LMEM_IERR_C_CNT               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000858)
#define MC_LMEM_BAD_CMD_CNT              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x0000085C)
#define MC_LMEM_PH_ERR_CNT               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000860)
#define MC_LMEM_FS_ERR_CNT               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000864)
#define MC_LMEM_Q_OVFL_CNT               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000868)
#define MC_LMEM_SE_OVFL_CNT              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x0000086C)
#define SRE_LMEM_TM_OVFL_CNT              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000870)
#define MC_LMEM_NCP_OVFL_CNT             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000874)
#define MC_LMEM_ABORT_ERR_CNT            (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000878)
#define MC_LMEM_IERR_U_DATA              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000880)
#define MC_LMEM_RAM_INIT_START           (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008A0)
#define MC_LMEM_RAM_INIT_STATUS          (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008A4)
#define MC_LMEM_CFG_MEM_OFFSET           (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008B0)
#define MC_LMEM_CFG_MEM_IND_OFFSET       (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008B4)
#define MC_LMEM_CFG_MEM_POL_OFFSET       (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008B8)
#define MC_LMEM_CFG_MEM_Q_OFFSET         (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008BC)
#define MC_LMEM_CFG_MEM_SEM_OFFSET       (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008C0)
#define MC_LMEM_POL_SYS_TIMER            (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008D0)
#define MC_LMEM_POL_TICK_CNT             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008D8)
#define MC_LMEM_POL_VIRTUAL_TH           (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008DC)
#define MC_LMEM_STAT_TS_DIV              (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x000008F0)
#define MC_LMEM_ADDNCP_ADDR_MOD          (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000900)
#define MC_LMEM_CLEARBIT_ADDR_MOD        (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000904)
#define MC_LMEM_MS0_EMEM_NCP_ADDR_MOD    (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000910)
#define MC_LMEM_DBG_BP_CFG               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000B00)
#define MC_LMEM_DBG_FIFO_TH0             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000B04)
#define MC_LMEM_DBG_FIFO_TH1             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000B08)
#define MC_LMEM_DBG_FIFO_TH2             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000B0C)
#define MC_LMEM_DBG_FIFO_OVFL            (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000B10)
#define MC_LMEM_DBG_STATUS               (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000B14)
#define MC_LMEM_DBG_NCF_FIFO             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000B18)
#define MC_LMEM_DIAG_CTL                 (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C00)
#define MC_LMEM_DIAG_INTRV_R             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C04)
#define MC_LMEM_DIAG_INTRV_W             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C08)
#define MC_LMEM_DIAG_CNT_RBA_REQ         (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C0C)
#define MC_LMEM_DIAG_CNT_RBA_RSP         (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C10)
#define MC_LMEM_DIAG_CNT_EMEM_REQ        (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C14)
#define MC_LMEM_DIAG_CNT_SE_REQ          (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C18)
#define SRE_LMEM_DIAG_CNT_TM_REQ          (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C1C)
#define MC_LMEM_DIAG_CNT_MS0             (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C20)
#define MC_LMEM_TIMING                   (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C40)
#define MC_LMEM_POWER1                   (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C44)
#define MC_LMEM_POWER2                   (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C48)
#define MC_LMEM_ICG                      (MC_SPPE_REG_BASE + MC_LMEM_OFFSET + 0x00000C4C)

/* TM 模块寄存器基地址 */
#if 0         /* z00202052 */
#define SRE_TM_BASE                             (0x11800000)
#else
#define SRE_TM_BASE                             (0xe1800000)
#endif        /* z00202052 */

/******************************************************************************/
/*                      TM 寄存器定义                                      */
/******************************************************************************/
#define SRE_TM_RSV0_REG                         (SRE_TM_BASE + 0x0)              /* TM预留寄存器0 */
#define SRE_TM_RSV1_REG                         (SRE_TM_BASE + 0x4)              /* TM预留寄存器1 */
#define SRE_TM_RSV2_REG                         (SRE_TM_BASE + 0x8)              /* TM预留寄存器2 */
#define SRE_TM_RSV3_REG                         (SRE_TM_BASE + 0xC)              /* TM预留寄存器3 */
#define SRE_TM_CFG_OK_REG                       (SRE_TM_BASE + 0x10)             /* TM配置结束寄存器 */
#define SRE_TM_DROP_FIFO_THR_REG                (SRE_TM_BASE + 0x14)             /* TM丢弃FIFO溢出和回读水线 */
#define SRE_TM_ENDIEN_CTRL_REG                  (SRE_TM_BASE + 0x18)             /* TM访问DDR大小端模式控制寄存器 */
#define SRE_TM_RAM_CFG_ERR_INST_REG             (SRE_TM_BASE + 0x1C)             /* TM_RAM_CFG模块错误植入寄存器 */
#define SRE_TM_OTHER_ERR_INST_REG               (SRE_TM_BASE + 0x20)             /* TM_OTHER 模块错误植入寄存器 */
#define SRE_TM_CF_OUT_DEPTH_REG                 (SRE_TM_BASE + 0x24)             /* TM MST口outstanding深度寄存器 */
#define SRE_TM_CF_INTER_CNT_REG                 (SRE_TM_BASE + 0x28)             /* TM MST口AXI总线ERROR重传时间配置寄存器 */
#define SRE_TM_CF_FAIL_CNT_REG                  (SRE_TM_BASE + 0x2C)             /* TM MST口AXI总线重传配置次数上报中断寄存器 */
#define SRE_TM_CF_TIMEOUT_REG                   (SRE_TM_BASE + 0x30)             /* TM MST重传次数过多中断上报未清除超时时间配置寄存器 */
#define SRE_TM_TOKEN_BS_MODE_REG                (SRE_TM_BASE + 0x34)             /* 令牌桶初始化模式寄存器 */
#define SRE_TM_RFS_MEM_TIMING_CTRL_REG          (SRE_TM_BASE + 0x38)             /* TM RFS类 MEM时序控制信号 */
#define SRE_TM_RAS_MEM_TIMING_CTRL_REG          (SRE_TM_BASE + 0x3C)             /* TM_RAS类 MEM时序控制信号 */
#define SRE_TM_RAS_HD_POWER_CTRL_REG            (SRE_TM_BASE + 0x40)             /* TM RAS_HD类MEM电源控制信号 */
#define SRE_TM_STORE_CFG_SPACE_REG              (SRE_TM_BASE + 0x44)             /* TM 缓存描述符空间配置寄存器 */
#define SRE_TM_WRED_TS_SEL_REG                  (SRE_TM_BASE + 0x48)             /* TM WRED表查找索引选择配置寄存器 */
#define SRE_TM_HAC_USER_REG                     (SRE_TM_BASE + 0x4C)             /* TM发送给其他加速器时使用USER */
#define SRE_TM_OWEN_USER_REG                    (SRE_TM_BASE + 0x50)             /* TM内部自己使用USER */
#define SRE_TM_ECC_BYPASS_REG                   (SRE_TM_BASE + 0x54)             /* TM_ECC_BYPASS寄存器 */
#define SRE_TM_SLV_OTD_CHK_BYPASS_REG           (SRE_TM_BASE + 0x58)             /* TM内部SLV口OUT */
#define SRE_TM_VM_BYPASS_REG                    (SRE_TM_BASE + 0x5C)             /* TM_虚拟化BYPASS寄存器 */
#define SRE_TM_ACK_SPPE_BP_MODE_REG             (SRE_TM_BASE + 0x60)             /* TM响应SPPE统计反压控制寄存器 */
#define SRE_TM_VMID_MAP_TAB1_REG                (SRE_TM_BASE + 0x100)            /* 虚拟化VMID映射表1 */
#define SRE_TM_VMID_MAP_TAB2_REG                (SRE_TM_BASE + 0x104)            /* 虚拟化VMID映射表2 */
#define SRE_TM_VM_QID_MAP_TAB_0_REG             (SRE_TM_BASE + 0x108)            /* 虚拟化VM对应队列配置信息表 */
#define SRE_TM_VM_QID_MAP_TAB_1_REG             (SRE_TM_BASE + 0x10C)            /* 虚拟化VM对应队列配置信息表 */
#define SRE_TM_VM_QERR_INTMSK_REG               (SRE_TM_BASE + 0x148)            /* 虚拟化队列号产生错误中断屏蔽寄存器 */
#define SRE_TM_VM_QERR_RINT_REG                 (SRE_TM_BASE + 0x14C)            /* 虚拟化队列号产生错误原始中断寄存器 */
#define SRE_TM_VM_QERR_INTSTS_REG               (SRE_TM_BASE + 0x150)            /* 虚拟化队列号产生错误中断状态寄存器 */
#define SRE_TM_VM_QERR_ID_0_REG                 (SRE_TM_BASE + 0x154)            /* 虚拟化队列号产生错误中断错误队列ID号寄存器 */
#define SRE_TM_VM_QERR_ID_1_REG                 (SRE_TM_BASE + 0x158)            /* 虚拟化队列号产生错误中断错误队列ID号寄存器 */
#define SRE_TM_RSV4_REG                         (SRE_TM_BASE + 0x200)            /* TM预留寄存器4 */
#define SRE_TM_RSV5_REG                         (SRE_TM_BASE + 0x204)            /* TM预留寄存器5 */
#define SRE_TM_RSV6_REG                         (SRE_TM_BASE + 0x208)            /* TM预留寄存器6 */
#define SRE_TM_RSV7_REG                         (SRE_TM_BASE + 0x20C)            /* TM预留寄存器7 */
#define SRE_TM_FQ_RLS_CNT_REG                   (SRE_TM_BASE + 0x25C)            /* TM FQ级别 释放空调度个数计数器 */
#define SRE_TM_COM_RLS_CNT_REG                  (SRE_TM_BASE + 0x260)            /* TM COM级别 释放空调度个数计数器 */
#define SRE_TM_LOC_RLS_CNT_REG                  (SRE_TM_BASE + 0x264)            /* TM LOC级别 释放空调度个数计数器 */
#define SRE_TM_QUEUE_SHAP_FSM3_PRB_REG          (SRE_TM_BASE + 0x268)            /* QUEUE_SHAP状态机探针3 */
#define SRE_TM_QUEUE_SHAP_FSM2_PRB_REG          (SRE_TM_BASE + 0x26C)            /* QUEUE_SHAP状态机探针2 */
#define SRE_TM_QUEUE_SHAP_FSM1_PRB_REG          (SRE_TM_BASE + 0x270)            /* QUEUE_SHAP状态机探针1 */
#define SRE_TM_QUEUE_DROP_FSM_PRB_REG           (SRE_TM_BASE + 0x274)            /* TM_SLV状态机探针 */
#define SRE_TM_QUEUE_TK_FSM_PRB_REG             (SRE_TM_BASE + 0x278)            /* QUEUE_TK状态机探针 */
#define SRE_TM_SLV_FSM_PRB_REG                  (SRE_TM_BASE + 0x27C)            /* TM_SLV状态机探针 */
#define SRE_TM_QUEUE_STA_FSM1_PRB_REG           (SRE_TM_BASE + 0x280)            /* QUEUE_STA状态机探针1 */
#define SRE_TM_QUEUE_STA_FSM2_PRB_REG           (SRE_TM_BASE + 0x284)            /* QUEUE_STA状态机探针2 */
#define SRE_TM_QUEUE_SCH_FSM_PRB_REG            (SRE_TM_BASE + 0x288)            /* QUEUE_SCH状态机探针 */
#define SRE_TM_QUEUE_M_FSM_PRB_REG              (SRE_TM_BASE + 0x28C)            /* QUEUE_M状态机探针 */
#define SRE_TM_FREE_PTR_CNT_REG                 (SRE_TM_BASE + 0x290)            /* TM剩余FREE BUF指针计数器 */
#define SRE_TM_MST_CNT_EN_REG                   (SRE_TM_BASE + 0x294)            /* MST口内部通道统计使能标志 */
#define SRE_TM_MST_CNT_CLR_REG                  (SRE_TM_BASE + 0x298)            /* MST口内部通道统计清除信号 */
#define SRE_TM_MST_LATENCY_AVG_REG              (SRE_TM_BASE + 0x29C)            /* MST口平均延时寄存器 */
#define SRE_TM_MST_LATENCY_MAX_REG              (SRE_TM_BASE + 0x2A0)            /* MST口最大延时寄存器 */
#define SRE_TM_MST_RD_ACC_REG                   (SRE_TM_BASE + 0x2A4)            /* MST口读计数器 */
#define SRE_TM_MST_WR_ACC_REG                   (SRE_TM_BASE + 0x2A8)            /* MST口写计数器 */
#define SRE_TM_MST_RD_OTD_1_REG                 (SRE_TM_BASE + 0x2AC)            /* MST口读outstanding计数器1 */
#define SRE_TM_MST_RD_OTD_2_REG                 (SRE_TM_BASE + 0x2B0)            /* MST口读outstanding计数器2 */
#define SRE_TM_MST_WR_OTD_1_REG                 (SRE_TM_BASE + 0x2B4)            /* MST口写outstanding计数器1 */
#define SRE_TM_MST_WR_OTD_2_REG                 (SRE_TM_BASE + 0x2B8)            /* MST口写outstanding计数器2 */
#define SRE_TM_PORT_SEND_DATA_DFX_0_REG         (SRE_TM_BASE + 0x2BC)            /* TM PORT发送数据探针 */
#define SRE_TM_PORT_SEND_DATA_DFX_1_REG         (SRE_TM_BASE + 0x2C0)            /* TM PORT发送数据探针 */
#define SRE_TM_SPPE_BP_REG                      (SRE_TM_BASE + 0x2FC)            /* SPPE给TM反压探针寄存器 */
#define SRE_TM_MPE_BP_REG                       (SRE_TM_BASE + 0x300)            /* MPE给TM反压探针寄存器 */
#define SRE_TM_PPE_BP_REG                       (SRE_TM_BASE + 0x304)            /* PPE给TM反压探针寄存器 */
#define SRE_TM_POE_BP_REG                       (SRE_TM_BASE + 0x308)            /* POE给TM反压探针信号 */
#define SRE_TM_CPU_ADD_WORD0_REG                (SRE_TM_BASE + 0x30C)            /* CPU写TM模块msg WORD0 */
#define SRE_TM_CPU_ADD_WORD1_REG                (SRE_TM_BASE + 0x310)            /* CPU写TM模块msg WORD1 */
#define SRE_TM_CPU_ADD_WORD2_REG                (SRE_TM_BASE + 0x314)            /* CPU写TM模块msg WORD2 */
#define SRE_TM_CPU_ADD_WORD3_REG                (SRE_TM_BASE + 0x318)            /* CPU写TM模块msg WORD3 */
#define SRE_TM_ACC_ADD_WORD0_REG                (SRE_TM_BASE + 0x31C)            /* 加速器写TM模块msg WORD0 */
#define SRE_TM_ACC_ADD_WORD1_REG                (SRE_TM_BASE + 0x320)            /* 加速器写TM模块msg WORD1 */
#define SRE_TM_ACC_ADD_WORD2_REG                (SRE_TM_BASE + 0x324)            /* 加速器写TM模块msg WORD2 */
#define SRE_TM_ACC_ADD_WORD3_REG                (SRE_TM_BASE + 0x328)            /* 加速器写TM模块msg WORD3 */
#define SRE_TM_MST_SEND_TIMES_INTMSK_REG        (SRE_TM_BASE + 0x32C)            /* MST推送次数超过配置值中断掩码寄存器 */
#define SRE_TM_MST_SEND_TIMES_RINT_REG          (SRE_TM_BASE + 0x330)            /* MST推送次数超过配置值原始中断寄存器 */
#define SRE_TM_MST_SEND_TIMES_INTSTS_REG        (SRE_TM_BASE + 0x334)            /* MST推送次数超过配置值中断状态寄存器 */
#define SRE_TM_BIND_ERR_INTMSK_REG              (SRE_TM_BASE + 0x338)            /* 端口不在绑定关系中断屏蔽寄存器 */
#define SRE_TM_BIND_ERR_RINT_REG                (SRE_TM_BASE + 0x33C)            /* 端口不在绑定关系原始中断寄存器 */
#define SRE_TM_BIND_ERR_INTSTS_REG              (SRE_TM_BASE + 0x340)            /* 端口不在绑定关系中断寄存器状态寄存器 */
#define SRE_TM_BIND_TK_ERR_STS1_REG             (SRE_TM_BASE + 0x344)            /* 端口不在绑定关系对应TK端口寄存器1 */
#define SRE_TM_BIND_TK_ERR_STS2_REG             (SRE_TM_BASE + 0x348)            /* 端口不在绑定关系对应TK端口寄存器2 */
#define SRE_TM_PORT_FIFO_INTMSK_REG             (SRE_TM_BASE + 0x350)            /* TM_PORT_FIFO模块中断屏蔽寄存器 */
#define SRE_TM_PORT_FIFO_RINT_REG               (SRE_TM_BASE + 0x354)            /* TM_PORT_FIFO原始中断寄存器 */
#define SRE_TM_PORT_FIFO_INTSTS_REG             (SRE_TM_BASE + 0x358)            /* TM_PORT_FIFO屏蔽后中断状态寄存器 */
#define SRE_TM_FIFO1_INTMSK_REG                 (SRE_TM_BASE + 0x35C)            /* TM_FIFO第一部分模块中断屏蔽寄存器 */
#define SRE_TM_FIFO1_RINT_REG                   (SRE_TM_BASE + 0x360)            /* TM_FIFO第一部分原始中断寄存器 */
#define SRE_TM_FIFO1_INTSTS_REG                 (SRE_TM_BASE + 0x364)            /* TM_FIFO第一部分屏蔽后中断状态寄存器 */
#define SRE_TM_FIFO2_INTMSK_REG                 (SRE_TM_BASE + 0x368)            /* TM_FIFO第二部分模块中断屏蔽寄存器 */
#define SRE_TM_FIFO2_RINT_REG                   (SRE_TM_BASE + 0x36C)            /* TM_FIFO第二部分原始中断寄存器 */
#define SRE_TM_FIFO2_INTSTS_REG                 (SRE_TM_BASE + 0x370)            /* TM_FIFO第二部分屏蔽后中断状态寄存器 */
#define SRE_TM_FIFO3_INTMSK_REG                 (SRE_TM_BASE + 0x374)            /* TM_FIFO第三部分模块中断屏蔽寄存器 */
#define SRE_TM_FIFO3_RINT_REG                   (SRE_TM_BASE + 0x378)            /* TM_FIFO第三部分原始中断寄存器 */
#define SRE_TM_FIFO3_INTSTS_REG                 (SRE_TM_BASE + 0x37C)            /* TM_FIFO第三部分屏蔽后中断状态寄存器 */
#define SRE_TM_QUEUE_M_FIFO_DFX_REG             (SRE_TM_BASE + 0x380)            /* QUEUE_M 模块FIFO DFX寄存器 */
#define SRE_TM_QUEUE_SHAP_FIFO_DFX_REG          (SRE_TM_BASE + 0x384)            /* QUEUE SHAP模块FIFO DFX寄存器 */
#define SRE_TM_SLV_FIFO_DFX_REG                 (SRE_TM_BASE + 0x388)            /* AXI SLV模块FIFO DFX寄存器 */
#define SRE_TM_QUEUE_TK_FIFO_DFX_REG            (SRE_TM_BASE + 0x38C)            /* QUEUE_TK 模块FIFO DFX寄存器 */
#define SRE_TM_PORT_FIFO_DFX_REG                (SRE_TM_BASE + 0x390)            /* TM_PORT_FIFO DFX寄存器 */
#define SRE_TM_QUEUE_SCH_FIFO_DFX_REG           (SRE_TM_BASE + 0x394)            /* QUEUE_SCH 模块FIFO DFX寄存器 */
#define SRE_TM_QUEUE_STA_FIFO_DFX_REG           (SRE_TM_BASE + 0x398)            /* QUEUE_STA 模块FIFO DFX寄存器 */
#define SRE_TM_OTHER_FIFO_DFX_REG               (SRE_TM_BASE + 0x39C)            /* TM OTHER模块FIFO DFX寄存器 */
#define SRE_TM_CPU_ADDPKT_CNT_REG               (SRE_TM_BASE + 0x3A0)            /* TM CPU成功添加包任务个数计数器 */
#define SRE_TM_ACC_ADDPKT_CNT_REG               (SRE_TM_BASE + 0x3A4)            /* TM 加速器成功添加包任务个数计数器 */
#define SRE_TM_QM2TK_PKT_CNT_REG                (SRE_TM_BASE + 0x3A8)            /* TM队列管理模块输出给Trunk模块包个数计数器 */
#define SRE_TM_NOTEN_DROP_CNT_REG               (SRE_TM_BASE + 0x3AC)            /* TM 队列不使能丢弃包个数统计计数器 */
#define SRE_TM_WRED_DROP_CNT_REG                (SRE_TM_BASE + 0x3B0)            /* TM 队列WRED/TAIL丢弃包个数统计计数器 */
#define SRE_TM_NOBUF_DROP_CNT_REG               (SRE_TM_BASE + 0x3B4)            /* TM 队列缓存空间满丢弃包个数统计计数器 */
#define SRE_TM_OUTPORT_DROP_CNT_REG             (SRE_TM_BASE + 0x3B8)            /* TM 队列指定端口丢弃个数统计寄存器 */
#define SRE_TM_SPPE_PPE_DROP_CNT_REG            (SRE_TM_BASE + 0x3BC)            /* TM 队列SPPE/PPE丢弃包个数统计计数器 */
#define SRE_TM_PORT0_SEND_CNT_REG               (SRE_TM_BASE + 0x3C0)            /* TM PORT0发送包数寄存器 */
#define SRE_TM_PORT1_SEND_CNT_REG               (SRE_TM_BASE + 0x3C4)            /* TM PORT1发送包数寄存器 */
#define SRE_TM_PORT2_SEND_CNT_REG               (SRE_TM_BASE + 0x3C8)            /* TM PORT2发送包数寄存器 */
#define SRE_TM_PORT3_SEND_CNT_REG               (SRE_TM_BASE + 0x3CC)            /* TM PORT3发送包数寄存器 */
#define SRE_TM_PORT4_SEND_CNT_REG               (SRE_TM_BASE + 0x3D0)            /* TM PORT4发送包数寄存器 */
#define SRE_TM_PORT5_SEND_CNT_REG               (SRE_TM_BASE + 0x3D4)            /* TM PORT5发送包数寄存器 */
#define SRE_TM_PORT6_SEND_CNT_REG               (SRE_TM_BASE + 0x3D8)            /* TM PORT6发送包数寄存器 */
#define SRE_TM_PORT7_SEND_CNT_REG               (SRE_TM_BASE + 0x3DC)            /* TM PORT7发送包数寄存器 */
#define SRE_TM_PORT8_SEND_CNT_REG               (SRE_TM_BASE + 0x3E0)            /* TM PORT8发送包数寄存器 */
#define SRE_TM_PORT9_SEND_CNT_REG               (SRE_TM_BASE + 0x3E4)            /* TM PORT9发送包数寄存器 */
#define SRE_TM_PORT10_SEND_CNT_REG              (SRE_TM_BASE + 0x3E8)            /* TM PORT10发送包数寄存器 */
#define SRE_TM_PORT11_SEND_CNT_REG              (SRE_TM_BASE + 0x3EC)            /* TM PORT11发送包数寄存器 */
#define SRE_TM_PORT12_SEND_CNT_REG              (SRE_TM_BASE + 0x3F0)            /* TM PORT12发送包数寄存器 */
#define SRE_TM_PORT13_SEND_CNT_REG              (SRE_TM_BASE + 0x3F4)            /* TM PORT13发送包数寄存器 */
#define SRE_TM_PORT14_SEND_CNT_REG              (SRE_TM_BASE + 0x3F8)            /* TM PORT14发送包数寄存器 */
#define SRE_TM_PORT15_SEND_CNT_REG              (SRE_TM_BASE + 0x3FC)            /* TM PORT15发送包数寄存器 */
#define SRE_TM_STA_CNT_CLR_REG                  (SRE_TM_BASE + 0x414)            /* TM读清寄存器清除信号配置寄存器 */
#define SRE_TM_RAM_INIT_DONE_REG                (SRE_TM_BASE + 0x418)            /* TM内部RAM初始化完成指示寄存器 */
#define SRE_TM_TOKEN_INIT_DONE_REG              (SRE_TM_BASE + 0x41C)            /* TM剩余令牌桶初始化完毕指示寄存器 */
#define SRE_TM_PKT_VLD_CORE_0_REG               (SRE_TM_BASE + 0x420)            /* Core添加是否成功寄存器 */
#define SRE_TM_PKT_VLD_CORE_1_REG               (SRE_TM_BASE + 0x424)            /* Core添加是否成功寄存器 */
#define SRE_TM_SOLE_CNT_REG                     (SRE_TM_BASE + 0x530)            /* TM队列独享空间大小寄存器 */
#define SRE_TM_ACTIVE_USE_REG                   (SRE_TM_BASE + 0x534)            /* TM使用队列数寄存器 */
#define SRE_TM_DROP_OVERFLOW_ADDR_REG           (SRE_TM_BASE + 0x538)            /* TM丢弃队列溢出DDR基地址寄存器 */
#define SRE_TM_DROP_QDEPTH_REG                  (SRE_TM_BASE + 0x53C)            /* TM丢弃队列溢出深度 */
#define SRE_TM_WRED_RANDOM_INIT_REG             (SRE_TM_BASE + 0x540)            /* TM WRED随机数初始值 */
#define SRE_TM_PORT_DROP_EN_REG                 (SRE_TM_BASE + 0x544)            /* TM指定端口丢包寄存器 */
#define SRE_TM_BMU_BUF_REG                      (SRE_TM_BASE + 0x548)            /* TM 基于释放BMU BUFFER基地址寄存器 */
#define SRE_TM_WEIGHT_OFFSET_REG                (SRE_TM_BASE + 0x54C)            /* TM权重偏移寄存器 */
#define SRE_TM_TK_BIND_TAB_0_REG                (SRE_TM_BASE + 0x550)            /* TRUNK绑定表 */
#define SRE_TM_TK_BIND_TAB_1_REG                (SRE_TM_BASE + 0x554)            /* TRUNK绑定表 */
#define SRE_TM_PORT_WADDR_0_REG                 (SRE_TM_BASE + 0x590)            /* TM发送端口地址寄存器 */
#define SRE_TM_PORT_WADDR_1_REG                 (SRE_TM_BASE + 0x594)            /* TM发送端口地址寄存器 */
#define SRE_TM_PORT_PART_DESC_0_REG             (SRE_TM_BASE + 0x5D0)            /* TM发送端口描述符域段配置寄存器寄存器 */
#define SRE_TM_PORT_PART_DESC_1_REG             (SRE_TM_BASE + 0x5D4)            /* TM发送端口描述符域段配置寄存器寄存器 */
#define SRE_TM_PORT_SEND_TYPE_0_REG             (SRE_TM_BASE + 0x610)            /* TM端口发送特性表 */
#define SRE_TM_PORT_SEND_TYPE_1_REG             (SRE_TM_BASE + 0x614)            /* TM端口发送特性表 */
#define SRE_TM_TK_IR_TAB_0_REG                  (SRE_TM_BASE + 0x650)            /* Trunk端口速率参数表 */
#define SRE_TM_TK_IR_TAB_1_REG                  (SRE_TM_BASE + 0x654)            /* Trunk端口速率参数表 */
#define SRE_TM_WRED_OFFSET_REG                  (SRE_TM_BASE + 0x690)            /* WRED参数偏移寄存器 */
#define SRE_TM_DEF_PORT_0_REG                   (SRE_TM_BASE + 0x694)            /* TM默认端口寄存器 */
#define SRE_TM_DEF_PORT_1_REG                   (SRE_TM_BASE + 0x698)            /* TM默认端口寄存器 */
#define SRE_TM_TK_SOFT_BP_REG                   (SRE_TM_BASE + 0x6D4)            /* TM软件基于TK口配置反压寄存器 */
#define SRE_TM_NODE_CODE_REG                    (SRE_TM_BASE + 0x6DC)            /* TM消息源设备号 */
#define SRE_TM_RAM_CFG_INTMSK_REG               (SRE_TM_BASE + 0x700)            /* TM_RAM_CFG模块中断屏蔽寄存器 */
#define SRE_TM_RAM_CFG_RINT_REG                 (SRE_TM_BASE + 0x704)            /* TM_RAM_CFG原始中断寄存器 */
#define SRE_TM_RAM_CFG_INTSTS_REG               (SRE_TM_BASE + 0x708)            /* TM_OTHER屏蔽后中断状态寄存器 */
#define SRE_TM_OTHER_INTMSK_REG                 (SRE_TM_BASE + 0x70C)            /* TM_OTHER模块中断屏蔽寄存器 */
#define SRE_TM_OTHER_RINT_REG                   (SRE_TM_BASE + 0x710)            /* TM_OTHER原始中断寄存器 */
#define SRE_TM_OTHER_INTSTS_REG                 (SRE_TM_BASE + 0x714)            /* TM_OTHER屏蔽后中断状态寄存器 */
#define SRE_TM_ANOTHER_INTMSK_REG               (SRE_TM_BASE + 0x718)            /* TM_ANOTHER模块中断屏蔽寄存器 */
#define SRE_TM_ANOTHER_RINT_REG                 (SRE_TM_BASE + 0x71C)            /* TM_ANOTHER原始中断寄存器 */
#define SRE_TM_ANOTHER_INTSTS_REG               (SRE_TM_BASE + 0x720)            /* TM_ANOTHER屏蔽后中断状态寄存器 */
#define SRE_TM_TK_CNT_0_REG                     (SRE_TM_BASE + 0x730)            /* Trunk端口缓存队列统计计数器 */
#define SRE_TM_TK_CNT_1_REG                     (SRE_TM_BASE + 0x734)            /* Trunk端口缓存队列统计计数器 */
#define SRE_TM_POOL_RLS_CNT_0_REG               (SRE_TM_BASE + 0x770)            /* TM释放BMU Buffer基于Pool计数器 */
#define SRE_TM_POOL_RLS_CNT_1_REG               (SRE_TM_BASE + 0x774)            /* TM释放BMU Buffer基于Pool计数器 */
#define SRE_TM_POOL_RLS_CNT_CLR_REG             (SRE_TM_BASE + 0x7F0)            /* TM释放BMU Buffer基于Pool计数器 */
#define SRE_TM_QINF_TABLE_0_REG                 (SRE_TM_BASE + 0x800)            /* 队列信息表 */
#define SRE_TM_QINF_TABLE_1_REG                 (SRE_TM_BASE + 0x804)            /* 队列信息表 */
#define SRE_TM_WRED_TABLE_0_REG                 (SRE_TM_BASE + 0x8800)           /* 流队列WRED表 */
#define SRE_TM_WRED_TABLE_1_REG                 (SRE_TM_BASE + 0x8804)           /* 流队列WRED表 */
#define SRE_TM_COM_LINK_TABLE_0_REG             (SRE_TM_BASE + 0xC800)           /* 小区到逻辑端口链接表 */
#define SRE_TM_COM_LINK_TABLE_1_REG             (SRE_TM_BASE + 0xC804)           /* 小区到逻辑端口链接表 */
#define SRE_TM_LOC_LINK_TABLE_0_REG             (SRE_TM_BASE + 0xD800)           /* 逻辑端口到Trunk端口连接表 */
#define SRE_TM_LOC_LINK_TABLE_1_REG             (SRE_TM_BASE + 0xD804)           /* 逻辑端口到Trunk端口连接表 */
#define SRE_TM_LOC_MAP_TAB_0_REG                (SRE_TM_BASE + 0xDD18)           /* 逻辑端口映射表 */
#define SRE_TM_LOC_MAP_TAB_1_REG                (SRE_TM_BASE + 0xDD1C)           /* 逻辑端口映射表 */
#define SRE_TM_COM_MAP_TAB_0_REG                (SRE_TM_BASE + 0xE518)           /* 小区端口映射表 */
#define SRE_TM_COM_MAP_TAB_1_REG                (SRE_TM_BASE + 0xE51C)           /* 小区端口映射表 */
#define SRE_TM_FQ_WEIGHT_TAB_0_REG              (SRE_TM_BASE + 0x10818)          /* 流队列权重表 */
#define SRE_TM_FQ_WEIGHT_TAB_1_REG              (SRE_TM_BASE + 0x1081C)          /* 流队列权重表 */
#define SRE_TM_COM_WEIGHT_TAB_0_REG             (SRE_TM_BASE + 0x18818)          /* 小区权重表 */
#define SRE_TM_COM_WEIGHT_TAB_1_REG             (SRE_TM_BASE + 0x1881C)          /* 小区权重表 */
#define SRE_TM_LOC_WEIGHT_TAB_0_REG             (SRE_TM_BASE + 0x19358)          /* 逻辑端口权重表 */
#define SRE_TM_LOC_WEIGHT_TAB_1_REG             (SRE_TM_BASE + 0x1935C)          /* 逻辑端口权重表 */
#define SRE_TM_LOC_CIR_TAB_0_REG                (SRE_TM_BASE + 0x19870)          /* 逻辑端口C桶shaping参数表 */
#define SRE_TM_LOC_CIR_TAB_1_REG                (SRE_TM_BASE + 0x19874)          /* 逻辑端口C桶shaping参数表 */
#define SRE_TM_LOC_PIR_TAB_0_REG                (SRE_TM_BASE + 0x19D88)          /* 逻辑端口P桶shaping参数表 */
#define SRE_TM_LOC_PIR_TAB_1_REG                (SRE_TM_BASE + 0x19D8C)          /* 逻辑端口P桶shaping参数表 */
#define SRE_TM_COM_CIR_TAB_0_REG                (SRE_TM_BASE + 0x1A2A0)          /* 小区端口C桶shaping参数表 */
#define SRE_TM_COM_CIR_TAB_1_REG                (SRE_TM_BASE + 0x1A2A4)          /* 小区端口C桶shaping参数表 */
#define SRE_TM_COM_PIR_TAB_0_REG                (SRE_TM_BASE + 0x1ADE0)          /* 小区端口P桶shaping参数表 */
#define SRE_TM_COM_PIR_TAB_1_REG                (SRE_TM_BASE + 0x1ADE4)          /* 小区端口P桶shaping参数表 */
#define SRE_TM_FQ_SCH_TYPE_TAB_0_REG            (SRE_TM_BASE + 0x1B920)          /* FQ队列调度属性表 */
#define SRE_TM_FQ_SCH_TYPE_TAB_1_REG            (SRE_TM_BASE + 0x1B924)          /* FQ队列调度属性表 */
#define SRE_TM_FQ_ST_BYTE_TAB_0_REG             (SRE_TM_BASE + 0x1C920)          /* 流队字节列缓存统计表 */
#define SRE_TM_FQ_ST_BYTE_TAB_1_REG             (SRE_TM_BASE + 0x1C924)          /* 流队字节列缓存统计表 */
#define SRE_TM_FQ_ST_NUM_TAB_0_REG              (SRE_TM_BASE + 0x24920)          /* 流队列包个数缓存统计表 */
#define SRE_TM_FQ_ST_NUM_TAB_1_REG              (SRE_TM_BASE + 0x24924)          /* 流队列包个数缓存统计表 */
#define SRE_TM_COM_ST_NUM_TAB_0_REG             (SRE_TM_BASE + 0x2C920)          /* 小区队列缓存统计表 */
#define SRE_TM_COM_ST_NUM_TAB_1_REG             (SRE_TM_BASE + 0x2C924)          /* 小区队列缓存统计表 */
#define SRE_TM_LOC_ST_NUM_TAB_0_REG             (SRE_TM_BASE + 0x2D920)          /* 逻辑端口缓存队列个数统计表 */
#define SRE_TM_LOC_ST_NUM_TAB_1_REG             (SRE_TM_BASE + 0x2D924)          /* 逻辑端口缓存队列个数统计表 */
#define SRE_TM_LOC_ST_BYTE_TAB_0_REG            (SRE_TM_BASE + 0x2DE38)          /* 逻辑端口缓存队列字节数统计表 */
#define SRE_TM_LOC_ST_BYTE_TAB_1_REG            (SRE_TM_BASE + 0x2DE3C)          /* 逻辑端口缓存队列字节数统计表 */
#define SRE_TM_LOC_SD_NUM_TAB_0_REG             (SRE_TM_BASE + 0x2E350)          /* 逻辑端口发送队列个数统计表 */
#define SRE_TM_LOC_SD_NUM_TAB_1_REG             (SRE_TM_BASE + 0x2E354)          /* 逻辑端口发送队列个数统计表 */
#define SRE_TM_LOC_SD_BYTE_TAB_0_REG            (SRE_TM_BASE + 0x2E868)          /* 逻辑端口发送队列字节数统计表 */
#define SRE_TM_LOC_SD_BYTE_TAB_1_REG            (SRE_TM_BASE + 0x2E86C)          /* 逻辑端口发送队列字节数统计表 */
#define SRE_TM_PKT_WORD0_CORE_0_REG             (SRE_TM_BASE + 0x100000)         /* Core写TM模块的msg WORD0 */
#define SRE_TM_PKT_WORD0_CORE_1_REG             (SRE_TM_BASE + 0x100010)         /* Core写TM模块的msg WORD0 */
#define SRE_TM_PKT_WORD1_CORE_0_REG             (SRE_TM_BASE + 0x100004)         /* Core写TM模块的msg WORD1 */
#define SRE_TM_PKT_WORD1_CORE_1_REG             (SRE_TM_BASE + 0x100014)         /* Core写TM模块的msg WORD1 */
#define SRE_TM_PKT_WORD2_CORE_0_REG             (SRE_TM_BASE + 0x100008)         /* Core写TM模块的msg WORD2 */
#define SRE_TM_PKT_WORD2_CORE_1_REG             (SRE_TM_BASE + 0x100018)         /* Core写TM模块的msg WORD2 */
#define SRE_TM_PKT_WORD3_CORE_0_REG             (SRE_TM_BASE + 0x10000C)         /* Core写TM模块的msg WORD3 */
#define SRE_TM_PKT_WORD3_CORE_1_REG             (SRE_TM_BASE + 0x10001C)         /* Core写TM模块的msg WORD3 */
#define SRE_TM_PKT_WORD0_ACC_REG                (SRE_TM_BASE + 0x100400)         /* 加速器写TM模块msg WORD0 */
#define SRE_TM_PKT_WORD1_ACC_REG                (SRE_TM_BASE + 0x100404)         /* 加速器写TM模块msg WORD1 */
#define SRE_TM_PKT_WORD2_ACC_REG                (SRE_TM_BASE + 0x100408)         /* 加速器写TM模块msg WORD2 */
#define SRE_TM_PKT_WORD3_ACC_REG                (SRE_TM_BASE + 0x10040C)         /* 加速器写TM模块msg WORD3 */

/* AQM 模块寄存器表单 */
#define SRE_AQM_BASE                            (SRE_TM_BASE + 0x200000)         /* 使用TM后2M空间 */

/******************************************************************************/
/*                      MC AQM 寄存器定义                                     */
/******************************************************************************/
#define SRE_AQM_VER_DATE_REG                       (SRE_AQM_BASE + 0x0)                 /* AQM 版本寄存器 */
#define SRE_AQM_RFS_EMA_CTRL_REG                   (SRE_AQM_BASE + 0x4)                 /* TM RFS MEM时序控制信号 */
#define SRE_AQM_RAS_EMA_CTRL_REG                   (SRE_AQM_BASE + 0x8)                 /* TM RAS MEM时序控制信号 */
#define SRE_AQM_HD_EMA_CTRL_REG                    (SRE_AQM_BASE + 0xC)                 /* AQM RAM 功耗模式控制 */
#define SRE_AQM_INIT_DONE_REG                      (SRE_AQM_BASE + 0x10)                /* AQM内部初始化完成标识 */
#define SRE_AQM_CFG_OK_REG                         (SRE_AQM_BASE + 0x14)                /* 软件配置AQM完成寄存器 */
#define SRE_AQM_LINKTABLE_INIT_DONE_REG            (SRE_AQM_BASE + 0x18)                /* AQM内部链表初始完成标识 */
#define SRE_AQM_INFO_BASE_ADDR_REG                 (SRE_AQM_BASE + 0x20)                /* AQM队列信息表基地址 */
#define SRE_AQM_LINK_BASE_ADDR_REG                 (SRE_AQM_BASE + 0x24)                /* AQM队列链表基地址 */
#define SRE_AQM_DESCPT_BASE_ADDR_REG               (SRE_AQM_BASE + 0x28)                /* AQM存储描述符基地址 */
#define SRE_AQM_TIME_BASE_ADDR_REG                 (SRE_AQM_BASE + 0x2C)                /* AQM 超时扫描溢出基地址 */
#define SRE_AQM_SEND_PORT_ADDR_REG                 (SRE_AQM_BASE + 0x30)                /* AQM发送端口寄存器 */
#define SRE_AQM_SEND_NODE_CODE_REG                 (SRE_AQM_BASE + 0x34)                /* AQM使用NODE CODE */
#define SRE_AQM_USER_REG                           (SRE_AQM_BASE + 0x38)                /* AQM使用USER */
#define SRE_AQM_RAND_INTT_REG                      (SRE_AQM_BASE + 0x3C)                /* AQM丢弃算法初始随机数 */
#define SRE_AQM_RED_TYPE_IND_REG                   (SRE_AQM_BASE + 0x40)                /* AQM丢弃算法依据方式 */
#define SRE_AQM_SCH_TYPE_IND_REG                   (SRE_AQM_BASE + 0x44)                /* AQM调度依据方式 */
#define SRE_AQM_LINK_THR_REG                       (SRE_AQM_BASE + 0x48)                /* AQM内部链表fifo溢出和回读门限 */
#define SRE_AQM_LINK_DEPTH_REG                     (SRE_AQM_BASE + 0x4C)                /* AQM链表深度配置寄存器 */
#define SRE_AQM_TIME_INTERVAL_REG                  (SRE_AQM_BASE + 0x50)                /* AQM 超时扫描间隔 */
#define SRE_AQM_TIME_FIFO_THR_REG                  (SRE_AQM_BASE + 0x54)                /* AQM 超时扫描FIFO溢出回读门限 */
#define SRE_AQM_TIME_DEPTH_REG                     (SRE_AQM_BASE + 0x58)                /* AQM超时回读溢出深度配置寄存器 */
#define SRE_AQM_TIME_SCAN_SWITCH_REG               (SRE_AQM_BASE + 0x5C)                /* AQM 超时扫描控制开关 */
#define SRE_AQM_MST_CFG_REG                        (SRE_AQM_BASE + 0x60)                /* AQM 操作AXI总线配置寄存器 */
#define SRE_AQM_CF_TIMEOUT_REG                     (SRE_AQM_BASE + 0x64)                /* AQM MST重传次数过多中断上报未清除超时时间配置寄存器 */
#define SRE_AQM_MST_CNT_CTRL_REG                   (SRE_AQM_BASE + 0x68)                /* AQM MST口内部通道统计控制寄存器 */
#define SRE_AQM_MST_LATENCY_AVG_REG                (SRE_AQM_BASE + 0x6C)                /* AQM MST口平均延时寄存器 */
#define SRE_AQM_MST_LATENCY_MAX_REG                (SRE_AQM_BASE + 0x70)                /* AQM MST口最大延时寄存器 */
#define SRE_AQM_AXI_INT_MASK_REG                   (SRE_AQM_BASE + 0x74)                /* AQM 读写AXI总线中断屏蔽寄存器 */
#define SRE_AQM_AXI_RINT_REG                       (SRE_AQM_BASE + 0x78)                /* AQM 读写AXI总线原始中断 */
#define SRE_AQM_AXI_INT_REG                        (SRE_AQM_BASE + 0x7C)                /* AQM 读写AXI总线中断信号 */
#define SRE_AQM_ERR_INST_REG                       (SRE_AQM_BASE + 0x80)                /* AQM错误植入寄存器 */
#define SRE_AQM_ERR_MASK_REG                       (SRE_AQM_BASE + 0x84)                /* AQM中断屏蔽寄存器 */
#define SRE_AQM_FIFO_ERR_MASK0_REG                 (SRE_AQM_BASE + 0x88)                /* AQM FIFO中断屏蔽寄存器0 */
#define SRE_AQM_FIFO_ERR_MASK1_REG                 (SRE_AQM_BASE + 0x8C)                /* AQM FIFO中断屏蔽寄存器1 */
#define SRE_AQM_ERR_RINT_REG                       (SRE_AQM_BASE + 0x90)                /* AQM 错误植入原始中断寄存器 */
#define SRE_AQM_FIFO_ERR_RINT0_REG                 (SRE_AQM_BASE + 0x94)                /* AQM FIFO原始中断寄存器0 */
#define SRE_AQM_FIFO_ERR_RINT1_REG                 (SRE_AQM_BASE + 0x98)                /* AQM FIFO原始中断寄存器1 */
#define SRE_AQM_ERR_INT_REG                        (SRE_AQM_BASE + 0x9C)                /* AQM错误植入中断寄存器 */
#define SRE_AQM_FIFO_ERR_INT0_REG                  (SRE_AQM_BASE + 0xA0)                /* AQM FIFO中断寄存器0 */
#define SRE_AQM_FIFO_ERR_INT1_REG                  (SRE_AQM_BASE + 0xA4)                /* AQM FIFO中断寄存器1 */
#define SRE_AQM_FIFO_DFX0_REG                      (SRE_AQM_BASE + 0xA8)                /* AQM FIFO DFX寄存器0 */
#define SRE_AQM_FIFO_DFX1_REG                      (SRE_AQM_BASE + 0xAC)                /* AQM FIFO DFX寄存器1 */
#define SRE_AQM_INQ_PKT_CNT_REG                    (SRE_AQM_BASE + 0xB0)                /* AQM 入队描述符统计 */
#define SRE_AQM_INQ_PKT_OK_CNT_REG                 (SRE_AQM_BASE + 0xB4)                /* AQM入队成功描述符统计 */
#define SRE_AQM_OUTQ_CARRY_CNT_REG                 (SRE_AQM_BASE + 0xB8)                /* AQM 承载出队指令统计 */
#define SRE_AQM_SWITCH_CARRY_CNT_REG               (SRE_AQM_BASE + 0xBC)                /* AQM承载切换指令统计 */
#define SRE_AQM_DROP_CARRY_CNT_REG                 (SRE_AQM_BASE + 0xC0)                /* AQM承载丢弃指令统计 */
#define SRE_AQM_DROP_DESCPT_CNT_REG                (SRE_AQM_BASE + 0xC4)                /* AQM丢弃描述符统计 */
#define SRE_AQM_OUTQ_DESCPT_CNT_REG                (SRE_AQM_BASE + 0xC8)                /* AQM出队描述符统计 */
#define SRE_AQM_FQ_PKT_CNT_REG                     (SRE_AQM_BASE + 0xCC)                /* AQM 快速出队描述符统计 */
#define SRE_AQM_DIS_DROP_CNT_REG                   (SRE_AQM_BASE + 0xD0)                /* AQM 队列未使能丢弃统计 */
#define SRE_AQM_BUF_DROP_CNT_REG                   (SRE_AQM_BASE + 0xD4)                /* AQM 缓存申请失败丢弃统计 */
#define SRE_AQM_WRED_DROP_CNT_REG                  (SRE_AQM_BASE + 0xD8)                /* AQM WRED丢弃描述符统计 */
#define SRE_AQM_LINK_FREE_PTR_CNT_REG              (SRE_AQM_BASE + 0xDC)                /* AQM 链表空指针计数寄存器 */
#define SRE_AQM_MST_CNT_RD_ACC_REG                 (SRE_AQM_BASE + 0xE0)                /* AQM MST口读计数器 */
#define SRE_AQM_MST_CNT_WR_ACC_REG                 (SRE_AQM_BASE + 0xE4)                /* AQM MST口写计数器 */
#define SRE_AQM_CREDIT_PKT_CNT_REG                 (SRE_AQM_BASE + 0xE8)                /* AQM 欠权重快速出队描述符统计 */
#define SRE_AQM_INTER_FSM0_REG                     (SRE_AQM_BASE + 0xF0)                /* AQM 内部状态机状态监控寄存器0 */
#define SRE_AQM_INTER_FSM1_REG                     (SRE_AQM_BASE + 0xF4)                /* AQM 内部状态机状态监控寄存器1 */
#define SRE_AQM_RED_MAX_THR_0_REG                  (SRE_AQM_BASE + 0x100)               /* AQM RED丢弃模板最大门限 */
#define SRE_AQM_RED_MAX_THR_1_REG                  (SRE_AQM_BASE + 0x104)               /* AQM RED丢弃模板最大门限 */
#define SRE_AQM_RED_MIN_THR_0_REG                  (SRE_AQM_BASE + 0x200)               /* AQM RED丢弃模板最小门限 */
#define SRE_AQM_RED_MIN_THR_1_REG                  (SRE_AQM_BASE + 0x204)               /* AQM RED丢弃模板最小门限 */
#define SRE_AQM_RED_DROP_SLOP_0_REG                (SRE_AQM_BASE + 0x300)               /* AQM RED丢弃模板斜率 */
#define SRE_AQM_RED_DROP_SLOP_1_REG                (SRE_AQM_BASE + 0x304)               /* AQM RED丢弃模板斜率 */
#define SRE_AQM_SCH_WEIGHT_0_REG                   (SRE_AQM_BASE + 0x400)               /* AQM 调度权重模板 */
#define SRE_AQM_SCH_WEIGHT_1_REG                   (SRE_AQM_BASE + 0x404)               /* AQM 调度权重模板 */
#define SRE_AQM_TIMEOUT_DROP_0_REG                 (SRE_AQM_BASE + 0x500)               /* AQM 超时丢弃模板 */
#define SRE_AQM_TIMEOUT_DROP_1_REG                 (SRE_AQM_BASE + 0x504)               /* AQM 超时丢弃模板 */
#define SRE_AQM_FQ_SCH_TYPE_0_REG                  (SRE_AQM_BASE + 0x600)               /* AQM调度属性表 */
#define SRE_AQM_FQ_SCH_TYPE_1_REG                  (SRE_AQM_BASE + 0x604)               /* AQM调度属性表 */
#define SRE_AQM_INTER_TEST0_REG                    (SRE_AQM_BASE + 0x680)               /* AQM 内部测试寄存器0 */
#define SRE_AQM_INTER_TEST1_REG                    (SRE_AQM_BASE + 0x684)               /* AQM 内部测试寄存器1 */
#define SRE_AQM_INTER_TEST2_REG                    (SRE_AQM_BASE + 0x688)               /* AQM 内部测试寄存器2 */
#define SRE_AQM_INTER_TEST3_REG                    (SRE_AQM_BASE + 0x68C)               /* AQM 内部测试寄存器3 */
#define SRE_AQM_INTER_CFG0_REG                     (SRE_AQM_BASE + 0x690)               /* AQM 内部配置寄存器0 */
#define SRE_AQM_INTER_CFG1_REG                     (SRE_AQM_BASE + 0x694)               /* AQM 内部配置寄存器1 */
#define SRE_AQM_INTER_CFG2_REG                     (SRE_AQM_BASE + 0x698)               /* AQM 内部配置寄存器2 */
#define SRE_AQM_INTER_CFG3_REG                     (SRE_AQM_BASE + 0x69C)               /* AQM 内部配置寄存器3 */
#define SRE_AQM_PKT_VLD_CORE_0_REG                 (SRE_AQM_BASE + 0x700)               /* Core添加是否成功寄存器 */
#define SRE_AQM_PKT_VLD_CORE_1_REG                 (SRE_AQM_BASE + 0x704)               /* Core添加是否成功寄存器 */
#define SRE_AQM_FQ_EN_0_REG                        (SRE_AQM_BASE + 0x800)               /* AQM 队列使能表 */
#define SRE_AQM_FQ_EN_1_REG                        (SRE_AQM_BASE + 0x804)               /* AQM 队列使能表 */
#define SRE_AQM_SCH_TYPE_ID_0_REG                  (SRE_AQM_BASE + 0x20800)             /* AQM调度属性表索引号 */
#define SRE_AQM_SCH_TYPE_ID_1_REG                  (SRE_AQM_BASE + 0x20804)             /* AQM调度属性表索引号 */
#define SRE_AQM_PKT_WORD0_CORE_0_REG               (SRE_AQM_BASE + 0x100000)            /* Core写TM模块的msg WORD0 */
#define SRE_AQM_PKT_WORD0_CORE_1_REG               (SRE_AQM_BASE + 0x100010)            /* Core写TM模块的msg WORD0 */
#define SRE_AQM_PKT_WORD1_CORE_0_REG               (SRE_AQM_BASE + 0x100004)            /* Core写TM模块的msg WORD1 */
#define SRE_AQM_PKT_WORD1_CORE_1_REG               (SRE_AQM_BASE + 0x100014)            /* Core写TM模块的msg WORD1 */
#define SRE_AQM_PKT_WORD2_CORE_0_REG               (SRE_AQM_BASE + 0x100008)            /* Core写TM模块的msg WORD2 */
#define SRE_AQM_PKT_WORD2_CORE_1_REG               (SRE_AQM_BASE + 0x100018)            /* Core写TM模块的msg WORD2 */
#define SRE_AQM_PKT_WORD3_CORE_0_REG               (SRE_AQM_BASE + 0x10000C)            /* Core写TM模块的msg WORD3 */
#define SRE_AQM_PKT_WORD3_CORE_1_REG               (SRE_AQM_BASE + 0x10001C)            /* Core写TM模块的msg WORD3 */
#define SRE_AQM_PKT_WORD0_ACC_REG                  (SRE_AQM_BASE + 0x100400)            /* 加速器写TM模块msg WORD0 */
#define SRE_AQM_PKT_WORD1_ACC_REG                  (SRE_AQM_BASE + 0x100404)            /* 加速器写TM模块msg WORD1 */
#define SRE_AQM_PKT_WORD2_ACC_REG                  (SRE_AQM_BASE + 0x100408)            /* 加速器写TM模块msg WORD2 */
#define SRE_AQM_PKT_WORD3_ACC_REG                  (SRE_AQM_BASE + 0x10040C)            /* 加速器写TM模块msg WORD3 */
#define SRE_AQM_CARRY_WORD_0_REG                   (SRE_AQM_BASE + 0x100800)            /* AQM承载指令添加寄存器 */
#define SRE_AQM_CARRY_WORD_1_REG                   (SRE_AQM_BASE + 0x100804)            /* AQM承载指令添加寄存器 */

#define DDRC0_CTRL_REG               0x1302c000
#define DDRC1_CTRL_REG               0x1302d000

#define DDRC_CFG_PERF_REG            (0x270+DDRC0_CTRL_REG)

/* DDR性能统计的命令ID配置寄存器  0x274+0x800*chs */
#define DDRC_CFG_STAID_REG           (0x274+DDRC0_CTRL_REG)

/* DDRC中断屏蔽寄存器 0x278+0x800*chs */
#define DDRC_CFG_STAIDMSK_REG        (0x278+DDRC0_CTRL_REG)

/* DDRC性能统计使能寄存器 0x010+0x800*chs */
#define DDRC_CTRL_PERF_REG           (0x010+DDRC0_CTRL_REG)

/* DDRC所有写命令流量统计寄存器 0x380+0x800*chs*/
#define DDRC_HIS_FLUX_WR_REG         (0x380+DDRC0_CTRL_REG)

/* DDRC所有读命令流量统计寄存器 0x384+0x800*chs */
#define DDRC_HIS_FLUX_RD_REG         (0x384+DDRC0_CTRL_REG)

/* DDRC所有写命令数目寄存器  0x388+0x800*chs */
#define DDRC_HIS_FLUX_WCMD_REG       (0x388+DDRC0_CTRL_REG)

/* DDRC所有读命令数目寄存器  0x38c+0x800*chs */
#define DDRC_HIS_FLUX_RCM_REG        (0x38c+DDRC0_CTRL_REG)

/* DDRC指定ID写流量统计寄存器 0x390+0x800*chs */
#define DDRC_HIS_FLUXID_WR_REG       (0x390+DDRC0_CTRL_REG)

/* DDRC指定ID读流量统计寄存器 0x394+0x800*chs */
#define DDRC_HIS_FLUXID_RD_REG       (0x394+DDRC0_CTRL_REG)

/* DDRC所有写命令数目统计寄存器 0x398+0x800*chs */
#define DDRC_HIS_FLUXID_WCMD_REG     (0x398+DDRC0_CTRL_REG)

/* DDRC所有读命令数目统计寄存器 0x039c+0x800*chs */
#define DDRC_HIS_FLUXID_RCMD_REG     (0x39c+DDRC0_CTRL_REG)
#define DDRC_HIS_WLATCNT0_REG        (0x3A0+DDRC0_CTRL_REG)
#define DDRC_HIS_WLATCNT1_REG        (0x3A4+DDRC0_CTRL_REG)
#define DDRC_HIS_RLATCNT0_REG        (0x3A8+DDRC0_CTRL_REG)
#define DDRC_HIS_RLATCNT1_REG        (0x3AC+DDRC0_CTRL_REG)
#define DDRC_HIS_INHERE_RLAT_CNT_REG (0x3B0+DDRC0_CTRL_REG)

#define SCH_FTE_BASE            0x13032000

#define FTE_AR_MODE_REG        (0x0080 + SCH_FTE_BASE)
#define FTE_AR_PYLD0_REG       (0x0084 + SCH_FTE_BASE)
#define FTE_AR_PYLD1_REG       (0x0088 + SCH_FTE_BASE)

#define FTE_AW_MODE_REG        (0x0090 + SCH_FTE_BASE)
#define FTE_AW_PYLD0_REG       (0x0094 + SCH_FTE_BASE)
#define FTE_AW_PYLD1_REG       (0x0098 + SCH_FTE_BASE)

#define FTE_AR_CNUM_REG        (0x0100 + SCH_FTE_BASE)
#define FTE_AR_RNUM_REG        (0x0104 + SCH_FTE_BASE)
#define FTE_AR_DAVG_REG        (0x0108 + SCH_FTE_BASE)
#define FTE_AR_DMAX_REG        (0x010c + SCH_FTE_BASE)

#define FTE_AW_CNUM_REG        (0x0110 + SCH_FTE_BASE)
#define FTE_AW_RNUM_REG        (0x0114 + SCH_FTE_BASE)
#define FTE_AW_DAVG_REG        (0x0118 + SCH_FTE_BASE)
#define FTE_AW_DMAX_REG        (0x011c + SCH_FTE_BASE)

/******************************************************************************/
/*                       SPI 寄存器定义                                   */
/******************************************************************************/
#define SPI_REG_BASE_ADDR                             (0xe400a000)

/******************************************************************************/
/*                       IOCONFIG 寄存器定义                                   */
/******************************************************************************/
#define IOCONFIG_REG_BASE_ADDR                        0xe400c000

/* BEGIN: Modified by g00198889, 2012-9-25   问题单号:SRIO 移植*/
/******************************************************************************/
/*                       SRIO 寄存器定义                                    */
/******************************************************************************/
#if 0         /* z00202052 */
#define OS_SRE_SRIO_BASE_ADDR                         0x18000000UL
#else
#define OS_SRE_SRIO_BASE_ADDR                         0xe8000000UL
#endif        /* z00202052 */
/* 其他寄存器定义见srio_rabreg.h srio_offsetaddr.h */

/******************************************************************************/
/*                       MPE 寄存器定义                                    */
/******************************************************************************/
#if 0         /* z00202052 */
#define OS_SRE_MPE_BASE_ADDR                          0x19000000UL
#else
#define OS_SRE_MPE_BASE_ADDR                          0xe9000000UL
#endif        /* z00202052 */
/* 其他寄存器定义见srio_mpe_reg.h */
/* END:   Modified by g00198889, 2012-9-25 */

/******************************************************************************/
/*                       SERDES3 寄存器定义                                   */
/******************************************************************************/
#define SERDES3_BASE_ADDR                            (0xe8001000)

/******************************************************************************/
/*                       IOCTRL1 寄存器定义                                   */
/******************************************************************************/
#define IOCTRL1_BASE_ADDR                            (0xe8002000)

/******************************************************************************/
/*                       SERDES2 寄存器定义                                   */
/******************************************************************************/
#define SERDES2_BASE_ADDR                            (0xeb000000)

/******************************************************************************/
/*                       PM 寄存器定义                                    */
/******************************************************************************/
#define SRE_PM_BASE     (0x13029000)

#define SRE_PM_SRST_REQ                             (SRE_PM_BASE + 0x0)
#define SRE_PM_SCLK_EN                              (SRE_PM_BASE + 0x4)
#define SRE_PM_SISO_EN                              (SRE_PM_BASE + 0x8)
#define SRE_PM_SMTCMOS_EN                           (SRE_PM_BASE + 0xC)
#define SRE_PM_SMTCMOS_STAT                         (SRE_PM_BASE + 0x10)
#define SRE_PM_PD_REQ                               (SRE_PM_BASE + 0x14)
#define SRE_PM_PD_STAT                              (SRE_PM_BASE + 0x18)
#define SRE_PM_SEC1_IDLE_DLY                        (SRE_PM_BASE + 0x1C)
#define SRE_PM_SEC0_IDLE_DLY                        (SRE_PM_BASE + 0x20)
#define SRE_PM_MTCMOS_STAT                          (SRE_PM_BASE + 0x24)
#define SRE_PM_SEC_PG_FSM_STAT                      (SRE_PM_BASE + 0x28)
#define SRE_PMU_IMVP_CFG                            (SRE_PM_BASE + 0x88)

#define SRE_GPIO_REG_BASE_ADDR 0xe4000000

#define SRE_URAT_REG_BASEADDR           0xe4007000


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* _SRE_MEMMAP_H */
