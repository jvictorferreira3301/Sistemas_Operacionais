#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 3

// cadathread executa esta função
void *print_abc (void *threadid){

if(threadid == (int*)0){
    printf("A");
}
else if(threadid == (int*)1){
    printf("B");
}
else{
    printf("C\n");
}

pthread_exit (NULL);
}


int main(int argc, char *argv[]) {
    pthread_t thread[NUM_THREADS];
    long i;
    int status;

    for (i = 0; i < NUM_THREADS; i++) {
        //printf("Creating thread %ld\n", i);
        status = pthread_create(&thread[i], NULL, print_abc, (void *)i);
        pthread_join(thread[i], NULL);
        if (status) { // Ocorreu um erro
            perror("pthread_create");
            exit(-1);
        }
    }
    
    

    pthread_exit(NULL);
}