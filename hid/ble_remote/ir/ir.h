/*
 * Copyright 2016-2020, Cypress Semiconductor Corporation or a subsidiary of
 * Cypress Semiconductor Corporation. All Rights Reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software"), is owned by Cypress Semiconductor Corporation
 * or one of its subsidiaries ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products. Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */

/** @file
 *
 * This file defines the interface of Infrared (IR) Transmit feature
 *
 */

#ifndef __BLEAPP_APPIRTX_H__
#define __BLEAPP_APPIRTX_H__

#ifdef REMOTE_PLATFORM
 #define IR_TX_GPIO           WICED_P38
#else
 #define IR_TX_GPIO           WICED_P15 // P38 not available on 62-pin package
#endif

#ifdef SUPPORT_IR
 #include "wiced.h"
 #include "wiced_irtx.h"
 void ir_init(BYTE gpio);
 void ir_start(uint8_t code, uint8_t repeat_count);
 void ir_stop();
 wiced_bool_t ir_button(uint8_t key, wiced_bool_t down);
 #define ir_is_active() (!wiced_irtx_is_available())
#else
 #define ir_init(gpio)
 #define ir_start(code, repeat)
 #define ir_stop()
 #define ir_button(key, down) FALSE
 #define ir_is_active() FALSE
#endif //SUPPORT_IR

#endif // __BLEAPP_APPIRTX_H__
