# SmartPrint Hub

## Overview

SmartPrint Hub is a full-stack IoT, Robotics, and Cloud Architecture project designed to integrate embedded devices, backend services, web applications, and cloud infrastructure into a unified platform.

The project serves as both:

* A production-grade learning platform
* A portfolio project demonstrating IoT, Cloud, Software Architecture, and Robotics skills

The long-term vision is to build a modular ecosystem capable of:

* Managing IoT devices
* Monitoring telemetry in real time
* Controlling robotic systems
* Integrating AI-powered automation
* Supporting smart manufacturing and 3D printing workflows

---

# Project Goals

## Technical Goals

* Build a modular IoT platform using ESP32 and MQTT
* Implement a well-defined MQTT API
* Apply cloud-native architecture principles
* Integrate robotics and autonomous devices
* Learn ROS2 and DDS communication models
* Implement Infrastructure as Code
* Develop AI-assisted automation capabilities

## Learning Goals

* Embedded Software Engineering
* ESP-IDF Development
* MQTT and Event-Driven Architecture
* AWS Cloud Architecture
* Robotics Engineering
* Distributed Systems
* Software Architecture

---

# Repository Structure

```text
smartprint-hub/
│
├── README.md
│
├── backend/
│   ├── services/
│   ├── api/
│   ├── domain/
│   └── infrastructure/
│
├── frontend/
│   ├── web/
│   └── shared/
│
├── infra/
│   ├── terraform/
│   ├── aws/
│   └── deployment/
│
└── iot/
    └── firmware/
        ├── main/
        └── components/
            ├── led_manager/
            ├── wifi_manager/
            ├── mqtt_manager/
            └── mqtt_api/
```

---

# System Architecture

```text
+------------------+
| Frontend UI      |
+--------+---------+
         |
         | REST / WebSocket
         |
+--------v---------+
| Backend Services |
+--------+---------+
         |
         | MQTT
         |
+--------v---------+
| MQTT Broker      |
+--------+---------+
         |
         |
+--------v---------+
| ESP32 Devices    |
+------------------+
```

Future Robotics Architecture:

```text
+------------------+
| Frontend UI      |
+--------+---------+
         |
         | REST / WebSocket
         |
+--------v---------+
| Backend Services |
+--------+---------+
         |
         | MQTT
         |
+--------v---------+
| MQTT Broker      |
+--------+---------+
         |
         |
+--------v---------+
| Robot Fleet      |
| ESP32 / ROS2     |
+------------------+
```

---

# Modules

---

## IoT Module

Location:

```text
iot/firmware
```

### Purpose

Implements the firmware running on ESP32 devices.

Responsible for:

* Hardware interaction
* Connectivity
* Telemetry
* Device state management
* MQTT communication

---

### Current Components

#### led_manager

Responsibilities:

* LED state management
* Visual feedback

States:

```text
CONNECTING
CONNECTED
ERROR
```

Technologies:

* ESP-IDF
* FreeRTOS
* GPIO

---

#### wifi_manager

Responsibilities:

* WiFi connection lifecycle
* Retry handling
* Connection monitoring

Technologies:

* ESP-IDF WiFi
* FreeRTOS

---

#### mqtt_manager

Responsibilities:

* MQTT broker connection
* Publish/Subscribe operations
* MQTT event handling

Technologies:

* ESP-MQTT
* MQTT 5.0 concepts

---

#### mqtt_api

Responsibilities:

* MQTT API contract definition
* Topic definitions
* Payload builders
* Event schema management

Technologies:

* Modern C++
* JSON payload generation

---

### Technologies

* ESP32
* ESP-IDF 5.x
* FreeRTOS
* MQTT
* PlatformIO
* C++17

### Development Tools

* PlatformIO
* Wokwi
* ESP-IDF
* Git

---

## Backend Module

Location:

```text
backend/
```

### Purpose

Provides business logic and APIs for SmartPrint Hub.

### Planned Responsibilities

* Device registration
* Command dispatching
* Telemetry processing
* Data persistence
* Authentication
* Authorization

### Technologies

* Java
* Spring Boot
* Maven
* Docker

### Future AWS Integrations

* API Gateway
* ECS
* Lambda
* DynamoDB
* RDS

---

## Frontend Module

Location:

```text
frontend/
```

### Purpose

Provides a user interface for managing devices and robots.

### Planned Features

* Device dashboard
* Robot dashboard
* Telemetry visualization
* Real-time monitoring
* Command console

### Technologies

* React
* Next.js
* TypeScript

### Tools

* Node.js
* npm

---

## Infrastructure Module

Location:

```text
infra/
```

### Purpose

Defines cloud infrastructure and deployment processes.

### Planned Responsibilities

* Resource provisioning
* CI/CD
* Networking
* Monitoring

### Technologies

* AWS
* Terraform
* GitHub Actions

---

# MQTT API

The MQTT API defines communication contracts between SmartPrint devices and the platform.

---

## Topic Structure

```text
smartprint/devices/{deviceId}/heartbeat
smartprint/devices/{deviceId}/telemetry
smartprint/devices/{deviceId}/state
smartprint/devices/{deviceId}/events
smartprint/devices/{deviceId}/commands
```

Current Device:

```text
esp32-01
```

---

## Heartbeat

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

## State

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

## Events

Topic:

```text
smartprint/devices/esp32-01/events
```

Payload:

```json
{
  "schemaVersion": "1.0",
  "deviceId": "esp32-01",
  "eventId": "evt-001",
  "type": "COMMAND_RECEIVED",
  "message": "Command processed successfully",
  "timestamp": 0
}
```

---

## Commands

Topic:

```text
smartprint/devices/esp32-01/commands
```

Payload:

```json
{
  "schemaVersion": "1.0",
  "commandId": "cmd-001",
  "type": "SET_LED_STATE",
  "payload": {
    "state": "ERROR"
  }
}
```

---

## Initial Command Set

```text
PING
SET_LED_STATE
PUBLISH_STATE
```

---

# Robotics Roadmap

## Phase 1

SmartPrint Rover

Hardware:

* ESP32
* Motor Driver
* DC Motors
* Distance Sensor
* LEDs

Capabilities:

* Remote control
* Telemetry
* MQTT Commands
* Obstacle detection

---

## Phase 2

Autonomous Rover

Features:

* Mapping
* Navigation
* Path planning

---

## Phase 3

ROS2 Integration

Technologies:

* ROS2
* DDS
* Micro-ROS

Goals:

* Multi-node architecture
* Robot fleet management
* MQTT bridge integration

---

# Current Status

## Completed

* ESP-IDF project setup
* PlatformIO integration
* Wokwi simulation
* Modular architecture
* WiFi connectivity
* MQTT connectivity
* MQTT heartbeat publishing
* MQTT API design

## In Progress

* MQTT command subscriptions
* Device state publishing
* Event publishing

## Planned

* Backend services
* Frontend dashboard
* AWS integration
* Local MQTT broker
* SmartPrint Rover

---

# Development Principles

* Modular architecture
* Component-based design
* Clear communication contracts
* Event-driven architecture
* Infrastructure as Code
* Documentation-first approach

---

# Author

Samuel Gomez Sosa

---

# License

To be defined.
