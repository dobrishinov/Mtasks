#include <Mtasks.h>

/**
*	Example how to use multiple tasks.
*/

Mtasks taskOne(1000); //Create a first task and specify the duration in miliseconds
Mtasks taskTwo(250);  //Create a second task and specify the duration in miliseconds

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  if (taskOne.isTaskReady()) //Check if first task is ready
  {
    Serial.println("Task 1 is Ready!"); //Call logic for your needs
  }

  if (taskTwo.isTaskReady()) //Check if second task is ready
  {
    Serial.println("Task 2 is Ready!"); //Call logic for your needs
  }
}