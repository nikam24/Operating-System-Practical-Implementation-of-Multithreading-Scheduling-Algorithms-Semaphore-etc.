// C Program to create Deadlock situation by the use of mutex lock
// I prefer not to go gentle ~Pratham Nikam
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
pthread_t thread_id[2];
int counter = 0;
pthread_mutex_t lock;

//function that is executed as by thread
void *myThreadFun(void *vargp)
{
	sleep(1);
	
	pthread_mutex_lock(&lock);
			
	// Enter Critical Section
	counter += 1;
	printf("Job %d is started.\n",counter);
	for(int i=0;i<(0xFFFFFFFF);i++); // Wait to see if other thread tries to enter into critical section	
	
	//This statement will lead to a deadlock condition
	//Because we are trying to lock the mutex again, which is not possible
	pthread_mutex_lock(&lock);
	printf("Job %d is finished.\n",counter);
	
	pthread_mutex_unlock(&lock);
	// Exit Critical Section
	return NULL;
}

int main()
{
	printf("Before Thread\n");
	
	pthread_mutex_init(&lock,NULL);
	
	for(int i=0;i<2;i++){
		pthread_create(&thread_id[i], NULL, myThreadFun, NULL);
	}
	
	pthread_join(thread_id[0], NULL);
	pthread_join(thread_id[1], NULL);
	
	printf("After Thread\n");
	exit(0);
}

