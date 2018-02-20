/*
  GrabberMachine
  grabber.h
  Created on 2018-02-20
  Copyright (c) 2018 Nefast. All rights reserved.

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  See file LICENSE for further informations on licensing terms.
*/

#ifndef GRABBER_H
#define GRABBER_H

#include <Arduino.h>
#include <Servo.h>
#include "enums.h"

class Grabber
{
  public :
    Grabber(int zPin1, int zPin2, int rzPin, float rzRealMin = 0, float rzRealMax = 180);
    void init();
    void grab();
    void release();

  protected :
    void up();
    void down();
    void stop();

  private :
    enum
    {
      FORWARD,
      BACKWARD
    };
    int _zPin1;
    int _zPin2;
    int _rzPin;
    float _rzRealMin;
    float _rzRealMax;
    bool _stopped = true;
    int _dir = FORWARD;
    Servo _grabberServo;

    const int ZDELAY  = 2000;
    const int RZDELAY = 1200;
};

#endif // GRABBER_H
