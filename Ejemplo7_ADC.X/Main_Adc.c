/* 
 * File:   Main_Adc.c
 * Author: HP
 *
 * Created on 10 de octubre de 2021, 04:32 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Configuracion.h"
#include <libpic30.h>
#include <stdint.h>
#include "LCD_dspic.h"
#include "ADC_dspic.h"
#include "Timer_dsPIC.h"

uint16_t a1,a2,a3,a4,a5,a6;
char str_a1[5],str_a2[5],str_a3[5],str_a4[5],str_a5[5],str_a6[5];

void __attribute__((interrupt,no_auto_psv)) _T3Interrupt(void){

    
    a1 = AnalogRead(AN0);
    IFS0bits.T3IF = 0;//limpiamos flag
}

int main(int argc, char** argv) {
    
    
    LCD_dsPIC_Init();
    Analog_Init(Modo_10bits);
    Timer_Temporizador(Timer3,0,0.001,64);
    LCD_dsPIC_SetCursor(0,FILA1);
    LCD_dsPIC_Print_String("AN0:");
//    LCD_dsPIC_SetCursor(0,FILA2);
//    LCD_dsPIC_Print_String("AN1:");
//    LCD_dsPIC_SetCursor(0,FILA3);
//    LCD_dsPIC_Print_String("AN2:");
//    LCD_dsPIC_SetCursor(0,FILA4);
//    LCD_dsPIC_Print_String("AN3:");
//    LCD_dsPIC_SetCursor(10,FILA1);
//    LCD_dsPIC_Print_String("AN4:");
//    LCD_dsPIC_SetCursor(10,FILA2);
//    LCD_dsPIC_Print_String("AN5:");
    
    ADPCFG &= ~(1<<0) & ~(1<<1) & ~(1<<2 ) & ~(1<<3) & ~(1<<4) & ~(1<<5);//habilitadas mis entradas analogicas
    TRISA |= (1<<0) | (1<<1);
    TRISB |= (1<<0) | (1<<1) | (1<<2) | (1<<3) ;
    
    
    for(;;){
       // a1 = AnalogRead(AN0);
//        a2 = AnalogRead(AN1);
//        a3 = AnalogRead(AN2);
//        a4 = AnalogRead(AN3);
//        a5 = AnalogRead(AN4);
//        a6 = AnalogRead(AN5);
        
        
        sprintf(str_a1,"%04u",a1);
//        sprintf(str_a2,"%04u",a2);
//        sprintf(str_a3,"%04u",a3);
//        sprintf(str_a4,"%04u",a4);
//        sprintf(str_a5,"%04u",a5);
//        sprintf(str_a6,"%04u",a6);
        
    LCD_dsPIC_SetCursor(5,FILA1);
    LCD_dsPIC_Print_String(str_a1);
//    LCD_dsPIC_SetCursor(5,FILA2);
//    LCD_dsPIC_Print_String(str_a2);
//    LCD_dsPIC_SetCursor(5,FILA3);
//    LCD_dsPIC_Print_String(str_a3);
//    LCD_dsPIC_SetCursor(5,FILA4);
//    LCD_dsPIC_Print_String(str_a4);
//    LCD_dsPIC_SetCursor(15,FILA1);
//    LCD_dsPIC_Print_String(str_a5);
//    LCD_dsPIC_SetCursor(15,FILA2);
//    LCD_dsPIC_Print_String(str_a6);
    
  
    }
    
    return (EXIT_SUCCESS);
}

