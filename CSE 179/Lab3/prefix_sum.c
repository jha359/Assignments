#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "omp.h"

#define NUM 4096
struct timeval time_start;
struct timeval time_end;
struct timeval time_start1;
struct timeval time_end1;
struct timeval time_start2;
struct timeval time_end2;
struct timeval time_start3;
struct timeval time_end3;
int main()
{
    int array[NUM];
    int i, threadnum, arrsize, numthreads;
    int partial[numthreads + 1];
    int sum = 0;
    for(int i = 0; i < NUM; i++)
    {
        array[i] = rand() % 100 + 1;
    }
    
    gettimeofday(&time_start, NULL);

    #pragma omp parallel private(i, threadnum) num_threads(4)
    {
        #pragma omp single
        {
            numthreads = omp_get_num_threads();
            arrsize = NUM / numthreads;
        }

        threadnum = omp_get_thread_num();
        partial[threadnum + 1] = array[arrsize * threadnum];

        gettimeofday(&time_start1, NULL);
        for(i = arrsize * threadnum + 1; i < arrsize * threadnum + arrsize && i < NUM; i++)
        {
            partial[threadnum + 1] = partial[threadnum + 1] +  array[i];
            array[i] = array[i] + array[i-1];
        }
        #pragma omp barrier
        gettimeofday(&time_end1, NULL);
        
        gettimeofday(&time_start2, NULL);
        #pragma omp single
        {
            for(int j = 1; j <= numthreads; j++)
            {
                partial[j] = partial[j] + partial[j-1];
            }
        }
        gettimeofday(&time_end2, NULL);
        gettimeofday(&time_start3, NULL);
        for(i = arrsize * threadnum; i < arrsize * threadnum + arrsize && i < NUM; i++)
        {
            array[i] = array[i] + partial[threadnum];
        }
        gettimeofday(&time_end3, NULL);
    }
    gettimeofday(&time_end, NULL);

    int time =  time_end.tv_usec - time_start.tv_usec;
    int time1 = time_end1.tv_usec - time_start1.tv_usec;
    int time2 = time_end2.tv_usec - time_start2.tv_usec;
    int time3 = time_end3.tv_usec - time_start3.tv_usec;

    printf("Total: %d microseconds\n", time);
    printf("Step 1: %d microseconds\n", time1);
    printf("Step 2: %d microseconds\n", time2);
    printf("Step 3: %d microseconds\n", time3);
    return 0;

    


    /*int sum[NUM];
    sum[0] = array[0];
    for(int j = 1; j < NUM; j++)
    {
        sum[j] = sum[j-1] + array[j];
    }*/
}