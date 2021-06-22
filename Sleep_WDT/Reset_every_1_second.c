//A program that puts the controller in reset mode every 1sec using the WDT module in an infinite loop


void main() {
	ANSELD = 0;
	LATD = 0;
	TRISD = 0;
	WDTCON.SWDTEN = 1;     //turn on WDT, prescaler initialized as 128,postscaler 256, due to: t=1(s)=(1/31K)*128*POSTCALER=1.057sec
	PORTD = 0b11111111;
	Delay_ms(400);
	PORTD = 0;
}
