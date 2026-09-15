#ifndef CONTROLLERCAR_H
#define CONTROLLERCAR_H

#include <Arduino.h>

class Motor
{
private:
    int IN1;
    int IN2;

public:
    Motor(int pino1, int pino2);

    void begin();
    void stop();
    void forward();
    void reverse();
};

class Carro
{
private:
    Motor motorEsquerdo;
    Motor motorDireito;

public:
    Carro(int pinoMtA1, int pinoMtA2, int pinoMtB1, int pinoMtB2);

    void begin();
    void forward();
    void reverse();
    void right();
    void left();
};

#endif