/**
  ******************************************************************************
  * @file    button.h
  * @author  Pierluigi,Alfonso,Erasmo
  * @version V1.0
  * @date    04-May-2017
  * @brief   Questo file definisce le principali funzioni di gestione dei bottoni      
  ******************************************************************************
  */

#ifndef SRC_BUTTON_H_
#define SRC_BUTTON_H_

/* Includes ------------------------------------------------------------------*/
#include "gpgpio.h"

#define BASE_ADDRESS XPAR_GPIO_SE_2_S00_AXI_BASEADDR /*!<indirizzo base della periferica gpio a cui sono collegati i bottoni*/

typedef struct btn_t btn_t;

/**
  * @brief tipo di dato astratto btn_t 
  *
*/
struct btn_t{

	void (*enable)(btn_t* self);
	void (*disable)(btn_t* self);
	uint32_t (*readStatus)(btn_t* self);

    uint32_t* base_addr;
};

/**
  * @brief firma della funzione di inizializzazione
 */
void BTN_Init(btn_t*);

#endif /* SRC_BUTTON_H_ */
