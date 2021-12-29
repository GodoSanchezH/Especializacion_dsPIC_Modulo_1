/* 
 * File:   Main.c
 * Author: HP
 *
 * Created on 22 de octubre de 2021, 08:12 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Config.h"
#include <libpic30.h>
#include <p33FJ128MC802.h>


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
uint16_t i = 0;
int main(int argc, char** argv) {

    TRISB &= ~(1<<7);
    RPOR3bits.RP7R =0b10010;
    Timer2_Init();
    //OC1_Cont_Pulse_Mode();
    
    for(;;){

       OC1_Active_Low_One_Shot();
       __delay_ms(1000);
        
        
        
    }
    
    return (EXIT_SUCCESS);
}

void Timer2_Init(void){
    T2CONbits.TON = 0;//desabilitamos el timer
    // FCY  = 8MHZ -> 0.125uS
    //1:8-> 1.6uS  ; 1:64 -> 12.8us  ; 1:256 -> 51.2 uS
    T2CONbits.TCS = 0;//FCY
    T2CONbits.TCKPS = 3;//1:256-> 32uS
    T2CONbits.TGATE = 0;
    T2CONbits.TSIDL = 0;
    
}
void OC1_PWM(void){
    OC1R = 0;
    OC1RS =1;
    TMR2=0x0000;
    PR2 = 624;
    OC1CONbits.OCTSEL = 0;//Selecciono el tiMER2 
    OC1CONbits.OCM = 0b110;//activamos el modo pwm
    T2CONbits.TON = 1;//DISPARAMOS EL TIMER
}


void OC1_Active_Low_One_Shot(void){
    T2CONbits.TON=0;
    TMR2 = 0;//cuenta en 0
            
    OC1CONbits.OCM = 0b000;//desabilitamos el modulo output compare
    OC1CONbits.OCTSEL = 0;//Selecciono el timer2
    OC1R = 1000;//1000* 32uS -> 32mS
    PR2 = 4000;//128mS
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
    OC1R = 2000;//2000* 32uS -> 64mS
    PR2 = 4000;//128mS
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
    OC1R = 2000;//32uS *2000-> 64mS
    OC1RS = 3000;// 32uS *3000-> 96mS
    //32ms
    PR2 = 4000;//128mS
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


