#include "global.h"
#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>
#include <stdexcept>
class PriorityThread
{
private:
    int numCore=0;
    pthread_t thread;
    pthread_attr_t attr;

public:
    PriorityThread(int num);
    int create_pri_thread(void* (*fun)(void*));
    ~PriorityThread();
};
