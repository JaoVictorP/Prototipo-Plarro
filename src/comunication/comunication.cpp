#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include "controllerCar.h"

extern Carro carro;

#define SERVICE_UUID "12345678-1234-1234-1234-123456789abc"
#define CHARACTERISTIC_UUID "87654321-4321-4321-4321-cba987654321"

class ComandoCallbacks : public BLECharacteristicCallbacks{
    public:
        void onWrite(BLECharacteristic *characteristic) override
        {
            std::string valor = characteristic->getValue();

            if (valor.empty())
            {
                return;
            }

            char comando = valor[0];
            comando = static_cast<char>(toupper(static_cast<unsigned char>(comando)));
            Serial.println("--- Comando BLE recebido ---");
            Serial.printf("Comando: %c\n", comando);
            switch (comando){
            case 'F':
                carro.forward();
                break;
            case 'B':
                carro.reverse();
                break;
            case 'L':
                carro.left();
                break;
            case 'R':
                carro.right();
                break;
            case 'S':
                carro.stop();
                break;
            default:
                Serial.printf("Comando desconhecido: %c\n", comando);
                return;
            }

            Serial.printf("Comando recebido: %c\n", comando);
        }
};

void iniciarBluetooth(){
    Serial1.println("Inicializando Bluetooth...");
    BLEDevice::init("SumoCar");
    BLEServer *server = BLEDevice::createServer();
    Serial.println("Servidor BLE criado.");
    BLEService *service = server->createService(SERVICE_UUID);
    BLECharacteristic *characteristic = service->createCharacteristic(
        CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);

    characteristic->setValue("S");
    characteristic->setCallbacks(new ComandoCallbacks());
    service->start();
    Serial.println("Servico BLE iniciado.");

    BLEAdvertising *advertising = BLEDevice::getAdvertising();
    advertising->addServiceUUID(SERVICE_UUID);
    advertising->setScanResponse(true);
    BLEDevice::startAdvertising();

    Serial.println("Bluetooth iniciado. Procure por SumoCar e envie F, B, L, R ou S.");
}
