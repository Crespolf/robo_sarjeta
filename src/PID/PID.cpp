#include "Arduino.h"
#include "env.hpp"

#include "PID.hpp"

float erroAnterior = 0.0f;

void iniciarSensores() 
{
    pinMode(SENSOR_FRENTE, INPUT);
    pinMode(SENSOR_TRAS, INPUT);
}


float calcularPID() 
{
    int leituraFrente = analogRead(SENSOR_FRENTE);
    int leituraTras   = analogRead(SENSOR_TRAS);

    float mediaDistancia = (leituraFrente + leituraTras) / 2.0;
    float erroAngulo     = (leituraFrente - leituraTras) * 0.5;

    float erro = (mediaDistancia - DISTANCIA) + erroAngulo;

    float P = erro;
    float D = erro - erroAnterior;

    erroAnterior = erro;

    return (KP * P) + (KD * D);
}