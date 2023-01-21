// Multhithreaded program to increment global variable value by 10 different variables
// I prefer not to go gentle ~Pratham Nikam
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
//pthread_t thread_id[3];
int row = 0;
int r1 = 0,c1 = 0,r2 = 0,c2 = 0;
int** A;
int** B;
int** C;

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

void* mult(void* argv){
	int i = row++;
	
	for(int j=0;j<c1;j++){
		for(int k=0;k<r2;k++){
			C[i][j] += A[i][k]*B[k][j];
		}
	}
}



int main()
{
	pthread_t p[4];	
	
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
		return 0;
	}
	
	A = malloc(r1*sizeof(int*));
	
	for(int i=0;i<r1;i++) A[i] = (int*)malloc(c1*sizeof(int));
	
	B = malloc(r2*sizeof(int*));
	
	for(int i=0;i<r2;i++) B[i] = (int*)malloc(c2*sizeof(int));
	
	C = malloc(r1*sizeof(int*));
	
	for(int i=0;i<r1;i++) C[i] = (int*)malloc(c2*sizeof(int));
	
	
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
	
	clock_t start,end;
	float execution_time;
	
	// Matrix Multiplication without threading
	
	start = clock();
	
	for(int i=0;i<r1;i++){
		for(int j=0;j<c1;j++){
			for(int k=0;k<r2;k++){
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	
	end = clock();
	
	execution_time = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Execution time of without threading : %f\n",execution_time);
	
	
	start = clock();
	
	for(int i=0;i<r1;i++){
		pthread_create(&p[i],NULL,mult,NULL);
	}
	
	for(int i=0;i<r1;i++){
		pthread_join(p[i],NULL);
	}
	
	//for(int i=0;i<r1;i++){
	//	for(int j=0;j<c1;j++){
	//		for(int k=0;k<r2;k++){
	//			C[i][j] += A[i][k]*B[k][j];
	//		}
	//	}
	//}
	
	end = clock();
	
	execution_time = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Execution time with threading : %f\n",execution_time);
	
	//for(int i=0;i<r1;i++){
	//	for(int j=0;j<c1;j++){
	//		printf("%d ",C[i][j]);
	//	}
	//	printf("\n");
	//}	

	//printf("Before Thread\n");
	//for(int i=0;i<10;i++){
	//	pthread_create(&thread_id[i], NULL, myThreadFun, NULL);
	//	pthread_join(thread_id[i], NULL);
	//}
	//printf("After Thread\n");
	
	return 0;
}
