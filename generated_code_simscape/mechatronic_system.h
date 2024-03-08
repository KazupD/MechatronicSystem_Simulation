/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mechatronic_system.h
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

#ifndef RTW_HEADER_mechatronic_system_h_
#define RTW_HEADER_mechatronic_system_h_
#ifndef mechatronic_system_COMMON_INCLUDES_
#define mechatronic_system_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "nesl_rtw.h"
#include "mechatronic_system_dfe09280_1_gateway.h"
#endif                                 /* mechatronic_system_COMMON_INCLUDES_ */

#include "mechatronic_system_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T INPUT_2_1_1[4];               /* '<S34>/INPUT_2_1_1' */
  real_T Switch2;                      /* '<S10>/Switch2' */
  real_T Product;                      /* '<S16>/Product' */
  real_T StateSpace_o1[3];             /* '<S35>/State-Space' */
  real_T StateSpace_o2;                /* '<S35>/State-Space' */
  real_T INPUT_1_1_1[4];               /* '<S34>/INPUT_1_1_1' */
  real_T INPUT_3_1_1[4];               /* '<S34>/INPUT_3_1_1' */
  real_T STATE_1[17];                  /* '<S34>/STATE_1' */
} B_mechatronic_system_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T INPUT_2_1_1_Discrete[2];      /* '<S34>/INPUT_2_1_1' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T StateSpace_DSTATE[2];         /* '<S35>/State-Space' */
  real_T INPUT_1_1_1_Discrete[2];      /* '<S34>/INPUT_1_1_1' */
  real_T INPUT_3_1_1_Discrete[2];      /* '<S34>/INPUT_3_1_1' */
  real_T STATE_1_Discrete[16];         /* '<S34>/STATE_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S34>/OUTPUT_1_0' */
  struct {
    void *AS;
    void *BS;
    void *CS;
    void *DS;
    void *DX_COL;
    void *BD_COL;
    void *TMP1;
    void *TMP2;
    void *XTMP;
    void *SWITCH_STATUS;
    void *SWITCH_STATUS_INIT;
    void *SW_CHG;
    void *G_STATE;
    void *USWLAST;
    void *XKM12;
    void *XKP12;
    void *XLAST;
    void *ULAST;
    void *IDX_SW_CHG;
    void *Y_SWITCH;
    void *SWITCH_TYPES;
    void *IDX_OUT_SW;
    void *SWITCH_TOPO_SAVED_IDX;
    void *SWITCH_MAP;
  } StateSpace_PWORK;                  /* '<S35>/State-Space' */

  void* STATE_1_Simulator;             /* '<S34>/STATE_1' */
  void* STATE_1_SimData;               /* '<S34>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S34>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S34>/STATE_1' */
  void* STATE_1_TsInfo;                /* '<S34>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S34>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S34>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S34>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S34>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsInfo;             /* '<S34>/OUTPUT_1_0' */
  int_T StateSpace_IWORK[11];          /* '<S35>/State-Space' */
  int_T STATE_1_Modes;                 /* '<S34>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S34>/OUTPUT_1_0' */
  boolean_T STATE_1_FirstOutput;       /* '<S34>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S34>/OUTPUT_1_0' */
} DW_mechatronic_system_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: S.A
   * Referenced by: '<S35>/State-Space'
   */
  real_T StateSpace_AS_param[4];

  /* Expression: S.B
   * Referenced by: '<S35>/State-Space'
   */
  real_T StateSpace_BS_param[6];

  /* Expression: S.C
   * Referenced by: '<S35>/State-Space'
   */
  real_T StateSpace_CS_param[6];

  /* Expression: S.D
   * Referenced by: '<S35>/State-Space'
   */
  real_T StateSpace_DS_param[9];

  /* Expression: S.x0
   * Referenced by: '<S35>/State-Space'
   */
  real_T StateSpace_X0_param[2];
} ConstP_mechatronic_system_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Ug;                           /* '<Root>/Ug' */
  real_T Enable;                       /* '<Root>/Enable' */
  real_T Mass_m;                       /* '<Root>/Mass_m' */
  real_T Ug_max;                       /* '<Root>/Ug_max' */
} ExtU_mechatronic_system_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T motor_pos;                    /* '<Root>/Out1' */
  real_T motor_current;                /* '<Root>/Out2' */
  real_T motor_torque;                 /* '<Root>/Out3' */
  real_T shaft_pos;                    /* '<Root>/Out4' */
  real_T shaft_vel;                    /* '<Root>/Out5' */
  real_T shaft_acc;                    /* '<Root>/Out6' */
  real_T mass_pos;                     /* '<Root>/Out7' */
  real_T mass_vel;                     /* '<Root>/Out8' */
  real_T mass_acc;                     /* '<Root>/Out9' */
} ExtY_mechatronic_system_T;

/* Real-time Model Data Structure */
struct tag_RTM_mechatronic_system_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block signals (default storage) */
extern B_mechatronic_system_T mechatronic_system_B;

/* Block states (default storage) */
extern DW_mechatronic_system_T mechatronic_system_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_mechatronic_system_T mechatronic_system_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_mechatronic_system_T mechatronic_system_Y;

/* Constant parameters (default storage) */
extern const ConstP_mechatronic_system_T mechatronic_system_ConstP;

/* Model entry point functions */
extern void mechatronic_system_initialize(void);
extern void mechatronic_system_step(void);
extern void mechatronic_system_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mechatronic_system_T *const mechatronic_system_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S16>/Acceleration' : Unused code path elimination
 * Block '<S20>/do not delete this gain' : Unused code path elimination
 * Block '<S23>/0 1' : Unused code path elimination
 * Block '<S23>/1//Rsw' : Unused code path elimination
 * Block '<S23>/Switch' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Propagation' : Unused code path elimination
 * Block '<S19>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain' : Eliminated nontunable gain of 1
 * Block '<S23>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'mechatronic_system'
 * '<S1>'   : 'mechatronic_system/Controlled Voltage Source'
 * '<S2>'   : 'mechatronic_system/DC Machine'
 * '<S3>'   : 'mechatronic_system/Ideal Switch1'
 * '<S4>'   : 'mechatronic_system/PS-Simulink Converter'
 * '<S5>'   : 'mechatronic_system/PS-Simulink Converter1'
 * '<S6>'   : 'mechatronic_system/PS-Simulink Converter2'
 * '<S7>'   : 'mechatronic_system/PS-Simulink Converter3'
 * '<S8>'   : 'mechatronic_system/PS-Simulink Converter4'
 * '<S9>'   : 'mechatronic_system/PS-Simulink Converter5'
 * '<S10>'  : 'mechatronic_system/Saturation Dynamic'
 * '<S11>'  : 'mechatronic_system/Simulink-PS Converter'
 * '<S12>'  : 'mechatronic_system/Simulink-PS Converter1'
 * '<S13>'  : 'mechatronic_system/Simulink-PS Converter2'
 * '<S14>'  : 'mechatronic_system/Solver Configuration'
 * '<S15>'  : 'mechatronic_system/powergui'
 * '<S16>'  : 'mechatronic_system/DC Machine/Electrical model'
 * '<S17>'  : 'mechatronic_system/DC Machine/FCEM'
 * '<S18>'  : 'mechatronic_system/DC Machine/Mechanical model'
 * '<S19>'  : 'mechatronic_system/DC Machine/iA'
 * '<S20>'  : 'mechatronic_system/DC Machine/iF'
 * '<S21>'  : 'mechatronic_system/DC Machine/iA/Model'
 * '<S22>'  : 'mechatronic_system/DC Machine/iF/Model'
 * '<S23>'  : 'mechatronic_system/Ideal Switch1/Model'
 * '<S24>'  : 'mechatronic_system/Ideal Switch1/Model/Measurement list'
 * '<S25>'  : 'mechatronic_system/PS-Simulink Converter/EVAL_KEY'
 * '<S26>'  : 'mechatronic_system/PS-Simulink Converter1/EVAL_KEY'
 * '<S27>'  : 'mechatronic_system/PS-Simulink Converter2/EVAL_KEY'
 * '<S28>'  : 'mechatronic_system/PS-Simulink Converter3/EVAL_KEY'
 * '<S29>'  : 'mechatronic_system/PS-Simulink Converter4/EVAL_KEY'
 * '<S30>'  : 'mechatronic_system/PS-Simulink Converter5/EVAL_KEY'
 * '<S31>'  : 'mechatronic_system/Simulink-PS Converter/EVAL_KEY'
 * '<S32>'  : 'mechatronic_system/Simulink-PS Converter1/EVAL_KEY'
 * '<S33>'  : 'mechatronic_system/Simulink-PS Converter2/EVAL_KEY'
 * '<S34>'  : 'mechatronic_system/Solver Configuration/EVAL_KEY'
 * '<S35>'  : 'mechatronic_system/powergui/EquivalentModel1'
 * '<S36>'  : 'mechatronic_system/powergui/EquivalentModel1/Gates'
 * '<S37>'  : 'mechatronic_system/powergui/EquivalentModel1/Sources'
 * '<S38>'  : 'mechatronic_system/powergui/EquivalentModel1/Status'
 * '<S39>'  : 'mechatronic_system/powergui/EquivalentModel1/Yout'
 */
#endif                                 /* RTW_HEADER_mechatronic_system_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
