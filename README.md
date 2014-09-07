L298N-lib
=========

An Arduino library for using the L298N motor driver.

Methods
=======

Constructor
-----------
Creates an object representing one motor output on the L298N motor controller, which is controlled using three pins.

For a typical setup, this would be either: Enable A, Input 1 and Input 2 or Enable B, Input 3 and Input 4.
```c
#include <L298N.h>


#define _EN  9   //Motor Driver Enable Pin
#define _INA 10  //Motor Driver Input  Pin A
#define _INB 11  //Motor Driver Input  Pin B

L298N motor(_EN, _INA, _INB); //L298N channel called motor
```
You can now use these functions on this object:

`void setDirection(direction)`
------------------------------
This will set the direction of the motor attached to the driver. Please note that for the motor to run, you must also set the speed.

Also note that the directions are completely arbitrary, because it depends on which way you have connected the motor and which way round you have connected the Input 1 and Input 2.

```c
motor.setDirection(LEFT);
```
or
```c
motor.setDirection(RIGHT);
```

`bool setSpeed(int percentage)`
-------------------------------
This will set the speed of the motor attached to the driver. Please note that for the motor to run, you must also set the direction.

Returns false if the percentage is out of bounds
```c
motor.setSpeed(50); //Set speed to 50%
```

```c
motor.setSpeed(100); //FULL SPEED AHEAD!
```

`void stop()`
-------------
This will stop the motor, letting it spin down to rest
```c
motor.stop();
```
This function will not save direction data.

`void brake()`
--------------
This will put the motor into the break state, stopping it (if moving) and making it harder to turn (in theory...)
```c
motor.brake();
```
This function will not save direction data.

`int getSpeed()`
----------------
Returns the current motor speed as a percentage
```c
int speed = motor.getSpeed(); //Get motor speed and save it into the speed variable
motor.stop(); //Stop the motor
delay(1000); //Wait 1 second
motor.setSpeed(speed); //Set the speed back to the previous speed
motor.setDirection(LEFT): //Set direction to LEFT because stop() overwrites it
```

`direction getDirection()`
--------------------------
Returns the current motor direction.
```c
direction d = motor.getDirection(); //Get motor direction and save it into the d variable
motor.stop(); //Stop the motor
delay(1000); //Wait 1 second
motor.setDirection(d); //Set the direction back to the previous direction
motor.setSpeed(100); //Set the speed to 100% because stop() overwrites it
```
