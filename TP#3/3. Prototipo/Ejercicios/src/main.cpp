/*Ejercicio 1: Encender un LED
• Enciende el led1 conectado al GPIO18 de forma continua.
#include <Arduino.h>

#define led1 18

void setup() {

  pinMode(led1, OUTPUT);

}

void loop() {

  digitalWrite(led1, HIGH);
  delay(500);
}

/*Ejercicio 2: Parpadeo de un LED
• Programa el led1 para que parpadee con un intervalo de 1
segundo.

#include <Arduino.h>

#define led1 18

void setup() {

  pinMode(led1, OUTPUT);

}

void loop() {

  digitalWrite(led1, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  delay(500);

}

Ejercicio 3: Secuencia de LEDs
• Crea una secuencia que encienda los LEDs del led1 al led3 de
forma sucesiva, cada uno durante 500ms.

#include <Arduino.h>

// Definir los pines a los que están conectados los LEDs
#define led1  18
#define led2  5
#define led3  17

void setup() {
  // Configurar los pines de los LEDs como salidas
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // Encender LED1
  digitalWrite(led1, HIGH);
  delay(500); // Esperar 500ms
  digitalWrite(led1, LOW);
  // Encender LED2
  digitalWrite(led2, HIGH);
  delay(500); // Esperar 500ms
  digitalWrite(led2, LOW);
  // Encender LED3
  digitalWrite(led3, HIGH);
  delay(500); // Esperar 500ms
  digitalWrite(led3, LOW);
}

Ejercicio 4: Control de LED con botón
• Usa el btn1 para encender el led1 mientras se mantenga
presionado.

#include <Arduino.h>

// Definir los pines
#define btn1 34
#define led1 18

// Configurar los pines LED y botón
void setup() {
  pinMode(btn1, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
}

void loop() {
  // Leer el estado del botón
  int botonState = digitalRead(btn1);

  // Si el botón está presionado (estado LOW), encender el LED
  if (botonState == LOW) {
    digitalWrite(led1, HIGH);
   else 
    digitalWrite(led1, LOW);
  }
}

-------NIVEL INTERMEDIO---------

Ejercicio 5: Uso de botón con estado
• Cambia el estado del led1 cada vez que se presione y suelte el
btn1.

#include <Arduino.h>

// Definir los pines
#define led1 18
#define btn1 34

bool ledState = false;    // Estado del LED
bool botonState = false; // Estado actual del botón
bool lastButtonState = false; // Último estado del botón

// Configurar los pines LED y botón
void setup() {
  pinMode(btn1, INPUT_PULLUP); // Configura el pin del botón como entrada con resistencia pull-up interna
  pinMode(led1, OUTPUT); // Configura el pin del LED como salida

  digitalWrite(led1, ledState);// Inicializa el LED en apagado
}


void loop() {
  // Leer el estado del botón
  int botonState = digitalRead(btn1);

  // Si el botón está presionado (estado LOW), encender el LED
  if (botonState != lastButtonState) {
    // si el boton ha sido presionado
    if (botonState == LOW) {
      ledState = !ledState; // Cambia el estado del LED
      digitalWrite(led1, ledState); // Actualiza el LED

    }
    // Guarda el estado del botón
    delay(50); // Debounce delay
  }
  lastButtonState = botonState;
}

Ejercicio 6: Debounce de botón
• Implementa una lógica de debounce en el btn1 para evitar
lecturas erróneas.

#include <Arduino.h>

#define led1 18 // Pin del LED
#define btn1 34 // Pin del boton

bool ledState = false;    // Estado del LED
bool botonState = false; // Estado actual del botón
bool lastButtonState = false; // Último estado del botón

unsigned long lastDebounceTime = 0;  // Último tiempo de cambio del botón
unsigned long debounceDelay = 0.10;    // Tiempo de debounce (en milisegundos)


void setup() {
  pinMode(btn1, INPUT_PULLUP); // Configura el pin del botón como entrada con resistencia pull-up interna
  pinMode(led1, OUTPUT); // Configura el pin del LED como salida

  digitalWrite(led1, ledState);// Inicializa el LED en apagado
}

void loop () {

  int reading = digitalRead(btn1); // Lee el estado del boton

  // Si el estado del botón ha cambiado, reinicia el temporizador de debounce
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

    // Si ha pasado el tiempo de debounce, considera la lectura como estable
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Si el estado ha cambiado
    if (reading != lastButtonState) {
      botonState = reading;

 // Solo cambia el estado del LED si el botón está presionado (estado bajo)
      if (botonState == LOW) {
        ledState = !ledState;
        digitalWrite(led1, ledState);
      }
    }
  }

 // Guarda el estado del botón para la próxima lectura
  lastButtonState = reading;

}

Ejercicio 7: Control de múltiples LEDs con botones
• Usa btn1 y btn2 para controlar el estado de led1 y led2
respectivamente.


#include <Arduino.h>

#define led1 18 // Pin del LED
#define led2 5
#define btn1 34 // Pin del boton
#define btn2 39


bool ledState1 = false;     // Estado del LED 1
bool ledState2 = false;     // Estado del LED 2

bool botonState1 = false;      // Estado actual del botón 1
bool lastButtonState1 = false;  // Último estado del botón 1
bool botonState2 = false;      // Estado actual del botón 2
bool lastButtonState2 = false;  // Último estado del botón 2

unsigned long lastDebounceTime1 = 0;  // Último tiempo de cambio del botón 1
unsigned long lastDebounceTime2 = 0;  // Último tiempo de cambio del botón 2
unsigned long debounceDelay = 0.10;     // Tiempo de debounce (en milisegundos)


void setup() {
  pinMode(btn1, INPUT_PULLUP); // Configura el pin del botón 1 como entrada con resistencia pull-up interna
  pinMode(btn2, INPUT_PULLUP); // Configura el pin del botón 2 como entrada con resistencia pull-up interna
  pinMode(led1, OUTPUT); // Configura el pin del LED 1 como salida
  pinMode(led2, OUTPUT); // Configura el pin del LED 2 como salida
  
  digitalWrite(led1, ledState1);// Inicializa el LED 1 en apagado
  digitalWrite(led2, ledState2);// Inicializa el LED 2 en apagado

}

void loop() {
  int reading1 = digitalRead(btn1); // Lee el estado del botón 1
  int reading2 = digitalRead(btn2); // Lee el estado del botón 2

    // Debounce para el botón 1
  if (reading1 != lastButtonState1) {
    lastDebounceTime1 = millis();
  }


  if ((millis() - lastDebounceTime1) > debounceDelay) {
    if (reading1 != botonState1) {
      botonState1 = reading1;

      if (botonState1 == LOW) {
        ledState1 = !ledState1;
        digitalWrite(led1, ledState1);
      }
    }
  }

  // Debounce para el botón 2
  if (reading2 != lastButtonState2) {
    lastDebounceTime2 = millis();
  }

  if ((millis() - lastDebounceTime2) > debounceDelay) {
    if (reading2 != botonState2) {
      botonState2 = reading2;

      if (botonState2 == LOW) {
        ledState2 = !ledState2;
        digitalWrite(led2, ledState2);
      }
    }
  }

  // Guarda el estado del botón para la próxima lectura
  lastButtonState1 = reading1;
  lastButtonState2 = reading2;
}


Ejercicio 8: Uso de dip switches para control de LEDs
• Lee el estado de los dip switches sw1.1 a sw1.8 y refleja el
estado en los led1 a led8.


#include <Arduino.h>
const int leds[8] = {18, 5, 17, 16, 4, 0, 2, 15}; 

// Definimos los pines switches
const int swis[8] = {13, 12, 14, 27, 26, 25, 33, 32};

void setup() {
  // Configurar pines de DIP switches como entrada
  for (int i = 0; i < 8; i++) {
    pinMode(swis[i], INPUT_PULLUP);  // si el switch conecta a GND cuando está activado
  }
  
  // Configurar pines de LEDs como salida
  for (int i = 0; i < 8; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // Leer estado de los DIP switches y reflejar en los LEDs
  for (int i = 0; i < 8; i++) {
    int switchState = digitalRead(swis[i]);
    digitalWrite(leds[i], switchState);
  }
  
  delay(100);  // Pequeño retardo para evitar lecturas inestables
}

 -------NIVEL AVANZADO---------

Ejercicio 9: Secuencia de LEDs con botón
• Crea una secuencia de luces que avance cada vez que se
presione btn1.



#include <Arduino.h>

#define led1 18 //Definir pines del LED
#define led2 5
#define led3 17

#define btn1 34 // Definir boton
int currentLED = 0; // LED que está encendido actualmente
bool botonState = LOW;  // Estado actual del botón
bool lastBotonState = LOW; // Último estado del botón


void setup() {
  // Configurar los pines de los LEDs como salidas
  pinMode(btn1, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {

    // Leer el estado del botón
  int botonState = digitalRead(btn1);

  // Si el botón está presionado (estado LOW), encender el LED
  if (botonState == LOW) 

  // Encender LED1
  digitalWrite(led1, HIGH);
  delay(500); // Esperar 500ms
  digitalWrite(led1, LOW);
  // Encender LED2
  digitalWrite(led2, HIGH);
  delay(500); // Esperar 500ms
  digitalWrite(led2, LOW);
  // Encender LED3
  digitalWrite(led3, HIGH);
  delay(500); // Esperar 500ms
  digitalWrite(led3, LOW);
}


#include <Arduino.h>

#define led1 18  // Definir pines del LED
#define led2 5
#define led3 17
#define led4 16

#define btn1 34  // Definir botón

int currentLED = 0;  // LED que está encendido actualmente
bool botonState = LOW;  // Estado actual del botón
bool lastBotonState = LOW;  // Último estado del botón

void setup() {
  // Configurar el pin del botón como entrada con pull-up interno
  pinMode(btn1, INPUT_PULLUP);
  
  // Configurar los pines de los LEDs como salidas
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);  // Agregado para led4
  
  // Apagar todos los LEDs al inicio
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void loop() {
  // Leer el estado del botón
  botonState = digitalRead(btn1);

  // Si el botón está presionado (estado LOW), ejecutar la secuencia de LEDs
  if (botonState == LOW) {
    // Encender LED1
    digitalWrite(led1, HIGH);
    delay(500);  // Esperar 500ms
    digitalWrite(led1, LOW);

    // Encender LED2
    digitalWrite(led2, HIGH);
    delay(500);  // Esperar 500ms
    digitalWrite(led2, LOW);

    // Encender LED3
    digitalWrite(led3, HIGH);
    delay(500);  // Esperar 500ms
    digitalWrite(led3, LOW);

    // Encender LED4 (opcional, si decides usarlo)
    digitalWrite(led4, HIGH);
    delay(500);  // Esperar 500ms
    digitalWrite(led4, LOW);
  }
}

Ejercicio 10: Control de velocidad de parpadeo con dip switch

• Utiliza los dip switches sw1.1 a sw1.3 para controlar la velocidad
de parpadeo de led1, asignando distintas velocidades.



// Definición de pines
#include <Arduino.h>

const int sw1 = 13;  // sw1.1
const int sw2 = 12;  // sw1.2
const int sw3 = 14;  // sw1.3
const int led = 2;   // LED

void setup() {
  // Configurar los pines de los switches como entrada
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);

  // Configurar el pin del LED como salida
  pinMode(led, OUTPUT);
}

void loop() {
  // Leer el estado de los switches
  int val1 = digitalRead(sw1);
  int val2 = digitalRead(sw2);
  int val3 = digitalRead(sw3);

  // Convertir las lecturas de los switches en un número binario
  int selector = (val1 << 2) | (val2 << 1) | val3;

  // Asignar diferentes velocidades de parpadeo en función del valor de selector
  int delayTime;
  switch (selector) {
    case 0b000: delayTime = 100; break; // Velocidad 1
    case 0b001: delayTime = 200; break; // Velocidad 2
    case 0b010: delayTime = 300; break; // Velocidad 3
    case 0b011: delayTime = 400; break; // Velocidad 4
    case 0b100: delayTime = 500; break; // Velocidad 5
    case 0b101: delayTime = 600; break; // Velocidad 6
    case 0b110: delayTime = 700; break; // Velocidad 7
    case 0b111: delayTime = 800; break; // Velocidad 8
    default: delayTime = 100; break;
  }

  // Encender el LED
  digitalWrite(led, HIGH);
  delay(delayTime);

  // Apagar el LED
  digitalWrite(led, LOW);
  delay(delayTime);
}


Ejercicio 11: Patrón de parpadeo de LEDs con dip switches
• Establece un patrón de parpadeo para los led1 a led8 basado en
la combinación de estados de sw1.1 a sw1.4.


-- Mas Lento el parpadeo--
#include <Arduino.h>

// Definición de pines para switches
const int sw1 = 13;  // sw1.1
const int sw2 = 12;  // sw1.2
const int sw3 = 14;  // sw1.3
const int sw4 = 27;  // sw1.4

// Definición de pines para LEDs
const int led1 = 18;
const int led2 = 4;
const int led3 = 16;
const int led4 = 17;
const int led5 = 5;
const int led6 = 0;
const int led7 = 2;
const int led8 = 15;

void setup() {
  // Configurar los pines de los switches como entrada
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(sw4, INPUT_PULLUP);

  // Configurar los pines de los LEDs como salida
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
}

void loop() {
  // Leer el estado de los switches
  int val1 = digitalRead(sw1);
  int val2 = digitalRead(sw2);
  int val3 = digitalRead(sw3);
  int val4 = digitalRead(sw4);

  // Crear un patrón basado en los estados de los switches
  int pattern = (val1 << 3) | (val2 << 2) | (val3 << 1) | val4;

  // Aplicar el patrón de encendido/apagado a los LEDs
  digitalWrite(led1, pattern & 0b1000 ? HIGH : LOW);
  digitalWrite(led2, pattern & 0b1000 ? HIGH : LOW);
  digitalWrite(led3, pattern & 0b0100 ? HIGH : LOW);
  digitalWrite(led4, pattern & 0b0100 ? HIGH : LOW);
  digitalWrite(led5, pattern & 0b0010 ? HIGH : LOW);
  digitalWrite(led6, pattern & 0b0010 ? HIGH : LOW);
  digitalWrite(led7, pattern & 0b0001 ? HIGH : LOW);
  digitalWrite(led8, pattern & 0b0001 ? HIGH : LOW);

  // Retardo para parpadeo lento
  delay(500);

  // Apagar todos los LEDs
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);

  // Retardo para parpadeo lento
  delay(500);
}

-- Mas Rapido el parpadeo--
#include <Arduino.h>

// Definición de pines para switches
const int sw1 = 13;  // sw1.1
const int sw2 = 12;  // sw1.2
const int sw3 = 14;  // sw1.3
const int sw4 = 27;  // sw1.4

// Definición de pines para LEDs

const int led1 = 18;
const int led2 = 4;
const int led3 = 16;
const int led4 = 17;
const int led5 = 5;
const int led6 = 0;
const int led7 = 2;
const int led8 = 15;

void setup() {
  // Configurar los pines de los switches como entrada
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(sw4, INPUT_PULLUP);

  // Configurar los pines de los LEDs como salida
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
}

void loop() {
  // Leer el estado de los switches
  int val1 = digitalRead(sw1);
  int val2 = digitalRead(sw2);
  int val3 = digitalRead(sw3);
  int val4 = digitalRead(sw4);

  // Crear un patrón basado en los estados de los switches
  int pattern = (val1 << 3) | (val2 << 2) | (val3 << 1) | val4;

  // Aplicar el patrón de encendido/apagado a los LEDs
  digitalWrite(led1, pattern & 0b1000 ? HIGH : LOW);
  digitalWrite(led2, pattern & 0b1000 ? HIGH : LOW);
  digitalWrite(led3, pattern & 0b0100 ? HIGH : LOW);
  digitalWrite(led4, pattern & 0b0100 ? HIGH : LOW);
  digitalWrite(led5, pattern & 0b0010 ? HIGH : LOW);
  digitalWrite(led6, pattern & 0b0010 ? HIGH : LOW);
  digitalWrite(led7, pattern & 0b0001 ? HIGH : LOW);
  digitalWrite(led8, pattern & 0b0001 ? HIGH : LOW);

  // Retardo para parpadeo rápido
  delay(100); // Ajusta este valor para el parpadeo rápido

  // Apagar todos los LEDs
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);

  // Retardo para parpadeo rápido
  delay(100); // Ajusta este valor para el parpadeo rápido
}

 
 Ejercicio 12: Medidor de pulsaciones
• Programa un contador de pulsaciones utilizando btn1. El número
de pulsaciones debe mostrarse en una secuencia de LEDs (por
ejemplo, led5 a led8 donde cada LED representa una cantidad
de pulsaciones).



#include <Arduino.h>

#define BTN1  34   // Pin para el botón btn1

#define LED2  5  // Pin para el LED2
#define LED3  17   // Pin para el LED3
#define LED4  16   // Pin para el LED4
#define LED5  4   // Pin para el LED5
#define LED6  0   // Pin para el LED6

int contador = 0;
int estadoAnteriorBoton = HIGH;

// Definición de la función antes de su uso
void actualizarLEDs(int num) {
  digitalWrite(LED2, num >= 1 ? HIGH : LOW);
  digitalWrite(LED3, num >= 2 ? HIGH : LOW);
  digitalWrite(LED4, num >= 3 ? HIGH : LOW);
  digitalWrite(LED5, num >= 4 ? HIGH : LOW);
  digitalWrite(LED6, num >= 5 ? HIGH : LOW);
}

void setup() {
  pinMode(BTN1, INPUT_PULLUP); // Configurar btn1 como entrada con resistencia pull-up
  pinMode(LED2, OUTPUT); // Configurar LED2 como salida
  pinMode(LED3, OUTPUT); // Configurar LED3 como salida
  pinMode(LED4, OUTPUT); // Configurar LED4 como salida
  pinMode(LED5, OUTPUT); // Configurar LED5 como salida
  pinMode(LED6, OUTPUT); // Configurar LED6 como salida
}

void loop() {
  int estadoBoton = digitalRead(BTN1);

  // Verificar si el botón ha sido presionado (transición de HIGH a LOW)
  if (estadoBoton == LOW && estadoAnteriorBoton == HIGH) {
    contador++;
    
    if (contador > 5) {
      contador = 5;  // Limitar el contador al número máximo de LEDs
    }
    
    // Actualizar LEDs según el valor del contador
    actualizarLEDs(contador);
  }
  
  // Guardar el estado actual del botón
  estadoAnteriorBoton = estadoBoton;
  
  // Pequeña demora para el debounce
  delay(50);
}

Ejercicio 13: Contraseña con botones
• Implementa un sistema de contraseña usando btn1, btn2, y
btn3 donde una secuencia específica de pulsaciones activa
led1. Si la secuencia es incorrecta, led2 debería encenderse.



#include <Arduino.h>

// Definir los pines de los botones y los LEDs
const int btn1Pin = 34;
const int btn2Pin = 39;
const int btn3Pin = 36;

const int led1Pin = 18;
const int led2Pin = 5;

// Definir la secuencia correcta de pulsaciones (1 para btn1, 2 para btn2, 3 para btn3)
const int correctSequence[] = {1, 2, 3, 1}; // Ejemplo: btn1, btn2, btn3, btn1
const int sequenceLength = sizeof(correctSequence) / sizeof(correctSequence[0]);

int userSequence[sequenceLength]; // Array para almacenar la secuencia del usuario
int sequenceIndex = 0; // Índice para rastrear la secuencia

// Declaración de la función checkSequence()
bool checkSequence();

void setup() {
  pinMode(btn1Pin, INPUT_PULLUP);
  pinMode(btn2Pin, INPUT_PULLUP);
  pinMode(btn3Pin, INPUT_PULLUP);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  
  // Apagamos los LEDs al inicio
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
}

void loop() {
  if (digitalRead(btn1Pin) == LOW) {
    userSequence[sequenceIndex] = 1;
    sequenceIndex++;
    delay(300); // Evitar rebote de botones
  } 
  else if (digitalRead(btn2Pin) == LOW) {
    userSequence[sequenceIndex] = 2;
    sequenceIndex++;
    delay(300);
  } 
  else if (digitalRead(btn3Pin) == LOW) {
    userSequence[sequenceIndex] = 3;
    sequenceIndex++;
    delay(300);
  }

  // Comprobar si se ha completado la secuencia
  if (sequenceIndex == sequenceLength) {
    if (checkSequence()) {
      digitalWrite(led1Pin, HIGH); // Secuencia correcta
      digitalWrite(led2Pin, LOW);
    } else {
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, HIGH); // Secuencia incorrecta
    }
    sequenceIndex = 0; // Reiniciar la secuencia
    delay(1000); // Espera un segundo antes de reiniciar
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
  }
}

bool checkSequence() {
  for (int i = 0; i < sequenceLength; i++) {
    if (userSequence[i] != correctSequence[i]) {
      return false;
    }
  }
  return true;
}



Ejercicio 14: Aplicación de timers para control de LEDs
• Utiliza el temporizador del ESP32 para controlar el parpadeo de
led1 a led4 sin usar la función delay(), permitiendo que el
programa ejecute otras tareas mientras los LEDs parpadean.


#include <Arduino.h>

// Definir los pines de los LEDs
const int led1 = 18;
const int led2 = 5;
const int led3 = 17;
const int led4 = 16;

// Variables para controlar el estado de los LEDs
bool led1State = LOW;
bool led2State = LOW;
bool led3State = LOW;
bool led4State = LOW;

// Variables para almacenar el último tiempo en que se cambió el estado de los LEDs
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
unsigned long previousMillis4 = 0;

// Intervalos de tiempo para cada LED (en milisegundos)
const long interval1 = 500; // 0.5 segundos
const long interval2 = 1000; // 1 segundo
const long interval3 = 1500; // 1.5 segundos
const long interval4 = 2000; // 2 segundos

void setup() {
  // Configurar los pines de los LEDs como salidas
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // Controlar led1
  if (currentMillis - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis;
    led1State = !led1State;
    digitalWrite(led1, led1State);
  }

  // Controlar led2
  if (currentMillis - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis;
    led2State = !led2State;
    digitalWrite(led2, led2State);
  }

  // Controlar led3
  if (currentMillis - previousMillis3 >= interval3) {
    previousMillis3 = currentMillis;
    led3State = !led3State;
    digitalWrite(led3, led3State);
  }

  // Controlar led4
  if (currentMillis - previousMillis4 >= interval4) {
    previousMillis4 = currentMillis;
    led4State = !led4State;
    digitalWrite(led4, led4State);
  }

  // Otras tareas pueden ejecutarse aquí mientras los LEDs parpadean
}


Ejercicio 15: Control de LEDs mediante comunicación serial
• Escribe un programa que reciba comandos a través del puerto
serie para controlar los LEDs. Por ejemplo, enviar '1' podría
encender led1, '2' apagar led2, etc.



/#include <Arduino.h>

const int led1 = 18; // Pin para LED1
const int led2 = 5;  // Pin para LED2
const int led3 = 17; // Pin para LED3
const int led4 = 16; // Pin para LED4

void setup() {
  // Configuración de los pines como salida
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  // Iniciar comunicación serial a 9600 baudios
  Serial.begin(9600);
}

void loop() {
  // Verificar si hay datos disponibles en el puerto serie
  if (Serial.available() > 0) {
    char comando = Serial.read(); // Leer el carácter enviado

    // Controlar los LEDs según el comando recibido
    switch (comando) {
      case '1':
        digitalWrite(led1, HIGH); // Encender LED1
        Serial.println("LED1 Encendido");
        break;
      case '2':
        digitalWrite(led1, LOW); // Apagar LED1
        Serial.println("LED1 Apagado");
        break;
      case '3':
        digitalWrite(led2, HIGH); // Encender LED2
        Serial.println("LED2 Encendido");
        break;
      case '4':
        digitalWrite(led2, LOW); // Apagar LED2
        Serial.println("LED2 Apagado");
        break;
      case '5':
        digitalWrite(led3, HIGH); // Encender LED3
        Serial.println("LED3 Encendido");
        break;
      case '6':
        digitalWrite(led3, LOW); // Apagar LED3
        Serial.println("LED3 Apagado");
        break;
      case '7':
        digitalWrite(led4, HIGH); // Encender LED4
        Serial.println("LED4 Encendido");
        break;
      case '8':
        digitalWrite(led4, LOW); // Apagar LED4
        Serial.println("LED4 Apagado");
        break;
      default:
        Serial.println("Comando no reconocido");
        break;
    }
  }
}




Ejercicio 16: Secuencia de luces de emergencia
• Simula luces de emergencia con los LEDs, donde led1 y led2
parpadean alternativamente en un patrón rápido, mientras que
led3 y led4 lo hacen en un patrón más lento.




// Definir los pines de los LEDs
#include <Arduino.h>

const int led1 = 18;
const int led2 = 5;
const int led3 = 17;
const int led4 = 16;

// Variables para temporización
unsigned long tiempoActual = 0;
unsigned long tiempoAnteriorRapido = 0;
unsigned long tiempoAnteriorLento = 0;

// Intervalos para parpadeo (en milisegundos)
const int intervaloRapido = 200; // Parpadeo rápido para led1 y led2 (200 ms)
const int intervaloLento = 600;  // Parpadeo lento para led3 y led4 (500 ms)

void setup() {
  // Configuración de los pines como salida
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  tiempoActual = millis(); // Obtener el tiempo actual

  // Control del parpadeo rápido de led1 y led2
  if (tiempoActual - tiempoAnteriorRapido >= intervaloRapido) {
    tiempoAnteriorRapido = tiempoActual; // Actualizar el tiempo anterior
    digitalWrite(led1, !digitalRead(led1)); // Alternar el estado de led1
    digitalWrite(led2, !digitalRead(led2)); // Alternar el estado de led2
  }

  // Control del parpadeo lento de led3 y led4
  if (tiempoActual - tiempoAnteriorLento >= intervaloLento) {
    tiempoAnteriorLento = tiempoActual; // Actualizar el tiempo anterior
    digitalWrite(led3, !digitalRead(led3)); // Alternar el estado de led3
    digitalWrite(led4, !digitalRead(led4)); // Alternar el estado de led4
  }
}
/*







