# LISTA DE MATERIALES (Bill of Materials) - PROTOTIPO FEEDBACK

Esta lista cubre todos los componentes necesarios para construir un prototipo funcional del sistema de bucle cerrado.

## Electrónica Principal
| Cantidad | Componente | Especificación | Proveedor Ejemplo | Precio Aprox. (USD) |
| :--- | :--- | :--- | :--- | :--- |
| 1 | Microcontrolador ESP32 Dev Board | ESP32-WROOM-32, con USB | Sparkfun, Adafruit | 8.00 |
| 1 | Sensor MPU-6050 | Acelerómetro/Giroscopio 3 ejes | Invensense | 4.50 |
| 1 | Sensor de Temperatura MLX90614 | Infrarrojo, sin contacto | Melexis | 12.00 |

## Módulos de Actuación
| Cantidad | Componente | Especificación | Función |
| :--- | :--- | :--- | :--- |
| 1 | Motor de Vibración DC | 6mm, 3V, 9000 RPM | Generar vibración a ~12 Hz |
| 1 | Driver de Motor | DRV8833 o L9110S | Control PWM del motor |
| 1 | Bobina Magnética | 10mH, baja resistencia | Generar campo a 432 Hz |
| 1 | Puente H para Bobina | IC L298N o similar | Conmutar corriente de la bobina |

## Otros
| Cantidad | Componente | Notas |
| :--- | :--- | :--- |
| 1 | Batería LiPo | 3.7V, 500mAh |
| 1 | Cargador inalámbrico Qi | Módulo receptor |
| 1 | PCB personalizado | Para integración final |
| - | Cables, soldadura, carcasa | - |

**COSTO TOTAL ESTIMADO POR PROTOTIPO:** ~$45-60 USD.
