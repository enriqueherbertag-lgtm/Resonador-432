/*
  FIRMWARE PRINCIPAL - RESONADOR 432
  Arquitectura: Medir -> Analizar -> Actuar con Feedback
  Componentes: MPU6050 (Sensor), Motor 12Hz, Bobina 432Hz, ESP32 (Control)
*/

#include <Wire.h>
#include <MPU6050.h>

// ===== CONFIGURACIÓN DE PINES Y PARÁMETROS =====
// Pines para el driver del Motor (12 Hz)
#define MOTOR_PWM_PIN 25
#define MOTOR_DIR_PIN 26
// Pin para el control de la Bobina (432 Hz) - Usando un pin PWM
#define BOBINA_PWM_PIN 27

// Parámetros de la sesión
const int DURACION_SESION_MS = 20 * 60 * 1000; // 20 minutos
const int INTERVALO_MEDICION_MS = 100; // Medir cada 100ms
const float FRECUENCIA_OBJETIVO = 12.0; // Hz (para el motor)
const int POTENCIA_MOTOR_INICIAL = 128; // Valor PWM inicial (0-255)

// ===== DECLARACIÓN DE OBJETOS =====
MPU6050 mpu;
float vibracionBase = 0.0; // Línea base de vibración al inicio

// ===== SETUP INICIAL =====
void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  // Inicializar MPU6050
  if(!mpu.begin()) {
    Serial.println("ERROR: No se encuentra el MPU6050");
    while(1);
  }
  mpu.calcGyroOffsets(); // Calibrar sensor (opcional, mantener sensor quieto)
  
  // Configurar pines de salida
  pinMode(MOTOR_PWM_PIN, OUTPUT);
  pinMode(MOTOR_DIR_PIN, OUTPUT);
  pinMode(BOBINA_PWM_PIN, OUTPUT);
  
  digitalWrite(MOTOR_DIR_PIN, HIGH); // Sentido de giro fijo
  Serial.println("=== SISTEMA RESONADOR 432 INICIADO ===");
  
  // Paso 1: Establecer LÍNEA BASE de vibración del tejido
  establecerLineaBase();
}

// ===== BUCLE PRINCIPAL =====
void loop() {
  // El sistema opera por sesiones. Este loop puede estar desactivado
  // hasta recibir un comando por Bluetooth para iniciar una sesión.
  // Por ahora, inicia una sesión de ejemplo al arrancar.
  if (false) { // Cambiar a 'true' para probar una sesión automática
    ejecutarSesionTerapeutica();
  }
  delay(1000);
}

// ===== FUNCIÓN CRÍTICA 1: Medir Vibración Instantánea =====
float medirVibracionInstantanea() {
  // Lee el acelerómetro y devuelve la desviación total (indicador de "ruido" vibratorio)
  mpu.update();
  float ax = mpu.getAccX();
  float ay = mpu.getAccY();
  float az = mpu.getAccZ();
  
  // Cálculo simple de magnitud de vibración (se puede refinar con FFT en Python)
  float magnitudVib = sqrt(ax*ax + ay*ay + az*az);
  return magnitudVib;
}

// ===== FUNCIÓN CRÍTICA 2: Establecer Línea Base =====
void establecerLineaBase() {
  Serial.println("Estableciendo línea base de vibración... (No mover el dispositivo)");
  delay(2000);
  float suma = 0;
  int lecturas = 50;
  
  for(int i=0; i<lecturas; i++) {
    suma += medirVibracionInstantanea();
    delay(50);
  }
  vibracionBase = suma / lecturas;
  Serial.print("Línea base establecida: ");
  Serial.println(vibracionBase);
}

// ===== FUNCIÓN CRÍTICA 3: Controlar Motor (12 Hz) =====
void controlarMotor(float potenciaNormalizada) {
  // Convierte una potencia normalizada (0.0 a 1.0) a un valor PWM
  // Para generar ~12 Hz, necesitamos un motor que gire a 720 RPM.
  // Esto se logra con un valor PWM fijo, que se calibrará empíricamente.
  int valorPWM = (int)(potenciaNormalizada * 255);
  valorPWM = constrain(valorPWM, 0, 255);
  analogWrite(MOTOR_PWM_PIN, valorPWM);
}

// ===== FUNCIÓN CRÍTICA 4: Controlar Bobina (432 Hz) =====
void controlarBobina(bool encender) {
  // Genera una señal cuadrada de ~432 Hz en el pin de la bobina.
  // Usamos tone() para simplicidad. En producción, usar un temporizador de hardware.
  if(encender) {
    // tone(BOBINA_PWM_PIN, 432); // Usar si el hardware lo soporta
    digitalWrite(BOBINA_PWM_PIN, HIGH); // Simulación: encendido constante
  } else {
    // noTone(BOBINA_PWM_PIN);
    digitalWrite(BOBINA_PWM_PIN, LOW);
  }
}

// ===== FUNCIÓN CRÍTICA 5: Ejecutar Sesión Terapéutica con FEEDBACK =====
void ejecutarSesionTerapeutica() {
  Serial.println("\n>>> INICIANDO SESIÓN TERAPÉUTICA <<<");
  
  // Encender actuadores con potencia inicial
  controlarMotor(0.5); // 50% de potencia inicial
  controlarBobina(true);
  
  unsigned long tiempoInicio = millis();
  
  while(millis() - tiempoInicio < DURACION_SESION_MS) {
    // PASO 1: MEDIR
    float vibracionActual = medirVibracionInstantanea();
    float desviacion = vibracionActual - vibracionBase;
    
    // PASO 2: ANALIZAR (Algoritmo de Feedback Simple)
    float ajusteMotor = 0.5; // Potencia base 50%
    
    if(desviacion > 0.5) { // Si la vibración está MUY ALTA (tejido caótico)
      ajusteMotor = 0.8; // Aumentar potencia para imponer ritmo
    } else if(desviacion < -0.1) { // Si la vibración está MUY BAJA (tejido rígido/silenciado)
      ajusteMotor = 0.3; // Reducir potencia para estimulación suave
    }
    // PASO 3: ACTUAR (Aplicar corrección)
    controlarMotor(ajusteMotor);
    
    // Reportar por serial
    Serial.print("Vib: ");
    Serial.print(vibracionActual);
    Serial.print(" | Desv: ");
    Serial.print(desviacion);
    Serial.print(" | Motor PWM: ");
    Serial.println((int)(ajusteMotor*255));
    
    delay(INTERVALO_MEDICION_MS); // Ciclo de feedback
  }
  
  // FINALIZAR SESIÓN
  controlarMotor(0.0);
  controlarBobina(false);
  Serial.println(">>> SESIÓN TERAPÉUTICA FINALIZADA <<<");
}
