///*
// * Copyright (c) 2006-2023, RT-Thread Development Team
// *
// * SPDX-License-Identifier: Apache-2.0
// *
// * Change Logs:
// * Date           Author       Notes
// * 2023-09-15     RT-Thread    first version
// */


#include "uart.h"

int main(void)
{
//    static int count = 1;
    rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);
    UART_Config();
    char str[] = "hello world\n";
    rt_device_write(serial, -1, str, sizeof(str)-1);
    while (1)
    {
        UART_ReceiveData();
    }
    return RT_EOK;
}
