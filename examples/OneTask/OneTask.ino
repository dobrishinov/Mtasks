#include <Mtasks.h>

/**
*	Example how to use simple task.
*/

Mtasks taskOne(1000); //Create a task and specify the duration in miliseconds

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  if (taskOne.isTaskReady()) //Check if task is ready
  {
    Serial.println("I'm Ready!"); //Call logic for your needs
  }
}