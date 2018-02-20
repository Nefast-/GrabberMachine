/*
  GrabberMachine
  axis.h
  Created on 2018-02-15
  Copyright (c) 2018 Nefast. All rights reserved.

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  See file LICENSE for further informations on licensing terms.
*/

// -------------------------
// List of tested devices
// Drivers : A4988
// Stepper motor : NEMA 17
// -------------------------

#ifndef AXIS_H
#define AXIS_H

#include <AccelStepper.h>
#include "enums.h"

class Axis
{
  public :
    Axis(int stepPin, int dirPin, int limitSwitchPin);
    void init();
    void setSpeed(int speed);
    bool moveForward();
    bool moveBackward();
    bool atEnd();

  private :
    int _stepPin;
    int _dirPin;
    int _limitSwitchPin;
    int _speed = 500;
    AccelStepper *_motor = nullptr;
};

#endif // AXIS_H
