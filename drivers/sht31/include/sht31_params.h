/*
 * Copyright (C) 2017 IMMS Institut fuer Mikroelektronik- und Mechatronik-Systeme gemeinnuetzige GmbH. 
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     drivers_sht31
 *
 * @{
 * @file
 * @brief       Default configuration for SHT31
 *
 * @author      Silvia Krug <silvia.krug@imms.de>
 */

#ifndef SHT31_PARAMS_H
#define SHT31_PARAMS_H

#include "board.h"
#include "sht31.h"
//#include "saul_reg.h"
#include "sht31_internals.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    Set default configuration parameters for the SHT31 sensor
 * @{
 */
#ifndef SHT31_PARAM_I2C_DEV
#define SHT31_PARAM_I2C_DEV          I2C_DEV(0)
#endif
#ifndef SHT31_PARAM_ADDR
#define SHT31_PARAM_ADDR             SHT31_I2C_ADDRESS
#endif

#ifndef SHT31_PARAMS
#define SHT31_PARAMS                 { .i2c_dev = SHT31_PARAM_I2C_DEV,  \
                                       .address = SHT31_PARAM_ADDR }
#endif
//#ifndef SHT31_SAUL_INFO
//#define SHT31_SAUL_INFO              { .name = "sht31" }
//#endif
/**@}*/

/**
 * @brief   Configure SHT31
 */
static const sht31_params_t sht31_params[] =
{
    SHT31_PARAMS
};

// /**
// * @brief   Configure SAUL registry entries
// */
//static const saul_reg_info_t sht31_saul_reg_info[] =
//{
//    SHT31_SAUL_INFO
//};

#ifdef __cplusplus
}
#endif

#endif /* SHT31_PARAMS_H */
/** @} */
