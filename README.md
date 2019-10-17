![Mtasks Logo](https://raw.githubusercontent.com/dobrishinov/Mtasks/develop/img/logo.PNG)

## Arduino Multi-Tasking library based on millis()

Set duration of the task and execute the functions every time when duration is reached. 
We have the option to change duration of the task runtime when we want.

## Check the examples for more details of how to use it:

```cpp
#include <Mtasks.h>

Mtasks taskOne(1000); //Create a task and specify the duration in miliseconds

void setup(){
  Serial.begin(115200);
}

void loop(){
  if(taskOne.isTaskReady()){ //Check if task is ready
    Serial.println("I'm Ready!"); //Call logic for your needs
  }
}

```