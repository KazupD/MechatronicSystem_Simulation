#include "udp_sender.h"

int sockfd;
struct sockaddr_in servaddr;

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

void udp_send_data(float *data, size_t num_elements) {
    
    char buffer[sizeof(float) * num_elements];
    memcpy(buffer, data, sizeof(float) * num_elements);

    ssize_t bytes_sent = sendto(sockfd, buffer, sizeof(buffer), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    if (bytes_sent == -1) {
        perror("Sendto failed");
        return;
    }
}

void udp_close(){
    close(sockfd);
}