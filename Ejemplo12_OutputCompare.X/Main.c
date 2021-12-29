/* 
 * File:   Main.c
 * Author: lenovo
 *
 * Created on 18 de octubre de 2021, 20:51
 */

#include <stdio.h>
#include <stdlib.h>
#include "Configuracion.h"
#include <libpic30.h>
#include <p33FJ32MC202.h>


void __attribute__((interrupt,no_auto_psv)) _OC1Interrupt(void){
    
IFS0bits.OC1IF = 0;//limpiamos el flag

}
void Timer2_Init(void);
void OC1_Active_Low_One_Shot(void);
void OC1_Active_HIGH_One_Shot(void);
void OC1_Toggle_Mode(void);
void OC1_Delayed_One_Shot(void);
void OC1_Cont_Pulse_Mode(void);
void OC1_PWM(void);


int main(int argc, char** argv) {
    
    //pines
    asm("nop");
    TRISB &= ~(1<<7);
    RPOR3bits.RP7R =0b10010;
    Timer2_Init();
    OC1_PWM();
    uint16_t i;
    for(;;){
    
        for(i=0;i<=389;i++){
        
            OC1RS = i;
        __delay_ms(20);
        }
    
    
    }
    
    
    return (EXIT_SUCCESS);
}
void Timer2_Init(void){
    T2CONbits.TON = 0;//desabilitamos el timer
    // FCY  = 5MHZ -> 0.2uS
    //1:8-> 1.6uS  ; 1:64 -> 12.8us  ; 1:256 -> 51.2 uS
    T2CONbits.TCS = 0;//FCY
    T2CONbits.TCKPS = 3;//1:1 -> 0.2uS
    T2CONbits.TGATE = 0;
    T2CONbits.TSIDL = 0;
    
}
void OC1_PWM(void){
    OC1R = 0;
    OC1RS =1;
    TMR2=0x0000;
    PR2 = 390;
    OC1CONbits.OCTSEL = 0;//Selecciono el tiMER2 
    OC1CONbits.OCM = 0b110;//activamos el modo pwm
    T2CONbits.TON = 1;//DISPARAMOS EL TIMER
}


void OC1_Active_Low_One_Shot(void){
    OC1CONbits.OCM = 0b000;//desabilitamos el modulo output compare
    OC1CONbits.OCTSEL = 0;//Selecciono el timer2
    OC1R = 200;//100* 0.2uS -> 20uS
    //PR2 = ;
    //rutina de interrupcion 
    IFS0bits.OC1IF = 0;//limpiamos el flag
    IEC0bits.OC1IE = 1;//habilitamos la interrupcion
    IPC0bits.OC1IP = 1;//prioridad 1
    OC1CONbits.OCM = 0b001;//habilitamos en el modo Active_Low_One_Shot
    T2CONbits.TON = 1;//DISPARAMOS EL TIMER
}

void OC1_Active_HIGH_One_Shot(void){
    OC1CONbits.OCM = 0b000;//desabilitamos el modulo output compare
    OC1CONbits.OCTSEL = 0;//Selecciono el timer2
    OC1R = 1000;//100* 0.2uS -> 20uS
    //PR2 = 80;
    //rutina de interrupcion 
    IFS0bits.OC1IF = 0;//limpiamos el flag
    IEC0bits.OC1IE = 1;//habilitamos la interrupcion
    IPC0bits.OC1IP = 1;//prioridad 1
    OC1CONbits.OCM = 0b010;//habilitamos en el modo Active_High_One_Shot
    T2CONbits.TON = 1;//DISPARAMOS EL TIMER
}

void OC1_Toggle_Mode(void){
    OC1CONbits.OCM = 0b000;//desabilitamos el modulo output compare
    OC1CONbits.OCTSEL = 0;//Selecciono el timer2
    OC1R = 1000;//100* 0.2uS -> 20uS
    //PR2 = 80;
    //rutina de interrupcion 
    IFS0bits.OC1IF = 0;//limpiamos el flag
    IEC0bits.OC1IE = 1;//habilitamos la interrupcion
    IPC0bits.OC1IP = 1;//prioridad 1
    OC1CONbits.OCM = 0b011;//habilitamos en el modo Active_High_One_Shot
    T2CONbits.TON = 1;//DISPARAMOS EL TIMER
}

void OC1_Cont_Pulse_Mode(void){
    OC1CONbits.OCM = 0b000;//desabilitamos el modulo output compare
    OC1CONbits.OCTSEL = 0;//Selecciono el timer2
    OC1R = 5000;//100* 0.2uS -> 20uS
    OC1RS = 40000;   //PR2 = 80;
    //rutina de interrupcion 
    IFS0bits.OC1IF = 0;//limpiamos el flag
    IEC0bits.OC1IE = 1;//habilitamos la interrupcion
    IPC0bits.OC1IP = 1;//prioridad 1
    OC1CONbits.OCM = 0b101;//habilitamos en el modo Active_High_One_Shot
    T2CONbits.TON = 1;//DISPARAMOS EL TIMER


}



void OC1_Delayed_One_Shot(void){
    OC1CONbits.OCM = 0b000;//desabilitamos el modulo output compare
    OC1CONbits.OCTSEL = 0;//Selecciono el timer2
    OC1R = 1000;//100* 0.2uS -> 20uS
    OC1RS = 2000;   //PR2 = 80;
    //rutina de interrupcion 
    IFS0bits.OC1IF = 0;//limpiamos el flag
    IEC0bits.OC1IE = 1;//habilitamos la interrupcion
    IPC0bits.OC1IP = 1;//prioridad 1
    OC1CONbits.OCM = 0b100;//habilitamos en el modo Active_High_One_Shot
    T2CONbits.TON = 1;//DISPARAMOS EL TIMER


}

