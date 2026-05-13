#include <Arduino.h>

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // -----------------------------------
    // Pin Configuration
    // -----------------------------------
    // PB2 -> System LED
    // PB1 -> PIR Sensor Input
    // PB0 -> Buzzer
    // PD7 -> Detection LED
    // -----------------------------------

    // Configure outputs
    DDRB |= (1 << PB2);   // System LED output
    DDRB |= (1 << PB0);   // Buzzer output
    DDRD |= (1 << PD7);   // Detection LED output

    // Configure input
    DDRB &= ~(1 << PB1);  // PIR input

    while (1)
    {
        // System ON indication LED
        PORTB |= (1 << PB2);

        // Check PIR sensor
        if (PINB & (1 << PB1))
        {
            // Motion detected

            PORTB |= (1 << PB0);   // Buzzer ON
            PORTD |= (1 << PD7);   // LED ON
        }
        else
        {
            // No motion detected

            PORTB &= ~(1 << PB0);  // Buzzer OFF
            PORTD &= ~(1 << PD7);  // LED OFF
        }

        _delay_ms(100);
    }
}