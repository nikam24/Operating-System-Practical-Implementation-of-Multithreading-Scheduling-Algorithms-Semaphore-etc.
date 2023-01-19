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

		for(int i=0;i<row1;i++){
			free(ptr1[i]);
			free(ptr2[i]);
			free(ptr3[i]);
		}

		free(ptr1);
		free(ptr2);
		free(ptr3);

		// Case 2 : ikj
		ptr1 = (int **) malloc(sizeof(int *) * row1);  
		ptr2 = (int **) malloc(sizeof(int *) * row2); 
		ptr3 = (int **) malloc(sizeof(int *) * row1); 
	 
		for(i=0; i<row1; i++) 
	 	ptr1[i] = (int *)malloc(sizeof(int) * col1); 
		for(i=0; i<row2; i++)  
	 	ptr2[i] = (int *)malloc(sizeof(int) * col2); 
		for(i=0; i<row1; i++)  
	 	ptr3[i] = (int *)malloc(sizeof(int) * col2); 

		start=clock();

		for(i=0; i < row1; i++) 
		{ 
			for(k=0; k<col2; k++)
			{ 
				ptr3[i][k] = 0; 
	 			    for(j=0; j < col1; j++)
					ptr3[i][k] = ptr3[i][k] + ptr1[i][j] * ptr2[j][k]; 
			} 
		} 

		printf("Matrix Multiplication done successfully.\n");
		end=clock();
	    execution_time=((double)(end-start))/CLOCKS_PER_SEC;
	            printf("Execution  time of i,k,j : %f\n",execution_time);

		for(int i=0;i<row1;i++){
			free(ptr1[i]);
			free(ptr2[i]);
			free(ptr3[i]);
		}

		free(ptr1);
		free(ptr2);
		free(ptr3);


		// Case 3 : jik

		ptr1 = (int **) malloc(sizeof(int *) * row1);  
		ptr2 = (int **) malloc(sizeof(int *) * row2); 
		ptr3 = (int **) malloc(sizeof(int *) * row1); 
	 
		for(i=0; i<row1; i++) 
	 	ptr1[i] = (int *)malloc(sizeof(int) * col1); 
		for(i=0; i<row2; i++)  
	 	ptr2[i] = (int *)malloc(sizeof(int) * col2); 
		for(i=0; i<row1; i++)  
	 	ptr3[i] = (int *)malloc(sizeof(int) * col2); 

		start=clock();

		
		for(j=0; j < col1; j++) 
		{ 
			
			for(i=0; i < row1; i++)
			{ 
				ptr3[j][i] = 0; 
	 			    for(k=0; k<col2; k++)
					ptr3[j][i] = ptr3[j][i] + ptr1[j][k] * ptr2[k][i]; 
			} 
		} 

		printf("Matrix Multiplication done successfully.\n");
		end=clock();
	    execution_time=((double)(end-start))/CLOCKS_PER_SEC;
	            printf("Execution  time of j,i,k : %f\n",execution_time);

		for(int i=0;i<row1;i++){
			free(ptr1[i]);
			free(ptr2[i]);
			free(ptr3[i]);
		}

		free(ptr1);
		free(ptr2);
		free(ptr3);

		// Case 4 : jki 

		ptr1 = (int **) malloc(sizeof(int *) * row1);  
		ptr2 = (int **) malloc(sizeof(int *) * row2); 
		ptr3 = (int **) malloc(sizeof(int *) * row1); 
	 
		for(i=0; i<row1; i++) 
	 	ptr1[i] = (int *)malloc(sizeof(int) * col1); 
		for(i=0; i<row2; i++)  
	 	ptr2[i] = (int *)malloc(sizeof(int) * col2); 
		for(i=0; i<row1; i++)  
	 	ptr3[i] = (int *)malloc(sizeof(int) * col2); 

		start=clock();

		
		for(j=0; j < col1; j++) 
		{ 
			
			for(k=0; k<col2; k++)
			{ 
				ptr3[j][k] = 0; 
	 			    for(i=0; i < row1; i++)
					ptr3[j][k] = ptr3[j][k] + ptr1[j][i] * ptr2[i][k]; 
			} 
		} 

		printf("Matrix Multiplication done successfully.\n");
		end=clock();
	    execution_time=((double)(end-start))/CLOCKS_PER_SEC;
	            printf("Execution  time of j,k,i : %f\n",execution_time);

		for(int i=0;i<row1;i++){
			free(ptr1[i]);
			free(ptr2[i]);
			free(ptr3[i]);
		}

		free(ptr1);
		free(ptr2);
		free(ptr3);

		// Case 5 : kij 

		ptr1 = (int **) malloc(sizeof(int *) * row1);  
	ptr2 = (int **) malloc(sizeof(int *) * row2); 
	ptr3 = (int **) malloc(sizeof(int *) * row1); 
	 
		for(i=0; i<row1; i++) 
	 	ptr1[i] = (int *)malloc(sizeof(int) * col1); 
		for(i=0; i<row2; i++)  
	 	ptr2[i] = (int *)malloc(sizeof(int) * col2); 
		for(i=0; i<row1; i++)  
	 	ptr3[i] = (int *)malloc(sizeof(int) * col2); 

		start=clock();

		
		 
		for(k=0; k<col2; k++)
		{ 
			
			for(i=0; i < row1; i++)
			{ 
				ptr3[k][i] = 0; 
	 			    for(j=0; j < col1; j++)
					ptr3[k][i] = ptr3[k][i] + ptr1[k][j] * ptr2[j][k]; 
			} 
		} 

		printf("Matrix Multiplication done successfully.\n");
		end=clock();
	    execution_time=((double)(end-start))/CLOCKS_PER_SEC;
	            printf("Execution  time of k,i,j : %f\n",execution_time);

		for(int i=0;i<row1;i++){
			free(ptr1[i]);
			free(ptr2[i]);
			free(ptr3[i]);
		}

		free(ptr1);
		free(ptr2);
		free(ptr3);

	    
		// Case 6 : kji
		
		ptr1 = (int **) malloc(sizeof(int *) * row1);  
	ptr2 = (int **) malloc(sizeof(int *) * row2); 
	ptr3 = (int **) malloc(sizeof(int *) * row1); 
	 
		for(i=0; i<row1; i++) 
	 	ptr1[i] = (int *)malloc(sizeof(int) * col1); 
		for(i=0; i<row2; i++)  
	 	ptr2[i] = (int *)malloc(sizeof(int) * col2); 
		for(i=0; i<row1; i++)  
	 	ptr3[i] = (int *)malloc(sizeof(int) * col2); 

		start=clock();

		
		 
		for(k=0; k<col2; k++)
		{ 
			
			
			for(j=0; j < col1; j++)
			{ 
				ptr3[k][j] = 0; 
	 			    for(i=0; i < row1; i++)
					ptr3[k][j] = ptr3[k][j] + ptr1[k][i] * ptr2[i][j]; 
			} 
		} 

		printf("Matrix Multiplication done successfully.\n\n");
		end=clock();
	    execution_time=((double)(end-start))/CLOCKS_PER_SEC;
	            printf("Execution  time of k,i,j : %f\n",execution_time);

		for(int i=0;i<row1;i++){
			free(ptr1[i]);
			free(ptr2[i]);
			free(ptr3[i]);
		}

		free(ptr1);
		free(ptr2);
		free(ptr3);
		

		// printf("\n\nResultant matrix :");  
		// for(i=0; i< row1; i++)  
		// { 
		// printf("\n\t\t\t"); 
		// for(j=0; j < col2; j++) 	 
		// printf("%d\t", ptr3[i][j]); 
		// } 
	  
	}