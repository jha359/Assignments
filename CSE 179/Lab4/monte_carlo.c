#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "omp.h"
#define NUM_THREADS 32
void *compute_pi (void *s){
    int seed;
    int i;
    int *hit_pointer;
    double x_coord;
    double y_coord;
    int local_hits;

    hit_pointer = (int*) s;
    seed = *hit_pointer;
    local_hits = 0;
    for (i = 0; i < 10000; i++){
        x_coord = (double)(rand_r(&seed)) / (RAND_MAX) - 0.5;
        y_coord = (double)(rand_r(&seed)) / (RAND_MAX) - 0.5;
        if((x_coord * x_coord + y_coord * y_coord) < 0.25){
            local_hits++;
        }
    }
    *hit_pointer = local_hits;
    pthread_exit(0);
}

int main(){
    double start_time;
    int i;
    int hits[NUM_THREADS];
    int total_hits=0;

    pthread_t p_threads[NUM_THREADS];
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    start_time = omp_get_wtime();
    for(i = 0; i < NUM_THREADS; i++){
        hits[i] = i;
        pthread_create(&p_threads[i], &attr, compute_pi, (void*) &hits[i]);
    }
    for(i = 0; i < NUM_THREADS; i++){
        pthread_join(p_threads[i], NULL);
        total_hits += hits[i];
    }
    float pi = (float)(4 * (total_hits) /(float)(NUM_THREADS * 10000));
    double time = omp_get_wtime() - start_time; 
    printf("PI = %f\n", pi);
    printf("TIME = %f\n", time);
    return 0;
}