#include <avr/io.h>
#include "potentiometer.h"

void ADC_Init(void) {
    // reference voltage: AVcc with external capacitor at AREF pin
    ADMUX = (1 << REFS0);

    // ADC enable, prescaler = 128 (16MHz / 128 = 125kHz)
    ADCSRA = (1 << ADEN) | (7 << ADPS0);
}

uint16_t ADC_Read(uint8_t channel) {
    // select ADC channel
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);

    // start conversion
    ADCSRA |= (1 << ADSC);

    // wait for conversion to complete
    while (ADCSRA & (1 << ADSC));

    // return ADC value
    return ADC;
}

