#include "Interrupciones.h"
#include <xc.h>

void Interrupcion_Externa(uint8_t INTX,bool Flanco,uint8_t Prioridad){

    switch(INTX){
        case INT0:
            IEC0bits.INT0IE = 1;//Habilito el INT0
            IPC0bits.INT0IP = Prioridad;//prioridad 1
            IFS0bits.INT0IF = 0;//limpio la bandera
            INTCON2bits.INT0EP = Flanco;//Flanco de Subida
            TRISB |= (1<<7);//Definimos como entrada al bit B7
        break;
        case INT1:
            IEC1bits.INT1IE = 1;//Habilito el INT1
            IPC5bits.INT1IP = Prioridad;//prioridad 2
            IFS1bits.INT1IF= 0;//limpio la bandera
            INTCON2bits.INT1EP = Flanco;//Flanco de Subida
            TRISB |= (1<<15);//Definimos como entrada al bit B15
            RPINR0bits.INT1R = 0XF;//definimos al pinRB15 como INT1
        break;

        case INT2:
            IEC1bits.INT2IE = 1;//Habilito el INT2
            IPC7bits.INT2IP = Prioridad;//prioridad 3
            IFS1bits.INT2IF = 0;//limpio la bandera
            INTCON2bits.INT2EP = Flanco;//Flanco de Subida
            TRISB |= (1<<14);//Definimos como entrada al bit B14
            RPINR1bits.INT2R = 0xE ;//definimos al pinRB14 como INT2
         break;

    }


}
