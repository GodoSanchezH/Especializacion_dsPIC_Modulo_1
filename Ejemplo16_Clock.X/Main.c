/* 
 * File:   Main.c
 * Author: lenovo
 *
 * Created on October 29, 2021, 10:26 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Config.h"
#include <libpic30.h>
#include <xc.h>

void __attribute__((interrupt,no_auto_psv)) _T1Interrupt(void){
    LATB ^= (1<<7)  ;
    //uart_sent_gsm
    IFS0bits.T1IF = 0;//limpiamos flag
}


/*
 * 
 */
int main(int argc, char** argv) {
        TRISB &= ~(1<<7)  ;
        CLKDIVbits.FRCDIV = 0;//divide entre 1
        OSCTUNbits.TUN  = 21;
//        PLLFBDbits.PLLDIV = 16;//M= 18
//        CLKDIVbits.PLLPOST = 0; //N2=2
//        CLKDIVbits.PLLPRE0 = 0;//N1=2
        
//        
//    //temporizacion timer
//            T1CONbits.TON = 0;//apagamos el timer    
//            T1CONbits.TCS = 0;//Activo el modo Temporizadoor
//            T1CONbits.TGATE = 0;// Desactivo el Gate
//            /*
//             * 0.05uS = 
//             * PR1 = 5MHz * 50ms
//             */
//            T1CONbits.TCKPS = 2;//preescaler1:64
//            
//            PR1 = 35155; //-> Valor para 50 ms a 5Mhz
//            TMR1 = 0x0000;//INICIE SIN CARGA
//            IEC0bits.T1IE = 1;//Habilitamos interrupcion por desbordamiento
//            IFS0bits.T1IF = 0;//limpiamos flag
//            IPC0bits.T1IP = 1;//Prioridad 1
//            T1CONbits.TON = 1;//Enciende Time
    for(;;){
    
    
    LATB ^= (1<<7)  ;
    __delay_ms(200);
    
    
    }
    
    
    
    return (EXIT_SUCCESS);
}

