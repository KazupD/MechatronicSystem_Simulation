/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mechatronic_system_ss.h
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

#ifndef RTW_HEADER_mechatronic_system_ss_h_
#define RTW_HEADER_mechatronic_system_ss_h_
#ifndef mechatronic_system_ss_COMMON_INCLUDES_
#define mechatronic_system_ss_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                              /* mechatronic_system_ss_COMMON_INCLUDES_ */

#include "mechatronic_system_ss_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T TmpSignalConversionAtStateSpace[6];
  real_T Merge;                        /* '<Root>/Merge' */
} B_mechatronic_system_ss_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int8_T If_ActiveSubsystem;           /* '<Root>/If' */
} DW_mechatronic_system_ss_T;

/* Continuous states (default storage) */
typedef struct {
  real_T StateSpace_CSTATE[6];         /* '<Root>/State-Space' */
} X_mechatronic_system_ss_T;

/* State derivatives (default storage) */
typedef struct {
  real_T StateSpace_CSTATE[6];         /* '<Root>/State-Space' */
} XDot_mechatronic_system_ss_T;

/* State disabled  */
typedef struct {
  boolean_T StateSpace_CSTATE[6];      /* '<Root>/State-Space' */
} XDis_mechatronic_system_ss_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: StateSpace_A_pr
   * Referenced by: '<Root>/State-Space'
   */
  real_T StateSpace_A_pr[12];

  /* Computed Parameter: StateSpace_A_ir
   * Referenced by: '<Root>/State-Space'
   */
  uint32_T StateSpace_A_ir[12];

  /* Computed Parameter: StateSpace_A_jc
   * Referenced by: '<Root>/State-Space'
   */
  uint32_T StateSpace_A_jc[7];

  /* Computed Parameter: StateSpace_B_ir
   * Referenced by: '<Root>/State-Space'
   */
  uint32_T StateSpace_B_ir[2];

  /* Computed Parameter: StateSpace_B_jc
   * Referenced by: '<Root>/State-Space'
   */
  uint32_T StateSpace_B_jc[7];
} ConstP_mechatronic_system_ss_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Ug;                           /* '<Root>/Ug' */
  real_T Ug_max;                       /* '<Root>/Ug_max' */
  real_T Enable;                       /* '<Root>/Enable' */
} ExtU_mechatronic_system_ss_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T charge;                       /* '<Root>/charge' */
  real_T motor_current;                /* '<Root>/motor_current' */
  real_T shaft_pos;                    /* '<Root>/shaft_pos' */
  real_T shaft_vel;                    /* '<Root>/shaft_vel' */
  real_T mass_pos;                     /* '<Root>/mass_pos' */
  real_T mass_vel;                     /* '<Root>/mass_vel' */
} ExtY_mechatronic_system_ss_T;

/* Real-time Model Data Structure */
struct tag_RTM_mechatronic_system_ss_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_mechatronic_system_ss_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_mechatronic_system_ss_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][6];
  ODE1_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_mechatronic_system_ss_T mechatronic_system_ss_B;

/* Continuous states (default storage) */
extern X_mechatronic_system_ss_T mechatronic_system_ss_X;

/* Disabled states (default storage) */
extern XDis_mechatronic_system_ss_T mechatronic_system_ss_XDis;

/* Block states (default storage) */
extern DW_mechatronic_system_ss_T mechatronic_system_ss_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_mechatronic_system_ss_T mechatronic_system_ss_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_mechatronic_system_ss_T mechatronic_system_ss_Y;

/* Constant parameters (default storage) */
extern const ConstP_mechatronic_system_ss_T mechatronic_system_ss_ConstP;

/* Model entry point functions */
extern void mechatronic_system_ss_initialize(void);
extern void mechatronic_system_ss_step(void);
extern void mechatronic_system_ss_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mechatronic_system_s_T *const mechatronic_system_ss_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Data Type Propagation' : Unused code path elimination
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
 * '<Root>' : 'mechatronic_system_ss'
 * '<S1>'   : 'mechatronic_system_ss/If Action Subsystem'
 * '<S2>'   : 'mechatronic_system_ss/If Action Subsystem1'
 * '<S3>'   : 'mechatronic_system_ss/If Action Subsystem2'
 * '<S4>'   : 'mechatronic_system_ss/Saturation Dynamic'
 */
#endif                                 /* RTW_HEADER_mechatronic_system_ss_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
