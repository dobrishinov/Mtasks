/*
  Mtasks.h - Library for Multi-Tasking based on millis().
  Created by Georgi Dobrishinov, October 17, 2019.
  Mtasks is licensed under the MIT License
*/
#ifndef MTASKS_H
#define MTASKS_H

#include "Arduino.h"

class Mtasks
{
public:
  Mtasks();
  Mtasks(unsigned long duration);

  bool isTaskReady();
  bool isTaskReady(unsigned long currentTime);

  void setDuration(unsigned long duration);
  void reset();

private:
  unsigned long _lastTime;
  unsigned long _duration;
  void _init();
  void _setLastTime(unsigned long time);
  bool _isTaskReady(unsigned long currentTime, unsigned long duration);
};

#endif