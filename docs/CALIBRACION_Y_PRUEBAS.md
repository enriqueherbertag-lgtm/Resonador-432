# GUÍA: Calibración y Pruebas del Sistema de Feedback

## Prueba 1: Validación del Sensor MPU-6050
**Objetivo**: Asegurar que el sensor lee vibraciones reales.
**Procedimiento**:
1. Subir un sketch simple que imprima los valores X, Y, Z del acelerómetro.
2. Golpear suavemente la mesa donde está el sensor. Los valores deben cambiar abruptamente.
3. Dejar el sensor en reposo. Los valores deben ser estables (≈ 0g en X,Y; ≈ 1g en Z).

## Prueba 2: Calibración de la Frecuencia del Motor (12 Hz)
**Objetivo**: Ajustar el PWM para que el motor gire a ~720 RPM (12 revoluciones por segundo).
**Procedimiento**:
1. Conectar un **sensor de efecto Hall** o un **encoder óptico** al motor.
2. Subir un código que varíe el valor PWM de 0 a 255 y mida la RPM resultante.
3. Graficar PWM vs. RPM y encontrar el valor que da **720 RPM**. Ese será el PWM para 12 Hz.

## Prueba 3: Integración y Bucle Cerrado
**Objetivo**: Verificar que el sistema completo responde a estímulos.
**Setup Simulado**:
- Pegar el prototipo a un **gelatin** (simula tejido).
- Con un **segundo motor externo**, vibrar la gelatina a una frecuencia distinta a 12 Hz (ej. 8 Hz).
**Resultado Esperado**:
El sistema debe detectar la vibración a 8 Hz (como "caótica") y encender su motor interno a máxima potencia para intentar imponer los 12 Hz.
