/*
 * Copyright (C) 2018 Mid Sweden University 
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     drivers_lsm9ds0
 *
 * @{
 * @file
 * @brief       Default configuration for LSM9DS0
 *
 * @author      Silvia Krug <silvia.krug@miun.se>
 */
 
#ifndef LSM9DS0_PARAMS_H
#define LSM9DS0_PARAMS_H

#include "board.h"
#include "lsm9ds0.h"
#include "saul_reg.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    Set default configuration parameters
 * @{
 */
#ifndef LSM9DS0_PARAM_I2C
#define LSM9DS0_PARAM_I2C            I2C_DEV(0)
#endif
#ifndef LSM9DS0_PARAM_ADDR_XM
#define LSM9DS0_PARAM_ADDR_XM        (0x1D) /* (0x1E) */
#endif
#ifndef LSM9DS0_PARAM_ADDR_G
#define LSM9DS0_PARAM_ADDR_G         (0x6B) /* (0x6A) */
#endif
#ifndef LSM9DS0_PARAM_ACC_ODR
#define LSM9DS0_PARAM_ACC_ODR        (LSM9DS0_A_ODR_50)
#endif
#ifndef LSM9DS0_PARAM_MAG_ODR
#define LSM9DS0_PARAM_MAG_ODR        (LSM9DS0_M_ODR_50)
#endif
#ifndef LSM9DS0_PARAM_GYRO_ODR
#define LSM9DS0_PARAM_GYRO_ODR       (LSM9DS0_G_ODR_95_BW_125)
#endif
#ifndef LSM9DS0_PARAM_ACC_FS
#define LSM9DS0_PARAM_ACC_FS         (LSM9DS0_A_SCALE_2G)
#endif
#ifndef LSM9DS0_PARAM_MAG_FS
#define LSM9DS0_PARAM_MAG_FS         (LSM9DS0_M_SCALE_2GS)
#endif
#ifndef LSM9DS0_PARAM_GYRO_FS
#define LSM9DS0_PARAM_GYRO_FS        (LSM9DS0_G_SCALE_245DPS)
#endif

#ifndef LSM9DS0_PARAMS
#define LSM9DS0_PARAMS               { .i2c             = LSM9DS0_PARAM_I2C,          \
                                       .addr_xm         = LSM9DS0_PARAM_ADDR_XM,      \
                                       .addr_g          = LSM9DS0_PARAM_ADDR_G,       \
                                       .acc_odr         = LSM9DS0_PARAM_ACC_ODR,      \
                                       .mag_odr         = LSM9DS0_PARAM_MAG_ODR,      \
                                       .gyro_odr        = LSM9DS0_PARAM_GYRO_ODR,     \
                                       .acc_fs          = LSM9DS0_PARAM_ACC_FS,       \
                                       .mag_fs          = LSM9DS0_PARAM_MAG_FS,       \
                                       .gyro_fs         = LSM9DS0_PARAM_GYRO_FS,      }
#endif
#ifndef LSM9DS0_SAUL_INFO
#define LSM9DS0_SAUL_INFO            { .name = "lsm9ds0" }
#endif
/** @} */

/**
 * @brief   Allocate some memory to store the actual configuration
 */
static const lsm6dsl_params_t lsm9ds0_params[] =
{
    LSM9DS0_PARAMS
};

/**
 * @brief   Additional meta information to keep in the SAUL registry
 */
static const saul_reg_info_t lsm9ds0_saul_info[] =
{
    LSM9DS0_SAUL_INFO
};

#ifdef __cplusplus
}
#endif

#endif /* LSM9DS0_PARAMS_H */
/** @} */
