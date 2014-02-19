/**
 * @file SRE_errno.h
 *
 * Copyright(C), 2008-2050, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. \n
 *
 * 描述：通用错误码定义头文件。 \n
 */

/**
 * @addtogroup SRE_err  错误处理
 * @ingroup SRE_inspect
 * @{
*/

#ifndef _SRE_ERRNO_H
#define _SRE_ERRNO_H

#include "SRE_base.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#define SRE_ErrHandle(pcFileName, uwLineNo, uwErrorNo, uwPara1, uwPara2) \
    SRE_printf("%s,%d:%#x,%#x,%#x\n", pcFileName, uwLineNo, uwErrorNo, uwPara1, uwPara2);

#define SRE_DotSet(pcFileName, uwLineNo, uwPara1, uwPara2) \
    SRE_printf("%s,%d:%#x,%#x\n", pcFileName, uwLineNo, uwPara1, uwPara2)

/* 0x00表示OS,0xFF表示DRV,应用系统可以使用 1~254 来标示应用各个子系统 */
#define SRE_ERRNO_OS_ID                                     ((UINT32)0x00 << 16)

/* 定义错误的等级 */
#define SRE_ERRTYPE_NORMAL                                  ((UINT32)0x00 << 24)
#define SRE_ERRTYPE_WARN                                    ((UINT32)0x01 << 24)
#define SRE_ERRTYPE_ERROR                                   ((UINT32)0x02 << 24)
#define SRE_ERRTYPE_FATAL                                   ((UINT32)0x03 << 24)

/**
 * @brief 定义OS致命错误
 *
 * @description
 * 宏定义，定义OS致命错误
 *
 * @attention 无

 * @param[in]   MID 模块ID编号。
 * @param[in]   ERRNO 错误码编号。
 *
 * @retval 无
 * @depend
 * SRE_errno.h: 该宏定义所在的头文件。
 * @since SRE V100R001
 * @see SRE_ERRNO_OS_ERROR | SRE_ERRNO_OS_WARN | SRE_ERRNO_OS_NORMAL
 */
#define SRE_ERRNO_OS_FATAL(MID,ERRNO)   \
            (SRE_ERRNO_OS_ID | ((UINT32)(MID) << 8) | SRE_ERRTYPE_FATAL | (ERRNO))


/**
 * @brief 定义OS严重错误
 *
 * @description
 * 宏定义，定义OS严重错误
 *
 * @attention 无
 * @param[in]   MID 模块ID编号。
 * @param[in]   ERRNO 错误码编号。
 *
 * @retval 无
 * @depend
 * SRE_errno.h: 该宏定义所在的头文件。
 * @since SRE V100R001
 * @see SRE_ERRNO_OS_FATAL | SRE_ERRNO_OS_WARN | SRE_ERRNO_OS_NORMAL
 */
#define SRE_ERRNO_OS_ERROR(MID,ERRNO)  \
            (SRE_ERRNO_OS_ID | ((UINT32)(MID) << 8) | SRE_ERRTYPE_ERROR | (ERRNO))


/**
 * @brief 定义OS告警信息
 *
 * @description
 * 宏定义，定义OS告警
 *
 * @attention 无
 * @param[in]   MID 模块ID编号。
 * @param[in]   ERRNO 错误码编号。
 *
 * @retval 无
 * @depend
 * SRE_errno.h: 该宏定义所在的头文件。
 * @since SRE V100R001
 * @see SRE_ERRNO_OS_FATAL | SRE_ERRNO_OS_ERROR | SRE_ERRNO_OS_NORMAL
 */
#define SRE_ERRNO_OS_WARN(MID,ERRNO)  \
            (SRE_ERRNO_OS_ID | ((UINT32)(MID) << 8) | SRE_ERRTYPE_WARN | (ERRNO))


/**
 * @brief 定义OS提示信息
 *
 * @description
 * 宏定义，定义OS提示信息
 *
 * @attention 无
 * @param[in]   MID 模块ID编号。
 * @param[in]   ERRNO 错误码编号。
 *
 * @retval 无
 * @depend
 * @li SRE_errno.h: 该宏定义所在的头文件。
 * @since SRE V100R001
 * @see SRE_ERRNO_OS_FATAL | SRE_ERRNO_OS_ERROR | SRE_ERRNO_OS_WARN
 */
#define SRE_ERRNO_OS_NORMAL(MID,ERRNO)  \
        (SRE_ERRNO_OS_ID | ((UINT32)(MID) << 8) | SRE_ERRTYPE_NORMAL | (ERRNO)); \


/**
*@brief 错误信息记录
*
*@description
*记录出错信息
*
*@attention  无
*
*@param[in] uwErrLine,类型#UINT32 出错行号
*@param[in] uwErrNo,  类型#UINT32 错误编号
*@param[in] uwPara1,  类型#UINT32 记录信息1
*@param[in] uwPara2,  类型#UINT32 记录信息2
*
*@retval 无
*@depend
*@li SRE_errno.h
*@since SRE V100R001
*@see SRE_ErrHandle
*/
#define REPORT_ERROR(uwErrLine, uwErrNo, uwPara1, uwPara2)  \
    SRE_MACRO_S \
        SRE_ErrHandle(__FILE__, uwErrLine, uwErrNo, (UINT32)(uwPara1), (UINT32)(uwPara2)); \
    SRE_MACRO_E

/**
*@brief 错误信息记录并返回错误编号
*
*@description
*遇到异常时记录错误发生地点和附加信息，\n
*并返回错误编号
*
*@attention 无
*
*@param[in] uwErrLine,类型#UINT32 出错行号
*@param[in] uwErrNo,  类型#UINT32 错误编号
*@param[in] uwPara1,  类型#UINT32 记录信息1
*@param[in] uwPara2,  类型#UINT32 记录信息2
*
*@retval uwErrNo,类型#UINT32 错误编号
*@depend
*@li SRE_errno.h
*@since SRE V001R001
*@see SRE_ErrHandle
*/
#define RETURN_ERROR(uwErrLine, uwErrNo, uwPara1, uwPara2) \
    SRE_MACRO_S \
        SRE_ErrHandle(__FILE__, uwErrLine, uwErrNo, (UINT32)(uwPara1), (UINT32)(uwPara2)); \
        \
        return uwErrNo; \
    SRE_MACRO_E

/**
*@brief 错误跳转
*@description
*错误发生时记录错误信息，并跳转到错误执行处#ErrHandler
*
*@attention
*@li 本语句只适合多异常分支的情形，以减少代码尺寸
*@li 使用本宏的函数必须定义局部变量uwErrNo类型UINT32,uwErrLine类型UINT32,
*uwPara1类型UINT32,uwPara2类型UINT32
*
*@param[in] uwErrNo,  类型#UINT32 错误编号
*@param[in] uwP1,  类型#UINT32 记录信息1
*@param[in] uwP2,  类型#UINT32 记录信息2
*
*@depend
*@li SRE_errno.h
*@since SRE V001R001
*@see 无
*/
#define GOTO_ERR_HANDLER(uwErrorNo, uwP1, uwP2) \
    SRE_MACRO_S \
        uwErrNo    = uwErrorNo; \
        uwErrLine  = __LINE__; \
        uwPara1 = (UINT32)(uwP1); \
        uwPara2 = (UINT32)(uwP2); \
        goto ErrHandler; \
    SRE_MACRO_E

/**
*@brief 记录初始化打点信息
*@description
*记录初始化打点信息；如果系统日志已初始化成功，同时记录日志信息
*
*@attention
*
*@param[in] uwP1,  类型#UINT32 打点信息1
*@param[in] uwP2,  类型#UINT32 打点信息2
*
*@depend
*@li SRE_errno.h
*@since SRE V001R001
*@see 无
*/
#define SRE_INIT_DOT(uwP1, uwP2) \
    SRE_MACRO_S \
        SRE_DotSet(__FILE__, __LINE__, (uwP1), (uwP2));\
    SRE_MACRO_E

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#endif /* _SRE_ERRNO_H */

/**
 * @}
*/

/**
 * History:
 *
 * vi: set expandtab ts=4 sw=4 tw=80:
*/

