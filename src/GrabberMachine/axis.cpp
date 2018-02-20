/*
  GrabberMachine
  axis.cpp
  Created on 2018-02-15
  Copyright (c) 2018 Nefast. All rights reserved.

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  See file LICENSE for further informations on licensing terms.
*/

#include "axis.h"

Axis::Axis(int stepPin, int dirPin, int limitSwitchPin)
{
  _stepPin = stepPin;
  _dirPin = dirPin;
  _limitSwitchPin = limitSwitchPin;
  pinMode(limitSwitchPin, INPUT_PULLUP);
  _motor = new AccelStepper(1, stepPin, dirPin);
  _motor->setMaxSpeed(1000);
}

void Axis::init()
{
  while (!atEnd())
  {
    moveBackward();
  }
}

void Axis::setSpeed(int speed)
{
  _speed = speed;
}

bool  Axis::moveForward()
{
  if (!atEnd())
  {
    _motor->setSpeed(_speed);
    _motor->runSpeed();
    return true;
  }
  return false;
}

bool Axis::moveBackward()
{
  if (!atEnd())
  {
    _motor->setSpeed(-_speed);
    _motor->runSpeed();
    return true;
  }
  return false;
}

bool Axis::atEnd()
{
  return !digitalRead(_limitSwitchPin); // inverted return because of pullup mode.
}
