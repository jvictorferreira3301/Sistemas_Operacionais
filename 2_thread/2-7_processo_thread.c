#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 300000

// cadathread executa esta função
void *print_abc (void *threadid){
    printf("%d\n",threadid);
pthread_exit (NULL);
}


int main(int argc, char *argv[]) {
    pthread_t thread[NUM_THREADS];
    long i;
    int status;

    for (i = 0; i < NUM_THREADS; i++) {
        //printf("Creating thread %ld\n", i);
        status = pthread_create(&thread[i], NULL, print_abc, (void *)i);
        
        if (status) { // Ocorreu um erro
            perror("pthread_create");
            exit(-1);
        }
    }
    for(int j = 0; j< NUM_THREADS; j++){
        pthread_join(thread[j], NULL);
    }
    
    
    

    pthread_exit(NULL);
}