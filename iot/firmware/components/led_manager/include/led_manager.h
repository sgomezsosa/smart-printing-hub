#ifndef LED_MANAGER_H
#define LED_MANAGER_H

typedef enum {
    LED_STATE_CONNECTING,
    LED_STATE_CONNECTED,
    LED_STATE_ERROR
} led_state_t;

void led_manager_init(void);
void led_manager_set_state(led_state_t state);

#endif