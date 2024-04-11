/*
 * helicopter_lab3_2020.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "helicopter_lab3_2020".
 *
 * Model version              : 11.10
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Thu Apr 11 12:31:44 2024
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

    /* Sum: '<Root>/Sum7' incorporates:
     *  Constant: '<Root>/Travel Offset [deg]'
     */
    helicopter_lab3_2020_B.Sum7 = helicopter_lab3_2020_P.TravelOffsetdeg_Value +
      helicopter_lab3_2020_B.Gain;

    /* Gain: '<S5>/Pitch: Count to rad' */
    helicopter_lab3_2020_B.PitchCounttorad =
      helicopter_lab3_2020_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Gain: '<S10>/Gain' */
    helicopter_lab3_2020_B.Gain_i = helicopter_lab3_2020_P.Gain_Gain_a *
      helicopter_lab3_2020_B.PitchCounttorad;

    /* Gain: '<S5>/Elevation: Count to rad' incorporates:
     *  Gain: '<S5>/Elevation_gain'
     */
    helicopter_lab3_2020_B.ElevationCounttorad =
      helicopter_lab3_2020_P.elevation_gain * rtb_HILReadEncoderTimebase_o3 *
      helicopter_lab3_2020_P.ElevationCounttorad_Gain;

    /* Gain: '<S8>/Gain' */
    helicopter_lab3_2020_B.Gain_e = helicopter_lab3_2020_P.Gain_Gain_l *
      helicopter_lab3_2020_B.ElevationCounttorad;

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/elavation_offset [deg]'
     */
    helicopter_lab3_2020_B.Sum = helicopter_lab3_2020_B.Gain_e +
      helicopter_lab3_2020_P.elavation_offsetdeg_Value;
  }

  /* Gain: '<S14>/Gain' incorporates:
   *  TransferFcn: '<S5>/Travel: Transfer Fcn'
   */
  helicopter_lab3_2020_B.Gain_d = (helicopter_lab3_2020_P.TravelTransferFcn_C *
    helicopter_lab3_2020_X.TravelTransferFcn_CSTATE +
    helicopter_lab3_2020_P.TravelTransferFcn_D *
    helicopter_lab3_2020_B.TravelCounttorad) *
    helicopter_lab3_2020_P.Gain_Gain_lu;

  /* Gain: '<S11>/Gain' incorporates:
   *  TransferFcn: '<S5>/Pitch: Transfer Fcn'
   */
  helicopter_lab3_2020_B.Gain_b = (helicopter_lab3_2020_P.PitchTransferFcn_C *
    helicopter_lab3_2020_X.PitchTransferFcn_CSTATE +
    helicopter_lab3_2020_P.PitchTransferFcn_D *
    helicopter_lab3_2020_B.PitchCounttorad) *
    helicopter_lab3_2020_P.Gain_Gain_ae;

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
  tmp[0] = helicopter_lab3_2020_P.Gain1_Gain * helicopter_lab3_2020_B.Sum7 -
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
    rtb_TmpSignalConversionAtToFile[0] = helicopter_lab3_2020_B.Sum7;
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
                              "Error writing to MAT-file Measure/LAB4_Q_R_tuned4.mat");
            return;
          }

          if (((++helicopter_lab3_2020_DW.ToFile_IWORK.Count) * (16 + 1))+1 >=
              100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file Measure/LAB4_Q_R_tuned4.mat.\n");
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
      3.1415926535897931, 3.0942938950510874, 2.9610159872633339,
      2.8277380794755813, 2.6907661259066589, 2.5460366761972795,
      2.3910633336566942, 2.2258399143743661, 2.0533084431781576,
      1.8773786206762111, 1.7015195818145687, 1.5289832025466585,
      1.3626118957594318, 1.2042076375997584, 1.0555332606625885,
      0.9173290380599054, 0.78985023043355118, 0.67316378398859722,
      0.56721678488863536, 0.4719162222629506, 0.38714451007083217,
      0.3122398932224329, 0.24657639827341862, 0.18974467624570374,
      0.13983246505685384, 0.094860104482063612, 0.05322842755398112,
      0.013777197826524548, -0.024286096783372426, -0.061482248042144222,
      -0.098144391987738985, -0.13448143875255386, -0.17062241583074858,
      -0.2066460581508465, -0.24259994331723952, -0.27851258937888274,
      -0.31440097396429545, -0.35027514575504315, -0.3861410225682177,
      -0.42200207427644848, -0.45786032759995682, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, -0.53311163115101134, -0.53311163115101146,
      -0.54788781427568967, -0.57891779883751493, -0.61989337016234236,
      -0.660893677129311, -0.69012588478483783, -0.70371929000778333,
      -0.70343615544657223, -0.6901455170716394, -0.66548522714890845,
      -0.633617032638697, -0.59469750774867836, -0.55281689041073956,
      -0.50991523050542076, -0.46674578577980785, -0.42378799639984915,
      -0.381202250502737, -0.3390868487684745, -0.29961846739360093,
      -0.26265397979605803, -0.22732688811085985, -0.19964884475539785,
      -0.17988944229916248, -0.16652670771233077, -0.15780491890982742,
      -0.15225317843958963, -0.14878460503508578, -0.14664857578237839,
      -0.14534818705926247, -0.14456390831277921, -0.14409456928038977,
      -0.14381554066557262, -0.14365058424657226, -0.14355353834165319,
      -0.14349668716299036, -0.14346350725269866, -0.14344420683292375,
      -0.14343301329403438, -0.1434265387782383, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, -7.8797461969250618E-17, 0.10443241895797412,
      0.21930807981174555, 0.28959968860224472, 0.28977451067378446,
      0.20660207925075322, 0.096072996478851425, -0.0020010869429783994,
      -0.093933156030783518, -0.17428951083683614, -0.22523222759510469,
      -0.275068337652868, -0.29599620816483863, -0.30321254707123008,
      -0.30510514790783128, -0.30360924876083439, -0.30097978751612009,
      -0.29765557460845204, -0.27894744566679008, -0.2612508807437593,
      -0.24967839179481213, -0.19561783954930609, -0.13965190998630608,
      -0.094442704521271237, -0.061642272202541253, -0.039237581305110222,
      -0.02451455209435268, -0.015096638958992338, -0.00919065084634993,
      -0.005542982645889644, -0.003317109029457524, -0.0019720676820214823,
      -0.0011658489688130961, -0.00068588339188239294, -0.00040180241800500126,
      -0.00023450293376069166, -0.00013640799569030436, -7.9111657797006232E-5,
      -4.5759404880189759E-5, -2.6404068884660075E-5, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.41772967583189691, 0.45950264341508651,
      0.281166435161996, 0.000699288286160421, -0.33268972569212396,
      -0.44211633108760684, -0.392296333687319, -0.36772827635121613,
      -0.32142541922421353, -0.2037708670330779, -0.1993444402310503,
      -0.083711482047883756, -0.028865355625565133, -0.0075704033464070314,
      0.005983596587987184, 0.010517844978861227, 0.013296851630672166,
      0.074832515766650648, 0.070786259692120768, 0.046289955795789831,
      0.21624220898202356, 0.223863718252, 0.18083682186013841,
      0.13120172927492124, 0.089618763589722289, 0.0588921168430302,
      0.037671652541442058, 0.02362395245056978, 0.014590672801840737,
      0.0089034944657274441, 0.0053801653897430765, 0.0032248748528350721,
      0.0019198623077210303, 0.0011363238955104989, 0.00066919793697627951,
      0.00039237975228151843, 0.00022918535157409294, 0.00013340901166664993,
      7.7421343982312377E-5, 4.4807252351408948E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.039531747707528611, 0.046600575145459962,
      0.058278897718796539, 0.073331173090364632, 0.0907561223578319,
      0.10974760923586807, 0.15854028408489959, 0.20127723243812989,
      0.20819973569660782, 0.20726250505075433, 0.20082516168304526,
      0.19258926419564593, 0.18328976250770571, 0.17310341501818835,
      0.16344644532753153, 0.15307553240755822, 0.14175358991607376,
      0.13035160285426212, 0.11915797075811965, 0.10817911117382113,
      0.099956384417893951, 0.092099040738857857, 0.084644214473051135,
      0.077614047262151542, 0.071018856002835432, 0.064859743069877324,
      0.059130738745114014, 0.053820552016075079, 0.048913994176403436,
      0.044393129671398475, 0.040238200133638463, 0.03642836032920261,
      0.032942258598788028, 0.029758489170832923, 0.026855939309260838,
      0.02421405051978736, 0.021813009875974856, 0.019633884853744146,
      0.017658858503530144, 0.015870700018201383, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.028275309751724941, 0.046713290293346074,
      0.0602091014862753, 0.069699797069870326, 0.075965947512142876,
      0.079656235910183545, 0.065593563617218881, 0.027690013033912754,
      -0.00374892258341478, -0.025749373470834655, -0.032943589949596841,
      -0.037198006751761645, -0.040745389958070713, -0.038627878762625148,
      -0.041483651679894172, -0.045287769965936434, -0.045607948247246996,
      -0.044774528384569481, -0.043915438337195412, -0.0328909070237083,
      -0.0314293747161447, -0.0298193050632269, -0.028120668843598741,
      -0.026380765037264844, -0.02463645173183272, -0.022916017299052318,
      -0.021240746916156138, -0.01962623135868705, -0.018083458020019386,
      -0.016619718151039631, -0.015239359217742434, -0.013944406921659394,
      -0.012735077711819644, -0.011610199446289011, -0.010567555157894013,
      -0.0096041625752492834, -0.0087165000889235546, -0.0079006881839413217,
      -0.0071526339413147955, -0.00646815411245678, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

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
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.515715649175181,
      0.51571564917518076, 0.39482275330425509, 0.18545949310799298,
      -0.121214699694965, -0.21497531465756745, -0.2231321189943809,
      -0.30948088374643634, -0.35342403952210205, -0.30581997715505144,
      -0.39523686087108656, -0.30396931157631546, -0.30036982829580355,
      -0.30177876098440787, -0.29489077309267669, -0.29285886973491482,
      -0.28849188193023517, -0.21023555220305379, -0.2195037127375194,
      -0.23053839649817509, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.452404956027601, 0.44764067538036761,
      0.44938671540570868, 0.450966433001409, 0.45238876844619708,
      0.45366452677505315, 0.20336979618917031, -0.18554227077911778,
      -0.19098568530346383, -0.15880316883577189, -0.010842452492777682,
      0.00098013305001662387, -0.012960894112345106, 0.054188381802551033,
      -0.027100466708619951, -0.063354053968724, -0.033198399957159092,
      -0.027343519557024853, -0.035001069926029194, 0.11988871842513939, 0.0,
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
    char fileName[509] = "Measure/LAB4_Q_R_tuned4.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(helicopter_lab3_2020_M,
                        "Error creating .mat file Measure/LAB4_Q_R_tuned4.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 16 + 1, 0, "LAB4")) {
      rtmSetErrorStatus(helicopter_lab3_2020_M,
                        "Error writing mat file header to file Measure/LAB4_Q_R_tuned4.mat");
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
      char fileName[509] = "Measure/LAB4_Q_R_tuned4.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helicopter_lab3_2020_M,
                          "Error closing MAT-file Measure/LAB4_Q_R_tuned4.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(helicopter_lab3_2020_M,
                          "Error reopening MAT-file Measure/LAB4_Q_R_tuned4.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 16 + 1,
           helicopter_lab3_2020_DW.ToFile_IWORK.Count, "LAB4")) {
        rtmSetErrorStatus(helicopter_lab3_2020_M,
                          "Error writing header for LAB4 to MAT-file Measure/LAB4_Q_R_tuned4.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helicopter_lab3_2020_M,
                          "Error closing MAT-file Measure/LAB4_Q_R_tuned4.mat");
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

  rtmSetTFinal(helicopter_lab3_2020_M, 35.0);
  helicopter_lab3_2020_M->Timing.stepSize0 = 0.002;
  helicopter_lab3_2020_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  helicopter_lab3_2020_M->Sizes.checksums[0] = (145133700U);
  helicopter_lab3_2020_M->Sizes.checksums[1] = (1075462520U);
  helicopter_lab3_2020_M->Sizes.checksums[2] = (3321752130U);
  helicopter_lab3_2020_M->Sizes.checksums[3] = (59741398U);

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
    helicopter_lab3_2020_B.Sum7 = 0.0;
    helicopter_lab3_2020_B.PitchCounttorad = 0.0;
    helicopter_lab3_2020_B.Gain_i = 0.0;
    helicopter_lab3_2020_B.ElevationCounttorad = 0.0;
    helicopter_lab3_2020_B.Gain_e = 0.0;
    helicopter_lab3_2020_B.Sum = 0.0;
    helicopter_lab3_2020_B.Gain_d = 0.0;
    helicopter_lab3_2020_B.Gain_b = 0.0;
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
  helicopter_lab3_2020_M->Sizes.numBlocks = (66);/* Number of blocks */
  helicopter_lab3_2020_M->Sizes.numBlockIO = (18);/* Number of block outputs */
  helicopter_lab3_2020_M->Sizes.numBlockPrms = (157);/* Sum of parameter "widths" */
  return helicopter_lab3_2020_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
