/*
 * Copyright (C) 2017 IMMS Institut fuer Mikroelektronik- und Mechatronik-Systeme gemeinnuetzige GmbH. 
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    drivers_sht31 SHT31 temperature and humidity sensor
 * @ingroup     drivers_sensors
 * @brief       Driver for the SHT31 temperature and humidity sensor.
 * @{
 *
 * @file
 * @brief       Interface definition of the SHT31 driver.
 *
 * @author      Silvia Krug <silvia.krug@imms.de>
 */

#ifndef SHT31_H
#define SHT31_H

#include "periph/i2c.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Driver return codes
 */
enum {
    SHT31_OK,                 /**< All OK */
    SHT31_ERR_NOI2C,          /**< An error occurred when initializing I2C bus */
    SHT31_ERR_NODEV,          /**< No valid device found on I2C bus */
    SHT31_ERR_I2C,            /**< An error occured when reading/writing on I2C bus */
    SHT31_ERR_CRC_T,          /**< An error occured when checking the CRC for temperature */
    SHT31_ERR_CRC_RH,         /**< An error occured when checking the CRC for relative humidity */
};

/**
 * @brief Device initialization parameters.
 */
typedef struct {
    i2c_t i2c_dev;              /**< I2C bus the sensor is connected to */
    uint8_t address;            /**< sensor address */
} sht31_params_t;

/**
 * @brief SHT31 device descriptor.
 */
typedef struct {
    sht31_params_t params;     /**< Device parameters */
} sht31_t;

/**
 * @brief   Initialize and reset the sensor.
 *
 * @param[in] dev           device descriptor
 * @param[in] params        initialization parameters
 *
 * @return                  -SHT31_OK on successful initialization
 * @return                  -SHT31_ERR_NOI2C on I2C initialization error
 * @return                  -SHT31_ERR_NODEV on device test error
 * @return                  -SHT31_ERR_I2C on I2C bus error
 */
int sht31_init(sht31_t *dev, const sht31_params_t *params);

/**
 * @brief   Read the relative humidity from the sensor. Uses clock streching.
 *
 * @param[in] dev           device descriptor
 * @return                  relative humidity in centi-percent (times 100)
 */
uint16_t sht31_get_relative_humidity(const sht31_t *dev);

/**
 * @brief   Read the current temperature from the sensor. Uses clock streching.
 *
 * @param[in] dev           device descriptor
 * @return                  current temperature in 1.5 centi-degrees Celsius
 *                          (times 1000)
 */
uint16_t sht31_get_temperature(const sht31_t *dev);

/**
 * @brief   Read the relative humidity and temperature from the sensor. Uses
 *          clock stretching.
 *
 * @param[in] dev           device descriptor
 * @param[out] humidity     pointer to relative humidity (in centi-percent)
 * @param[out] temperature  pointer to temperature (in 1.5 centi-degrees Celsius)
 */
void sht31_get_both(const sht31_t *dev, uint16_t *temperature, uint16_t *humidity);


/**
 * @brief   Resets sensor
 *
 * @param[in] dev       Device descriptor
 *
 * @return              SHT21_OK on success
 * @return              SHT21_ERROR on error
 */
int sht31_reset(const sht31_t *dev);

#ifdef __cplusplus
}
#endif

#endif /* SHT31_H */
/** @} */
