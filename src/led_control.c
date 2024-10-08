#include <avr/io.h>
#include "config.h"
#include "led_control.h"

// arrays for LED data direction registers and ports
static volatile uint8_t * const led_ddr[NUM_LEDS] = {
    &DDRD, &DDRD, &DDRD, &DDRD, &DDRD, &DDRD, &DDRB, &DDRB, &DDRB
};

static volatile uint8_t * const led_port[NUM_LEDS] = {
    &PORTD, &PORTD, &PORTD, &PORTD, &PORTD, &PORTD, &PORTB, &PORTB, &PORTB
};

// arrays for LED pins (Arduino pins 2-10)
static const uint8_t led_pin[NUM_LEDS] = {
    PD2, PD3, PD4, PD5, PD6, PD7, PB0, PB1, PB2
};

void LED_Init(void) {
    for (uint8_t i = 0; i < NUM_LEDS; i++) {
        // set LED pins as outputs
        *led_ddr[i] |= (1 << led_pin[i]);
    }
}

void LED_Update(uint8_t level) {
    for (uint8_t i = 0; i < NUM_LEDS; i++) {
        if (i < level) {
            // turn on LED
            *led_port[i] |= (1 << led_pin[i]);
        } else {
            // turn off LED 
            *led_port[i] &= ~(1 << led_pin[i]);
        }
    }
}

