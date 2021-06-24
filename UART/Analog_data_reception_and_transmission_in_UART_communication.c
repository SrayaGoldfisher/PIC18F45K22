//Program for receiving analog information from an LDR sensor
//The data from the sensor is sent via UART serial communication to the compiler / proteus terminal screen


int tmp;

void main() {

     TRISA = 0xFF;
     ANSELA - 0xFF;
     ANSELC = 0;
     
     ADC_Init();
     Delay_ms(100);
     UART1_Init(9600);
     Delay_ms(100);
     UART1_Write_Text("start");
     while(1) {
              tmp = (ADC_Read(0)) >> 2;
              UART1_Write(tmp);
              Delay_ms(1000);
     }
}
