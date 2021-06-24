//A program that turns on a LED when it's dark outside
//The analog reading is performed using an LDR sensor


unsigned tmp;
sbit LED at RB0_bit;

void main() {
     PORTA = PORTB = 0;
     TRISA = 0xFF;
     TRISB = 0;
     ANSELB = 0;
     ANSELA = 255;
     
     while(1) {
              ADC_Init();
              tmp = ADC_Read(1);
              if(tmp < 20) {
                       LED = 1;
              }
              else {
                   LED = 0;
              }
     }
}
