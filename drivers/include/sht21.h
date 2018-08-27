/*
 * Copyright (C) 2017 RWTH Aachen
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    drivers_sht21
 * @ingroup     drivers_sensors
 * @brief       Device driver interface for the Sensirion SHT21 Humidity and Temp Sensor
 * @{
 *
 * @file
 * @brief       Device driver interface for the SHT21 Humidity and Temperature Sensor
 *
 * @author      Steffen Robertz <steffen.robertz@rwth-aachen.de>
 * @author      Josua Arndt <jarndt@ias.rwth-aachen.de>
 */

#ifndef SHT21_H
#define SHT21_H

#include <stdint.h>
#include "periph/i2c.h"
#include "sht21_regs.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    CRC_DISABLED = 0,
    CRC_ENABLED
}sht21_crc_type_t;

typedef struct {
    float temp;
    float rel_humidity;
    uint8_t read_settings;
} sht21_values_t;

typedef struct {
    i2c_t bus;
    uint8_t addr;
    sht21_crc_type_t crc;
    uint8_t set_settings;
} sht21_params_t;

typedef struct {
    i2c_t bus;
    uint8_t addr;
    sht21_values_t values;
    sht21_crc_type_t crc;
    uint8_t set_settings;
} sht21_t;

enum {
    SHT21_OK = 0,
    SHT21_ERROR = -1
};

/**
 * @brief Initializes the sensor and I2C
 *
 * @param[in] dev       Device descriptor
 * @param[in] params    SHTC1 parameters to be used	
 *
 * @return              SHT21_OK on success
 * @return              SHT21_ERROR on error
 */
uint8_t sht21_init(sht21_t* const dev, const sht21_params_t* const params);

/**
 * @brief   Reads temperature or humidity values
 * @details The measurements will be saved in the values struct within the device descriptor in °C/%
 *
 * @param[in] dev       Device descriptor
 * @param[in] cmd       Measurement command (SHT21_CMD_TEMP/SHT21_CMD_HUMIDITY)
 *
 * @return              SHT21_OK on success
 * @return              SHT21_ERROR on error
 */
uint8_t sht21_measure(sht21_t* const dev, const uint8_t cmd);

/**
 * @brief   Resets sensor
 * @details Resets the internal state machines and reloads calibration data from the memory
 *
 * @param[in] dev       Device descriptor
 *
 * @return              SHT21_OK on success
 * @return              SHT21_ERROR on error
 */
int8_t sht21_reset(const sht21_t* const dev);

/**
 * @brief Read the settings register
 *
 * @param[in] dev       Device descriptor
 *
 * @return              SHT21_OK on success
 * @return              SHT21_ERROR on error
 */
uint8_t sht21_read_settings(sht21_t* const dev);

/**
 * @brief Write the settings register
 *
 * @param[in] dev       Device descriptor
 * @param[in] setting   Settings byte
 *
 * @return              SHT21_OK on success
 * @return              SHT21_ERROR on error
 */
uint8_t sht21_write_settings(const sht21_t* const dev, const uint8_t setting);

/**
 * @brief Checks if the battery is getting empty
 *
 * @param[in] dev       Device descriptor
 *
 * @return              0 VDD > 2.25V
 * @return              1 VDD < 2.25V
 */
uint8_t sht21_is_end_of_battery(sht21_t* const dev);

#ifdef __cplusplus
}
#endif

#endif /*SHT21_H*/
/** @} */
