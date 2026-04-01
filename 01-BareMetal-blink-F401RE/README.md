# 01-STM32 Bare-Metal Blink 💡

A bare-metal implementation of a blinking LED on the **STM32 Nucleo-F401RE** development board, written in pure C without relying on the HAL (Hardware Abstraction Layer) libraries.

## 🎯 Objective
The goal of this project is to understand the core architecture of the ARM Cortex-M4 processor by directly manipulating hardware registers (RCC, GPIO) to control the onboard user LED (PA5).

## 🛠️ Hardware & Tools
* **Board:** STMicroelectronics NUCLEO-F401RE
* **Microcontroller:** STM32F401RET6 (ARM Cortex-M4)
* **IDE:** STM32CubeIDE
* **Language:** C

## 🧠 Core Concepts Explored
* **Memory-Mapped I/O (MMIO):** Accessing and modifying peripheral registers via pointers.
* **Bitwise Operations:** Setting and clearing specific bits to configure GPIO pins and system clock.
* **Datasheet Navigation:** Extracting memory addresses and register offsets from the official RM0368 Reference Manual.

## 🚀 How it works
The code enables the peripheral clock for GPIO Port A, configures Pin 5 as a general-purpose output, and toggles the pin state using a basic software delay loop.
