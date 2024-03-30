/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller.c
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

#include "controller.h"

/* Block states (default storage) */
DW_controller_T controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_controller_T controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_controller_T controller_Y;

/* Real-time model */
static RT_MODEL_controller_T controller_M_;
RT_MODEL_controller_T *const controller_M = &controller_M_;

/* Model step function */
void controller_step(void)
{
  /* Sum: '<Root>/Sum1' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/Gain4'
   *  Inport: '<Root>/Ki'
   *  Inport: '<Root>/m_pos'
   *  Inport: '<Root>/m_vel'
   *  Inport: '<Root>/mot_amp'
   *  Inport: '<Root>/shft_pos'
   *  Inport: '<Root>/shft_vel'
   *  Product: '<Root>/Product'
   *  Sum: '<Root>/Sum'
   */
  controller_Y.Ug_U = controller_U.Ki *
    controller_DW.DiscreteTimeIntegrator_DSTATE - ((((0.0091666666666686061 *
    controller_U.mot_amp + 35.436246586663806 * controller_U.shft_pos) +
    0.24665946666667934 * controller_U.shft_vel) + -297.72178555570343 *
    controller_U.m_pos) + 1.7725884183998313 * controller_U.m_vel);

  /* Switch: '<S1>/Switch2' incorporates:
   *  Gain: '<Root>/Gain5'
   *  Inport: '<Root>/Ug_max_c'
   *  RelationalOperator: '<S1>/LowerRelop1'
   *  RelationalOperator: '<S1>/UpperRelop'
   *  Switch: '<S1>/Switch'
   */
  if (controller_Y.Ug_U > controller_U.Ug_max_c) {
    /* Sum: '<Root>/Sum1' incorporates:
     *  Outport: '<Root>/Ug_U'
     */
    controller_Y.Ug_U = controller_U.Ug_max_c;
  } else if (controller_Y.Ug_U < -controller_U.Ug_max_c) {
    /* Sum: '<Root>/Sum1' incorporates:
     *  Gain: '<Root>/Gain5'
     *  Outport: '<Root>/Ug_U'
     *  Switch: '<S1>/Switch'
     */
    controller_Y.Ug_U = -controller_U.Ug_max_c;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/h_ref'
   *  Inport: '<Root>/m_pos'
   *  Sum: '<Root>/Sum2'
   */
  controller_DW.DiscreteTimeIntegrator_DSTATE += (controller_U.h_ref -
    controller_U.m_pos) * 0.02;
  if (controller_DW.DiscreteTimeIntegrator_DSTATE > 50.0) {
    controller_DW.DiscreteTimeIntegrator_DSTATE = 50.0;
  } else if (controller_DW.DiscreteTimeIntegrator_DSTATE < -50.0) {
    controller_DW.DiscreteTimeIntegrator_DSTATE = -50.0;
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
}

/* Model initialize function */
void controller_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
