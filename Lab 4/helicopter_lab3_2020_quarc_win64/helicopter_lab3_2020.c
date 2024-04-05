/*
 * helicopter_lab3_2020.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "helicopter_lab3_2020".
 *
 * Model version              : 11.7
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Thu Apr  4 16:14:30 2024
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "helicopter_lab3_2020.h"
#include "helicopter_lab3_2020_private.h"
#include "helicopter_lab3_2020_dt.h"

/* Block signals (default storage) */
B_helicopter_lab3_2020_T helicopter_lab3_2020_B;

/* Continuous states */
X_helicopter_lab3_2020_T helicopter_lab3_2020_X;

/* Block states (default storage) */
DW_helicopter_lab3_2020_T helicopter_lab3_2020_DW;

/* Real-time model */
static RT_MODEL_helicopter_lab3_2020_T helicopter_lab3_2020_M_;
RT_MODEL_helicopter_lab3_2020_T *const helicopter_lab3_2020_M =
  &helicopter_lab3_2020_M_;

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

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
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  helicopter_lab3_2020_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void helicopter_lab3_2020_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T rtb_TmpSignalConversionAtToFile[16];
  real_T tmp[6];
  real_T lastTime;
  real_T rtb_Backgain;
  real_T rtb_Clock;
  real_T rtb_Derivative;
  real_T *lastU;
  int32_T i;
  int32_T i_0;
  int8_T rtAction;
  if (rtmIsMajorTimeStep(helicopter_lab3_2020_M)) {
    /* set solver stop time */
    if (!(helicopter_lab3_2020_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&helicopter_lab3_2020_M->solverInfo,
                            ((helicopter_lab3_2020_M->Timing.clockTickH0 + 1) *
        helicopter_lab3_2020_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&helicopter_lab3_2020_M->solverInfo,
                            ((helicopter_lab3_2020_M->Timing.clockTick0 + 1) *
        helicopter_lab3_2020_M->Timing.stepSize0 +
        helicopter_lab3_2020_M->Timing.clockTickH0 *
        helicopter_lab3_2020_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(helicopter_lab3_2020_M)) {
    helicopter_lab3_2020_M->Timing.t[0] = rtsiGetT
      (&helicopter_lab3_2020_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(helicopter_lab3_2020_DW.IfActionSubsystem_SubsysRanBC);
  if (rtmIsMajorTimeStep(helicopter_lab3_2020_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S5>/HIL Read Encoder Timebase' */

    /* S-Function Block: helicopter_lab3_2020/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (helicopter_lab3_2020_DW.HILReadEncoderTimebase_Task, 1,
         &helicopter_lab3_2020_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          helicopter_lab3_2020_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          helicopter_lab3_2020_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          helicopter_lab3_2020_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Gain: '<S5>/Travel: Count to rad' incorporates:
     *  Gain: '<S5>/Travel_gain'
     */
    helicopter_lab3_2020_B.TravelCounttorad = helicopter_lab3_2020_P.travel_gain
      * rtb_HILReadEncoderTimebase_o1 *
      helicopter_lab3_2020_P.TravelCounttorad_Gain;

    /* Gain: '<S13>/Gain' */
    helicopter_lab3_2020_B.Gain = helicopter_lab3_2020_P.Gain_Gain *
      helicopter_lab3_2020_B.TravelCounttorad;

    /* Gain: '<S5>/Pitch: Count to rad' */
    helicopter_lab3_2020_B.PitchCounttorad =
      helicopter_lab3_2020_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Gain: '<S10>/Gain' */
    helicopter_lab3_2020_B.Gain_i = helicopter_lab3_2020_P.Gain_Gain_a *
      helicopter_lab3_2020_B.PitchCounttorad;
  }

  /* Gain: '<S14>/Gain' incorporates:
   *  TransferFcn: '<S5>/Travel: Transfer Fcn'
   */
  helicopter_lab3_2020_B.Gain_d = (helicopter_lab3_2020_P.TravelTransferFcn_C *
    helicopter_lab3_2020_X.TravelTransferFcn_CSTATE +
    helicopter_lab3_2020_P.TravelTransferFcn_D *
    helicopter_lab3_2020_B.TravelCounttorad) *
    helicopter_lab3_2020_P.Gain_Gain_l;

  /* Gain: '<S11>/Gain' incorporates:
   *  TransferFcn: '<S5>/Pitch: Transfer Fcn'
   */
  helicopter_lab3_2020_B.Gain_b = (helicopter_lab3_2020_P.PitchTransferFcn_C *
    helicopter_lab3_2020_X.PitchTransferFcn_CSTATE +
    helicopter_lab3_2020_P.PitchTransferFcn_D *
    helicopter_lab3_2020_B.PitchCounttorad) *
    helicopter_lab3_2020_P.Gain_Gain_ae;
  if (rtmIsMajorTimeStep(helicopter_lab3_2020_M)) {
    /* Gain: '<S5>/Elevation: Count to rad' incorporates:
     *  Gain: '<S5>/Elevation_gain'
     */
    helicopter_lab3_2020_B.ElevationCounttorad =
      helicopter_lab3_2020_P.elevation_gain * rtb_HILReadEncoderTimebase_o3 *
      helicopter_lab3_2020_P.ElevationCounttorad_Gain;

    /* Gain: '<S8>/Gain' */
    helicopter_lab3_2020_B.Gain_e = helicopter_lab3_2020_P.Gain_Gain_lv *
      helicopter_lab3_2020_B.ElevationCounttorad;

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/elavation_offset [deg]'
     */
    helicopter_lab3_2020_B.Sum = helicopter_lab3_2020_B.Gain_e +
      helicopter_lab3_2020_P.elavation_offsetdeg_Value;
  }

  /* Gain: '<S9>/Gain' incorporates:
   *  TransferFcn: '<S5>/Elevation: Transfer Fcn'
   */
  helicopter_lab3_2020_B.Gain_dg =
    (helicopter_lab3_2020_P.ElevationTransferFcn_C *
     helicopter_lab3_2020_X.ElevationTransferFcn_CSTATE +
     helicopter_lab3_2020_P.ElevationTransferFcn_D *
     helicopter_lab3_2020_B.ElevationCounttorad) *
    helicopter_lab3_2020_P.Gain_Gain_n;

  /* FromWorkspace: '<Root>/From Workspace2' */
  {
    real_T *pDataValues = (real_T *)
      helicopter_lab3_2020_DW.FromWorkspace2_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helicopter_lab3_2020_DW.FromWorkspace2_PWORK.TimePtr;
    int_T currTimeIndex = helicopter_lab3_2020_DW.FromWorkspace2_IWORK.PrevIndex;
    real_T t = helicopter_lab3_2020_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[80]) {
      currTimeIndex = 79;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    helicopter_lab3_2020_DW.FromWorkspace2_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 6; ++elIdx) {
              (&helicopter_lab3_2020_B.FromWorkspace2[0])[elIdx] =
                pDataValues[currTimeIndex];
              pDataValues += 81;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 6; ++elIdx) {
              (&helicopter_lab3_2020_B.FromWorkspace2[0])[elIdx] =
                pDataValues[currTimeIndex + 1];
              pDataValues += 81;
            }
          }
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 6; ++elIdx) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            (&helicopter_lab3_2020_B.FromWorkspace2[0])[elIdx] = (real_T)
              rtInterpolate(d1, d2, f1, f2);
            pDataValues += 81;
          }
        }
      }
    }
  }

  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T *pDataValues = (real_T *)
      helicopter_lab3_2020_DW.FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helicopter_lab3_2020_DW.FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex = helicopter_lab3_2020_DW.FromWorkspace_IWORK.PrevIndex;
    real_T t = helicopter_lab3_2020_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[80]) {
      currTimeIndex = 79;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    helicopter_lab3_2020_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 2; ++elIdx) {
              (&helicopter_lab3_2020_B.FromWorkspace[0])[elIdx] =
                pDataValues[currTimeIndex];
              pDataValues += 81;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 2; ++elIdx) {
              (&helicopter_lab3_2020_B.FromWorkspace[0])[elIdx] =
                pDataValues[currTimeIndex + 1];
              pDataValues += 81;
            }
          }
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 2; ++elIdx) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            (&helicopter_lab3_2020_B.FromWorkspace[0])[elIdx] = (real_T)
              rtInterpolate(d1, d2, f1, f2);
            pDataValues += 81;
          }
        }
      }
    }
  }

  /* Gain: '<S3>/Gain1' incorporates:
   *  Sum: '<Root>/Sum5'
   */
  tmp[0] = helicopter_lab3_2020_P.Gain1_Gain * helicopter_lab3_2020_B.Gain -
    helicopter_lab3_2020_B.FromWorkspace2[0];
  tmp[1] = helicopter_lab3_2020_P.Gain1_Gain * helicopter_lab3_2020_B.Gain_d -
    helicopter_lab3_2020_B.FromWorkspace2[1];
  tmp[2] = helicopter_lab3_2020_P.Gain1_Gain * helicopter_lab3_2020_B.Gain_i -
    helicopter_lab3_2020_B.FromWorkspace2[2];
  tmp[3] = helicopter_lab3_2020_P.Gain1_Gain * helicopter_lab3_2020_B.Gain_b -
    helicopter_lab3_2020_B.FromWorkspace2[3];
  tmp[4] = helicopter_lab3_2020_P.Gain1_Gain * helicopter_lab3_2020_B.Sum -
    helicopter_lab3_2020_B.FromWorkspace2[4];
  tmp[5] = helicopter_lab3_2020_P.Gain1_Gain * helicopter_lab3_2020_B.Gain_dg -
    helicopter_lab3_2020_B.FromWorkspace2[5];
  for (i = 0; i < 2; i++) {
    /* Sum: '<Root>/Sum6' incorporates:
     *  Gain: '<Root>/Gain1'
     */
    rtb_Clock = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Clock += helicopter_lab3_2020_P.K_lqr[(i_0 << 1) + i] * tmp[i_0];
    }

    helicopter_lab3_2020_B.Sum6[i] = helicopter_lab3_2020_B.FromWorkspace[i] -
      rtb_Clock;

    /* End of Sum: '<Root>/Sum6' */
  }

  if (rtmIsMajorTimeStep(helicopter_lab3_2020_M)) {
    /* SignalConversion generated from: '<Root>/To File' */
    rtb_TmpSignalConversionAtToFile[0] = helicopter_lab3_2020_B.Gain;
    rtb_TmpSignalConversionAtToFile[1] = helicopter_lab3_2020_B.Gain_d;
    rtb_TmpSignalConversionAtToFile[2] = helicopter_lab3_2020_B.Gain_i;
    rtb_TmpSignalConversionAtToFile[3] = helicopter_lab3_2020_B.Gain_b;
    rtb_TmpSignalConversionAtToFile[4] = helicopter_lab3_2020_B.Sum;
    rtb_TmpSignalConversionAtToFile[5] = helicopter_lab3_2020_B.Gain_dg;
    for (i = 0; i < 6; i++) {
      rtb_TmpSignalConversionAtToFile[i + 6] =
        helicopter_lab3_2020_B.FromWorkspace2[i];
    }

    rtb_TmpSignalConversionAtToFile[12] = helicopter_lab3_2020_B.FromWorkspace[0];
    rtb_TmpSignalConversionAtToFile[14] = helicopter_lab3_2020_B.Sum6[0];
    rtb_TmpSignalConversionAtToFile[13] = helicopter_lab3_2020_B.FromWorkspace[1];
    rtb_TmpSignalConversionAtToFile[15] = helicopter_lab3_2020_B.Sum6[1];

    /* End of SignalConversion generated from: '<Root>/To File' */

    /* ToFile: '<Root>/To File' */
    {
      if (!(++helicopter_lab3_2020_DW.ToFile_IWORK.Decimation % 1) &&
          (helicopter_lab3_2020_DW.ToFile_IWORK.Count * (16 + 1)) + 1 <
          100000000 ) {
        FILE *fp = (FILE *) helicopter_lab3_2020_DW.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[16 + 1];
          helicopter_lab3_2020_DW.ToFile_IWORK.Decimation = 0;
          u[0] = helicopter_lab3_2020_M->Timing.t[1];
          u[1] = rtb_TmpSignalConversionAtToFile[0];
          u[2] = rtb_TmpSignalConversionAtToFile[1];
          u[3] = rtb_TmpSignalConversionAtToFile[2];
          u[4] = rtb_TmpSignalConversionAtToFile[3];
          u[5] = rtb_TmpSignalConversionAtToFile[4];
          u[6] = rtb_TmpSignalConversionAtToFile[5];
          u[7] = rtb_TmpSignalConversionAtToFile[6];
          u[8] = rtb_TmpSignalConversionAtToFile[7];
          u[9] = rtb_TmpSignalConversionAtToFile[8];
          u[10] = rtb_TmpSignalConversionAtToFile[9];
          u[11] = rtb_TmpSignalConversionAtToFile[10];
          u[12] = rtb_TmpSignalConversionAtToFile[11];
          u[13] = rtb_TmpSignalConversionAtToFile[12];
          u[14] = rtb_TmpSignalConversionAtToFile[13];
          u[15] = rtb_TmpSignalConversionAtToFile[14];
          u[16] = rtb_TmpSignalConversionAtToFile[15];
          if (fwrite(u, sizeof(real_T), 16 + 1, fp) != 16 + 1) {
            rtmSetErrorStatus(helicopter_lab3_2020_M,
                              "Error writing to MAT-file Measure/LAB4_Q1_R01.mat");
            return;
          }

          if (((++helicopter_lab3_2020_DW.ToFile_IWORK.Count) * (16 + 1))+1 >=
              100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file Measure/LAB4_Q1_R01.mat.\n");
          }
        }
      }
    }
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Vd_bias'
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S6>/K_pd'
   *  Gain: '<S6>/K_pp'
   *  Sum: '<S6>/Sum2'
   *  Sum: '<S6>/Sum3'
   */
  rtb_Clock = ((helicopter_lab3_2020_B.Sum6[0] -
                helicopter_lab3_2020_P.Gain1_Gain_f *
                helicopter_lab3_2020_B.Gain_i) * helicopter_lab3_2020_P.K_pp -
               helicopter_lab3_2020_P.Gain1_Gain_f *
               helicopter_lab3_2020_B.Gain_b * helicopter_lab3_2020_P.K_pd) +
    helicopter_lab3_2020_P.Vd_ff;

  /* Integrator: '<S4>/Integrator' */
  /* Limited  Integrator  */
  if (helicopter_lab3_2020_X.Integrator_CSTATE >=
      helicopter_lab3_2020_P.Integrator_UpperSat) {
    helicopter_lab3_2020_X.Integrator_CSTATE =
      helicopter_lab3_2020_P.Integrator_UpperSat;
  } else {
    if (helicopter_lab3_2020_X.Integrator_CSTATE <=
        helicopter_lab3_2020_P.Integrator_LowerSat) {
      helicopter_lab3_2020_X.Integrator_CSTATE =
        helicopter_lab3_2020_P.Integrator_LowerSat;
    }
  }

  /* Sum: '<S4>/Sum' incorporates:
   *  Gain: '<S2>/Gain1'
   */
  rtb_Derivative = helicopter_lab3_2020_B.Sum6[1] -
    helicopter_lab3_2020_P.Gain1_Gain_f * helicopter_lab3_2020_B.Sum;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Vs_bias'
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S4>/K_ed'
   *  Gain: '<S4>/K_ep'
   *  Integrator: '<S4>/Integrator'
   *  Sum: '<S4>/Sum1'
   */
  rtb_Backgain = ((helicopter_lab3_2020_P.K_ep * rtb_Derivative +
                   helicopter_lab3_2020_X.Integrator_CSTATE) -
                  helicopter_lab3_2020_P.Gain1_Gain_f *
                  helicopter_lab3_2020_B.Gain_dg * helicopter_lab3_2020_P.K_ed)
    + helicopter_lab3_2020_P.Vs_ff;

  /* If: '<S4>/If' incorporates:
   *  Clock: '<S4>/Clock'
   *  Gain: '<S4>/K_ei'
   *  Inport: '<S7>/In1'
   */
  if (rtmIsMajorTimeStep(helicopter_lab3_2020_M)) {
    rtAction = (int8_T)!(helicopter_lab3_2020_M->Timing.t[0] >= 2.0);
    helicopter_lab3_2020_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = helicopter_lab3_2020_DW.If_ActiveSubsystem;
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    helicopter_lab3_2020_B.In1 = helicopter_lab3_2020_P.K_ei * rtb_Derivative;
    if (rtmIsMajorTimeStep(helicopter_lab3_2020_M)) {
      srUpdateBC(helicopter_lab3_2020_DW.IfActionSubsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
  }

  /* End of If: '<S4>/If' */
  if (rtmIsMajorTimeStep(helicopter_lab3_2020_M)) {
  }

  /* Derivative: '<S5>/Derivative' */
  rtb_Derivative = helicopter_lab3_2020_M->Timing.t[0];
  if ((helicopter_lab3_2020_DW.TimeStampA >= rtb_Derivative) &&
      (helicopter_lab3_2020_DW.TimeStampB >= rtb_Derivative)) {
    rtb_Derivative = 0.0;
  } else {
    lastTime = helicopter_lab3_2020_DW.TimeStampA;
    lastU = &helicopter_lab3_2020_DW.LastUAtTimeA;
    if (helicopter_lab3_2020_DW.TimeStampA < helicopter_lab3_2020_DW.TimeStampB)
    {
      if (helicopter_lab3_2020_DW.TimeStampB < rtb_Derivative) {
        lastTime = helicopter_lab3_2020_DW.TimeStampB;
        lastU = &helicopter_lab3_2020_DW.LastUAtTimeB;
      }
    } else {
      if (helicopter_lab3_2020_DW.TimeStampA >= rtb_Derivative) {
        lastTime = helicopter_lab3_2020_DW.TimeStampB;
        lastU = &helicopter_lab3_2020_DW.LastUAtTimeB;
      }
    }

    rtb_Derivative = (helicopter_lab3_2020_B.PitchCounttorad - *lastU) /
      (rtb_Derivative - lastTime);
  }

  /* End of Derivative: '<S5>/Derivative' */

  /* Gain: '<S12>/Gain' */
  helicopter_lab3_2020_B.Gain_l = helicopter_lab3_2020_P.Gain_Gain_a1 *
    rtb_Derivative;
  if (rtmIsMajorTimeStep(helicopter_lab3_2020_M)) {
  }

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  rtb_Derivative = (rtb_Backgain - rtb_Clock) *
    helicopter_lab3_2020_P.Backgain_Gain;

  /* Saturate: '<S5>/Back motor: Saturation' */
  if (rtb_Derivative > helicopter_lab3_2020_P.BackmotorSaturation_UpperSat) {
    /* Saturate: '<S5>/Back motor: Saturation' */
    helicopter_lab3_2020_B.BackmotorSaturation =
      helicopter_lab3_2020_P.BackmotorSaturation_UpperSat;
  } else if (rtb_Derivative <
             helicopter_lab3_2020_P.BackmotorSaturation_LowerSat) {
    /* Saturate: '<S5>/Back motor: Saturation' */
    helicopter_lab3_2020_B.BackmotorSaturation =
      helicopter_lab3_2020_P.BackmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S5>/Back motor: Saturation' */
    helicopter_lab3_2020_B.BackmotorSaturation = rtb_Derivative;
  }

  /* End of Saturate: '<S5>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(helicopter_lab3_2020_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  rtb_Derivative = (rtb_Clock + rtb_Backgain) *
    helicopter_lab3_2020_P.Frontgain_Gain;

  /* Saturate: '<S5>/Front motor: Saturation' */
  if (rtb_Derivative > helicopter_lab3_2020_P.FrontmotorSaturation_UpperSat) {
    /* Saturate: '<S5>/Front motor: Saturation' */
    helicopter_lab3_2020_B.FrontmotorSaturation =
      helicopter_lab3_2020_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Derivative <
             helicopter_lab3_2020_P.FrontmotorSaturation_LowerSat) {
    /* Saturate: '<S5>/Front motor: Saturation' */
    helicopter_lab3_2020_B.FrontmotorSaturation =
      helicopter_lab3_2020_P.FrontmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S5>/Front motor: Saturation' */
    helicopter_lab3_2020_B.FrontmotorSaturation = rtb_Derivative;
  }

  /* End of Saturate: '<S5>/Front motor: Saturation' */
  if (rtmIsMajorTimeStep(helicopter_lab3_2020_M)) {
    /* S-Function (hil_write_analog_block): '<S5>/HIL Write Analog' */

    /* S-Function Block: helicopter_lab3_2020/Helicopter_interface/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      helicopter_lab3_2020_DW.HILWriteAnalog_Buffer[0] =
        helicopter_lab3_2020_B.FrontmotorSaturation;
      helicopter_lab3_2020_DW.HILWriteAnalog_Buffer[1] =
        helicopter_lab3_2020_B.BackmotorSaturation;
      result = hil_write_analog(helicopter_lab3_2020_DW.HILInitialize_Card,
        helicopter_lab3_2020_P.HILWriteAnalog_channels, 2,
        &helicopter_lab3_2020_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
      }
    }
  }
}

/* Model update function */
void helicopter_lab3_2020_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<S5>/Derivative' */
  if (helicopter_lab3_2020_DW.TimeStampA == (rtInf)) {
    helicopter_lab3_2020_DW.TimeStampA = helicopter_lab3_2020_M->Timing.t[0];
    lastU = &helicopter_lab3_2020_DW.LastUAtTimeA;
  } else if (helicopter_lab3_2020_DW.TimeStampB == (rtInf)) {
    helicopter_lab3_2020_DW.TimeStampB = helicopter_lab3_2020_M->Timing.t[0];
    lastU = &helicopter_lab3_2020_DW.LastUAtTimeB;
  } else if (helicopter_lab3_2020_DW.TimeStampA <
             helicopter_lab3_2020_DW.TimeStampB) {
    helicopter_lab3_2020_DW.TimeStampA = helicopter_lab3_2020_M->Timing.t[0];
    lastU = &helicopter_lab3_2020_DW.LastUAtTimeA;
  } else {
    helicopter_lab3_2020_DW.TimeStampB = helicopter_lab3_2020_M->Timing.t[0];
    lastU = &helicopter_lab3_2020_DW.LastUAtTimeB;
  }

  *lastU = helicopter_lab3_2020_B.PitchCounttorad;

  /* End of Update for Derivative: '<S5>/Derivative' */
  if (rtmIsMajorTimeStep(helicopter_lab3_2020_M)) {
    rt_ertODEUpdateContinuousStates(&helicopter_lab3_2020_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++helicopter_lab3_2020_M->Timing.clockTick0)) {
    ++helicopter_lab3_2020_M->Timing.clockTickH0;
  }

  helicopter_lab3_2020_M->Timing.t[0] = rtsiGetSolverStopTime
    (&helicopter_lab3_2020_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++helicopter_lab3_2020_M->Timing.clockTick1)) {
      ++helicopter_lab3_2020_M->Timing.clockTickH1;
    }

    helicopter_lab3_2020_M->Timing.t[1] =
      helicopter_lab3_2020_M->Timing.clockTick1 *
      helicopter_lab3_2020_M->Timing.stepSize1 +
      helicopter_lab3_2020_M->Timing.clockTickH1 *
      helicopter_lab3_2020_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void helicopter_lab3_2020_derivatives(void)
{
  XDot_helicopter_lab3_2020_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_helicopter_lab3_2020_T *) helicopter_lab3_2020_M->derivs);

  /* Derivatives for TransferFcn: '<S5>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE +=
    helicopter_lab3_2020_P.TravelTransferFcn_A *
    helicopter_lab3_2020_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += helicopter_lab3_2020_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S5>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += helicopter_lab3_2020_P.PitchTransferFcn_A *
    helicopter_lab3_2020_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += helicopter_lab3_2020_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S5>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    helicopter_lab3_2020_P.ElevationTransferFcn_A *
    helicopter_lab3_2020_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    helicopter_lab3_2020_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  lsat = (helicopter_lab3_2020_X.Integrator_CSTATE <=
          helicopter_lab3_2020_P.Integrator_LowerSat);
  usat = (helicopter_lab3_2020_X.Integrator_CSTATE >=
          helicopter_lab3_2020_P.Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (helicopter_lab3_2020_B.In1 > 0.0)) ||
      (usat && (helicopter_lab3_2020_B.In1 < 0.0))) {
    _rtXdot->Integrator_CSTATE = helicopter_lab3_2020_B.In1;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S4>/Integrator' */
}

/* Model initialize function */
void helicopter_lab3_2020_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helicopter_lab3_2020/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &helicopter_lab3_2020_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (helicopter_lab3_2020_DW.HILInitialize_Card,
       "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(helicopter_lab3_2020_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
      return;
    }

    if ((helicopter_lab3_2020_P.HILInitialize_AIPStart && !is_switching) ||
        (helicopter_lab3_2020_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &helicopter_lab3_2020_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (helicopter_lab3_2020_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &helicopter_lab3_2020_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = helicopter_lab3_2020_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (helicopter_lab3_2020_DW.HILInitialize_Card,
         helicopter_lab3_2020_P.HILInitialize_AIChannels, 8U,
         &helicopter_lab3_2020_DW.HILInitialize_AIMinimums[0],
         &helicopter_lab3_2020_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_lab3_2020_P.HILInitialize_AOPStart && !is_switching) ||
        (helicopter_lab3_2020_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums =
          &helicopter_lab3_2020_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (helicopter_lab3_2020_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums =
          &helicopter_lab3_2020_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = helicopter_lab3_2020_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (helicopter_lab3_2020_DW.HILInitialize_Card,
         helicopter_lab3_2020_P.HILInitialize_AOChannels, 8U,
         &helicopter_lab3_2020_DW.HILInitialize_AOMinimums[0],
         &helicopter_lab3_2020_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_lab3_2020_P.HILInitialize_AOStart && !is_switching) ||
        (helicopter_lab3_2020_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &helicopter_lab3_2020_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helicopter_lab3_2020_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(helicopter_lab3_2020_DW.HILInitialize_Card,
        helicopter_lab3_2020_P.HILInitialize_AOChannels, 8U,
        &helicopter_lab3_2020_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
        return;
      }
    }

    if (helicopter_lab3_2020_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &helicopter_lab3_2020_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helicopter_lab3_2020_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (helicopter_lab3_2020_DW.HILInitialize_Card,
         helicopter_lab3_2020_P.HILInitialize_AOChannels, 8U,
         &helicopter_lab3_2020_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_lab3_2020_P.HILInitialize_EIPStart && !is_switching) ||
        (helicopter_lab3_2020_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &helicopter_lab3_2020_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            helicopter_lab3_2020_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (helicopter_lab3_2020_DW.HILInitialize_Card,
         helicopter_lab3_2020_P.HILInitialize_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &helicopter_lab3_2020_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_lab3_2020_P.HILInitialize_EIStart && !is_switching) ||
        (helicopter_lab3_2020_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &helicopter_lab3_2020_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            helicopter_lab3_2020_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(helicopter_lab3_2020_DW.HILInitialize_Card,
        helicopter_lab3_2020_P.HILInitialize_EIChannels, 8U,
        &helicopter_lab3_2020_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_lab3_2020_P.HILInitialize_POPStart && !is_switching) ||
        (helicopter_lab3_2020_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &helicopter_lab3_2020_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = helicopter_lab3_2020_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(helicopter_lab3_2020_DW.HILInitialize_Card,
        helicopter_lab3_2020_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &helicopter_lab3_2020_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          helicopter_lab3_2020_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues =
          &helicopter_lab3_2020_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            helicopter_lab3_2020_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            helicopter_lab3_2020_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = helicopter_lab3_2020_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            helicopter_lab3_2020_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            helicopter_lab3_2020_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              helicopter_lab3_2020_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (helicopter_lab3_2020_DW.HILInitialize_Card,
           &helicopter_lab3_2020_DW.HILInitialize_POSortedChans[0],
           num_duty_cycle_modes,
           &helicopter_lab3_2020_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (helicopter_lab3_2020_DW.HILInitialize_Card,
           &helicopter_lab3_2020_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &helicopter_lab3_2020_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &helicopter_lab3_2020_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            helicopter_lab3_2020_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &helicopter_lab3_2020_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] =
            helicopter_lab3_2020_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &helicopter_lab3_2020_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] =
            helicopter_lab3_2020_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration
        (helicopter_lab3_2020_DW.HILInitialize_Card,
         helicopter_lab3_2020_P.HILInitialize_POChannels, 8U,
         (t_pwm_configuration *)
         &helicopter_lab3_2020_DW.HILInitialize_POModeValues[0],
         (t_pwm_alignment *)
         &helicopter_lab3_2020_DW.HILInitialize_POAlignValues[0],
         (t_pwm_polarity *)
         &helicopter_lab3_2020_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &helicopter_lab3_2020_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = helicopter_lab3_2020_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &helicopter_lab3_2020_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helicopter_lab3_2020_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(helicopter_lab3_2020_DW.HILInitialize_Card,
        helicopter_lab3_2020_P.HILInitialize_POChannels, 8U,
        &helicopter_lab3_2020_DW.HILInitialize_POSortedFreqs[0],
        &helicopter_lab3_2020_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_lab3_2020_P.HILInitialize_POStart && !is_switching) ||
        (helicopter_lab3_2020_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &helicopter_lab3_2020_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helicopter_lab3_2020_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(helicopter_lab3_2020_DW.HILInitialize_Card,
        helicopter_lab3_2020_P.HILInitialize_POChannels, 8U,
        &helicopter_lab3_2020_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
        return;
      }
    }

    if (helicopter_lab3_2020_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &helicopter_lab3_2020_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helicopter_lab3_2020_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (helicopter_lab3_2020_DW.HILInitialize_Card,
         helicopter_lab3_2020_P.HILInitialize_POChannels, 8U,
         &helicopter_lab3_2020_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S5>/HIL Read Encoder Timebase' */

  /* S-Function Block: helicopter_lab3_2020/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (helicopter_lab3_2020_DW.HILInitialize_Card,
       helicopter_lab3_2020_P.HILReadEncoderTimebase_SamplesI,
       helicopter_lab3_2020_P.HILReadEncoderTimebase_Channels, 3,
       &helicopter_lab3_2020_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (helicopter_lab3_2020_DW.HILReadEncoderTimebase_Task,
         (t_buffer_overflow_mode)
         (helicopter_lab3_2020_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
    }
  }

  /* Start for FromWorkspace: '<Root>/From Workspace2' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75,
      2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0,
      5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25,
      8.5, 8.75, 9.0, 9.25, 9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25,
      11.5, 11.75, 12.0, 12.25, 12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0,
      14.25, 14.5, 14.75, 15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75,
      17.0, 17.25, 17.5, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5,
      19.75, 20.0 } ;

    static real_T pDataValues0[] = { 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.0942938950510874, 2.9607308034093491,
      2.8271677117676108, 2.6899105743447023, 2.5453608633296465,
      2.3918534238745419, 2.2299928701689358, 2.062967013135526,
      1.8939893491573685, 1.7262058153931732, 1.5622486822091937,
      1.4044220222899941, 1.25390371881641, 1.1114350205802908,
      0.97774230519938532, 0.85313087351072547, 0.73768828189870139,
      0.63200034236723757, 0.53588409383095381, 0.44886057968236659,
      0.37059836021499581, 0.30056864501942887, 0.23800448773204486,
      0.18116211160144058, 0.12835536347607018, 0.078256967356529386,
      0.029916980971818594, -0.017308031186341902, -0.063838490640083359,
      -0.10994222182249684, -0.15578665409953474, -0.20147494288273662,
      -0.24706991174159523, -0.29260946209056116, -0.33811628135575988,
      -0.38360386052805573, -0.42908017675099974, -0.47454992385775846,
      -0.52001585197889344, -0.56547956637348706, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, -0.53425236656695385, -0.53425236656695407,
      -0.54902854969163184, -0.57819884406022348, -0.61402975782041891,
      -0.6474422148224247, -0.6681034281336351, -0.67591065591263011,
      -0.671134135056786, -0.65582853273591712, -0.63130663967679879,
      -0.60207321389433577, -0.56987479294447541, -0.53477086152362141,
      -0.49844572675463572, -0.46177036644809638, -0.42275175812585597,
      -0.38446499414513524, -0.34809405659435105, -0.31304887786948404,
      -0.28011886078226694, -0.25025662914953606, -0.22736950452241558,
      -0.21122699250148416, -0.20039358447816291, -0.19335994553884175,
      -0.18890004863264306, -0.18612183781496883, -0.18441492472965282,
      -0.183377729108151, -0.18275315513280765, -0.18237987543543421,
      -0.18215820139586505, -0.18202727706079361, -0.18195031668918557,
      -0.181905264891775, -0.18187898842703576, -0.18186371248453825,
      -0.18185485757837594, -0.18184973815420194, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, -7.4797181771072831E-17, 0.10443241895797423,
      0.2061644997848108, 0.25323921379954839, 0.23614648509742203,
      0.14602556468677383, 0.0551785041804601, -0.033758625144940872,
      -0.10817415163916257, -0.17331137466179566, -0.20661068850670677,
      -0.22756614194940372, -0.24810118027650713, -0.256732179135201,
      -0.25920743947537517, -0.275768621509547, -0.27059622521202659,
      -0.25705589570380993, -0.24768593866028868, -0.23273678403469916,
      -0.2110548481008496, -0.16175745574043832, -0.11408910976397481,
      -0.076566390378889709, -0.049711073713176651, -0.03152084799487944,
      -0.019635332996130968, -0.01206380977729349, -0.0073305025236927741,
      -0.0044142503184304051, -0.0026381983368563939, -0.0015667074492168361,
      -0.00092532319723988136, -0.00054392651357564894, -0.00031840889776824945,
      -0.00018571201718774397, -0.00010796452733195585, -6.2583094865728087E-5,
      -3.6182134834140645E-5, -2.0868962120907057E-5, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.41772967583189718, 0.40692832330734746,
      0.18829885605895244, -0.068370914808506156, -0.36048368164259109,
      -0.36338824202525533, -0.35574851730160567, -0.29766210597688464,
      -0.26054889209052962, -0.13319725537964908, -0.083821813770782974,
      -0.08214015330841043, -0.034523995434779554, -0.0099010413606978043,
      -0.066244728136685221, 0.020689585190082002, 0.054161318032866092,
      0.03747982817408619, 0.059796618502358921, 0.086727743735398266,
      0.1971895694416464, 0.19067338390585303, 0.15009087754034078,
      0.10742126666285398, 0.072760902873186262, 0.047542059994991753,
      0.030286092875351535, 0.018933229014401736, 0.011665008821047672,
      0.0071042079262964054, 0.0042859635505577282, 0.0025655370079096236,
      0.001525586734656661, 0.000902070463230576, 0.00053078752231895524,
      0.00031098995942404728, 0.00018152572986461187, 0.00010560384012567691,
      6.1252690853742976E-5, 3.5432798301151213E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.039266508310211931, 0.046336443019539673,
      0.058021327289678473, 0.073084054884987454, 0.0905221062213146,
      0.10952837024212424, 0.16353997597317504, 0.18271010743237445,
      0.19174237921411139, 0.1942130481973221, 0.19278602620180349,
      0.18848735940168423, 0.18218721379948505, 0.17503185311779043,
      0.16688148712012096, 0.15777054582582561, 0.14783765705335908,
      0.13727478773733931, 0.12629141725153475, 0.11509028939694195,
      0.10385203774917835, 0.093625063241528569, 0.08433214427096028,
      0.075899563429885283, 0.068257438044845284, 0.061339913327473496,
      0.055085247319993889, 0.049435811668642471, 0.044338027940753796,
      0.039742255587514833, 0.035602644636011267, 0.031876963678828647,
      0.028526411638504036, 0.02551542005077885, 0.022811451178133765,
      0.02038479608535633, 0.018208375841114781, 0.016257548219100023,
      0.014509921630071133, 0.012945177497376274, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.028279738837311687, 0.046739537080555164,
      0.060250910381237373, 0.069752205345309168, 0.076025056083241851,
      0.079718967324421464, 0.076680525836795937, 0.036129087126947915,
      0.0098826759328407981, -0.0057080879820741639, -0.017194667200476809,
      -0.025200582408797162, -0.02862144272677828, -0.032601463990677058,
      -0.036443765177182161, -0.03973155508986493, -0.042251477264078872,
      -0.0439334819432176, -0.044804511418371648, -0.0449530065910551,
      -0.040907898030600215, -0.037171675882273575, -0.033730323364300527,
      -0.030568501540160189, -0.027670098869488208, -0.025018664029918942,
      -0.022597742605406233, -0.020391134911554379, -0.018383089412955748,
      -0.016558443806013873, -0.014902723828729867, -0.013402208161297956,
      -0.012043966350900355, -0.010815875490581406, -0.0097066203711098486,
      -0.0087056809769658263, -0.0078033104880592188, -0.0069905063561140485,
      -0.0062589765307794337, -0.0056011024999641215, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
    } ;

    helicopter_lab3_2020_DW.FromWorkspace2_PWORK.TimePtr = (void *) pTimeValues0;
    helicopter_lab3_2020_DW.FromWorkspace2_PWORK.DataPtr = (void *) pDataValues0;
    helicopter_lab3_2020_DW.FromWorkspace2_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75,
      2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0,
      5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25,
      8.5, 8.75, 9.0, 9.25, 9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25,
      11.5, 11.75, 12.0, 12.25, 12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0,
      14.25, 14.5, 14.75, 15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75,
      17.0, 17.25, 17.5, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5,
      19.75, 20.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.51571564917518109,
      0.45080908114093521, 0.2866620778816994, 0.09850919063122919,
      -0.18336151479519214, -0.16797681596553554, -0.24830738975653427,
      -0.26838600723524808, -0.31867551587684306, -0.2404486777757005,
      -0.26035098976404036, -0.29766991311328961, -0.26004759886784551,
      -0.25606246647060571, -0.33729344333349309, -0.22548638021148518,
      -0.21145706655416716, -0.23101141487770643, -0.18786004917918039,
      -0.14799694867860641, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.45247582139698594, 0.447742235551354,
      0.44947656415267634, 0.45104568823977154, 0.45245848807314482,
      0.45372491041315416, 0.37978917573780036, -0.17856094003720568,
      -0.092716123165538136, -0.018179139693168478, -0.012404571225422295,
      -0.0040872859332274081, 0.032951264678798262, 0.0040211026700024549,
      -0.016850821828993952, -0.031498212191534508, -0.041474429321057264,
      -0.048080326869182066, -0.05239561163799214, -0.055302551184886542, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helicopter_lab3_2020_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    helicopter_lab3_2020_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    helicopter_lab3_2020_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "Measure/LAB4_Q1_R01.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(helicopter_lab3_2020_M,
                        "Error creating .mat file Measure/LAB4_Q1_R01.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 16 + 1, 0, "LAB4")) {
      rtmSetErrorStatus(helicopter_lab3_2020_M,
                        "Error writing mat file header to file Measure/LAB4_Q1_R01.mat");
      return;
    }

    helicopter_lab3_2020_DW.ToFile_IWORK.Count = 0;
    helicopter_lab3_2020_DW.ToFile_IWORK.Decimation = -1;
    helicopter_lab3_2020_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for If: '<S4>/If' */
  helicopter_lab3_2020_DW.If_ActiveSubsystem = -1;

  /* InitializeConditions for TransferFcn: '<S5>/Travel: Transfer Fcn' */
  helicopter_lab3_2020_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/Pitch: Transfer Fcn' */
  helicopter_lab3_2020_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/Elevation: Transfer Fcn' */
  helicopter_lab3_2020_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  helicopter_lab3_2020_X.Integrator_CSTATE =
    helicopter_lab3_2020_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<S5>/Derivative' */
  helicopter_lab3_2020_DW.TimeStampA = (rtInf);
  helicopter_lab3_2020_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void helicopter_lab3_2020_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helicopter_lab3_2020/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(helicopter_lab3_2020_DW.HILInitialize_Card);
    hil_monitor_stop_all(helicopter_lab3_2020_DW.HILInitialize_Card);
    is_switching = false;
    if ((helicopter_lab3_2020_P.HILInitialize_AOTerminate && !is_switching) ||
        (helicopter_lab3_2020_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &helicopter_lab3_2020_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helicopter_lab3_2020_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((helicopter_lab3_2020_P.HILInitialize_POTerminate && !is_switching) ||
        (helicopter_lab3_2020_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &helicopter_lab3_2020_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helicopter_lab3_2020_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(helicopter_lab3_2020_DW.HILInitialize_Card
                         , helicopter_lab3_2020_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , helicopter_lab3_2020_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &helicopter_lab3_2020_DW.HILInitialize_AOVoltages[0]
                         , &helicopter_lab3_2020_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (helicopter_lab3_2020_DW.HILInitialize_Card,
             helicopter_lab3_2020_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &helicopter_lab3_2020_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (helicopter_lab3_2020_DW.HILInitialize_Card,
             helicopter_lab3_2020_P.HILInitialize_POChannels,
             num_final_pwm_outputs,
             &helicopter_lab3_2020_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helicopter_lab3_2020_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(helicopter_lab3_2020_DW.HILInitialize_Card);
    hil_monitor_delete_all(helicopter_lab3_2020_DW.HILInitialize_Card);
    hil_close(helicopter_lab3_2020_DW.HILInitialize_Card);
    helicopter_lab3_2020_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) helicopter_lab3_2020_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "Measure/LAB4_Q1_R01.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helicopter_lab3_2020_M,
                          "Error closing MAT-file Measure/LAB4_Q1_R01.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(helicopter_lab3_2020_M,
                          "Error reopening MAT-file Measure/LAB4_Q1_R01.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 16 + 1,
           helicopter_lab3_2020_DW.ToFile_IWORK.Count, "LAB4")) {
        rtmSetErrorStatus(helicopter_lab3_2020_M,
                          "Error writing header for LAB4 to MAT-file Measure/LAB4_Q1_R01.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helicopter_lab3_2020_M,
                          "Error closing MAT-file Measure/LAB4_Q1_R01.mat");
        return;
      }

      helicopter_lab3_2020_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  helicopter_lab3_2020_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  helicopter_lab3_2020_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  helicopter_lab3_2020_initialize();
}

void MdlTerminate(void)
{
  helicopter_lab3_2020_terminate();
}

/* Registration function */
RT_MODEL_helicopter_lab3_2020_T *helicopter_lab3_2020(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  helicopter_lab3_2020_P.Integrator_UpperSat = rtInf;
  helicopter_lab3_2020_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)helicopter_lab3_2020_M, 0,
                sizeof(RT_MODEL_helicopter_lab3_2020_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&helicopter_lab3_2020_M->solverInfo,
                          &helicopter_lab3_2020_M->Timing.simTimeStep);
    rtsiSetTPtr(&helicopter_lab3_2020_M->solverInfo, &rtmGetTPtr
                (helicopter_lab3_2020_M));
    rtsiSetStepSizePtr(&helicopter_lab3_2020_M->solverInfo,
                       &helicopter_lab3_2020_M->Timing.stepSize0);
    rtsiSetdXPtr(&helicopter_lab3_2020_M->solverInfo,
                 &helicopter_lab3_2020_M->derivs);
    rtsiSetContStatesPtr(&helicopter_lab3_2020_M->solverInfo, (real_T **)
                         &helicopter_lab3_2020_M->contStates);
    rtsiSetNumContStatesPtr(&helicopter_lab3_2020_M->solverInfo,
      &helicopter_lab3_2020_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&helicopter_lab3_2020_M->solverInfo,
      &helicopter_lab3_2020_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&helicopter_lab3_2020_M->solverInfo,
      &helicopter_lab3_2020_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&helicopter_lab3_2020_M->solverInfo,
      &helicopter_lab3_2020_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&helicopter_lab3_2020_M->solverInfo,
                          (&rtmGetErrorStatus(helicopter_lab3_2020_M)));
    rtsiSetRTModelPtr(&helicopter_lab3_2020_M->solverInfo,
                      helicopter_lab3_2020_M);
  }

  rtsiSetSimTimeStep(&helicopter_lab3_2020_M->solverInfo, MAJOR_TIME_STEP);
  helicopter_lab3_2020_M->intgData.f[0] = helicopter_lab3_2020_M->odeF[0];
  helicopter_lab3_2020_M->contStates = ((real_T *) &helicopter_lab3_2020_X);
  rtsiSetSolverData(&helicopter_lab3_2020_M->solverInfo, (void *)
                    &helicopter_lab3_2020_M->intgData);
  rtsiSetSolverName(&helicopter_lab3_2020_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = helicopter_lab3_2020_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    helicopter_lab3_2020_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    helicopter_lab3_2020_M->Timing.sampleTimes =
      (&helicopter_lab3_2020_M->Timing.sampleTimesArray[0]);
    helicopter_lab3_2020_M->Timing.offsetTimes =
      (&helicopter_lab3_2020_M->Timing.offsetTimesArray[0]);

    /* task periods */
    helicopter_lab3_2020_M->Timing.sampleTimes[0] = (0.0);
    helicopter_lab3_2020_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    helicopter_lab3_2020_M->Timing.offsetTimes[0] = (0.0);
    helicopter_lab3_2020_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(helicopter_lab3_2020_M, &helicopter_lab3_2020_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = helicopter_lab3_2020_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    helicopter_lab3_2020_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(helicopter_lab3_2020_M, -1);
  helicopter_lab3_2020_M->Timing.stepSize0 = 0.002;
  helicopter_lab3_2020_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  helicopter_lab3_2020_M->Sizes.checksums[0] = (4035369870U);
  helicopter_lab3_2020_M->Sizes.checksums[1] = (15271536U);
  helicopter_lab3_2020_M->Sizes.checksums[2] = (2240009348U);
  helicopter_lab3_2020_M->Sizes.checksums[3] = (1039356196U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    helicopter_lab3_2020_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &helicopter_lab3_2020_DW.IfActionSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(helicopter_lab3_2020_M->extModeInfo,
      &helicopter_lab3_2020_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(helicopter_lab3_2020_M->extModeInfo,
                        helicopter_lab3_2020_M->Sizes.checksums);
    rteiSetTPtr(helicopter_lab3_2020_M->extModeInfo, rtmGetTPtr
                (helicopter_lab3_2020_M));
  }

  helicopter_lab3_2020_M->solverInfoPtr = (&helicopter_lab3_2020_M->solverInfo);
  helicopter_lab3_2020_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&helicopter_lab3_2020_M->solverInfo, 0.002);
  rtsiSetSolverMode(&helicopter_lab3_2020_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  helicopter_lab3_2020_M->blockIO = ((void *) &helicopter_lab3_2020_B);

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      helicopter_lab3_2020_B.FromWorkspace2[i] = 0.0;
    }

    helicopter_lab3_2020_B.TravelCounttorad = 0.0;
    helicopter_lab3_2020_B.Gain = 0.0;
    helicopter_lab3_2020_B.Gain_d = 0.0;
    helicopter_lab3_2020_B.PitchCounttorad = 0.0;
    helicopter_lab3_2020_B.Gain_i = 0.0;
    helicopter_lab3_2020_B.Gain_b = 0.0;
    helicopter_lab3_2020_B.ElevationCounttorad = 0.0;
    helicopter_lab3_2020_B.Gain_e = 0.0;
    helicopter_lab3_2020_B.Sum = 0.0;
    helicopter_lab3_2020_B.Gain_dg = 0.0;
    helicopter_lab3_2020_B.FromWorkspace[0] = 0.0;
    helicopter_lab3_2020_B.FromWorkspace[1] = 0.0;
    helicopter_lab3_2020_B.Sum6[0] = 0.0;
    helicopter_lab3_2020_B.Sum6[1] = 0.0;
    helicopter_lab3_2020_B.Gain_l = 0.0;
    helicopter_lab3_2020_B.BackmotorSaturation = 0.0;
    helicopter_lab3_2020_B.FrontmotorSaturation = 0.0;
    helicopter_lab3_2020_B.In1 = 0.0;
  }

  /* parameters */
  helicopter_lab3_2020_M->defaultParam = ((real_T *)&helicopter_lab3_2020_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &helicopter_lab3_2020_X;
    helicopter_lab3_2020_M->contStates = (x);
    (void) memset((void *)&helicopter_lab3_2020_X, 0,
                  sizeof(X_helicopter_lab3_2020_T));
  }

  /* states (dwork) */
  helicopter_lab3_2020_M->dwork = ((void *) &helicopter_lab3_2020_DW);
  (void) memset((void *)&helicopter_lab3_2020_DW, 0,
                sizeof(DW_helicopter_lab3_2020_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_lab3_2020_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_lab3_2020_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_lab3_2020_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_lab3_2020_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_lab3_2020_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_lab3_2020_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_lab3_2020_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_lab3_2020_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  helicopter_lab3_2020_DW.TimeStampA = 0.0;
  helicopter_lab3_2020_DW.LastUAtTimeA = 0.0;
  helicopter_lab3_2020_DW.TimeStampB = 0.0;
  helicopter_lab3_2020_DW.LastUAtTimeB = 0.0;
  helicopter_lab3_2020_DW.HILWriteAnalog_Buffer[0] = 0.0;
  helicopter_lab3_2020_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    helicopter_lab3_2020_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  helicopter_lab3_2020_M->Sizes.numContStates = (4);/* Number of continuous states */
  helicopter_lab3_2020_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  helicopter_lab3_2020_M->Sizes.numY = (0);/* Number of model outputs */
  helicopter_lab3_2020_M->Sizes.numU = (0);/* Number of model inputs */
  helicopter_lab3_2020_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  helicopter_lab3_2020_M->Sizes.numSampTimes = (2);/* Number of sample times */
  helicopter_lab3_2020_M->Sizes.numBlocks = (63);/* Number of blocks */
  helicopter_lab3_2020_M->Sizes.numBlockIO = (17);/* Number of block outputs */
  helicopter_lab3_2020_M->Sizes.numBlockPrms = (156);/* Sum of parameter "widths" */
  return helicopter_lab3_2020_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
