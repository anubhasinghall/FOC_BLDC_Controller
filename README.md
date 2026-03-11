# FOC BLDC Motor Controller
Implementation of **Field-Oriented Control (FOC)** for a BLDC/PMSM motor using a **Model-Based Design workflow**.
The controller is designed in **Simulink**, automatically converted to **C code using Embedded Coder**, and deployed to an **STM32 microcontroller** using **STM32CubeIDE**.

## Project Workflow
Simulink Model → Embedded C Code Generation → STM32 Firmware → Hardware Testing → Motor Control

## Current Status
* Simulink controller model implemented
* System simulation model completed
* C code generated from Simulink
* STM32CubeIDE firmware project builds successfully
* Preparing for hardware testing with inverter and PMSM motor

## Repository Structure
Simulink_Model/
Contains the Simulink design files used for controller development and system simulation.

Generated_Code/
Auto-generated embedded C code produced by Simulink Embedded Coder.

STM32_Project/
STM32CubeIDE project used to compile and flash firmware to the microcontroller.

documentation/
Hardware wiring, pin configuration, and setup instructions.

## Simulink Models
PMSMController.slx
Controller model used for **code generation and embedded implementation**.

PMSMSystem.slx
Full simulation model including **controller, inverter, and motor plant** for testing and validation.

## Hardware Platform
Microcontroller: STM32
Motor Type: PMSM / BLDC
Control Strategy: Field-Oriented Control (FOC)
PWM Generation: Simple PWM

## Control Architecture

Speed Reference
↓
Speed Controller (PI)
↓
Current Controllers (Id / Iq PI)
↓
Clarke Transform
↓
Park Transform
↓
SVPWM Generation
↓
Three-Phase Inverter
↓
PMSM Motor

## Development Tools
* MATLAB / Simulink
* Simulink Embedded Coder
* STM32CubeIDE
* Git & GitHub

## Hardware Setup

### Pin Connections

See [HARDWARE_CONNECTIONS.md](HARDWARE_CONNECTIONS.md) for detailed mapping.

### Implementation Timeline

- **Days 1-2:** Power supply & gate driver circuit
- **Days 3-4:** Component testing (without motor)
- **Days 5-6:** Motor integration & full system test
- **Day 7:** Demo video & final documentation

### Project Status

- ✅ Simulink FOC model (Clarke-Park transforms, PI control)
- ✅ C code auto-generated (Embedded Coder)
- ✅ STM32F411 firmware compiled & flashed
- 🔄 Hardware assembly in progress
- ⏳ Motor testing (components arriving 3-5 days)

## Author
Anubha Singhal
Electrical Engineering, Aligarh Muslim University
