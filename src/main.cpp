#include <Arduino.h>
// #include "controllerCar.h"
#include "comunication.h"

Carro carro(0,1,2,3);

void setup()
{
  Serial.begin(115200);
  Serial.println("Iniciando...");
  carro.begin();
  iniciarBluetooth();
}
void loop()
{
  Serial.print(1);
  static unsigned long ultimoStatus = 0;

  if (millis() - ultimoStatus >= 5000)
  {
    ultimoStatus = millis();
    Serial.println("Firmware executando. Aguardando comando BLE...");
  }
}