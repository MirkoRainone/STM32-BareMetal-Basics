# ⚡ STM32 Bare-Metal Basics

This repository documents my learning journey into Bare-Metal programming on STM32 microcontrollers. 
No external libraries (such as HAL or standard peripheral libraries) are used. The hardware is controlled by directly mapping physical memory registers and using bitwise operators in pure C.

## 📂 Learning Path

* [**01 - Button LED Mirror**](./01-Button-LED-Mirror/) : Direct I/O manipulation.
* [**02 - Button Toggle**](./02-Button-Toggle/) : State logic, handling loop speed, and bit toggling.

## 🛠️ Hardware & Environment
* **Target Board:** STM32 Nucleo-F401RE
* **Language:** Pure C (`<stdint.h>`)
* **Core Concepts:** Clock Configuration (RCC), GPIO Direction (MODER), Output Data (ODR), and Input Data (IDR).