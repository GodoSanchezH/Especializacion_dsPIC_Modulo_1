/* 
 * File:   Main.c
 * Author: LENOVO
 *
 * Created on 15 de octubre de 2021, 10:22 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Configuracion.h"
#include <libpic30.h>
#include "LCD_dspic.h"



unsigned int Capt1,Capt2;

void __attribute__((interrupt,no_auto_psv)) _IC1Interrupt(void){
    
    Capt1 = IC1BUF;
    Capt2 = IC1BUF;
    
    
    IFS0bits.IC1IF = 0;//limpiamos el flaj
}


char Resultado[100];
char mensaje[] = "No hay pulsos";
unsigned long Frecuencia;
unsigned int Ticks;

void Timer_Init(void){
 //FCY = 5MHZ -> TCY = 0.2uS*8 -> 
    TMR2 = 0;
    T2CONbits.TON = 0;//descativamos el timer
    T2CONbits.TCS = 0;//reloj interno
    T2CONbits.TCKPS = 0;//  preescaler 1:8 ->1.6uS cuenta
    T2CONbits.TGATE = 0;//sin gate
    T2CONbits.TSIDL = 0;//modo continuo
    T2CONbits.TON = 1;//empieza la cuenta del timer


}
void IC_Clear(void){

IC1CON = 0x0000;
}

void IC_config1(void){
    IC1CONbits.ICTMR = 1;//selecciono el timer 2
    IC1CONbits.ICM = 0b11;//seleccionamos flanco de subido
    IC1CONbits.ICI = 0b01;//el 2er evento
}
void IC_config2(void){
    IC1CONbits.ICTMR = 1;//selecciono el timer 2
    IC1CONbits.ICM = 0b100;//seleccionamos el 4t flanco de subido
    IC1CONbits.ICI = 0b01;//el 2er evento
}

void IC_config3(void){
    IC1CONbits.ICTMR = 1;//selecciono el timer 2
    IC1CONbits.ICM = 0b101;//seleccionamos el 16 flanco de subido
    IC1CONbits.ICI = 0b01;//el 2er evento
}

int main(int argc, char** argv) {
    //inicilamos lcd
    LCD_dsPIC_Init();
    TRISB |= (1<<6);
    RPINR7bits.IC1R = 6;//RB6
    IFS0bits.IC1IF = 0;//limpiamos el flaj
    IEC0bits.IC1IE = 1;//habilitamos su interrupcion
    IPC0bits.IC1IP = 2;//prioridad 2
    
    Timer_Init();
    IC_Clear();
    IC_config1();

    
   
    

    asm("nop");
        
        
    for(;;){
    
        if(Capt1==0 && Capt2 == 0){
        LCD_dsPIC_SetCursor(0,FILA1);
        LCD_dsPIC_Print_String(mensaje);
        IC_Clear();
        __delay_ms(500);
        
        LCD_dsPIC_Clear();
        
        }
        
        if(((Capt1==0 && Capt2 != 0)) || Capt1>Capt2){
        
            T2CONbits.TON = 0;
            TMR2 = 0;
            T2CONbits.TON = 1;
        }
        
        
        
        if(Frecuencia<=700000){
            IC_Clear();
            IC_config1();
            Ticks = Capt2-Capt1;
            
            Frecuencia = ((5000000)/Ticks);
        }
        else if((Frecuencia >700000) &&(Frecuencia< 3000000)){
            IC_Clear();
            IC_config2();
            Ticks = Capt2-Capt1;
            
            Frecuencia = ((5000000*4)/Ticks);
        
        }
        else if(Frecuencia>= 3000000){
            IC_Clear();
            IC_config3();
            Ticks = Capt2-Capt1;
            
            Frecuencia = ((5000000*16)/Ticks);
        
        }
        
        
        
        sprintf(Resultado,"Frecuencia:%06li Hz",Frecuencia);
         LCD_dsPIC_SetCursor(0,FILA1);
         LCD_dsPIC_Print_String(Resultado);
         __delay_ms(100);
    
    }
    
    
    
    return (EXIT_SUCCESS);
}

