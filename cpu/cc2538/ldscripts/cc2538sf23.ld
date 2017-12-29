/*
 * Copyright (C) 2017 IMMS Ilmenau
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @addtogroup      cpu_cc2538
 * @{
 *
 * @file
 * @brief           Linker script for the CC2538SF23
 *
 * @author          Silvia Krug <silvia.krug@imms.de>
 */

/* Memory Space Definitions: */
MEMORY
{
    rom   (rx ) : ORIGIN = 0x00200000, LENGTH = 0x0003ffd4
    cca   (rx ) : ORIGIN = 0x0023ffd4, LENGTH = 0x2c
    ram   (rwx) : ORIGIN = 0x20000000, LENGTH = 32K
}

/* MCU Specific Section Definitions */
SECTIONS
{
    .flashcca :
    {
        KEEP(*(.flashcca))
    } > cca
}

INCLUDE cortexm_base.ld

/* @} */
