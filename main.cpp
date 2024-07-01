
#include <iostream>
#include "PriorityThread.h"
#include "global.h"

void* thread_function_1(void* arg) {

    printf("Thread running on CPU core %d\n", sched_getcpu());
    sleep(5); // Simulate work
    printf("Thread finished\n");
    return NULL;
}

int main(int argc, char **argv) 
{   

    get_cpu_core_nums();
    PriorityThread *p=new PriorityThread(3);
    p->create_pri_thread(thread_function_1);
    delete p;
    return 0;
}
