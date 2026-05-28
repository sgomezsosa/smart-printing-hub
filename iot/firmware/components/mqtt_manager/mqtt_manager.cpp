#include "mqtt_manager.hpp"

#include "esp_log.h"
#include "mqtt_client.h"

static const char *TAG = "MQTT";

static esp_mqtt_client_handle_t mqtt_client = nullptr;

#define MQTT_BROKER_URI "mqtt://broker.hivemq.com"
#define MQTT_HEARTBEAT_TOPIC "smartprint/esp32-01/heartbeat"

static void mqtt_event_handler(
    void *handler_args,
    esp_event_base_t base,
    int32_t event_id,
    void *event_data
) {
    auto *event = static_cast<esp_mqtt_event_handle_t>(event_data);

    switch (static_cast<esp_mqtt_event_id_t>(event_id)) {
        case MQTT_EVENT_CONNECTED:
            ESP_LOGI(TAG, "MQTT connected to broker");
            break;

        case MQTT_EVENT_DISCONNECTED:
            ESP_LOGW(TAG, "MQTT disconnected from broker");
            break;

        case MQTT_EVENT_PUBLISHED:
            ESP_LOGI(TAG, "MQTT message published, msg_id=%d", event->msg_id);
            break;

        case MQTT_EVENT_ERROR:
            ESP_LOGE(TAG, "MQTT error");
            break;

        default:
            ESP_LOGI(TAG, "MQTT event received: %ld", static_cast<long>(event_id));
            break;
    }
}

void mqtt_manager_init()
{
    esp_mqtt_client_config_t mqtt_cfg = {};
    mqtt_cfg.broker.address.uri = MQTT_BROKER_URI;

    mqtt_client = esp_mqtt_client_init(&mqtt_cfg);

    if (mqtt_client == nullptr) {
        ESP_LOGE(TAG, "Could not initialize MQTT client");
        return;
    }

    ESP_ERROR_CHECK(
        esp_mqtt_client_register_event(
            mqtt_client,
            static_cast<esp_mqtt_event_id_t>(ESP_EVENT_ANY_ID),
            mqtt_event_handler,
            nullptr
        )
    );

    ESP_ERROR_CHECK(esp_mqtt_client_start(mqtt_client));

    ESP_LOGI(TAG, "MQTT initialization completed");
}

void mqtt_manager_publish_heartbeat()
{
    if (mqtt_client == nullptr) {
        ESP_LOGW(TAG, "MQTT not initialized, heartbeat skipped");
        return;
    }

    const char *payload = "{\"deviceId\":\"esp32-01\",\"status\":\"ONLINE\"}";

    int msg_id = esp_mqtt_client_publish(
        mqtt_client,
        MQTT_HEARTBEAT_TOPIC,
        payload,
        0,
        1,
        0
    );

    ESP_LOGI(TAG, "Heartbeat sent, msg_id=%d", msg_id);
}