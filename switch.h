/**
  ******************************************************************************
  * @file    switch.h
  * @author  Pierluigi,Alfonso,Erasmo
  * @version V1.0
  * @date    04-May-2017
  * @brief   Questo file definisce le principali funzioni di gestione degli switch      
  ******************************************************************************
  */

#ifndef SRC_SWITCH_H_
#define SRC_SWITCH_H_

/* Includes ------------------------------------------------------------------*/
#include "gpgpio.h"

#define BASE_ADDRESS XPAR_GPIO_SE_1_S00_AXI_BASEADDR/*!<indirizzo base della periferica gpio a cui sono collegati gli switch*/

typedef struct switch_t switch_t;

/**
  * @brief tipo di dato astratto switch_t 
  *
*/
struct switch_t{

	void (*enable)(switch_t* self);
	void (*disable)(switch_t* self);
	uint32_t (*readStatus)(switch_t* self);

    uint32_t* base_addr;
};

/**
  * @brief firma della funzione di inizializzazione
 */
void SW_Init(switch_t*);

#endif /* SRC_SWITCH_H_ */


