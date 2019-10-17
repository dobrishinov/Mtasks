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

    bool isTaskReady(unsigned long currentTime);
    bool isTaskReady(unsigned long currentTime, unsigned long duration);
    bool isTaskReady()
    {
        return isTaskReady(millis());
    }

    void setDuration(unsigned long duration)
    {
        this->_duration = duration;
    }
    void setLastTime(unsigned long time)
    {
        this->_lastTime = time;
    }
    void reset()
    {
        setLastTime(millis());
    }

private:
    unsigned long _lastTime = 0;
    unsigned long _duration = 0;
};

#endif