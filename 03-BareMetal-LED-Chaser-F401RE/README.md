# 🏎️ 03 - LED Chaser (Knight Rider Effect)

## 🎯 Objective
This project implements a dynamic "chaser" light sequence (also known as the Knight Rider or Larson Scanner effect). It cycles through 4 LEDs in a continuous loop, turning them on and off sequentially to create a moving light illusion.

## 🔌 Hardware Setup
* **LEDs:** 4 LEDs connected to Port A, Pins 0, 1, 2, and 3 (`PA0`, `PA1`, `PA2`, `PA3`).
*(Note: Base addresses might need to be adjusted depending on your specific STM32 microcontroller).*

## 🧠 Bare-Metal Concepts Explored
This exercise marks the transition from static pin manipulation to dynamic logic using C loops and advanced bitwise operations:

1. **Hexadecimal Masks for Multiple Pins:** Instead of configuring each pin individually, hexadecimal masks are used to configure 4 pins simultaneously. 
   * `~0xFF` clears the first 8 bits of the `MODER` register.
   * `0x55` (which is `01010101` in binary) configures `PA0` to `PA3` as General Purpose Outputs in a single instruction.
2. **Dynamic Bit Shifting:** Using a variable inside a `for` loop (`1 << i`) to dynamically target different bits of the Output Data Register (`ODR`) rather than hardcoding static values.
3. **Blocking Delays & `volatile`:** Implementing a software delay loop. The `volatile` keyword ensures that the compiler does not optimize away the empty counting loop.

## 💻 Core Logic Snippet
```c
while(1) {
    // Iterate through pins 0 to 3
    for(int i = 0; i < 4; i++) {
        
        GPIOA_ODR |= (1 << i);    // Turn ON the current LED
        
        simple_delay(500000);     // Wait for visibility
        
        GPIOA_ODR &= ~(1 << i);   // Turn OFF the current LED
    }
}