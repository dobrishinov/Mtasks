/*
  Mtasks.cpp - Library for Multi-Tasking based on millis().
  Created by Georgi Dobrishinov, October 17, 2019.
  Mtasks is licensed under the MIT License
*/
#include "Mtasks.h"

/**
* Constructor
*/
Mtasks::Mtasks() {}

Mtasks::Mtasks(unsigned long duration)
{
    setDuration(duration);
}

void Mtasks::setDuration(unsigned long duration)
{
    this->_duration = duration;
}

bool Mtasks::isTaskReady()
{
    return isTaskReady(millis());
}

bool Mtasks::isTaskReady(unsigned long currentTime)
{
    return isTaskReady(currentTime, this->_duration);
}

bool Mtasks::isTaskReady(unsigned long currentTime, unsigned long duration)
{
    if ((unsigned long)currentTime - _lastTime >= duration)
    {
        _lastTime = currentTime;
        return true;
    }
    return false;
}

void Mtasks::reset()
{
    setLastTime(millis());
}

void Mtasks::setLastTime(unsigned long time)
{
    this->_lastTime = time;
}
