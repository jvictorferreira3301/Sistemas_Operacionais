#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TIME_SLICE 2


/*
A função a seguir tem a finalidade de calcular o tempo de espera para cada processo em 
uma lista de processos. O tempo de espera é calculado somando-se o tempo de execução do
processo anterior com o tempo de espera do processo anterior.
*/
int waitingtime(int proc[], int n, int burst_time[], int wait_time[]) {
    wait_time[0] = 0;
    for (int i = 1; i < n; i++) {
        wait_time[i] = burst_time[i - 1] + wait_time[i - 1];
    }
    return 0;
}

/*
Essa função calcula o tempo de retorno (turnaround time) para cada processo e o armazena no array tat[i]. 
O tempo de retorno é a soma do tempo de execução e do tempo de espera do processo.
*/
int turnaroundtime(int proc[], int n, int burst_time[], int wait_time[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = burst_time[i] + wait_time[i];
    }
    return 0;
}

/*
A função abaixo é responsável por implementar o escalonador Round Robin.
*/
int rr_sched(int proc[], int n, int burst_time[]) {
    int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
    int remaining_time[n];
    int i, t = 0, completed = 0;

    for (i = 0; i < n; i++) {
        remaining_time[i] = burst_time[i];
        wait_time[i] = 0;
    }

    printf("PID\t  Temp_Execução\t    Temp_Espera\t    Temp_Retorno\n");

    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                if (remaining_time[i] > TIME_SLICE) {
                    t += TIME_SLICE;
                    remaining_time[i] -= TIME_SLICE;
                } else {
                    t += remaining_time[i];
                    wait_time[i] = t - burst_time[i];
                    remaining_time[i] = 0;
                    completed++;                  
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        tat[i] = burst_time[i] + wait_time[i];
        total_wt += wait_time[i];
        total_tat += tat[i];
        printf("%d\t \t%d\t \t%d\t \t%d\n", i + 1, burst_time[i], wait_time[i], tat[i]);
    }

    printf("\n\x1b[33mTempo Médio de Espera: %.2f \n\x1b[32mTempo médio de Retorno: %.2f\x1b[0m\n", 
    total_wt/(float)n, total_tat/(float)n);
    return 0;
}

int main() {
    int n = 30;
    int proc[n];
    int burst_time[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        proc[i] = i + 1;
        int random_time = rand() % 3;
        if (random_time == 0) {
            burst_time[i] = 5;
        } else if (random_time == 1) {
            burst_time[i] = 8;
        } else {
            burst_time[i] = 12;
        }
    }

    rr_sched(proc, n, burst_time);
    return 0;
}