/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
文 件 名   	: mc_gmac_arch.c
版 本 号   	: 初稿
作    者       	:  w63320
生成日期   	: 2009年6月15日
最近修改   	:
功能描述   	: ARM 网口驱动
函数列表   	:
修改历史   	:
作    者   		: w63320
修改内容   	: 创建文件

******************************************************************************/

#include "SRE_ge.h"
#include "SRE_ge1.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

SRE_NET_DRV_SHARE_S g_stSreNetDrvShare; //by zqg
#if 0
extern SRE_NET_PERF_CFG_S gstrMcPerfCfg; //by zqg
extern MC_MEM_POOL_CFG gastrMcMemPoolCfg[SRE_MEM_POOL_MAX_NUM];
#endif
/* BEGIN: Modified by f63884, 2012/8/14 */
#if 0
extern SRE_BLKMEM_SHARE_S *gpstrMcBlkmemShare;
#endif
/* END:   Modified by f63884, 2012/8/14 */
//extern UINT32 SRE_GetPoePktNum(VOID); //by zqg: not use
extern UINT32 SRE_UpdateAnLinkTime(UINT32 uwPort, UINT32 uwAnLinkTime);

extern UINT32 MAR1512_Write(UINT32 uwRegAddr, UINT32 uwPage, UINT32 uwVal);//def in SRE_phydrv.c
//extern UINT32 MAR1512_Read(UINT32 uwRegAddr, UINT32 uwPage, UINT32 *puwVal);//zqg:not use

UINT32 SRE_PhyDelayUs(UINT32 uwTime)
{
    UINT32 i;
    volatile UINT32 j;
    for(i = 0;i<uwTime; i++)

    {
        j = i;
    }
    (void)j;
    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_GeResetDreq
 功能描述  : GE软复位去请求接口
 输入参数  : VOID
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年6月9日
    作    者   : wugao
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GeRstDreq(VOID)
{
    OS_WRITE_REG(SRE_SC_GE_RESET_DREQ_REG, 0, 0xffffffff);    /* ge tx&rx rstdreq */
    OS_WRITE_REG(SRE_SC_MAC_CFG_RESET_DREQ_REG, 0, 0xffffffff);    /* ge cfg rstdreq */
    OS_WRITE_REG(SRE_SC_MAC_RESET_DREQ_REG, 0, 0xffffffff);    /* ge eth&mac rstdreq */

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_WaitMdioReady
 功能描述  :等待mdio接口操作完成
 输入参数  : uwMdioID
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
UINT32 SRE_WaitMdioReady(UINT32 uwMdioID)
{
    MDIO_COMMAND_REG_U  unMdioCmd;
    UINT32              uwTimeout = 1000;

    while (uwTimeout)
    {
        --uwTimeout;

        MDIO_REG_READ(uwMdioID, MDIO_COMMAND_REG, unMdioCmd.u32);
        if (0 == unMdioCmd.bits.Mdio_Start)
        {
            return OS_SUCCESS;
        }

        //SRE_DelayUs(1000);
        SRE_PhyDelayUs(1000);
    }

    return OS_FAIL;
}

/*****************************************************************************
  RE_MdioStartPhyRead
 功能描述  :执行读操作
 输入参数  : uwMdioID
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
VOID SRE_MdioStartPhyRead(UINT32 uwMdioID, UINT32 uwPhyAddr, UINT32 uwPhyRegNum)
{
    MDIO_COMMAND_REG_U unMdioCmdReg;

    /* Step 2; 配置命令寄存器，发出读命令  */
    unMdioCmdReg.u32             = 0;
    unMdioCmdReg.bits.Mdio_St    = MDIO_ST_CLAUSE_22;       /* 配置当前的mdio为clause22  */
    unMdioCmdReg.bits.Mdio_Op    = MDIO_CLAUSE_22_READ;     /* 配置当前的操作为读操作  */
    unMdioCmdReg.bits.Mdio_Prtad = (UINT16)uwPhyAddr;        /* 当mdio_st为2’b01时，表示要访问的外部的PHY地址  */
    unMdioCmdReg.bits.Mdio_Devad = uwPhyRegNum;                /* 当mdio_st为2’b01时，表示要访问的外部PHY的寄存器地址  */
    unMdioCmdReg.bits.Mdio_Start = 1;                       /* 启动操作  */
    MDIO_REG_WRITE(uwMdioID, MDIO_COMMAND_REG, unMdioCmdReg.u32);

    return;
}

/*****************************************************************************
 函 数 名  : SRE_MdioStartPhyRead
 功能描述  :执行mdio写操作
 输入参数  : mdio_id，phy地址，寄存器号，写入的值
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
VOID SRE_MdioPhyWrite(UINT32 uwMdioID, UINT32 uwPhyAddr, UINT32 uwPhyRegNum, UINT32 uwWriteValue)
{
    MDIO_COMMAND_REG_U  unMdioCmdReg;
    MDIO_WDATA_REG_U    unMdioWDataReg;

    /* Step 1; 将需要写入的值先写入写访问数据寄存器  */
    MDIO_REG_READ(uwMdioID, MDIO_WDATA_REG, unMdioWDataReg.u32);
    unMdioWDataReg.bits.Mdio_Wdata = uwWriteValue;
    MDIO_REG_WRITE(uwMdioID, MDIO_WDATA_REG, unMdioWDataReg.u32);

    /* Step 2; 配置写操作命令  */
    unMdioCmdReg.u32             = 0;
    unMdioCmdReg.bits.Mdio_St    = MDIO_ST_CLAUSE_22;       /* 配置当前的mdio为clause22  */
    unMdioCmdReg.bits.Mdio_Op    = MDIO_CLAUSE_22_WRITE;    /* 配置当前的操作为写操作  */
    unMdioCmdReg.bits.Mdio_Prtad = (UINT16)uwPhyAddr;       /* 当mdio_st为2’b01时，表示要访问的外部的PHY地址  */
    unMdioCmdReg.bits.Mdio_Devad = uwPhyRegNum;             /* 当mdio_st为2’b01时，表示要访问的外部PHY的寄存器地址  */
    unMdioCmdReg.bits.Mdio_Start = 1;                       /* 启动操作  */
    MDIO_REG_WRITE(uwMdioID, MDIO_COMMAND_REG, unMdioCmdReg.u32);
}

/*****************************************************************************
 函 数 名  : SRE_MdioRead
 功能描述  : MDIO接口的读操作函数
 输入参数  : mdio组id，phy地址，要读的寄存器号
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
UINT32 SRE_MdioRead(UINT32 uwMdioID, UINT32 uwPhyAddr, UINT32 uwPhyRegNum, UINT32 *puwRegValue)
{
    MDIO_RDATA_REG_U    unMdioRDataReg;
    MDIO_STA_REG_U      unMdioStaReg;
    //SRE_printf("SRE_MdioRead para check begin\n");
    /* 输入参数合法性判断 */
    if (uwMdioID >= SRE_MDIO_MAX)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: uwMdioID(%d) Error!"
            "\n[ %d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_MDIO_ID, uwMdioID, 0, 0, 0);
	   	RETURN_ERROR(__LINE__, OS_ERRNO_MDIO_ID, 0, 0);
    }

    if (uwPhyAddr > SRE_PHY_ADDR_MAX)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: uwPhyAddr(%d) Error!"
            "\n[ %d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_MDIO_PHY_ADDR, uwPhyAddr, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_MDIO_PHY_ADDR, 0, 0);
    }

    if (uwPhyRegNum > SRE_PHY_REG_MAX)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: uwPhyRegNum(%d) Error!"
            "\n[ %d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_MDIO_PHY_REG, uwPhyRegNum, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_MDIO_PHY_REG, 0, 0);
    }

    if (NULL == puwRegValue)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: puwRegValue is NULL!"
            "\n[ %d, %d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_MDIO_INPUT_PTR_NULL, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_MDIO_INPUT_PTR_NULL, 0, 0);
    }

    /* Step 1; 先判断MDIO_COMMAND_REG的mdio_start位是否为0，因为只有为0的时候，才可以进行读写操作  */
    if (SRE_WaitMdioReady(uwMdioID) != OS_SUCCESS)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Mdio busy!"
            "\n[ %d, %d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_MDIO_BUSY, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_MDIO_BUSY, 0, 0);
    }
    //SRE_printf("SRE_MdioRead para check end\n");
    /* Step 2; 配置命令寄存器，发出读命令  */
    SRE_MdioStartPhyRead(uwMdioID, uwPhyAddr, uwPhyRegNum);

    /* Step 3; 查询MDIO_COMMAND_REG的mdio_start位是否为0， 检查此时读命令是否完成  */
    if (SRE_WaitMdioReady(uwMdioID) != OS_SUCCESS)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Read timeout!"
            "\n[ %d, %d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_MDIO_READ, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_MDIO_READ, 0, 0);
    }
    //SRE_printf("SRE_MdioRead step 3.1 ok\n");

    MDIO_REG_READ(uwMdioID, MDIO_STA_REG, unMdioStaReg.u32);
    if (unMdioStaReg.bits.Mdio_Sta) /* 表示读操作异常  */
    {
        SRE_printf("[SRE_HISGMAC]: Mdio Read fail!\n");
        RETURN_ERROR(__LINE__, OS_ERRNO_MDIO_READ, 0, 0);
    }
    //SRE_printf("SRE_MdioRead step 3.2 ok\n");

    /* Step 4; 读出数据  */
    MDIO_REG_READ(uwMdioID, MDIO_RDATA_REG, unMdioRDataReg.u32);
    *puwRegValue = unMdioRDataReg.bits.Mdio_Rdata;

	return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_MdioWrite
 功能描述  : MDIO接口的写操作函数
 输入参数  : 端口号
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
UINT32 SRE_MdioWrite(UINT32 uwMdioID, UINT32 uwPhyAddr, UINT32 uwPhyRegNum, UINT32 uwWriteValue)
{
    /* 输入参数合法性判断 */
    if (uwMdioID >= SRE_MDIO_MAX)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: uwMdioID(%d) Error!"
            "\n[ %d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_MDIO_ID, uwMdioID, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_MDIO_ID, 0, 0);
    }

    if (uwPhyAddr > SRE_PHY_ADDR_MAX)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: uwPhyAddr(%d) Error!"
            "\n[%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_MDIO_PHY_ADDR, uwPhyAddr, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_MDIO_PHY_ADDR, 0, 0);
    }

    if (uwPhyRegNum > SRE_PHY_REG_MAX)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: uwPhyRegNum(%d) Error!"
            "\n[%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_MDIO_PHY_REG, uwPhyRegNum, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_MDIO_PHY_REG, 0, 0);
    }

    /* Step 1; 先判断MDIO_COMMAND_REG的mdio_start位是否为0，因为只有为0的时候，才可以进行读写操作  */
    if (SRE_WaitMdioReady(uwMdioID) != OS_SUCCESS)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Read timeout!"
            "\n[ %d, %d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_MDIO_READ, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_MDIO_READ, 0, 0);
    }

    SRE_MdioPhyWrite(uwMdioID, uwPhyAddr, uwPhyRegNum, uwWriteValue);

    return OS_SUCCESS;
}
#if 0
/*****************************************************************************
 函 数 名  : SRE_GmacReadPhy
 功能描述  : 读phy寄存器接口
 输入参数  : UINT32 uwPhyAddr
             UINT32 uwPhyRegNum
             UINT32 uwShadow
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年1月20日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GmacReadPhy(UINT32 uwMdioId, UINT32 uwPhyAddr, UINT32 uwPhyRegNum,
    UINT32 uwShadow)
{
    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_GeEnableRx
 功能描述  : 使能gmac的接收通道
 输入参数  : 端口号、value设置值(取值范围0或1)
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
UINT32 SRE_GeEnableRx( UINT32 uwPort, UINT32 uwEnValue)
{
    SRE_GMAC_PORT_EN_U unPortEn;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwEnValue > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    // read the RX channel configuration register to get current status
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_PORT_EN_REG, unPortEn.u32);
    unPortEn.bits.rx_en = uwEnValue;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_PORT_EN_REG, unPortEn.u32);

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_GeEnableTx
 功能描述  : 使能gmac的发送通道
 输入参数  : 端口号、value设置值(取值范围0或1)
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
UINT32 SRE_GeEnableTx(UINT32 uwPort, UINT32 uwEnValue)
{
    SRE_GMAC_PORT_EN_U unPortEn;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwEnValue > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    // read the RX channel configuration register to get current status
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_PORT_EN_REG, unPortEn.u32);
    unPortEn.bits.tx_en = uwEnValue;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_PORT_EN_REG, unPortEn.u32);

    return OS_SUCCESS;
}

UINT32 SRE_GetGeEnableRxTx( UINT32 uwPort, UINT32 *puwRxEn, UINT32 *puwTxEn)
{
    SRE_GMAC_PORT_EN_U unPortEn;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == puwRxEn)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    if(NULL == puwRxEn)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    // read the RX channel configuration register to get current status
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_PORT_EN_REG, unPortEn.u32);
    *puwRxEn = unPortEn.bits.rx_en;
    *puwTxEn = unPortEn.bits.tx_en;

    return OS_SUCCESS;
}


/*****************************************************************************
 函 数 名  : SRE_PortWorkModeSet, SRE_PortWorkModeGet
 功能描述  : 当前GMAC接口类型的设置和查询
 输入参数  : 端口号
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
UINT32 SRE_PortWorkModeSet(UINT32 uwPort, SRE_PORT_MODE_E enPortMode)
{
    SRE_GMAC_PORT_MODE_U unPortMode;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if ( enPortMode > GMAC_1000M_SGMII )
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] PortMode exceeds the maximum number!"
            "\nenPortMode = %d,[%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            OS_ERRNO_GMAC_PORT_MODE, enPortMode, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_MODE, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_PORT_MODE_REG, unPortMode.u32);
    unPortMode.bits.port_mode = enPortMode;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_PORT_MODE_REG, unPortMode.u32);

    return OS_SUCCESS;
}

UINT32 SRE_PortWorkModeGet(UINT32 uwPort, SRE_PORT_MODE_E *pMode)
{
    SRE_GMAC_PORT_MODE_U unPortMode;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pMode)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_PORT_MODE_REG, unPortMode.u32);
    *pMode = (SRE_PORT_MODE_E)unPortMode.bits.port_mode;

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_AnModeSet, SRE_AnModeGet
 功能描述  : 自协商使能的设置和状态获取
 输入参数  : 端口号
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
UINT32 SRE_AnModeSet(UINT32 uwPort, UINT32 uwEnValue)
{
    SRE_GMAC_TRANSMIT_CONTROL_U unTxCtrl;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwEnValue > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TRANSMIT_CONTROL_REG, unTxCtrl.u32);
    unTxCtrl.bits.an_enable = uwEnValue;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_TRANSMIT_CONTROL_REG, unTxCtrl.u32);

    return OS_SUCCESS;
}

UINT32 SRE_AnModeGet(UINT32 uwPort, UINT32 *pEnable)
{
    SRE_GMAC_TRANSMIT_CONTROL_U unTxCtrl;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pEnable)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TRANSMIT_CONTROL_REG, unTxCtrl.u32);
    *pEnable = unTxCtrl.bits.an_enable;

    return OS_SUCCESS;
}

UINT32 SRE_AnTypeSet(UINT32 uwPort, MCSS_AUTONEG_MODE_E *penAutoNegMode)
{
    SRE_GMAC_TX_LOCAL_PAG_U unTxLocalPag;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == penAutoNegMode)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }
    if(MCSS_GMAC_AUTONEG_1000BASEX == *penAutoNegMode)
    {
        SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_LOCAL_PAGE_REG, unTxLocalPag.u32);
        unTxLocalPag.bits.cfg_15bit = 0;  /* 1000Base-X自协商模式下，bit15是保留域，必须配置为0 */
        unTxLocalPag.bits.cfg_13_12bit = 0;    /* 1000Base-X本地状态00：No error, link OK (default)01：Offline10：Link_Failure11：Auto-Negotiation_Error */
        unTxLocalPag.bits.cfg_11_10bit = 0;     /* 1000Base-X自协商模式下，bit11、bit10是保留域，必须配置为0 */
        unTxLocalPag.bits.cfg_8_5bit = 0xd;     /* 1000Base-X自协商模式：bit[8:7]意义如下：2'b00：不支持流控帧 2'b01：既可以发送PAUSE也能够处理接收的PAUSE帧2'b10：可以发送PAUSE帧，但不能处理接收到的PAUSE（丢弃或作为普通多播帧处理） */
                                           /*  2'11：具有以下三种能力：其一，同时支持发送和处理PAUSE帧；其二，支持发送PAUSE帧，但不处理PAUSE帧；其三，支持处理PAUSE帧，但不支持发送PAUSE帧 */
                                           /* Bit6表示：1：能支持半双工；0：不能支持半双工 Bit5表示：1：能支持全双工；0：不能支持全双工 */
        unTxLocalPag.bits.cfg_0bit = 0;         /* 1000Base-X自协商模式，bit0是保留域，必须配置为0 */
        SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_TX_LOCAL_PAGE_REG, unTxLocalPag.u32);
    }
    else if (MCSS_GMAC_AUTONEG_SGMII_PHY == *penAutoNegMode)
    {
        SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_LOCAL_PAGE_REG, unTxLocalPag.u32);
        unTxLocalPag.bits.cfg_15bit = 0;   /* 表示link状态 1：link up 0：link down */
        unTxLocalPag.bits.cfg_13_12bit = 0;     /* SGMII自协商PHY模式下bit13是保留域，必须配置为0，bit12表示Duplex状态1：full0：half */
        unTxLocalPag.bits.cfg_11_10bit = 0;     /* SGMII自协商PHY模式，表示本端Speed状态11：保留10：1000BASE-TX/1000BASE-X10: 100BASE-TX/100BASE-FX00: 10BASET/10BASE2/10BASE5 */
        unTxLocalPag.bits.cfg_8_5bit = 0;       /* SGMII自协商PHY模式下bit8~bit5为保留域，必须配置为0 */
        unTxLocalPag.bits.cfg_0bit = 1;         /* SGMII自协商PHY模式下bit0必须配置为1 */
        SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_TX_LOCAL_PAGE_REG, unTxLocalPag.u32);
    }
    else if (MCSS_GMAC_AUTONEG_SGMII_MAC == *penAutoNegMode)
    {
        SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_LOCAL_PAGE_REG, unTxLocalPag.u32);
        unTxLocalPag.bits.cfg_15bit = 0;   /* SGMII自协商MAC模式，bit15是保留域，必须配置为0 */
        unTxLocalPag.bits.cfg_13_12bit = 0;     /* SGMII自协商MAC模式下bit13、bit12是保留域，必须配置为0 */
        unTxLocalPag.bits.cfg_11_10bit = 0;     /* SGMII自协商MAC模式下，bit11、bit10是保留域，必须配置为0 */
        unTxLocalPag.bits.cfg_8_5bit = 0;       /* SGMII自协商MAC模式下bit8~bit5为保留域，必须配置为0 */
        unTxLocalPag.bits.cfg_0bit = 1;         /* SGMII自协商MAC模式下bit0必须配置为1 */
        SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_TX_LOCAL_PAGE_REG, unTxLocalPag.u32);
    }
    else
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input para error!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PARA, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PARA, 0, 0);
    }
    //SRE_printf("*unTxLocalPag.u32  0x%x\n", unTxLocalPag.u32);

    return OS_SUCCESS;
}

UINT32 SRE_AnTypeGet(UINT32 uwPort, MCSS_AUTONEG_MODE_E *penAutoNegMode)
{
    SRE_GMAC_TX_LOCAL_PAG_U unTxLocalPag;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == penAutoNegMode)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_LOCAL_PAGE_REG, unTxLocalPag.u32);
    //SRE_printf("*unTxLocalPag.bits.cfg_8_5bit  0x%x\n", unTxLocalPag.bits.cfg_8_5bit);
    //SRE_printf("*unTxLocalPag.bits.cfg_0bit  0x%x\n", unTxLocalPag.bits.cfg_0bit);
    if((0xd == unTxLocalPag.bits.cfg_8_5bit) && (0 == unTxLocalPag.bits.cfg_0bit))
    {
        *penAutoNegMode = MCSS_GMAC_AUTONEG_1000BASEX;
        //SRE_printf("*penAutoNegMode  0x%x\n", *penAutoNegMode);
    }
    else if(1 == unTxLocalPag.bits.cfg_0bit)
    {
        *penAutoNegMode = MCSS_GMAC_AUTONEG_SGMII_PHY;
        //SRE_printf("*penAutoNegMode  0x%x\n", *penAutoNegMode);
    }
    else
    {
        *penAutoNegMode = MCSS_GMAC_AUTONEG_RESERVE;
        //SRE_printf("*penAutoNegMode  0x%x\n", *penAutoNegMode);
    }

    return OS_SUCCESS;
}


/*****************************************************************************
 函 数 名  : SRE_MaxFrmSizeSet, SRE_MaxFrmSizeGet
 功能描述  : 端口接收最大帧长设置和获取
 输入参数  : uwFramSize 单位是字节，最大可配置为0xfffb，即65531
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
UINT32 SRE_MaxFrmSizeSet(UINT32 uwPort, UINT32 uwFramSize)
{
    SRE_GMAC_MAX_FRM_SIZE_U unMaxFrmSize;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwFramSize > SRE_GMAC_MAX_FRM_SIZE)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PKT_LEN_EXCCEED_MAX, 0, 0);
    }
    g_stSreNetDrvShare.auwSreGmacMaxFrmSize[uwPort] = uwFramSize;//by zqg

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_MAX_FRM_SIZE_REG, unMaxFrmSize.u32);
    unMaxFrmSize.bits.max_frm_size = uwFramSize;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_MAX_FRM_SIZE_REG, unMaxFrmSize.u32);

    return OS_SUCCESS;
}

UINT32 SRE_MaxFrmSizeGet(UINT32 uwPort, UINT32 *pFramSize)
{
    SRE_GMAC_MAX_FRM_SIZE_U unMaxFrmSize;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pFramSize)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_MAX_FRM_SIZE_REG, unMaxFrmSize.u32);
    *pFramSize = unMaxFrmSize.bits.max_frm_size;

    return OS_SUCCESS;
}


/*****************************************************************************
 函 数 名  : SRE_ShortFrmSizeSet, SRE_ShortFrmSizeGet
 功能描述  : 端口接收超短帧长设置和获取
 输入参数  : 端口号
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
UINT32 SRE_ShortFrmSizeSet(UINT32 uwPort, UINT32 uwFramSize)
{
    SRE_GMAC_SHORT_RUNTS_THR_U unShortFrmThr;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwFramSize > SRE_GMAC_SHORT_MAX_FRM_SIZE)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PKT_SHORT_LEN_EXCCEED_MAX, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_SHORT_RUNTS_THR_REG, unShortFrmThr.u32);
    unShortFrmThr.bits.short_runts_thr = uwFramSize;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_SHORT_RUNTS_THR_REG, unShortFrmThr.u32);

    return OS_SUCCESS;
}

UINT32 SRE_ShortFrmSizeGet(UINT32 uwPort, UINT32 *pFramSize)
{
    SRE_GMAC_SHORT_RUNTS_THR_U unShortFrmThr;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pFramSize)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_SHORT_RUNTS_THR_REG, unShortFrmThr.u32);
    *pFramSize = unShortFrmThr.bits.short_runts_thr;

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_ShortFrmPassEn, SRE_ShortFrmPassStatusGet
 功能描述  : 短帧 和 超短帧的透传使能和状态查询
             (加上crc的长短小于等于8byte确定无法传入)
 输入参数  : 端口号，en_value取值范围(0和1)
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
UINT32 SRE_ShortFrmPassEn(UINT32 uwPort, UINT32 uwEnValue)
{
    SRE_GMAC_RECV_CONTROL_U unRecvCtrl;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwEnValue > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RECV_CONTROL_REG, unRecvCtrl.u32);
    unRecvCtrl.bits.runt_pkt_en = uwEnValue;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_RECV_CONTROL_REG, unRecvCtrl.u32);

    return OS_SUCCESS;
}

UINT32 SRE_ShortFrmPassStatusGet(UINT32 uwPort, UINT32 *pEnValue)
{
    SRE_GMAC_RECV_CONTROL_U unRecvCtrl;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pEnValue)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RECV_CONTROL_REG, unRecvCtrl.u32);
    *pEnValue = unRecvCtrl.bits.runt_pkt_en;

    return OS_SUCCESS;
}


/*****************************************************************************
 函 数 名  : SRE_RxPadStripEn, SRE_RxPadStripStatusGet, SRE_TxPadAddEn, SRE_TxPadAddStatusGet
 功能描述  : 接收pad剥离使能和发送pad添加使能以及状态查询
 输入参数  : 端口号
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
UINT32 SRE_RxPadStripEn(UINT32 uwPort, UINT32 uwEnValue)
{
    SRE_GMAC_RECV_CONTROL_U unRecvCtrl;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwEnValue > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RECV_CONTROL_REG, unRecvCtrl.u32);
    unRecvCtrl.bits.strip_pad_en = uwEnValue;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_RECV_CONTROL_REG, unRecvCtrl.u32);

    return OS_SUCCESS;
}

UINT32 SRE_RxPadStripStatusGet(UINT32 uwPort, UINT32 *pEnValue)
{
    SRE_GMAC_RECV_CONTROL_U unRecvCtrl;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pEnValue)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RECV_CONTROL_REG, unRecvCtrl.u32);
    *pEnValue = unRecvCtrl.bits.strip_pad_en;

    return OS_SUCCESS;
}


UINT32 SRE_TxPadAddEn(UINT32 uwPort, UINT32 uwEnValue)
{
    SRE_GMAC_TRANSMIT_CONTROL_U unTxCtrl;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwEnValue > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TRANSMIT_CONTROL_REG, unTxCtrl.u32);
    unTxCtrl.bits.pad_enable = uwEnValue;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_TRANSMIT_CONTROL_REG, unTxCtrl.u32);

    return OS_SUCCESS;
}

UINT32 SRE_TxPadAddStatusGet(UINT32 uwPort, UINT32 *pEnValue)
{
    SRE_GMAC_TRANSMIT_CONTROL_U unTxCtrl;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pEnValue)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TRANSMIT_CONTROL_REG, unTxCtrl.u32);
    *pEnValue = unTxCtrl.bits.pad_enable ;

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_RxSkipLenSet, SRE_RxSkipLenGet
 功能描述  : 报文头不解析字段长度设置和查询
 输入参数  : 端口号
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
UINT32 SRE_RxSkipLenSet(UINT32 uwPort, UINT32 uwSkipLen)
{
    SRE_GMAC_MAC_SKIP_LEN_U unSkipLenReg;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_MAC_SKIP_LEN_REG, unSkipLenReg.u32);
    unSkipLenReg.bits.mac_skip_len = uwSkipLen;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_MAC_SKIP_LEN_REG, unSkipLenReg.u32);

    return OS_SUCCESS;
}

UINT32 SRE_RxSkipLenGet(UINT32 uwPort, UINT32 *pSkipLen)
{
    SRE_GMAC_MAC_SKIP_LEN_U unSkipLenReg;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pSkipLen)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_MAC_SKIP_LEN_REG, unSkipLenReg.u32);
    *pSkipLen = unSkipLenReg.bits.mac_skip_len;

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_LineLoopBackEn, SRE_InLoopBackEn
 功能描述  : 链路测环回使能和应用测环回使能
 输入参数  : 端口号，en_value(取值范围0和1)
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
UINT32 SRE_LineLoopBackEn(UINT32 uwPort, UINT32 uwEnValue)
{
    SRE_GMAC_LINE_LOOP_BACK_U unLineLoopBack;
    SRE_GMAC_LOOP_REG_U unLoopBack;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwEnValue > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    SRE_InLoopBackDis(uwPort);

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_LINE_LOOP_BACK_REG, unLineLoopBack.u32);
    unLineLoopBack.bits.line_loop_back = uwEnValue;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_LINE_LOOP_BACK_REG, unLineLoopBack.u32 );

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_LOOP_REG, unLoopBack.u32);
    if(1 == uwEnValue)
    {
        unLoopBack.bits.cf_ext_drive_lp = 0;
    }
    else
    {
        unLoopBack.bits.cf_ext_drive_lp = 1;
    }
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_LOOP_REG, unLoopBack.u32 );

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_LineLoopBackDis
 功能描述  : 链路侧环回去使能
 输入参数  : UINT32 uwPort
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年3月14日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_LineLoopBackDis(UINT32 uwPort)
{
    SRE_GMAC_LINE_LOOP_BACK_U unLineLoopBack;
    SRE_GMAC_LOOP_REG_U unLoopBack;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_LINE_LOOP_BACK_REG, unLineLoopBack.u32);
    unLineLoopBack.bits.line_loop_back = 0;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_LINE_LOOP_BACK_REG, unLineLoopBack.u32 );

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_LOOP_REG, unLoopBack.u32);
    unLoopBack.bits.cf_ext_drive_lp = 1;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_LOOP_REG, unLoopBack.u32 );

    return OS_SUCCESS;

}

/*****************************************************************************
 函 数 名  : SRE_InLoopBackEn
 功能描述  : 应用侧环回使能
 输入参数  : UINT32 uwPort
             UINT32 uwEnValue
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年3月14日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_InLoopBackEn(UINT32 uwPort, UINT32 uwEnValue)
{
    SRE_GMAC_LOOP_REG_U unLoopBack;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwEnValue > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }
    SRE_LineLoopBackDis(uwPort);

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_LOOP_REG, unLoopBack.u32);
    unLoopBack.bits.cf2mi_lp_en = uwEnValue;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_LOOP_REG, unLoopBack.u32 );

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_InLoopBackDis
 功能描述  : 应用侧环回去使能
 输入参数  : UINT32 uwPort
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年3月14日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_InLoopBackDis(UINT32 uwPort)
{
    SRE_GMAC_LOOP_REG_U unLoopBack;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_LOOP_REG, unLoopBack.u32);
    unLoopBack.bits.cf2mi_lp_en = 0;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_LOOP_REG, unLoopBack.u32 );

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_SdsLoopBackEn
 功能描述  : Serdes环回使能
 输入参数  : UINT32 uwPort
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年11月5日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_SdsLoopBackEn(UINT32 uwPort)
{
    return OS_SUCCESS;

}

/*****************************************************************************
 函 数 名  : SRE_SdsLoopBackDis
 功能描述  : Serdes环回禁止
 输入参数  : UINT32 uwPort
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年11月5日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_SdsLoopBackDis(UINT32 uwPort)
{
    return OS_SUCCESS;

}

/*****************************************************************************
 函 数 名  : SRE_SdsOutLoopBackEn
 功能描述  : Serdes外环回使能
 输入参数  : UINT32 uwPort
             UINT32 uwMode 0串行外环   1串行并环
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年4月8日
    作    者   : z00176027
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_SdsOutLoopBackEn(UINT32 uwPort,UINT32 mode)
{
    return OS_SUCCESS;

}

/*****************************************************************************
 函 数 名  : SRE_SdsLoopBackDis
 功能描述  : Serdes外环回禁止
 输入参数  : UINT32 uwPort
             UINT32 uwMode 0串行外环   1串行并环
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年4月8日
    作    者   : z00176027
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_SdsOutLoopBackDis(UINT32 uwPort,UINT32 mode)
{
    return OS_SUCCESS;

}

/*****************************************************************************
 函 数 名  : SRE_GetInLoopBackStatus
 功能描述  : 应用侧环回状态查询函数
 输入参数  : UINT32 uwPort
             UINT32* puwLoopBackStatus
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年2月3日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GetInLoopBackStatus(UINT32 uwPort, UINT32* puwLoopBackStatus)
{
    SRE_GMAC_LOOP_REG_U unLoopBack;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == puwLoopBackStatus)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_LOOP_REG, unLoopBack.u32);
    *puwLoopBackStatus = unLoopBack.bits.cf2mi_lp_en;

    return OS_SUCCESS;

}

/*****************************************************************************
 函 数 名  : SRE_GetLineLoopBackStatus
 功能描述  : 链路侧环回状态查询函数
 输入参数  : UINT32 uwPort
             UINT32* puwLoopBackStatus
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年2月3日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GetLineLoopBackStatus(UINT32 uwPort, UINT32* puwLoopBackStatus)
{
    SRE_GMAC_LINE_LOOP_BACK_U unLineLoopBack;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == puwLoopBackStatus)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_LINE_LOOP_BACK_REG, unLineLoopBack.u32);
    *puwLoopBackStatus = unLineLoopBack.bits.line_loop_back;

    return OS_SUCCESS;

}

/*****************************************************************************
 函 数 名  : SRE_GetSdsLoopBackStatus
 功能描述  : Ge的pcs和serdes接口出链路侧环回状态获取
 输入参数  : UINT32 uwPort
             UINT32* puwSdsBackStatus
 输出参数  : 无
 返 回 值  : UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2013年7月23日
    作    者   : wugao
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GetSdsLoopBackStatus(UINT32 uwPort, UINT32* puwSdsBackStatus)
{

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == puwSdsBackStatus)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    *puwSdsBackStatus = 0;

    return OS_SUCCESS;
}

UINT32 SRE_GmacLoopEnableShow(UINT32 uwPort)
{
    UINT32 uwInLoopBackStatus;
    UINT32 uwLineLoopBackBackStatus;
    UINT32 uwSdsBackStatus;

    SRE_GetInLoopBackStatus(uwPort, &uwInLoopBackStatus);
    SRE_GetLineLoopBackStatus(uwPort, &uwLineLoopBackBackStatus);
    SRE_GetSdsLoopBackStatus(uwPort, &uwSdsBackStatus);

    if(1 == uwInLoopBackStatus)
    {
        SRE_printf("in loop back : enable\n");
    }
    else
    {
        SRE_printf("in loop back : disable\n");
    }
    if(1 == uwLineLoopBackBackStatus)
    {
        SRE_printf("line loop back : enable\n");
    }
    else
    {
        SRE_printf("line loop back : disable\n");
    }
    if(1 == uwSdsBackStatus)
    {
        SRE_printf("sds loop back : enable\n");
    }
    else
    {
        SRE_printf("sds loop back : disable\n");
    }

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_BcPktFiltEn, SRE_McPktFiltEn, SRE_UcNoLocalPktFiltEn,SRE_VlanPktFiltEn
 功能描述  : 广播，组播，非本地单播，vlan报文过滤设置
 输入参数  : 端口号
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
UINT32 SRE_MacAddrFilterSet(UINT32 uwPort, const SRE_MAC_FILTER_CFG_S *pMacFilter)
{
    SRE_GMAC_REC_FILT_CONTROL_U unFiltCtrl;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pMacFilter)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input mac filter parameter NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    /*设置过滤规则，非本地单播帧,非本地组播帧,流控帧和CRC错误帧丢弃*/
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_REC_FILT_CONTROL_REG, unFiltCtrl.u32);
    unFiltCtrl.bits.crc_err_pass = pMacFilter->crc_err_pass;
    unFiltCtrl.bits.pause_frm_pass = pMacFilter->pause_frm_pass;
    unFiltCtrl.bits.bc_drop_en = pMacFilter->bc_drop_en;
    unFiltCtrl.bits.mc_match_en = pMacFilter->mc_match_en;
    unFiltCtrl.bits.uc_match_en = pMacFilter->uc_match_en;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_REC_FILT_CONTROL_REG, unFiltCtrl.u32);

    return OS_SUCCESS;
}

UINT32 SRE_GeCrcErrReportEn(UINT32 uwPort, UINT32 uwEnValue)
{
    SRE_GMAC_REC_FILT_CONTROL_U unFiltCtrl;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwEnValue > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_REC_FILT_CONTROL_REG, unFiltCtrl.u32);
    unFiltCtrl.bits.crc_err_pass = uwEnValue;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_REC_FILT_CONTROL_REG, unFiltCtrl.u32);

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_GePausePassEn
 功能描述  : 流控帧透传使能
 输入参数  : UINT32 uwPort
             UINT32 uwEnValue
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2013年4月25日
    作    者   : wugao
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GePausePassEn(UINT32 uwPort, UINT32 uwEnValue)
{
    SRE_GMAC_REC_FILT_CONTROL_U unFiltCtrl;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwEnValue > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_REC_FILT_CONTROL_REG, unFiltCtrl.u32);
    unFiltCtrl.bits.pause_frm_pass = uwEnValue;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_REC_FILT_CONTROL_REG, unFiltCtrl.u32);

    return OS_SUCCESS;
}

UINT32 SRE_BcPktFiltEn(UINT32 uwPort, UINT32 uwEnValue)
{
    SRE_GMAC_REC_FILT_CONTROL_U unFiltCtrl;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwEnValue > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_REC_FILT_CONTROL_REG, unFiltCtrl.u32);
    unFiltCtrl.bits.bc_drop_en = uwEnValue;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_REC_FILT_CONTROL_REG, unFiltCtrl.u32);

    return OS_SUCCESS;
}

UINT32 SRE_McPktFiltEn(UINT32 uwPort, UINT32 uwEnValue)
{
    SRE_GMAC_REC_FILT_CONTROL_U unFiltCtrl;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwEnValue > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_REC_FILT_CONTROL_REG, unFiltCtrl.u32);
    unFiltCtrl.bits.mc_match_en = uwEnValue;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_REC_FILT_CONTROL_REG, unFiltCtrl.u32);

    return OS_SUCCESS;
}

UINT32 SRE_GeUcPktFiltEn(UINT32 uwPort, UINT32 uwEnValue)
{
    SRE_GMAC_REC_FILT_CONTROL_U unFiltCtrl;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwEnValue > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_REC_FILT_CONTROL_REG, unFiltCtrl.u32);
    unFiltCtrl.bits.uc_match_en = uwEnValue;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_REC_FILT_CONTROL_REG, unFiltCtrl.u32);

    return OS_SUCCESS;
}

UINT32 SRE_GmacFilterStatusGet(UINT32 uwPort, SRE_MAC_FILTER_CFG_S *pMacFilter)
{
    SRE_GMAC_REC_FILT_CONTROL_U unFiltCtrl;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pMacFilter)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input mac filter pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_REC_FILT_CONTROL_REG, unFiltCtrl.u32);

    pMacFilter->crc_err_pass = unFiltCtrl.bits.crc_err_pass;
    pMacFilter->pause_frm_pass = unFiltCtrl.bits.pause_frm_pass;
    pMacFilter->bc_drop_en = unFiltCtrl.bits.bc_drop_en;
    pMacFilter->mc_match_en = unFiltCtrl.bits.mc_match_en;
    pMacFilter->uc_match_en = unFiltCtrl.bits.uc_match_en;

    return OS_SUCCESS;
}

UINT32 SRE_FilterStatusShow(UINT32 uwPort)
{
    SRE_GMAC_REC_FILT_CONTROL_U unFiltCtrl;
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_REC_FILT_CONTROL_REG, unFiltCtrl.u32);

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(!unFiltCtrl.bits.crc_err_pass)
    {
        MC_PRINTK_DFX("crc error packets   :report\n");
    }
    else
    {
        MC_PRINTK_DFX("crc error packets   :not report\n");
    }

    if(!unFiltCtrl.bits.pause_frm_pass)
    {
        MC_PRINTK_DFX("flow control packets:drop\n");
    }
    else
    {
        MC_PRINTK_DFX("flow control packets:pass\n");
    }

    if(!unFiltCtrl.bits.bc_drop_en)
    {
        MC_PRINTK_DFX("broadcast packets   :pass\n");
    }
    else
    {
        MC_PRINTK_DFX("broadcast packets   :drop\n");
    }

    if(!unFiltCtrl.bits.mc_match_en)
    {
        MC_PRINTK_DFX("multi cast packets       :pass\n");
    }
    else
    {
        MC_PRINTK_DFX("multi cast packets       :drop\n");
    }

    if(!unFiltCtrl.bits.uc_match_en)
    {
        MC_PRINTK_DFX("unicast none local packets:pass\n");
    }
    else
    {
        MC_PRINTK_DFX("unicast none local packets:drop\n");
    }

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_MacAddrAdd
 功能描述  : MAC地址的添加函数
 输入参数  : UINT32 uwPort
             const SRE_MAC_MASK_ADDR_STR_S *pstrMacAddr
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年3月25日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_MacAddrAdd(UINT32 uwPort, const SRE_MAC_MASK_ADDR_STR_S *pstrMacAddr)
{
    UINT32 uwMacAddrIndex;
    UINT32 uwMacAddrLow;
    UINT32 uwMacAddrHi;
    UINT32 uwMacAddrLowMsk;
    UINT32 uwMacAddrHiMsk;
    UINT32 uwMacIndex;

    /* 输入参数合法性检查 */
    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pstrMacAddr)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input mac address NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    /*check if MAC address exist*/
    for(uwMacAddrIndex = 0; uwMacAddrIndex < SRE_MAC_ADDR_NUM; uwMacAddrIndex++)
    {
        SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_LOW_REG(uwMacAddrIndex), uwMacAddrLow);
        SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_HIGH_REG(uwMacAddrIndex), uwMacAddrHi);

        if ( uwMacAddrIndex < SRE_MAC_ADDR_MSK_NUM )
        {
            SRE_GMAC_READ_REG(uwPort, SRE_MAC_ADDR_LOW_MSK_REG(uwMacAddrIndex), uwMacAddrLowMsk);
            SRE_GMAC_READ_REG(uwPort, SRE_MAC_ADDR_HI_MSK_REG(uwMacAddrIndex), uwMacAddrHiMsk);
            uwMacAddrLow = uwMacAddrLow & uwMacAddrLowMsk;
            uwMacAddrHi = uwMacAddrHi & uwMacAddrHiMsk;
        }

        if((uwMacAddrLow == (pstrMacAddr->mac_addr_low & pstrMacAddr->mac_addr_low_mask))
            && ((uwMacAddrHi & 0xffff) == ((pstrMacAddr->mac_addr_hi & pstrMacAddr->mac_addr_hi_mask) & 0xffff)))
        {
            SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]:MAC address already exist!"
                "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
                0xffffffff, OS_ERRNO_GMAC_MAC_ADDR_REPEAT, 0, 0, 0, 0);
            RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_MAC_ADDR_REPEAT, uwMacAddrIndex, 0);
        }
    }

    /* mac address without mask */
    if((0xffff == (pstrMacAddr->mac_addr_hi_mask & 0xffff)) && (0xffffffff == pstrMacAddr->mac_addr_low_mask))
    {
        /* check if there is idle mac address registers,MAC Adress reg 2 is for main mac address
        不带掩码的MAC地址从 3 开始，2为主MAC地址,即发送流控帧的源mac地址 */
        for(uwMacAddrIndex = 0, uwMacIndex = 3; uwMacIndex < SRE_MAC_ADDR_NUM; uwMacIndex++)
        {
            SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_LOW_REG(uwMacIndex), uwMacAddrLow);
            SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_HIGH_REG(uwMacIndex), uwMacAddrHi);
            if(!uwMacAddrLow && !(uwMacAddrHi & 0xffff))
            {
                uwMacAddrIndex = uwMacIndex;
                break;
            }
        }

        if(0 == uwMacAddrIndex)
        {
            SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]:No idle address registers! Add Mac address failed!"
                "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
                0xffffffff, OS_ERRNO_GMAC_MAC_ADDR_REG_FULL, 0, 0, 0, 0);
    	    RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_MAC_ADDR_REG_FULL, 0, 0);
        }
    }
    else    /* mac address with mask */
    {
        for(uwMacAddrIndex = 0; uwMacAddrIndex < SRE_MAC_ADDR_MSK_NUM; uwMacAddrIndex++)
        {
            SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_LOW_REG(uwMacAddrIndex), uwMacAddrLow);
            SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_HIGH_REG(uwMacAddrIndex), uwMacAddrHi);
            if(!uwMacAddrLow && !(uwMacAddrHi & 0xffff))
            {
                break;
            }
        }

        if(uwMacAddrIndex >= SRE_MAC_ADDR_MSK_NUM)
        {
            SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]:No idle address registers! Add Mac address failed!"
                "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
                0xffffffff, OS_ERRNO_GMAC_MAC_ADDR_REG_FULL, 0, 0, 0, 0);
            RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_MAC_ADDR_REG_FULL, 0, 0);
        }
    }

    if(uwMacAddrIndex < SRE_MAC_ADDR_MSK_NUM)
    {
        /*setting address mask*/
        SRE_GMAC_WRITE_REG(uwPort, SRE_MAC_ADDR_LOW_MSK_REG(uwMacAddrIndex), pstrMacAddr->mac_addr_low_mask);
        SRE_GMAC_WRITE_REG(uwPort, SRE_MAC_ADDR_HI_MSK_REG(uwMacAddrIndex), pstrMacAddr->mac_addr_hi_mask);
    }

    /*setting MAC address*/
    SRE_GMAC_WRITE_REG(uwPort, SRE_MAC_SA_LOW_REG(uwMacAddrIndex), pstrMacAddr->mac_addr_low);
    SRE_GMAC_WRITE_REG(uwPort, SRE_MAC_SA_HIGH_REG(uwMacAddrIndex), pstrMacAddr->mac_addr_hi);

    return OS_SUCCESS;

}


/*****************************************************************************
 函 数 名  : SRE_MacAddrDel
 功能描述  : MAC地址的删除函数
 输入参数  : UINT32 uwPort
             const SRE_MAC_MASK_ADDR_STR_S *pstrMacAddr
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年3月25日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_MacAddrDel(UINT32 uwPort, const SRE_MAC_MASK_ADDR_STR_S *pstrMacAddr)
{
    UINT32 uwMacAddrIndex;
    UINT32 uwMacAddrLow;
    UINT32 uwMacAddrHi;
    UINT32 uwMacAddrLowMsk;
    UINT32 uwMacAddrHiMsk;
    UINT32 uwMacIndex;

    /* 输入参数合法性检查 */
    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pstrMacAddr)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]:Input mac address NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    /* mac address without mask */
    if((0xffff == (pstrMacAddr->mac_addr_hi_mask & 0xffff)) && (0xffffffff == pstrMacAddr->mac_addr_low_mask))
    {
        /* check if match current register value,MAC Adress reg 2 is for main mac address
        不带掩码的MAC地址从 3 开始，2为主MAC地址 */
        for(uwMacAddrIndex = 0, uwMacIndex = 3; uwMacIndex < SRE_MAC_ADDR_NUM; uwMacIndex++)
        {
            SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_LOW_REG(uwMacIndex), uwMacAddrLow);
            SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_HIGH_REG(uwMacIndex), uwMacAddrHi);

            if((uwMacAddrLow == pstrMacAddr->mac_addr_low) && ((uwMacAddrHi & 0xffff) == (pstrMacAddr->mac_addr_hi & 0xffff)))
            {
                uwMacAddrIndex = uwMacIndex;
                break;
            }
        }

        if(0 == uwMacAddrIndex)
        {
            SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]:No MAC address matched! Del Mac address failed!"
                "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
                0xffffffff, OS_ERRNO_GMAC_MAC_DEL, 0, 0, 0, 0);
            RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_MAC_DEL, 0, 0);
        }
    }
    else    /* mac address with mask */
    {
        for(uwMacAddrIndex = 0; uwMacAddrIndex < SRE_MAC_ADDR_MSK_NUM; uwMacAddrIndex++)
        {
            SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_LOW_REG(uwMacAddrIndex), uwMacAddrLow);
            SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_HIGH_REG(uwMacAddrIndex), uwMacAddrHi);
            SRE_GMAC_READ_REG(uwPort, SRE_MAC_ADDR_LOW_MSK_REG(uwMacAddrIndex), uwMacAddrLowMsk);
            SRE_GMAC_READ_REG(uwPort, SRE_MAC_ADDR_HI_MSK_REG(uwMacAddrIndex), uwMacAddrHiMsk);

            if(((uwMacAddrLow & uwMacAddrLowMsk)
                == (pstrMacAddr->mac_addr_low & pstrMacAddr->mac_addr_low_mask))
                && (((uwMacAddrHi & uwMacAddrHiMsk) & 0xffff)
                == ((pstrMacAddr->mac_addr_hi & pstrMacAddr->mac_addr_hi_mask) & 0xffff)))
            {
                break;
            }
        }

        if(uwMacAddrIndex >= SRE_MAC_ADDR_MSK_NUM)
        {
            SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]:No MAC address matched! Del Mac address failed!"
                "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
                0xffffffff, OS_ERRNO_GMAC_MAC_DEL, 0, 0, 0, 0);
            RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_MAC_DEL, 0, 0);
        }
    }

    /*clear mac address register*/
    SRE_GMAC_WRITE_REG(uwPort, SRE_MAC_SA_LOW_REG(uwMacAddrIndex), 0);
    SRE_GMAC_WRITE_REG(uwPort, SRE_MAC_SA_HIGH_REG(uwMacAddrIndex), 0);
    if(uwMacAddrIndex < SRE_MAC_ADDR_MSK_NUM)
    {
        SRE_GMAC_WRITE_REG(uwPort, SRE_MAC_ADDR_LOW_MSK_REG(uwMacAddrIndex), 0xffffffff);
        SRE_GMAC_WRITE_REG(uwPort, SRE_MAC_ADDR_HI_MSK_REG(uwMacAddrIndex), 0xffff);
    }

    return OS_SUCCESS;
}

UINT32 SRE_MacAddrAdd_Ex(UINT32 uwPort,
                                        UINT32  uwAddrLow,
                                        UINT32  uwAddrHi,
                                        UINT32  uwAddrMaskLow,
                                        UINT32  uwAddrMaskHi)
{
    UINT32 uwRtn;

    SRE_MAC_MASK_ADDR_STR_S strMacAddr;
    strMacAddr.mac_addr_low = uwAddrLow;/**< mac地址低32bits  */
    strMacAddr.mac_addr_hi = uwAddrHi;/**< mac地址高16bits  */
    strMacAddr.mac_addr_low_mask = uwAddrMaskLow;/**< mac地址低32bits掩码  */
    strMacAddr.mac_addr_hi_mask = uwAddrMaskHi;/**< mac地址高16bits掩码  */

    uwRtn = SRE_MacAddrAdd(uwPort, &strMacAddr);

    return uwRtn;
}

UINT32 SRE_MacAddrDel_Ex(UINT32 uwPort,
                                        UINT32  uwAddrLow,
                                        UINT32  uwAddrHi,
                                        UINT32  uwAddrMaskLow,
                                        UINT32  uwAddrMaskHi)
{
    UINT32 uwRtn;

    SRE_MAC_MASK_ADDR_STR_S strMacAddr;
    strMacAddr.mac_addr_low = uwAddrLow;/**< mac地址低32bits  */
    strMacAddr.mac_addr_hi = uwAddrHi;/**< mac地址高16bits  */
    strMacAddr.mac_addr_low_mask = uwAddrMaskLow;/**< mac地址低32bits掩码  */
    strMacAddr.mac_addr_hi_mask = uwAddrMaskHi;/**< mac地址高16bits掩码  */

    uwRtn = SRE_MacAddrDel(uwPort, &strMacAddr);

    return uwRtn;
}

/*****************************************************************************
 函 数 名  : SRE_MacAddrDelWithNoMskChk
 功能描述  : MAC地址的删除函数，不检查掩码，
             先检查不带掩码的MAC匹配项，若找到则删除后返回成功
             若未找到，检查带掩码的MAC匹配项，若找到则删除后返回成功
             若未找到，则返回失败
 输入参数  : UINT32 uwPort
             const SRE_MAC_MASK_ADDR_STR_S *pstrMacAddr
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年3月25日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_MacAddrDelWithNoMskChk(UINT32 uwPort, const SRE_MAC_MASK_ADDR_STR_S *pstrMacAddr)
{
    UINT32 uwMacAddrIndex;
    UINT32 uwMacAddrLow;
    UINT32 uwMacAddrHi;
    UINT32 uwMacIndex;

    /* 输入参数合法性检查 */
    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pstrMacAddr)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]:Input mac address NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    /* mac address without mask */
    /* check if match current register value,MAC Adress reg 2 is for main mac address
    不带掩码的MAC地址从 3 开始，2为主MAC地址 */
    for(uwMacAddrIndex = 0, uwMacIndex = 3; uwMacIndex < SRE_MAC_ADDR_NUM; uwMacIndex++)
    {
        SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_LOW_REG(uwMacIndex), uwMacAddrLow);
        SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_HIGH_REG(uwMacIndex), uwMacAddrHi);

        if((uwMacAddrLow == pstrMacAddr->mac_addr_low) && ((uwMacAddrHi & 0xffff) == (pstrMacAddr->mac_addr_hi & 0xffff)))
        {
            uwMacAddrIndex = uwMacIndex;
            break;
        }
    }

    if(0 == uwMacAddrIndex)
    {
        /* mac address with mask */
        for(uwMacAddrIndex = 0; uwMacAddrIndex < SRE_MAC_ADDR_MSK_NUM; uwMacAddrIndex++)
        {
            SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_LOW_REG(uwMacAddrIndex), uwMacAddrLow);
            SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_HIGH_REG(uwMacAddrIndex), uwMacAddrHi);

            if((uwMacAddrLow == pstrMacAddr->mac_addr_low)
                && (((uwMacAddrHi) & 0xffff) == ((pstrMacAddr->mac_addr_hi) & 0xffff)))
            {
                break;
            }
        }

        if(uwMacAddrIndex >= SRE_MAC_ADDR_MSK_NUM)
        {
            SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]:No MAC address matched! Del Mac address failed!"
                "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
                0xffffffff, OS_ERRNO_GMAC_MAC_DEL, 0, 0, 0, 0);
            RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_MAC_DEL, 0, 0);
        }
    }

    /*clear mac address register*/
    SRE_GMAC_WRITE_REG(uwPort, SRE_MAC_SA_LOW_REG(uwMacAddrIndex), 0);
    SRE_GMAC_WRITE_REG(uwPort, SRE_MAC_SA_HIGH_REG(uwMacAddrIndex), 0);
    if(uwMacAddrIndex < SRE_MAC_ADDR_MSK_NUM)
    {
        SRE_GMAC_WRITE_REG(uwPort, SRE_MAC_ADDR_LOW_MSK_REG(uwMacAddrIndex), 0xffffffff);
        SRE_GMAC_WRITE_REG(uwPort, SRE_MAC_ADDR_HI_MSK_REG(uwMacAddrIndex), 0xffff);
    }

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_MacAddrShow
 功能描述  : MAC地址打印接口
 输入参数  : UINT32 uwPort
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年3月25日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_MacAddrShow(UINT32 uwPort)
{
    UINT32 uwRegIndex;
    UINT32 uwMacAddrLow;
    UINT32 uwMacAddrHi;
    UINT32 uwMacAddrMskLow;
    UINT32 uwMacAddrMskHi;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    for(uwRegIndex = 0; uwRegIndex < SRE_MAC_ADDR_NUM; uwRegIndex++)
    {
        SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_LOW_REG(uwRegIndex), uwMacAddrLow);
        SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_HIGH_REG(uwRegIndex), uwMacAddrHi);

        if( uwMacAddrLow ||(uwMacAddrHi & 0xffff))
        {
            SRE_printf("MAC address %d: %04x%08x\n", uwRegIndex, (uwMacAddrHi&0xffff), uwMacAddrLow);
            if(uwRegIndex<SRE_MAC_ADDR_MSK_NUM)
            {
                SRE_GMAC_READ_REG( uwPort, SRE_MAC_ADDR_LOW_MSK_REG(uwRegIndex), uwMacAddrMskLow);
                SRE_GMAC_READ_REG( uwPort, SRE_MAC_ADDR_HI_MSK_REG(uwRegIndex), uwMacAddrMskHi);
	            SRE_printf("The mask of MAC address %d is: %04x%08x\n", uwRegIndex, (uwMacAddrMskHi&0xffff) ,  uwMacAddrMskLow);
            }
        }
    }

    return OS_SUCCESS;
}

UINT32 SRE_MacAddrStationShow(UINT32 uwPort)
{
    UINT32 uwRegIndex;
    UINT32 uwMacAddrLow;
    UINT32 uwMacAddrHi;
    UINT32 uwMacAddrMskLow;
    UINT32 uwMacAddrMskHi;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    for(uwRegIndex = 0; uwRegIndex < SRE_MAC_ADDR_NUM; uwRegIndex++)
    {
        SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_LOW_REG(uwRegIndex), uwMacAddrLow);
        SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_HIGH_REG(uwRegIndex), uwMacAddrHi);

        SRE_printf("MAC address %d: %04x%08x\n", uwRegIndex, (uwMacAddrHi&0xffff), uwMacAddrLow);
        if(uwRegIndex<SRE_MAC_ADDR_MSK_NUM)
        {
            SRE_GMAC_READ_REG( uwPort, SRE_MAC_ADDR_LOW_MSK_REG(uwRegIndex), uwMacAddrMskLow);
            SRE_GMAC_READ_REG( uwPort, SRE_MAC_ADDR_HI_MSK_REG(uwRegIndex), uwMacAddrMskHi);
            SRE_printf("The mask of MAC address %d is: %04x%08x\n", uwRegIndex, (uwMacAddrMskHi&0xffff) ,  uwMacAddrMskLow);
        }
    }

    return OS_SUCCESS;
}

UINT32 SRE_GeSetShareUcEn(UINT32 uwPort, UINT32 uwStation, UINT32 uwMacAddrEn)
{
    UINT32 uwShareUcEnable;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwMacAddrEn > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_DMAC_EN_REG, uwShareUcEnable);
    uwShareUcEnable &= ~(1<<uwStation);
    uwShareUcEnable |= (uwMacAddrEn<<uwStation);
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_DMAC_EN_REG, uwShareUcEnable);
    SRE_printf("%s,SRE_GeSetShareUcEn port %d,station %d,en %d\n",__FUNCTION__,uwPort,uwStation,uwMacAddrEn);
    SRE_printf("%s,uwShareUcEnable 0x%08x\n",__FUNCTION__,uwShareUcEnable);
    return OS_SUCCESS;
}

UINT32 SRE_GeGetShareUcEn(UINT32 uwPort, UINT32 uwStation, UINT32 *puwMacAddrEn)
{
    UINT32 uwShareUcEnable;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_DMAC_EN_REG, uwShareUcEnable);
    *puwMacAddrEn = 0x1 & (uwShareUcEnable>>uwStation);

    SRE_printf("%s,uwStation = 0x%08x\n",__FUNCTION__,uwStation);
    SRE_printf("%s,uwShareUcEnable =0x%08x\n",__FUNCTION__,uwShareUcEnable);
    SRE_printf("%s,*puwMacAddrEn = 0x%08x\n",__FUNCTION__,*puwMacAddrEn);
    return OS_SUCCESS;
}

UINT32 SRE_GeAddShareUcMacAddr(UINT32 uwPort, SRE_MAC_MASK_ADDR_STR_S *pstrMacAddr)
{
    UINT32 uwRtn;
    UINT32 uwEmptyStation;
    UINT32 uwExistStation;
    SRE_XGE_MAC_ADDR_S stMacAddr;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    stMacAddr.uwMacAddrHi16 = pstrMacAddr->mac_addr_hi;
    stMacAddr.uwMacAddrLo32 = pstrMacAddr->mac_addr_low;

    SRE_printf("%s,add share uc start\n",__FUNCTION__);
    SRE_printf("%s,port:%d,addr: %04x%08x \n",__FUNCTION__,uwPort,stMacAddr.uwMacAddrHi16,stMacAddr.uwMacAddrLo32);

    /* 搜索mac地址 */
    uwRtn = SRE_XgeaSerchShareUcMacAddr(&uwExistStation, &stMacAddr);
    if(OS_SUCCESS == uwRtn)
    {
        SRE_printf("%s,serch addr ok,hit station %d\n",__FUNCTION__,uwExistStation);
        /* 本gmac对该 station 感知 */
        uwRtn = SRE_GeSetShareUcEn(uwPort, uwExistStation, 1);
        if(OS_SUCCESS != uwRtn)
        {
            return uwRtn;
        }

        /* 使能本 station */
        uwRtn = SRE_XgeSetUcFiltEn(uwExistStation, 1);
        if(OS_SUCCESS != uwRtn)
        {
            return uwRtn;
        }
    }
    else
    {
        SRE_printf("%s,serch addr fail\n",__FUNCTION__);
        /* 寻找排位，并将mac地址放入 公有 uc 池  */
        uwRtn = SRE_XgeaAddShareUcMacAddr(&uwEmptyStation, &stMacAddr);
        if(OS_SUCCESS != uwRtn)
        {
            SRE_printf("%s,add addr fail\n",__FUNCTION__);
            return uwRtn;
        }
        SRE_printf("%s,add to station %d ok\n",__FUNCTION__,uwEmptyStation);
        /* 本gmac对该 station 感知 */
        uwRtn = SRE_GeSetShareUcEn(uwPort, uwEmptyStation, 1);
        if(OS_SUCCESS != uwRtn)
        {
            return uwRtn;
        }

        /* 使能本 station */
        uwRtn = SRE_XgeSetUcFiltEn(uwEmptyStation, 1);
        if(OS_SUCCESS != uwRtn)
        {
            return uwRtn;
        }
    }
    return OS_SUCCESS;
}

UINT32 SRE_GeDelShareUcMacAddr(UINT32 uwPort, SRE_MAC_MASK_ADDR_STR_S *pstrMacAddr)
{
    UINT32 uwRtn;
    UINT32 uwExistStation;
    UINT32 uwGmacPortIndex;
    UINT32 uwMacAddrEn;
    SRE_XGE_MAC_ADDR_S stXgeMacAddr;

    stXgeMacAddr.uwMacAddrHi16 = pstrMacAddr->mac_addr_hi;
    stXgeMacAddr.uwMacAddrLo32 = pstrMacAddr->mac_addr_low;

    /* 搜索mac地址 */
    uwRtn = SRE_XgeaSerchShareUcMacAddr(&uwExistStation, &stXgeMacAddr);
    if(OS_SUCCESS != uwRtn)
    {
        return uwRtn;
    }

    /* 本gmac对该 station 去感知 */
    uwRtn = SRE_GeSetShareUcEn(uwPort, uwExistStation, 0);
    if(OS_SUCCESS != uwRtn)
    {
        return uwRtn;
    }
    SRE_printf("%s,port %d unlock station=%d addr=%04x%08x\n",__FUNCTION__,uwPort, uwExistStation,stXgeMacAddr.uwMacAddrHi16,stXgeMacAddr.uwMacAddrLo32);
    /* 如果所有gmac对该 station 都已去感知则删除该station，并关闭总开关 */
    for(uwGmacPortIndex = 0;uwGmacPortIndex < SRE_GE_MAX_BUSINESS_PORT_NUM; uwGmacPortIndex++)
    {
        uwRtn = SRE_GeGetShareUcEn(uwGmacPortIndex, uwExistStation, &uwMacAddrEn);
        if(OS_SUCCESS != uwRtn)
        {
            return uwRtn;
        }

        if(1 == uwMacAddrEn)
        {
            return OS_SUCCESS;
        }
    }

    /*关闭该station的总开关 */
    uwRtn = SRE_XgeSetUcFiltEn(uwExistStation, 0);
    if(OS_SUCCESS != uwRtn)
    {
        return uwRtn;
    }

    /* 删除该地址 */
    uwRtn = SRE_XgeaDelShareUcMacAddr(&uwExistStation, &stXgeMacAddr);
    if(OS_SUCCESS != uwRtn)
    {
        return uwRtn;
    }

    return OS_SUCCESS;
}

UINT32 SRE_GeShowShareUcMacCfg(void)
{
    SRE_XGE_MAC_ADDR_S stMacAddr;
    UINT32 uwShareUcFirstEn;
    UINT32 uwShareUcSecndEn[SRE_GE_MAX_BUSINESS_PORT_NUM];
    UINT32 uwStation;
    UINT32 uwPort;
    UINT32 uwRtn;

    MC_PRINTK_DFX("station      addr   1stEn  2ndEn_0 1 2 3 4 5 6 7 8\n");
    for(uwStation = 0;uwStation< SRE_XGE_SHARE_UC_MAC_ADDR_MAX_NUM;uwStation++)
    {
        uwRtn = SRE_XgeGetUcMacAddr(uwStation, &stMacAddr);
        if(OS_SUCCESS != uwRtn)
        {
            return uwRtn;
        }

        uwRtn = SRE_XgeGetUcFiltEn(uwStation, &uwShareUcFirstEn);
        if(OS_SUCCESS != uwRtn)
        {
            return uwRtn;
        }

        MC_PRINTK_DFX("%02d      %04x%08x   %d         ",uwStation,
                                        stMacAddr.uwMacAddrHi16,
                                        stMacAddr.uwMacAddrLo32,
                                        uwShareUcFirstEn);

        for(uwPort = 0;uwPort< SRE_GE_MAX_BUSINESS_PORT_NUM;uwPort++)
        {
            uwRtn = SRE_GeGetShareUcEn(uwPort, uwStation, &uwShareUcSecndEn[uwPort]);
            if(OS_SUCCESS != uwRtn)
            {
                return uwRtn;
            }
            MC_PRINTK_DFX("%d ",uwShareUcSecndEn[uwPort]);
        }
        MC_PRINTK_DFX("\n");
    }

    return OS_SUCCESS;
}
/*****************************************************************************
 函 数 名  : SRE_GmacMacAddrQuery
 功能描述  : 过滤mac地址的查询接口
 输入参数  : UINT32 uwPort
             const SRE_MAC_MASK_ADDR_STR_S *pstrMacAddr
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年3月25日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GmacMacAddrQuery(UINT32 uwPort, UINT32 *uwMacNum, SRE_MAC_MASK_ADDR_STR_S *pstrMacAddr)
{
    UINT32 uwRegIndex;
    UINT32 uwMacAddrLow;
    UINT32 uwMacAddrHi;
    UINT32 uwMacAddrMskLow;
    UINT32 uwMacAddrMskHi;
    UINT32 uwValidMacAddrNum = 0;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if((NULL == pstrMacAddr) || (NULL == uwMacNum))
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]:Input mac address ptr is NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    for(uwRegIndex = 0; uwRegIndex < SRE_MAC_ADDR_NUM; uwRegIndex++)
    {
        /*GMAC2for main mac address*/
        if(2 == uwRegIndex)
        {
            continue;
        }

        SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_LOW_REG(uwRegIndex), uwMacAddrLow);
        SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_HIGH_REG(uwRegIndex), uwMacAddrHi);

        if( uwMacAddrLow ||(uwMacAddrHi & 0xffff))
        {
            pstrMacAddr[uwValidMacAddrNum].mac_addr_hi = uwMacAddrHi & 0xffff;
            pstrMacAddr[uwValidMacAddrNum].mac_addr_low = uwMacAddrLow;
            pstrMacAddr[uwValidMacAddrNum].mac_addr_low_mask = 0xffffffff;
            pstrMacAddr[uwValidMacAddrNum].mac_addr_hi_mask = 0xffff;

            if(uwRegIndex<SRE_MAC_ADDR_MSK_NUM)
            {
                SRE_GMAC_READ_REG( uwPort, SRE_MAC_ADDR_LOW_MSK_REG(uwRegIndex), uwMacAddrMskLow);
                SRE_GMAC_READ_REG( uwPort, SRE_MAC_ADDR_HI_MSK_REG(uwRegIndex), uwMacAddrMskHi);
                pstrMacAddr[uwValidMacAddrNum].mac_addr_low_mask = uwMacAddrMskLow;
                pstrMacAddr[uwValidMacAddrNum].mac_addr_hi_mask = uwMacAddrMskHi & 0xffff;
            }
            uwValidMacAddrNum++;
        }
    }

    *uwMacNum = uwValidMacAddrNum;

    return OS_SUCCESS;

}

/*****************************************************************************
 函 数 名  : SRE_GmacMainMacAddrSet
 功能描述  : GMAC 主MAC地址设置函数
 输入参数  : UINT32 uwPort
             const SRE_MAC_ADDR_STR_S *pstrMacAddr
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年3月16日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GmacMainMacAddrSet(UINT32 uwPort, const SRE_MAC_MASK_ADDR_STR_S *pstrMacAddr)
{
    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pstrMacAddr)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC] Input mac address NULL!!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_WRITE_REG(uwPort, SRE_MAC_SA_MSK_LOW_REG(2), pstrMacAddr->mac_addr_low);
    SRE_GMAC_WRITE_REG(uwPort, SRE_MAC_SA_MSK_HIGH_REG(2), pstrMacAddr->mac_addr_hi);

    return OS_SUCCESS;

}

/*****************************************************************************
 函 数 名  : SRE_GmacMainMacAddrClr
 功能描述  : GMAC 主MAC地址清除函数
 输入参数  : UINT32 uwPort
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年3月16日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GmacMainMacAddrClr(UINT32 uwPort)
{
    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    SRE_GMAC_WRITE_REG(uwPort, SRE_MAC_SA_MSK_LOW_REG(2), 0);
    SRE_GMAC_WRITE_REG(uwPort, SRE_MAC_SA_MSK_HIGH_REG(2), 0);

    return OS_SUCCESS;

}

/*****************************************************************************
 函 数 名  : SRE_GmacMainMacAddrQuery
 功能描述  : 主MAC地址的查询接口
 输入参数  : UINT32 uwPort
             const SRE_MAC_MASK_ADDR_STR_S *pstrMacAddr
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年3月25日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GmacMainMacAddrQuery(UINT32 uwPort, SRE_MAC_MASK_ADDR_STR_S *pstrMacAddr)
{
    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pstrMacAddr)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC] Input mac address NULL!!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_MSK_LOW_REG(2), pstrMacAddr->mac_addr_low);
    SRE_GMAC_READ_REG(uwPort, SRE_MAC_SA_MSK_HIGH_REG(2), pstrMacAddr->mac_addr_hi);
    pstrMacAddr->mac_addr_low_mask = 0xffffffff;
    pstrMacAddr->mac_addr_hi_mask = 0xffff;

    return OS_SUCCESS;
}


/*****************************************************************************
 函 数 名  : SRE_PktModeSet, SRE_PktModeGet
 功能描述  : 报文的输入模式及解析模式设置和查询
 输入参数  : 端口号
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
UINT32 SRE_PktModeSet(UINT32 uwPort, const SRE_RX_PKT_MODE_CFG_S *pstrRxPktMode)
{
    SRE_GMAC_MAC_SKIP_LEN_U unSkipLen;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pstrRxPktMode)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC] Packet mode parameter NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    /*报文头不解析字段长度,不解析字段做CRC*/
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_MAC_SKIP_LEN_REG, unSkipLen.u32);
    unSkipLen.bits.mac_skip_len = pstrRxPktMode->mac_skip_len;
    unSkipLen.bits.mac_skip_crc = pstrRxPktMode->mac_skip_crc;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_MAC_SKIP_LEN_REG, unSkipLen.u32);

    return OS_SUCCESS;
}

UINT32 SRE_PktModeGet(UINT32 uwPort, SRE_RX_PKT_MODE_CFG_S *pstrRxPktMode)
{
    SRE_GMAC_MAC_SKIP_LEN_U unSkipLen;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pstrRxPktMode)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC] Packet mode pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }


    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_MAC_SKIP_LEN_REG, unSkipLen.u32);
    pstrRxPktMode->mac_skip_len = unSkipLen.bits.mac_skip_len ;
    pstrRxPktMode->mac_skip_len = unSkipLen.bits.mac_skip_crc ;
    return OS_SUCCESS;
}


/*****************************************************************************
 函 数 名  : SRE_InputModeSet
 功能描述  : 报文的输入模式设置函数
 输入参数  : UINT32 uwPort
             UINT32 uwInMode     0: 非指令头模式  1: 指令头模式
             UINT32 uwPsMode     0: 不解析1:从2层开始解析2:从 3层开始解析
             UINT32 uwPktSkip     报文头不解析的长度
             UINT32 uwMacSkip   报文头到MAC的长度
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年5月19日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_InputModeSet(UINT32 uwPort, UINT32 uwMacSkip, UINT32 uwSkipCrc)
{
    SRE_GMAC_MAC_SKIP_LEN_U unSkipLen;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    /*报文头不解析字段长度,不解析字段做CRC*/
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_MAC_SKIP_LEN_REG, unSkipLen.u32);
    unSkipLen.bits.mac_skip_len = uwMacSkip;
    unSkipLen.bits.mac_skip_crc = uwSkipCrc;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_MAC_SKIP_LEN_REG, unSkipLen.u32);

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_SetGpio
 功能描述  : 设置和网口相关的两个GPIO管脚方向
 输入参数  : VOID
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年11月4日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
VOID SRE_SetGpio(VOID)
{
    UINT32 uwReadReg;

    /*set gpio output*/
    uwReadReg = OS_READ_REG(MC_GPIO0_SWPORT_DR_REG, 0);
    uwReadReg |= 0x00080000;
    OS_WRITE_REG(MC_GPIO0_SWPORT_DR_REG, 0, uwReadReg);

    uwReadReg = OS_READ_REG(MC_GPIO0_SWPORT_DDR_REG, 0);
    uwReadReg |= 0x00080000;
    OS_WRITE_REG(MC_GPIO0_SWPORT_DDR_REG, 0, uwReadReg);

    //SRE_DelayUs(1000);
    SRE_PhyDelayUs(1000);
}
/*****************************************************************************
 函 数 名  : SRE_PortModeSet, SRE_PortModeGet
 功能描述  : 端口模式相关参数的设置及查询
 输入参数  : 端口号
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
UINT32 SRE_PortModeSet(UINT32 uwPort, const SRE_PORT_MODE_CFG_S *pstrPortMode)
{
    SRE_GMAC_MAX_FRM_SIZE_U unMaxFrmSize;
    SRE_GMAC_SHORT_RUNTS_THR_U unShortFrmThr;
    SRE_GMAC_TRANSMIT_CONTROL_U unTxCtrl;
    SRE_GMAC_RECV_CONTROL_U unRecvCtrl;
    SRE_GMAC_PORT_MODE_U unPortMode;
    SRE_GMAC_MODE_CHANGE_EN_U unModeChangeEn;
    UINT32 uwRtn;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pstrPortMode)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC] Port mode parameter NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }


    /*设置端口模式*/
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_PORT_MODE_REG, unPortMode.u32);
    unPortMode.bits.port_mode = pstrPortMode->port_mode;
    if((pstrPortMode->port_mode >= GMAC_10M_RGMII) && (pstrPortMode->port_mode <= GMAC_1000M_RGMII))
    {
        /* BEGIN: Added by c00111586, 2010/10/22   问题单号:DTS2010101600721 */
        unPortMode.bits.rgmii_1000m_delay = 1;
        /* END:   Added by c00111586, 2010/10/22 */
    }
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_PORT_MODE_REG, unPortMode.u32);

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_MODE_CHANGE_EN_REG, unModeChangeEn.u32);
    unModeChangeEn.bits.mode_change_en = 1;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_MODE_CHANGE_EN_REG, unModeChangeEn.u32);


    /*设置最大帧长*/
    unMaxFrmSize.u32 = 0;
    unMaxFrmSize.bits.max_frm_size = pstrPortMode->max_frm_size;

    /*短帧／超短帧界限*/
    unShortFrmThr.u32 = 0;
    unShortFrmThr.bits.short_runts_thr = pstrPortMode->short_runts_thr;

    /*设置最大帧长*/
    uwRtn = SRE_MaxFrmSizeSet(uwPort, unMaxFrmSize.u32);
    if(uwRtn != OS_SUCCESS)
    {
        return uwRtn;
    }

    /*短帧／超短帧界限*/
    uwRtn = SRE_ShortFrmSizeSet(uwPort, unShortFrmThr.u32);
    if(uwRtn != OS_SUCCESS)
    {
        return uwRtn;
    }

    /* BEGIN: Modified by c00111586, 2011/7/28   问题单号:DTS2011072603695  */
    /* 配置SGMII自协商本地配置寄存器TX_LOCAL_PAGE（基地址0x30000000+-
       1000*ch_num，偏移地址为0x005C）为32’h1。 */
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_TX_LOCAL_PAGE_REG, 0x1UL);

    /* 自协商link时间，推荐值为 0x3f */
    uwRtn = SRE_UpdateAnLinkTime(uwPort, 0x3fUL);
    if(uwRtn != OS_SUCCESS)
    {
        return uwRtn;
    }
    /* END:   Modified by c00111586, 2011/7/28 */

    /*发送添加pad/FCS/自协商使能*/
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TRANSMIT_CONTROL_REG, unTxCtrl.u32);
    unTxCtrl.bits.pad_enable = 1;
    unTxCtrl.bits.crc_add = 1;
    unTxCtrl.bits.an_enable = 1;

    /*发送添加pad/FCS/自协商使能*/
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_TRANSMIT_CONTROL_REG, unTxCtrl.u32);

    /*超短帧透传／接收PAD剥离使能*/
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RECV_CONTROL_REG, unRecvCtrl.u32);

    /* 短帧透传功能需要禁止 */
    unRecvCtrl.bits.runt_pkt_en = 0;
    unRecvCtrl.bits.strip_pad_en = 1;

    /*超短帧透传／接收PAD剥离使能*/
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_RECV_CONTROL_REG, unRecvCtrl.u32);

    return OS_SUCCESS;
}

UINT32 SRE_PortModeGet(UINT32 uwPort, SRE_PORT_MODE_CFG_S *pstrPortMode)
{
    SRE_GMAC_MAX_FRM_SIZE_U unMaxFrmSize;
    SRE_GMAC_SHORT_RUNTS_THR_U unShortFrmThr;
    SRE_GMAC_TRANSMIT_CONTROL_U unTxCtrl;
    SRE_GMAC_RECV_CONTROL_U unRecvCtrl;
    SRE_GMAC_PORT_MODE_U unPortMode;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == pstrPortMode)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC] Port mode pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_PORT_MODE_REG, unPortMode.u32);
    pstrPortMode->port_mode = (SRE_PORT_MODE_E)unPortMode.bits.port_mode;

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_MAX_FRM_SIZE_REG, unMaxFrmSize.u32);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_SHORT_RUNTS_THR_REG, unShortFrmThr.u32);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TRANSMIT_CONTROL_REG, unTxCtrl.u32);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RECV_CONTROL_REG, unRecvCtrl.u32);

    pstrPortMode->max_frm_size = unMaxFrmSize.bits.max_frm_size;
    pstrPortMode->short_runts_thr = unShortFrmThr.bits.short_runts_thr;

    pstrPortMode->pad_enable = unTxCtrl.bits.pad_enable;
    pstrPortMode->crc_add = unTxCtrl.bits.crc_add;
    pstrPortMode->an_enable = unTxCtrl.bits.an_enable;

    pstrPortMode->runt_pkt_en = unRecvCtrl.bits.runt_pkt_en;
    pstrPortMode->strip_pad_en = unRecvCtrl.bits.strip_pad_en;

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_GmacCrcStripEn
 功能描述  : GMAC接收剥离CRC使能函数
 输入参数  : UINT32 uwPort
             UINT32 uwEnValue
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年5月17日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GmacCrcStripEn(UINT32 uwPort, UINT32 uwEnValue)
{
    SRE_GMAC_CF_CRC_STRIP_U unCrcStrip;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwEnValue > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_CF_CRC_STRIP_REG, unCrcStrip.u32);
    unCrcStrip.bits.cf_crc_strip = uwEnValue;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_CF_CRC_STRIP_REG, unCrcStrip.u32);

    return OS_SUCCESS;
}


/*****************************************************************************
 函 数 名  : SRE_GmacCrcAddEn
 功能描述  : GMAC发送添加CRC使能函数
 输入参数  : UINT32 uwPort
             UINT32 uwEnValue
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年5月17日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GmacCrcAddEn(UINT32 uwPort, UINT32 uwEnValue)
{
    SRE_GMAC_TRANSMIT_CONTROL_U unTxCtrl;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwEnValue > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TRANSMIT_CONTROL_REG, unTxCtrl.u32);
    unTxCtrl.bits.crc_add = uwEnValue;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_TRANSMIT_CONTROL_REG, unTxCtrl.u32);

    return OS_SUCCESS;
}












/*****************************************************************************
 函 数 名  : SRE_GmacStatisticsShow
 功能描述  : GMAC端口各计数器查询
 输入参数  : 端口号
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

*****************************************************************************/
UINT32 SRE_GmacStatisticsShow(UINT32 uwPort)
{
    UINT32 uwrx_octets_total_ok_cnt;
    UINT32 uwrx_octets_bad_cnt;
    UINT32 uwrx_uc_pkts_cnt;
    UINT32 uwrx_mc_pkts_cnt;
    UINT32 uwrx_bc_pkts_cnt;
    UINT32 uwrx_vlan_pkt_cnt;
    UINT32 uwrx_fw_ctrl_frame_cnt;
    UINT32 uwrx_octets_total_filt_cnt;
    UINT32 uwrx_filt_pkt_cnt;

    UINT32 uwrx_framsize_64;
    UINT32 uwrx_framsize_65_127;
    UINT32 uwrx_framsize_128_255;
    UINT32 uwrx_framsize_256_511;
    UINT32 uwrx_framsize_512_1023;
    UINT32 uwrx_framsize_1024_1518;
    UINT32 uwrx_framsize_bt_1518;


    UINT32 uwrx_fcs_error_cnt;
    UINT32 uwrx_data_error_cnt;
    UINT32 uwrx_align_error_cnt;
    UINT32 uwrx_frame_long_err_cnt;
    UINT32 uwrx_frame_very_long_err_cnt;
    UINT32 uwrx_frame_runt_err_cnt;
    UINT32 uwrx_frame_short_err_cnt;
    UINT32 uwrx_overrun_cnt;


    UINT32 uwtx_octets_total_ok_cnt;
    UINT32 uwtx_octets_bad_cnt;
    UINT32 uwtx_uc_pkts_cnt;
    UINT32 uwtx_mc_pkts_cnt;
    UINT32 uwtx_bc_pkts_cnt;
    UINT32 uwtx_vlan_pkt_cnt;
    UINT32 uwtx_fw_ctrl_frame_cnt;

    UINT32 uwtx_framsize_64;
    UINT32 uwtx_framsize_65_127;
    UINT32 uwtx_framsize_128_255;
    UINT32 uwtx_framsize_256_511;
    UINT32 uwtx_framsize_512_1023;
    UINT32 uwtx_framsize_1024_1518;
    UINT32 uwtx_framsize_bt_1518;

    UINT32 uwtx_fcs_error_cnt;
    UINT32 uwtx_underrun_err_cnt;


    UINT32 uwtx_excessive_drop_cnt;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    /*RX COUNT*/
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_UC_PKTS_REG, uwrx_uc_pkts_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_MC_PKTS_REG, uwrx_mc_pkts_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_BC_PKTS_REG, uwrx_bc_pkts_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_TAGGED_REG, uwrx_vlan_pkt_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_PAUSE_MACCONTROL_FRAMCOUNTER_REG, uwrx_fw_ctrl_frame_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_OCTETS_TOTAL_OK_REG, uwrx_octets_total_ok_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_OCTETS_BAD_REG, uwrx_octets_bad_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_OCTETS_TOTAL_FILT_REG, uwrx_octets_total_filt_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_FILT_PKT_CNT_REG, uwrx_filt_pkt_cnt);

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_PKTS_64OCTETS_REG, uwrx_framsize_64);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_PKTS_65TO127OCTETS_REG, uwrx_framsize_65_127);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_PKTS_128TO255OCTETS_REG, uwrx_framsize_128_255);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_PKTS_255TO511OCTETS_REG, uwrx_framsize_256_511);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_PKTS_512TO1023OCTETS_REG, uwrx_framsize_512_1023);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_PKTS_1024TO1518OCTETS_REG, uwrx_framsize_1024_1518);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_PKTS_1519TOMAXOCTETS_REG, uwrx_framsize_bt_1518);

    /*RX ERROR COUNT*/
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_LONG_ERRORS_REG, uwrx_frame_long_err_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_VERY_LONG_ERR_CNT_REG, uwrx_frame_very_long_err_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_RUNT_ERR_CNT_REG, uwrx_frame_runt_err_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_SHORT_ERR_CNT_REG, uwrx_frame_short_err_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_OVERRUN_CNT_REG, uwrx_overrun_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_FCS_ERRORS_REG, uwrx_fcs_error_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_DATA_ERR_REG, uwrx_data_error_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_RX_ALIGN_ERRORS_REG, uwrx_align_error_cnt);

    /*TX COUNT*/
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_UC_PKTS_REG, uwtx_uc_pkts_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_MC_PKTS_REG, uwtx_mc_pkts_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_BC_PKTS_REG, uwtx_bc_pkts_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_TAGGED_REG, uwtx_vlan_pkt_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_PAUSE_FRAMES_REG, uwtx_fw_ctrl_frame_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_OCTETS_TRANSMITTED_OK_REG, uwtx_octets_total_ok_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_OCTETS_TRANSMITTED_BAD_REG, uwtx_octets_bad_cnt);

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_PKTS_64OCTETS_REG, uwtx_framsize_64);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_PKTS_65TO127OCTETS_REG, uwtx_framsize_65_127);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_PKTS_128TO255OCTETS_REG, uwtx_framsize_128_255);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_PKTS_255TO511OCTETS_REG, uwtx_framsize_256_511);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_PKTS_512TO1023OCTETS_REG, uwtx_framsize_512_1023);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_PKTS_1024TO1518OCTETS_REG, uwtx_framsize_1024_1518);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_PKTS_1519TOMAXOCTETS_REG, uwtx_framsize_bt_1518);

    /*TX ERROR COUNT*/
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_CRC_ERROR_REG, uwtx_fcs_error_cnt);
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_UNDERRUN_REG, uwtx_underrun_err_cnt);

    /*RX DROP COUNT*/

    /*TX DROP COUNT*/
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_EXCESSIVE_LENGTH_DROP_REG, uwtx_excessive_drop_cnt);

    MC_PRINTK_DFX("\n****************************RX COUNTERS****************************\n");

    if(uwrx_uc_pkts_cnt)
    {
        MC_PRINTK_DFX("Received unicast packets counter: %u\n", uwrx_uc_pkts_cnt);
    }
    if(uwrx_mc_pkts_cnt)
    {
	MC_PRINTK_DFX("Received multicast packets counter: %u\n", uwrx_mc_pkts_cnt);
    }
    if(uwrx_bc_pkts_cnt)
    {
	MC_PRINTK_DFX("Received broadcast packets counter: %u\n", uwrx_bc_pkts_cnt);
    }
    if(uwrx_vlan_pkt_cnt)
    {
        MC_PRINTK_DFX("Received vlan packets counter: %u\n", uwrx_vlan_pkt_cnt);
    }
    if(uwrx_octets_total_ok_cnt)
    {
        MC_PRINTK_DFX("Received paket bytes: %u\n", uwrx_octets_total_ok_cnt);
    }
    if(uwrx_octets_total_filt_cnt)
    {
        MC_PRINTK_DFX("Received filt total bytes: %u\n", uwrx_octets_total_filt_cnt);
    }
    if(uwrx_filt_pkt_cnt)
    {
        MC_PRINTK_DFX("Received filt packets: %u\n", uwrx_filt_pkt_cnt);
    }
    if(uwrx_fw_ctrl_frame_cnt)
    {
        MC_PRINTK_DFX("Received flow control frames counter: %u\n", uwrx_fw_ctrl_frame_cnt);
    }
    if(uwrx_framsize_64)
    {
        MC_PRINTK_DFX("Received  frames size 64 bytes counter: %u\n", uwrx_framsize_64);
    }
    if(uwrx_framsize_65_127)
    {
        MC_PRINTK_DFX("Received  frames size 65-127 bytes counter: %u\n", uwrx_framsize_65_127);
    }
    if(uwrx_framsize_128_255)
    {
        MC_PRINTK_DFX("Received  frames size 128-255 bytes counter: %u\n", uwrx_framsize_128_255);
    }
    if(uwrx_framsize_256_511)
    {
        MC_PRINTK_DFX("Received  frames size 256-511 bytes counter: %u\n", uwrx_framsize_256_511);
    }
    if(uwrx_framsize_512_1023)
    {
        MC_PRINTK_DFX("Received  frames size 511-1023 bytes counter: %u\n", uwrx_framsize_512_1023);
    }
    if(uwrx_framsize_1024_1518)
    {
        MC_PRINTK_DFX("Received  frames size 1024-1518 bytes counter: %u\n", uwrx_framsize_1024_1518);
    }
    if(uwrx_framsize_bt_1518)
    {
        MC_PRINTK_DFX("Received  frames size bigger than 1518 bytes counter: %u\n", uwrx_framsize_bt_1518);
    }

    MC_PRINTK_DFX("\n****************************RX ERROR COUNTERS****************************\n");

    if(uwrx_octets_bad_cnt)
    {
        MC_PRINTK_DFX("Received error pakets bytes counter: %u\n", uwrx_octets_bad_cnt);
    }

    if(uwrx_frame_long_err_cnt)
    {
        MC_PRINTK_DFX("Received long frames counter: %u\n", uwrx_frame_long_err_cnt);
    }
    if(uwrx_frame_long_err_cnt || uwrx_frame_very_long_err_cnt)
    {
        MC_PRINTK_DFX("Received super long frames counter: %u\n", uwrx_frame_very_long_err_cnt);
    }
    if(uwrx_frame_runt_err_cnt || uwrx_frame_short_err_cnt)
    {
        MC_PRINTK_DFX("Received super short frames counter: %u\n", uwrx_frame_short_err_cnt);
    }

    if(uwrx_frame_runt_err_cnt)
    {
        MC_PRINTK_DFX("Received short frames counter: %u\n", uwrx_frame_runt_err_cnt);
    }

    if(uwrx_overrun_cnt)
    {
        MC_PRINTK_DFX("Received fifo overrun counter: %u\n", uwrx_overrun_cnt);
    }
    if(uwrx_fcs_error_cnt)
    {
        MC_PRINTK_DFX("Received packet crc error counter: %u\n", uwrx_fcs_error_cnt);
    }
    if(uwrx_data_error_cnt)
    {
        MC_PRINTK_DFX("Received packet data error counter: %u\n", uwrx_data_error_cnt);
    }
    if(uwrx_align_error_cnt)
    {
        MC_PRINTK_DFX("Received frame align error counter: %u\n", uwrx_align_error_cnt);
    }

    MC_PRINTK_DFX("\n****************************TX COUNTERS****************************\n");

    if(uwtx_uc_pkts_cnt)
    {
        MC_PRINTK_DFX("Transmited unicast packets counter: %u\n", uwtx_uc_pkts_cnt);
    }
    if(uwtx_mc_pkts_cnt)
    {
        MC_PRINTK_DFX("Transmited multicast packets counter: %u\n", uwtx_mc_pkts_cnt);
    }
    if(uwtx_bc_pkts_cnt)
    {
        MC_PRINTK_DFX("Transmited broadcast packets counter: %u\n", uwtx_bc_pkts_cnt);
    }
    if(uwtx_vlan_pkt_cnt)
    {
        MC_PRINTK_DFX("Transmited vlan packets counter: %u\n", uwtx_vlan_pkt_cnt);
    }
    if(uwtx_octets_total_ok_cnt)
    {
        MC_PRINTK_DFX("Transmited packet bytes counter: %u\n", uwtx_octets_total_ok_cnt);
    }
    if(uwtx_fw_ctrl_frame_cnt)
    {
        MC_PRINTK_DFX("Transmited flow control frames counter: %u\n", uwtx_fw_ctrl_frame_cnt);
    }
    if(uwtx_framsize_64)
    {
        MC_PRINTK_DFX("Transmited  frames size 64 bytes counter: %u\n", uwtx_framsize_64);
    }
    if(uwtx_framsize_65_127)
    {
        MC_PRINTK_DFX("Transmited  frames size 65-127 bytes counter: %u\n", uwtx_framsize_65_127);
    }
    if(uwtx_framsize_128_255)
    {
        MC_PRINTK_DFX("Transmited  frames size 128-255 bytes counter: %u\n", uwtx_framsize_128_255);
    }
    if(uwtx_framsize_256_511)
    {
        MC_PRINTK_DFX("Transmited  frames size 256-511 bytes counter: %u\n", uwtx_framsize_256_511);
    }
    if(uwtx_framsize_512_1023)
    {
        MC_PRINTK_DFX("Transmited  frames size 511-1023 bytes counter: %u\n", uwtx_framsize_512_1023);
    }
    if(uwtx_framsize_1024_1518)
    {
        MC_PRINTK_DFX("Transmited  frames size 1024-1518 bytes counter: %u\n", uwtx_framsize_1024_1518);
    }
    if(uwtx_framsize_bt_1518)
    {
        MC_PRINTK_DFX("Transmited  frames size bigger than 1518 bytes counter: %u\n", uwtx_framsize_bt_1518);
    }

    MC_PRINTK_DFX("\n****************************TX ERROR COUNTERS****************************\n");

    if(uwtx_octets_bad_cnt)
    {
        MC_PRINTK_DFX("Transmited bad packets bytes counter: %u\n", uwtx_octets_bad_cnt);
    }
    if(uwtx_underrun_err_cnt)
    {
        MC_PRINTK_DFX("Transmited failed counter: %u\n", uwtx_underrun_err_cnt);
    }
    if(uwtx_fcs_error_cnt)
    {
        MC_PRINTK_DFX("Transmited packet crc error counter: %u\n", uwtx_fcs_error_cnt);
    }

    MC_PRINTK_DFX("\n****************************RX DROP COUNTERS****************************\n");


    MC_PRINTK_DFX("\n****************************TX DROP COUNTERS****************************\n");

    if(uwtx_excessive_drop_cnt)
    {
        MC_PRINTK_DFX("Transmited excessive length frame failed drop counter: %u\n", uwtx_excessive_drop_cnt);
    }

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_GmacPauseFrmCfg
 功能描述  : 响应流控帧配置接口
 输入参数  : UINT32 uwPort
             UINT32 uwRxPauseEn
             UINT32 uwTxPauseEn
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年3月18日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GmacPauseFrmCfg(UINT32 uwPort, UINT32 uwRxPauseEn, UINT32 uwTxPauseEn)
{
    SRE_GMAC_PAUSE_EN_U unPauseEn;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwRxPauseEn > 1 || uwTxPauseEn > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_PAUSE_EN_REG, unPauseEn.u32);
    unPauseEn.bits.rx_fdfc = uwRxPauseEn;
    unPauseEn.bits.tx_fdfc = uwTxPauseEn;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_PAUSE_EN_REG, unPauseEn.u32);

    return OS_SUCCESS;

}

/*****************************************************************************
 函 数 名  : SRE_GetGmacPauseFrmCfg
 功能描述  : 获取pause帧配置信息
 输入参数  : UINT32 uwPort
             UINT32 *puwRxPauseEn
             UINT32 *puwTxPauseEn
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年11月17日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GetGmacPauseFrmCfg(UINT32 uwPort, UINT32 *puwRxPauseEn, UINT32 *puwTxPauseEn)
{
    SRE_GMAC_PAUSE_EN_U unPauseEn;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC]: Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if((NULL == puwRxPauseEn) || (NULL == puwTxPauseEn))
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_PAUSE_EN_REG, unPauseEn.u32);
    *puwRxPauseEn = unPauseEn.bits.rx_fdfc;
    *puwTxPauseEn = unPauseEn.bits.tx_fdfc;
    return OS_SUCCESS;
}

UINT32 SRE_GmacPauseCfgShow(UINT32 uwPort)
{
    UINT32 uwRxPauseEn;
    UINT32 uwTxPauseEn;

    SRE_GetGmacPauseFrmCfg(uwPort, &uwRxPauseEn, &uwTxPauseEn);
    if(1 == uwRxPauseEn)
    {
        SRE_printf("rx pause : enable\n");
    }
    else
    {
        SRE_printf("rx pause : disable\n");
    }
    if(1 == uwTxPauseEn)
    {
        SRE_printf("tx pause : enable\n");
    }
    else
    {
        SRE_printf("tx pause : disable\n");
    }

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_SerdesBist
 功能描述  : Serdes BIST自检函数
 输入参数  : UINT32 uwPort
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年8月16日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_SerdesBist(UINT32 uwPort)
{

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_GmacRst
 功能描述  : GMAC复位
 输入参数  : UINT32 uwGmacId
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年11月5日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GmacRst(UINT32 uwGmacId)
{
    (void)uwGmacId;
#if 0
    SRE_PERCTRL6_U strPerCtrl6;
    SRE_PERCTRL7_U strPerCtrl7;
    SRE_PERCTRL6_U strPerCtrl6_1;
    SRE_PERCTRL7_U strPerCtrl7_1;
    SRE_PERCTRL6_U strPerCtrl6_2;
    SRE_PERCTRL7_U strPerCtrl7_2;
    SRE_PERCTRL6_U strPerCtrl6Rst;
    SRE_PERCTRL7_U strPerCtrl7Rst;
    /*SRE_GMAC_RX_CTRL_U unRxCtrl;*/
    /*SRE_GMAC_CF_CFF_DATA_NUM_U unCffNum;*/
    /*SRE_GMAC_FIFO_CURR_STATUS_U unFifoStatus;*/
   /* SRE_GMAC_DEBUG_ST_MCH_U unStMch;*/
    SRE_PERCTRL69_U unMacRstReq;

    SRE_GeEnableTx(uwGmacId, 1);
    SRE_GeEnableRx(uwGmacId, 0);

#if 0 /*后期需要对这一块进行修改20111117  wuqian */
    /* 禁止向BMU申请buffer */
    SRE_GMAC_READ_REG(uwGmacId, SRE_GMAC_RX_CTRL_REG, unRxCtrl.u32);
    unRxCtrl.bits.cf_rx_cfg_req_en = 0;
    SRE_GMAC_WRITE_REG(uwGmacId, SRE_GMAC_RX_CTRL_REG, unRxCtrl.u32);

step4 :
    do
    {
        SRE_GMAC_READ_REG(uwGmacId, SRE_GMAC_CF_CFF_DATA_NUM_REG, unCffNum.u32);
        if ( 0 != unCffNum.bits.cf_tx_cfg_num )
        {
            if ( uwCfgNum == unCffNum.bits.cf_tx_cfg_num )
            {
                RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
            }
            uwCfgNum = unCffNum.bits.cf_tx_cfg_num ;
            SRE_DelayMs(10);
        }

    } while ( 0 != unCffNum.bits.cf_tx_cfg_num );


    SRE_GMAC_READ_REG(uwGmacId, SRE_GMAC_FIFO_CURR_STATUS_REG, unFifoStatus.u32);
    if ( 1 == unFifoStatus.bits.rff_cf_empty )
    {
        /* 步骤5 */
        SRE_DelayMs(10);
        SRE_GMAC_READ_REG(uwGmacId, SRE_GMAC_DEBUG_ST_MCH_REG, unStMch.u32);
        if ( (0 != unStMch.bits.tx_st_mch) || (0 != unStMch.bits.rx_st_mch))
        {
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }
    }
    else if ( ( 0 == unFifoStatus.bits.rff_cf_empty ) && ( 1 == unFifoStatus.bits.cff_cf_rx_empty ) )
    {
        /* 步骤6 */
        SRE_DelayMs(10);
        SRE_GMAC_READ_REG(uwGmacId, SRE_GMAC_DEBUG_ST_MCH_REG, unStMch.u32);
        if ( (0 != (unStMch.u32 & 0x1ff)) && (0x20 != (unStMch.u32 & 0x1ff)))
        {
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
        }
    }
    else /* ( ( 0 == unFifoStatus.bits.rff_cf_empty ) && ( 0 == unFifoStatus.bits.cff_cf_rx_empty ) )  */
    {
        /* 步骤7 */
        uwCfgNum = 0;
        do
        {
            SRE_GMAC_READ_REG(uwGmacId, SRE_GMAC_CF_CFF_DATA_NUM_REG, unCffNum.u32);
            if ( 0 == unCffNum.bits.cf_rx_cfg_num )
            {
                goto step4;
            }
            else
            {
                SRE_DelayMs(10);
                if ( uwCfgNum == unCffNum.bits.cf_rx_cfg_num )
                {
                    SRE_GMAC_READ_REG(uwGmacId, SRE_GMAC_FIFO_CURR_STATUS_REG, unFifoStatus.u32);
                    if ( 1 == unFifoStatus.bits.rff_cf_empty)
                    {
                        uwCfgNum = 0;
                        goto step4;
                    }
                    else
                    {
                        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
                    }
                }
                uwCfgNum = unCffNum.bits.cf_rx_cfg_num ;
            }
        } while ( 0 != unCffNum.bits.cf_rx_cfg_num );

    }
#endif

    /* 根据复位请求设置寄存器内容 */
    /* rx软复位请求 */
    /* tx软复位请求 */
    /* rx125m软复位请求 */
    /* eth软复位请求 */
    /* sys软复位请求 */

    strPerCtrl6.u32 = 0;
    strPerCtrl7.u32 = 0;
    switch ( uwGmacId )
    {
        case 0 :
            strPerCtrl6.bits.gmac0_eth_srst_req = 1;
            strPerCtrl7.bits.gmac0_sys_srst_req = 1;
            break;
        case 1 :
            strPerCtrl6.bits.gmac1_eth_srst_req = 1;
            strPerCtrl7.bits.gmac1_sys_srst_req = 1;
            break;
        case 2 :
            strPerCtrl6.bits.gmac2_eth_srst_req = 1;
            strPerCtrl7.bits.gmac2_sys_srst_req = 1;
            break;
        case 3 :
            strPerCtrl6.bits.gmac3_eth_srst_req = 1;
            strPerCtrl7.bits.gmac3_sys_srst_req = 1;
            break;
        case 4 :
            strPerCtrl6.bits.gmac4_eth_srst_req = 1;
            strPerCtrl7.bits.gmac4_sys_srst_req = 1;
            break;
        case 5 :
            strPerCtrl6.bits.gmac5_eth_srst_req = 1;
            strPerCtrl7.bits.gmac5_sys_srst_req = 1;
            break;
        case 6 :
            strPerCtrl6.bits.gmac6_eth_srst_req = 1;
            strPerCtrl7.bits.gmac6_sys_srst_req = 1;
            break;
        case 7 :
            strPerCtrl6.bits.gmac7_eth_srst_req = 1;
            strPerCtrl7.bits.gmac7_sys_srst_req = 1;
            break;
        default:
            SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]uwGmacId(%d) Error!"
            "\n[%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, uwGmacId, 0, 0, 0);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    /* 读出相关控制寄存器的内容 */
    strPerCtrl6Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL6_REG, 0);
    strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
    strPerCtrl6Rst.u32 |= strPerCtrl6.u32;
    strPerCtrl7Rst.u32 |= strPerCtrl7.u32;

    /* 把更新后的内容写入相关的控制寄存器 */
    OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);
    OS_WRITE_REG(SRE_SYS_PERCTRL6_REG, 0, strPerCtrl6Rst.u32);

    strPerCtrl6_1.u32 = strPerCtrl6.u32;
    strPerCtrl7_1.u32 = strPerCtrl7.u32;

    /* 步骤 10	配置MAC_CORE的配置寄存器软复位寄存器为1 */
    unMacRstReq.u32 = OS_READ_REG(SRE_SYS_PERCTRL69_REG, 0);
    unMacRstReq.u32 |= (1 << (19 - uwGmacId));
    OS_WRITE_REG(SRE_SYS_PERCTRL69_REG, 0, unMacRstReq.u32);


    strPerCtrl6.u32 = 0;
    strPerCtrl7.u32 = 0;
    switch ( uwGmacId )
    {
        case 0 :
            strPerCtrl6.bits.gmac0_rx_srst_req = 1;
            strPerCtrl7.bits.gmac0_tx_srst_req = 1;
            break;
        case 1 :
            strPerCtrl6.bits.gmac1_rx_srst_req = 1;
            strPerCtrl7.bits.gmac1_tx_srst_req = 1;
            break;
        case 2 :
            strPerCtrl6.bits.gmac2_rx_srst_req = 1;
            strPerCtrl7.bits.gmac2_tx_srst_req = 1;
            break;
        case 3 :
            strPerCtrl6.bits.gmac3_rx_srst_req = 1;
            strPerCtrl7.bits.gmac3_tx_srst_req = 1;
            break;
        case 4 :
            strPerCtrl7.bits.gmac4_rx_srst_req = 1;
            strPerCtrl7.bits.gmac4_tx_srst_req = 1;
            break;
        case 5 :
            strPerCtrl7.bits.gmac5_rx_srst_req = 1;
            strPerCtrl7.bits.gmac5_tx_srst_req = 1;
            break;
        case 6 :
            strPerCtrl7.bits.gmac6_rx_srst_req = 1;
            strPerCtrl7.bits.gmac6_tx_srst_req = 1;
            break;
        case 7 :
            strPerCtrl7.bits.gmac7_rx_srst_req = 1;
            strPerCtrl7.bits.gmac7_tx_srst_req = 1;
            break;
        default:
            SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]uwGmacId(%d) Error!"
            "\n[%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, uwGmacId, 0, 0, 0);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    /* 读出相关控制寄存器的内容 */
    strPerCtrl6Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL6_REG, 0);
    strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
    strPerCtrl6Rst.u32 |= strPerCtrl6.u32;
    strPerCtrl7Rst.u32 |= strPerCtrl7.u32;

    /* 把更新后的内容写入相关的控制寄存器 */
    OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);
    OS_WRITE_REG(SRE_SYS_PERCTRL6_REG, 0, strPerCtrl6Rst.u32);

    strPerCtrl6_2.u32 = strPerCtrl6.u32;
    strPerCtrl7_2.u32 = strPerCtrl7.u32;

    if ( 0 == uwGmacId )
    {
        strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
        strPerCtrl7Rst.bits.gmac0_rx125m_srst_req = 1;
        OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);
    }
    else if ( 1 == uwGmacId )
    {
        strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
        strPerCtrl7Rst.bits.gmac1_rx125m_srst_req = 1;
        OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);
    }

    /* 解复位 */
    strPerCtrl6Rst.u32 &= (~strPerCtrl6_1.u32);
    strPerCtrl7Rst.u32 &= (~strPerCtrl7_1.u32);
    OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);
    OS_WRITE_REG(SRE_SYS_PERCTRL6_REG, 0, strPerCtrl6Rst.u32);

    unMacRstReq.u32 = OS_READ_REG(SRE_SYS_PERCTRL69_REG, 0);
    unMacRstReq.u32 &= ~(1UL << (19 - uwGmacId));
    OS_WRITE_REG(SRE_SYS_PERCTRL69_REG, 0, unMacRstReq.u32);

    /* 解复位 */
    strPerCtrl6Rst.u32 &= (~strPerCtrl6_2.u32);
    strPerCtrl7Rst.u32 &= (~strPerCtrl7_2.u32);
    OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);
    OS_WRITE_REG(SRE_SYS_PERCTRL6_REG, 0, strPerCtrl6Rst.u32);

    if ( 0 == uwGmacId )
    {
        strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
        strPerCtrl7Rst.bits.gmac0_rx125m_srst_req = 0;
        OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);
    }
    else if ( 1 == uwGmacId )
    {
        strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
        strPerCtrl7Rst.bits.gmac1_rx125m_srst_req = 0;
        OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);
    }
    SRE_DelayMs(10);
#endif

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_SetDuplexType
 功能描述  : 设置双工类型
 输入参数  : UINT32 uwPort
             SRE_DUPLEX_TYPE_E uwDuplexType
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年11月17日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_SetDuplexType(UINT32 uwPort, SRE_DUPLEX_TYPE_E enDuplexType)
{
    SRE_MAC_DUPLEX_TYPE_U unDuplexType;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    /*lint -e685  */
    if ( enDuplexType > SRE_FULL_DUPLEX_MODE )
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] DuplexType exceeds the maximum number!"
            "\nenDuplexType = %d,[%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            OS_ERRNO_GMAC_DUPLEX_TYPE, enDuplexType, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_DUPLEX_TYPE, 0, 0);
    }
    /*lint +e685  */

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_DUPLEX_TYPE_REG, unDuplexType.u32);
    unDuplexType.bits.duplex_type = enDuplexType;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_DUPLEX_TYPE_REG, unDuplexType.u32);

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_GetDuplexType
 功能描述  : 获取双工类型
 输入参数  : UINT32 uwPort
             SRE_DUPLEX_TYPE_E *puwDuplexType
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年11月17日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GetDuplexType(UINT32 uwPort, SRE_DUPLEX_TYPE_E *penDuplexType)
{
    SRE_MAC_DUPLEX_TYPE_U unDuplexType;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC]: Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == penDuplexType)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_DUPLEX_TYPE_REG, unDuplexType.u32);
    *penDuplexType = (SRE_DUPLEX_TYPE_E)unDuplexType.bits.duplex_type;

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_SetPortMode
 功能描述  : 设置端口模式
 输入参数  : UINT32 uwPort
             SRE_PORT_MODE_E enPortMode
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年11月17日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_SetPortMode(UINT32 uwPort, SRE_PORT_MODE_E enPortMode)
{
    SRE_GMAC_PORT_MODE_U unPortMode;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if ( enPortMode > GMAC_1000M_SGMII )
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] PortMode exceeds the maximum number!"
            "\nenPortMode = %d,[%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            OS_ERRNO_GMAC_PORT_MODE, enPortMode, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_MODE, 0, 0);
    }

    /*设置端口模式*/
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_PORT_MODE_REG, unPortMode.u32);
    unPortMode.bits.port_mode = enPortMode;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_PORT_MODE_REG, unPortMode.u32);
    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_GetPortMode
 功能描述  : 获取端口模式
 输入参数  : UINT32 uwPort
             SRE_PORT_MODE_E *penPortMode
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年11月17日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GetPortMode(UINT32 uwPort, SRE_PORT_MODE_E *penPortMode)
{
    SRE_GMAC_PORT_MODE_U unPortMode;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == penPortMode)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    /*设置端口模式*/
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_PORT_MODE_REG, unPortMode.u32);
    *penPortMode = (SRE_PORT_MODE_E)unPortMode.bits.port_mode;
    return OS_SUCCESS;
}

UINT32 SRE_GeSetPortCfg(MCSS_CMD_GMAC_SET_PORT_ST *pstCmdGmacSetPort)
{
    UINT32 uwRtn;

    if(pstCmdGmacSetPort->port >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    /* 双工模式 */

    uwRtn = SRE_SetDuplexType(pstCmdGmacSetPort->port, (SRE_DUPLEX_TYPE_E)pstCmdGmacSetPort->duplex_type);
    if(OS_SUCCESS != uwRtn)
    {
        return uwRtn;
    }

    /* 速率 */
    uwRtn = SRE_SetPortMode(pstCmdGmacSetPort->port, (SRE_PORT_MODE_E)pstCmdGmacSetPort->speed);
    if(OS_SUCCESS != uwRtn)
    {
        return uwRtn;
    }

    /* 自协商使能 */
    uwRtn = SRE_AnModeSet(pstCmdGmacSetPort->port, pstCmdGmacSetPort->autoneg_en);
    if(OS_SUCCESS != uwRtn)
    {
        return uwRtn;
    }

    /* 自协商模式 */
    uwRtn = SRE_AnTypeSet(pstCmdGmacSetPort->port, (MCSS_AUTONEG_MODE_E *)&pstCmdGmacSetPort->autoneg_mode);
    if(OS_SUCCESS != uwRtn)
    {
        return uwRtn;
    }

    return OS_SUCCESS;
}

UINT32 SRE_GeGetPortCfg(MCSS_CMD_GMAC_SET_PORT_ST *pstCmdGmacSetPort)
{
    UINT32 uwRtn;

    if(pstCmdGmacSetPort->port >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    /* 双工模式 */

    uwRtn = SRE_GetDuplexType(pstCmdGmacSetPort->port, (SRE_DUPLEX_TYPE_E *)&pstCmdGmacSetPort->duplex_type);
    if(OS_SUCCESS != uwRtn)
    {
        return uwRtn;
    }

    /* 速率 */
    uwRtn = SRE_GetPortMode(pstCmdGmacSetPort->port, (SRE_PORT_MODE_E *)&pstCmdGmacSetPort->speed);
    if(OS_SUCCESS != uwRtn)
    {
        return uwRtn;
    }

    /* 自协商使能 */
    uwRtn = SRE_AnModeGet(pstCmdGmacSetPort->port, (UINT32 *)&pstCmdGmacSetPort->autoneg_en);
    if(OS_SUCCESS != uwRtn)
    {
        return uwRtn;
    }

    /* 自协商模式 */
    uwRtn = SRE_AnTypeGet(pstCmdGmacSetPort->port, (MCSS_AUTONEG_MODE_E *)&pstCmdGmacSetPort->autoneg_mode);
    if(OS_SUCCESS != uwRtn)
    {
        return uwRtn;
    }

    return OS_SUCCESS;
}

UINT32 SRE_GeGetPortAuNegState(UINT32 uwPort, UINT32 *puwAnNegState)
{
    SRE_GMAC_AN_NEG_STATE_U unAnState;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC]: Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == puwAnNegState)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_AN_NEG_STATE_REG, unAnState.u32);

    *puwAnNegState = unAnState.u32;

    return OS_SUCCESS;
}


/*****************************************************************************
 函 数 名  : SRE_GetAnLinkState
 功能描述  : 获取自协商link状态
 输入参数  : UINT32 uwPort
             UINT32 *puwLinkState
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年11月17日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GetAnLinkState(UINT32 uwPort, UINT32 *puwLinkState)
{
    SRE_GMAC_AN_NEG_STATE_U unAnState;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC]: Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == puwLinkState)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_AN_NEG_STATE_REG, unAnState.u32);

    /* BEGIN: Added by c00111586, 2011/7/28   问题单号:DTS2011072603695  */
    /* 查看自协商是否已完成 */
    if ( 1 != unAnState.bits.an_done)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Auto-negotiate is not complete!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_AN_NOT_COMPLETE, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_AN_NOT_COMPLETE, 0, 0);
    }
    /* END:   Added by c00111586, 2011/7/28 */

    *puwLinkState = unAnState.bits.np_link_ok;
    return OS_SUCCESS;
}
/*****************************************************************************
 函 数 名  : SRE_GetAnSpeed
 功能描述  : 获取自协商速度
 输入参数  : UINT32 uwPort
             SRE_AN_NEG_SPEED_E *penAnSpeed
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年11月17日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GetAnSpeed(UINT32 uwPort, SRE_AN_NEG_SPEED_E *penAnSpeed)
{
    SRE_GMAC_AN_NEG_STATE_U unAnState;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC]: Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == penAnSpeed)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_AN_NEG_STATE_REG, unAnState.u32);
    *penAnSpeed = (SRE_AN_NEG_SPEED_E)unAnState.bits.speed;
    return OS_SUCCESS;
}
/*****************************************************************************
 函 数 名  : SRE_SetAnNegInfo
 功能描述  : 设置自协商配置信息
 输入参数  : UINT32 uwPort
             SRE_GMAC_TX_LOCAL_PAGE_U *punAnNegInfo
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年11月17日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_SetAnNegInfo(UINT32 uwPort, SRE_GMAC_TX_LOCAL_PAGE_U *punAnNegInfo)
{
    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC]: Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == punAnNegInfo)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_TX_LOCAL_PAGE_REG, punAnNegInfo->u32);

    return OS_SUCCESS;
}

/* BEGIN: Added by c00111586, 2011/7/28   问题单号:DTS2011072603695  */
/*****************************************************************************
 函 数 名  : SRE_UpdateAnLinkTime
 功能描述  : 更新自协商链接时间，单位为32个125M时钟周期
 输入参数  : UINT32 uwPort
             UINT32 uwAnLinkTime
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年7月28日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_UpdateAnLinkTime(UINT32 uwPort, UINT32 uwAnLinkTime)
{
    SRE_GMAC_SIXTEEN_BIT_CNTR_U unAnLinkTime;
    SRE_GMAC_LD_LINK_COUNTER_U unAnLdLinkCnt;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC]: Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwAnLinkTime > 0xffffUL)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC]: illegal uwAnNegLinkTime value(%d): use"
            "\n1-0xffff [%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_AN_LINK_TIME_ILLEGAL, uwAnLinkTime, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_AN_LINK_TIME_ILLEGAL, 0, 0);
    }

    /* 自协商链接时间更新寄存器
       当该寄存器配置由0变成1时，0x01CC的自协商链接时间寄存器sixteen_bit_cntr
       才会生效 */
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_LD_LINK_COUNTER_REG, unAnLdLinkCnt.u32);
    unAnLdLinkCnt.bits.ld_link_counter = 0UL;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_LD_LINK_COUNTER_REG, unAnLdLinkCnt.u32);

    /* 步骤 1	配置自协商链接时间寄存器 SIXTEEN_BIT_CNTR [sixteen_bit_cntr]（
       基地址0x30000000+1000*ch_num，偏移地址为0x01CC，Bit[15:0]）为16’h3F
       。 */
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_SIXTEEN_BIT_CNTR_REG, unAnLinkTime.u32);
    unAnLinkTime.bits.sixteen_bit_cntr = uwAnLinkTime;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_SIXTEEN_BIT_CNTR_REG, unAnLinkTime.u32);

    /* 步骤 2	配置自协商链接时间更新寄存器LD_LINK_COUNTER [ld_link_counter]
       （基地址0x30000000+1000*ch_num，偏移地址为0x01D0，Bit[1]）为1。 */
    unAnLdLinkCnt.bits.ld_link_counter = 0x1UL;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_LD_LINK_COUNTER_REG, unAnLdLinkCnt.u32);

    return OS_SUCCESS;
}
/* END:   Added by c00111586, 2011/7/28 */
/*****************************************************************************
 函 数 名  : SRE_GetAnNegInfo
 功能描述  : 获取自协商配置信息
 输入参数  : UINT32 uwPort
             SRE_GMAC_TX_LOCAL_PAGE_U *punAnNegInfo
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年11月17日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GetAnNegInfo(UINT32 uwPort, SRE_GMAC_TX_LOCAL_PAGE_U *punAnNegInfo)
{
    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC]: Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == punAnNegInfo)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_LOCAL_PAGE_REG, punAnNegInfo->u32);
    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_ReadGmacStatRegs
 功能描述  : 读网口统计寄存器信息
 输入参数  : SRE_GMAC_STAT_S *pstrGmacStatInfo
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年12月9日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_ReadGmacStatRegs(SRE_GMAC_STAT_S *pstrGmacStatInfo)
{
    UINT32 uwIdx;

    if ( NULL == pstrGmacStatInfo )
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    for ( uwIdx = 0 ; uwIdx < SRE_GE_MAX_BUSINESS_PORT_NUM ; uwIdx++, pstrGmacStatInfo++ )
    {
        /*RX COUNT*/
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_UC_PKTS_REG, pstrGmacStatInfo->uwrx_uc_pkts_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_MC_PKTS_REG, pstrGmacStatInfo->uwrx_mc_pkts_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_BC_PKTS_REG, pstrGmacStatInfo->uwrx_bc_pkts_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_TAGGED_REG, pstrGmacStatInfo->uwrx_vlan_pkt_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_PAUSE_MACCONTROL_FRAMCOUNTER_REG, pstrGmacStatInfo->uwrx_fw_ctrl_frame_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_OCTETS_TOTAL_OK_REG, pstrGmacStatInfo->uwrx_octets_total_ok_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_OCTETS_BAD_REG, pstrGmacStatInfo->uwrx_octets_bad_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_OCTETS_TOTAL_FILT_REG, pstrGmacStatInfo->uwrx_octets_total_filt_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_FILT_PKT_CNT_REG, pstrGmacStatInfo->uwrx_filt_pkt_cnt);

        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_PKTS_64OCTETS_REG, pstrGmacStatInfo->uwrx_framsize_64);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_PKTS_65TO127OCTETS_REG, pstrGmacStatInfo->uwrx_framsize_65_127);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_PKTS_128TO255OCTETS_REG, pstrGmacStatInfo->uwrx_framsize_128_255);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_PKTS_255TO511OCTETS_REG, pstrGmacStatInfo->uwrx_framsize_256_511);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_PKTS_512TO1023OCTETS_REG, pstrGmacStatInfo->uwrx_framsize_512_1023);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_PKTS_1024TO1518OCTETS_REG, pstrGmacStatInfo->uwrx_framsize_1024_1518);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_PKTS_1519TOMAXOCTETS_REG, pstrGmacStatInfo->uwrx_framsize_bt_1518);

        /*RX ERROR COUNT*/
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_LONG_ERRORS_REG, pstrGmacStatInfo->uwrx_frame_long_err_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_VERY_LONG_ERR_CNT_REG, pstrGmacStatInfo->uwrx_frame_very_long_err_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_RUNT_ERR_CNT_REG, pstrGmacStatInfo->uwrx_frame_runt_err_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_SHORT_ERR_CNT_REG, pstrGmacStatInfo->uwrx_frame_short_err_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_OVERRUN_CNT_REG, pstrGmacStatInfo->uwrx_overrun_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_FCS_ERRORS_REG, pstrGmacStatInfo->uwrx_fcs_error_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_DATA_ERR_REG, pstrGmacStatInfo->uwrx_data_error_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_RX_ALIGN_ERRORS_REG, pstrGmacStatInfo->uwrx_align_error_cnt);

        /*TX COUNT*/
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_TX_UC_PKTS_REG, pstrGmacStatInfo->uwtx_uc_pkts_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_TX_MC_PKTS_REG, pstrGmacStatInfo->uwtx_mc_pkts_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_TX_BC_PKTS_REG, pstrGmacStatInfo->uwtx_bc_pkts_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_TX_TAGGED_REG, pstrGmacStatInfo->uwtx_vlan_pkt_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_TX_PAUSE_FRAMES_REG, pstrGmacStatInfo->uwtx_fw_ctrl_frame_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_OCTETS_TRANSMITTED_OK_REG, pstrGmacStatInfo->uwtx_octets_total_ok_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_OCTETS_TRANSMITTED_BAD_REG, pstrGmacStatInfo->uwtx_octets_bad_cnt);

        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_TX_PKTS_64OCTETS_REG, pstrGmacStatInfo->uwtx_framsize_64);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_TX_PKTS_65TO127OCTETS_REG, pstrGmacStatInfo->uwtx_framsize_65_127);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_TX_PKTS_128TO255OCTETS_REG, pstrGmacStatInfo->uwtx_framsize_128_255);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_TX_PKTS_255TO511OCTETS_REG, pstrGmacStatInfo->uwtx_framsize_256_511);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_TX_PKTS_512TO1023OCTETS_REG, pstrGmacStatInfo->uwtx_framsize_512_1023);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_TX_PKTS_1024TO1518OCTETS_REG, pstrGmacStatInfo->uwtx_framsize_1024_1518);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_TX_PKTS_1519TOMAXOCTETS_REG, pstrGmacStatInfo->uwtx_framsize_bt_1518);

        /*TX ERROR COUNT*/
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_TX_CRC_ERROR_REG, pstrGmacStatInfo->uwtx_fcs_error_cnt);
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_TX_UNDERRUN_REG, pstrGmacStatInfo->uwtx_underrun_err_cnt);

        /*RX DROP COUNT*/

        /*TX DROP COUNT*/
        SRE_GMAC_READ_REG(uwIdx, SRE_GMAC_TX_EXCESSIVE_LENGTH_DROP_REG, pstrGmacStatInfo->uwtx_excessive_drop_cnt);
    }
    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_ChangePortMode
 功能描述  : 改变端口模式接口，网口初始化完成后，如果要改变双工模式，端口模
             式，必须使用该接口
 输入参数  : UINT32 uwPort
             SRE_DUPLEX_TYPE_E enDuplexType
             SRE_PORT_MODE_E enPortMode
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年12月24日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_ChangePortMode(UINT32 uwPort, SRE_DUPLEX_TYPE_E enDuplexType, SRE_PORT_MODE_E enPortMode)
{
    UINT32 uwRtn;
    SRE_GMAC_MODE_CHANGE_EN_U unModeChangeEn;
    SRE_PERCTRL69_U unMacRstReq;
    SRE_GMAC_PORT_MODE_U unPortMode;
    SRE_PERCTRL6_U strPerCtrl6;
    SRE_PERCTRL7_U strPerCtrl7;
    SRE_PERCTRL6_U strPerCtrl6_1;
    SRE_PERCTRL7_U strPerCtrl7_1;
    SRE_PERCTRL6_U strPerCtrl6_2;
    SRE_PERCTRL7_U strPerCtrl7_2;
    SRE_PERCTRL6_U strPerCtrl6Rst;
    SRE_PERCTRL7_U strPerCtrl7Rst;

    /* 步骤 1	配置端口通道使能寄存器 先关闭发送再关闭接收*/
    uwRtn = SRE_GeEnableTx(uwPort, 0);
    if ( OS_SUCCESS != uwRtn )
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: SRE_GeEnableTx failed!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, uwRtn, 0, 0, 0, 0);
        return uwRtn;
    }

    uwRtn = SRE_GeEnableRx(uwPort, 0);
    if ( OS_SUCCESS != uwRtn )
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: SRE_GeEnableRx failed!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, uwRtn, 0, 0, 0, 0);
        return uwRtn;
    }

    /* 步骤 2	配置全双工半双工模式寄存器为对接PHY的双工模式 */
    uwRtn = SRE_SetDuplexType(uwPort, enDuplexType);
    if ( OS_SUCCESS != uwRtn )
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: SRE_SetDuplexType failed!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, uwRtn, 0, 0, 0, 0);
        return uwRtn;
    }

    /* 步骤 3	配置端口模式寄存器为对接PHY的工作模式 */
    uwRtn = SRE_SetPortMode(uwPort, enPortMode);
    if ( OS_SUCCESS != uwRtn )
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: SRE_SetPortMode failed!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, uwRtn, 0, 0, 0, 0);
        return uwRtn;
    }

    /* 步骤 4	配置端口模式寄存器 RGMII模式是否delay取决于PHY是否配置了delay模式*/
    if ((enPortMode >= GMAC_10M_RGMII) && (enPortMode <= GMAC_1000M_RGMII))
    {
        SRE_GMAC_READ_REG(uwPort, SRE_GMAC_PORT_MODE_REG, unPortMode.u32);
        unPortMode.bits.rgmii_1000m_delay = 1;
        SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_PORT_MODE_REG, unPortMode.u32);
    }

    /* 步骤 5	配置端口模式改变使能寄存器 */
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_MODE_CHANGE_EN_REG, unModeChangeEn.u32);
    unModeChangeEn.bits.mode_change_en = 1;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_MODE_CHANGE_EN_REG, unModeChangeEn.u32);

    /* 步骤 6	配置MAC_CORE的应用侧时钟软复位寄存器为1 */
    unMacRstReq.u32 = OS_READ_REG(SRE_SYS_PERCTRL69_REG, 0);
    unMacRstReq.u32 |= (1 << (9 - uwPort));
    OS_WRITE_REG(SRE_SYS_PERCTRL69_REG, 0, unMacRstReq.u32);

    /* 步骤 7	配置MAC的工作时钟软复位寄存器为1。 */
    strPerCtrl6.u32 = 0;
    strPerCtrl7.u32 = 0;
    switch ( uwPort )
    {
        case 0 :
            strPerCtrl6.bits.gmac0_eth_srst_req = 1;
            strPerCtrl7.bits.gmac0_tx_srst_req = 1;
            break;
        case 1 :
            strPerCtrl6.bits.gmac1_eth_srst_req = 1;
            strPerCtrl7.bits.gmac1_tx_srst_req = 1;
            break;
        case 2 :
            strPerCtrl6.bits.gmac2_eth_srst_req = 1;
            strPerCtrl7.bits.gmac2_tx_srst_req = 1;
            break;
        case 3 :
            strPerCtrl6.bits.gmac3_eth_srst_req = 1;
            strPerCtrl7.bits.gmac3_tx_srst_req = 1;
            break;
        case 4 :
            strPerCtrl6.bits.gmac4_eth_srst_req = 1;
            strPerCtrl7.bits.gmac4_tx_srst_req = 1;
            break;
        case 5 :
            strPerCtrl6.bits.gmac5_eth_srst_req = 1;
            strPerCtrl7.bits.gmac5_tx_srst_req = 1;
            break;
        case 6 :
            strPerCtrl6.bits.gmac6_eth_srst_req = 1;
            strPerCtrl7.bits.gmac6_tx_srst_req = 1;
            break;
        case 7 :
            strPerCtrl6.bits.gmac7_eth_srst_req = 1;
            strPerCtrl7.bits.gmac7_tx_srst_req = 1;
            break;
        default:
            SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]uwPort(%d) Error!"
            "\n[%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, uwPort, 0, 0, 0);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    /* 读出相关控制寄存器的内容 */
    strPerCtrl6Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL6_REG, 0);
    strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
    strPerCtrl6Rst.u32 |= strPerCtrl6.u32;
    strPerCtrl7Rst.u32 |= strPerCtrl7.u32;

    /* 把更新后的内容写入相关的控制寄存器 */
    OS_WRITE_REG(SRE_SYS_PERCTRL6_REG, 0, strPerCtrl6Rst.u32);

    /* 步骤 8	配置MAC的发送方向SERDES的时钟软复位寄存器为1。 */
    OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);

    strPerCtrl6_1.u32 = strPerCtrl6.u32;
    strPerCtrl7_1.u32 = strPerCtrl7.u32;

    /* 步骤 9	配置MAC的接收方向SERDES时钟软复位寄存器为1。 */
    strPerCtrl6.u32 = 0;
    strPerCtrl7.u32 = 0;
    switch ( uwPort )
    {
        case 0 :
            strPerCtrl6.bits.gmac0_rx_srst_req = 1;
            break;
        case 1 :
            strPerCtrl6.bits.gmac1_rx_srst_req = 1;
            break;
        case 2 :
            strPerCtrl6.bits.gmac2_rx_srst_req = 1;
            break;
        case 3 :
            strPerCtrl6.bits.gmac3_rx_srst_req = 1;
            break;
        case 4 :
            strPerCtrl7.bits.gmac4_rx_srst_req = 1;
            break;
        case 5 :
            strPerCtrl7.bits.gmac5_rx_srst_req = 1;
            break;
        case 6 :
            strPerCtrl7.bits.gmac6_rx_srst_req = 1;
            break;
        case 7 :
            strPerCtrl7.bits.gmac7_rx_srst_req = 1;
            break;
        default:
            SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]uwPort(%d) Error!"
            "\n[%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, uwPort, 0, 0, 0);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    /* 读出相关控制寄存器的内容 */
    strPerCtrl6Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL6_REG, 0);
    strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
    strPerCtrl6Rst.u32 |= strPerCtrl6.u32;
    strPerCtrl7Rst.u32 |= strPerCtrl7.u32;

    /* 把更新后的内容写入相关的控制寄存器 */
    OS_WRITE_REG(SRE_SYS_PERCTRL6_REG, 0, strPerCtrl6Rst.u32);
    OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);

    strPerCtrl6_2.u32 = strPerCtrl6.u32;
    strPerCtrl7_2.u32 = strPerCtrl7.u32;

    /* 步骤 10	配置MAC的RGMII接收方向时钟软复位寄存器为1。 */
    if ( 0 == uwPort )
    {
        strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
        strPerCtrl7Rst.bits.gmac0_rx125m_srst_req = 1;
        OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);
    }
    else if ( 1 == uwPort )
    {
        strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
        strPerCtrl7Rst.bits.gmac1_rx125m_srst_req = 1;
        OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);
    }

    /* 步骤 11	配置MAC_CORE的应用侧时钟软复位寄存器为0。 */
    unMacRstReq.u32 = OS_READ_REG(SRE_SYS_PERCTRL69_REG, 0);
    unMacRstReq.u32 &= ~(1UL << (9 - uwPort));
    OS_WRITE_REG(SRE_SYS_PERCTRL69_REG, 0, unMacRstReq.u32);

    /* 步骤 12	配置MAC的工作时钟软复位寄存器为0。 */
    /* 解复位 */
    strPerCtrl6Rst.u32 &= (~strPerCtrl6_1.u32);
    strPerCtrl7Rst.u32 &= (~strPerCtrl7_1.u32);
    OS_WRITE_REG(SRE_SYS_PERCTRL6_REG, 0, strPerCtrl6Rst.u32);

    /* 步骤 13	配置MAC的发送方向SERDES的时钟软复位寄存器为0。 */
    OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);

    /* 步骤 14	配置MAC的接收方向SERDES时钟软复位寄存器为0。 */
    /* 解复位 */
    strPerCtrl6Rst.u32 &= (~strPerCtrl6_2.u32);
    strPerCtrl7Rst.u32 &= (~strPerCtrl7_2.u32);
    OS_WRITE_REG(SRE_SYS_PERCTRL6_REG, 0, strPerCtrl6Rst.u32);
    OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);

    /* 步骤 15	配置MAC的RGMII接收方向时钟软复位寄存器为0。 */
    if ( 0 == uwPort )
    {
        strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
        strPerCtrl7Rst.bits.gmac0_rx125m_srst_req = 0;
        OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);
    }
    else if ( 1 == uwPort )
    {
        strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
        strPerCtrl7Rst.bits.gmac1_rx125m_srst_req = 0;
        OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);
    }

    /* 步骤 16	配置端口通道使能寄存器 打开发送，打开接收 */
    uwRtn = SRE_GeEnableTx(uwPort, 1);
    if ( OS_SUCCESS != uwRtn )
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: SRE_GeEnableTx failed!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, uwRtn, 0, 0, 0, 0);
        return uwRtn;
    }
    uwRtn = SRE_GeEnableRx(uwPort, 1);
    if ( OS_SUCCESS != uwRtn )
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: SRE_GeEnableRx failed!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, uwRtn, 0, 0, 0, 0);
        return uwRtn;
    }

    return OS_SUCCESS;

}
/*****************************************************************************
 函 数 名  : SRE_InitGeReg
 功能描述  : 初始化GE模式设置
 输入参数  : UINT32 uwPort
             SRE_DUPLEX_TYPE_E enDuplexType
             SRE_PORT_MODE_E enPortMode
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :
 修改历史      :

  1.日    期   : 2012年03月21日
    作    者   : w00200395
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_InitGeReg(UINT32 uwPort, SRE_DUPLEX_TYPE_E enDuplexType, SRE_PORT_MODE_E enPortMode)
{
    UINT32 uwRtn;
    SRE_GMAC_MODE_CHANGE_EN_U unModeChangeEn;
    //SRE_PERCTRL69_U unMacRstReq;
    SRE_GMAC_PORT_MODE_U unPortMode;
    //SRE_PERCTRL6_U strPerCtrl6;
    //SRE_PERCTRL7_U strPerCtrl7;
    //SRE_PERCTRL6_U strPerCtrl6_1;
    //SRE_PERCTRL7_U strPerCtrl7_1;
    //SRE_PERCTRL6_U strPerCtrl6_2;
    //SRE_PERCTRL7_U strPerCtrl7_2;
    //SRE_PERCTRL6_U strPerCtrl6Rst;
    //SRE_PERCTRL7_U strPerCtrl7Rst;

    /* 步骤 1	配置端口通道使能寄存器 先关闭发送再关闭接收*/
    uwRtn = SRE_GeEnableTx(uwPort, 0);
    if ( OS_SUCCESS != uwRtn )
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: SRE_GeEnableTx failed!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, uwRtn, 0, 0, 0, 0);
        return uwRtn;
    }

    uwRtn = SRE_GeEnableRx(uwPort, 0);
    if ( OS_SUCCESS != uwRtn )
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: SRE_GeEnableRx failed!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, uwRtn, 0, 0, 0, 0);
        return uwRtn;
    }

    /* 步骤 2	配置全双工半双工模式寄存器为对接PHY的双工模式 */
    uwRtn = SRE_SetDuplexType(uwPort, enDuplexType);
    if ( OS_SUCCESS != uwRtn )
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: SRE_SetDuplexType failed!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, uwRtn, 0, 0, 0, 0);
        return uwRtn;
    }

    /* 步骤 3	配置端口模式寄存器 */
    uwRtn = SRE_SetPortMode(uwPort, enPortMode);
    if ( OS_SUCCESS != uwRtn )
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: SRE_SetPortMode failed!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, uwRtn, 0, 0, 0, 0);
        return uwRtn;
    }

    /* 步骤 4	配置端口模式寄存器 RGMII模式是否delay */
    if ((enPortMode >= GMAC_10M_RGMII) && (enPortMode <= GMAC_1000M_RGMII))
    {
        SRE_GMAC_READ_REG(uwPort, SRE_GMAC_PORT_MODE_REG, unPortMode.u32);
        unPortMode.bits.rgmii_1000m_delay = 1;
        SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_PORT_MODE_REG, unPortMode.u32);
    }

    /* 步骤 5	配置端口模式改变使能寄存器 */
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_MODE_CHANGE_EN_REG, unModeChangeEn.u32);
    unModeChangeEn.bits.mode_change_en = 1;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_MODE_CHANGE_EN_REG, unModeChangeEn.u32);
#if 0
    /* 步骤 6	配置MAC_CORE的应用侧时钟软复位寄存器为1 */
    unMacRstReq.u32 = OS_READ_REG(SRE_SYS_PERCTRL69_REG, 0);
    unMacRstReq.u32 |= (1 << (9 - uwPort));
    OS_WRITE_REG(SRE_SYS_PERCTRL69_REG, 0, unMacRstReq.u32);

    /* 步骤 7	配置MAC的工作时钟软复位寄存器为1。 */
    strPerCtrl6.u32 = 0;
    strPerCtrl7.u32 = 0;
    switch ( uwPort )
    {
        case 0 :
            strPerCtrl6.bits.gmac0_eth_srst_req = 1;
            strPerCtrl7.bits.gmac0_tx_srst_req = 1;
            break;
        case 1 :
            strPerCtrl6.bits.gmac1_eth_srst_req = 1;
            strPerCtrl7.bits.gmac1_tx_srst_req = 1;
            break;
        case 2 :
            strPerCtrl6.bits.gmac2_eth_srst_req = 1;
            strPerCtrl7.bits.gmac2_tx_srst_req = 1;
            break;
        case 3 :
            strPerCtrl6.bits.gmac3_eth_srst_req = 1;
            strPerCtrl7.bits.gmac3_tx_srst_req = 1;
            break;
        case 4 :
            strPerCtrl6.bits.gmac4_eth_srst_req = 1;
            strPerCtrl7.bits.gmac4_tx_srst_req = 1;
            break;
        case 5 :
            strPerCtrl6.bits.gmac5_eth_srst_req = 1;
            strPerCtrl7.bits.gmac5_tx_srst_req = 1;
            break;
        case 6 :
            strPerCtrl6.bits.gmac6_eth_srst_req = 1;
            strPerCtrl7.bits.gmac6_tx_srst_req = 1;
            break;
        case 7 :
            strPerCtrl6.bits.gmac7_eth_srst_req = 1;
            strPerCtrl7.bits.gmac7_tx_srst_req = 1;
            break;
        default:
            SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]uwPort(%d) Error!"
            "\n[%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, uwPort, 0, 0, 0);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    /* 读出相关控制寄存器的内容 */
    strPerCtrl6Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL6_REG, 0);
    strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
    strPerCtrl6Rst.u32 |= strPerCtrl6.u32;
    strPerCtrl7Rst.u32 |= strPerCtrl7.u32;

    /* 把更新后的内容写入相关的控制寄存器 */
    OS_WRITE_REG(SRE_SYS_PERCTRL6_REG, 0, strPerCtrl6Rst.u32);

    /* 步骤 8	配置MAC的发送方向SERDES的时钟软复位寄存器为1。 */
    OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);

    strPerCtrl6_1.u32 = strPerCtrl6.u32;
    strPerCtrl7_1.u32 = strPerCtrl7.u32;

    /* 步骤 9	配置MAC的接收方向SERDES时钟软复位寄存器为1。 */
    strPerCtrl6.u32 = 0;
    strPerCtrl7.u32 = 0;
    switch ( uwPort )
    {
        case 0 :
            strPerCtrl6.bits.gmac0_rx_srst_req = 1;
            break;
        case 1 :
            strPerCtrl6.bits.gmac1_rx_srst_req = 1;
            break;
        case 2 :
            strPerCtrl6.bits.gmac2_rx_srst_req = 1;
            break;
        case 3 :
            strPerCtrl6.bits.gmac3_rx_srst_req = 1;
            break;
        case 4 :
            strPerCtrl7.bits.gmac4_rx_srst_req = 1;
            break;
        case 5 :
            strPerCtrl7.bits.gmac5_rx_srst_req = 1;
            break;
        case 6 :
            strPerCtrl7.bits.gmac6_rx_srst_req = 1;
            break;
        case 7 :
            strPerCtrl7.bits.gmac7_rx_srst_req = 1;
            break;
        default:
            SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]uwPort(%d) Error!"
            "\n[%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, uwPort, 0, 0, 0);
            RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    /* 读出相关控制寄存器的内容 */
    strPerCtrl6Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL6_REG, 0);
    strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
    strPerCtrl6Rst.u32 |= strPerCtrl6.u32;
    strPerCtrl7Rst.u32 |= strPerCtrl7.u32;

    /* 把更新后的内容写入相关的控制寄存器 */
    OS_WRITE_REG(SRE_SYS_PERCTRL6_REG, 0, strPerCtrl6Rst.u32);
    OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);

    strPerCtrl6_2.u32 = strPerCtrl6.u32;
    strPerCtrl7_2.u32 = strPerCtrl7.u32;

    /* 步骤 10	配置MAC的RGMII接收方向时钟软复位寄存器为1。 */
    if ( 0 == uwPort )
    {
        strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
        strPerCtrl7Rst.bits.gmac0_rx125m_srst_req = 1;
        OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);
    }
    else if ( 1 == uwPort )
    {
        strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
        strPerCtrl7Rst.bits.gmac1_rx125m_srst_req = 1;
        OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);
    }

    /* 步骤 11	配置MAC_CORE的应用侧时钟软复位寄存器为0。 */
    unMacRstReq.u32 = OS_READ_REG(SRE_SYS_PERCTRL69_REG, 0);
    unMacRstReq.u32 &= ~(1UL << (9 - uwPort));
    OS_WRITE_REG(SRE_SYS_PERCTRL69_REG, 0, unMacRstReq.u32);

    /* 步骤 12	配置MAC的工作时钟软复位寄存器为0。 */
    /* 解复位 */
    strPerCtrl6Rst.u32 &= (~strPerCtrl6_1.u32);
    strPerCtrl7Rst.u32 &= (~strPerCtrl7_1.u32);
    OS_WRITE_REG(SRE_SYS_PERCTRL6_REG, 0, strPerCtrl6Rst.u32);

    /* 步骤 13	配置MAC的发送方向SERDES的时钟软复位寄存器为0。 */
    OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);

    /* 步骤 14	配置MAC的接收方向SERDES时钟软复位寄存器为0。 */
    /* 解复位 */
    strPerCtrl6Rst.u32 &= (~strPerCtrl6_2.u32);
    strPerCtrl7Rst.u32 &= (~strPerCtrl7_2.u32);
    OS_WRITE_REG(SRE_SYS_PERCTRL6_REG, 0, strPerCtrl6Rst.u32);
    OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);

    /* 步骤 15	配置MAC的RGMII接收方向时钟软复位寄存器为0。 */
    if ( 0 == uwPort )
    {
        strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
        strPerCtrl7Rst.bits.gmac0_rx125m_srst_req = 0;
        OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);
    }
    else if ( 1 == uwPort )
    {
        strPerCtrl7Rst.u32 = OS_READ_REG(SRE_SYS_PERCTRL7_REG, 0);
        strPerCtrl7Rst.bits.gmac1_rx125m_srst_req = 0;
        OS_WRITE_REG(SRE_SYS_PERCTRL7_REG, 0, strPerCtrl7Rst.u32);
    }
#endif
	/* 步骤 16	配置端口通道使能寄存器 打开发送，打开接收 */
	/* 暂不执行，留给调用它的函数执行 */
    return OS_SUCCESS;

}

/*****************************************************************************
 函 数 名  : SRE_CheckGmacPortCfg
 功能描述  : 检查gmac端口配置
 输入参数  : UINT32 uwPort
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年3月4日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_CheckGmacPortCfg(UINT32 uwPort)
{
#if 0
    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    /* 判断配置的POOL ID 是否合法,检查小 pool 的配置 */
    if (OS_UNLIKELY((SRE_MEM_POOL_MAX_NUM <= g_astSreGmacCfg[uwPort].uwGmacSmallPool)
        || (0 == SRE_GetPoolBlockSize(g_astSreGmacCfg[uwPort].uwGmacSmallPool))))
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC]: the uwPoolID is invalid!"
            "\n P0=%d,P1=%d,P2=%d,P3=%d.(%s,L%d,B0x%x,E0x%x@VCPU%d)",
            OS_ERRNO_GMAC_POOL_CFG, 0, 0, 0, 0);
        return  OS_ERRNO_GMAC_POOL_CFG;
    }

    /* 检查大 pool 的配置 */
    if (SRE_GMAC_INVALID_POOL_ID != g_astSreGmacCfg[uwPort].uwGmacBigPool)
    {
        if (OS_UNLIKELY((SRE_MEM_POOL_MAX_NUM <= g_astSreGmacCfg[uwPort].uwGmacBigPool)
            || (0 == SRE_GetPoolBlockSize(g_astSreGmacCfg[uwPort].uwGmacBigPool))))
        {
            SRE_HIGMAC_ERROR("\n[SRE_HIGMAC]: the uwPoolID is invalid!"
                "\n P0=%d,P1=%d,P2=%d,P3=%d.(%s,L%d,B0x%x,E0x%x@VCPU%d)",
                OS_ERRNO_GMAC_POOL_CFG, 0, 0, 0, 0);
            return  OS_ERRNO_GMAC_POOL_CFG;
        }
    }
#endif
    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_SetFcTxTmr
 功能描述  : 设置流控帧发送时间参数
 输入参数  : UINT32 uwPort
             UINT32 uwFcTxTmr
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年3月12日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_SetFcTxTmr(UINT32 uwPort, UINT32 uwFcTxTmr)
{
    SRE_GMAC_FC_TX_TIMER_U unTxTimer;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if ( uwFcTxTmr > 0xffff )
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC] uwFcTxTmr exceeds the maximum: 0xffff!"
            "\nuwFcTxTmr = %d [%d,%d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            OS_ERRNO_GMAC_FC_TX_TMR, uwFcTxTmr, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_FC_TX_TMR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_FC_TX_TIMER_REG, unTxTimer.u32);
    unTxTimer.bits.fc_tx_timer = uwFcTxTmr;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_FC_TX_TIMER_REG, unTxTimer.u32);

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_GetFcTxTmr
 功能描述  : 获取流控帧发送时间参数
 输入参数  : UINT32 uwPort
             UINT32 *puwFcTxTmr
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年3月12日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GetFcTxTmr(UINT32 uwPort, UINT32 *puwFcTxTmr)
{
    SRE_GMAC_FC_TX_TIMER_U unTxTimer;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HIGMAC]: Port exceeds the maximum number!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PORT_ID, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(NULL == puwFcTxTmr)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC]: Input pointer NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_NULL_PTR, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_NULL_PTR, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_FC_TX_TIMER_REG, unTxTimer.u32);
    *puwFcTxTmr = unTxTimer.bits.fc_tx_timer;

    return OS_SUCCESS;
}


/*****************************************************************************
 函 数 名  : SRE_CheckPerfMonitorCfg
 功能描述  : 检查性能监测配置是否非法
 输入参数  : VOID
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年4月14日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_CheckPerfMonitorCfg(VOID)
{
	/* BEGIN: Modified by f63884, 2012/8/14 */
	#if 0
    if ( gstrMcPerfCfg.uwHitRate > 100)
    {
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if ( gstrMcPerfCfg.uwPoeOverLoadThr > 20000)
    {
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if ( gstrMcPerfCfg.uwPoeRecoverThr < 1)
    {
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }

    if ( 0 == (gstrMcPerfCfg.uwPortMsk & 0xff))
    {
        RETURN_ERROR(__LINE__, OS_FAIL, 0, 0);
    }
	#endif
	/* END:   Modified by f63884, 2012/8/14 */
    return OS_SUCCESS;

}

/*****************************************************************************
 函 数 名  : SRE_PerfMonitorInit
 功能描述  : 性能监测初始化
 输入参数  : VOID
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年4月15日
    作    者   : chenxin
    修改内容   : 新生成函数

*****************************************************************************/
VOID SRE_PerfMonitorInit(VOID)
{
#if 0
    UINT32 uwIdx;
    UINT32 uwRtn;
    UINT32 uwPortMsk;          /* 过载时反压端口号掩码 */

    uwRtn = SRE_CheckPerfMonitorCfg();
    if ( OS_SUCCESS != uwRtn )
    {
        SRE_printf("\nSRE_CheckPerfMonitorCfg failed!");
        return;
    }

    SRE_MemSet((VOID*)&gstrMcPerf, 0, sizeof(SRE_GMAC_PERF_S));

    uwPortMsk = gstrMcPerfCfg.uwPortMsk;

    /* 计算配置的端口号 */
    for ( uwIdx = 0 ; uwIdx < SRE_GE_MAX_BUSINESS_PORT_NUM; uwIdx++ )
    {
        if ( uwPortMsk & (1UL << uwIdx) )
        {
            gstrMcPerf.auwPort[gstrMcPerf.uwPortSum] = uwIdx;
            gstrMcPerf.uwPortSum++;
        }
    }

    /* 获取端口对应的pool */
    gstrMcPerf.uwPool = g_astSreGmacCfg[gstrMcPerf.auwPort[0]].uwGmacSmallPool;

    /* 获取使用的pool配置的buffer总数 */
    gstrMcPerf.uwPoolTotalNum = gastrMcMemPoolCfg[gstrMcPerf.uwPool].uwBlockNums;

    /* 获取timebase频率 */
    gstrMcPerf.uwTimeBaseRate = SRE_GetLocalTimeBaseRate();

    /* 计算查询周期的tick数 */
    gstrMcPerf.uwlIntervalTick = ((UINT64)gstrMcPerfCfg.uwPeriod * (UINT32)(gstrMcPerf.uwTimeBaseRate / 1000));
#endif
    return;
}

/*****************************************************************************
 函 数 名  : SRE_PerMonitor
 功能描述  : 性能监测
 输入参数  : VOID
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年4月14日
    作    者   : c00111586
    修改内容   : 新生成函数

*****************************************************************************/
VOID SRE_PerfMonitor(VOID)
{
#if 0
    /* BEGIN: Modified by c00111586, 2011/4/27   问题单号:DTS2011042603592 */
    UINT64 uwlCurTick;
    /* END:   Modified by c00111586, 2011/4/27 */

    UINT32 uwHitRate;          /* cache命中率 这里的值不包含 "%" */
    UINT32 uwPoeOverLoadThr;   /* POE中缓存的报文个数检测过载门限 */
    UINT32 uwPoeRecoverThr;    /* POE中缓存的报文个数检测恢复门限 */
    UINT32 uwPoePktNum;
    UINT32 uwCurHitRate;
    UINT32 uwPoolCnt;
    UINT32 uwIdx;
    UINT32 uwBmuIntEn;
    UINT32 uwDataHit;
    UINT32 uwDataAcc;
    UINT32 uwOddHit;
    UINT32 uwOddAcc;

    /* 获取当前tick值 */
    uwlCurTick = SRE_GetLocalTimeBase();

    /* 计算是否到达监测时间 */
    if((uwlCurTick - gstrMcPerf.uwlTick) >= gstrMcPerf.uwlIntervalTick)
    {
        /* 读出配置接口的变量，优点: 降低性能损耗，缺点: 不能动态设置 */
        uwHitRate = gstrMcPerfCfg.uwHitRate;
        uwPoeOverLoadThr = gstrMcPerfCfg.uwPoeOverLoadThr;
        uwPoeRecoverThr = gstrMcPerfCfg.uwPoeRecoverThr;

        /* 更新监测时基 */
        gstrMcPerf.uwlTick = uwlCurTick;

        /* 计算Cache命中率 */
        uwDataHit = OS_READ_REG(SRE_L2_DATA_RD_HIT_REG, 0);
        uwDataAcc = OS_READ_REG(SRE_L2_DATA_RD_CNT_REG, 0);
        uwDataHit = 0xffffffffUL - uwDataHit;
        uwDataAcc  = 0xffffffffUL - uwDataAcc;

        /*更新统计*/
        gstrMcPerf.uwL2Cnt[0] = uwDataHit;
        gstrMcPerf.uwL2Cnt[1] = uwDataAcc;

        /* 检测端口是否处于流控状态 */
        if ( 1 == gstrMcPerf.uwFlowCtrlFlg )
        {
            /*检测POE中报文个数*/
            uwPoePktNum = SRE_GetPoePktNum();

            /* 如果POE中报文个数低于恢复门限，清除端口强制流控 */
            if ( uwPoePktNum > uwPoeRecoverThr )
            {
                /* BEGIN: Modified by chenxin, 2011/4/22   问题单号:DTS2011042102894  */
                /* 清除BMU空中断标志，指示空中断已被处理 */
                gpstrMcBlkmemShare->uwMcBmuEmptyFlg = 0;

                /* 使能BMU空中断使能 */
                uwBmuIntEn = OS_READ_REG(SRE_BMU_INT_EN,0);
                uwBmuIntEn |= (1UL << 10);
                OS_WRITE_REG((UINT32*)SRE_BMU_INT_EN, 0, uwBmuIntEn);
                /* END:   Modified by chenxin, 2011/4/22 */
                return;
            }

            /*如果采用gmac反压，停止pause帧  */
            for ( uwIdx = 0 ; uwIdx < gstrMcPerf.uwPortSum ; uwIdx++ )
            {
                SRE_GMAC_WRITE_REG(gstrMcPerf.auwPort[uwIdx], SRE_GMAC_PAUSE_EN_REG,
                    gstrMcPerf.auwPauseEn[uwIdx]);
                SRE_SetCfTxPause(gstrMcPerf.auwPort[uwIdx],0);
            }

            /* 退出流控状态 */
            gstrMcPerf.uwFlowCtrlFlg = 0;
        }
        else    /* 如果不在流控状态 */
        {
            /* 检查是否有BMU的空中断 */
            if ( 1 != gpstrMcBlkmemShare->uwMcBmuEmptyFlg )
            {
                if (uwDataHit > gstrMcPerf.uwL2Cnt[0])
                {
                    uwOddHit  = uwDataHit - gstrMcPerf.uwL2Cnt[0];
                }
                else
                {
                    uwOddHit  =  uwDataHit + (0xffffffff - gstrMcPerf.uwL2Cnt[0]);
                }

                if (uwDataAcc > gstrMcPerf.uwL2Cnt[1])
                {
                    uwOddAcc  = uwDataAcc - gstrMcPerf.uwL2Cnt[1];
                }
                else
                {
                    uwOddAcc  = uwDataAcc + (0xffffffff - gstrMcPerf.uwL2Cnt[1]);
                }

                uwCurHitRate = (uwOddHit * 100)/uwOddAcc;

                if ( uwCurHitRate > uwHitRate )
                {
                    return;
                }

                /* 获取pool的buffer个数 */
                uwPoolCnt = (UINT32)SRE_GetPoolCnt(gstrMcPerf.uwPool);
                if ((uwPoolCnt << 1) > gstrMcPerf.uwPoolTotalNum )
                {
                    return;
                }
            }

            /*检测POE中报文个数*/
            uwPoePktNum = SRE_GetPoePktNum();

            /* 如果POE中报文个数低于恢复门限，清除端口强制流控 */
            if ( uwPoePktNum < uwPoeOverLoadThr)
            {
                /* BEGIN: Modified by chenxin, 2011/4/22   问题单号:DTS2011042102894  */
                /* 清除BMU空中断标志，指示空中断已被处理 */
                gpstrMcBlkmemShare->uwMcBmuEmptyFlg = 0;

                /* 使能BMU空中断使能 */
                uwBmuIntEn = OS_READ_REG(SRE_BMU_INT_EN,0);
                uwBmuIntEn |= (1UL << 10);
                OS_WRITE_REG((UINT32*)SRE_BMU_INT_EN, 0, uwBmuIntEn);
                /* END:   Modified by chenxin, 2011/4/22 */
                return;
            }

            /* 强制发送流控帧 */
            for ( uwIdx = 0 ; uwIdx < gstrMcPerf.uwPortSum ; uwIdx++ )
            {
                SRE_GMAC_READ_REG(gstrMcPerf.auwPort[uwIdx], SRE_GMAC_PAUSE_EN_REG,
                    gstrMcPerf.auwPauseEn[uwIdx]);
                SRE_GmacPauseFrmCfg(gstrMcPerf.auwPort[uwIdx],1,1);
                SRE_SetCfTxPause(gstrMcPerf.auwPort[uwIdx],1);
            }

            /* 进入流控状态 */
            gstrMcPerf.uwFlowCtrlFlg = 1;
        }

        /* 清除BMU空中断标志，指示空中断已被处理 */
        gpstrMcBlkmemShare->uwMcBmuEmptyFlg = 0;

        /* 使能BMU空中断使能 */
        uwBmuIntEn = OS_READ_REG(SRE_BMU_INT_EN,0);
        uwBmuIntEn |= (1UL << 10);
        OS_WRITE_REG((UINT32*)SRE_BMU_INT_EN, 0, uwBmuIntEn);
    }
#endif
    return;
}

/*****************************************************************************
 函 数 名  : SRE_LocalMacAddrEn
 功能描述  : 与XGE共用的本地不带掩码的mac地址使能31-0bit对应
                            31-0个本地mac地址
 输入参数  : uwMacAddrEn
 输出参数  : 无
 返 回 值  : UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年11月11日
    作    者   : wuqian 00163512
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GeEnLocalMacAddr( UINT32 uwPort, UINT32 uwMacAddrEn )
{
    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_DMAC_EN_REG, uwMacAddrEn);

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_LocalMacAddrEn
 功能描述  : 与XGE共用的本地带掩码的mac地址使能5-0bit对应
                            5-0个本地带掩码的mac地址
 输入参数  : uwMacAddrEn
 输出参数  : 无
 返 回 值  : UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年11月11日
    作    者   : wuqian 00163512
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GeEnLocalMacAddrMask( UINT32 uwPort, UINT32 uwMacAddrEn )
{
    SRE_GMAC_DMAC_WITH_MSK_EN_U unEnMacAddrWithMsk;
    unEnMacAddrWithMsk.u32 = 0;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwMacAddrEn > SRE_GE_MAC_ADDR_MSK_MAX)
    {
        SRE_HIGMAC_ERROR("\n[SRE_HISGMAC] Port mode parameter NULL!"
            "\n[%d,%d, %d, %d] (%s,L%d,B0x%x,E0x%x@VCPU%d)",
            0xffffffff, OS_ERRNO_GMAC_PARA, 0, 0, 0, 0);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PARA, 0, 0);
    }

   unEnMacAddrWithMsk.bits.dmac_with_msk_en = uwMacAddrEn & 0x3f;
   SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_DMAC_EN_REG, unEnMacAddrWithMsk.u32);

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : SRE_GmacCrcAddEn
 功能描述  : GE无损环回使能配置
 输入参数  : UINT32 uwPort
             UINT32 uwEnValue
 输出参数  : 无
 返 回 值  :
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2010年5月17日
    作    者   : wuzhenhua
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 SRE_GeSetNlstEn(UINT32 uwPort, UINT32 uwNlstEn)
{
    SRE_GMAC_TX_LOOP_PKT_PRI_U unGeTxLoopPktPri;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwNlstEn > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }

    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_LOOP_PKT_PRI_REG, unGeTxLoopPktPri.u32);
    unGeTxLoopPktPri.bits.loop_pkt_en = uwNlstEn;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_TX_LOOP_PKT_PRI_REG, unGeTxLoopPktPri.u32);

    return OS_SUCCESS;
}

UINT32 SRE_GeSetNlstPri(UINT32 uwPort, UINT32 uwNlstPri)
{
    SRE_GMAC_TX_LOOP_PKT_PRI_U unGeTxLoopPktPri;

    if(uwPort >= SRE_GE_MAX_BUSINESS_PORT_NUM)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if(uwNlstPri > 1)
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_VALUE_EXCEED_MAX, 0, 0);
    }
    SRE_GMAC_READ_REG(uwPort, SRE_GMAC_TX_LOOP_PKT_PRI_REG, unGeTxLoopPktPri.u32);
    unGeTxLoopPktPri.bits.loop_pkt_hig_pri = uwNlstPri;
    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_TX_LOOP_PKT_PRI_REG, unGeTxLoopPktPri.u32);

    return OS_SUCCESS;
}

UINT32 guwMdioTimeOut = 1000;
UINT32 SRE_GeSetMidoTimeOut(UINT32 uwTimeOut)
{
    guwMdioTimeOut = uwTimeOut;
    return OS_SUCCESS;
}

UINT32 guwCnt;


/*****************************************************************************
 函 数 名  : MDIO_Hi1381_Read
 功能描述  : MDIO读函数，读PHY寄存器的值
 输入参数  : UINT32 uwMdioPort
             UINT32 uwPhyAddr
             UINT32 uwRegAddr
 输出参数  : 无
 返 回 值  : UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年6月5日
    作    者   : g00198889
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 MDIO_Hi1381_Read(UINT32 uwMdioPort, UINT32 uwPhyAddr, UINT32 uwRegAddr,UINT32 *puwRegVal)
{
    MDIO_COMMAND_REG_U      unMdioCmdReg;
    MDIO_RDATA_REG_U        unMdioRDataReg;
    MDIO_STA_REG_U          unMdioStaReg;

    UINT32                  uwTimeCnt = guwMdioTimeOut;
    //UINT32                   lRegVal   = -1;
    //SRE_printf("Read time %d\n",guwCnt);
    guwCnt ++;

    if (uwMdioPort > 2)
    {
        SRE_printf("Wrong mdio port: uwMdioPort(%x)\n", uwMdioPort);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if (uwPhyAddr > MDIO_MAX_PHY_ADDR)
    {
        SRE_printf("Wrong phy address: uwPhyAddr(%x)\n", uwPhyAddr);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if (uwRegAddr > MDIO_MAX_PHY_REG_ADDR)
    {
        SRE_printf("Wrong uwRegAddr address: uwRegAddr(%x)\n", uwRegAddr);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if (NULL == puwRegVal)
    {
        SRE_printf("puwRegVal is NULL\n");
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    /* Step 1; 先判断MDIO_COMMAND_REG的mdio_start位是否为0，因为只有为0的时候，才可以进行读写操作  */
    MDIO_REG_READ(uwMdioPort, MDIO_COMMAND_REG, unMdioCmdReg.u32);
    while (unMdioCmdReg.bits.Mdio_Start)     /* 表示此时正在进行MDIO访问，需要等待50us  */
    {
        SRE_PhyDelayUs(10000);     /* 延时50us,  650 FPGA下该时间不够，所以这里提高了二十倍的延时  */
        uwTimeCnt--;
        MDIO_REG_READ(uwMdioPort, MDIO_COMMAND_REG, unMdioCmdReg.u32);
        if (0 == uwTimeCnt)         /* 表示已经超时，此时应该报错  */
        {
            SRE_printf(" Timeout! MDIO is always busy! MDIO_COMMAND_REG(0x%x) \n", unMdioCmdReg.u32);
            RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
        }
    }

    /* Step 2; 配置命令寄存器，发出读命令  */
    unMdioCmdReg.bits.Mdio_St    = MDIO_ST_CLAUSE_22;       /* 配置当前的mdio为clause22  */
    unMdioCmdReg.bits.Mdio_Op    = MDIO_CLAUSE_22_READ;     /* 配置当前的操作为读操作  */
    unMdioCmdReg.bits.Mdio_Prtad = (UINT16)uwPhyAddr;        /* 当mdio_st为2’b01时，表示要访问的外部的PHY地址  */
    unMdioCmdReg.bits.Mdio_Devad = uwRegAddr;                /* 当mdio_st为2’b01时，表示要访问的外部PHY的寄存器地址  */
    unMdioCmdReg.bits.Mdio_Start = 1;                       /* 启动操作  */
    MDIO_REG_WRITE(uwMdioPort, MDIO_COMMAND_REG, unMdioCmdReg.u32);

    /* Step 3; 查询MDIO_COMMAND_REG的mdio_start位是否为0， 检查此时读命令是否完成  */
    uwTimeCnt = guwMdioTimeOut;
    while (unMdioCmdReg.bits.Mdio_Start)     /* 表示此时正在进行MDIO访问，需要等待50us  */
    {
        SRE_PhyDelayUs(10000);     /* 延时50us,  650 FPGA下该时间不够，所以这里提高了二十倍的延时  */
        uwTimeCnt--;
        MDIO_REG_READ(uwMdioPort, MDIO_COMMAND_REG, unMdioCmdReg.u32);
        if (0 == uwTimeCnt)         /* 表示已经超时，此时应该报错  */
        {
            SRE_printf(" Timeout! MDIO is always busy! MDIO_COMMAND_REG(0x%x) \n", unMdioCmdReg.u32);
            RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
        }
    }

    MDIO_REG_READ(uwMdioPort, MDIO_STA_REG, unMdioStaReg.u32);
    if (unMdioStaReg.bits.Mdio_Sta) /* 表示读操作异常  */
    {
        SRE_printf(" ERROR! MDIO Read failed!\n");
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    /* Step 4; 读出数据  */
    MDIO_REG_READ(uwMdioPort, MDIO_RDATA_REG, unMdioRDataReg.u32);
    *puwRegVal = unMdioRDataReg.bits.Mdio_Rdata;

    return OS_SUCCESS;
}

/*****************************************************************************
 函 数 名  : MDIO_Hi1381_Write
 功能描述  : MDIO写函数，往PHY寄存器写值
 输入参数  : UINT32 uwMdioPort
             UINT32 uwPhyAddr
             UINT32 uwRegAddr
             UINT32 uwValue
 输出参数  : 无
 返 回 值  : UINT32
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年6月5日
    作    者   : g00198889
    修改内容   : 新生成函数

*****************************************************************************/
UINT32 MDIO_Hi1381_Write(UINT32 uwMdioPort, UINT32 uwPhyAddr, UINT32 uwRegAddr, UINT32 uwValue)
{
    MDIO_COMMAND_REG_U      unMdioCmdReg;
    MDIO_WDATA_REG_U        unMdioWDataReg;

    UINT32                  uwTimeCnt     = guwMdioTimeOut;
    UINT32                   uwRet          = MDIO_ERROR;
    //SRE_printf("Write time %d\n",guwCnt);
    guwCnt ++;

    if (uwMdioPort > 2)
    {
        SRE_printf("Wrong mdio port: uwMdioPort(%x)\n", uwMdioPort);
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    if (uwPhyAddr > MDIO_MAX_PHY_ADDR)
    {
        SRE_printf("Wrong phy address\n");
        return uwRet;
    }

    if (uwRegAddr > MDIO_MAX_PHY_REG_ADDR)
    {
        SRE_printf("Wrong reg address\n");
        return uwRet;
    }
/*SRE_printf("%s %d; "" LeoGao mdio0 Here ! \n", __FUNCTION__, __LINE__);  */

    /* Step 1; 先判断MDIO_COMMAND_REG的mdio_start位是否为0，因为只有为0的时候，才可以进行读写操作  */
    MDIO_REG_READ(uwMdioPort, MDIO_COMMAND_REG, unMdioCmdReg.u32);

    while (unMdioCmdReg.bits.Mdio_Start)     /* 表示此时正在进行MDIO访问，需要等待50us  */
    {
        SRE_PhyDelayUs(10000);        /* 延时50us,  650 FPGA下该时间不够，所以这里提高了二十倍的延时      */
        uwTimeCnt--;
        MDIO_REG_READ(uwMdioPort, MDIO_COMMAND_REG, unMdioCmdReg.u32);
        if (0 == uwTimeCnt)         /* 表示已经超时，此时应该报错  */
        {
            SRE_printf(" Timeout! MDIO is always busy! MDIO_COMMAND_REG(0x%x) \n", unMdioCmdReg.u32);
            return uwRet;
        }
    }
/*SRE_printf("%s %d; "" LeoGao mdio1 Here ! \n", __FUNCTION__, __LINE__);  */

    /* Step 2; 将需要写入的值先写入写访问数据寄存器  */
    MDIO_REG_READ(uwMdioPort, MDIO_WDATA_REG, unMdioWDataReg.u32);
    unMdioWDataReg.bits.Mdio_Wdata = uwValue;
    //SRE_printf("%s %d; "" LeoGao mdio2 Here; uwValue = 0x%x ! \n", __FUNCTION__, __LINE__, uwValue);
    MDIO_REG_WRITE(uwMdioPort, MDIO_WDATA_REG, unMdioWDataReg.u32);
    //SRE_printf("%s %d; "" LeoGao mdio3 Here ! \n", __FUNCTION__, __LINE__);

    /* Step 3; 配置写操作命令  */
    unMdioCmdReg.bits.Mdio_St    = MDIO_ST_CLAUSE_22;       /* 配置当前的mdio为clause22  */
    unMdioCmdReg.bits.Mdio_Op    = MDIO_CLAUSE_22_WRITE;    /* 配置当前的操作为写操作  */
    unMdioCmdReg.bits.Mdio_Prtad = (UINT16)uwPhyAddr;        /* 当mdio_st为2’b01时，表示要访问的外部的PHY地址  */
    unMdioCmdReg.bits.Mdio_Devad = uwRegAddr;                /* 当mdio_st为2’b01时，表示要访问的外部PHY的寄存器地址  */
    unMdioCmdReg.bits.Mdio_Start = 1;                       /* 启动操作  */
/*SRE_printf("%s %d; "" LeoGao mdio4 Here ! \n", __FUNCTION__, __LINE__);  */
    MDIO_REG_WRITE(uwMdioPort, MDIO_COMMAND_REG, unMdioCmdReg.u32);
/*SRE_printf("%s %d; "" LeoGao mdio5 Here ! \n", __FUNCTION__, __LINE__);  */

    return OS_SUCCESS;
}

UINT32 SRE_PhyReadReg(UINT32 uwMdioPort, UINT32 uwPhyAddr,UINT32 uwRegPage, UINT32 uwRegAddr, UINT32 *puwValue)
{
    if((uwRegPage > 28) || (uwRegPage == 22))
    {
        ;
    }

    MDIO_Hi1381_Write(uwMdioPort, uwPhyAddr, 22, uwRegPage);
    MDIO_Hi1381_Read(uwMdioPort, uwPhyAddr, uwRegAddr, puwValue);

    return OS_SUCCESS;
}

UINT32 SRE_PhyWriteReg(UINT32 uwMdioPort, UINT32 uwPhyAddr, UINT32 uwRegPage, UINT32 uwRegAddr, UINT32 uwValue)
{
    if((uwRegPage > 28) || (uwRegPage == 22))
    {
        RETURN_ERROR(__LINE__, OS_ERRNO_GMAC_PORT_ID, 0, 0);
    }

    MDIO_Hi1381_Write(uwMdioPort, uwPhyAddr, 22, uwRegPage);
    MDIO_Hi1381_Write(uwMdioPort, uwPhyAddr, uwRegAddr, uwValue);

    return OS_SUCCESS;
}
UINT32 SRE_PhyTestRead(UINT32 uwRegPage, UINT32 uwRegAddr)
{
    UINT32 uwMdioPort = 0;
    UINT32 uwPhyAddr = 0;
    UINT32 uwValue;
    SRE_PhyReadReg(uwMdioPort, uwPhyAddr, uwRegPage, uwRegAddr, &uwValue);
    SRE_printf("\nuwValue = 0x%08x\n",uwValue);

    return OS_SUCCESS;
}

UINT32 SRE_PhyTestWrite(UINT32 uwRegPage, UINT32 uwRegAddr, UINT32 uwValue)
{
    UINT32 uwMdioPort = 0;
    UINT32 uwPhyAddr = 0;

    SRE_PhyWriteReg(uwMdioPort, uwPhyAddr, uwRegPage, uwRegAddr, uwValue);

    return OS_SUCCESS;
}

UINT32 SRE_SetLineLoop(void)
{
    //UINT32 uwReadReg;
    UINT32 uwValue;
    UINT32 uwMdioPort = 0;
    UINT32 uwPhy = 0;
    //UINT32 uwTmpMaxSpeed;
    //UINT32 uwTmpAutoNegEnable;

    /*cancel force link*/
    SRE_PhyReadReg(uwMdioPort, uwPhy, 0, 16, &uwValue);
    uwValue &= ~(1<<10);
    SRE_PhyWriteReg(uwMdioPort, uwPhy, 0, 16, uwValue);

    /*restore auto-negotiate mode */
    #if 0
    uwRet = MARVL88E1512_PHY_QryAutoNeg (uwPhy,&uwTmpMaxSpeed, &uwTmpAutoNegEnable);


    if(g_auwMvl1512PhyAutoNegStateBeforeLoop[uwPhy] != uwTmpAutoNegEnable)
    {
        uwRet = MARVL88E1512_PHY_SetAutoNeg (uwPhy, g_auwMvl1512PhyAutoNegSpeedBeforeLoop[uwPhy], g_auwMvl1512PhyAutoNegStateBeforeLoop[uwPhy]);
    }
    #endif

    /*enable the line side loop,控制line loop的寄存器是 register 21_2 */
    SRE_PhyReadReg(uwMdioPort, uwPhy, 2, 21, &uwValue);
    uwValue |= (1<<14);
    SRE_PhyWriteReg(uwMdioPort, uwPhy, 2, 21, uwValue);


    return OS_SUCCESS;
}

UINT32 SRE_GeFpgaAdapt(UINT32 uwPort)
{
    SRE_SetPortMode(uwPort, GMAC_100M_SGMII);

    SRE_PhyTestWrite(18, 20, 1);
    SRE_PhyTestWrite(18, 20, 0x8001);

    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_TRANSMIT_CONTROL_REG, 0x60);

    return OS_SUCCESS;
}

UINT32 SRE_SamplePhySet(UINT32 uwPort)
{
    SRE_SetPortMode(uwPort, GMAC_1000M_SGMII);

    MAR1512_Write(20, 18, 1);
    MAR1512_Write(20, 18, 0x8001);

    SRE_GMAC_WRITE_REG(uwPort, SRE_GMAC_TRANSMIT_CONTROL_REG, 0x60);
return OS_SUCCESS;
}
#endif
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

