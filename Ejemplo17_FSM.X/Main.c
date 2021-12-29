/* 
 * File:   Main.c
 * Author: lenovo
 *
 * Created on October 29, 2021, 11:47 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Config.h"
#include <libpic30.h>
#include <p33FJ128MC802.h>


//contador de 0 F ; retardo -> 
//contador de 0 a F con pulsor



 typedef struct{

    uint8_t Contador;
    uint8_t Limite;

}Datos;


typedef enum{
    reinicia = 0,
            sube,
            muestreo,
            reposo,
            lectura
}State;


State Estados = reinicia;
Datos Datos_FSM;

void GPIO_Init(void);

int main(int argc, char** argv) {
    GPIO_Init();
    Datos_FSM.Limite = 9;//LIMITE DEL CONTADOR
    
    for(;;){
    
        switch(Estados){
        
            case reinicia:
                Datos_FSM.Contador = 0;//reinicia la cuenta
                Estados = muestreo;
                break;
            /////////////////////////    
            case sube:
                Datos_FSM.Contador++;
                Estados = muestreo;
                        
                break;
             ////////////////////////////   
            case muestreo:
                if(Datos_FSM.Contador == Datos_FSM.Limite+1){
                
                    Estados = reinicia;
                }
                else{
                
                    LATB = (Datos_FSM.Contador & 0b00001111)<<6;
                    Estados = lectura;
                }
                break;
             //////////////////////////  
            case lectura:
             
                if (PORTAbits.RA0 ==0) {
                    __delay_ms(10);
                    while (PORTAbits.RA0 ==0) ;
                    Estados = sube;
                }

                break;
        
        
        }
        
        
    }
    
    
    return (EXIT_SUCCESS);
}

void GPIO_Init(void){
    AD1PCFGL = 0xFFFF;
    TRISB = 0X0000;
    TRISAbits.TRISA0 = 1;
}


/*ejemplo 1 */
//
//switch(Estados){
//        
//            case reinicia:
//                Datos_FSM.Contador = 0;//reinicia la cuenta
//                Estados = muestreo;
//                break;
//            /////////////////////////    
//            case sube:
//                Datos_FSM.Contador++;
//                Estados = reposo;
//                        
//                break;
//             ////////////////////////////   
//            case muestreo:
//                if(Datos_FSM.Contador == Datos_FSM.Limite+1){
//                
//                    Estados = reinicia;
//                }
//                else{
//                
//                    LATB = (Datos_FSM.Contador & 0b00001111)<<6;
//                    Estados = sube;
//                }
//                break;
//             //////////////////////////  
//            case reposo:
//                __delay_ms(500);
//                Estados = muestreo;
//                break;
//        
        