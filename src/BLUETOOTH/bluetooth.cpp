#include <Arduino.h>

#include "NimBLEDevice.h"
#include "NuSerial.hpp"

void bluetoothSetup() {
#define DEVICE_NAME "ROBO_SARJETA"

  Serial.begin(115200);

  NimBLEDevice::init(DEVICE_NAME);                      // inicializa bluetooth
  NimBLEDevice::getAdvertising()->setName(DEVICE_NAME); // mostra bluetooth
  NuSerial.begin(115200); // inicialza serial bluetooth na velocidade (X)
}
