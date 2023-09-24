/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-09-21     Admin       the first version
 */
#include "uart.h"

struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT;
char buf[50];
rt_device_t serial;
uint8_t rk_ok_flag = 0;
static char tmp_char;
static rt_uint8_t RXI = 0;


static rt_err_t UART_recv_callback(rt_device_t dev, rt_size_t size)
{
    rk_ok_flag = 1;
    return RT_EOK;
}

void UART_Config(void)
{
    serial = rt_device_find(SAMPLE_UART_NAME);
    if (!serial)
    {
        rt_kprintf("find %s failed!\n", SAMPLE_UART_NAME);
        return RT_ERROR;
    }
    rt_kprintf("Da tim thay uart\n");
    if(RT_EOK != rt_device_control(serial, RT_DEVICE_CTRL_CONFIG, &config))
    {
        rt_kprintf("not ok\n");
        return RT_ERROR;
    }
    rt_kprintf("Cau hinh che do thanh cong\n");
    if(RT_EOK != rt_device_open(serial, RT_DEVICE_FLAG_INT_RX))
    {
        rt_kprintf("Bi loi nhan tin hieu !\n");
        return RT_ERROR;
    }
    rt_kprintf("Chon che do ngat nhan thanh cong!\n");
    rt_device_set_rx_indicate(serial, UART_recv_callback);
}

void UART_ReceiveData(void)
{
    if ( rk_ok_flag == 1 && rt_device_read(serial, -1, &tmp_char, 1) == 0)
    {
        rk_ok_flag = 0;
        if(tmp_char == 13)
        {
//            rt_kprintf("------------<START>------------\n");
            buf[RXI] = 0x00;
            rt_device_write(serial,-1, buf, strlen(buf));
            rt_kprintf("\n");
            RXI = 0;
        }
        else
        {
            buf[RXI] = tmp_char;
            RXI ++;
//            rt_kprintf ("%c", tmp_char);
        }
    }
}

