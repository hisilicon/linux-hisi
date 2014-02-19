/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
  文 件 名   : SRE_phydrv.inc
  版 本 号   : 初稿
  作    者   : w00146306
  生成日期   : 2010年10月28日
  最近修改   :
  功能描述   : SRE PHY驱动模块 头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2010年10月28日
    作    者   : w00146306
    修改内容   : 创建文件

******************************************************************************/
#ifndef _SRE_PHYDRV_INC
#define _SRE_PHYDRV_INC

#include "SRE_drv.h"
//#include "SRE_ge.h"
#include "SRE_memmap.h"
//#include "ge/SRE_ge.inc"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*----------------------------------------------*
 * 外部变量说明                                 *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 外部函数原型说明                             *
 *----------------------------------------------*/
UINT32 SRE_StdPhySet(UINT32 uwPort);
/*----------------------------------------------*
 * 宏定义                                       *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 内部函数原型说明                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 全局变量                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 模块级变量                                   *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 常量定义                                     *
 *----------------------------------------------*/
#define SRE_PHY_ERROR(fmt, arg...)   OS_DBG_PRINT(fmt, ##arg) //OS_DBG_PRINT(fmt, ##arg)//SRE_printf(fmt, arg...)

#define MARVELL1512_ID  0x01410dd0

#define SRE_MDIO_REG_ADDR_LEN    0x10000

#define SRE_MDIO_PHY_GRP_LEN       0x100
#define SRE_MDIO_REG_LEN       0x10

/* 表示的是clause 22  */
#define MDIO_ST_CLAUSE_22           (0x01)

/* 定义MDIO clause 22的操作  */
#define MDIO_CLAUSE_22_READ         (0x02)
#define MDIO_CLAUSE_22_WRITE        (0x01)

#define MDIO_REG_ADDR_LEN            0x1000
#define MDIO_PHY_GRP_LEN             0x100
#define MDIO_REG_LEN                 0x10
#define MDIO_PHY_ADDR_NUM            5
#define MDIO_MAX_PHY_ADDR            0x1F   /* 每个clause 22 MDIO下面最多只有32个PHY  */
#define MDIO_MAX_PHY_REG_ADDR        0x1F   /* Clause45 MDIO支持的PHY寄存器偏移地址最多只到0x1F  */

#define MDIO_REG_ADDR(port, offset)      (MDIO_BASE_ADDR + (port) * MDIO_REG_ADDR_LEN + (offset))

#define MDIO_REG_READ(port,offset,data)  \
        ( (data) = OS_READ_REG(MDIO_REG_ADDR(port, offset), 0))

#define MDIO_REG_WRITE(port,offset,data)  \
        (OS_WRITE_REG(MDIO_REG_ADDR(port, offset), 0, data))



#define MAR_PHY_MAX_ADDR 0x1F

#define PHY_SPEED_10M        0
#define PHY_SPEED_100M       1
#define PHY_SPEED_1000M      2

#define PHY_LINK_UNKNOW      2
#define PHY_LINK             1
#define PHY_UNLINK           0
#define PHY_LOOP             1
#define PHY_UNLOOP           0

#define PHY_AUTONEG_ENABLE   1
#define PHY_AUTONEG_DISABLE  0


/* Standard MII Registers */
#define MII_CTRL_REG            0x00    /* MII Control Register : r/w */
#define MII_STAT_REG            0x01    /* MII Status Register: ro */
#define MII_PHY_ID0_REG         0x02    /* MII PHY ID register: r/w */
#define MII_PHY_ID1_REG         0x03    /* MII PHY ID register: r/w */
#define MII_ANA_REG             0x04    /* MII Auto-Neg Advertisement: r/w */
#define MII_ANP_REG             0x05    /* MII Auto-Neg Link Partner: ro */
#define MII_AN_EXP_REG          0x06    /* MII Auto-Neg Expansion: ro */
#define MII_GB_CTRL_REG         0x09    /* MII 1000Base-T control register */
#define MII_GB_STAT_REG         0x0a    /* MII 1000Base-T Status register */
#define MII_SGB_CTRL_REG        0x0b    /* SGMII/1000-X Control Register */
#define MII_ESR_REG             0x0f    /* MII Extended Status register */

/* Non-standard MII Registers */

/*page any*/
#define MII_PAGE_ADDR_REG          0x16

/*page 0*/
#define MII_COPPER_SPEC_CTRL_1     0x10
#define MII_COPPER_SPEC_STATUS_1   0x11

/*page 2*/
#define MII_MAC_SPEC_CTRL_2        0x15

/* MII Control Register: bit definitions */

#define MII_CTRL_SS_MSB         (1 << 6)  /* Speed select, MSb */
#define MII_CTRL_CST            (1 << 7)  /* Collision Signal test */
#define MII_CTRL_FD             (1 << 8)  /* Full Duplex */
#define MII_CTRL_RAN            (1 << 9)  /* Restart Autonegotiation */
#define MII_CTRL_IP             (1 << 10) /* Isolate Phy */
#define MII_CTRL_PD             (1 << 11) /* Power Down */
#define MII_CTRL_AE             (1 << 12) /* Autonegotiation enable */
#define MII_CTRL_SS_LSB         (1 << 13) /* Speed select, LSb */
#define MII_CTRL_LE             (1 << 14) /* Loopback enable */
#define MII_CTRL_RESET          (1 << 15) /* PHY reset */

/*
 * MII Link Advertisment
 */
#define MII_ANA_ASF             (1 << 0)  /* Advertise Selector Field */
#define MII_ANA_HD_10           (1 << 5)  /* Half duplex 10Mb/s supported */
#define MII_ANA_FD_10           (1 << 6)  /* Full duplex 10Mb/s supported */
#define MII_ANA_HD_100          (1 << 7)  /* Half duplex 100Mb/s supported */
#define MII_ANA_FD_100          (1 << 8)  /* Full duplex 100Mb/s supported */
#define MII_ANA_T4              (1 << 9)  /* T4 */
#define MII_ANA_PAUSE           (1 << 10) /* Pause supported */
#define MII_ANA_ASYM_PAUSE      (1 << 11) /* Asymmetric pause supported */
#define MII_ANA_RF              (1 << 13) /* Remote fault */
#define MII_ANA_NP              (1 << 15) /* Next Page */

/*
 * 1000Base-T Control Register
 */
#define MII_GB_CTRL_ADV_1000FD  (1 << 9)  /* Advertise 1000Base-T FD */
#define MII_GB_CTRL_ADV_1000HD  (1 << 8)  /* Advertise 1000Base-T HD */


typedef enum MAR_PHY_INTERFACE
{
    SGMII_COPPER = 0,
    RGMII_COPPER,
    RTBI_COPPER,
    RGMII_FIBER,
    RTBI_FIBER,
    SGMII_100BASE_FX = 5,
    RGMII_100BASE_FX,
    GBIC/*fiber to copper*/
}MAR_PHY_INTERFACE_ENUM;

typedef enum PHY_LOOPMODE
{
    PHY_LOOP_MODE_OFF = 0,      /*链路无环回*/
    PHY_LOOP_MODE_LINE,         /*链路线路环回*/
    PHY_LOOP_MODE_SYS,          /*链路系统环回*/
    PHY_LOOP_MODE_UNKNOWN       /*未知的链路环回模式*/
}PHY_LOOPMODE_ENUM;



#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* _SRE_PHYDRV_INC */




