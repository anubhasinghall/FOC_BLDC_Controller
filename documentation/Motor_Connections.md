# Motor Connections Guide

## BLDC Motor Wiring

### 3-Phase Power Connections
Connect motor phase wires to inverter outputs:
- Motor Phase A → Inverter Phase A Output
- Motor Phase B → Inverter Phase B Output
- Motor Phase C → Inverter Phase C Output

### Hall Sensor Connections
Motor has 3 Hall sensors (usually red, green, black wires):
- Hall A → PA0 (STM32)
- Hall B → PA1 (STM32)
- Hall C → PA2 (STM32)
- GND → GND (common)
- 5V (optional) → 3.3V from STM32

### Current Sensing
ACS712 current sensors (if using):
- Phase A current sensor → PA4
- Phase B current sensor → PA5

## Power Supply Connections
- 12V positive → Inverter VCC
- GND → Inverter GND, STM32 GND, Motor GND (all common)

## Safety Checklist BEFORE POWERING
- [ ] All connections double-checked
- [ ] No exposed solder joints
- [ ] No short circuits with multimeter
- [ ] Motor not mechanically stuck
- [ ] Current limit set on power supply