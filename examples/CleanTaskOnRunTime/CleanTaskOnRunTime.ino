#include <Mtasks.h>

/**
*	Example how to clean(stop) running task.
*/

Mtasks taskOne(2000);                      //Create a task and specify the task execution interval in miliseconds
Mtasks taskTwo(1000, 20);                  //Create a task that will be executed every 1s for 20 times after that the task will stop.
Mtasks taskThreeCleanOtherTasks(10000, 1); //Create a task which will executed for 1 time after 10s. The task will clean(stop) other running tasks.

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
    bool isReadyToStop = true;

    if (isReadyToStop) //Example condition to stop the task on run time
    {
      Serial.println("Task 3 is Ready!"); //Call logic for your needs
      taskOne.cleanTask();                //The task 1 will be cleaned. This works for Task with duration too.
      taskTwo.cleanTask();                //The task 2 will be cleaned too.
    }
  }
}