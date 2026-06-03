# MQTT API v1

## Purpose

This document defines the MQTT communication contract between SmartPrint Hub devices and the platform.

---

# Topic Structure

```text
smartprint/devices/{deviceId}/heartbeat
smartprint/devices/{deviceId}/telemetry
smartprint/devices/{deviceId}/state
smartprint/devices/{deviceId}/events
smartprint/devices/{deviceId}/commands
```

Current device:

```text
esp32-01
```

---

# Heartbeat

Topic:

```text
smartprint/devices/esp32-01/heartbeat
```

Payload:

```json
{
  "schemaVersion": "1.0",
  "deviceId": "esp32-01",
  "type": "HEARTBEAT",
  "status": "ONLINE",
  "firmwareVersion": "0.1.0",
  "timestamp": 0
}
```

---

# State

Topic:

```text
smartprint/devices/esp32-01/state
```

Payload:

```json
{
  "schemaVersion": "1.0",
  "deviceId": "esp32-01",
  "type": "STATE_CHANGED",
  "state": "CONNECTED",
  "timestamp": 0
}
```

---

# Events

Topic:

```text
smartprint/devices/esp32-01/events
```

Payload:

```json
{
  "schemaVersion": "1.0",
  "eventId": "evt-001",
  "type": "COMMAND_RECEIVED",
  "message": "Command processed successfully"
}
```

---

# Commands

Topic:

```text
smartprint/devices/esp32-01/commands
```

Supported commands:

* PING
* SET_LED_STATE
* PUBLISH_STATE

Future commands:

* REBOOT
* OTA_UPDATE
* WIFI_RECONNECT

---

# Versioning

All MQTT payloads must contain:

```json
{
  "schemaVersion": "1.0"
}
```

Future schema changes must be backward compatible whenever possible.
