# Resonador 432 - Sistema de Feedback de Frecuencia

> **Nota**: Este repositorio contiene la **implementación técnica y de ingeniería** del sistema de medición y actuación con feedback del proyecto Resonador 432. Para la documentación del anteproyecto (visión, negocio, regulatorio), consulta la carpeta [`documentos_anteproyecto/`](./documentos_anteproyecto).

## 🎯 Objetivo Técnico
Implementar un sistema de bucle cerrado (closed-loop) que:
1.  **Mide** la vibración mecánica de un tejido en tiempo real mediante un acelerómetro (MPU-6050).
2.  **Analiza** la señal para determinar su desviación de una línea base.
3.  **Actúa** aplicando una frecuencia mecánica de 12 Hz y una magnética de 432 Hz, ajustando la potencia en base a la medición.

## ⚙️ Arquitectura del Sistema
El núcleo del sistema es un microcontrolador ESP32 que orquesta los siguientes componentes:

| Módulo | Componente | Función |
| :--- | :--- | :--- |
| **Entrada (Sensado)** | MPU-6050 | Mide la vibración/oscillación del tejido. |
| **Procesamiento** | ESP32 (Dual Core) | Ejecuta el algoritmo de feedback. |
| **Salida (Actuación)** | Motor DC + Bobina PCB | Genera la terapia (12 Hz mecánico + 432 Hz magnético). |

**Diagrama de Flujo Simplificado:**
[Sensor MPU6050] -> [ESP32 (Analisis)] -> [Actuadores (Motor + Bobina)]
^ |
| v
+------------------[Tejido]-------------------------+

text

## 📁 Estructura del Repositorio
- [`/firmware`](./firmware) - Código fuente para el ESP32 (Arduino Core).
- [`/docs`](./docs) - **Documentación técnica detallada de desarrollo** (especificaciones, protocolos, lista de materiales, guías).
- [`/documentos_anteproyecto`](./documentos_anteproyecto) - Documentos de visión, negocio y regulatorios (capa conceptual del proyecto).

## 🚀 Primeros Pasos
1.  Revisa las **especificaciones de hardware** en [`/docs/01_ESPECIFICACIONES_HARDWARE_FEEDBACK.md`](./docs/01_ESPECIFICACIONES_HARDWARE_FEEDBACK.md).
2.  Consulta el **protocolo de medición y el algoritmo de feedback** en [`/docs/02_PROTOCOLO_MEDICION_FEEDBACK.md`](./docs/02_PROTOCOLO_MEDICION_FEEDBACK.md).
3.  Carga el firmware (`/firmware/resonador432_firmware.ino`) en una placa ESP32.

## 📄 Licencia
El código fuente y la documentación de este repositorio se publican bajo la **Licencia Pública General de GNU v3.0 (GPLv3)**.
Consulta el archivo [LICENSE](./LICENSE) para los términos completos.

**Para uso comercial bajo una licencia propietaria diferente** (que no requiere publicar modificaciones), consulta los términos en [COMERCIAL.md](./COMERCIAL.md) o contacta al autor.

