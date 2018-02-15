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
const int buttonPin = 2;  // playButton


// -- Working modes --
enum modes
{
  READY,
  MOVE_X,
  MOVE_Y,
  GRAB_AND_RELEASE
};

#endif // ENUMS_H
