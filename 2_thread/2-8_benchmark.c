#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <time.h>

#define NUM_SIMULATIONS 20
#define NUM_TASKS 1000 // Defina o número de tarefas desejado


// Função a ser executada por threads
void *task(void *id) {
    // Realize a tarefa aqui
    return NULL;
}

int main() {
    double time_fork = 0, time_thread = 0;

    for (int sim = 0; sim < NUM_SIMULATIONS; sim++) {
        clock_t start, end;

        // Usando fork
        start = clock();
        for (int i = 0; i < NUM_TASKS; i++) {
            int pid = fork();
            if (pid == 0) {
                // Processo filho realiza a tarefa
                exit(0);
            } else {
                // Processo pai espera pelo filho
                wait(NULL);
            }
        }
        end = clock();
        time_fork += (double)(end - start) / CLOCKS_PER_SEC;

        // Usando threads
        pthread_t threads[NUM_TASKS];
        start = clock();
        for (int i = 0; i < NUM_TASKS; i++) {
            pthread_create(&threads[i], NULL, task, NULL);
        }
        for (int i = 0; i < NUM_TASKS; i++) {
            pthread_join(threads[i], NULL);
        }
        end = clock();
        time_thread += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo médio usando fork: %f segundos\n", time_fork / NUM_SIMULATIONS);
    printf("Tempo médio usando threads: %f segundos\n", time_thread / NUM_SIMULATIONS);

    return 0;
}
