#include <Arduino.h>
#include "env.hpp"

#include "MOTORES/motores.hpp"
#include"PID/pid.hpp"
#include "BLUETOOTH/bluetooth.hpp"

bool roboAtivo = false;

void setup() 
{
  Serial.begin(115200);

  iniciarMotores();
  iniciarSensores();

}

void loop() 
{
  bluetoothLoop(roboAtivo);

  if (roboAtivo) {
    float correcao = calcularPID();
    controleMotores(VELOCIDADE_BASE - correcao, VELOCIDADE_BASE + correcao);
  } else {
    pararMotores();
  }

  delay(10);
}