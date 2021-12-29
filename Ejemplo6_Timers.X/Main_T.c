/* 
 * File:   Main_T.c
 * Author: LENOVO
 *
 * Created on 28 de septiembre de 2021, 08:07 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Configuracion.h"
#include <libpic30.h>
#include <xc.h>
#include "Timer_dsPIC.h"


//#define TON 15
//#define TCS 1
//#define TGATE 6
//#define TCKPS1  5
//#define TCKPS0  4
//#define T1IF    3
//#define T1IE    3
//#define T1IP2    14
//#define T1IP1    13
//#define T1IP0    12

void Timer1_Config(void);
void Timer2_Config(void);
void Timer3_Config(void);

void __attribute__((interrupt,no_auto_psv)) _T1Interrupt(void){
    LATB ^= (1<<0)  ;
    //uart_sent_gsm
    IFS0bits.T1IF = 0;//limpiamos flag
}

void __attribute__((interrupt,no_auto_psv)) _T2Interrupt(void){
    LATB ^= (1<<1)  ;
    //Y = PID(mOTOT1,kP,KI,KD)
    //DUTY_CICLY(Y);
    IFS0bits.T2IF = 0;//limpiamos flag
}

void __attribute__((interrupt,no_auto_psv)) _T3Interrupt(void){
    LATB ^= (1<<2)  ;
    //analog_read();
   IFS0bits.T3IF = 0;//limpiamos flag
}
int main(int argc, char** argv) {
    
    ADPCFG |= (1<<2) |(1<<3)|(1<<4);//Pines como digitales
    TRISB &= ~(1<<0) &  ~(1<<1) & ~(1<<2);//Establecemos como salida
    LATB &= ~(1<<0) &  ~(1<<1) & ~(1<<2);//Limpiamos los Pines a 0
 
    
//    Timer_Temporizador(Timer1,0,0.05,64);
//    Timer_Temporizador(Timer2,0,0.025,64);
//    Timer_Temporizador(Timer3,0,0.0125,64);
//    Timer_Contador(Timer2,0,3,1);
//    Timer_Contador(Timer3,0,6,1);
//    Timer_Gate(Timer2,0,0.04,64);
//    Timer_Gate(Timer3,0,0.05,64);
    //Timer_32bits(T32_Temp);
    //Timer_32bits(T32_Cont);
    Timer_32bits(T32_Gate);
    
    for(;;){
     
    

    
    }
    
    
    return (EXIT_SUCCESS);
}

//    //Timer 1 Por mascaras
//    T1CON &= ~(1<<TON);//apagamos el timer    
//    T1CON &= ~(1<<TCS);//Activo el modo Temporizadoor
//    T1CON |= (1<<TCKPS1);
//    T1CON &= ~(1<<TCKPS0);
//    PR1 = 3905;//-> Valor para 50 ms a 5Mhz
//    TMR1 = 0;//INICIE SIN CARGA   
//    IEC0 |= (1<<T1IE);//Habilitamos interrupcion por desbordamiento
//    IFS0 &= ~(1<T1IF);//limpiamos flag
//    IPC0 &= ~(1<<T1IP2);//Prioridad 2
//    IPC0 |= (1<<T1IP1);//Prioridad 2 
//    IPC0 &= ~(1<<T1IP0);//Prioridad 2 
//    T1CON |= (1<<TON);
