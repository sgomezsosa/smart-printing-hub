# SmartPrint Hub

## AI + IoT Platform for 3D Printing Operations

---

## 🎯 Objetivo del Proyecto

Diseñar y construir una plataforma inteligente que integre:

* Hardware (ESP32 + sensores)
* Cloud (AWS)
* Inteligencia Artificial

Para mejorar el monitoreo, trazabilidad y calidad de procesos de impresión 3D.

---

## 🧠 Problema que Resuelve

* Fallas en impresión por condiciones ambientales
* Falta de trazabilidad de trabajos
* Mala comunicación con clientes
* Falta de insights operativos

---

## 🏗️ Arquitectura General

ESP32 → AWS IoT Core → Lambda → DynamoDB → API Gateway → Frontend
↓
IA (LLM)

---

## 🔌 Componentes

### 1. Hardware (ESP32)

Sensores:

* Temperatura
* Humedad
* Vibración
* Estado de puerta

Opcionales:

* OLED display
* LEDs
* Botón físico

---

### 2. Cloud (AWS)

* AWS IoT Core
* AWS Lambda
* DynamoDB
* API Gateway
* S3
* SNS
* Bedrock (IA)

---

### 3. IA

Funciones:

* Explicación de alertas
* Recomendaciones
* Resumen de trabajos
* Asistente de pedidos

---

### 4. Frontend

Dashboard con:

* Telemetría
* Trabajos activos
* Alertas
* Recomendaciones IA

---

## 🔄 Flujo de Uso

1. Cliente solicita pieza
2. Sistema genera especificaciones con IA
3. Se crea un Job
4. ESP32 monitorea condiciones
5. AWS procesa eventos
6. IA genera alertas y recomendaciones
7. Se genera resumen final

---

## 📊 Modelo de Datos

* printers
* jobs
* sensor_readings
* alerts
* recommendations
* customers

---

## 🤖 Funciones de IA

### 1. Explicación de alertas

Transforma datos técnicos en lenguaje natural

### 2. Recomendaciones

Sugerencias basadas en condiciones

### 3. Resumen automático

Reporte final del trabajo

### 4. Intake de pedidos

Transforma texto del cliente en requerimientos

---

## 🧪 MVP (2–3 semanas)

### Semana 1

* Setup ESP32
* Envío de datos a AWS IoT
* Persistencia en DynamoDB

### Semana 2

* Backend + API
* Dashboard básico
* Reglas de alertas

### Semana 3

* Integración IA
* Resúmenes automáticos
* Demo final

---

## 🧰 Stack Tecnológico

### Hardware

* ESP32
* DHT22 / SHT31
* Sensor vibración
* Reed switch

### Backend

* Java (Spring Boot)
* AWS Lambda

### Frontend

* React / Next.js

### Cloud

* AWS IoT Core
* DynamoDB
* API Gateway
* Bedrock

---

## 🚀 Valor Profesional

Demuestra:

* Arquitectura cloud
* IoT
* IA aplicada
* Diseño de sistemas
* Integración hardware-software

---

## 🏷️ Nombre para Portfolio

**SmartPrint Hub: AI + IoT Monitoring for 3D Printing Operations**

---

## ⚠️ Alcance Controlado

Evitar inicialmente:

* Visión por cámara
* Generación de STL con IA
* Control automático completo
* App móvil nativa

---

## 📌 Conclusión

Proyecto ideal para posicionarte como:

* AWS Solutions Architect
* AI Engineer
* Maker innovador

---
