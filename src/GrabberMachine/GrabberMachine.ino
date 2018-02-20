/*
  GrabberMachine
  GrabberMachine.ino
  Created on 2018-02-14
  Copyright (c) 2018 Nefast. All rights reserved.

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  See file LICENSE for further informations on licensing terms.
*/

#include <Servo.h> // TODO : Move this to class
#include "helpers.h"
#include "axis.h"

Servo grabber; // TODO : Move this to class
Axis X(xStepPin, xDirPin, xLimitSwitchPin);
Axis Y(yStepPin, yDirPin, yLimitSwitchPin);
modesEnum currentMode = INIT;

void setup()
{
  //-- TODO : Move this to class --
  pinMode(zPin, OUTPUT);
  grabber.attach(rzPin);
  grabber.write(20); // init to real zero
  //-- END TODO --

  pinMode(playButtonPin, INPUT_PULLUP);
  Y.init();
  X.init();

  currentMode = READY;
}

void loop()
{
  if (playButtonState())
  {
    currentMode = getNextMode(currentMode);
  }
  switch (currentMode)
  {
    case MOVE_Y :
      {
        if (!Y.moveForward())
        {
          currentMode = MOVE_X;
        }
      } break;
    case MOVE_X:
      {
        if (!X.moveForward())
        {
          currentMode = getNextMode(currentMode);
        }
      } break;
    case GRAB_AND_RELEASE :
      {
        // TODO : Implement Grab and release sequence with class
        // TODO : Find something for invert Z axis

        digitalWrite(zPin, HIGH);
        delay(2000);
        digitalWrite(zPin, LOW);

        grabber.write(179);
        delay(1000);

        digitalWrite(zPin, HIGH);
        delay(2000);
        digitalWrite(zPin, LOW);

        
        Y.init();
        X.init();
        grabber.write(0);
        delay(3000);
        currentMode = READY;
      } break;
  }
}
