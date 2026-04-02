#include <stdint.h>

// RCC Register (Reset and Clock Control): Manages power/clocking of the chip
#define RCC_AHB1ENR (*(volatile uint32_t *)0x40023830)

// --- Memory Mapping ---
#define GPIOB_MODER (*(volatile uint32_t *)0x40020400) // MODER Port B
#define GPIOB_IDR   (*(volatile uint32_t *)0x40020410) // IDR Port B (Input)
#define GPIOA_MODER (*(volatile uint32_t *)0x40020000) // MODER Port A
#define GPIOA_ODR   (*(volatile uint32_t *)0x40020014) // ODR Port A (Output)

// A simple blocking delay function
void simple_delay(volatile uint32_t time_delay) {
    while (time_delay > 0) {
        time_delay--; // The processor counts backwards and "wastes time"
    }
}

int main(void) {

    // 1. Enable clock for the first two bits (Port A and Port B)
    // 3 in decimal is '11' in binary, activating bit 0 and bit 1 simultaneously
    RCC_AHB1ENR |= (3 << 0);

    // 2. Configure Pin 3 on Port B (PB3) as Input
    // Clear bits 6 and 7 to set the mode to '00' (Input mode)
    GPIOB_MODER &= ~(3 << 6);

    // 3. Configure Pin 7 on Port A (PA7) as Output
    // Clear bits 14 and 15 for PA7
    GPIOA_MODER &= ~(3 << 14);
    // Set bit 14 to '1' to configure it as General Purpose Output ('01')
    GPIOA_MODER |= (1 << 14);

    // 4. Infinite Loop (Button Mirror Logic)
    while(1) {

        // If the 3rd bit of Port B is HIGH (Button is pressed)
        if (GPIOB_IDR & (1 << 3)) {
            // Turn ON the LED on PA7
            GPIOA_ODR |= (1 << 7);
        }
        // If the button is released
        else {
            // Turn OFF the LED on PA7 safely using AND NOT mask
            GPIOA_ODR &= ~(1 << 7);
        }
    }
}
