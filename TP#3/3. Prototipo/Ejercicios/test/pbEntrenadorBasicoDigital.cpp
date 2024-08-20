#include <Arduino.h>

// Definición de los pines de los pulsadores
#define btn1 34 // Pulsador 1
#define btn2 39 // Pulsador 2
#define btn3 36 // Pulsador 3

// Definición de los pines de los dip switches
#define sw1 13 // Posición 1 del Dip Switch
#define sw2 12 // Posición 2 del Dip Switch
#define sw3 14 // Posición 3 del Dip Switch
#define sw4 27 // Posición 4 del Dip Switch
#define sw5 26 // Posición 5 del Dip Switch
#define sw6 25 // Posición 6 del Dip Switch
#define sw7 33 // Posición 7 del Dip Switch
#define sw8 32 // Posición 8 del Dip Switch

// Definición de los pines de los LEDs
#define led1 18 // LED 1
#define led2 5  // LED 2
#define led3 17 // LED 3
#define led4 16 // LED 4
#define led5 4  // LED 5
#define led6 0  // LED 6
#define led7 2  // LED 7
#define led8 15 // LED 8

// Prototipo de la función pinSetup
void pinSetup();

void setup()
{
    pinSetup();
}

void loop()
{
    // Código para manejar las entradas y salidas
}

// Definición de la función pinSetup
void pinSetup()
{
    // Configuración de los pines de los pulsadores como entrada
    pinMode(btn1, INPUT);
    pinMode(btn2, INPUT);
    pinMode(btn3, INPUT);

    // Configuración de los pines de los dip switches como entrada con pull-up
    pinMode(sw1, INPUT_PULLUP);
    pinMode(sw2, INPUT_PULLUP);
    pinMode(sw3, INPUT_PULLUP);
    pinMode(sw4, INPUT_PULLUP);
    pinMode(sw5, INPUT_PULLUP);
    pinMode(sw6, INPUT_PULLUP);
    pinMode(sw7, INPUT_PULLUP);
    pinMode(sw8, INPUT_PULLUP);

    // Configuración de los pines de los LEDs como salida
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
    pinMode(led6, OUTPUT);
    pinMode(led7, OUTPUT);
    pinMode(led8, OUTPUT);
}