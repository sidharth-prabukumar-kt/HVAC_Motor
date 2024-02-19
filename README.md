# HVAC Motor Project

## Overview

This project is centered around the development of an HVAC motor using a custom-designed motor controller PCB, crafted with KiCAD. The core of the software architecture is built on Zephyr RTOS, tailored with a customized device tree for optimal performance with the STM32 microcontroller.

## Features

- **Motor Control**: Utilizes PWM lines controlled by timer peripherals, interfacing with the TI *DRV8313* motor driver to manage a three-phase motor. This setup is enhanced with feedback mechanisms through current sense resistors and ADC, alongside hall effect sensors.
- **Temperature Regulation**: Incorporates a *LM75B* temperature sensor for data acquisition via I2C, regulating a surface's temperature. This surface is heated using a filament for testing purposes, simulating a real-world application.
- **Fan Implementation**: The three-phase motor is specifically deployed to drive a fan. This fan plays a role in cooling the aforementioned surface, ensuring the system remains within operational thermal limits.
- **Control Systems**: Implements two control systems:
    - A Field Oriented Control (FOC) system, leveraging feedback from the motor for precise PID loop control.
    - A temperature maintenance system, utilizing feedback from the temperature sensor to ensure the surface temperature remains within a designated range.
