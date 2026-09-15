#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>

#define SERVICE_UUID "12345678-1234-1234-1234-123456789abc"
#define CHARACTERISTIC_UUID "87654321-4321-4321-4321-cba987654321"

void iniciarBTE()
{

    Serial.begin(115200);
    // inicializa o BTE da esp e da um nome ao dispositivo
    BLEDevice::init("SumoCar");
    // cria a variavel server que pode guardar o endereço BLEServer
    BLEServer *server = BLEDevice::createServer(); // e dps cria um servidor
    Serial.println("Bluetooth iniciado!");
}
