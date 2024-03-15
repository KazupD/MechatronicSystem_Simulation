#include "gpio_utils.h"

void export_gpio(int gpio_pin) {
    FILE *export_fd = fopen(GPIO_EXPORT_FILE, "w");
    if (export_fd == NULL) {
        perror("Error exporting GPIO");
        exit(EXIT_FAILURE);
    }

    fprintf(export_fd, "%d", gpio_pin);
    fclose(export_fd);
}

void unexport_gpio(int gpio_pin) {
    FILE *unexport_fd = fopen(GPIO_UNEXPORT_FILE, "w");
    if (unexport_fd == NULL) {
        perror("Error unexporting GPIO");
        exit(EXIT_FAILURE);
    }

    fprintf(unexport_fd, "%d", gpio_pin);
    fclose(unexport_fd);
}

void set_direction(int gpio_pin, const char *direction) { // "in" or "out"
    char file_path[128];
    snprintf(file_path, sizeof(file_path), "/sys/class/gpio/gpio%d/direction", gpio_pin);
    
    FILE *direction_fd = fopen(file_path, "w");
    if (direction_fd == NULL) {
        perror("Error setting GPIO direction");
        exit(EXIT_FAILURE);
    }

    fprintf(direction_fd, "%s", direction);
    fclose(direction_fd);
}

void write_value(int gpio_pin, int value) {
    char file_path[128];
    snprintf(file_path, sizeof(file_path), "/sys/class/gpio/gpio%d/value", gpio_pin);
    
    FILE *value_fd = fopen(file_path, "w");
    if (value_fd == NULL) {
        perror("Error writing GPIO value");
        exit(EXIT_FAILURE);
    }

    fprintf(value_fd, "%d", value);
    fclose(value_fd);
}

int read_value(int gpio_pin) {
    char file_path[128];
    char value_str[3];
    int value;

    snprintf(file_path, sizeof(file_path), "/sys/class/gpio/gpio%d/value", gpio_pin);

    FILE *value_fd = fopen(file_path, "r");
    if (value_fd == NULL) {
        perror("Error reading GPIO value");
        exit(EXIT_FAILURE);
    }

    if (fgets(value_str, sizeof(value_str), value_fd) == NULL) {
        perror("Error reading GPIO value");
        exit(EXIT_FAILURE);
    }

    value = atoi(value_str);

    fclose(value_fd);

    return value;
}