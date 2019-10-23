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
  Mtasks(unsigned long interval);
  Mtasks(unsigned long interval, unsigned int durationCount);

  bool isTaskReady();
  bool isTaskReady(unsigned long currentTime);

  void setTaskInterval(unsigned long interval);
  void setTaskInterval(unsigned long interval, unsigned int durationCount);
  void reset();

private:
  unsigned long _lastTime;
  unsigned long _interval;
  unsigned int _durationCount;
  void _init();
  void _setLastTime(unsigned long time);
  bool _isTaskReady(unsigned long currentTime, unsigned long interval);
};

#endif