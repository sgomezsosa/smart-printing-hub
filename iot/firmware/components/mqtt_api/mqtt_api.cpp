#include "mqtt_api.hpp"

namespace smartprint::mqtt_api {

std::string build_heartbeat_payload()
{
    return std::string("{")
        + "\"schemaVersion\":\"" + SCHEMA_VERSION + "\","
        + "\"deviceId\":\"" + DEVICE_ID + "\","
        + "\"type\":\"HEARTBEAT\","
        + "\"status\":\"ONLINE\","
        + "\"firmwareVersion\":\"0.1.0\","
        + "\"timestamp\":0"
        + "}";
}

std::string build_state_payload(const std::string& state)
{
    return std::string("{")
        + "\"schemaVersion\":\"" + SCHEMA_VERSION + "\","
        + "\"deviceId\":\"" + DEVICE_ID + "\","
        + "\"type\":\"STATE_CHANGED\","
        + "\"state\":\"" + state + "\","
        + "\"timestamp\":0"
        + "}";
}

std::string build_event_payload(
    const std::string& event_id,
    const std::string& type,
    const std::string& message
) {
    return std::string("{")
        + "\"schemaVersion\":\"" + SCHEMA_VERSION + "\","
        + "\"deviceId\":\"" + DEVICE_ID + "\","
        + "\"eventId\":\"" + event_id + "\","
        + "\"type\":\"" + type + "\","
        + "\"message\":\"" + message + "\","
        + "\"timestamp\":0"
        + "}";
}

} // namespace smartprint::mqtt_api