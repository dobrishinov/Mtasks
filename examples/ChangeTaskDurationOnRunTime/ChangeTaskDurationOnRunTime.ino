#include <Mtasks.h>

/**
*	Example how to use simple task and change task execution interval and duration on run time.
*/

Mtasks taskOne(1000); //Create a task and specify the task execution interval in miliseconds

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  bool isReadyToChangeInterval = true;

  if (isReadyToChangeInterval) //Example condition to change task execution interval and duration on run time
  {
    taskOne.runTask(2000, 2); //The task that will be executed every 2s for 2 times after that the task will stop. To run it again use runTask() function again.
  }

  if (taskOne.isTaskReady()) //Check if task is ready
  {
    Serial.println("I'm Ready!"); //Call logic for your needs
  }
}