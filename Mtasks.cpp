/*
  Mtasks.cpp - Library for Multi-Tasking based on millis().
  Created by Georgi Dobrishinov, October 17, 2019.
  Mtasks is licensed under the MIT License
*/
#include "Mtasks.h"

/**
*   Constructors
*/
Mtasks::Mtasks()
{
    _init();
}

Mtasks::Mtasks(unsigned long interval)
{
    _init();
    runTask(interval);
}

Mtasks::Mtasks(unsigned long interval, unsigned int durationCount)
{
    _init();
    runTask(interval, durationCount);
}

/**
*   Destructors
*/
Mtasks::~Mtasks() {}

/**
*   Initialization
*/
void Mtasks::_init()
{
    this->_lastTime = 0;
    this->_interval = 0;
    this->_durationCount = -1;
    this->_isRunning = false;
}

/**
*   runTask();
*   Input: unsigned long interval
*   Output: void
*/
void Mtasks::runTask(unsigned long interval)
{
    this->_interval = interval;
    this->_isRunning = true;
}

/**
*   runTask();
*   Input: unsigned long interval, unsigned int durationCount
*   Output: void
*/
void Mtasks::runTask(unsigned long interval, unsigned int durationCount)
{
    this->_interval = interval;
    this->_durationCount = durationCount;
    this->_isRunning = true;
}

/**
*   isTaskReady();
*   Input: void
*   Output: bool
*/
bool Mtasks::isTaskReady()
{
    return isTaskReady(millis());
}

/**
*   isTaskReady();
*   Input: unsigned long currentTime
*   Output: bool
*/
bool Mtasks::isTaskReady(unsigned long currentTime)
{
    return _taskProcessor(currentTime, this->_interval);
}

/**
*   _taskProcessor();
*   Input: unsigned long currentTime, unsigned long interval
*   Output: bool
*/
bool Mtasks::_taskProcessor(unsigned long currentTime, unsigned long interval)
{
    if ((unsigned long)currentTime - _lastTime >= interval)
    {
        if (isRunning())
        {
            if (_durationCount == 0)
            {
                cleanTask();
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
    }
    return false;
}

/**
*   cleanTask();
*   Input: void
*   Output: void
*/
void Mtasks::cleanTask()
{
    this->_durationCount = -1;
    this->_isRunning = false;
}

/**
*   isRunning();
*   Input: void
*   Output: bool
*/
bool Mtasks::isRunning()
{
    return _isRunning;
}