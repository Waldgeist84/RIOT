/*
 * Copyright (C) 2018 Mid Sweden University.
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 *
 */

/**
 * @defgroup    drivers_lsm9ds0 LSM9DS0 9 DOF motion sensor
 * @ingroup     drivers_sensors
 * @brief       Device driver for the LSM9DS0 9 DOF motion sensor. 
 *              This chip consists of two in package sensors a gyro and
 *              a combined accelerometer/magnetometer
 *          
 * @author      Silvia Krug <siliva.krug@miun.se>
 *
 */

#ifndef LSM9DS0_H
#define LSM9DS0_H

#ifdef __cplusplus
extern "C" {
#endif

#include "periph/i2c.h"

/**
 * @brief   LSM9DS0 interface mode setting
 */
enum lsm9ds0_interface_mode
{
	LSM9DS0_MODE_SPI,
	LSM9DS0_MODE_I2C,
};

/**
 * @brief   LSM9DS0 gyroscope FSR settings
 */
enum lsm9ds0_gyro_scale
{
	LSM9DS0_G_SCALE_245DPS,		// 00:  245 degrees per second
	LSM9DS0_G_SCALE_500DPS,		// 01:  500 dps
	LSM9DS0_G_SCALE_2000DPS,	// 10:  2000 dps
};


/**
 * @brief   LSM9DS0 accelerometer FSR settings
 */
enum lsm9ds0_accel_scale
{
	LSM9DS0_A_SCALE_2G,	// 000:  2g
	LSM9DS0_A_SCALE_4G,	// 001:  4g
	LSM9DS0_A_SCALE_6G,	// 010:  6g
	LSM9DS0_A_SCALE_8G,	// 011:  8g
	LSM9DS0_A_SCALE_16G	// 100:  16g
};

/**
 * @brief   LSM9DS0 magnetometer FSR settings
 */
enum lsm9ds0_mag_scale
{
	LSM9DS0_M_SCALE_2GS,	// 00:  2Gs
	LSM9DS0_M_SCALE_4GS, 	// 01:  4Gs
	LSM9DS0_M_SCALE_8GS,	// 10:  8Gs
	LSM9DS0_M_SCALE_12GS,	// 11:  12Gs
};

/**
 * @brief   LSM9DS0 gryoscope data rate settings
 */
enum lsm9ds0_gyro_odr
{							        // ODR (Hz) --- Cutoff
	LSM9DS0_G_ODR_95_BW_125  = 0x0, //   95         12.5
	LSM9DS0_G_ODR_95_BW_25   = 0x1, //   95          25
	// 0x2 and 0x3 define the same data rate and bandwidth
    LSM9DS0_G_ODR_190_BW_125 = 0x4, //   190        12.5
	LSM9DS0_G_ODR_190_BW_25  = 0x5, //   190         25
	LSM9DS0_G_ODR_190_BW_50  = 0x6, //   190         50
	LSM9DS0_G_ODR_190_BW_70  = 0x7, //   190         70
	LSM9DS0_G_ODR_380_BW_20  = 0x8, //   380         20
	LSM9DS0_G_ODR_380_BW_25  = 0x9, //   380         25
	LSM9DS0_G_ODR_380_BW_50  = 0xA, //   380         50
	LSM9DS0_G_ODR_380_BW_100 = 0xB, //   380         100
	LSM9DS0_G_ODR_760_BW_30  = 0xC, //   760         30
	LSM9DS0_G_ODR_760_BW_35  = 0xD, //   760         35
	LSM9DS0_G_ODR_760_BW_50  = 0xE, //   760         50
	LSM9DS0_G_ODR_760_BW_100 = 0xF, //   760         100
};

/**
 * @brief   LSM9DS0 accelerometer data rate settings
 */
enum lsm9ds0_accel_odr
{
	LSM9DS0_A_POWER_DOWN, 	// Power-down mode (0x0)
	LSM9DS0_A_ODR_3125,		//    3.125 Hz	   (0x1)
	LSM9DS0_A_ODR_625,		//    6.25 Hz      (0x2)
	LSM9DS0_A_ODR_125,		//   12.5 Hz       (0x3)
	LSM9DS0_A_ODR_25,		//   25 Hz         (0x4)
	LSM9DS0_A_ODR_50,		//   50 Hz         (0x5)
	LSM9DS0_A_ODR_100,		//  100 Hz         (0x6)
	LSM9DS0_A_ODR_200,		//  200 Hz         (0x7)
	LSM9DS0_A_ODR_400,		//  400 Hz         (0x8)
	LSM9DS0_A_ODR_800,		//  800 Hz         (0x9)
	LSM9DS0_A_ODR_1600		// 1600 Hz         (0xA)
};


/**
 * @brief   LSM9DS0 accelerometer anti-aliasing filter rate settings
 */
enum lsm9ds0_accel_abw
{
	LSM9DS0_A_ABW_773,		// 773 Hz (0x0)
	LSM9DS0_A_ABW_194,		// 194 Hz (0x1)
	LSM9DS0_A_ABW_362,		// 362 Hz (0x2)
	LSM9DS0_A_ABW_50,		//  50 Hz (0x3)
};


/**
 * @brief   LSM9DS0 magnetometer data rate settings
 */
enum lsm9ds0_mag_odr
{
	LSM9DS0_M_ODR_3125,	//   3.125 Hz (0x00)
	LSM9DS0_M_ODR_625,	//   6.25 Hz  (0x01)
	LSM9DS0_M_ODR_125,	//  12.5 Hz   (0x02)
	LSM9DS0_M_ODR_25,	//  25 Hz     (0x03)
	LSM9DS0_M_ODR_50,	//  50 Hz     (0x04)
	LSM9DS0_M_ODR_100,	// 100 Hz     (0x05)
};



/**
 * @brief   LSM9DS0 driver parameters
 */
typedef struct {
    i2c_t i2c;                  /**< i2c bus */
    uint8_t addr_xm;            /**< i2c address of acc/mag */
    uint8_t addr_g;             /**< i2c address of gyro */
    uint8_t acc_odr;            /**< accelerometer output data rate */
    uint8_t gyro_odr;           /**< gyroscope output data rate */
    uint8_t mag_odr;            /**< magnetometer output data rate */
    uint8_t acc_fs;             /**< accelerometer full scale */
    uint8_t gyro_fs;            /**< gyroscope full scale */
    uint8_t mag_fs;             /**< magnetometer full scale */
} lsm9ds0_params_t;

/**
 * @brief   LSM9DS0 device descriptor
 */
typedef struct {
    lsm9ds0_params_t params; /**< driver parameters */
} lsm9ds0_t;

/**
 * @brief   3D output data
 */
typedef struct {
    int16_t x;  /**< X axis */
    int16_t y;  /**< Y axis */
    int16_t z;  /**< Z axis */
} lsm9ds0_3d_data_t;

/**
 * @brief   Named return values
 */
enum {
    LSM9DS0_OK = 0,             /**< all good */
    LSM9DS0_ERROR_BUS,          /**< I2C bus error */
    LSM9DS0_ERROR_CNF,          /**< Config error */
    LSM9DS0_ERROR_DEV,          /**< device error */
};

/**
 * @brief   Initialize a LSM9DS0 device
 *
 * @param[out] dev     device to initialize
 * @param[in] params  driver parameters
 *
 * @return LSM9DS0_OK on success
 * @return < 0 on error
 */
int lsm9ds0_init(lsm9ds0_t *dev, const lsm9ds0_params_t *params);

/**
 * @brief   Read accelerometer data
 *
 * @param[in] dev    device to read
 * @param[out] data  accelerometer values
 *
 * @return LSM9DS0_OK on success
 * @return < 0 on error
 */
int lsm9ds0_read_acc(const lsm9ds0_t *dev, lsm9ds0_3d_data_t *data);

/**
 * @brief   Read gyroscope data
 *
 * @param[in] dev    device to read
 * @param[out] data  gyroscope values
 *
 * @return LSM9DS0_OK on success
 * @return < 0 on error
 */
int lsm9ds0_read_gyro(const lsm9ds0_t *dev, lsm9ds0_3d_data_t *data);

/**
 * @brief   Read temperature data
 *
 * @note To avoid floating point data types but still provide high resolution
 *       for temperature readings, resulting values are scale by factor 100.
 *
 *
 * @param[in] dev    device to read
 * @param[out] data  temperature value, in °C x 100
 *
 * @return LSM9DS0_OK on success
 * @return < 0 on error
 */
int lsm9ds0_read_temp(const lsm9ds0_t *dev, int16_t *data);

/**
 * @brief   Power down accelerometer
 *
 * @param[in] dev    device to power down
 *
 * @return LSM9DS0_OK on success
 * @return < 0 on error
 */
int lsm9ds0_acc_power_down(const lsm9ds0_t *dev);

/**
 * @brief   Power down gyroscope
 *
 * @param[in] dev    device to power down
 *
 * @return LSM9DS0_OK on success
 * @return < 0 on error
 */
int lsm9ds0_gyro_power_down(const lsm9ds0_t *dev);

/**
 * @brief   Power up accelerometer
 *
 * @param[in] dev    device to power up
 *
 * @return LSM9DS0_OK on success
 * @return < 0 on error
 */
int lsm9ds0_acc_power_up(const lsm9ds0_t *dev);

/**
 * @brief   Power up gyroscope
 *
 * @param[in] dev    device to power up
 *
 * @return LSM9DS0_OK on success
 * @return < 0 on error
 */
int lsm9ds0_gyro_power_up(const lsm9ds0_t *dev);

#ifdef __cplusplus
}
#endif

#endif /* LSM9DSL_H */
/** @} */
