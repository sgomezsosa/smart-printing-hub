# SmartPrint Hub

## Overview

SmartPrint Hub is a full-stack project designed to integrate **IoT (ESP32)**, **Backend services**, **Frontend applications**, and **Infrastructure** into a unified system for managing and monitoring 3D printing workflows.

The goal is to build a **production-ready, scalable architecture** that combines:

* IoT device control (ESP32 + sensors/actuators)
* Cloud-native backend services (Java / AWS)
* Web-based user interfaces
* Infrastructure as Code (IaC)

This repository is structured as a **monorepo**, enabling consistent development practices, shared context, and easier system evolution.

---

## Project Goals

* Build a **modular IoT platform** for device monitoring and control
* Integrate **real-time communication (MQTT)**
* Apply **cloud architecture principles (AWS)**
* Create a **portfolio-grade system** demonstrating Software Architecture skills
* Enable future expansion into:

    * Robotics
    * AI-assisted workflows
    * Smart manufacturing

---

## Repository Structure

```
smartprint-hub/
  backend/        # Java backend services (API, business logic)
  frontend/       # Web UI / dashboards
  iot/            # ESP32 firmware and device logic
  infra/          # Infrastructure as Code (AWS, networking, deployment)
```

---

## Module Breakdown

### 1. IoT Module (`iot/`)

#### Purpose

Handles device-level logic using ESP32, including connectivity, telemetry, and hardware interaction.

#### Structure

```
iot/
  firmware/
    main/
    components/
      led_manager/
      wifi_manager/
      mqtt_manager/
```

#### Components

* **led_manager**

    * Controls LED states for visual feedback
    * States: CONNECTING, CONNECTED, ERROR

* **wifi_manager**

    * Handles WiFi connection lifecycle
    * Manages retries and connection state

* **mqtt_manager**

    * Connects to MQTT broker
    * Publishes telemetry (heartbeat)
    * Will handle subscriptions in future

#### Technologies

* ESP-IDF (Espressif IoT Development Framework)
* PlatformIO
* FreeRTOS
* MQTT protocol

#### Tools

* PlatformIO CLI
* Wokwi Simulator (for development)
* ESP32 hardware (for real testing)

---

### 2. Backend Module (`backend/`)

#### Purpose

Provides APIs and business logic to interact with IoT devices and process data.

#### Planned Responsibilities

* REST APIs for device management
* MQTT consumer/producer integration
* Data persistence
* Authentication and authorization

#### Technologies

* Java (Spring Boot)
* REST APIs
* AWS services (planned):

    * API Gateway
    * Lambda / ECS
    * DynamoDB / RDS

#### Tools

* Maven / Gradle
* Docker
* Postman / Insomnia

---

### 3. Frontend Module (`frontend/`)

#### Purpose

User interface for interacting with devices, monitoring telemetry, and controlling workflows.

#### Planned Features

* Real-time device status dashboard
* Telemetry visualization
* Command/control interface

#### Technologies

* React / Next.js (planned)
* TypeScript
* WebSockets / MQTT over Web

#### Tools

* Node.js
* npm / yarn

---

### 4. Infrastructure Module (`infra/`)

#### Purpose

Defines and manages cloud infrastructure required for the system.

#### Responsibilities

* Cloud resource provisioning
* Networking setup
* Deployment pipelines

#### Technologies

* AWS (primary target)
* Terraform / AWS CDK (to be defined)

#### Planned Services

* AWS IoT Core
* S3
* CloudWatch
* IAM

---

## Communication Architecture

```
ESP32 (IoT)
   ↓ MQTT
Broker (Local / Cloud)
   ↓
Backend Services
   ↓ REST / WebSocket
Frontend UI
```

---

## Current Status

### Implemented

* ESP32 firmware (ESP-IDF)
* Modular component architecture
* WiFi connectivity
* MQTT publishing (heartbeat)
* Wokwi simulation setup

### In Progress

* MQTT subscriptions (commands)
* Backend service skeleton

### Planned

* AWS IoT integration
* Full backend implementation
* Frontend dashboard
* CI/CD pipelines

---

## Development Workflow

### IoT

```bash
cd iot/firmware
pio run
```

### Simulation

* Use Wokwi to simulate ESP32
* Serial output enabled via `diagram.json`

---

## Future Improvements

* Add device provisioning
* Secure MQTT (TLS, certificates)
* OTA updates
* AI-driven automation
* Integration with 3D printing workflows

---

## Contribution Guidelines

* Keep modules decoupled
* Follow component-based architecture
* Document new features
* Maintain consistency across modules

---

## Notes

This project is intended as a **learning + production-grade hybrid system**, evolving progressively over time. Documentation and architecture will continue to improve as new components are added.

---

## Author

Samuel Gomez Sosa

---

## License

(To be defined)
