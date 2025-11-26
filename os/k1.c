#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

#define NUM_THREADS 5

void* print_thread_message(void *arg){
	long thread_index;
	thread_index = (long)arg;
	printf("hhelllo world! it's me , thread #%ld\n", thread_index);
	pthread_exit(NULL);
}

int main(){
	pthread_t thread_handles[NUM_THREADS];

	int create_status;
	long i;

	for(i=0; i<NUM_THREADS; i++){
		printf("In main: creating thread %ld\n", i);
		create_status = pthread_create(&thread_handles[i], NULL, print_thread_message, (void*)i);

		if(create_status != 0)
		{
			printf("ERROR: return code from pthread_create() is %d\n", create_status);
			exit(-1);
		}
	}

	pthread_exit(NULL);
}	


