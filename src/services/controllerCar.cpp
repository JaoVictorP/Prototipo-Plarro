#include "controllerCar.h"

Motor::Motor(int pino1, int pino2) //o construtor pertence a class Motor
{
    IN1 = pino1;
    IN2 = pino2;
}

void Motor::begin() //a funcao begin pertence a class Motor
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    stop();
}

void Motor::stop()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
}

void Motor::forward()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
}

void Motor::reverse()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
}



Carro::Carro(int pinoMtA1, int pinoMtA2, int pinoMtB1, int pinoMtB2)
    : motorEsquerdo(pinoMtA1, pinoMtA2),
      motorDireito(pinoMtB1, pinoMtB2)
{
}

void Carro::begin()
{
    motorEsquerdo.begin();
    motorDireito.begin();
}

void Carro::forward()
{
    motorEsquerdo.forward();
    motorDireito.forward();
}

void Carro::reverse()
{
    motorEsquerdo.reverse();
    motorDireito.reverse();
}

void Carro::right()
{
    motorEsquerdo.forward();
    motorDireito.reverse();
}

void Carro::left()
{
    motorEsquerdo.reverse();
    motorDireito.forward();
}