# SmartPrint Hub

## AI + IoT Platform for 3D Printing Operations

---

# 🚀 IMPLEMENTACIÓN PASO A PASO (ESP32 + AWS IoT)

Este documento describe cómo construir el MVP desde cero, comenzando por la integración entre ESP32 y AWS IoT Core.

---

## 🎯 Objetivo de esta fase

Lograr que:

1. ESP32 lea sensores
2. Envíe datos vía MQTT
3. AWS IoT Core reciba los datos
4. Lambda procese y guarde en DynamoDB

---

# 🔧 1. Requisitos

## Hardware

* ESP32
* Sensor DHT22 (temperatura/humedad)
* Cables

## Software

* Arduino IDE
* Cuenta AWS

---

# ☁️ 2. Configuración AWS IoT Core

## 2.1 Crear Thing

1. Ir a AWS IoT Core
2. Crear "Thing"
3. Nombre: `esp32-smartprint-01`

---

## 2.2 Certificados

1. Crear certificados
2. Descargar:

    * certificate.pem
    * private.key
    * AmazonRootCA1.pem

---

## 2.3 Política IoT

Crear policy:

```json
{
  "Version": "2012-10-17",
  "Statement": [
    {
      "Effect": "Allow",
      "Action": [
        "iot:Connect",
        "iot:Publish",
        "iot:Subscribe",
        "iot:Receive"
      ],
      "Resource": "*"
    }
  ]
}
```

Asignar policy al certificado.

---

# 📡 3. Código ESP32

## Librerías necesarias

* WiFi.h
* PubSubClient.h
* DHT.h

---

## Código base

```cpp
#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "TU_WIFI";
const char* password = "TU_PASSWORD";

const char* mqtt_server = "YOUR_ENDPOINT.iot.region.amazonaws.com";

WiFiClientSecure espClient;
PubSubClient client(espClient);

void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void reconnect() {
  while (!client.connected()) {
    client.connect("ESP32Client");
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  setup_wifi();
  client.setServer(mqtt_server, 8883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  String payload = "{";
  payload += "\"temperature\":" + String(temp) + ",";
  payload += "\"humidity\":" + String(hum);
  payload += "}";

  client.publish("smartprint/esp32-01/telemetry", payload.c_str());

  delay(5000);
}
```

---

# 📥 4. AWS IoT Rule

SQL:

```sql
SELECT * FROM 'smartprint/+/telemetry'
```

Acción:

* Enviar a Lambda

---

# ⚙️ 5. Lambda (Python)

```python
import json
import boto3

client = boto3.resource('dynamodb')
table = client.Table('sensor_readings')

def lambda_handler(event, context):
    table.put_item(Item={
        'deviceId': 'esp32-01',
        'timestamp': int(event['timestamp']),
        'temperature': event['temperature'],
        'humidity': event['humidity']
    })
    return {
        'statusCode': 200
    }
```

---

# 🗄️ 6. DynamoDB

Tabla: `sensor_readings`

* Partition Key: deviceId
* Sort Key: timestamp

---

# 🧪 7. Validación

Checklist:

* ESP32 conectado a WiFi
* Datos visibles en AWS IoT Core (Test MQTT)
* Lambda ejecutándose
* Datos almacenados en DynamoDB

---

# 🚀 Próximos pasos

1. Agregar más sensores
2. Crear backend Spring Boot
3. Crear dashboard
4. Integrar IA (Bedrock)

---

# 🧠 Resultado

Al completar esta fase tendrás:

✅ IoT funcionando
✅ Datos en la nube
✅ Base real del proyecto

---
