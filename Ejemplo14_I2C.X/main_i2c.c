/* 
 * File:   main_i2c.c
 * Author: HP
 *
 * Created on 22 de octubre de 2021, 10:06 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Configuracion.h"
#include <libpic30.h>
#include "I2C_dspic.h"
#include "RTC.h"
#include "Uart_dspic.h"

/*
 * 
 */
uint8_t decenas,unidades,centenas;




uint8_t HORA,MINUTO,SEGUNDO = 0;
uint8_t YEAR,MES,DIA_MES,DIA_SEMANA=0;
char calendario[30];
char reloj[25];
uint8_t Display_7Seg_A[10] = {0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
int main(int argc, char** argv) {
    
     I2C_Init(100);
//     DS1307_init();
     UART_dsPIC_Init(9600,one_bit_Stop,Ocho_D_SP,2);
     
    printf("INICIANDO\n\r");
//    DS1307_Write_Hours_24(0,15,50);
//    DS1307_Write_Date(23,10,21,2);
//    
    
    
    
    for(;;){
//        for(centenas=0;centenas<10;centenas++){
//            I2C_Start();
//            I2C_Write_Address_Slave(ADDRES_PCF3,I2C_WRITE);
//            I2C_Write_Data_Slave(Display_7Seg_A[centenas]);
//              for(decenas=0;decenas<10;decenas++){
//                I2C_Restart();
//                I2C_Write_Address_Slave(ADDRES_PCF2,I2C_WRITE);
//                I2C_Write_Data_Slave(Display_7Seg_A[decenas]);
//             
//                  for(unidades=0;unidades<10;unidades++){
//                         I2C_Restart();
//                I2C_Write_Address_Slave(ADDRES_PCF1,I2C_WRITE);
//                            I2C_Write_Data_Slave(Display_7Seg_A[unidades]);
//                            __delay_ms(500);
//                  }
//              }
//              I2C_Stop();
//        }
                            
//       DS1307_Read_H_24(&HORA,&MINUTO,&SEGUNDO);    
//       DS1307_Read_Date(&YEAR,&MES,&DIA_MES,&DIA_SEMANA);
//       printf("H:%02u M:%02u S:%02u\r\n",HORA,MINUTO,SEGUNDO);  
//       printf("A:%u M:%u D_M:%u D_S:%u\r\n",YEAR,MES,DIA_MES,DIA_SEMANA);  
//       __delay_ms(200);
        
        
        
    }
    
    
    return (EXIT_SUCCESS);
}

