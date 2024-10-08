#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#include "config.h"
#include "potentiometer.h"
#include "led_control.h"

int main(void) {
    // initialize ADC and LEDs
    ADC_Init();
    LED_Init();

    while(1) {
        // read potentiometer value
        uint16_t sensorReading = ADC_Read(POT_ADC_CHANNEL);

        // map sensor reading to number of LEDs
        uint8_t ledLevel = ((uint32_t)sensorReading * (NUM_LEDS + 1)) / 1024;

        // update LEDs based on potentiometer value
        LED_Update(ledLevel);
    }
    
    return 0;
}

