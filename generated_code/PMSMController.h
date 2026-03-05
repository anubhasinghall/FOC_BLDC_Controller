/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSMController.h
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

#ifndef PMSMController_h_
#define PMSMController_h_
#ifndef PMSMController_COMMON_INCLUDES_
#define PMSMController_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PMSMController_COMMON_INCLUDES_ */

#include <string.h>

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_CTRLPARAMS_STRUCT_
#define DEFINED_TYPEDEF_FOR_CTRLPARAMS_STRUCT_

typedef struct {
  real32_T Current_P;
  real32_T Current_I;
  real32_T Velocity_P;
  real32_T Velocity_I;
  real32_T Position_P;
  real32_T Position_I;
  real32_T StartupAcceleration;
  real32_T StartupCurrent;
  real32_T RampToStopVelocity;
  real32_T AdcZeroOffsetDriverUnits;
  real32_T AdcDriverUnitsToAmps;
  real32_T EncoderToMechanicalZeroOffsetRads;
  real32_T PmsmPolePairs;
} CTRLPARAMS_STRUCT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumControllerMode_
#define DEFINED_TYPEDEF_FOR_EnumControllerMode_

typedef enum {
  StandBy = 0,                         /* Default value */
  Startup,
  TorqueControl,
  VelocityControl,
  PositionControl
} EnumControllerMode;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumErrorType_
#define DEFINED_TYPEDEF_FOR_EnumErrorType_

typedef enum {
  NoError = 0,                         /* Default value */
  MeasuredVelocityError
} EnumErrorType;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SENSORS_STRUCT_
#define DEFINED_TYPEDEF_FOR_SENSORS_STRUCT_

typedef struct {
  uint16_T adc_phase_currents[2];
  uint16_T encoder_valid;
  uint16_T encoder_counter;
} SENSORS_STRUCT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumCommandType_
#define DEFINED_TYPEDEF_FOR_EnumCommandType_

typedef enum {
  Torque = 0,                          /* Default value */
  Velocity,
  Position
} EnumCommandType;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T Merge;                      /* '<S5>/Merge' */
  real32_T position;                   /* '<S270>/Integrate_To_Position' */
  real32_T velocity_command;           /* '<S1>/Controller_Mode_Scheduler' */
  real32_T position_command;           /* '<S1>/Controller_Mode_Scheduler' */
  real32_T torque_command;             /* '<S1>/Controller_Mode_Scheduler' */
  real32_T Integrator_DSTATE;          /* '<S55>/Integrator' */
  real32_T Integrator_DSTATE_o;        /* '<S109>/Integrator' */
  real32_T Velocity_Delay_DSTATE;      /* '<S265>/Velocity_Delay' */
  real32_T Integrate_To_Position_DSTATE;/* '<S270>/Integrate_To_Position' */
  real32_T Integrate_To_Velocity_DSTATE;/* '<S270>/Integrate_To_Velocity' */
  real32_T Integrator_DSTATE_n;        /* '<S185>/Integrator' */
  real32_T Integrator_DSTATE_f;        /* '<S240>/Integrator' */
  int32_T Position_Delay_DSTATE;       /* '<S264>/Position_Delay' */
  EnumErrorType error_l;               /* '<Root>/Data Store Memory' */
  int16_T DelayInput1_DSTATE;          /* '<S13>/Delay Input1' */
  uint16_T Position_Valid;             /* '<S260>/Wait_For_Valid_Position' */
  int8_T Integrator_PrevResetState;    /* '<S55>/Integrator' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S5>/Switch Case' */
  int8_T Integrator_PrevResetState_i;  /* '<S109>/Integrator' */
  uint8_T is_active_c2_PMSMController; /* '<S260>/Wait_For_Valid_Position' */
  uint8_T is_c2_PMSMController;        /* '<S260>/Wait_For_Valid_Position' */
  uint8_T temporalCounter_i1;          /* '<S260>/Wait_For_Valid_Position' */
  uint8_T is_c1_PMSMController;        /* '<S1>/Controller_Mode_Scheduler' */
  uint8_T is_Motor_On;                 /* '<S1>/Controller_Mode_Scheduler' */
  uint8_T is_Motor_Control;            /* '<S1>/Controller_Mode_Scheduler' */
  boolean_T RelationalOperator_aj;     /* '<S262>/Relational Operator' */
  volatile boolean_T Lo_to_Hi_Rate_Transition3_Buffe;/* '<S6>/Lo_to_Hi_Rate_Transition3' */
  boolean_T OpenLoopPosition_MODE;     /* '<S262>/Open Loop Position' */
} D_Work;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Lookup_Table_table
   * Referenced by: '<S133>/Lookup_Table'
   */
  uint16_T Lookup_Table_table[7];
} ConstParam;

/* Real-time Model Data Structure */
struct tag_RTM {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern D_Work DWork;

/* Constant parameters (default storage) */
extern const ConstParam ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T phase_currents[2];     /* '<S259>/Product' */
extern real32_T rotor_position;        /* '<S260>/Add' */
extern real32_T velocity_measured;     /* '<S264>/Scale_Output' */
extern real32_T d_current_error;       /* '<S12>/Sum2' */
extern real32_T q_current_command;     /* '<S5>/Lo_to_Hi_Rate_Transition1' */
extern real32_T q_current_measured;    /* '<S128>/Add' */
extern real32_T q_current_error;       /* '<S12>/Sum' */
extern real32_T phase_voltages[3];     /* '<S132>/Select_Sector' */
extern real32_T velocity_error;        /* '<S11>/Sum2' */
extern EnumControllerMode controller_mode;/* '<S1>/Controller_Mode_Scheduler' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern CTRLPARAMS_STRUCT ctrlParams;   /* Variable: ctrlParams
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

/* Model entry point functions */
extern void Controller_Init(void);

/* Customized model step function */
extern EnumErrorType Controller(uint16_T motor_on, EnumCommandType command_type,
  real32_T current_request, SENSORS_STRUCT *sensors, uint16_T pwm_compare[3]);

/* Real-time Model object */
extern RT_MODEL *const M;

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
 * '<Root>' : 'PMSMController'
 * '<S1>'   : 'PMSMController/Mode_Scheduler'
 * '<S2>'   : 'PMSMController/Model Info'
 * '<S3>'   : 'PMSMController/Motor_Control'
 * '<S4>'   : 'PMSMController/Mode_Scheduler/Controller_Mode_Scheduler'
 * '<S5>'   : 'PMSMController/Motor_Control/Field_Oriented_Controller'
 * '<S6>'   : 'PMSMController/Motor_Control/Phase_Voltages_to_PWM_Compare_Values'
 * '<S7>'   : 'PMSMController/Motor_Control/Sensors_To_Engineering_Units'
 * '<S8>'   : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control'
 * '<S9>'   : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control'
 * '<S10>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Torque_Control'
 * '<S11>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control'
 * '<S12>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers'
 * '<S13>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Detect_Change'
 * '<S14>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Rotation_Coefficients_Sin_Cos'
 * '<S15>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_ABC_to_dq'
 * '<S16>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC'
 * '<S17>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control'
 * '<S18>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control'
 * '<S19>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Anti-windup'
 * '<S20>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/D Gain'
 * '<S21>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/External Derivative'
 * '<S22>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Filter'
 * '<S23>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Filter ICs'
 * '<S24>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/I Gain'
 * '<S25>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Ideal P Gain'
 * '<S26>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Ideal P Gain Fdbk'
 * '<S27>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Integrator'
 * '<S28>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Integrator ICs'
 * '<S29>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/N Copy'
 * '<S30>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/N Gain'
 * '<S31>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/P Copy'
 * '<S32>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Parallel P Gain'
 * '<S33>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Reset Signal'
 * '<S34>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Saturation'
 * '<S35>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Saturation Fdbk'
 * '<S36>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Sum'
 * '<S37>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Sum Fdbk'
 * '<S38>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Tracking Mode'
 * '<S39>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Tracking Mode Sum'
 * '<S40>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Tsamp - Integral'
 * '<S41>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Tsamp - Ngain'
 * '<S42>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/postSat Signal'
 * '<S43>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/preInt Signal'
 * '<S44>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/preSat Signal'
 * '<S45>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Anti-windup/Disc. Clamping Parallel'
 * '<S46>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S47>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S48>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/D Gain/Disabled'
 * '<S49>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/External Derivative/Disabled'
 * '<S50>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Filter/Disabled'
 * '<S51>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Filter ICs/Disabled'
 * '<S52>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/I Gain/Internal Parameters'
 * '<S53>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Ideal P Gain/Passthrough'
 * '<S54>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Ideal P Gain Fdbk/Disabled'
 * '<S55>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Integrator/Discrete'
 * '<S56>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Integrator ICs/Internal IC'
 * '<S57>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/N Copy/Disabled wSignal Specification'
 * '<S58>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/N Gain/Disabled'
 * '<S59>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/P Copy/Disabled'
 * '<S60>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Parallel P Gain/Internal Parameters'
 * '<S61>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Reset Signal/External Reset'
 * '<S62>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Saturation/Enabled'
 * '<S63>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Saturation Fdbk/Disabled'
 * '<S64>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Sum/Sum_PI'
 * '<S65>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Sum Fdbk/Disabled'
 * '<S66>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Tracking Mode/Disabled'
 * '<S67>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Tracking Mode Sum/Passthrough'
 * '<S68>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Tsamp - Integral/TsSignalSpecification'
 * '<S69>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/Tsamp - Ngain/Passthrough'
 * '<S70>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/postSat Signal/Forward_Path'
 * '<S71>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/preInt Signal/Internal PreInt'
 * '<S72>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Direct_Current_Control/preSat Signal/Forward_Path'
 * '<S73>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Anti-windup'
 * '<S74>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/D Gain'
 * '<S75>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/External Derivative'
 * '<S76>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Filter'
 * '<S77>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Filter ICs'
 * '<S78>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/I Gain'
 * '<S79>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Ideal P Gain'
 * '<S80>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Ideal P Gain Fdbk'
 * '<S81>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Integrator'
 * '<S82>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Integrator ICs'
 * '<S83>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/N Copy'
 * '<S84>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/N Gain'
 * '<S85>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/P Copy'
 * '<S86>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Parallel P Gain'
 * '<S87>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Reset Signal'
 * '<S88>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Saturation'
 * '<S89>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Saturation Fdbk'
 * '<S90>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Sum'
 * '<S91>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Sum Fdbk'
 * '<S92>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Tracking Mode'
 * '<S93>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Tracking Mode Sum'
 * '<S94>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Tsamp - Integral'
 * '<S95>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Tsamp - Ngain'
 * '<S96>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/postSat Signal'
 * '<S97>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/preInt Signal'
 * '<S98>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/preSat Signal'
 * '<S99>'  : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Anti-windup/Disc. Clamping Parallel'
 * '<S100>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S101>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S102>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/D Gain/Disabled'
 * '<S103>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/External Derivative/Disabled'
 * '<S104>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Filter/Disabled'
 * '<S105>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Filter ICs/Disabled'
 * '<S106>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/I Gain/Internal Parameters'
 * '<S107>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Ideal P Gain/Passthrough'
 * '<S108>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Ideal P Gain Fdbk/Disabled'
 * '<S109>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Integrator/Discrete'
 * '<S110>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Integrator ICs/Internal IC'
 * '<S111>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/N Copy/Disabled wSignal Specification'
 * '<S112>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/N Gain/Disabled'
 * '<S113>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/P Copy/Disabled'
 * '<S114>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Parallel P Gain/Internal Parameters'
 * '<S115>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Reset Signal/External Reset'
 * '<S116>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Saturation/Enabled'
 * '<S117>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Saturation Fdbk/Disabled'
 * '<S118>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Sum/Sum_PI'
 * '<S119>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Sum Fdbk/Disabled'
 * '<S120>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Tracking Mode/Disabled'
 * '<S121>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Tracking Mode Sum/Passthrough'
 * '<S122>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Tsamp - Integral/TsSignalSpecification'
 * '<S123>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/Tsamp - Ngain/Passthrough'
 * '<S124>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/postSat Signal/Forward_Path'
 * '<S125>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/preInt Signal/Internal PreInt'
 * '<S126>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Current_Controllers/Quadrature_Current_Control/preSat Signal/Forward_Path'
 * '<S127>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_ABC_to_dq/Clarke_Transform'
 * '<S128>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_ABC_to_dq/Park_Transform'
 * '<S129>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC'
 * '<S130>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Inverse_Park_Transform'
 * '<S131>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC/Space_Vector_Modulation'
 * '<S132>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC/Space_Vector_Modulation/Calculate_Phase_Voltages'
 * '<S133>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC/Space_Vector_Modulation/Determine_Sector'
 * '<S134>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC/Space_Vector_Modulation/Phase_Advanced_Inverse_Clarke'
 * '<S135>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC/Space_Vector_Modulation/Calculate_Phase_Voltages/Va_Sectors_1_and_4'
 * '<S136>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC/Space_Vector_Modulation/Calculate_Phase_Voltages/Va_Sectors_2_and_5'
 * '<S137>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC/Space_Vector_Modulation/Calculate_Phase_Voltages/Va_Sectors_3_and_6'
 * '<S138>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC/Space_Vector_Modulation/Calculate_Phase_Voltages/Vb_Sectors_1_and_4'
 * '<S139>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC/Space_Vector_Modulation/Calculate_Phase_Voltages/Vb_Sectors_2_and_5'
 * '<S140>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC/Space_Vector_Modulation/Calculate_Phase_Voltages/Vb_Sectors_3_and_6'
 * '<S141>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC/Space_Vector_Modulation/Calculate_Phase_Voltages/Vc_Sectors_1_and_4'
 * '<S142>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC/Space_Vector_Modulation/Calculate_Phase_Voltages/Vc_Sectors_2_and_5'
 * '<S143>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC/Space_Vector_Modulation/Calculate_Phase_Voltages/Vc_Sectors_3_and_6'
 * '<S144>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC/Space_Vector_Modulation/Determine_Sector/Compare_VA_To_Zero'
 * '<S145>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC/Space_Vector_Modulation/Determine_Sector/Compare_VB_To_Zero'
 * '<S146>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Current_Control/Transform_Coordinates_dq_to_ABC/Alpha_Beta_to_ABC/Space_Vector_Modulation/Determine_Sector/Compare_VC_To_Zero'
 * '<S147>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control'
 * '<S148>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Wrap_Error_pi'
 * '<S149>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Anti-windup'
 * '<S150>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/D Gain'
 * '<S151>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/External Derivative'
 * '<S152>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Filter'
 * '<S153>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Filter ICs'
 * '<S154>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/I Gain'
 * '<S155>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Ideal P Gain'
 * '<S156>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Ideal P Gain Fdbk'
 * '<S157>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Integrator'
 * '<S158>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Integrator ICs'
 * '<S159>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/N Copy'
 * '<S160>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/N Gain'
 * '<S161>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/P Copy'
 * '<S162>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Parallel P Gain'
 * '<S163>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Reset Signal'
 * '<S164>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Saturation'
 * '<S165>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Saturation Fdbk'
 * '<S166>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Sum'
 * '<S167>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Sum Fdbk'
 * '<S168>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Tracking Mode'
 * '<S169>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Tracking Mode Sum'
 * '<S170>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Tsamp - Integral'
 * '<S171>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Tsamp - Ngain'
 * '<S172>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/postSat Signal'
 * '<S173>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/preInt Signal'
 * '<S174>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/preSat Signal'
 * '<S175>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Anti-windup/Disc. Clamping Parallel'
 * '<S176>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S177>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S178>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/D Gain/Disabled'
 * '<S179>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/External Derivative/Disabled'
 * '<S180>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Filter/Disabled'
 * '<S181>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Filter ICs/Disabled'
 * '<S182>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/I Gain/Internal Parameters'
 * '<S183>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Ideal P Gain/Passthrough'
 * '<S184>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Ideal P Gain Fdbk/Disabled'
 * '<S185>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Integrator/Discrete'
 * '<S186>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Integrator ICs/Internal IC'
 * '<S187>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/N Copy/Disabled wSignal Specification'
 * '<S188>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/N Gain/Disabled'
 * '<S189>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/P Copy/Disabled'
 * '<S190>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Parallel P Gain/Internal Parameters'
 * '<S191>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Reset Signal/Disabled'
 * '<S192>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Saturation/Enabled'
 * '<S193>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Saturation Fdbk/Disabled'
 * '<S194>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Sum/Sum_PI'
 * '<S195>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Sum Fdbk/Disabled'
 * '<S196>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Tracking Mode/Disabled'
 * '<S197>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Tracking Mode Sum/Passthrough'
 * '<S198>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Tsamp - Integral/TsSignalSpecification'
 * '<S199>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/Tsamp - Ngain/Passthrough'
 * '<S200>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/postSat Signal/Forward_Path'
 * '<S201>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/preInt Signal/Internal PreInt'
 * '<S202>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Position_Control/Position_Control/preSat Signal/Forward_Path'
 * '<S203>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control'
 * '<S204>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Anti-windup'
 * '<S205>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/D Gain'
 * '<S206>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/External Derivative'
 * '<S207>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Filter'
 * '<S208>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Filter ICs'
 * '<S209>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/I Gain'
 * '<S210>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Ideal P Gain'
 * '<S211>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Ideal P Gain Fdbk'
 * '<S212>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Integrator'
 * '<S213>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Integrator ICs'
 * '<S214>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/N Copy'
 * '<S215>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/N Gain'
 * '<S216>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/P Copy'
 * '<S217>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Parallel P Gain'
 * '<S218>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Reset Signal'
 * '<S219>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Saturation'
 * '<S220>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Saturation Fdbk'
 * '<S221>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Sum'
 * '<S222>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Sum Fdbk'
 * '<S223>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Tracking Mode'
 * '<S224>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Tracking Mode Sum'
 * '<S225>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Tsamp - Integral'
 * '<S226>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Tsamp - Ngain'
 * '<S227>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/postSat Signal'
 * '<S228>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/preInt Signal'
 * '<S229>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/preSat Signal'
 * '<S230>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Anti-windup/Disc. Clamping Parallel'
 * '<S231>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S232>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S233>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/D Gain/Disabled'
 * '<S234>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/External Derivative/Disabled'
 * '<S235>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Filter/Disabled'
 * '<S236>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Filter ICs/Disabled'
 * '<S237>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/I Gain/Internal Parameters'
 * '<S238>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Ideal P Gain/Passthrough'
 * '<S239>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Ideal P Gain Fdbk/Disabled'
 * '<S240>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Integrator/Discrete'
 * '<S241>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Integrator ICs/Internal IC'
 * '<S242>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/N Copy/Disabled wSignal Specification'
 * '<S243>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/N Gain/Disabled'
 * '<S244>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/P Copy/Disabled'
 * '<S245>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Parallel P Gain/Internal Parameters'
 * '<S246>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Reset Signal/Disabled'
 * '<S247>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Saturation/Enabled'
 * '<S248>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Saturation Fdbk/Disabled'
 * '<S249>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Sum/Sum_PI'
 * '<S250>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Sum Fdbk/Disabled'
 * '<S251>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Tracking Mode/Disabled'
 * '<S252>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Tracking Mode Sum/Passthrough'
 * '<S253>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Tsamp - Integral/TsSignalSpecification'
 * '<S254>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/Tsamp - Ngain/Passthrough'
 * '<S255>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/postSat Signal/Forward_Path'
 * '<S256>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/preInt Signal/Internal PreInt'
 * '<S257>' : 'PMSMController/Motor_Control/Field_Oriented_Controller/Velocity_Control/Rotor_Speed_Control/preSat Signal/Forward_Path'
 * '<S258>' : 'PMSMController/Motor_Control/Phase_Voltages_to_PWM_Compare_Values/Enumerated_Constant'
 * '<S259>' : 'PMSMController/Motor_Control/Sensors_To_Engineering_Units/ADC_Level_to_Phase_Current'
 * '<S260>' : 'PMSMController/Motor_Control/Sensors_To_Engineering_Units/Encoder_To_Position'
 * '<S261>' : 'PMSMController/Motor_Control/Sensors_To_Engineering_Units/Position_To_Velocity'
 * '<S262>' : 'PMSMController/Motor_Control/Sensors_To_Engineering_Units/Startup_Open_Loop_Control'
 * '<S263>' : 'PMSMController/Motor_Control/Sensors_To_Engineering_Units/Encoder_To_Position/Wait_For_Valid_Position'
 * '<S264>' : 'PMSMController/Motor_Control/Sensors_To_Engineering_Units/Position_To_Velocity/Implicit_Integer_Wrap_With_Error'
 * '<S265>' : 'PMSMController/Motor_Control/Sensors_To_Engineering_Units/Position_To_Velocity/Implicit_Integer_Wrap_With_Error/Detect_Velocity_Error'
 * '<S266>' : 'PMSMController/Motor_Control/Sensors_To_Engineering_Units/Position_To_Velocity/Implicit_Integer_Wrap_With_Error/Detect_Velocity_Error/Enumerated_Constant'
 * '<S267>' : 'PMSMController/Motor_Control/Sensors_To_Engineering_Units/Position_To_Velocity/Implicit_Integer_Wrap_With_Error/Detect_Velocity_Error/Generate_Error'
 * '<S268>' : 'PMSMController/Motor_Control/Sensors_To_Engineering_Units/Position_To_Velocity/Implicit_Integer_Wrap_With_Error/Detect_Velocity_Error/Generate_Error/Enumerated_Constant'
 * '<S269>' : 'PMSMController/Motor_Control/Sensors_To_Engineering_Units/Startup_Open_Loop_Control/Enumerated Constant'
 * '<S270>' : 'PMSMController/Motor_Control/Sensors_To_Engineering_Units/Startup_Open_Loop_Control/Open Loop Position'
 */

/*-
 * Requirements for '<Root>': PMSMController

 */
#endif                                 /* PMSMController_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
