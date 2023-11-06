#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define NUM_PROCESSES 300000

void print(int process_id) {
    printf("%d\n", process_id);
}

int main(int argc, char *argv[]) {
    int i;

    for (i = 0; i < NUM_PROCESSES; i++) {
        pid_t child_pid = fork();

        if (child_pid < 0) {
            sleep(2); //Para ter certeza que vai printar a mensagem de erro no momento certo.
            perror("fork");
            printf("ERRO no fork [%d]\n\n",i);
            exit(-1);
        } else if (child_pid == 0) {
            // Child process
            print(i);
            exit(0);
        }
    }

    // Parent process waits for all child processes to finish
    for (int j = 0; j < NUM_PROCESSES; j++) {
        wait(NULL);
    }

    return 0;
}
