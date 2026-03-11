# Hardware Connections

## Pin Mapping

| Component | STM32 Pin / Connection | Function |
|-----------|----------------------|----------|
| IR2104 Phase A IN | PA8 | PWM Input |
| IR2104 Phase A HO | Q1 Gate | High-Side MOSFET |
| IR2104 Phase A LO | Q4 Gate | Low-Side MOSFET |
| IR2104 Phase B IN | PA9 | PWM Input |
| IR2104 Phase B HO | Q2 Gate | High-Side MOSFET |
| IR2104 Phase B LO | Q5 Gate | Low-Side MOSFET |
| IR2104 Phase C IN | PA10 | PWM Input |
| IR2104 Phase C HO | Q3 Gate | High-Side MOSFET |
| IR2104 Phase C LO | Q6 Gate | Low-Side MOSFET |
| Hall Sensor A | PA0 | Motor Commutation |
| Hall Sensor B | PA1 | Motor Commutation |
| Hall Sensor C | PA2 | Motor Commutation |
| Current Sensor A | PA4 | ADC Phase Current |
| Current Sensor B | PA5 | ADC Phase Current |
| 24V SMPS | - | Power Supply |
| Ground | GND | Common Return |

## Hardware Components

### Power Supply
- 24V 5A SMPS

### Motor Inverter
- 6x IRF540N MOSFETs
- 3x IR2104 Gate Drivers
- 6x 1N4007 Freewheeling Diodes
- 1000µF Filtering Capacitor
- 5A Fuse

### Motor
- 24V BLDC with Hall Sensors
- 3 Phase Wires (U, V, W)
- 3 Hall Sensor Wires (A, B, C)

### Sensing
- 2x ACS712 Current Sensors
- STM32F411 ADC inputs
