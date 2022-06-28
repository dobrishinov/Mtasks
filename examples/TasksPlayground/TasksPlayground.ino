#include <Mtasks.h>

/**
* Example to show different scenarious - run tasks, change tasks behaviour, clean(stop) running task, enable stopped tasks and so on.
*/

Mtasks taskOne(2000);                      //Create a task and specify the task execution interval in miliseconds
Mtasks taskTwo(1000, 20);                  //Create a task that will be executed every 1s for 20 times after that the task will stop.
Mtasks taskThreeCleanOtherTasks(10000, 1); //Create a task which will executed for 1 time after 10s. The task will clean(stop) other running tasks.
Mtasks taskFourRunOtherTasks(20000);       //Create a task that will be executed every 20s.

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    if (taskOne.isTaskReady()) //Check if the first task is ready
    {
        Serial.println("Task 1 is Ready!"); //Call logic for your needs
    }

    if (taskTwo.isTaskReady()) //Check if the second task is ready
    {
        Serial.println("Task 2 is Ready!"); //Call logic for your needs
    }

    if (taskThreeCleanOtherTasks.isTaskReady()) //Check if the third task is ready
    {
        Serial.println("Task 3 is Ready!"); //Call logic for your needs
        taskOne.cleanTask();                //The task 1 will be cleaned. This works for Task with duration too.
        taskTwo.cleanTask();                //The task 2 will be cleaned too.
    }

    if (taskFourRunOtherTasks.isTaskReady()) //Check if the fourth task is ready
    {
        Serial.println("Task 4 is Ready!"); //Call logic for your needs

        if (!taskOne.isRunning()) //Check is task 1 is running, if not, run it with new parameters
        {
            taskOne.runTask(1000); //The task 1 will be started again with the new parameters, so the task will be executed every 1s.
        }

        if (!taskTwo.isRunning()) //Check is task 2 is running, if not, run it with new parameters
        {
            taskTwo.runTask(500, 10); //The task 2 will be started again with the new parameters, so the task will be executed every 0.5s for 10 times.
        }
    }
}