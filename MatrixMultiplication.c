// Multhithreaded program to increment global variable value by 10 different variables
// I prefer not to go gentle ~Pratham Nikam
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
pthread_t thread_id[3];
int row = 0;

//function that is executed as by thread
//void *myThreadFun(void *vargp)
//{
	//sleep(1);
	//printf("Hi i am thread with id : %lu \n",pthread_self());
//	int oldgvar = gvar;
//	for(int i=0;i<50000;i++){
//		gvar++;
//	}
	//gvar += 50000;
//	printf("I incremented gvar from gvar = %d to gvar = %d \n",oldgvar,gvar);
//	return NULL;
//}

int main()
{
	int r1,c1,r2,c2;
	printf("Enter no. of row in matrix A : ");
	scanf("%d",&r1);
	printf("Enter no. of col in matrix A : ");
	scanf("%d",&c1);
	printf("Enter no. of row in matrix B : ");
	scanf("%d",&r2);
	printf("Enter no. of col in matrix B : ");
	scanf("%d",&c2);
	
	if(c1 != r2){
		printf("Matrix multiplication of A and B is not possible\n");
	}
	
	int** A = (int**)malloc(sizeof(r1*(int*)));
	
	for(int i=0;i<r1;i++) A[i] = (int*)malloc(sizeof(c1*(int)));
	
	int** B = (int**)malloc(sizeof(r2*(int*)));
	
	for(int i=0;i<r2;i++) B[i] = (int*)malloc(sizeof(c2*(int)));
	
	int** C = (int**)malloc(sizeof(r1*(int*)));
	
	for(int i=0;i<r1;i++) A[i] = (int*)malloc(sizeof(c2*(int)));
	
	
	for(int i=0;i<r1;i++){
		for(int j=0;j<c1;j++){
			A[i][j] = 1;
		}
	}
	
	for(int i=0;i<r2;i++){
		for(int j=0;j<c2;j++){
			B[i][j] = 1;
		}
	}
	
	for(int i=0;i<r1;i++){
		for(int j=0;j<c2;j++){
			for(int k=0;k<c1;k++){
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	
	for(int i=0;i<r1;i++){
		for(int j=0;j<c2;j++){
			for(int k=0;k<c1;k++){
				printf("%d ",C[i][j]);
			}
			printf("\n");
		}
	}	

	//printf("Before Thread\n");
	//for(int i=0;i<10;i++){
	//	pthread_create(&thread_id[i], NULL, myThreadFun, NULL);
	//	pthread_join(thread_id[i], NULL);
	//}
	//printf("After Thread\n");
	exit(0);
}

