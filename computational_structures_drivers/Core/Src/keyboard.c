#include "keyboard.h"


/**
 * @brief This functions initialize the functionality of the keypad
 */
void keypad_init(void)
{
	/* Set the rows high to be detected in the columns by rising interrupt */
	SET_ROWS_HIGH();
}



/**
 * @brief  This function debounces and identify keypad events.
 * @param  column_to_evaluate: the column where the event happened.
 * @retval 0xFF -> invalid key. [0x00 - 0x0F] -> valid key.
 */
uint8_t keypad_handler(uint16_t column_to_evaluate)
{
	uint8_t key_pressed = 0xFF; // Value to return

	static uint32_t last_pressed_tick = 0;
	if (HAL_GetTick() <= (last_pressed_tick + KEY_DEBOUNCE_MS)) {
		// less than KEY_DEBOUNCE_MS since last press. Probably noise
		return key_pressed; // return 0xFF
	}
	last_pressed_tick = HAL_GetTick();

	/*** Check in which column the event happened ***/
	switch (column_to_evaluate) {
	case COLUMN_1_Pin:
		SET_FIRST_ROW_HIGH();
		HAL_Delay(2); // wait for voltage to establish
		if (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin) {
			key_pressed = 0x01; // if column 1 is still high -> column 1 + row 1 = key 1
			break;
		}

		ROW_1_GPIO_Port->BRR = ROW_1_Pin; 	// turn off row 1
		ROW_2_GPIO_Port->BSRR = ROW_2_Pin; 	// turn on row 2
		HAL_Delay(2); // wait for voltage to establish
		if (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin) {
			key_pressed = 0x04; // if column 1 is still high -> column 1 + row 2 = key 4
			break;
		}

		ROW_2_GPIO_Port->BRR = ROW_2_Pin; 	// turn off row 2
		ROW_3_GPIO_Port->BSRR = ROW_3_Pin; 	// turn on row 3
		HAL_Delay(2); // wait for voltage to establish
		if (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin) {
			key_pressed = 0x07; // if column 1 is still high -> column 1 + row 3 = key 7
			break;
		}

		ROW_3_GPIO_Port->BRR = ROW_3_Pin;	// turn off row 3
		ROW_4_GPIO_Port->BSRR = ROW_4_Pin; 	// turn on row 4
		HAL_Delay(2); // wait for voltage to establish
		if (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin) {
			key_pressed = 0x0E; // if column 1 is still high -> column 1 + row 4 = key *
			break;
		}
	  break;

	case COLUMN_2_Pin:
		SET_FIRST_ROW_HIGH();
		HAL_Delay(2); // wait for voltage to establish
		if (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin) {
			key_pressed = 0x02; // if column 1 is still high -> column 1 + row 1 = key 1
			break;
		}

		ROW_1_GPIO_Port->BRR = ROW_1_Pin; 	// turn off row 1
		ROW_2_GPIO_Port->BSRR = ROW_2_Pin; 	// turn on row 2
		HAL_Delay(2); // wait for voltage to establish
		if (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin) {
			key_pressed = 0x05; // if column 1 is still high -> column 1 + row 2 = key 4
			break;
		}

		ROW_2_GPIO_Port->BRR = ROW_2_Pin; 	// turn off row 2
		ROW_3_GPIO_Port->BSRR = ROW_3_Pin; 	// turn on row 3
		HAL_Delay(2); // wait for voltage to establish
		if (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin) {
			key_pressed = 0x08; // if column 1 is still high -> column 1 + row 3 = key 7
			break;
		}

		ROW_3_GPIO_Port->BRR = ROW_3_Pin;	// turn off row 3
		ROW_4_GPIO_Port->BSRR = ROW_4_Pin; 	// turn on row 4
		HAL_Delay(2); // wait for voltage to establish
		if (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin) {
			key_pressed = 0x00; // if column 1 is still high -> column 1 + row 4 = key *
			break;
		}
	  break;

	case COLUMN_3_Pin:
			SET_FIRST_ROW_HIGH();
			HAL_Delay(2); // wait for voltage to establish
			if (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin) {
				key_pressed = 0x03; // if column 1 is still high -> column 1 + row 1 = key 1
				break;
			}

			ROW_1_GPIO_Port->BRR = ROW_1_Pin; 	// turn off row 1
			ROW_2_GPIO_Port->BSRR = ROW_2_Pin; 	// turn on row 2
			HAL_Delay(2); // wait for voltage to establish
			if (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin) {
				key_pressed = 0x06; // if column 1 is still high -> column 1 + row 2 = key 4
				break;
			}

			ROW_2_GPIO_Port->BRR = ROW_2_Pin; 	// turn off row 2
			ROW_3_GPIO_Port->BSRR = ROW_3_Pin; 	// turn on row 3
			HAL_Delay(2); // wait for voltage to establish
			if (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin) {
				key_pressed = 0x09; // if column 1 is still high -> column 1 + row 3 = key 7
				break;
			}

			ROW_3_GPIO_Port->BRR = ROW_3_Pin;	// turn off row 3
			ROW_4_GPIO_Port->BSRR = ROW_4_Pin; 	// turn on row 4
			HAL_Delay(2); // wait for voltage to establish
			if (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin) {
				key_pressed = 0x0F; // if column 1 is still high -> column 1 + row 4 = key *
				break;
			}
		  break;

	case COLUMN_4_Pin:
				SET_FIRST_ROW_HIGH();
				HAL_Delay(2); // wait for voltage to establish
				if (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin) {
					key_pressed = 0x0A; // if column 1 is still high -> column 1 + row 1 = key 1
					break;
				}

				ROW_1_GPIO_Port->BRR = ROW_1_Pin; 	// turn off row 1
				ROW_2_GPIO_Port->BSRR = ROW_2_Pin; 	// turn on row 2
				HAL_Delay(2); // wait for voltage to establish
				if (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin) {
					key_pressed = 0x0B; // if column 1 is still high -> column 1 + row 2 = key 4
					break;
				}

				ROW_2_GPIO_Port->BRR = ROW_2_Pin; 	// turn off row 2
				ROW_3_GPIO_Port->BSRR = ROW_3_Pin; 	// turn on row 3
				HAL_Delay(2); // wait for voltage to establish
				if (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin) {
					key_pressed = 0x0C; // if column 1 is still high -> column 1 + row 3 = key 7
					break;
				}

				ROW_3_GPIO_Port->BRR = ROW_3_Pin;	// turn off row 3
				ROW_4_GPIO_Port->BSRR = ROW_4_Pin; 	// turn on row 4
				HAL_Delay(2); // wait for voltage to establish
				if (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin) {
					key_pressed = 0x0D; // if column 1 is still high -> column 1 + row 4 = key *
					break;
				}
			  break;
	default:
		/* This should not be reached */
		printf("Unknown column: %x\r\n", column_to_evaluate);
	  break;
	}

	keypad_init(); // set the columns high again
	return key_pressed; // invalid: 0xFF, valid:[0x00-0x0F]
}
