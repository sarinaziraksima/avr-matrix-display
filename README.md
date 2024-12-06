# AVR matrix display

On this projects, we used Atmel Studio to program the Atmega32 microcontroller, and we tested their functionality with Proteus.
This program has three modes:
- Mode 00: It turns on the selected LEDs of the matrix display using an x input button and a y input button.
- Mode 01: After selecting all the LEDs, you can use this mode to check if a column or a row of the matrix display is on or off. If that’s the case, the LEDs will start to flash.
- Mode 10: This mode checks if there is a path from the first row to the last one.

On the programming side, obtaining parallel data, converting it into an array, adjusting it, and finally converting it to a byte for each row were the main tasks that operated very smoothly at a frequency of 8 MHz in the simulation on Proteus (with no blinking). Debugging this project was a unique experience, as each line of code was simplified to ensure that the desired functionality was met before finalizing the comprehensive system.
