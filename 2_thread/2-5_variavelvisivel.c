#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int visivel; // Variavel visivel ao pai e filho


int main() {
    visivel = 1;
    printf("Valor da variavel no processo pai antes do fork: %d\n",visivel);

    int pid = fork();
    
    if (pid < 0) {
        printf("Erro na criação do processo filho\n");
        return 1;
    } 
    
    //Processo Pai
    else if (pid > 0) {
        wait(NULL);
        printf("Valor da variavel no processo pai depois do fork: %d\n", visivel);
    }
    //Processo Filho
    else {
        visivel = 5;
        printf("Valor da variavel no processo filho: %d\n",visivel);
        // O processo filho termina após a ordenação e a impressão
        exit(0);
    }

    return 0;
}
