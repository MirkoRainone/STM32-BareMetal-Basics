# 04 - STM32 Bare-Metal LED Controller & State Machine

## Overview
This project demonstrates a fully bare-metal C application for the STM32 Cortex-M series microcontrollers. It features a custom bootloader, direct memory-mapped register manipulation, and a basic state machine controlled by a physical push-button with software debouncing.

## Features
* **100% Bare-Metal:** No HAL, CMSIS, or STM32Cube IDE generated code. Even the Vector Table and `Reset_Handler` are implemented manually in C.
* **Software Debouncing:** Implements a robust non-interrupt based polling method to filter out physical button bounces on press and release.
* **State Machine:** Uses a `switch-case` architecture to toggle between 3 different operational modes.

## Hardware Configuration
This code is written for an STM32 series (e.g., STM32F4xx) with the following GPIO mapping:
* **Outputs (LEDs):** `PA0`, `PA1`, `PA2`, `PA3`
* **Input (Button):** `PA5` (Active-High configuration assumed)

## Operating Modes
Pressing the button on `PA5` cycles through the following modes:
* **Mode 0:** All LEDs OFF.
* **Mode 1:** All LEDs ON.
* **Mode 2:** LED Chaser (Animation scrolling from PA0 to PA3).

## Technical Notes
* **Memory Addresses:** The code directly accesses the AHB1 Peripheral Clock Register (`RCC_AHB1ENR`), GPIOA Mode Register (`GPIOA_MODER`), Output Data Register (`GPIOA_ODR`), and Input Data Register (`GPIOA_IDR`).
* **Blocking Delays:** The `simple_delay()` function uses empty `while` loops to waste CPU cycles. *Note: While in Mode 2, button inputs are ignored until the current LED animation cycle is fully completed due to the blocking nature of the delay.*