idf_component_register(
    SRCS "led_manager.cpp"
    INCLUDE_DIRS "include"
    REQUIRES esp_driver_gpio freertos
)