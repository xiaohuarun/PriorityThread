# PriorityThread
This is a high-priority thread class that is arbitrarily placed on the cpu core. <br>

**To use this class, you need to get the highest privileges of the system, otherwise you can't use it** <br>

Here's a way to make a thread's priority as high as possible while fixing it to a CPU core.<br>

You just have to write the functions that the threads need to use and instantiate the priority threads,<br>
forexemple:<br>
    **PriorityThread \*p=new PriorityThread(3)**   <br>
    **p->create_pri_thread(thread_function_1);**  <br>
    but don't use the class too much because the object has the highest priority.<br>
    
Bind threads to specific CPU cores to avoid time-consuming scheduling.<br>

**Note:** It is not recommended to bind threads that require real-time performance to the 0th core,<br>
as the 0th core will handle some CPU interrupts that will interrupt the execution of the thread.<br>

**Notes:** <br>
1. The above procedure provides a top priority approach, please use it with caution, it does not make sense to set all threads to the highest priority.<br>
 It is only suitable for real-time demanding scenarios.<br>
2. When the scheduling scheme is set to "SCHED_FIFO", please note that the thread can not take up a lot of CPU resources,
 otherwise it will lead to other low priority threads can not be executed.
