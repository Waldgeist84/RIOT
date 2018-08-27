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
 * @brief LSM9DS0 chip addresses. This uses two addresses as both chip 
 *        are accessed separately.
 */
#define LSM9DS0_XM_I2C_ADDRESS      (0x1D) // Would be 0x1E if SDO_XM is LOW
#define LSM9DS0_G_I2C_ADDRESS       (0x6B) // Would be 0x6A if SDO_G is LOW

/**
 * @name    LSM9DS0 Gyro Registers
 * @{
 */
#define LSM9DS0_WHO_AM_I_G			(0x0F)
#define LSM9DS0_CTRL_REG1_G			(0x20)
#define LSM9DS0_CTRL_REG2_G			(0x21)
#define LSM9DS0_CTRL_REG3_G			(0x22)
#define LSM9DS0_CTRL_REG4_G			(0x23)
#define LSM9DS0_CTRL_REG5_G			(0x24)
#define LSM9DS0_REFERENCE_G			(0x25)
#define LSM9DS0_STATUS_REG_G		(0x27)
#define LSM9DS0_OUT_X_L_G			(0x28)
#define LSM9DS0_OUT_X_H_G			(0x29)
#define LSM9DS0_OUT_Y_L_G			(0x2A)
#define LSM9DS0_OUT_Y_H_G			(0x2B)
#define LSM9DS0_OUT_Z_L_G			(0x2C)
#define LSM9DS0_OUT_Z_H_G			(0x2D)
#define LSM9DS0_FIFO_CTRL_REG_G		(0x2E)
#define LSM9DS0_FIFO_SRC_REG_G		(0x2F)
#define LSM9DS0_INT1_CFG_G			(0x30)
#define LSM9DS0_INT1_SRC_G			(0x31)
#define LSM9DS0_INT1_THS_XH_G		(0x32)
#define LSM9DS0_INT1_THS_XL_G		(0x33)
#define LSM9DS0_INT1_THS_YH_G		(0x34)
#define LSM9DS0_INT1_THS_YL_G		(0x35)
#define LSM9DS0_INT1_THS_ZH_G		(0x36)
#define LSM9DS0_INT1_THS_ZL_G		(0x37)
#define LSM9DS0_INT1_DURATION_G		(0x38)

/**
 * @name    LSM9DS0 Gyro Registers
 * @{
 */
#define LSM9DS0_OUT_TEMP_L_XM		(0x05)
#define LSM9DS0_OUT_TEMP_H_XM		(0x06)
#define LSM9DS0_STATUS_REG_M		(0x07)
#define LSM9DS0_OUT_X_L_M			(0x08)
#define LSM9DS0_OUT_X_H_M			(0x09)
#define LSM9DS0_OUT_Y_L_M			(0x0A)
#define LSM9DS0_OUT_Y_H_M			(0x0B)
#define LSM9DS0_OUT_Z_L_M			(0x0C)
#define LSM9DS0_OUT_Z_H_M			(0x0D)
#define LSM9DS0_WHO_AM_I_XM			(0x0F)
#define LSM9DS0_INT_CTRL_REG_M		(0x12)
#define LSM9DS0_INT_SRC_REG_M		(0x13)
#define LSM9DS0_INT_THS_L_M			(0x14)
#define LSM9DS0_INT_THS_H_M			(0x15)
#define LSM9DS0_OFFSET_X_L_M		(0x16)
#define LSM9DS0_OFFSET_X_H_M		(0x17)
#define LSM9DS0_OFFSET_Y_L_M		(0x18)
#define LSM9DS0_OFFSET_Y_H_M		(0x19)
#define LSM9DS0_OFFSET_Z_L_M		(0x1A)
#define LSM9DS0_OFFSET_Z_H_M		(0x1B)
#define LSM9DS0_REFERENCE_X			(0x1C)
#define LSM9DS0_REFERENCE_Y			(0x1D)
#define LSM9DS0_REFERENCE_Z			(0x1E)
#define LSM9DS0_CTRL_REG0_XM		(0x1F)
#define LSM9DS0_CTRL_REG1_XM		(0x20)
#define LSM9DS0_CTRL_REG2_XM		(0x21)
#define LSM9DS0_CTRL_REG3_XM		(0x22)
#define LSM9DS0_CTRL_REG4_XM		(0x23)
#define LSM9DS0_CTRL_REG5_XM		(0x24)
#define LSM9DS0_CTRL_REG6_XM		(0x25)
#define LSM9DS0_CTRL_REG7_XM		(0x26)
#define LSM9DS0_STATUS_REG_A		(0x27)
#define LSM9DS0_OUT_X_L_A			(0x28)
#define LSM9DS0_OUT_X_H_A			(0x29)
#define LSM9DS0_OUT_Y_L_A			(0x2A)
#define LSM9DS0_OUT_Y_H_A			(0x2B)
#define LSM9DS0_OUT_Z_L_A			(0x2C)
#define LSM9DS0_OUT_Z_H_A			(0x2D)
#define LSM9DS0_FIFO_CTRL_REG		(0x2E)
#define LSM9DS0_FIFO_SRC_REG		(0x2F)
#define LSM9DS0_INT_GEN_1_REG		(0x30)
#define LSM9DS0_INT_GEN_1_SRC		(0x31)
#define LSM9DS0_INT_GEN_1_THS		(0x32)
#define LSM9DS0_INT_GEN_1_DURATION	(0x33)
#define LSM9DS0_INT_GEN_2_REG		(0x34)
#define LSM9DS0_INT_GEN_2_SRC		(0x35)
#define LSM9DS0_INT_GEN_2_THS		(0x36)
#define LSM9DS0_INT_GEN_2_DURATION	(0x37)
#define LSM9DS0_CLICK_CFG			(0x38)
#define LSM9DS0_CLICK_SRC			(0x39)
#define LSM9DS0_CLICK_THS			(0x3A)
#define LSM9DS0_TIME_LIMIT			(0x3B)
#define LSM9DS0_TIME_LATENCY		(0x3C)
#define LSM9DS0_TIME_WINDOW			(0x3D)
#define LSM9DS0_ACT_THS				(0x3E)
#define LSM9DS0_ACT_DUR	            (0x3F)
/** @} */


/** WHO_AM_I values */
#define LSM9DS0_XM_ID               (0b01001001)
#define LSM9DS0_G_ID                (0b11010100)


#ifdef __cplusplus
}
#endif

#endif /* LSM9DS0_INTERNALS_H */
/** @} */
