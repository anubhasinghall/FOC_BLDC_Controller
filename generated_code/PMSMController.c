/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSMController.c
 *
 * Code generated for Simulink model 'PMSMController'.
 *
 * Model version                  : 11.0
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Thu Mar  5 19:49:40 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "PMSMController.h"
#include "rtwtypes.h"
#include <math.h>
#include <float.h>

/* Named constants for Chart: '<S1>/Controller_Mode_Scheduler' */
#define IN_Motor_Control               ((uint8_T)1U)
#define IN_Motor_On                    ((uint8_T)1U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_Position_Control            ((uint8_T)1U)
#define IN_Ramp_To_Stop                ((uint8_T)2U)
#define IN_Stand_By                    ((uint8_T)2U)
#define IN_Startup_Open_Loop_Control   ((uint8_T)2U)
#define IN_Torque_Control              ((uint8_T)3U)
#define IN_Velocity_Control            ((uint8_T)4U)

/* Named constants for Chart: '<S260>/Wait_For_Valid_Position' */
#define IN_Position_Valid              ((uint8_T)1U)
#define IN_Wait_For_Valid_Position     ((uint8_T)2U)
#define IN_Wait_For_Valid_Velocity     ((uint8_T)3U)

/* Exported block signals */
real32_T phase_currents[2];            /* '<S259>/Product' */
real32_T rotor_position;               /* '<S260>/Add' */
real32_T velocity_measured;            /* '<S264>/Scale_Output' */
real32_T d_current_error;              /* '<S12>/Sum2' */
real32_T q_current_command;            /* '<S5>/Lo_to_Hi_Rate_Transition1' */
real32_T q_current_measured;           /* '<S128>/Add' */
real32_T q_current_error;              /* '<S12>/Sum' */
real32_T phase_voltages[3];            /* '<S132>/Select_Sector' */
real32_T velocity_error;               /* '<S11>/Sum2' */
EnumControllerMode controller_mode;    /* '<S1>/Controller_Mode_Scheduler' */

/* Exported block parameters */
CTRLPARAMS_STRUCT ctrlParams = {
  10.0F,
  10000.0F,
  0.005F,
  0.015F,
  0.1F,
  0.6F,
  1.0F,
  0.2F,
  20.0F,
  2252.25F,
  0.00488400506F,
  -0.0F,
  4.0F
} ;                                    /* Variable: ctrlParams
                                        * Referenced by:
                                        *   '<S1>/Controller_Mode_Scheduler'
                                        *   '<S259>/ADC_Driver_Units_To_Amps'
                                        *   '<S259>/ADC_Zero_Offset'
                                        *   '<S260>/Offset_Between_Encoder_Zero_And_Mechanical_Zero'
                                        *   '<S14>/number_of_pole_pairs'
                                        *   '<S270>/Startup_Acceleration_Constant'
                                        *   '<S182>/Integral Gain'
                                        *   '<S190>/Proportional Gain'
                                        *   '<S237>/Integral Gain'
                                        *   '<S245>/Proportional Gain'
                                        *   '<S52>/Integral Gain'
                                        *   '<S60>/Proportional Gain'
                                        *   '<S106>/Integral Gain'
                                        *   '<S114>/Proportional Gain'
                                        */

/* Constant parameters (default storage) */
const ConstParam ConstP = {
  /* Computed Parameter: Lookup_Table_table
   * Referenced by: '<S133>/Lookup_Table'
   */
  { 2U, 2U, 6U, 1U, 4U, 3U, 5U }
};

/* Block signals and states (default storage) */
D_Work DWork;

/* Real-time model */
static RT_MODEL M_;
RT_MODEL *const M = &M_;
extern real32_T rt_modf(real32_T u0, real32_T u1);
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (M->Timing.TaskCounters.TID[1])++;
  if ((M->Timing.TaskCounters.TID[1]) > 124) {/* Sample time: [0.005s, 0.0s] */
    M->Timing.TaskCounters.TID[1] = 0;
  }
}

real32_T rt_modf(real32_T u0, real32_T u1)
{
  real32_T q;
  real32_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else {
    y = (real32_T)fmod(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > ((real32_T)floor(u1)))) {
      q = (real32_T)fabs(u0 / u1);
      yEq = (((real32_T)fabs(q - ((real32_T)floor(q + 0.5F)))) <= (FLT_EPSILON *
              q));
    }

    if (yEq) {
      y = 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
EnumErrorType Controller(uint16_T motor_on, EnumCommandType command_type,
  real32_T current_request, SENSORS_STRUCT *sensors, uint16_T pwm_compare[3])
{
  int32_T Wrap_To_Pi;
  real32_T DeadZone;
  real32_T Gain1;
  real32_T IntegralGain_f;
  real32_T Switch_f;
  real32_T beta_voltage;
  real32_T cos_coefficient;
  real32_T electrical_angle;
  real32_T sin_coefficient;
  int16_T u0;
  int8_T rtPrevAction;
  int8_T tmp_0;
  uint8_T FixPtRelationalOperator;
  boolean_T Lo_to_Hi_Rate_Transition3;
  boolean_T tmp;

  /* specified return value */
  EnumErrorType error;

  /* RateTransition: '<S6>/Lo_to_Hi_Rate_Transition3' */
  Lo_to_Hi_Rate_Transition3 = DWork.Lo_to_Hi_Rate_Transition3_Buffe;

  /* Product: '<S259>/Product' incorporates:
   *  Constant: '<S259>/ADC_Driver_Units_To_Amps'
   *  Constant: '<S259>/ADC_Zero_Offset'
   *  Inport: '<Root>/sensors'
   *  Sum: '<S259>/Add'
   */
  phase_currents[0] = (((real32_T)sensors->adc_phase_currents[0]) -
                       ctrlParams.AdcZeroOffsetDriverUnits) *
    ctrlParams.AdcDriverUnitsToAmps;
  phase_currents[1] = (((real32_T)sensors->adc_phase_currents[1]) -
                       ctrlParams.AdcZeroOffsetDriverUnits) *
    ctrlParams.AdcDriverUnitsToAmps;

  /* Chart: '<S260>/Wait_For_Valid_Position' incorporates:
   *  Inport: '<Root>/sensors'
   */
  /* Gateway: Motor_Control/Sensors_To_Engineering_Units/Encoder_To_Position/Wait_For_Valid_Position */
  if (DWork.temporalCounter_i1 < 127) {
    DWork.temporalCounter_i1++;
  }

  /* During: Motor_Control/Sensors_To_Engineering_Units/Encoder_To_Position/Wait_For_Valid_Position */
  if (DWork.is_active_c2_PMSMController == 0) {
    /* Entry: Motor_Control/Sensors_To_Engineering_Units/Encoder_To_Position/Wait_For_Valid_Position */
    DWork.is_active_c2_PMSMController = 1U;

    /* Entry Internal: Motor_Control/Sensors_To_Engineering_Units/Encoder_To_Position/Wait_For_Valid_Position */
    /* Transition: '<S263>:113' */
    if (sensors->encoder_valid == 0) {
      /* Transition: '<S263>:114' */
      /* Transition: '<S263>:115' */
      DWork.is_c2_PMSMController = IN_Wait_For_Valid_Position;
    } else {
      /* Transition: '<S263>:120' */
      /* Transition: '<S263>:119' */
      DWork.Position_Valid = 1U;
      DWork.is_c2_PMSMController = IN_Position_Valid;
    }
  } else {
    switch (DWork.is_c2_PMSMController) {
     case IN_Position_Valid:
      /* During 'Position_Valid': '<S263>:25' */
      break;

     case IN_Wait_For_Valid_Position:
      /* During 'Wait_For_Valid_Position': '<S263>:99' */
      if (sensors->encoder_valid != 0) {
        /* Transition: '<S263>:100' */
        DWork.temporalCounter_i1 = 0U;
        DWork.is_c2_PMSMController = IN_Wait_For_Valid_Velocity;
      }
      break;

     default:
      /* During 'Wait_For_Valid_Velocity': '<S263>:101' */
      if (DWork.temporalCounter_i1 >= 124) {
        /* Transition: '<S263>:102' */
        DWork.Position_Valid = 1U;
        DWork.is_c2_PMSMController = IN_Position_Valid;
      }
      break;
    }
  }

  /* End of Chart: '<S260>/Wait_For_Valid_Position' */

  /* Sum: '<S260>/Add' incorporates:
   *  Constant: '<S260>/Offset_Between_Encoder_Zero_And_Mechanical_Zero'
   *  Gain: '<S260>/radians_per_counts'
   *  Inport: '<Root>/sensors'
   */
  rotor_position = (0.000785398181F * ((real32_T)sensors->encoder_counter)) +
    ctrlParams.EncoderToMechanicalZeroOffsetRads;

  /* Update for RateTransition: '<S6>/Lo_to_Hi_Rate_Transition3' */
  tmp = (M->Timing.TaskCounters.TID[1] == 0);
  if (tmp) {
    /* Gain: '<S264>/Wrap_To_Pi' incorporates:
     *  DataTypeConversion: '<S264>/Convert_to_Uint32'
     *  Gain: '<S264>/Scale_Input'
     */
    Wrap_To_Pi = (((int32_T)(1.70891312E+8F * rotor_position)) << 2);

    /* Gain: '<S264>/Scale_Output' incorporates:
     *  DataTypeConversion: '<S264>/Difference_to_Single'
     *  Delay: '<S264>/Position_Delay'
     *  Sum: '<S264>/Difference_Wrap'
     */
    velocity_measured = ((real32_T)(Wrap_To_Pi - DWork.Position_Delay_DSTATE)) *
      2.92583621E-7F;

    /* Chart: '<S1>/Controller_Mode_Scheduler' incorporates:
     *  Inport: '<Root>/command_type'
     *  Inport: '<Root>/command_value'
     *  Inport: '<Root>/motor_on'
     */
    /* Gateway: Mode_Scheduler/Controller_Mode_Scheduler */
    /* During: Mode_Scheduler/Controller_Mode_Scheduler */
    if (DWork.is_c1_PMSMController == IN_Motor_On) {
      /* During 'Motor_On': '<S4>:338' */
      if (((int32_T)DWork.error_l) != 0) {
        /* Transition: '<S4>:339' */
        /* Transition: '<S4>:353' */
        /* Exit Internal 'Motor_On': '<S4>:338' */
        /* Exit Internal 'Motor_Control': '<S4>:344' */
        DWork.is_Motor_Control = IN_NO_ACTIVE_CHILD;
        DWork.is_Motor_On = IN_NO_ACTIVE_CHILD;
        DWork.is_c1_PMSMController = IN_Stand_By;

        /* Entry 'Stand_By': '<S4>:154' */
        controller_mode = StandBy;
      } else if (DWork.is_Motor_On == IN_Motor_Control) {
        /* During 'Motor_Control': '<S4>:344' */
        if (motor_on == 0) {
          /* Transition: '<S4>:282' */
          /* Exit Internal 'Motor_Control': '<S4>:344' */
          DWork.is_Motor_Control = IN_NO_ACTIVE_CHILD;
          DWork.is_Motor_On = IN_Ramp_To_Stop;

          /* Entry 'Ramp_To_Stop': '<S4>:270' */
          controller_mode = VelocityControl;
          DWork.velocity_command = 0.0F;
          DWork.torque_command = 0.0F;
        } else {
          switch (DWork.is_Motor_Control) {
           case IN_Position_Control:
            controller_mode = PositionControl;

            /* During 'Position_Control': '<S4>:226' */
            DWork.position_command = current_request;
            break;

           case IN_Startup_Open_Loop_Control:
            controller_mode = Startup;

            /* During 'Startup_Open_Loop_Control': '<S4>:103' */
            if (DWork.Position_Valid != 0) {
              /* Transition: '<S4>:157' */
              /* Transition: '<S4>:233' */
              switch (command_type) {
               case Velocity:
                /* Transition: '<S4>:162' */
                DWork.is_Motor_Control = IN_Velocity_Control;

                /* Entry 'Velocity_Control': '<S4>:108' */
                controller_mode = VelocityControl;
                DWork.velocity_command = current_request;
                break;

               case Position:
                /* Transition: '<S4>:235' */
                /* Transition: '<S4>:234' */
                DWork.is_Motor_Control = IN_Position_Control;

                /* Entry 'Position_Control': '<S4>:226' */
                controller_mode = PositionControl;
                DWork.position_command = current_request;
                break;

               default:
                /* Transition: '<S4>:237' */
                /* Transition: '<S4>:158' */
                /*  [command_type==Torque] */
                DWork.is_Motor_Control = IN_Torque_Control;

                /* Entry 'Torque_Control': '<S4>:220' */
                controller_mode = TorqueControl;
                DWork.torque_command = current_request;
                break;
              }
            }
            break;

           case IN_Torque_Control:
            controller_mode = TorqueControl;

            /* During 'Torque_Control': '<S4>:220' */
            DWork.torque_command = current_request;
            break;

           default:
            controller_mode = VelocityControl;

            /* During 'Velocity_Control': '<S4>:108' */
            DWork.velocity_command = current_request;
            break;
          }
        }
      } else {
        controller_mode = VelocityControl;

        /* During 'Ramp_To_Stop': '<S4>:270' */
        if (((real32_T)fabs(velocity_measured)) < ctrlParams.RampToStopVelocity)
        {
          /* Transition: '<S4>:169' */
          /* Transition: '<S4>:355' */
          DWork.is_Motor_On = IN_NO_ACTIVE_CHILD;
          DWork.is_c1_PMSMController = IN_Stand_By;

          /* Entry 'Stand_By': '<S4>:154' */
          controller_mode = StandBy;
        }
      }
    } else {
      controller_mode = StandBy;

      /* During 'Stand_By': '<S4>:154' */
      if ((motor_on != 0) && (((int32_T)DWork.error_l) == 0)) {
        /* Transition: '<S4>:164' */
        if (DWork.Position_Valid == 0) {
          /* Transition: '<S4>:133' */
          DWork.is_c1_PMSMController = IN_Motor_On;
          DWork.is_Motor_On = IN_Motor_Control;
          DWork.is_Motor_Control = IN_Startup_Open_Loop_Control;

          /* Entry 'Startup_Open_Loop_Control': '<S4>:103' */
          controller_mode = Startup;
          DWork.torque_command = ctrlParams.StartupCurrent;
        } else {
          /* Transition: '<S4>:137' */
          /* Transition: '<S4>:233' */
          switch (command_type) {
           case Velocity:
            /* Transition: '<S4>:162' */
            DWork.is_c1_PMSMController = IN_Motor_On;
            DWork.is_Motor_On = IN_Motor_Control;
            DWork.is_Motor_Control = IN_Velocity_Control;

            /* Entry 'Velocity_Control': '<S4>:108' */
            controller_mode = VelocityControl;
            DWork.velocity_command = current_request;
            break;

           case Position:
            /* Transition: '<S4>:235' */
            /* Transition: '<S4>:234' */
            DWork.is_c1_PMSMController = IN_Motor_On;
            DWork.is_Motor_On = IN_Motor_Control;
            DWork.is_Motor_Control = IN_Position_Control;

            /* Entry 'Position_Control': '<S4>:226' */
            controller_mode = PositionControl;
            DWork.position_command = current_request;
            break;

           default:
            /* Transition: '<S4>:237' */
            /* Transition: '<S4>:158' */
            /*  [command_type==Torque] */
            DWork.is_c1_PMSMController = IN_Motor_On;
            DWork.is_Motor_On = IN_Motor_Control;
            DWork.is_Motor_Control = IN_Torque_Control;

            /* Entry 'Torque_Control': '<S4>:220' */
            controller_mode = TorqueControl;
            DWork.torque_command = current_request;
            break;
          }
        }
      }
    }

    /* End of Chart: '<S1>/Controller_Mode_Scheduler' */

    /* RelationalOperator: '<S262>/Relational Operator' incorporates:
     *  Constant: '<S269>/Constant'
     */
    DWork.RelationalOperator_aj = (controller_mode == Startup);
  }

  /* Outputs for Enabled SubSystem: '<S262>/Open Loop Position' incorporates:
   *  EnablePort: '<S270>/Enable'
   */
  if (DWork.RelationalOperator_aj) {
    if (!DWork.OpenLoopPosition_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S270>/Integrate_To_Position' */
      DWork.Integrate_To_Position_DSTATE = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S270>/Integrate_To_Velocity' */
      DWork.Integrate_To_Velocity_DSTATE = 0.0F;
      DWork.OpenLoopPosition_MODE = true;
    }

    /* DiscreteIntegrator: '<S270>/Integrate_To_Position' */
    DWork.position = DWork.Integrate_To_Position_DSTATE;

    /* Update for DiscreteIntegrator: '<S270>/Integrate_To_Position' incorporates:
     *  DiscreteIntegrator: '<S270>/Integrate_To_Velocity'
     */
    DWork.Integrate_To_Position_DSTATE += 4.0E-5F *
      DWork.Integrate_To_Velocity_DSTATE;

    /* Update for DiscreteIntegrator: '<S270>/Integrate_To_Velocity' incorporates:
     *  Constant: '<S270>/Startup_Acceleration_Constant'
     */
    DWork.Integrate_To_Velocity_DSTATE += 4.0E-5F *
      ctrlParams.StartupAcceleration;

    /* Switch: '<S262>/Switch' */
    Switch_f = DWork.position;
  } else {
    DWork.OpenLoopPosition_MODE = false;

    /* Switch: '<S262>/Switch' */
    Switch_f = rotor_position;
  }

  /* End of Outputs for SubSystem: '<S262>/Open Loop Position' */

  /* Gain: '<S14>/number_of_pole_pairs' */
  electrical_angle = ctrlParams.PmsmPolePairs * Switch_f;

  /* Trigonometry: '<S14>/sine_cosine' */
  sin_coefficient = (real32_T)sin(electrical_angle);
  cos_coefficient = (real32_T)cos(electrical_angle);

  /* Gain: '<S127>/Beta_Gain' incorporates:
   *  Gain: '<S127>/B_Gain'
   *  Sum: '<S127>/Add'
   */
  electrical_angle = ((2.0F * phase_currents[1]) + phase_currents[0]) *
    0.577350259F;

  /* Sum: '<S12>/Sum2' incorporates:
   *  Constant: '<S12>/d_current_command (A)'
   *  Product: '<S128>/Product2'
   *  Product: '<S128>/Product3'
   *  Sum: '<S128>/Add1'
   */
  d_current_error = 0.0F - ((phase_currents[0] * cos_coefficient) +
    (electrical_angle * sin_coefficient));

  /* RelationalOperator: '<S13>/FixPt Relational Operator' incorporates:
   *  DataTypeConversion: '<S8>/Enum_To_Int'
   *  UnitDelay: '<S13>/Delay Input1'
   */
  FixPtRelationalOperator = (uint8_T)(((int32_T)controller_mode) !=
    DWork.DelayInput1_DSTATE);

  /* DiscreteIntegrator: '<S55>/Integrator' */
  if ((FixPtRelationalOperator != 0) || (DWork.Integrator_PrevResetState != 0))
  {
    DWork.Integrator_DSTATE = 0.0F;
  }

  /* Sum: '<S64>/Sum' incorporates:
   *  DiscreteIntegrator: '<S55>/Integrator'
   *  Gain: '<S60>/Proportional Gain'
   */
  DeadZone = (ctrlParams.Current_P * d_current_error) + DWork.Integrator_DSTATE;

  /* Saturate: '<S62>/Saturation' */
  if (DeadZone > 12.0F) {
    Gain1 = 12.0F;
  } else if (DeadZone < -12.0F) {
    Gain1 = -12.0F;
  } else {
    Gain1 = DeadZone;
  }

  /* End of Saturate: '<S62>/Saturation' */
  if (tmp) {
    /* SwitchCase: '<S5>/Switch Case' */
    rtPrevAction = DWork.SwitchCase_ActiveSubsystem;
    switch (controller_mode) {
     case VelocityControl:
      DWork.SwitchCase_ActiveSubsystem = 0;
      break;

     case PositionControl:
      DWork.SwitchCase_ActiveSubsystem = 1;
      break;

     default:
      DWork.SwitchCase_ActiveSubsystem = 2;
      break;
    }

    switch (DWork.SwitchCase_ActiveSubsystem) {
     case 0:
      if (DWork.SwitchCase_ActiveSubsystem != rtPrevAction) {
        /* InitializeConditions for IfAction SubSystem: '<S5>/Velocity_Control' incorporates:
         *  ActionPort: '<S11>/Action Port'
         */
        /* InitializeConditions for SwitchCase: '<S5>/Switch Case' incorporates:
         *  DiscreteIntegrator: '<S240>/Integrator'
         */
        DWork.Integrator_DSTATE_f = 0.0F;

        /* End of InitializeConditions for SubSystem: '<S5>/Velocity_Control' */
      }

      /* Outputs for IfAction SubSystem: '<S5>/Velocity_Control' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      /* Sum: '<S11>/Sum2' */
      velocity_error = DWork.velocity_command - velocity_measured;

      /* Sum: '<S249>/Sum' incorporates:
       *  DiscreteIntegrator: '<S240>/Integrator'
       *  Gain: '<S245>/Proportional Gain'
       */
      Switch_f = (ctrlParams.Velocity_P * velocity_error) +
        DWork.Integrator_DSTATE_f;

      /* Saturate: '<S247>/Saturation' */
      if (Switch_f > 2.0F) {
        /* Merge: '<S5>/Merge' incorporates:
         *  SignalConversion: '<S11>/Isolate_For_Merge'
         */
        DWork.Merge = 2.0F;

        /* DeadZone: '<S232>/DeadZone' */
        Switch_f -= 2.0F;
      } else {
        if (Switch_f < -2.0F) {
          /* Merge: '<S5>/Merge' incorporates:
           *  SignalConversion: '<S11>/Isolate_For_Merge'
           */
          DWork.Merge = -2.0F;
        } else {
          /* Merge: '<S5>/Merge' incorporates:
           *  SignalConversion: '<S11>/Isolate_For_Merge'
           */
          DWork.Merge = Switch_f;
        }

        /* DeadZone: '<S232>/DeadZone' */
        if (Switch_f >= -2.0F) {
          Switch_f = 0.0F;
        } else {
          Switch_f -= -2.0F;
        }
      }

      /* End of Saturate: '<S247>/Saturation' */

      /* Gain: '<S237>/Integral Gain' */
      IntegralGain_f = ctrlParams.Velocity_I * velocity_error;

      /* Switch: '<S230>/Switch1' incorporates:
       *  Constant: '<S230>/Clamping_zero'
       *  Constant: '<S230>/Constant'
       *  Constant: '<S230>/Constant2'
       *  RelationalOperator: '<S230>/fix for DT propagation issue'
       */
      if (Switch_f > 0.0F) {
        rtPrevAction = 1;
      } else {
        rtPrevAction = -1;
      }

      /* Switch: '<S230>/Switch2' incorporates:
       *  Constant: '<S230>/Clamping_zero'
       *  Constant: '<S230>/Constant3'
       *  Constant: '<S230>/Constant4'
       *  RelationalOperator: '<S230>/fix for DT propagation issue1'
       */
      if (IntegralGain_f > 0.0F) {
        tmp_0 = 1;
      } else {
        tmp_0 = -1;
      }

      /* Switch: '<S230>/Switch' incorporates:
       *  Constant: '<S230>/Clamping_zero'
       *  Constant: '<S230>/Constant1'
       *  Logic: '<S230>/AND3'
       *  RelationalOperator: '<S230>/Equal1'
       *  RelationalOperator: '<S230>/Relational Operator'
       *  Switch: '<S230>/Switch1'
       *  Switch: '<S230>/Switch2'
       */
      if ((Switch_f != 0.0F) && (rtPrevAction == tmp_0)) {
        IntegralGain_f = 0.0F;
      }

      /* Update for DiscreteIntegrator: '<S240>/Integrator' incorporates:
       *  Switch: '<S230>/Switch'
       */
      DWork.Integrator_DSTATE_f += 0.005F * IntegralGain_f;

      /* End of Outputs for SubSystem: '<S5>/Velocity_Control' */
      break;

     case 1:
      if (DWork.SwitchCase_ActiveSubsystem != rtPrevAction) {
        /* InitializeConditions for IfAction SubSystem: '<S5>/Position_Control' incorporates:
         *  ActionPort: '<S9>/Action Port'
         */
        /* InitializeConditions for SwitchCase: '<S5>/Switch Case' incorporates:
         *  DiscreteIntegrator: '<S185>/Integrator'
         */
        DWork.Integrator_DSTATE_n = 0.0F;

        /* End of InitializeConditions for SubSystem: '<S5>/Position_Control' */
      }

      /* Outputs for IfAction SubSystem: '<S5>/Position_Control' incorporates:
       *  ActionPort: '<S9>/Action Port'
       */
      /* Sum: '<S9>/Sum2' */
      Switch_f = DWork.position_command - Switch_f;

      /* Switch: '<S148>/Select_Angle' incorporates:
       *  Constant: '<S148>/Neg_Pi_Constant'
       *  Constant: '<S148>/Pi_Constant_1'
       *  Constant: '<S148>/Pi_Constant_2'
       *  Constant: '<S148>/Pi_Constant_3'
       *  Constant: '<S148>/Two_Pi_Constant'
       *  Logic: '<S148>/OR'
       *  Math: '<S148>/Modulus'
       *  RelationalOperator: '<S148>/Greater_Than'
       *  RelationalOperator: '<S148>/Less_Than'
       *  Sum: '<S148>/Add'
       *  Sum: '<S148>/Subtract'
       */
      if ((Switch_f < -1.57079637F) || (Switch_f >= 1.57079637F)) {
        Switch_f = rt_modf(Switch_f + 1.57079637F, 3.14159274F) - 1.57079637F;
      }

      /* End of Switch: '<S148>/Select_Angle' */

      /* Sum: '<S194>/Sum' incorporates:
       *  DiscreteIntegrator: '<S185>/Integrator'
       *  Gain: '<S190>/Proportional Gain'
       */
      IntegralGain_f = (ctrlParams.Position_P * Switch_f) +
        DWork.Integrator_DSTATE_n;

      /* Saturate: '<S192>/Saturation' */
      if (IntegralGain_f > 2.0F) {
        /* Merge: '<S5>/Merge' incorporates:
         *  SignalConversion: '<S9>/Isolate_For_Merge'
         */
        DWork.Merge = 2.0F;

        /* DeadZone: '<S177>/DeadZone' */
        IntegralGain_f -= 2.0F;
      } else {
        if (IntegralGain_f < -2.0F) {
          /* Merge: '<S5>/Merge' incorporates:
           *  SignalConversion: '<S9>/Isolate_For_Merge'
           */
          DWork.Merge = -2.0F;
        } else {
          /* Merge: '<S5>/Merge' incorporates:
           *  SignalConversion: '<S9>/Isolate_For_Merge'
           */
          DWork.Merge = IntegralGain_f;
        }

        /* DeadZone: '<S177>/DeadZone' */
        if (IntegralGain_f >= -2.0F) {
          IntegralGain_f = 0.0F;
        } else {
          IntegralGain_f -= -2.0F;
        }
      }

      /* End of Saturate: '<S192>/Saturation' */

      /* Gain: '<S182>/Integral Gain' */
      Switch_f *= ctrlParams.Position_I;

      /* Switch: '<S175>/Switch1' incorporates:
       *  Constant: '<S175>/Clamping_zero'
       *  Constant: '<S175>/Constant'
       *  Constant: '<S175>/Constant2'
       *  RelationalOperator: '<S175>/fix for DT propagation issue'
       */
      if (IntegralGain_f > 0.0F) {
        rtPrevAction = 1;
      } else {
        rtPrevAction = -1;
      }

      /* Switch: '<S175>/Switch2' incorporates:
       *  Constant: '<S175>/Clamping_zero'
       *  Constant: '<S175>/Constant3'
       *  Constant: '<S175>/Constant4'
       *  RelationalOperator: '<S175>/fix for DT propagation issue1'
       */
      if (Switch_f > 0.0F) {
        tmp_0 = 1;
      } else {
        tmp_0 = -1;
      }

      /* Switch: '<S175>/Switch' incorporates:
       *  Constant: '<S175>/Clamping_zero'
       *  Constant: '<S175>/Constant1'
       *  Logic: '<S175>/AND3'
       *  RelationalOperator: '<S175>/Equal1'
       *  RelationalOperator: '<S175>/Relational Operator'
       *  Switch: '<S175>/Switch1'
       *  Switch: '<S175>/Switch2'
       */
      if ((IntegralGain_f != 0.0F) && (rtPrevAction == tmp_0)) {
        Switch_f = 0.0F;
      }

      /* Update for DiscreteIntegrator: '<S185>/Integrator' incorporates:
       *  Switch: '<S175>/Switch'
       */
      DWork.Integrator_DSTATE_n += 0.005F * Switch_f;

      /* End of Outputs for SubSystem: '<S5>/Position_Control' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S5>/Torque_Control' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      /* Merge: '<S5>/Merge' incorporates:
       *  SignalConversion generated from: '<S10>/torque_command'
       */
      DWork.Merge = DWork.torque_command;

      /* End of Outputs for SubSystem: '<S5>/Torque_Control' */
      break;
    }

    /* End of SwitchCase: '<S5>/Switch Case' */
  }

  /* RateTransition: '<S5>/Lo_to_Hi_Rate_Transition1' */
  q_current_command = DWork.Merge;

  /* Sum: '<S128>/Add' incorporates:
   *  Product: '<S128>/Product'
   *  Product: '<S128>/Product1'
   */
  q_current_measured = (electrical_angle * cos_coefficient) - (phase_currents[0]
    * sin_coefficient);

  /* Sum: '<S12>/Sum' */
  q_current_error = q_current_command - q_current_measured;

  /* DiscreteIntegrator: '<S109>/Integrator' */
  if ((FixPtRelationalOperator != 0) || (DWork.Integrator_PrevResetState_i != 0))
  {
    DWork.Integrator_DSTATE_o = 0.0F;
  }

  /* Sum: '<S118>/Sum' incorporates:
   *  DiscreteIntegrator: '<S109>/Integrator'
   *  Gain: '<S114>/Proportional Gain'
   */
  electrical_angle = (ctrlParams.Current_P * q_current_error) +
    DWork.Integrator_DSTATE_o;

  /* Saturate: '<S116>/Saturation' */
  if (electrical_angle > 12.0F) {
    IntegralGain_f = 12.0F;
  } else if (electrical_angle < -12.0F) {
    IntegralGain_f = -12.0F;
  } else {
    IntegralGain_f = electrical_angle;
  }

  /* End of Saturate: '<S116>/Saturation' */

  /* Sum: '<S130>/Add' incorporates:
   *  Product: '<S130>/Product'
   *  Product: '<S130>/Product1'
   */
  beta_voltage = (Gain1 * sin_coefficient) + (IntegralGain_f * cos_coefficient);

  /* Gain: '<S134>/Gain' */
  Switch_f = 0.5F * beta_voltage;

  /* Sum: '<S130>/Add1' incorporates:
   *  Product: '<S130>/Product2'
   *  Product: '<S130>/Product3'
   */
  IntegralGain_f = (Gain1 * cos_coefficient) - (IntegralGain_f * sin_coefficient);

  /* Gain: '<S134>/Gain1' */
  Gain1 = 0.866025388F * IntegralGain_f;

  /* Gain: '<S137>/Alpha_Gain' incorporates:
   *  Gain: '<S140>/Alpha_Gain'
   */
  sin_coefficient = 1.73205078F * IntegralGain_f;

  /* Gain: '<S137>/Space_Vector_Gain' incorporates:
   *  Concatenate: '<S132>/Sectors_3_and_6'
   *  Gain: '<S137>/Alpha_Gain'
   *  Sum: '<S137>/Add'
   */
  phase_voltages[0] = ((sin_coefficient + 33.941124F) - beta_voltage) *
    0.353553385F;

  /* Gain: '<S140>/Va_Gain' incorporates:
   *  Concatenate: '<S132>/Sectors_3_and_6'
   *  Sum: '<S140>/Add'
   */
  phase_voltages[1] = ((33.941124F - sin_coefficient) + beta_voltage) *
    0.353553385F;

  /* Gain: '<S143>/Beta_Gain' incorporates:
   *  Gain: '<S138>/Beta_Gain'
   */
  cos_coefficient = 3.0F * beta_voltage;

  /* Gain: '<S143>/Space_Vector_Gain' incorporates:
   *  Concatenate: '<S132>/Sectors_3_and_6'
   *  Gain: '<S143>/Beta_Gain'
   *  Sum: '<S140>/Add'
   *  Sum: '<S143>/Add'
   */
  phase_voltages[2] = ((33.941124F - sin_coefficient) - cos_coefficient) *
    0.353553385F;

  /* LookupNDDirect: '<S133>/Lookup_Table' incorporates:
   *  Constant: '<S144>/Constant'
   *  Constant: '<S145>/Constant'
   *  Constant: '<S146>/Constant'
   *  Gain: '<S133>/Sector_Gain_VB'
   *  Gain: '<S133>/Sector_Gain_VC'
   *  RelationalOperator: '<S144>/Compare'
   *  RelationalOperator: '<S145>/Compare'
   *  RelationalOperator: '<S146>/Compare'
   *  Sum: '<S133>/Calculate_Phase_Advanced_Sector'
   *  Sum: '<S134>/Add'
   *  Sum: '<S134>/Add1'
   *
   * About '<S133>/Lookup_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  u0 = (int16_T)(((((Gain1 - Switch_f) > 0.0F) << 1) + (beta_voltage > 0.0F)) +
                 ((((0.0F - Switch_f) - Gain1) > 0.0F) << 2));
  if (u0 > 6) {
    u0 = 6;
  }

  /* MultiPortSwitch: '<S132>/Select_Sector' incorporates:
   *  LookupNDDirect: '<S133>/Lookup_Table'
   *
   * About '<S133>/Lookup_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  switch (ConstP.Lookup_Table_table[u0]) {
   case 1:
    /* MultiPortSwitch: '<S132>/Select_Sector' incorporates:
     *  Concatenate: '<S132>/Sectors_3_and_6'
     *  Gain: '<S135>/Space_Vector_Gain'
     *  Gain: '<S137>/Alpha_Gain'
     *  Gain: '<S138>/Va_Gain'
     *  Gain: '<S141>/Space_Vector_Gain'
     *  Sum: '<S135>/Add'
     *  Sum: '<S137>/Add'
     *  Sum: '<S138>/Add'
     *  Sum: '<S140>/Add'
     *  Sum: '<S141>/Add'
     */
    phase_voltages[0] = ((sin_coefficient + 33.941124F) + beta_voltage) *
      0.353553385F;
    phase_voltages[1] = ((33.941124F - sin_coefficient) + cos_coefficient) *
      0.353553385F;
    phase_voltages[2] = ((33.941124F - sin_coefficient) - beta_voltage) *
      0.353553385F;
    break;

   case 2:
    /* MultiPortSwitch: '<S132>/Select_Sector' incorporates:
     *  Concatenate: '<S132>/Sectors_3_and_6'
     *  Constant: '<S132>/Bus_Voltage'
     *  Gain: '<S136>/Alpha_Gain'
     *  Gain: '<S136>/Space_Vector_Gain'
     *  Sum: '<S136>/Add'
     */
    phase_voltages[0] = ((2.44948983F * IntegralGain_f) + 24.0F) * 0.5F;

    /* Gain: '<S139>/Beta_Gain' incorporates:
     *  Gain: '<S142>/Beta_Gain'
     */
    sin_coefficient = 1.41421354F * beta_voltage;

    /* MultiPortSwitch: '<S132>/Select_Sector' incorporates:
     *  Concatenate: '<S132>/Sectors_3_and_6'
     *  Constant: '<S132>/Bus_Voltage'
     *  Gain: '<S139>/Beta_Gain'
     *  Gain: '<S139>/Va_Gain'
     *  Gain: '<S142>/Space_Vector_Gain'
     *  Sum: '<S139>/Add'
     *  Sum: '<S142>/Add'
     */
    phase_voltages[1] = (sin_coefficient + 24.0F) * 0.5F;
    phase_voltages[2] = (24.0F - sin_coefficient) * 0.5F;
    break;

   case 3:
    break;

   case 4:
    /* MultiPortSwitch: '<S132>/Select_Sector' incorporates:
     *  Concatenate: '<S132>/Sectors_3_and_6'
     *  Gain: '<S135>/Space_Vector_Gain'
     *  Gain: '<S137>/Alpha_Gain'
     *  Gain: '<S138>/Va_Gain'
     *  Gain: '<S141>/Space_Vector_Gain'
     *  Sum: '<S135>/Add'
     *  Sum: '<S137>/Add'
     *  Sum: '<S138>/Add'
     *  Sum: '<S140>/Add'
     *  Sum: '<S141>/Add'
     */
    phase_voltages[0] = ((sin_coefficient + 33.941124F) + beta_voltage) *
      0.353553385F;
    phase_voltages[1] = ((33.941124F - sin_coefficient) + cos_coefficient) *
      0.353553385F;
    phase_voltages[2] = ((33.941124F - sin_coefficient) - beta_voltage) *
      0.353553385F;
    break;

   case 5:
    /* MultiPortSwitch: '<S132>/Select_Sector' incorporates:
     *  Concatenate: '<S132>/Sectors_3_and_6'
     *  Constant: '<S132>/Bus_Voltage'
     *  Gain: '<S136>/Alpha_Gain'
     *  Gain: '<S136>/Space_Vector_Gain'
     *  Sum: '<S136>/Add'
     */
    phase_voltages[0] = ((2.44948983F * IntegralGain_f) + 24.0F) * 0.5F;

    /* Gain: '<S139>/Beta_Gain' incorporates:
     *  Gain: '<S142>/Beta_Gain'
     */
    sin_coefficient = 1.41421354F * beta_voltage;

    /* MultiPortSwitch: '<S132>/Select_Sector' incorporates:
     *  Concatenate: '<S132>/Sectors_3_and_6'
     *  Constant: '<S132>/Bus_Voltage'
     *  Gain: '<S139>/Beta_Gain'
     *  Gain: '<S139>/Va_Gain'
     *  Gain: '<S142>/Space_Vector_Gain'
     *  Sum: '<S139>/Add'
     *  Sum: '<S142>/Add'
     */
    phase_voltages[1] = (sin_coefficient + 24.0F) * 0.5F;
    phase_voltages[2] = (24.0F - sin_coefficient) * 0.5F;
    break;

   default:
    /* no actions */
    break;
  }

  /* End of MultiPortSwitch: '<S132>/Select_Sector' */

  /* Switch: '<S6>/Switch' */
  if (Lo_to_Hi_Rate_Transition3) {
    /* Outport: '<Root>/pwm_compare' incorporates:
     *  Constant: '<S6>/Constant'
     */
    pwm_compare[0] = 1500U;
    pwm_compare[1] = 1500U;
    pwm_compare[2] = 1500U;
  } else {
    /* Gain: '<S6>/Voltage to PWM Compare Units' */
    Gain1 = 125.0F * phase_voltages[0];

    /* Saturate: '<S6>/Saturation' */
    if (Gain1 > 2999.0F) {
      /* Outport: '<Root>/pwm_compare' */
      pwm_compare[0] = 2999U;
    } else if (Gain1 < 0.0F) {
      /* Outport: '<Root>/pwm_compare' */
      pwm_compare[0] = 0U;
    } else {
      /* Outport: '<Root>/pwm_compare' incorporates:
       *  DataTypeConversion: '<S6>/Quantize'
       */
      pwm_compare[0] = (uint16_T)Gain1;
    }

    /* Gain: '<S6>/Voltage to PWM Compare Units' */
    Gain1 = 125.0F * phase_voltages[1];

    /* Saturate: '<S6>/Saturation' */
    if (Gain1 > 2999.0F) {
      /* Outport: '<Root>/pwm_compare' */
      pwm_compare[1] = 2999U;
    } else if (Gain1 < 0.0F) {
      /* Outport: '<Root>/pwm_compare' */
      pwm_compare[1] = 0U;
    } else {
      /* Outport: '<Root>/pwm_compare' incorporates:
       *  DataTypeConversion: '<S6>/Quantize'
       */
      pwm_compare[1] = (uint16_T)Gain1;
    }

    /* Gain: '<S6>/Voltage to PWM Compare Units' */
    Gain1 = 125.0F * phase_voltages[2];

    /* Saturate: '<S6>/Saturation' */
    if (Gain1 > 2999.0F) {
      /* Outport: '<Root>/pwm_compare' */
      pwm_compare[2] = 2999U;
    } else if (Gain1 < 0.0F) {
      /* Outport: '<Root>/pwm_compare' */
      pwm_compare[2] = 0U;
    } else {
      /* Outport: '<Root>/pwm_compare' incorporates:
       *  DataTypeConversion: '<S6>/Quantize'
       */
      pwm_compare[2] = (uint16_T)Gain1;
    }
  }

  /* End of Switch: '<S6>/Switch' */

  /* DeadZone: '<S47>/DeadZone' */
  if (DeadZone > 12.0F) {
    DeadZone -= 12.0F;
  } else if (DeadZone >= -12.0F) {
    DeadZone = 0.0F;
  } else {
    DeadZone -= -12.0F;
  }

  /* End of DeadZone: '<S47>/DeadZone' */

  /* Gain: '<S52>/Integral Gain' */
  Switch_f = ctrlParams.Current_I * d_current_error;

  /* Switch: '<S45>/Switch1' incorporates:
   *  Constant: '<S45>/Clamping_zero'
   *  Constant: '<S45>/Constant'
   *  Constant: '<S45>/Constant2'
   *  RelationalOperator: '<S45>/fix for DT propagation issue'
   */
  if (DeadZone > 0.0F) {
    rtPrevAction = 1;
  } else {
    rtPrevAction = -1;
  }

  /* Switch: '<S45>/Switch2' incorporates:
   *  Constant: '<S45>/Clamping_zero'
   *  Constant: '<S45>/Constant3'
   *  Constant: '<S45>/Constant4'
   *  RelationalOperator: '<S45>/fix for DT propagation issue1'
   */
  if (Switch_f > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S45>/Switch' incorporates:
   *  Constant: '<S45>/Clamping_zero'
   *  Constant: '<S45>/Constant1'
   *  Logic: '<S45>/AND3'
   *  RelationalOperator: '<S45>/Equal1'
   *  RelationalOperator: '<S45>/Relational Operator'
   *  Switch: '<S45>/Switch1'
   *  Switch: '<S45>/Switch2'
   */
  if ((DeadZone != 0.0F) && (rtPrevAction == tmp_0)) {
    DeadZone = 0.0F;
  } else {
    DeadZone = Switch_f;
  }

  /* End of Switch: '<S45>/Switch' */

  /* DeadZone: '<S101>/DeadZone' */
  if (electrical_angle > 12.0F) {
    electrical_angle -= 12.0F;
  } else if (electrical_angle >= -12.0F) {
    electrical_angle = 0.0F;
  } else {
    electrical_angle -= -12.0F;
  }

  /* End of DeadZone: '<S101>/DeadZone' */

  /* Gain: '<S106>/Integral Gain' */
  Switch_f = ctrlParams.Current_I * q_current_error;

  /* Update for RateTransition: '<S6>/Lo_to_Hi_Rate_Transition3' incorporates:
   *  Abs: '<S265>/Velocity_Abs'
   *  Constant: '<S265>/Max_Valid_Velocity_Change'
   *  Constant: '<S266>/Constant'
   *  Delay: '<S265>/Velocity_Delay'
   *  Logic: '<S265>/AND'
   *  RelationalOperator: '<S265>/Excessive_Velocity_Change'
   *  RelationalOperator: '<S265>/Relational_Operator'
   *  Sum: '<S265>/Velocity_Difference'
   */
  if (tmp) {
    /* RelationalOperator: '<S6>/Relational Operator' incorporates:
     *  Constant: '<S258>/Constant'
     */
    Lo_to_Hi_Rate_Transition3 = (controller_mode == StandBy);

    /* Outputs for Enabled SubSystem: '<S265>/Generate_Error' incorporates:
     *  EnablePort: '<S267>/Enable'
     */
    if ((controller_mode == VelocityControl) && (((real32_T)fabs
          (velocity_measured - DWork.Velocity_Delay_DSTATE)) >= 628.318542F)) {
      /* DataStoreWrite: '<S267>/Data_Store_Write' incorporates:
       *  Constant: '<S268>/Constant'
       */
      DWork.error_l = MeasuredVelocityError;
    }

    /* End of Outputs for SubSystem: '<S265>/Generate_Error' */
    DWork.Lo_to_Hi_Rate_Transition3_Buffe = Lo_to_Hi_Rate_Transition3;

    /* Update for Delay: '<S264>/Position_Delay' incorporates:
     *  Abs: '<S265>/Velocity_Abs'
     *  Constant: '<S265>/Max_Valid_Velocity_Change'
     *  Constant: '<S266>/Constant'
     *  Delay: '<S265>/Velocity_Delay'
     *  Logic: '<S265>/AND'
     *  RelationalOperator: '<S265>/Excessive_Velocity_Change'
     *  RelationalOperator: '<S265>/Relational_Operator'
     *  Sum: '<S265>/Velocity_Difference'
     */
    DWork.Position_Delay_DSTATE = Wrap_To_Pi;
  }

  /* Outport: '<Root>/error' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   */
  error = DWork.error_l;

  /* Update for UnitDelay: '<S13>/Delay Input1' incorporates:
   *  DataTypeConversion: '<S8>/Enum_To_Int'
   */
  DWork.DelayInput1_DSTATE = (int16_T)controller_mode;

  /* Update for DiscreteIntegrator: '<S55>/Integrator' incorporates:
   *  DiscreteIntegrator: '<S109>/Integrator'
   */
  DWork.Integrator_DSTATE += 4.0E-5F * DeadZone;
  DWork.Integrator_PrevResetState = (int8_T)(FixPtRelationalOperator > 0);

  /* Switch: '<S99>/Switch1' incorporates:
   *  Constant: '<S99>/Clamping_zero'
   *  Constant: '<S99>/Constant'
   *  Constant: '<S99>/Constant2'
   *  RelationalOperator: '<S99>/fix for DT propagation issue'
   */
  if (electrical_angle > 0.0F) {
    rtPrevAction = 1;
  } else {
    rtPrevAction = -1;
  }

  /* Switch: '<S99>/Switch2' incorporates:
   *  Constant: '<S99>/Clamping_zero'
   *  Constant: '<S99>/Constant3'
   *  Constant: '<S99>/Constant4'
   *  RelationalOperator: '<S99>/fix for DT propagation issue1'
   */
  if (Switch_f > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S99>/Switch' incorporates:
   *  Constant: '<S99>/Clamping_zero'
   *  Constant: '<S99>/Constant1'
   *  Logic: '<S99>/AND3'
   *  RelationalOperator: '<S99>/Equal1'
   *  RelationalOperator: '<S99>/Relational Operator'
   *  Switch: '<S99>/Switch1'
   *  Switch: '<S99>/Switch2'
   */
  if ((electrical_angle != 0.0F) && (rtPrevAction == tmp_0)) {
    Switch_f = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S109>/Integrator' incorporates:
   *  Switch: '<S99>/Switch'
   */
  DWork.Integrator_DSTATE_o += 4.0E-5F * Switch_f;
  DWork.Integrator_PrevResetState_i = DWork.Integrator_PrevResetState;
  if (tmp) {
    /* Update for Delay: '<S265>/Velocity_Delay' */
    DWork.Velocity_Delay_DSTATE = velocity_measured;
  }

  rate_scheduler();
  return error;
}

/* Model initialize function */
void Controller_Init(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)M, 0,
                sizeof(RT_MODEL));

  /* block I/O */

  /* exported global signals */
  phase_currents[0] = 0.0F;
  phase_currents[1] = 0.0F;
  rotor_position = 0.0F;
  velocity_measured = 0.0F;
  d_current_error = 0.0F;
  q_current_command = 0.0F;
  q_current_measured = 0.0F;
  q_current_error = 0.0F;
  phase_voltages[0] = 0.0F;
  phase_voltages[1] = 0.0F;
  phase_voltages[2] = 0.0F;
  velocity_error = 0.0F;
  controller_mode = StandBy;

  /* states (dwork) */
  (void) memset((void *)&DWork, 0,
                sizeof(D_Work));

  /* Start for SwitchCase: '<S5>/Switch Case' */
  DWork.SwitchCase_ActiveSubsystem = -1;

  /* InitializeConditions for DiscreteIntegrator: '<S55>/Integrator' */
  DWork.Integrator_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S109>/Integrator' */
  DWork.Integrator_PrevResetState_i = 0;

  /* SystemInitialize for Chart: '<S260>/Wait_For_Valid_Position' */
  DWork.temporalCounter_i1 = 0U;
  DWork.Position_Valid = 0U;
  DWork.is_active_c2_PMSMController = 0U;
  DWork.is_c2_PMSMController = IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S1>/Controller_Mode_Scheduler' */
  DWork.velocity_command = 0.0F;
  DWork.position_command = 0.0F;
  DWork.torque_command = 0.0F;
  DWork.is_Motor_On = IN_NO_ACTIVE_CHILD;
  DWork.is_Motor_Control = IN_NO_ACTIVE_CHILD;

  /* Chart: '<S1>/Controller_Mode_Scheduler' */
  /* Entry: Mode_Scheduler/Controller_Mode_Scheduler */
  /* Entry Internal: Mode_Scheduler/Controller_Mode_Scheduler */
  /* Transition: '<S4>:9' */
  DWork.is_c1_PMSMController = IN_Stand_By;

  /* Entry 'Stand_By': '<S4>:154' */
  controller_mode = StandBy;

  /* SystemInitialize for Enabled SubSystem: '<S262>/Open Loop Position' */
  /* InitializeConditions for DiscreteIntegrator: '<S270>/Integrate_To_Position' */
  DWork.Integrate_To_Position_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S270>/Integrate_To_Velocity' */
  DWork.Integrate_To_Velocity_DSTATE = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S262>/Open Loop Position' */

  /* SystemInitialize for IfAction SubSystem: '<S5>/Velocity_Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S240>/Integrator' */
  DWork.Integrator_DSTATE_f = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S5>/Velocity_Control' */

  /* SystemInitialize for IfAction SubSystem: '<S5>/Position_Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S185>/Integrator' */
  DWork.Integrator_DSTATE_n = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S5>/Position_Control' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
