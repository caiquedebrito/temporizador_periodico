#include <stdio.h>
#include "pico/stdlib.h"

#define LED_GREEN_PIN 11
#define LED_YELLOW_PIN 12
#define LED_RED_PIN 13

// Variável para armazenar o proximo LED a ser aceso
static uint8_t led_pin_turned_on = LED_YELLOW_PIN;

void turn_leds(bool red, bool blue, bool green);
bool repeating_timer_callback(struct repeating_timer *timer);
void print_timer();

int main()
{
    // Inicializa a biblioteca stdlib
    stdio_init_all();

    // Inicializa os pinos dos LEDs como saída
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);
    gpio_init(LED_YELLOW_PIN);
    gpio_set_dir(LED_YELLOW_PIN, GPIO_OUT);

    // Inicializa com o LED vermelho aceso
    turn_leds(true, false, false);

    struct repeating_timer timer;

    // Inicializa o temporizador periódico
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        print_timer();
        sleep_ms(1000);
    }
}

void turn_leds(bool red, bool blue, bool green){
  gpio_put(LED_RED_PIN, red);
  gpio_put(LED_YELLOW_PIN, blue);
  gpio_put(LED_GREEN_PIN, green);
}

bool repeating_timer_callback(struct repeating_timer *timer) {
    turn_leds(led_pin_turned_on == LED_RED_PIN, led_pin_turned_on == LED_YELLOW_PIN, led_pin_turned_on == LED_GREEN_PIN);

    if (led_pin_turned_on == LED_RED_PIN) {
        led_pin_turned_on = LED_YELLOW_PIN;
    } else if (led_pin_turned_on == LED_YELLOW_PIN) {
        led_pin_turned_on = LED_GREEN_PIN;
    } else {
        led_pin_turned_on = LED_RED_PIN;
    }

    return true;
}

void print_timer() {
    static int timer = 3;
    if (timer == 0) timer = 3;
    printf("Tempo restante: %d\n", timer--);
}