# FOC BLDC Motor Controller - Hardware Pin Configuration

## STM32F411CEU6 Black Pill Pin Assignments

### PWM Outputs (for MOSFET Gate Drivers)
- PA8: PWM1 (Phase A High)
- PA9: PWM2 (Phase B High)
- PA10: PWM3 (Phase C High)
- PB13: PWM4 (Phase A Low)
- PB14: PWM5 (Phase B Low)
- PB15: PWM6 (Phase C Low)

### Hall Sensors (Digital Inputs)
- PA0: Hall Sensor A
- PA1: Hall Sensor B
- PA2: Hall Sensor C

### Current Sensors (ADC Inputs)
- PA4: Phase A Current (ADC1_CH4)
- PA5: Phase B Current (ADC1_CH5)

### UART for Debugging
- PA2: TX (Serial output)
- PA3: RX (Serial input)

### Power Supply
- GND: Ground (common return)
- 3.3V: Microcontroller power
- 12V: Motor inverter supply

## Soldering Checklist
- [ ] All GPIO pins soldered
- [ ] PWM pins (PA8-PA10, PB13-PB15) confirmed
- [ ] Hall sensor pins (PA0-PA2) confirmed
- [ ] ADC pins (PA4-PA5) confirmed
- [ ] Power pins soldered
- [ ] Test with multimeter for continuity

## Next: Configure in STM32CubeMX
Once soldered, configure these pins in STM32CubeMX.