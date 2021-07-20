#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char*argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage: number of elements per processor\n");
        exit(1);
    }
    int num_elements_per_proc = atoi(argv[1]);
    int npes, rank, SIZE;

    double start_time, end_time;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &npes);

    SIZE = num_elements_per_proc * npes;
    int *sendbuf, *recvbuf;
    int i;
    if(rank == 0){
        sendbuf = (int*)malloc(sizeof(int) * SIZE);
        printf("Task 0: ");
        for(i = 0; i < SIZE; i ++){
            sendbuf[i] = i;
            printf("%d ", sendbuf[i]);
        }
        printf("\n------------------------------------------------------------\n");
    }

    MPI_Barrier(MPI_COMM_WORLD);
    start_time = MPI_Wtime();
    recvbuf = (int*)malloc(sizeof(int) * num_elements_per_proc);
    assert(recvbuf != NULL);

    MPI_Scatter(sendbuf, num_elements_per_proc, MPI_INT, recvbuf, num_elements_per_proc, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);

    int *gather_send = (int*)malloc(sizeof(int) * num_elements_per_proc);
    assert(gather_send != NULL);
    printf("Task %d: ", rank);
    for(i = 0; i < num_elements_per_proc; i++){
        printf("%d ", recvbuf[i]);
        gather_send[i] = recvbuf[i] + rank;
    }
    printf("\n");
    int *gather_buf = NULL;
    if(rank == 0) {
        gather_buf = (int*)malloc(sizeof(int) * SIZE);
        assert(gather_buf != NULL);
    }
    MPI_Gather(gather_send, num_elements_per_proc, MPI_INT, gather_buf, num_elements_per_proc, MPI_INT, 0 , MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    end_time = MPI_Wtime();

    if(rank == 0){
        printf("------------------------------------------------------------\n");
        printf("Task 0: ");
        for(i = 0; i < SIZE; i++){
            printf("%d ", gather_buf[i]);
        }
        printf("\n");
    }
    if(rank == 0){
        free(sendbuf);
        free(gather_buf);
    }
    free(recvbuf);
    free(gather_send);
    MPI_Barrier(MPI_COMM_WORLD);
    if(rank == 0){
        printf("Execution Time: %f\n", end_time - start_time);
    }
    MPI_Finalize();
    return 0;
}