	#include <stdio.h>  
	#include<stdlib.h> 
	#include<time.h>

	void main()  
{


	int **ptr1, **ptr2, **ptr3; 

	int row1, col1, row2, col2; 

	int i, j, k; 

	printf("\nEnter number of rows for first matrix : "); 
	scanf("%d", &row1);  
	printf("\nEnter number of columns for first matrix : "); 
	scanf("%d", &col1); 
	printf("\nEnter number of rows for second matrix : "); 
	scanf("%d", &row2); 
	printf("\nEnter number of columns for second matrix : "); 
	scanf("%d", &col2); 
	if(col1 != row2) 
	{ 
		printf("\nCannot multiply two matrices.");  
		return;  
	} 

	ptr1 = (int **) malloc(sizeof(int *) * row1);  
	ptr2 = (int **) malloc(sizeof(int *) * row2); 
	ptr3 = (int **) malloc(sizeof(int *) * row1); 
	 
		for(i=0; i<row1; i++) 
	 	ptr1[i] = (int *)malloc(sizeof(int) * col1); 
		for(i=0; i<row2; i++)  
	 	ptr2[i] = (int *)malloc(sizeof(int) * col2); 
		for(i=0; i<row1; i++)  
	 	ptr3[i] = (int *)malloc(sizeof(int) * col2); 

		// ("\nEnter elements of first matrix :\n");  
		
		for(i=0; i< row1; i++) 
		{ 
			for(j=0; j< col1; j++) 
			{ 
				// printf("\tA[%d][%d] = ",i, j); 
				// scanf("%d", &ptr1[i][j]); 
				ptr1[i][j] = 1;
			} 
		} 

		// printf("\nEnter elements of second matrix :\n"); 
		for(i=0; i< row2; i++) 
		{ 
			for(j=0; j< col2; j++) 
			{ 
				// printf("\tB[%d][%d] = ",i, j); 
				// scanf("%d", &ptr2[i][j]); 
				ptr2[i][j] = 1;
			} 
		} 
		clock_t start,end;
	    float execution_time;

		// Case 1 : ijk
		start=clock();

		for(i=0; i < row1; i++) 
		{ 
			for(j=0; j < col1; j++) 
			{ 
				ptr3[i][j] = 0; 
	 			for(k=0; k<col2; k++)  
					ptr3[i][j] = ptr3[i][j] + ptr1[i][k] * ptr2[k][j]; 
			} 
		} 

		printf("Matrix Multiplication done successfully.\n");
		end=clock();
	    execution_time=((double)(end-start))/CLOCKS_PER_SEC;
	            printf("Execution  time of i,j,k : %f\n",execution_time);

		// Case 2 : ikj
		start=clock();

		for(i=0; i < row1; i++) 
		{ 
			for(k=0; k<col2; k++)
			{ 
				ptr3[i][j] = 0; 
	 			    for(j=0; j < col1; j++)
					ptr3[i][j] = ptr3[i][j] + ptr1[i][k] * ptr2[k][j]; 
			} 
		} 

		printf("Matrix Multiplication done successfully.\n");
		end=clock();
	    execution_time=((double)(end-start))/CLOCKS_PER_SEC;
	            printf("Execution  time of i,k,j : %f\n",execution_time);


		// Case 3 : jik
		start=clock();

		
		for(j=0; j < col1; j++) 
		{ 
			
			for(i=0; i < row1; i++)
			{ 
				ptr3[i][j] = 0; 
	 			    for(k=0; k<col2; k++)
					ptr3[i][j] = ptr3[i][j] + ptr1[i][k] * ptr2[k][j]; 
			} 
		} 

		printf("Matrix Multiplication done successfully.\n");
		end=clock();
	    execution_time=((double)(end-start))/CLOCKS_PER_SEC;
	            printf("Execution  time of j,i,k : %f\n",execution_time);

		// Case 4 : jki 
		start=clock();

		
		for(j=0; j < col1; j++) 
		{ 
			
			for(k=0; k<col2; k++)
			{ 
				ptr3[i][j] = 0; 
	 			    for(i=0; i < row1; i++)
					ptr3[i][j] = ptr3[i][j] + ptr1[i][k] * ptr2[k][j]; 
			} 
		} 

		printf("Matrix Multiplication done successfully.\n");
		end=clock();
	    execution_time=((double)(end-start))/CLOCKS_PER_SEC;
	            printf("Execution  time of j,k,i : %f\n",execution_time);

		// Case 5 : kij 
		start=clock();

		
		 
		for(k=0; k<col2; k++)
		{ 
			
			for(i=0; i < row1; i++)
			{ 
				ptr3[i][j] = 0; 
	 			    for(j=0; j < col1; j++)
					ptr3[i][j] = ptr3[i][j] + ptr1[i][k] * ptr2[k][j]; 
			} 
		} 

		printf("Matrix Multiplication done successfully.\n");
		end=clock();
	    execution_time=((double)(end-start))/CLOCKS_PER_SEC;
	            printf("Execution  time of k,i,j : %f\n",execution_time);

	    
		// Case 6 : kji 
		start=clock();

		
		 
		for(k=0; k<col2; k++)
		{ 
			
			
			for(j=0; j < col1; j++)
			{ 
				ptr3[i][j] = 0; 
	 			    for(i=0; i < row1; i++)
					ptr3[i][j] = ptr3[i][j] + ptr1[i][k] * ptr2[k][j]; 
			} 
		} 

		printf("Matrix Multiplication done successfully.\n");
		end=clock();
	    execution_time=((double)(end-start))/CLOCKS_PER_SEC;
	            printf("Execution  time of k,i,j : %f\n",execution_time);
		

		// printf("\n\nResultant matrix :");  
		// for(i=0; i< row1; i++)  
		// { 
		// printf("\n\t\t\t"); 
		// for(j=0; j < col2; j++) 	 
		// printf("%d\t", ptr3[i][j]); 
		// } 
	  
	}