#ifndef LED_MANAGER_HPP
#define LED_MANAGER_HPP

enum class LedState {
    CONNECTING,
    CONNECTED,
    ERROR
};

void led_manager_init();
void led_manager_set_state(LedState state);

#endif