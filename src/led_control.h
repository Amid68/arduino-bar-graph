#ifndef __LED_CONTROL_H__
#define __LED_CONTROL_H__

#include <stdint.h>

/**
 * @brief Initialize the LED pins as outputs.
 */
void LED_Init(void);

/**
 * @brief Update the LEDs based on the level.
 *
 * @param level Number of LEDs to turn on (0 to NUM_LEDS).
 */
void LED_Update(uint8_t level);

#endif
