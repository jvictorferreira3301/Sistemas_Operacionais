#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
A função a seguir tem a finalidade de calcular o tempo de espera para cada processo em 
uma lista de processos. O tempo de espera é calculado somando-se o tempo de execução do
processo anterior com o tempo de espera do processo anterior.
*/
int waitingtime(int proc[], int n, int burst_time[], int wait_time[], int priority[]) {
    wait_time[0] = 0;                        // Tempo de espera para o primeiro processo é 0
    for (int i = 1; i < n ; i++ )            
    wait_time[i] = burst_time[i-1] + wait_time[i-1] ; //Calculo do tempo de espera
    return 0;
}


/*
Essa função calcula o tempo de retorno (turnaround time) para cada processo e o armazena no array tat[i]. 
O tempo de retorno é a soma do tempo de execução e do tempo de espera do processo.
*/
int turnaroundtime(int proc[], int n, int burst_time[], int wait_time[], int tat[], int priority[]){
    int i;     // Tempo de retorno para o primeiro processo é o tempo de execução                              
    for ( i = 0; i < n ; i++)               
    tat[i] = burst_time[i] + wait_time[i]; //Calculo do tempo de retorno
    return 0;
}


/*
A função abaixo é responsável por calcular o tempo médio de espera e o tempo médio de retorno para um conjunto de processos. 
Ela também imprime na saída padrão os tempos de espera e os tempos de retorno de cada processo. 
*/
int sched_priory( int proc[], int n, int burst_time[], int priority[]) {

    int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
    int i, j, aux; 

    // Ordena os processos de acordo com suas prioridades
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {         
            /*
            Se a prioridade do processo i for maior que a prioridade do processo j,
            então o valor armazenado nas variáveis trocam de lugar.
            */
            if (priority[i] > priority[j]) {
                //Usando uma variável auxilixar para trocar os valores de prioridade, burst_time e proc
                aux = priority[i];
                priority[i] = priority[j];
                priority[j] = aux;

                aux = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = aux;

                aux = proc[i];
                proc[i] = proc[j];
                proc[j] = aux;
            }
        }
    }

    waitingtime(proc, n, burst_time, wait_time, priority);             
    turnaroundtime(proc, n, burst_time, wait_time, tat, priority);
    printf("=========================== Prioridade Fixa ============================\n");  
    printf("PID\t  Prioridade\t  Temp_Execução\t    Temp_Espera\t    Temp_Retorno\n");  

    for ( i=0; i<n; i++) {                                   
        total_wt = total_wt + wait_time[i];                   
        total_tat = total_tat + tat[i];
        printf("%d\t \t%d\t \t%d\t \t%d\t \t%d\n", proc[i], priority[i], burst_time[i], wait_time[i], tat[i]);
    }

    printf("\n\x1b[33mTempo Médio de Espera: %.2f \n\x1b[32mTempo médio de Retorno: %.2f\x1b[0m\n", 
    total_wt/(float)n, total_tat/(float)n);
    return 0;
}


int main() {

    int n = 30;
    int proc[n];
    int burst_time[n];
    int priority[n];

    srand(time(NULL)); //Gerador de números aleatórios

    for (int i = 0; i < n; i++) {
         proc[i] = i+1;
         int random_time = rand() % 3; // gera um número aleatório entre 0 e 2
         if (random_time == 0) {
              burst_time[i] = 5;
         } else if (random_time == 1) {
              burst_time[i] = 8;
         } else {
              burst_time[i] = 12;
         }
         priority[i] = rand() % 5; // gera um número aleatório entre 0 e 4 para a prioridade
    }

    sched_priory(proc, n, burst_time, priority); //Chamada da função que calcula o tempo médio de espera e o tempo médio de retorno
    return 0;
}
