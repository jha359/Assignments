#include <iostream>
#include <math.h>

__global__
void findMax(int *N, int* thelist)
{
	int index = threadIdx.x;
	int numthreads = blockDim.x;

	int max = -1;

	for (int i = index; i < N; i += numthreads)
	{
		if (thelist[i] > max)
		{
			max = thelist[i];
		}
	}

	__syncthreads();

	N = max;
}

int main()
{
	int input;
	std::cin >> input;

	int thelist[input];

	for (int i = 0; i < input; i++)
	{
		thelist[input] = rand() % 100 + 1;
	}

	findMax << <1, 256 >> > (input, thelist);

	cudaDeviceSynchronize();

	std::cout << N;
}