/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
  文 件 名   : SRE_ge.inc
  版 本 号   : 初稿
  作    者   : Xu-Qiming
  生成日期   : 2010年4月7日
  最近修改   :
  功能描述   :
  函数列表   :
  修改历史   :
  1.日    期   : 2010年4月7日
    作    者   : Xu-Qiming
    修改内容   : 创建文件

******************************************************************************/

#ifndef _SRE_GE_INC
#define _SRE_GE_INC

#include "SRE_drv.h"
#include "SRE_memmap.h"
//#include "SRE_ge1.h"
//#include "SRE_xge.h"

/*----------------------------------------------*
 * 外部变量说明                                 *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 外部函数原型说明                             *
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

/*----------------------------------------------*
 * 宏定义                                       *
 *----------------------------------------------*/


#define SRE_MDIO_0   0
#define SRE_MDIO_1   1
#define SRE_MDIO_MAX        2
#define SRE_PHY_ADDR_MAX    31
#define SRE_PHY_REG_MAX     31

/* 最大帧长 */
#define SRE_GMAC_MAX_FRM_SIZE 65531   /* 单位是字节 */

/* 超短帧的最大长度 */
#define SRE_GMAC_SHORT_MAX_FRM_SIZE 31


/***********************************************************
****************************************************************
              MAC寄存器的联合体定义START
***************************************************************
***************************************************************/

/*结构体定义*/
/* Define the union SRE_MAC_DUPLEX_TYPE_U  addr :0x8*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0    : 31  ; /* [31..1]  */
        UINT32    duplex_type   : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

}SRE_MAC_DUPLEX_TYPE_U;

/* Define the union SRE_GMAC_FD_FC_TYPE_U  addr :0xc*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 16  ; /* [31..16]  */
        UINT32    fc_tx_timer           : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_FD_FC_TYPE_U;


/* Define the union SRE_GMAC_FC_TX_TIMER_U  addr :0x1c*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 16  ; /* [31..16]  */
        UINT32    fc_tx_timer           : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_FC_TX_TIMER_U;

/* Define the union SRE_GMAC_FD_FC_ADDR_HIGH_U  addr :0x24*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 16  ; /* [31..16]  */
        UINT32    fd_fc_addr_high       : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_FD_FC_ADDR_HIGH_U;

/* Define the union SRE_GMAC_IPG_TX_TIMER_U  addr :0x30*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 24  ; /* [31..8]  */
        UINT32    ipg_tx_timer          : 8   ; /* [7..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_IPG_TX_TIMER_U;

/* Define the union SRE_GMAC_PAUSE_THR_U  addr :0x38*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 16  ; /* [31..16]  */
        UINT32    pause_thr             : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_PAUSE_THR_U;

/* Define the union SRE_GMAC_MAX_FRM_SIZE_U  addr :0x3c*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 16  ; /* [31..15]  */
        UINT32    max_frm_size          : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_MAX_FRM_SIZE_U;

/* Define the union SRE_GMAC_PORT_MODE_U  addr :0x40*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 24  ; /* [31..8]  */
        UINT32    dbg_clk_los_msk       : 1 ;  /*[7]  */
        UINT32    fifo_err_auto_rst     : 1 ;  /*[6]  */
        UINT32    mii_tx_edge_sel       : 1 ;  /*[5]  */
        UINT32    rgmii_1000m_delay     : 1 ;  /*[4]  */
        UINT32    port_mode             : 4   ; /* [3..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_PORT_MODE_U;

/* Define the union SRE_GMAC_PORT_EN_U  addr :0x44*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 29  ; /* [31..3]  */
        UINT32    tx_en                 : 1   ; /* [2]  */
        UINT32    rx_en                 : 1   ; /* [1]  */
        UINT32    Reserved_1            : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_PORT_EN_U;

/* Define the union SRE_GMAC_PAUSE_EN_U  addr :0x48*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 29  ; /* [31..3]  */
        UINT32    tx_hdfc               : 1   ; /* [2]  */
        UINT32    tx_fdfc               : 1   ; /* [1]  */
        UINT32    rx_fdfc               : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_PAUSE_EN_U;

/* Define the union SRE_GMAC_SHORT_RUNTS_THR_U  addr :0x50*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 27  ; /* [31..5]  */
        UINT32    short_runts_thr       : 5   ; /* [4..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_SHORT_RUNTS_THR_U;

/* Define the union SRE_GMAC_AN_NEG_STATE_U  addr :0x58*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0    : 10  ; /* [31..22]  */
        UINT32    an_done          :1  ;/*[21]*/
        UINT32    rx_sync_ok     :1  ;/*[20]*/
        UINT32    Reserved_1    : 4  ; /* [19..16]  */
        UINT32    np_link_ok       : 1   ; /* [15]  */
        UINT32    Reserved_2    : 1; /* [14]  */
        UINT32    rf2               : 1   ; /* [13]  */
        UINT32    rf1_duplex        : 1   ; /* [12]  */
        UINT32    speed         : 2   ; /* [11..10]  */
        UINT32    Reserved_3    : 1; /* [9]  */
         UINT32    ps         : 2   ; /* [7..8]  */
        UINT32    hd         : 1   ; /* [6]  */
        UINT32    fd         : 1   ; /* [5]  */
        UINT32     Reserved_4    : 5  ; /* [4..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_AN_NEG_STATE_U;

/* Define the union SRE_GMAC_TX_LOCAL_PAG_U  addr :0x5c*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    reserved_0      : 16  ; /* [31..16]  */
        UINT32    cfg_15bit       : 1   ; /* [15]*/
        UINT32    reserved_1      : 1   ; /* [14]*/
        UINT32    cfg_13_12bit    : 2   ; /* [13..12]  */
        UINT32    cfg_11_10bit    : 2   ; /* [11..10]  */
        UINT32    reserved_2      : 1   ; /* [9]  */
        UINT32    cfg_8_5bit      : 4   ; /* [8..5]  */
        UINT32    reserved_3      : 4   ; /* [4..1]  */
        UINT32    cfg_0bit        : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_TX_LOCAL_PAG_U;

/* Define the union SRE_GMAC_TRANSMIT_CONTROL_U  addr :0x60*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 24  ; /* [31..8]  */
        UINT32    pad_enable            : 1   ; /* [7]  */
        UINT32    crc_add               : 1   ; /* [6]  */
        UINT32    an_enable           :1;    /*[5]*/
        UINT32    Reserved_1            : 5   ; /* [4..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_TRANSMIT_CONTROL_U;

/* Define the union SRE_GMAC_REC_FILT_CONTROL_U  addr :0x64*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 26  ; /* [31..6]  */
        UINT32    crc_err_pass          : 1   ; /* [5]  */
        UINT32    pause_frm_pass        : 1   ; /* [4]  */
        UINT32    reserved_1          : 1   ; /* [3]  */
        UINT32    bc_drop_en            : 1   ; /* [2]  */
        UINT32    mc_match_en           : 1   ; /* [1]  */
        UINT32    uc_match_en           : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_REC_FILT_CONTROL_U;


/* Define the union SRE_GMAC_PTP_CONFIG_U  addr :0x74*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 30  ; /* [31..2]  */
        UINT32    chksum_calc_en               : 1   ; /* [1]  */
        UINT32    corfield_msb_en               : 1   ; /* [0]  */
   } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_PTP_CONFIG_U;

/* Define the union SRE_GMAC_LED_MOD_U  addr :0x16c*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 31  ; /* [31..1]  */
        UINT32    led_mod               : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_LED_MOD_U;

/* Define the union SRE_GMAC_LINE_LOOP_BACK_U  addr :0x1A8*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 31  ; /* [31..1]  */
        UINT32    line_loop_back        : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_LINE_LOOP_BACK_U;

/* Define the union SRE_GMAC_CF_CRC_STRIP_U  addr :0x1B0*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 31  ; /* [31..1]  */
        UINT32    cf_crc_strip          : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_CF_CRC_STRIP_U;

/* Define the union SRE_GMAC_MODE_CHANGE_EN_U  addr :0x1B4*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 31  ; /* [31..1]  */
        UINT32    mode_change_en        : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_MODE_CHANGE_EN_U;

/* Define the union SRE_GMAC_SIXTEEN_BIT_CNTR_U  addr :0x1CC*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 31  ; /* [31..1]  */
        UINT32    sixteen_bit_cntr        : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_SIXTEEN_BIT_CNTR_U;

/* Define the union SRE_GMAC_LD_LINK_COUNTER_U  addr :0x1D0*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 30  ; /* [31..2]  */
        UINT32    ld_link_counter        : 1   ; /* [1]  */
        UINT32    Reserved_1            : 1  ; /* [0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_LD_LINK_COUNTER_U;

/* Define the union SRE_GMAC_LOOP_REG_U  addr :0x1DC*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 29  ; /* [31..3]  */
        UINT32    cf2mi_lp_en           : 1   ; /* [2]  */
        UINT32    cf_ext_drive_lp       : 1   ; /* [1]  */
        UINT32    Reserved_1            : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_LOOP_REG_U;

/* Define the union SRE_GMAC_RECV_CONTROL_U  addr :0x1e0*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 27  ; /* [31..5]  */
        UINT32    runt_pkt_en           : 1   ; /* [4]  */
        UINT32    strip_pad_en          : 1   ; /* [3]  */
        UINT32    Reserved_1            : 3   ; /* [2..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_RECV_CONTROL_U;

/* Define the union SRE_GMAC_VLAN_CODE_U  addr :0x1e8*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 16  ; /* [31..16]  */
        UINT32    cf_vlan_code          : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_VLAN_CODE_U;

/* Define the union SRE_GMAC_STATION_ADDR_HIGH_U  addr :0x204*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 15  ; /* [31..17]  */
        UINT32    station_addr_0_en  :1   ;/*[16]*/
        UINT32    station_addr_high_0   : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_STATION_ADDR_HIGH_U;

/* Define the union SRE_GMAC_STATION_ADDR_HIGH_1_U  addr :0x20c*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 15  ; /* [31..17]  */
        UINT32    station_addr_1_en  :1   ;/*[16]*/
        UINT32    station_addr_high_1   : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_STATION_ADDR_HIGH_1_U;

/* Define the union SRE_GMAC_STATION_ADDR_HIGH_2_U  addr :0x214*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 15  ; /* [31..17]  */
        UINT32    station_addr_2_en  :1   ;/*[16]*/
        UINT32    station_addr_high_2   : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_STATION_ADDR_HIGH_2_U;

/* Define the union SRE_GMAC_STATION_ADDR_HIGH_3_U  addr :0x21c*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 15  ; /* [31..17]  */
        UINT32    station_addr_3_en  :1   ;/*[16]*/
        UINT32    station_addr_high_3   : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_STATION_ADDR_HIGH_3_U;

/* Define the union SRE_GMAC_STATION_ADDR_HIGH_4_U  addr :0x224*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 15  ; /* [31..17]  */
        UINT32    station_addr_4_en  :1   ;/*[16]*/
        UINT32    station_addr_high_4   : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_STATION_ADDR_HIGH_4_U;

/* Define the union SRE_GMAC_STATION_ADDR_HIGH_5_U  addr :0x22c*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 15  ; /* [31..17]  */
        UINT32    station_addr_5_en  :1   ;/*[16]*/
        UINT32    station_addr_high_5   : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_STATION_ADDR_HIGH_5_U;

/* Define the union SRE_GMAC_STATION_ADDR_HIGH_MSK_0_U  addr :0x234*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0                : 16  ; /* [31..16]  */
        UINT32    station_addr_high_msk_0   : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_STATION_ADDR_HIGH_MSK_0_U;

/* Define the union SRE_GMAC_STATION_ADDR_HIGH_MSK_1_U  addr :0x23c*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0                : 16  ; /* [31..16]  */
        UINT32    station_addr_high_msk_1   : 16  ; /* [15..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_STATION_ADDR_HIGH_MSK_1_U;

/* Define the union SRE_GMAC_MAC_SKIP_LEN_U  addr :0x240*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved_0            : 25  ; /* [31..7]  */
        UINT32    mac_skip_crc          : 1   ; /* [6]  */
        UINT32    mac_skip_len          : 6   ; /* [5..0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_MAC_SKIP_LEN_U;

/* Define the union SRE_GMAC_DEBUG_PKT_PTR_U  addr :0x0344*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    reserved               : 29  ; /* [31..3]  */
        UINT32    debug_pkt_ptr         : 3   ; /* [2:0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_DEBUG_PKT_PTR_U;

/* Define the union SRE_GMAC_DEBUG_EN_U  addr :0x0348*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    reserved               : 31  ; /* [31..1]  */
        UINT32    debug_en         : 1   ; /* [0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_DEBUG_EN_U;

/* Define the union SRE_GMAC_INTR_STATE_U  addr :0x034c*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    reserved                : 25  ; /* [31..7]  */
        UINT32    back_1588_flag         : 1   ; /* [6]  */
        UINT32    dbg_grp0_flag           : 1  ; /* [5]  */
        UINT32    dbg_grp1_flag          : 1   ; /* [4]  */
        UINT32    dbg_grp0_num           : 2   ; /* [3:2]  */
        UINT32    dbg_grp1_num           : 2   ; /* [1:0]  */

    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_INTR_STATE_U;

/* Define the union SRE_GMAC_INTR_CLR_U  addr :0x0350*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    reserved0               : 25  ; /* [31..7]  */
        UINT32    back_1588_clr         : 1   ; /* [6]  */
        UINT32    dbg_grp0_clr           : 1  ; /* [5]  */
        UINT32    dbg_grp1_clr          : 1   ; /* [4]  */
        UINT32    reserved1              : 4   ; /* [3:0]  */

    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_INTR_CLR_U;

/* Define the union SRE_GMAC_INTR_MSK_U  addr :0x0354*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    reserved0               : 25  ; /* [31..7]  */
        UINT32    back_1588_msk         : 1   ; /* [6]  */
        UINT32    dbg_grp0_msk           : 1  ; /* [5]  */
        UINT32    dbg_grp1_msk          : 1   ; /* [4]  */
        UINT32    reserved1              : 4   ; /* [3:0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_INTR_MSK_U;

/* Define the union SRE_GMAC_SEQ_ID_U  addr :0x0358*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    seq_id                : 16  ; /* [31..16]  */
        UINT32    stp_79_to_64         : 16   ; /* [15:0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_SEQ_ID_U;

/* Define the union SRE_GMAC_DBG_GRP0_VLD_WORDS_U  addr :0x0364*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    ram0_drop_crc_bytes          : 2  ; /* [31..30]  */
        UINT32    ram1_drop_crc_bytes         : 2   ; /* [29:28]  */
        UINT32    ram2_drop_crc_bytes          : 2  ; /* [27..26]  */
        UINT32    ram3_drop_crc_bytes         : 2   ; /* [25:24]  */
        UINT32    ram0_vld_word                : 6  ; /* [23..18]  */
        UINT32    ram1_vld_word               : 6   ; /* [17:12]  */
        UINT32    ram2_vld_word                : 6  ; /* [11..6]  */
        UINT32    ram3_vld_word               : 6   ; /* [5:0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_DBG_GRP0_VLD_WORDS_U;

/* Define the union SRE_GMAC_DBG_GRP1_VLD_WORDS_U  addr :0x0368*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    ram4_drop_crc_bytes          : 2  ; /* [31..30]  */
        UINT32    ram5_drop_crc_bytes         : 2   ; /* [29:28]  */
        UINT32    ram6_drop_crc_bytes          : 2  ; /* [27..26]  */
        UINT32    ram7_drop_crc_bytes         : 2   ; /* [25:24]  */
        UINT32    ram4_vld_word                : 6  ; /* [23..18]  */
        UINT32    ram5_vld_word               : 6   ; /* [17:12]  */
        UINT32    ram6_vld_word                : 6  ; /* [11..6]  */
        UINT32    ram7_vld_word               : 6   ; /* [5:0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_DBG_GRP1_VLD_WORDS_U;

/* Define the union SRE_GMAC_DMAC_WITH_MSK_EN_U  addr :0x0374*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    reserved                  : 26  ; /* [31..6]  */
        UINT32    dmac_with_msk_en         : 6   ; /* [5:0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_DMAC_WITH_MSK_EN_U;

/* Define the union SRE_GMAC_TX_LOOP_PKT_PRI_U  addr :0x0378*/
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    reserved                 : 30 ; /* [31..2]  */
        UINT32    loop_pkt_en              : 1  ; /* [1]  */
        UINT32    loop_pkt_hig_pri         : 1  ; /* [0]  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_GMAC_TX_LOOP_PKT_PRI_U;

/***********************************************************
****************************************************************
              MAC寄存器的联合体定义END
***************************************************************
***************************************************************/


/***********************************************************
****************************************************************
              系统寄存器的联合体定义
***************************************************************
***************************************************************/
#if 0
#if (SRE_CPU == SRE_CPU_P600)

typedef union
{
    struct
    {
        UINT32    temp_trim               :3  ; /* [31..29]  */
        UINT32    temp_en                 :1  ; /* [28]  */
        UINT32    trace_out_en            :1  ; /* [27]  */
        UINT32    mdio_out_en             :1  ; /* [26]  */
        UINT32    smc_dout_vld_bypass     :1  ; /* [25]  */
        UINT32    sram_exmon_bypass       :1  ; /* [24]  */
        UINT32    i2c1_delay_bypass       :1  ; /* [23]  */
        UINT32    i2c0_delay_bypass       :1  ; /* [22]  */
        UINT32    normal_mode             :1  ; /* [21]  */
        UINT32    ss_in_n                 :1  ; /* [20]  */
        UINT32    ebitimeoutvalue2        :10  ; /* [19..10]  */
        UINT32    ebitimeoutvalue1        :10  ; /* [9..0]
  */
    }bits;

    UINT32    u32;

}SRE_PERCTRL10_U;

#elif(SRE_CPU == SRE_CPU_HI1380)

typedef union
{
    struct
    {
        UINT32    mem_scan_mode           :1  ; /* [31]  */
        UINT32    em_w_slice_en           :1  ; /* [30]  */
        UINT32    sm_cs_7_n_cfg           :1  ; /* [29]  */
        UINT32    sram_err_clr            :1  ; /* [28]  */
        UINT32    sram_ecc_err_trans      :1  ; /* [27]  */
        UINT32    sram_ecc_err_en         :1  ; /* [26]  */
        UINT32    smc_dout_vld_bypass     :1  ; /* [25]  */
        UINT32    sram_exmon_bypass       :1  ; /* [24]  */
        UINT32    i2c1_delay_bypass       :1  ; /* [23]  */
        UINT32    i2c0_delay_bypass       :1  ; /* [22]  */
        UINT32    normal_mode             :1  ; /* [21]  */
        UINT32    ss_in_n                 :1  ; /* [20]  */
        UINT32    ebitimeoutvalue2        :10  ; /* [19..10]  */
        UINT32    ebitimeoutvalue1        :10  ; /* [9..0]
  */
    }bits;

    UINT32    u32;

}SRE_PERCTRL10_U;

#endif
#endif

typedef union
{
    struct
    {
        UINT32    gmac3_rx_srst_req       :1  ; /* [31] gmac3 rx软复位请求  */
        UINT32    gmac2_rx_srst_req       :1  ; /* [30] gmac2 rx软复位请求  */
        UINT32    gmac1_rx_srst_req       :1  ; /* [29] gmac1 rx软复位请求  */
        UINT32    gmac0_rx_srst_req       :1  ; /* [28] gmac0 rx软复位请求  */
        UINT32    gmac9_eth_srst_req      :1  ; /* [27] gamc 9 eth软复位请求  */
        UINT32    gmac8_eth_srst_req      :1  ; /* [26] gamc 8 eth软复位请求  */
        UINT32    gmac7_eth_srst_req      :1  ; /* [25] gamc 7 eth软复位请求  */
        UINT32    gmac6_eth_srst_req      :1  ; /* [24] gamc 6 eth软复位请求  */
        UINT32    gmac5_eth_srst_req      :1  ; /* [23] gamc 5 eth软复位请求  */
        UINT32    gmac4_eth_srst_req      :1  ; /* [22] gamc 4 eth软复位请求  */
        UINT32    gmac3_eth_srst_req      :1  ; /* [21] gamc 3 eth软复位请求  */
        UINT32    gmac2_eth_srst_req      :1  ; /* [20] gamc 2 eth软复位请求  */
        UINT32    gmac1_eth_srst_req      :1  ; /* [19] gamc 1 eth软复位请求  */
        UINT32    gmac0_eth_srst_req      :1  ; /* [18] gamc 0 eth软复位请求  */
        UINT32    crc_srst_req            :1  ; /* [17] crc 的软复位请求  */
        UINT32    uart2_srst_req          :1  ; /* [16] uart2 的软复位请求  */
        UINT32    uart1_srst_req          :1  ; /* [15] uart1 的软复位请求  */
        UINT32    uart0_srst_req          :1  ; /* [14] uart0 的软复位请求  */
        UINT32    gpio1_srst_req          :1  ; /* [13] gpio1 的软复位请求  */
        UINT32    gpio0_srst_req          :1  ; /* [12] gpio0 的软复位请求  */
        UINT32    i2c_delay_srst_req      :1  ; /* [11] i2c_delay模块的软复位请求  */
        UINT32    i2c1_srst_req           :1  ; /* [10] i2c1模块的软复位请求  */
        UINT32    i2c0_srst_req           :1  ; /* [9] i2c0模块的软复位请求  */
        UINT32    reserved_0              :1  ; /* [8] 保留  */
        UINT32    ssp_srst_req            :1  ; /* [7] ssp模块的软复位请求  */
        UINT32    tdm_srst_req            :1  ; /* [6] TDM软复位请求  */
        UINT32    pcie0_aux_srst_req      :1  ; /* [5] pcie0 aux软复位请求  */
        UINT32    reserved_1              :1  ; /* [4] 保留  */
        UINT32    pcie0_rsyn_srst_req     :1  ; /* [3] pcie0 接收软复位请求  */
        UINT32    ddrphy_por_srst_req     :1  ; /* [2] ddrphy 上电软复位请求  */
        UINT32    mddrc_srst_req          :1  ; /* [1] mddrc软复位请求  */
        UINT32    reserved_2              :1  ; /* [0] 保留  */
    }bits;
    UINT32    u32;
}SRE_PERCTRL6_U;

typedef union
{
    struct
    {
        UINT32    gmac9_rx125m_srst_req   :1  ; /* [31] gmac9 rx125m软复位请求  */
        UINT32    gmac8_rx125m_srst_req   :1  ; /* [30] gmac8 rx125m软复位请求  */
        UINT32    gmac1_rx_srst_req       :2  ; /* [29:28] 保留  */
        UINT32    clust0_ptm_srst_req     :1  ; /* [27] cluster0 ptm软复位请求  */
        UINT32    clust1_ptm_srst_req     :1  ; /* [26] cluster1 ptm软复位请求  */
        UINT32    ssmc_srst_req           :1  ; /* [25] ssmc软复位请求  */
        UINT32    core_sight_srst_req     :1  ; /* [24] core sight软复位请求  */
        UINT32    gmac1_rx125m_srst_req   :1  ; /* [23] gmac1 rx125m软复位请求  */
        UINT32    gmac0_rx125m_srst_req   :1  ; /* [22] gmac0 rx125m软复位请求  */
        UINT32    gmac9_sys_srst_req      :1  ; /* [21] gamc9 sys软复位请求  */
        UINT32    gmac8_sys_srst_req      :1  ; /* [20] gamc8 sys软复位请求  */
        UINT32    gmac7_sys_srst_req      :1  ; /* [19] gamc7 sys软复位请求  */
        UINT32    gmac6_sys_srst_req      :1  ; /* [18] gamc6 sys软复位请求  */
        UINT32    gmac5_sys_srst_req      :1  ; /* [17] gamc5 sys软复位请求  */
        UINT32    gmac4_sys_srst_req      :1  ; /* [16] gamc4 sys软复位请求  */
        UINT32    gmac3_sys_srst_req      :1  ; /* [15] gamc3 sys软复位请求  */
        UINT32    gmac2_sys_srst_req      :1  ; /* [14] gamc2 sys软复位请求  */
        UINT32    gmac1_sys_srst_req      :1  ; /* [13] gamc1 sys软复位请求  */
        UINT32    gmac0_sys_srst_req      :1  ; /* [12] gamc0 sys软复位请求  */
        UINT32    gmac7_tx_srst_req       :1  ; /* [11] gmac 7 tx软复位请求  */
        UINT32    gmac6_tx_srst_req       :1  ; /* [10] gmac 6 tx软复位请求  */
        UINT32    gmac5_tx_srst_req       :1  ; /* [9] gmac 5 tx软复位请求  */
        UINT32    gmac4_tx_srst_req       :1  ; /* [8] gmac 4 tx软复位请求  */
        UINT32    gmac3_tx_srst_req       :1  ; /* [7] gmac 3 tx软复位请求  */
        UINT32    gmac2_tx_srst_req       :1  ; /* [6] gmac 2 tx软复位请求  */
        UINT32    gmac1_tx_srst_req       :1  ; /* [5] gmac 1 tx软复位请求  */
        UINT32    gmac0_tx_srst_req       :1  ; /* [4] gmac 0 tx软复位请求  */
        UINT32    gmac7_rx_srst_req       :1  ; /* [3] gmac 7 rx软复位请求  */
        UINT32    gmac6_rx_srst_req       :1  ; /* [2] gmac 6 rx软复位请求  */
        UINT32    gmac5_rx_srst_req       :1  ; /* [1] gmac 5 rx软复位请求  */
        UINT32    gmac4_rx_srst_req       :1  ; /* [0] gmac 4 rx软复位请求  */
    }bits;
    UINT32    u32;
}SRE_PERCTRL7_U;


/* Define the union SRE_PERCTRL69_U  */
typedef union
{
    /* Define the struct bits  */
    struct
    {
        UINT32    Reserved        	    : 12  ; /* [31..20] 保留  */
        UINT32    gmac_cfg_srst_req    	: 10   ; /*  */
        UINT32    gmac_macsys_srst_req  : 10   ; /*  */
    } bits;

    /* Define an unsigned member  */
    UINT32    u32;

} SRE_PERCTRL69_U;

/* BEGIN: Added by h00175571, 2011/11/26   问题单号:P650临时修改 */

/******************************************************************************/
/*                      MDIO 寄存器结构定义                              */
/******************************************************************************/

/* Define the union MDIO_COMMAND_REG_U  */
/* MDIO控制寄存器  */
/* 0x4  */
typedef union tagMdioCommandReg
{
    /* Define the struct bits  */
    struct
    {
        unsigned int    Mdio_Devad            : 5   ; /* [4..0] MDIO访问的外部的设备地址。  */
        unsigned int    Mdio_Prtad            : 5   ; /* [9..5] MDIO访问的外部的端口地址。  */
        unsigned int    Mdio_Op               : 2   ; /* [11..10] MDIO操作寄存器。          */
        unsigned int    Mdio_St               : 2   ; /* [13..12] MDIO访问类型寄存器。      */
        unsigned int    Mdio_Start            : 1   ; /* [14] MDIO启动命令控制字。          */
        unsigned int    Rsv                   : 17  ; /* [31..15] 保留。                    */
    } bits;
    /* Define an unsigned member  */
    unsigned int    u32;

} MDIO_COMMAND_REG_U;

/* Define the union MDIO_ADDR_REG_U  */
/* MDIO间接地址寄存器  */
/* 0x8  */
typedef union tagMdioAddrReg
{
    /* Define the struct bits  */
    struct
    {
        unsigned int    Mdio_Address          : 16  ; /* [15..0] 当mdio_st为2’b00时有效，代表要访问的外部某端口某设备的内部寄存器的地址，当mdio_st为其它值时无效。  */
        unsigned int    Rsv                   : 16  ; /* [31..16] 保留。  */
    } bits;

    /* Define an unsigned member  */
    unsigned int    u32;

} MDIO_ADDR_REG_U;

/* Define the union MDIO_WDATA_REG_U  */
/* MDIO写数据寄存器  */
/* 0xC  */
typedef union tagMdioWdataReg
{
    /* Define the struct bits  */
    struct
    {
        unsigned int    Mdio_Wdata            : 16  ; /* [15..0] MDIO写访问的写数据。  */
        unsigned int    Rsv                   : 16  ; /* [31..16] 保留。  */
    } bits;

    /* Define an unsigned member  */
    unsigned int    u32;

} MDIO_WDATA_REG_U;

/* Define the union MDIO_RDATA_REG_U  */
/* MDIO读数据寄存器  */
/* 0x10  */
typedef union tagMdioRdataReg
{
    /* Define the struct bits  */
    struct
    {
        unsigned int    Mdio_Rdata            : 16  ; /* [15..0] MDIO读访问的读数据。  */
        unsigned int    Rsv                   : 16  ; /* [31..16] 保留。  */
    } bits;

    /* Define an unsigned member  */
    unsigned int    u32;

} MDIO_RDATA_REG_U;

/* Define the union MDIO_STA_REG_U  */
/* MDIO访问状态寄存器  */
/* 0x14  */
typedef union tagMdioStaReg
{
    /* Define the struct bits  */
    struct
    {
        unsigned int    Mdio_Sta              : 1   ;   /* [0] MDIO读访问的状态。   */
        unsigned int    Rsv                   : 31  ;   /* [31..1] 保留。           */
    } bits;

    /* Define an unsigned member  */
    unsigned int    u32;

} MDIO_STA_REG_U;


/* END:   Added by h00175571, 2011/11/26 */
/***********************************************************
****************************************************************
              系统寄存器的联合体定义END
***************************************************************
***************************************************************/

/*
 * 各个模块错误处理宏定义
 */
#define SRE_HIGMAC_ERROR(fmt, arg0, arg1, arg2, arg3, arg...)   \
    SRE_printf(fmt, arg0, arg1, arg2, arg3, __FUNCTION__, __LINE__, 0, 0, SRE_GetCoreID())



#endif /* _SRE_GE_INC */

