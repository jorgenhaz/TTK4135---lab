/*
 * helicopter_lab3_2020_data.c
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

/* Block parameters (default storage) */
P_helicopter_lab3_2020_T helicopter_lab3_2020_P = {
  /* Variable: K_ed
   * Referenced by: '<S4>/K_ed'
   */
  13.923207611281008,

  /* Variable: K_ei
   * Referenced by: '<S4>/K_ei'
   */
  0.34808019028202519,

  /* Variable: K_ep
   * Referenced by: '<S4>/K_ep'
   */
  3.4808019028202519,

  /* Variable: K_lqr
   * Referenced by: '<Root>/Gain1'
   */
  { -1.1232525263041251, 6.8180098182912174E-15, -3.7428279218980252,
    2.0411717990348885E-14, 2.211460573543671, -5.9837228385114672E-15,
    0.64679847342007657, -9.8312634337365234E-16, 5.6107253473197258E-16,
    11.97709764447729, 8.4284093472086052E-16, 8.3905799755374417 },

  /* Variable: K_pd
   * Referenced by: '<S6>/K_pd'
   */
  6.5546177370030589,

  /* Variable: K_pp
   * Referenced by: '<S6>/K_pp'
   */
  5.8991559633027535,

  /* Variable: Vd_ff
   * Referenced by: '<Root>/Vd_bias'
   */
  0.1,

  /* Variable: Vs_ff
   * Referenced by: '<Root>/Vs_bias'
   */
  7.88,

  /* Variable: elevation_gain
   * Referenced by: '<S5>/Elevation_gain'
   */
  1.0,

  /* Variable: travel_gain
   * Referenced by: '<S5>/Travel_gain'
   */
  1.0,

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S5>/HIL Write Analog'
   */
  { 0U, 1U },

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<Root>/HIL Initialize'
   */
  24305.934065934067,

  /* Expression: pwm_leading_deadband
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_trailing_deadband
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: 180
   * Referenced by: '<Root>/Travel Offset [deg]'
   */
  180.0,

  /* Expression: 2*pi/8192
   * Referenced by: '<S5>/Travel: Count to rad'
   */
  0.00076699039394282058,

  /* Expression: 180/pi
   * Referenced by: '<S13>/Gain'
   */
  57.295779513082323,

  /* Expression: 2*pi /4096
   * Referenced by: '<S5>/Pitch: Count to rad'
   */
  0.0015339807878856412,

  /* Expression: 180/pi
   * Referenced by: '<S10>/Gain'
   */
  57.295779513082323,

  /* Expression: -2 * pi /4096
   * Referenced by: '<S5>/Elevation: Count to rad'
   */
  -0.0015339807878856412,

  /* Expression: 180/pi
   * Referenced by: '<S8>/Gain'
   */
  57.295779513082323,

  /* Expression: -30
   * Referenced by: '<Root>/elavation_offset [deg]'
   */
  -30.0,

  /* Computed Parameter: TravelTransferFcn_A
   * Referenced by: '<S5>/Travel: Transfer Fcn'
   */
  -10.0,

  /* Computed Parameter: TravelTransferFcn_C
   * Referenced by: '<S5>/Travel: Transfer Fcn'
   */
  -100.0,

  /* Computed Parameter: TravelTransferFcn_D
   * Referenced by: '<S5>/Travel: Transfer Fcn'
   */
  10.0,

  /* Expression: 180/pi
   * Referenced by: '<S14>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: PitchTransferFcn_A
   * Referenced by: '<S5>/Pitch: Transfer Fcn'
   */
  -30.0,

  /* Computed Parameter: PitchTransferFcn_C
   * Referenced by: '<S5>/Pitch: Transfer Fcn'
   */
  -900.0,

  /* Computed Parameter: PitchTransferFcn_D
   * Referenced by: '<S5>/Pitch: Transfer Fcn'
   */
  30.0,

  /* Expression: 180/pi
   * Referenced by: '<S11>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: ElevationTransferFcn_A
   * Referenced by: '<S5>/Elevation: Transfer Fcn'
   */
  -10.0,

  /* Computed Parameter: ElevationTransferFcn_C
   * Referenced by: '<S5>/Elevation: Transfer Fcn'
   */
  -100.0,

  /* Computed Parameter: ElevationTransferFcn_D
   * Referenced by: '<S5>/Elevation: Transfer Fcn'
   */
  10.0,

  /* Expression: 180/pi
   * Referenced by: '<S9>/Gain'
   */
  57.295779513082323,

  /* Expression: pi/180
   * Referenced by: '<S3>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S2>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S4>/Integrator'
   */
  0.0,

  /* Expression: -inf
   * Referenced by: '<S4>/Integrator'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Back gain'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S1>/Front gain'
   */
  0.5,

  /* Expression: 180/pi
   * Referenced by: '<S12>/Gain'
   */
  57.295779513082323,

  /* Expression: 5
   * Referenced by: '<S5>/Back motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S5>/Back motor: Saturation'
   */
  -5.0,

  /* Expression: 5
   * Referenced by: '<S5>/Front motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S5>/Front motor: Saturation'
   */
  -5.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 1, 2 },

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Clock
   * Referenced by: '<S5>/HIL Read Encoder Timebase'
   */
  0,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILReadEncoderTimebase_Channels
   * Referenced by: '<S5>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },

  /* Computed Parameter: HILReadEncoderTimebase_SamplesI
   * Referenced by: '<S5>/HIL Read Encoder Timebase'
   */
  500U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Active
   * Referenced by: '<S5>/HIL Read Encoder Timebase'
   */
  1,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S5>/HIL Write Analog'
   */
  0,

  /* Computed Parameter: HILReadEncoderTimebase_Overflow
   * Referenced by: '<S5>/HIL Read Encoder Timebase'
   */
  1U
};
