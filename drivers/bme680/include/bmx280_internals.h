/*
 * Copyright (C) 2018 Silvia Krug, Mid Sweden University
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     drivers_bme680
 * @brief       Internal addresses, registers, constants for the BME680 sensor.
 * @{
 * @file
 * @brief       Internal addresses, registers, constants for the BME680 sensor.
 *
 * @author      Silvia Krug <silvia.krug@miun.se>
 */

#ifndef BMX680_INTERNALS_H
#define BMX680_INTERNALS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    BME680 registers
 * @{
 */
#define BME280_CHIP_ID                          0x60    /* The identifier of the BME280 */
#define BMP280_CHIP_ID                          0x58    /* The identifier of the BMP280 */
#define BMX280_CHIP_ID_REG                      0xD0
#define BME680_RST_REG                          0xE0 /* Softreset Reg */

#define BMX280_DIG_T1_LSB_REG                   0x88
#define BMX280_DIG_T1_MSB_REG                   0x89
#define BMX280_DIG_T2_LSB_REG                   0x8A
#define BMX280_DIG_T2_MSB_REG                   0x8B
#define BMX280_DIG_T3_LSB_REG                   0x8C
#define BMX280_DIG_T3_MSB_REG                   0x8D
#define BMX280_DIG_P1_LSB_REG                   0x8E
#define BMX280_DIG_P1_MSB_REG                   0x8F
#define BMX280_DIG_P2_LSB_REG                   0x90
#define BMX280_DIG_P2_MSB_REG                   0x91
#define BMX280_DIG_P3_LSB_REG                   0x92
#define BMX280_DIG_P3_MSB_REG                   0x93
#define BMX280_DIG_P4_LSB_REG                   0x94
#define BMX280_DIG_P4_MSB_REG                   0x95
#define BMX280_DIG_P5_LSB_REG                   0x96
#define BMX280_DIG_P5_MSB_REG                   0x97
#define BMX280_DIG_P6_LSB_REG                   0x98
#define BMX280_DIG_P6_MSB_REG                   0x99
#define BMX280_DIG_P7_LSB_REG                   0x9A
#define BMX280_DIG_P7_MSB_REG                   0x9B
#define BMX280_DIG_P8_LSB_REG                   0x9C
#define BMX280_DIG_P8_MSB_REG                   0x9D
#define BMX280_DIG_P9_LSB_REG                   0x9E
#define BMX280_DIG_P9_MSB_REG                   0x9F

#define BME280_DIG_H1_REG                       0xA1
#define BME280_DIG_H2_LSB_REG                   0xE1
#define BME280_DIG_H2_MSB_REG                   0xE2
#define BME280_DIG_H3_REG                       0xE3
#define BME280_DIG_H4_MSB_REG                   0xE4 /* H4[11:4] */
#define BME280_DIG_H4_H5_REG                    0xE5 /* H5[3:0]  H4[3:0] */
#define BME280_DIG_H5_MSB_REG                   0xE6 /* H5[11:4] */
#define BME280_DIG_H6_REG                       0xE7

#define BMX280_STAT_REG                         0xF3 /* Status Reg */
#define BMX280_CTRL_MEAS_REG                    0xF4 /* Ctrl Measure Reg */
#define BMX280_CONFIG_REG                       0xF5 /* Configuration Reg */
#define BMX280_PRESSURE_MSB_REG                 0xF7 /* Pressure MSB */
#define BMX280_PRESSURE_LSB_REG                 0xF8 /* Pressure LSB */
#define BMX280_PRESSURE_XLSB_REG                0xF9 /* Pressure XLSB */
#define BMX280_TEMPERATURE_MSB_REG              0xFA /* Temperature MSB */
#define BMX280_TEMPERATURE_LSB_REG              0xFB /* Temperature LSB */
#define BMX280_TEMPERATURE_XLSB_REG             0xFC /* Temperature XLSB */
#define BME280_CTRL_HUMIDITY_REG                0xF2 /* Ctrl Humidity Reg */
#define BME280_HUMIDITY_MSB_REG                 0xFD /* Humidity MSB */
#define BME280_HUMIDITY_LSB_REG                 0xFE /* Humidity LSB */
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* BME680_INTERNALS_H */
/** @} */
