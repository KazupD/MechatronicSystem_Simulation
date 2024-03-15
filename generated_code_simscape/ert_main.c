/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'mechatronic_system'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Mar  6 18:41:30 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#define _GNU_SOURCE
#include <stddef.h>
#include <stdio.h>
#include "mechatronic_system.h"
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <linux/sched.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <math.h>
#include <time.h>
#include <hw_interface/gpio_utils.h>
#include <hw_interface/spi_utils.h>
#include <scope_stream/udp_sender.h>

#define clear_terminal() printf("\033[H\033[J")

#define NANOSECONDS_IN_SECOND 1000000000
#define INTERVAL_NS 2000000 // 2 milliseconds
#define ARRAY_SIZE 8


struct sched_attr {
    uint32_t size;
    uint32_t sched_policy;
    uint64_t sched_flags;
    int32_t sched_nice;
    uint32_t sched_priority;
    uint64_t sched_runtime;
    uint64_t sched_deadline;
    uint64_t sched_period;
};

float spi_output_data[ARRAY_SIZE] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float spi_input_data[ARRAY_SIZE] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
float stream_data[ARRAY_SIZE] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(mechatronic_system_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Set model inputs here */
  if(spi_input_data[0] == 1.0){
    mechatronic_system_U.Ug = spi_input_data[1];
  }
  else{
    if(read_value(21) == 1){mechatronic_system_U.Ug = mechatronic_system_U.Ug_max;}
    else{mechatronic_system_U.Ug = 0.0;}
  }

  /* Step the model */
  mechatronic_system_step();

  /* Get model outputs here */
  spi_output_data[0] = (float)mechatronic_system_U.Ug;
  spi_output_data[1] = (float)mechatronic_system_Y.motor_current;
  spi_output_data[2] = (float)mechatronic_system_Y.shaft_pos;
  spi_output_data[3] = (float)mechatronic_system_Y.shaft_vel;
  spi_output_data[4] = (float)mechatronic_system_Y.shaft_acc;
  spi_output_data[5] = (float)mechatronic_system_Y.mass_pos;
  spi_output_data[6] = (float)mechatronic_system_Y.mass_vel;
  spi_output_data[7] = (float)mechatronic_system_Y.mass_acc;

  stream_data[0] = (float)mechatronic_system_U.Ug;
  stream_data[1] = (float)mechatronic_system_Y.motor_current;
  stream_data[2] = (float)mechatronic_system_Y.shaft_pos;
  stream_data[3] = (float)mechatronic_system_Y.shaft_vel;
  stream_data[4] = (float)mechatronic_system_Y.shaft_acc;
  stream_data[5] = (float)mechatronic_system_Y.mass_pos;
  stream_data[6] = (float)mechatronic_system_Y.mass_vel;
  stream_data[7] = (float)mechatronic_system_Y.mass_acc;

  OverrunFlag = false;
}

void print_simulation_data(){
  printf("Sim time\t%.2f\t[s     ]\n\n", (float)(mechatronic_system_M->Timing.clockTick0)*0.002);
  printf("Mtr  vel\t%.2f\t[rad/s ]\n", mechatronic_system_Y.motor_pos);
  printf("Mtr  amp\t%.2f\t[A     ]\n", mechatronic_system_Y.motor_current);
  printf("Mtr  trq\t%.2f\t[Nm    ]\n\n", mechatronic_system_Y.motor_torque);
  printf("Shft pos\t%.2f\t[rad   ]\n", mechatronic_system_Y.shaft_pos);
  printf("Shft vel\t%.2f\t[rad/s ]\n", mechatronic_system_Y.shaft_vel);
  printf("Shft acc\t%.2f\t[rad/s2]\n\n", mechatronic_system_Y.shaft_acc);
  printf("Mss  pos\t%.2f\t[m     ]\n", mechatronic_system_Y.mass_pos);
  printf("Mss  vel\t%.2f\t[m/s   ]\n", mechatronic_system_Y.mass_vel);
  printf("Mss  acc\t%.2f\t[m/s2  ]\n\n", mechatronic_system_Y.mass_acc);
}

void print_spi_in(){
  printf("SPI:\t");
  for(int i = 0; i < ARRAY_SIZE; i++){printf("%.2f\t", spi_input_data[i]);}
  printf("\n");
}

static int sched_setattr(pid_t pid, const struct sched_attr *attr, unsigned int flags)
{
    return syscall (SYS_sched_setattr, pid, attr, flags);
}


int_T main(int_T argc, const char *argv[])
{
  (void)(argc);
  (void)(argv);

  struct sched_attr attr;
  memset (&attr, 0, sizeof (struct sched_attr));

  attr.size = sizeof (attr);
  attr.sched_policy = SCHED_DEADLINE;
  attr.sched_runtime = 1 * 1000 * 1000;
  attr.sched_period = 2 * 1000 * 1000;
  attr.sched_deadline = 1 * 1000 * 1000;

  int res;

  res = sched_setattr(getpid(), &attr, 0);
  if (res < 0) {
      printf("Scheduling failed\n");
      perror("ERROR: ");
      return 1;
  }

  export_gpio(21);
  set_direction(21, "in");

  spi_init();

  const char *ip_address = "169.254.49.60";
  udp_init(ip_address);

  mechatronic_system_initialize();
  mechatronic_system_U.Enable = 1;
  mechatronic_system_U.Mass_m = 2.0;
  mechatronic_system_U.Ug_max = 24.0;

  struct timespec start, end;
  int step_counter = 0;
  long long elapsed_ns;

  while (rtmGetErrorStatus(mechatronic_system_M) == (NULL)) {
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    clear_terminal();
    rt_OneStep();

    spi_transfer(spi_output_data, spi_input_data);
    
    if(step_counter%5 == 0){udp_send_data(stream_data, 8);}

    print_simulation_data();
    print_spi_in();

    step_counter++;
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_ns = (end.tv_sec - start.tv_sec) * NANOSECONDS_IN_SECOND + (end.tv_nsec - start.tv_nsec);
    printf("Time demand : %lld\t[ns]\n", elapsed_ns);
    printf("Percent     : %.2f\t[% ]\n\n", ((float)elapsed_ns/(float)INTERVAL_NS)*100.0);

    fflush(0);
    sched_yield();

  }

  mechatronic_system_terminate();
  udp_close();
  spi_close();
  return 0;
}
