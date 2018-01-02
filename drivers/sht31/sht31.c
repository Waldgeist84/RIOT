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
 * @brief       Implementation of a device driver for Sensirion SHT31 temperature and humidity sensors
 *
 * @author      Silvia Krug <silvia.krug@imms.de>
 */

#include <string.h>
#include "xtimer.h"

#include "sht31_internals.h"
#include "sht31.h"

#define ENABLE_DEBUG (0)
#include "debug.h"

#define SHT31_I2C     (dev->params.i2c_dev)
#define SHT31_ADDR    (dev->params.address)
#define POLYNOMIAL    (0x31)

/**
 * @brief   Internal helper function to perform a crc check.
 */
static uint8_t _check_crc(uint8_t *data, int len)
{
	/* CRC-8 with polynomial 0x31 (x8 + x5 +x4 +1) */
    uint8_t crc = 0xFF;
  
    for ( int j = len; j; --j ) {
        crc ^= *data++;

        for ( int i = 8; i; --i ) {
	        if ( crc & 0x80 ) {
	            crc = (crc << 1) ^ POLYNOMIAL;
	        }
	        else { 
	            crc = (crc << 1);
	        }
        }
    }
    
    return crc;
}


/**
 * @brief   Internal helper function to perform a measurement. Returns both values.
 */
static int _do_measure(const sht31_t *dev, uint8_t command_a, uint8_t command_b, uint16_t *temperature, uint16_t *rel_humidity)
{
	uint16_t temp;
    uint16_t humidity;
    uint8_t result[6];
    uint8_t out[2];
    out[0] = command_a; 
    out[1] = command_b;
    
    
    i2c_acquire(SHT31_I2C);

    if (i2c_write_bytes(SHT31_I2C, SHT31_ADDR, out, 2) != 2){
        DEBUG("[ERROR] Cannot write command '%x' '%x' to I2C.\n", out[0], out[1]);
    }

    if (i2c_read_bytes(SHT31_I2C, SHT31_ADDR, result, 6) != 6) {
        DEBUG("[ERROR] Cannot read command '%x' '%x' result from I2C.\n", out[0], out[1]);
    }

    i2c_release(SHT31_I2C);

    /* wait until values are available - this setting is valid for high repeadability and can be lower for other settings */
    xtimer_usleep(15 * US_PER_MS);

    temp = result[0];
    temp <<= 8;
    temp |= result[1];

    if (result[2] != _check_crc(result, 2)) {
        DEBUG("[ERROR] CRC Check Failed for T value.\n");
		return -SHT31_ERR_CRC_T;
	}

	*temperature = temp;

    humidity = result[3];
    humidity <<= 8;
    humidity |= result[4];

    out[0] = result[3]; 
    out[1] = result[4];

    if (result[5] != _check_crc(out, 2)) { 
        DEBUG("[ERROR] CRC Check Failed for RH value.\n");
	    return -SHT31_ERR_CRC_RH;
    }

	*rel_humidity = humidity;

    /* reconstruct raw result pair */
    return SHT31_OK;
}


/**
 * @brief   Internal helper function to perform and reconstruct a measurement.
 */
int sht31_reset(const sht31_t *const dev)
{
    uint8_t out[2];
    out[0] = SHT31_SOFTRESET_A; 
    out[1] = SHT31_SOFTRESET_B;
    
    if (i2c_write_bytes(SHT31_I2C, SHT31_ADDR, out, 2) != 2) {
        DEBUG("[ERROR] Cannot reset device.\n");
        i2c_release(SHT31_I2C);
        return SHT31_ERR_I2C;
    }
    
    xtimer_usleep(10* US_PER_MS);
    
    return SHT31_OK;
}


int sht31_init(sht31_t *dev, const sht31_params_t *params)
{
    /* initialize the device descriptor */
    memcpy(&dev->params, params, sizeof(sht31_params_t));

    /* setup the i2c bus */
    i2c_acquire(SHT31_I2C);

    if (i2c_init_master(SHT31_I2C, I2C_SPEED_NORMAL) != 0) {
        DEBUG("[ERROR] Cannot initialize I2C bus.\n");
        i2c_release(SHT31_I2C);
        return -SHT31_ERR_NOI2C;
    }

    /* initialize the peripheral */
    uint8_t out[2];
    out[0] = SHT31_SOFTRESET_A; 
    out[1] = SHT31_SOFTRESET_B;
    
    if (i2c_write_bytes(SHT31_I2C, SHT31_ADDR, out, 2) != 2) {
        DEBUG("[ERROR] Cannot reset device.\n");
        i2c_release(SHT31_I2C);
        return SHT31_ERR_I2C;
    }

    i2c_release(SHT31_I2C);

    /* sensor is ready after at most 10 ms */
    xtimer_usleep(10* US_PER_MS);


    printf("DONE... ");
    DEBUG("[DEBUG] Device initialized with success.\n");
    return SHT31_OK;
}


uint16_t sht31_get_relative_humidity(const sht31_t *dev)
{
	/* resolution is 0.01 % -> scale by 100 */
	
	uint16_t raw_temp;
    uint16_t raw_hum;
    int32_t humidity = -1;

    /* perform measurement */
    int result = _do_measure(dev, SHT31_MEAS_HR_A, SHT31_MEAS_HR_B, &raw_temp, &raw_hum);
    
    if (result != SHT31_ERR_CRC_RH) {
        /* calculation of real value according to datasheet (scaled by 100) */
        humidity = raw_hum;
        humidity *= 10000;
        humidity /= 0xFFFF;
    } 
    
    return (uint16_t) humidity;
}

uint16_t sht31_get_temperature(const sht31_t *dev)
{
	/* resolution 0.015 % */
	uint16_t raw_temp;
    uint16_t raw_hum;
    int32_t temp = -100;
    
    int result = _do_measure(dev, SHT31_MEAS_HR_A, SHT31_MEAS_HR_B, &raw_temp, &raw_hum);
    
    if (result != SHT31_ERR_CRC_T) {
		/* calculation of real value according to datasheet (scaled by 1000) */
        temp = raw_temp;
        temp *= 175000;
        temp /= 0xffff;
        temp = -45000 + temp;	
    }
		
    return (uint16_t) temp;
}

void sht31_get_both(const sht31_t *dev, uint16_t *temperature, uint16_t *humidity)
{
	uint16_t raw_temp;
    uint16_t raw_hum;
    int32_t temp = - 100;
    int32_t hum = -1;

    /* perform measurement */
    int result = _do_measure(dev, SHT31_MEAS_HR_A, SHT31_MEAS_HR_B, &raw_temp, &raw_hum);
    
    if (result != SHT31_ERR_CRC_T) {		
		/* calculation of real value according to datasheet (scaled by 1000) */
        temp = raw_temp;
        temp *= 175000;
        temp /= 0xffff;
        temp = -45000 + temp;	
        
        *temperature = temp;
    }
        
    if (result != SHT31_ERR_CRC_RH) {
        /* calculation of real value according to datasheet (scaled by 100) */
        hum = raw_hum;
        hum *= 10000;
        hum /= 0xFFFF;
  
        *humidity = hum;
	}
}
