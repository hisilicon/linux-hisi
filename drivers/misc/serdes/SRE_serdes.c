/*******************************************************************
              Copyright 2007 - 2011, Huawei Tech. Co., Ltd.
                      ALL RIGHTS RESERVED

Filename      : SRE_serdes.c
Author        : z00228490
Creation time : 2012/12/27
Description   :
                    serdes 驱动
Version       : 1.0
********************************************************************/

#include "SRE_serdes.h"
#include "SRE_rawmutex.h"
#include "SRE_memmap.h"


/*基地址包含文件定义。*/
#define SYSCTRL_BASE_ADDR                 SRE_SYS_REG_BASEADDR

extern UINT32 osSerdes0InitGe1g25(void);
extern UINT32 osSerdes0InitGe1g25Xaui3g125(void);
extern UINT32 osSerdes0InitGe1g25Xge10g125(void);
extern UINT32 osSerdes1InitGe1G25Srio1g25(void);
extern UINT32 osSerdes1InitXaui3g125(void);
extern UINT32 osSerdes1InitXge10g3125(void);
extern UINT32 osSerdes1InitPcie2g5(void);
extern UINT32 osSerdes1InitPcie5g(void);
extern UINT32 osSerdes1InitPcie8g(void);
extern UINT32 osSerdes2InitGe1g25Srio1g25(void);
extern UINT32 osSerdes2InitSrio2g5(void);
extern UINT32 osSerdes2InitSrio3g125(void);
extern UINT32 osSerdes2InitSrio5g(void);
extern UINT32 osSerdes2InitSrio6g25(void);
extern UINT32 osSerdes2InitPcie2g5(void);
extern UINT32 osSerdes2InitPcie5g(void);
extern UINT32 osSerdes2InitPcie8g(void);
extern UINT32 osSerdes2InitSata1g5(void);
extern UINT32 osSerdes2InitSata3g(void);
extern UINT32 osSerdes2InitSata6g(void);
extern UINT32 osSerdes3InitSrio1g25(void);
extern UINT32 osSerdes3InitSrio2g5(void);
extern UINT32 osSerdes3InitSrio3g125(void);
extern UINT32 osSerdes3InitSrio5g(void);
extern UINT32 osSerdes3InitSrio6g25(void);
extern UINT32 osSerdes3InitPcie5g(void);
extern UINT32 osSerdes0ComCfg(void);
extern UINT32 osSerdes0WaitForPllCfg(void);
extern UINT32 osSerdesWrite( UINT32 ulAddr, UINT32 ulIndex, UINT32 ulMask, UINT32 ulType );
extern void osSerdesBitWrite( UINT32 ulAddr, UINT32 ulOrMask, UINT32 ulAndMask );
extern void osSerdesWait( UINT32 ulLoop );
extern UINT32 osSerdes1PmaLp( UINT32 ulLane, UINT32 ulLpMode );
extern UINT32 osSerdes2PmaLp( UINT32 ulLane, UINT32 ulLpMode );
extern void osSerdes0LowWrite( UINT32 ulAddr, UINT32 ulValue );
extern void osSerdes0HighWrite( UINT32 ulAddr, UINT32 ulValue );
extern void osSerdes1Write( UINT32 ulPage, UINT32 ulType, UINT32 ulOffset, UINT32 ulValue );
extern UINT32 osSerdes1Read( UINT32 ulPage, UINT32 ulType, UINT32 ulOffset );
extern void osSerdes2Write( UINT32 ulPage, UINT32 ulType, UINT32 ulOffset, UINT32 ulValue );
extern UINT32 osSerdes2Read( UINT32 ulPage, UINT32 ulType, UINT32 ulOffset );
extern void    OS_SDS_WRITE_REG ( UINT32 pRegBase, UINT32 ulRegIndex, UINT32  ulValue );


/*宏定义*/
#define SERDES_WART_TIME    0x100000

#define SREDES_LOOP_TIME    0x100000

#define SERDES_DEBUG_OPEN     (0)

UINT32 gulDebugOpen  = 0x0;

#if 0
UINT32 SRE_SerdesInit(void)
{
    UINT32 ulRet = OS_SUCCESS;
    /*
    *该复用关系如下:
    *serdes0-->liane0-->GE4
    *serdes0-->liane1-->GE5
    *serdes0-->liane2-->GE6
    *serdes0-->liane3-->GE7
    *serdes0-->liane4-->GE0
    *serdes0-->liane5-->GE8
    *serdes0-->liane6-->GE2
    *serdes0-->liane7-->GE3
    *serdes1-->liane0-->GE1
    *serdes2-->liane0~3-->srio
    *serdes3-->不用
    */
    (VOID)SRE_RawMutexProtect(SRE_SERDES_INITSAFE_LOCK);

    if (0 == SRE_RawMutexGetFlag(SRE_SERDES_INITSAFE_LOCK))
    {
#if 1
        SRE_printf("==========bugin mutil use===========\n");
        /*1、配置ioctrl0 选择GE复用*/
        OS_SDS_WRITE_REG( IOCTRL0_BASE_ADDR, 0, 0x0 );
        /*2、配置serdes1复用关系*/
        OS_SDS_WRITE_REG( IOCTRL0_BASE_ADDR + 0x4, 0, 0x0 );
        /*3、配置serdes2复用关系*/
        OS_SDS_WRITE_REG( IOCTRL1_BASE_ADDR, 0, 0x00002222 );
        /*4、serdes3暂时不用*/
        /*5、配置GE复用*/
        OS_SDS_WRITE_REG( IOCTRL0_BASE_ADDR + 0x8, 0, 0x1ff );
        /*6、配置SRIO复用*/
        OS_SDS_WRITE_REG( IOCTRL1_BASE_ADDR + 0x8, 0, 0x22 );
        /*配置serdes0apb接口*/
        OS_SDS_WRITE_REG( IOCTRL0_BASE_ADDR + 0x10, 0, 0x11 );
#endif

        SRE_printf("==========bugin osSerdes0InitGe1g25===========\n");
        /*将 serdes0 line0 ~ 7全部初始化为ge/1.25g*/
        ulRet = osSerdes0InitGe1g25();
        //ulRet = osSerdes0InitGe1g25Xge10g125();
        if ( OS_SUCCESS != ulRet )
        {
            SRE_printf( "serdes0 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
            return OS_FAIL;
        }
        SRE_printf("==========bugin osSerdes1InitGe1G25Srio1g25===========\n");
        /*将serdes1 line0 初始化为ge/1.25g*/
        ulRet = osSerdes1InitGe1G25Srio1g25();
        if ( OS_SUCCESS != ulRet )
        {
            SRE_printf( "serdes1 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
            return OS_FAIL;
        }
        SRE_printf("==========bugin osSerdes2InitGe1g25Srio1g25===========\n");
        /*将serdes2初始化为srio/1.25g*/
        //ulRet = osSerdes2InitGe1g25Srio1g25();
        //ulRet = osSerdes2InitSrio3g125();
        ulRet = osSerdes2InitSrio6g25();
        //ulRet = osSerdes2InitSrio5g();
        if ( OS_SUCCESS != ulRet )
        {
            SRE_printf( "serdes2 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
            return OS_FAIL;
        }

        (VOID)SRE_RawMutexSetFlag(SRE_SERDES_INITSAFE_LOCK);
    }
    (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);

    return ulRet;
}
#endif

#if 1
/*
      NOTE: serdes 复用关系配置，仅配置 serdes0，注意物理连线。
 */
SRE_SERDES_CFG gstrSerdesCfg =
{
	/*.enSerdes0InitType = GE,
	  .enSerdes1InitType = GE,
	  .enSerdes2InitType = SRIO,
	  .enSerdes3InitType = NOT_USED,
	  .enSerdes0Speed = S1G25,
	  .enSerdes1Speed = S1G25,
	  .enSerdes2Speed = S6G25,//S3G125,
	  .enSerdes3Speed = S5G,
	 */
	.enSerdes0InitType = GE,
	.enSerdes1InitType = NOT_USED,
	.enSerdes2InitType = NOT_USED,
	.enSerdes3InitType = NOT_USED,
	.enSerdes0Speed = S1G25,
	.enSerdes1Speed = S1G25,
	.enSerdes2Speed = S6G25,//S3G125,
	.enSerdes3Speed = S5G,

};



UINT32 SRE_SerdesInit(VOID)
{
    UINT32 ulRet = OS_SUCCESS;
    (VOID)SRE_RawMutexProtect(SRE_SERDES_INITSAFE_LOCK);

    if (0 == SRE_RawMutexGetFlag(SRE_SERDES_INITSAFE_LOCK))
    {
        /*设置默认参数*/
        OS_SDS_WRITE_REG(IOCTRL0_BASE_ADDR,0x0,0x0);
        OS_SDS_WRITE_REG(IOCTRL0_BASE_ADDR + 0x4,0x0,0x0);
        OS_SDS_WRITE_REG(IOCTRL0_BASE_ADDR + 0x8 ,0x0,0x10000000);
	//OS_SDS_WRITE_REG(IOCTRL1_BASE_ADDR,0x0,0x2222);
	//OS_SDS_WRITE_REG(IOCTRL1_BASE_ADDR + 0x4,0x0,0x0);
	//OS_SDS_WRITE_REG(IOCTRL1_BASE_ADDR + 0x8 ,0x0,0x2E);
        /*配置serdes0apb接口*/
        OS_SDS_WRITE_REG( IOCTRL0_BASE_ADDR + 0x10, 0, 0x11 );
        switch(gstrSerdesCfg.enSerdes0InitType)
        {
            case GE:
                osSerdesBitWrite(IOCTRL0_BASE_ADDR,0x0,0x0);
                osSerdesBitWrite(IOCTRL0_BASE_ADDR + 0x8 ,0x1FD,0xefffffff);
                if(gstrSerdesCfg.enSerdes0Speed == S1G25)
                {
                    ulRet = osSerdes0InitGe1g25();
                    if ( OS_SUCCESS != ulRet )
                    {
                        SRE_printf( "osSerdes0InitGe1g25 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                        (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                        return OS_FAIL;
                    }
                }else
                {
                    SRE_printf("Unsupport Speed! at  GE Speed[%d]\n",gstrSerdesCfg.enSerdes0Speed);
                }
           break;
           case XGE_XAUI:
                osSerdesBitWrite(IOCTRL0_BASE_ADDR,0x11110000,0x1111FFFF);
                osSerdesBitWrite(IOCTRL0_BASE_ADDR + 0x8 ,0x1000F0,0xEEFFFEF2);
                if(gstrSerdesCfg.enSerdes0Speed == S3G125)
                {
                    ulRet = osSerdes0InitGe1g25Xaui3g125();
                    if ( OS_SUCCESS != ulRet )
                    {
                        SRE_printf( "osSerdes0InitGe1g25Xaui3g125 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                        (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                        return OS_FAIL;
                    }
                }else
                {
                    SRE_printf("Unsupport Speed! at  XGE-XAUI Speed[%d]\n",gstrSerdesCfg.enSerdes0Speed);
                }
           break;
           case XGE_SFI:
                osSerdesBitWrite(IOCTRL0_BASE_ADDR,0x22000000,0x22FFFFFF);
                osSerdesBitWrite(IOCTRL0_BASE_ADDR + 0x8 ,0xC0000,0xeFFFFFF3);
                if(gstrSerdesCfg.enSerdes0Speed == S10G3125)
                {
                    ulRet = osSerdes0InitGe1g25Xge10g125();
                    if ( OS_SUCCESS != ulRet )
                    {
                        SRE_printf( "osSerdes0InitGe1g25Xge10g125 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                        (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                        return OS_FAIL;
                    }
                }else
                {
                    SRE_printf("Unsupport Speed! at  XGE-XAUI Speed[%d]\n",gstrSerdesCfg.enSerdes0Speed);
                }
           break;
           case NOT_USED:
           break;
           default:
                SRE_printf("serdes0 unsupport init type\n");
            break;
        }
        switch(gstrSerdesCfg.enSerdes1InitType)
        {
            case GE:
                osSerdesBitWrite(IOCTRL0_BASE_ADDR + 0x4,0x0,0xfffffff0);
                osSerdesBitWrite(IOCTRL0_BASE_ADDR + 0x8 ,0x2,0xFFFFFFFF);
                if(gstrSerdesCfg.enSerdes1Speed == S1G25)
                {
                    ulRet = osSerdes1InitGe1G25Srio1g25();
                    if ( OS_SUCCESS != ulRet )
                    {
                        SRE_printf( "osSerdes1InitGe1G25Srio1g25 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                        (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                        return OS_FAIL;
                    }
                }else
                {
                    SRE_printf( "unspport speed at GE serdes1 at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                    (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                    return OS_FAIL;
                }
                break;
            case XGE_XAUI:
                osSerdesBitWrite(IOCTRL0_BASE_ADDR + 0x4,0x1111,0xffff1111);
                osSerdesBitWrite(IOCTRL0_BASE_ADDR + 0x8 ,0x200000,0xeFFFFFFF);
                if(gstrSerdesCfg.enSerdes1Speed == S3G125)
                {
                    ulRet = osSerdes1InitXaui3g125();
                    if ( OS_SUCCESS != ulRet )
                    {
                        SRE_printf( "osSerdes1InitXaui3g125 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                        (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                        return OS_FAIL;
                    }
                }else
                {
                    SRE_printf("Unsupport Speed! at  XGE-XAUI Speed[%d]\n",gstrSerdesCfg.enSerdes1Speed);
                }
            break;
            case XGE_SFI:
                osSerdesBitWrite(IOCTRL0_BASE_ADDR + 0x4,0x22,0xffffff22);
                osSerdesBitWrite(IOCTRL0_BASE_ADDR + 0x8 ,0x30000,0xeFFFFFFF);
                if(gstrSerdesCfg.enSerdes1Speed == S10G3125)
                {
                    ulRet = osSerdes1InitXge10g3125();
                    if ( OS_SUCCESS != ulRet )
                    {
                        SRE_printf( "osSerdes1InitXge10g3125 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                        (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                        return OS_FAIL;
                    }
                }else
                {
                    SRE_printf("Unsupport Speed! at  XGE-XFI Speed[%d]\n",gstrSerdesCfg.enSerdes1Speed);
                }
            break;
            case PCIE:
                osSerdesBitWrite(IOCTRL0_BASE_ADDR + 0x4,0x0,0xffffffff);
                osSerdesBitWrite(IOCTRL0_BASE_ADDR + 0x8 ,0x10000000,0xFFFFFFFF);
                switch(gstrSerdesCfg.enSerdes1Speed)
                {
                    case S2G5:
                        ulRet = osSerdes1InitPcie2g5();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes1InitPcie2g5 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                    break;
                    case S5G:
                        ulRet = osSerdes1InitPcie5g();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes1InitPcie5g init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                    break;
                    case S8G:
                        ulRet = osSerdes1InitPcie8g();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes1InitPcie8g init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                    break;
                    default:
                        SRE_printf( "serdes 1 unsupport speed\n");
                        (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                        return OS_FAIL;
                }
            break;
            case NOT_USED:
            break;
            default:
                SRE_printf( "serdes 1 unsupport init type\n");
                (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                return OS_FAIL;
        }
        switch(gstrSerdesCfg.enSerdes2InitType)
        {
            case SRIO:
                osSerdesBitWrite(IOCTRL1_BASE_ADDR ,0x2222,0xffff2222);
                osSerdesBitWrite(IOCTRL1_BASE_ADDR + 0x8 ,0x2,0xFFFFFFEF);
                switch(gstrSerdesCfg.enSerdes2Speed)
                {
                    case S1G25:
                        ulRet = osSerdes2InitGe1g25Srio1g25();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes2InitGe1g25Srio1g25 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                    break;
                    case S2G5:
                        ulRet = osSerdes2InitSrio2g5();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes2InitSrio2g5 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                    break;
                    case S3G125:
                        ulRet = osSerdes2InitSrio3g125();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes2InitSrio3g125 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                    break;
                    case S5G:
                        ulRet = osSerdes2InitSrio5g();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes2InitSrio5g init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                    break;
                    case S6G25:
                        ulRet = osSerdes2InitSrio6g25();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes2InitSrio6g25 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                    break;
                    default:
                        SRE_printf( "serdes 2 unsupport speed\n");
                        (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                        return OS_FAIL;
                }
            break;
            case PCIE:
                osSerdesBitWrite(IOCTRL1_BASE_ADDR ,0x0,0xffffffff);
                osSerdesBitWrite(IOCTRL1_BASE_ADDR + 0x8 ,0x0,0xFFFFFFDF);
                switch(gstrSerdesCfg.enSerdes2Speed)
                {
                    case S2G5:
                        ulRet = osSerdes2InitPcie2g5();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes2InitPcie2g5 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                    break;
                    case S5G:
                        ulRet = osSerdes2InitPcie5g();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes2InitPcie5g init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                    break;
                    case S8G:
                        ulRet = osSerdes2InitPcie8g();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes2InitPcie8g init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                    break;
                    default:
                        SRE_printf( "serdes 1 unsupport speed\n");
                        (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                        return OS_FAIL;
                }
            break;
            case SATA:
                osSerdesBitWrite(IOCTRL1_BASE_ADDR ,0x1111,0xffff1111);
                osSerdesBitWrite(IOCTRL1_BASE_ADDR + 0x8 ,0x1,0xFFFFFFFF);
                switch(gstrSerdesCfg.enSerdes2Speed)
                {
                    case S1G5:
                        ulRet = osSerdes2InitSata1g5();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes2InitSata1g5 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                    break;
                    case S3G:
                        ulRet = osSerdes2InitSata3g();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes2InitSata3g init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                    break;
                    case S6G:
                        ulRet = osSerdes2InitSata6g();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes2InitSata6g init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                    break;
                    default:
                        SRE_printf( "serdes 1 unsupport speed\n");
                        (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                        return OS_FAIL;
                }
            break;
            case NOT_USED:
            break;
            default:
                SRE_printf( "serdes 1 unsupport init type\n");
                (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                return OS_FAIL;
        }

        switch(gstrSerdesCfg.enSerdes3InitType)
        {
            case SRIO:
                osSerdesBitWrite(IOCTRL1_BASE_ADDR ,0x11,0xffffff11);
                osSerdesBitWrite(IOCTRL1_BASE_ADDR + 0x8 ,0x12,0xFFFFFFFF);
                switch(gstrSerdesCfg.enSerdes3Speed)
                {
                    case S1G25:
                        ulRet = osSerdes3InitSrio1g25();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes3InitSrio1g25 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                     break;
                     case S2G5:
                        ulRet = osSerdes3InitSrio2g5();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes3InitSrio2g5 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                     break;
                     case S3G125:
                        ulRet = osSerdes3InitSrio3g125();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes3InitSrio3g125 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                     break;
                     case S5G:
                        ulRet = osSerdes3InitSrio5g();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes3InitSrio3g125 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                     break;
                     case S6G25:
                        ulRet = osSerdes3InitSrio6g25();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes3InitSrio6g25 init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                     break;
                     default:
                        SRE_printf( "serdes 1 unsupport speed\n");
                        (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                        return OS_FAIL;
                }
            break;
            case PCIE:
                osSerdesBitWrite(IOCTRL1_BASE_ADDR ,0x0,0xffffff00);
                osSerdesBitWrite(IOCTRL1_BASE_ADDR + 0x8 ,0x2C,0xFFFFFFFF);
                switch(gstrSerdesCfg.enSerdes3Speed)
                {
                    case S5G:
                        ulRet = osSerdes3InitPcie5g();
                        if ( OS_SUCCESS != ulRet )
                        {
                            SRE_printf( "osSerdes3InitPcie5g init error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
                            (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                            return OS_FAIL;
                        }
                    break;
                    default:
                        SRE_printf( "serdes 3 unsupport speed\n");
                        (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                        return OS_FAIL;
                    break;
                }
            break;
            case NOT_USED:
            break;
            default:
                SRE_printf( "serdes 1 unsupport init type\n");
                (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
                return OS_FAIL;
        }
      (VOID)SRE_RawMutexSetFlag(SRE_SERDES_INITSAFE_LOCK);
    }
    (VOID)SRE_RawMutexUnProtect(SRE_SERDES_INITSAFE_LOCK);
    return OS_SUCCESS;
}

#endif


/*****************************************************************
函数名 :  osSerdes0InitGe1g25
输入参数    :   None
输出参数      :
Description   :  2.2.1  Macro0 Lane0~7 初始化为1000BASE-KX
                      初始化GE/1.25G
Author        :  z00228490
Creation time :  2012/12/28
*****************************************************************/
UINT32 osSerdes0InitGe1g25(void)
{
    //UINT32 ulValue = 0;
    UINT32 ulLoop = 0;
    //INT32 ulWaitTime = SERDES_WART_TIME;
    UINT32 ulRet = OS_SUCCESS;

    /*前四步配置统一*/
    ulRet = osSerdes0ComCfg();
    if ( OS_SUCCESS != ulRet )
    {
        return OS_FAIL;
    }
    osSerdes0LowWrite( 0x0, 0x36 );
    osSerdes0LowWrite( 0x4 , 0x26 );
    osSerdes0LowWrite( 0x100 ,0x20010c );


    osSerdes0HighWrite( 0x0, 0x36 );
    osSerdes0HighWrite( 0x4 , 0x26 );
    osSerdes0HighWrite( 0x100 , 0x20010c );
#if 0
    /*Pcie_sel=0*/
    /*Addr[serdes0_low_base_addr+0x4],data[bit8=0]*/
    osSerdesWrite( SERDES0_LOW_BASE_ADDR + 0x4, 0, 0xFFFFFEFF, 1 );

    /*Addr[serdes0_high_base_addr+0x4] ,data[bit8=0]*/
    osSerdesWrite( SERDES0_HIGHT_BASE_ADDR + 0x4, 0, 0xFFFFFEFF, 1 );
#endif
    /*Lane0~3配置chx_tx/rxdatawidth_sel=2, chx_tx/rx_rate_sel=2, */
    /*Lane4~7配置chx_tx/rxdatawidth_sel=1, chx_tx/rx_rate_sel=0*/
    /*Addr[serdes0_low_base_addr+0x81c+0x80*0~3],data[bit7-6=2’b10,bit5-3=3’b11]*/
    /*Addr[serdes0_low_base_addr+0x82c+0x80*0~3],data[bit7-6=2’b10,bit5-3=3’b11]*/
    /*Addr[serdes0_high_base_addr+0x81c+0x80*0~3],data[bit7-6=2’b10,bit5-3=3’b11] */
    /*Addr[serdes0_high_base_addr+0x82c+0x80*0~3],data[bit7-6=2’b10,bit5-3=3’b11]*/
    for ( ulLoop = 0; ulLoop < 4; ulLoop++ )
    {
        osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x81c + 0x80 * ulLoop, 0x98, 0xFFFFFF9F );

        osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x82c + 0x80 * ulLoop, 0x98, 0xFFFFFF9F );

        osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x81c + 0x80 * ulLoop, 0x98, 0xFFFFFF9F );

        osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x82c + 0x80 * ulLoop, 0x98, 0xFFFFFF9F );

    }
/*
SRE_WriteReg 0xe28f2838,0x1b
SRE_WriteReg 0xe28f28b8,0x1b
SRE_WriteReg 0xe28f2938,0x1b
SRE_WriteReg 0xe28f29b8,0x1b
SRE_WriteReg 0xe28f3838,0x1b
SRE_WriteReg 0xe28f38b8,0x1b
SRE_WriteReg 0xe28f3938,0x1b
SRE_WriteReg 0xe28f39b8,0x1b

devmem 0xe28f2838 32 0x1b000000
devmem 0xe28f29b8 32 0x1b000000
*/
	/*osSerdesBitWrite(0xe28f2838, 0x1b, 0xffffffff);
	osSerdesBitWrite(0xe28f28b8, 0x1b, 0xffffffff);
	osSerdesBitWrite(0xe28f2938, 0x1b, 0xffffffff);
	osSerdesBitWrite(0xe28f29b8, 0x1b, 0xffffffff);
	osSerdesBitWrite(0xe28f3838, 0x1b, 0xffffffff);
	osSerdesBitWrite(0xe28f38b8, 0x1b, 0xffffffff);
	osSerdesBitWrite(0xe28f3938, 0x1b, 0xffffffff);
	osSerdesBitWrite(0xe28f39b8, 0x1b, 0xffffffff);
	*/

    osSerdesBitWrite(MDIO_BASE_ADDR + 0x2804,0x0,0xfffffffd);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x2884,0x0,0xfffffffd);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x2904,0x0,0xfffffffd);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x2984,0x0,0xfffffffd);

    osSerdesBitWrite(MDIO_BASE_ADDR + 0x3804,0x0,0xfffffffd);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x3884,0x0,0xfffffffd);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x3904,0x0,0xfffffffd);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x3984,0x0,0xfffffffd);

    osSerdesBitWrite(MDIO_BASE_ADDR + 0x2800,0x5b0f30, 0x5b0f30);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x2880,0x5b0f30, 0x5b0f30);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x2900,0x5b0f30, 0x5b0f30);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x2980,0x5b0f30, 0x5b0f30);

    osSerdesBitWrite(MDIO_BASE_ADDR + 0x3800,0x5b0f30, 0x5b0f30);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x3880,0x5b0f30, 0x5b0f30);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x3900,0x5b0f30, 0x5b0f30);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x3980,0x5b0f30, 0x5b0f30);

    osSerdesBitWrite(MDIO_BASE_ADDR + 0x2808,0x4503030f, 0x4503030f);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x2888,0x4503030f, 0x4503030f);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x2908,0x4503030f, 0x4503030f);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x2988,0x4503030f, 0x4503030f);

    osSerdesBitWrite(MDIO_BASE_ADDR + 0x3808,0x4503030f, 0x4503030f);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x3888,0x4503030f, 0x4503030f);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x3908,0x4503030f, 0x4503030f);
    osSerdesBitWrite(MDIO_BASE_ADDR + 0x3988,0x4503030f, 0x4503030f);

    for(ulLoop = 0;ulLoop<0x4;ulLoop++)
    {
        osSerdes0LowWrite(0x804 + 0x80 * ulLoop,0xf0001);
    }
    for(ulLoop = 0;ulLoop<0x4;ulLoop++)
    {
        osSerdes0HighWrite(0x804 + 0x80 * ulLoop,0xf0001);
    }
    /*等100ns*/
    osSerdesWait( 0x1000000);

    /*等待复位撤离信号*/
    ulRet = osSerdes0WaitForPllCfg();
    if ( OS_SUCCESS != ulRet )
    {
        return OS_FAIL;
    }
    return OS_SUCCESS;

}



/*****************************************************************
函数名 :  osSerdes0InitGe1g25Xaui3g125
输入参数    :   None
输出参数      :
Description   :  Macro0 Lane0~3 初始化为1000BASE-KX，
                    Lane4~7初始化为XAUI

Author        :  z00228490
Creation time :  2012/12/28
*****************************************************************/
UINT32 osSerdes0InitGe1g25Xaui3g125(void)
{
    //UINT32 ulValue = 0;
    UINT32 ulLoop = 0;
    //INT32 ulWaitTime = SERDES_WART_TIME;
    UINT32 ulRet = OS_SUCCESS;
    /*前四步配置统一*/
    ulRet = osSerdes0ComCfg();
    if ( ulRet != OS_SUCCESS )
    {
        return OS_FAIL;
    }
    /*Pcie_sel=0*/
    /*Addr[serdes0_low_base_addr+0x4],data[bit8=0]*/
    osSerdesWrite( SERDES0_LOW_BASE_ADDR + 0x4, 0, 0xFFFFFEFF, 1 );

    /*Addr[serdes0_high_base_addr+0x4] ,data[bit8=0]*/
    osSerdesWrite( SERDES0_HIGHT_BASE_ADDR + 0x4, 0, 0xFFFFFEFF, 1 );

    /*Lane0~3配置chx_tx/rxdatawidth_sel=2, chx_tx/rx_rate_sel=2, */
    /*Lane4~7配置chx_tx/rxdatawidth_sel=1, chx_tx/rx_rate_sel=0*/
    /*Addr[serdes0_low_base_addr+0x81c+0x80*0~3],data[bit7-6=2’b10,bit5-3=3’b10]*/
    /*Addr[serdes0_low_base_addr+0x82c+0x80*0~3],data[bit7-6=2’b10,bit5-3=3’b10]*/
    /*Addr[serdes0_high_base_addr+0x81c+0x80*0~3],data[bit7-6=2’b10,bit5-3=3’b01] */
    /*Addr[serdes0_high_base_addr+0x82c+0x80*0~3],data[bit7-6=2’b10,bit5-3=3’b01]*/
    for ( ulLoop = 0; ulLoop < 4; ulLoop++ )
    {
        osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x81c + 0x80 * ulLoop, 0x90, 0xFFFFFF97 );
        osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x82c + 0x80 * ulLoop, 0x90, 0xFFFFFF97 );
        osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x81c + 0x80 * ulLoop, 0x88, 0xFFFFFF8F );
        osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x82c + 0x80 * ulLoop, 0x88, 0xFFFFFF8F );

    }
    /*Lane0~3配置Pll_prediv=5’h1,pll_postdiv=8’d20*/
    /*Lane4~7配置Pll_prediv=5’h1,pll_postdiv=8’d25*/
    /*Addr[serdes0_low_base_addr+0x100],data[bit12-8=5’h1,bit23-16=8’d20]*/
    /*Addr[serdes0_high_base_addr+0x100],data[bit12-8=5’h1,bit23-16=8’d25]*/
    osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x100, 0x140100, 0xFF14E1FF );
    osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x100, 0x190100, 0xFF19E1FF );

    /*Lane0~3配置Vcofreq=8’h7*/
    /*Lane4~7配置Vcofreq=8’h6*/
    /*Addr[serdes0_low_base_addr+0x108],data[bit31-24=8’h7]*/
    /*Addr[serdes0_high_base_addr+0x108],data[bit31-24=8’h6]*/
    osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x108, 0x7000000, 0x7FFFFFF );
    osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x108, 0x60000000, 0xFFFFFF );

    /*等100ns*/
    osSerdesWait( 0x1000 );

    /*等待复位撤离信号*/
    ulRet = osSerdes0WaitForPllCfg();
    if ( ulRet != OS_SUCCESS )
    {
        return OS_FAIL;
    }
    return ulRet;

}


/*****************************************************************
函数名 :  osSerdes0InitGe1g25Xge10g125
输入参数    :   None
输出参数      :
Description   :  Macro0 Lane0~3 初始化为1000BASE-KX，
                    Lane6~7初始化为XGE2，XGE3

Author        :  z00228490
Creation time :  2012/12/28
*****************************************************************/
UINT32 osSerdes0InitGe1g25Xge10g125(void)
{
    //UINT32 ulValue = 0;
    UINT32 ulLoop = 0;
    //INT32 ulWaitTime = SERDES_WART_TIME;
    UINT32 ulRet = OS_SUCCESS;
    /*前四步配置统一*/
    ulRet = osSerdes0ComCfg();
    if ( ulRet != OS_SUCCESS )
    {
        return OS_FAIL;
    }
    /*Pcie_sel=0*/
    /*Addr[serdes0_low_base_addr+0x4],data[bit8=0]*/
    osSerdesWrite( SERDES0_LOW_BASE_ADDR + 0x4, 0, 0xFFFFFEFF, 1 );

    /*Addr[serdes0_high_base_addr+0x4] ,data[bit8=0]*/
    osSerdesWrite( SERDES0_HIGHT_BASE_ADDR + 0x4, 0, 0xFFFFFEFF, 1 );

    /*Lane0~3配置chx_tx/rxdatawidth_sel=2, chx_tx/rx_rate_sel=2, */
    /*Lane4~7配置chx_tx/rxdatawidth_sel=1, chx_tx/rx_rate_sel=0*/
    /*Addr[serdes0_low_base_addr+0x81c+0x80*0~3],data[bit7-6=2’b10,bit5-3=3’b10]*/
    /*Addr[serdes0_low_base_addr+0x82c+0x80*0~3],data[bit7-6=2’b10,bit5-3=3’b10]*/
    /*Addr[serdes0_high_base_addr+0x81c+0x80*0~3],data[bit7-6=2’b01,bit5-3=3’b0] */
    /*Addr[serdes0_high_base_addr+0x82c+0x80*0~3],data[bit7-6=2’b01,bit5-3=3’b0]*/
    for ( ulLoop = 0; ulLoop < 4; ulLoop++ )
    {
        osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x81c + 0x80 * ulLoop, 0x90, 0xFFFFFF97 );
        osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x82c + 0x80 * ulLoop, 0x90, 0xFFFFFF97 );
        osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x81c + 0x80 * ulLoop, 0x40, 0xFFFFFF47 );
        osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x82c + 0x80 * ulLoop, 0x40, 0xFFFFFF47 );

    }
    /*Lane0~3配置Pll_prediv=5’h1,pll_postdiv=8’d20*/
    /*Lane4~7配置Pll_prediv=5’h1,pll_postdiv=8’d33*/
    /*Addr[serdes0_low_base_addr+0x100],data[bit12-8=5’h1,bit23-16=8’d20]*/
    /*Addr[serdes0_high_base_addr+0x100],data[bit12-8=5’h1,bit23-16=8’d33]*/
    osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x100, 0x140100, 0xFF14E1FF );
    osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x100, 0x210100, 0xFF21E1FF );

    /*Lane0~3配置Vcofreq=8’h7*/
    /*Lane4~7配置Vcofreq=8’h0*/
    /*Addr[serdes0_low_base_addr+0x108],data[bit31-24=8’h7]*/
    /*Addr[serdes0_high_base_addr+0x108],data[bit31-24=8’h0]*/
    osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x108, 0x7000000, 0x7FFFFFF );
    osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x108, 0x0, 0xFFFFFF );

    /*等100ns*/
    osSerdesWait( 0x1000 );

    /*等待复位撤离信号*/
    ulRet = osSerdes0WaitForPllCfg();
    if ( ulRet != OS_SUCCESS )
    {
        return OS_FAIL;
    }
    return ulRet;
}


/*****************************************************************
函数名 :  osSerdes1InitGe1G25Srio1g25
输入参数    :   None
输出参数      :
Description   :  macro1 Lane0~3 初始化为1000BASE-KX /SRIO 1.25G

Author        :  z00228490
Creation time :  2013/1/4
*****************************************************************/
UINT32 osSerdes1InitGe1G25Srio1g25(void)
{


    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = 0x10000000;
    //UINT32 ulRet = OS_SUCCESS;

    //*********************************************************
    //serdes1  initialization
    //*********************************************************
    //1.    POR
    osSerdesBitWrite (SRE_SC_SERDES_RESET_REQ1_REG,0x200,0xffffffff);

    //1(1) set multi-mode:
    osSerdesBitWrite (MDIO_BASE_ADDR + 0x4060,0x1400,0xFFFFF7FF);

    //1(2) set pcie-mode:
    //osSerdesBitWrite (MDIO_BASE_ADDR + 0x4060,0x1c00,0xFFFFFFFF);

    //2.    Release POR
    osSerdesBitWrite (SRE_SC_SERDES_RESET_DREQ1_REG,0x200,0xffffffff);

    osSerdesWait(0x1000000);
    //3.    Enable Hard Reset
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASSEN   7   1
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASSEN_SYNTH 4   1
    //4.    Hard Reset
    //HARDRST.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASS     7   0
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASS_SYNTH   4   0
    osSerdes1Write (0x0,0x0,0x2,0x2);
    osSerdes1Write (0x1,0x0,0x2,0x2);
    osSerdes1Write (0x2,0x0,0x2,0x2);
    osSerdes1Write (0x3,0x0,0x2,0x2);
    osSerdes1Write (0x4,0x0,0x2,0x1);
    osSerdesWait(0x1000000);
    // 5.   Load Different Data Rate Settings
    //1p25Gbps_156p25MHz.memcfg
    //load the 1.25Gbps_156.25MHz_VSM.txt
    osSerdes1Write (0,0,101,183);
    osSerdes1Write (0,0,102,183);
    osSerdes1Write (0,0,103,12);
    osSerdes1Write (0,0,104,12);
    osSerdes1Write (0,0,105,26);
    osSerdes1Write (0,0,106,26);
    osSerdes1Write (0,0,107,2);
    osSerdes1Write (0,0,108,2);
    osSerdes1Write (0,0,109,17);
    osSerdes1Write (0,0,110,13);
    osSerdes1Write (1,0,101,183);
    osSerdes1Write (1,0,102,183);
    osSerdes1Write (1,0,103,12);
    osSerdes1Write (1,0,104,12);
    osSerdes1Write (1,0,105,26);
    osSerdes1Write (1,0,106,26);
    osSerdes1Write (1,0,107,2);
    osSerdes1Write (1,0,108,2);
    osSerdes1Write (1,0,109,17);
    osSerdes1Write (1,0,110,13);
    osSerdes1Write (2,0,101,183);
    osSerdes1Write (2,0,102,183);
    osSerdes1Write (2,0,103,12);
    osSerdes1Write (2,0,104,12);
    osSerdes1Write (2,0,105,26);
    osSerdes1Write (2,0,106,26);
    osSerdes1Write (2,0,107,2);
    osSerdes1Write (2,0,108,2);
    osSerdes1Write (2,0,109,17);
    osSerdes1Write (2,0,110,13);
    osSerdes1Write (3,0,101,183);
    osSerdes1Write (3,0,102,183);
    osSerdes1Write (3,0,103,12);
    osSerdes1Write (3,0,104,12);
    osSerdes1Write (3,0,105,26);
    osSerdes1Write (3,0,106,26);
    osSerdes1Write (3,0,107,2);
    osSerdes1Write (3,0,108,2);
    osSerdes1Write (3,0,109,17);
    osSerdes1Write (3,0,110,13);
    osSerdes1Write (4,0,101,153);
    osSerdes1Write (4,0,102,0);
    osSerdes1Write (4,0,103,108);
    osSerdes1Write (4,0,104,183);
    osSerdes1Write (4,0,105,183);
    osSerdes1Write (4,0,106,12);
    osSerdes1Write (4,0,107,12);
    osSerdes1Write (4,0,108,26);
    osSerdes1Write (4,0,109,26);
    osSerdes1Write (4,0,110,7);
    osSerdes1Write (4,0,111,12);
    osSerdes1Write (4,0,112,8);
    osSerdes1Write (4,0,113,0);
    osSerdes1Write (4,0,114,8);
    osSerdes1Write (4,0,115,0);
    osSerdes1Write (4,0,116,255);
    osSerdes1Write (4,0,117,179);
    osSerdes1Write (4,0,118,246);
    osSerdes1Write (4,0,119,208);
    osSerdes1Write (4,0,120,239);
    osSerdes1Write (4,0,121,251);
    osSerdes1Write (4,0,122,255);
    osSerdes1Write (4,0,123,255);
    osSerdes1Write (4,0,124,255);
    osSerdes1Write (4,0,125,255);
    osSerdes1Write (4,0,126,255);
    osSerdes1Write (4,0,127,211);
    osSerdes1Write (4,0,128,211);
    osSerdes1Write (4,0,129,226);
    osSerdes1Write (4,0,130,239);
    osSerdes1Write (4,0,131,251);
    osSerdes1Write (4,0,132,251);
    osSerdes1Write (4,0,133,255);
    osSerdes1Write (4,0,134,239);
    osSerdes1Write (4,0,135,255);
    osSerdes1Write (4,0,136,255);
    osSerdes1Write (4,0,137,211);
    osSerdes1Write (4,0,138,211);
    osSerdes1Write (4,0,139,226);
    osSerdes1Write (4,0,140,239);
    osSerdes1Write (4,0,141,251);
    osSerdes1Write (4,0,142,251);
    osSerdes1Write (4,0,143,255);
    osSerdes1Write (4,0,144,239);
    osSerdes1Write (4,0,145,255);
    osSerdes1Write (4,0,146,255);
    osSerdes1Write (4,0,147,251);
    osSerdes1Write (4,0,148,255);
    osSerdes1Write (4,0,149,63);
    osSerdes1Write (4,0,150,0);
    osSerdes1Write (4,0,151,100);
    osSerdes1Write (4,0,152,0);
    osSerdes1Write (4,0,153,4);
    osSerdes1Write (4,0,154,2);
    osSerdes1Write (4,0,155,5);
    osSerdes1Write (4,0,156,5);
    osSerdes1Write (4,0,157,4);
    osSerdes1Write (4,0,158,0);
    osSerdes1Write (4,0,159,0);
    osSerdes1Write (4,0,160,8);
    osSerdes1Write (4,0,161,4);
    osSerdes1Write (4,0,162,0);
    osSerdes1Write (4,0,163,0);
    osSerdes1Write (4,0,164,4);
    osSerdes1Write (0,0,7,0);
    osSerdes1Write (1,0,7,0);
    osSerdes1Write (2,0,7,0);
    osSerdes1Write (3,0,7,0);
    osSerdes1Write (4,0,13,16);
    osSerdes1Write (4,0,48,0);
    osSerdes1Write (4,0,49,0);
    osSerdes1Write (4,0,54,0);
    osSerdes1Write (4,0,55,180);
    osSerdes1Write (4,0,93,2);
    osSerdes1Write (4,0,165,2);
    osSerdes1Write (0,0,41,6);
    osSerdes1Write (1,0,41,6);
    osSerdes1Write (2,0,41,6);
    osSerdes1Write (3,0,41,6);
    osSerdes1Write (4,0,354,3);
    osSerdes1Write (4,0,355,58);
    osSerdes1Write (4,0,356,9);
    osSerdes1Write (4,0,357,3);
    osSerdes1Write (4,0,358,62);
    osSerdes1Write (4,0,359,12);
    osSerdes1Write (0,0,701,0);
    osSerdes1Write (1,0,701,0);
    osSerdes1Write (2,0,701,0);
    osSerdes1Write (3,0,701,0);
    osSerdesWait(0x1000000);
    // 6.   Overwrite
    //PCSOVR_ENABLE.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //85[1:1]   LB_LOCWREN  7   0
    //85[4:4]   PCSRX_LOCWREN   7   0
    //85[7:7]   PCSTX_LOCWREN   7   0
    //95[4:4]   CMNPCSBIST_LOCWREN  4   0
    //86[0:0]   PCSTXBIST_LOCWREN   7   0
    //87[5:5]   TXDRV_LOCWREN   7   0
    //86[3:3]   RXCALEQ_LOCWREN 7   0
    //85[5:5]   PCSRXBIST_LOCWREN   7   0
    //95[2:2]   CMNPCIEGEN3_LOCWREN 4   0
    //95[5:5]   CMNPCSPSTATE_LOCWREN    4   0
    //86[4:4]   RXCALEYEDIAGFSMIN_LOCWREN   7   0
    //95[3:3]   CMNPCS_LOCWREN  4   0
    //85[0:0]   LANEPCSPSTATE_LOCWREN   7   0
    //230[0:0]  RXLOCK2REF_LOCWREN  7   0
    osSerdes1Write (0x0,0x0,0x55,0x4c);
    osSerdes1Write (0x0,0x0,0x56,0xe6);
    osSerdes1Write (0x0,0x0,0x57,0x1f);
    osSerdes1Write (0x0,0x0,0xe6,0xfe);

    osSerdes1Write (0x1,0x0,0x55,0x4c);
    osSerdes1Write (0x1,0x0,0x56,0xe6);
    osSerdes1Write (0x1,0x0,0x57,0x1f);
    osSerdes1Write (0x1,0x0,0xe6,0xfe);

    osSerdes1Write (0x2,0x0,0x55,0x4c);
    osSerdes1Write (0x2,0x0,0x56,0xe6);
    osSerdes1Write (0x2,0x0,0x57,0x1f);
    osSerdes1Write (0x2,0x0,0xe6,0xfe);

    osSerdes1Write (0x3,0x0,0x55,0x4c);
    osSerdes1Write (0x3,0x0,0x56,0xe6);
    osSerdes1Write (0x3,0x0,0x57,0x1f);
    osSerdes1Write (0x3,0x0,0xe6,0xfe);

    osSerdes1Write (0x4,0x0,0x5f,0xc3);
    osSerdesWait(0x1000000);
    // 7.   Set to IDDQ state
    //PCSPSTATE_IDDQ.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //3[4:0]    LANEPCSPSTATE_RX    7   1
    //3[4:0]    CMNPCSPSTATE_SYNTH  4   1
    //4[4:0]    LANEPCSPSTATE_TX    7   1
    osSerdes1Write (0x0,0x0,0x3,0x1);
    osSerdes1Write (0x0,0x0,0x4,0x1);

    osSerdes1Write (0x1,0x0,0x3,0x1);
    osSerdes1Write (0x1,0x0,0x4,0x1);

    osSerdes1Write (0x2,0x0,0x3,0x1);
    osSerdes1Write (0x2,0x0,0x4,0x1);

    osSerdes1Write (0x3,0x0,0x3,0x1);
    osSerdes1Write (0x3,0x0,0x4,0x1);

    osSerdes1Write (0x4,0x0,0x3,0x1);
    osSerdesWait(0x1000000);
    // 8.   Release Hard Reset
    //HARDRST_NOT.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASS     7   1
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASS_SYNTH   4   1
    osSerdes1Write (0x0,0x0,0x2,0x3);
    osSerdes1Write (0x1,0x0,0x2,0x3);
    osSerdes1Write (0x2,0x0,0x2,0x3);
    osSerdes1Write (0x3,0x0,0x2,0x3);
    osSerdes1Write (0x4,0x0,0x2,0x3);
    osSerdesWait(0x1000000);
    // 9(1). PRBS pattern
    //TXBIST_PRBS7.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //80[2:0]   CMNPCSBIST_MODESEL  4   1
    //prbs7
    osSerdes1Write (0x4,0x0,0x50,0x1);
    //prbs23
    //osSerdes1Write (0x4,0x0,0x50,0x2);
    //prbs31
    //osSerdes1Write (0x4,0x0,0x50,0x3);
    osSerdesWait(0x1000000);
    // 10.  RXEQ setting
    //RXEQ.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //83[0:0]   RXAGC_DCCOUPLEEN    4   0
    //24[2:0]   RXCALEQ_DCGAIN      7   0
    //27[6:4]   RXCALEQ_LOFREQAGCGAIN   7   7
    //28[7:3]   RXCALEQ_HIFREQAGCCAP    7   0
    //25[2:0]   RXCALEQ_DFEPSTAPGAIN    7   0
    //24[5:3]   RXCALEQ_DFEPSTAPF3DB    7   0
    //25[6:3]   RXCALEQ_DFETAP1GAIN 7   0
    //26[3:0]   RXCALEQ_DFETAP2GAIN 7   8
    //26[7:4]   RXCALEQ_DFETAP3GAIN 7   0
    //27[3:0]   RXCALEQ_DFETAP4GAIN 7   8
    osSerdes1Write (0x0,0x0,0x18,0x0);
    osSerdes1Write (0x0,0x0,0x19,0x0);
    osSerdes1Write (0x0,0x0,0x1a,0x8);
    osSerdes1Write (0x0,0x0,0x1b,0x78);
    osSerdes1Write (0x0,0x0,0x1c,0x0);

    osSerdes1Write (0x1,0x0,0x18,0x0);
    osSerdes1Write (0x1,0x0,0x19,0x0);
    osSerdes1Write (0x1,0x0,0x1a,0x8);
    osSerdes1Write (0x1,0x0,0x1b,0x78);
    osSerdes1Write (0x1,0x0,0x1c,0x0);

    osSerdes1Write (0x2,0x0,0x18,0x0);
    osSerdes1Write (0x2,0x0,0x19,0x0);
    osSerdes1Write (0x2,0x0,0x1a,0x8);
    osSerdes1Write (0x2,0x0,0x1b,0x78);
    osSerdes1Write (0x2,0x0,0x1c,0x0);

    osSerdes1Write (0x3,0x0,0x18,0x0);
    osSerdes1Write (0x3,0x0,0x19,0x0);
    osSerdes1Write (0x3,0x0,0x1a,0x8);
    osSerdes1Write (0x3,0x0,0x1b,0x78);
    osSerdes1Write (0x3,0x0,0x1c,0x0);

    osSerdes1Write (0x4,0x0,0x53,0x2);
    osSerdesWait(0x1000000);
    // 11.  TXIODRIVER setting
    //TXIODRIVER.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //21[2:0]   TXDRV_HLEV  7   7
    //21[7:3]   TXDRV_LEVN  7   1b
    //22[3:0]   TXDRV_LEVNM1    7   0
    //22[5:4]   TXDRV_LEVNM2    7   0
    //23[2:0]   TXDRV_LEVNP1    7   0
    //23[4:3]   TXDRV_SLEW  7   0
    osSerdes1Write (0x0,0x0,0x15,0xdf);
    osSerdes1Write (0x0,0x0,0x16,0x0);
    osSerdes1Write (0x0,0x0,0x17,0x0);

    osSerdes1Write (0x1,0x0,0x15,0xdf);
    osSerdes1Write (0x1,0x0,0x16,0x0);
    osSerdes1Write (0x1,0x0,0x17,0x0);

    osSerdes1Write (0x2,0x0,0x15,0xdf);
    osSerdes1Write (0x2,0x0,0x16,0x0);
    osSerdes1Write (0x2,0x0,0x17,0x0);

    osSerdes1Write (0x3,0x0,0x15,0xdf);
    osSerdes1Write (0x3,0x0,0x16,0x0);
    osSerdes1Write (0x3,0x0,0x17,0x0);
    osSerdesWait(0x1000000);
    // 12.  Change Data Width to 10 bits
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //5[6:4]    PCSTX_DATAWIDTH 7   1
    //5[2:0]    PCSRX_DATAWIDTH 7   1
    osSerdes1Write (0x0,0x0,0x5,0x11);
    osSerdes1Write (0x1,0x0,0x5,0x11);
    osSerdes1Write (0x2,0x0,0x5,0x11);
    osSerdes1Write (0x3,0x0,0x5,0x11);
    osSerdesWait(0x1000000);
    // 13.  Change DIVRATE
    //RXPCSDATARATE_DIV4.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //6[2:0]    PCSRX_DIVRATE   7   1
    //TXPCSDATARATE_DIV4.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //6[6:4]    PCSTX_DIVRATE   7   1
    osSerdes1Write (0x0,0x0,0x6,0x11);
    osSerdes1Write (0x1,0x0,0x6,0x11);
    osSerdes1Write (0x2,0x0,0x6,0x11);
    osSerdes1Write (0x3,0x0,0x6,0x11);
    osSerdesWait(0x1000000);
    // 15.  Enable PCS TX
    //CMNPCS_TXENABLE.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //8[2:2]    CMNPCS_TXENABLE 4   1
    osSerdes1Write (0x4,0x0,0x8,0x54);

    osSerdesWait(0x1000000);
    // 16.  Overwrite Enable for Lock2Ref
    //RXLOCK2REF_OVREN.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //39[1:1]   RXLOCK2REF_OVREN    7   1
    osSerdes1Write (0x0,0x0,0x27,0x2);
    osSerdes1Write (0x1,0x0,0x27,0x2);
    osSerdes1Write (0x2,0x0,0x27,0x2);
    osSerdes1Write (0x3,0x0,0x27,0x2);
    osSerdesWait(0x1000000);
    // 17.  Power Up to P0
    //PCSPSTATE_P0.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //3[4:0]    LANEPCSPSTATE_RX    7   10
    //3[4:0]    CMNPCSPSTATE_SYNTH  4   10
    //4[4:0]    LANEPCSPSTATE_TX    7   10
    osSerdes1Write (0x0,0x0,0x3,0x10);
    osSerdes1Write (0x0,0x0,0x4,0x10);

    osSerdes1Write (0x1,0x0,0x3,0x10);
    osSerdes1Write (0x1,0x0,0x4,0x10);

    osSerdes1Write (0x2,0x0,0x3,0x10);
    osSerdes1Write (0x2,0x0,0x4,0x10);

    osSerdes1Write (0x3,0x0,0x3,0x10);
    osSerdes1Write (0x3,0x0,0x4,0x10);

    osSerdes1Write (0x4,0x0,0x3,0x10);
#if 0
    // 18.  Read out critical status registers
    //PCSOUTTX_READY    7   11[2:2]     r   expected: 1
    //PCSOUTRX_READY    7   11[0:0]     r   expected: 1
    SreShell 1 );osSerdes1Read 0x0,0x0,11);
    SreShell 1 );osSerdes1Read 0x1,0x0,11);
    SreShell 1 );osSerdes1Read 0x2,0x0,11);
    SreShell 1 );osSerdes1Read 0x3,0x0,11);
#endif
    osSerdesWait(0x1000000);

    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl0_base_addr+0x404],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
#if SERDES_DEBUG_OPEN
    SRE_printf( "check IOCTRL0_BASE_ADDR + 0x404 == 0xff0\n" );
#else
    ulValue = ulValue & 0xFF0;
    while ( -- ulWaitTime )
    {
        if( ulValue != 0xFF0 )
        {
            ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
            ulValue = ulValue & 0xFF0;
        }else
        {
            break;
        }
    }
#endif
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;
}


/*****************************************************************
函数名 :  osSerdes1InitSrio2g5
输入参数    :   None
输出参数      :
Description   :  Macro1 Lane0~3 初始化为SRIO 2.5G

Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes1InitSrio2g5(void)
{

    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit9-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0x3FF, 0xFFFFFFFF );

    /*3、设置模式为multi-mode*/
    /*Addr[ioctrl0_base_addr+0x60],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x60, 0x0, 0xFFFFF7FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x200, 0xFFFFFE00 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载1.25Gbps_156.25MHz_VSM.txt配置文件*/
    osSerdes1Write( 0x0, 0x0, 0x65, 0xb7 );
    osSerdes1Write( 0x0, 0x0, 0x66, 0xb7 );
    osSerdes1Write( 0x0, 0x0, 0x67, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x68, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x69, 0x1a );
    osSerdes1Write( 0x0, 0x0, 0x6a, 0x1a );
    osSerdes1Write( 0x0, 0x0, 0x6b, 0x2 );
    osSerdes1Write( 0x0, 0x0, 0x6c, 0x2 );
    osSerdes1Write( 0x0, 0x0, 0x6d, 0x11 );
    osSerdes1Write( 0x0, 0x0, 0x6e, 0xd );
    osSerdes1Write( 0x1, 0x0, 0x65, 0xb7 );
    osSerdes1Write( 0x1, 0x0, 0x66, 0xb7 );
    osSerdes1Write( 0x1, 0x0, 0x67, 0xc );
    osSerdes1Write( 0x1, 0x0, 0x68, 0xc );
    osSerdes1Write( 0x1, 0x0, 0x69, 0x1a );
    osSerdes1Write( 0x1, 0x0, 0x6a, 0x1a );
    osSerdes1Write( 0x1, 0x0, 0x6b, 0x2 );
    osSerdes1Write( 0x1, 0x0, 0x6c, 0x2 );
    osSerdes1Write( 0x1, 0x0, 0x6d, 0x11 );
    osSerdes1Write( 0x1, 0x0, 0x6e, 0xd );
    osSerdes1Write( 0x2, 0x0, 0x65, 0xb7 );
    osSerdes1Write( 0x2, 0x0, 0x66, 0xb7 );
    osSerdes1Write( 0x2, 0x0, 0x67, 0xc );
    osSerdes1Write( 0x2, 0x0, 0x68, 0xc );
    osSerdes1Write( 0x2, 0x0, 0x69, 0x1a );
    osSerdes1Write( 0x2, 0x0, 0x6a, 0x1a );
    osSerdes1Write( 0x2, 0x0, 0x6b, 0x2 );
    osSerdes1Write( 0x2, 0x0, 0x6c, 0x2 );
    osSerdes1Write( 0x2, 0x0, 0x6d, 0x11 );
    osSerdes1Write( 0x2, 0x0, 0x6e, 0xd );
    osSerdes1Write( 0x3, 0x0, 0x65, 0xb7 );
    osSerdes1Write( 0x3, 0x0, 0x66, 0xb7 );
    osSerdes1Write( 0x3, 0x0, 0x67, 0xc );
    osSerdes1Write( 0x3, 0x0, 0x68, 0xc );
    osSerdes1Write( 0x3, 0x0, 0x69, 0x1a );
    osSerdes1Write( 0x3, 0x0, 0x6a, 0x1a );
    osSerdes1Write( 0x3, 0x0, 0x6b, 0x2 );
    osSerdes1Write( 0x3, 0x0, 0x6c, 0x2 );
    osSerdes1Write( 0x3, 0x0, 0x6d, 0x11 );
    osSerdes1Write( 0x3, 0x0, 0x6e, 0xd );
    osSerdes1Write( 0x4, 0x0, 0x65, 0x99 );
    osSerdes1Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x67, 0x6c );
    osSerdes1Write( 0x4, 0x0, 0x68, 0xb7 );
    osSerdes1Write( 0x4, 0x0, 0x69, 0xb7 );
    osSerdes1Write( 0x4, 0x0, 0x6a, 0xc );
    osSerdes1Write( 0x4, 0x0, 0x6b, 0xc );
    osSerdes1Write( 0x4, 0x0, 0x6c, 0x1a );
    osSerdes1Write( 0x4, 0x0, 0x6d, 0x1a );
    osSerdes1Write( 0x4, 0x0, 0x6e, 0x7 );
    osSerdes1Write( 0x4, 0x0, 0x6f, 0xc );
    osSerdes1Write( 0x4, 0x0, 0x70, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x72, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x75, 0xb3 );
    osSerdes1Write( 0x4, 0x0, 0x76, 0xf6 );
    osSerdes1Write( 0x4, 0x0, 0x77, 0xd0 );
    osSerdes1Write( 0x4, 0x0, 0x78, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x79, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x7a, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7f, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x80, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x81, 0xe2 );
    osSerdes1Write( 0x4, 0x0, 0x82, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x83, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x84, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x85, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x86, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x89, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x8a, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x8b, 0xe2 );
    osSerdes1Write( 0x4, 0x0, 0x8c, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x8d, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x8e, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x8f, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x90, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x93, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x94, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes1Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x97, 0x64 );
    osSerdes1Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x99, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0x9a, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes1Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x37, 0xb4 );
    osSerdes1Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes1Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes1Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes1Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes1Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x2bd, 0x0 );

    /*配置并行数据接口的数据位宽和速率*/
    /*Addr[ioctrl0_base_addr+0x64],data[bit31-29=3'b001,*/
    /*bit28-26=3'b001,bit25-23=3'b001,bit22-20=3b001,bit19-17=3b001,*/
    /*bit16-14=3b001,bit13-11=3b001,bit10-8=3b001,bit7-0=all 1]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x64, 0x249249FF, 0x249249FF );

    /*addr[ioctrl0_base_addr+0x68],data[bit31-24=all0,bit23-21=3'b010,*/
    /*bit20-18=3'b010,bit17-15=3'b010,bit14-12=3'b010,bit11-9=3'b010,*/
    /*bit8-6=3'b010,bit5-3=3'b010,bit2-0=3'b010]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x68, 0x492492, 0x492492 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x3ff, 0xffffffff );

    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl0_base_addr+0x404],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;
}


/*****************************************************************
函数名 :  osSerdes1InitSrio3g125
输入参数    :   None
输出参数      :
Description   :  macro1 Lane0~3 初始化为SRIO 3.125G

Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes1InitSrio3g125(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit9-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0x3FF, 0xFFFFFFFF );

    /*3、设置模式为multi-mode*/
    /*Addr[ioctrl0_base_addr+0x60],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x60, 0x0, 0xFFFFF7FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x200, 0xFFFFFE00 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载3.125Gbps_156.25MHz_VSM.txt配置文件*/
    osSerdes1Write( 0x0, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x0, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x0, 0x0, 0x67, 0xa );
    osSerdes1Write( 0x0, 0x0, 0x68, 0xa );
    osSerdes1Write( 0x0, 0x0, 0x69, 0xe );
    osSerdes1Write( 0x0, 0x0, 0x6a, 0xe );
    osSerdes1Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x0, 0x0, 0x6e, 0xd );
    osSerdes1Write( 0x1, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x1, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x1, 0x0, 0x67, 0xa );
    osSerdes1Write( 0x1, 0x0, 0x68, 0xa );
    osSerdes1Write( 0x1, 0x0, 0x69, 0xe );
    osSerdes1Write( 0x1, 0x0, 0x6a, 0xe );
    osSerdes1Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x1, 0x0, 0x6e, 0xd );
    osSerdes1Write( 0x2, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x2, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x2, 0x0, 0x67, 0xa );
    osSerdes1Write( 0x2, 0x0, 0x68, 0xa );
    osSerdes1Write( 0x2, 0x0, 0x69, 0xe );
    osSerdes1Write( 0x2, 0x0, 0x6a, 0xe );
    osSerdes1Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x2, 0x0, 0x6e, 0xd );
    osSerdes1Write( 0x3, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x3, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x3, 0x0, 0x67, 0xa );
    osSerdes1Write( 0x3, 0x0, 0x68, 0xa );
    osSerdes1Write( 0x3, 0x0, 0x69, 0xe );
    osSerdes1Write( 0x3, 0x0, 0x6a, 0xe );
    osSerdes1Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x3, 0x0, 0x6e, 0xd );
    osSerdes1Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes1Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x67, 0x6c );
    osSerdes1Write( 0x4, 0x0, 0x68, 0xbf );
    osSerdes1Write( 0x4, 0x0, 0x69, 0xbf );
    osSerdes1Write( 0x4, 0x0, 0x6a, 0xa );
    osSerdes1Write( 0x4, 0x0, 0x6b, 0xa );
    osSerdes1Write( 0x4, 0x0, 0x6c, 0xe );
    osSerdes1Write( 0x4, 0x0, 0x6d, 0xe );
    osSerdes1Write( 0x4, 0x0, 0x6e, 0x7 );
    osSerdes1Write( 0x4, 0x0, 0x6f, 0xc );
    osSerdes1Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x75, 0xb3 );
    osSerdes1Write( 0x4, 0x0, 0x76, 0xf6 );
    osSerdes1Write( 0x4, 0x0, 0x77, 0xd0 );
    osSerdes1Write( 0x4, 0x0, 0x78, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x79, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x7a, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7f, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x80, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x81, 0xe2 );
    osSerdes1Write( 0x4, 0x0, 0x82, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x83, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x84, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x85, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x86, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x89, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x8a, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x8b, 0xe2 );
    osSerdes1Write( 0x4, 0x0, 0x8c, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x8d, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x8e, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x8f, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x90, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x93, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x94, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes1Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x97, 0x64 );
    osSerdes1Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x99, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes1Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes1Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x37, 0x9c );
    osSerdes1Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes1Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes1Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes1Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes1Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x2bd, 0x0 );

    /*配置并行数据接口的数据位宽和速率*/
    /*Addr[ioctrl0_base_addr+0x64],data[bit31-29=3'b001,*/
    /*bit28-26=3'b001,bit25-23=3'b001,bit22-20=3b001,bit19-17=3b001,*/
    /*bit16-14=3b001,bit13-11=3b001,bit10-8=3b001,bit7-0=all 1]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x64, 0x249249FF, 0x249249FF );

    /*addr[ioctrl0_base_addr+0x68],data[bit31-24=all0,bit23-21=3'b010,*/
    /*bit20-18=3'b010,bit17-15=3'b010,bit14-12=3'b010,bit11-9=3'b010,*/
    /*bit8-6=3'b010,bit5-3=3'b010,bit2-0=3'b010]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x68, 0x492492, 0x492492 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x3ff, 0xffffffff );

    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl0_base_addr+0x404],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;

}


/*****************************************************************
函数名 :  osSerdes1InitXaui3g125
输入参数    :   None
输出参数      :
Description   :  macro1 Lane0~3 初始化为XAUI  3.125G

Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes1InitXaui3g125(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit9-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0x3FF, 0xFFFFFFFF );

    /*3、设置模式为multi-mode*/
    /*Addr[ioctrl0_base_addr+0x60],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x60, 0x0, 0xFFFFF7FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x200, 0xFFFFFE00 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载XAUI_156.25MHz_VSM.txt配置文件*/
    osSerdes1Write( 0x0, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x0, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x0, 0x0, 0x67, 0xa );
    osSerdes1Write( 0x0, 0x0, 0x68, 0xa );
    osSerdes1Write( 0x0, 0x0, 0x69, 0xe );
    osSerdes1Write( 0x0, 0x0, 0x6a, 0xe );
    osSerdes1Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x0, 0x0, 0x6e, 0xd );
    osSerdes1Write( 0x1, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x1, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x1, 0x0, 0x67, 0xa );
    osSerdes1Write( 0x1, 0x0, 0x68, 0xa );
    osSerdes1Write( 0x1, 0x0, 0x69, 0xe );
    osSerdes1Write( 0x1, 0x0, 0x6a, 0xe );
    osSerdes1Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x1, 0x0, 0x6e, 0xd );
    osSerdes1Write( 0x2, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x2, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x2, 0x0, 0x67, 0xa );
    osSerdes1Write( 0x2, 0x0, 0x68, 0xa );
    osSerdes1Write( 0x2, 0x0, 0x69, 0xe );
    osSerdes1Write( 0x2, 0x0, 0x6a, 0xe );
    osSerdes1Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x2, 0x0, 0x6e, 0xd );
    osSerdes1Write( 0x3, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x3, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x3, 0x0, 0x67, 0xa );
    osSerdes1Write( 0x3, 0x0, 0x68, 0xa );
    osSerdes1Write( 0x3, 0x0, 0x69, 0xe );
    osSerdes1Write( 0x3, 0x0, 0x6a, 0xe );
    osSerdes1Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x3, 0x0, 0x6e, 0xd );
    osSerdes1Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes1Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x67, 0x6c );
    osSerdes1Write( 0x4, 0x0, 0x68, 0xbf );
    osSerdes1Write( 0x4, 0x0, 0x69, 0xbf );
    osSerdes1Write( 0x4, 0x0, 0x6a, 0xa );
    osSerdes1Write( 0x4, 0x0, 0x6b, 0xa );
    osSerdes1Write( 0x4, 0x0, 0x6c, 0xe );
    osSerdes1Write( 0x4, 0x0, 0x6d, 0xe );
    osSerdes1Write( 0x4, 0x0, 0x6e, 0x7 );
    osSerdes1Write( 0x4, 0x0, 0x6f, 0xc );
    osSerdes1Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x75, 0xb3 );
    osSerdes1Write( 0x4, 0x0, 0x76, 0xf6 );
    osSerdes1Write( 0x4, 0x0, 0x77, 0xd0 );
    osSerdes1Write( 0x4, 0x0, 0x78, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x79, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x7a, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7f, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x80, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x81, 0xe2 );
    osSerdes1Write( 0x4, 0x0, 0x82, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x83, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x84, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x85, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x86, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x89, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x8a, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x8b, 0xe2 );
    osSerdes1Write( 0x4, 0x0, 0x8c, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x8d, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x8e, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x8f, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x90, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x93, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x94, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes1Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x97, 0x32 );
    osSerdes1Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x99, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes1Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes1Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x37, 0x9c );
    osSerdes1Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes1Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes1Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes1Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes1Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x2bd, 0x0 );

    /*Addr[ioctrl0_base_addr+0x64],data[bit31-29=3'b011, bit28-26=3'b011,*/
    /*bit25-23=3'b011,bit22-20=3b011,bit19-17=3b011,bit16-14=3b011,*/
    /*bit13-11=3b011,bit10-8=3b011,bit7-0=all 1]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x64, 0x6DB6DBFF, 0x6DB6DBFF );

    /*addr[ioctrl0_base_addr+0x68],data[bit31-24=all0,bit23-21=3'b010,*/
    /*bit20-18=3'b010,bit17-15=3'b010,bit14-12=3'b010,bit11-9=3'b010,*/
    /*bit8-6=3'b010,bit5-3=3'b010,bit2-0=3'b010]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x68, 0x492492, 0x492492 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x3ff, 0xffffffff );

    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl0_base_addr+0x404],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;
}


/*****************************************************************
函数名 :  osSerdes1InitSrio5g
输入参数    :   None
输出参数      :
Description   :  macro1 Lane0~3 初始化为SRIO 5.0G

Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes1InitSrio5g(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit9-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0x3FF, 0xFFFFFFFF );

    /*3、设置模式为multi-mode*/
    /*Addr[ioctrl0_base_addr+0x60],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x60, 0x0, 0xFFFFF7FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x200, 0xFFFFFE00 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载5Gbps_156.25MHz_VSM.txt配置文件*/
    osSerdes1Write( 0x0, 0x0, 0x65, 0xb7 );
    osSerdes1Write( 0x0, 0x0, 0x66, 0xb7 );
    osSerdes1Write( 0x0, 0x0, 0x67, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x68, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x69, 0x1a );
    osSerdes1Write( 0x0, 0x0, 0x6a, 0x1a );
    osSerdes1Write( 0x0, 0x0, 0x6b, 0x2 );
    osSerdes1Write( 0x0, 0x0, 0x6c, 0x2 );
    osSerdes1Write( 0x0, 0x0, 0x6d, 0x11 );
    osSerdes1Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x1, 0x0, 0x65, 0xb7 );
    osSerdes1Write( 0x1, 0x0, 0x66, 0xb7 );
    osSerdes1Write( 0x1, 0x0, 0x67, 0xc );
    osSerdes1Write( 0x1, 0x0, 0x68, 0xc );
    osSerdes1Write( 0x1, 0x0, 0x69, 0x1a );
    osSerdes1Write( 0x1, 0x0, 0x6a, 0x1a );
    osSerdes1Write( 0x1, 0x0, 0x6b, 0x2 );
    osSerdes1Write( 0x1, 0x0, 0x6c, 0x2 );
    osSerdes1Write( 0x1, 0x0, 0x6d, 0x11 );
    osSerdes1Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x2, 0x0, 0x65, 0xb7 );
    osSerdes1Write( 0x2, 0x0, 0x66, 0xb7 );
    osSerdes1Write( 0x2, 0x0, 0x67, 0xc );
    osSerdes1Write( 0x2, 0x0, 0x68, 0xc );
    osSerdes1Write( 0x2, 0x0, 0x69, 0x1a );
    osSerdes1Write( 0x2, 0x0, 0x6a, 0x1a );
    osSerdes1Write( 0x2, 0x0, 0x6b, 0x2 );
    osSerdes1Write( 0x2, 0x0, 0x6c, 0x2 );
    osSerdes1Write( 0x2, 0x0, 0x6d, 0x11 );
    osSerdes1Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x3, 0x0, 0x65, 0xb7 );
    osSerdes1Write( 0x3, 0x0, 0x66, 0xb7 );
    osSerdes1Write( 0x3, 0x0, 0x67, 0xc );
    osSerdes1Write( 0x3, 0x0, 0x68, 0xc );
    osSerdes1Write( 0x3, 0x0, 0x69, 0x1a );
    osSerdes1Write( 0x3, 0x0, 0x6a, 0x1a );
    osSerdes1Write( 0x3, 0x0, 0x6b, 0x2 );
    osSerdes1Write( 0x3, 0x0, 0x6c, 0x2 );
    osSerdes1Write( 0x3, 0x0, 0x6d, 0x11 );
    osSerdes1Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x65, 0x99 );
    osSerdes1Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x67, 0x6c );
    osSerdes1Write( 0x4, 0x0, 0x68, 0xb7 );
    osSerdes1Write( 0x4, 0x0, 0x69, 0xb7 );
    osSerdes1Write( 0x4, 0x0, 0x6a, 0xc );
    osSerdes1Write( 0x4, 0x0, 0x6b, 0xc );
    osSerdes1Write( 0x4, 0x0, 0x6c, 0x1a );
    osSerdes1Write( 0x4, 0x0, 0x6d, 0x1a );
    osSerdes1Write( 0x4, 0x0, 0x6e, 0x7 );
    osSerdes1Write( 0x4, 0x0, 0x6f, 0xc );
    osSerdes1Write( 0x4, 0x0, 0x70, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x72, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x75, 0xb3 );
    osSerdes1Write( 0x4, 0x0, 0x76, 0xf6 );
    osSerdes1Write( 0x4, 0x0, 0x77, 0xd0 );
    osSerdes1Write( 0x4, 0x0, 0x78, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x79, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x7a, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7f, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x80, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x81, 0xe2 );
    osSerdes1Write( 0x4, 0x0, 0x82, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x83, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x84, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x85, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x86, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x89, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x8a, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x8b, 0xe2 );
    osSerdes1Write( 0x4, 0x0, 0x8c, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x8d, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x8e, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x8f, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x90, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x93, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x94, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes1Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x97, 0x64 );
    osSerdes1Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x99, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0x9a, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes1Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x37, 0xb4 );
    osSerdes1Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes1Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes1Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes1Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes1Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x2bd, 0x0 );

    /*Addr[ioctrl0_base_addr+0x64],data[bit31-29=3'b001, bit28-26=3'b001,*/
    /*bit25-23=3'b001,bit22-20=3b001,bit19-17=3b001,bit16-14=3b001,*/
    /*bit13-11=3b001,bit10-8=3b001,bit7-0=all 1]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x64, 0x249249FF, 0x249249FF );

    /*addr[ioctrl0_base_addr+0x68],data[bit31-24=all0,bit23-21=3'b011,*/
    /*bit20-18=3'b011,bit17-15=3'b011,bit14-12=3'b011,bit11-9=3'b011,*/
    /*bit8-6=3'b011,bit5-3=3'b011,bit2-0=3'b011]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x68, 0x6DB6DB, 0x6DB6DB );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x3ff, 0xffffffff );

    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl0_base_addr+0x404],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;
}

/*****************************************************************
函数名 :  osSerdes1InitSrio6g25
输入参数    :   None
输出参数      :
Description   :  macro1 Lane0~3 初始化为SRIO 5.0G

Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes1InitSrio6g25(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit9-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0x3FF, 0xFFFFFFFF );

    /*3、设置模式为multi-mode*/
    /*Addr[ioctrl0_base_addr+0x60],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x60, 0x0, 0xFFFFF7FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x200, 0xFFFFFE00 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载6.25Gbps_156.25MHz_VSM.txt配置文件*/
    osSerdes1Write( 0x0, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x0, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x0, 0x0, 0x67, 0xa );
    osSerdes1Write( 0x0, 0x0, 0x68, 0xa );
    osSerdes1Write( 0x0, 0x0, 0x69, 0xe );
    osSerdes1Write( 0x0, 0x0, 0x6a, 0xe );
    osSerdes1Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x1, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x1, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x1, 0x0, 0x67, 0xa );
    osSerdes1Write( 0x1, 0x0, 0x68, 0xa );
    osSerdes1Write( 0x1, 0x0, 0x69, 0xe );
    osSerdes1Write( 0x1, 0x0, 0x6a, 0xe );
    osSerdes1Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x2, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x2, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x2, 0x0, 0x67, 0xa );
    osSerdes1Write( 0x2, 0x0, 0x68, 0xa );
    osSerdes1Write( 0x2, 0x0, 0x69, 0xe );
    osSerdes1Write( 0x2, 0x0, 0x6a, 0xe );
    osSerdes1Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x3, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x3, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x3, 0x0, 0x67, 0xa );
    osSerdes1Write( 0x3, 0x0, 0x68, 0xa );
    osSerdes1Write( 0x3, 0x0, 0x69, 0xe );
    osSerdes1Write( 0x3, 0x0, 0x6a, 0xe );
    osSerdes1Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes1Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x67, 0x6c );
    osSerdes1Write( 0x4, 0x0, 0x68, 0xbf );
    osSerdes1Write( 0x4, 0x0, 0x69, 0xbf );
    osSerdes1Write( 0x4, 0x0, 0x6a, 0xa );
    osSerdes1Write( 0x4, 0x0, 0x6b, 0xa );
    osSerdes1Write( 0x4, 0x0, 0x6c, 0xe );
    osSerdes1Write( 0x4, 0x0, 0x6d, 0xe );
    osSerdes1Write( 0x4, 0x0, 0x6e, 0x7 );
    osSerdes1Write( 0x4, 0x0, 0x6f, 0xc );
    osSerdes1Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x75, 0xb3 );
    osSerdes1Write( 0x4, 0x0, 0x76, 0xf6 );
    osSerdes1Write( 0x4, 0x0, 0x77, 0xd0 );
    osSerdes1Write( 0x4, 0x0, 0x78, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x79, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x7a, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7f, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x80, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x81, 0xe2 );
    osSerdes1Write( 0x4, 0x0, 0x82, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x83, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x84, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x85, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x86, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x89, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x8a, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x8b, 0xe2 );
    osSerdes1Write( 0x4, 0x0, 0x8c, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x8d, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x8e, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x8f, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x90, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x93, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x94, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes1Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x97, 0x64 );
    osSerdes1Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x99, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes1Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes1Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x37, 0x9c );
    osSerdes1Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes1Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes1Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes1Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes1Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x2bd, 0x0 );

    /*Addr[ioctrl0_base_addr+0x64],data[bit31-29=3'b001, bit28-26=3'b001,*/
    /*bit25-23=3'b001,bit22-20=3b001,bit19-17=3b001,bit16-14=3b001,*/
    /*bit13-11=3b001,bit10-8=3b001,bit7-0=all 1]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x64, 0x249249FF, 0x249249FF );

    /*addr[ioctrl0_base_addr+0x68],data[bit31-24=all0,bit23-21=3'b011,*/
    /*bit20-18=3'b011,bit17-15=3'b011,bit14-12=3'b011,bit11-9=3'b011,*/
    /*bit8-6=3'b011,bit5-3=3'b011,bit2-0=3'b011]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x68, 0x6DB6DB, 0x6DB6DB );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x3ff, 0xffffffff );

    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl0_base_addr+0x404],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;
}

/*****************************************************************
函数名 :  osSerdes1InitXge10g3125
输入参数    :   None
输出参数      :
Description   :  macro1 Lane0~3 初始化为10GE 10.3125G

Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes1InitXge10g3125(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit9-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0x3FF, 0xFFFFFFFF );

    /*3、设置模式为multi-mode*/
    /*Addr[ioctrl0_base_addr+0x60],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x60, 0x0, 0xFFFFF7FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x200, 0xFFFFFE00 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载6.25Gbps_156.25MHz_VSM.txt配置文件*/
    osSerdes1Write( 0x0, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x0, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x0, 0x0, 0x67, 0xa );
    osSerdes1Write( 0x0, 0x0, 0x68, 0xa );
    osSerdes1Write( 0x0, 0x0, 0x69, 0xe );
    osSerdes1Write( 0x0, 0x0, 0x6a, 0xe );
    osSerdes1Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x1, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x1, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x1, 0x0, 0x67, 0xa );
    osSerdes1Write( 0x1, 0x0, 0x68, 0xa );
    osSerdes1Write( 0x1, 0x0, 0x69, 0xe );
    osSerdes1Write( 0x1, 0x0, 0x6a, 0xe );
    osSerdes1Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x2, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x2, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x2, 0x0, 0x67, 0xa );
    osSerdes1Write( 0x2, 0x0, 0x68, 0xa );
    osSerdes1Write( 0x2, 0x0, 0x69, 0xe );
    osSerdes1Write( 0x2, 0x0, 0x6a, 0xe );
    osSerdes1Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x3, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x3, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x3, 0x0, 0x67, 0xa );
    osSerdes1Write( 0x3, 0x0, 0x68, 0xa );
    osSerdes1Write( 0x3, 0x0, 0x69, 0xe );
    osSerdes1Write( 0x3, 0x0, 0x6a, 0xe );
    osSerdes1Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes1Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x67, 0x6c );
    osSerdes1Write( 0x4, 0x0, 0x68, 0xbf );
    osSerdes1Write( 0x4, 0x0, 0x69, 0xbf );
    osSerdes1Write( 0x4, 0x0, 0x6a, 0xa );
    osSerdes1Write( 0x4, 0x0, 0x6b, 0xa );
    osSerdes1Write( 0x4, 0x0, 0x6c, 0xe );
    osSerdes1Write( 0x4, 0x0, 0x6d, 0xe );
    osSerdes1Write( 0x4, 0x0, 0x6e, 0x7 );
    osSerdes1Write( 0x4, 0x0, 0x6f, 0xc );
    osSerdes1Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x75, 0xb3 );
    osSerdes1Write( 0x4, 0x0, 0x76, 0xf6 );
    osSerdes1Write( 0x4, 0x0, 0x77, 0xd0 );
    osSerdes1Write( 0x4, 0x0, 0x78, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x79, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x7a, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7f, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x80, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x81, 0xe2 );
    osSerdes1Write( 0x4, 0x0, 0x82, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x83, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x84, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x85, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x86, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x89, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x8a, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x8b, 0xe2 );
    osSerdes1Write( 0x4, 0x0, 0x8c, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x8d, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x8e, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x8f, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x90, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x93, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x94, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes1Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x97, 0x64 );
    osSerdes1Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x99, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes1Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes1Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x37, 0x9c );
    osSerdes1Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes1Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes1Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes1Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes1Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x2bd, 0x0 );

    /*Addr[ioctrl0_base_addr+0x64],data[bit31-29=3'b010, bit28-26=3'b010,*/
    /*bit25-23=3'b010,bit22-20=3b010,bit19-17=3b010,bit16-14=3b010,*/
    /*bit13-11=3b010,bit10-8=3b010,bit7-0=all 1]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x64, 0x492492FF, 0x492492FF );

    /*addr[ioctrl0_base_addr+0x68],data[bit31-24=all0,bit23-21=3'b011,*/
    /*bit20-18=3'b011,bit17-15=3'b011,bit14-12=3'b011,bit11-9=3'b011,*/
    /*bit8-6=3'b011,bit5-3=3'b011,bit2-0=3'b011]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x68, 0x6DB6DB, 0x6DB6DB );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x3ff, 0xffffffff );

    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl0_base_addr+0x404],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;
}


/*****************************************************************
函数名 :  osSerdes1InitPcie2g5
输入参数    :   None
输出参数      :
Description   :  macro1 Lane0~3 初始化为PCIE GEN1 2.5G
Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes1InitPcie2g5(void)
{
    //UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    //INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit9=1,bit8-5=all 1,bit4-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0x3E0, 0xFFFFFFE0 );

    /*3、设置模式为pcie-mode*/
    /*Addr[ioctrl0_base_addr+0x60],data[bit11=1]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x60, 0x800, 0xFFFFFFFF );

    /*配置pcie controller 这是控制器配置可问冯海/刘君龙*/



    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x200, 0xFFFFFE00 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载PCIe_100MHz_VSM.txt配置文件*/
    osSerdes1Write( 0x0, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x0, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x0, 0x0, 0x67, 0x8 );
    osSerdes1Write( 0x0, 0x0, 0x68, 0x5 );
    osSerdes1Write( 0x0, 0x0, 0x69, 0x13 );
    osSerdes1Write( 0x0, 0x0, 0x6a, 0x22 );
    osSerdes1Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6d, 0x31 );
    osSerdes1Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x1, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x1, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x1, 0x0, 0x67, 0x8 );
    osSerdes1Write( 0x1, 0x0, 0x68, 0x5 );
    osSerdes1Write( 0x1, 0x0, 0x69, 0x13 );
    osSerdes1Write( 0x1, 0x0, 0x6a, 0x22 );
    osSerdes1Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6d, 0x31 );
    osSerdes1Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x2, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x2, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x2, 0x0, 0x67, 0x8 );
    osSerdes1Write( 0x2, 0x0, 0x68, 0x5 );
    osSerdes1Write( 0x2, 0x0, 0x69, 0x13 );
    osSerdes1Write( 0x2, 0x0, 0x6a, 0x22 );
    osSerdes1Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6d, 0x31 );
    osSerdes1Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x3, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x3, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x3, 0x0, 0x67, 0x8 );
    osSerdes1Write( 0x3, 0x0, 0x68, 0x5 );
    osSerdes1Write( 0x3, 0x0, 0x69, 0x13 );
    osSerdes1Write( 0x3, 0x0, 0x6a, 0x22 );
    osSerdes1Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6d, 0x31 );
    osSerdes1Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes1Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x67, 0x45 );
    osSerdes1Write( 0x4, 0x0, 0x68, 0xbf );
    osSerdes1Write( 0x4, 0x0, 0x69, 0xbf );
    osSerdes1Write( 0x4, 0x0, 0x6a, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0x6b, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x6c, 0x13 );
    osSerdes1Write( 0x4, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x4, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x6f, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x75, 0xcf );
    osSerdes1Write( 0x4, 0x0, 0x76, 0xf7 );
    osSerdes1Write( 0x4, 0x0, 0x77, 0xe1 );
    osSerdes1Write( 0x4, 0x0, 0x78, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x79, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x7a, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7f, 0xe3 );
    osSerdes1Write( 0x4, 0x0, 0x80, 0xe7 );
    osSerdes1Write( 0x4, 0x0, 0x81, 0xdb );
    osSerdes1Write( 0x4, 0x0, 0x82, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x83, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x84, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x85, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x86, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x89, 0xe3 );
    osSerdes1Write( 0x4, 0x0, 0x8a, 0xe7 );
    osSerdes1Write( 0x4, 0x0, 0x8b, 0xdb );
    osSerdes1Write( 0x4, 0x0, 0x8c, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x8d, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x8e, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x8f, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x90, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x93, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x94, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes1Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x97, 0x32 );
    osSerdes1Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x99, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes1Write( 0x4, 0x0, 0x9b, 0x1 );
    osSerdes1Write( 0x4, 0x0, 0x9c, 0x1 );
    osSerdes1Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes1Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x37, 0xa6 );
    osSerdes1Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0xa5, 0x0 );
    osSerdes1Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes1Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes1Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes1Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x2bd, 0x0 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-5=all 1,bit4-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x3E0, 0xFFFFFFE0 );

    /*等待pcie linkup*/


    return OS_SUCCESS;
}


/*****************************************************************
函数名 :  osSerdes1InitPcie5g
输入参数    :   None
输出参数      :
Description   :  macro1  Lane0~3 初始化为PCIE GEN2  5.0G
Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes1InitPcie5g(void)
{
    //UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    //INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit9=1,bit8-5=all 1,bit4-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0x3E0, 0xFFFFFFE0 );

    /*3、设置模式为pcie-mode*/
    /*Addr[ioctrl0_base_addr+0x60],data[bit11=1]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x60, 0x800, 0xFFFFFFFF );

    /*配置pcie controller 这是控制器配置可问冯海/刘君龙*/



    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x200, 0xFFFFFE00 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载PCIe_100MHz_VSM.txt配置文件*/
    osSerdes1Write( 0x0, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x0, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x0, 0x0, 0x67, 0x8 );
    osSerdes1Write( 0x0, 0x0, 0x68, 0x5 );
    osSerdes1Write( 0x0, 0x0, 0x69, 0x13 );
    osSerdes1Write( 0x0, 0x0, 0x6a, 0x22 );
    osSerdes1Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6d, 0x31 );
    osSerdes1Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x1, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x1, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x1, 0x0, 0x67, 0x8 );
    osSerdes1Write( 0x1, 0x0, 0x68, 0x5 );
    osSerdes1Write( 0x1, 0x0, 0x69, 0x13 );
    osSerdes1Write( 0x1, 0x0, 0x6a, 0x22 );
    osSerdes1Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6d, 0x31 );
    osSerdes1Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x2, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x2, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x2, 0x0, 0x67, 0x8 );
    osSerdes1Write( 0x2, 0x0, 0x68, 0x5 );
    osSerdes1Write( 0x2, 0x0, 0x69, 0x13 );
    osSerdes1Write( 0x2, 0x0, 0x6a, 0x22 );
    osSerdes1Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6d, 0x31 );
    osSerdes1Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x3, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x3, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x3, 0x0, 0x67, 0x8 );
    osSerdes1Write( 0x3, 0x0, 0x68, 0x5 );
    osSerdes1Write( 0x3, 0x0, 0x69, 0x13 );
    osSerdes1Write( 0x3, 0x0, 0x6a, 0x22 );
    osSerdes1Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6d, 0x31 );
    osSerdes1Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes1Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x67, 0x45 );
    osSerdes1Write( 0x4, 0x0, 0x68, 0xbf );
    osSerdes1Write( 0x4, 0x0, 0x69, 0xbf );
    osSerdes1Write( 0x4, 0x0, 0x6a, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0x6b, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x6c, 0x13 );
    osSerdes1Write( 0x4, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x4, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x6f, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x75, 0xcf );
    osSerdes1Write( 0x4, 0x0, 0x76, 0xf7 );
    osSerdes1Write( 0x4, 0x0, 0x77, 0xe1 );
    osSerdes1Write( 0x4, 0x0, 0x78, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x79, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x7a, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7f, 0xe3 );
    osSerdes1Write( 0x4, 0x0, 0x80, 0xe7 );
    osSerdes1Write( 0x4, 0x0, 0x81, 0xdb );
    osSerdes1Write( 0x4, 0x0, 0x82, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x83, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x84, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x85, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x86, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x89, 0xe3 );
    osSerdes1Write( 0x4, 0x0, 0x8a, 0xe7 );
    osSerdes1Write( 0x4, 0x0, 0x8b, 0xdb );
    osSerdes1Write( 0x4, 0x0, 0x8c, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x8d, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x8e, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x8f, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x90, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x93, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x94, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes1Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x97, 0x32 );
    osSerdes1Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x99, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes1Write( 0x4, 0x0, 0x9b, 0x1 );
    osSerdes1Write( 0x4, 0x0, 0x9c, 0x1 );
    osSerdes1Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes1Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x37, 0xa6 );
    osSerdes1Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0xa5, 0x0 );
    osSerdes1Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes1Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes1Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes1Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x2bd, 0x0 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-5=all 1,bit4-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x3E0, 0xFFFFFFE0 );

    /*等待pcie linkup*/


    return OS_SUCCESS;
}



/*****************************************************************
函数名 :  osSerdes1InitPcie8g
输入参数    :   None
输出参数      :
Description   :  macro1  Lane0~3 初始化为PCIE GEN2  5.0G
Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes1InitPcie8g(void)
{
    //UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    //INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit9=1,bit8-5=all 1,bit4-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0x3E0, 0xFFFFFFE0 );

    /*3、设置模式为pcie-mode*/
    /*Addr[ioctrl0_base_addr+0x60],data[bit11=1]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x60, 0x800, 0xFFFFFFFF );

    /*配置pcie controller 这是控制器配置可问冯海/刘君龙*/



    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x200, 0xFFFFFE00 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载PCIe_Gen3_100MHz_VSM.txt配置文件*/
    osSerdes1Write( 0x0, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x0, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x0, 0x0, 0x67, 0x5 );
    osSerdes1Write( 0x0, 0x0, 0x68, 0x5 );
    osSerdes1Write( 0x0, 0x0, 0x69, 0x22 );
    osSerdes1Write( 0x0, 0x0, 0x6a, 0x22 );
    osSerdes1Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6d, 0x33 );
    osSerdes1Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x1, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x1, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x1, 0x0, 0x67, 0x5 );
    osSerdes1Write( 0x1, 0x0, 0x68, 0x5 );
    osSerdes1Write( 0x1, 0x0, 0x69, 0x22 );
    osSerdes1Write( 0x1, 0x0, 0x6a, 0x22 );
    osSerdes1Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6d, 0x33 );
    osSerdes1Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x2, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x2, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x2, 0x0, 0x67, 0x5 );
    osSerdes1Write( 0x2, 0x0, 0x68, 0x5 );
    osSerdes1Write( 0x2, 0x0, 0x69, 0x22 );
    osSerdes1Write( 0x2, 0x0, 0x6a, 0x22 );
    osSerdes1Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6d, 0x33 );
    osSerdes1Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x3, 0x0, 0x65, 0xbf );
    osSerdes1Write( 0x3, 0x0, 0x66, 0xbf );
    osSerdes1Write( 0x3, 0x0, 0x67, 0x5 );
    osSerdes1Write( 0x3, 0x0, 0x68, 0x5 );
    osSerdes1Write( 0x3, 0x0, 0x69, 0x22 );
    osSerdes1Write( 0x3, 0x0, 0x6a, 0x22 );
    osSerdes1Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6d, 0x33 );
    osSerdes1Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes1Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x67, 0x45 );
    osSerdes1Write( 0x4, 0x0, 0x68, 0xbf );
    osSerdes1Write( 0x4, 0x0, 0x69, 0xbf );
    osSerdes1Write( 0x4, 0x0, 0x6a, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x6b, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x6c, 0x22 );
    osSerdes1Write( 0x4, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x4, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x6f, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x75, 0xcf );
    osSerdes1Write( 0x4, 0x0, 0x76, 0xf7 );
    osSerdes1Write( 0x4, 0x0, 0x77, 0xe1 );
    osSerdes1Write( 0x4, 0x0, 0x78, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x79, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x7a, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7f, 0xe3 );
    osSerdes1Write( 0x4, 0x0, 0x80, 0xe7 );
    osSerdes1Write( 0x4, 0x0, 0x81, 0xdb );
    osSerdes1Write( 0x4, 0x0, 0x82, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x83, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x84, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x85, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x86, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x89, 0xe3 );
    osSerdes1Write( 0x4, 0x0, 0x8a, 0xe7 );
    osSerdes1Write( 0x4, 0x0, 0x8b, 0xdb );
    osSerdes1Write( 0x4, 0x0, 0x8c, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x8d, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x8e, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x8f, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x90, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x93, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x94, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes1Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x97, 0x32 );
    osSerdes1Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x99, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes1Write( 0x4, 0x0, 0x9b, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x9c, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes1Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x37, 0xc4 );
    osSerdes1Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0xa5, 0x0 );
    osSerdes1Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes1Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes1Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes1Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x2bd, 0x0 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-5=all 1,bit4-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x3E0, 0xFFFFFFE0 );

    /*等待pcie linkup*/


    return OS_SUCCESS;
}


/*****************************************************************
函数名 :  osSerdes1InitSata1g5
输入参数    :   None
输出参数      :
Description   :  macro1  Lane0~3 初始化为SATA GEN2  1.5G
Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes1InitSata1g5(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit9-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0x3FF, 0xFFFFFFFF );

    /*3、设置模式为multi-mode*/
    /*Addr[ioctrl0_base_addr+0x60],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x60, 0x0, 0xFFFFF7FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x200, 0xFFFFFE00 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载SATA_100MHz_VSM.txt配置文件*/
    osSerdes1Write( 0x0, 0x0, 0x65, 0xc9 );
    osSerdes1Write( 0x0, 0x0, 0x66, 0xc9 );
    osSerdes1Write( 0x0, 0x0, 0x67, 0x7 );
    osSerdes1Write( 0x0, 0x0, 0x68, 0x7 );
    osSerdes1Write( 0x0, 0x0, 0x69, 0x18 );
    osSerdes1Write( 0x0, 0x0, 0x6a, 0x18 );
    osSerdes1Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x1, 0x0, 0x65, 0xc9 );
    osSerdes1Write( 0x1, 0x0, 0x66, 0xc9 );
    osSerdes1Write( 0x1, 0x0, 0x67, 0x7 );
    osSerdes1Write( 0x1, 0x0, 0x68, 0x7 );
    osSerdes1Write( 0x1, 0x0, 0x69, 0x18 );
    osSerdes1Write( 0x1, 0x0, 0x6a, 0x18 );
    osSerdes1Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x2, 0x0, 0x65, 0xc9 );
    osSerdes1Write( 0x2, 0x0, 0x66, 0xc9 );
    osSerdes1Write( 0x2, 0x0, 0x67, 0x7 );
    osSerdes1Write( 0x2, 0x0, 0x68, 0x7 );
    osSerdes1Write( 0x2, 0x0, 0x69, 0x18 );
    osSerdes1Write( 0x2, 0x0, 0x6a, 0x18 );
    osSerdes1Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x3, 0x0, 0x65, 0xc9 );
    osSerdes1Write( 0x3, 0x0, 0x66, 0xc9 );
    osSerdes1Write( 0x3, 0x0, 0x67, 0x7 );
    osSerdes1Write( 0x3, 0x0, 0x68, 0x7 );
    osSerdes1Write( 0x3, 0x0, 0x69, 0x18 );
    osSerdes1Write( 0x3, 0x0, 0x6a, 0x18 );
    osSerdes1Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes1Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x67, 0x45 );
    osSerdes1Write( 0x4, 0x0, 0x68, 0xc9 );
    osSerdes1Write( 0x4, 0x0, 0x69, 0xc9 );
    osSerdes1Write( 0x4, 0x0, 0x6a, 0x7 );
    osSerdes1Write( 0x4, 0x0, 0x6b, 0x7 );
    osSerdes1Write( 0x4, 0x0, 0x6c, 0x18 );
    osSerdes1Write( 0x4, 0x0, 0x6d, 0x18 );
    osSerdes1Write( 0x4, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x6f, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x75, 0xcf );
    osSerdes1Write( 0x4, 0x0, 0x76, 0xf7 );
    osSerdes1Write( 0x4, 0x0, 0x77, 0xe1 );
    osSerdes1Write( 0x4, 0x0, 0x78, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x79, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x7a, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7f, 0xe3 );
    osSerdes1Write( 0x4, 0x0, 0x80, 0xe7 );
    osSerdes1Write( 0x4, 0x0, 0x81, 0xdb );
    osSerdes1Write( 0x4, 0x0, 0x82, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x83, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x84, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x85, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x86, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x89, 0xe3 );
    osSerdes1Write( 0x4, 0x0, 0x8a, 0xe7 );
    osSerdes1Write( 0x4, 0x0, 0x8b, 0xdb );
    osSerdes1Write( 0x4, 0x0, 0x8c, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x8d, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x8e, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x8f, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x90, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x93, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x94, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes1Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x97, 0x32 );
    osSerdes1Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x99, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes1Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes1Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x37, 0xb0 );
    osSerdes1Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes1Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes1Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes1Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes1Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x2bd, 0x0 );

    /*配置并行数据接口的数据位宽和速率*/
    /*Addr[ioctrl0_base_addr+0x64],data[bit31-29=3'b001,*/
    /*bit28-26=3'b001,bit25-23=3'b001,bit22-20=3b001,bit19-17=3b001,*/
    /*bit16-14=3b001,bit13-11=3b001,bit10-8=3b001,bit7-0=all 1]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x64, 0x249249FF, 0x249249FF );

    /*addr[ioctrl0_base_addr+0x68],data[bit31-24=all0,*/
    /*bit23-21=3'b001,bit20-18=3'b001,bit17-15=3'b001,bit14-12=3'b001,*/
    /*bit11-9=3'b001,bit8-6=3'b001,bit5-3=3'b001,bit2-0=3'b001]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x68, 0x249249, 0x249249 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x3ff, 0xffffffff );

    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl0_base_addr+0x404],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;

}


/*****************************************************************
函数名 :  osSerdes1InitSata3g
输入参数    :   None
输出参数      :
Description   :  macro1  Lane0~3 初始化为SATA GEN2  3.0G
Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes1InitSata3g(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit9-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0x3FF, 0xFFFFFFFF );

    /*3、设置模式为multi-mode*/
    /*Addr[ioctrl0_base_addr+0x60],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x60, 0x0, 0xFFFFF7FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x200, 0xFFFFFE00 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载SATA_100MHz_VSM.txt配置文件*/
    osSerdes1Write( 0x0, 0x0, 0x65, 0xc9 );
    osSerdes1Write( 0x0, 0x0, 0x66, 0xc9 );
    osSerdes1Write( 0x0, 0x0, 0x67, 0x7 );
    osSerdes1Write( 0x0, 0x0, 0x68, 0x7 );
    osSerdes1Write( 0x0, 0x0, 0x69, 0x18 );
    osSerdes1Write( 0x0, 0x0, 0x6a, 0x18 );
    osSerdes1Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x1, 0x0, 0x65, 0xc9 );
    osSerdes1Write( 0x1, 0x0, 0x66, 0xc9 );
    osSerdes1Write( 0x1, 0x0, 0x67, 0x7 );
    osSerdes1Write( 0x1, 0x0, 0x68, 0x7 );
    osSerdes1Write( 0x1, 0x0, 0x69, 0x18 );
    osSerdes1Write( 0x1, 0x0, 0x6a, 0x18 );
    osSerdes1Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x2, 0x0, 0x65, 0xc9 );
    osSerdes1Write( 0x2, 0x0, 0x66, 0xc9 );
    osSerdes1Write( 0x2, 0x0, 0x67, 0x7 );
    osSerdes1Write( 0x2, 0x0, 0x68, 0x7 );
    osSerdes1Write( 0x2, 0x0, 0x69, 0x18 );
    osSerdes1Write( 0x2, 0x0, 0x6a, 0x18 );
    osSerdes1Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x3, 0x0, 0x65, 0xc9 );
    osSerdes1Write( 0x3, 0x0, 0x66, 0xc9 );
    osSerdes1Write( 0x3, 0x0, 0x67, 0x7 );
    osSerdes1Write( 0x3, 0x0, 0x68, 0x7 );
    osSerdes1Write( 0x3, 0x0, 0x69, 0x18 );
    osSerdes1Write( 0x3, 0x0, 0x6a, 0x18 );
    osSerdes1Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes1Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x67, 0x45 );
    osSerdes1Write( 0x4, 0x0, 0x68, 0xc9 );
    osSerdes1Write( 0x4, 0x0, 0x69, 0xc9 );
    osSerdes1Write( 0x4, 0x0, 0x6a, 0x7 );
    osSerdes1Write( 0x4, 0x0, 0x6b, 0x7 );
    osSerdes1Write( 0x4, 0x0, 0x6c, 0x18 );
    osSerdes1Write( 0x4, 0x0, 0x6d, 0x18 );
    osSerdes1Write( 0x4, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x6f, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x75, 0xcf );
    osSerdes1Write( 0x4, 0x0, 0x76, 0xf7 );
    osSerdes1Write( 0x4, 0x0, 0x77, 0xe1 );
    osSerdes1Write( 0x4, 0x0, 0x78, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x79, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x7a, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7f, 0xe3 );
    osSerdes1Write( 0x4, 0x0, 0x80, 0xe7 );
    osSerdes1Write( 0x4, 0x0, 0x81, 0xdb );
    osSerdes1Write( 0x4, 0x0, 0x82, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x83, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x84, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x85, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x86, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x89, 0xe3 );
    osSerdes1Write( 0x4, 0x0, 0x8a, 0xe7 );
    osSerdes1Write( 0x4, 0x0, 0x8b, 0xdb );
    osSerdes1Write( 0x4, 0x0, 0x8c, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x8d, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x8e, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x8f, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x90, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x93, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x94, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes1Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x97, 0x32 );
    osSerdes1Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x99, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes1Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes1Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x37, 0xb0 );
    osSerdes1Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes1Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes1Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes1Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes1Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x2bd, 0x0 );

    /*配置并行数据接口的数据位宽和速率*/
    /*Addr[ioctrl0_base_addr+0x64],data[bit31-29=3'b011,*/
    /*bit28-26=3'b011,bit25-23=3'b011,bit22-20=3b011,bit19-17=3b011,*/
    /*bit16-14=3b011,bit13-11=3b011,bit10-8=3b011,bit7-0=all 1]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x64, 0x6DB6DBFF, 0x6DB6DBFF );

    /*addr[ioctrl0_base_addr+0x68],data[bit31-24=all0,*/
    /*bit23-21=3'b010,bit20-18=3'b010,bit17-15=3'b010,bit14-12=3'b010,*/
    /*bit11-9=3'b010,bit8-6=3'b010,bit5-3=3'b010,bit2-0=3'b010]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x68, 0x492492, 0x492492 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x3ff, 0xffffffff );

    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl0_base_addr+0x404],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;

}

/*****************************************************************
函数名 :  osSerdes1InitSata6g
输入参数    :   None
输出参数      :
Description   :  macro1  Lane0~3 初始化为SATA GEN2  6.0G
Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes1InitSata6g(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit9-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0x3FF, 0xFFFFFFFF );

    /*3、设置模式为multi-mode*/
    /*Addr[ioctrl0_base_addr+0x60],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x60, 0x0, 0xFFFFF7FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x200, 0xFFFFFE00 );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载SATA_100MHz_VSM.txt配置文件*/
    osSerdes1Write( 0x0, 0x0, 0x65, 0xc9 );
    osSerdes1Write( 0x0, 0x0, 0x66, 0xc9 );
    osSerdes1Write( 0x0, 0x0, 0x67, 0x7 );
    osSerdes1Write( 0x0, 0x0, 0x68, 0x7 );
    osSerdes1Write( 0x0, 0x0, 0x69, 0x18 );
    osSerdes1Write( 0x0, 0x0, 0x6a, 0x18 );
    osSerdes1Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x0, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x1, 0x0, 0x65, 0xc9 );
    osSerdes1Write( 0x1, 0x0, 0x66, 0xc9 );
    osSerdes1Write( 0x1, 0x0, 0x67, 0x7 );
    osSerdes1Write( 0x1, 0x0, 0x68, 0x7 );
    osSerdes1Write( 0x1, 0x0, 0x69, 0x18 );
    osSerdes1Write( 0x1, 0x0, 0x6a, 0x18 );
    osSerdes1Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x1, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x2, 0x0, 0x65, 0xc9 );
    osSerdes1Write( 0x2, 0x0, 0x66, 0xc9 );
    osSerdes1Write( 0x2, 0x0, 0x67, 0x7 );
    osSerdes1Write( 0x2, 0x0, 0x68, 0x7 );
    osSerdes1Write( 0x2, 0x0, 0x69, 0x18 );
    osSerdes1Write( 0x2, 0x0, 0x6a, 0x18 );
    osSerdes1Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x2, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x3, 0x0, 0x65, 0xc9 );
    osSerdes1Write( 0x3, 0x0, 0x66, 0xc9 );
    osSerdes1Write( 0x3, 0x0, 0x67, 0x7 );
    osSerdes1Write( 0x3, 0x0, 0x68, 0x7 );
    osSerdes1Write( 0x3, 0x0, 0x69, 0x18 );
    osSerdes1Write( 0x3, 0x0, 0x6a, 0x18 );
    osSerdes1Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes1Write( 0x3, 0x0, 0x6d, 0x22 );
    osSerdes1Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes1Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x67, 0x45 );
    osSerdes1Write( 0x4, 0x0, 0x68, 0xc9 );
    osSerdes1Write( 0x4, 0x0, 0x69, 0xc9 );
    osSerdes1Write( 0x4, 0x0, 0x6a, 0x7 );
    osSerdes1Write( 0x4, 0x0, 0x6b, 0x7 );
    osSerdes1Write( 0x4, 0x0, 0x6c, 0x18 );
    osSerdes1Write( 0x4, 0x0, 0x6d, 0x18 );
    osSerdes1Write( 0x4, 0x0, 0x6e, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x6f, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x75, 0xcf );
    osSerdes1Write( 0x4, 0x0, 0x76, 0xf7 );
    osSerdes1Write( 0x4, 0x0, 0x77, 0xe1 );
    osSerdes1Write( 0x4, 0x0, 0x78, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x79, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x7a, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7f, 0xe3 );
    osSerdes1Write( 0x4, 0x0, 0x80, 0xe7 );
    osSerdes1Write( 0x4, 0x0, 0x81, 0xdb );
    osSerdes1Write( 0x4, 0x0, 0x82, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x83, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x84, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x85, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x86, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x89, 0xe3 );
    osSerdes1Write( 0x4, 0x0, 0x8a, 0xe7 );
    osSerdes1Write( 0x4, 0x0, 0x8b, 0xdb );
    osSerdes1Write( 0x4, 0x0, 0x8c, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x8d, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x8e, 0xfd );
    osSerdes1Write( 0x4, 0x0, 0x8f, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x90, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x93, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x94, 0xf5 );
    osSerdes1Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes1Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x97, 0x32 );
    osSerdes1Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x99, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes1Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes1Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x37, 0xb0 );
    osSerdes1Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes1Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes1Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes1Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes1Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x2bd, 0x0 );

    /*配置并行数据接口的数据位宽和速率*/
    /*Addr[ioctrl0_base_addr+0x64],data[bit31-29=3'b011,*/
    /*bit28-26=3'b011,bit25-23=3'b011,bit22-20=3b011,bit19-17=3b011,*/
    /*bit16-14=3b011,bit13-11=3b011,bit10-8=3b011,bit7-0=all 1]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x64, 0x6DB6DBFF, 0x6DB6DBFF );

    /*addr[ioctrl0_base_addr+0x68],data[bit31-24=all0,*/
    /*bit23-21=3'b011,bit20-18=3'b011,bit17-15=3'b011,bit14-12=3'b011,*/
    /*bit11-9=3'b011,bit8-6=3'b011,bit5-3=3'b011,bit2-0=3'b011]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x68, 0x6DB6DB, 0x6DB6DB );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x3ff, 0xffffffff );

    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl0_base_addr+0x404],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;

}


/*****************************************************************
函数名 :  osSerdes2InitGe1g25Srio1g25
输入参数    :   None
输出参数      :
Description   :  macro2   Lane0~3初始化为1000BASE-KX/SRIO 1.25G
Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes2InitGe1g25Srio1g25(void)
{
    UINT32 ulValue = 0x0;
    INT32 ulWaitTime = 0x10000000;
    //*********************************************************
    //serdes2  initialization:sds2_ge_srio_1g25
    //*********************************************************
    //1.    POR
    osSerdesBitWrite (SRE_SC_SERDES_RESET_REQ1_REG,0x80000,0xffffffff);

    //1(1); set multi-mode:
    osSerdesBitWrite (IOCTRL1_BASE_ADDR + 0x00c,0x1400,0xFFFFF7FF);

    //1(2); set pcie-mode:
    //osSerdesBitWrite (IOCTRL1_BASE_ADDR + 0x00c,0x1c00,0xFFFFFFFF);

    //2.    Release POR
    osSerdesBitWrite (SRE_SC_SERDES_RESET_DREQ1_REG,0x80000,0xffffffff);
    osSerdesWait(0x1000000);
    //3.    Enable Hard Reset
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane);    Value
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASSEN   7   1
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASSEN_SYNTH 4   1
    //4.    Hard Reset
    //HARDRST.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane);    Value
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASS     7   0
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASS_SYNTH   4   0
    osSerdes2Write (0x0,0x0,0x2,0x2);
    osSerdes2Write (0x1,0x0,0x2,0x2);
    osSerdes2Write (0x2,0x0,0x2,0x2);
    osSerdes2Write (0x3,0x0,0x2,0x2);
    osSerdes2Write (0x4,0x0,0x2,0x1);
    osSerdesWait(0x1000000);
    // 5.   Load Different Data Rate Settings
    //1p25Gbps_156p25MHz.memcfg
    //load the 1.25Gbps_156.25MHz_VSM.txt
    osSerdes2Write (0,0,101,183);
    osSerdes2Write (0,0,102,183);
    osSerdes2Write (0,0,103,12);
    osSerdes2Write (0,0,104,12);
    osSerdes2Write (0,0,105,26);
    osSerdes2Write (0,0,106,26);
    osSerdes2Write (0,0,107,2);
    osSerdes2Write (0,0,108,2);
    osSerdes2Write (0,0,109,17);
    osSerdes2Write (0,0,110,13);
    osSerdes2Write (1,0,101,183);
    osSerdes2Write (1,0,102,183);
    osSerdes2Write (1,0,103,12);
    osSerdes2Write (1,0,104,12);
    osSerdes2Write (1,0,105,26);
    osSerdes2Write (1,0,106,26);
    osSerdes2Write (1,0,107,2);
    osSerdes2Write (1,0,108,2);
    osSerdes2Write (1,0,109,17);
    osSerdes2Write (1,0,110,13);
    osSerdes2Write (2,0,101,183);
    osSerdes2Write (2,0,102,183);
    osSerdes2Write (2,0,103,12);
    osSerdes2Write (2,0,104,12);
    osSerdes2Write (2,0,105,26);
    osSerdes2Write (2,0,106,26);
    osSerdes2Write (2,0,107,2);
    osSerdes2Write (2,0,108,2);
    osSerdes2Write (2,0,109,17);
    osSerdes2Write (2,0,110,13);
    osSerdes2Write (3,0,101,183);
    osSerdes2Write (3,0,102,183);
    osSerdes2Write (3,0,103,12);
    osSerdes2Write (3,0,104,12);
    osSerdes2Write (3,0,105,26);
    osSerdes2Write (3,0,106,26);
    osSerdes2Write (3,0,107,2);
    osSerdes2Write (3,0,108,2);
    osSerdes2Write (3,0,109,17);
    osSerdes2Write (3,0,110,13);
    osSerdes2Write (4,0,101,153);
    osSerdes2Write (4,0,102,0);
    osSerdes2Write (4,0,103,108);
    osSerdes2Write (4,0,104,183);
    osSerdes2Write (4,0,105,183);
    osSerdes2Write (4,0,106,12);
    osSerdes2Write (4,0,107,12);
    osSerdes2Write (4,0,108,26);
    osSerdes2Write (4,0,109,26);
    osSerdes2Write (4,0,110,7);
    osSerdes2Write (4,0,111,12);
    osSerdes2Write (4,0,112,8);
    osSerdes2Write (4,0,113,0);
    osSerdes2Write (4,0,114,8);
    osSerdes2Write (4,0,115,0);
    osSerdes2Write (4,0,116,255);
    osSerdes2Write (4,0,117,179);
    osSerdes2Write (4,0,118,246);
    osSerdes2Write (4,0,119,208);
    osSerdes2Write (4,0,120,239);
    osSerdes2Write (4,0,121,251);
    osSerdes2Write (4,0,122,255);
    osSerdes2Write (4,0,123,255);
    osSerdes2Write (4,0,124,255);
    osSerdes2Write (4,0,125,255);
    osSerdes2Write (4,0,126,255);
    osSerdes2Write (4,0,127,211);
    osSerdes2Write (4,0,128,211);
    osSerdes2Write (4,0,129,226);
    osSerdes2Write (4,0,130,239);
    osSerdes2Write (4,0,131,251);
    osSerdes2Write (4,0,132,251);
    osSerdes2Write (4,0,133,255);
    osSerdes2Write (4,0,134,239);
    osSerdes2Write (4,0,135,255);
    osSerdes2Write (4,0,136,255);
    osSerdes2Write (4,0,137,211);
    osSerdes2Write (4,0,138,211);
    osSerdes2Write (4,0,139,226);
    osSerdes2Write (4,0,140,239);
    osSerdes2Write (4,0,141,251);
    osSerdes2Write (4,0,142,251);
    osSerdes2Write (4,0,143,255);
    osSerdes2Write (4,0,144,239);
    osSerdes2Write (4,0,145,255);
    osSerdes2Write (4,0,146,255);
    osSerdes2Write (4,0,147,251);
    osSerdes2Write (4,0,148,255);
    osSerdes2Write (4,0,149,63);
    osSerdes2Write (4,0,150,0);
    osSerdes2Write (4,0,151,100);
    osSerdes2Write (4,0,152,0);
    osSerdes2Write (4,0,153,4);
    osSerdes2Write (4,0,154,2);
    osSerdes2Write (4,0,155,5);
    osSerdes2Write (4,0,156,5);
    osSerdes2Write (4,0,157,4);
    osSerdes2Write (4,0,158,0);
    osSerdes2Write (4,0,159,0);
    osSerdes2Write (4,0,160,8);
    osSerdes2Write (4,0,161,4);
    osSerdes2Write (4,0,162,0);
    osSerdes2Write (4,0,163,0);
    osSerdes2Write (4,0,164,4);
    osSerdes2Write (0,0,7,0);
    osSerdes2Write (1,0,7,0);
    osSerdes2Write (2,0,7,0);
    osSerdes2Write (3,0,7,0);
    osSerdes2Write (4,0,13,16);
    osSerdes2Write (4,0,48,0);
    osSerdes2Write (4,0,49,0);
    osSerdes2Write (4,0,54,0);
    osSerdes2Write (4,0,55,180);
    osSerdes2Write (4,0,93,2);
    osSerdes2Write (4,0,165,2);
    osSerdes2Write (0,0,41,6);
    osSerdes2Write (1,0,41,6);
    osSerdes2Write (2,0,41,6);
    osSerdes2Write (3,0,41,6);
    osSerdes2Write (4,0,354,3);
    osSerdes2Write (4,0,355,58);
    osSerdes2Write (4,0,356,9);
    osSerdes2Write (4,0,357,3);
    osSerdes2Write (4,0,358,62);
    osSerdes2Write (4,0,359,12);
    osSerdes2Write (0,0,701,0);
    osSerdes2Write (1,0,701,0);
    osSerdes2Write (2,0,701,0);
    osSerdes2Write (3,0,701,0);
    osSerdesWait(0x1000000);
    // 6.   Overwrite
    //PCSOVR_ENABLE.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane);    Value
    //85[1:1]   LB_LOCWREN  7   0
    //85[4:4]   PCSRX_LOCWREN   7   0
    //85[7:7]   PCSTX_LOCWREN   7   0
    //95[4:4]   CMNPCSBIST_LOCWREN  4   0
    //86[0:0]   PCSTXBIST_LOCWREN   7   0
    //87[5:5]   TXDRV_LOCWREN   7   0
    //86[3:3]   RXCALEQ_LOCWREN 7   0
    //85[5:5]   PCSRXBIST_LOCWREN   7   0
    //95[2:2]   CMNPCIEGEN3_LOCWREN 4   0
    //95[5:5]   CMNPCSPSTATE_LOCWREN    4   0
    //86[4:4]   RXCALEYEDIAGFSMIN_LOCWREN   7   0
    //95[3:3]   CMNPCS_LOCWREN  4   0
    //85[0:0]   LANEPCSPSTATE_LOCWREN   7   0
    //230[0:0]  RXLOCK2REF_LOCWREN  7   0
    osSerdes2Write (0x0,0x0,0x55,0x4c);
    osSerdes2Write (0x0,0x0,0x56,0xe6);
    osSerdes2Write (0x0,0x0,0x57,0x1f);
    osSerdes2Write (0x0,0x0,0xe6,0xfe);

    osSerdes2Write (0x1,0x0,0x55,0x4c);
    osSerdes2Write (0x1,0x0,0x56,0xe6);
    osSerdes2Write (0x1,0x0,0x57,0x1f);
    osSerdes2Write (0x1,0x0,0xe6,0xfe);

    osSerdes2Write (0x2,0x0,0x55,0x4c);
    osSerdes2Write (0x2,0x0,0x56,0xe6);
    osSerdes2Write (0x2,0x0,0x57,0x1f);
    osSerdes2Write (0x2,0x0,0xe6,0xfe);

    osSerdes2Write (0x3,0x0,0x55,0x4c);
    osSerdes2Write (0x3,0x0,0x56,0xe6);
    osSerdes2Write (0x3,0x0,0x57,0x1f);
    osSerdes2Write (0x3,0x0,0xe6,0xfe);

    osSerdes2Write (0x4,0x0,0x5f,0xc3);
    osSerdesWait(0x1000000);
    // 7.   Set to IDDQ state
    //PCSPSTATE_IDDQ.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane);    Value
    //3[4:0]    LANEPCSPSTATE_RX    7   1
    //3[4:0]    CMNPCSPSTATE_SYNTH  4   1
    //4[4:0]    LANEPCSPSTATE_TX    7   1
    osSerdes2Write (0x0,0x0,0x3,0x1);
    osSerdes2Write (0x0,0x0,0x4,0x1);

    osSerdes2Write (0x1,0x0,0x3,0x1);
    osSerdes2Write (0x1,0x0,0x4,0x1);

    osSerdes2Write (0x2,0x0,0x3,0x1);
    osSerdes2Write (0x2,0x0,0x4,0x1);

    osSerdes2Write (0x3,0x0,0x3,0x1);
    osSerdes2Write (0x3,0x0,0x4,0x1);

    osSerdes2Write (0x4,0x0,0x3,0x1);
    osSerdesWait(0x1000000);
    // 8.   Release Hard Reset
    //HARDRST_NOT.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane);    Value
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASS     7   1
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASS_SYNTH   4   1
    osSerdes2Write (0x0,0x0,0x2,0x3);
    osSerdes2Write (0x1,0x0,0x2,0x3);
    osSerdes2Write (0x2,0x0,0x2,0x3);
    osSerdes2Write (0x3,0x0,0x2,0x3);
    osSerdes2Write (0x4,0x0,0x2,0x3);
    osSerdesWait(0x1000000);
    // 9(1);. PRBS pattern
    //TXBIST_PRBS7.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane);    Value
    //80[2:0]   CMNPCSBIST_MODESEL  4   1
    //prbs7
    osSerdes2Write (0x4,0x0,0x50,0x1);
    //prbs23
    //osSerdes2Write (0x4,0x0,0x50,0x2);
    //prbs31
    //osSerdes2Write (0x4,0x0,0x50,0x3);
    osSerdesWait(0x1000000);
    // 10.  RXEQ setting
    //RXEQ.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane);    Value
    //83[0:0]   RXAGC_DCCOUPLEEN    4   0
    //24[2:0]   RXCALEQ_DCGAIN      7   0
    //27[6:4]   RXCALEQ_LOFREQAGCGAIN   7   7
    //28[7:3]   RXCALEQ_HIFREQAGCCAP    7   0
    //25[2:0]   RXCALEQ_DFEPSTAPGAIN    7   0
    //24[5:3]   RXCALEQ_DFEPSTAPF3DB    7   0
    //25[6:3]   RXCALEQ_DFETAP1GAIN 7   0
    //26[3:0]   RXCALEQ_DFETAP2GAIN 7   8
    //26[7:4]   RXCALEQ_DFETAP3GAIN 7   0
    //27[3:0]   RXCALEQ_DFETAP4GAIN 7   8
    osSerdes2Write (0x0,0x0,0x18,0x0);
    osSerdes2Write (0x0,0x0,0x19,0x0);
    osSerdes2Write (0x0,0x0,0x1a,0x8);
    osSerdes2Write (0x0,0x0,0x1b,0x78);
    osSerdes2Write (0x0,0x0,0x1c,0x0);

    osSerdes2Write (0x1,0x0,0x18,0x0);
    osSerdes2Write (0x1,0x0,0x19,0x0);
    osSerdes2Write (0x1,0x0,0x1a,0x8);
    osSerdes2Write (0x1,0x0,0x1b,0x78);
    osSerdes2Write (0x1,0x0,0x1c,0x0);

    osSerdes2Write (0x2,0x0,0x18,0x0);
    osSerdes2Write (0x2,0x0,0x19,0x0);
    osSerdes2Write (0x2,0x0,0x1a,0x8);
    osSerdes2Write (0x2,0x0,0x1b,0x78);
    osSerdes2Write (0x2,0x0,0x1c,0x0);

    osSerdes2Write (0x3,0x0,0x18,0x0);
    osSerdes2Write (0x3,0x0,0x19,0x0);
    osSerdes2Write (0x3,0x0,0x1a,0x8);
    osSerdes2Write (0x3,0x0,0x1b,0x78);
    osSerdes2Write (0x3,0x0,0x1c,0x0);

    osSerdes2Write (0x4,0x0,0x53,0x2);
    osSerdesWait(0x1000000);
    // 11.  TXIODRIVER setting
    //TXIODRIVER.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane);    Value
    //21[2:0]   TXDRV_HLEV  7   7
    //21[7:3]   TXDRV_LEVN  7   1b
    //22[3:0]   TXDRV_LEVNM1    7   0
    //22[5:4]   TXDRV_LEVNM2    7   0
    //23[2:0]   TXDRV_LEVNP1    7   0
    //23[4:3]   TXDRV_SLEW  7   0
    osSerdes2Write (0x0,0x0,0x15,0xdf);
    osSerdes2Write (0x0,0x0,0x16,0x0);
    osSerdes2Write (0x0,0x0,0x17,0x0);

    osSerdes2Write (0x1,0x0,0x15,0xdf);
    osSerdes2Write (0x1,0x0,0x16,0x0);
    osSerdes2Write (0x1,0x0,0x17,0x0);

    osSerdes2Write (0x2,0x0,0x15,0xdf);
    osSerdes2Write (0x2,0x0,0x16,0x0);
    osSerdes2Write (0x2,0x0,0x17,0x0);

    osSerdes2Write (0x3,0x0,0x15,0xdf);
    osSerdes2Write (0x3,0x0,0x16,0x0);
    osSerdes2Write (0x3,0x0,0x17,0x0);
    osSerdesWait(0x1000000);
    // 12.  Change Data Width to 10 bits
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane);    Value
    //5[6:4]    PCSTX_DATAWIDTH 7   1
    //5[2:0]    PCSRX_DATAWIDTH 7   1
    osSerdes2Write (0x0,0x0,0x5,0x11);
    osSerdes2Write (0x1,0x0,0x5,0x11);
    osSerdes2Write (0x2,0x0,0x5,0x11);
    osSerdes2Write (0x3,0x0,0x5,0x11);
    osSerdesWait(0x1000000);
    // 13.  Change DIVRATE
    //RXPCSDATARATE_DIV4.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane);    Value
    //6[2:0]    PCSRX_DIVRATE   7   1
    //TXPCSDATARATE_DIV4.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane);    Value
    //6[6:4]    PCSTX_DIVRATE   7   1
    osSerdes2Write (0x0,0x0,0x6,0x11);
    osSerdes2Write (0x1,0x0,0x6,0x11);
    osSerdes2Write (0x2,0x0,0x6,0x11);
    osSerdes2Write (0x3,0x0,0x6,0x11);
    osSerdesWait(0x1000000);
    // 15.  Enable PCS TX
    //CMNPCS_TXENABLE.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane);    Value
    //8[2:2]    CMNPCS_TXENABLE 4   1
    osSerdes2Write (0x4,0x0,0x8,0x54);

    osSerdesWait(0x1000000);
    // 16.  Overwrite Enable for Lock2Ref
    //RXLOCK2REF_OVREN.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane);    Value
    //39[1:1]   RXLOCK2REF_OVREN    7   1
    osSerdes2Write (0x0,0x0,0x27,0x2);
    osSerdes2Write (0x1,0x0,0x27,0x2);
    osSerdes2Write (0x2,0x0,0x27,0x2);
    osSerdes2Write (0x3,0x0,0x27,0x2);
    osSerdesWait(0x1000000);
    // 17.  Power Up to P0
    //PCSPSTATE_P0.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane);    Value
    //3[4:0]    LANEPCSPSTATE_RX    7   10
    //3[4:0]    CMNPCSPSTATE_SYNTH  4   10
    //4[4:0]    LANEPCSPSTATE_TX    7   10
    osSerdes2Write (0x0,0x0,0x3,0x10);
    osSerdes2Write (0x0,0x0,0x4,0x10);

    osSerdes2Write (0x1,0x0,0x3,0x10);
    osSerdes2Write (0x1,0x0,0x4,0x10);

    osSerdes2Write (0x2,0x0,0x3,0x10);
    osSerdes2Write (0x2,0x0,0x4,0x10);

    osSerdes2Write (0x3,0x0,0x3,0x10);
    osSerdes2Write (0x3,0x0,0x4,0x10);

    osSerdes2Write (0x4,0x0,0x3,0x10);
#if 0
    // 18.  Read out critical status registers
    //PCSOUTTX_READY    7   11[2:2]     r   expected: 1
    //PCSOUTRX_READY    7   11[0:0]     r   expected: 1
    osSerdes2Read (0x0,0x0,11);
    osSerdes2Read (0x1,0x0,11);
    osSerdes2Read (0x2,0x0,11);
    osSerdes2Read (0x3,0x0,11);
#endif
    osSerdesWait(0x1000000);
    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl1_base_addr+0x400],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
    ulValue = ulValue & 0xFF0;
#if SERDES_DEBUG_OPEN
    SRE_printf( "check IOCTRL1_BASE_ADDR + 0x400 == 0xff0\n" );
#else
    while ( -- ulWaitTime)
    {
        if( ulValue != 0xFF0 )
        {
            ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
            ulValue = ulValue & 0xFF0;
        }
        else
        {
            break;
        }
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
#endif
    return OS_SUCCESS;

}


/*****************************************************************
函数名 :  osSerdes2InitSrio2g5
输入参数    :   None
输出参数      :
Description   :  macro2   Lane0~3初始化为SRIO 2.5G
Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes2InitSrio2g5(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    //*********************************************************
    //serdes2  initialization:init_macro2_srio_2g5
    //*********************************************************
    //1.    POR
    osSerdesBitWrite(SRE_SC_SERDES_RESET_REQ1_REG,0x80000,0xffffffff);

    //1(1) set multi-mode:
    osSerdesBitWrite(IOCTRL1_BASE_ADDR + 0x00c,0x1400,0xFFFFF7FF);

    //1(2) set pcie-mode:
    //osSerdesBitWrite(IOCTRL1_BASE_ADDR + 0x00c,0x1c00,0xFFFFFFFF);

    //2.    Release POR
    osSerdesBitWrite(SRE_SC_SERDES_RESET_DREQ1_REG,0x80000,0xffffffff);
    osSerdesWait(0x1000000);
    //3.    Enable Hard Reset
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASSEN   7   1
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASSEN_SYNTH 4   1
    //4.    Hard Reset
    //HARDRST.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASS     7   0
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASS_SYNTH   4   0
    osSerdes2Write(0x0,0x0,0x2,0x2);
    osSerdes2Write(0x1,0x0,0x2,0x2);
    osSerdes2Write(0x2,0x0,0x2,0x2);
    osSerdes2Write(0x3,0x0,0x2,0x2);
    osSerdes2Write(0x4,0x0,0x2,0x1);
    osSerdesWait(0x1000000);
    // 5.   Load Different Data Rate Settings
    //load the 1.25Gbps_156.25MHz_VSM.txt
    osSerdes2Write(0,0,101,183);
    osSerdes2Write(0,0,102,183);
    osSerdes2Write(0,0,103,12);
    osSerdes2Write(0,0,104,12);
    osSerdes2Write(0,0,105,26);
    osSerdes2Write(0,0,106,26);
    osSerdes2Write(0,0,107,2);
    osSerdes2Write(0,0,108,2);
    osSerdes2Write(0,0,109,17);
    osSerdes2Write(0,0,110,13);
    osSerdes2Write(1,0,101,183);
    osSerdes2Write(1,0,102,183);
    osSerdes2Write(1,0,103,12);
    osSerdes2Write(1,0,104,12);
    osSerdes2Write(1,0,105,26);
    osSerdes2Write(1,0,106,26);
    osSerdes2Write(1,0,107,2);
    osSerdes2Write(1,0,108,2);
    osSerdes2Write(1,0,109,17);
    osSerdes2Write(1,0,110,13);
    osSerdes2Write(2,0,101,183);
    osSerdes2Write(2,0,102,183);
    osSerdes2Write(2,0,103,12);
    osSerdes2Write(2,0,104,12);
    osSerdes2Write(2,0,105,26);
    osSerdes2Write(2,0,106,26);
    osSerdes2Write(2,0,107,2);
    osSerdes2Write(2,0,108,2);
    osSerdes2Write(2,0,109,17);
    osSerdes2Write(2,0,110,13);
    osSerdes2Write(3,0,101,183);
    osSerdes2Write(3,0,102,183);
    osSerdes2Write(3,0,103,12);
    osSerdes2Write(3,0,104,12);
    osSerdes2Write(3,0,105,26);
    osSerdes2Write(3,0,106,26);
    osSerdes2Write(3,0,107,2);
    osSerdes2Write(3,0,108,2);
    osSerdes2Write(3,0,109,17);
    osSerdes2Write(3,0,110,13);
    osSerdes2Write(4,0,101,153);
    osSerdes2Write(4,0,102,0);
    osSerdes2Write(4,0,103,108);
    osSerdes2Write(4,0,104,183);
    osSerdes2Write(4,0,105,183);
    osSerdes2Write(4,0,106,12);
    osSerdes2Write(4,0,107,12);
    osSerdes2Write(4,0,108,26);
    osSerdes2Write(4,0,109,26);
    osSerdes2Write(4,0,110,7);
    osSerdes2Write(4,0,111,12);
    osSerdes2Write(4,0,112,8);
    osSerdes2Write(4,0,113,0);
    osSerdes2Write(4,0,114,8);
    osSerdes2Write(4,0,115,0);
    osSerdes2Write(4,0,116,255);
    osSerdes2Write(4,0,117,179);
    osSerdes2Write(4,0,118,246);
    osSerdes2Write(4,0,119,208);
    osSerdes2Write(4,0,120,239);
    osSerdes2Write(4,0,121,251);
    osSerdes2Write(4,0,122,255);
    osSerdes2Write(4,0,123,255);
    osSerdes2Write(4,0,124,255);
    osSerdes2Write(4,0,125,255);
    osSerdes2Write(4,0,126,255);
    osSerdes2Write(4,0,127,211);
    osSerdes2Write(4,0,128,211);
    osSerdes2Write(4,0,129,226);
    osSerdes2Write(4,0,130,239);
    osSerdes2Write(4,0,131,251);
    osSerdes2Write(4,0,132,251);
    osSerdes2Write(4,0,133,255);
    osSerdes2Write(4,0,134,239);
    osSerdes2Write(4,0,135,255);
    osSerdes2Write(4,0,136,255);
    osSerdes2Write(4,0,137,211);
    osSerdes2Write(4,0,138,211);
    osSerdes2Write(4,0,139,226);
    osSerdes2Write(4,0,140,239);
    osSerdes2Write(4,0,141,251);
    osSerdes2Write(4,0,142,251);
    osSerdes2Write(4,0,143,255);
    osSerdes2Write(4,0,144,239);
    osSerdes2Write(4,0,145,255);
    osSerdes2Write(4,0,146,255);
    osSerdes2Write(4,0,147,251);
    osSerdes2Write(4,0,148,255);
    osSerdes2Write(4,0,149,63);
    osSerdes2Write(4,0,150,0);
    osSerdes2Write(4,0,151,100);
    osSerdes2Write(4,0,152,0);
    osSerdes2Write(4,0,153,4);
    osSerdes2Write(4,0,154,2);
    osSerdes2Write(4,0,155,5);
    osSerdes2Write(4,0,156,5);
    osSerdes2Write(4,0,157,4);
    osSerdes2Write(4,0,158,0);
    osSerdes2Write(4,0,159,0);
    osSerdes2Write(4,0,160,8);
    osSerdes2Write(4,0,161,4);
    osSerdes2Write(4,0,162,0);
    osSerdes2Write(4,0,163,0);
    osSerdes2Write(4,0,164,4);
    osSerdes2Write(0,0,7,0);
    osSerdes2Write(1,0,7,0);
    osSerdes2Write(2,0,7,0);
    osSerdes2Write(3,0,7,0);
    osSerdes2Write(4,0,13,16);
    osSerdes2Write(4,0,48,0);
    osSerdes2Write(4,0,49,0);
    osSerdes2Write(4,0,54,0);
    osSerdes2Write(4,0,55,180);
    osSerdes2Write(4,0,93,2);
    osSerdes2Write(4,0,165,2);
    osSerdes2Write(0,0,41,6);
    osSerdes2Write(1,0,41,6);
    osSerdes2Write(2,0,41,6);
    osSerdes2Write(3,0,41,6);
    osSerdes2Write(4,0,354,3);
    osSerdes2Write(4,0,355,58);
    osSerdes2Write(4,0,356,9);
    osSerdes2Write(4,0,357,3);
    osSerdes2Write(4,0,358,62);
    osSerdes2Write(4,0,359,12);
    osSerdes2Write(0,0,701,0);
    osSerdes2Write(1,0,701,0);
    osSerdes2Write(2,0,701,0);
    osSerdes2Write(3,0,701,0);

    osSerdesWait(0x1000000);
    // 6.   Overwrite
    //PCSOVR_ENABLE.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //85[1:1]   LB_LOCWREN  7   0
    //85[4:4]   PCSRX_LOCWREN   7   0
    //85[7:7]   PCSTX_LOCWREN   7   0
    //95[4:4]   CMNPCSBIST_LOCWREN  4   0
    //86[0:0]   PCSTXBIST_LOCWREN   7   0
    //87[5:5]   TXDRV_LOCWREN   7   0
    //86[3:3]   RXCALEQ_LOCWREN 7   0
    //85[5:5]   PCSRXBIST_LOCWREN   7   0
    //95[2:2]   CMNPCIEGEN3_LOCWREN 4   0
    //95[5:5]   CMNPCSPSTATE_LOCWREN    4   0
    //86[4:4]   RXCALEYEDIAGFSMIN_LOCWREN   7   0
    //95[3:3]   CMNPCS_LOCWREN  4   0
    //85[0:0]   LANEPCSPSTATE_LOCWREN   7   0
    //230[0:0]  RXLOCK2REF_LOCWREN  7   0
    osSerdes2Write(0x0,0x0,0x55,0x4c);
    osSerdes2Write(0x0,0x0,0x56,0xe6);
    osSerdes2Write(0x0,0x0,0x57,0x1f);
    osSerdes2Write(0x0,0x0,0xe6,0xfe);

    osSerdes2Write(0x1,0x0,0x55,0x4c);
    osSerdes2Write(0x1,0x0,0x56,0xe6);
    osSerdes2Write(0x1,0x0,0x57,0x1f);
    osSerdes2Write(0x1,0x0,0xe6,0xfe);

    osSerdes2Write(0x2,0x0,0x55,0x4c);
    osSerdes2Write(0x2,0x0,0x56,0xe6);
    osSerdes2Write(0x2,0x0,0x57,0x1f);
    osSerdes2Write(0x2,0x0,0xe6,0xfe);

    osSerdes2Write(0x3,0x0,0x55,0x4c);
    osSerdes2Write(0x3,0x0,0x56,0xe6);
    osSerdes2Write(0x3,0x0,0x57,0x1f);
    osSerdes2Write(0x3,0x0,0xe6,0xfe);

    osSerdes2Write(0x4,0x0,0x5f,0xc3);
    osSerdesWait(0x1000000);
    // 7.   Set to IDDQ state
    //PCSPSTATE_IDDQ.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //3[4:0]    LANEPCSPSTATE_RX    7   1
    //3[4:0]    CMNPCSPSTATE_SYNTH  4   1
    //4[4:0]    LANEPCSPSTATE_TX    7   1
    osSerdes2Write(0x0,0x0,0x3,0x1);
    osSerdes2Write(0x0,0x0,0x4,0x1);

    osSerdes2Write(0x1,0x0,0x3,0x1);
    osSerdes2Write(0x1,0x0,0x4,0x1);

    osSerdes2Write(0x2,0x0,0x3,0x1);
    osSerdes2Write(0x2,0x0,0x4,0x1);

    osSerdes2Write(0x3,0x0,0x3,0x1);
    osSerdes2Write(0x3,0x0,0x4,0x1);

    osSerdes2Write(0x4,0x0,0x3,0x1);
    osSerdesWait(0x1000000);
    // 8.   Release Hard Reset
    //HARDRST_NOT.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASS     7   1
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASS_SYNTH   4   1
    osSerdes2Write(0x0,0x0,0x2,0x3);
    osSerdes2Write(0x1,0x0,0x2,0x3);
    osSerdes2Write(0x2,0x0,0x2,0x3);
    osSerdes2Write(0x3,0x0,0x2,0x3);
    osSerdes2Write(0x4,0x0,0x2,0x3);
    osSerdesWait(0x1000000);
    // 9(1). PRBS pattern
    //TXBIST_PRBS7.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //80[2:0]   CMNPCSBIST_MODESEL  4   1
    //clock pattern
    //osSerdes2Write(0x4,0x0,0x50,0x0);
    //prbs7
    osSerdes2Write(0x4,0x0,0x50,0x1);
    //prbs23
    //osSerdes2Write(0x4,0x0,0x50,0x2);
    //prbs31
    //osSerdes2Write(0x4,0x0,0x50,0x3);
    osSerdesWait(0x1000000);
    // 10.  RXEQ setting
    //RXEQ.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //83[0:0]   RXAGC_DCCOUPLEEN    4   0
    //24[2:0]   RXCALEQ_DCGAIN      7   0
    //27[6:4]   RXCALEQ_LOFREQAGCGAIN   7   7
    //28[7:3]   RXCALEQ_HIFREQAGCCAP    7   0
    //25[2:0]   RXCALEQ_DFEPSTAPGAIN    7   0
    //24[5:3]   RXCALEQ_DFEPSTAPF3DB    7   0
    //25[6:3]   RXCALEQ_DFETAP1GAIN 7   0
    //26[3:0]   RXCALEQ_DFETAP2GAIN 7   8
    //26[7:4]   RXCALEQ_DFETAP3GAIN 7   0
    //27[3:0]   RXCALEQ_DFETAP4GAIN 7   8
    osSerdes2Write(0x0,0x0,0x18,0x0);
    osSerdes2Write(0x0,0x0,0x19,0x0);
    osSerdes2Write(0x0,0x0,0x1a,0x8);
    osSerdes2Write(0x0,0x0,0x1b,0x78);
    osSerdes2Write(0x0,0x0,0x1c,0x0);

    osSerdes2Write(0x1,0x0,0x18,0x0);
    osSerdes2Write(0x1,0x0,0x19,0x0);
    osSerdes2Write(0x1,0x0,0x1a,0x8);
    osSerdes2Write(0x1,0x0,0x1b,0x78);
    osSerdes2Write(0x1,0x0,0x1c,0x0);

    osSerdes2Write(0x2,0x0,0x18,0x0);
    osSerdes2Write(0x2,0x0,0x19,0x0);
    osSerdes2Write(0x2,0x0,0x1a,0x8);
    osSerdes2Write(0x2,0x0,0x1b,0x78);
    osSerdes2Write(0x2,0x0,0x1c,0x0);

    osSerdes2Write(0x3,0x0,0x18,0x0);
    osSerdes2Write(0x3,0x0,0x19,0x0);
    osSerdes2Write(0x3,0x0,0x1a,0x8);
    osSerdes2Write(0x3,0x0,0x1b,0x78);
    osSerdes2Write(0x3,0x0,0x1c,0x0);

    osSerdes2Write(0x4,0x0,0x53,0x2);
    osSerdesWait(0x1000000);
    // 11.  TXIODRIVER setting
    //TXIODRIVER.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //21[2:0]   TXDRV_HLEV  7   7
    //21[7:3]   TXDRV_LEVN  7   1b
    //22[3:0]   TXDRV_LEVNM1    7   0
    //22[5:4]   TXDRV_LEVNM2    7   0
    //23[2:0]   TXDRV_LEVNP1    7   0
    //23[4:3]   TXDRV_SLEW  7   0
    osSerdes2Write(0x0,0x0,0x15,0xdf);
    osSerdes2Write(0x0,0x0,0x16,0x0);
    osSerdes2Write(0x0,0x0,0x17,0x0);

    osSerdes2Write(0x1,0x0,0x15,0xdf);
    osSerdes2Write(0x1,0x0,0x16,0x0);
    osSerdes2Write(0x1,0x0,0x17,0x0);

    osSerdes2Write(0x2,0x0,0x15,0xdf);
    osSerdes2Write(0x2,0x0,0x16,0x0);
    osSerdes2Write(0x2,0x0,0x17,0x0);

    osSerdes2Write(0x3,0x0,0x15,0xdf);
    osSerdes2Write(0x3,0x0,0x16,0x0);
    osSerdes2Write(0x3,0x0,0x17,0x0);
    osSerdesWait(0x1000000);
    // 12.  Change Data Width to 10 bits
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //5[6:4]    PCSTX_DATAWIDTH 7   1
    //5[2:0]    PCSRX_DATAWIDTH 7   1
    osSerdes2Write(0x0,0x0,0x5,0x11);
    osSerdes2Write(0x1,0x0,0x5,0x11);
    osSerdes2Write(0x2,0x0,0x5,0x11);
    osSerdes2Write(0x3,0x0,0x5,0x11);
    osSerdesWait(0x1000000);
    // 13.  Change DIVRATE
    //RXPCSDATARATE_DIV2.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //6[2:0]    PCSRX_DIVRATE   7   2
    //TXPCSDATARATE_DIV2.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //6[6:4]    PCSTX_DIVRATE   7   2
    osSerdes2Write(0x0,0x0,0x6,0x22);
    osSerdes2Write(0x1,0x0,0x6,0x22);
    osSerdes2Write(0x2,0x0,0x6,0x22);
    osSerdes2Write(0x3,0x0,0x6,0x22);
    osSerdesWait(0x1000000);
    // 15.  Enable PCS TX
    //CMNPCS_TXENABLE.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //8[2:2]    CMNPCS_TXENABLE 4   1
    osSerdes2Write(0x4,0x0,0x8,0x54);

    osSerdesWait(0x1000000);
    // 16.  Overwrite Enable for Lock2Ref
    //RXLOCK2REF_OVREN.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //39[1:1]   RXLOCK2REF_OVREN    7   1
    osSerdes2Write(0x0,0x0,0x27,0x2);
    osSerdes2Write(0x1,0x0,0x27,0x2);
    osSerdes2Write(0x2,0x0,0x27,0x2);
    osSerdes2Write(0x3,0x0,0x27,0x2);
    osSerdesWait(0x1000000);
    // 17.  Power Up to P0
    //PCSPSTATE_P0.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //3[4:0]    LANEPCSPSTATE_RX    7   10
    //3[4:0]    CMNPCSPSTATE_SYNTH  4   10
    //4[4:0]    LANEPCSPSTATE_TX    7   10
    osSerdes2Write(0x0,0x0,0x3,0x10);
    osSerdes2Write(0x0,0x0,0x4,0x10);

    osSerdes2Write(0x1,0x0,0x3,0x10);
    osSerdes2Write(0x1,0x0,0x4,0x10);

    osSerdes2Write(0x2,0x0,0x3,0x10);
    osSerdes2Write(0x2,0x0,0x4,0x10);

    osSerdes2Write(0x3,0x0,0x3,0x10);
    osSerdes2Write(0x3,0x0,0x4,0x10);

    osSerdes2Write(0x4,0x0,0x3,0x10);
    osSerdesWait(0x1000000);
    // 18.  Read out critical status registers
    //PCSOUTTX_READY    7   11[2:2]     r   expected: 1
    //PCSOUTRX_READY    7   11[0:0]     r   expected: 1
    osSerdes2Read(0x0,0x0,11);
    osSerdes2Read(0x1,0x0,11);
    osSerdes2Read(0x2,0x0,11);
    osSerdes2Read(0x3,0x0,11);
    osSerdesWait(0x1000000);
    //the initialization is finished
    //*********************************************************

    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl1_base_addr+0x400],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;

}

/*****************************************************************
函数名 :  osSerdes2InitSrio3g125
输入参数    :   None
输出参数      :
Description   :  macro2   Lane0~3初始化为SRIO 3.125G
Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes2InitSrio3g125(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    //*********************************************************
    //serdes2  initialization:init_macro2_srio_3g125
    //*********************************************************
    //1.    POR
    osSerdesBitWrite (SRE_SC_SERDES_RESET_REQ1_REG,0x80000,0xffffffff);

    //1(1) set multi-mode:
    osSerdesBitWrite(IOCTRL1_BASE_ADDR + 0x00c,0x1400,0xFFFFF7FF);

    //1(2) set pcie-mode:
    //osSerdesBitWrite(IOCTRL1_BASE_ADDR + 00c,0x1c00,0xFFFFFFFF);

    //2.    Release POR
    osSerdesBitWrite(SRE_SC_SERDES_RESET_DREQ1_REG,0x80000,0xffffffff);
    osSerdesWait(0x1000000);
    //3.    Enable Hard Reset
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASSEN   7   1
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASSEN_SYNTH 4   1
    //4.    Hard Reset
    //HARDRST.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASS     7   0
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASS_SYNTH   4   0
    osSerdes2Write(0x0,0x0,0x2,0x2);
    osSerdes2Write(0x1,0x0,0x2,0x2);
    osSerdes2Write(0x2,0x0,0x2,0x2);
    osSerdes2Write(0x3,0x0,0x2,0x2);
    osSerdes2Write(0x4,0x0,0x2,0x1);
    osSerdesWait(0x1000000);
    // 5.   Load Different Data Rate Settings
    //3.125Gbps_156.25MHz_VSM.txt
    osSerdes2Write(0,0,101,191);
    osSerdes2Write(0,0,102,191);
    osSerdes2Write(0,0,103,10);
    osSerdes2Write(0,0,104,10);
    osSerdes2Write(0,0,105,14);
    osSerdes2Write(0,0,106,14);
    osSerdes2Write(0,0,107,1);
    osSerdes2Write(0,0,108,1);
    osSerdes2Write(0,0,109,34);
    osSerdes2Write(0,0,110,13);
    osSerdes2Write(1,0,101,191);
    osSerdes2Write(1,0,102,191);
    osSerdes2Write(1,0,103,10);
    osSerdes2Write(1,0,104,10);
    osSerdes2Write(1,0,105,14);
    osSerdes2Write(1,0,106,14);
    osSerdes2Write(1,0,107,1);
    osSerdes2Write(1,0,108,1);
    osSerdes2Write(1,0,109,34);
    osSerdes2Write(1,0,110,13);
    osSerdes2Write(2,0,101,191);
    osSerdes2Write(2,0,102,191);
    osSerdes2Write(2,0,103,10);
    osSerdes2Write(2,0,104,10);
    osSerdes2Write(2,0,105,14);
    osSerdes2Write(2,0,106,14);
    osSerdes2Write(2,0,107,1);
    osSerdes2Write(2,0,108,1);
    osSerdes2Write(2,0,109,34);
    osSerdes2Write(2,0,110,13);
    osSerdes2Write(3,0,101,191);
    osSerdes2Write(3,0,102,191);
    osSerdes2Write(3,0,103,10);
    osSerdes2Write(3,0,104,10);
    osSerdes2Write(3,0,105,14);
    osSerdes2Write(3,0,106,14);
    osSerdes2Write(3,0,107,1);
    osSerdes2Write(3,0,108,1);
    osSerdes2Write(3,0,109,34);
    osSerdes2Write(3,0,110,13);
    osSerdes2Write(4,0,101,170);
    osSerdes2Write(4,0,102,0);
    osSerdes2Write(4,0,103,108);
    osSerdes2Write(4,0,104,191);
    osSerdes2Write(4,0,105,191);
    osSerdes2Write(4,0,106,10);
    osSerdes2Write(4,0,107,10);
    osSerdes2Write(4,0,108,14);
    osSerdes2Write(4,0,109,14);
    osSerdes2Write(4,0,110,7);
    osSerdes2Write(4,0,111,12);
    osSerdes2Write(4,0,112,16);
    osSerdes2Write(4,0,113,0);
    osSerdes2Write(4,0,114,16);
    osSerdes2Write(4,0,115,0);
    osSerdes2Write(4,0,116,255);
    osSerdes2Write(4,0,117,179);
    osSerdes2Write(4,0,118,246);
    osSerdes2Write(4,0,119,208);
    osSerdes2Write(4,0,120,239);
    osSerdes2Write(4,0,121,251);
    osSerdes2Write(4,0,122,255);
    osSerdes2Write(4,0,123,255);
    osSerdes2Write(4,0,124,255);
    osSerdes2Write(4,0,125,255);
    osSerdes2Write(4,0,126,255);
    osSerdes2Write(4,0,127,211);
    osSerdes2Write(4,0,128,211);
    osSerdes2Write(4,0,129,226);
    osSerdes2Write(4,0,130,239);
    osSerdes2Write(4,0,131,251);
    osSerdes2Write(4,0,132,251);
    osSerdes2Write(4,0,133,255);
    osSerdes2Write(4,0,134,239);
    osSerdes2Write(4,0,135,255);
    osSerdes2Write(4,0,136,255);
    osSerdes2Write(4,0,137,211);
    osSerdes2Write(4,0,138,211);
    osSerdes2Write(4,0,139,226);
    osSerdes2Write(4,0,140,239);
    osSerdes2Write(4,0,141,251);
    osSerdes2Write(4,0,142,251);
    osSerdes2Write(4,0,143,255);
    osSerdes2Write(4,0,144,239);
    osSerdes2Write(4,0,145,255);
    osSerdes2Write(4,0,146,255);
    osSerdes2Write(4,0,147,251);
    osSerdes2Write(4,0,148,255);
    osSerdes2Write(4,0,149,63);
    osSerdes2Write(4,0,150,0);
    osSerdes2Write(4,0,151,100);
    osSerdes2Write(4,0,152,0);
    osSerdes2Write(4,0,153,2);
    osSerdes2Write(4,0,154,1);
    osSerdes2Write(4,0,155,5);
    osSerdes2Write(4,0,156,5);
    osSerdes2Write(4,0,157,4);
    osSerdes2Write(4,0,158,0);
    osSerdes2Write(4,0,159,0);
    osSerdes2Write(4,0,160,8);
    osSerdes2Write(4,0,161,4);
    osSerdes2Write(4,0,162,0);
    osSerdes2Write(4,0,163,0);
    osSerdes2Write(4,0,164,4);
    osSerdes2Write(0,0,7,0);
    osSerdes2Write(1,0,7,0);
    osSerdes2Write(2,0,7,0);
    osSerdes2Write(3,0,7,0);
    osSerdes2Write(4,0,13,16);
    osSerdes2Write(4,0,48,0);
    osSerdes2Write(4,0,49,0);
    osSerdes2Write(4,0,54,0);
    osSerdes2Write(4,0,55,156);
    osSerdes2Write(4,0,93,2);
    osSerdes2Write(4,0,165,2);
    osSerdes2Write(0,0,41,6);
    osSerdes2Write(1,0,41,6);
    osSerdes2Write(2,0,41,6);
    osSerdes2Write(3,0,41,6);
    osSerdes2Write(4,0,354,3);
    osSerdes2Write(4,0,355,58);
    osSerdes2Write(4,0,356,9);
    osSerdes2Write(4,0,357,3);
    osSerdes2Write(4,0,358,62);
    osSerdes2Write(4,0,359,12);
    osSerdes2Write(0,0,701,0);
    osSerdes2Write(1,0,701,0);
    osSerdes2Write(2,0,701,0);
    osSerdes2Write(3,0,701,0);

    osSerdesWait(0x1000000);
    // 6.   Overwrite
    //PCSOVR_ENABLE.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //85[1:1]   LB_LOCWREN  7   0
    //85[4:4]   PCSRX_LOCWREN   7   0
    //85[7:7]   PCSTX_LOCWREN   7   0
    //95[4:4]   CMNPCSBIST_LOCWREN  4   0
    //86[0:0]   PCSTXBIST_LOCWREN   7   0
    //87[5:5]   TXDRV_LOCWREN   7   0
    //86[3:3]   RXCALEQ_LOCWREN 7   0
    //85[5:5]   PCSRXBIST_LOCWREN   7   0
    //95[2:2]   CMNPCIEGEN3_LOCWREN 4   0
    //95[5:5]   CMNPCSPSTATE_LOCWREN    4   0
    //86[4:4]   RXCALEYEDIAGFSMIN_LOCWREN   7   0
    //95[3:3]   CMNPCS_LOCWREN  4   0
    //85[0:0]   LANEPCSPSTATE_LOCWREN   7   0
    //230[0:0]  RXLOCK2REF_LOCWREN  7   0
    osSerdes2Write(0x0,0x0,0x55,0x4c);
    osSerdes2Write(0x0,0x0,0x56,0xe6);
    osSerdes2Write(0x0,0x0,0x57,0x1f);
    osSerdes2Write(0x0,0x0,0xe6,0xfe);

    osSerdes2Write(0x1,0x0,0x55,0x4c);
    osSerdes2Write(0x1,0x0,0x56,0xe6);
    osSerdes2Write(0x1,0x0,0x57,0x1f);
    osSerdes2Write(0x1,0x0,0xe6,0xfe);

    osSerdes2Write(0x2,0x0,0x55,0x4c);
    osSerdes2Write(0x2,0x0,0x56,0xe6);
    osSerdes2Write(0x2,0x0,0x57,0x1f);
    osSerdes2Write(0x2,0x0,0xe6,0xfe);

    osSerdes2Write(0x3,0x0,0x55,0x4c);
    osSerdes2Write(0x3,0x0,0x56,0xe6);
    osSerdes2Write(0x3,0x0,0x57,0x1f);
    osSerdes2Write(0x3,0x0,0xe6,0xfe);

    osSerdes2Write(0x4,0x0,0x5f,0xc3);
    osSerdesWait(0x1000000);
    // 7.   Set to IDDQ state
    //PCSPSTATE_IDDQ.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //3[4:0]    LANEPCSPSTATE_RX    7   1
    //3[4:0]    CMNPCSPSTATE_SYNTH  4   1
    //4[4:0]    LANEPCSPSTATE_TX    7   1
    osSerdes2Write(0x0,0x0,0x3,0x1);
    osSerdes2Write(0x0,0x0,0x4,0x1);

    osSerdes2Write(0x1,0x0,0x3,0x1);
    osSerdes2Write(0x1,0x0,0x4,0x1);

    osSerdes2Write(0x2,0x0,0x3,0x1);
    osSerdes2Write(0x2,0x0,0x4,0x1);

    osSerdes2Write(0x3,0x0,0x3,0x1);
    osSerdes2Write(0x3,0x0,0x4,0x1);

    osSerdes2Write(0x4,0x0,0x3,0x1);
    osSerdesWait(0x1000000);
    // 8.   Release Hard Reset
    //HARDRST_NOT.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASS     7   1
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASS_SYNTH   4   1
    osSerdes2Write(0x0,0x0,0x2,0x3);
    osSerdes2Write(0x1,0x0,0x2,0x3);
    osSerdes2Write(0x2,0x0,0x2,0x3);
    osSerdes2Write(0x3,0x0,0x2,0x3);
    osSerdes2Write(0x4,0x0,0x2,0x3);
    osSerdesWait(0x1000000);
    // 9(1). PRBS pattern
    //TXBIST_PRBS7.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //80[2:0]   CMNPCSBIST_MODESEL  4   1
    //clock pattern
    //osSerdes2Write(0x4,0x0,0x50,0x0);
    //prbs7
    osSerdes2Write(0x4,0x0,0x50,0x1);
    //prbs23
    //osSerdes2Write(0x4,0x0,0x50,0x2);
    //prbs31
    //osSerdes2Write(0x4,0x0,0x50,0x3);
    osSerdesWait(0x1000000);
    // 10.  RXEQ setting
    //RXEQ.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //83[0:0]   RXAGC_DCCOUPLEEN    4   0
    //24[2:0]   RXCALEQ_DCGAIN      7   0
    //27[6:4]   RXCALEQ_LOFREQAGCGAIN   7   7
    //28[7:3]   RXCALEQ_HIFREQAGCCAP    7   0
    //25[2:0]   RXCALEQ_DFEPSTAPGAIN    7   0
    //24[5:3]   RXCALEQ_DFEPSTAPF3DB    7   0
    //25[6:3]   RXCALEQ_DFETAP1GAIN 7   0
    //26[3:0]   RXCALEQ_DFETAP2GAIN 7   8
    //26[7:4]   RXCALEQ_DFETAP3GAIN 7   0
    //27[3:0]   RXCALEQ_DFETAP4GAIN 7   8
    osSerdes2Write(0x0,0x0,0x18,0x0);
    osSerdes2Write(0x0,0x0,0x19,0x0);
    osSerdes2Write(0x0,0x0,0x1a,0x8);
    osSerdes2Write(0x0,0x0,0x1b,0x78);
    osSerdes2Write(0x0,0x0,0x1c,0x0);

    osSerdes2Write(0x1,0x0,0x18,0x0);
    osSerdes2Write(0x1,0x0,0x19,0x0);
    osSerdes2Write(0x1,0x0,0x1a,0x8);
    osSerdes2Write(0x1,0x0,0x1b,0x78);
    osSerdes2Write(0x1,0x0,0x1c,0x0);

    osSerdes2Write(0x2,0x0,0x18,0x0);
    osSerdes2Write(0x2,0x0,0x19,0x0);
    osSerdes2Write(0x2,0x0,0x1a,0x8);
    osSerdes2Write(0x2,0x0,0x1b,0x78);
    osSerdes2Write(0x2,0x0,0x1c,0x0);

    osSerdes2Write(0x3,0x0,0x18,0x0);
    osSerdes2Write(0x3,0x0,0x19,0x0);
    osSerdes2Write(0x3,0x0,0x1a,0x8);
    osSerdes2Write(0x3,0x0,0x1b,0x78);
    osSerdes2Write(0x3,0x0,0x1c,0x0);

    osSerdes2Write(0x4,0x0,0x53,0x2);
    osSerdesWait(0x1000000);
    // 11.  TXIODRIVER setting
    //TXIODRIVER.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //21[2:0]   TXDRV_HLEV  7   7
    //21[7:3]   TXDRV_LEVN  7   1b
    //22[3:0]   TXDRV_LEVNM1    7   0
    //22[5:4]   TXDRV_LEVNM2    7   0
    //23[2:0]   TXDRV_LEVNP1    7   0
    //23[4:3]   TXDRV_SLEW  7   0
    osSerdes2Write(0x0,0x0,0x15,0xdf);
    osSerdes2Write(0x0,0x0,0x16,0x0);
    osSerdes2Write(0x0,0x0,0x17,0x0);

    osSerdes2Write(0x1,0x0,0x15,0xdf);
    osSerdes2Write(0x1,0x0,0x16,0x0);
    osSerdes2Write(0x1,0x0,0x17,0x0);

    osSerdes2Write(0x2,0x0,0x15,0xdf);
    osSerdes2Write(0x2,0x0,0x16,0x0);
    osSerdes2Write(0x2,0x0,0x17,0x0);

    osSerdes2Write(0x3,0x0,0x15,0xdf);
    osSerdes2Write(0x3,0x0,0x16,0x0);
    osSerdes2Write(0x3,0x0,0x17,0x0);
    osSerdesWait(0x1000000);
    // 12.  Change Data Width to 10 bits
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //5[6:4]    PCSTX_DATAWIDTH 7   1
    //5[2:0]    PCSRX_DATAWIDTH 7   1
    osSerdes2Write(0x0,0x0,0x5,0x11);
    osSerdes2Write(0x1,0x0,0x5,0x11);
    osSerdes2Write(0x2,0x0,0x5,0x11);
    osSerdes2Write(0x3,0x0,0x5,0x11);
    osSerdesWait(0x1000000);
    // 13.  Change DIVRATE
    //RXPCSDATARATE_DIV2.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //6[2:0]    PCSRX_DIVRATE   7   2
    //TXPCSDATARATE_DIV2.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //6[6:4]    PCSTX_DIVRATE   7   2
    osSerdes2Write(0x0,0x0,0x6,0x22);
    osSerdes2Write(0x1,0x0,0x6,0x22);
    osSerdes2Write(0x2,0x0,0x6,0x22);
    osSerdes2Write(0x3,0x0,0x6,0x22);
    osSerdesWait(0x1000000);
    // 15.  Enable PCS TX
    //CMNPCS_TXENABLE.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //8[2:2]    CMNPCS_TXENABLE 4   1
    osSerdes2Write(0x4,0x0,0x8,0x54);
    osSerdesWait(0x1000000);

    // 16.  Overwrite Enable for Lock2Ref
    //RXLOCK2REF_OVREN.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //39[1:1]   RXLOCK2REF_OVREN    7   1
    osSerdes2Write(0x0,0x0,0x27,0x2);
    osSerdes2Write(0x1,0x0,0x27,0x2);
    osSerdes2Write(0x2,0x0,0x27,0x2);
    osSerdes2Write(0x3,0x0,0x27,0x2);
    osSerdesWait(0x1000000);
    // 17.  Power Up to P0
    //PCSPSTATE_P0.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //3[4:0]    LANEPCSPSTATE_RX    7   10
    //3[4:0]    CMNPCSPSTATE_SYNTH  4   10
    //4[4:0]    LANEPCSPSTATE_TX    7   10
    osSerdes2Write(0x0,0x0,0x3,0x10);
    osSerdes2Write(0x0,0x0,0x4,0x10);

    osSerdes2Write(0x1,0x0,0x3,0x10);
    osSerdes2Write(0x1,0x0,0x4,0x10);

    osSerdes2Write(0x2,0x0,0x3,0x10);
    osSerdes2Write(0x2,0x0,0x4,0x10);

    osSerdes2Write(0x3,0x0,0x3,0x10);
    osSerdes2Write(0x3,0x0,0x4,0x10);

    osSerdes2Write(0x4,0x0,0x3,0x10);
    osSerdesWait(0x1000000);
    // 18.  Read out critical status registers
    //PCSOUTTX_READY    7   11[2:2]     r   expected: 1
    //PCSOUTRX_READY    7   11[0:0]     r   expected: 1
    osSerdes2Read(0x0,0x0,11);
    osSerdes2Read(0x1,0x0,11);
    osSerdes2Read(0x2,0x0,11);
    osSerdes2Read(0x3,0x0,11);
    osSerdesWait(0x1000000);
    //the initialization is finished
    //*********************************************************

    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl1_base_addr+0x400],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;

}



/*****************************************************************
函数名 :  osSerdes2InitXaui3g125
输入参数    :   None
输出参数      :
Description   :  macro2   Lane0~3初始化为XAUI 3.125G
Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes2InitXaui3g125(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit19-10=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0xFFC00, 0xFFFFFFFF );

    /*3、设置模式为multi-mode*/
    /*Addr[ioctrl1_base_addr+0x60],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0xC, 0x0, 0xFFFFF7FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit19=1,bit18-10=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x80000, 0xFFF803FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载3.125Gbps_156.25MHz_VSM.txt配置文件*/
    osSerdes2Write( 0x0, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x0, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x0, 0x0, 0x67, 0xa );
    osSerdes2Write( 0x0, 0x0, 0x68, 0xa );
    osSerdes2Write( 0x0, 0x0, 0x69, 0xe );
    osSerdes2Write( 0x0, 0x0, 0x6a, 0xe );
    osSerdes2Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x0, 0x0, 0x6e, 0xd );
    osSerdes2Write( 0x1, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x1, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x1, 0x0, 0x67, 0xa );
    osSerdes2Write( 0x1, 0x0, 0x68, 0xa );
    osSerdes2Write( 0x1, 0x0, 0x69, 0xe );
    osSerdes2Write( 0x1, 0x0, 0x6a, 0xe );
    osSerdes2Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x1, 0x0, 0x6e, 0xd );
    osSerdes2Write( 0x2, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x2, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x2, 0x0, 0x67, 0xa );
    osSerdes2Write( 0x2, 0x0, 0x68, 0xa );
    osSerdes2Write( 0x2, 0x0, 0x69, 0xe );
    osSerdes2Write( 0x2, 0x0, 0x6a, 0xe );
    osSerdes2Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x2, 0x0, 0x6e, 0xd );
    osSerdes2Write( 0x3, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x3, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x3, 0x0, 0x67, 0xa );
    osSerdes2Write( 0x3, 0x0, 0x68, 0xa );
    osSerdes2Write( 0x3, 0x0, 0x69, 0xe );
    osSerdes2Write( 0x3, 0x0, 0x6a, 0xe );
    osSerdes2Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x3, 0x0, 0x6e, 0xd );
    osSerdes2Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes2Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x67, 0x6c );
    osSerdes2Write( 0x4, 0x0, 0x68, 0xbf );
    osSerdes2Write( 0x4, 0x0, 0x69, 0xbf );
    osSerdes2Write( 0x4, 0x0, 0x6a, 0xa );
    osSerdes2Write( 0x4, 0x0, 0x6b, 0xa );
    osSerdes2Write( 0x4, 0x0, 0x6c, 0xe );
    osSerdes2Write( 0x4, 0x0, 0x6d, 0xe );
    osSerdes2Write( 0x4, 0x0, 0x6e, 0x7 );
    osSerdes2Write( 0x4, 0x0, 0x6f, 0xc );
    osSerdes2Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x75, 0xb3 );
    osSerdes2Write( 0x4, 0x0, 0x76, 0xf6 );
    osSerdes2Write( 0x4, 0x0, 0x77, 0xd0 );
    osSerdes2Write( 0x4, 0x0, 0x78, 0xef );
    osSerdes2Write( 0x4, 0x0, 0x79, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x7a, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7f, 0xd3 );
    osSerdes2Write( 0x4, 0x0, 0x80, 0xd3 );
    osSerdes2Write( 0x4, 0x0, 0x81, 0xe2 );
    osSerdes2Write( 0x4, 0x0, 0x82, 0xef );
    osSerdes2Write( 0x4, 0x0, 0x83, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x84, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x85, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x86, 0xef );
    osSerdes2Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x89, 0xd3 );
    osSerdes2Write( 0x4, 0x0, 0x8a, 0xd3 );
    osSerdes2Write( 0x4, 0x0, 0x8b, 0xe2 );
    osSerdes2Write( 0x4, 0x0, 0x8c, 0xef );
    osSerdes2Write( 0x4, 0x0, 0x8d, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x8e, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x8f, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x90, 0xef );
    osSerdes2Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x93, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x94, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes2Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x97, 0x32 );
    osSerdes2Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x99, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes2Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes2Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes2Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x37, 0x9c );
    osSerdes2Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes2Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes2Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes2Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes2Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes2Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x2bd, 0x0 );


    /*配置并行数据接口的数据位宽和速率*/
    /*Addr[ioctrl1_base_addr+0x10],data[bit31-29=3'b011, bit28-26=3'b011,*/
    /*bit25-23=3'b011,bit22-20=3b011,bit19-17=3b011,bit16-14=3b011,*/
    /*bit13-11=3b011,bit10-8=3b011,bit7-0=all 1]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x10, 0x6DB6DBFF, 0x6DB6DBFF );

    /*addr[ioctrl1_base_addr+0x14],data[bit31-24=all0,bit23-21=3'b010,*/
    /*bit20-18=3'b010,bit17-15=3'b010,bit14-12=3'b010,bit11-9=3'b010,*/
    /*bit8-6=3'b010,bit5-3=3'b010,bit2-0=3'b010]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x14, 0x6DB6DBFF, 0x6DB6DBFF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit19=1,bit18-10=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0xFFC00, 0xffffffff );

    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl1_base_addr+0x400],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;

}



/*****************************************************************
函数名 :  osSerdes2InitSrio5g
输入参数    :   None
输出参数      :
Description   :  macro2   Lane0~3初始化为Srio 5G
Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes2InitSrio5g(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    //*********************************************************
    //serdes2  initialization:init_macro2_ srio_5g
    //*********************************************************
    //1.    POR
    osSerdesBitWrite (SRE_SC_SERDES_RESET_REQ1_REG,0x80000,0xffffffff);

    //1(1) set multi-mode:
    osSerdesBitWrite(IOCTRL1_BASE_ADDR + 0x00c,0x1400,0xFFFFF7FF);

    //1(2) set pcie-mode:
    //osSerdesBitWrite(IOCTRL1_BASE_ADDR + 0x00c,0x1c00,0xFFFFFFFF);

    //2.    Release POR
    osSerdesBitWrite(SRE_SC_SERDES_RESET_DREQ1_REG,0x80000,0xffffffff);
    osSerdesWait(0x1000000);
    //3.    Enable Hard Reset
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASSEN   7   1
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASSEN_SYNTH 4   1
    //4.    Hard Reset
    //HARDRST.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASS     7   0
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASS_SYNTH   4   0
    osSerdes2Write(0x0,0x0,0x2,0x2);
    osSerdes2Write(0x1,0x0,0x2,0x2);
    osSerdes2Write(0x2,0x0,0x2,0x2);
    osSerdes2Write(0x3,0x0,0x2,0x2);
    osSerdes2Write(0x4,0x0,0x2,0x1);
    osSerdesWait(0x1000000);
    // 5.   Load Different Data Rate Settings
    //load the 5Gbps_156.25MHz_VSM.txt
    osSerdes2Write(0,0,101,183);
    osSerdes2Write(0,0,102,183);
    osSerdes2Write(0,0,103,12);
    osSerdes2Write(0,0,104,12);
    osSerdes2Write(0,0,105,26);
    osSerdes2Write(0,0,106,26);
    osSerdes2Write(0,0,107,2);
    osSerdes2Write(0,0,108,2);
    osSerdes2Write(0,0,109,17);
    osSerdes2Write(0,0,110,5);
    osSerdes2Write(1,0,101,183);
    osSerdes2Write(1,0,102,183);
    osSerdes2Write(1,0,103,12);
    osSerdes2Write(1,0,104,12);
    osSerdes2Write(1,0,105,26);
    osSerdes2Write(1,0,106,26);
    osSerdes2Write(1,0,107,2);
    osSerdes2Write(1,0,108,2);
    osSerdes2Write(1,0,109,17);
    osSerdes2Write(1,0,110,5);
    osSerdes2Write(2,0,101,183);
    osSerdes2Write(2,0,102,183);
    osSerdes2Write(2,0,103,12);
    osSerdes2Write(2,0,104,12);
    osSerdes2Write(2,0,105,26);
    osSerdes2Write(2,0,106,26);
    osSerdes2Write(2,0,107,2);
    osSerdes2Write(2,0,108,2);
    osSerdes2Write(2,0,109,17);
    osSerdes2Write(2,0,110,5);
    osSerdes2Write(3,0,101,183);
    osSerdes2Write(3,0,102,183);
    osSerdes2Write(3,0,103,12);
    osSerdes2Write(3,0,104,12);
    osSerdes2Write(3,0,105,26);
    osSerdes2Write(3,0,106,26);
    osSerdes2Write(3,0,107,2);
    osSerdes2Write(3,0,108,2);
    osSerdes2Write(3,0,109,17);
    osSerdes2Write(3,0,110,5);
    osSerdes2Write(4,0,101,153);
    osSerdes2Write(4,0,102,0);
    osSerdes2Write(4,0,103,108);
    osSerdes2Write(4,0,104,183);
    osSerdes2Write(4,0,105,183);
    osSerdes2Write(4,0,106,12);
    osSerdes2Write(4,0,107,12);
    osSerdes2Write(4,0,108,26);
    osSerdes2Write(4,0,109,26);
    osSerdes2Write(4,0,110,7);
    osSerdes2Write(4,0,111,12);
    osSerdes2Write(4,0,112,8);
    osSerdes2Write(4,0,113,0);
    osSerdes2Write(4,0,114,8);
    osSerdes2Write(4,0,115,0);
    osSerdes2Write(4,0,116,255);
    osSerdes2Write(4,0,117,179);
    osSerdes2Write(4,0,118,246);
    osSerdes2Write(4,0,119,208);
    osSerdes2Write(4,0,120,239);
    osSerdes2Write(4,0,121,251);
    osSerdes2Write(4,0,122,255);
    osSerdes2Write(4,0,123,255);
    osSerdes2Write(4,0,124,255);
    osSerdes2Write(4,0,125,255);
    osSerdes2Write(4,0,126,255);
    osSerdes2Write(4,0,127,211);
    osSerdes2Write(4,0,128,211);
    osSerdes2Write(4,0,129,226);
    osSerdes2Write(4,0,130,239);
    osSerdes2Write(4,0,131,251);
    osSerdes2Write(4,0,132,251);
    osSerdes2Write(4,0,133,255);
    osSerdes2Write(4,0,134,239);
    osSerdes2Write(4,0,135,255);
    osSerdes2Write(4,0,136,255);
    osSerdes2Write(4,0,137,211);
    osSerdes2Write(4,0,138,211);
    osSerdes2Write(4,0,139,226);
    osSerdes2Write(4,0,140,239);
    osSerdes2Write(4,0,141,251);
    osSerdes2Write(4,0,142,251);
    osSerdes2Write(4,0,143,255);
    osSerdes2Write(4,0,144,239);
    osSerdes2Write(4,0,145,255);
    osSerdes2Write(4,0,146,255);
    osSerdes2Write(4,0,147,251);
    osSerdes2Write(4,0,148,255);
    osSerdes2Write(4,0,149,63);
    osSerdes2Write(4,0,150,0);
    osSerdes2Write(4,0,151,100);
    osSerdes2Write(4,0,152,0);
    osSerdes2Write(4,0,153,4);
    osSerdes2Write(4,0,154,2);
    osSerdes2Write(4,0,155,5);
    osSerdes2Write(4,0,156,5);
    osSerdes2Write(4,0,157,4);
    osSerdes2Write(4,0,158,0);
    osSerdes2Write(4,0,159,0);
    osSerdes2Write(4,0,160,8);
    osSerdes2Write(4,0,161,4);
    osSerdes2Write(4,0,162,0);
    osSerdes2Write(4,0,163,0);
    osSerdes2Write(4,0,164,4);
    osSerdes2Write(0,0,7,0);
    osSerdes2Write(1,0,7,0);
    osSerdes2Write(2,0,7,0);
    osSerdes2Write(3,0,7,0);
    osSerdes2Write(4,0,13,16);
    osSerdes2Write(4,0,48,0);
    osSerdes2Write(4,0,49,0);
    osSerdes2Write(4,0,54,0);
    osSerdes2Write(4,0,55,180);
    osSerdes2Write(4,0,93,2);
    osSerdes2Write(4,0,165,2);
    osSerdes2Write(0,0,41,6);
    osSerdes2Write(1,0,41,6);
    osSerdes2Write(2,0,41,6);
    osSerdes2Write(3,0,41,6);
    osSerdes2Write(4,0,354,3);
    osSerdes2Write(4,0,355,58);
    osSerdes2Write(4,0,356,9);
    osSerdes2Write(4,0,357,3);
    osSerdes2Write(4,0,358,62);
    osSerdes2Write(4,0,359,12);
    osSerdes2Write(0,0,701,0);
    osSerdes2Write(1,0,701,0);
    osSerdes2Write(2,0,701,0);
    osSerdes2Write(3,0,701,0);

    osSerdesWait(0x1000000);
    // 6.   Overwrite
    //PCSOVR_ENABLE.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //85[1:1]   LB_LOCWREN  7   0
    //85[4:4]   PCSRX_LOCWREN   7   0
    //85[7:7]   PCSTX_LOCWREN   7   0
    //95[4:4]   CMNPCSBIST_LOCWREN  4   0
    //86[0:0]   PCSTXBIST_LOCWREN   7   0
    //87[5:5]   TXDRV_LOCWREN   7   0
    //86[3:3]   RXCALEQ_LOCWREN 7   0
    //85[5:5]   PCSRXBIST_LOCWREN   7   0
    //95[2:2]   CMNPCIEGEN3_LOCWREN 4   0
    //95[5:5]   CMNPCSPSTATE_LOCWREN    4   0
    //86[4:4]   RXCALEYEDIAGFSMIN_LOCWREN   7   0
    //95[3:3]   CMNPCS_LOCWREN  4   0
    //85[0:0]   LANEPCSPSTATE_LOCWREN   7   0
    //230[0:0]  RXLOCK2REF_LOCWREN  7   0
    osSerdes2Write(0x0,0x0,0x55,0x4c);
    osSerdes2Write(0x0,0x0,0x56,0xe6);
    osSerdes2Write(0x0,0x0,0x57,0x1f);
    osSerdes2Write(0x0,0x0,0xe6,0xfe);

    osSerdes2Write(0x1,0x0,0x55,0x4c);
    osSerdes2Write(0x1,0x0,0x56,0xe6);
    osSerdes2Write(0x1,0x0,0x57,0x1f);
    osSerdes2Write(0x1,0x0,0xe6,0xfe);

    osSerdes2Write(0x2,0x0,0x55,0x4c);
    osSerdes2Write(0x2,0x0,0x56,0xe6);
    osSerdes2Write(0x2,0x0,0x57,0x1f);
    osSerdes2Write(0x2,0x0,0xe6,0xfe);

    osSerdes2Write(0x3,0x0,0x55,0x4c);
    osSerdes2Write(0x3,0x0,0x56,0xe6);
    osSerdes2Write(0x3,0x0,0x57,0x1f);
    osSerdes2Write(0x3,0x0,0xe6,0xfe);

    osSerdes2Write(0x4,0x0,0x5f,0xc3);
    osSerdesWait(0x1000000);
    // 7.   Set to IDDQ state
    //PCSPSTATE_IDDQ.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //3[4:0]    LANEPCSPSTATE_RX    7   1
    //3[4:0]    CMNPCSPSTATE_SYNTH  4   1
    //4[4:0]    LANEPCSPSTATE_TX    7   1
    osSerdes2Write(0x0,0x0,0x3,0x1);
    osSerdes2Write(0x0,0x0,0x4,0x1);

    osSerdes2Write(0x1,0x0,0x3,0x1);
    osSerdes2Write(0x1,0x0,0x4,0x1);

    osSerdes2Write(0x2,0x0,0x3,0x1);
    osSerdes2Write(0x2,0x0,0x4,0x1);

    osSerdes2Write(0x3,0x0,0x3,0x1);
    osSerdes2Write(0x3,0x0,0x4,0x1);

    osSerdes2Write(0x4,0x0,0x3,0x1);
    osSerdesWait(0x1000000);
    // 8.   Release Hard Reset
    //HARDRST_NOT.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASS     7   1
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASS_SYNTH   4   1
    osSerdes2Write(0x0,0x0,0x2,0x3);
    osSerdes2Write(0x1,0x0,0x2,0x3);
    osSerdes2Write(0x2,0x0,0x2,0x3);
    osSerdes2Write(0x3,0x0,0x2,0x3);
    osSerdes2Write(0x4,0x0,0x2,0x3);
    osSerdesWait(0x1000000);
    // 9(1). PRBS pattern
    //TXBIST_PRBS7.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //80[2:0]   CMNPCSBIST_MODESEL  4   1
    //clock pattern
    //osSerdes2Write(0x4,0x0,0x50,0x0);
    //prbs7
    osSerdes2Write(0x4,0x0,0x50,0x1);
    //prbs23
    //osSerdes2Write(0x4,0x0,0x50,0x2);
    //prbs31
    //osSerdes2Write(0x4,0x0,0x50,0x3);
    osSerdesWait(0x1000000);
    // 10.  RXEQ setting
    //RXEQ.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //83[0:0]   RXAGC_DCCOUPLEEN    4   0
    //24[2:0]   RXCALEQ_DCGAIN      7   0
    //27[6:4]   RXCALEQ_LOFREQAGCGAIN   7   7
    //28[7:3]   RXCALEQ_HIFREQAGCCAP    7   0
    //25[2:0]   RXCALEQ_DFEPSTAPGAIN    7   0
    //24[5:3]   RXCALEQ_DFEPSTAPF3DB    7   0
    //25[6:3]   RXCALEQ_DFETAP1GAIN 7   0
    //26[3:0]   RXCALEQ_DFETAP2GAIN 7   8
    //26[7:4]   RXCALEQ_DFETAP3GAIN 7   0
    //27[3:0]   RXCALEQ_DFETAP4GAIN 7   8
    osSerdes2Write(0x0,0x0,0x18,0x0);
    osSerdes2Write(0x0,0x0,0x19,0x0);
    osSerdes2Write(0x0,0x0,0x1a,0x8);
    osSerdes2Write(0x0,0x0,0x1b,0x78);
    osSerdes2Write(0x0,0x0,0x1c,0x0);

    osSerdes2Write(0x1,0x0,0x18,0x0);
    osSerdes2Write(0x1,0x0,0x19,0x0);
    osSerdes2Write(0x1,0x0,0x1a,0x8);
    osSerdes2Write(0x1,0x0,0x1b,0x78);
    osSerdes2Write(0x1,0x0,0x1c,0x0);

    osSerdes2Write(0x2,0x0,0x18,0x0);
    osSerdes2Write(0x2,0x0,0x19,0x0);
    osSerdes2Write(0x2,0x0,0x1a,0x8);
    osSerdes2Write(0x2,0x0,0x1b,0x78);
    osSerdes2Write(0x2,0x0,0x1c,0x0);

    osSerdes2Write(0x3,0x0,0x18,0x0);
    osSerdes2Write(0x3,0x0,0x19,0x0);
    osSerdes2Write(0x3,0x0,0x1a,0x8);
    osSerdes2Write(0x3,0x0,0x1b,0x78);
    osSerdes2Write(0x3,0x0,0x1c,0x0);

    osSerdes2Write(0x4,0x0,0x53,0x2);
    osSerdesWait(0x1000000);
    // 11.  TXIODRIVER setting
    //TXIODRIVER.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //21[2:0]   TXDRV_HLEV  7   7
    //21[7:3]   TXDRV_LEVN  7   1b
    //22[3:0]   TXDRV_LEVNM1    7   0
    //22[5:4]   TXDRV_LEVNM2    7   0
    //23[2:0]   TXDRV_LEVNP1    7   0
    //23[4:3]   TXDRV_SLEW  7   0
    osSerdes2Write(0x0,0x0,0x15,0xdf);
    osSerdes2Write(0x0,0x0,0x16,0x0);
    osSerdes2Write(0x0,0x0,0x17,0x0);

    osSerdes2Write(0x1,0x0,0x15,0xdf);
    osSerdes2Write(0x1,0x0,0x16,0x0);
    osSerdes2Write(0x1,0x0,0x17,0x0);

    osSerdes2Write(0x2,0x0,0x15,0xdf);
    osSerdes2Write(0x2,0x0,0x16,0x0);
    osSerdes2Write(0x2,0x0,0x17,0x0);

    osSerdes2Write(0x3,0x0,0x15,0xdf);
    osSerdes2Write(0x3,0x0,0x16,0x0);
    osSerdes2Write(0x3,0x0,0x17,0x0);
    osSerdesWait(0x1000000);
    // 12.  Change Data Width to 10 bits
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //5[6:4]    PCSTX_DATAWIDTH 7   1
    //5[2:0]    PCSRX_DATAWIDTH 7   1
    osSerdes2Write(0x0,0x0,0x5,0x11);
    osSerdes2Write(0x1,0x0,0x5,0x11);
    osSerdes2Write(0x2,0x0,0x5,0x11);
    osSerdes2Write(0x3,0x0,0x5,0x11);
    osSerdesWait(0x1000000);
    // 13.  Change DIVRATE
    //RXPCSDATARATE_DIV1.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //6[2:0]    PCSRX_DIVRATE   7   3
    //TXPCSDATARATE_DIV1.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //6[6:4]    PCSTX_DIVRATE   7   3
    osSerdes2Write(0x0,0x0,0x6,0x33);
    osSerdes2Write(0x1,0x0,0x6,0x33);
    osSerdes2Write(0x2,0x0,0x6,0x33);
    osSerdes2Write(0x3,0x0,0x6,0x33);
    osSerdesWait(0x1000000);
    // 15.  Enable PCS TX
    //CMNPCS_TXENABLE.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //8[2:2]    CMNPCS_TXENABLE 4   1
    osSerdes2Write(0x4,0x0,0x8,0x54);

    osSerdesWait(0x1000000);
    // 16.  Overwrite Enable for Lock2Ref
    //RXLOCK2REF_OVREN.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //39[1:1]   RXLOCK2REF_OVREN    7   1
    osSerdes2Write(0x0,0x0,0x27,0x2);
    osSerdes2Write(0x1,0x0,0x27,0x2);
    osSerdes2Write(0x2,0x0,0x27,0x2);
    osSerdes2Write(0x3,0x0,0x27,0x2);
    osSerdesWait(0x1000000);
    // 17.  Power Up to P0
    //PCSPSTATE_P0.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //3[4:0]    LANEPCSPSTATE_RX    7   10
    //3[4:0]    CMNPCSPSTATE_SYNTH  4   10
    //4[4:0]    LANEPCSPSTATE_TX    7   10
    osSerdes2Write(0x0,0x0,0x3,0x10);
    osSerdes2Write(0x0,0x0,0x4,0x10);

    osSerdes2Write(0x1,0x0,0x3,0x10);
    osSerdes2Write(0x1,0x0,0x4,0x10);

    osSerdes2Write(0x2,0x0,0x3,0x10);
    osSerdes2Write(0x2,0x0,0x4,0x10);

    osSerdes2Write(0x3,0x0,0x3,0x10);
    osSerdes2Write(0x3,0x0,0x4,0x10);

    osSerdes2Write(0x4,0x0,0x3,0x10);
    osSerdesWait(0x1000000);
    // 18.  Read out critical status registers
    //PCSOUTTX_READY    7   11[2:2]     r   expected: 1
    //PCSOUTRX_READY    7   11[0:0]     r   expected: 1
    osSerdes2Read(0x0,0x0,11);
    osSerdes2Read(0x1,0x0,11);
    osSerdes2Read(0x2,0x0,11);
    osSerdes2Read(0x3,0x0,11);
    osSerdesWait(0x1000000);

    //the initialization is finished
    //*********************************************************


    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl1_base_addr+0x400],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;

}


/*****************************************************************
函数名 :  osSerdes2InitSrio6g25
输入参数    :   None
输出参数      :
Description   :  macro2   Lane0~3初始化为Srio 6.25G
Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes2InitSrio6g25(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    //*********************************************************
    //serdes2  initialization:init_macro2_ srio_6g25
    //*********************************************************
    //1.    POR
    osSerdesBitWrite(SRE_SC_SERDES_RESET_REQ1_REG,0x80000,0xffffffff);

    //1(1) set multi-mode:
    osSerdesBitWrite(IOCTRL1_BASE_ADDR + 0x00c,0x1400,0xFFFFF7FF);

    //1(2) set pcie-mode:
    //osSerdesBitWrite(IOCTRL1_BASE_ADDR + 0x00c,0x1c00,0xFFFFFFFF);

    //2.    Release POR
    osSerdesBitWrite(SRE_SC_SERDES_RESET_DREQ1_REG,0x80000,0xffffffff);
    osSerdesWait(0x1000000);
    //3.    Enable Hard Reset
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASSEN   7   1
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASSEN_SYNTH 4   1
    //4.    Hard Reset
    //HARDRST.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASS     7   0
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASS_SYNTH   4   0
    osSerdes2Write(0x0,0x0,0x2,0x2);
    osSerdes2Write(0x1,0x0,0x2,0x2);
    osSerdes2Write(0x2,0x0,0x2,0x2);
    osSerdes2Write(0x3,0x0,0x2,0x2);
    osSerdes2Write(0x4,0x0,0x2,0x1);
    osSerdesWait(0x1000000);
    // 5.   Load Different Data Rate Settings
    //load the 6.25Gbps_156.25MHz_VSM.txt
    osSerdes2Write(0,0,101,191);
    osSerdes2Write(0,0,102,191);
    osSerdes2Write(0,0,103,10);
    osSerdes2Write(0,0,104,10);
    osSerdes2Write(0,0,105,14);
    osSerdes2Write(0,0,106,14);
    osSerdes2Write(0,0,107,1);
    osSerdes2Write(0,0,108,1);
    osSerdes2Write(0,0,109,34);
    osSerdes2Write(0,0,110,5);
    osSerdes2Write(1,0,101,191);
    osSerdes2Write(1,0,102,191);
    osSerdes2Write(1,0,103,10);
    osSerdes2Write(1,0,104,10);
    osSerdes2Write(1,0,105,14);
    osSerdes2Write(1,0,106,14);
    osSerdes2Write(1,0,107,1);
    osSerdes2Write(1,0,108,1);
    osSerdes2Write(1,0,109,34);
    osSerdes2Write(1,0,110,5);
    osSerdes2Write(2,0,101,191);
    osSerdes2Write(2,0,102,191);
    osSerdes2Write(2,0,103,10);
    osSerdes2Write(2,0,104,10);
    osSerdes2Write(2,0,105,14);
    osSerdes2Write(2,0,106,14);
    osSerdes2Write(2,0,107,1);
    osSerdes2Write(2,0,108,1);
    osSerdes2Write(2,0,109,34);
    osSerdes2Write(2,0,110,5);
    osSerdes2Write(3,0,101,191);
    osSerdes2Write(3,0,102,191);
    osSerdes2Write(3,0,103,10);
    osSerdes2Write(3,0,104,10);
    osSerdes2Write(3,0,105,14);
    osSerdes2Write(3,0,106,14);
    osSerdes2Write(3,0,107,1);
    osSerdes2Write(3,0,108,1);
    osSerdes2Write(3,0,109,34);
    osSerdes2Write(3,0,110,5);
    osSerdes2Write(4,0,101,170);
    osSerdes2Write(4,0,102,0);
    osSerdes2Write(4,0,103,108);
    osSerdes2Write(4,0,104,191);
    osSerdes2Write(4,0,105,191);
    osSerdes2Write(4,0,106,10);
    osSerdes2Write(4,0,107,10);
    osSerdes2Write(4,0,108,14);
    osSerdes2Write(4,0,109,14);
    osSerdes2Write(4,0,110,7);
    osSerdes2Write(4,0,111,12);
    osSerdes2Write(4,0,112,16);
    osSerdes2Write(4,0,113,0);
    osSerdes2Write(4,0,114,16);
    osSerdes2Write(4,0,115,0);
    osSerdes2Write(4,0,116,255);
    osSerdes2Write(4,0,117,179);
    osSerdes2Write(4,0,118,246);
    osSerdes2Write(4,0,119,208);
    osSerdes2Write(4,0,120,239);
    osSerdes2Write(4,0,121,251);
    osSerdes2Write(4,0,122,255);
    osSerdes2Write(4,0,123,255);
    osSerdes2Write(4,0,124,255);
    osSerdes2Write(4,0,125,255);
    osSerdes2Write(4,0,126,255);
    osSerdes2Write(4,0,127,211);
    osSerdes2Write(4,0,128,211);
    osSerdes2Write(4,0,129,226);
    osSerdes2Write(4,0,130,239);
    osSerdes2Write(4,0,131,251);
    osSerdes2Write(4,0,132,251);
    osSerdes2Write(4,0,133,255);
    osSerdes2Write(4,0,134,239);
    osSerdes2Write(4,0,135,255);
    osSerdes2Write(4,0,136,255);
    osSerdes2Write(4,0,137,211);
    osSerdes2Write(4,0,138,211);
    osSerdes2Write(4,0,139,226);
    osSerdes2Write(4,0,140,239);
    osSerdes2Write(4,0,141,251);
    osSerdes2Write(4,0,142,251);
    osSerdes2Write(4,0,143,255);
    osSerdes2Write(4,0,144,239);
    osSerdes2Write(4,0,145,255);
    osSerdes2Write(4,0,146,255);
    osSerdes2Write(4,0,147,251);
    osSerdes2Write(4,0,148,255);
    osSerdes2Write(4,0,149,63);
    osSerdes2Write(4,0,150,0);
    osSerdes2Write(4,0,151,100);
    osSerdes2Write(4,0,152,0);
    osSerdes2Write(4,0,153,2);
    osSerdes2Write(4,0,154,1);
    osSerdes2Write(4,0,155,5);
    osSerdes2Write(4,0,156,5);
    osSerdes2Write(4,0,157,4);
    osSerdes2Write(4,0,158,0);
    osSerdes2Write(4,0,159,0);
    osSerdes2Write(4,0,160,8);
    osSerdes2Write(4,0,161,4);
    osSerdes2Write(4,0,162,0);
    osSerdes2Write(4,0,163,0);
    osSerdes2Write(4,0,164,4);
    osSerdes2Write(0,0,7,0);
    osSerdes2Write(1,0,7,0);
    osSerdes2Write(2,0,7,0);
    osSerdes2Write(3,0,7,0);
    osSerdes2Write(4,0,13,16);
    osSerdes2Write(4,0,48,0);
    osSerdes2Write(4,0,49,0);
    osSerdes2Write(4,0,54,0);
    osSerdes2Write(4,0,55,156);
    osSerdes2Write(4,0,93,2);
    osSerdes2Write(4,0,165,2);
    osSerdes2Write(0,0,41,6);
    osSerdes2Write(1,0,41,6);
    osSerdes2Write(2,0,41,6);
    osSerdes2Write(3,0,41,6);
    osSerdes2Write(4,0,354,3);
    osSerdes2Write(4,0,355,58);
    osSerdes2Write(4,0,356,9);
    osSerdes2Write(4,0,357,3);
    osSerdes2Write(4,0,358,62);
    osSerdes2Write(4,0,359,12);
    osSerdes2Write(0,0,701,0);
    osSerdes2Write(1,0,701,0);
    osSerdes2Write(2,0,701,0);
    osSerdes2Write(3,0,701,0);

    osSerdesWait(0x1000000);

    // 6.   Overwrite
    //PCSOVR_ENABLE.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //85[1:1]   LB_LOCWREN  7   0
    //85[4:4]   PCSRX_LOCWREN   7   0
    //85[7:7]   PCSTX_LOCWREN   7   0
    //95[4:4]   CMNPCSBIST_LOCWREN  4   0
    //86[0:0]   PCSTXBIST_LOCWREN   7   0
    //87[5:5]   TXDRV_LOCWREN   7   0
    //86[3:3]   RXCALEQ_LOCWREN 7   0
    //85[5:5]   PCSRXBIST_LOCWREN   7   0
    //95[2:2]   CMNPCIEGEN3_LOCWREN 4   0
    //95[5:5]   CMNPCSPSTATE_LOCWREN    4   0
    //86[4:4]   RXCALEYEDIAGFSMIN_LOCWREN   7   0
    //95[3:3]   CMNPCS_LOCWREN  4   0
    //85[0:0]   LANEPCSPSTATE_LOCWREN   7   0
    //230[0:0]  RXLOCK2REF_LOCWREN  7   0
    osSerdes2Write(0x0,0x0,0x55,0x4c);
    osSerdes2Write(0x0,0x0,0x56,0xe6);
    osSerdes2Write(0x0,0x0,0x57,0x1f);
    osSerdes2Write(0x0,0x0,0xe6,0xfe);

    osSerdes2Write(0x1,0x0,0x55,0x4c);
    osSerdes2Write(0x1,0x0,0x56,0xe6);
    osSerdes2Write(0x1,0x0,0x57,0x1f);
    osSerdes2Write(0x1,0x0,0xe6,0xfe);

    osSerdes2Write(0x2,0x0,0x55,0x4c);
    osSerdes2Write(0x2,0x0,0x56,0xe6);
    osSerdes2Write(0x2,0x0,0x57,0x1f);
    osSerdes2Write(0x2,0x0,0xe6,0xfe);

    osSerdes2Write(0x3,0x0,0x55,0x4c);
    osSerdes2Write(0x3,0x0,0x56,0xe6);
    osSerdes2Write(0x3,0x0,0x57,0x1f);
    osSerdes2Write(0x3,0x0,0xe6,0xfe);

    osSerdes2Write(0x4,0x0,0x5f,0xc3);
    osSerdesWait(0x1000000);
    // 7.   Set to IDDQ state
    //PCSPSTATE_IDDQ.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //3[4:0]    LANEPCSPSTATE_RX    7   1
    //3[4:0]    CMNPCSPSTATE_SYNTH  4   1
    //4[4:0]    LANEPCSPSTATE_TX    7   1
    osSerdes2Write(0x0,0x0,0x3,0x1);
    osSerdes2Write(0x0,0x0,0x4,0x1);

    osSerdes2Write(0x1,0x0,0x3,0x1);
    osSerdes2Write(0x1,0x0,0x4,0x1);

    osSerdes2Write(0x2,0x0,0x3,0x1);
    osSerdes2Write(0x2,0x0,0x4,0x1);

    osSerdes2Write(0x3,0x0,0x3,0x1);
    osSerdes2Write(0x3,0x0,0x4,0x1);

    osSerdes2Write(0x4,0x0,0x3,0x1);
    osSerdesWait(0x1000000);
    // 8.   Release Hard Reset
    //HARDRST_NOT.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //2[0:0]    CMNCTLPOR_HARDRSTBYPASS     7   1
    //2[1:1]    CMNCTLPOR_HARDRSTBYPASS_SYNTH   4   1
    osSerdes2Write(0x0,0x0,0x2,0x3);
    osSerdes2Write(0x1,0x0,0x2,0x3);
    osSerdes2Write(0x2,0x0,0x2,0x3);
    osSerdes2Write(0x3,0x0,0x2,0x3);
    osSerdes2Write(0x4,0x0,0x2,0x3);
    osSerdesWait(0x1000000);
    // 9(1). PRBS pattern
    //TXBIST_PRBS7.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //80[2:0]   CMNPCSBIST_MODESEL  4   1
    //prbs7
    osSerdes2Write(0x4,0x0,0x50,0x1);
    //prbs23
    //osSerdes2Write(0x4,0x0,0x50,0x2);
    //prbs31
    //osSerdes2Write(0x4,0x0,0x50,0x3);
    osSerdesWait(0x1000000);
    // 10.  RXEQ setting
    //RXEQ.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //83[0:0]   RXAGC_DCCOUPLEEN    4   0
    //24[2:0]   RXCALEQ_DCGAIN      7   0
    //27[6:4]   RXCALEQ_LOFREQAGCGAIN   7   7
    //28[7:3]   RXCALEQ_HIFREQAGCCAP    7   0
    //25[2:0]   RXCALEQ_DFEPSTAPGAIN    7   0
    //24[5:3]   RXCALEQ_DFEPSTAPF3DB    7   0
    //25[6:3]   RXCALEQ_DFETAP1GAIN 7   0
    //26[3:0]   RXCALEQ_DFETAP2GAIN 7   8
    //26[7:4]   RXCALEQ_DFETAP3GAIN 7   0
    //27[3:0]   RXCALEQ_DFETAP4GAIN 7   8
    osSerdes2Write(0x0,0x0,0x18,0x0);
    osSerdes2Write(0x0,0x0,0x19,0x0);
    osSerdes2Write(0x0,0x0,0x1a,0x8);
    osSerdes2Write(0x0,0x0,0x1b,0x78);
    osSerdes2Write(0x0,0x0,0x1c,0x0);

    osSerdes2Write(0x1,0x0,0x18,0x0);
    osSerdes2Write(0x1,0x0,0x19,0x0);
    osSerdes2Write(0x1,0x0,0x1a,0x8);
    osSerdes2Write(0x1,0x0,0x1b,0x78);
    osSerdes2Write(0x1,0x0,0x1c,0x0);

    osSerdes2Write(0x2,0x0,0x18,0x0);
    osSerdes2Write(0x2,0x0,0x19,0x0);
    osSerdes2Write(0x2,0x0,0x1a,0x8);
    osSerdes2Write(0x2,0x0,0x1b,0x78);
    osSerdes2Write(0x2,0x0,0x1c,0x0);

    osSerdes2Write(0x3,0x0,0x18,0x0);
    osSerdes2Write(0x3,0x0,0x19,0x0);
    osSerdes2Write(0x3,0x0,0x1a,0x8);
    osSerdes2Write(0x3,0x0,0x1b,0x78);
    osSerdes2Write(0x3,0x0,0x1c,0x0);

    osSerdes2Write(0x4,0x0,0x53,0x2);
    osSerdesWait(0x1000000);
    // 11.  TXIODRIVER setting
    //TXIODRIVER.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //21[2:0]   TXDRV_HLEV  7   7
    //21[7:3]   TXDRV_LEVN  7   1b
    //22[3:0]   TXDRV_LEVNM1    7   0
    //22[5:4]   TXDRV_LEVNM2    7   0
    //23[2:0]   TXDRV_LEVNP1    7   0
    //23[4:3]   TXDRV_SLEW  7   0
    osSerdes2Write(0x0,0x0,0x15,0xdf);
    osSerdes2Write(0x0,0x0,0x16,0x0);
    osSerdes2Write(0x0,0x0,0x17,0x0);

    osSerdes2Write(0x1,0x0,0x15,0xdf);
    osSerdes2Write(0x1,0x0,0x16,0x0);
    osSerdes2Write(0x1,0x0,0x17,0x0);

    osSerdes2Write(0x2,0x0,0x15,0xdf);
    osSerdes2Write(0x2,0x0,0x16,0x0);
    osSerdes2Write(0x2,0x0,0x17,0x0);

    osSerdes2Write(0x3,0x0,0x15,0xdf);
    osSerdes2Write(0x3,0x0,0x16,0x0);
    osSerdes2Write(0x3,0x0,0x17,0x0);
    osSerdesWait(0x1000000);
    // 12.  Change Data Width to 10 bits
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //5[6:4]    PCSTX_DATAWIDTH 7   1
    //5[2:0]    PCSRX_DATAWIDTH 7   1
    osSerdes2Write(0x0,0x0,0x5,0x11);
    osSerdes2Write(0x1,0x0,0x5,0x11);
    osSerdes2Write(0x2,0x0,0x5,0x11);
    osSerdes2Write(0x3,0x0,0x5,0x11);
    osSerdesWait(0x1000000);
    // 13.  Change DIVRATE
    //RXPCSDATARATE_DIV1.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //6[2:0]    PCSRX_DIVRATE   7   3
    //TXPCSDATARATE_DIV1.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //6[6:4]    PCSTX_DIVRATE   7   3
    osSerdes2Write(0x0,0x0,0x6,0x33);
    osSerdes2Write(0x1,0x0,0x6,0x33);
    osSerdes2Write(0x2,0x0,0x6,0x33);
    osSerdes2Write(0x3,0x0,0x6,0x33);
    osSerdesWait(0x1000000);
    // 15.  Enable PCS TX
    //CMNPCS_TXENABLE.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //8[2:2]    CMNPCS_TXENABLE 4   1
    osSerdes2Write(0x4,0x0,0x8,0x54);
    osSerdesWait(0x1000000);

    // 16.  Overwrite Enable for Lock2Ref
    //RXLOCK2REF_OVREN.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //39[1:1]   RXLOCK2REF_OVREN    7   1
    osSerdes2Write(0x0,0x0,0x27,0x2);
    osSerdes2Write(0x1,0x0,0x27,0x2);
    osSerdes2Write(0x2,0x0,0x27,0x2);
    osSerdes2Write(0x3,0x0,0x27,0x2);
    osSerdesWait(0x1000000);
    // 17.  Power Up to P0
    //PCSPSTATE_P0.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
    //3[4:0]    LANEPCSPSTATE_RX    7   10
    //3[4:0]    CMNPCSPSTATE_SYNTH  4   10
    //4[4:0]    LANEPCSPSTATE_TX    7   10
    osSerdes2Write(0x0,0x0,0x3,0x10);
    osSerdes2Write(0x0,0x0,0x4,0x10);

    osSerdes2Write(0x1,0x0,0x3,0x10);
    osSerdes2Write(0x1,0x0,0x4,0x10);

    osSerdes2Write(0x2,0x0,0x3,0x10);
    osSerdes2Write(0x2,0x0,0x4,0x10);

    osSerdes2Write(0x3,0x0,0x3,0x10);
    osSerdes2Write(0x3,0x0,0x4,0x10);

    osSerdes2Write(0x4,0x0,0x3,0x10);
    osSerdesWait(0x1000000);
    // 18.  Read out critical status registers
    //PCSOUTTX_READY    7   11[2:2]     r   expected: 1
    //PCSOUTRX_READY    7   11[0:0]     r   expected: 1
    osSerdes2Read(0x0,0x0,11);
    osSerdes2Read(0x1,0x0,11);
    osSerdes2Read(0x2,0x0,11);
    osSerdes2Read(0x3,0x0,11);
    osSerdesWait(0x1000000);
    //the initialization is finished
    //*********************************************************


    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl1_base_addr+0x400],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;

}


/*****************************************************************
函数名 :  osSerdes2InitSrio10g3125
输入参数    :   None
输出参数      :
Description   :  macro2   Lane0~3初始化为Srio 10.3125G
Author        :  z00228490
Creation time :  2012/12/29
*****************************************************************/
UINT32 osSerdes2InitSrio10g3125(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit19-10=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0xFFC00, 0xFFFFFFFF );

    /*3、设置模式为multi-mode*/
    /*Addr[ioctrl1_base_addr+0x60],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0xC, 0x0, 0xFFFFF7FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit19=1,bit18-10=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x80000, 0xFFF803FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载6.25Gbps_156.25MHz_VSM.txt配置文件*/
    osSerdes2Write( 0x0, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x0, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x0, 0x0, 0x67, 0xa );
    osSerdes2Write( 0x0, 0x0, 0x68, 0xa );
    osSerdes2Write( 0x0, 0x0, 0x69, 0xe );
    osSerdes2Write( 0x0, 0x0, 0x6a, 0xe );
    osSerdes2Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x1, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x1, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x1, 0x0, 0x67, 0xa );
    osSerdes2Write( 0x1, 0x0, 0x68, 0xa );
    osSerdes2Write( 0x1, 0x0, 0x69, 0xe );
    osSerdes2Write( 0x1, 0x0, 0x6a, 0xe );
    osSerdes2Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x2, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x2, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x2, 0x0, 0x67, 0xa );
    osSerdes2Write( 0x2, 0x0, 0x68, 0xa );
    osSerdes2Write( 0x2, 0x0, 0x69, 0xe );
    osSerdes2Write( 0x2, 0x0, 0x6a, 0xe );
    osSerdes2Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x3, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x3, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x3, 0x0, 0x67, 0xa );
    osSerdes2Write( 0x3, 0x0, 0x68, 0xa );
    osSerdes2Write( 0x3, 0x0, 0x69, 0xe );
    osSerdes2Write( 0x3, 0x0, 0x6a, 0xe );
    osSerdes2Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes2Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x67, 0x6c );
    osSerdes2Write( 0x4, 0x0, 0x68, 0xbf );
    osSerdes2Write( 0x4, 0x0, 0x69, 0xbf );
    osSerdes2Write( 0x4, 0x0, 0x6a, 0xa );
    osSerdes2Write( 0x4, 0x0, 0x6b, 0xa );
    osSerdes2Write( 0x4, 0x0, 0x6c, 0xe );
    osSerdes2Write( 0x4, 0x0, 0x6d, 0xe );
    osSerdes2Write( 0x4, 0x0, 0x6e, 0x7 );
    osSerdes2Write( 0x4, 0x0, 0x6f, 0xc );
    osSerdes2Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x75, 0xb3 );
    osSerdes2Write( 0x4, 0x0, 0x76, 0xf6 );
    osSerdes2Write( 0x4, 0x0, 0x77, 0xd0 );
    osSerdes2Write( 0x4, 0x0, 0x78, 0xef );
    osSerdes2Write( 0x4, 0x0, 0x79, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x7a, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7f, 0xd3 );
    osSerdes2Write( 0x4, 0x0, 0x80, 0xd3 );
    osSerdes2Write( 0x4, 0x0, 0x81, 0xe2 );
    osSerdes2Write( 0x4, 0x0, 0x82, 0xef );
    osSerdes2Write( 0x4, 0x0, 0x83, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x84, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x85, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x86, 0xef );
    osSerdes2Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x89, 0xd3 );
    osSerdes2Write( 0x4, 0x0, 0x8a, 0xd3 );
    osSerdes2Write( 0x4, 0x0, 0x8b, 0xe2 );
    osSerdes2Write( 0x4, 0x0, 0x8c, 0xef );
    osSerdes2Write( 0x4, 0x0, 0x8d, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x8e, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x8f, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x90, 0xef );
    osSerdes2Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x93, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x94, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes2Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x97, 0x64 );
    osSerdes2Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x99, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes2Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes2Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes2Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x37, 0x9c );
    osSerdes2Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes2Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes2Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes2Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes2Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes2Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x2bd, 0x0 );



    /*配置并行数据接口的数据位宽和速率*/
    /*Addr[ioctrl1_base_addr+0x10],data[bit31-29=3'b010, bit28-26=3'b010,*/
    /*bit25-23=3'b010,bit22-20=3b010,bit19-17=3b010,bit16-14=3b010,*/
    /*bit13-11=3b010,bit10-8=3b010,bit7-0=all 1]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x10, 0x492492FF, 0x492492FF );

    /*addr[ioctrl1_base_addr+0x14],data[bit31-24=all0,bit23-21=3'b011,*/
    /*bit20-18=3'b011,bit17-15=3'b011,bit14-12=3'b011,bit11-9=3'b011,*/
    /*bit8-6=3'b011,bit5-3=3'b011,bit2-0=3'b011]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x14, 0x6DB6DB, 0x6DB6DB );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit19=1,bit18-10=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0xFFC00, 0xffffffff );

    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl1_base_addr+0x400],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;

}


/*****************************************************************
函数名 :  osSerdes2InitPcie2g5
输入参数    :   None
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes2InitPcie2g5(void)
{
    //UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    //INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit19=1,bit18-15=all 1,bit14-10=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0xF8000, 0xFFFF83FF );

    /*3、设置模式为pcie-mode*/
    /*Addr[ioctrl1_base_addr+0xC],data[bit11=1]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0xC, 0x800, 0xFFFFFFFF );

    /*配置pcie controller 这是控制器配置可问冯海/刘君龙*/



    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit19=1,bit18-10=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x80000, 0xFFF803FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载PCIe_100MHz_VSM.txt配置文件*/
    osSerdes2Write( 0x0, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x0, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x0, 0x0, 0x67, 0x8 );
    osSerdes2Write( 0x0, 0x0, 0x68, 0x5 );
    osSerdes2Write( 0x0, 0x0, 0x69, 0x13 );
    osSerdes2Write( 0x0, 0x0, 0x6a, 0x22 );
    osSerdes2Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6d, 0x31 );
    osSerdes2Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x1, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x1, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x1, 0x0, 0x67, 0x8 );
    osSerdes2Write( 0x1, 0x0, 0x68, 0x5 );
    osSerdes2Write( 0x1, 0x0, 0x69, 0x13 );
    osSerdes2Write( 0x1, 0x0, 0x6a, 0x22 );
    osSerdes2Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6d, 0x31 );
    osSerdes2Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x2, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x2, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x2, 0x0, 0x67, 0x8 );
    osSerdes2Write( 0x2, 0x0, 0x68, 0x5 );
    osSerdes2Write( 0x2, 0x0, 0x69, 0x13 );
    osSerdes2Write( 0x2, 0x0, 0x6a, 0x22 );
    osSerdes2Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6d, 0x31 );
    osSerdes2Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x3, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x3, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x3, 0x0, 0x67, 0x8 );
    osSerdes2Write( 0x3, 0x0, 0x68, 0x5 );
    osSerdes2Write( 0x3, 0x0, 0x69, 0x13 );
    osSerdes2Write( 0x3, 0x0, 0x6a, 0x22 );
    osSerdes2Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6d, 0x31 );
    osSerdes2Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes2Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x67, 0x45 );
    osSerdes2Write( 0x4, 0x0, 0x68, 0xbf );
    osSerdes2Write( 0x4, 0x0, 0x69, 0xbf );
    osSerdes2Write( 0x4, 0x0, 0x6a, 0x8 );
    osSerdes2Write( 0x4, 0x0, 0x6b, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x6c, 0x13 );
    osSerdes2Write( 0x4, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x4, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x6f, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x75, 0xcf );
    osSerdes2Write( 0x4, 0x0, 0x76, 0xf7 );
    osSerdes2Write( 0x4, 0x0, 0x77, 0xe1 );
    osSerdes2Write( 0x4, 0x0, 0x78, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x79, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x7a, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7f, 0xe3 );
    osSerdes2Write( 0x4, 0x0, 0x80, 0xe7 );
    osSerdes2Write( 0x4, 0x0, 0x81, 0xdb );
    osSerdes2Write( 0x4, 0x0, 0x82, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x83, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x84, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x85, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x86, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x89, 0xe3 );
    osSerdes2Write( 0x4, 0x0, 0x8a, 0xe7 );
    osSerdes2Write( 0x4, 0x0, 0x8b, 0xdb );
    osSerdes2Write( 0x4, 0x0, 0x8c, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x8d, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x8e, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x8f, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x90, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x93, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x94, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes2Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x97, 0x32 );
    osSerdes2Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x99, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes2Write( 0x4, 0x0, 0x9b, 0x1 );
    osSerdes2Write( 0x4, 0x0, 0x9c, 0x1 );
    osSerdes2Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes2Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes2Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x37, 0xa6 );
    osSerdes2Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0xa5, 0x0 );
    osSerdes2Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes2Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes2Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes2Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes2Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x2bd, 0x0 );


    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit19=1,bit18-15=all 1, bit14-10=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0xF8000, 0xFFFF83FF );

    /*等待pcie linkup*/


    return OS_SUCCESS;
}



/*****************************************************************
函数名 :  osSerdes2InitPcie5g
输入参数    :   None
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes2InitPcie5g(void)
{
    //UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    //INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit19=1,bit18-15=all 1,bit14-10=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0xF8000, 0xFFFF83FF );

    /*3、设置模式为pcie-mode*/
    /*Addr[ioctrl1_base_addr+0xC],data[bit11=1]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0xC, 0x800, 0xFFFFFFFF );

    /*配置pcie controller 这是控制器配置可问冯海/刘君龙*/



    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit19=1,bit18-10=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x80000, 0xFFF803FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载PCIe_100MHz_VSM.txt配置文件*/
    osSerdes2Write( 0x0, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x0, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x0, 0x0, 0x67, 0x8 );
    osSerdes2Write( 0x0, 0x0, 0x68, 0x5 );
    osSerdes2Write( 0x0, 0x0, 0x69, 0x13 );
    osSerdes2Write( 0x0, 0x0, 0x6a, 0x22 );
    osSerdes2Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6d, 0x31 );
    osSerdes2Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x1, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x1, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x1, 0x0, 0x67, 0x8 );
    osSerdes2Write( 0x1, 0x0, 0x68, 0x5 );
    osSerdes2Write( 0x1, 0x0, 0x69, 0x13 );
    osSerdes2Write( 0x1, 0x0, 0x6a, 0x22 );
    osSerdes2Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6d, 0x31 );
    osSerdes2Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x2, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x2, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x2, 0x0, 0x67, 0x8 );
    osSerdes2Write( 0x2, 0x0, 0x68, 0x5 );
    osSerdes2Write( 0x2, 0x0, 0x69, 0x13 );
    osSerdes2Write( 0x2, 0x0, 0x6a, 0x22 );
    osSerdes2Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6d, 0x31 );
    osSerdes2Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x3, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x3, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x3, 0x0, 0x67, 0x8 );
    osSerdes2Write( 0x3, 0x0, 0x68, 0x5 );
    osSerdes2Write( 0x3, 0x0, 0x69, 0x13 );
    osSerdes2Write( 0x3, 0x0, 0x6a, 0x22 );
    osSerdes2Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6d, 0x31 );
    osSerdes2Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes2Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x67, 0x45 );
    osSerdes2Write( 0x4, 0x0, 0x68, 0xbf );
    osSerdes2Write( 0x4, 0x0, 0x69, 0xbf );
    osSerdes2Write( 0x4, 0x0, 0x6a, 0x8 );
    osSerdes2Write( 0x4, 0x0, 0x6b, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x6c, 0x13 );
    osSerdes2Write( 0x4, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x4, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x6f, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x75, 0xcf );
    osSerdes2Write( 0x4, 0x0, 0x76, 0xf7 );
    osSerdes2Write( 0x4, 0x0, 0x77, 0xe1 );
    osSerdes2Write( 0x4, 0x0, 0x78, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x79, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x7a, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7f, 0xe3 );
    osSerdes2Write( 0x4, 0x0, 0x80, 0xe7 );
    osSerdes2Write( 0x4, 0x0, 0x81, 0xdb );
    osSerdes2Write( 0x4, 0x0, 0x82, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x83, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x84, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x85, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x86, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x89, 0xe3 );
    osSerdes2Write( 0x4, 0x0, 0x8a, 0xe7 );
    osSerdes2Write( 0x4, 0x0, 0x8b, 0xdb );
    osSerdes2Write( 0x4, 0x0, 0x8c, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x8d, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x8e, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x8f, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x90, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x93, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x94, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes2Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x97, 0x32 );
    osSerdes2Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x99, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes2Write( 0x4, 0x0, 0x9b, 0x1 );
    osSerdes2Write( 0x4, 0x0, 0x9c, 0x1 );
    osSerdes2Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes2Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes2Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x37, 0xa6 );
    osSerdes2Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0xa5, 0x0 );
    osSerdes2Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes2Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes2Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes2Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes2Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x2bd, 0x0 );


    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit19=1,bit18-15=all 1, bit14-10=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0xF8000, 0xFFFF83FF );

    /*等待pcie linkup*/


    return OS_SUCCESS;
}

/*****************************************************************
函数名 :  osSerdes2InitPcie8g
输入参数    :   None
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes2InitPcie8g(void)
{
    //UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    //INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit19=1,bit18-15=all 1,bit14-10=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0xF8000, 0xFFFF83FF );

    /*3、设置模式为pcie-mode*/
    /*Addr[ioctrl1_base_addr+0xC],data[bit11=1]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0xC, 0x800, 0xFFFFFFFF );

    /*配置pcie controller 这是控制器配置可问冯海/刘君龙*/



    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit19=1,bit18-10=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x80000, 0xFFF803FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*加载PCIe_100MHz_VSM.txt配置文件*/
    osSerdes2Write( 0x0, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x0, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x0, 0x0, 0x67, 0x5 );
    osSerdes2Write( 0x0, 0x0, 0x68, 0x5 );
    osSerdes2Write( 0x0, 0x0, 0x69, 0x22 );
    osSerdes2Write( 0x0, 0x0, 0x6a, 0x22 );
    osSerdes2Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6d, 0x33 );
    osSerdes2Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x1, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x1, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x1, 0x0, 0x67, 0x5 );
    osSerdes2Write( 0x1, 0x0, 0x68, 0x5 );
    osSerdes2Write( 0x1, 0x0, 0x69, 0x22 );
    osSerdes2Write( 0x1, 0x0, 0x6a, 0x22 );
    osSerdes2Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6d, 0x33 );
    osSerdes2Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x2, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x2, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x2, 0x0, 0x67, 0x5 );
    osSerdes2Write( 0x2, 0x0, 0x68, 0x5 );
    osSerdes2Write( 0x2, 0x0, 0x69, 0x22 );
    osSerdes2Write( 0x2, 0x0, 0x6a, 0x22 );
    osSerdes2Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6d, 0x33 );
    osSerdes2Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x3, 0x0, 0x65, 0xbf );
    osSerdes2Write( 0x3, 0x0, 0x66, 0xbf );
    osSerdes2Write( 0x3, 0x0, 0x67, 0x5 );
    osSerdes2Write( 0x3, 0x0, 0x68, 0x5 );
    osSerdes2Write( 0x3, 0x0, 0x69, 0x22 );
    osSerdes2Write( 0x3, 0x0, 0x6a, 0x22 );
    osSerdes2Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6d, 0x33 );
    osSerdes2Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes2Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x67, 0x45 );
    osSerdes2Write( 0x4, 0x0, 0x68, 0xbf );
    osSerdes2Write( 0x4, 0x0, 0x69, 0xbf );
    osSerdes2Write( 0x4, 0x0, 0x6a, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x6b, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x6c, 0x22 );
    osSerdes2Write( 0x4, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x4, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x6f, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x75, 0xcf );
    osSerdes2Write( 0x4, 0x0, 0x76, 0xf7 );
    osSerdes2Write( 0x4, 0x0, 0x77, 0xe1 );
    osSerdes2Write( 0x4, 0x0, 0x78, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x79, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x7a, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7f, 0xe3 );
    osSerdes2Write( 0x4, 0x0, 0x80, 0xe7 );
    osSerdes2Write( 0x4, 0x0, 0x81, 0xdb );
    osSerdes2Write( 0x4, 0x0, 0x82, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x83, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x84, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x85, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x86, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x89, 0xe3 );
    osSerdes2Write( 0x4, 0x0, 0x8a, 0xe7 );
    osSerdes2Write( 0x4, 0x0, 0x8b, 0xdb );
    osSerdes2Write( 0x4, 0x0, 0x8c, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x8d, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x8e, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x8f, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x90, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x93, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x94, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes2Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x97, 0x32 );
    osSerdes2Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x99, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes2Write( 0x4, 0x0, 0x9b, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x9c, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes2Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes2Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x37, 0xc4 );
    osSerdes2Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0xa5, 0x0 );
    osSerdes2Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes2Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes2Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes2Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes2Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x2bd, 0x0 );



    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit19=1,bit18-15=all 1, bit14-10=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0xF8000, 0xFFFF83FF );

    /*等待pcie linkup*/


    return OS_SUCCESS;
}


/*****************************************************************
函数名 :  osSerdes2InitSataHostAuto
输入参数    :   None
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes2InitSataHostAuto(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    /*Addr[ioctrl1_base_addr+0x14],data[bit31-24=all 0,bit23-0=24'h249249]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x14, 0x249249, 0x249249 );
    /*Addr[ioctrl1_base_addr+0x10],data[bit31-8=24'h249249,bit7-0=all 0]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x10, 0x24924900, 0x24924900 );
    /*Addr[ioctrl1_base_addr+0x30],data[bit27-24=all 0]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x30, 0x0, 0xF0FFFFFF );

    /*Addr[sysctrl_base_addr+0x588],data[bit19-10=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0xFFC00, 0xFFFFFFFF );

    /*Addr[sysctrl_base_addr+0x600],data[bit17-16=2'b11]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x600, 0x30000, 0xFFFFFFFF );

    /*Addr[ioctrl1_base_addr+0x8],data[bit0=0]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x8, 0x0, 0xFFFFFFFE );

    /*Addr[sysctrl_base_addr+0x310],data[bit1-0=2'b00]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x310, 0x0, 0xFFFFFFFC );

    /*Addr[sysctrl_base_addr+0x314],data[bit1-0=2'b11]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x314, 0x3, 0xFFFFFFFF );

    /*Addr[ioctrl1_base_addr+0xC],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0xC, 0x0, 0xFFFFF7FF );

    /*Addr[sysctrl_base_addr+0x58c],data[bit19=1,bit18-10=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58C, 0x80000, 0xFFF803FF );

    osSerdesWait( 1000 );

    /*SATA_100MHz_VSM.txt*/
    osSerdes2Write( 0x0, 0x0, 0x65, 0xc9 );
    osSerdes2Write( 0x0, 0x0, 0x66, 0xc9 );
    osSerdes2Write( 0x0, 0x0, 0x67, 0x7 );
    osSerdes2Write( 0x0, 0x0, 0x68, 0x7 );
    osSerdes2Write( 0x0, 0x0, 0x69, 0x18 );
    osSerdes2Write( 0x0, 0x0, 0x6a, 0x18 );
    osSerdes2Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x1, 0x0, 0x65, 0xc9 );
    osSerdes2Write( 0x1, 0x0, 0x66, 0xc9 );
    osSerdes2Write( 0x1, 0x0, 0x67, 0x7 );
    osSerdes2Write( 0x1, 0x0, 0x68, 0x7 );
    osSerdes2Write( 0x1, 0x0, 0x69, 0x18 );
    osSerdes2Write( 0x1, 0x0, 0x6a, 0x18 );
    osSerdes2Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x2, 0x0, 0x65, 0xc9 );
    osSerdes2Write( 0x2, 0x0, 0x66, 0xc9 );
    osSerdes2Write( 0x2, 0x0, 0x67, 0x7 );
    osSerdes2Write( 0x2, 0x0, 0x68, 0x7 );
    osSerdes2Write( 0x2, 0x0, 0x69, 0x18 );
    osSerdes2Write( 0x2, 0x0, 0x6a, 0x18 );
    osSerdes2Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x3, 0x0, 0x65, 0xc9 );
    osSerdes2Write( 0x3, 0x0, 0x66, 0xc9 );
    osSerdes2Write( 0x3, 0x0, 0x67, 0x7 );
    osSerdes2Write( 0x3, 0x0, 0x68, 0x7 );
    osSerdes2Write( 0x3, 0x0, 0x69, 0x18 );
    osSerdes2Write( 0x3, 0x0, 0x6a, 0x18 );
    osSerdes2Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes2Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x67, 0x45 );
    osSerdes2Write( 0x4, 0x0, 0x68, 0xc9 );
    osSerdes2Write( 0x4, 0x0, 0x69, 0xc9 );
    osSerdes2Write( 0x4, 0x0, 0x6a, 0x7 );
    osSerdes2Write( 0x4, 0x0, 0x6b, 0x7 );
    osSerdes2Write( 0x4, 0x0, 0x6c, 0x18 );
    osSerdes2Write( 0x4, 0x0, 0x6d, 0x18 );
    osSerdes2Write( 0x4, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x6f, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x75, 0xcf );
    osSerdes2Write( 0x4, 0x0, 0x76, 0xf7 );
    osSerdes2Write( 0x4, 0x0, 0x77, 0xe1 );
    osSerdes2Write( 0x4, 0x0, 0x78, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x79, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x7a, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7f, 0xe3 );
    osSerdes2Write( 0x4, 0x0, 0x80, 0xe7 );
    osSerdes2Write( 0x4, 0x0, 0x81, 0xdb );
    osSerdes2Write( 0x4, 0x0, 0x82, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x83, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x84, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x85, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x86, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x89, 0xe3 );
    osSerdes2Write( 0x4, 0x0, 0x8a, 0xe7 );
    osSerdes2Write( 0x4, 0x0, 0x8b, 0xdb );
    osSerdes2Write( 0x4, 0x0, 0x8c, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x8d, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x8e, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x8f, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x90, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x93, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x94, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes2Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x97, 0x32 );
    osSerdes2Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x99, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes2Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes2Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes2Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x37, 0xb0 );
    osSerdes2Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes2Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes2Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes2Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes2Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes2Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x2bd, 0x0 );

    osSerdesWait( 0x1000 );
    /*Addr[sysctrl_base_addr+0x58c], data[bit19=1,bit18-10=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58C, 0xFFC00, 0xFFFFFFFF );

    /*Addr[ioctrl1_base_addr+0x400],data[bit11-4==all 1],等待bit11-4全部为1，即为等到ready*/
    /*Addr[ioctrl1_base_addr+0x400],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }

    /*Addr[ioctrl1_base_addr+0x8],data[bit0=1]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x8, 0x1, 0xFFFFFFFF );

    /*Addr[sysctrl_base_addr+0x604],data[bit17-16=2'b11]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x604, 0x30000, 0xFFFFFFFF );

    /*Addr[sysctrl_base_addr+0x310],data[bit1-0=2'b11]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x310, 0x3, 0xFFFFFFFF );

    /*Addr[sysctrl_base_addr+0x314],data[bit1-0=2'b00]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x314, 0x0, 0xFFFFFFFC );

    /*Addr[ioctrl1_base_addr+0x0],data[bit15-12=4'b1,bit11-8=4'b1,bit7-4=4'b1,bit3-0=4'b1]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x0, 0x1111, 0xFFFF1111 );

    /*开始配置SATA控制器*/



    return OS_SUCCESS;

}


/*****************************************************************
函数名 :  osSerdes2InitSata1g5
输入参数    :   None
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes2InitSata1g5(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    /*Addr[sysctrl_base_addr+0x588],data[bit19-10=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0xFFC00, 0xFFFFFFFF );
    /*Addr[ioctrl1_base_addr+0xC],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0xC, 0x0, 0xFFFFF7FF );

    osSerdesWait( 0x1000 );
    /*Addr[sysctrl_base_addr+0x58c],data[bit19=1,bit18-10=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58C, 0x80000, 0xFFF803FF );

    osSerdesWait( 0x1000 );
    /*SATA_100MHz_VSM.txt*/
    osSerdes2Write( 0x0, 0x0, 0x65, 0xc9 );
    osSerdes2Write( 0x0, 0x0, 0x66, 0xc9 );
    osSerdes2Write( 0x0, 0x0, 0x67, 0x7 );
    osSerdes2Write( 0x0, 0x0, 0x68, 0x7 );
    osSerdes2Write( 0x0, 0x0, 0x69, 0x18 );
    osSerdes2Write( 0x0, 0x0, 0x6a, 0x18 );
    osSerdes2Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x1, 0x0, 0x65, 0xc9 );
    osSerdes2Write( 0x1, 0x0, 0x66, 0xc9 );
    osSerdes2Write( 0x1, 0x0, 0x67, 0x7 );
    osSerdes2Write( 0x1, 0x0, 0x68, 0x7 );
    osSerdes2Write( 0x1, 0x0, 0x69, 0x18 );
    osSerdes2Write( 0x1, 0x0, 0x6a, 0x18 );
    osSerdes2Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x2, 0x0, 0x65, 0xc9 );
    osSerdes2Write( 0x2, 0x0, 0x66, 0xc9 );
    osSerdes2Write( 0x2, 0x0, 0x67, 0x7 );
    osSerdes2Write( 0x2, 0x0, 0x68, 0x7 );
    osSerdes2Write( 0x2, 0x0, 0x69, 0x18 );
    osSerdes2Write( 0x2, 0x0, 0x6a, 0x18 );
    osSerdes2Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x3, 0x0, 0x65, 0xc9 );
    osSerdes2Write( 0x3, 0x0, 0x66, 0xc9 );
    osSerdes2Write( 0x3, 0x0, 0x67, 0x7 );
    osSerdes2Write( 0x3, 0x0, 0x68, 0x7 );
    osSerdes2Write( 0x3, 0x0, 0x69, 0x18 );
    osSerdes2Write( 0x3, 0x0, 0x6a, 0x18 );
    osSerdes2Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes2Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x67, 0x45 );
    osSerdes2Write( 0x4, 0x0, 0x68, 0xc9 );
    osSerdes2Write( 0x4, 0x0, 0x69, 0xc9 );
    osSerdes2Write( 0x4, 0x0, 0x6a, 0x7 );
    osSerdes2Write( 0x4, 0x0, 0x6b, 0x7 );
    osSerdes2Write( 0x4, 0x0, 0x6c, 0x18 );
    osSerdes2Write( 0x4, 0x0, 0x6d, 0x18 );
    osSerdes2Write( 0x4, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x6f, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x75, 0xcf );
    osSerdes2Write( 0x4, 0x0, 0x76, 0xf7 );
    osSerdes2Write( 0x4, 0x0, 0x77, 0xe1 );
    osSerdes2Write( 0x4, 0x0, 0x78, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x79, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x7a, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7f, 0xe3 );
    osSerdes2Write( 0x4, 0x0, 0x80, 0xe7 );
    osSerdes2Write( 0x4, 0x0, 0x81, 0xdb );
    osSerdes2Write( 0x4, 0x0, 0x82, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x83, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x84, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x85, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x86, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x89, 0xe3 );
    osSerdes2Write( 0x4, 0x0, 0x8a, 0xe7 );
    osSerdes2Write( 0x4, 0x0, 0x8b, 0xdb );
    osSerdes2Write( 0x4, 0x0, 0x8c, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x8d, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x8e, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x8f, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x90, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x93, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x94, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes2Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x97, 0x32 );
    osSerdes2Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x99, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes2Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes2Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes2Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x37, 0xb0 );
    osSerdes2Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes2Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes2Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes2Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes2Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes2Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x2bd, 0x0 );

    /*Addr[ioctrl1_base_addr+0x10],data[bit31-29=3'b001, bit28-26=3'b001,*/
    /*bit25-23=3'b001,bit22-20=3b001,bit19-17=3b001,bit16-14=3b001,*/
    /*bit13-11=3b001,bit10-8=3b001,bit7-0=all 1]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x10, 0x249249FF, 0x249249FF );

    /*addr[ioctrl1_base_addr+0x14],data[bit31-24=all0,bit23-21=3'b001,*/
    /*bit20-18=3'b001,bit17-15=3'b001,bit14-12=3'b001,bit11-9=3'b001,*/
    /*bit8-6=3'b001,bit5-3=3'b001,bit2-0=3'b001]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x14, 0x249249, 0x249249 );

    osSerdesWait( 0x1000 );
    /*Addr[sysctrl_base_addr+0x58c], data[bit19=1,bit18-10=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58C, 0xFFC00, 0xFFFFFFFF );

    /*Addr[ioctrl1_base_addr+0x400],data[bit11-4==all 1],等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;
}


/*****************************************************************
函数名 :  osSerdes2InitSata3g
输入参数    :   None
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes2InitSata3g(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    /*Addr[sysctrl_base_addr+0x588],data[bit19-10=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0xFFC00, 0xFFFFFFFF );
    /*Addr[ioctrl1_base_addr+0xC],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0xC, 0x0, 0xFFFFF7FF );

    osSerdesWait( 0x1000 );
    /*Addr[sysctrl_base_addr+0x58c],data[bit19=1,bit18-10=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58C, 0x80000, 0xFFF803FF );

    osSerdesWait( 0x1000 );
    /*SATA_100MHz_VSM.txt*/
    osSerdes2Write( 0x0, 0x0, 0x65, 0xc9 );
    osSerdes2Write( 0x0, 0x0, 0x66, 0xc9 );
    osSerdes2Write( 0x0, 0x0, 0x67, 0x7 );
    osSerdes2Write( 0x0, 0x0, 0x68, 0x7 );
    osSerdes2Write( 0x0, 0x0, 0x69, 0x18 );
    osSerdes2Write( 0x0, 0x0, 0x6a, 0x18 );
    osSerdes2Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x1, 0x0, 0x65, 0xc9 );
    osSerdes2Write( 0x1, 0x0, 0x66, 0xc9 );
    osSerdes2Write( 0x1, 0x0, 0x67, 0x7 );
    osSerdes2Write( 0x1, 0x0, 0x68, 0x7 );
    osSerdes2Write( 0x1, 0x0, 0x69, 0x18 );
    osSerdes2Write( 0x1, 0x0, 0x6a, 0x18 );
    osSerdes2Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x2, 0x0, 0x65, 0xc9 );
    osSerdes2Write( 0x2, 0x0, 0x66, 0xc9 );
    osSerdes2Write( 0x2, 0x0, 0x67, 0x7 );
    osSerdes2Write( 0x2, 0x0, 0x68, 0x7 );
    osSerdes2Write( 0x2, 0x0, 0x69, 0x18 );
    osSerdes2Write( 0x2, 0x0, 0x6a, 0x18 );
    osSerdes2Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x3, 0x0, 0x65, 0xc9 );
    osSerdes2Write( 0x3, 0x0, 0x66, 0xc9 );
    osSerdes2Write( 0x3, 0x0, 0x67, 0x7 );
    osSerdes2Write( 0x3, 0x0, 0x68, 0x7 );
    osSerdes2Write( 0x3, 0x0, 0x69, 0x18 );
    osSerdes2Write( 0x3, 0x0, 0x6a, 0x18 );
    osSerdes2Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes2Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x67, 0x45 );
    osSerdes2Write( 0x4, 0x0, 0x68, 0xc9 );
    osSerdes2Write( 0x4, 0x0, 0x69, 0xc9 );
    osSerdes2Write( 0x4, 0x0, 0x6a, 0x7 );
    osSerdes2Write( 0x4, 0x0, 0x6b, 0x7 );
    osSerdes2Write( 0x4, 0x0, 0x6c, 0x18 );
    osSerdes2Write( 0x4, 0x0, 0x6d, 0x18 );
    osSerdes2Write( 0x4, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x6f, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x75, 0xcf );
    osSerdes2Write( 0x4, 0x0, 0x76, 0xf7 );
    osSerdes2Write( 0x4, 0x0, 0x77, 0xe1 );
    osSerdes2Write( 0x4, 0x0, 0x78, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x79, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x7a, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7f, 0xe3 );
    osSerdes2Write( 0x4, 0x0, 0x80, 0xe7 );
    osSerdes2Write( 0x4, 0x0, 0x81, 0xdb );
    osSerdes2Write( 0x4, 0x0, 0x82, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x83, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x84, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x85, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x86, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x89, 0xe3 );
    osSerdes2Write( 0x4, 0x0, 0x8a, 0xe7 );
    osSerdes2Write( 0x4, 0x0, 0x8b, 0xdb );
    osSerdes2Write( 0x4, 0x0, 0x8c, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x8d, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x8e, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x8f, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x90, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x93, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x94, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes2Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x97, 0x32 );
    osSerdes2Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x99, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes2Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes2Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes2Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x37, 0xb0 );
    osSerdes2Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes2Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes2Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes2Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes2Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes2Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x2bd, 0x0 );

    /*Addr[ioctrl1_base_addr+0x10],data[bit31-29=3'b011, bit28-26=3'b011,*/
    /*bit25-23=3'b011,bit22-20=3b011,bit19-17=3b011,bit16-14=3b011,*/
    /*bit13-11=3b011,bit10-8=3b011,bit7-0=all 1]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x10, 0x6DB6DBFF, 0x6DB6DBFF );

    /*addr[ioctrl1_base_addr+0x14],data[bit31-24=all0,bit23-21=3'b010,*/
    /*bit20-18=3'b010,bit17-15=3'b010,bit14-12=3'b010,bit11-9=3'b010,*/
    /*bit8-6=3'b010,bit5-3=3'b010,bit2-0=3'b010]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x14, 0x492492, 0x492492 );

    osSerdesWait( 0x1000 );
    /*Addr[sysctrl_base_addr+0x58c], data[bit19=1,bit18-10=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58C, 0xFFC00, 0xFFFFFFFF );

    /*Addr[ioctrl1_base_addr+0x400],data[bit11-4==all 1],等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;
}


/*****************************************************************
函数名 :  osSerdes2InitSata6g
输入参数    :   None
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes2InitSata6g(void)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    /*Addr[sysctrl_base_addr+0x588],data[bit19-10=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0xFFC00, 0xFFFFFFFF );
    /*Addr[ioctrl1_base_addr+0xC],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0xC, 0x0, 0xFFFFF7FF );

    osSerdesWait( 0x1000 );
    /*Addr[sysctrl_base_addr+0x58c],data[bit19=1,bit18-10=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58C, 0x80000, 0xFFF803FF );

    osSerdesWait( 0x1000 );
    /*SATA_100MHz_VSM.txt*/
    osSerdes2Write( 0x0, 0x0, 0x65, 0xc9 );
    osSerdes2Write( 0x0, 0x0, 0x66, 0xc9 );
    osSerdes2Write( 0x0, 0x0, 0x67, 0x7 );
    osSerdes2Write( 0x0, 0x0, 0x68, 0x7 );
    osSerdes2Write( 0x0, 0x0, 0x69, 0x18 );
    osSerdes2Write( 0x0, 0x0, 0x6a, 0x18 );
    osSerdes2Write( 0x0, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x0, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x0, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x1, 0x0, 0x65, 0xc9 );
    osSerdes2Write( 0x1, 0x0, 0x66, 0xc9 );
    osSerdes2Write( 0x1, 0x0, 0x67, 0x7 );
    osSerdes2Write( 0x1, 0x0, 0x68, 0x7 );
    osSerdes2Write( 0x1, 0x0, 0x69, 0x18 );
    osSerdes2Write( 0x1, 0x0, 0x6a, 0x18 );
    osSerdes2Write( 0x1, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x1, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x1, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x2, 0x0, 0x65, 0xc9 );
    osSerdes2Write( 0x2, 0x0, 0x66, 0xc9 );
    osSerdes2Write( 0x2, 0x0, 0x67, 0x7 );
    osSerdes2Write( 0x2, 0x0, 0x68, 0x7 );
    osSerdes2Write( 0x2, 0x0, 0x69, 0x18 );
    osSerdes2Write( 0x2, 0x0, 0x6a, 0x18 );
    osSerdes2Write( 0x2, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x2, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x2, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x3, 0x0, 0x65, 0xc9 );
    osSerdes2Write( 0x3, 0x0, 0x66, 0xc9 );
    osSerdes2Write( 0x3, 0x0, 0x67, 0x7 );
    osSerdes2Write( 0x3, 0x0, 0x68, 0x7 );
    osSerdes2Write( 0x3, 0x0, 0x69, 0x18 );
    osSerdes2Write( 0x3, 0x0, 0x6a, 0x18 );
    osSerdes2Write( 0x3, 0x0, 0x6b, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6c, 0x1 );
    osSerdes2Write( 0x3, 0x0, 0x6d, 0x22 );
    osSerdes2Write( 0x3, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x65, 0xaa );
    osSerdes2Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x67, 0x45 );
    osSerdes2Write( 0x4, 0x0, 0x68, 0xc9 );
    osSerdes2Write( 0x4, 0x0, 0x69, 0xc9 );
    osSerdes2Write( 0x4, 0x0, 0x6a, 0x7 );
    osSerdes2Write( 0x4, 0x0, 0x6b, 0x7 );
    osSerdes2Write( 0x4, 0x0, 0x6c, 0x18 );
    osSerdes2Write( 0x4, 0x0, 0x6d, 0x18 );
    osSerdes2Write( 0x4, 0x0, 0x6e, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x6f, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x70, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x72, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x75, 0xcf );
    osSerdes2Write( 0x4, 0x0, 0x76, 0xf7 );
    osSerdes2Write( 0x4, 0x0, 0x77, 0xe1 );
    osSerdes2Write( 0x4, 0x0, 0x78, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x79, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x7a, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7f, 0xe3 );
    osSerdes2Write( 0x4, 0x0, 0x80, 0xe7 );
    osSerdes2Write( 0x4, 0x0, 0x81, 0xdb );
    osSerdes2Write( 0x4, 0x0, 0x82, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x83, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x84, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x85, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x86, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x89, 0xe3 );
    osSerdes2Write( 0x4, 0x0, 0x8a, 0xe7 );
    osSerdes2Write( 0x4, 0x0, 0x8b, 0xdb );
    osSerdes2Write( 0x4, 0x0, 0x8c, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x8d, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x8e, 0xfd );
    osSerdes2Write( 0x4, 0x0, 0x8f, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x90, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x93, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x94, 0xf5 );
    osSerdes2Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes2Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x97, 0x32 );
    osSerdes2Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x99, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0x9a, 0x1 );
    osSerdes2Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes2Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes2Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x37, 0xb0 );
    osSerdes2Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes2Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes2Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes2Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes2Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes2Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x2bd, 0x0 );

    /*Addr[ioctrl1_base_addr+0x10],data[bit31-29=3'b011, bit28-26=3'b011,*/
    /*bit25-23=3'b011,bit22-20=3b011,bit19-17=3b011,bit16-14=3b011,*/
    /*bit13-11=3b011,bit10-8=3b011,bit7-0=all 1]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x10, 0x6DB6DBFF, 0x6DB6DBFF );

    /*addr[ioctrl1_base_addr+0x14],data[bit31-24=all0,bit23-21=3'b011,*/
    /*bit20-18=3'b011,bit17-15=3'b011,bit14-12=3'b011,bit11-9=3'b011,*/
    /*bit8-6=3'b011,bit5-3=3'b011,bit2-0=3'b011]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x14, 0x6DB6DB, 0x6DB6DB );

    osSerdesWait( 0x1000 );
    /*Addr[sysctrl_base_addr+0x58c], data[bit19=1,bit18-10=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58C, 0xFFC00, 0xFFFFFFFF );

    /*Addr[ioctrl1_base_addr+0x400],data[bit11-4==all 1],等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
    ulValue = ulValue & 0xFF0;
    while ( ( ulValue != 0xFF0 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
        ulValue = ulValue & 0xFF0;
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;
}


/*****************************************************************
函数名 :  osSerdes3InitSrio1g25
输入参数    :   None
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes3InitSrio1g25(void)
{
    UINT32 ulValue = 0;
    UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    /*Addr[sysctrl_base_addr+0x590],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x590, 0x1FFFF00, 0xFFFFFFFF );

    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=0,bit4=0]*/
    for ( ulLoop = 0; ulLoop < 4; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x0, 0xFFFFFFEE );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x0, 0xFFF7FFFF );

    /*Addr[serdes3_base_addr+0x0],data[bit29=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x0, 0x0, 0xDFFFFFFF );

    osSerdesWait( 0x1000 );
    /*Addr[serdes3_base_addr+0x4],data[bit8=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x4, 0x0, 0xFFFFFEFF );
    /*Addr[serdes3_base_addr+0x81c+0x80*0~3],data[bit7-6=2b10,bit5-3=3b10]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x81c + 0x80 * ulLoop, 0x90, 0xFFFFFF97 );
    }
    /*Addr[serdes3_base_addr+0x82c+0x80*0~3],data[bit7-6=2b10,bit5-3=3b10]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x82c + 0x80 * ulLoop, 0x90, 0xFFFFFF97 );
    }
    /*Addr[serdes3_base_addr+0x100],data[bit12-8=5'h1,bit23-16=8'd16]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x100, 0x100100, 0xFF10E1FF );
    /*Addr[serdes3_base_addr+0x108],data[bit31-24=8'h7]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x108, 0x7000000, 0x7FFFFFF );

    osSerdesWait( 0x1000 );
    /*Addr[sysctrl_base_addr+0x594],data[bit24=1, bit23-8= all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1000000, 0xFF0000FF );
    osSerdesWait( 1000000 );
    /*Addr[ioctrl1_base_addr+0x434],data[bit4=1, means pll is locked]*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    while ( 0x10 != ( ulValue & 0x10 ) && (-- ulWaitTime ) )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "osSerdes0WaitForPllCfg error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    osSerdesWait( 0x100 );
    /*Addr[sysctrl_base_addr+0x594],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1FFFF00, 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=1,bit4=1]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x11, 0xFFFFFFFF );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x80000, 0xFFFFFFFF );

    /*Addr[serdes3_base_addr+0x0],data[bit29=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x0, 0x20000000, 0xFFFFFFFF );

    osSerdesWait( 1000000 );

    return OS_SUCCESS;
}

/*****************************************************************
函数名 :  osSerdes3InitSrio2g5
输入参数    :   None
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes3InitSrio2g5(void)
{
    UINT32 ulValue = 0;
    UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    /*Addr[sysctrl_base_addr+0x590],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x590, 0x1FFFF00, 0xFFFFFFFF );

    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=0,bit4=0]*/
    for ( ulLoop = 0; ulLoop < 4; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x0, 0xFFFFFFEE );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x0, 0xFFF7FFFF );

    /*Addr[serdes3_base_addr+0x0],data[bit29=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x0, 0x0, 0xDFFFFFFF );

    osSerdesWait( 0x1000 );
    /*Addr[serdes3_base_addr+0x4],data[bit8=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x4, 0x0, 0xFFFFFEFF );
    /*Addr[serdes3_base_addr+0x81c+0x80*0~3],data[bit7-6=2b10,bit5-3=3b01]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x81c + 0x80 * ulLoop, 0x88, 0xFFFFFF8F );
    }
    /*Addr[serdes3_base_addr+0x82c+0x80*0~3],data[bit7-6=2b10,bit5-3=3b01]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x82c + 0x80 * ulLoop, 0x88, 0xFFFFFF8F );
    }
    /*Addr[serdes3_base_addr+0x100],data[bit12-8=5'h1,bit23-16=8'd20]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x100, 0x140100, 0xFF14E1FF );
    /*Addr[serdes3_base_addr+0x108],data[bit31-24=8'h7]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x108, 0x7000000, 0x7FFFFFF );

    osSerdesWait( 0x1000 );
    /*Addr[sysctrl_base_addr+0x594],data[bit24=1, bit23-8= all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1000000, 0xFF0000FF );
    osSerdesWait( 0x1000 );
    /*Addr[ioctrl1_base_addr+0x434],data[bit4=1, means pll is locked]*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    while ( 0x10 != ( ulValue & 0x10 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "osSerdes0WaitForPllCfg error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    osSerdesWait( 0x100 );
    /*Addr[sysctrl_base_addr+0x594],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1FFFF00, 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=1,bit4=1]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x11, 0xFFFFFFFF );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x80000, 0xFFFFFFFF );

    /*Addr[serdes3_base_addr+0x0],data[bit29=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x0, 0x20000000, 0xFFFFFFFF );

    osSerdesWait( 0x1000 );

    return OS_SUCCESS;
}


/*****************************************************************
函数名 :  osSerdes3InitSrio3g125
输入参数    :   None
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes3InitSrio3g125(void)
{
    UINT32 ulValue = 0;
    UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    /*Addr[sysctrl_base_addr+0x590],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x590, 0x1FFFF00, 0xFFFFFFFF );

    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=0,bit4=0]*/
    for ( ulLoop = 0; ulLoop < 4; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x0, 0xFFFFFFEE );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x0, 0xFFF7FFFF );

    /*Addr[serdes3_base_addr+0x0],data[bit29=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x0, 0x0, 0xDFFFFFFF );

    osSerdesWait( 0x1000 );
    /*Addr[serdes3_base_addr+0x4],data[bit8=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x4, 0x0, 0xFFFFFEFF );
    /*Addr[serdes3_base_addr+0x81c+0x80*0~3],data[bit7-6=2b10,bit5-3=3b01]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x81c + 0x80 * ulLoop, 0x88, 0xFFFFFF8F );
    }
    /*Addr[serdes3_base_addr+0x82c+0x80*0~3],data[bit7-6=2b10,bit5-3=3b01]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x82c + 0x80 * ulLoop, 0x88, 0xFFFFFF8F );
    }
    /*Addr[serdes3_base_addr+0x100],data[bit12-8=5'h1,bit23-16=8'd25]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x100, 0x190100, 0xFF19E1FF );
    /*Addr[serdes3_base_addr+0x108],data[bit31-24=8'h6]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x108, 0x6000000, 0x6ffffff );

    osSerdesWait( 0x1000 );
    /*Addr[sysctrl_base_addr+0x594],data[bit24=1, bit23-8= all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1000000, 0xFF0000FF );
    osSerdesWait( 0x1000 );
    /*Addr[ioctrl1_base_addr+0x434],data[bit4=1, means pll is locked]*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    while ( 0x10 != ( ulValue & 0x10 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "osSerdes0WaitForPllCfg error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    osSerdesWait( 0x100 );
    /*Addr[sysctrl_base_addr+0x594],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1FFFF00, 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=1,bit4=1]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x11, 0xFFFFFFFF );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x80000, 0xFFFFFFFF );

    /*Addr[serdes3_base_addr+0x0],data[bit29=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x0, 0x20000000, 0xFFFFFFFF );

    osSerdesWait( 0x1000 );

    return OS_SUCCESS;
}


/*****************************************************************
函数名 :  osSerdes3InitSrio5g
输入参数    :   None
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes3InitSrio5g(void)
{
    UINT32 ulValue = 0;
    UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    /*Addr[sysctrl_base_addr+0x590],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x590, 0x1FFFF00, 0xFFFFFFFF );

    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=0,bit4=0]*/
    for ( ulLoop = 0; ulLoop < 4; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x0, 0xFFFFFFEE );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x0, 0xFFF7FFFF );

    /*Addr[serdes3_base_addr+0x0],data[bit29=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x0, 0x0, 0xDFFFFFFF );

    osSerdesWait( 0x1000 );
    /*Addr[serdes3_base_addr+0x4],data[bit8=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x4, 0x0, 0xFFFFFEFF );
    /*Addr[serdes3_base_addr+0x81c+0x80*0~3],data[bit7-6=2b10,bit5-3=3b00]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x81c + 0x80 * ulLoop, 0x80, 0xFFFFFF87 );
    }
    /*Addr[serdes3_base_addr+0x82c+0x80*0~3],data[bit7-6=2b10,bit5-3=3b00]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x82c + 0x80 * ulLoop, 0x80, 0xFFFFFF87 );
    }
    /*Addr[serdes3_base_addr+0x100],data[bit12-8=5'h2,bit23-16=8'd40]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x100, 0x280200, 0xFF28E2FF );
    /*Addr[serdes3_base_addr+0x108],data[bit31-24=8'h7]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x108, 0x7000000, 0x7ffffff );

    osSerdesWait( 0x1000 );
    /*Addr[sysctrl_base_addr+0x594],data[bit24=1, bit23-8= all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1000000, 0xFF0000FF );
    osSerdesWait( 0x1000 );
    /*Addr[ioctrl1_base_addr+0x434],data[bit4=1, means pll is locked]*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    while ( 0x10 != ( ulValue & 0x10 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "osSerdes0WaitForPllCfg error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    osSerdesWait( 0x100 );
    /*Addr[sysctrl_base_addr+0x594],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1FFFF00, 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=1,bit4=1]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x11, 0xFFFFFFFF );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x80000, 0xFFFFFFFF );

    /*Addr[serdes3_base_addr+0x0],data[bit29=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x0, 0x20000000, 0xFFFFFFFF );

    osSerdesWait( 0x1000 );

    return OS_SUCCESS;
}

/*****************************************************************
函数名 :  osSerdes3InitSrio6g25
输入参数    :   None
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes3InitSrio6g25(void)
{
    UINT32 ulValue = 0;
    UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    /*Addr[sysctrl_base_addr+0x590],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x590, 0x1FFFF00, 0xFFFFFFFF );

    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=0,bit4=0]*/
    for ( ulLoop = 0; ulLoop < 4; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x0, 0xFFFFFFEE );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x0, 0xFFF7FFFF );

    /*Addr[serdes3_base_addr+0x0],data[bit29=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x0, 0x0, 0xDFFFFFFF );

    osSerdesWait( 0x1000 );
    /*Addr[serdes3_base_addr+0x4],data[bit8=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x4, 0x0, 0xFFFFFEFF );
    /*Addr[serdes3_base_addr+0x81c+0x80*0~3],data[bit7-6=2b10,bit5-3=3b00]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x81c + 0x80 * ulLoop, 0x80, 0xFFFFFF87 );
    }
    /*Addr[serdes3_base_addr+0x82c+0x80*0~3],data[bit7-6=2b10,bit5-3=3b00]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x82c + 0x80 * ulLoop, 0x80, 0xFFFFFF87 );
    }
    /*Addr[serdes3_base_addr+0x100],data[bit12-8=5'h2,bit23-16=8'd50]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x100, 0x320200, 0xFF32E2FF );
    /*Addr[serdes3_base_addr+0x108],data[bit31-24=8'h6]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x108, 0x6000000, 0x6ffffff );

    osSerdesWait( 0x1000 );
    /*Addr[sysctrl_base_addr+0x594],data[bit24=1, bit23-8= all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1000000, 0xFF0000FF );
    osSerdesWait( 0x1000 );
    /*Addr[ioctrl1_base_addr+0x434],data[bit4=1, means pll is locked]*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    while ( 0x10 != ( ulValue & 0x10 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "osSerdes0WaitForPllCfg error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    osSerdesWait( 0x100 );
    /*Addr[sysctrl_base_addr+0x594],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1FFFF00, 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=1,bit4=1]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x11, 0xFFFFFFFF );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x80000, 0xFFFFFFFF );

    /*Addr[serdes3_base_addr+0x0],data[bit29=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x0, 0x20000000, 0xFFFFFFFF );

    osSerdesWait( 0x1000 );

    return OS_SUCCESS;
}

/*****************************************************************
函数名 :  osSerdes3InitPcie2g5
输入参数    :   None
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes3InitPcie2g5(void)
{
    UINT32 ulValue = 0;
    UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    /*Addr[sysctrl_base_addr+0x590],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x590, 0x1FFFF00 , 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=0,bit4=0]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x0 , 0xFFFFFFEE );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x590, 0x0 , 0xFFF7FFFF );
    osSerdesWait( 0x100 );

    /*Addr[serdes3_base_addr+0x4],data[bit8=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x4, 0x100, 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x81c+0x80*0~3],data[bit7-6=2b00,bit5-3=3b01]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x81C + 0x80 * ulLoop, 0x8 , 0xFFFFFF0F );
    }
    /*Addr[serdes3_base_addr+0x82c+0x80*0~3],data[bit7-6=2b00,bit5-3=3b01]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x82C + 0x80 * ulLoop, 0x8 , 0xFFFFFF0F );
    }
    osSerdesWait( 0x100 );

    /*Addr[sysctrl_base_addr+0x594],data[bit24=1, bit23-8= all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1000000, 0xFF0000FF );
    osSerdesWait( 0x1000 );

    /*Addr[ioctrl1_base_addr+0x434],data[bit4=1, means pll is locked]*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    while ( 0x10 != ( ulValue & 0x10 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "osSerdes0WaitForPllCfg error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    osSerdesWait( 0x100 );

    /*Addr[sysctrl_base_addr+0x594],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1FFFF00, 0xFFFFFFFF );

    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=1,bit4=1]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x11 , 0xFFFFFFFF );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x80000 , 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x0],data[bit29=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x0, 0x20000000 , 0xFFFFFFFF );

    osSerdesWait( 0x1000 );

    return OS_SUCCESS;
}

/*****************************************************************
函数名 :  osSerdes3InitPcie5g
输入参数    :   None
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes3InitPcie5g(void)
{
    UINT32 ulValue = 0;
    UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    /*Addr[sysctrl_base_addr+0x590],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x590, 0x1FFFF00 , 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=0,bit4=0]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x0 , 0xFFFFFFEE );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x0 , 0xFFF7FFFF );

    osSerdesWait( 0x10000000 );

    /*Addr[serdes3_base_addr+0x4],data[bit8=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x4, 0x100, 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x81c+0x80*0~3],data[bit7-6=2b00,bit5-3=3b01]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x81C + 0x80 * ulLoop, 0x8 , 0xFFFFFF0F );
    }
    /*Addr[serdes3_base_addr+0x82c+0x80*0~3],data[bit7-6=2b00,bit5-3=3b01]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x82C + 0x80 * ulLoop, 0x8 , 0xFFFFFF0F );
    }
    osSerdesWait( 0x10000000 );

    /*Addr[sysctrl_base_addr+0x594],data[bit24=1, bit23-8= all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1000000, 0xFF0000FF );
    osSerdesWait( 0x10000000 );

    /*Addr[ioctrl1_base_addr+0x434],data[bit4=1, means pll is locked]*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    while ( 0x10 != ( ulValue & 0x10 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "osSerdes0WaitForPllCfg error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    osSerdesWait( 0x10000000 );

    /*Addr[sysctrl_base_addr+0x594],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1FFFF00, 0xFFFFFFFF );

    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=1,bit4=1]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x11 , 0xFFFFFFFF );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x80000 , 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x0],data[bit29=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x0, 0x20000000 , 0xFFFFFFFF );

    osSerdesWait( 0x10000000 );

    return OS_SUCCESS;
}


/*****************************************************************
函数名 :  osSerdes3InitPcieS2g5
输入参数    :   None
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes3InitPcieS2g5(void)
{
    UINT32 ulValue = 0;
    UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    /*Addr[sysctrl_base_addr+0x590],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x590, 0x1FFFF00 , 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=0,bit4=0]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x0 , 0xFFFFFFEE );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x590, 0x0 , 0xFFF7FFFF );
    osSerdesWait( 0x100 );

    /*Addr[serdes3_base_addr+0x4],data[bit8=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x4, 0x100, 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x81c+0x80*0~3],data[bit7-6=2b00,bit5-3=3b01]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x81C + 0x80 * ulLoop, 0x8 , 0xFFFFFF17 );
    }
    /*Addr[serdes3_base_addr+0x82c+0x80*0~3],data[bit7-6=2b00,bit5-3=3b01]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x82C + 0x80 * ulLoop, 0x8 , 0xFFFFFF17 );
    }
    osSerdesWait( 0x100 );

    /*Addr[sysctrl_base_addr+0x594],data[bit24=1, bit23-8= all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1000000, 0xFF0000FF );
    osSerdesWait( 0x1000 );

    /*Addr[ioctrl1_base_addr+0x434],data[bit4=1, means pll is locked]*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    while ( 0x10 != ( ulValue & 0x10 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "osSerdes0WaitForPllCfg error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    osSerdesWait( 0x100 );

    /*Addr[sysctrl_base_addr+0x594],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1FFFF00, 0xFFFFFFFF );

    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=1,bit4=1]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x11 , 0xFFFFFFFF );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x80000 , 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x0],data[bit29=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x0, 0x20000000 , 0xFFFFFFFF );

    osSerdesWait( 0x1000 );

    return OS_SUCCESS;
}

/*****************************************************************
函数名 :  osSerdes3InitPcieS5g
输入参数    :   None
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes3InitPcieS5g(void)
{
    UINT32 ulValue = 0;
    UINT32 ulLoop = 0;
    INT32 ulWaitTime = SERDES_WART_TIME;
    //UINT32 ulRet = OS_SUCCESS;

    /*Addr[sysctrl_base_addr+0x590],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x590, 0x1FFFF00 , 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=0,bit4=0]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x0 , 0xFFFFFFEE );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x590, 0x0 , 0xFFF7FFFF );
    osSerdesWait( 0x100 );

    /*Addr[serdes3_base_addr+0x4],data[bit8=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x4, 0x100, 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x81c+0x80*0~3],data[bit7-6=2b00,bit5-3=3b00]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x81C + 0x80 * ulLoop, 0x0 , 0xFFFFFF07 );
    }
    /*Addr[serdes3_base_addr+0x82c+0x80*0~3],data[bit7-6=2b00,bit5-3=3b00]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x82C + 0x80 * ulLoop, 0x0 , 0xFFFFFF07 );
    }
    osSerdesWait( 0x100 );

    /*Addr[sysctrl_base_addr+0x594],data[bit24=1, bit23-8= all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1000000, 0xFF0000FF );
    osSerdesWait( 0x1000 );

    /*Addr[ioctrl1_base_addr+0x434],data[bit4=1, means pll is locked]*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    while ( 0x10 != ( ulValue & 0x10 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "osSerdes0WaitForPllCfg error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    osSerdesWait( 0x100 );

    /*Addr[sysctrl_base_addr+0x594],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1FFFF00, 0xFFFFFFFF );

    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=1,bit4=1]*/
    for ( ulLoop = 0; ulLoop < 3; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x11 , 0xFFFFFFFF );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x80000 , 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x0],data[bit29=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x0, 0x20000000 , 0xFFFFFFFF );

    osSerdesWait( 0x1000 );

    return OS_SUCCESS;
}

/*****************************************************************
函数名 :  osSerdes0ComCfg
输入参数    :   None
输出参数      :
Description   :  serdes0 通用配置

Author        :  z00228490
Creation time :  2012/12/28
*****************************************************************/
UINT32 osSerdes0ComCfg(void)
{
    //UINT32 ulValue = 0;
    UINT32 ulLoop = 0;
    //INT32 ulWaitTime = SERDES_WART_TIME;

    /*1、等待芯片AXI总线复位*/
    /*2、复位CMU/EOM/DIG，以及相应TX/RX通道*/
    osSerdesWait(0x100000);
    /*Addr[sysctrl_base_addr+0x580],data[bit24-0=all 1]*/
    osSerdesBitWrite(SRE_SC_SERDES_RESET_REQ0_REG,0x1ffffff,0xffffffff);

    /*Addr[sysctrl_base_addr+0x590],data[bit7-0= all 1]*/
    osSerdesBitWrite(SRE_SC_SERDES_RESET_REQ2_REG,0x1ffffff,0xffffffff);

    /*3、置位chx_fifo_rst_n  chx_bist_rst_n  jtf_rst_n  imp_rst_n*/
    for ( ulLoop  = 0 ; ulLoop < 4 ; ulLoop++ )
    {
        /*Addr[serdes0_low_base_addr+0x838+0x80*0~3],data[bit0=0,bit4=0]*/
        osSerdesWrite( SERDES0_LOW_BASE_ADDR + 0x838 + 0x80 * ulLoop,0, 0xFFFFFFEE, 1 );
    }
    for ( ulLoop  = 0 ; ulLoop < 4 ; ulLoop++ )
    {
        /*Addr[serdes0_high_base_addr+0x838+0x80*0~3],data[bit0=0,bit4=0]*/
        osSerdesWrite( SERDES0_HIGHT_BASE_ADDR + 0x838 + 0x80 * ulLoop,0, 0xFFFFFFEE, 1 );
    }

    /*Addr[serdes0_low_base_addr+0x144],data[bit19=0]*/
    osSerdesWrite( SERDES0_LOW_BASE_ADDR + 0x144, 0, 0xFFF7FFFF, 1 );
    /*Addr[serdes0_hight_base_addr+0x144],data[bit19=0]*/
    osSerdesWrite( SERDES0_HIGHT_BASE_ADDR + 0x144, 0, 0xFFF7FFFF, 1 );

    /*Addr[serdes0_low_base_addr+0x0],data[bit29=0]*/
    osSerdesWrite( SERDES0_LOW_BASE_ADDR, 0, 0xDFFFFFFF, 1 );
    /*Addr[serdes0_high_base_addr+0x0],data[bit29=0]*/
    osSerdesWrite( SERDES0_HIGHT_BASE_ADDR, 0, 0xDFFFFFFF, 1 );

    /*4、等待100ns*/
    osSerdesWait( 0x100000 );

    return OS_SUCCESS;
}

/*****************************************************************
函数名 :  osSerdes0WaitForPllCfg
输入参数    :   None
输出参数      :
Description   :  serdes0 线速配置之后的通用配置
                    等待复位撤离信号

Author        :  z00228490
Creation time :  2012/12/28
*****************************************************************/
UINT32 osSerdes0WaitForPllCfg(void)
{
    UINT32 ulValue = 0;
    UINT32 ulLoop = 0;
    volatile INT32 ulWaitTime = SERDES_WART_TIME;
    /*撤离CMU复位*/
    /*Addr[sysctrl_base_addr+0x584],data[bit24=1,bit23-0= all 0]*/
    /*Addr[sysctrl_base_addr+0x594],data[bit7-0= all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x584, 0x1ffffff, 0xFFffffff );
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1ffffff, 0xFFffffff );

    /*等待1ms*/
    osSerdesWait( 0x10000000);

    /*等待pll lock*/
    /*Addr[ioctrl0_base_addr+0x400],data[bit9-8=2’b11, means pll is locked]*/
    ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x400, 0 );
#if SERDES_DEBUG_OPEN
    SRE_printf( "check IOCTRL0_BASE_ADDR + 0x400 == 0x300\n" );

#else
    SRE_printf( "ulValue = %#x == 0x300\n",ulValue );
    while (-- ulWaitTime )
    {
        if(0x300 != ( ulValue & 0x300 ))
        {
            ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x400, 0 );
        }
        else
        {
            break;
        }
    }
    if ( ulWaitTime <= 0 )
    {
		SRE_printf( "ulValue = %#x == 0x300\n",ulValue );
        SRE_printf( "osSerdes0WaitForPllCfg error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }

#endif
    /*等待100ns*/
    osSerdesWait( 0x10000 );

    /*复位撤离，chx_fifo_rst_n  chx_bist_rst_n   jtf_rst_n  imp_rst_n*/
    /*Addr[serdes0_low_base_addr+0x838+0x80*0~3],data[bit0=1,bit4=1]*/
    /*Addr[serdes0_high_base_addr+0x838+0x80*0~3],data[bit0=1,bit4=1]*/
    /*Addr[serdes0_low_base_addr+0x144],data[bit19=1]*/
    /*Addr[serdes0_high_base_addr+0x144],data[bit19=1]*/
    /*Addr[serdes0_low_base_addr+0x0],data[bit29=1]*/
    /*Addr[serdes0_high_base_addr+0x0],data[bit29=1]*/
    for ( ulLoop = 0; ulLoop < 4; ulLoop ++ )
    {
        osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x11, 0xffffffff );
        osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x11, 0xffffffff );
    }
    osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x144, 0x80000, 0xffffffff );
    osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x144, 0x80000, 0xffffffff );
    osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x0, 0x20000000, 0xffffffff );
    osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x0, 0x20000000, 0xffffffff );

    /*等1ms 可以收发数据了*/
    osSerdesWait( 0x1000000 );

    return OS_SUCCESS;
}



/*****************************************************************
函数名 :  osSerdesWrite
输入参数    :  ulAddr   寄存器地址
              ulIndex   下标
              ulMask   掩码
              ulType   0 为与1为或
输出参数      :
Description   :  修改其中某几比特

Author        :  z00228490
Creation time :  2012/12/28
*****************************************************************/
UINT32 osSerdesWrite( UINT32 ulAddr, UINT32 ulIndex, UINT32 ulMask, UINT32 ulType )
{
    UINT32 ulValue = 0;

    ulValue = OS_READ_REG( ulAddr, ulIndex );

    if ( !ulType )
    {
        OS_SDS_WRITE_REG( ulAddr, ulIndex, ulValue | ulMask );
    }
    else
    {
        OS_SDS_WRITE_REG( ulAddr, ulIndex, ulValue & ulMask );
    }
    return OS_SUCCESS;
    /*回读*/
}

/*****************************************************************
函数名 :  osSerdesBitWrite
输入参数    :  ulAddr
              ulOrMask  置1掩码
              ulAndMask 置0掩码
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/28
*****************************************************************/
void osSerdesBitWrite( UINT32 ulAddr, UINT32 ulOrMask, UINT32 ulAndMask )
{
    UINT32 ulValue = 0;
    ulValue = OS_READ_REG( ulAddr, 0 );
    ulValue = ( ulValue | ulOrMask ) & ulAndMask;
    OS_SDS_WRITE_REG( ulAddr, 0, ulValue );
}


/*****************************************************************
函数名 :  osSerdesWait
输入参数    :  ulLoop
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/28
*****************************************************************/
void osSerdesWait( volatile UINT32 ulLoop )
{
    while ( ulLoop -- )
    {
        ;
    }
}

UINT32 SRE_SetSerdes0LowRdOn(UINT32 ulLaneMask)
{
    UINT32 ulValue = 0x0;
    for(ulValue = 0;ulValue < 0x4;ulValue ++)
    {
        if((0x1 << ulValue) & ulLaneMask)
        {
            OS_SDS_WRITE_REG(SERDES0_LOW_BASE_ADDR + 0x838 + 0x80 * ulValue, 0x0, 0x17);
        }
    }
    return OS_SUCCESS;
}

UINT32 SRE_SetSerdes0LowRdOff(UINT32 ulLaneMask)
{
    UINT32 ulValue = 0x0;
    for(ulValue = 0;ulValue < 0x4;ulValue ++)
    {
        if((0x1 << ulValue) & ulLaneMask)
        {
            OS_SDS_WRITE_REG(SERDES0_LOW_BASE_ADDR + 0x838 + 0x80 * ulValue, 0x0, 0x11);
        }
    }
    return OS_SUCCESS;
}

UINT32 SRE_SetSerdes0HighRdOn(UINT32 ulLaneMask)
{
    UINT32 ulValue = 0x0;
    for(ulValue = 0;ulValue < 0x4;ulValue ++)
    {
        if((0x1 << ulValue) & ulLaneMask)
        {
            OS_SDS_WRITE_REG(SERDES0_HIGHT_BASE_ADDR + 0x838 + 0x80 * ulValue, 0x0, 0x17);
        }
    }
    return OS_SUCCESS;
}

UINT32 SRE_SetSerdes0HighRdOff(UINT32 ulLaneMask)
{
    UINT32 ulValue = 0x0;
    for(ulValue = 0;ulValue < 0x4;ulValue ++)
    {
        if((0x1 << ulValue) & ulLaneMask)
        {
            OS_SDS_WRITE_REG(SERDES0_HIGHT_BASE_ADDR + 0x838 + 0x80 * ulValue, 0x0, 0x11);
        }
    }
    return OS_SUCCESS;
}
UINT32 SRE_SetSerdes1RdOn(void)
{
     //the initialization is finished
    //*********************************************************

// 21.  Enable LB
//LB_TX2RXBUFTIMEDEN.memcfg
//Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane) Value
//13[2:2]LB_SYNTHPLLFBCLK2CDRREFCLKEN   4   0
//13[1:1]LB_SYNTHCDRDIVCLK2TXEN     4   0
//7[1:1]    LB_CDRDIVCLK2EXTEN      7   0
//7[0:0]    LB_CDRCLK2TXEN          7   0
//7[5:5]    LB_TX2RXBUFTIMEDEN      7   0
//7[6:6]    LB_TX2RXIOTIMEDEN       7   1
//7[7:7]    LB_PARRX2TXTIMEDEN      7   0
//7[4:4]    LB_RX2TXUNTIMEDEN       7   0
//7[2:2]    LB_CDRDIVCLK2TXEN       7   0
//7[3:3]    LB_PLLFBCLK2CDRREFCLKEN     7   0
//85[1:1]   LB_LOCWREN      7   0
//osSerdes1Write (0x0,0x0,0x7,0x40);
//jaki suggestion
osSerdes1Write (0x0,0x0,0x7,0x20);
osSerdes1Write (0x0,0x0,0x55,0x4c);
osSerdes1Write (0x1,0x0,0x7,0x20);
osSerdes1Write (0x1,0x0,0x55,0x4c);
osSerdes1Write (0x2,0x0,0x7,0x20);
osSerdes1Write (0x2,0x0,0x55,0x4c);
osSerdes1Write (0x3,0x0,0x7,0x20);
osSerdes1Write (0x3,0x0,0x55,0x4c);
osSerdes1Write (0x4,0x0,0xd,0x10);

    return OS_SUCCESS;
}

UINT32 SRE_SetSerdes2RdOn(void)
{
     //the initialization is finished
    //*********************************************************

    // 21.  Enable LB
    //LB_TX2RXBUFTIMEDEN.memcfg
    //Address   RegisterName    LaneIdentifier(7:singleLane; 4: commonLane);    Value
    //13[2:2]LB_SYNTHPLLFBCLK2CDRREFCLKEN   4   0
    //13[1:1]LB_SYNTHCDRDIVCLK2TXEN     4   0
    //7[1:1]    LB_CDRDIVCLK2EXTEN      7   0
    //7[0:0]    LB_CDRCLK2TXEN          7   0
    //7[5:5]    LB_TX2RXBUFTIMEDEN      7   0
    //7[6:6]    LB_TX2RXIOTIMEDEN       7   1
    //7[7:7]    LB_PARRX2TXTIMEDEN      7   0
    //7[4:4]    LB_RX2TXUNTIMEDEN       7   0
    //7[2:2]    LB_CDRDIVCLK2TXEN       7   0
    //7[3:3]    LB_PLLFBCLK2CDRREFCLKEN     7   0
    //85[1:1]   LB_LOCWREN      7   0
    //osSerdes2Write (0x0,0x0,0x7,0x40);
    //jaki suggestion
    osSerdes2Write (0x0,0x0,0x7,0x20);
    osSerdes2Write (0x0,0x0,0x55,0x4c);
    osSerdes2Write (0x1,0x0,0x7,0x20);
    osSerdes2Write (0x1,0x0,0x55,0x4c);
    osSerdes2Write (0x2,0x0,0x7,0x20);
    osSerdes2Write (0x2,0x0,0x55,0x4c);
    osSerdes2Write (0x3,0x0,0x7,0x20);
    osSerdes2Write (0x3,0x0,0x55,0x4c);
    osSerdes2Write (0x4,0x0,0xd,0x10);

    return OS_SUCCESS;
}

/*===================封装的debug 函数接口函数=============*/

#define SERDES1   (0x1)
#define SERDES2    (0x2)
UINT32 osSerdesVsemiTxDriverWrite(
                                        UINT32 ulSdsx,
                                        UINT32 ulLanex,
                                        UINT32 ulHlev,
                                        UINT32 ulLevn,
                                        UINT32 levnm1,
                                        UINT32 levnm2,
                                        UINT32 levnp1,
                                        UINT32 slew
)
{
    UINT32 ulValue = 0;

    SRE_printf("VsemiTxDriverWrite:sdsx= %s,lanex=%d\n",
                    ulSdsx == SERDES1?"serdes1":"serdes2",ulLanex);
        /*如果sdsx=sds1, Macro1_rd(lanex,0x0,0x57),bit4=0回写*/
        /*如果sdsx=sds2, Macro2_rd(lanex,0x0,0x57),bit4=0回写*/
    if(ulSdsx == SERDES1)
    {
        ulValue = osSerdes1Read(ulLanex,0x0,0x57);
        osSerdes1Write(ulLanex,0,0x57,ulValue & 0xffffffef);
        /*macro1_rd(lanex,0x0,0x15);bit2-0=hlev,bit7-3=levn,回写*/
        /*macro1_rd(lanex,0x0,0x16);bit3-0=levnm1,bit5-4=levnm2,回写*/
        /*macro1_rd(lanex,0x0,0x17);bit2-0=levnp1,bit4-3=slew,回写*/
        ulValue = 0x0;//osSerdes1Read(ulLanex,0x0,0x15);
        ulValue = ( (ulHlev&0x7))  |
                    (((ulLevn & 0x1f)<<0x3));
        osSerdes1Write(ulLanex,0x0,0x15,ulValue);

        ulValue = 0x0;//osSerdes1Read(ulLanex,0x0,0x16);
        ulValue = ( (levnm1&0xF))  |
                    ( ((levnm2 & 0x3)<<0x4));
        osSerdes1Write(ulLanex,0x0,0x16,ulValue);

        ulValue = 0x0;//osSerdes1Read(ulLanex,0x0,0x17);
        ulValue = ( (levnp1&0x7))  |
                    ( ((slew & 0x3)<<0x3));
        osSerdes1Write(ulLanex,0x0,0x17,ulValue);


    }
    else
    {
        ulValue = osSerdes2Read(ulLanex,0x0,0x57);
        osSerdes2Write(ulLanex,0,0x57,ulValue & 0xffffffef);

        ulValue = osSerdes2Read(ulLanex,0x0,0x57);
        osSerdes2Write(ulLanex,0,0x57,ulValue & 0xffffffef);
        /*macro1_rd(lanex,0x0,0x15);bit2-0=hlev,bit7-3=levn,回写*/
        /*macro1_rd(lanex,0x0,0x16);bit3-0=levnm1,bit5-4=levnm2,回写*/
        /*macro1_rd(lanex,0x0,0x17);bit2-0=levnp1,bit4-3=slew,回写*/
        ulValue = 0x0;//osSerdes2Read(ulLanex,0x0,0x15);
        ulValue = ( (ulHlev&0x7))  |
                    (((ulLevn & 0x1f)<<0x3));
        osSerdes2Write(ulLanex,0x0,0x15,ulValue);

        ulValue = 0x0;//osSerdes2Read(ulLanex,0x0,0x16);
        ulValue = ( (levnm1&0xF))  |
                    ( ((levnm2 & 0x3)<<0x4));
        osSerdes2Write(ulLanex,0x0,0x16,ulValue);

        ulValue = 0x0;//osSerdes2Read(ulLanex,0x0,0x17);
        ulValue = ( (levnp1&0x7))  |
                    ( ((slew & 0x3)<<0x3));
        osSerdes2Write(ulLanex,0x0,0x17,ulValue);
    }

    return OS_SUCCESS;
}


UINT32 osSerdesVsemiTxDriverRead(UINT32 sdsx,UINT32 lanex)
{
    UINT32 ulValue = 0;
    SRE_printf("VsemiTxDriverRead:sdsx= %s,lanex=%d\n",
                    sdsx == SERDES1?"serdes1":"serdes2",lanex);
    if(sdsx == SERDES1)
    {
        ulValue = osSerdes1Read(lanex,0x0,0x57);
        osSerdes1Write(lanex,0,0x57,ulValue & 0xffffffef);

        /*macro1_rd(lanex,0x0,0x15); hlev= bit2-0, levn= bit7-3*/
        /*macro1_rd(lanex,0x0,0x16); levnm1=bit3-0, levnm2= bit5-4*/
        /*macro1_rd(lanex,0x0,0x17); levnp1=bit2-0, slew=bit4-3*/
        ulValue = osSerdes1Read(lanex,0x0,0x15);
        SRE_printf("ulValue = 0x%08x,hlev = 0x%08x,levn = 0x%08x\n",ulValue,ulValue & 0x7,(ulValue &0xF8) >> 0x3 );
        ulValue = osSerdes1Read(lanex,0x0,0x16);
        SRE_printf("ulValue = 0x%08x,levnm1 = 0x%08x,levnm2 = 0x%08x\n",ulValue,ulValue & 0xf,(ulValue &0x30) >> 0x4 );
        ulValue = osSerdes1Read(lanex,0x0,0x17);
        SRE_printf("ulValue = 0x%08x,levnp1 = 0x%08x,slew = 0x%08x\n",ulValue,ulValue & 0x7,(ulValue &0x18) >> 0x3 );


    }
    else
    {
        ulValue = osSerdes2Read(lanex,0x0,0x57);
        osSerdes2Write(lanex,0,0x57,ulValue & 0xffffffef);

        /*macro1_rd(lanex,0x0,0x15); hlev= bit2-0, levn= bit7-3*/
        /*macro1_rd(lanex,0x0,0x16); levnm1=bit3-0, levnm2= bit5-4*/
        /*macro1_rd(lanex,0x0,0x17); levnp1=bit2-0, slew=bit4-3*/
        ulValue = osSerdes2Read(lanex,0x0,0x15);
        SRE_printf("ulValue = 0x%08x,hlev = 0x%08x,levn = 0x%08x\n",ulValue,ulValue & 0x7,(ulValue &0xF8) >> 0x3 );
        ulValue = osSerdes2Read(lanex,0x0,0x16);
        SRE_printf("ulValue = 0x%08x,levnm1 = 0x%08x,levnm2 = 0x%08x\n",ulValue,ulValue & 0xf,(ulValue &0x30) >> 0x4 );
        ulValue = osSerdes2Read(lanex,0x0,0x17);
        SRE_printf("ulValue = 0x%08x,levnp1 = 0x%08x,slew = 0x%08x\n",ulValue,ulValue & 0x7,(ulValue &0x18) >> 0x3 );

    }

     return OS_SUCCESS;
}

UINT32 osSerdes1PmaBistOnNormal(UINT32 ulLane,UINT32 ulPrbsPatten,UINT32 LpMode)
{
    //UINT32 ulRet = OS_SUCCESS;
    UINT32 ulData = 0;
    INT32 ulWaitTime = 1000000;
    /*配置prbs pattern和 on-chip loopback*/
    /*Macro1_rd(3'h4,1'h0,12'h5f,data[7:0]);data[4:4]=0,回写*/
    ulData = osSerdes1Read(0x4,0x0,0x5f);
    ulData &= 0xffffffef;
    osSerdes1Write(0x4,0x0,0x5f,ulData);

    /*Macro1_rd(3'h4,1'h0,12'h50,data[7:0]);data[2:0]=x2[2:0]*/
    ulData = osSerdes1Read(0x4,0x0,0x50);
    ulData = (ulData & 0xfffffff8 ) | ulPrbsPatten;
    osSerdes1Write(0x4,0x0,0x5f,ulData);

    /*Macro1_rd(x1[2:0],1'h0,12'h55,data[7:0]);data[1:1]=0,回写*/
    ulData = osSerdes1Read(ulLane & 0x7,0x0,0x55);
    ulData = (ulData & 0xfffffffd );
    osSerdes1Write(ulLane & 0x7,0x0,0x55,ulData);

    /*环回*/
    osSerdes1PmaLp(ulLane, LpMode);

    /*Enable p0 state*/
    /*Macro1_rd(x1[2:0],1'h0,12'h55,data[7:0]);data[0:0]=0,回写*/
    ulData = osSerdes1Read(ulLane & 0x7,0x0,0x55);
    ulData &= 0xFFFFFFFE;
    osSerdes1Write(ulLane & 0x7,0x0,0x55,ulData);

    /*Macro1_rd(x1[2:0],1'h0,12'h3,data[7:0]);data[4:0]=5'b10000,回写*/
    ulData = osSerdes1Read(ulLane & 0x7,0x0,0x3);
    ulData = (ulData | 0x10)  & 0xFFFFFFF0;
    osSerdes1Write(ulLane & 0x7,0x0,0x3,ulData);

    /*Macro1_rd(x1[2:0],1'h0,12'h4,data[7:0]);data[4:0]=5'b10000,回写*/
    ulData = osSerdes1Read(ulLane & 0x7,0x0,0x4);
    ulData = (ulData | 0x10)  & 0xFFFFFFF0;
    osSerdes1Write(ulLane & 0x7,0x0,0x4,ulData);

    /*3.开启PMA BIST*/
    /*macro1_rd(x1[2:0],1'h0,12'h56,data[7:0])，data[0:0]=0,回写*/
    ulData = osSerdes1Read(ulLane & 0x7,0x0,0x56);
    ulData = (ulData )  & 0xFFFFFFFE;
    osSerdes1Write(ulLane & 0x7,0x0,0x56,ulData);

    /*macro1_rd(x1[2:0],1'h0,12'h8,data[7:0]);data[1:1]=1'b1; 回写*/
    ulData = osSerdes1Read(ulLane & 0x7,0x0,0x8);
    ulData = (ulData )  | 0x2;
    osSerdes1Write(ulLane & 0x7,0x0,0x8,ulData);

    /*等待CDR锁定 register-based*/
    /*macro1_rd(x1[2:0], 1'h0,12'h28,data[7:0]);data[5:5]=1'b1;data[6:6] =1'b0;回写*/
    ulData = osSerdes1Read(ulLane & 0x7,0x0,0x28);
    ulData = (ulData  | 0x20 ) & 0xFFFFFFBF;
    osSerdes1Write(ulLane & 0x7,0x0,0x28,ulData);

    /*等待macro1_rd(x1[2:0], 1'h0,12'hB,data[7:0]);直到data[5:5]==1*/
    ulData = osSerdes1Read(ulLane & 0x7,0x0,0xB);
    while(0x20 != (ulData & 0x20) && ulWaitTime -- )
    {
        ulData = osSerdes1Read(ulLane & 0x7,0x0,0xB);
    }
    if(ulWaitTime <= 0)
    {
        SRE_printf("cdr didn't lock at LINE[%d]\n",__LINE__);
        return OS_FAIL;
    }

    /*开始PMA BIST receiver检查*/
    /*macro1_rd(x1[2:0],1'h0,12'h55,data[7:0]);data[5:5]=0;回写*/
    ulData = osSerdes1Read(ulLane & 0x7,0x0,0x55);
    ulData = (ulData  ) & 0xFFFFFFDF;
    osSerdes1Write(ulLane & 0x7,0x0,0x55,ulData);

    /*macro1_rd(x1[2:0],1'h0,12'h8,data[7:0]);data[1:1]=1'b1;回写*/
    ulData = osSerdes1Read(ulLane & 0x7,0x0,0x8);
    ulData = (ulData  | 0x2);
    osSerdes1Write(ulLane & 0x7,0x0,0x8,ulData);

    /*等待symbol lock*/
    /*一直进行macro1_rd(x1[2:0],1'h0,12'h8,data[7:0]);直到data[4:4]=1'b1;*/
    ulData = osSerdes1Read(ulLane & 0x7,0x0,0x8);
    ulWaitTime = 1000000;
    while(0x10 != (ulData & 0x10) && ulWaitTime --)
    {
        ulData = osSerdes1Read(ulLane & 0x7,0x0,0x8);
    }
    if(ulWaitTime <= 0)
    {
        SRE_printf("symbol lock over time at line[%d]\n",__LINE__);
        return OS_FAIL;
    }

    return OS_SUCCESS;
}


UINT32 osSerdes1PmaBistOnReset(UINT32 ulLane,UINT32 ulPrbsPatten,UINT32 ulLpMode)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = 50000000;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit9-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0x3FF, 0xFFFFFFFF );

    /*3、设置模式为multi-mode*/
    /*Addr[ioctrl0_base_addr+0x60],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x60, 0x0, 0xFFFFF7FF );

    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x200, 0xFFFFFE00 );

    /*等待500ns*/
    osSerdesWait( 500 );

    /*加载1.25Gbps_156.25MHz_VSM.txt配置文件*/
    osSerdes1Write( 0x0, 0x0, 0x65, 0xb7 );
    osSerdes1Write( 0x0, 0x0, 0x66, 0xb7 );
    osSerdes1Write( 0x0, 0x0, 0x67, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x68, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x69, 0x1a );
    osSerdes1Write( 0x0, 0x0, 0x6a, 0x1a );
    osSerdes1Write( 0x0, 0x0, 0x6b, 0x2 );
    osSerdes1Write( 0x0, 0x0, 0x6c, 0x2 );
    osSerdes1Write( 0x0, 0x0, 0x6d, 0x11 );
    osSerdes1Write( 0x0, 0x0, 0x6e, 0xd );
    osSerdes1Write( 0x1, 0x0, 0x65, 0xb7 );
    osSerdes1Write( 0x1, 0x0, 0x66, 0xb7 );
    osSerdes1Write( 0x1, 0x0, 0x67, 0xc );
    osSerdes1Write( 0x1, 0x0, 0x68, 0xc );
    osSerdes1Write( 0x1, 0x0, 0x69, 0x1a );
    osSerdes1Write( 0x1, 0x0, 0x6a, 0x1a );
    osSerdes1Write( 0x1, 0x0, 0x6b, 0x2 );
    osSerdes1Write( 0x1, 0x0, 0x6c, 0x2 );
    osSerdes1Write( 0x1, 0x0, 0x6d, 0x11 );
    osSerdes1Write( 0x1, 0x0, 0x6e, 0xd );
    osSerdes1Write( 0x2, 0x0, 0x65, 0xb7 );
    osSerdes1Write( 0x2, 0x0, 0x66, 0xb7 );
    osSerdes1Write( 0x2, 0x0, 0x67, 0xc );
    osSerdes1Write( 0x2, 0x0, 0x68, 0xc );
    osSerdes1Write( 0x2, 0x0, 0x69, 0x1a );
    osSerdes1Write( 0x2, 0x0, 0x6a, 0x1a );
    osSerdes1Write( 0x2, 0x0, 0x6b, 0x2 );
    osSerdes1Write( 0x2, 0x0, 0x6c, 0x2 );
    osSerdes1Write( 0x2, 0x0, 0x6d, 0x11 );
    osSerdes1Write( 0x2, 0x0, 0x6e, 0xd );
    osSerdes1Write( 0x3, 0x0, 0x65, 0xb7 );
    osSerdes1Write( 0x3, 0x0, 0x66, 0xb7 );
    osSerdes1Write( 0x3, 0x0, 0x67, 0xc );
    osSerdes1Write( 0x3, 0x0, 0x68, 0xc );
    osSerdes1Write( 0x3, 0x0, 0x69, 0x1a );
    osSerdes1Write( 0x3, 0x0, 0x6a, 0x1a );
    osSerdes1Write( 0x3, 0x0, 0x6b, 0x2 );
    osSerdes1Write( 0x3, 0x0, 0x6c, 0x2 );
    osSerdes1Write( 0x3, 0x0, 0x6d, 0x11 );
    osSerdes1Write( 0x3, 0x0, 0x6e, 0xd );
    osSerdes1Write( 0x4, 0x0, 0x65, 0x99 );
    osSerdes1Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x67, 0x6c );
    osSerdes1Write( 0x4, 0x0, 0x68, 0xb7 );
    osSerdes1Write( 0x4, 0x0, 0x69, 0xb7 );
    osSerdes1Write( 0x4, 0x0, 0x6a, 0xc );
    osSerdes1Write( 0x4, 0x0, 0x6b, 0xc );
    osSerdes1Write( 0x4, 0x0, 0x6c, 0x1a );
    osSerdes1Write( 0x4, 0x0, 0x6d, 0x1a );
    osSerdes1Write( 0x4, 0x0, 0x6e, 0x7 );
    osSerdes1Write( 0x4, 0x0, 0x6f, 0xc );
    osSerdes1Write( 0x4, 0x0, 0x70, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x72, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x75, 0xb3 );
    osSerdes1Write( 0x4, 0x0, 0x76, 0xf6 );
    osSerdes1Write( 0x4, 0x0, 0x77, 0xd0 );
    osSerdes1Write( 0x4, 0x0, 0x78, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x79, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x7a, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x7f, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x80, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x81, 0xe2 );
    osSerdes1Write( 0x4, 0x0, 0x82, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x83, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x84, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x85, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x86, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x89, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x8a, 0xd3 );
    osSerdes1Write( 0x4, 0x0, 0x8b, 0xe2 );
    osSerdes1Write( 0x4, 0x0, 0x8c, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x8d, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x8e, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x8f, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x90, 0xef );
    osSerdes1Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x93, 0xfb );
    osSerdes1Write( 0x4, 0x0, 0x94, 0xff );
    osSerdes1Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes1Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x97, 0x64 );
    osSerdes1Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x99, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0x9a, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes1Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes1Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes1Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes1Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes1Write( 0x4, 0x0, 0x37, 0xb4 );
    osSerdes1Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes1Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes1Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes1Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes1Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes1Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes1Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes1Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes1Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes1Write( 0x3, 0x0, 0x2bd, 0x0 );
    /*配置并行数据接口的数据位宽和速率*/
    /*Addr[ioctrl0_base_addr+0x64],data[bit31-29=3'b001,*/
    /*bit28-26=3'b001,bit25-23=3'b001,bit22-20=3b001,bit19-17=3b001,*/
    /*bit16-14=3b001,bit13-11=3b001,bit10-8=3b001,bit7-0=all 1]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x64, 0x249249FF, 0x249249FF );

    /*addr[ioctrl0_base_addr+0x68],data[bit31-24=all0,*/
    /*bit23-21=3'b001,bit20-18=3'b001,bit17-15=3'b001,bit14-12=3'b001,*/
    /*bit11-9=3'b001,bit8-6=3'b001,bit5-3=3'b001,bit2-0=3'b001]*/
    osSerdesBitWrite( IOCTRL0_BASE_ADDR + 0x68, 0x249249, 0x249249 );

    /*配置prbs pattern和 on-chip loopback*/
    /*Macro1_rd(3'h4,1'h0,12'h5f,data[7:0]);data[4:4]=0,回写*/
    ulValue = osSerdes1Read(0x4,0x0,0x5f);
    ulValue &= 0xffffffef;
    osSerdes1Write(0x4,0x0,0x5f,ulValue);

    /*Macro1_rd(3'h4,1'h0,12'h50,data[7:0]);data[2:0]=x2[2:0]*/
    ulValue = osSerdes1Read(0x4,0x0,0x50);
    ulValue = (ulValue & 0xfffffff8 ) | ulPrbsPatten;
    osSerdes1Write(0x4,0x0,0x5f,ulValue);

    /*Macro1_rd(x1[2:0],1'h0,12'h55,data[7:0]);data[1:1]=0,回写*/
    ulValue = osSerdes1Read(ulLane & 0x7,0x0,0x55);
    ulValue = (ulValue & 0xfffffffd );
    osSerdes1Write(ulLane & 0x7,0x0,0x55,ulValue);

    /*环回*/
    osSerdes1PmaLp(ulLane, ulLpMode);


    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x3ff, 0xffffffff );

   /*Enable p0 state*/
    /*Macro1_rd(x1[2:0],1'h0,12'h55,data[7:0]);data[0:0]=0,回写*/
    ulValue = osSerdes1Read(ulLane & 0x7,0x0,0x55);
    ulValue &= 0xFFFFFFFE;
    osSerdes1Write(ulLane & 0x7,0x0,0x55,ulValue);

    /*Macro1_rd(x1[2:0],1'h0,12'h3,data[7:0]);data[4:0]=5'b10000,回写*/
    ulValue = osSerdes1Read(ulLane & 0x7,0x0,0x3);
    ulValue = (ulValue | 0x10)  & 0xFFFFFFF0;
    osSerdes1Write(ulLane & 0x7,0x0,0x3,ulValue);

    /*Macro1_rd(x1[2:0],1'h0,12'h4,data[7:0]);data[4:0]=5'b10000,回写*/
    ulValue = osSerdes1Read(ulLane & 0x7,0x0,0x4);
    ulValue = (ulValue | 0x10)  & 0xFFFFFFF0;
    osSerdes1Write(ulLane & 0x7,0x0,0x4,ulValue);


    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl0_base_addr+0x404],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
#if SERDES_DEBUG_OPEN
    SRE_printf( "check IOCTRL0_BASE_ADDR + 0x404 == 0xff0\n" );
#else
    ulValue = ulValue & 0xFF0;
    while (  ulWaitTime -- )
    {
        if( ulValue != 0xFF0 )
        {
            ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x404, 0 );
            ulValue = ulValue & 0xFF0;
        }
        else
        {
            break;
        }
    }
#endif
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }

    /*3.开启PMA BIST*/
    /*macro1_rd(x1[2:0],1'h0,12'h56,data[7:0])，data[0:0]=0,回写*/
    ulValue = osSerdes1Read(ulLane & 0x7,0x0,0x56);
    ulValue = (ulValue )  & 0xFFFFFFFE;
    osSerdes1Write(ulLane & 0x7,0x0,0x56,ulValue);

    /*macro1_rd(x1[2:0],1'h0,12'h8,data[7:0]);data[1:1]=1'b1; 回写*/
    ulValue = osSerdes1Read(ulLane & 0x7,0x0,0x8);
    ulValue = (ulValue )  | 0x2;
    osSerdes1Write(ulLane & 0x7,0x0,0x8,ulValue);

    /*等待CDR锁定 register-based*/
    /*macro1_rd(x1[2:0], 1'h0,12'h28,data[7:0]);data[5:5]=1'b1;data[6:6] =1'b0;回写*/
    ulValue = osSerdes1Read(ulLane & 0x7,0x0,0x28);
    ulValue = (ulValue  | 0x20 ) & 0xFFFFFFBF;
    osSerdes1Write(ulLane & 0x7,0x0,0x28,ulValue);

    /*等待macro1_rd(x1[2:0], 1'h0,12'hB,data[7:0]);直到data[5:5]==1*/
    ulValue = osSerdes1Read(ulLane & 0x7,0x0,0xB);
    while(0x20 != (ulValue & 0x20) && ulWaitTime -- )
    {
        ulValue = osSerdes1Read(ulLane & 0x7,0x0,0xB);
    }
    if(ulWaitTime <= 0)
    {
        SRE_printf("cdr didn't lock at LINE[%d]\n",__LINE__);
        return OS_FAIL;
    }

    /*开始PMA BIST receiver检查*/
    /*macro1_rd(x1[2:0],1'h0,12'h55,data[7:0]);data[5:5]=0;回写*/
    ulValue = osSerdes1Read(ulLane & 0x7,0x0,0x55);
    ulValue = (ulValue  ) & 0xFFFFFFDF;
    osSerdes1Write(ulLane & 0x7,0x0,0x55,ulValue);

    /*macro1_rd(x1[2:0],1'h0,12'h8,data[7:0]);data[1:1]=1'b1;回写*/
    ulValue = osSerdes1Read(ulLane & 0x7,0x0,0x8);
    ulValue = (ulValue  | 0x2);
    osSerdes1Write(ulLane & 0x7,0x0,0x8,ulValue);

    /*等待symbol lock*/
    /*一直进行macro1_rd(x1[2:0],1'h0,12'h8,data[7:0]);直到data[4:4]=1'b1;*/
    ulValue = osSerdes1Read(ulLane & 0x7,0x0,0x8);
    ulWaitTime = 1000000;
    while(0x10 != (ulValue & 0x10) && ulWaitTime --)
    {
        ulValue = osSerdes1Read(ulLane & 0x7,0x0,0x8);
    }
    if(ulWaitTime <= 0)
    {
        SRE_printf("symbol lock over time at line[%d]\n",__LINE__);
        return OS_FAIL;
    }
    return OS_SUCCESS;
}


UINT32 osSerdes2PmaBistOnNormal(UINT32 ulLane,UINT32 ulPrbsPatten,UINT32 LpMode)
{
    //UINT32 ulRet = OS_SUCCESS;
    UINT32 ulData = 0;
    INT32 ulWaitTime = 1000000;
    /*配置prbs pattern和 on-chip loopback*/
    /*Macro2_rd(3'h4,1'h0,12'h5f,data[7:0]);data[4:4]=0,回写*/
    ulData = osSerdes2Read(0x4,0x0,0x5f);
    ulData &= 0xffffffef;
    osSerdes2Write(0x4,0x0,0x5f,ulData);

    /*Macro2_rd(3'h4,1'h0,12'h50,data[7:0]);data[2:0]=x2[2:0]*/
    ulData = osSerdes2Read(0x4,0x0,0x50);
    ulData = (ulData & 0xfffffff8 ) | ulPrbsPatten;
    osSerdes2Write(0x4,0x0,0x5f,ulData);

    /*Macro2_rd(x1[2:0],1'h0,12'h55,data[7:0]);data[1:1]=0,回写*/
    ulData = osSerdes2Read(ulLane & 0x7,0x0,0x55);
    ulData = (ulData & 0xfffffffd );
    osSerdes2Write(ulLane & 0x7,0x0,0x55,ulData);

    /*环回*/
    osSerdes2PmaLp(ulLane, LpMode);

    /*Enable p0 state*/
    /*Macro2_rd(x1[2:0],1'h0,12'h55,data[7:0]);data[0:0]=0,回写*/
    ulData = osSerdes2Read(ulLane & 0x7,0x0,0x55);
    ulData &= 0xFFFFFFFE;
    osSerdes2Write(ulLane & 0x7,0x0,0x55,ulData);

    /*Macro2_rd(x1[2:0],1'h0,12'h3,data[7:0]);data[4:0]=5'b10000,回写*/
    ulData = osSerdes2Read(ulLane & 0x7,0x0,0x3);
    ulData = (ulData | 0x10)  & 0xFFFFFFF0;
    osSerdes2Write(ulLane & 0x7,0x0,0x3,ulData);

    /*Macro2_rd(x1[2:0],1'h0,12'h4,data[7:0]);data[4:0]=5'b10000,回写*/
    ulData = osSerdes2Read(ulLane & 0x7,0x0,0x4);
    ulData = (ulData | 0x10)  & 0xFFFFFFF0;
    osSerdes2Write(ulLane & 0x7,0x0,0x4,ulData);

    /*3.开启PMA BIST*/
    /*macro2_rd(x1[2:0],1'h0,12'h56,data[7:0])，data[0:0]=0,回写*/
    ulData = osSerdes2Read(ulLane & 0x7,0x0,0x56);
    ulData = (ulData )  & 0xFFFFFFFE;
    osSerdes2Write(ulLane & 0x7,0x0,0x56,ulData);

    /*macro2_rd(x1[2:0],1'h0,12'h8,data[7:0]);data[1:1]=1'b1; 回写*/
    ulData = osSerdes2Read(ulLane & 0x7,0x0,0x8);
    ulData = (ulData )  | 0x2;
    osSerdes2Write(ulLane & 0x7,0x0,0x8,ulData);

    /*等待CDR锁定 register-based*/
    /*macro2_rd(x1[2:0], 1'h0,12'h28,data[7:0]);data[5:5]=1'b1;data[6:6] =1'b0;回写*/
    ulData = osSerdes2Read(ulLane & 0x7,0x0,0x28);
    ulData = (ulData  | 0x20 ) & 0xFFFFFFBF;
    osSerdes2Write(ulLane & 0x7,0x0,0x28,ulData);

    /*等待macro2_rd(x1[2:0], 1'h0,12'hB,data[7:0]);直到data[5:5]==1*/
    ulData = osSerdes2Read(ulLane & 0x7,0x0,0xB);
    while(0x20 != (ulData & 0x20) && ulWaitTime -- )
    {
        ulData = osSerdes2Read(ulLane & 0x7,0x0,0xB);
    }
    if(ulWaitTime <= 0)
    {
        SRE_printf("cdr didn't lock at LINE[%d]\n",__LINE__);
        return OS_FAIL;
    }

    /*开始PMA BIST receiver检查*/
    /*macro2_rd(x1[2:0],1'h0,12'h55,data[7:0]);data[5:5]=0;回写*/
    ulData = osSerdes2Read(ulLane & 0x7,0x0,0x55);
    ulData = (ulData  ) & 0xFFFFFFDF;
    osSerdes2Write(ulLane & 0x7,0x0,0x55,ulData);

    /*macro2_rd(x1[2:0],1'h0,12'h8,data[7:0]);data[1:1]=1'b1;回写*/
    ulData = osSerdes2Read(ulLane & 0x7,0x0,0x8);
    ulData = (ulData  | 0x2);
    osSerdes2Write(ulLane & 0x7,0x0,0x8,ulData);

    /*等待symbol lock*/
    /*一直进行macro2_rd(x1[2:0],1'h0,12'h8,data[7:0]);直到data[4:4]=1'b1;*/
    ulData = osSerdes2Read(ulLane & 0x7,0x0,0x8);
    ulWaitTime = 1000000;
    while(0x10 != (ulData & 0x10) && ulWaitTime --)
    {
        ulData = osSerdes2Read(ulLane & 0x7,0x0,0x8);
    }
    if(ulWaitTime <= 0)
    {
        SRE_printf("symbol lock over time at line[%d]\n",__LINE__);
        return OS_FAIL;
    }

    return OS_SUCCESS;
}


UINT32 osSerdes2PmaBistOnReset(UINT32 ulLane,UINT32 ulPrbsPatten,UINT32 ulLpMode)
{
    UINT32 ulValue = 0;
    //UINT32 ulLoop = 0;
    INT32 ulWaitTime = 50000000;
    //UINT32 ulRet = OS_SUCCESS;
    /*1、等待芯片初始化完成，然后开始该serdes的初始化*/
    /*2.power on reset/Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x588],data[bit19-10=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x588, 0xFFC00, 0xFFFFFFFF );

    /*3、设置模式为multi-mode*/
    /*Addr[ioctrl1_base_addr+0xC],data[bit11=0]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0xC, 0x0, 0xFFFFF7FF );

    /*等待500ns*/
    osSerdesWait( 500 );

    /*撤离Power on reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit19=1,bit18-10=all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x80000, 0xFFF803FF );

    /*等待500ns*/
    osSerdesWait( 500 );

    /*加载1.25Gbps_156.25MHz_VSM.txt配置文件*/
    osSerdes2Write( 0x0, 0x0, 0x65, 0xb7 );
    osSerdes2Write( 0x0, 0x0, 0x66, 0xb7 );
    osSerdes2Write( 0x0, 0x0, 0x67, 0xc );
    osSerdes2Write( 0x0, 0x0, 0x68, 0xc );
    osSerdes2Write( 0x0, 0x0, 0x69, 0x1a );
    osSerdes2Write( 0x0, 0x0, 0x6a, 0x1a );
    osSerdes2Write( 0x0, 0x0, 0x6b, 0x2 );
    osSerdes2Write( 0x0, 0x0, 0x6c, 0x2 );
    osSerdes2Write( 0x0, 0x0, 0x6d, 0x11 );
    osSerdes2Write( 0x0, 0x0, 0x6e, 0xd );
    osSerdes2Write( 0x1, 0x0, 0x65, 0xb7 );
    osSerdes2Write( 0x1, 0x0, 0x66, 0xb7 );
    osSerdes2Write( 0x1, 0x0, 0x67, 0xc );
    osSerdes2Write( 0x1, 0x0, 0x68, 0xc );
    osSerdes2Write( 0x1, 0x0, 0x69, 0x1a );
    osSerdes2Write( 0x1, 0x0, 0x6a, 0x1a );
    osSerdes2Write( 0x1, 0x0, 0x6b, 0x2 );
    osSerdes2Write( 0x1, 0x0, 0x6c, 0x2 );
    osSerdes2Write( 0x1, 0x0, 0x6d, 0x11 );
    osSerdes2Write( 0x1, 0x0, 0x6e, 0xd );
    osSerdes2Write( 0x2, 0x0, 0x65, 0xb7 );
    osSerdes2Write( 0x2, 0x0, 0x66, 0xb7 );
    osSerdes2Write( 0x2, 0x0, 0x67, 0xc );
    osSerdes2Write( 0x2, 0x0, 0x68, 0xc );
    osSerdes2Write( 0x2, 0x0, 0x69, 0x1a );
    osSerdes2Write( 0x2, 0x0, 0x6a, 0x1a );
    osSerdes2Write( 0x2, 0x0, 0x6b, 0x2 );
    osSerdes2Write( 0x2, 0x0, 0x6c, 0x2 );
    osSerdes2Write( 0x2, 0x0, 0x6d, 0x11 );
    osSerdes2Write( 0x2, 0x0, 0x6e, 0xd );
    osSerdes2Write( 0x3, 0x0, 0x65, 0xb7 );
    osSerdes2Write( 0x3, 0x0, 0x66, 0xb7 );
    osSerdes2Write( 0x3, 0x0, 0x67, 0xc );
    osSerdes2Write( 0x3, 0x0, 0x68, 0xc );
    osSerdes2Write( 0x3, 0x0, 0x69, 0x1a );
    osSerdes2Write( 0x3, 0x0, 0x6a, 0x1a );
    osSerdes2Write( 0x3, 0x0, 0x6b, 0x2 );
    osSerdes2Write( 0x3, 0x0, 0x6c, 0x2 );
    osSerdes2Write( 0x3, 0x0, 0x6d, 0x11 );
    osSerdes2Write( 0x3, 0x0, 0x6e, 0xd );
    osSerdes2Write( 0x4, 0x0, 0x65, 0x99 );
    osSerdes2Write( 0x4, 0x0, 0x66, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x67, 0x6c );
    osSerdes2Write( 0x4, 0x0, 0x68, 0xb7 );
    osSerdes2Write( 0x4, 0x0, 0x69, 0xb7 );
    osSerdes2Write( 0x4, 0x0, 0x6a, 0xc );
    osSerdes2Write( 0x4, 0x0, 0x6b, 0xc );
    osSerdes2Write( 0x4, 0x0, 0x6c, 0x1a );
    osSerdes2Write( 0x4, 0x0, 0x6d, 0x1a );
    osSerdes2Write( 0x4, 0x0, 0x6e, 0x7 );
    osSerdes2Write( 0x4, 0x0, 0x6f, 0xc );
    osSerdes2Write( 0x4, 0x0, 0x70, 0x8 );
    osSerdes2Write( 0x4, 0x0, 0x71, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x72, 0x8 );
    osSerdes2Write( 0x4, 0x0, 0x73, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x74, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x75, 0xb3 );
    osSerdes2Write( 0x4, 0x0, 0x76, 0xf6 );
    osSerdes2Write( 0x4, 0x0, 0x77, 0xd0 );
    osSerdes2Write( 0x4, 0x0, 0x78, 0xef );
    osSerdes2Write( 0x4, 0x0, 0x79, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x7a, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7b, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7c, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7d, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7e, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x7f, 0xd3 );
    osSerdes2Write( 0x4, 0x0, 0x80, 0xd3 );
    osSerdes2Write( 0x4, 0x0, 0x81, 0xe2 );
    osSerdes2Write( 0x4, 0x0, 0x82, 0xef );
    osSerdes2Write( 0x4, 0x0, 0x83, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x84, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x85, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x86, 0xef );
    osSerdes2Write( 0x4, 0x0, 0x87, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x88, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x89, 0xd3 );
    osSerdes2Write( 0x4, 0x0, 0x8a, 0xd3 );
    osSerdes2Write( 0x4, 0x0, 0x8b, 0xe2 );
    osSerdes2Write( 0x4, 0x0, 0x8c, 0xef );
    osSerdes2Write( 0x4, 0x0, 0x8d, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x8e, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x8f, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x90, 0xef );
    osSerdes2Write( 0x4, 0x0, 0x91, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x92, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x93, 0xfb );
    osSerdes2Write( 0x4, 0x0, 0x94, 0xff );
    osSerdes2Write( 0x4, 0x0, 0x95, 0x3f );
    osSerdes2Write( 0x4, 0x0, 0x96, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x97, 0x64 );
    osSerdes2Write( 0x4, 0x0, 0x98, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x99, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0x9a, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0x9b, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x9c, 0x5 );
    osSerdes2Write( 0x4, 0x0, 0x9d, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0x9e, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x9f, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa0, 0x8 );
    osSerdes2Write( 0x4, 0x0, 0xa1, 0x4 );
    osSerdes2Write( 0x4, 0x0, 0xa2, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa3, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xa4, 0x4 );
    osSerdes2Write( 0x0, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x7, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0xd, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x30, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x31, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x36, 0x0 );
    osSerdes2Write( 0x4, 0x0, 0x37, 0xb4 );
    osSerdes2Write( 0x4, 0x0, 0x5d, 0x2 );
    osSerdes2Write( 0x4, 0x0, 0xa5, 0x2 );
    osSerdes2Write( 0x0, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x1, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x2, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x3, 0x0, 0x29, 0x6 );
    osSerdes2Write( 0x4, 0x0, 0x162, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x163, 0x3a );
    osSerdes2Write( 0x4, 0x0, 0x164, 0x9 );
    osSerdes2Write( 0x4, 0x0, 0x165, 0x3 );
    osSerdes2Write( 0x4, 0x0, 0x166, 0x3e );
    osSerdes2Write( 0x4, 0x0, 0x167, 0xc );
    osSerdes2Write( 0x0, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x1, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x2, 0x0, 0x2bd, 0x0 );
    osSerdes2Write( 0x3, 0x0, 0x2bd, 0x0 );


    /*配置并行数据接口的数据位宽和速率*/
    /*Addr[ioctrl1_base_addr+0x10],data[bit31-29=3'b001, bit28-26=3'b001,*/
    /*bit25-23=3'b001,bit22-20=3b001,bit19-17=3b001,bit16-14=3b001,*/
    /*bit13-11=3b001,bit10-8=3b001,bit7-0=all 1]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x10, 0x249249FF, 0x249249FF );

    /*addr[ioctrl1_base_addr+0x14],data[bit31-24=all0,bit23-21=3'b001,*/
    /*bit20-18=3'b001,bit17-15=3'b001,bit14-12=3'b001,bit11-9=3'b001,*/
    /*bit8-6=3'b001,bit5-3=3'b001,bit2-0=3'b001]*/
    osSerdesBitWrite( IOCTRL1_BASE_ADDR + 0x14, 0x249249, 0x249249 );

    /*配置prbs pattern和 on-chip loopback*/
    /*Macro2_rd(3'h4,1'h0,12'h5f,data[7:0]);data[4:4]=0,回写*/
    ulValue = osSerdes2Read(0x4,0x0,0x5f);
    ulValue &= 0xffffffef;
    osSerdes2Write(0x4,0x0,0x5f,ulValue);

    /*Macro2_rd(3'h4,1'h0,12'h50,data[7:0]);data[2:0]=x2[2:0]*/
    ulValue = osSerdes2Read(0x4,0x0,0x50);
    ulValue = (ulValue & 0xfffffff8 ) | ulPrbsPatten;
    osSerdes2Write(0x4,0x0,0x5f,ulValue);

    /*Macro2_rd(x1[2:0],1'h0,12'h55,data[7:0]);data[1:1]=0,回写*/
    ulValue = osSerdes2Read(ulLane & 0x7,0x0,0x55);
    ulValue = (ulValue & 0xfffffffd );
    osSerdes2Write(ulLane & 0x7,0x0,0x55,ulValue);

    /*环回*/
    osSerdes2PmaLp(ulLane, ulLpMode);


    /*等待500ns*/
    osSerdesWait( 0x1000 );

    /*复位撤离，Lane reset/syn reset*/
    /*Addr[sysctrl_base_addr+0x58c],data[bit9=1,bit8-0=all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x58c, 0x3ff, 0xffffffff );

   /*Enable p0 state*/
    /*Macro2_rd(x1[2:0],1'h0,12'h55,data[7:0]);data[0:0]=0,回写*/
    ulValue = osSerdes2Read(ulLane & 0x7,0x0,0x55);
    ulValue &= 0xFFFFFFFE;
    osSerdes2Write(ulLane & 0x7,0x0,0x55,ulValue);

    /*Macro2_rd(x1[2:0],1'h0,12'h3,data[7:0]);data[4:0]=5'b10000,回写*/
    ulValue = osSerdes2Read(ulLane & 0x7,0x0,0x3);
    ulValue = (ulValue | 0x10)  & 0xFFFFFFF0;
    osSerdes2Write(ulLane & 0x7,0x0,0x3,ulValue);

    /*Macro2_rd(x1[2:0],1'h0,12'h4,data[7:0]);data[4:0]=5'b10000,回写*/
    ulValue = osSerdes2Read(ulLane & 0x7,0x0,0x4);
    ulValue = (ulValue | 0x10)  & 0xFFFFFFF0;
    osSerdes2Write(ulLane & 0x7,0x0,0x4,ulValue);


    /*等待lanex tx/rx ready,synth ready，至此初始化完成*/
    /*Addr[ioctrl1_base_addr+0x400],data[bit11-4==all 1],*/
    /*等待bit11-4全部为1，即为等到ready*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
    ulValue = ulValue & 0xFF0;
#if SERDES_DEBUG_OPEN
    SRE_printf( "check IOCTRL1_BASE_ADDR + 0x400 == 0xff0\n" );
#else
    while ( ulWaitTime -- )
    {
        if(ulValue != 0xFF0)
        {
            ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x400, 0 );
            ulValue = ulValue & 0xFF0;
        }
        else
        {
            break;
        }
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "waiting for lanex tx/rx ready,synth ready over time at FILE:%s,LINE:%d \n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
#endif

    /*3.开启PMA BIST*/
    /*macro2_rd(x1[2:0],1'h0,12'h56,data[7:0])，data[0:0]=0,回写*/
    ulValue = osSerdes2Read(ulLane & 0x7,0x0,0x56);
    ulValue = (ulValue )  & 0xFFFFFFFE;
    osSerdes2Write(ulLane & 0x7,0x0,0x56,ulValue);

    /*macro2_rd(x1[2:0],1'h0,12'h8,data[7:0]);data[1:1]=1'b1; 回写*/
    ulValue = osSerdes2Read(ulLane & 0x7,0x0,0x8);
    ulValue = (ulValue )  | 0x2;
    osSerdes2Write(ulLane & 0x7,0x0,0x8,ulValue);

    /*等待CDR锁定 register-based*/
    /*macro2_rd(x1[2:0], 1'h0,12'h28,data[7:0]);data[5:5]=1'b1;data[6:6] =1'b0;回写*/
    ulValue = osSerdes2Read(ulLane & 0x7,0x0,0x28);
    ulValue = (ulValue  | 0x20 ) & 0xFFFFFFBF;
    osSerdes2Write(ulLane & 0x7,0x0,0x28,ulValue);

    /*等待macro2_rd(x1[2:0], 1'h0,12'hB,data[7:0]);直到data[5:5]==1*/
    ulValue = osSerdes2Read(ulLane & 0x7,0x0,0xB);
    while(0x20 != (ulValue & 0x20) && ulWaitTime -- )
    {
        ulValue = osSerdes2Read(ulLane & 0x7,0x0,0xB);
    }
    if(ulWaitTime <= 0)
    {
        SRE_printf("cdr didn't lock at LINE[%d]\n",__LINE__);
        return OS_FAIL;
    }

    /*开始PMA BIST receiver检查*/
    /*macro2_rd(x1[2:0],1'h0,12'h55,data[7:0]);data[5:5]=0;回写*/
    ulValue = osSerdes2Read(ulLane & 0x7,0x0,0x55);
    ulValue = (ulValue  ) & 0xFFFFFFDF;
    osSerdes2Write(ulLane & 0x7,0x0,0x55,ulValue);

    /*macro2_rd(x1[2:0],1'h0,12'h8,data[7:0]);data[1:1]=1'b1;回写*/
    ulValue = osSerdes2Read(ulLane & 0x7,0x0,0x8);
    ulValue = (ulValue  | 0x2);
    osSerdes2Write(ulLane & 0x7,0x0,0x8,ulValue);

    /*等待symbol lock*/
    /*一直进行macro2_rd(x1[2:0],1'h0,12'h8,data[7:0]);直到data[4:4]=1'b1;*/
    ulValue = osSerdes2Read(ulLane & 0x7,0x0,0x8);
    ulWaitTime = 1000000;
    while( ulWaitTime --)
    {
        if(0x10 != (ulValue & 0x10))
        {
             ulValue = osSerdes2Read(ulLane & 0x7,0x0,0x8);
        }
        else
        {
            break;
        }
    }
    if(ulWaitTime <= 0)
    {
        SRE_printf("symbol lock over time at line[%d]\n",__LINE__);
        return OS_FAIL;
    }
    return OS_SUCCESS;
}


UINT32 osSerdes1TbusRead( UINT32 addr0, UINT32 addr1 )
{
    //UINT32 ulRet = OS_SUCCESS;
    UINT32 ulData = 0;
    UINT32 ulData2 = 0;
     UINT32 ulData3 = 0;
      UINT32 ulData4 = 0;
        UINT32 ulData5 = 0;
    ulData = osSerdes1Read( 0x4, 0x0, 0x60 );
    osSerdes1Write( 0x4, 0x0, 0x60, ulData & 0xFFFFFFFB );

    ulData = osSerdes1Read( 0x4, 0x0, 0x10 );
    osSerdes1Write( 0x4, 0x0, 0x10, ulData & 0xFFFFFFF7 );

    /*macro1_wr(3'h4,1'h0,12'h16,{x1,x2});*/
    osSerdes1Write( 0x4, 0x0, 0x16,  ((addr0 & 0x7) << 0x5) | (addr1 & 0x1F));

    ulData = osSerdes1Read( 0x4, 0x0, 0x10 );
    /*macro1_rd(3'h4,1'h0,12'h10,data[7:0]);data[3:3]=1*/
    osSerdes1Write( 0x4, 0x0, 0x10, ulData | 0x8 );

    /*macro1_rd(3'h4,1'h0,12'h11,rdata1[7:0]); macro1_rd(3'h4,1'h0,12'h12,rdata2[7:0]); */
    ulData = (osSerdes1Read( 0x4, 0x0, 0x11 ) & 0xff) << 0;
    ulData2 = (osSerdes1Read( 0x4, 0x0, 0x12 ) & 0xff) << 8;
   /*macro1_rd(3'h4,1'h0,12'h13,rdata3[7:0]); macro1_rd(3'h4,1'h0,12'h14,rdata4[7:0]); */
    ulData3 = (osSerdes1Read( 0x4, 0x0, 0x13 ) & 0xff) << 16;
    ulData4 = (osSerdes1Read( 0x4, 0x0, 0x14 ) & 0xff) << 24;
    /*macro1_rd(3'h4,1'h0,12'h15,rdata5[7:0]);*/
    ulData5 = osSerdes1Read( 0x4, 0x0, 0x15 );

    SRE_printf("osSerdes1ThusRead : addr[0x%08x] , value[0x%08x]\n",ulData5,ulData4 | ulData3 | ulData2 |ulData);

    return OS_SUCCESS;
}


UINT32 osSerdes2TbusRead( UINT32 addr0, UINT32 addr1 )
{
    //UINT32 ulRet = OS_SUCCESS;
    UINT32 ulData = 0;
    UINT32 ulData2 = 0;
     UINT32 ulData3 = 0;
      UINT32 ulData4 = 0;
        UINT32 ulData5 = 0;
    ulData = osSerdes2Read( 0x4, 0x0, 0x60 );
    osSerdes2Write( 0x4, 0x0, 0x60, ulData & 0xFFFFFFFB );

    ulData = osSerdes2Read( 0x4, 0x0, 0x10 );
    osSerdes2Write( 0x4, 0x0, 0x10, ulData & 0xFFFFFFF7 );

    /*macro1_wr(3'h4,1'h0,12'h16,{x1,x2});*/
    osSerdes2Write( 0x4, 0x0, 0x16,  ((addr0 & 0x7) << 0x5) | (addr1 & 0x1F));

    ulData = osSerdes2Read( 0x4, 0x0, 0x10 );
    /*macro1_rd(3'h4,1'h0,12'h10,data[7:0]);data[3:3]=1*/
    osSerdes2Write( 0x4, 0x0, 0x10, ulData | 0x8 );

    /*macro1_rd(3'h4,1'h0,12'h11,rdata1[7:0]); macro1_rd(3'h4,1'h0,12'h12,rdata2[7:0]); */
    ulData = (osSerdes2Read( 0x4, 0x0, 0x11 ) & 0xff) << 0;
    ulData2 = (osSerdes2Read( 0x4, 0x0, 0x12 ) & 0xff) << 8;
   /*macro1_rd(3'h4,1'h0,12'h13,rdata3[7:0]); macro1_rd(3'h4,1'h0,12'h14,rdata4[7:0]); */
    ulData3 = (osSerdes2Read( 0x4, 0x0, 0x13 ) & 0xff) << 16;
    ulData4 = (osSerdes2Read( 0x4, 0x0, 0x14 ) & 0xff) << 24;
    /*macro1_rd(3'h4,1'h0,12'h15,rdata5[7:0]);*/
    ulData5 = osSerdes2Read( 0x4, 0x0, 0x15 );

    SRE_printf("osSerdes2ThusRead : addr[0x%08x] , value[0x%08x]\n",ulData5,ulData4 | ulData3 | ulData2 |ulData);

    return OS_SUCCESS;
}



/*****************************************************************
函数名 :  osSerdes1PmaLp
输入参数    :  ulLane
              ulLpMode
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/31
*****************************************************************/
UINT32 osSerdes1PmaLp( UINT32 ulLane, UINT32 ulLpMode )
{
    UINT32 ulData = 0;
    /*macro1_rd(x1[2:0],1'h0,12'h55,data[7:0]);data[1:1]=0; macro1_wr(a,1'h0,12'h55,data[7:0])*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0x55 );
    ulData &= 0xFFFFFFFD;
    osSerdes1Write( ulLane & 0x7, 0x0, 0x55 ,ulData);

    /*macro1_rd(x1[2:0],1'h0,12'h7,data[7:0]);*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0x7 );

    switch ( ulLpMode )
    {
        case 0:
            /*data[4:4]=1'b1, data[5:5]=1'b0,data[6:6]=1'b0, data[7:7]=1'b0;bit[0:0]=1'b0*/
            ulData = ( ulData | 0x10 ) & 0xFFFFFF1E;
            break;
        case 1:
            /*data[4:4]=1'b0, data[5:5]=1'b1,data[6:6]=1'b0, data[7:7]=1'b0;bit[0:0]=1'b0*/
            ulData = ( ulData | 0x20 ) & 0xFFFFFF2E;
            break;
        case 2:
            /*data[4:4]=1'b0, data[5:5]=1'b0,data[6:6]=1'b1, data[7:7]=1'b0;bit[0:0]=1'b0*/
            ulData = ( ulData | 0x40 ) & 0xFFFFFF4E;
            break;
        case 3:
            /*data[4:4]=1'b0, data[5:5]=1'b0,data[6:6]=1'b0, data[7:7]=1'b1;bit[0:0]=1'b1*/
            ulData = ( ulData | 0x81 ) & 0xFFFFFF8F;
            break;
        default:
            SRE_printf( "ERROR ulLpMode at FILE:%s,LINE %d\n", __FILE__, __LINE__ );
            return OS_FAIL;
    }
    osSerdes1Write( ulLane & 0x7, 0x0, 0x7, ulData );
    return OS_SUCCESS;
}


/*****************************************************************
函数名 :  osSerdes2PmaLp
输入参数    :  ulLane
              ulLpMode
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/31
*****************************************************************/
UINT32 osSerdes2PmaLp( UINT32 ulLane, UINT32 ulLpMode )
{
    UINT32 ulData = 0;
    /*macro1_rd(x1[2:0],1'h0,12'h55,data[7:0]);data[1:1]=0; macro1_wr(a,1'h0,12'h55,data[7:0])*/
    ulData = osSerdes2Read( ulLane & 0x7, 0x0, 0x55 );
    ulData &= 0xFFFFFFFD;
    osSerdes2Write( ulLane & 0x7, 0x0, 0x55 ,ulData );

    /*macro1_rd(x1[2:0],1'h0,12'h7,data[7:0]);*/
    ulData = osSerdes2Read( ulLane & 0x7, 0x0, 0x7 );

    switch ( ulLpMode )
    {
        case 0:
            /*data[4:4]=1'b1, data[5:5]=1'b0,data[6:6]=1'b0, data[7:7]=1'b0;bit[0:0]=1'b0*/
            ulData = ( ulData | 0x10 ) & 0xFFFFFF1E;
            break;
        case 1:
            /*data[4:4]=1'b0, data[5:5]=1'b1,data[6:6]=1'b0, data[7:7]=1'b0;bit[0:0]=1'b0*/
            ulData = ( ulData | 0x20 ) & 0xFFFFFF2E;
            break;
        case 2:
            /*data[4:4]=1'b0, data[5:5]=1'b0,data[6:6]=1'b1, data[7:7]=1'b0;bit[0:0]=1'b0*/
            ulData = ( ulData | 0x40 ) & 0xFFFFFF4E;
            break;
        case 3:
            /*data[4:4]=1'b0, data[5:5]=1'b0,data[6:6]=1'b0, data[7:7]=1'b1;bit[0:0]=1'b1*/
            ulData = ( ulData | 0x81 ) & 0xFFFFFF8F;
            break;
        default:
            SRE_printf( "ERROR ulLpMode at FILE:%s,LINE %d\n", __FILE__, __LINE__ );
            return OS_FAIL;
    }
    osSerdes2Write( ulLane & 0x7, 0x0, 0x7, ulData );
    return OS_SUCCESS;
}

/*****************************************************************
函数名 :  osSerdes1PcsLp
输入参数    :  ulLane
              ulLpMode
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/31
*****************************************************************/
UINT32 osSerdes1PcsLp( UINT32 ulLane, UINT32 ulLpMode )
{
    UINT32 ulData = 0;
    /*macro1_rd(x1[2:0],1'h0,12'h55,data[7:0]);data[1:1]=0; macro1_wr(a,1'h0,12'h55,data[7:0]);*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x1, 0x55 );
    ulData = ulData & 0xFFFFFFFD;
    osSerdes1Write( ulLane & 0x7, 0x1, 0x55, ulData );

    /*macro1_rd(x1[2:0],1'h0,12'hC,data[7:0])*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x1, 0xc );

    if ( ulLpMode == 1 )
    {
        ulData = ( ulData | 0x8 ) & 0xFFFFFFEF;
    }
    else if ( ulLpMode == 2 )
    {
        ulData = ( ulData | 0x10 ) & 0xFFFFFFF7;
    }
    else
    {
        SRE_printf( "ERROR ulLpMode at FILE:%s,LINE %d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    osSerdes1Write( ulLane & 0x7, 0x1, 0xc, ulData );
    return OS_SUCCESS;
}

/*****************************************************************
函数名 :  osSerdes2PcsLp
输入参数    :  ulLane
              ulLpMode
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/31
*****************************************************************/
UINT32 osSerdes2PcsLp( UINT32 ulLane, UINT32 ulLpMode )
{
    UINT32 ulData = 0;
    /*macro1_rd(x1[2:0],1'h0,12'h55,data[7:0]);data[1:1]=0; macro1_wr(a,1'h0,12'h55,data[7:0]);*/
    ulData = osSerdes2Read( ulLane & 0x7, 0x1, 0x55 );
    ulData = ulData & 0xFFFFFFFD;
    osSerdes2Write( ulLane & 0x7, 0x1, 0x55, ulData );

    /*macro1_rd(x1[2:0],1'h0,12'hC,data[7:0])*/
    ulData = osSerdes2Read( ulLane & 0x7, 0x1, 0xc );

    if ( ulLpMode == 1 )
    {
        ulData = ( ulData | 0x8 ) & 0xFFFFFFEF;
    }
    else if ( ulLpMode == 2 )
    {
        ulData = ( ulData | 0x10 ) & 0xFFFFFFF7;
    }
    else
    {
        SRE_printf( "ERROR ulLpMode at FILE:%s,LINE %d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    osSerdes2Write( ulLane & 0x7, 0x1, 0xc, ulData );
    return OS_SUCCESS;
}

/*****************************************************************
函数名 :  osSerdes1PmaBistOn
输入参数    :  ulLane
              ulPrabPatten
              ulLpMode
输出参数      :
Description   :  serdes1 开启bist测试

Author        :  z00228490
Creation time :  2012/12/31
*****************************************************************/
UINT32 osSerdes1PmaBistOn( UINT32 ulLane, UINT32 ulPrabPatten, UINT32 ulLpMode )
{
    UINT32 ulData = 0;
    INT32 ulWaitTime = 0x10000;
    /*macro1_rd(x1[2:0],1'h0,12'h55,data[7:0])*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0x55 );
    ulData = ulData & 0xFFFFFFDE;

    /*macro1_wr(x1[2:0],1'h0,12'h55,data[7:0])*/
    osSerdes1Write( ulLane & 0x7, 0x0, 0x55, ulData );

    /*macro1_rd(x1[2:0],1'h0,12'h56,data[7:0])*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0x56 );
    ulData = ulData & 0xFFFFFFFE;

    /*macro1_wr(x1[2:0],1'h0,12'h56,data[7:0]);*/
    osSerdes1Write( ulLane & 0x7, 0x0, 0x56, ulData );

    /*macro1_rd(3'h4,1'h0,12'h50,data[7:0]);*/
    ulData = osSerdes1Read( 0x4, 0x0, 0x50 );
    ulData = ( ulData & 0xFFFFFFF8 ) | ( ulPrabPatten & 0x7 );

    /*macro1_wr(3'h4,1'h0,12'h50,data[7:0]);*/
    osSerdes1Write( 0x4, 0x0, 0x50, ulData );

    osSerdes1PmaLp( ulLane, ulLpMode );

    /*macro1_rd(x1[2:0],1'h0,12'h8,data[7:0]);*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0x8 );
    ulData = ulData | 0x2;

    /*macro1_wr(x1[2:0],1'h0,12'h8,data[7:0]);*/
    osSerdes1Write( ulLane & 0x7, 0x0, 0x8, ulData );

    /*macro1_rd(x1[2:0], 1'h0,12'h28,data[7:0]);*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0x28 );
    ulData = ( ulData | 0x20 ) & 0xFFFFFFBF;

    /*macro1_wr(x1[2:0], 1'h0,12'h28,data[7:0]);*/
    osSerdes1Write( ulLane & 0x7, 0x0, 0x28, ulData );

    /*macro1_rd(x1[2:0], 1'h0,12'hB,data[7:0])*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0xB );
    while ( 0x20 != ( ulData & 0x20 ) && ulWaitTime -- )
    {
        ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0xB );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "wait for bit change over time at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }

    /*macro1_rd(x1[2:0],1'h0,12'h8,data[7:0])*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0x8 );
    ulData = ulData | 0x2;

    /*macro1_wr(x1[2:0],1'h0,12'h8,data[7:0]);*/
    osSerdes1Write( ulLane & 0x7, 0x0, 0x8, ulData );

    /*macro1_rd(x1[2:0],1'h0,12'h8,data[7:0]);*/
    ulWaitTime = 0x10000;
    ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0x8 );
    while ( 0x10 != ( ulData & 0x10 ) && ulWaitTime-- )
    {
        ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0x8 );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "wait for bit change over time at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;
}


/*****************************************************************
函数名 :  osSerdes2PmaBistOn
输入参数    :  ulLane
              ulPrabPatten
              ulLpMode
输出参数      :
Description   :  serdes1 开启bist测试

Author        :  z00228490
Creation time :  2012/12/31
*****************************************************************/
UINT32 osSerdes2PmaBistOn( UINT32 ulLane, UINT32 ulPrabPatten, UINT32 ulLpMode )
{
    UINT32 ulData = 0;
    INT32 ulWaitTime = 0x10000;
    /*macro1_rd(x1[2:0],1'h0,12'h55,data[7:0])*/
    ulData = osSerdes2Read( ulLane & 0x7, 0x0, 0x55 );
    ulData = ulData & 0xFFFFFFDE;

    /*macro1_wr(x1[2:0],1'h0,12'h55,data[7:0])*/
    osSerdes2Write( ulLane & 0x7, 0x0, 0x55, ulData );

    /*macro1_rd(x1[2:0],1'h0,12'h56,data[7:0])*/
    ulData = osSerdes2Read( ulLane & 0x7, 0x0, 0x56 );
    ulData = ulData & 0xFFFFFFFE;

    /*macro1_wr(x1[2:0],1'h0,12'h56,data[7:0]);*/
    osSerdes2Write( ulLane & 0x7, 0x0, 0x56, ulData );

    /*macro1_rd(3'h4,1'h0,12'h50,data[7:0]);*/
    ulData = osSerdes2Read( 0x4, 0x0, 0x50 );
    ulData = ( ulData & 0xFFFFFFF8 ) | ( ulPrabPatten & 0x7 );

    /*macro1_wr(3'h4,1'h0,12'h50,data[7:0]);*/
    osSerdes2Write( 0x4, 0x0, 0x50, ulData );

    osSerdes2PmaLp( ulLane, ulLpMode );

    /*macro1_rd(x1[2:0],1'h0,12'h8,data[7:0]);*/
    ulData = osSerdes2Read( ulLane & 0x7, 0x0, 0x8 );
    ulData = ulData | 0x2;

    /*macro1_wr(x1[2:0],1'h0,12'h8,data[7:0]);*/
    osSerdes2Write( ulLane & 0x7, 0x0, 0x8, ulData );

    /*macro1_rd(x1[2:0], 1'h0,12'h28,data[7:0]);*/
    ulData = osSerdes2Read( ulLane & 0x7, 0x0, 0x28 );
    ulData = ( ulData | 0x20 ) & 0xFFFFFFBF;

    /*macro1_wr(x1[2:0], 1'h0,12'h28,data[7:0]);*/
    osSerdes2Write( ulLane & 0x7, 0x0, 0x28, ulData );

    /*macro1_rd(x1[2:0], 1'h0,12'hB,data[7:0])*/
    ulData = osSerdes2Read( ulLane & 0x7, 0x0, 0xB );
    while ( 0x20 != ( ulData & 0x20 ) && ulWaitTime -- )
    {
        ulData = osSerdes2Read( ulLane & 0x7, 0x0, 0xB );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "wait for bit change over time at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }

    /*macro1_rd(x1[2:0],1'h0,12'h8,data[7:0])*/
    ulData = osSerdes2Read( ulLane & 0x7, 0x0, 0x8 );
    ulData = ulData | 0x2;

    /*macro1_wr(x1[2:0],1'h0,12'h8,data[7:0]);*/
    osSerdes2Write( ulLane & 0x7, 0x0, 0x8, ulData );

    /*macro1_rd(x1[2:0],1'h0,12'h8,data[7:0]);*/
    ulWaitTime = 0x10000;
    ulData = osSerdes2Read( ulLane & 0x7, 0x0, 0x8 );
    while ( 0x10 != ( ulData & 0x10 ) && ulWaitTime-- )
    {
        ulData = osSerdes2Read( ulLane & 0x7, 0x0, 0x8 );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "wait for bit change over time at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    return OS_SUCCESS;
}

UINT32 osSerdes1PmaBistOff( UINT32 ulLane, UINT32 ulPrabPatten, UINT32 ulLpMode )
{
    UINT32 ulData = 0;
    INT32 ulWaitTime = 0x10000;
    UINT32 ulBistCnt1, ulBistCnt2;

    /*macro1_rd(x1[2:0],1'h0,12'h8,data[7:0])*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0x8 );
    ulData = ulData & 0xFFFFFFFD;
    osSerdes1Write( ulLane & 0x7, 0x0, 0x8, ulData );

    /*macro1_rd(x1[2:0],1'h0,12'h8,data[7:0]);直到data[2:2]=1'b1*/
    ulWaitTime = 0x10000;
    ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0x8 );
    while ( 0x8 != ( ulData & 0x8 ) && ulWaitTime -- )
    {
        ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0x8 );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "wait for bit change over time at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    ulBistCnt1 = osSerdes1Read( ulLane & 0x7, 0x0, 0x9 );
    ulBistCnt2 = osSerdes1Read( ulLane & 0x7, 0x0, 0xA );

    SRE_printf("ulBistCnt1 : [%d],ulBistCnt2 : [%d]\n",ulBistCnt1,ulBistCnt2);

    /*Macro2_rd(x1[2:0],1'h0,12'h8,data[7:0]); data[3:3]=1*/
    ulBistCnt1 = osSerdes1Read( ulLane & 0x7, 0x0, 0x8 );

    if(0x8 == (ulBistCnt1 & 0x8))
    {
        SRE_printf("error is too many !osSerdes1PmaBistOff \n");
    }

    return OS_SUCCESS;
}
UINT32 osSerdes2PmaBistOff( UINT32 ulLane, UINT32 ulPrabPatten, UINT32 ulLpMode )
{
    UINT32 ulData = 0;
    INT32 ulWaitTime = 0x10000;
    UINT32 ulBistCnt1, ulBistCnt2;

    /*macro1_rd(x1[2:0],1'h0,12'h8,data[7:0])*/
    ulData = osSerdes2Read( ulLane & 0x7, 0x0, 0x8 );
    ulData = ulData & 0xFFFFFFFD;
    osSerdes2Write( ulLane & 0x7, 0x0, 0x8, ulData );

    /*macro1_rd(x1[2:0],1'h0,12'h8,data[7:0]);直到data[2:2]=1'b1*/
    ulWaitTime = 0x10000;
    ulData = osSerdes2Read( ulLane & 0x7, 0x0, 0x8 );
    while ( 0x8 != ( ulData & 0x8 ) && ulWaitTime -- )
    {
        ulData = osSerdes2Read( ulLane & 0x7, 0x0, 0x8 );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "wait for bit change over time at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    ulBistCnt1 = osSerdes2Read( ulLane & 0x7, 0x0, 0x9 );
    ulBistCnt2 = osSerdes2Read( ulLane & 0x7, 0x0, 0xA );

    SRE_printf("ulBistCnt1 : [%d],ulBistCnt2 : [%d]\n",ulBistCnt1,ulBistCnt2);

    /*Macro2_rd(x1[2:0],1'h0,12'h8,data[7:0]); data[3:3]=1*/
    ulBistCnt1 = osSerdes2Read( ulLane & 0x7, 0x0, 0x8 );

    if(0x8 == (ulBistCnt1 & 0x8))
    {
        SRE_printf("error is too many !osSerdes2PmaBistOff \n");
    }

    return OS_SUCCESS;
}

UINT32 osSerdes3BistTest(void)
{
    UINT32 ulValue = 0;
    UINT32 ulLoop = 0;
    INT32 ulWaitTime = 0x10000;
    /*Addr[sysctrl_base_addr+0x590],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x590, 0x1FFFF00, 0xffffffff );
    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=0,bit4=0]*/
    for ( ulLoop = 0; ulLoop < 4; ulLoop++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x0, 0xFFFFFFEE );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x0, 0xFFF7FFFF );
    /*Addr[serdes3_base_addr+0x0],data[bit29=0]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR, 0x0, 0xDFFFFFFF );

    osSerdesWait( 0x1000 );

    OS_SDS_WRITE_REG( SERDES3_BASE_ADDR, 0x0, 0x36 );
    OS_SDS_WRITE_REG( SERDES3_BASE_ADDR + 0x4 , 0x0, 0x26 );
    OS_SDS_WRITE_REG( SERDES3_BASE_ADDR + 0x100 , 0x0, 0x21010c );
    OS_SDS_WRITE_REG( SERDES3_BASE_ADDR + 0x104 , 0x0, 0x210affa0 );

    OS_SDS_WRITE_REG( SERDES3_BASE_ADDR + 0x82c , 0x0, 0x40000 );
    OS_SDS_WRITE_REG( SERDES3_BASE_ADDR + 0x838  , 0x0, 0xd33 );
    OS_SDS_WRITE_REG( SERDES3_BASE_ADDR + 0x8ac , 0x0, 0x0 );
    OS_SDS_WRITE_REG( SERDES3_BASE_ADDR + 0x8b8  , 0x0, 0xd33 );
    OS_SDS_WRITE_REG( SERDES3_BASE_ADDR + 0x92c , 0x0, 0x0 );
    OS_SDS_WRITE_REG( SERDES3_BASE_ADDR + 0x938  , 0x0, 0xd33 );
    OS_SDS_WRITE_REG( SERDES3_BASE_ADDR + 0x9ac , 0x0, 0x0 );
    OS_SDS_WRITE_REG( SERDES3_BASE_ADDR + 0x9b8  , 0x0, 0xd33 );

    osSerdesWait( 0x1000 );

    /*Addr[sysctrl_base_addr+0x594],data[bit24=1, bit23-8= all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1000000, 0xFF0000FF );

    osSerdesWait( 0x1000 );
    /*Addr[ioctrl1_base_addr+0x434],data[bit4=1, means pll is locked]*/
    ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    while ( 0x10 != ( ulValue & 0x10 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x434, 0 );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "osSerdes0WaitForPllCfg error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    osSerdesWait( 0x1000 );
    /*Addr[sysctrl_base_addr+0x594],data[bit24-8= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0x1FFFF00, 0xFFffffFF );
    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=1,bit4=1]*/
    for ( ulLoop = 0; ulLoop < 4; ulLoop++ )
    {
        osSerdesBitWrite( SERDES3_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x11, 0xFFFFFFFF );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x144, 0x80000, 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x0],data[bit29=1]*/
    osSerdesBitWrite( SERDES3_BASE_ADDR + 0x0, 0x20000000, 0xFFFFFFFF );

    /**/

    return OS_SUCCESS;
}

UINT32 osSerdes0BistTest(void)
{
    UINT32 ulValue = 0;
    UINT32 ulLoop = 0;
    INT32 ulWaitTime = 0x10000;
    /*Addr[sysctrl_base_addr+0x580],data[bit24-0= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x580, 0x1FFFFFF, 0xffffffff );
    /*Addr[sysctrl_base_addr+0x590],data[bit7-0= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x590, 0xFF, 0xffffffff );

    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=0,bit4=0]*/
    for ( ulLoop = 0; ulLoop < 4; ulLoop++ )
    {
        osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x0, 0xFFFFFFEE );
        osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x0, 0xFFFFFFEE );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=0]*/
    osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x144, 0x0, 0xFFF7FFFF );
    osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x144, 0x0, 0xFFF7FFFF );
    /*Addr[serdes3_base_addr+0x0],data[bit29=0]*/
    osSerdesBitWrite( SERDES0_LOW_BASE_ADDR, 0x0, 0xDFFFFFFF );
    osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR, 0x0, 0xDFFFFFFF );

    osSerdesWait( 0x1000 );

    OS_SDS_WRITE_REG( SERDES0_LOW_BASE_ADDR, 0x0, 0x36 );
    OS_SDS_WRITE_REG( SERDES0_LOW_BASE_ADDR + 0x4 , 0x0, 0x26 );
    OS_SDS_WRITE_REG( SERDES0_LOW_BASE_ADDR + 0x100 , 0x0, 0x21010c );
    OS_SDS_WRITE_REG( SERDES0_LOW_BASE_ADDR + 0x104 , 0x0, 0x210affa0 );

    OS_SDS_WRITE_REG( SERDES0_HIGHT_BASE_ADDR, 0x0, 0x36 );
    OS_SDS_WRITE_REG( SERDES0_HIGHT_BASE_ADDR + 0x4 , 0x0, 0x26 );
    OS_SDS_WRITE_REG( SERDES0_HIGHT_BASE_ADDR + 0x100 , 0x0, 0x21010c );
    OS_SDS_WRITE_REG( SERDES0_HIGHT_BASE_ADDR + 0x104 , 0x0, 0x210affa0 );

    OS_SDS_WRITE_REG( SERDES0_LOW_BASE_ADDR + 0x82c , 0x0, 0x40000 );
    OS_SDS_WRITE_REG( SERDES0_LOW_BASE_ADDR + 0x838  , 0x0, 0xd33 );
    OS_SDS_WRITE_REG( SERDES0_LOW_BASE_ADDR + 0x8ac , 0x0, 0x0 );
    OS_SDS_WRITE_REG( SERDES0_LOW_BASE_ADDR + 0x8b8  , 0x0, 0xd33 );
    OS_SDS_WRITE_REG( SERDES0_LOW_BASE_ADDR + 0x92c , 0x0, 0x0 );
    OS_SDS_WRITE_REG( SERDES0_LOW_BASE_ADDR + 0x938  , 0x0, 0xd33 );
    OS_SDS_WRITE_REG( SERDES0_LOW_BASE_ADDR + 0x9ac , 0x0, 0x0 );
    OS_SDS_WRITE_REG( SERDES0_LOW_BASE_ADDR + 0x9b8  , 0x0, 0xd33 );

    OS_SDS_WRITE_REG( SERDES0_HIGHT_BASE_ADDR + 0x82c , 0x0, 0x40000 );
    OS_SDS_WRITE_REG( SERDES0_HIGHT_BASE_ADDR + 0x838  , 0x0, 0xd33 );
    OS_SDS_WRITE_REG( SERDES0_HIGHT_BASE_ADDR + 0x8ac , 0x0, 0x0 );
    OS_SDS_WRITE_REG( SERDES0_HIGHT_BASE_ADDR + 0x8b8  , 0x0, 0xd33 );
    OS_SDS_WRITE_REG( SERDES0_HIGHT_BASE_ADDR + 0x92c , 0x0, 0x0 );
    OS_SDS_WRITE_REG( SERDES0_HIGHT_BASE_ADDR + 0x938  , 0x0, 0xd33 );
    OS_SDS_WRITE_REG( SERDES0_HIGHT_BASE_ADDR + 0x9ac , 0x0, 0x0 );
    OS_SDS_WRITE_REG( SERDES0_HIGHT_BASE_ADDR + 0x9b8  , 0x0, 0xd33 );

    osSerdesWait( 0x1000 );

    /*Addr[sysctrl_base_addr+0x584],data[bit24=1, bit23-0= all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x584, 0x1000000, 0xFF000000 );
    /*Addr[sysctrl_base_addr+0x594],data[bit7-0= all 0]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x584, 0x0, 0xFFFFFF00 );

    osSerdesWait( 0x1000 );
    /*Addr[ioctrl0_base_addr+0x400],data[bit9-8=2'b11, means pll is locked]*/
    ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x400, 0 );
    while ( 0x300 != ( ulValue & 0x300 ) && ulWaitTime -- )
    {
        ulValue = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x400, 0 );
    }
    if ( ulWaitTime <= 0 )
    {
        SRE_printf( "osSerdes0WaitForPllCfg error at FILE:%s,LINE:%d\n", __FILE__, __LINE__ );
        return OS_FAIL;
    }
    osSerdesWait( 0x1000 );
    /*Addr[sysctrl_base_addr+0x584],data[bit24-0= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x584, 0x1FFFFFF, 0xFFffffFF );
    /*Addr[sysctrl_base_addr+0x594],data[bit7-0= all 1]*/
    osSerdesBitWrite( SYSCTRL_BASE_ADDR + 0x594, 0xFF, 0xFFffffFF );

    /*Addr[serdes3_base_addr+0x838+0x80*0~3],data[bit0=1,bit4=1]*/
    for ( ulLoop = 0; ulLoop < 4; ulLoop++ )
    {
        osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x11, 0xFFFFFFFF );
        osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x838 + 0x80 * ulLoop, 0x11, 0xFFFFFFFF );
    }
    /*Addr[serdes3_base_addr+0x144],data[bit19=1]*/
    osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x144, 0x80000, 0xFFFFFFFF );
    osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x144, 0x80000, 0xFFFFFFFF );
    /*Addr[serdes3_base_addr+0x0],data[bit29=1]*/
    osSerdesBitWrite( SERDES0_LOW_BASE_ADDR + 0x0, 0x20000000, 0xFFFFFFFF );
    osSerdesBitWrite( SERDES0_HIGHT_BASE_ADDR + 0x0, 0x20000000, 0xFFFFFFFF );

    /**/

    return OS_SUCCESS;
}


#if 0
/*****************************************************************
函数名 :  osSerdes1PcsBistOn
输入参数    :  ulLane
              ulPrabPatten
              ulLpMode
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/31
*****************************************************************/
UINT32 osSerdes1PcsBistOn( UINT32 ulLane, UINT32 ulPrabPatten, UINT32 ulLpMode )
{
    UINT32 ulData = 0;
    INT32 ulWaitTime = 0x10000;
    UINT32 ulTemp1, ulTemp2;

    /*Macro1_rd(x1[2:0],1'h0,12'h55,data[7:0])*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0x55 );
    ulData = ulData & 0xFFFFFFDD;
    osSerdes1Write( ulLane & 0x7, 0x0, 0x55, ulData );

    /*macro1_rd(x1[2:0],1'h0,12'h56,data[7:0])*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0x56 );
    ulData = ulData & 0xFFFFFFFE;
    osSerdes1Write( ulLane & 0x7, 0x0, 0x55, ulData );

    /*Macro1_rd(x1[2:0],1'h0, 12'h7,data[7:0]);data[6:6]=1;再回写*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x0, 0x7 );
    ulData = ulData | 0x40;
    osSerdes1Write( ulLane & 0x7, 0x0, 0x7, ulData );

    /*Macro1_rd(x1[2:0],1'h1, 12'h7,data[7:0]);data[6:6]=1;再回写*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x1, 0x7 );
    ulData = ulData | 0x40;
    osSerdes1Write( ulLane & 0x7, 0x1, 0x7, ulData );

    /*Macro1_rd(x1[2:0],1'h1, 12'h7,data[7:0]);data[1:1]=1;再回写*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x1, 0x7 );
    ulData = ulData | 0x2;
    osSerdes1Write( ulLane & 0x7, 0x1, 0x7, ulData );

    /*Macro1_rd(x1[2:0],1'h1, 12'h9,data[7:0]);data[6:6]=0;再回写*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x1, 0x9 );
    ulData = ulData & 0xFFFFFFBF;
    osSerdes1Write( ulLane & 0x7, 0x1, 0x9, ulData );

    /*Macro1_rd(x1[2:0],1'h1, 12'h9,data[7:0]);data[1:1]=0;再回写*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x1, 0x9 );
    ulData = ulData & 0xFFFFFFFD;
    osSerdes1Write( ulLane & 0x7, 0x1, 0x9, ulData );

    /*Macro1_rd(x1[2:0],1'h1, 12'h7,data[7:0]);data[0:0]=0;再回写*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x1, 0x7 );
    ulData = ulData & 0xFFFFFFFE;
    osSerdes1Write( ulLane & 0x7, 0x1, 0x7, ulData );

    /*Macro1_rd(x1[2:0],1'h1, 12'h7,data[7:0]);data[2:2]=0;再回写*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x1, 0x7 );
    ulData = ulData & 0xFFFFFFFB;
    osSerdes1Write( ulLane & 0x7, 0x1, 0x7, ulData );

    /*Macro1_rd(x1[2:0],1'h1, 12'h9,data[7:0]);data[5:2]=0;再回写*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x1, 0x9 );
    ulData = ulData & 0xFFFFFFC3;
    osSerdes1Write( ulLane & 0x7, 0x1, 0x9, ulData );

    /*Macro1_rd(x1[2:0],1'h1, 12'h8,data[7:0]);data[1:0]=x2[1:0];再回写*/
    ulData = osSerdes1Read( ulLane & 0x7, 0x1, 0x8 );
    ulData = ( ulData & 0xFFFFFFFC ) | ( ulPrabPatten & 0x3 );
    osSerdes1Write( ulLane & 0x7, 0x1, 0x8, ulData );

    /*Macro1_rd(3'h4,1'h1, 12'h11,data[7:0]);data[2:0]= 3'b1;再回写*/
    ulData = osSerdes1Read( 0x4, 0x1, 0x11 );
    ulData = ( ulData | 0x1 ) & 0xFFFFFFF9;
    osSerdes1Write( 0x4, 0x1, 0x11, ulData );

    /*Macro1_rd(3'h4,1'h1, 12'h7,data1[7:0])*/
    ulTemp1 = osSerdes1Read( 0x4, 0x1, 0x7 );
    ulTemp2 = osSerdes1Read( 0x4, 0x1, 0x8 );
    ulData = ( ( ulTemp1 & 0xFF ) << 0x8 ) | ( ulTemp2 & 0xFF );
    while ( 0x4B0 != ( ulData & 0xFFFF ) && ulWaitTime -- )
    {
        ulTemp1 = osSerdes1Read( 0x4, 0x1, 0x7 );
        ulTemp2 = osSerdes1Read( 0x4, 0x1, 0x8 );
        ulData = ( ( ulTemp1 & 0xFF ) << 0x8 ) | ( ulTemp2 & 0xFF );
    }
    osSerdes1Write( 0x4, 0x1, 0x11, ulData );


}

#endif
/*****************************************************************
函数名 :  osSerdes0Write
输入参数    :  ulAddr   地址
              ulValue    写数据
输出参数      :
Description   :  serdes0 debug读写接口

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
void osSerdes0LowWrite( UINT32 ulAddr, UINT32 ulValue )
{
    OS_SDS_WRITE_REG( SERDES0_LOW_BASE_ADDR + ulAddr, 0, ulValue );
}

/*****************************************************************
函数名 :  osSerdes0LowRead
输入参数    :  ulAddr   地址
              ulValue    写数据
输出参数      :
Description   :  serdes0 debug读写接口

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes0LowRead( UINT32 ulAddr )
{
    return OS_READ_REG( SERDES0_LOW_BASE_ADDR + ulAddr, 0 );
}

/*****************************************************************
函数名 :  osSerdes0HighWrite
输入参数    :  ulAddr   地址
              ulValue    写数据
输出参数      :
Description   :  serdes0 debug读写接口

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
void osSerdes0HighWrite( UINT32 ulAddr, UINT32 ulValue )
{
    OS_SDS_WRITE_REG( SERDES0_HIGHT_BASE_ADDR + ulAddr, 0, ulValue );
}

/*****************************************************************
函数名 :  osSerdes0HighRead
输入参数    :  ulAddr   地址
              ulValue    写数据
输出参数      :
Description   :  serdes0 debug读写接口

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes0HighRead( UINT32 ulAddr )
{
    return OS_READ_REG( SERDES0_HIGHT_BASE_ADDR + ulAddr, 0 );
}


/*****************************************************************
函数名 :  osSerdes1Write
输入参数    :  ulPage  :3bit
              ulType  : 1bit
              ulOffset :12 bit
              ulValue  :8 bit
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/28
*****************************************************************/
void osSerdes1Write( UINT32 ulPage, UINT32 ulType, UINT32 ulOffset, UINT32 ulValue )
{
    /*1、:write addr[ioctrl0_base_addr+0x9c],data[bit31-27=all 0,*/
    /*bit26=0,bit25=1,bit24=1,bit23-16=x4,bit15-13=x1,bit12=x2,bit11-0=x3]*/
    UINT32 ulTemp = 0;
    UINT32 ulRdata = 0;
    INT32 ulLoop = SREDES_LOOP_TIME;
    UINT32 ulStepChoose = 0;
    ulTemp = ( ( ulTemp | 0x3000000 ) | ( ulValue << 16 ) | \
               ( ulOffset & 0xfff ) | ( ulType << 12 ) | ( ulPage << 13 ) );
    OS_SDS_WRITE_REG( IOCTRL0_BASE_ADDR + 0x9c, 0, ulTemp );

    /*2:write addr[ioctrl0_base_addr+0x9c],*/
    /*data[bit31-27=all 0,bit26=0,bit25=0,bit24=1,*/
    /*bit23-16=x4,bit15-13=x1,bit12=x2,bit11-0=x3]*/
    OS_SDS_WRITE_REG( IOCTRL0_BASE_ADDR + 0x9c, 0, ulTemp & 0xFDFFFFFF );

    /*第3步：read addr[ioctrl0_base_addr+0x42c], 回读的数据为rdata*/
    ulRdata = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x42c, 0 );
#if SERDES_DEBUG_OPEN
    SRE_printf( "check IOCTRL0_BASE_ADDR + 0x42c == 0x100\n" );

#else

    /*第4步：如果第3步中rdata[bit8==0],回到第3步；如果1ms内，*/
    /*rdata[bit8==1],走到第5步；如果超过1ms后，直接走到第6步*/
    while ( --ulLoop )
    {
        if ( 0x100 == ( ulRdata & 0x100 ) )
        {
            ulStepChoose = 5;
            break;
        }
        else
        {
            ulRdata = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x42c, 0 );
        }
    }

#endif
    if(gulDebugOpen)
    {
        if ( 5 == ulStepChoose )
        {
            SRE_printf( "serdes1 write ok page=%x sel=%x offset=%x rdata=%x", ulPage, ulType, ulOffset, ulRdata );
        }
    }
    if ( ulLoop <= 0 )
    {
            SRE_printf( "serdes1 write outoftime page=%x sel=%x offset=%x", ulPage, ulType, ulOffset );
    }

    /*第7步：write addr[ioctrl0_base_addr+0x9c],*/
    /*data[bit31-27=all 0,bit26=1,bit25=0,bit24=1,bit23-16=X4,bit15-13=x1,*/
    /*bit12=x2,bit11-0=x3]*/
    ulTemp = 0;
    ulTemp = ( ulTemp | 0x5000000 ) | ( ulPage << 13 ) | ( ulType << 12 ) | ( ulOffset & 0xfff ) | (ulValue << 16);
    OS_SDS_WRITE_REG( IOCTRL0_BASE_ADDR + 0x9c, 0, ulTemp );

    /*等1us，在执行其他操作*/
    osSerdesWait(0x1000);
}

/*****************************************************************
函数名 :  osSerdes1Read
输入参数    :  ulPage  : 3bit
              ulType    : 1 bit
              ulOffset  :12 bit
输出参数      :     value : 8bit
Description   :

Author        :  z00228490
Creation time :  2012/12/30
*****************************************************************/
UINT32 osSerdes1Read( UINT32 ulPage, UINT32 ulType, UINT32 ulOffset )
{
    UINT32 ulTemp = 0;
    UINT32 ulRdata = 0;
    INT32 ulLoop = SREDES_LOOP_TIME;
    UINT32 ulStepChoose = 0;

    /*write addr[ioctrl0_base_addr+0x9c],data[bit31-27=all 0,bit26=0,bit25=1,*/
    /*bit24=0,bit23-16=all 0,bit15-13=x1,bit12=x2,bit11-0=x3]*/
    ulTemp = ( ( ulTemp | 0x2000000 ) | \
               ( ulOffset & 0xfff) | ( ulType << 12 ) | ( ulPage << 13 ) );
    OS_SDS_WRITE_REG( IOCTRL0_BASE_ADDR + 0x9c, 0, ulTemp );

    /*write addr[ioctrl0_base_addr+0x9c], data[bit31-27=all 0,bit26=0,*/
    /*bit25=0,bit24=0,bit23-16=all 0,bit15-13=x1,bit12=x2,bit11-0=x3]*/
    OS_SDS_WRITE_REG( IOCTRL0_BASE_ADDR + 0x9c, 0, ulTemp & 0xFDFFFFFF );

    /*第3步：read addr[ioctrl0_base_addr+0x42c], 回读的数据为rdata*/
    ulRdata = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x42c, 0 );
    /*第4步：如果第3步中rdata[bit8==0],回到第3步；如果1ms内，*/
    /*rdata[bit8==1],走到第5步；如果超过1ms后，直接走到第6步*/
    while ( --ulLoop )
    {
        if ( 0x100 == ( ulRdata & 0x100 ) )
        {
            ulStepChoose = 5;
            break;
        }
        else
        {
            ulRdata = OS_READ_REG( IOCTRL0_BASE_ADDR + 0x42c, 0 );
        }
    }

    if(gulDebugOpen)
    {

        if ( 5 == ulStepChoose )
        {
            SRE_printf( "serdes2 read ok page=%x sel=%x offset=%x rdata=%x", ulPage, ulType, ulOffset, ulRdata );
        }
    }
    if ( ulLoop <= 0 )
    {
        SRE_printf( "serdes2 read outoftime page=%x sel=%x offset=%x", ulPage, ulType, ulOffset );
    }
    /*第7步：write addr[ioctrl0_base_addr+0x9c],*/
    /*data[bit31-27=all 0,bit26=1,bit25=0,bit24=0,bit23-16=all 0,bit15-13=x1,*/
    /*bit12=x2,bit11-0=x3]*/
    ulTemp = 0;
    ulTemp = ( ulTemp | 0x4000000 ) | ( ulPage << 13 ) | ( ulType << 12 ) | ( ulOffset & 0xfff );
    OS_SDS_WRITE_REG( IOCTRL0_BASE_ADDR + 0x9c, 0, ulTemp );

    return ulRdata & 0x1FF;
}

/*****************************************************************
函数名 :  osSerdes2Write
输入参数    :  ulPage  :3bit
              ulType  : 1bit
              ulOffset :12 bit
              ulValue  :8 bit
输出参数      :
Description   :

Author        :  z00228490
Creation time :  2012/12/28
*****************************************************************/
void osSerdes2Write( UINT32 ulPage, UINT32 ulType, UINT32 ulOffset, UINT32 ulValue )
{
    /*1、:write addr[ioctrl1_base_addr+0x48],data[bit31-27=all 0,*/
    /*bit26=0,bit25=1,bit24=1,bit23-16=x4,bit15-13=x1,bit12=x2,bit11-0=x3]*/
    UINT32 ulTemp = 0;
    UINT32 ulRdata = 0;
    INT32 ulLoop = SREDES_LOOP_TIME;
    UINT32 ulStepChoose = 0;
    ulTemp = ( ( ulTemp | 0x3000000 ) | ( ulValue << 16 ) | \
               ( ulOffset & 0xfff ) | ( ulType << 12 ) | ( ulPage << 13 ) );
    OS_SDS_WRITE_REG( IOCTRL1_BASE_ADDR + 0x48, 0, ulTemp );

    /*2:write addr[ioctrl1_base_addr+0x48],*/
    /*data[bit31-27=all 0,bit26=0,bit25=0,bit24=1,*/
    /*bit23-16=x4,bit15-13=x1,bit12=x2,bit11-0=x3]*/
    OS_SDS_WRITE_REG( IOCTRL1_BASE_ADDR + 0x48, 0, ulTemp & 0xFDFFFFFF );

    /*第3步：read addr[ioctrl1_base_addr+0x428], 回读的数据为rdata*/
    ulRdata = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x428, 0 );
#if SERDES_DEBUG_OPEN
    SRE_printf( "check IOCTRL1_BASE_ADDR + 0x428 == 0x100\n" );
#else
    /*第4步：如果第3步中rdata[bit8==0],回到第3步；如果1ms内，*/
    /*rdata[bit8==1],走到第5步；如果超过1ms后，直接走到第6步*/
    while ( --ulLoop )
    {
        if ( 0x100 == ( ulRdata & 0x100 ) )
        {
            ulStepChoose = 5;
            break;
        }
        else
        {
            ulRdata = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x428, 0 );
        }
    }
#endif
    if(gulDebugOpen)
    {

        if ( 5 == ulStepChoose )
        {
            SRE_printf( "serdes2 read ok page=%x sel=%x offset=%x rdata=%x", ulPage, ulType, ulOffset, ulRdata );
        }
    }
    if ( ulLoop <= 0 )
    {
        SRE_printf( "serdes2 read outoftime page=%x sel=%x offset=%x", ulPage, ulType, ulOffset );
    }
    /*第7步：write addr[ioctrl1_base_addr+0x48],*/
    /*data[bit31-27=all 0,bit26=1,bit25=0,bit24=1,bit23-16=x4,bit15-13=x1,*/
    /*bit12=x2,bit11-0=x3]*/
    ulTemp = 0;
    ulTemp = ( ulTemp | 0x5000000 ) | ( ulPage << 13 ) | ( ulType << 12 ) | ( ulOffset & 0xfff ) | (ulValue << 16);
    OS_SDS_WRITE_REG( IOCTRL1_BASE_ADDR + 0x48, 0, ulTemp );

    osSerdesWait(1000);

}

/*****************************************************************
函数名 :  osSerdes2Read
输入参数    :  ulPage  :3bit
              ulType  : 1bit
              ulOffset :12 bit

输出参数      :  ulValue  :8 bit
Description   :

Author        :  z00228490
Creation time :  2012/12/28
*****************************************************************/
UINT32 osSerdes2Read( UINT32 ulPage, UINT32 ulType, UINT32 ulOffset )
{
    /*1、:write addr[ioctrl1_base_addr+0x48],data[bit31-27=all 0,*/
    /*bit26=0,bit25=1,bit24=0,bit23-16 all 0,bit15-13=x1,bit12=x2,bit11-0=x3]*/
    UINT32 ulTemp = 0;
    UINT32 ulRdata = 0;
    INT32 ulLoop = SREDES_LOOP_TIME;
    UINT32 ulStepChoose = 0;
    ulTemp = ( ( ulTemp | 0x2000000 )  | \
               ( ulOffset ) | ( ulType << 12 ) | ( ulPage << 13 ) );
    OS_SDS_WRITE_REG( IOCTRL1_BASE_ADDR + 0x48, 0, ulTemp );

    /*2:write addr[ioctrl1_base_addr+0x48],*/
    /*data[bit31-27=all 0,bit26=0,bit25=0,bit24=0,*/
    /*bit23-16 all 0,bit15-13=x1,bit12=x2,bit11-0=x3]*/
    OS_SDS_WRITE_REG( IOCTRL1_BASE_ADDR + 0x48, 0, ulTemp & 0xFDFFFFFF );

    /*第3步：read addr[ioctrl1_base_addr+0x428], 回读的数据为rdata*/
    ulRdata = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x428, 0 );

    /*第4步：如果第3步中rdata[bit8==0],回到第3步；如果1ms内，*/
    /*rdata[bit8==1],走到第5步；如果超过1ms后，直接走到第6步*/
    while (--ulLoop )
    {
        if ( 0x100 == ( ulRdata & 0x100 ) )
        {
            ulStepChoose = 5;
            break;
        }
        else
        {
            ulRdata = OS_READ_REG( IOCTRL1_BASE_ADDR + 0x428, 0 );
        }
    }

    if(gulDebugOpen)
    {
        if ( 5 == ulStepChoose )
        {
             SRE_printf( "serdes2 read ok page=%x sel=%x offset=%x rdata=%x", ulPage, ulType, ulOffset, ulRdata );
        }
    }
    if ( ulLoop <= 0 )
    {
        SRE_printf( "serdes2 read outoftime page=%x sel=%x offset=%x", ulPage, ulType, ulOffset );
    }
    /*第7步：write addr[ioctrl1_base_addr+0x48],*/
    /*data[bit31-27=all 0,bit26=1,bit25=0,bit24=0,bit23-16=all 0,bit15-13=x1,*/
    /*bit12=x2,bit11-0=x3]*/
    ulTemp = 0;
    ulTemp = ( ulTemp | 0x4000000 ) | ( ulPage << 13 ) | ( ulType << 12 ) | ( ulOffset & 0xfff );
    OS_SDS_WRITE_REG( IOCTRL1_BASE_ADDR + 0x48, 0, ulTemp );

    osSerdesWait(1000);

    return ulRdata & 0x1FF;
}



void osSerdes3Write( UINT32 ulAddr, UINT32 ulValue )
{
    /*Write addr[serdes3_base_addr +x1],data[bit31-0=x2]*/
    OS_SDS_WRITE_REG( SERDES3_BASE_ADDR + ulAddr, 0, ulValue );
}

UINT32 osSerdes3Read( UINT32 ulAddr )
{
    return OS_READ_REG( SERDES3_BASE_ADDR + ulAddr, 0 );
}

void osIoCtrl0Write( UINT32 ulAddr, UINT32 ulValue )
{
    OS_SDS_WRITE_REG( IOCTRL0_BASE_ADDR + ulAddr, 0, ulValue );
}

UINT32 osIoCtrl0Read( UINT32 ulAddr )
{
    return OS_READ_REG( IOCTRL0_BASE_ADDR + ulAddr, 0 );
}

void osIoCtrl1Write( UINT32 ulAddr, UINT32 ulValue )
{
    OS_SDS_WRITE_REG( IOCTRL1_BASE_ADDR + ulAddr, 0, ulValue );
}

UINT32 osIoCtrl1Read( UINT32 ulAddr )
{
    return OS_READ_REG( IOCTRL1_BASE_ADDR + ulAddr, 0 );
}

void osSysCtrlWrite( UINT32 ulAddr, UINT32 ulValue )
{
    OS_SDS_WRITE_REG( SYSCTRL_BASE_ADDR + ulAddr, 0, ulValue );
}

UINT32 osSysCtrlRead( UINT32 ulAddr )
{
    return OS_READ_REG( SYSCTRL_BASE_ADDR + ulAddr, 0 );
}

void    OS_SDS_WRITE_REG ( UINT32 pRegBase, UINT32 ulRegIndex, UINT32  ulValue )
{
#if  SERDES_DEBUG_OPEN
    SRE_printf( "addr:0x%8x,ulValue:0x%8x\n", pRegBase, ulValue );
#else
    OS_WRITE_REG( pRegBase, ulRegIndex, ulValue );
#endif
}

void  osSerdesDebugOn(void)
{
    gulDebugOpen = 1;
}

void  osSerdesDebugOff(void)
{
    gulDebugOpen = 0;
}


