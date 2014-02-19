/*******************************************************************
              Copyright 2007 - 2011, Huawei Tech. Co., Ltd.
                      ALL RIGHTS RESERVED

Filename      : SRE_serdes.h
Author        : z00228490
Creation time : 2012/12/27
Description   :
                 serdes 驱动头文件
Version       : 1.0
********************************************************************/

#include "SRE_drv.h"

#ifndef _SRE_SERDES_H_
#define _SRE_SERDES_H_

extern UINT32 SRE_SerdesInit(VOID);

/*serdes 可以复用类型*/
typedef enum  enSerdesInitType
{
    GE,
    XGE_XAUI,
    XGE_SFI,
    SRIO,
    PCIE,
    SATA,
    NOT_USED     //未使用
}SRE_SERDES_INIT_TYPE;


/*serdes 典型速率*/
typedef enum  enSerdesSpeed
{
    S1G25,
    S1G5,
    S2G5,
    S3G,
    S3G125,
    S5G,
    S6G,
    S6G25,
    S8G,
    S10G3125
}SRE_SERDES_SPEED;


typedef struct tarSerdesCfg
{
    SRE_SERDES_INIT_TYPE enSerdes0InitType;
    SRE_SERDES_INIT_TYPE enSerdes1InitType;
    SRE_SERDES_INIT_TYPE enSerdes2InitType;
    SRE_SERDES_INIT_TYPE enSerdes3InitType;
    SRE_SERDES_SPEED    enSerdes0Speed;
    SRE_SERDES_SPEED    enSerdes1Speed;
    SRE_SERDES_SPEED    enSerdes2Speed;
    SRE_SERDES_SPEED    enSerdes3Speed;
}SRE_SERDES_CFG;

extern int serdes_init(void);
extern void serdes_exit(void);

#endif /* _SRE_SERDES_H_ */

