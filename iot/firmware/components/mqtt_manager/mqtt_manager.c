#include "mqtt_manager.h"

#include <stdio.h>
#include <string.h>

#include "esp_log.h"
#include "mqtt_client.h"

static const char *TAG = "MQTT";

static esp_mqtt_client_handle_t mqtt_client = NULL;

#define MQTT_BROKER_URI "mqtt://broker.hivemq.com"
#define MQTT_HEARTBEAT_TOPIC "smartprint/esp32-01/heartbeat"

static void mqtt_event_handler(void *handler_args,
                               esp_event_base_t base,
                               int32_t event_id,
                               void *event_data)
{
    esp_mqtt_event_handle_t event = event_data;

    switch ((esp_mqtt_event_id_t)event_id) {
        case MQTT_EVENT_CONNECTED:
            ESP_LOGI(TAG, "MQTT conectado al broker");
            break;

        case MQTT_EVENT_DISCONNECTED:
            ESP_LOGW(TAG, "MQTT desconectado del broker");
            break;

        case MQTT_EVENT_PUBLISHED:
            ESP_LOGI(TAG, "Mensaje MQTT publicado, msg_id=%d", event->msg_id);
            break;

        case MQTT_EVENT_ERROR:
            ESP_LOGE(TAG, "Error en MQTT");
            break;

        default:
            ESP_LOGI(TAG, "Evento MQTT recibido: %ld", (long)event_id);
            break;
    }
}

void mqtt_manager_init(void)
{
    esp_mqtt_client_config_t mqtt_cfg = {
        .broker.address.uri = MQTT_BROKER_URI,
    };

    mqtt_client = esp_mqtt_client_init(&mqtt_cfg);
    if (mqtt_client == NULL) {
        ESP_LOGE(TAG, "No se pudo inicializar el cliente MQTT");
        return;
    }

    ESP_ERROR_CHECK(esp_mqtt_client_register_event(
        mqtt_client,
        ESP_EVENT_ANY_ID,
        mqtt_event_handler,
        NULL
    ));

    ESP_ERROR_CHECK(esp_mqtt_client_start(mqtt_client));

    ESP_LOGI(TAG, "Inicialización MQTT completada");
}

void mqtt_manager_publish_heartbeat(void)
{
    if (mqtt_client == NULL) {
        ESP_LOGW(TAG, "MQTT no inicializado, heartbeat no enviado");
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

    ESP_LOGI(TAG, "Heartbeat enviado, msg_id=%d", msg_id);
}