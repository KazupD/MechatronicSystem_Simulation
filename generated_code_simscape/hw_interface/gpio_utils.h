#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define GPIO_EXPORT_FILE "/sys/class/gpio/export"
#define GPIO_UNEXPORT_FILE "/sys/class/gpio/unexport"

void export_gpio(int gpio_pin);

void unexport_gpio(int gpio_pin);

void set_direction(int gpio_pin, const char *direction);

void write_value(int gpio_pin, int value);

int read_value(int gpio_pin);