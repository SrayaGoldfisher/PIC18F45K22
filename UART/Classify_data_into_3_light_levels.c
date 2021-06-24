//Program for receiving analog information from an LDR sensor
//The data from the sensor is sent via UART serial communication to the compiler / forteus terminal screen
//The terminal screen will display 3 possible light levels (very bright, medium, very dark)


int tmp;

void main() {

     PORTA = 0;
     TRISA  = 0xFF;
     ANSELA - 0xFF;
     ANSELB = ANSELC = 0;

     ADC_Init();
     Delay_ms(50);
     UART1_Init(9600);
     Delay_ms(100);
     UART1_Write_text("START");
     while(1) {
              tmp = (ADC_Read(0));
              if(tmp > 680) {
                     UART1_Write_text("strong-light  ");
              }
              if(tmp > 340 && tmp < 680) {
                     UART1_Write_text("middle-light  ");
              }
              if(tmp < 340) {
                     UART1_Write_text("dark  ");
              }
              Delay_ms(1000);
     }
}
