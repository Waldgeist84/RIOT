/*
 * Copyright (C) 2017 IMMS Institut fuer Mikroelektronik- und Mechatronik-Systeme gemeinnuetzige GmbH. 
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
 * @brief       Test application for the SHT31 sensor driver
 *
 * @author      Silvia Krug <silvia.krug@imms.de>
 *
 * @}
 */

#include <stdio.h>

#include "xtimer.h"

#include "sht31_params.h"
#include "sht31.h"

int main(void)
{
    sht31_t dev;

    puts("SHT31 temperature and humidity sensor test application");

    /* initialize the sensor */
    printf("Initializing sensor... ");

    if (sht31_init(&dev, &sht31_params[0]) == 0) {
        puts("[OK]");
    }
    else {
        puts("[Failed]");
        return 1;
    }

    /* read temperature and humidity every 1 seconds */
    bool both = false;

    uint16_t temperature;
    uint16_t humidity;

    while (1) {
        /* rotate the way of getting the data */
        if (both) {
            sht31_get_both(&dev, &temperature, &humidity);
        }
        else {
            temperature = sht31_get_temperature(&dev);
            humidity = sht31_get_relative_humidity(&dev);
        }

        both = !both;

        
        /* display results */
        printf("relative humidity: %d.%02d\n", humidity / 100, humidity % 100);
        printf("temperature: %d.%03d C\n", temperature / 1000, temperature % 1000);

        /* sleep between measurements */
        xtimer_usleep(1000 * US_PER_MS);
    }

    return 0;
}
