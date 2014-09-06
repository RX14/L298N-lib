/*
  L298N
  Created by RX14, June 7, 2014
  Soon to be released into the public domain
*/
#ifndef L298N_h
#define L298N_h

#include "Arduino.h"

class L298N
{
  public:
    enum direction {LEFT, RIGHT};

    L298N(int EN, int INA, int INB);

    void stop();
    void brake();

    void setSpeed(int percentage);
    int  getSpeed();

    void      setDirection(direction);
    direction getDirection();

  private:
    int _EN;
    int _INA;
    int _INB;
};

#endif
