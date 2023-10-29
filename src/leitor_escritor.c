#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <locale.h>
#include <unistd.h>

// DEFINIÇÃO DE MACROS:
#define LEITORES 10 // Número de leitores
#define ESCRITORES 5 // Número de escritores

// SEMÁFOROS:
pthread_mutex_t db; // 'db': Garante acesso à base de dados.
pthread_mutex_t mutex; // 'mutex': Garante acesso à variável 'leitor_lendo'.

int leitor_lendo, // Representa o número de leitores ativos no momento.
cnt = 0; // O contador 'cnt' representa o dado compartilhado.

// FUNÇÕES DE AÇÃO:
void ler_base_de_dados(void*ln); // Leitura abstrata da base de dados
void usar_banco_de_dados(void*ln); // Uso do dado
void pensando_nos_dados(void* en); // Escritores "pensam" no dado que vai ser escrito
void escrever_no_banco_de_dados(void* en); // Escritores modificam o contador 'cnt'

// FUNÇÃO 'leitor()'
void leitor(void* ln){
    while(1){
        pthread_mutex_lock(&mutex); // Acesso à variável 'leitor_lendo'
        leitor_lendo++;

        if(leitor_lendo == 1) 
            pthread_mutex_lock(&db); // Acesso à base de dados
        pthread_mutex_unlock(&mutex);   // Libera 'leitor_lendo'

        ler_base_de_dados(ln); // Leitura do dado compartilhado
        pthread_mutex_lock(&mutex); // Acesso à variável 'leitor_lendo'
        leitor_lendo--; 

        if(leitor_lendo == 0) 
            pthread_mutex_unlock(&db); // Libera o acesso à base de dados
        pthread_mutex_unlock(&mutex); // Libera 'leitor_lendo'
        
        usar_banco_de_dados(ln); // Usa o dado
    }
}
// FUNÇÃO 'escritor()'
void escritor(void* en){
    while(1){
        pensando_nos_dados(en); // Passa um tempo na função
        pthread_mutex_lock(&db); // Acesso à base de dados
        escrever_no_banco_de_dados(en); // Escrita na base de dados

        pthread_mutex_unlock(&db); // Libera a base de dados
    }
}

int main(){
    // THREADS: 'escritores' e 'leitores'
    pthread_t escritores[ESCRITORES], leitores[LEITORES];
    int i;
    // INICIALIZAÇÃO: semáforos 'db' e 'mutex'
    pthread_mutex_init(&db, NULL);
    pthread_mutex_init(&mutex, NULL);

    // CRIAÇÃO DAS THREADS DE ESCRITORES
    for(i=0; i<ESCRITORES; i++){
        int* escritor_id = malloc(sizeof(int));
        *escritor_id = i+1; // ID relativa da thread 
        pthread_create(&escritores[i], NULL, (void*) escritor, (void*) escritor_id);
    }
    // CRIAÇÃO DAS THREADS DE LEITORES
    for(i=0; i<LEITORES; i++){
        int* leitor_id = malloc(sizeof(int));
        *leitor_id = i+1; // ID relativa da thread
        pthread_create(&leitores[i], NULL, (void*) leitor, (void*) leitor_id);
    }
    // SINCRONIZAÇÃO DAS THREADS DE ECRITORES
    for(i=0; i<ESCRITORES; i++){
        pthread_join(escritores[i], NULL);
    }
    // SINCRONIZAÇÃO DAS THREADS DE LEITORES
    for(i=0; i<LEITORES; i++){
        pthread_join(leitores[i], NULL);
    }
    return 0;
}
// FUNÇÃO 'ler_base_de_dados':
void ler_base_de_dados(void*ln){
    setlocale(LC_ALL, "Portuguese");
        int tempo_de_leitura; 
        tempo_de_leitura = rand() % 5; // Define um tempo de leitura
        printf("\033[0;32m");
        // Imprime a ação de leitura da thread leitor
        printf("Leitor %d LENDO %d do banco de dados. Total de %d leitores LENDO agora.\n", *((int*)ln), cnt,leitor_lendo); 
        sleep(tempo_de_leitura); // Suspende a thread leitor por 'tempo_de_leitura' segundos
}
// FUNÇÃO 'usar_banco_de_dados':
void usar_banco_de_dados(void*ln){
    setlocale(LC_ALL, "Portuguese");
        int tempo_de_uso;
        tempo_de_uso = rand() % 15; // Define um tempo de uso
        printf("\033[0;34m");
        // Imprime a ação de uso a partir da leitura do dado pela thread leitor
        printf("A partir do leitor %d, usuário está utilizando o contador %d adquirido no banco de dados.\n", *((int*)ln), cnt);
        sleep(tempo_de_uso); // Suspende a thread leitor por 'tempo_de_uso' segundos
}
// FUNÇÃO 'pensando_nos_dados':
void pensando_nos_dados(void*en){
    setlocale(LC_ALL, "Portuguese");
        int tempo_para_pensar;
        tempo_para_pensar = rand() % 10; // Define um tempo de "pensamento"
        printf("\033[0;34m");
        // Imprime a ação de pensar do escritor
        printf("Escritor %d PENSANDO no que irá escrever.\n", *((int*)en));
        sleep(tempo_para_pensar); // Suspende a thread escritor por 'tempo_para_pensar' segundos
}
// FUNÇÃO 'escrever_no_banco_de_dados':
void escrever_no_banco_de_dados(void* en){
    setlocale(LC_ALL, "Portuguese");
        int tempo_de_escrita;
        tempo_de_escrita = rand() % 10; // Define um tempo de escrita
        cnt++; // Modifica o dado compartilhado
        printf("\033[0;31m");
        // Imprime a ação de escrita pelo escritor e estado do dado compartilhado
        printf("Escritor %d ESCREVENDO no banco de dados. Contador em %d\n", *((int*)en), cnt);
        sleep(tempo_de_escrita); // Suspende a thread escritor por 'tempo_de_escrita' segundos
}