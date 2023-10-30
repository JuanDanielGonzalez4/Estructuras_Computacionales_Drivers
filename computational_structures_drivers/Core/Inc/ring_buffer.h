/*
 * ring_buffer.h
 *
 *  Created on: Oct 23, 2023
 *      Author: juang
 */

#ifndef INC_RING_BUFFER_H_
#define INC_RING_BUFFER_H_


#include <stdint.h>
// Macro - Typedef to tell the type of the struct
typedef struct {
	// Pointer to memory where we going to store our data
	uint8_t *buffer;
	// Head of the buffer ring to read new data
	uint16_t head;
	// Tail of the buffer ring to read old data
	uint16_t tail;
	// Size of the buffer ring
	uint16_t capacity;
	// Flag to notice if the buffer is full
	uint8_t is_full;

}ring_buffer_t;

// Method to initialize the ring_buffer
void ring_buffer_init(ring_buffer_t *ring_buffer, uint8_t *buffer, uint16_t capacity);
uint8_t ring_buffer_put(ring_buffer_t *ring_buffer, uint8_t data);

uint8_t ring_buffer_get(ring_buffer_t *ring_buffer, uint8_t *data);
uint8_t ring_buffer_size(ring_buffer_t *ring_buffer);
uint8_t ring_buffer_empty(ring_buffer_t *ring_buffer);
uint8_t ring_buffer_reset(ring_buffer_t *ring_buffer);


#endif /* INC_RING_BUFFER_H_ */
