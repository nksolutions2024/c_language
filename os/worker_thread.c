#include <pthread.h>
#include <stdio.h>

void* worker_thread(void* arg)
{
    printf("Worker thread is running!\n");
    return NULL;
}

int main()
{
    pthread_t worker;
    int status;

    // Create the worker thread
    status = pthread_create(&worker, NULL, worker_thread, NULL);
    if (status != 0) {
        fprintf(stderr, "Error: Could not create thread (code %d)\n", status);
        return 1; // simple error code, no stdlib
    }

    // Wait for the worker thread to finish
    status = pthread_join(worker, NULL);
    if (status != 0) {
        fprintf(stderr, "Error: Could not join thread (code %d)\n", status);
        return 1;
    }

    printf("Main thread: Worker has finished.\n");
    return 0;
}

