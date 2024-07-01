#include "PriorityThread.h"
#include <iostream>
#include <stdexcept>
#include <unistd.h> // For sleep function

PriorityThread::PriorityThread(int num) {
    if (num < numCores && numCores!=-1)
            this->numCore = num; // Initialize numCore
    pthread_attr_init(&attr);
}

PriorityThread::~PriorityThread() {
    pthread_attr_destroy(&attr); // Clean up thread attributes
}

int PriorityThread::create_pri_thread(void* (*fun)(void*)) {
    int ret;
    struct sched_param param;
    cpu_set_t cpuset;

    std::cout << "Creating thread on CPU core: " << this->numCore << std::endl;

    ret = pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    if (ret != 0) {
        perror("pthread_attr_setschedpolicy");
        return 1;
    }

    int max_priority = sched_get_priority_max(SCHED_FIFO);
    if (max_priority == -1) {
        perror("sched_get_priority_max");
        return 1;
    }

    param.sched_priority = max_priority;
    ret = pthread_attr_setschedparam(&attr, &param);
    if (ret != 0) {
        perror("pthread_attr_setschedparam");
        return 1;
    }

    ret = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    if (ret != 0) {
        perror("pthread_attr_setinheritsched");
        return 1;
    }

    ret = pthread_create(&thread, &attr, fun, NULL);
    if (ret != 0) {
        std::cout << "Thread created failed." << std::endl;
        perror("pthread_create failed");
        return 1;
    }

    CPU_ZERO(&cpuset);
 
    CPU_SET(numCore, &cpuset);

    ret = pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
    if (ret != 0) {
        perror("pthread_setaffinity_np");
        return 1;
    }

    pthread_join(thread, NULL);
    return 0;
}
