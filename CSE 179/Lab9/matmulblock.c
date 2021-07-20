#include <stdio.h>
#include <mpi.h>

#define sizen 8
#define sizeq 4

int main(int argc, char** argv){
    int numprocs, rank;
    double start_time, end_time;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    int arrayA[sizen][sizen];
    int arrayB[sizen][sizen];
    int arrayC[sizen][sizen];
    int num = 1;
    for(int i = 0; i < sizen; i++){
        for(int j = 0; j < sizen; j++){
            arrayA[i][j] = num;
            arrayB[i][j] = num;
            num++;
            arrayC[i][j] = 0;
        }
    }

    start_time = MPI_Wtime();
    for(int kk = 0; kk < sizen; kk += sizeq){
        for (int jj = 0; jj < sizen; jj += sizeq){
            for(int i = 0; i < sizen; i++){
                for(int j = jj; j < jj + sizeq; j++){
                    int sum = arrayC[i][j];
                    for(int k = kk; k < kk + sizeq; k++){
                        sum += arrayA[i][k] * arrayB[k][j];
                    }
                    arrayC[i][j] = sum;
                }
            }
        }
    }

    MPI_Barrier(MPI_COMM_WORLD);
    end_time = MPI_Wtime();

    if(rank == 0){    
        for(int i = 0; i < sizen; i++){
            for(int j = 0; j < sizen; j++){
                printf("%d ", arrayC[i][j]);
            }
            printf("\n");
        }
        printf("Time: %f\n", end_time - start_time);
    }
    MPI_Finalize();
}