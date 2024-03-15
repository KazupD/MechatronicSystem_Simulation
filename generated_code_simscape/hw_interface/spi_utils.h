#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

#define SPI_DEVICE "/dev/spidev0.0"
#define SPI_SPEED_HZ 2500000
#define ARRAY_SIZE 8

void spi_init();

void spi_transfer(float *send_data, float *recv_data);

void spi_close();