![Mtasks Logo](https://raw.githubusercontent.com/dobrishinov/Mtasks/develop/img/logo.PNG)

## Arduino Multi-Tasking library based on millis()

### Create asynchronous tasks easily.
Set execution interval of the task and execute the functions every time when interval is reached.
We have the option to change how many times the task will be executed.
Also we have the option to change interval and duration of the task runtime when we want.
  
-----------
### Check the example for more details of how to use it 
###### (for more examples check the example directory):

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
  if (taskOne.isTaskReady()) //Check if the first task is ready
  {
    Serial.println("Task 1 is Ready!"); //Call logic for your needs
  }

  if (taskTwo.isTaskReady()) //Check if second the task is ready
  {
    Serial.println("Task 2 is Ready!"); //Call logic for your needs
  }
}

```


Using the same code above, you can change the "taskOne" task on runtime to repeat every 2s instead of 1s and will be executed only 5 times now. 
```cpp
  if (taskOne.isTaskReady()) //Check if the first task is ready
  {
    taskOne.runTask(2000, 5); //The timer will repeat every 2000ms (2s) and will call the callback only 5 times
    Serial.println("Task 1 is Ready!"); //Call logic for your needs
  }
```

Using the same code above, you can clean the "taskOne" task. The task duration is reset and task has been stopped. 
```cpp
  if (taskOne.isTaskReady()) //Check if the first task is ready
  {
    taskOne.clearTask(); //Clean task means, the task duration is reset and task has been stopped
    Serial.println("Task 1 is Ready!"); //Call logic for your needs
  }
```

Using the same code above, you can check from other task "taskTwo", if "taskOne" is working, if not working we can start again the task with the new parameters.
```cpp
  if (taskTwo.isTaskReady()) //Check if the first task is ready
  {
    if (!taskOne.isRunning()) //Check is taskOne is running, if not, run it with new parameters
    {
      taskOne.runTask(1000); ///The timer will repeat every 1000ms (1s)
      Serial.println("Task 1 is Ready!"); //Call logic for your needs
    }
  }
```

Using the same code above, you can pass one current time reference to the different tasks, so if we use many tasks we can pass the same reference of the current time. For example view MultipleTasksOneTimeReference example.
```cpp
  unsigned long timeNow = millis();

  if (taskOne.isTaskReady(timeNow)) //Check if the first task is ready
  {
    Serial.println("Task 1 is Ready!"); //Call logic for your needs
  }

  if (taskTwo.isTaskReady(timeNow)) //Check if the second task is ready
  {
    Serial.println("Task 2 is Ready!"); //Call logic for your needs
  }
```

## Library Reference
### `Mtasks` class

*  `Mtasks()` - Constructor

*  `Mtasks(unsigned long interval)` - Constructor with one input parameter - interval of the task (Every 1s, Every 2s..., etc.)

*  `Mtasks(unsigned long interval, unsigned int durationCount)` - Constructor with two input parameter - interval of the task and duration of the task (Every 1s and 1 run, Every 2s and 10 runs..., etc.)

*  `~Mtasks()` - Destructor

*  `bool isTaskReady()` - This method returns true or false when the task is running, use the method in IF condition in the loop context to execute some logic.

*  `bool isTaskReady(unsigned long currentTime)` - This method returns true or false when the task is running, use the method in IF condition in the loop context to execute some logic. We can pass one current time reference to the method, so if we use many tasks we can pass the same reference of the current time. For example view MultipleTasksOneTimeReference example.

*  `bool isRunning()` - This flag returns true or false when some task is running, we can use it in one task to check the status of the other task. For example view TasksPlayground example.

*  `void runTask(unsigned long interval)` - Run some task which is stopped. We can pass the interval of the task. (Every 1s, Every 2s..., etc.) For example view ChangeTaskDurationOnRunTime example.

*  `void runTask(unsigned long interval, unsigned int durationCount)` - Run some task which is stopped. We can pass the interval and duration of the task. (Every 1s and 1 run, Every 2s and 10 runs..., etc.) For example view ChangeTaskDurationOnRunTime example.

*  `void cleanTask()` - Reset and stop current task. Disable duration of the task if exist and stop the task. For example view CleanTaskOnRunTime example.

*  **private** `bool _isRunning` - Stores _isRunning flag.

*  **private** `unsigned long _lastTime` - Stores _lastTime.

*  **private** `unsigned long _interval` - Stores the interval of the task.

*  **private** `unsigned int _durationCount` - Stores the duration of the task.

*  **private** `void _init()` - Initialization. Set some default values on the tasks.

*  **private** `bool _taskProcessor(unsigned long currentTime, unsigned long interval)` - Calculation of the task times.

