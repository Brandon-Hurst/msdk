/**
 * @file    dma_regs.h
 * @brief   Registers, Bit Masks and Bit Positions for the DMA Peripheral Module.
 * @note    This file is @generated.
 * @ingroup dma_registers
 */

/******************************************************************************
 *
 * Copyright (C) 2022-2023 Maxim Integrated Products, Inc. (now owned by 
 * Analog Devices, Inc.),
 * Copyright (C) 2023-2024 Analog Devices, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/

#ifndef LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32520_INCLUDE_DMA_REGS_H_
#define LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32520_INCLUDE_DMA_REGS_H_

/* **** Includes **** */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined (__ICCARM__)
  #pragma system_include
#endif

#if defined (__CC_ARM)
  #pragma anon_unions
#endif
/// @cond
/*
    If types are not defined elsewhere (CMSIS) define them here
*/
#ifndef __IO
#define __IO volatile
#endif
#ifndef __I
#ifdef __cplusplus
#define __I volatile
#else
#define __I volatile const
#endif
#endif
#ifndef __O
#define __O  volatile
#endif
#ifndef __R
#define __R  volatile const
#endif
/// @endcond

/* **** Definitions **** */

/**
 * @ingroup     dma
 * @defgroup    dma_registers DMA_Registers
 * @brief       Registers, Bit Masks and Bit Positions for the DMA Peripheral Module.
 * @details     DMA Controller Fully programmable, chaining capable DMA channels.
 */

/**
 * @ingroup dma_registers
 * Structure type to access the DMA Registers.
 */
typedef struct {
    __IO uint32_t cfg;                  /**< <tt>\b 0x000:</tt> DMA CFG Register */
    __IO uint32_t st;                   /**< <tt>\b 0x004:</tt> DMA ST Register */
    __IO uint32_t src;                  /**< <tt>\b 0x008:</tt> DMA SRC Register */
    __IO uint32_t dst;                  /**< <tt>\b 0x00C:</tt> DMA DST Register */
    __IO uint32_t cnt;                  /**< <tt>\b 0x010:</tt> DMA CNT Register */
    __IO uint32_t src_rld;              /**< <tt>\b 0x014:</tt> DMA SRC_RLD Register */
    __IO uint32_t dst_rld;              /**< <tt>\b 0x018:</tt> DMA DST_RLD Register */
    __IO uint32_t cnt_rld;              /**< <tt>\b 0x01C:</tt> DMA CNT_RLD Register */
} mxc_dma_ch_regs_t;

typedef struct {
    __IO uint32_t cn;                   /**< <tt>\b 0x000:</tt> DMA CN Register */
    __I  uint32_t intr;                 /**< <tt>\b 0x004:</tt> DMA INTR Register */
    __R  uint32_t rsv_0x8_0xff[62];
    __IO mxc_dma_ch_regs_t ch[8];       /**< <tt>\b 0x100:</tt> DMA CH Register */
} mxc_dma_regs_t;

/* Register offsets for module DMA */
/**
 * @ingroup    dma_registers
 * @defgroup   DMA_Register_Offsets Register Offsets
 * @brief      DMA Peripheral Register Offsets from the DMA Base Peripheral Address.
 * @{
 */
#define MXC_R_DMA_CFG                      ((uint32_t)0x00000000UL) /**< Offset from DMA Base Address: <tt> 0x0000</tt> */
#define MXC_R_DMA_ST                       ((uint32_t)0x00000004UL) /**< Offset from DMA Base Address: <tt> 0x0004</tt> */
#define MXC_R_DMA_SRC                      ((uint32_t)0x00000008UL) /**< Offset from DMA Base Address: <tt> 0x0008</tt> */
#define MXC_R_DMA_DST                      ((uint32_t)0x0000000CUL) /**< Offset from DMA Base Address: <tt> 0x000C</tt> */
#define MXC_R_DMA_CNT                      ((uint32_t)0x00000010UL) /**< Offset from DMA Base Address: <tt> 0x0010</tt> */
#define MXC_R_DMA_SRC_RLD                  ((uint32_t)0x00000014UL) /**< Offset from DMA Base Address: <tt> 0x0014</tt> */
#define MXC_R_DMA_DST_RLD                  ((uint32_t)0x00000018UL) /**< Offset from DMA Base Address: <tt> 0x0018</tt> */
#define MXC_R_DMA_CNT_RLD                  ((uint32_t)0x0000001CUL) /**< Offset from DMA Base Address: <tt> 0x001C</tt> */
#define MXC_R_DMA_CN                       ((uint32_t)0x00000000UL) /**< Offset from DMA Base Address: <tt> 0x0000</tt> */
#define MXC_R_DMA_INTR                     ((uint32_t)0x00000004UL) /**< Offset from DMA Base Address: <tt> 0x0004</tt> */
#define MXC_R_DMA_CH                       ((uint32_t)0x00000100UL) /**< Offset from DMA Base Address: <tt> 0x0100</tt> */
/**@} end of group dma_registers */

/**
 * @ingroup  dma_registers
 * @defgroup DMA_CN DMA_CN
 * @brief    DMA Control Register.
 * @{
 */
#define MXC_F_DMA_CN_CHIEN_POS                         0 /**< CN_CHIEN Position */
#define MXC_F_DMA_CN_CHIEN                             ((uint32_t)(0xFUL << MXC_F_DMA_CN_CHIEN_POS)) /**< CN_CHIEN Mask */
#define MXC_V_DMA_CN_CHIEN_DIS                         ((uint32_t)0x0UL) /**< CN_CHIEN_DIS Value */
#define MXC_S_DMA_CN_CHIEN_DIS                         (MXC_V_DMA_CN_CHIEN_DIS << MXC_F_DMA_CN_CHIEN_POS) /**< CN_CHIEN_DIS Setting */
#define MXC_V_DMA_CN_CHIEN_EN                          ((uint32_t)0x1UL) /**< CN_CHIEN_EN Value */
#define MXC_S_DMA_CN_CHIEN_EN                          (MXC_V_DMA_CN_CHIEN_EN << MXC_F_DMA_CN_CHIEN_POS) /**< CN_CHIEN_EN Setting */

/**@} end of group DMA_CN_Register */

/**
 * @ingroup  dma_registers
 * @defgroup DMA_INTR DMA_INTR
 * @brief    DMA Interrupt Register.
 * @{
 */
#define MXC_F_DMA_INTR_IPEND_POS                       0 /**< INTR_IPEND Position */
#define MXC_F_DMA_INTR_IPEND                           ((uint32_t)(0xFUL << MXC_F_DMA_INTR_IPEND_POS)) /**< INTR_IPEND Mask */
#define MXC_V_DMA_INTR_IPEND_INACTIVE                  ((uint32_t)0x0UL) /**< INTR_IPEND_INACTIVE Value */
#define MXC_S_DMA_INTR_IPEND_INACTIVE                  (MXC_V_DMA_INTR_IPEND_INACTIVE << MXC_F_DMA_INTR_IPEND_POS) /**< INTR_IPEND_INACTIVE Setting */
#define MXC_V_DMA_INTR_IPEND_PENDING                   ((uint32_t)0x1UL) /**< INTR_IPEND_PENDING Value */
#define MXC_S_DMA_INTR_IPEND_PENDING                   (MXC_V_DMA_INTR_IPEND_PENDING << MXC_F_DMA_INTR_IPEND_POS) /**< INTR_IPEND_PENDING Setting */

/**@} end of group DMA_INTR_Register */

/**
 * @ingroup  dma_registers
 * @defgroup DMA_CFG DMA_CFG
 * @brief    DMA Channel Configuration Register.
 * @{
 */
#define MXC_F_DMA_CFG_CHIEN_POS                        0 /**< CFG_CHIEN Position */
#define MXC_F_DMA_CFG_CHIEN                            ((uint32_t)(0x1UL << MXC_F_DMA_CFG_CHIEN_POS)) /**< CFG_CHIEN Mask */

#define MXC_F_DMA_CFG_RLDEN_POS                        1 /**< CFG_RLDEN Position */
#define MXC_F_DMA_CFG_RLDEN                            ((uint32_t)(0x1UL << MXC_F_DMA_CFG_RLDEN_POS)) /**< CFG_RLDEN Mask */

#define MXC_F_DMA_CFG_PRI_POS                          2 /**< CFG_PRI Position */
#define MXC_F_DMA_CFG_PRI                              ((uint32_t)(0x3UL << MXC_F_DMA_CFG_PRI_POS)) /**< CFG_PRI Mask */
#define MXC_V_DMA_CFG_PRI_HIGH                         ((uint32_t)0x0UL) /**< CFG_PRI_HIGH Value */
#define MXC_S_DMA_CFG_PRI_HIGH                         (MXC_V_DMA_CFG_PRI_HIGH << MXC_F_DMA_CFG_PRI_POS) /**< CFG_PRI_HIGH Setting */
#define MXC_V_DMA_CFG_PRI_MEDHIGH                      ((uint32_t)0x1UL) /**< CFG_PRI_MEDHIGH Value */
#define MXC_S_DMA_CFG_PRI_MEDHIGH                      (MXC_V_DMA_CFG_PRI_MEDHIGH << MXC_F_DMA_CFG_PRI_POS) /**< CFG_PRI_MEDHIGH Setting */
#define MXC_V_DMA_CFG_PRI_MEDLOW                       ((uint32_t)0x2UL) /**< CFG_PRI_MEDLOW Value */
#define MXC_S_DMA_CFG_PRI_MEDLOW                       (MXC_V_DMA_CFG_PRI_MEDLOW << MXC_F_DMA_CFG_PRI_POS) /**< CFG_PRI_MEDLOW Setting */
#define MXC_V_DMA_CFG_PRI_LOW                          ((uint32_t)0x3UL) /**< CFG_PRI_LOW Value */
#define MXC_S_DMA_CFG_PRI_LOW                          (MXC_V_DMA_CFG_PRI_LOW << MXC_F_DMA_CFG_PRI_POS) /**< CFG_PRI_LOW Setting */

#define MXC_F_DMA_CFG_REQSEL_POS                       4 /**< CFG_REQSEL Position */
#define MXC_F_DMA_CFG_REQSEL                           ((uint32_t)(0x3FUL << MXC_F_DMA_CFG_REQSEL_POS)) /**< CFG_REQSEL Mask */
#define MXC_V_DMA_CFG_REQSEL_MEMTOMEM                  ((uint32_t)0x0UL) /**< CFG_REQSEL_MEMTOMEM Value */
#define MXC_S_DMA_CFG_REQSEL_MEMTOMEM                  (MXC_V_DMA_CFG_REQSEL_MEMTOMEM << MXC_F_DMA_CFG_REQSEL_POS) /**< CFG_REQSEL_MEMTOMEM Setting */
#define MXC_V_DMA_CFG_REQSEL_SPI0RX                    ((uint32_t)0x1UL) /**< CFG_REQSEL_SPI0RX Value */
#define MXC_S_DMA_CFG_REQSEL_SPI0RX                    (MXC_V_DMA_CFG_REQSEL_SPI0RX << MXC_F_DMA_CFG_REQSEL_POS) /**< CFG_REQSEL_SPI0RX Setting */
#define MXC_V_DMA_CFG_REQSEL_SPI1RX                    ((uint32_t)0x2UL) /**< CFG_REQSEL_SPI1RX Value */
#define MXC_S_DMA_CFG_REQSEL_SPI1RX                    (MXC_V_DMA_CFG_REQSEL_SPI1RX << MXC_F_DMA_CFG_REQSEL_POS) /**< CFG_REQSEL_SPI1RX Setting */
#define MXC_V_DMA_CFG_REQSEL_I2C0RX                    ((uint32_t)0x7UL) /**< CFG_REQSEL_I2C0RX Value */
#define MXC_S_DMA_CFG_REQSEL_I2C0RX                    (MXC_V_DMA_CFG_REQSEL_I2C0RX << MXC_F_DMA_CFG_REQSEL_POS) /**< CFG_REQSEL_I2C0RX Setting */
#define MXC_V_DMA_CFG_REQSEL_UART0RX                   ((uint32_t)0x1CUL) /**< CFG_REQSEL_UART0RX Value */
#define MXC_S_DMA_CFG_REQSEL_UART0RX                   (MXC_V_DMA_CFG_REQSEL_UART0RX << MXC_F_DMA_CFG_REQSEL_POS) /**< CFG_REQSEL_UART0RX Setting */
#define MXC_V_DMA_CFG_REQSEL_SPI0TX                    ((uint32_t)0x21UL) /**< CFG_REQSEL_SPI0TX Value */
#define MXC_S_DMA_CFG_REQSEL_SPI0TX                    (MXC_V_DMA_CFG_REQSEL_SPI0TX << MXC_F_DMA_CFG_REQSEL_POS) /**< CFG_REQSEL_SPI0TX Setting */
#define MXC_V_DMA_CFG_REQSEL_SPI1TX                    ((uint32_t)0x22UL) /**< CFG_REQSEL_SPI1TX Value */
#define MXC_S_DMA_CFG_REQSEL_SPI1TX                    (MXC_V_DMA_CFG_REQSEL_SPI1TX << MXC_F_DMA_CFG_REQSEL_POS) /**< CFG_REQSEL_SPI1TX Setting */
#define MXC_V_DMA_CFG_REQSEL_I2C0TX                    ((uint32_t)0x27UL) /**< CFG_REQSEL_I2C0TX Value */
#define MXC_S_DMA_CFG_REQSEL_I2C0TX                    (MXC_V_DMA_CFG_REQSEL_I2C0TX << MXC_F_DMA_CFG_REQSEL_POS) /**< CFG_REQSEL_I2C0TX Setting */
#define MXC_V_DMA_CFG_REQSEL_UART0TX                   ((uint32_t)0x3CUL) /**< CFG_REQSEL_UART0TX Value */
#define MXC_S_DMA_CFG_REQSEL_UART0TX                   (MXC_V_DMA_CFG_REQSEL_UART0TX << MXC_F_DMA_CFG_REQSEL_POS) /**< CFG_REQSEL_UART0TX Setting */

#define MXC_F_DMA_CFG_REQWAIT_POS                      10 /**< CFG_REQWAIT Position */
#define MXC_F_DMA_CFG_REQWAIT                          ((uint32_t)(0x1UL << MXC_F_DMA_CFG_REQWAIT_POS)) /**< CFG_REQWAIT Mask */

#define MXC_F_DMA_CFG_TOSEL_POS                        11 /**< CFG_TOSEL Position */
#define MXC_F_DMA_CFG_TOSEL                            ((uint32_t)(0x7UL << MXC_F_DMA_CFG_TOSEL_POS)) /**< CFG_TOSEL Mask */
#define MXC_V_DMA_CFG_TOSEL_TO4                        ((uint32_t)0x0UL) /**< CFG_TOSEL_TO4 Value */
#define MXC_S_DMA_CFG_TOSEL_TO4                        (MXC_V_DMA_CFG_TOSEL_TO4 << MXC_F_DMA_CFG_TOSEL_POS) /**< CFG_TOSEL_TO4 Setting */
#define MXC_V_DMA_CFG_TOSEL_TO8                        ((uint32_t)0x1UL) /**< CFG_TOSEL_TO8 Value */
#define MXC_S_DMA_CFG_TOSEL_TO8                        (MXC_V_DMA_CFG_TOSEL_TO8 << MXC_F_DMA_CFG_TOSEL_POS) /**< CFG_TOSEL_TO8 Setting */
#define MXC_V_DMA_CFG_TOSEL_TO16                       ((uint32_t)0x2UL) /**< CFG_TOSEL_TO16 Value */
#define MXC_S_DMA_CFG_TOSEL_TO16                       (MXC_V_DMA_CFG_TOSEL_TO16 << MXC_F_DMA_CFG_TOSEL_POS) /**< CFG_TOSEL_TO16 Setting */
#define MXC_V_DMA_CFG_TOSEL_TO32                       ((uint32_t)0x3UL) /**< CFG_TOSEL_TO32 Value */
#define MXC_S_DMA_CFG_TOSEL_TO32                       (MXC_V_DMA_CFG_TOSEL_TO32 << MXC_F_DMA_CFG_TOSEL_POS) /**< CFG_TOSEL_TO32 Setting */
#define MXC_V_DMA_CFG_TOSEL_TO64                       ((uint32_t)0x4UL) /**< CFG_TOSEL_TO64 Value */
#define MXC_S_DMA_CFG_TOSEL_TO64                       (MXC_V_DMA_CFG_TOSEL_TO64 << MXC_F_DMA_CFG_TOSEL_POS) /**< CFG_TOSEL_TO64 Setting */
#define MXC_V_DMA_CFG_TOSEL_TO128                      ((uint32_t)0x5UL) /**< CFG_TOSEL_TO128 Value */
#define MXC_S_DMA_CFG_TOSEL_TO128                      (MXC_V_DMA_CFG_TOSEL_TO128 << MXC_F_DMA_CFG_TOSEL_POS) /**< CFG_TOSEL_TO128 Setting */
#define MXC_V_DMA_CFG_TOSEL_TO256                      ((uint32_t)0x6UL) /**< CFG_TOSEL_TO256 Value */
#define MXC_S_DMA_CFG_TOSEL_TO256                      (MXC_V_DMA_CFG_TOSEL_TO256 << MXC_F_DMA_CFG_TOSEL_POS) /**< CFG_TOSEL_TO256 Setting */
#define MXC_V_DMA_CFG_TOSEL_TO512                      ((uint32_t)0x7UL) /**< CFG_TOSEL_TO512 Value */
#define MXC_S_DMA_CFG_TOSEL_TO512                      (MXC_V_DMA_CFG_TOSEL_TO512 << MXC_F_DMA_CFG_TOSEL_POS) /**< CFG_TOSEL_TO512 Setting */

#define MXC_F_DMA_CFG_PSSEL_POS                        14 /**< CFG_PSSEL Position */
#define MXC_F_DMA_CFG_PSSEL                            ((uint32_t)(0x3UL << MXC_F_DMA_CFG_PSSEL_POS)) /**< CFG_PSSEL Mask */
#define MXC_V_DMA_CFG_PSSEL_DIS                        ((uint32_t)0x0UL) /**< CFG_PSSEL_DIS Value */
#define MXC_S_DMA_CFG_PSSEL_DIS                        (MXC_V_DMA_CFG_PSSEL_DIS << MXC_F_DMA_CFG_PSSEL_POS) /**< CFG_PSSEL_DIS Setting */
#define MXC_V_DMA_CFG_PSSEL_DIV256                     ((uint32_t)0x1UL) /**< CFG_PSSEL_DIV256 Value */
#define MXC_S_DMA_CFG_PSSEL_DIV256                     (MXC_V_DMA_CFG_PSSEL_DIV256 << MXC_F_DMA_CFG_PSSEL_POS) /**< CFG_PSSEL_DIV256 Setting */
#define MXC_V_DMA_CFG_PSSEL_DIV64K                     ((uint32_t)0x2UL) /**< CFG_PSSEL_DIV64K Value */
#define MXC_S_DMA_CFG_PSSEL_DIV64K                     (MXC_V_DMA_CFG_PSSEL_DIV64K << MXC_F_DMA_CFG_PSSEL_POS) /**< CFG_PSSEL_DIV64K Setting */
#define MXC_V_DMA_CFG_PSSEL_DIV16M                     ((uint32_t)0x3UL) /**< CFG_PSSEL_DIV16M Value */
#define MXC_S_DMA_CFG_PSSEL_DIV16M                     (MXC_V_DMA_CFG_PSSEL_DIV16M << MXC_F_DMA_CFG_PSSEL_POS) /**< CFG_PSSEL_DIV16M Setting */

#define MXC_F_DMA_CFG_SRCWD_POS                        16 /**< CFG_SRCWD Position */
#define MXC_F_DMA_CFG_SRCWD                            ((uint32_t)(0x3UL << MXC_F_DMA_CFG_SRCWD_POS)) /**< CFG_SRCWD Mask */
#define MXC_V_DMA_CFG_SRCWD_BYTE                       ((uint32_t)0x0UL) /**< CFG_SRCWD_BYTE Value */
#define MXC_S_DMA_CFG_SRCWD_BYTE                       (MXC_V_DMA_CFG_SRCWD_BYTE << MXC_F_DMA_CFG_SRCWD_POS) /**< CFG_SRCWD_BYTE Setting */
#define MXC_V_DMA_CFG_SRCWD_HALFWORD                   ((uint32_t)0x1UL) /**< CFG_SRCWD_HALFWORD Value */
#define MXC_S_DMA_CFG_SRCWD_HALFWORD                   (MXC_V_DMA_CFG_SRCWD_HALFWORD << MXC_F_DMA_CFG_SRCWD_POS) /**< CFG_SRCWD_HALFWORD Setting */
#define MXC_V_DMA_CFG_SRCWD_WORD                       ((uint32_t)0x2UL) /**< CFG_SRCWD_WORD Value */
#define MXC_S_DMA_CFG_SRCWD_WORD                       (MXC_V_DMA_CFG_SRCWD_WORD << MXC_F_DMA_CFG_SRCWD_POS) /**< CFG_SRCWD_WORD Setting */

#define MXC_F_DMA_CFG_SRCINC_POS                       18 /**< CFG_SRCINC Position */
#define MXC_F_DMA_CFG_SRCINC                           ((uint32_t)(0x1UL << MXC_F_DMA_CFG_SRCINC_POS)) /**< CFG_SRCINC Mask */

#define MXC_F_DMA_CFG_DSTWD_POS                        20 /**< CFG_DSTWD Position */
#define MXC_F_DMA_CFG_DSTWD                            ((uint32_t)(0x3UL << MXC_F_DMA_CFG_DSTWD_POS)) /**< CFG_DSTWD Mask */
#define MXC_V_DMA_CFG_DSTWD_BYTE                       ((uint32_t)0x0UL) /**< CFG_DSTWD_BYTE Value */
#define MXC_S_DMA_CFG_DSTWD_BYTE                       (MXC_V_DMA_CFG_DSTWD_BYTE << MXC_F_DMA_CFG_DSTWD_POS) /**< CFG_DSTWD_BYTE Setting */
#define MXC_V_DMA_CFG_DSTWD_HALFWORD                   ((uint32_t)0x1UL) /**< CFG_DSTWD_HALFWORD Value */
#define MXC_S_DMA_CFG_DSTWD_HALFWORD                   (MXC_V_DMA_CFG_DSTWD_HALFWORD << MXC_F_DMA_CFG_DSTWD_POS) /**< CFG_DSTWD_HALFWORD Setting */
#define MXC_V_DMA_CFG_DSTWD_WORD                       ((uint32_t)0x2UL) /**< CFG_DSTWD_WORD Value */
#define MXC_S_DMA_CFG_DSTWD_WORD                       (MXC_V_DMA_CFG_DSTWD_WORD << MXC_F_DMA_CFG_DSTWD_POS) /**< CFG_DSTWD_WORD Setting */

#define MXC_F_DMA_CFG_DSTINC_POS                       22 /**< CFG_DSTINC Position */
#define MXC_F_DMA_CFG_DSTINC                           ((uint32_t)(0x1UL << MXC_F_DMA_CFG_DSTINC_POS)) /**< CFG_DSTINC Mask */

#define MXC_F_DMA_CFG_BRST_POS                         24 /**< CFG_BRST Position */
#define MXC_F_DMA_CFG_BRST                             ((uint32_t)(0x1FUL << MXC_F_DMA_CFG_BRST_POS)) /**< CFG_BRST Mask */

#define MXC_F_DMA_CFG_CHDIEN_POS                       30 /**< CFG_CHDIEN Position */
#define MXC_F_DMA_CFG_CHDIEN                           ((uint32_t)(0x1UL << MXC_F_DMA_CFG_CHDIEN_POS)) /**< CFG_CHDIEN Mask */

#define MXC_F_DMA_CFG_CTZIEN_POS                       31 /**< CFG_CTZIEN Position */
#define MXC_F_DMA_CFG_CTZIEN                           ((uint32_t)(0x1UL << MXC_F_DMA_CFG_CTZIEN_POS)) /**< CFG_CTZIEN Mask */

/**@} end of group DMA_CFG_Register */

/**
 * @ingroup  dma_registers
 * @defgroup DMA_ST DMA_ST
 * @brief    DMA Channel Status Register.
 * @{
 */
#define MXC_F_DMA_ST_CH_ST_POS                         0 /**< ST_CH_ST Position */
#define MXC_F_DMA_ST_CH_ST                             ((uint32_t)(0x1UL << MXC_F_DMA_ST_CH_ST_POS)) /**< ST_CH_ST Mask */

#define MXC_F_DMA_ST_IPEND_POS                         1 /**< ST_IPEND Position */
#define MXC_F_DMA_ST_IPEND                             ((uint32_t)(0x1UL << MXC_F_DMA_ST_IPEND_POS)) /**< ST_IPEND Mask */

#define MXC_F_DMA_ST_CTZ_ST_POS                        2 /**< ST_CTZ_ST Position */
#define MXC_F_DMA_ST_CTZ_ST                            ((uint32_t)(0x1UL << MXC_F_DMA_ST_CTZ_ST_POS)) /**< ST_CTZ_ST Mask */

#define MXC_F_DMA_ST_RLD_ST_POS                        3 /**< ST_RLD_ST Position */
#define MXC_F_DMA_ST_RLD_ST                            ((uint32_t)(0x1UL << MXC_F_DMA_ST_RLD_ST_POS)) /**< ST_RLD_ST Mask */

#define MXC_F_DMA_ST_BUS_ERR_POS                       4 /**< ST_BUS_ERR Position */
#define MXC_F_DMA_ST_BUS_ERR                           ((uint32_t)(0x1UL << MXC_F_DMA_ST_BUS_ERR_POS)) /**< ST_BUS_ERR Mask */

#define MXC_F_DMA_ST_TO_ST_POS                         6 /**< ST_TO_ST Position */
#define MXC_F_DMA_ST_TO_ST                             ((uint32_t)(0x1UL << MXC_F_DMA_ST_TO_ST_POS)) /**< ST_TO_ST Mask */

/**@} end of group DMA_ST_Register */

/**
 * @ingroup  dma_registers
 * @defgroup DMA_SRC DMA_SRC
 * @brief    Source Device Address. If SRCINC=1, the counter bits are incremented by 1,2, or
 *           4, depending on the data width of each AHB cycle. For peripheral transfers, some
 *           or all of the actual address bits are fixed. If SRCINC=0, this register remains
 *           constant. In the case where a count-to-zero condition occurs while RLDEN=1, the
 *           register is reloaded with the contents of DMA_SRC_RLD.
 * @{
 */
#define MXC_F_DMA_SRC_SRC_POS                          0 /**< SRC_SRC Position */
#define MXC_F_DMA_SRC_SRC                              ((uint32_t)(0xFFFFFFFFUL << MXC_F_DMA_SRC_SRC_POS)) /**< SRC_SRC Mask */

/**@} end of group DMA_SRC_Register */

/**
 * @ingroup  dma_registers
 * @defgroup DMA_DST DMA_DST
 * @brief    Destination Device Address. For peripheral transfers, some or all of the actual
 *           address bits are fixed. If DSTINC=1, this register is incremented on every AHB
 *           write out of the DMA FIFO. They are incremented by 1, 2, or 4, depending on the
 *           data width of each AHB cycle. In the case where a count-to-zero condition occurs
 *           while RLDEN=1, the register is reloaded with DMA_DST_RLD.
 * @{
 */
#define MXC_F_DMA_DST_DST_POS                          0 /**< DST_DST Position */
#define MXC_F_DMA_DST_DST                              ((uint32_t)(0xFFFFFFFFUL << MXC_F_DMA_DST_DST_POS)) /**< DST_DST Mask */

/**@} end of group DMA_DST_Register */

/**
 * @ingroup  dma_registers
 * @defgroup DMA_CNT DMA_CNT
 * @brief    DMA Counter. The user loads this register with the number of bytes to transfer.
 *           This counter decreases on every AHB cycle into the DMA FIFO. The decrement will
 *           be 1, 2, or 4 depending on the data width of each AHB cycle. When the counter
 *           reaches 0, a count-to-zero condition is triggered.
 * @{
 */
#define MXC_F_DMA_CNT_CNT_POS                          0 /**< CNT_CNT Position */
#define MXC_F_DMA_CNT_CNT                              ((uint32_t)(0xFFFFFFUL << MXC_F_DMA_CNT_CNT_POS)) /**< CNT_CNT Mask */

/**@} end of group DMA_CNT_Register */

/**
 * @ingroup  dma_registers
 * @defgroup DMA_SRC_RLD DMA_SRC_RLD
 * @brief    Source Address Reload Value. The value of this register is loaded into DMA0_SRC
 *           upon a count-to-zero condition.
 * @{
 */
#define MXC_F_DMA_SRC_RLD_SRC_RLD_POS                  0 /**< SRC_RLD_SRC_RLD Position */
#define MXC_F_DMA_SRC_RLD_SRC_RLD                      ((uint32_t)(0x7FFFFFFFUL << MXC_F_DMA_SRC_RLD_SRC_RLD_POS)) /**< SRC_RLD_SRC_RLD Mask */

/**@} end of group DMA_SRC_RLD_Register */

/**
 * @ingroup  dma_registers
 * @defgroup DMA_DST_RLD DMA_DST_RLD
 * @brief    Destination Address Reload Value. The value of this register is loaded into
 *           DMA0_DST upon a count-to-zero condition.
 * @{
 */
#define MXC_F_DMA_DST_RLD_DST_RLD_POS                  0 /**< DST_RLD_DST_RLD Position */
#define MXC_F_DMA_DST_RLD_DST_RLD                      ((uint32_t)(0x7FFFFFFFUL << MXC_F_DMA_DST_RLD_DST_RLD_POS)) /**< DST_RLD_DST_RLD Mask */

/**@} end of group DMA_DST_RLD_Register */

/**
 * @ingroup  dma_registers
 * @defgroup DMA_CNT_RLD DMA_CNT_RLD
 * @brief    DMA Channel Count Reload Register.
 * @{
 */
#define MXC_F_DMA_CNT_RLD_CNT_RLD_POS                  0 /**< CNT_RLD_CNT_RLD Position */
#define MXC_F_DMA_CNT_RLD_CNT_RLD                      ((uint32_t)(0xFFFFFFUL << MXC_F_DMA_CNT_RLD_CNT_RLD_POS)) /**< CNT_RLD_CNT_RLD Mask */

#define MXC_F_DMA_CNT_RLD_RLDEN_POS                    31 /**< CNT_RLD_RLDEN Position */
#define MXC_F_DMA_CNT_RLD_RLDEN                        ((uint32_t)(0x1UL << MXC_F_DMA_CNT_RLD_RLDEN_POS)) /**< CNT_RLD_RLDEN Mask */

/**@} end of group DMA_CNT_RLD_Register */

#ifdef __cplusplus
}
#endif

#endif // LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32520_INCLUDE_DMA_REGS_H_
