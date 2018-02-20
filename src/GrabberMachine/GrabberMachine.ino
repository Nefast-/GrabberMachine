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

#include "helpers.h"
#include "axis.h"
#include "grabber.h"

Axis X(xStepPin, xDirPin, xLimitSwitchPin);
Axis Y(yStepPin, yDirPin, yLimitSwitchPin);
Grabber grabber(zPin1, zPin2, rzPin, 20, 180);
modesEnum currentMode = INIT;

void setup()
{
  pinMode(playButtonPin, INPUT_PULLUP);
  grabber.init();
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
        grabber.grab();
        X.init();
        Y.init();
        grabber.release();
        currentMode = READY;
      } break;
  }
}
