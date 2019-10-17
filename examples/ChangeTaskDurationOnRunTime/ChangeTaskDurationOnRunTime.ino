#include <Mtasks.h>

/**
*	Example how to use simple task and change task duration on run time.
*/

Mtasks taskOne(1000); //Create a task and specify the duration in miliseconds

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  bool isReadyToChangeDuration = true;

  if (isReadyToChangeDuration) //Example condition to change task duration on run time
  {
    taskOne.setInterval(2000);
  }

  if (taskOne.isTaskReady()) //Check if task is ready
  {
    Serial.println("I'm Ready!"); //Call logic for your needs
  }
}