/* 
 * File:   Main_IC.c
 * Author: LENOVO
 *
 * Created on 15 de octubre de 2021, 09:35 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Configuracion.h"
#include <libpic30.h>
#include "LCD_dspic.h"



double Tiempo;
char Str_Tiempo[];

void __attribute__((interrupt,no_auto_psv)) _IC1Interrupt(void){
    unsigned int ticks = 0;
    ticks = IC1BUF;
    Tiempo = ticks*0.0000016;
    TMR2 = 0;
    
    IFS0bits.IC1IF = 0;//limpiamos el flaj
}

int main(int argc, char** argv) {
    
    //inicilamos lcd
    LCD_dsPIC_Init();
    
    // configurar el timer
    //FCY = 5MHZ -> TCY = 0.2uS*8 -> 
    TMR2 = 0;
    T2CONbits.TON = 0;//descativamos el timer
    T2CONbits.TCS = 0;//reloj interno
    T2CONbits.TCKPS = 1;//  preescaler 1:8 ->1.6uS cuenta
    T2CONbits.TGATE = 0;//sin gate
    T2CONbits.TSIDL = 0;//modo continuo
     
    
    //configurar el modulo input capture
    TRISB |= (1<<6);
    RPINR7bits.IC1R = 6;//RB6
    IC1CON = 0x0000;
    IC1CONbits.ICTMR = 1;//selecciono el timer 2
    IC1CONbits.ICM = 0b11;//seleccionamos flaco de subido
    IC1CONbits.ICI = 0b00;//el 1er evento
    
    IFS0bits.IC1IF = 0;//limpiamos el flaj
    IEC0bits.IC1IE = 1;//habilitamos su interrupcion
    IPC0bits.IC1IP = 2;//prioridad 2
    T2CONbits.TON = 1;//empieza la cuenta del timer
    
    
    
    
    
    for(;;){
    
      sprintf(Str_Tiempo,"Tiempo->%0.6f",Tiempo);
      LCD_dsPIC_SetCursor(0,FILA1);
      LCD_dsPIC_Print_String(Str_Tiempo);
    
    }

    return (EXIT_SUCCESS);
}

