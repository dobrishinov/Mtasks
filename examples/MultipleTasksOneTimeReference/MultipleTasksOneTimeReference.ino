#include <Mtasks.h>

/**
*	Example how to use multiple tasks with one time reference. 
*	We need this to be sure there will be no time drift between different tasks.
*/

Mtasks taskOne(1000); //Create a first task and specify the duration in miliseconds
Mtasks taskTwo(250);  //Create a second task and specify the duration in miliseconds

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  unsigned long timeNow = millis();

  if (taskOne.isTaskReady(timeNow)) //Check if first task is ready
  {
    Serial.println("Task 1 is Ready!"); //Call logic for your needs
  }

  if (taskTwo.isTaskReady(timeNow)) //Check if second task is ready
  {
    Serial.println("Task 2 is Ready!"); //Call logic for your needs
  }
}