#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    int PID_avo, PID_pai, PID_filho;

    // Cria um processo avô
    PID_avo = getpid();
    printf("PID do processo Avô: %d\n", PID_avo);

    // Cria um processo pai
    PID_pai = fork();

    if (PID_pai < 0) {
        printf("Erro na criação do processo pai\n");
        exit(-1);
    } else if (PID_pai > 0) {
        // Processo Pai
        printf("PID do processo Pai: %d\n", PID_pai);

        // Cria um processo filho
        PID_filho = fork();

        if (PID_filho < 0) {
            printf("Erro na criação do processo filho\n");
            exit(-1);
        } else if (PID_filho == 0) {
            // Processo Filho
            printf("PID do processo Filho: %d\n", getpid());
            
            // Aguarde um pouco antes de matar o pai
            sleep(2);

            // "Elimine" o processo Pai
            kill(PID_pai, SIGKILL);

            // Aguarde um pouco para que o processo Pai seja encerrado
            sleep(2);

            // Mostre quem é o novo pai do processo Filho
            printf("PPID do processo Filho (Novo Pai): %d\n", getppid());

            // O processo Filho continua a ser executado
            for (;;) {
                sleep(1);
            }
        } else {
            // Processo Pai continua aqui
            for (;;) {
                sleep(1);
            }
        }
    }

    return 0;
}
