#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

// DEFINIÇÃO DE MACROS
#define Maximo 5 // Número máximo de iterações
#define TBuffer 5 // Tamanho do Buffer

// PROTÓTIPOS: 'produtor()' e 'consumidor()' 
void *produtor(void *pno);
void *consumidor(void *cno);
// SEMÁFOROS:
sem_t vazio; // 'vazio': semáforo para indicar se pode adicionar um novo item ao buffer
sem_t cheio; // 'cheio': semáforo para indicar se pode consumir um item do buffer 
// VARRÁVEIS DE CONTROLE:
int entrando = 0; // 'entrando': Variável auxiliar para indexação
int saindo = 0; // 'saindo':  Variável auxiliar para indexação
int buffer[TBuffer]; 
pthread_mutex_t mutex; // Mutex para exclusão mútua ao buffer 

int main(){
    /* VARIÁVEIS 
    Threads: 'pro' produtores, 'con' consumidores */
    pthread_t pro[5],con[5];
    // Inicialização dos semáforos
    pthread_mutex_init(&mutex, NULL);
    sem_init(&vazio,0,TBuffer);
    sem_init(&cheio,0,0);
    // Identificação das Threads
    int a[5] = {1,2,3,4,5};

    // Loop de criação das Threads
    for(int i = 0; i < 5; i++) {
        pthread_create(&pro[i], NULL, (void *)produtor, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&con[i], NULL, (void *)consumidor, (void *)&a[i]);
    }
    // Junção das Threads
    for(int i = 0; i < 5; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(con[i], NULL);
    }
    // Encerramento dos semáforos
    pthread_mutex_destroy(&mutex);
    sem_destroy(&vazio);
    sem_destroy(&cheio);
    return 0;
}

// FUNÇÃO 'produtor()':
void *produtor(void *pno){
    int item;
    for(int i = 0; i < Maximo; i++) {
        item = rand() % 10; // Produz um item aleatório
        sem_wait(&vazio); // Solicita acesso ao semáforo 'vazio'
        pthread_mutex_lock(&mutex); // Solicita lock ao mutex para acesso exclusivo ao buffer
        buffer[entrando] = item; // O produtor adiciona 'item' ao buffer na posição 'entrando'
        printf("\033[0;31m");
        printf("Produtor %d: Insere item %d em %d\n", *((int*)pno),buffer[entrando],entrando);
        entrando = (entrando+1)%TBuffer; // 'entrando' é incrementado com limite 'TBuffer'
        pthread_mutex_unlock(&mutex); // // O mutex é liberado
        sem_post(&cheio); // O semáforo 'cheio' é incrementado
    }
}

// FUNÇÃO CONSUMIDOR
void *consumidor(void *cno){
    for(int i = 0; i < Maximo; i++) {
        sem_wait(&cheio); // Solicita acesso ao semáforo 'cheio'
        pthread_mutex_lock(&mutex); // Solicita lock ao mutex para acessar o buffer
        int item = buffer[saindo]; // "consome" o item da posição 'saindo' do buffer
        printf("\033[0;32m");
        printf("Consumidor %d: Remove item %d de %d\n",*((int *)cno),item, saindo);
        saindo = (saindo+1)%TBuffer; // 'saindo' é incrementado com limite 'TBuffer'
        pthread_mutex_unlock(&mutex); // Libera o mutex
        sem_post(&vazio); // O semáforo 'vazio' é incrementado
    }
}