/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mechatronic_system.c
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

#include "mechatronic_system.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>
#include "mechatronic_system_private.h"

/* Block signals (default storage) */
B_mechatronic_system_T mechatronic_system_B;

/* Block states (default storage) */
DW_mechatronic_system_T mechatronic_system_DW;

/* External inputs (root inport signals with default storage) */
ExtU_mechatronic_system_T mechatronic_system_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_mechatronic_system_T mechatronic_system_Y;

/* Real-time model */
static RT_MODEL_mechatronic_system_T mechatronic_system_M_;
RT_MODEL_mechatronic_system_T *const mechatronic_system_M =
  &mechatronic_system_M_;

/* Model step function */
void mechatronic_system_step(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  NeuDiagnosticTree *diagnosticTree_0;
  NeuDiagnosticTree *diagnosticTree_1;
  char *msg;
  char *msg_0;
  char *msg_1;
  real_T tmp_3[29];
  real_T tmp_0[12];
  real_T tmp_5[12];
  real_T rtb_OUTPUT_1_0[6];
  real_T time;
  real_T time_0;
  real_T time_1;
  real_T time_2;
  real_T time_3;
  real_T time_tmp;
  real_T time_tmp_0;
  int32_T isHit;
  int32_T isHit_0;
  int32_T tmp_2;
  int_T tmp_4[5];
  int_T tmp_1[4];
  int_T tmp_6[4];
  boolean_T tmp;

  /* SimscapeInputBlock: '<S34>/INPUT_2_1_1' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Inport: '<Root>/Mass_m'
   */
  mechatronic_system_B.INPUT_2_1_1[0] = -9.81 * mechatronic_system_U.Mass_m;
  mechatronic_system_B.INPUT_2_1_1[1] = 0.0;
  mechatronic_system_B.INPUT_2_1_1[2] = 0.0;
  mechatronic_system_DW.INPUT_2_1_1_Discrete[0] =
    !(mechatronic_system_B.INPUT_2_1_1[0] ==
      mechatronic_system_DW.INPUT_2_1_1_Discrete[1]);
  mechatronic_system_DW.INPUT_2_1_1_Discrete[1] =
    mechatronic_system_B.INPUT_2_1_1[0];
  mechatronic_system_B.INPUT_2_1_1[0] =
    mechatronic_system_DW.INPUT_2_1_1_Discrete[1];
  mechatronic_system_B.INPUT_2_1_1[3] =
    mechatronic_system_DW.INPUT_2_1_1_Discrete[0];

  /* Switch: '<S10>/Switch2' incorporates:
   *  Gain: '<Root>/Gain2'
   *  Inport: '<Root>/Ug'
   *  Inport: '<Root>/Ug_max'
   *  RelationalOperator: '<S10>/LowerRelop1'
   *  RelationalOperator: '<S10>/UpperRelop'
   *  Switch: '<S10>/Switch'
   */
  if (mechatronic_system_U.Ug > mechatronic_system_U.Ug_max) {
    /* Switch: '<S10>/Switch2' */
    mechatronic_system_B.Switch2 = mechatronic_system_U.Ug_max;
  } else if (mechatronic_system_U.Ug < -mechatronic_system_U.Ug_max) {
    /* Switch: '<S10>/Switch' incorporates:
     *  Gain: '<Root>/Gain2'
     *  Switch: '<S10>/Switch2'
     */
    mechatronic_system_B.Switch2 = -mechatronic_system_U.Ug_max;
  } else {
    /* Switch: '<S10>/Switch2' */
    mechatronic_system_B.Switch2 = mechatronic_system_U.Ug;
  }

  /* End of Switch: '<S10>/Switch2' */

  /* Product: '<S16>/Product' incorporates:
   *  Constant: '<S16>/Constant'
   *  Delay: '<Root>/Delay'
   */
  mechatronic_system_B.Product = mechatronic_system_DW.Delay_DSTATE * 0.1;

  /* S-Function (sfun_spssw_discc): '<S35>/State-Space' incorporates:
   *  Constant: '<S37>/SwitchCurrents'
   *  Inport: '<Root>/Enable'
   */

  /* S-Function block: <S35>/State-Space */
  {
    real_T accum;

    /* Circuit has switches */
    int_T *switch_status = (int_T*)
      mechatronic_system_DW.StateSpace_PWORK.SWITCH_STATUS;
    int_T *switch_status_init = (int_T*)
      mechatronic_system_DW.StateSpace_PWORK.SWITCH_STATUS_INIT;
    int_T *SwitchChange = (int_T*) mechatronic_system_DW.StateSpace_PWORK.SW_CHG;
    int_T *gState = (int_T*) mechatronic_system_DW.StateSpace_PWORK.G_STATE;
    real_T *yswitch = (real_T*)mechatronic_system_DW.StateSpace_PWORK.Y_SWITCH;
    int_T *switchTypes = (int_T*)
      mechatronic_system_DW.StateSpace_PWORK.SWITCH_TYPES;
    int_T *idxOutSw = (int_T*) mechatronic_system_DW.StateSpace_PWORK.IDX_OUT_SW;
    real_T *DxCol = (real_T*)mechatronic_system_DW.StateSpace_PWORK.DX_COL;
    real_T *tmp2 = (real_T*)mechatronic_system_DW.StateSpace_PWORK.TMP2;
    real_T *BDcol = (real_T*)mechatronic_system_DW.StateSpace_PWORK.BD_COL;
    real_T *tmp1 = (real_T*)mechatronic_system_DW.StateSpace_PWORK.TMP1;
    real_T *uswlast = (real_T*)mechatronic_system_DW.StateSpace_PWORK.USWLAST;
    int_T newState;
    int_T swChanged = 0;
    int loopsToDo = 20;
    real_T temp;

    /* keep an initial copy of switch_status*/
    memcpy(switch_status_init, switch_status, 1 * sizeof(int_T));
    memcpy(uswlast, &mechatronic_system_B.StateSpace_o1[0], 1*sizeof(real_T));
    do {
      if (loopsToDo == 1) {            /* Need to reset some variables: */
        swChanged = 0;

        /* return to the original switch status*/
        {
          int_T i1;
          for (i1=0; i1 < 1; i1++) {
            swChanged = ((SwitchChange[i1] = switch_status_init[i1] -
                          switch_status[i1]) != 0) ? 1 : swChanged;
            switch_status[i1] = switch_status_init[i1];
          }
        }
      } else {
        /*
         * Compute outputs:
         * ---------------
         */
        real_T *Cs = (real_T*)mechatronic_system_DW.StateSpace_PWORK.CS;
        real_T *Ds = (real_T*)mechatronic_system_DW.StateSpace_PWORK.DS;
        accum = 0.0;
        accum += *(Cs++) * mechatronic_system_DW.StateSpace_DSTATE[0];
        accum += *(Cs++) * mechatronic_system_DW.StateSpace_DSTATE[1];
        accum += *(Ds++) * 0.0;
        accum += *(Ds++) * mechatronic_system_B.Switch2;
        accum += *(Ds++) * mechatronic_system_B.Product;
        mechatronic_system_B.StateSpace_o1[0] = accum;
        accum = 0.0;
        accum += *(Cs++) * mechatronic_system_DW.StateSpace_DSTATE[0];
        accum += *(Cs++) * mechatronic_system_DW.StateSpace_DSTATE[1];
        accum += *(Ds++) * 0.0;
        accum += *(Ds++) * mechatronic_system_B.Switch2;
        accum += *(Ds++) * mechatronic_system_B.Product;
        mechatronic_system_B.StateSpace_o1[1] = accum;
        accum = 0.0;
        accum += *(Cs++) * mechatronic_system_DW.StateSpace_DSTATE[0];
        accum += *(Cs++) * mechatronic_system_DW.StateSpace_DSTATE[1];
        accum += *(Ds++) * 0.0;
        accum += *(Ds++) * mechatronic_system_B.Switch2;
        accum += *(Ds++) * mechatronic_system_B.Product;
        mechatronic_system_B.StateSpace_o1[2] = accum;
        swChanged = 0;

        /* Ideal switch */
        newState = gState[0] > 0 ? 1 : 0;
        swChanged = ((SwitchChange[0] = newState - switch_status[0]) != 0) ? 1 :
          swChanged;
        switch_status[0] = newState;   /* Keep new state */
      }

      /*
       * Compute new As, Bs, Cs and Ds matrixes:
       * --------------------------------------
       */
      if (swChanged) {
        real_T *As = (real_T*)mechatronic_system_DW.StateSpace_PWORK.AS;
        real_T *Cs = (real_T*)mechatronic_system_DW.StateSpace_PWORK.CS;
        real_T *Bs = (real_T*)mechatronic_system_DW.StateSpace_PWORK.BS;
        real_T *Ds = (real_T*)mechatronic_system_DW.StateSpace_PWORK.DS;
        real_T a1;

        {
          int_T i1;
          for (i1=0; i1 < 1; i1++) {
            if (SwitchChange[i1] != 0) {
              a1 = 1.0E+6*SwitchChange[i1];
              temp = 1/(1-Ds[i1*4]*a1);
              DxCol[0]= Ds[0 + i1]*temp*a1;
              DxCol[1]= Ds[3 + i1]*temp*a1;
              DxCol[2]= Ds[6 + i1]*temp*a1;
              DxCol[i1] = temp;
              BDcol[0]= Bs[0 + i1]*a1;
              BDcol[1]= Bs[3 + i1]*a1;

              /* Copy row nSw of Cs into tmp1 and zero it out in Cs */
              memcpy(tmp1, &Cs[i1 * 2], 2 * sizeof(real_T));
              memset(&Cs[i1 * 2], '\0', 2 * sizeof(real_T));

              /* Copy row nSw of Ds into tmp2 and zero it out in Ds */
              memcpy(tmp2, &Ds[i1 * 3], 3 * sizeof(real_T));
              memset(&Ds[i1 * 3], '\0', 3 * sizeof(real_T));

              /* Cs = Cs + DxCol * tmp1, Ds = Ds + DxCol * tmp2 *******************/
              a1 = DxCol[0];
              Cs[0 + 0] += a1 * tmp1[0];
              Cs[0 + 1] += a1 * tmp1[1];
              Ds[0 + 0] += a1 * tmp2[0];
              Ds[0 + 1] += a1 * tmp2[1];
              Ds[0 + 2] += a1 * tmp2[2];
              a1 = DxCol[1];
              Cs[2 + 0] += a1 * tmp1[0];
              Cs[2 + 1] += a1 * tmp1[1];
              Ds[3 + 0] += a1 * tmp2[0];
              Ds[3 + 1] += a1 * tmp2[1];
              Ds[3 + 2] += a1 * tmp2[2];
              a1 = DxCol[2];
              Cs[4 + 0] += a1 * tmp1[0];
              Cs[4 + 1] += a1 * tmp1[1];
              Ds[6 + 0] += a1 * tmp2[0];
              Ds[6 + 1] += a1 * tmp2[1];
              Ds[6 + 2] += a1 * tmp2[2];

              /* As = As + BdCol*Cs(nSw,:), Bs = Bs + BdCol*Ds(nSw,:) *************/
              a1 = BDcol[0];
              As[0 + 0] += a1 * Cs[i1 * 2 + 0];
              As[0 + 1] += a1 * Cs[i1 * 2 + 1];
              Bs[0 + 0] += a1 * Ds[i1 * 3 + 0];
              Bs[0 + 1] += a1 * Ds[i1 * 3 + 1];
              Bs[0 + 2] += a1 * Ds[i1 * 3 + 2];
              a1 = BDcol[1];
              As[2 + 0] += a1 * Cs[i1 * 2 + 0];
              As[2 + 1] += a1 * Cs[i1 * 2 + 1];
              Bs[3 + 0] += a1 * Ds[i1 * 3 + 0];
              Bs[3 + 1] += a1 * Ds[i1 * 3 + 1];
              Bs[3 + 2] += a1 * Ds[i1 * 3 + 2];
            }
          }
        }
      }                                /* if (swChanged) */
    } while (swChanged > 0 && --loopsToDo > 0);

    if (loopsToDo == 0) {
      real_T *Cs = (real_T*)mechatronic_system_DW.StateSpace_PWORK.CS;
      real_T *Ds = (real_T*)mechatronic_system_DW.StateSpace_PWORK.DS;
      accum = 0.0;
      accum += *(Cs++) * mechatronic_system_DW.StateSpace_DSTATE[0];
      accum += *(Cs++) * mechatronic_system_DW.StateSpace_DSTATE[1];
      accum += *(Ds++) * 0.0;
      accum += *(Ds++) * mechatronic_system_B.Switch2;
      accum += *(Ds++) * mechatronic_system_B.Product;
      mechatronic_system_B.StateSpace_o1[0] = accum;
      accum = 0.0;
      accum += *(Cs++) * mechatronic_system_DW.StateSpace_DSTATE[0];
      accum += *(Cs++) * mechatronic_system_DW.StateSpace_DSTATE[1];
      accum += *(Ds++) * 0.0;
      accum += *(Ds++) * mechatronic_system_B.Switch2;
      accum += *(Ds++) * mechatronic_system_B.Product;
      mechatronic_system_B.StateSpace_o1[1] = accum;
      accum = 0.0;
      accum += *(Cs++) * mechatronic_system_DW.StateSpace_DSTATE[0];
      accum += *(Cs++) * mechatronic_system_DW.StateSpace_DSTATE[1];
      accum += *(Ds++) * 0.0;
      accum += *(Ds++) * mechatronic_system_B.Switch2;
      accum += *(Ds++) * mechatronic_system_B.Product;
      mechatronic_system_B.StateSpace_o1[2] = accum;
    }

    /* Output new switches states */
    mechatronic_system_B.StateSpace_o2 = (real_T)switch_status[0];
  }

  /* Outport: '<Root>/Out3' incorporates:
   *  Constant: '<S16>/Constant'
   *  Product: '<S16>/Product1'
   */
  mechatronic_system_Y.motor_torque = mechatronic_system_B.StateSpace_o1[1] *
    0.1;

  /* SimscapeInputBlock: '<S34>/INPUT_1_1_1' incorporates:
   *  Outport: '<Root>/Out3'
   */
  mechatronic_system_B.INPUT_1_1_1[0] = mechatronic_system_Y.motor_torque;
  mechatronic_system_B.INPUT_1_1_1[1] = 0.0;
  mechatronic_system_B.INPUT_1_1_1[2] = 0.0;
  mechatronic_system_DW.INPUT_1_1_1_Discrete[0] =
    !(mechatronic_system_B.INPUT_1_1_1[0] ==
      mechatronic_system_DW.INPUT_1_1_1_Discrete[1]);
  mechatronic_system_DW.INPUT_1_1_1_Discrete[1] =
    mechatronic_system_B.INPUT_1_1_1[0];
  mechatronic_system_B.INPUT_1_1_1[0] =
    mechatronic_system_DW.INPUT_1_1_1_Discrete[1];
  mechatronic_system_B.INPUT_1_1_1[3] =
    mechatronic_system_DW.INPUT_1_1_1_Discrete[0];

  /* SimscapeInputBlock: '<S34>/INPUT_3_1_1' incorporates:
   *  Inport: '<Root>/Mass_m'
   */
  mechatronic_system_B.INPUT_3_1_1[0] = mechatronic_system_U.Mass_m;
  mechatronic_system_B.INPUT_3_1_1[1] = 0.0;
  mechatronic_system_B.INPUT_3_1_1[2] = 0.0;
  mechatronic_system_DW.INPUT_3_1_1_Discrete[0] =
    !(mechatronic_system_B.INPUT_3_1_1[0] ==
      mechatronic_system_DW.INPUT_3_1_1_Discrete[1]);
  mechatronic_system_DW.INPUT_3_1_1_Discrete[1] =
    mechatronic_system_B.INPUT_3_1_1[0];
  mechatronic_system_B.INPUT_3_1_1[0] =
    mechatronic_system_DW.INPUT_3_1_1_Discrete[1];
  mechatronic_system_B.INPUT_3_1_1[3] =
    mechatronic_system_DW.INPUT_3_1_1_Discrete[0];

  /* SimscapeExecutionBlock: '<S34>/STATE_1' incorporates:
   *  SimscapeExecutionBlock: '<S34>/OUTPUT_1_0'
   */
  simulationData = (NeslSimulationData *)mechatronic_system_DW.STATE_1_SimData;
  time_tmp = ((mechatronic_system_M->Timing.clockTick0) * 0.01);
  time = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 16;
  simulationData->mData->mDiscStates.mX =
    &mechatronic_system_DW.STATE_1_Discrete[0];
  simulationData->mData->mModeVector.mN = 1;
  simulationData->mData->mModeVector.mX = &mechatronic_system_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = true;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = true;
  tmp_1[0] = 0;
  tmp_0[0] = mechatronic_system_B.INPUT_2_1_1[0];
  tmp_0[1] = mechatronic_system_B.INPUT_2_1_1[1];
  tmp_0[2] = mechatronic_system_B.INPUT_2_1_1[2];
  tmp_0[3] = mechatronic_system_B.INPUT_2_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = mechatronic_system_B.INPUT_1_1_1[0];
  tmp_0[5] = mechatronic_system_B.INPUT_1_1_1[1];
  tmp_0[6] = mechatronic_system_B.INPUT_1_1_1[2];
  tmp_0[7] = mechatronic_system_B.INPUT_1_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = mechatronic_system_B.INPUT_3_1_1[0];
  tmp_0[9] = mechatronic_system_B.INPUT_3_1_1[1];
  tmp_0[10] = mechatronic_system_B.INPUT_3_1_1[2];
  tmp_0[11] = mechatronic_system_B.INPUT_3_1_1[3];
  tmp_1[3] = 12;
  simulationData->mData->mInputValues.mN = 12;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 4;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mOutputs.mN = 17;
  simulationData->mData->mOutputs.mX = &mechatronic_system_B.STATE_1[0];
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  time_tmp_0 = ((mechatronic_system_M->Timing.clockTick0) * 0.01);
  time_0 = time_tmp_0;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  isHit = 0;
  simulationData->mData->mSampleHits.mN = 1;
  simulationData->mData->mSampleHits.mX = &isHit;
  simulationData->mData->mIsFundamentalSampleHit = true;
  diagnosticManager = (NeuDiagnosticManager *)
    mechatronic_system_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)
    mechatronic_system_DW.STATE_1_Simulator, NESL_SIM_OUTPUTS, simulationData,
    diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(mechatronic_system_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(mechatronic_system_M, msg);
    }
  }

  /* End of SimscapeExecutionBlock: '<S34>/STATE_1' */

  /* SimscapeExecutionBlock: '<S34>/OUTPUT_1_0' */
  simulationData = (NeslSimulationData *)
    mechatronic_system_DW.OUTPUT_1_0_SimData;
  time_1 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_1;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX =
    &mechatronic_system_DW.OUTPUT_1_0_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX =
    &mechatronic_system_DW.OUTPUT_1_0_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = true;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = true;
  tmp_4[0] = 0;
  tmp_3[0] = mechatronic_system_B.INPUT_2_1_1[0];
  tmp_3[1] = mechatronic_system_B.INPUT_2_1_1[1];
  tmp_3[2] = mechatronic_system_B.INPUT_2_1_1[2];
  tmp_3[3] = mechatronic_system_B.INPUT_2_1_1[3];
  tmp_4[1] = 4;
  tmp_3[4] = mechatronic_system_B.INPUT_1_1_1[0];
  tmp_3[5] = mechatronic_system_B.INPUT_1_1_1[1];
  tmp_3[6] = mechatronic_system_B.INPUT_1_1_1[2];
  tmp_3[7] = mechatronic_system_B.INPUT_1_1_1[3];
  tmp_4[2] = 8;
  tmp_3[8] = mechatronic_system_B.INPUT_3_1_1[0];
  tmp_3[9] = mechatronic_system_B.INPUT_3_1_1[1];
  tmp_3[10] = mechatronic_system_B.INPUT_3_1_1[2];
  tmp_3[11] = mechatronic_system_B.INPUT_3_1_1[3];
  tmp_4[3] = 12;
  memcpy(&tmp_3[12], &mechatronic_system_B.STATE_1[0], 17U * sizeof(real_T));
  tmp_4[4] = 29;
  simulationData->mData->mInputValues.mN = 29;
  simulationData->mData->mInputValues.mX = &tmp_3[0];
  simulationData->mData->mInputOffsets.mN = 5;
  simulationData->mData->mInputOffsets.mX = &tmp_4[0];
  simulationData->mData->mOutputs.mN = 6;
  simulationData->mData->mOutputs.mX = &rtb_OUTPUT_1_0[0];
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  time_2 = time_tmp_0;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_2;
  isHit_0 = 0;
  simulationData->mData->mSampleHits.mN = 1;
  simulationData->mData->mSampleHits.mX = &isHit_0;
  simulationData->mData->mIsFundamentalSampleHit = true;
  diagnosticManager = (NeuDiagnosticManager *)
    mechatronic_system_DW.OUTPUT_1_0_DiagMgr;
  diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)
    mechatronic_system_DW.OUTPUT_1_0_Simulator, NESL_SIM_OUTPUTS, simulationData,
    diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(mechatronic_system_M));
    if (tmp) {
      msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
      rtmSetErrorStatus(mechatronic_system_M, msg_0);
    }
  }

  /* Outport: '<Root>/Out5' */
  mechatronic_system_Y.shaft_vel = rtb_OUTPUT_1_0[1];

  /* Outport: '<Root>/Out4' */
  mechatronic_system_Y.shaft_pos = rtb_OUTPUT_1_0[0];

  /* Outport: '<Root>/Out6' */
  mechatronic_system_Y.shaft_acc = rtb_OUTPUT_1_0[2];

  /* Outport: '<Root>/Out7' */
  mechatronic_system_Y.mass_pos = rtb_OUTPUT_1_0[4];

  /* Outport: '<Root>/Out8' */
  mechatronic_system_Y.mass_vel = rtb_OUTPUT_1_0[5];

  /* Outport: '<Root>/Out9' */
  mechatronic_system_Y.mass_acc = rtb_OUTPUT_1_0[3];

  /* Outport: '<Root>/Out2' */
  mechatronic_system_Y.motor_current = mechatronic_system_B.StateSpace_o1[1];

  /* Outport: '<Root>/Out1' incorporates:
   *  Delay: '<Root>/Delay'
   */
  mechatronic_system_Y.motor_pos = mechatronic_system_DW.Delay_DSTATE;

  /* Update for Delay: '<Root>/Delay' */
  mechatronic_system_DW.Delay_DSTATE = rtb_OUTPUT_1_0[1];

  /* Update for S-Function (sfun_spssw_discc): '<S35>/State-Space' incorporates:
   *  Constant: '<S37>/SwitchCurrents'
   *  Inport: '<Root>/Enable'
   */

  /* S-Function block: <S35>/State-Space */
  {
    const real_T *As = (real_T*)mechatronic_system_DW.StateSpace_PWORK.AS;
    const real_T *Bs = (real_T*)mechatronic_system_DW.StateSpace_PWORK.BS;
    real_T *xtmp = (real_T*)mechatronic_system_DW.StateSpace_PWORK.XTMP;
    real_T accum;

    /* Calculate new states... */
    accum = 0.0;
    accum += *(As++) * mechatronic_system_DW.StateSpace_DSTATE[0];
    accum += *(As++) * mechatronic_system_DW.StateSpace_DSTATE[1];
    accum += *(Bs++) * 0.0;
    accum += *(Bs++) * mechatronic_system_B.Switch2;
    accum += *(Bs++) * mechatronic_system_B.Product;
    xtmp[0] = accum;
    accum = 0.0;
    accum += *(As++) * mechatronic_system_DW.StateSpace_DSTATE[0];
    accum += *(As++) * mechatronic_system_DW.StateSpace_DSTATE[1];
    accum += *(Bs++) * 0.0;
    accum += *(Bs++) * mechatronic_system_B.Switch2;
    accum += *(Bs++) * mechatronic_system_B.Product;
    xtmp[1] = accum;
    mechatronic_system_DW.StateSpace_DSTATE[0] = xtmp[0];
    mechatronic_system_DW.StateSpace_DSTATE[1] = xtmp[1];

    {
      int_T *gState = (int_T*)mechatronic_system_DW.StateSpace_PWORK.G_STATE;

      /* Store switch gates values for next step */
      *(gState++) = (int_T) mechatronic_system_U.Enable;
    }
  }

  /* Update for SimscapeExecutionBlock: '<S34>/STATE_1' */
  simulationData = (NeslSimulationData *)mechatronic_system_DW.STATE_1_SimData;
  time_3 = time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_3;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 16;
  simulationData->mData->mDiscStates.mX =
    &mechatronic_system_DW.STATE_1_Discrete[0];
  simulationData->mData->mModeVector.mN = 1;
  simulationData->mData->mModeVector.mX = &mechatronic_system_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = true;
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = true;
  tmp_6[0] = 0;
  tmp_5[0] = mechatronic_system_B.INPUT_2_1_1[0];
  tmp_5[1] = mechatronic_system_B.INPUT_2_1_1[1];
  tmp_5[2] = mechatronic_system_B.INPUT_2_1_1[2];
  tmp_5[3] = mechatronic_system_B.INPUT_2_1_1[3];
  tmp_6[1] = 4;
  tmp_5[4] = mechatronic_system_B.INPUT_1_1_1[0];
  tmp_5[5] = mechatronic_system_B.INPUT_1_1_1[1];
  tmp_5[6] = mechatronic_system_B.INPUT_1_1_1[2];
  tmp_5[7] = mechatronic_system_B.INPUT_1_1_1[3];
  tmp_6[2] = 8;
  tmp_5[8] = mechatronic_system_B.INPUT_3_1_1[0];
  tmp_5[9] = mechatronic_system_B.INPUT_3_1_1[1];
  tmp_5[10] = mechatronic_system_B.INPUT_3_1_1[2];
  tmp_5[11] = mechatronic_system_B.INPUT_3_1_1[3];
  tmp_6[3] = 12;
  simulationData->mData->mInputValues.mN = 12;
  simulationData->mData->mInputValues.mX = &tmp_5[0];
  simulationData->mData->mInputOffsets.mN = 4;
  simulationData->mData->mInputOffsets.mX = &tmp_6[0];
  diagnosticManager = (NeuDiagnosticManager *)
    mechatronic_system_DW.STATE_1_DiagMgr;
  diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)
    mechatronic_system_DW.STATE_1_Simulator, NESL_SIM_UPDATE, simulationData,
    diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(mechatronic_system_M));
    if (tmp) {
      msg_1 = rtw_diagnostics_msg(diagnosticTree_1);
      rtmSetErrorStatus(mechatronic_system_M, msg_1);
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  mechatronic_system_M->Timing.clockTick0++;
}

/* Model initialize function */
void mechatronic_system_initialize(void)
{
  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    char *msg;
    char *msg_0;
    real_T tmp_2;
    int32_T tmp_3;
    boolean_T tmp_0;

    /* Start for S-Function (sfun_spssw_discc): '<S35>/State-Space' incorporates:
     *  Constant: '<S37>/SwitchCurrents'
     *  Inport: '<Root>/Enable'
     */

    /* S-Function block: <S35>/State-Space */
    {
      mechatronic_system_DW.StateSpace_PWORK.AS = (real_T*)calloc(2 * 2, sizeof
        (real_T));
      mechatronic_system_DW.StateSpace_PWORK.BS = (real_T*)calloc(2 * 3, sizeof
        (real_T));
      mechatronic_system_DW.StateSpace_PWORK.CS = (real_T*)calloc(3 * 2, sizeof
        (real_T));
      mechatronic_system_DW.StateSpace_PWORK.DS = (real_T*)calloc(3 * 3, sizeof
        (real_T));
      mechatronic_system_DW.StateSpace_PWORK.DX_COL = (real_T*)calloc(3, sizeof
        (real_T));
      mechatronic_system_DW.StateSpace_PWORK.TMP2 = (real_T*)calloc(3, sizeof
        (real_T));
      mechatronic_system_DW.StateSpace_PWORK.BD_COL = (real_T*)calloc(2, sizeof
        (real_T));
      mechatronic_system_DW.StateSpace_PWORK.TMP1 = (real_T*)calloc(2, sizeof
        (real_T));
      mechatronic_system_DW.StateSpace_PWORK.XTMP = (real_T*)calloc(2, sizeof
        (real_T));
      mechatronic_system_DW.StateSpace_PWORK.SWITCH_STATUS = (int_T*)calloc(1,
        sizeof(int_T));
      mechatronic_system_DW.StateSpace_PWORK.SW_CHG = (int_T*)calloc(1, sizeof
        (int_T));
      mechatronic_system_DW.StateSpace_PWORK.G_STATE = (int_T*)calloc(1, sizeof
        (int_T));
      mechatronic_system_DW.StateSpace_PWORK.Y_SWITCH = (real_T*)calloc(1,
        sizeof(real_T));
      mechatronic_system_DW.StateSpace_PWORK.SWITCH_TYPES = (int_T*)calloc(1,
        sizeof(int_T));
      mechatronic_system_DW.StateSpace_PWORK.IDX_OUT_SW = (int_T*)calloc(1,
        sizeof(int_T));
      mechatronic_system_DW.StateSpace_PWORK.SWITCH_STATUS_INIT = (int_T*)calloc
        (1, sizeof(int_T));
      mechatronic_system_DW.StateSpace_PWORK.USWLAST = (real_T*)calloc(1, sizeof
        (real_T));
    }

    /* Start for SimscapeExecutionBlock: '<S34>/STATE_1' */
    tmp = nesl_lease_simulator("mechatronic_system/Solver Configuration_1", 0, 0);
    mechatronic_system_DW.STATE_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(mechatronic_system_DW.STATE_1_Simulator);
    if (tmp_0) {
      mechatronic_system_dfe09280_1_gateway();
      tmp = nesl_lease_simulator("mechatronic_system/Solver Configuration_1", 0,
        0);
      mechatronic_system_DW.STATE_1_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    mechatronic_system_DW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    mechatronic_system_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_ODE;
    modelParameters.mSolverAbsTol = 0.001;
    modelParameters.mSolverRelTol = 0.001;
    modelParameters.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters.mRTWModifiedTimeStamp = 6.31647305E+8;
    modelParameters.mUseModelRefSolver = false;
    modelParameters.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters.mSolverTolerance = tmp_2;
    tmp_2 = 0.01;
    modelParameters.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters.mIsUsingODEN = tmp_0;
    modelParameters.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      mechatronic_system_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      mechatronic_system_DW.STATE_1_Simulator, &modelParameters,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(mechatronic_system_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(mechatronic_system_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S34>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S34>/OUTPUT_1_0' */
    tmp = nesl_lease_simulator("mechatronic_system/Solver Configuration_1", 1, 0);
    mechatronic_system_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(mechatronic_system_DW.OUTPUT_1_0_Simulator);
    if (tmp_0) {
      mechatronic_system_dfe09280_1_gateway();
      tmp = nesl_lease_simulator("mechatronic_system/Solver Configuration_1", 1,
        0);
      mechatronic_system_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    mechatronic_system_DW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    mechatronic_system_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_ODE;
    modelParameters_0.mSolverAbsTol = 0.001;
    modelParameters_0.mSolverRelTol = 0.001;
    modelParameters_0.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters_0.mRTWModifiedTimeStamp = 6.31647305E+8;
    modelParameters_0.mUseModelRefSolver = false;
    modelParameters_0.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_2;
    tmp_2 = 0.01;
    modelParameters_0.mFixedStepSize = tmp_2;
    tmp_0 = false;
    modelParameters_0.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    modelParameters_0.mIsUsingODEN = tmp_0;
    modelParameters_0.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      mechatronic_system_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      mechatronic_system_DW.OUTPUT_1_0_Simulator, &modelParameters_0,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(mechatronic_system_M));
      if (tmp_0) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(mechatronic_system_M, msg_0);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S34>/OUTPUT_1_0' */

    /* InitializeConditions for S-Function (sfun_spssw_discc): '<S35>/State-Space' incorporates:
     *  Constant: '<S37>/SwitchCurrents'
     *  Inport: '<Root>/Enable'
     */
    {
      int32_T i, j;
      real_T *As = (real_T*)mechatronic_system_DW.StateSpace_PWORK.AS;
      real_T *Bs = (real_T*)mechatronic_system_DW.StateSpace_PWORK.BS;
      real_T *Cs = (real_T*)mechatronic_system_DW.StateSpace_PWORK.CS;
      real_T *Ds = (real_T*)mechatronic_system_DW.StateSpace_PWORK.DS;
      real_T *X0 = (real_T*)&mechatronic_system_DW.StateSpace_DSTATE[0];
      for (i = 0; i < 2; i++) {
        X0[i] = (mechatronic_system_ConstP.StateSpace_X0_param[i]);
      }

      /* Copy and transpose A and B */
      for (i=0; i<2; i++) {
        for (j=0; j<2; j++)
          As[i*2 + j] = (mechatronic_system_ConstP.StateSpace_AS_param[i + j*2]);
        for (j=0; j<3; j++)
          Bs[i*3 + j] = (mechatronic_system_ConstP.StateSpace_BS_param[i + j*2]);
      }

      /* Copy and transpose C */
      for (i=0; i<3; i++) {
        for (j=0; j<2; j++)
          Cs[i*2 + j] = (mechatronic_system_ConstP.StateSpace_CS_param[i + j*3]);
      }

      /* Copy and transpose D */
      for (i=0; i<3; i++) {
        for (j=0; j<3; j++)
          Ds[i*3 + j] = (mechatronic_system_ConstP.StateSpace_DS_param[i + j*3]);
      }

      {
        /* Switches work vectors */
        int_T *switch_status = (int_T*)
          mechatronic_system_DW.StateSpace_PWORK.SWITCH_STATUS;
        int_T *gState = (int_T*)mechatronic_system_DW.StateSpace_PWORK.G_STATE;
        real_T *yswitch = (real_T*)
          mechatronic_system_DW.StateSpace_PWORK.Y_SWITCH;
        int_T *switchTypes = (int_T*)
          mechatronic_system_DW.StateSpace_PWORK.SWITCH_TYPES;
        int_T *idxOutSw = (int_T*)
          mechatronic_system_DW.StateSpace_PWORK.IDX_OUT_SW;
        int_T *switch_status_init = (int_T*)
          mechatronic_system_DW.StateSpace_PWORK.SWITCH_STATUS_INIT;

        /* Initialize work vectors */
        switch_status[0] = 0;
        switch_status_init[0] = 0;
        gState[0] = (int_T) 0.0;
        yswitch[0] = 1/1.0E-6;
        switchTypes[0] = (int_T)1.0;
        idxOutSw[0] = ((int_T)0.0) - 1;
      }
    }
  }
}

/* Model terminate function */
void mechatronic_system_terminate(void)
{
  /* Terminate for S-Function (sfun_spssw_discc): '<S35>/State-Space' incorporates:
   *  Constant: '<S37>/SwitchCurrents'
   *  Inport: '<Root>/Enable'
   */

  /* S-Function block: <S35>/State-Space */
  {
    /* Free memory */
    free(mechatronic_system_DW.StateSpace_PWORK.AS);
    free(mechatronic_system_DW.StateSpace_PWORK.BS);
    free(mechatronic_system_DW.StateSpace_PWORK.CS);
    free(mechatronic_system_DW.StateSpace_PWORK.DS);
    free(mechatronic_system_DW.StateSpace_PWORK.DX_COL);
    free(mechatronic_system_DW.StateSpace_PWORK.TMP2);
    free(mechatronic_system_DW.StateSpace_PWORK.BD_COL);
    free(mechatronic_system_DW.StateSpace_PWORK.TMP1);
    free(mechatronic_system_DW.StateSpace_PWORK.XTMP);

    /*
     * Circuit has switches*/
    free(mechatronic_system_DW.StateSpace_PWORK.G_STATE);
    free(mechatronic_system_DW.StateSpace_PWORK.SWITCH_STATUS);
    free(mechatronic_system_DW.StateSpace_PWORK.SW_CHG);
    free(mechatronic_system_DW.StateSpace_PWORK.SWITCH_STATUS_INIT);
  }

  /* Terminate for SimscapeExecutionBlock: '<S34>/STATE_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    mechatronic_system_DW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    mechatronic_system_DW.STATE_1_SimData);
  nesl_erase_simulator("mechatronic_system/Solver Configuration_1");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S34>/OUTPUT_1_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    mechatronic_system_DW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    mechatronic_system_DW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("mechatronic_system/Solver Configuration_1");
  nesl_destroy_registry();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
