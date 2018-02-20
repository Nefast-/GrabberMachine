/*
  GrabberMachine
  helpers.h
  Created on 2018-02-14
  Copyright (c) 2018 Nefast. All rights reserved.
  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.
  See file LICENSE for further informations on licensing terms.
*/

#ifndef HELPERS_H
#define HELPERS_H

#include "enums.h"

bool playButtonLastState = false;

// all helpers functions here
bool playButtonState()
{
  bool state = !digitalRead(playButtonPin); // inverted because of pullup mode
  if (playButtonLastState != state)
  {
    playButtonLastState = state;
    return true;
  }
  playButtonLastState = state;
  return false;
}

modesEnum getNextMode(modesEnum &current)
{
  switch (current)
  {
    case READY :
      {
        return MOVE_Y;
      } break;
    case MOVE_Y:
      {
        return WAITING;
      } break;
    case WAITING:
      {
        return MOVE_X;
      } break;
    case MOVE_X :
      {
        return GRAB_AND_RELEASE;
      } break;
  }
  return current;
}

#endif // HELPERS_H
