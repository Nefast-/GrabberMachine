/*
  GrabberMachine
  enums.h
  Created on 2018-02-14
  Copyright (c) 2018 Nefast. All rights reserved.

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  See file LICENSE for further informations on licensing terms.
*/

#ifndef ENUMS_H
#define ENUMS_H

// -- Pin attributions --

// -- Buttons --
const int playButtonPin   = 2;
const int xLimitSwitchPin = 3;
const int yLimitSwitchPin = 4;

// -- Motors --
const int xStepPin = 5;
const int xDirPin  = 7;
const int yStepPin = 6;
const int yDirPin  = 8;
const int zPin1    = 9;
const int zPin2    = 10;
const int rzPin    = A0;

// -- Enums & others constants--

// -- Working modes --
enum modesEnum
{
  INIT,
  READY,
  MOVE_X,
  WAITING,
  MOVE_Y,
  GRAB_AND_RELEASE
};

#endif // ENUMS_H
