/*
  Mtasks.cpp - Library for Multi-Tasking based on millis().
  Created by Georgi Dobrishinov, October 17, 2019.
  Mtasks is licensed under the MIT License
*/
#include "Mtasks.h"

/**
* Constructors
*/
Mtasks::Mtasks()
{
    _init();
}

Mtasks::Mtasks(unsigned long duration)
{
    _init();
    setDuration(duration);
}

void Mtasks::_init()
{
    this->_lastTime = 0;
    this->_duration = 0;
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
    return _isTaskReady(currentTime, this->_duration);
}

bool Mtasks::_isTaskReady(unsigned long currentTime, unsigned long duration)
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
