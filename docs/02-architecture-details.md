# SmartPrint Hub

## AI + IoT Platform for 3D Printing Operations

---
# 🏗️ ARQUITECTURA DETALLADA (OPCIÓN 2)

Esta sección define la arquitectura completa del sistema lista para implementación.

---

## 🔄 Flujo del Sistema

```text
ESP32
  ↓ (MQTT)
AWS IoT Core
  ↓ (Rule)
Lambda (processTelemetry)
  ↓
DynamoDB

Frontend → API Gateway → Spring Boot → DynamoDB

IA:
Spring Boot → Bedrock
```

---

## 📡 MQTT Topics

### Telemetría

```
smartprint/{deviceId}/telemetry
```

### Payload

```json
{
  "deviceId": "esp32-01",
  "timestamp": 1710000000,
  "temperature": 28.5,
  "humidity": 62.3,
  "vibration": 0.8,
  "doorOpen": false,
  "jobId": "job-123"
}
```

---

### Eventos

```
smartprint/{deviceId}/events
```

```json
{
  "type": "DOOR_OPEN",
  "timestamp": 1710000000,
  "jobId": "job-123"
}
```

---

## 🗄️ Modelo de Datos (DynamoDB)

### sensor_readings

* PK: deviceId
* SK: timestamp

Atributos:

* temperature
* humidity
* vibration
* doorOpen
* jobId

---

### jobs

```json
{
  "jobId": "job-123",
  "status": "IN_PROGRESS",
  "createdAt": 1710000000,
  "completedAt": null,
  "printerId": "printer-01",
  "description": "Soporte audífonos",
  "material": "PLA"
}
```

---

### alerts

```json
{
  "alertId": "alert-001",
  "jobId": "job-123",
  "type": "HIGH_HUMIDITY",
  "message": "Humidity exceeded threshold",
  "timestamp": 1710000000,
  "severity": "MEDIUM"
}
```

---

### recommendations

```json
{
  "recommendationId": "rec-001",
  "jobId": "job-123",
  "content": "Reduce humidity or enclose printer",
  "createdAt": 1710000000
}
```

---

## ⚙️ IoT Rule

```sql
SELECT * FROM 'smartprint/+/telemetry'
```

Acción:

* Lambda → processTelemetry

---

## 🧩 Lambda: processTelemetry

### Responsabilidades

* Guardar datos en DynamoDB
* Evaluar reglas
* Generar alertas

---

### Lógica base

```python
if humidity > 65:
    create_alert("HIGH_HUMIDITY")

if vibration > 1.2:
    create_alert("HIGH_VIBRATION")

if doorOpen:
    create_alert("DOOR_OPEN")
```

---

## ☕ Backend (Spring Boot)

### Endpoints

#### Jobs

```
POST /jobs
GET /jobs
GET /jobs/{id}
PATCH /jobs/{id}/status
```

#### Telemetría

```
GET /devices/{deviceId}/telemetry
```

#### Alerts

```
GET /jobs/{id}/alerts
```

#### IA

```
POST /ai/recommendations
POST /ai/job-summary
POST /ai/intake
```

---

## 🤖 Integración IA

### Ejemplo Input

```json
{
  "temperature": 29,
  "humidity": 70,
  "vibration": 1.3,
  "material": "PLA"
}
```

### Prompt

```
You are an expert in 3D printing.
Explain possible issues and suggest actions.
```

---

## 🧠 ESP32 Loop

```cpp
void loop() {
  readSensors();
  publishTelemetry();
  delay(5000);
}
```

---

## 🖥️ Frontend

Vistas:

* Dashboard
* Job Detail
* Alerts Panel
* Telemetry charts
* AI insights

---

## 📁 Estructura del Proyecto

### Backend

```
/backend
  /controllers
  /services
  /repositories
  /ai
```

### Infra

```
/infra
```

### IoT

```
/iot
```

### Frontend

```
/frontend
```

---

## 🎯 Primera Iteración

* ESP32 enviando datos
* Lambda guardando
* Endpoint GET telemetría
* UI básica

---

## 🚀 Resultado

Arquitectura completa lista para implementación real.

---
