#include "led_manager.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_PIN GPIO_NUM_4

static volatile led_state_t g_led_state = LED_STATE_CONNECTING;

static void led_task(void *pvParameters)
{
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (1) {
        switch (g_led_state) {
            case LED_STATE_CONNECTING:
                gpio_set_level(LED_PIN, 1);
                vTaskDelay(pdMS_TO_TICKS(150));
                gpio_set_level(LED_PIN, 0);
                vTaskDelay(pdMS_TO_TICKS(150));
                break;

            case LED_STATE_CONNECTED:
                gpio_set_level(LED_PIN, 1);
                vTaskDelay(pdMS_TO_TICKS(500));
                break;

            case LED_STATE_ERROR:
                gpio_set_level(LED_PIN, 1);
                vTaskDelay(pdMS_TO_TICKS(800));
                gpio_set_level(LED_PIN, 0);
                vTaskDelay(pdMS_TO_TICKS(800));
                break;
        }
    }
}

void led_manager_init(void)
{
    xTaskCreate(led_task, "led_task", 2048, NULL, 5, NULL);
}

void led_manager_set_state(led_state_t state)
{
    g_led_state = state;
}