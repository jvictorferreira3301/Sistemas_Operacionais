#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <locale.h>
#include <unistd.h>

/* DEFINIÇÃO DE MACROS:
'LEITORES': Número de leitores
'ESCRITORES': Número de escritores */
#define LEITORES 10
#define ESCRITORES 5

/* SEMÁFOROS:
'db': Garante acesso à base de dados
'mutex': Garante acesso à variável 'leitor_lendo' */
pthread_mutex_t db;
pthread_mutex_t mutex;
int leitor_lendo, cnt = 0; // O contador 'cnt' representa o dado compartilhado

/*FUNÇÕES DE AÇÃO:
'ler_base_de_dados()': Leittura abstrata da base de dados
'usar_banco_de_dados()': Uso abstrato do dado
'pensando_nos_dados': Escritores "pensam" no dado que vai ser escrito
'escrever_no_banco_de_dados': Escritores modificam o contador 'cnt' */
void ler_base_de_dados(void*ln);
void usar_banco_de_dados(void*ln);
void pensando_nos_dados(void* en);
void escrever_no_banco_de_dados(void* en);

/* FUNÇÃO 'leitor()':
1. Recebe o id simbólico 'ln' da thread leitor
2. Inicia o Loop infinito
3. Solicita acesso à variável 'leitor_lendo'
4. Tendo acesso, incrementa a variável
5. Se for o primeiro/único leitor lendo, solicita acesso exclusivo à base de dados
6. Tendo acesso, libera a variável 'leitor_lendo'
7. Tendo acesso à base de dados, chama a função de leitura 'ler_base_de_dados'
8. Solicita acesso exclusivo à variável 'leitor_lendo'
9. Tendo acesso, decrementa a variável
10. Se não houverem mais leitores na fila, a base de dados é liberada
11. A variável 'leitor_lendo' é liberada
12. O leitor consome o dado lido*/
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
/* FUNÇÃO 'escritor()':
1. Recebe o id simbólico 'en' da thread escritor
2. Passa um tempo na função 'pensando_nos_dados'
3. Solciita acesso à base de dados
4. Tendo acesso, chama a função 'escrever_no_banco_de_dados'
5. Libera o acesso à base de dados */
void escritor(void* en){
    
    while(1){
        pensando_nos_dados(en); // Passa um tempo na função
        pthread_mutex_lock(&db); // Acesso à base de dados
        escrever_no_banco_de_dados(en); // Escrita na base de dados

        pthread_mutex_unlock(&db); // Libera a base de dados
    }
}
/*FUNÇÃO 'ler_base_de_dados':
1. Define um tempo de leitura
2. Imprime a ação de leitura da thread leitor
3. Suspende a thread leitor por 'tempo_de_leitura' segundos*/
void ler_base_de_dados(void*ln){

    setlocale(LC_ALL, "Portuguese");

        int tempo_de_leitura;
        tempo_de_leitura = rand() % 5;

        printf("Leitor %d LENDO %d do banco de dados. Total de %d leitores LENDO agora.\n", *((int*)ln), cnt,leitor_lendo);
        sleep(tempo_de_leitura);
}
/*FUNÇÃO 'usar_banco_de_dados':
1. Define um tempo de uso
2. Imprime a ação de uso a partir da leitura do dado pela thread leitor
3. Suspende a thread leitor por 'tempo_de_uso' segundos*/
void usar_banco_de_dados(void*ln){
    setlocale(LC_ALL, "Portuguese");
        int tempo_de_uso;
        tempo_de_uso = rand() % 15;
        printf("A partir do leitor %d, usuário está utilizando o contador %d adquirido no banco de dados.\n", *((int*)ln), cnt);
        sleep(tempo_de_uso);
}
/*FUNÇÃO 'pensando_nos_dados':
1. Define um tempo de "pensamento"
2. Imprime a ação de pensar do escritor
3. Suspende a thread escritor por 'tempo_para_pensar' segundos*/
void pensando_nos_dados(void*en){
    setlocale(LC_ALL, "Portuguese");
        int tempo_para_pensar;
        tempo_para_pensar = rand() % 10;

        printf("Escritor %d PENSANDO no que irá escrever.\n", *((int*)en));
        sleep(tempo_para_pensar);
}
/*FUNÇÃO 'escrever_no_banco_de_dados':
1. Define um tempo de escrita
2. Imprime a ação de escrita pelo escritor e estado do dado compartilhado
3. Suspende a thread escritor por 'tempo_de_escrita' segundos*/
void escrever_no_banco_de_dados(void* en){
    setlocale(LC_ALL, "Portuguese");
        int tempo_de_escrita;
        tempo_de_escrita = rand() % 10;
        cnt++;
        printf("Escritor %d ESCREVENDO no banco de dados. Contador em %d\n", *((int*)en), cnt);
        sleep(tempo_de_escrita);
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