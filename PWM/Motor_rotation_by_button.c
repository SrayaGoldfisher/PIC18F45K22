//A program that rotates the engine to the right or left by pressing a push button


sbit push_button at RB5_bit;
int flag;
void interrupt () {
     if(push_button) {
         flag =~ flag;
     }
     RBIF_bit = 0;
}
void main () {
     ANSELB = ANSELC = 0;
     TRISB = 0xFF;
     TRISC = 0;
     PORTC = 0;
     INTCON=0b10001000;
     IOCB5_bit = 1;
     PWM1_Init(5000);
     PWM1_Set_Duty(127);
     PWM2_Init(5000);
     PWM2_Set_Duty(127);
     while(1) {
         if(flag) {
             PWM1_Stop();
             PWM2_Start();
         }
         if(!flag) {
              PWM2_Stop();
              PWM1_Start();
         }
     }
}
