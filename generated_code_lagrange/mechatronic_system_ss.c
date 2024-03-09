/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mechatronic_system_ss.c
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

#include "mechatronic_system_ss.h"
#include "rtwtypes.h"
#include "mechatronic_system_ss_private.h"

/* Block signals (default storage) */
B_mechatronic_system_ss_T mechatronic_system_ss_B;

/* Continuous states */
X_mechatronic_system_ss_T mechatronic_system_ss_X;

/* Disabled State Vector */
XDis_mechatronic_system_ss_T mechatronic_system_ss_XDis;

/* Block states (default storage) */
DW_mechatronic_system_ss_T mechatronic_system_ss_DW;

/* External inputs (root inport signals with default storage) */
ExtU_mechatronic_system_ss_T mechatronic_system_ss_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_mechatronic_system_ss_T mechatronic_system_ss_Y;

/* Real-time model */
static RT_MODEL_mechatronic_system_s_T mechatronic_system_ss_M_;
RT_MODEL_mechatronic_system_s_T *const mechatronic_system_ss_M =
  &mechatronic_system_ss_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  mechatronic_system_ss_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void mechatronic_system_ss_step(void)
{
  real_T rtb_StateSpace[6];
  real_T rtb_Gain;
  real_T rtb_Gain2;
  real_T rtb_Sum;
  int32_T ri;
  int_T iy;
  if (rtmIsMajorTimeStep(mechatronic_system_ss_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&mechatronic_system_ss_M->solverInfo,
                          ((mechatronic_system_ss_M->Timing.clockTick0+1)*
      mechatronic_system_ss_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(mechatronic_system_ss_M)) {
    mechatronic_system_ss_M->Timing.t[0] = rtsiGetT
      (&mechatronic_system_ss_M->solverInfo);
  }

  /* StateSpace: '<Root>/State-Space' */
  for (iy = 0; iy < 6; iy++) {
    rtb_StateSpace[iy] = 0.0;
  }

  for (iy = 0; iy < 6; iy++) {
    for (ri = iy; (uint32_T)ri < (uint32_T)iy + 1U; ri = (int32_T)((uint32_T)ri
          + 1U)) {
      rtb_StateSpace[(uint32_T)ri] += mechatronic_system_ss_X.StateSpace_CSTATE
        [(uint32_T)iy];
    }
  }

  /* End of StateSpace: '<Root>/State-Space' */

  /* Outport: '<Root>/charge' */
  mechatronic_system_ss_Y.charge = rtb_StateSpace[0];

  /* Outport: '<Root>/motor_current' */
  mechatronic_system_ss_Y.motor_current = rtb_StateSpace[1];

  /* Outport: '<Root>/shaft_pos' */
  mechatronic_system_ss_Y.shaft_pos = rtb_StateSpace[2];

  /* Outport: '<Root>/shaft_vel' */
  mechatronic_system_ss_Y.shaft_vel = rtb_StateSpace[3];

  /* Outport: '<Root>/mass_pos' */
  mechatronic_system_ss_Y.mass_pos = rtb_StateSpace[4];

  /* Outport: '<Root>/mass_vel' */
  mechatronic_system_ss_Y.mass_vel = rtb_StateSpace[5];

  /* Gain: '<Root>/Gain' */
  rtb_Gain = -1000.0 * rtb_StateSpace[2];

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Inport: '<Root>/Enable'
   */
  if (mechatronic_system_ss_U.Enable > 0.0) {
    /* Switch: '<S4>/Switch2' incorporates:
     *  Gain: '<Root>/Gain3'
     *  Inport: '<Root>/Ug'
     *  Inport: '<Root>/Ug_max'
     *  RelationalOperator: '<S4>/LowerRelop1'
     *  RelationalOperator: '<S4>/UpperRelop'
     *  Switch: '<S4>/Switch'
     */
    if (mechatronic_system_ss_U.Ug > mechatronic_system_ss_U.Ug_max) {
      rtb_Sum = mechatronic_system_ss_U.Ug_max;
    } else if (mechatronic_system_ss_U.Ug < -mechatronic_system_ss_U.Ug_max) {
      /* Switch: '<S4>/Switch' incorporates:
       *  Gain: '<Root>/Gain3'
       */
      rtb_Sum = -mechatronic_system_ss_U.Ug_max;
    } else {
      rtb_Sum = mechatronic_system_ss_U.Ug;
    }

    /* End of Switch: '<S4>/Switch2' */
  } else {
    rtb_Sum = 0.0;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* Gain: '<Root>/Gain2' incorporates:
   *  Constant: '<Root>/Constant8'
   *  Sum: '<Root>/Sum'
   */
  rtb_Gain2 = (rtb_StateSpace[2] - 50.0) * -1000.0;

  /* If: '<Root>/If' */
  if (rtsiIsModeUpdateTimeStep(&mechatronic_system_ss_M->solverInfo)) {
    if (rtb_StateSpace[4] <= 0.0) {
      mechatronic_system_ss_DW.If_ActiveSubsystem = 0;
    } else if (rtb_StateSpace[4] >= 5.0) {
      mechatronic_system_ss_DW.If_ActiveSubsystem = 1;
    } else {
      mechatronic_system_ss_DW.If_ActiveSubsystem = 2;
    }
  }

  switch (mechatronic_system_ss_DW.If_ActiveSubsystem) {
   case 0:
    /* Switch: '<Root>/Switch' */
    if (rtb_Gain >= -9.81) {
      /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
       *  ActionPort: '<S1>/Action Port'
       */
      /* Merge: '<Root>/Merge' incorporates:
       *  Gain: '<Root>/Gain4'
       *  SignalConversion generated from: '<S1>/In1'
       *  Sum: '<Root>/Sum1'
       */
      mechatronic_system_ss_B.Merge = -250.0 * rtb_StateSpace[5] + rtb_Gain;

      /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
       *  ActionPort: '<S1>/Action Port'
       */
      /* Merge: '<Root>/Merge' incorporates:
       *  Constant: '<Root>/Constant6'
       *  SignalConversion generated from: '<S1>/In1'
       */
      mechatronic_system_ss_B.Merge = -9.81;

      /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
    }

    /* End of Switch: '<Root>/Switch' */
    break;

   case 1:
    /* Switch: '<Root>/Switch1' */
    if (rtb_Gain2 >= -9.81) {
      /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S2>/Action Port'
       */
      /* Merge: '<Root>/Merge' incorporates:
       *  Constant: '<Root>/Constant6'
       *  SignalConversion generated from: '<S2>/In1'
       */
      mechatronic_system_ss_B.Merge = -9.81;

      /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S2>/Action Port'
       */
      /* Merge: '<Root>/Merge' incorporates:
       *  Gain: '<Root>/Gain4'
       *  SignalConversion generated from: '<S2>/In1'
       *  Sum: '<Root>/Sum2'
       */
      mechatronic_system_ss_B.Merge = -250.0 * rtb_StateSpace[5] + rtb_Gain2;

      /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */
    }

    /* End of Switch: '<Root>/Switch1' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    if (rtmIsMajorTimeStep(mechatronic_system_ss_M)) {
      /* Merge: '<Root>/Merge' incorporates:
       *  Constant: '<Root>/Constant5'
       *  SignalConversion generated from: '<S3>/In1'
       */
      mechatronic_system_ss_B.Merge = -9.81;
    }

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem2' */
    break;
  }

  /* End of If: '<Root>/If' */

  /* SignalConversion generated from: '<Root>/State-Space' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Gain: '<Root>/Gain1'
   */
  mechatronic_system_ss_B.TmpSignalConversionAtStateSpace[0] = 0.0;
  mechatronic_system_ss_B.TmpSignalConversionAtStateSpace[1] =
    21.276595744680851 * rtb_Sum;
  mechatronic_system_ss_B.TmpSignalConversionAtStateSpace[2] = 0.0;
  mechatronic_system_ss_B.TmpSignalConversionAtStateSpace[3] = 0.0;
  mechatronic_system_ss_B.TmpSignalConversionAtStateSpace[4] = 0.0;
  mechatronic_system_ss_B.TmpSignalConversionAtStateSpace[5] =
    mechatronic_system_ss_B.Merge;
  if (rtmIsMajorTimeStep(mechatronic_system_ss_M)) {
    rt_ertODEUpdateContinuousStates(&mechatronic_system_ss_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++mechatronic_system_ss_M->Timing.clockTick0;
    mechatronic_system_ss_M->Timing.t[0] = rtsiGetSolverStopTime
      (&mechatronic_system_ss_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.002s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.002, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      mechatronic_system_ss_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void mechatronic_system_ss_derivatives(void)
{
  XDot_mechatronic_system_ss_T *_rtXdot;
  int_T is;
  uint32_T ri;
  _rtXdot = ((XDot_mechatronic_system_ss_T *) mechatronic_system_ss_M->derivs);

  /* Derivatives for StateSpace: '<Root>/State-Space' */
  for (is = 0; is < 6; is++) {
    _rtXdot->StateSpace_CSTATE[is] = 0.0;
  }

  for (is = 0; is < 6; is++) {
    for (ri = mechatronic_system_ss_ConstP.StateSpace_A_jc[(uint32_T)is]; ri <
         mechatronic_system_ss_ConstP.StateSpace_A_jc[(uint32_T)is + 1U]; ri++)
    {
      _rtXdot->StateSpace_CSTATE[mechatronic_system_ss_ConstP.StateSpace_A_ir[ri]]
        += mechatronic_system_ss_ConstP.StateSpace_A_pr[ri] *
        mechatronic_system_ss_X.StateSpace_CSTATE[(uint32_T)is];
    }
  }

  for (is = 0; is < 6; is++) {
    for (ri = mechatronic_system_ss_ConstP.StateSpace_B_jc[(uint32_T)is]; ri <
         mechatronic_system_ss_ConstP.StateSpace_B_jc[(uint32_T)is + 1U]; ri++)
    {
      _rtXdot->StateSpace_CSTATE[mechatronic_system_ss_ConstP.StateSpace_B_ir[ri]]
        += mechatronic_system_ss_B.TmpSignalConversionAtStateSpace[(uint32_T)is];
    }
  }

  /* End of Derivatives for StateSpace: '<Root>/State-Space' */
}

/* Model initialize function */
void mechatronic_system_ss_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&mechatronic_system_ss_M->solverInfo,
                          &mechatronic_system_ss_M->Timing.simTimeStep);
    rtsiSetTPtr(&mechatronic_system_ss_M->solverInfo, &rtmGetTPtr
                (mechatronic_system_ss_M));
    rtsiSetStepSizePtr(&mechatronic_system_ss_M->solverInfo,
                       &mechatronic_system_ss_M->Timing.stepSize0);
    rtsiSetdXPtr(&mechatronic_system_ss_M->solverInfo,
                 &mechatronic_system_ss_M->derivs);
    rtsiSetContStatesPtr(&mechatronic_system_ss_M->solverInfo, (real_T **)
                         &mechatronic_system_ss_M->contStates);
    rtsiSetNumContStatesPtr(&mechatronic_system_ss_M->solverInfo,
      &mechatronic_system_ss_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&mechatronic_system_ss_M->solverInfo,
      &mechatronic_system_ss_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&mechatronic_system_ss_M->solverInfo,
      &mechatronic_system_ss_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&mechatronic_system_ss_M->solverInfo,
      &mechatronic_system_ss_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&mechatronic_system_ss_M->solverInfo, (boolean_T**)
      &mechatronic_system_ss_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&mechatronic_system_ss_M->solverInfo,
                          (&rtmGetErrorStatus(mechatronic_system_ss_M)));
    rtsiSetRTModelPtr(&mechatronic_system_ss_M->solverInfo,
                      mechatronic_system_ss_M);
  }

  rtsiSetSimTimeStep(&mechatronic_system_ss_M->solverInfo, MAJOR_TIME_STEP);
  mechatronic_system_ss_M->intgData.f[0] = mechatronic_system_ss_M->odeF[0];
  mechatronic_system_ss_M->contStates = ((X_mechatronic_system_ss_T *)
    &mechatronic_system_ss_X);
  mechatronic_system_ss_M->contStateDisabled = ((XDis_mechatronic_system_ss_T *)
    &mechatronic_system_ss_XDis);
  mechatronic_system_ss_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&mechatronic_system_ss_M->solverInfo, (void *)
                    &mechatronic_system_ss_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&mechatronic_system_ss_M->solverInfo,
    false);
  rtsiSetSolverName(&mechatronic_system_ss_M->solverInfo,"ode1");
  rtmSetTPtr(mechatronic_system_ss_M, &mechatronic_system_ss_M->Timing.tArray[0]);
  mechatronic_system_ss_M->Timing.stepSize0 = 0.002;

  {
    int_T is;

    /* Start for If: '<Root>/If' */
    mechatronic_system_ss_DW.If_ActiveSubsystem = -1;

    /* InitializeConditions for StateSpace: '<Root>/State-Space' */
    for (is = 0; is < 6; is++) {
      mechatronic_system_ss_X.StateSpace_CSTATE[is] = 0.0;
    }

    /* End of InitializeConditions for StateSpace: '<Root>/State-Space' */
  }
}

/* Model terminate function */
void mechatronic_system_ss_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
