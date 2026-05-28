#include "esp_log.h"
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "led_manager.hpp"
#include "wifi_manager.hpp"
#include "mqtt_manager.hpp"

static const char *TAG = "MAIN";

extern "C" void app_main(void)
{
    esp_err_t ret = nvs_flash_init();

    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }

    ESP_ERROR_CHECK(ret);

    led_manager_init();
    wifi_manager_init();
    mqtt_manager_init();

    while (true) {
        ESP_LOGI(TAG, "Heartbeat");
        mqtt_manager_publish_heartbeat();
        vTaskDelay(pdMS_TO_TICKS(10000));
    }
}