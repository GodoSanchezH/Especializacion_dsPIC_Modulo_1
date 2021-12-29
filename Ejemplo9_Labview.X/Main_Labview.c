/* 
 * File:   Main_Labview.c
 * Author: LENOVO
 *
 * Created on 15 de octubre de 2021, 07:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Configuracion.h"
#include <libpic30.h>
#include "Uart_dspic.h"
#include "ADC_dspic.h"
#include <string.h>
#include <xc.h>

uint16_t dato1,dato2,dato3;

int main(int argc, char** argv) {
    ADPCFG &= ~(1<<0) & ~(1<<1) & ~(1<<2 ) ;//habilitadas mis entradas analogicas
    TRISA |= (1<<0) | (1<<1);
    TRISB |= (1<<0);
    Analog_Init(Modo_10bits);   
    UART_dsPIC_Init(9600,one_bit_Stop,Ocho_D_SP,1);
    

    //A0 ,A1 ,B0
    
    for(;;){
        dato1 = AnalogRead(AN0);
        dato2 = AnalogRead(AN1);
        dato3 = AnalogRead(AN2);
        
        printf("%u;%u;%u\n\r",dato1,dato2,dato3);
        __delay_ms(200);
    }
    
    return (EXIT_SUCCESS);
}

