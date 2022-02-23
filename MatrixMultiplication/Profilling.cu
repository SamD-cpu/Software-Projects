#include <random>
#include <chrono>
#include <thread>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <iostream>
 

#define SIZE 32

bool checkCorrectness(int* resultDevice, int* resultHost, int m, int k);

/***************************************************************
** Description: naive implmentation of Matrix Multiplication
**  
**
** Precondition: takes in values that factors in size relative
** to the hardware architreture.
**
**Postcondition: completed matrix with correct values
*****************************************************************
*/
__global__ void gpuMM(int* A, int* B, int* Res, int m, int n, int k)
{
	//using cuda builtin variables to return the 
	//full global thread  ID for multiplication matrix execution of rows and columns
	int Row = blockIdx.y * blockDim.y + threadIdx.y;
	int Col = blockIdx.x * blockDim.x + threadIdx.x;
	int resVal = 0;
	if (Col < k && Row < m)
	{
		for (int i = 0; i < n; i++)
		{
			resVal += A[Row * n + i] * B[i * k + Col];//fuction multiplication
		}
		Res[Row * k + Col] = resVal;// save resulting value
	}
}
/***************************************************************
** Description: tilled implmentation of Matrix Multiplication,
**inspired from techdarting nivida example, linked above
** 
** Precondition: takes in values that factors in size relative
** to the hardware architreture.
**
**Postcondition: completed matrix with correct values   
*****************************************************************
*/
__global__ void gpuBlockMM(int* deviceA, int* deviceB, int* deviceRes, int dim)
{
	__shared__ int tileA[SIZE][SIZE];
	__shared__ int tileB[SIZE][SIZE];
	int Row = blockIdx.y * SIZE + threadIdx.y;
	int Col = blockIdx.x * SIZE + threadIdx.x;

	int resVal = 0;

	for (int i = 0; i < gridDim.x; ++i)
	{
		if ((Row * dim + i * SIZE + threadIdx.x) <= dim * dim)
		{
			//copy elements to the shared memory for row load
			tileA[threadIdx.y][threadIdx.x] = deviceA[(Row * dim) + (i * SIZE) + threadIdx.x];
		}
		else
		{
			tileA[threadIdx.y][threadIdx.x] = 0;
		}
		if (((i * SIZE + threadIdx.y) * dim + Col) <= dim * dim)
		{
			//copy elements to the shared memory for column load
			tileB[threadIdx.y][threadIdx.x] = deviceB[(i * SIZE + threadIdx.y) * dim + Col];
		}
		else
		{
			tileB[threadIdx.y][threadIdx.x] = 0;
		}
		__syncthreads();//used when bounds of block reached

		for (int k = 0; k < SIZE; ++k)
		{
			//save values from multiplication
			resVal += tileA[threadIdx.y][k] * tileB[k][threadIdx.x];
		}
		__syncthreads();
	}
	if (Row < dim && Col < dim)// making sure the actual rows and columns do not exceed bounds
	{
		deviceRes[Row * dim + Col] = resVal;//saves resulting values
	}
}

/***************************************************************
** Description: implmentation of Matrix Multiplication,
** that will be run on the CPU for baseline comparison
**
** Precondition: takes in values that factors in size relative
** to the hardware architreture.
**
**Postcondition: completed matrix with correct values
*****************************************************************
*/

void cpuMM(int* hostA, int* hostB, int* hostRes, int m, int n, int k) {
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			int C = 0.0;
			for (int l = 0; l < n; ++l)
			{
				C += hostA[i * n + l] * hostB[l * k + j];//saves results to index
			}
			hostRes[i * k + j] = C;//saves resulting values
		}
	}
}



int main()
{
	int m, n, k;
	srand(time(NULL));//using system internal clock for seed
	n = (double)1024;
	m = (double)1024;
	k = (double)1024;

	//allocates memory for host operation
	int* hostA, * hostB, * hostRes, * hostResCopy;
	cudaMallocHost((void**)& hostA, sizeof(int) * m * n);
	cudaMallocHost((void**)& hostB, sizeof(int) * n * k);
	cudaMallocHost((void**)& hostRes, sizeof(int) * m * k);
	cudaMallocHost((void**)& hostResCopy, sizeof(int) * m * k);

	//randomizes variables for host var
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			hostA[i * n + j] = rand() % 20;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			hostB[i * k + j] = rand() % 20;
		}
	}

	float gpuTimeMS, cpuTimeMS, memTimeMS;

//event call for calculating the execution time and memoryCopy
	cudaEvent_t startEvent, stopEvent;
	cudaEventCreate(&startEvent);
	cudaEventCreate(&stopEvent);

	cudaEvent_t startEvent2, stopEvent2;
	cudaEventCreate(&startEvent2);
	cudaEventCreate(&stopEvent2);

	cudaEventRecord(startEvent2, 0);
	
	//allocates memory for device operation
	int* deviceA, * deviceB, * deviceRes;
	cudaMalloc((void**)& deviceA, sizeof(int) * m * n);
	cudaMalloc((void**)& deviceB, sizeof(int) * n * k);
	cudaMalloc((void**)& deviceRes, sizeof(int) * m * k);

	// copy matrix A and B from host to device memory
	cudaMemcpy(deviceA, hostA, sizeof(int) * m * n, cudaMemcpyHostToDevice);
	cudaMemcpy(deviceB, hostB, sizeof(int) * n * k, cudaMemcpyHostToDevice);
	//consideration for a size that is not a multiple of thread per block
	dim3 dimGrid((k + SIZE - 1) / SIZE, (m + SIZE - 1) / SIZE);
	dim3 dimBlock(SIZE, SIZE);
	
	cudaEventRecord(startEvent, 0);
	 //accounts for blocking preconditions
		//gpuBlockMM <<<dimGrid, dimBlock >>> (deviceA, deviceB, deviceRes, n);
	
		gpuMM << <dimGrid, dimBlock >> > (deviceA, deviceB, deviceRes, m, n, k);

	cudaMemcpy(hostRes, deviceRes, sizeof(int) * m * k, cudaMemcpyDeviceToHost);
	cudaDeviceSynchronize();
	cudaEventRecord(stopEvent, 0);
	cudaEventSynchronize(stopEvent);

	cudaEventRecord(stopEvent2, 0);
	cudaEventSynchronize(stopEvent2);

	cudaEventElapsedTime(&memTimeMS, startEvent2, stopEvent2);
	printf("Size of M: %d ,Size of N: %d , Size of K: %d , Milliseconds for Memory recorded: %f , \nmatrix size %dx%d , threads %dx%d  GPU\n", m, n, k, memTimeMS, m,k,SIZE,SIZE);

	cudaEventElapsedTime(&gpuTimeMS, startEvent, stopEvent);
	printf("Size of M: %d ,Size of N: %d , Size of K: %d , Milliseconds for Memory recorded: %f , \nmatrix size %dx%d , threads %dx%d  GPU\n", m, n, k, gpuTimeMS, m, k, SIZE, SIZE);

	cudaEventRecord(startEvent, 0);

	cpuMM(hostA, hostB, hostResCopy, m, n, k);

	cudaEventRecord(stopEvent, 0);
	cudaEventSynchronize(stopEvent);
	
	cudaEventElapsedTime(&cpuTimeMS, startEvent, stopEvent);
	printf("Size of M: %d ,Size of N: %d , Size of K: %d , Milliseconds for Memory recorded: %f , \nmatrix size %dx%d , threads %dx%d  GPU\n", m, n, k, cpuTimeMS, m, k, SIZE, SIZE);

	checkCorrectness(hostResCopy, hostRes, m, k);
	//residual for both resulting array's
	double	sum_err = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			sum_err += abs(hostResCopy[i * k + j] - hostRes[i * k + j]);
		}
	}
	std::cout << "average of residual:\n";
	std::cout << (double)sum_err / (double)(m * n) << "\n";

	// free memory
	cudaEventDestroy(startEvent);
	cudaEventDestroy(stopEvent);
	cudaEventDestroy(startEvent2);
	cudaEventDestroy(stopEvent2);
	cudaFree(deviceA);
	cudaFree(deviceB);
	cudaFree(deviceRes);
	cudaFreeHost(hostA);
	cudaFreeHost(hostB);
	cudaFreeHost(hostRes);
	cudaFreeHost(hostResCopy);
	return 0;
}

/***************************************************************
** Description: takes an input of two completed arrays
** used to check the correctness of matrix
**
** Precondition: takes in values that factors in size relative
** to the hardware architreture.
**
**Postcondition: returns a value that justifies the correctness of
** two matrices results
*****************************************************************
*/

bool checkCorrectness(int* resultDevice, int* resultHost, int m, int k)
{
	bool check = true;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			if (resultDevice[i * k + j] != resultHost[i * k + j])
			{
				printf("INCORRECT\n");
				return false;
			}
		}
	}
	if (check)
		printf("CORRECT\n");
	return true;
}
