/*
 * helicopter_lab3_2020.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "helicopter_lab3_2020".
 *
 * Model version              : 11.5
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Thu Mar  7 14:31:56 2024
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
  real_T rtb_TmpSignalConversionAtToFile[12];
  real_T lastTime;
  real_T rtb_Backgain;
  real_T rtb_Clock;
  real_T rtb_Derivative;
  real_T *lastU;
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

  /* FromWorkspace: '<Root>/From Workspace1' */
  {
    real_T *pDataValues = (real_T *)
      helicopter_lab3_2020_DW.FromWorkspace1_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helicopter_lab3_2020_DW.FromWorkspace1_PWORK.TimePtr;
    int_T currTimeIndex = helicopter_lab3_2020_DW.FromWorkspace1_IWORK.PrevIndex;
    real_T t = helicopter_lab3_2020_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[140]) {
      currTimeIndex = 139;
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

    helicopter_lab3_2020_DW.FromWorkspace1_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 4; ++elIdx) {
              (&helicopter_lab3_2020_B.FromWorkspace1[0])[elIdx] =
                pDataValues[currTimeIndex];
              pDataValues += 141;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 4; ++elIdx) {
              (&helicopter_lab3_2020_B.FromWorkspace1[0])[elIdx] =
                pDataValues[currTimeIndex + 1];
              pDataValues += 141;
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
          for (elIdx = 0; elIdx < 4; ++elIdx) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            (&helicopter_lab3_2020_B.FromWorkspace1[0])[elIdx] = (real_T)
              rtInterpolate(d1, d2, f1, f2);
            pDataValues += 141;
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
    } else if (t >= pTimeValues[140]) {
      currTimeIndex = 139;
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
          helicopter_lab3_2020_B.FromWorkspace = pDataValues[currTimeIndex];
        } else {
          helicopter_lab3_2020_B.FromWorkspace = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        helicopter_lab3_2020_B.FromWorkspace = (real_T) rtInterpolate(d1, d2, f1,
          f2);
        pDataValues += 141;
      }
    }
  }

  /* Sum: '<Root>/Sum4' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<S3>/Gain1'
   *  Sum: '<Root>/Sum3'
   */
  helicopter_lab3_2020_B.Sum4 = helicopter_lab3_2020_B.FromWorkspace -
    ((((helicopter_lab3_2020_P.Gain1_Gain * helicopter_lab3_2020_B.Gain -
        helicopter_lab3_2020_B.FromWorkspace1[0]) * helicopter_lab3_2020_P.K[0]
       + (helicopter_lab3_2020_P.Gain1_Gain * helicopter_lab3_2020_B.Gain_d -
          helicopter_lab3_2020_B.FromWorkspace1[1]) * helicopter_lab3_2020_P.K[1])
      + (helicopter_lab3_2020_P.Gain1_Gain * helicopter_lab3_2020_B.Gain_i -
         helicopter_lab3_2020_B.FromWorkspace1[2]) * helicopter_lab3_2020_P.K[2])
     + (helicopter_lab3_2020_P.Gain1_Gain * helicopter_lab3_2020_B.Gain_b -
        helicopter_lab3_2020_B.FromWorkspace1[3]) * helicopter_lab3_2020_P.K[3]);
  if (rtmIsMajorTimeStep(helicopter_lab3_2020_M)) {
    /* SignalConversion generated from: '<Root>/To File' */
    rtb_TmpSignalConversionAtToFile[0] = helicopter_lab3_2020_B.Gain;
    rtb_TmpSignalConversionAtToFile[1] = helicopter_lab3_2020_B.Gain_d;
    rtb_TmpSignalConversionAtToFile[2] = helicopter_lab3_2020_B.Gain_i;
    rtb_TmpSignalConversionAtToFile[3] = helicopter_lab3_2020_B.Gain_b;
    rtb_TmpSignalConversionAtToFile[4] = helicopter_lab3_2020_B.Sum;
    rtb_TmpSignalConversionAtToFile[5] = helicopter_lab3_2020_B.Gain_dg;
    rtb_TmpSignalConversionAtToFile[6] = helicopter_lab3_2020_B.FromWorkspace1[0];
    rtb_TmpSignalConversionAtToFile[7] = helicopter_lab3_2020_B.FromWorkspace1[1];
    rtb_TmpSignalConversionAtToFile[8] = helicopter_lab3_2020_B.FromWorkspace1[2];
    rtb_TmpSignalConversionAtToFile[9] = helicopter_lab3_2020_B.FromWorkspace1[3];
    rtb_TmpSignalConversionAtToFile[10] = helicopter_lab3_2020_B.FromWorkspace;
    rtb_TmpSignalConversionAtToFile[11] = helicopter_lab3_2020_B.Sum4;

    /* ToFile: '<Root>/To File' */
    {
      if (!(++helicopter_lab3_2020_DW.ToFile_IWORK.Decimation % 1) &&
          (helicopter_lab3_2020_DW.ToFile_IWORK.Count * (12 + 1)) + 1 <
          100000000 ) {
        FILE *fp = (FILE *) helicopter_lab3_2020_DW.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[12 + 1];
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
          if (fwrite(u, sizeof(real_T), 12 + 1, fp) != 12 + 1) {
            rtmSetErrorStatus(helicopter_lab3_2020_M,
                              "Error writing to MAT-file Measure/LAB3_Q1_R1.mat");
            return;
          }

          if (((++helicopter_lab3_2020_DW.ToFile_IWORK.Count) * (12 + 1))+1 >=
              100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file Measure/LAB3_Q1_R1.mat.\n");
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
  rtb_Clock = ((helicopter_lab3_2020_B.Sum4 -
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
   *  Constant: '<Root>/Constant'
   *  Gain: '<S2>/Gain1'
   */
  rtb_Derivative = helicopter_lab3_2020_P.Constant_Value -
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

  /* Start for FromWorkspace: '<Root>/From Workspace1' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75,
      2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0,
      5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25,
      8.5, 8.75, 9.0, 9.25, 9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25,
      11.5, 11.75, 12.0, 12.25, 12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0,
      14.25, 14.5, 14.75, 15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75,
      17.0, 17.25, 17.5, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5,
      19.75, 20.0, 20.25, 20.5, 20.75, 21.0, 21.25, 21.5, 21.75, 22.0, 22.25,
      22.5, 22.75, 23.0, 23.25, 23.5, 23.75, 24.0, 24.25, 24.5, 24.75, 25.0,
      25.25, 25.5, 25.75, 26.0, 26.25, 26.5, 26.75, 27.0, 27.25, 27.5, 27.75,
      28.0, 28.25, 28.5, 28.75, 29.0, 29.25, 29.5, 29.75, 30.0, 30.25, 30.5,
      30.75, 31.0, 31.25, 31.5, 31.75, 32.0, 32.25, 32.5, 32.75, 33.0, 33.25,
      33.5, 33.75, 34.0, 34.25, 34.5, 34.75, 35.0 } ;

    static real_T pDataValues0[] = { 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1374254177816958, 3.12450698677629,
      3.0990555940874724, 3.0582979442798077, 3.0003273967456696,
      2.9238855686788789, 2.8289226925758952, 2.7154387684331134,
      2.5834337962580287, 2.4329077760471383, 2.2638607078004771,
      2.07756581489165, 1.8775783792464975, 1.6690820875672876,
      1.4579268554277154, 1.2498291292807462, 1.0498418347484206,
      0.86201835515290626, 0.68928890223028039, 0.53365052687352943,
      0.39621309495077617, 0.27729671106047665, 0.17658687102470946,
      0.093255101724984774, 0.02608891411034257, -0.02638585054895522,
      -0.0657977230766492, -0.093839936787796313, -0.11219848239898556,
      -0.12249673959703712, -0.12625494770419687, -0.12486254231436998,
      -0.11956134611918244, -0.11143767560235188, -0.10142156310073112,
      -0.090291467288597632, -0.078683036191732891, -0.067100683097248731,
      -0.055930928619173793, -0.045456645722071309, -0.035871514571766287,
      -0.027294148065693864, -0.019781485331805911, -0.013341168843339286,
      -0.0079427212946709715, -0.0035274217657949524, -1.6848128363464388E-5,
      0.0026798944610880206, 0.0046601991939876127, 0.0060231489358976049,
      0.0068657658146167762, 0.0072802006886342648, 0.00735173971998198,
      0.0071575060604666795, 0.0067657394010769718, 0.0062355437469319925,
      0.0056170033453378839, 0.0049515774317328339, 0.0042726957331622861,
      0.0036064879741303491, 0.0029725915750720847, 0.0023849920317604977,
      0.0018528599157553055, 0.0013813569176959624, 0.00097239080388174812,
      0.00062530555987273351, 0.000337498377993895, 0.0001049595624365564,
      -7.7265048865988444E-5, -0.00021468682563224379, -0.00031305791925766922,
      -0.00037811994189421725, -0.00041541114499650295, -0.00043012504218746815,
      -0.00042701331630973704, -0.0004103260139754706, -0.00038378239526827578,
      -0.00035056631274567492, -0.00031334059278440636, -0.00027427554192289841,
      -0.00023508736777064055, -0.00019708296165491378, -0.00016120811833732733,
      -0.00012809685224593503, -9.8119999619136584E-5, -7.1431765537516829E-5,
      -4.8013280642394241E-5, -2.771257314999159E-5, -1.0280637544243094E-5,
      4.5965075573488244E-6, 1.7269733520551174E-5, 2.8102568756748302E-5,
      3.7450688883886088E-5, 4.5645063431065644E-5, 5.2978833328992888E-5,
      5.9698205112772283E-5, 6.599789137024984E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.016668943247339547,
      -0.051673724001007247, -0.10180557073440349, -0.16303059925574853,
      -0.23188219015975742, -0.30576731228497844, -0.37985150442147519,
      -0.45393569655583604, -0.52801988869587591, -0.60210408084807054,
      -0.67618827299167061, -0.74517957164635207, -0.799949742579111,
      -0.8339851667187419, -0.84462092855959325, -0.8323909045818394,
      -0.79994917812971855, -0.751293918380085, -0.69091781168941258,
      -0.62255350142744126, -0.54974972769111086, -0.47566553556084645,
      -0.40283936014219385, -0.3333270771999261, -0.2686647504590064,
      -0.20989905863756, -0.15764749010976831, -0.11216885484414024,
      -0.073434182446458371, -0.041193028794311214, -0.015032832425807444,
      0.0055696215598421391, 0.021204784780769547, 0.032494682066557576,
      0.040064450007008479, 0.044520383249637745, 0.046433724387605874,
      0.046329412378274613, 0.044679017912523773, 0.041897131587934108,
      0.038340524601399438, 0.034309466024677632, 0.030050650935640695,
      0.025761265954129753, 0.021593790194613521, 0.017661198115628454,
      0.014042294549695224, 0.010786970357866636, 0.007921218931622313,
      0.0054517989676793324, 0.0033704675148538781, 0.0016577394960469085,
      0.00028615612532149507, -0.00077693463809365318, -0.0015670666377278965,
      -0.00212078261652242, -0.0024741616063512113, -0.002661703654441861,
      -0.002715526794250541, -0.0026648310361320191, -0.0025355855962262922,
      -0.002350398173246262, -0.0021285284640334963, -0.0018860119922144559,
      -0.0016358644552555606, -0.0013883409760389958, -0.001151228727516111,
      -0.00093015526222510741, -0.00072889844520990547, -0.0005496871070626659,
      -0.00039348437450141961, -0.00026024809054360785, -0.00014916481241533867,
      -5.8855588763508634E-5, 1.2446903516357074E-5, 6.67492093341423E-5,
      0.00010617447483172476, 0.00013286433008737454, 0.00014890287984582173,
      0.00015626020345066281, 0.00015675269660625894, 0.00015201762446277858,
      0.00014349937326979702, 0.00013244506436753577, 0.00011990741050787,
      0.00010675293632592285, 9.3673939580974E-5, 8.1202829969885136E-5,
      6.9727742423154656E-5, 5.9508580406324029E-5, 5.0692903852874587E-5,
      4.3331340944750306E-5, 3.7392480508522136E-5, 3.2777498188640624E-5,
      2.9335079591637717E-5, 2.6877487135060826E-5, 2.519874502992483E-5,
      2.4095550432346531E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.11780972451609184, 0.24740042148576846, 0.35431274647884514,
      0.4327151181347334, 0.48661674864803717, 0.52219182478651682,
      0.52359877559793488, 0.52359877559780987, 0.52359877559764356,
      0.52359877559748369, 0.52359877559649493, 0.48760414940412222,
      0.38709465027512857, 0.2405493788084917, 0.075169502655390019,
      -0.086437138535023383, -0.22928573227709653, -0.34387679328416543,
      -0.42671526306778662, -0.48317283502066732, -0.5145492673158486,
      -0.52359877550162781, -0.51470759385363951, -0.49128626749302196,
      -0.4570086293586676, -0.41533346583119896, -0.36929413025966529,
      -0.32142562472924685, -0.27376187086652159, -0.22786816036042268,
      -0.18489027671202712, -0.14561027623183243, -0.11050336222311929,
      -0.079792682156490768, -0.053500228721763521, -0.031492834325402175,
      -0.013522764416820432, 0.00073723743490716753, 0.011664357757627641,
      0.019661310072796478, 0.025136739830122878, 0.028489982466917585,
      0.0300996785070613, 0.030315734834755137, 0.029454127010505537,
      0.027794058867111948, 0.025577028260135304, 0.023007388104351656,
      0.0202540365841406, 0.017452917175893257, 0.01471005579933804,
      0.012104907505302354, 0.00969382742579128, 0.00751351949675183,
      0.0055843512022645259, 0.0039134530622901842, 0.002497547736054484,
      0.0013254755688910658, 0.00038040139622308455, -0.00035829825686117811,
      -0.00091345740742865278, -0.0013088339780656932, -0.0015680903676976721,
      -0.0017140138000101279, -0.0017679472540330643, -0.0017494014162582339,
      -0.0016758188138886743, -0.0015624628195514134, -0.0014224063180470203,
      -0.0012665972930552272, -0.0011039812563718998, -0.00094166316901522773,
      -0.00078509418459804525, -0.00063827110155256772, -0.0005039387833631892,
      -0.00038378795827265222, -0.000278642719155342, -0.00018863370352650843,
      -0.00011335434417791834, -5.199875330152981E-5, -3.4807535795877698E-6,
      3.3465681470223885E-5, 6.0203746098386191E-5, 7.8127633432512056E-5,
      8.8611349043365983E-5, 9.2970799506320034E-5, 9.243735382535867E-5,
      8.8141039721545411E-5, 8.11015361753542E-5, 7.2225134199133123E-5,
      6.2305834968801044E-5, 5.2028715082474974E-5, 4.1973597375122296E-5,
      3.2616932468032545E-5, 2.432969990373568E-5, 1.736932487172993E-5,
      1.1864708048814343E-5, 7.796958080064087E-6, 4.9875797032417069E-6, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4712388980374192,
      0.51836278783983025, 0.42764929997354517, 0.31360948663753485,
      0.21560652205263267, 0.14230030455309284, 0.005627803245672503,
      -4.9974619901183885E-13, -6.6559601395617739E-13, -6.3875036807285532E-13,
      -3.9642385169746331E-12, -0.14397850476917326, -0.40203799651147737,
      -0.58618108592407525, -0.66151950455780062, -0.64642656467160442,
      -0.57139437522983372, -0.45836424406476151, -0.33135387911777842,
      -0.22583028785857895, -0.12550572911646393, -0.036198032721437824,
      0.035564726591873992, 0.09368530544270591, 0.13711055253750232,
      0.166700654110349, 0.18415734228524094, 0.19147402212078443,
      0.19065501545278615, 0.18357484202687932, 0.17191153459257291,
      0.15712000192658282, 0.14042765603582621, 0.12284272026767519,
      0.10516981373693834, 0.088029577584949253, 0.071880279634290584,
      0.05704000740668666, 0.0437084812918775, 0.031987809259351442,
      0.021901719030674723, 0.013412970546368988, 0.0064387841605055614,
      0.00086422531072876665, -0.0034464312968845445, -0.0066402725739271133,
      -0.0088681224272842089, -0.010278560623365131, -0.011013406080304123,
      -0.011204477632692842, -0.010971445505654267, -0.010420593176171226,
      -0.0096443203179532744, -0.0087212317163710418, -0.00771667317785728,
      -0.00668359255954533, -0.0056636213050076526, -0.0046882886687060745,
      -0.003780296690725236, -0.0029547986122488604, -0.0022206366023816192,
      -0.0015815062825931629, -0.0010370255585483985, -0.000583693729231555,
      -0.00021573381608672163, 7.4183351115046777E-5, 0.00029433040945780445,
      0.00045342397734548444, 0.00056022600601032086, 0.00062323609998077582,
      0.00065046414669977137, 0.00064927234940726939, 0.0006262759376677473,
      0.00058729233222467616, 0.00053732927274634571, 0.00048060330033198744,
      0.00042058095647148647, 0.00036003606251858308, 0.0003011174373886869,
      0.00024542236351020471, 0.00019407199888335529, 0.00014778574020392495,
      0.00010695225850934884, 7.1695549339957851E-5, 4.1934862444518296E-5,
      1.7437801848648704E-5, -2.1337827219114584E-6, -1.7185256414661577E-5,
      -2.8158014184927928E-5, -3.5505607904792829E-5, -3.9677196921137613E-5,
      -4.1108479545664056E-5, -4.0220470829328336E-5, -3.7426659628428E-5,
      -3.3148930257063223E-5, -2.7841500128499378E-5, -2.2018467291378384E-5,
      -1.6270999875232789E-5, -1.1237513507145635E-5, -7.4392873955664755E-6,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helicopter_lab3_2020_DW.FromWorkspace1_PWORK.TimePtr = (void *) pTimeValues0;
    helicopter_lab3_2020_DW.FromWorkspace1_PWORK.DataPtr = (void *) pDataValues0;
    helicopter_lab3_2020_DW.FromWorkspace1_IWORK.PrevIndex = 0;
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
      19.75, 20.0, 20.25, 20.5, 20.75, 21.0, 21.25, 21.5, 21.75, 22.0, 22.25,
      22.5, 22.75, 23.0, 23.25, 23.5, 23.75, 24.0, 24.25, 24.5, 24.75, 25.0,
      25.25, 25.5, 25.75, 26.0, 26.25, 26.5, 26.75, 27.0, 27.25, 27.5, 27.75,
      28.0, 28.25, 28.5, 28.75, 29.0, 29.25, 29.5, 29.75, 30.0, 30.25, 30.5,
      30.75, 31.0, 31.25, 31.5, 31.75, 32.0, 32.25, 32.5, 32.75, 33.0, 33.25,
      33.5, 33.75, 34.0, 34.25, 34.5, 34.75, 35.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.52359877559812762,
      0.52359877559808921, 0.52359877559803036, 0.52359877559792645,
      0.52359877559769241, 0.523598775596804, 0.42839704355028863,
      0.46934733083556879, 0.47123889803745711, 0.47123889803739294,
      0.47123889803355556, 0.31126278162760757, 0.040527624665403716,
      -0.16779769472547879, -0.32150525470820035, -0.428255130410881,
      -0.49540491289498989, -0.52359876528293736, -0.52359877536849764,
      -0.52359455835622748, -0.49840229272729719, -0.46113050685938822,
      -0.41955597407026091, -0.37109575041464538, -0.32130125447551383,
      -0.2721691975693436, -0.22521079211732931, -0.18151313270126668,
      -0.14180070252163957, -0.10649490616558, -0.075770072234742136,
      -0.049604846026632454, -0.027828298103670657, -0.010160410092637351,
      0.0037531314543202132, 0.014311692960189748, 0.021935707346162459,
      0.02704753737761223, 0.030056712637321792, 0.0313490260580368,
      0.031278964320414326, 0.030164955335669097, 0.028286940409232075,
      0.025885814103135285, 0.02316431751419179, 0.020289017524368624,
      0.017393053009556847, 0.014579377001883054, 0.011924269858608172,
      0.0094809414887054855, 0.00728307987864385, 0.0053482380965714782,
      0.0036809824413284176, 0.0022757504385518823, 0.0011193891207615936,
      0.00019336172285522313, -0.00052437508359071128, -0.0010578106197081105,
      -0.0014316157307320276, -0.001670148591526921, -0.0017967017891268311,
      -0.0018329602337732176, -0.00179863936701119, -0.0017112741062339509,
      -0.0015861307122214674, -0.0014362160503204047, -0.0012723613349117091,
      -0.0011033602341873339, -0.00093614403441599769, -0.0007759793160654338,
      -0.00062667620101641841, -0.00049079763625736739, -0.00036986234993052758,
      -0.00026453603160880856, -0.00017480694445159983, -0.00010014357688581388,
      -3.9633097870583889E-5, 7.8996896336613887E-6, 4.3792476247528356E-5,
      6.9463688796567169E-5, 8.63474930526964E-5, 9.58439446026027E-5,
      9.9282526765498424E-5, 9.78972505329967E-5, 9.2811490943867092E-5,
      8.5030776316386E-5, 7.5441810909460116E-5, 6.4816077174678632E-5,
      5.3816408949858285E-5, 4.3004928542478282E-5, 3.2850675745987878E-5,
      2.3735109830891332E-5, 1.5953448277872262E-5, 9.7096074126445941E-6,
      5.1026106440144048E-6, 2.1034535515607189E-6, 5.2526627059013009E-7, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helicopter_lab3_2020_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    helicopter_lab3_2020_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    helicopter_lab3_2020_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "Measure/LAB3_Q1_R1.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(helicopter_lab3_2020_M,
                        "Error creating .mat file Measure/LAB3_Q1_R1.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 12 + 1, 0, "LAB3")) {
      rtmSetErrorStatus(helicopter_lab3_2020_M,
                        "Error writing mat file header to file Measure/LAB3_Q1_R1.mat");
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
      char fileName[509] = "Measure/LAB3_Q1_R1.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helicopter_lab3_2020_M,
                          "Error closing MAT-file Measure/LAB3_Q1_R1.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(helicopter_lab3_2020_M,
                          "Error reopening MAT-file Measure/LAB3_Q1_R1.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 12 + 1,
           helicopter_lab3_2020_DW.ToFile_IWORK.Count, "LAB3")) {
        rtmSetErrorStatus(helicopter_lab3_2020_M,
                          "Error writing header for LAB3 to MAT-file Measure/LAB3_Q1_R1.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helicopter_lab3_2020_M,
                          "Error closing MAT-file Measure/LAB3_Q1_R1.mat");
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
  helicopter_lab3_2020_M->Sizes.checksums[0] = (4283889419U);
  helicopter_lab3_2020_M->Sizes.checksums[1] = (1287711955U);
  helicopter_lab3_2020_M->Sizes.checksums[2] = (3418461072U);
  helicopter_lab3_2020_M->Sizes.checksums[3] = (544711790U);

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
    helicopter_lab3_2020_B.FromWorkspace1[0] = 0.0;
    helicopter_lab3_2020_B.FromWorkspace1[1] = 0.0;
    helicopter_lab3_2020_B.FromWorkspace1[2] = 0.0;
    helicopter_lab3_2020_B.FromWorkspace1[3] = 0.0;
    helicopter_lab3_2020_B.FromWorkspace = 0.0;
    helicopter_lab3_2020_B.Sum4 = 0.0;
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
  helicopter_lab3_2020_M->Sizes.numBlocks = (64);/* Number of blocks */
  helicopter_lab3_2020_M->Sizes.numBlockIO = (17);/* Number of block outputs */
  helicopter_lab3_2020_M->Sizes.numBlockPrms = (149);/* Sum of parameter "widths" */
  return helicopter_lab3_2020_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
