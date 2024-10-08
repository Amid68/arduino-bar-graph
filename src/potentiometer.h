#ifndef __POTENTIOMETER_H__
#define __POTENTIOMETER_H__

#include <stdint.h>

/**
 * @brief Initialize the ADC module
 */
void ADC_Init(void);

/**
 * @brief Read the ADC value from the specified channel
 *
 * @param channel ADC channel to read (0-7).
 * @return uint16_t ADC conversion result (0-1023).
 */
uint16_t ADC_Read(uint8_t channel);

#endif
