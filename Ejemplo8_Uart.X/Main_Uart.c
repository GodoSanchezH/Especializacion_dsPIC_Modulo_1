/* 
 * File:   Main_Uart.c
 * Author: LENOVO
 *
 * Created on 11 de octubre de 2021, 08:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Configuracion.h"
#include <libpic30.h>
#include <p33FJ32MC202.h>
#include "Uart_dspic.h"
#include "ADC_dspic.h"
/*
 * 
 */
uint16_t a1,a2,a3,a4,a5,a6;

void __attribute__((interrupt,no_auto_psv)) _U1RXInterrupt(void){
    char ch;
    if(U1STAbits.OERR == 1){
        U1STAbits.OERR  = 0;
    }else if((U1STAbits.FERR == 0) && (U1STAbits.PERR == 0)){
    
        ch = U1RXREG;
    }
    
    switch(ch){
    
        case '*':
            
             printf("%u;%u;%u",a1,a2,a3);
            break;
        case 'A':
            
            LATB |= (1<<12);
            
            break;    
        case 'B':
            
            LATB &= ~(1<<12);
            
            break;          
        case 'C':
            
            LATB |= (1<<13);
            
            break;          
        case 'D':
            
            LATB &= ~(1<<13);
            
            break;          
        case 'E':
            
            LATB |= (1<<14);
            
            break;          
        case 'F':
            
            LATB &= ~(1<<14);
            
            break;          
        case 'G':
            
            LATB |= (1<<15);
            
            break;        
        case 'H':
            
            LATB &= ~(1<<15);
            
            break;          
    
    }
    
    
IFS0bits.U1RXIF = 0;//limpiamos el flag
}


int main(int argc, char** argv) {
    Analog_Init(Modo_10bits);
    UART_dsPIC_Init(9600,one_bit_Stop,Ocho_D_SP,1);
    ADPCFG &= ~(1<<0) & ~(1<<1) & ~(1<<2 ) & ~(1<<3) & ~(1<<4) & ~(1<<5);//habilitadas mis entradas analogicas
    TRISA |= (1<<0) | (1<<1);
    TRISB |= (1<<0) | (1<<1) | (1<<2) | (1<<3) ;
    TRISB &= ~(1<<15) & ~(1<<14)& ~(1<<13)& ~(1<<12);//ENTRADAS DIGITALES
    
    for(;;){
//        UART_Tx_Char('G');
//        UART_Tx_String("****Bienvenidos***\n\r");
//        UART_Tx_String("a la Especializacion\n\r");
//        UART_Tx_String("de dsPIC\n\r");
//        UART_Tx_String("****MUCHAS GRACIAS*****\n\r");
        
//        printf("****Bienvenidos***\n\r");
//        printf("a la Especializacion\n\r");
//        printf("de dsPIC\n\r");
//        printf("****MUCHAS GRACIAS*****\n\r");

        a1 = AnalogRead(AN0);
        a2 = AnalogRead(AN1);
        a3 = AnalogRead(AN2);
     //printf("%u;%u;%u",a1,a2,a3);
     //   __delay_ms(250);
    
    }
    
    
    return (EXIT_SUCCESS);
}

