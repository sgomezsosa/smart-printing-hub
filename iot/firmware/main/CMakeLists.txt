idf_component_register(
    SRCS "main.cpp"
    INCLUDE_DIRS "."
    REQUIRES wifi_manager led_manager mqtt_manager freertos nvs_flash
)