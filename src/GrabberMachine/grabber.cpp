/*
  GrabberMachine
  grabber.cpp
  Created on 2018-02-20
  Copyright (c) 2018 Nefast. All rights reserved.

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  See file LICENSE for further informations on licensing terms.
*/

#include "grabber.h"

Grabber::Grabber(int zPin1, int zPin2, int rzPin, float rzRealMin, float rzRealMax)
{
  _zPin1 = zPin1;
  _zPin2 = zPin2;
  _rzPin = rzPin;
  _rzRealMin = rzRealMin;
  _rzRealMax = rzRealMax;

  pinMode(_zPin1, OUTPUT);
  pinMode(_zPin2, OUTPUT);
}

void Grabber::init()
{
  _grabberServo.attach(_rzPin);
  _grabberServo.write(_rzRealMax); // test max
  delay(RZDELAY);
  _grabberServo.write(_rzRealMin); // init to real zero
}

void Grabber::grab()
{
  down();
  delay(ZDELAY);

  _grabberServo.write(_rzRealMax);
  delay(RZDELAY);

  up();
  delay(ZDELAY);
  stop();
}

void Grabber::release()
{
  _grabberServo.write(_rzRealMin);
  delay(RZDELAY);
}

void Grabber::up()
{
  if (_dir != FORWARD || _stopped)
  {
    stop();
    digitalWrite(_zPin1, HIGH);
    digitalWrite(_zPin2, LOW);
    _stopped = false;
    _dir = FORWARD;
  }
}

void Grabber::down()
{
  if (_dir != BACKWARD || _stopped)
  {
    stop();
    digitalWrite(_zPin1, LOW);
    digitalWrite(_zPin2, HIGH);
    _stopped = false;
    _dir = BACKWARD;
  }
}

void Grabber::stop()
{
  digitalWrite(_zPin1, LOW);
  digitalWrite(_zPin2, LOW);
  _stopped = true;
}
