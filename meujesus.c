#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>

sem_t mutex, escritex;
int ret0, ret1, readerCount = 0;

pthread_t leitores[2];
pthread_t escritores[2];
    
void reader(){
    int i = 0;
    while(i < 100){ //while(1) para emular uma execucao sem limite
        sem_wait(&mutex); //bloqueia o acesso ao readerCount por outras threads
        readerCount++;
        printf("H� %d leitores\n", readerCount); //mostra quantos leitores est�o na fila
        if(readerCount == 1) sem_wait(&escritex); //verifica se h� alguma thread lendo para bloquear a escrita
        sem_post(&mutex);
        
        printf("Lendo...\n");//abstra��o de uma leitura
        sleep(1+ (rand()%3));//para randomizar um pouco o comportamento
        
        sem_wait(&mutex);//ap�s um leitor acabar
        readerCount--;
        
        if(readerCount == 0) sem_post(&escritex);//se for o ultimo, desbloqueia a escrita
        sem_post(&mutex);//libera acesso para readerCount
        
        i++;//somente para o loop acabar
    }
}

void writer(){
    int i = 0;
    while(i < 100){ //while(1) para emular uma execu��o sem limite
        sem_wait(&escritex);//bloqueia a escrita para que haja somente um escritor por vez
        printf("Escrevendo...\n");//abstra��o de uma escrita
        sleep(3+(rand()%5));//randomizar o comportamento um pouco

        sem_post(&escritex);//libera a escrita

        i++;//somente para o loop acabar
    }
}

int main(void) {
    
    sem_init(&mutex, 0, 1); //cria o semaforo para o reader count
    sem_init(&escritex, 0, 1);//cria o semaforo para o escritor
    
    for(int i=0; i<2; i++){
    	ret0 = pthread_create( &leitores[i], NULL,reader, NULL);//cria uma thread para cada leitor
	}
    for(int i = 0; i<2; i++){
        ret1 = pthread_create(&escritores[i], NULL, writer, NULL);//cria uma thread para cada escritor
    }
    for(int i=0; i<2; i++){
    	pthread_join(leitores[i], NULL);//para que o main espere a execua��o das threads
	}
    for(int i = 0; i<2; i++){
        pthread_join(escritores[i], NULL);//para que o main espere a execu��o das threads
    }

    
	return 0;
}