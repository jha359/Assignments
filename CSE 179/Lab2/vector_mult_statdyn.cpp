#include <iostream>
#include <vector>
#include <omp.h>
#include <sys/time.h>

int main()
{
    std::vector<std::vector<int>> thematrix = {{2,4},{6,8}};
    std::vector<int> thematrix2 = {1,3};
    std::vector<int> result = {0,0};

    struct timeval time_start;
    struct timeval time_end;

    gettimeofday(&time_start, NULL);

    #pragma omp parallel for schedule(static) num_threads(4) shared(thematrix, thematrix2, result)
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                result[j] = result[j] + (thematrix[j][k] * thematrix2[k]);
            }
        }

    gettimeofday(&time_end, NULL);

    std::cout << result[0] << " " << result[1] << "\n";
    std::cout << "Static: " << time_end.tv_usec - time_start.tv_usec << " microsecond(s)" << "\n";

    gettimeofday(&time_start, NULL);

    result = {0,0};

    #pragma omp parallel for schedule(dynamic) num_threads(4) shared(thematrix, thematrix2, result)
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                result[j] = result[j] + (thematrix[j][k] * thematrix2[k]);
            }
        }

    gettimeofday(&time_end, NULL);

    std::cout << result[0] << " " << result[1] << "\n";
    std::cout << "Dynamic: " << time_end.tv_usec - time_start.tv_usec << " microsecond(s)" << "\n";
}