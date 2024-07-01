#include "global.h"
#include <iostream>
#include <thread>
#include <unistd.h>
unsigned int numCores = -1;

void get_cpu_core_nums() 
{
    numCores = std::thread::hardware_concurrency();
    std::cout << "Returned cores: " << numCores << std::endl;
    if (numCores == 0)
        std::cerr << "Warning: Failed to get number of CPU cores." << std::endl;
    else
        std::cout << "Number of CPU cores: " << numCores << std::endl;
    return;
}
