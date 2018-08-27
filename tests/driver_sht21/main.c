/*
 * Copyright (C) 2017 RWTH Aachen, Josua Arndt, Steffen Robertz
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     tests
 * @{
 *
 * @file
 * @brief       test aplication for the sht21 temperature and humidity sensor
 *
 * @author      Steffen Robertz <steffen.robertz@rwth-aachen.de>
 * @author      Josua Arndt <jarndt@ias.rwth-aachen.de>
 * @}
 */
#include <stdio.h>
#include "board.h"
#include "periph_conf.h"
#include "sht21.h"
#include "sht21_params.h"
#include "xtimer.h"

int main(void)
{
    sht21_t dev;

    puts("SHT21 test");
    puts("This will test the Temperature and Humidity sensor");
    sht21_init(&dev, sht21_params);
    sht21_write_settings(&dev, SHT21_SETTING_RES_RH12_T14);
    if (sht21_measure(&dev, SHT21_CMD_TEMP) == SHT21_OK && \
        sht21_measure(&dev, SHT21_CMD_HUMIDITY) == SHT21_OK) {
        printf("Temp: %0.2f \n", dev.values.temp);
        printf("Humidity: %0.2f \n", dev.values.rel_humidity);
    }
    else {
        puts("Error while taking measurement");
    }
    puts("Reading settings, enabling chip heater, then re-reading settings");
    puts("The settings byte should change");
    if (sht21_read_settings(&dev) == SHT21_OK) {
        printf("Read_setting: %x \n", dev.values.read_settings);
    }
    if (sht21_write_settings(&dev, SHT21_SETTING_RES_RH12_T14 | SHT21_SETTING_EN_CHIP_HEATER) == SHT21_OK \
        && sht21_read_settings(&dev) == SHT21_OK) {
        printf("Read_setting: %x \n", dev.values.read_settings);
        puts("Chip heater enabled. Refresh every 5s.");
        puts("Temperature should increase, humidity decrease");
        while (1) {
            if (sht21_measure(&dev, SHT21_CMD_TEMP) == SHT21_OK && \
                sht21_measure(&dev, SHT21_CMD_HUMIDITY) == SHT21_OK) {
                printf("Temp: %0.2f \n", dev.values.temp);
                printf("Humidity: %0.2f \n", dev.values.rel_humidity);
            }
            else {
                puts("Error while taking measurement");
            }
            xtimer_sleep(5);
        }
    }
    else {
        puts("Error while reading or writing settings, testcase aborted");
        while (1) {
        }
    }
    return 0;
}
