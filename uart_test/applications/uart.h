/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-09-21     Admin       the first version
 */
#ifndef APPLICATIONS_UART_H_
#define APPLICATIONS_UART_H_

#include <rtthread.h>
#include <board.h>
#include <rtdevice.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////

#define LED0_PIN    GET_PIN(C, 13)
#define SAMPLE_UART_NAME       "uart1"

///////////////////////////////////////////////////////////////////////////////////////////////////////////


extern char buf[50];
extern rt_device_t serial;
extern uint8_t rk_ok_flag;


///////////////////////////////////////////////////////////////////////////////////////////////////////////


void UART_Config(void);
void UART_ReceiveData(void);

///////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* APPLICATIONS_UART_H_ */
