#ifndef UDP_SENDER_H
#define UDP_SENDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define PORT_RTCHECK 9000

void udp_init(const char *ip_address);
void udp_init_rtcheck(const char *ip_address_rtcheck);
void udp_send_data(float *data, size_t num_elements);
void udp_send_data_rtcheck(float *data, size_t num_elements);
void udp_close();
void udp_close_rtcheck();

#endif