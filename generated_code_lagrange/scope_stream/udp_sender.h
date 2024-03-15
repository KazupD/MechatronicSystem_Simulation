#ifndef UDP_SENDER_H
#define UDP_SENDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

void udp_init(const char *ip_address);
void udp_send_data(float *data, size_t num_elements);
void udp_close();

#endif