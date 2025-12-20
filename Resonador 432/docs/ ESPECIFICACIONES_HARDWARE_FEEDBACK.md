# ESPECIFICACIONES DE HARDWARE - SISTEMA DE FEEDBACK

## Componentes Críticos para el Bucle Cerrado

### 1. Unidad de Sensado (Entrada)
| Componente | Modelo/Especificación | Función en el Sistema |
| :--- | :--- | :--- |
| **Acelerómetro/Giroscopio** | MPU-6050 (3 ejes, ±2g) | **Mide la vibración mecánica** del tejido en tiempo real. Es el sensor primario para el feedback. |
| **Sensor de Temperatura** | MLX90614 (±0.3°C) | Monitorea cambios térmicos como proxy de inflamación. |
| **Microcontrolador** | ESP32-WROOM-32 | Procesa señales del sensor, ejecuta el algoritmo y controla los actuadores. |

### 2. Unidad de Actuación (Salida)
| Componente | Modelo/Especificación | Función en el Sistema |
| :--- | :--- | :--- |
| **Actuador de Vibración (12 Hz)** | Motor DC de 6mm + Driver DRV8833 | **Genera la vibración mecánica terapéutica**. El driver permite control PWM de velocidad precisa. |
| **Generador de Campo Magnético (432 Hz)** | Bobina plana de PCB (16 espiras) + Puente H | Genera el campo magnético pulsante. |

### 3. Diagrama de Conexiones (ESQUEMA CLAVE)
```
                [ TEJIDO ]
                    |
                    | (Vibración Mecánica)
                    ▼
              [ MPU-6050 ] --- I2C ---> [ ESP32 ] <--- PWM --- [ Driver Motor ] ---> [ Motor 12Hz ]
                    |                          |                      |
                    | (Temperatura)            | <--- PWM --- [ Puente H ] -------> [ Bobina 432Hz ]
                    ▼                          |
            [ MLX90614 ] --- I2C --------------'
```
