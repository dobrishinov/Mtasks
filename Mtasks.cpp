/*
  Mtasks.cpp - Library for Multi-Tasking based on millis().
  Created by Georgi Dobrishinov, October 17, 2019.
  Mtasks is licensed under the MIT License
*/
#include "Mtasks.h"

/**
*   Constructor
*/
Mtasks::Mtasks()
{
    _init();
}

/**
*   Mtasks();
*   Input: unsigned long interval
*   Output: void
*   Descrtiption: Constructor with one input parameter - 
*                 interval of the task (Every 1s, Every 2s..., etc.)
*/
Mtasks::Mtasks(unsigned long interval)
{
    _init();
    runTask(interval);
}

/**
*   Mtasks();
*   Input: unsigned long interval
*   Output: void
*   Descrtiption: Constructor with two input parameter - 
*                 interval of the task and duration of the task 
*                 (Every 1s and 1 run, Every 2s and 10 runs..., etc.)
*/
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
*   Initialization: Set some default values on the tasks.
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
*   Descrtiption: Run some task which is stopped. 
*                 We can pass the interval of the task. 
*                 (Every 1s, Every 2s..., etc.)
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
*   Descrtiption: Run some task which is stopped. 
*                 We can pass the interval and duration of the task. 
*                 (Every 1s and 1 run, Every 2s and 10 runs..., etc.)
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
*   Descrtiption: This method returns true or false when the task is running, 
*                 use the method in IF condition in the loop context to execute some logic.
*/
bool Mtasks::isTaskReady()
{
    return isTaskReady(millis());
}

/**
*   isTaskReady();
*   Input: unsigned long currentTime
*   Output: bool
*   Descrtiption: This method returns true or false when the task is running, 
*                 use the method in IF condition in the loop context to execute some logic. 
*                 We can pass one current time reference to the method, 
*                 so if we use many tasks we can pass the same reference of the current time.
*/
bool Mtasks::isTaskReady(unsigned long currentTime)
{
    return _taskProcessor(currentTime, this->_interval);
}

/**
*   _taskProcessor();
*   Input: unsigned long currentTime, unsigned long interval
*   Output: bool
*   Descrtiption: Calculation of the task times.
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
*   Descrtiption: Reset and stop current task. 
*                 Disable duration of the task if exist and stop the task.
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
*   Descrtiption: Returns true or false when some task is running, 
*                 we can use it in one task to check the status of the other task.
*/
bool Mtasks::isRunning()
{
    return _isRunning;
}