#include "Arduino.h"
#include "env.hpp"

#include "motores.hpp"

void iniciarMotores() 
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  pararMotores();
}

void pararMotores() 
{
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void controleMotores(int velA, int velB)
{
  velA = constrain(velA, -VELOCIDADE_MAX, VELOCIDADE_MAX);
  velB = constrain(velB, -VELOCIDADE_MAX, VELOCIDADE_MAX);

  // Motor A
  if (velA >= 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, velA);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, abs(velA));
  }

  // Motor B
  if (velB >= 0) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, velB);
  } else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, abs(velB));
  }
}