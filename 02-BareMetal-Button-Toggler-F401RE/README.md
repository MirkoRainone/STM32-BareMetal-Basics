# 🔄 02 - Button Toggle

## 🎯 Objective
A standard switch behavior: press the button once to turn the LED on, press it again to turn it off.

## 🧠 Key Concepts Covered
* **State Variables:** Using C variables to track the previous state of the button.
* **Loop Speed Handling:** Preventing the microcontroller from executing multiple toggles during a single physical button press.
* **Bit Toggling:** Using the bitwise XOR operator (`|=`) to efficiently flip the state of the ODR register.