/*
 * Copyright 2017, RWTH Aachen. All rights reserved.
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     drivers_sht21
 * @name        Default parameters for the SHT21 Temperature and humidity sensor
 * @{
 *
 * @file
 * @brief       Default parameters for the SHT21 Temperature and humidity sensor
 *
 * @author      Steffen Robertz <steffen.robertz@rwth-aachen.de>
 * @author      Josua Arndt <jarndt@ias.rwth-aachen.de>
 */

#ifndef SHT21_PARAMS_H
#define SHT21_PARAMS_H

#include "board.h"
#include "sht21.h"
#include "sht21_regs.h"

#ifdef __cplusplus 
extern "C" {
#endif

/**
 * @brief   Default configuration parameters for SHT21 sensors
 * @{
 */
#ifndef SHT21_PARAM_I2C
#define SHT21_PARAM_I2C        (I2C_DEV(0))
#endif
#ifndef SHT21_PARAM_ADDR
#define SHT21_PARAM_ADDR       (0x40)
#endif
#ifndef SHT21_PARAM_CRC
#define SHT21_PARAM_CRC        (CRC_ENABLED)
#endif
#ifndef SHT21_PARAM_SETTING
#define SHT21_PARAM_SETTING    (0x00) /*SHT21_SETTINGS_RES_RH12_T14 */
#endif

#ifndef SHT21_PARAMS
#define SHT21_PARAMS           { .bus = SHT21_PARAM_I2C, \
                                 .addr = SHT21_PARAM_ADDR, \
                                 .crc = SHT21_PARAM_CRC, \
                                 .set_settings = SHT21_PARAM_SETTING }
#endif
/** @} */

/**
 * @brief   Allocation of SHT21 configuration
 */
static const sht21_params_t sht21_params[] = {
    #ifdef SHT21_PARAMS_BOARD
        SHT21_PARAMS_BOARD
    #else
        SHT21_PARAMS
    #endif
};
#ifdef __cplusplus
}
#endif
#endif /*SHT21_PARAMS_C*/
/** @} */
