/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller.h
 *
 * Code generated for Simulink model 'controller'.
 *
 * Model version                  : 1.28
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Mar 30 17:12:39 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_h_
#define RTW_HEADER_controller_h_
#ifndef controller_COMMON_INCLUDES_
#define controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* controller_COMMON_INCLUDES_ */

#include "controller_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
} DW_controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T mot_amp;                      /* '<Root>/mot_amp' */
  real_T shft_pos;                     /* '<Root>/shft_pos' */
  real_T shft_vel;                     /* '<Root>/shft_vel' */
  real_T m_pos;                        /* '<Root>/m_pos' */
  real_T m_vel;                        /* '<Root>/m_vel' */
  real_T h_ref;                        /* '<Root>/h_ref' */
  real_T Ug_max_c;                     /* '<Root>/Ug_max_c' */
  real_T Ki;                           /* '<Root>/Ki' */
} ExtU_controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Ug_U;                         /* '<Root>/Ug_U' */
} ExtY_controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_controller_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_controller_T controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_controller_T controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_controller_T controller_Y;

/* Model entry point functions */
extern void controller_initialize(void);
extern void controller_step(void);
extern void controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_controller_T *const controller_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 * Block '<S1>/Data Type Propagation' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'controller'
 * '<S1>'   : 'controller/Saturation Dynamic'
 */
#endif                                 /* RTW_HEADER_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
