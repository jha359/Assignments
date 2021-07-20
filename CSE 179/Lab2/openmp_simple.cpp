#include <iostream>
#include "omp.h"

int main()
{
    #pragma omp parallel
    {
        std::cout << "Thread number " << omp_get_thread_num();
        std::cout << " - Hello World";
        std::cout << " - Number of threads: " << omp_get_num_threads() << "\n";
    }
    return 0;
} 
