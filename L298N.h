/*
  L298N - Library for operating a L298N motor driver
  Created by RX14, June 7, 2014
  Unlicensed, do what you want with it!
*/

#ifndef L298N_h_RX14
#define L298N_h_RX14

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

typedef enum {LEFT, RIGHT, NONE} direction;

class L298N
{
public:
    L298N(int EN, int INA, int INB);

    void stop();
    void brake();

    void setSpeed(int percentage);
    int  getSpeed();

    void      setDirection(direction);
    direction getDirection();

private:
    int _EN, _INA, _INB; //Configured pins

    int _speed; //Stored speed
    direction _direction; //Stored direction
};

#endif
