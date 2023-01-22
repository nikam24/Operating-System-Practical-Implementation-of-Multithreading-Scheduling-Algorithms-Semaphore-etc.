// Parrallel programming using openMP library
// I prefer not to go gentle ~Pratham Nikam
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<omp.h>

// Performance gain is achieved over running the loops 
// more than 10^8 times

// Loop running lesser than 10^8 times is killing out the benefit 
// of faster execution due to the overhead of creation and management of thread

// Compiliation can be done using following command : 
// $gcc -fopenmp -o pratham filename.c

int main()
{
	
	int i,n;
	
	printf("Enter value of n : ");
	scanf("%d",&n);
	
	clock_t start,end;
	float execution_time;
	
	// Execution of loop without threads
	
	start = clock();
	
	for(i=0;i<n;i++){
		//printf("Hello from not so thread\n");
	}
	
	end = clock();
	
	execution_time = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Execution time is %f\n", execution_time);
	
	
	// Execution of loop with openMP threads
	
	start = clock();
	
	#pragma omp parallel for
	for(i=0;i<n;i++){
		//int id = omp_get_thread_num();
		//printf("Hello from thread %d\n", id);
	}
	
	end = clock();
	
	execution_time = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Execution time is %f\n", execution_time);
	
	return 0;
}

