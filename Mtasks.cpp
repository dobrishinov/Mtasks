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

Mtasks::Mtasks(unsigned long interval)
{
    _init();
    setTaskInterval(interval);
}

Mtasks::Mtasks(unsigned long interval, unsigned int durationCount)
{
    _init();
    setTaskInterval(interval, durationCount);
}

void Mtasks::_init()
{
    this->_lastTime = 0;
    this->_interval = 0;
    this->_durationCount = -1;
}

void Mtasks::setTaskInterval(unsigned long interval)
{
    this->_interval = interval;
}

void Mtasks::setTaskInterval(unsigned long interval, unsigned int durationCount)
{
    this->_interval = interval;
    this->_durationCount = durationCount;
}

bool Mtasks::isTaskReady()
{
    return isTaskReady(millis());
}

bool Mtasks::isTaskReady(unsigned long currentTime)
{
    return _isTaskReady(currentTime, this->_interval);
}

bool Mtasks::_isTaskReady(unsigned long currentTime, unsigned long interval)
{
    if ((unsigned long)currentTime - _lastTime >= interval)
    {
        if (_durationCount == 0)
        {
            return false;
        }
        else if (_durationCount > 0)
        {
            _lastTime = currentTime;
            _durationCount -= 1;
            return true;
        }
        else
        {
            _lastTime = currentTime;
            return true;
        }
    }
    return false;
}

void Mtasks::reset()
{
    _setLastTime(millis());
}

void Mtasks::_setLastTime(unsigned long time)
{
    this->_lastTime = time;
}
