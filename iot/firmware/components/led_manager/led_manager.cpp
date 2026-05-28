#include "led_manager.hpp"

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_PIN GPIO_NUM_4

static volatile LedState g_led_state = LedState::CONNECTING;

static void led_task(void *pvParameters)
{
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (true) {
        switch (g_led_state) {
            case LedState::CONNECTING:
                gpio_set_level(LED_PIN, 1);
                vTaskDelay(pdMS_TO_TICKS(150));
                gpio_set_level(LED_PIN, 0);
                vTaskDelay(pdMS_TO_TICKS(150));
                break;

            case LedState::CONNECTED:
                gpio_set_level(LED_PIN, 1);
                vTaskDelay(pdMS_TO_TICKS(500));
                break;

            case LedState::ERROR:
                gpio_set_level(LED_PIN, 1);
                vTaskDelay(pdMS_TO_TICKS(800));
                gpio_set_level(LED_PIN, 0);
                vTaskDelay(pdMS_TO_TICKS(800));
                break;
        }
    }
}

void led_manager_init()
{
    xTaskCreate(led_task, "led_task", 2048, nullptr, 5, nullptr);
}

void led_manager_set_state(LedState state)
{
    g_led_state = state;
}