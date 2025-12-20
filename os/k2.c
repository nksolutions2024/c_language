#include<pthread.h>
#include<stdio.h>

void * worker_thread(void* arg){
	printf("Thread is running!\n");
	return NULL;
}

int main(){
	pthread_t worker;
	int status;

	status = pthread_create(&worker, NULL, worker_thread, NULL);
	
	status = pthread_join(worker, NULL);
	printf("Main thread: Worker has finished. \n");

	return 0;
}
