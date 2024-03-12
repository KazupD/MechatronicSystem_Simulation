/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'mechatronic_system_ss'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Mar  9 20:26:14 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>
#include "mechatronic_system_ss.h"
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <linux/sched.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <math.h>
#include <time.h>
#include <hw_interface/gpio_utils.h>
#include <scope_stream/udp_sender.h>

#define clear_terminal() printf("\033[H\033[J")

#define NANOSECONDS_IN_SECOND 1000000000
#define INTERVAL_NS 2000000 // 2 milliseconds


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


void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(mechatronic_system_ss_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Set model inputs here */

  if(read_value(21) == 1){
    mechatronic_system_ss_U.Ug = mechatronic_system_ss_U.Ug_max;
  }
  else{
    mechatronic_system_ss_U.Ug = 0.0;
  }

  /* Step the model */
  mechatronic_system_ss_step();

  /* Get model outputs here */

  printf("Time %.3f [s]\n", (float)(mechatronic_system_ss_M->Timing.clockTick0)*0.002);

  printf("Motor current %.3f [A]\n", mechatronic_system_ss_Y.motor_current);

  printf("Shaft pos %.3f [rad]\n", mechatronic_system_ss_Y.shaft_pos);
  printf("Shaft vel %.3f [rad/s]\n", mechatronic_system_ss_Y.shaft_vel);

  printf("Mass pos %.3f [m]\n", mechatronic_system_ss_Y.mass_pos);
  printf("Mass vel %.3f [m/s]\n", mechatronic_system_ss_Y.mass_vel);
  

  /* Indicate task complete */
  OverrunFlag = false;

}

static int sched_setattr(pid_t pid, const struct sched_attr *attr, unsigned int flags)
{
    return syscall (SYS_sched_setattr, pid, attr, flags);
}

int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
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

  /* Initialize model */
  mechatronic_system_ss_initialize();
  mechatronic_system_ss_U.Enable = 1;
  mechatronic_system_ss_U.Ug_max = 24.0;

  export_gpio(21);
  set_direction(21, "in");

  struct timespec start, end;
  int step_counter = 0;

  double stream_data[6];
  const char *ip_address = "169.254.49.60";
  setup_udp(ip_address);
  
  while ((rtmGetErrorStatus(mechatronic_system_ss_M) == (NULL)) && !rtmGetStopRequested(mechatronic_system_ss_M)) {
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    clear_terminal();
    printf("---- Step %d ----\n", step_counter);
    rt_OneStep();

    if(step_counter%5 == 0){
      stream_data[0] = (double)mechatronic_system_ss_U.Ug;
      stream_data[1] = (double)mechatronic_system_ss_Y.motor_current;
      stream_data[2] = (double)mechatronic_system_ss_Y.shaft_pos;
      stream_data[3] = (double)mechatronic_system_ss_Y.shaft_vel;
      stream_data[4] = (double)mechatronic_system_ss_Y.mass_pos;
      stream_data[5] = (double)mechatronic_system_ss_Y.mass_vel;

      udp_send_data(stream_data, 6);
    }

    step_counter++;
    clock_gettime(CLOCK_MONOTONIC, &end);

    long long elapsed_ns = (end.tv_sec - start.tv_sec) * NANOSECONDS_IN_SECOND + (end.tv_nsec - start.tv_nsec);

    printf("Computation took %lld [ns]\n", elapsed_ns);
    printf("Percent : %.2f\n\n\n", ((float)elapsed_ns/(float)INTERVAL_NS)*100.0);

    fflush(0);
    sched_yield();

  }

  /* Terminate model */
  mechatronic_system_ss_terminate();
  close_udp();
  return 0;
}

