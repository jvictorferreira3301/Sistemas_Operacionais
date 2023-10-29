#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <locale.h>

// DEFINIÇÃO DE MACROS
#define CHAIRS 5 // Número de cadeiras para os clientes à espera
#define TRUE 1 // Estado padrão

sem_t clientes; // 'clientes': Número de cliente à espera de atendimento 
sem_t barbeiros; // 'barbeiros': Número de barbeiros à espera de clientes 
sem_t mutex; // 'mutex': Garante acesso exclusivo à 'esperando'
sem_t cliente_cortando_mutex; // Garante exclusão mútua à 'cliente_cortando'
int esperando = 0; // Clientes que estão esperando (não estão cortando) 
int count = 0; // Variável auxiliar para contagem no loop 'while(count < 100)'
int cliente_cortando = 0; // Variável auxiliar de indexação

// PROTÓTIPOS
void* barbeiro(); // Função padrão dos barbeiros
void* cliente(void* id); // Função padrão dos cleintes
void cortar_cabelo(); // Indica que o barbeiro está cortando o cabelo
void chegada_cliente(); // Indica a chegada de um novo cliente
void conseguir_corte(); // Indica o que um cliente conseguiu acesso ao barbeiro
void desistir_corte(); // Indica que um cliente desistiu de cortar o cabelo

int main() {
    sem_init(&clientes, TRUE, 0);
    sem_init(&barbeiros, TRUE, 0);
    sem_init(&mutex, TRUE, 1);
    sem_init(&cliente_cortando_mutex, TRUE, 1);
    pthread_t b,c;
    // INICIALIAÇÃO da threads 'c' de clientes e b 'b' de barbeiros
    pthread_create(&b, NULL, (void *) barbeiro, NULL);
    while(count < 100) {
        count++;
        int* c_id = malloc(sizeof(int));
        *c_id = count; // ID relativa da thread
        pthread_create(&c, NULL, (void *) cliente, (void*) c_id);
        sleep(1);
    }
return 0;
}
// FUNÇÃO 'barbeiro()':
void* barbeiro() {
    while(TRUE) {
        sem_wait(&clientes); // Vai dormir se o número de clientes for 0 
        sem_wait(&mutex); // Obtém acesso a 'esperando' 
        esperando--; // Descresce de um o contador de clientes à espera 
        sem_post(&barbeiros); // Um barbeiro está agora pronto para cortar cabelo 
        sem_post(&mutex); // Libera 'esperando' 
        sem_wait(&cliente_cortando_mutex); // Exclusão mútua à 'cliente_cortando'
            int cliente_id = cliente_cortando; // ID do cliente que está sendo atendido
        sem_post(&cliente_cortando_mutex); // Libera o mutex 'cliente_cortando_mutex'
        cortar_cabelo(&cliente_id); // Corta o cabelo (fora da região crítica) 
    }
    pthread_exit(NULL);
}
// FUNÇÃO 'cliente()':
void* cliente(void *id) {
    sem_wait(&mutex); // Acesso à região crítica
    if(esperando < CHAIRS) { // Se não houver cadeiras vazias, saia 
        chegada_cliente(id); // Indica a chegada de um cliente.
        esperando = esperando + 1; // Incrementa o contador de clientes à espera
        sem_post(&clientes); // Acorda o barbeiro se necessário 
        sem_post(&mutex); // Libera o acesso a 'esperando' 
        sem_wait(&barbeiros); // Vai dormir se o número de barbeiros livres for 0 
        sem_wait(&cliente_cortando_mutex); // Adquira o semáforo para proteger cliente_cortando
            cliente_cortando = *((int *) id); // ID cliente atendido atualizado
        sem_post(&cliente_cortando_mutex); 
        conseguir_corte(id); // Sentado e sendo servido 
    }else {
        sem_post(&mutex); // A barbearia está cheia; não espera 
        desistir_corte(id); // Desiste o do corte
    }
    pthread_exit(NULL);
}
// FUNÇÃO 'cortar_cabelo()':
void cortar_cabelo(void* id){
    setlocale(LC_ALL, "Portuguese"); // Linguagem
    if (*((int*)id) > 0){ // Indica o cliente que está sendo atendido, se houver
        printf("\033[0;34m");
        printf("Barbeiro está cortando o cabelo do cliente %d!\n", *((int*)id));
    }
    sleep(3);
}
// FUNÇÂO 'chegada_cliente()':
void chegada_cliente(void* id) {
    // Indica a chegada de um novo cliente
    setlocale(LC_ALL, "Portuguese");
    printf("\033[0;33m");
    printf("Cliente %d chegou para cortar cabelo!\n", *((int*)id));
}
// FUNÇÃO 'conseguir_corte()':
void conseguir_corte(void* id) {
    // Indica que um cliente conseguiu ser atendido
    setlocale(LC_ALL, "Portuguese");
    printf("\033[0;32m");
    printf("Cliente %d está tendo o cabelo cortado!\n", *((int*)id));
}
// FUNÇÂO 'desistir_corte()':
void desistir_corte(void* id){
    // Indica a desistência de um cliente
    setlocale(LC_ALL, "Portuguese");
    printf("\033[0;31m");
    printf("Cliente %d desistiu! (O salão está muito cheio!)\n", *((int*)id));
}