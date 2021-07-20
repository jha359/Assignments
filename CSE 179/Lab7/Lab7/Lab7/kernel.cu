
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <iostream>
#include <math.h>
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

__global__ void findMax(int N, int* thelistArray)
{
	int index = threadIdx.x;
	int numthreads = blockDim.x;
	int max = thelistArray[0];
	for (int i = index; i < N; i += numthreads)
	{
		if (max < thelistArray[i])
		{
			max = thelistArray[i];
		}
	}

	thelistArray[0] = max;
}

cudaEvent_t beginEvent1;
cudaEvent_t endEvent1;
cudaEvent_t beginEvent2;
cudaEvent_t endEvent2;

int main(void)
{
	int input = 0;
	std::cout << "Input: ";
	std::cin >> input;
	thrust::host_vector<int> thelist;
	for (int i = 0; i < input; i++)
	{
		thelist.push_back(rand() % 1000 + 1);
	}

	//CPU-METHOD
	cudaEventCreate(&beginEvent1);
	cudaEventCreate(&endEvent1);
	cudaEventRecord(beginEvent1, 0);

	int largest = thelist[0];
	for (int j = 1; j < input; j++)
	{
		if (thelist[j] > largest)
		{
			largest = thelist[j];
		}
	}
	cudaEventRecord(endEvent1, 0);
	cudaEventSynchronize(endEvent1);
	float time;
	cudaEventElapsedTime(&time, beginEvent1, endEvent1);
	std::cout << "Value: " << largest << "\n";
	std::cout << "Time: " << time << " milliseconds" << "\n";
	cudaEventDestroy(beginEvent1);
	cudaEventDestroy(endEvent1);

	//GPU-METHOD
	cudaEventCreate(&beginEvent2);
	cudaEventCreate(&endEvent2);
	cudaEventRecord(beginEvent2, 0);
	int* thelistArray = thrust::raw_pointer_cast(&thelist[0]);
	findMax <<<1, 256 >>> (input, thelistArray);
	cudaEventRecord(endEvent2, 0);
	cudaEventSynchronize(endEvent2);
	float time2;
	cudaEventElapsedTime(&time2, beginEvent2, endEvent2);
	std::cout << "Value: " << thelistArray[0] << "\n";
	std::cout << "Time: " << time2 << " milliseconds" << "\n";
	cudaEventDestroy(beginEvent2);
	cudaEventDestroy(endEvent2);
}
