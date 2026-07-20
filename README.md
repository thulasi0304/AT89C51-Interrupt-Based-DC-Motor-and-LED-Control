# AT89C51 Interrupt-Based DC Motor and LED Control

## Description
This project demonstrates the use of multiple interrupts in the AT89C51 microcontroller. External Interrupt 0 (INT0) is used to control the operating state of a DC motor, while Timer0 Interrupt is used to blink two LEDs at a fixed time interval. The project illustrates interrupt-driven programming by executing multiple tasks independently.

## Features
- Uses External Interrupt 0 (INT0) for DC motor control
- Uses Timer0 Interrupt for LED blinking
- DC motor operates in Forward, Stop, and Reverse modes
- LEDs blink automatically using Timer0 interrupt
- Embedded C implementation
- Proteus simulation

## Hardware Required
- AT89C51 Microcontroller
- L293D Motor Driver IC
- DC Motor
- 2 LEDs
- Push Button

## Software Required
- Keil µVision
- Proteus 8 Professional

## Pin Connections

### DC Motor
- IN1 → P2.0
- IN2 → P2.1
- EN1 → P2.2

### LEDs
- LED1 → P3.0
- LED2 → P3.1

### External Interrupt
- Push Button → P3.2 (INT0)

## Working
1. When the system is powered ON, the DC motor starts rotating in the forward direction.
2. Each press of the push button connected to INT0 changes the motor state in the following sequence:
   - Forward
   - Stop
   - Reverse
   - stop
   - Forward (repeats)
3. Timer0 generates periodic interrupts to blink LED1 and LED2 automatically.
4. The motor control and LED blinking operate independently using interrupts.

## Applications
- DC Motor Direction Control
- Interrupt-Based Embedded Systems
- Industrial Automation
- Robotics
- Embedded Systems Learning
- AT89C51 Programming Practice
