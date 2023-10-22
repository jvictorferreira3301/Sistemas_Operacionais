#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

/* PROÓTIPOS: 'filosofos', 'come' */
void* filosofos(void *);
void* comer(int);

/* DECLARAÇÃO DOS SEMÁFOROS
'filosofo': filósofos na mesa
'garfo': garfos disponíveis na mesa */
sem_t filosofo;
sem_t garfo[5];

int main(){
    int i, a[5];
    pthread_t thread[5];
    // INICIALIZAÇÃO: 'filosofos' sentados à mesa: 5
    sem_init(&filosofo, 0, 4);

    // INICIALIZAÇÃO: cada garfo é disponível a um único filósofo por vez
    for(i = 0; i < 5 ; i++){
        sem_init(&garfo[i], 0, 1); 
    }

    // CRIAÇÃO DAS THREADS
    for(i = 0; i < 5; i++){
        a[i]=i; // Identificação das Threads
        pthread_create(&thread[i], NULL, filosofos, (void *)&a[i]);
    }
    // Sincronização das Threads
    for(i = 0; i < 5; i++){
        pthread_join(thread[i], NULL);
    }
}
/* FUNÇÃO 'filosofos'
1. A posição 'n' do filósofo é passada para a função 
2. O filósofo 'f' solicita acesso ao primeiro garfo de posição 'f'
3. Tendo acesso, solicita acesso ao garfo conseguinte 'f+1'
4. Tendo acesso dos aos dois garfos, chama a função 'come'
5. Terminando de comer, o filósofo 'f' libera os garfos 'f' e 'f+1' */
void* filosofos(void * n){
    int f = *(int *)n;

    sem_wait(&filosofo);
    sem_wait(&garfo[f]);
    sem_wait(&garfo[(f+1)%5]);

    sleep(2);
    comer(f);

    printf("Filósofo %d terminou de comer\n\n", f);
    sem_post(&garfo[(f+1)%5]);
    sem_post(&garfo[f]);
    sem_post(&filosofo);

    return 0;
}
// FUNÇÃO 'comer': Imprime indicando que o filósofo 'f' está comendo
void* comer(int f){
    sleep(1);
    printf("Filósofo %d está comendo\n",f);
    return 0;
}