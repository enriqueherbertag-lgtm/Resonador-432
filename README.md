# Resonador 432 - Sistema de Feedback de Frecuencia

[![License: CC BY-NC 4.0](https://img.shields.io/badge/License-CC_BY--NC_4.0-lightgrey.svg)](https://creativecommons.org/licenses/by-nc/4.0/)

> **Nota**: Este repositorio contiene la **implementación técnica y de ingeniería** del sistema de medición y actuación con feedback del proyecto Resonador 432. Para la documentación del anteproyecto (visión, negocio, regulatorio), consulta la carpeta `documentos_anteproyecto/`.

---

##  Objetivo Técnico

Implementar un sistema de bucle cerrado (closed-loop) que:

1. **Mide** la vibración mecánica de un tejido en tiempo real mediante un acelerómetro (MPU-6050).
2. **Analiza** la señal para determinar su desviación de una línea base.
3. **Actúa** aplicando una frecuencia mecánica de 12 Hz y una magnética de 432 Hz, ajustando la potencia en base a la medición.

---
## Cita

Si usás Goliat-Orbital en tu investigación, por favor citá:

Aguayo H., E. (2026). Goliat-Orbital: Captura y reciclaje de basura espacial (v1.0.0). Zenodo. https://doi.org/10.5281/zenodo.<img width="191" height="20" alt="image" src="https://github.com/user-attachments/assets/52e6fd22-02a5-4e8b-8e44-35187028d0e0" />





##  Arquitectura del Sistema

El núcleo del sistema es un microcontrolador ESP32 que orquesta los siguientes componentes:

| Módulo | Componente | Función |
|--------|------------|---------|
| **Entrada (Sensado)** | MPU-6050 | Mide la vibración/oscillación del tejido. |
| **Procesamiento** | ESP32 (Dual Core) | Ejecuta el algoritmo de feedback. |
| **Salida (Actuación)** | Motor DC + Bobina PCB | Genera la terapia (12 Hz mecánico + 432 Hz magnético). |

**Diagrama de Flujo Simplificado:**

[Sensor MPU6050] → [ESP32 (Análisis)] → [Actuadores (Motor + Bobina)]
↑ ↓
└─────────────── [Tejido] ────────────────┘


---

##  Estructura del Repositorio

- `/firmware` — Código fuente para el ESP32 (Arduino Core).
- `/docs` — **Documentación técnica detallada de desarrollo** (especificaciones, protocolos, lista de materiales, guías).
- `/documentos_anteproyecto` — Documentos de visión, negocio y regulatorios (capa conceptual del proyecto).

---

##  Primeros Pasos

1. Revisa las **especificaciones de hardware** en `/docs/01_ESPECIFICACIONES_HARDWARE_FEEDBACK.md`.
2. Consulta el **protocolo de medición y el algoritmo de feedback** en `/docs/02_PROTOCOLO_MEDICION_FEEDBACK.md`.
3. Carga el firmware (`/firmware/resonador432_firmware.ino`) en una placa ESP32.

---

## Estado actual

 Concepto arquitectónico definido  
 Especificaciones técnicas preliminares  
 Selección de componentes validada  
 Prototipo de hardware integrado  
 Validación clínica  
 Certificación regulatoria

---

## Próximos pasos

1. **Prototipo hardware** — Integrar MPU-6050, ESP32, motor DC y bobina PCB.
2. **Ajuste de algoritmo** — Optimizar feedback en tiempo real.
3. **Pruebas de laboratorio** — Validar en tejidos simulados.
4. **Documentación clínica** — Preparar ensayos para certificación.

---

## Proyectos relacionados

- **CORPUS** — sistema corporal artificial para IA  
  [Repositorio](https://github.com/enriqueherbertag-lgtm/Corpus)
- **ENA** — interfaz cerebro-máquina no invasiva  
  [Repositorio](https://github.com/enriqueherbertag-lgtm/ENA-Enlace-Neural-Avatar)
- **OsteoFlux** — intervención ósea basada en resonancia  
  [Repositorio](https://github.com/enriqueherbertag-lgtm/osteoflux)

---

## Licencia

**CC BY-NC 4.0 (Attribution-NonCommercial 4.0 International)**

Este proyecto está liberado bajo una licencia Creative Commons que permite:
- ✅ Compartir y modificar
- ✅ Uso personal, investigación, prototipos
- ❌ **No permite uso comercial sin autorización expresa**

**¿Quieres usar este diseño comercialmente?**  
Contacta para una licencia comercial: **eaguayo@migst.cl**

[![License: CC BY-NC 4.0](https://img.shields.io/badge/License-CC_BY--NC_4.0-lightgrey.svg)](https://creativecommons.org/licenses/by-nc/4.0/)

---

## Autor

**Enrique Aguayo H.**  
Investigador independiente, Mackiber Labs  
Contacto: eaguayo@migst.cl  
ORCID: 0009-0004-4615-6825  
GitHub: [@enriqueherbertag-lgtm](https://github.com/enriqueherbertag-lgtm)
