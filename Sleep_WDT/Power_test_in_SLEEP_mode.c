//A program that checks the low power consumption of the controller during SLEEP mode


void main() {
	TRISB = 0b00000000;
	TRISA = 0b00100000;
	ANSELA = ANSELB = 0;
	do {
		asm sleep;          // Sleep mode, WDT is cleared,
		                    // Current is minimum in Sleep mode
		LATB = 255;
		Delay_ms(1500);		// After wake-up the LED is turned on Delay_ms(500);
		LATB = 0;
		asm CLRWDT;         // Clear WDT
		Delay_ms(2000);     // Measure current here and compare with Sleep mode
    }
	while (1);
}
