//Program that generates 80% DC PWM signal
//(80% of duty cycle on high and 20% of duty cycle on low)
//The signal has a frequency of 5kHz on the 5 leg of port B
//The program is executed using interrupts without the use of library functions


sbit output at RB5_bit;
int cnt = 0;

void interrupt() {
	if(TMR0IF_bit) {
		if(cnt < 4) {
			output = 1;
		}
		if(cnt == 4) {
			output = 0;
			cnt = 0;
		}
		cnt++;
     }
     TMR0IF_bit = 0;
}

void main(){
	TRISB = 0;
	ANSELB = 0;
	PORTB = 0;
	T0CON = 0b11000010;
	INTCON = 0b10100000;
	while(1);
}
