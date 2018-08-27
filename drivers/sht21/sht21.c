/*
 * Copyright (C) 2017 RWTH Aachen
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     drivers_sht21
 * @{
 *
 * @file
 * @brief       Device driver implementation for the Sensirion SHT21 temperature and humidity sensor
 *
 * @author      Steffen Robertz <steffen.robertz@rwth-aachen.de>
 * @author      Josua Arndt <jarndt@ias.rwth-aachen.de>
 * @}
 */

#define ENABLE_DEBUG    (0)
#include "debug.h"
#include "sht21_regs.h"
#include "sht21.h"

/*
 * does a crc check and returns 0 for passed. Anthing else for failed
 */
uint8_t _check_crc(uint8_t *rec_values, uint8_t right_crc)
{
    uint8_t crc = 0x00;
    uint8_t current_byte;
    uint8_t bit;

    for (current_byte = 0; current_byte < 2; current_byte++) {
        crc ^= (rec_values[current_byte]);
        for (bit = 8; bit > 0; bit--) {
            if (crc & 0x80) {
                crc = (crc << 1) ^ SHT21_CRC_POLYNOMIAL;
            }
            else {
                crc = (crc << 1);
            }
        }
    }
    return !(crc == right_crc);
}

uint8_t sht21_init(sht21_t *const dev, const sht21_params_t *const params)
{
    assert(dev && params);
    /* copy settings into device descriptor */
    dev->bus = params->bus;
    dev->addr = params->addr;
    dev->crc = params->crc;
    dev->set_settings = params->set_settings;
    /* initalize I2C bus */
    i2c_acquire(dev->bus);
    int8_t error = i2c_init_master(dev->bus, I2C_SPEED_FAST);
    i2c_release(dev->bus);
    return (error == 0) ? SHT21_OK : SHT21_ERROR;
}

uint8_t sht21_measure(sht21_t *const dev, const uint8_t cmd)
{
    /* Check for right command */
    if (!(cmd == SHT21_CMD_TEMP || cmd == SHT21_CMD_HUMIDITY)) {
        DEBUG("Invalid measurement command %x \n", cmd);
        return SHT21_ERROR;
    }
    /* read requested value from sensor */
    uint8_t received[3];
    i2c_acquire(dev->bus);
    i2c_read_regs(dev->bus, dev->addr, cmd, received, 3);
    i2c_release(dev->bus);
    /* Verify Checksum */
    if (dev->crc) {
        if ((_check_crc(received, received[2]))) {
            DEBUG("CRC Error\n");
            return SHT21_ERROR;
        }
        DEBUG("CRC Passed! \n");
    }
    /* Convert raw data to value in either °C or % */
    uint16_t value = ((received[0] << 8) | received[1]);
    if (cmd == SHT21_CMD_TEMP) {
        dev->values.temp =  (((float)(value & 0xfffc) / 65536) * 175.72 - 46.85);
    }
    else {
        dev->values.rel_humidity = (((float)(value & 0xfffc) / 65536) * 125 - 6);
    }

    return SHT21_OK;
}

int8_t sht21_reset(const sht21_t *const dev)
{
    /* send reset command */
    i2c_acquire(dev->bus);
    int8_t check = i2c_write_byte(dev->bus, dev->addr, SHT21_CMD_RESET);
    i2c_release(dev->bus);
    /* check how many bytes were written to the bus for verification */
    return (check == 1) ? SHT21_OK : SHT21_ERROR;
}

uint8_t sht21_read_settings(sht21_t *const dev)
{
    /* send the read settings command */
    i2c_acquire(dev->bus);
    uint8_t check = i2c_read_reg(dev->bus, dev->addr, SHT21_CMD_SETTINGS_READ, &(dev->values.read_settings));
    i2c_release(dev->bus);
    /* check how many bytes were written to the bus for verification */
    return (check == 1) ? SHT21_OK : SHT21_ERROR;
}

uint8_t sht21_write_settings(const sht21_t *const dev, const uint8_t setting)
{
    /* write settings to sensor */
    i2c_acquire(dev->bus);
    uint8_t check = i2c_write_reg(dev->bus, dev->addr, SHT21_CMD_SETTINGS_WRITE, setting);
    i2c_release(dev->bus);
    /* check how many bytes were written to the bus for verification */
    return (check == 1) ? SHT21_OK : SHT21_ERROR;
}

uint8_t sht21_is_end_of_battery(sht21_t *const dev)
{
    return ((sht21_read_settings(dev) & SHT21_MASK_END_OF_BAT) >> 6);
}
