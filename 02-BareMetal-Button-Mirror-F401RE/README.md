# 💡 02 - Button LED Mirror

## 🎯 Objective
This project implements a hardware "mirror" effect. The microcontroller continuously reads the physical state of a push-button and instantly mirrors its state to an LED. 
- **Button Pressed:** LED turns ON.
- **Button Released:** LED turns OFF.

## 🔌 Hardware Setup
* **Button:** Connected to Port B, Pin 3 (`PB3`).
* **LED:** Connected to Port A, Pin 7 (`PA7`).
*(Note: Base addresses might need to be adjusted depending on the specific STM32 family used).*

## 🧠 Bare-Metal Concepts Explored
This exercise demonstrates pure direct I/O manipulation without using any HAL or external libraries. The hardware is controlled directly via memory-mapped registers:

1. **Clock Enabling (`RCC_AHB1ENR`):** Powering up both the GPIOA and GPIOB peripherals on the AHB1 bus.
2. **Pin Configuration (`GPIOx_MODER`):** * Clearing and setting `PB3` as Input (`00`).
   * Clearing and setting `PA7` as General Purpose Output (`01`).
3. **Input Polling (`GPIOx_IDR`):** Reading the Input Data Register using the bitwise `&` (AND) mask to safely isolate the 3rd bit.
4. **Output Driving (`GPIOx_ODR`):** * Using `|=` (OR) to set the 7th bit to `1` (Output High / 3.3V).
   * Using `&= ~` (AND NOT) to safely clear the 7th bit to `0` (Output Low / 0V) without affecting the state of other adjacent pins.

## 💻 Core Logic Snippet
```c
while(1) {
    // If PB3 is receiving voltage (button pressed)
    if (GPIOB_IDR & (1 << 3)) {
        GPIOA_ODR |= (1 << 7);    // Turn on PA7 LED
    } 
    // If PB3 is not receiving voltage (button released)
    else { 
        GPIOA_ODR &= ~(1 << 7);   // Turn off PA7 LED
    }
}
