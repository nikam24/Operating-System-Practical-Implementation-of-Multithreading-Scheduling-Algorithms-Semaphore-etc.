// Multhithreaded program to increment global variable value by 10 different variables
// I prefer not to go gentle ~Pratham Nikam
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
pthread_t thread_id[10];
int gvar = 0;

//function that is executed as by thread
void *myThreadFun(void *vargp)
{
	sleep(1);
	printf("Hi i am thread with id : %lu \n",pthread_self());
	int oldgvar = gvar;
	gvar += 50000;
	printf("I incremented gvar from gvar = %d to gvar = %d \n",oldgvar,gvar);
	return NULL;
}

int main()
{
	printf("Before Thread\n");
	for(int i=0;i<10;i++){
		pthread_create(&thread_id[i], NULL, myThreadFun, NULL);
		pthread_join(thread_id[i], NULL);
	}
	printf("After Thread\n");
	exit(0);
}

