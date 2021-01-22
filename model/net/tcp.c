#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#include <sys/socket.h> //使用BSD socket需要包含此头文件
#include "string.h"
#include "network.h"
#define TCP_SERVER_ADDR "192.168.103.28" //电脑连接热点后得到的IP地址
#define TCP_SERVER_PORT 4000
void tcp_client_thread_entry(void *args)
{
    int ret = 0;
    int fd = -1;
    struct sockaddr_in server_addr;
    struct  timeval t;
    fd_set readfds;

    char buf[512] = { 0x00 };
    int len = 0;

reconnect:
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == fd)
    {
        rt_kprintf("create socket error!!!\r\n");
        goto exit;
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(TCP_SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr( TCP_SERVER_ADDR );
    rt_memset(&server_addr.sin_zero, 0x00, sizeof(server_addr.sin_zero));

    ret = connect(fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr ));
    if (0 == ret)
    {
        rt_kprintf("connect success\r\n");
    }else
    {
        rt_kprintf("connect error!!!\r\n");
        goto try_reconnect;
    }

    t.tv_sec = 2;
    t.tv_usec = 0;

    while (1)
    {
        FD_ZERO(&readfds);
        FD_SET(fd, &readfds);

        ret = select(fd + 1, &readfds, 0, 0, &t);
        if (-1 == ret)
        {
            rt_kprintf("select() error!\r\n");
            goto try_reconnect;
        }
        // else if(0 == ret)
        // {
        //     rt_kprintf("select() timeout!\r\n");
        // }
        else if(ret > 0)
        {
            if (FD_ISSET(fd, &readfds));
            {
                len = recv(fd, buf, sizeof(buf), 0);
                if (len > 0)
                {
                    buf[len] = 0x00;
                    rt_kprintf("receive data:%s\r\n", buf);
                }else
                {
                    rt_kprintf("receive data from tcp server error!\r\n");
                    goto try_reconnect;
                }
                if (-1 != fd)
                {
                    rt_sprintf(buf, "%s\r\n", buf);
                    ret = send(fd, buf, strlen(buf), 0);
                    if (ret < 0)
                    {
                        rt_kprintf("send error, closee socket");
                        goto try_reconnect;
                    }
                }
            }
        }
    }
try_reconnect:
    if (-1 != fd)
    {
        closesocket(fd);
    }
    rt_thread_mdelay(1);
    goto reconnect;

exit:
    if (-1 != fd)
    {
        closesocket(fd);
    }
    rt_kprintf("thread tcp_client exit!\r\n");
}
