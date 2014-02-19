/**
 * @file SRE_typedef.h
 *
 * Copyright(C), 2008-2050, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. \n
 *
 * 描述：定义基本数据类型和数据结构。 \n
 */

/**
 * @addtogroup SRE_sys 系统基本功能接口
 * @ingroup
 * @{
*/

#ifndef _SRE_TYPEDEF_H
#define _SRE_TYPEDEF_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#ifdef SRE_WIN
#include <windows.h>
#include <mmsystem.h>
#include <malloc.h>
#include <stdio.h>

#define INLINE                                              static __inline
#else
#if 1
#define EXPR_STAT_NOT_SUPPORT
#define INLINE                                              static __inline
#else
#define INLINE                                              static inline
#endif
#endif



#ifdef EXPR_STAT_NOT_SUPPORT
#define SRE_MACRO_S  do{
#define SRE_MACRO_E  }while(0)
#else
/* 编译器支持语句表达式时，使用以下宏，提高代码覆盖率 */
#define SRE_MACRO_S  \
    /*lint -save -e160 -e522 */ \
    ({
#define SRE_MACRO_E  \
    }) \
    /*lint -restore */
#endif

#ifndef SRE_TYPE_DEF
#define SRE_TYPE_DEF

/* type definitions */
#ifdef SRE_WIN
typedef unsigned __int64                                    UINT64;
typedef signed   __int64                                    INT64;
typedef unsigned int                                        UINTPTR;
typedef signed int                                          INTPTR;
typedef unsigned short                                      UINT16;
typedef unsigned int                                        UINT32;
typedef unsigned char                                       UINT8;
typedef signed char                                         INT8;
typedef signed short                                        INT16;
typedef signed int                                          INT32;
typedef float                                               FLOAT;
typedef double                                              DOUBLE;
typedef char                                                CHAR;
#else
typedef unsigned char                                       UINT8;
typedef unsigned short                                      UINT16;
typedef unsigned int                                        UINT32;
typedef signed short                                        INT16;
typedef signed int                                          INT32;
typedef float                                               FLOAT;
typedef double                                              DOUBLE;
typedef char                                                CHAR;
typedef unsigned long long                                  UINT64;
typedef signed long long                                    INT64;
typedef unsigned int                                        UINTPTR;
typedef signed int                                          INTPTR;
typedef unsigned int                                        BOOL;
typedef signed char                                         INT8;
#endif

#define VOID                                                void

#endif  /*end of #ifndef SRE_TYPE_DEF*/

#ifndef FALSE
#define FALSE                                               ((BOOL)0)
#endif

#ifndef TRUE
#define TRUE                                                ((BOOL)1)
#endif

#ifndef NULL
#define NULL                                                ((VOID *)0)
#endif

#ifdef  YES
#undef  YES
#endif
#define YES                                                 (1)

#ifdef  NO
#undef  NO
#endif
#define NO                                                  (0)

#define OS_NULL_BYTE                                        ((UINT8)0xff)
#define OS_NULL_SHORT                                       ((UINT16)0xffff)
#define OS_NULL_INT                                         ((UINT32)0xffffffff)
#define OS_SUCCESS                                          (0)
#define OS_FAIL                                             (1)
#define OS_ERROR                                            (-1)
#define OS_INVALID                                          (-1)

//#define GDB_TEST_SWITCH

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */


/*cavium65XX 驱动 基本数据类型和数据结构*/

#ifndef __std_H
#define __std_H


#ifndef _ASMLANGUAGE

/* *类型定义 */
typedef int INT;

typedef signed char     S8;
typedef signed short    S16;
typedef signed int      S32;

#ifndef VC_DEBUG_MODE
typedef long long       S64;
#else
typedef __int64         S64;
#endif

#ifndef U8
typedef unsigned char   U8;
#endif

#ifndef U16
typedef unsigned short  U16;
#endif

#ifndef U32
typedef unsigned int    U32;
#endif

#ifndef VC_DEBUG_MODE
typedef unsigned long long  U64;
#else
typedef unsigned __int64 U64;
#endif

#ifndef LONG
typedef long    LONG;
#endif

/*
#ifndef CHAR
typedef char    CHAR;
#endif
*/

typedef volatile unsigned char  V8;
typedef volatile unsigned short V16;
typedef volatile unsigned int   V32;

#ifndef VC_DEBUG_MODE
typedef volatile unsigned long long  V64;
#else
typedef volatile unsigned __int64 V64;
#endif

#ifndef VC_DEBUG_MODE
typedef  char           BYTE;
#endif

typedef  unsigned char  UBYTE;
typedef  short          HWORD;
typedef  unsigned short UHWORD;

#ifndef VC_DEBUG_MODE
/*typedef  long           WORD;*/
typedef  unsigned long  UWORD;
#endif




typedef  volatile char           VBYTE;
typedef  volatile unsigned char  VUBYTE;
typedef  volatile short          VHWORD;
typedef  volatile unsigned short VUHWORD;
typedef  volatile long           VWORD;
typedef  volatile unsigned long  VUWORD;

#define REG64(Addr) (*(volatile unsigned long long *)(Addr))
#define REG32(Addr) (*(volatile unsigned int *)(Addr))
#define REG16(Addr) (*(volatile unsigned short *)(Addr))
#define REG8(Addr)  (*(volatile unsigned char *)(Addr))

U32 vxImmrGet (void);

#endif

/* BEGIN: Added by l52061, 2007/8/17 */
#define SIZE_1        1
#define SIZE_4        4
#define SIZE_59      59
/* END:   Added by l52061, 2007/8/17 */
#endif /* __std_H */

#endif /* _SRE_TYPEDEF_H */

/**
 * @}
*/

/**
 * History:
 *
 * vi: set expandtab ts=4 sw=4 tw=80:
*/

