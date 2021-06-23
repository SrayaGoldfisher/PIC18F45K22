void main() {
	LATC = TRISC = ANSELC = 0;
	PWM1_Init(491);
	PWM1_Set_Duty(204);
	PWM1_Start();
}