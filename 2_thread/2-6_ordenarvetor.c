#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <signal.h>

int vetor[100]; // Vetor compartilhado

// Função de comparação para qsort
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    srand(time(NULL));
    int valor_maximo = 1000;
    // Criação do vetor com valores aleatórios:
    for (int i = 0; i < 100; i++) {
        vetor[i] = rand() % (valor_maximo + 1);
    }
    // Exibindo os valores do vetor no processo Pai antes de ordenar:
    printf("Valores do vetor no processo Pai antes de ordenar:\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    int pid = fork();

    if (pid < 0) {
        printf("Erro na criação do processo filho\n");
        return 1;
    } 
    //Processo Pai
    else if (pid > 0) {
        wait(NULL);
        printf("\n\nValores do Vetor, depois da ordenação no processo filho (fork):\n");
        for (int i = 0; i < 100; i++) {
            printf("%d ", vetor[i]);
        }
        printf("\n");
    }
    //Processo Filho
    else {
        // Ordenando o vetor no processo filho:
        qsort(vetor, sizeof(vetor) / sizeof(vetor[0]), sizeof(int), comparar);
        
        // Impressão dos valores ordenados no processo filho
        printf("\nValores do vetor no processo filho depois da ordenação:\n");
        for (int i = 0; i < 100; i++) {
            printf("%d ", vetor[i]);
        }

        // O processo filho termina após a ordenação e a impressão
        exit(0);
    }

    return 0;
}
