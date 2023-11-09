#ifndef INC_KEYBOARD_H_
#define INC_KEYBOARD_H_


#include "stm32l4xx_hal.h"

#include "main.h"


/*** GPIOS pins for the keyboard
#define COLUMN_1_Pin GPIO_PIN_10
#define COLUMN_1_GPIO_Port GPIOB
#define COLUMN_1_EXTI_IRQn EXTI15_10_IRQn
#define COLUMN_4_Pin GPIO_PIN_7
#define COLUMN_4_GPIO_Port GPIOC
#define COLUMN_4_EXTI_IRQn EXTI9_5_IRQn
#define COLUMN_2_Pin GPIO_PIN_8
#define COLUMN_2_GPIO_Port GPIOA
#define COLUMN_2_EXTI_IRQn EXTI9_5_IRQn
#define COLUMN_3_Pin GPIO_PIN_9
#define COLUMN_3_GPIO_Port GPIOA
#define COLUMN_3_EXTI_IRQn EXTI9_5_IRQn
#define ROW_1_Pin GPIO_PIN_10
#define ROW_1_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define ROW_2_Pin GPIO_PIN_3
#define ROW_2_GPIO_Port GPIOB
#define ROW_4_Pin GPIO_PIN_4
#define ROW_4_GPIO_Port GPIOB
#define ROW_3_Pin GPIO_PIN_5
#define ROW_3_GPIO_Port GPIOB ***/



#include <stdint.h>
#include <stdio.h>

/*** Debounce variable to remove noise in the key ***/
#define KEY_DEBOUNCE_MS 300


/* Set the rows high*/
#define SET_ROWS_HIGH() do { \
	ROW_1_GPIO_Port->BSRR = ROW_1_Pin; \
	ROW_2_GPIO_Port->BSRR = ROW_2_Pin; \
	ROW_3_GPIO_Port->BSRR = ROW_3_Pin; \
	ROW_4_GPIO_Port->BSRR = ROW_4_Pin; \
} while(0)


/* Set the first rows high*/
#define SET_FIRST_ROW_HIGH() do { \
	ROW_1_GPIO_Port->BSRR = ROW_1_Pin; \
	ROW_2_GPIO_Port->BRR = ROW_2_Pin; \
	ROW_3_GPIO_Port->BRR = ROW_3_Pin; \
	ROW_4_GPIO_Port->BRR = ROW_4_Pin; \
} while(0)

/*
#define SET_SECOND_ROW_HIGH() do { \
	ROW_1_GPIO_Port->BRR = ROW_1_Pin;  \	// turn off row 1
	ROW_2_GPIO_Port->BSRR = ROW_2_Pin; \	// turn on row 2
}

#define SET_THIRD_ROW_HIGH() do { \
	ROW_2_GPIO_Port->BRR = ROW_2_Pin;  \	// turn off row 2
	ROW_3_GPIO_Port->BSRR = ROW_3_Pin; \	// turn on row 3
} while(0)

#define SET_FOUR_ROW_HIGH() do { \
	ROW_3_GPIO_Port->BRR = ROW_3_Pin;  \	// turn off row 3
	ROW_4_GPIO_Port->BSRR = ROW_4_Pin; \	// turn on row 4
} while(0)
*/

/*  Method to initialize the keyboard*/
void keypad_init(void);

/*  Method to identify keypad events.*/
uint8_t keypad_handler(uint16_t column_to_evaluate);

#endif /* INC_KEYBOARD_H_ */
