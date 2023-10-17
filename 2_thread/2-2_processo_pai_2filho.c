#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Printa o PID do processo pai
    printf("Bom dia, eu me apresento. Sou o processo %d.\n", getpid());

    // Cria o primeiro processo filho (Filho 1)
    int pid_filho1 = fork();

    if (pid_filho1 < 0) {
        printf("Erro na criação do primeiro processo filho\n");
        return 1;
    } else if (pid_filho1 == 0) {
        // Este é o código executado pelo primeiro filho (Filho 1)
        printf("Oi, eu sou o processo filho 1, com PID %d. Meu pai é o processo %d.\n", getpid(), getppid());
        return 0;
    } else {
        // O processo pai espera pelo primeiro filho terminar
        wait(NULL);

        /* Cria o segundo processo filho (Filho 2), pois como estamos dentro do processo pai se criarmos
        outro processo, estará rodando dentro do processo pai, ou seja um mesmo processo tem dois filhos.
        */
        int pid_filho2 = fork();

        if (pid_filho2 < 0) {
            printf("Erro na criação do segundo processo filho\n");
            return 1;
        } else if (pid_filho2 == 0) {
            // Este é o código executado pelo segundo filho (Filho 2)
            printf("Oie, eu sou o processo filho 2, com PID %d. Meu pai é o processo %d.\n", getpid(), getppid());
            return 0;
        } else {
            // O processo pai espera pelo segundo filho terminar
            wait(NULL);
        }
    }

    return 0;
}
