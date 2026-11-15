#include <Arduino.h>
#include "env.hpp"

#include "MOTORES/motores.hpp"
#include"PID/pid.hpp"


void setup() 
{
  Serial.begin(115200);

  iniciarMotores();
  iniciarSensores();

}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}