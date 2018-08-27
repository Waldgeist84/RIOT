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

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    Set default configuration parameters
 * @{
 */
#ifndef LSM6DSL_PARAM_I2C
#define LSM6DSL_PARAM_I2C            I2C_DEV(0)
#endif
#ifndef LSM6DSL_PARAM_ADDR
#define LSM6DSL_PARAM_ADDR           (0x6B) /* (0x6A) */
#endif
#ifndef LSM6DSL_PARAM_ACC_ODR
#define LSM6DSL_PARAM_ACC_ODR        (LSM6DSL_DATA_RATE_52HZ)
#endif
#ifndef LSM6DSL_PARAM_GYRO_ODR
#define LSM6DSL_PARAM_GYRO_ODR       (LSM6DSL_DATA_RATE_52HZ)
#endif
#ifndef LSM6DSL_PARAM_ACC_FS
#define LSM6DSL_PARAM_ACC_FS         (LSM6DSL_ACC_FS_2G)
#endif
#ifndef LSM6DSL_PARAM_GYRO_FS
#define LSM6DSL_PARAM_GYRO_FS        (LSM6DSL_GYRO_FS_245DPS)
#endif
#ifndef LSM6DSL_PARAM_ACC_FIFO_DEC
#define LSM6DSL_PARAM_ACC_FIFO_DEC   (LSM6DSL_DECIMATION_NO)
#endif
#ifndef LSM6DSL_PARAM_GYRO_FIFO_DEC
#define LSM6DSL_PARAM_GYRO_FIFO_DEC  (LSM9DS0_DECIMATION_NO)
#endif

#ifndef LSM9DS0_PARAMS
#define LSM9DS0_PARAMS               { .i2c             = LSM9DS0_PARAM_I2C,          \
                                       .addr            = LSM9DS0_PARAM_ADDR,         \
                                       .acc_odr         = LSM9DS0_PARAM_ACC_ODR,      \
                                       .gyro_odr        = LSM9DS0_PARAM_GYRO_ODR,     \
                                       .acc_fs          = LSM9DS0_PARAM_ACC_FS,       \
                                       .gyro_fs         = LSM9DS0_PARAM_GYRO_FS,      \
                                       .acc_decimation  = LSM9DS0_PARAM_ACC_FIFO_DEC, \
                                       .gyro_decimation = LSM9DS0_PARAM_GYRO_FIFO_DEC }
#endif
#ifndef LSM9DS0_SAUL_INFO
#define LSM9DS0_SAUL_INFO            { .name = "lsm6dsl" }
#endif
/** @} */

/**
 * @brief   Allocate some memory to store the actual configuration
 */
static const lsm6dsl_params_t lsm6dsl_params[] =
{
    LSM9DS0_PARAMS
};

/**
 * @brief   Additional meta information to keep in the SAUL registry
 */
static const saul_reg_info_t lsm6dsl_saul_info[] =
{
    LSM9DS0_SAUL_INFO
};

#ifdef __cplusplus
}
#endif

#endif /* LSM9DS0_PARAMS_H */
/** @} */
