/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-01-22     pan39       the first version
 */
#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#include <sys/socket.h> //使用BSD socket需要包含此头文件
#include "string.h"
#include "netdev.h"
#include "netdb.h"
#include "network.h"
#define BUFSZ   1024
int stepNum;
int ecgNum;
float tempNum;
int heartNum;
char *recv_data;
uint8_t NetRecFlag=0;
static void DataProcess(void);
/*
 *  sender设置
 *  SendData[0] = stepNum;
 *  SendData[1] = stepNum >> 8;
 *  SendData[2] = ecgNum;
 *  SendData[3] = ecgNum>> 8;
 *  SendData[4] = heartNum;
 *  SendData[5] = tempNum;
 *  SendData[6] = tempNum >> 8;
 * */
static void DataProcess(void)
{
//    stepNum=(recv_data[5]<<8)+recv_data[4];
//    ecgNum=(recv_data[17]<<8)+recv_data[16];
//    tempNum=(recv_data[22]<<8)+recv_data[21];
//    heartNum=recv_data[20];
    stepNum=(recv_data[1]<<8)+recv_data[0];
    ecgNum=(recv_data[3]<<8)+recv_data[2];
    heartNum=recv_data[4];
    tempNum=(recv_data[6]<<8)+recv_data[5];
    tempNum/=10.0;
}
void udpserv(void *args)
{
    //static long CounterNum=0;
    int sock;
    int bytes_read;

    socklen_t addr_len;
    struct sockaddr_in server_addr, client_addr;

    /* 分配接收用的数据缓冲 */
    recv_data = rt_malloc(BUFSZ);
    if (recv_data == RT_NULL)
    {
        /* 分配内存失败，返回 */
        rt_kprintf("No memory\n");
        return;
    }

    /* 创建一个socket，类型是SOCK_DGRAM，UDP类型 */
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        rt_kprintf("Socket error\n");

        /* 释放接收用的数据缓冲 */
        rt_free(recv_data);
        return;
    }

    /* 初始化服务端地址 */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(4001);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    rt_memset(&(server_addr.sin_zero), 0, sizeof(server_addr.sin_zero));

    /* 绑定socket到服务端地址 */
    if (bind(sock, (struct sockaddr *)&server_addr,
             sizeof(struct sockaddr)) == -1)
    {
        /* 绑定地址失败 */
        rt_kprintf("Bind error\n");

        /* 释放接收用的数据缓冲 */
        rt_free(recv_data);
        return;
    }

    addr_len = sizeof(struct sockaddr);
    rt_kprintf("UDPServer Waiting for client on port 4001...\n");

    while (1)
    {
        /* 从sock中收取最大BUFSZ - 1字节数据 */
        bytes_read = recvfrom(sock, recv_data, BUFSZ - 1, 0,
                              (struct sockaddr *)&client_addr, &addr_len);
        /* UDP不同于TCP，它基本不会出现收取的数据失败的情况，除非设置了超时等待 */

        recv_data[bytes_read] = '\0'; /* 把末端清零 */
        if(strlen(recv_data)>0)
        {
            DataProcess();
            NetRecFlag=1;
            //CounterNum++;
        }
        /* 输出接收的数据 */
//        rt_kprintf("\n(%s , %d) said : ", inet_ntoa(client_addr.sin_addr),
//                   ntohs(client_addr.sin_port));
        //rt_kprintf("%d\r\n", (int)recv_data[0]);

        /* 如果接收数据是exit，退出 */
//        if (strcmp(recv_data, "exit") == 0)
//        {
//            rt_kprintf("%d", CounterNum);
//            closesocket(sock);
//
//            /* 释放接收用的数据缓冲 */
//            rt_free(recv_data);
//            break;
//        }
    }

    return;
}
MSH_CMD_EXPORT(udpserv, a udp server sample);
