/* 
 * File:   Interrupciones.h
 * Author: LENOVO
 *
 * Created on 24 de septiembre de 2021, 09:45 PM
 */

#ifndef INTERRUPCIONES_H
#define	INTERRUPCIONES_H

#include <stdint.h>
#include <stdbool.h>


#define Subida 0
#define Bajada 1

typedef enum{
    INT0=0,
            INT1,
            INT2
}Interrupt;

void Interrupcion_Externa(uint8_t INTX,bool Flanco,uint8_t Prioridad);


#endif	/* INTERRUPCIONES_H */

