// C Program to demonstrate Race Condition due to concurrent execution of threads ( Critical Section Problem )
// I prefer not to go gentle ~Pratham Nikam
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
pthread_t thread_id[2];
int counter = 0;

//function that is executed as by thread
void *myThreadFun(void *vargp)
{
	sleep(1);
	counter += 1;
	printf("Job %d is started.\n",counter);
	for(int i=0;i<(0xFFFFFFFF);i++);	
	printf("Job %d is finished.\n",counter);
	return NULL;
}

int main()
{
	printf("Before Thread\n");
	
	for(int i=0;i<2;i++){
		pthread_create(&thread_id[i], NULL, myThreadFun, NULL);
	}
	
	pthread_join(thread_id[0], NULL);
	pthread_join(thread_id[1], NULL);
	
	printf("After Thread\n");
	exit(0);
}

