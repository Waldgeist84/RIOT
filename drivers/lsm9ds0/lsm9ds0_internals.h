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

#ifndef LSM9DS0_INTERNALS_H
#define LSM9DS0_INTERNALS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief LSM9DS0 chip addresses.
 */
#define LSM9DS0_I2C_ADDRESS           (0x44)

/**
 * @name LSM9DS0 device commands.
 * @{
 */
#define SHT31_MEAS_HR_STRETCH_A     (0x2C)
#define SHT31_MEAS_HR_STRETCH_B     (0x06)
#define SHT31_MEAS_MR_STRETCH_A     (0x2C)
#define SHT31_MEAS_MR_STRETCH_B     (0x0D)
#define SHT31_MEAS_LR_STRETCH_A     (0x2C)
#define SHT31_MEAS_LR_STRETCH_B     (0x10)
#define SHT31_MEAS_HR_A             (0x24)
#define SHT31_MEAS_HR_B             (0x00)
#define SHT31_MEAS_MR_A             (0x24)
#define SHT31_MEAS_MR_B             (0x0B)
#define SHT31_MEAS_LR_A             (0x24)
#define SHT31_MEAS_LR_B             (0x16)
#define SHT31_READSTATUS_A          (0xF3)
#define SHT31_READSTATUS_B          (0x2D)
#define SHT31_CLEARSTATUS_A         (0x30)
#define SHT31_CLEARSTATUS_B         (0x41)
#define SHT31_SOFTRESET_A           (0x30)
#define SHT31_SOFTRESET_B           (0xA2)
#define SHT31_HEATEREN_A            (0x30)
#define SHT31_HEATEREN_B            (0x6D)
#define SHT31_HEATERDIS_A           (0x30)
#define SHT31_HEATERDIS_B           (0x66)
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* LSM9DS0_INTERNALS_H */
/** @} */
