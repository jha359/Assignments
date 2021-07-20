#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){

    MPI_Init(&argc, &argv);

    int npes, rank, my2drank, mycoords[2];
    MPI_Comm_size(MPI_COMM_WORLD, &npes);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int dims[2]={4,4};
    int periods[2] = {1,1};
    MPI_Comm comm_2d;
    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, 1, &comm_2d);
    MPI_Comm_rank(comm_2d, &my2drank);
    MPI_Cart_coords(comm_2d, my2drank, 2, mycoords);

    int up, down, left, right;

    MPI_Cart_shift(comm_2d, 0, 1, &left, &right);
    MPI_Cart_shift(comm_2d, 1, 1, &up, &down);
    printf("Global rank: %d, local rank: %d, Coord = (%d, %d), My neighbors are u:%d, d:%d, l:%d, r:%d, \t avg:%f\n", 
    rank, my2drank, mycoords[0], mycoords[1], up, down, left, right, (rank + up + down + left + right)/5.0);

    MPI_Finalize();
    return 0;
}