/*
 * Copyright 2017, RWTH Aachen. All rights reserved.
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     drivers_sht21
 * @name        Register definition for the SHT21 Temperature and humidity sensor
 * @{
 *
 * @file
 * @brief       Register definition for the SHT21 Temperature and humidity sensor
 *
 * @author      Steffen Robertz <steffen.robertz@rwth-aachen.de>
 * @author      Josua Arndt <jarndt@ias.rwth-aachen.de>
 */

#ifndef SHT21_REGS_H
#define SHT21_REGS_H

#ifdef __cplusplus 
extern "C" {
#endif

#define SHT21_SETTING_RES_RH12_T14          0x00
#define SHT21_SETTING_RES_RH8_T12           0x01
#define SHT21_SETTING_RES_RH10_T13          0x80
#define SHT21_SETTING_RES_RH11_T11          0x81
#define SHT21_SETTING_EN_CHIP_HEATER        0x04
#define SHT21_SETTING_DIS_OTP_RELOAD        0x02

#define SHT21_MASK_END_OF_BAT               0x40

#define SHT21_CMD_SETTINGS_READ             0xE7
#define SHT21_CMD_SETTINGS_WRITE            0xE6
#define SHT21_CMD_RESET                     0xFE
#define SHT21_CMD_TEMP                      0xE3
#define SHT21_CMD_HUMIDITY                  0xE5

#define SHT21_CRC_POLYNOMIAL                0x31

#ifdef __cplusplus
}
#endif
#endif /* SHT21_REGS_H */
/** @} */
