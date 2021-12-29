/* 
 * File:   RTC.h
 * Author: LENOVO
 *
 * Created on 24 de julio de 2021, 10:46 AM
 */

#ifndef RTC_H
#define	RTC_H

#include <xc.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define AM  0
#define PM  1




void DS1307_init(void);
void DS1307_Write_Hours_12(uint8_t horas,uint8_t minutos,uint8_t segundos,uint8_t formato);
void DS1307_Write_Hours_24(uint8_t horas,uint8_t minutos,uint8_t segundos);
void DS1307_Write_Date(uint8_t dia_mes,uint8_t mes ,uint8_t year,uint8_t dia_semana);
void DS1307_Read_H_24(uint8_t *horas ,uint8_t *minutos,uint8_t *segundos);
void DS1307_Read_Date(uint8_t *year ,uint8_t *mes,uint8_t *dia_mes ,uint8_t *dia_semana);


#endif	/* RTC_H */

