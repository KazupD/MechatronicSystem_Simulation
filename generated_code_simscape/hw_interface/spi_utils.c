#include "spi_utils.h"

int spi_fd;

void spi_init() {
    spi_fd = open(SPI_DEVICE, O_RDWR);
    if (spi_fd < 0) {
        perror("Error opening SPI device");
        return;
    }

    uint8_t mode = SPI_MODE_0;
    if (ioctl(spi_fd, SPI_IOC_WR_MODE, &mode) < 0) {
        perror("Error setting SPI mode");
        return;
    }

    uint32_t speed = SPI_SPEED_HZ;
    if (ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0) {
        perror("Error setting SPI clock speed");
        return;
    }
}

void spi_transfer(float *send_data, float *recv_data) {
    uint8_t send_buf[ARRAY_SIZE * sizeof(float)];
    uint8_t recv_buf[ARRAY_SIZE * sizeof(float)];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        *(float *)(send_buf + i * sizeof(float)) = send_data[i];
    }

    struct spi_ioc_transfer transfer = {
        .tx_buf = (unsigned long)send_buf,
        .rx_buf = (unsigned long)recv_buf,
        .len = sizeof(send_buf),
        .speed_hz = SPI_SPEED_HZ,
        .bits_per_word = 8,
    };

    ioctl(spi_fd, SPI_IOC_MESSAGE(1), &transfer);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        recv_data[i] = *(float *)(recv_buf + i * sizeof(float));
    }
}

void spi_close() {
    close(spi_fd);
}