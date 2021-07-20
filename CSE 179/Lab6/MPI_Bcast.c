#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    MPI_Init(&argc, &argv);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int num = 420;

    if(world_rank == 0){
        printf("%d: Before broadcast, the value is %d\n", world_rank, num);
        num = num * 100;
        num = num + 69;
    } else {
        printf("%d: Before broadcast, the value is 0\n", world_rank);
    }
    MPI_Barrier(MPI_COMM_WORLD);

    double start_time = MPI_Wtime();

    MPI_Bcast(&num, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    
    double end_time = MPI_Wtime();

    printf("%d: After broadcast, the value is %d\n", world_rank, num);
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();

    double time = end_time - start_time;
    printf("The time for processor %d was %f\n", world_rank, time);

    return 0;
}