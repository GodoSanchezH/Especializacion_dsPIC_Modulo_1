/* 
 * File:   Main_E1.c
 * Author: lenovo
 *
 * Created on 17 de septiembre de 2021, 19:26
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "Configuracion.h"
#include <libpic30.h>//libreria para los delay
#include <math.h>
#include <xc.h>
//#include <xlcd.h>
void Ejemplo10(void);
void Ejemplo9(void);
void Ejemplo8(void);
void Ejemplo7(void);
void Ejemplo6(void);
void Ejemplo5(void);
void Ejemplo4(void);
void Ejemplo3(void);
void Ejemplo2(void);
void Ejemplo1(void);


int i = 0;


int main(int argc, char** argv) {
    // SALIDAS -> 0
    // ENTRADAS ->1
    asm("nop");
//  TRISB = 0X0F00; //HEXADECIMAL
//    TRISA = .15; //DECIMAL
//    TRISC = 0b0100000100000000;//Binario
    
    /*CONFIGURACION BIT A BIT*/
//    AD1PCFGLbits.PCFG0 = 1;//AN0-> DIGITAL
//    AD1PCFGLbits.PCFG2 = 1;//AN2-> DIGITAL
//    TRISBbits.TRISB0 = 0;//salida
//    TRISAbits.TRISA0 = 0;//salida
//    TRISCbits.TRISC0 = 1;//Entrada

    /*CONFIGURACION MEDIANTE ENMASCARAMIENTO*/
//    
//    AD1PCFGL |= (1<<0) | (1<<2);
//    TRISB &= ~(1<<0);
//    TRISA &= ~(1<<0);
 /*CONFIGURACION ATACANDO EL REGISTRO*/
    AD1PCFGL = 0x01FF;
//    TRISB = 0x0000;
//    LATB = 0x0001;
     TRISB &= ~(1<<8) & ~(1<<9); //salidas
     //CNPU2bits.CN27PUE = 1;//activo el pull up
     CNPU1bits.CN2PUE = 1;
     TRISB |= (1<<5);//pin rb5 como entrada
     TRISA|= (1<<0);//pin rb5 como entrada
   //Pullup
  
     
     
    //while(true)
    for(;;){
//         if(PORTAbits.RA0==0){
//            while(PORTAbits.RA0==0);
//           __delay_ms(20);
//           LATB |= (1<<8);
//           LATB &= ~(1<<9);}
//        if(PORTAbits.RA0!=0){
//       while(PORTAbits.RA0!=0);
//           __delay_ms(20);
//            LATB |= (1<<9);
//            LATB &= ~(1<<8);
//        }  
        
         printf("hola\n\r");
         __delay_ms(100);
    }
    return (EXIT_SUCCESS);
}

void Ejemplo9(void){

//       if(!PORTBbits.RB5) return(LATBbits.LATB8=1);
//        return(LATBbits.LATB8=0);

}
void Ejemplo8(void){
        if((PORTB & (1<<5))!=0){
            LATB |= (1<<8);
            LATB &= ~(1<<9);
        }else{
            LATB |= (1<<9);
            LATB &= ~(1<<8);
        }   
}
void Ejemplo7(void){
        if(PORTBbits.RB5 ==0){
            LATBbits.LATB8 = 1;
            LATBbits.LATB9 = 0;
        }else{
            LATBbits.LATB8 = 0;
            LATBbits.LATB9 = 1;
        }

}
void Ejemplo6(void){
   while(i<15){
          __delay_ms(200);
            LATB |= (LATB<<1);
            
            i++;
        }
        i--;
        while(i>=0){
             __delay_ms(200);
            LATB |= (LATB>>1);
           
            i--;
        }
        i=0;  


}
void Ejemplo5(void){
        while(i<16){
            LATB |= (1<<i);
            __delay_ms(100);
            i++;
        }
        i--;
        while(i>=0){
            LATB &= ~(1<<i);
            __delay_ms(100);
            i--;
        }
        i=0;

}
void Ejemplo4(void){
  for(i = 0;i<=16;i++){
            LATB = pow(2,i)-1;
            __delay_ms(100);
        }
        for(i = 15;i>0;i--){
            LATB = pow(2,i)-1;
            __delay_ms(100);
        }
}
void Ejemplo3(void){
        LATB = 0x0f0f;
        __delay_ms(250);
        LATB = 0xF0F0;
        __delay_ms(250);
}
void Ejemplo2(void){
        LATB |= (1<<0);
        LATA &= ~(1<<0);
        __delay_ms(1000);
        LATA |= (1<<0);
        LATB &= ~(1<<0);
        __delay_ms(1000);

}
void Ejemplo1(void){
        LATBbits.LATB0 = 1;
        LATAbits.LATA0 = 0;
        __delay_ms(100);
        LATBbits.LATB0 = 0;
        LATAbits.LATA0 = 1;
        __delay_ms(100);
}
