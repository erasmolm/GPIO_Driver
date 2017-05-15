/**
  ******************************************************************************
  * @file    led.h
  * @author  Pierluigi,Alfonso,Erasmo
  * @version V1.0
  * @date    04-May-2017
  * @brief   Questo file definisce le principali funzioni di gestione dei led      
  ******************************************************************************
  */
#ifndef SRC_LED_H_
#define SRC_LED_H_

/* Includes ------------------------------------------------------------------*/
#include "gpgpio.h"

#define BASE_ADDRESS XPAR_GPIO_SE_0_S00_AXI_BASEADDR /*!<indirizzo base della periferica gpio a cui sono collegati i led*/


#define LED0	0 
#define LED1	1
#define LED2	2
#define LED3	3

/**
  * @brief maschere per accendere i led
*/  
#define LED0_MASK	(uint32_t)(0x1 << LED0)
#define LED1_MASK	(uint32_t)(0x1 << LED1)
#define LED2_MASK	(uint32_t)(0x1 << LED2)
#define LED3_MASK	(uint32_t)(0x1 << LED3)

typedef struct led_t led_t;
/**
  * @brief tipo di dato astratto led_t 
  *
*/
struct led_t{

	void (*enable)(led_t* self);
	void (*disable)(led_t* self);
	uint32_t (*readStatus)(led_t* self);
	void (*setOn)(led_t* self,int pos);
	void (*setOff)(led_t* self,int pos);
	void (*toggle)(led_t* self,int pos);
	void (*setLeds)(led_t* self,uint32_t led_mask);

    uint32_t* base_addr;
};

/**
  * @brief firma della funzione di inizializzazione
 */
void LED_Init(led_t*);

#endif /* SRC_LED_H_ */
