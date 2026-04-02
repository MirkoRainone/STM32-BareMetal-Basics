#include <stdint.h>

// --- Memory Mapping (Base Addresses + Offsets) ---

// RCC (Reset and Clock Control) - AHB1 Enable Register
#define RCC_AHB1ENR (*(volatile uint32_t *)0x40023830)

// GPIOA Registers
#define GPIOA_MODER (*(volatile uint32_t *)0x40020000) // Mode Register (Input/Output)
#define GPIOA_ODR   (*(volatile uint32_t *)0x40020014) // Output Data Register (High/Low)

// --- Functions ---

// A simple blocking delay function using a volatile counter
void simple_delay(volatile uint32_t time_delay) {
    while (time_delay > 0) {
        time_delay--; // The processor wastes cycles counting backwards
    }
}

// --- Main Program ---

int main(void) {

    // 1. Enable Clock for GPIOA (Bit 0)
    RCC_AHB1ENR |= (1 << 0);

    // 2. Configure PA0, PA1, PA2, PA3 as General Purpose Output (01)
    // Clear the first 8 bits (4 pins * 2 bits each) using hex mask 0xFF (11111111)
    GPIOA_MODER &= ~(0xFF << 0);
    // Set the output mode (01) for the 4 pins using hex mask 0x55 (01010101)
    GPIOA_MODER |= (0x55 << 0);

    // 3. Infinite Loop (LED Chaser Logic)
    while(1) {
        // Iterate through pins 0 to 3
        for(int i = 0; i < 4; i++) {

            // Turn ON the current LED by setting the i-th bit to 1
            GPIOA_ODR |= (1 << i);

            // Wait to make the LED state visible to the human eye
            simple_delay(500000);

            // Turn OFF the current LED by clearing the i-th bit to 0
            GPIOA_ODR &= ~(1 << i);
        }
    }
}
