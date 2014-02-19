
 /******************************************************************************
  文 件 名   : sre_rawmutex.h
  版 本 号   : 初稿
  作    者   : z00202155
  生成日期   : 2012年1月11日
  最近修改   :
  功能描述   : SRESS 原生互斥体管理 模块 API
  函数列表   :
  修改历史   :
  1.日    期   : 2012年1月11日
    作    者   : z00202155
    修改内容   : 创建文件

******************************************************************************/

#ifndef __SRE_RAWMUTEX_H__
#define __SRE_RAWMUTEX_H__

//#include "SRE_drv.h"


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


/*
 * 本模块错误码定义
 */
/**
 * @ingroup SRE_RawMutex
 * 日志错误码：原生互斥体最大参数输入错误
 * 值: 0x02003100
 * 解决方法: 调用SRE_InitRawMutex函数时，确保uwMaxItem参数正确
 */
#define OS_ERRNO_RAWMUTEX_MaxItem_ERR                   SRE_ERRNO_OS_ERROR(OS_MID_RAWMUTEX, 0x00)

/**
 * @ingroup SRE_RawMutex
 * 日志错误码：锁入队失败
 * 值: 0x02003101
 * 解决方法: 检查函数参数输入
 */
#define OS_ERRNO_RAWMUTEX_DESCPUSH_ERR                   SRE_ERRNO_OS_ERROR(OS_MID_RAWMUTEX, 0x01)

/**
 * @ingroup SRE_RawMutex
 * 日志错误码：出队失败
 * 值: 0x02003102
 * 解决方法: 检查函数参数输入
 */
#define OS_ERRNO_RAWMUTEX_DescPop_ERR                   SRE_ERRNO_OS_ERROR(OS_MID_RAWMUTEX, 0x02)

/**
 * @ingroup SRE_RawMutex
 * 日志错误码：输入原生互斥体序号不合法
 * 值: 0x02003103
 * 解决方法: 检查函数参数输入
 */
#define OS_ERRNO_RAWMUTEX_INDEX_ERR                   SRE_ERRNO_OS_ERROR(OS_MID_RAWMUTEX, 0x03)

/**
 * @ingroup SRE_RawMutex
 * 日志错误码：输入原生互斥体配置结构体指针为空
 * 值: 0x02003104
 * 解决方法: 检查函数参数输入
 */
#define OS_ERRNO_RAWMUTEX_PTRNULL_ERR                   SRE_ERRNO_OS_ERROR(OS_MID_RAWMUTEX, 0x04)

/**
 * @ingroup SRE_RawMutex
 * 日志错误码：原生互斥体初始化清空队列失败
 * 值: 0x02003105
 * 解决方法:
 */
#define OS_ERRNO_RAWMUTEX_EMPTYQUE_FAIL_ERROR            SRE_ERRNO_OS_ERROR(OS_MID_RAWMUTEX, 0x05)


/* 原生互斥体结构 */
typedef struct tagMcRawMutex
{
    volatile UINT32 stRawSpin;      /* 原生自旋锁的值 */
    volatile UINT32 uwFlag;         /* 初始化完成标志 */
} SRE_RAWMUTEX_S;

/* 需要申请使用一个原生锁的时候，就在这里添加一个宏定义就可以了，*/
/* 使用的时候用这个宏定义的数值作为数组的下标作索引就好了。*/
typedef enum tagRawMutexId
{
    MOD_TBL_INITSAFE_LOCK_SYS_1,                /* 0 */
    MOD_TBL_INITSAFE_LOCK_SYS_2,
    MOD_REGISTER_INITSAFE_LOCK,
    MEM_POOL_HW_INIT_LOCK,
    BLOCK_MEM_HEAD_INIT_LOCK_POOL0,

    BLOCK_MEM_HEAD_INIT_LOCK_POOL1,             /* 5 */
    BLOCK_MEM_HEAD_INIT_LOCK_POOL2,
    BLOCK_MEM_HEAD_INIT_LOCK_POOL3,
    BLOCK_MEM_HEAD_INIT_LOCK_POOL4,
    BLOCK_MEM_HEAD_INIT_LOCK_POOL5,

    BLOCK_MEM_HEAD_INIT_LOCK_POOL6,             /* 10 */
    BLOCK_MEM_HEAD_INIT_LOCK_POOL7,
    BLOCK_MEM_HEAD_INIT_LOCK_POOL8,
    BLOCK_MEM_HEAD_INIT_LOCK_POOL9,
    BLOCK_MEM_HEAD_INIT_LOCK_POOL10,

    BLOCK_MEM_HEAD_INIT_LOCK_POOL11,            /* 15 */
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL0,
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL1,
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL2,
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL3,

    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL4,         /* 20 */
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL5,
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL6,
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL7,
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL8,

    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL9,         /* 25 */
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL10,
    BLOCK_MEM_PUB_POOL_INIT_LOCK_POOL11,
    BYTE_MEM_MONITOR_STRUCT_INIT_LOCK,
    PUB_BYTE_MEM_ADMIN_STRUCT_INIT_LOCK_POOL0,

    PUB_BYTE_MEM_ADMIN_STRUCT_INIT_LOCK_POOL1,  /* 30 */
    PUB_BYTE_MEM_ADMIN_STRUCT_INIT_LOCK_POOL2,
    PUB_BYTE_MEM_ADMIN_STRUCT_INIT_LOCK_POOL3,
    PUB_BYTE_MEM_ADMIN_STRUCT_INIT_LOCK_POOL4,
    PUB_BYTE_MEM_ADMIN_STRUCT_INIT_LOCK_POOL5,

    PUB_BYTE_MEM_ADMIN_STRUCT_INIT_LOCK_POOL6,  /* 35 */
    PUB_BYTE_MEM_ADMIN_STRUCT_INIT_LOCK_POOL7,
    SPINLOCK_INIT_LOCK,
    SPINLOCK_INIT_LOCK_SYS_1,
    SPINLOCK_INIT_LOCK_SYS_2,

    NETWORK_PORT_INIT_LOCK,                     /* 40 */
    NETWORK_PORT_INIT_LOCK_1,
    NETWORK_PORT_INIT_LOCK_2,
    SRE_FAU_INITSAFE_LOCK,
    SRE_LOCAL_MEMEORY_INITSAFE_LOCK,

    SRE_SYSLOG_INITSAFE_LOCK,                    /* 45 */
    SRE_TIMER_INITSAFE_LOCK,
    SRE_CRC_INITSAFE_LOCK,
    SRE_CACHE_INITSAFE_LOCK,
    SRE_CLUSTER0_CACHE_INITSAFE_LOCK,

    SRE_CLUSTER1_CACHE_INITSAFE_LOCK,            /* 50 */
    SRE_TIMEBASE_INITSAFE_LOCK,
    SRE_POEINIT_INITSAFE_LOCK,
    SRE_GIC_INITSAFE_LOCK,
    SRE_BLACKBOX_INITSAFE_LOCK,

    SRE_POETEST_INITSAFE_LOCK,                   /* 55 */
    SRE_QMUINIT_INITSAFE_LOCK,
    SRE_QMUTEST_INITSAFE_LOCK,
    SRE_SYSSNAP_INITSAFE_LOCK,
    SRE_STAT_INITSAFE_LOCK,

    SRE_HDCP_INITSAFE_LOCK,                      /* 60 */
    SRE_SYSCTL_INITSAFE_LOCK,
    SRE_BLKMEM_ALARM_INITSAFE_LOCK,
    SRE_BLKBOX_INITSAFE_LOCK,
    SRE_TIMER_INIT_LOCK_CLUSTER_A,

    SRE_TIMER_INIT_LOCK_CLUSTER_B,               /* 65 */
    SRE_DWTH_INITSAFE_LOCK,
    SRE_BLOG_INIT_LOCK,
    SRE_DMA_INIT_LOCK,
    SRE_DYNAMIC_INITSAGE_LOCK,

    SRE_TIMER_HW_INITSAFE_LOCK,                  /* 70 */
    SRE_GMAC_ENABLE_ALL_INITSAFE_LOCK,
    SRE_GDB_INITSAFE_LOCK,
    SRE_QTIMER_INITSAFE_LOCK_CLUSTER_A,
    SRE_QTIMER_INITSAFE_LOCK_CLUSTER_B,

    SRE_DMA_INITSAFE_LOCK,                       /* 75 */
    SRE_HWTIMER_INITSAFE_A_LOCK,
    SRE_HWTIMER_INITSAFE_B_LOCK,
    SRE_SEC_INITSAFE_LOCK,
    SRE_ROHC_INITSAFE_LOCK,

    SRE_POU_INIT_LOCK,                          /* 80 */
    SRE_CLUSTER0_MF_INITSAFE_LOCK,
    SRE_CLUSTER1_MF_INITSAFE_LOCK,
    SRE_CPU_STATUS_RESET_LOCK,
    SRE_CPU_RATE_INIT_LOCK,

    SRE_CPU_HEARTBEAT_INIT_LOCK,                /* 85 */
    SRE_PRINT_INIT_LOCK,
    SRE_BLKMEM_SNAP_INIT_LOCK,
    SRE_NETDRV_SNAP_INIT_LOCK,
    SRE_SPINLOCK_SNAP_INIT_LOCK,

    SRE_BMU_SETUPPOOL_LOCK,                       /* 90 */
    SRE_TM_INITSAFE_LOCK,
    SRE_SCH_INITSAFE_LOCK,
    SRE_DLHDCP_INITSAFE_LOCK,
	SRE_AQM_INITSAFE_LOCK,

    SRE_ULHDCP_INITSAFE_LOCK,                   /* 95 */
/* BEGIN: Added by wangming 2012/11/14 */
    SRE_BPSS_INITSAFE_LOCK,
    SRE_MACE_INITSAFE_LOCK,
    SRE_FP_INITSAFE_LOCK,
    SRE_PDM_INITSAFE_LOCK,
    SRE_PMM_INITSAFE_LOCK,
    SRE_SORT_INITSAFE_LOCK,
    SRE_JSPCPF_INITSAFE_LOCK,
    SRE_JSPCPC_INITSAFE_LOCK,
    SRE_VMIMO_INITSAFE_LOCK,
    SRE_RESM_INITSAFE_LOCK,
    SRE_CQI_INITSAFE_LOCK,
    SRE_DRX_INITSAFE_LOCK,
    SRE_TRACE_INITSAFE_LOCK,
    SRE_PDCFG_INITSAFE_LOCK,
    SRE_BDM_INITSAFE_LOCK,
    SRE_SERDES_INITSAFE_LOCK,
    SRE_SPI_INITSAFE_LOCK,
    SRE_SPPEINIT_INITSAFE_LOCK,
    SRE_TSINIT_INITSAFE_LOCK,
    SRE_MPE_INITSAFE_LOCK,                  /*115 */

/* END: Added by wangming 2012/11/14 */
    /* MAX_RAWMUTEX_LOCK_NUMBER 必须放在最后，作为整个枚举变量个数的统计 */
    MAX_RAWMUTEX_LOCK_NUMBER = 128

}SRE_RAWMUTEX_ID_ENUM;

/*原生互斥体配置结构体*/
typedef struct tagMcRawMutexHwQueueCfg
{
    void *pBaseMem;     /* 管理内存基址 */
    UINT32 ulMaxItem;  /* 管理最大索引 */
} SRE_RAWMUTEX_HW_QUEUE_CFG_S;

#if 0
/*
* 对外接口函数
*/
/*****************************************************************************
 函 数 名  : SRE_RawMutexRegister
 功能描述  : RawMutex模块配置注册函数
 输入参数  : SRE_RAWMUTEX_HW_QUEUE_CFG_S *stRawMutesQueCfg
 输出参数  :
 返 回 值  : OS_SUCCESS 成功
             其他 失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年1月11日
    作    者   : z00202155
    修改内容   : 新生成函数
*****************************************************************************/
extern UINT32 SRE_RawMutexRegister(SRE_RAWMUTEX_HW_QUEUE_CFG_S *stRawMutesQueCfg);

/*****************************************************************************
 函 数 名  : SRE_InitRawMutex
 功能描述  : RawMutex模块配置初始化
 输入参数  : 无
 输出参数  : 无
 返 回 值  : OS_SUCCESS 成功
             其他 失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年1月11日
    作    者   : z00202155
    修改内容   : 新生成函数

*****************************************************************************/
extern UINT32 SRE_InitRawMutex(void);
#endif
/*****************************************************************************
 函 数 名  : SRE_RawMutexProtect
 功能描述  : 获取原生互斥体保护
 输入参数  : UINT32 uwRawMutexIndex
 输出参数  : 无
 返 回 值  : OS_SUCCESS 成功
             其他 失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月11日
    作    者   : z00202155
    修改内容   : 新生成函数

*****************************************************************************/
//extern UINT32 SRE_RawMutexProtect(UINT32 uwRawMutexIndex);
#define SRE_RawMutexProtect(uwRawMutexIndex) 0  /* 以下定义仅用于规避对SRE原有代码的修改，无实际意义 */

/*****************************************************************************
 函 数 名  : SRE_RawMutexUnProtect
 功能描述  : 释放原生互斥体保护
 输入参数  : UINT32 uwRawMutexIndex
 输出参数  : 无
 返 回 值  : OS_SUCCESS 成功
             其他 失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月11日
    作    者   : z00202155
    修改内容   : 新生成函数

*****************************************************************************/
//extern UINT32 SRE_RawMutexUnProtect(UINT32 uwRawMutexIndex);
#define SRE_RawMutexUnProtect(uwRawMutexIndex) 0    /* 以下定义仅用于规避对SRE原有代码的修改，无实际意义 */

/*****************************************************************************
 函 数 名  : SRE_RawMutexSetFlag
 功能描述  : 设置原生互斥体初始化完成标志
 输入参数  : UINT32 uwRawMutexIndex
 输出参数  : 无
 返 回 值  : OS_SUCCESS 成功
             其他 失败
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月11日
    作    者   : z00202155
    修改内容   : 新生成函数

*****************************************************************************/
//extern UINT32 SRE_RawMutexSetFlag(UINT32 uwRawMutexIndex);
#define SRE_RawMutexSetFlag(uwRawMutexIndex) 0  /* 以下定义仅用于规避对SRE原有代码的修改，无实际意义 */

/*****************************************************************************
 函 数 名  : SRE_RawMutexGetFlag
 功能描述  : 获取原生互斥体初始化完成标志
 输入参数  : UINT32 uwRawMutexIndex
 输出参数  : 无
 返 回 值  : 0 -- 互斥体未使用
             1 -- 互斥体已使用
 调用函数  :
 被调函数  :

 修改历史  :
   1.日    期   : 2012年1月11日
     作    者   : z00202155
     修改内容   : 新生成函数


*****************************************************************************/
//extern UINT32 SRE_RawMutexGetFlag(UINT32 uwRawMutexIndex);
#define SRE_RawMutexGetFlag(uwRawMutexIndex) 0  /* 以下定义仅用于规避对SRE原有代码的修改，无实际意义 */

#define SRE_RawMutexClearFlag(uwRawMutexIndex) 0    /* 以下定义仅用于规避对SRE原有代码的修改，无实际意义 */

#if 0
/* 本模块编译宏,在极度追求效率的情形下可去掉 */
#define SRE_RAWMUTEX_CHECK
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __SRE_RAWMUTEX_H__ */
