// C program demonstrating the use of fork() system call
// I prefer not to go gentle ~Pratham Nikam
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main()
{
	// Returned value from fork() call is stored
	int gotfromfork = fork();
	
	// if returned value is -1 means child process was not created successfully.
	if(gotfromfork == -1) printf("Child was not created successfully.\n");
	
	// if returned value is +ve means child process was created successfully and 
	// the value is process id of new child process and we are currently in parent process.
	else if(gotfromfork > 0) printf("Child created successfully with process id : %d \n", gotfromfork);
	
	// We are currently working in newly created child process
	else printf("Hi from child!!!\n");
	
	pid_t pid;
	pid = getpid();
	
	printf("Hello pratham!!! My process id is %d \n",pid);
	
	return;
}
