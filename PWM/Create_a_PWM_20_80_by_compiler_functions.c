//Program that generates 80% DC PWM signal
//(80% of cycle time on high and 20% of cycle time on low)
//The program is executed using the PWM's built-in commands from the compiler's function library


void main() {
	LATC = TRISC = ANSELC = 0;
	PWM1_Init(1953);
	PWM1_Set_Duty(204);
	PWM1_Start();
}
