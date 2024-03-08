#include "pwm_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void export_pwm_pin_0(int pwm_pin) {
    char export_path[50];
    snprintf(export_path, sizeof(export_path), PWM_CHIP_PATH_0 "/export");

    FILE *export_fd = fopen(export_path, "w");
    if (export_fd == NULL) {
        perror("Error opening export file");
        return;
    }

    fprintf(export_fd, "%d", pwm_pin);
    fclose(export_fd);
}

// Function to set PWM period
void set_pwm_period_0(int period_ns, int pwm_pin) {
    char period_path[100];
    snprintf(period_path, sizeof(period_path), PWM_CHIP_PATH_0 "/pwm%d/period", pwm_pin);

    FILE *period_fd = fopen(period_path, "w");
    if (period_fd == NULL) {
        perror("Error opening period file");
        return;
    }

    fprintf(period_fd, "%d", period_ns);
    fclose(period_fd);
}

// Function to set PWM duty cycle
void set_pwm_duty_cycle_0(int duty_cycle_ns, int pwm_pin) {
    char duty_cycle_path[100];
    snprintf(duty_cycle_path, sizeof(duty_cycle_path), PWM_CHIP_PATH_0 "/pwm%d/duty_cycle", pwm_pin);

    FILE *duty_cycle_fd = fopen(duty_cycle_path, "w");
    if (duty_cycle_fd == NULL) {
        perror("Error opening duty_cycle file");
        return;
    }

    fprintf(duty_cycle_fd, "%d", duty_cycle_ns);
    fclose(duty_cycle_fd);
}

// Function to enable PWM with a specified period
void enable_pwm_0(int period_ns, int pwm_pin) {
    char period_path[100], enable_path[100];
    snprintf(period_path, sizeof(period_path), PWM_CHIP_PATH_0 "/pwm%d/period", pwm_pin);
    snprintf(enable_path, sizeof(enable_path), PWM_CHIP_PATH_0 "/pwm%d/enable", pwm_pin);

    FILE *period_fd = fopen(period_path, "w");
    if (period_fd == NULL) {
        perror("Error opening period file");
        return;
    }

    fprintf(period_fd, "%d", period_ns);
    fclose(period_fd);

    FILE *enable_fd = fopen(enable_path, "w");
    if (enable_fd == NULL) {
        perror("Error opening enable file");
        return;
    }

    fprintf(enable_fd, "1");
    fclose(enable_fd);
}


//----------------------------------------------------------------------


void export_pwm_pin_1(int pwm_pin) {
    char export_path[50];
    snprintf(export_path, sizeof(export_path), PWM_CHIP_PATH_1 "/export");

    FILE *export_fd = fopen(export_path, "w");
    if (export_fd == NULL) {
        perror("Error opening export file");
        return;
    }

    fprintf(export_fd, "%d", pwm_pin);
    fclose(export_fd);
}

// Function to set PWM period
void set_pwm_period_1(int period_ns, int pwm_pin) {
    char period_path[100];
    snprintf(period_path, sizeof(period_path), PWM_CHIP_PATH_1 "/pwm%d/period", pwm_pin);

    FILE *period_fd = fopen(period_path, "w");
    if (period_fd == NULL) {
        perror("Error opening period file");
        return;
    }

    fprintf(period_fd, "%d", period_ns);
    fclose(period_fd);
}

// Function to set PWM duty cycle
void set_pwm_duty_cycle_1(int duty_cycle_ns, int pwm_pin) {
    char duty_cycle_path[100];
    snprintf(duty_cycle_path, sizeof(duty_cycle_path), PWM_CHIP_PATH_1 "/pwm%d/duty_cycle", pwm_pin);

    FILE *duty_cycle_fd = fopen(duty_cycle_path, "w");
    if (duty_cycle_fd == NULL) {
        perror("Error opening duty_cycle file");
        return;
    }

    fprintf(duty_cycle_fd, "%d", duty_cycle_ns);
    fclose(duty_cycle_fd);
}

// Function to enable PWM with a specified period
void enable_pwm_1(int period_ns, int pwm_pin) {
    char period_path[100], enable_path[100];
    snprintf(period_path, sizeof(period_path), PWM_CHIP_PATH_1 "/pwm%d/period", pwm_pin);
    snprintf(enable_path, sizeof(enable_path), PWM_CHIP_PATH_1 "/pwm%d/enable", pwm_pin);

    FILE *period_fd = fopen(period_path, "w");
    if (period_fd == NULL) {
        perror("Error opening period file");
        return;
    }

    fprintf(period_fd, "%d", period_ns);
    fclose(period_fd);

    FILE *enable_fd = fopen(enable_path, "w");
    if (enable_fd == NULL) {
        perror("Error opening enable file");
        return;
    }

    fprintf(enable_fd, "1");
    fclose(enable_fd);
}