//A program that controls the speed of the motor using a potentiometer


int tmp;

void main() {
     TRISA = 255;
     TRISB = 0b00000001;
     ANSELA = 255;
     TRISC = 0;
     ANSELC = 0;
     ADC_Init();
     UART1_Init(9600);
     delay_ms(10);
     PWM2_Init(5000);
     delay_ms(10);
     PWM2_Start();
     while(1) {
              tmp = ADC_Read(0) >> 2;
              UART1_Write(tmp);
              PWM2_Set_Duty(tmp);
     }
}
