# Software - Resonador-432

Esta carpeta contiene el firmware y software de control del dispositivo.

## Contenido planificado

- `firmware/` — código para ESP32 (generación de frecuencias, control del motor, lectura del acelerómetro).
- `gui/` — interfaz gráfica para control remoto (opcional).
- `scripts/` — scripts de prueba y calibración.

## Firmware

El firmware está escrito en C++ para ESP32. Funcionalidades:

- Generación de señales PWM para control del motor.
- Lectura del acelerómetro MPU-6050 (I2C).
- Modos de operación: frecuencia fija, barrido lineal, barrido logarítmico, modulación por pulsos.
- Comunicación serie para configuración remota.

## Estado

- Firmware funcional.
- GUI pendiente.
- Scripts de prueba pendientes.
