#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <locale.h>

#define CHAIRS 5                /* número de cadeiras para os clientes à espera */
#define TRUE 1

sem_t clientes;                /* número de cliente à espera de atendimento */
sem_t barbeiros;                  /* número de barbeiros à espera de clientes */
sem_t mutex;                    /* para exclusão mútua */
sem_t cliente_cortando_mutex;
int esperando = 0;         /* clientes que estão esperando (não estão cortando) */
int count = 0;
int cliente_cortando = 0;
/* protótipos */
void* barbeiro();
void* customer(void *id);
void cortar_cabelo();
void chegada_cliente();
void conseguir_corte();
void desistir_corte();

int main() {
    sem_init(&clientes, TRUE, 0);
    sem_init(&barbeiros, TRUE, 0);
    sem_init(&mutex, TRUE, 1);
    sem_init(&cliente_cortando_mutex, TRUE, 1);

    pthread_t b,c;

    /* criando único barbeiro */
    pthread_create(&b, NULL, (void *) barbeiro, NULL);


    /* criação indefinida de clientes */
    while(count < 100) {
        count++;
        int* c_id = malloc(sizeof(int));
        *c_id = count; // ID relativa da thread
        pthread_create(&c, NULL, (void *) customer, (void*) c_id);
        sleep(1);
    }

return 0;
}

void* barbeiro() {
    while(TRUE) {
        sem_wait(&clientes);   // vai dormir se o número de clientes for 0 
        sem_wait(&mutex);       // obtém acesso a 'esperando' 
        esperando--;            //descresce de um o contador de clientes à espera 
        sem_post(&barbeiros);     // um barbeiro está agora pronto para cortar cabelo 
        sem_post(&mutex);       // libera 'esperando' 
        sem_wait(&cliente_cortando_mutex); // Adquira o semáforo para proteger cliente_cortando
            int cliente_id = cliente_cortando;
        sem_post(&cliente_cortando_mutex);
        cortar_cabelo(&cliente_id);             // corta o cabelo (fora da região crítica) 
    }
    pthread_exit(NULL);
}

void* customer(void *id) {
    sem_wait(&mutex);           /* entra na região crítica */

    if(esperando < CHAIRS) {      /* se não houver cadeiras vazias, saia */
        chegada_cliente(id);
        esperando = esperando + 1;  /* incrementa o contador de clientes à espera */
        sem_post(&clientes);   /* acorda o barbeiro se necessário */
        sem_post(&mutex);       /* libera o acesso a 'esperando' */
        sem_wait(&barbeiros);     /* vai dormir se o número de barbeiros livres for 0 */
        sem_wait(&cliente_cortando_mutex); // Adquira o semáforo para proteger cliente_cortando
            cliente_cortando = *((int *) id);
        sem_post(&cliente_cortando_mutex);
        conseguir_corte(id);          /* sentado e sendo servido */
    }else {
        sem_post(&mutex);       /* a barbearia está cheia; não espera */
        desistir_corte(id);

    }

    pthread_exit(NULL);
}

void cortar_cabelo(void* id){
    setlocale(LC_ALL, "Portuguese");
    if (*((int*)id) > 0){
        printf("\033[0;34m");
        printf("Barbeiro está cortando o cabelo do cliente %d!\n", *((int*)id));
    }
    sleep(3);
}

void chegada_cliente(void* id) {
    setlocale(LC_ALL, "Portuguese");
    printf("\033[0;33m");
    printf("Cliente %d chegou para cortar cabelo!\n", *((int*)id));
}

void conseguir_corte(void* id) {
    setlocale(LC_ALL, "Portuguese");
    printf("\033[0;32m");
    printf("Cliente %d está tendo o cabelo cortado!\n", *((int*)id));
}

void desistir_corte(void* id){
    setlocale(LC_ALL, "Portuguese");
    printf("\033[0;31m");
    printf("Cliente %d desistiu! (O salão está muito cheio!)\n", *((int*)id));
}