#ifndef __NEtWORK_H
#define __NEtWORK_H
#include <rtthread.h>
#include <rtdevice.h>
void tcp_client_thread_entry(void *args);
void udpserv(void *args);
extern char *recv_data;
extern uint8_t NetRecFlag;

#endif
