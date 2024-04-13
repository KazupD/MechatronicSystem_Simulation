#include "udp_sender.h"

int sockfd, sockfd_rtcheck;
struct sockaddr_in servaddr, servaddr_rtcheck;

void udp_init(const char *ip_address){
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_aton(ip_address, &servaddr.sin_addr);
}

void udp_init_rtcheck(const char *ip_address_rtcheck){
    sockfd_rtcheck = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd_rtcheck == -1) {
        perror("Socket creation failed");
        return;
    }

    memset(&servaddr_rtcheck, 0, sizeof(servaddr_rtcheck));
    servaddr_rtcheck.sin_family = AF_INET;
    servaddr_rtcheck.sin_port = htons(PORT_RTCHECK);
    inet_aton(ip_address_rtcheck, &servaddr_rtcheck.sin_addr);
}



void udp_send_data(float *data, size_t num_elements) {
    
    char buffer[sizeof(float) * num_elements];
    memcpy(buffer, data, sizeof(float) * num_elements);

    ssize_t bytes_sent = sendto(sockfd, buffer, sizeof(buffer), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    if (bytes_sent == -1) {
        perror("Sendto failed");
        return;
    }
}

void udp_send_data_rtcheck(float *data, size_t num_elements) {
    
    char buffer[sizeof(float) * num_elements];
    memcpy(buffer, data, sizeof(float) * num_elements);

    ssize_t bytes_sent = sendto(sockfd_rtcheck, buffer, sizeof(buffer), 0, (const struct sockaddr *)&servaddr_rtcheck, sizeof(servaddr_rtcheck));
    if (bytes_sent == -1) {
        perror("Sendto failed");
        return;
    }
}



void udp_close(){
    close(sockfd);
}

void udp_close_rtcheck(){
    close(sockfd_rtcheck);
}