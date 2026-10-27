
# Raspberry Pi Pico USB MIDI Controller

## Overview

A personal embedded systems project using a Raspberry Pi Pico H,
C and a rotary encoder. The long-term goal is to build a custom
USB MIDI controller for Ableton Live.

I am developing the project incrementally to learn embedded C,
GPIO input handling, digital signal decoding and USB MIDI
communication.

## Current status

**Stage 1: Rotary encoder input — working**

- Read two digital signals from a rotary encoder using GPIO.
- Detect rotation direction using quadrature decoding.
- Track encoder movement using a transition table.
- Convert rotation into a value between 0 and 127.
- Display the count and value through the USB serial connection.

USB MIDI communication and Ableton integration are planned
next steps and have not yet been implemented.

## Hardware

- Raspberry Pi Pico H (RP2040)
- Rotary encoder
- Breadboard and jumper wires
- Mac development computer

## Wiring

| Encoder connection | Raspberry Pi Pico |
|---|---|
| A | GP16 |
| C (common) | GND |
| B | GP17 |

The encoder's switch contacts are not currently used.

## Software

- C
- Raspberry Pi Pico SDK
- CMake
- Visual Studio Code
- USB serial output for debugging

## What I am learning

- C programming fundamentals
- Digital inputs and GPIO
- Pull-up resistors and logic levels
- Quadrature encoder decoding
- State tracking and transition tables
- Bitwise operators
- Embedded firmware build and upload workflows
- USB MIDI communication (planned)

## Planned development

1. Improve and test encoder decoding.
2. Deepen understanding of the C implementation.
3. Configure USB MIDI output from the Pico.
4. Send MIDI Control Change messages.
5. Test the controller with Ableton Live.
6. Document testing, problems and improvements.

## Project notes

This is an ongoing learning project. Code and documentation
will be updated as features are implemented and tested.
