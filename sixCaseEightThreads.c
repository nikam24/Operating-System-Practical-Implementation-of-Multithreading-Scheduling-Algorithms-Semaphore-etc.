// Multhithreaded program to multiply two large matrices using 8 threads
// G-r-i-n-d i-s e-t-e-r-n-a-l ~Pratham Nikam
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int row = 0,col = 0;
int r1 = 0,c1 = 0,r2 = 0,c2 = 0;
int** A;
int** B;
int** C;

// Calling function for Case 1 : 
void* mult_ijk(void* argv){
	int i = row++;
	
	for(int j=0;j<c1;j++){
		for(int k=0;k<r2;k++){
			C[i][j] += A[i][k]*B[k][j];
		}
	}	
}

// Calling function for Case 2 : 
void* mult_ikj(void* argv){
	int i = row++,j,k;
	
	for(k=0; k<col; k++)
	{ 
		C[i][k] = 0; 
		    for(j=0; j < col; j++)
			C[i][k]+= A[i][j] * B[j][k]; 
	} 	
}

// Calling function for Case 3 : 
void* mult_jik(void* argv){
	int j = col++,i,k;
	
	for(i=0; i < row; i++)
	{ 
		C[j][i] = 0; 
		    for(k=0; k<col; k++)
			C[j][i] += A[j][k] * B[k][i]; 
	}  	
}

// Calling function for Case 4 : 
void* mult_jki(void* argv){
	int j = col++,i,k;
	
	for(k=0; k<col; k++)
	{ 
		C[j][k] = 0; 
		    for(i=0; i < row; i++)
			C[j][k] += A[j][i] * B[i][k]; 
	}  	
}

// Calling function for Case 5 : 
void* mult_kij(void* argv){
	int k = col++,i,j;
	
	for(i=0; i < row; i++)
	{ 
		C[k][i] = 0; 
		    for(j=0; j < col; j++)
			C[k][i] += A[k][j] * B[j][k]; 
	} 	
}

// Calling function for Case 6 : 
void* mult_kji(void* argv){
	int k = col++,i,j;
	
	for(j=0; j < col; j++)
	{ 
		C[k][j] = 0; 
		    for(i=0; i < row; i++)
			C[k][j] += A[k][i] * B[i][j]; 
	} 	
}


int main()
{
	
	printf("Enter no. of row in matrix A : ");
	scanf("%d",&r1);
	printf("Enter no. of col in matrix A : ");
	scanf("%d",&c1);
	printf("Enter no. of row in matrix B : ");
	scanf("%d",&r2);
	printf("Enter no. of col in matrix B : ");
	scanf("%d",&c2);
	
	pthread_t p[r1];	

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
	
	// Case 1 : ijk
	start = clock();
	
	int i = 0;
	
	while(row < r2){
		i = (i+1)%8;
		
		pthread_create(&p[i],NULL,mult_ijk,NULL);
		pthread_join(p[i],NULL);
	}
	
	end = clock();
	
	execution_time = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Execution time with threading : %f\n",execution_time);
	
	// Case 2 : ikj
	start = clock();
	
	row = 0,i = 0;
	
	while(row < r2){
		i = (i+1)%8;
		
		pthread_create(&p[i],NULL,mult_ikj,NULL);
		pthread_join(p[i],NULL);
	}
	
	end = clock();
	
	execution_time = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Execution time with threading : %f\n",execution_time);
	
	// Case 3 : jik
	start = clock();
	
	i = 0,col = 0;
	
	while(col < c1){
		i = (i+1)%8;
		
		pthread_create(&p[i],NULL,mult_jik,NULL);
		pthread_join(p[i],NULL);
	}
	
	end = clock();
	
	execution_time = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Execution time with threading : %f\n",execution_time);
	
	// Case 4 : jki
	start = clock();
	
	i = 0,col = 0;
	
	while(col < c1){
		i = (i+1)%8;
		
		pthread_create(&p[i],NULL,mult_jki,NULL);
		pthread_join(p[i],NULL);
	}
	
	end = clock();
	
	execution_time = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Execution time with threading : %f\n",execution_time);
	
	// Case 5 : kij
	start = clock();
	
	i = 0,col = 0;
	
	while(col < c1){
		i = (i+1)%8;
		
		pthread_create(&p[i],NULL,mult_kij,NULL);
		pthread_join(p[i],NULL);
	}
	
	end = clock();
	
	execution_time = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Execution time with threading : %f\n",execution_time);
	
	// Case 6 : kji
	start = clock();
	
	i = 0,col = 0;
	
	while(col < c1){
		i = (i+1)%8;
		
		pthread_create(&p[i],NULL,mult_kji,NULL);
		pthread_join(p[i],NULL);
	}
	
	end = clock();
	
	execution_time = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Execution time with threading : %f\n",execution_time);
	
	for(int i=0;i<r1;i++) free(A[i]);
	free(A);
	
	for(int i=0;i<r2;i++) free(B[i]);
	free(B);
	
	for(int i=0;i<r1;i++) free(C[i]);
	free(C);
	
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
