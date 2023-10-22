#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int PID_pai;

    // Cria um processo pai
    PID_pai = fork();

    if (PID_pai < 0) {
        printf("Erro na criação do processo pai\n");
        exit(-1);
    } else if (PID_pai > 0) {
        // Processo Pai
        printf("PID do processo Avô: %d\n",getppid());
        printf("PID do processo Pai: %d\n", getpid());
        
        // Espere pelo processo filho (neto)
        //wait(NULL);
        wait(NULL);
    } else {
        // Processo Filho (Neto
        printf("PID do processo neto: %d\n", getpid());
        for(;;){
            
        }
    }

    return 0;
}
