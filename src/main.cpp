#include <Arduino.h>
#include "controllerCar.h"
#include "comunication.h"

// class Motor
// {
// private:
//   int IN1;
//   int IN2;

// public:
//   Motor(int pino1, int pino2)
//   {
//     IN1 = pino1;
//     IN2 = pino2;
//   }

//   void begin()
//   {
//     pinMode(IN1, OUTPUT);
//     pinMode(IN2, OUTPUT);
//     stop();
//   }

//   void stop()
//   {

//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, LOW);
//   }

//   void forward()
//   {
//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);
//   }

//   void reverse()
//   {
//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, HIGH);
//   }
// };

// class Carro
// {
// private: //a classe carro possui dois obejtos da classe motor
//   Motor motorEsquerdo;
//   Motor motorDireito;

// public:
//   Carro(int pinoMtA1, int pinoMtA2, int pinoMtB1, int pinoMtB2)
//       : motorEsquerdo(pinoMtA1, pinoMtA2),
//         motorDireito(pinoMtB1, pinoMtB2)
//   {
//   }

//   void forward()
//   {
//     motorEsquerdo.forward();
//     motorDireito.forward();
//   }

//   void reverse()
//   {
//     motorEsquerdo.reverse();
//     motorDireito.reverse();
//   }

//   void right()
//   {
//     motorEsquerdo.forward();
//     motorDireito.reverse();
//   }

//   void left()
//   {
//     motorEsquerdo.reverse();
//     motorDireito.forward();
//   }
// };

// Motor mtEsquerdo(0, 1);
// Motor mtDireito(2, 3);

Carro carro(0,1,2,3);

void setup()
{
  Serial.begin(115200);
  iniciarBluetooth();


}
void loop()
{
}