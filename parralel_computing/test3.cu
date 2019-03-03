#include <stdio.h>
#include <cuda_runtime.h>
#include <cuda.h>
#include <stdlib.h>

#define N 5

__global__ void add(int *a, int *b, int *c) {
	*c += a[threadIdx.x] * b[threadIdx.x];
}

void print_five(int* array){
	for(int i=0; i<5; ++i){
		printf("%d ", array[i]);
	}
	printf("\n");
}

void random_ints(int *a, int n){
   int i;
   for (i = 0; i < n; ++i)
       a[i] = rand() %10;
}

int main(void) {
	int *a, *b, *c; // host copies of a, b, c
	int *d_a, *d_b, *d_c; // device copies of a, b, c
	int size = N * sizeof(int);
	// Alloc space for device copies of a, b, c
	cudaMalloc((void **)&d_a, size);
	cudaMalloc((void **)&d_b, size);
	cudaMalloc((void **)&d_c, size);
	// Alloc space for host copies of a, b, c and setup input values
	a = (int *)malloc(size); random_ints(a, N);
	b = (int *)malloc(size); random_ints(b, N);
	*c = 0;
	cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_c, c, sizeof(int), cudaMemcpyHostToDevice);
	
	// Launch add() kernel on GPU with N blocks
	add<<<1,N>>>(d_a, d_b, d_c);
	// Copy result back to host
	cudaMemcpy(c, d_c, size, cudaMemcpyDeviceToHost);
	print_five(a);
	print_five(b);
	pritf("c: %d\n", c);

	// Cleanup
	free(a); free(b); free(c);
	cudaFree(d_a); cudaFree(d_b);
	return 0;
}