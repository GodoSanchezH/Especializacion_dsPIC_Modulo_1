#include "Uart_dspic.h"
#include "Configuracion.h"
#include <xc.h>


void UART_dsPIC_Init(uint32_t Baudios,bool Stop_bit,uint8_t Data_P ,uint8_t IPC_RX){
    TRISBbits.TRISB15=0;//pin 15 como salida
    RPOR7bits.RP15R = 3;//pin 15 como trasnmision
    
    TRISBbits.TRISB14 = 1;//pin 14 como entradqa
    RPINR18bits.U1RXR = 0XE;
    
     
    U1MODE = 0;             //LIMPIO TODA LA CONFIGURACION
    U1STA = 0;              //LIMPIO TODA LA CONFIGURACION
    
    U1MODEbits.STSEL = 0 ;//1 bit de stop
    U1MODEbits.PDSEL = 0b00;//paridad 0
     U1BRG =  (uint16_t) (FCY / 16 / Baudios)-1;//SE ESTABLECE LA VELOCIDAD DE TRANSMISION
    

    //habilitamos la tramsision
    U1STAbits.UTXEN = 1;//SE HABILITA LA TRANSMISION DE DATOS
    
    //habilitamos recepcion
    U1STAbits.URXISEL = 0;//habilitamos que recbiremos por interrupcion
    IFS0bits.U1RXIF = 0; //Limpiamos el flag
    IPC2bits.U1RXIP = 4;  //prioridad 4
    IEC0bits.U1RXIE = 1; // Enable UART Receive interrupt
    
    U1MODEbits.UARTEN = 1 ;//SE HABILITA EL MODULO UART1
}
void UART_Tx_Char(char Caracter){

    while(U1STAbits.UTXBF == 1);
    U1TXREG = Caracter;

}
void UART_Tx_String(char *str){
    char *ptr;
    ptr = str ;
    
    while(*ptr)
        UART_Tx_Char(*ptr++);
}


int    write(int handle, void *buffer, unsigned int len)
{
  int i;
   switch (handle)
  {
      case 0:        // handle 0 corresponds to stdout
      case 1:        // handle 1 corresponds to stdin
      case 2:        // handle 2 corresponds to stderr
      default:
          for (i=0; i<len; i++)
              UART_Tx_Char(*(char*)buffer++);
              
  }
  return(len);
}
