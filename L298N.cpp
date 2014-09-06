/*
L298N
Created by RX14, June 7, 2014
Soon to be released into the public domain
*/

#include "Arduino.h"
#include "L298N.h"

L298N::L298N(int EN, int INA, int INB)
{
    pinMode(EN, OUTPUT);
    pinMode(INA, OUTPUT);
    pinMode(INB, OUTPUT);

    _EN  = EN;
    _INA = INA;
    _INB = INB;
}

void L298N::stop()
{
    digitalWrite(_EN , LOW);
    digitalWrite(_INA, LOW);
    digitalWrite(_INB, LOW);
}

void L298N::brake()
{
    digitalWrite(_EN , HIGH);
    digitalWrite(_INA, HIGH);
    digitalWrite(_INB, HIGH);
}

bool L298N::setSpeed(int percentage)
{
    if (percentage > 100) return false;
    if (percentage < 0) return false;

    int speed = percentage * 2.55;
    analogWrite(_EN, speed);
    _speed = percentage;

    return true;
}

int L298N::getSpeed()
{
    return _speed;
}

void L298N::setDirection(direction d)
{
    switch (d)
    {
        case LEFT:
            digitalWrite(_INA, HIGH);
            digitalWrite(_INB, LOW);
            break;

        case RIGHT:
            digitalWrite(_INA, LOW);
            digitalWrite(_INB, HIGH);
            break;
    }

    _direction = d;
}

direction L298N::getDirection()
{
    return _direction;
}
