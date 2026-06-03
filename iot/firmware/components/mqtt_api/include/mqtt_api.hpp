#ifndef MQTT_API_HPP
#define MQTT_API_HPP

#include <string>

namespace smartprint::mqtt_api {

constexpr const char* DEVICE_ID = "esp32-01";
constexpr const char* SCHEMA_VERSION = "1.0";

constexpr const char* TOPIC_HEARTBEAT = "smartprint/devices/esp32-01/heartbeat";
constexpr const char* TOPIC_STATE     = "smartprint/devices/esp32-01/state";
constexpr const char* TOPIC_EVENTS    = "smartprint/devices/esp32-01/events";
constexpr const char* TOPIC_COMMANDS  = "smartprint/devices/esp32-01/commands";

// Builds a standard heartbeat payload.
// Future improvement: replace timestamp=0 with real RTC/NTP time.
std::string build_heartbeat_payload();

// Builds a device state payload.
// Example states: CONNECTING, CONNECTED, ERROR.
std::string build_state_payload(const std::string& state);

// Builds a generic device event payload.
// Used to report important operational events.
std::string build_event_payload(
    const std::string& event_id,
    const std::string& type,
    const std::string& message
);

} // namespace smartprint::mqtt_api

#endif