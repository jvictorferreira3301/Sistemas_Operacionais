#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 3

// cadathread executa esta função
void *print_abc (void *threadid){

if(threadid == 0){
    sleep(1);
    printf("A");
}
else if(threadid == 1){
    sleep(2);
    printf("B");
}
else{
    sleep(3);
    printf("C\n");
}

pthread_exit (NULL);
}


int main (int argc, char *argv[]){
pthread_t thread[NUM_THREADS];
long status, i;

for(i = 0; i < NUM_THREADS; i++) {
    printf ("Creating thread %ld\n", i);
    status = pthread_create (&thread[i], NULL,print_abc, (void *) i);
    
if (status) { // ocorreu um erro
    perror ("pthread_create");
    exit (-1);
}
}
pthread_exit (NULL);
}