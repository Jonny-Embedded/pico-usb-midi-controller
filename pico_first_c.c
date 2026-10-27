
#include "pico/stdlib.h"
#include <stdio.h>
#include <stdint.h>

#define ENCODER_A 16
#define ENCODER_B 17

int main(void)
{
    stdio_init_all();

    gpio_init(ENCODER_A);
    gpio_set_dir(ENCODER_A, GPIO_IN);
    gpio_pull_up(ENCODER_A);

    gpio_init(ENCODER_B);
    gpio_set_dir(ENCODER_B, GPIO_IN);
    gpio_pull_up(ENCODER_B);

    int previous_state =
        (gpio_get(ENCODER_A) << 1) | gpio_get(ENCODER_B);

    int count = 0;
    int midi_value = 64;
    int transition_accumulator = 0;

    const int8_t transitions[16] = {
         0, -1,  1,  0,
         1,  0,  0, -1,
        -1,  0,  0,  1,
         0,  1, -1,  0
    };

    while (true)
    {
        int current_state =
            (gpio_get(ENCODER_A) << 1) | gpio_get(ENCODER_B);

        int index = (previous_state << 2) | current_state;
        int movement = transitions[index];

        if (movement != 0)
        {
            count += movement;
            transition_accumulator += movement;

            if (transition_accumulator >= 4)
            {
                if (midi_value < 127)
                    midi_value++;

                transition_accumulator = 0;
            }
            else if (transition_accumulator <= -4)
            {
                if (midi_value > 0)
                    midi_value--;

                transition_accumulator = 0;
            }

            printf("Count: %d | MIDI value: %d\n",
                   count, midi_value);
        }

        previous_state = current_state;
        sleep_ms(1);
    }
}
