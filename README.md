![Mtasks Logo](https://raw.githubusercontent.com/dobrishinov/Mtasks/develop/img/logo.PNG)

## Arduino Multi-Tasking library based on millis()

Set execution interval of the task and execute the functions every time when interval is reached. 
We have the option to change interval of the task runtime when we want.

## Check the examples for more details of how to use it:

```cpp
#include <Mtasks.h>

/**
*	Example how to use multiple tasks.
*/

Mtasks taskOne(1000); //Create a first task and specify the task execution interval in miliseconds
Mtasks taskTwo(250);  //Create a second task and specify the task execution interval in miliseconds

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

```