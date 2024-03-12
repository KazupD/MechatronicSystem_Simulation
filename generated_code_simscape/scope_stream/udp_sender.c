#include "udp_sender.h"

int sockfd;
struct sockaddr_in servaddr;

void setup_udp(const char *ip_address){
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return;
    }

    // Configure server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_aton(ip_address, &servaddr.sin_addr);
}

void udp_send_data(double *data, size_t num_elements) {
    
    // Prepare data to be sent
    char buffer[sizeof(double) * num_elements];
    memcpy(buffer, data, sizeof(double) * num_elements);

    // Send data
    ssize_t bytes_sent = sendto(sockfd, buffer, sizeof(buffer), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    if (bytes_sent == -1) {
        perror("Sendto failed");
        //close(sockfd);
        return;
    }
}

void close_udp(){
    close(sockfd);
}