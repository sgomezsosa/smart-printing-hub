# System Overview

## Purpose

SmartPrint Hub is an IoT, Cloud and Robotics platform designed to manage smart devices, collect telemetry, execute commands and provide a foundation for future autonomous systems.

The project is intentionally designed to evolve through multiple stages:

1. IoT Platform
2. Smart Device Management
3. Robotics Integration
4. AI-Assisted Automation

---

## High-Level Architecture

```text
Frontend
    │
    │ REST / WebSocket
    ▼
Backend Services
    │
    │ MQTT
    ▼
MQTT Broker
    │
    │ MQTT
    ▼
ESP32 Devices
```

Future architecture:

```text
Frontend
    │
    ▼
Backend
    │
    ▼
MQTT Broker
    │
    ├── ESP32 Devices
    │
    └── ROS2 Robots
            │
            ▼
           DDS
```

---

## Current Scope

Implemented:

* ESP-IDF project
* Modular firmware architecture
* WiFi connectivity
* MQTT connectivity
* MQTT heartbeat publishing

Planned:

* MQTT command processing
* Device state reporting
* Event reporting
* Backend services
* Frontend dashboard
* Robotics integration

---

## Technology Stack

### IoT

* ESP32
* ESP-IDF
* FreeRTOS
* MQTT
* PlatformIO

### Backend

* Java
* Spring Boot

### Frontend

* React
* TypeScript

### Infrastructure

* AWS
* Terraform

### Robotics

* ESP32
* ROS2
* DDS
* micro-ROS
