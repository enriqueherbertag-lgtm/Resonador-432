# Resonador-432: Terapia por resonancia mecánica (vibración) para cáncer

[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.19342270.svg)](https://doi.org/10.5281/zenodo.19342270)
[![License](https://img.shields.io/badge/License-Proprietary-red.svg)](LICENSE)
[![EN](https://img.shields.io/badge/English-version-blue.svg)](./README.en.md)

**No es magnético. Es vibracional.**

Los tratamientos convencionales contra el cáncer (quimioterapia, radiación) son invasivos, agresivos y con efectos secundarios severos. La resonancia magnética (MRI) es diagnóstica, no terapéutica.

Resonador-432 explora un camino diferente: usar frecuencias de vibración específicas para inducir efectos mecánicos en las células tumorales.

## Que hace

El dispositivo genera vibraciones en el rango de 432 Hz y sus armónicos. Está controlado por un ESP32 y utiliza un acelerómetro MPU-6050 para medir la vibración real y ajustarla en tiempo real.

Modos de operación:
- Frecuencia fija.
- Barrido lineal (recorre un rango de frecuencias).
- Barrido logarítmico.
- Modulación por pulsos.

Componentes principales:
- Generador de vibración: motor DC + bobina o elemento piezoeléctrico.
- Control: ESP32 (firmware personalizado).
- Sensor: acelerómetro MPU-6050.
- Alimentación: 5V DC.

## Para quién es

- Investigadores en biofísica y terapia por vibración.
- Desarrolladores de dispositivos médicos experimentales.
- Colaboradores interesados en validación preclínica.

## Estado actual

- Firmware funcional.
- Esquemas electrónicos documentados.
- Algoritmos de control implementados.
- Prototipo funcional (pendiente de pruebas biológicas).
- Validación clínica (pendiente).

## Aviso importante

Este es un proyecto de investigación aplicada. No es un dispositivo médico comercial ni ha sido validado clínicamente. Se comparte para exploración científica y desarrollo colaborativo.

## Proyectos relacionados

- CORPUS — sistemas corporales artificiales
- ENA — interfaz cerebro-máquina
- OsteoFlux — vibración adaptativa para osteoporosis

## Licencia

Copyright © 2026 Enrique Aguayo. Todos los derechos reservados.

Este proyecto está protegido por derechos de autor.

PERMITIDO:
- Uso no comercial con fines educativos o de investigación.
- Distribución sin modificación, siempre que se mantenga esta licencia y se dé crédito al autor.

PROHIBIDO sin autorización expresa por escrito:
- Uso comercial (incluyendo, pero no limitado a: ofrecerlo como servicio, SaaS, suscripción, integración en productos que generen ingresos, o cualquier uso que genere beneficio económico directo o indirecto).
- Modificación para entornos de producción.
- Distribución de versiones modificadas sin autorización.

Para licencias comerciales, soporte técnico, pilotos empresariales o consultas:
Contacto: eaguayo@migst.cl

Cualquier uso fuera de los términos permitidos requiere permiso previo del autor.

Las consultas comerciales son bienvenidas y se responderán en un plazo máximo de 7 días hábiles.

## Autor

Enrique Aguayo H.
Mackiber Labs
Contacto: eaguayo@migst.cl
ORCID: 0009-0004-4615-6825
GitHub: @enriqueherbertag-lgtm

Documentación asistida por Ana (DeepSeek), IA para investigación y optimización técnica.
