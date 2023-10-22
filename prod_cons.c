#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

/* DEFINIÇÃO DE MACROS
- Maximo: número máximo que um produtor produz e que um consumidor consome 
- TBuffer: tamanho do buffer */
#define Maximo 5
#define TBuffer 5

/* PROTÓTIPOS: 'produtor' e 'consumidor' */
void *produtor(void *pno);
void *consumidor(void *cno);
/* SEMÁFOROS:
'vazio': semáforo para indicar a possibilidade de adicionar um novo item ao buffer
'cheio': semáforo para indicar a possibilidade de consumir um item do buffer */
sem_t vazio;
sem_t cheio;
/* VARRÁVEIS DE CONTROLE:
'entrando':
'saindo': */
int entrando = 0;
int saindo = 0;
int buffer[TBuffer]; 
/* Mutex para exclusão mútua ao buffer */
pthread_mutex_t mutex;

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

/* FUNÇÃO PRODUTOR
1. Solicita acesso ao semáforo 'vazio'
2. Se tiver espaço no buffer, continua, se não, espera
3. Solicita lock ao mutex para acesso exclusivo ao buffer
4. Tendo acesso ao buffer, o produtor adiciona 'item' ao buffer na posição 'entrando'
5. 'entrando' é incrementado com limite 'TBuffer'
6. O mutex é liberado
7. O semáforo 'cheio' é incrementado
- O loop acontece 'Maximo' vezes para cada Thread de produtor.
*/
void *produtor(void *pno){
    int item;

    for(int i = 0; i < Maximo; i++) {
        item = rand() % 10; // Produz um item aleatório
        sem_wait(&vazio);
        pthread_mutex_lock(&mutex);
        buffer[entrando] = item;
        printf("Produtor %d: Insere item %d em %d\n", *((int*)pno),buffer[entrando],entrando);
        entrando = (entrando+1)%TBuffer;
        pthread_mutex_unlock(&mutex);
        sem_post(&cheio);
    }
    return 0;
}

/* FUNÇÃO CONSUMIDOR
1. Solicita acesso ao semáforo 'cheio'
2. Se tiver itens a serem consumidos, o semáforo é acessado, se não, a Thread espera
3. Se o semáforo for acessado, solicita lock ao mutex para acessar o buffer
4. Tendo acesso ao buffer, "consome" o item da posição 'saindo' do buffer
5. 'saindo' é incrementado com limite 'TBuffer'
6. O mutex é liberado
7. O semáforo 'vazio' é incrementado
*/
void *consumidor(void *cno){
    for(int i = 0; i < Maximo; i++) {
        sem_wait(&cheio);
        pthread_mutex_lock(&mutex);
        int item = buffer[saindo];
        printf("Consumidor %d: Remove item %d de %d\n",*((int *)cno),item, saindo);
        saindo = (saindo+1)%TBuffer;
        pthread_mutex_unlock(&mutex);
        sem_post(&vazio);
    }
    return 0;
}