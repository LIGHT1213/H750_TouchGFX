/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-09-02     RT-Thread    first version
 */
#define UDP_MODE
//#define TCP_MODE 1
#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#include "network.h"
#define LED_PIN GET_PIN(I, 8)
#define LED_R_PIN GET_PIN(C,15)
extern void wlan_autoconnect_init(void);
int main(void)
{
    rt_uint32_t count = 1;
    rt_pin_mode(LED_R_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);
    rt_pin_write(LED_PIN, PIN_HIGH);
    rt_pin_write(LED_R_PIN,PIN_LOW);
    /* init Wi-Fi auto connect feature */
    wlan_autoconnect_init();
    /* enable auto reconnect on WLAN device */
    rt_wlan_config_autoreconnect(RT_TRUE);
    while(rt_wlan_is_ready()==RT_FALSE)
    {
        rt_kprintf("wait wifi connect and dhcp server\r\n");
        rt_thread_delay(1000);
    }
#ifdef TCP_MODE
    rt_thread_t uart_thread = rt_thread_create("tcp_client", tcp_client_thread_entry, RT_NULL, 4*1024, 25, 10);
    if (uart_thread != NULL)
    {
        rt_thread_startup(uart_thread);
    }else
    {
        //ret = RT_ERROR;
        rt_kprintf("create tcp client error!!!");
    }
#endif
#ifdef UDP_MODE
    rt_thread_t uart_thread = rt_thread_create("udp_client", udpserv, RT_NULL, 4*1024, 25, 10);
    if (uart_thread != NULL)
    {
        rt_thread_startup(uart_thread);
    }else
    {
        rt_kprintf("create udp client error!!!");
    }
#endif
    rt_pin_write(LED_R_PIN,PIN_HIGH);
    while(count++)
    {
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED_PIN, PIN_LOW);
    }
    return RT_EOK;
}
#include "stm32h7xx.h"
static int vtor_config(void)
{
    /* Vector Table Relocation in Internal QSPI_FLASH */
    SCB->VTOR = QSPI_BASE;
    return 0;
}
INIT_BOARD_EXPORT(vtor_config);


