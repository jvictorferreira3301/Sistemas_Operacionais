#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
A função a seguir tem a finalidade de calcular o tempo de espera para cada processo em 
uma lista de processos. O tempo de espera é calculado somando-se o tempo de execução do
processo anterior com o tempo de espera do processo anterior.
*/
int waitingtime(int proc[], int n, int burst_time[], int wait_time[]) {
    wait_time[0] = 0;                        // Tempo de espera para o primeiro processo é 0
    for (int i = 1; i < n ; i++ )            
    wait_time[i] = burst_time[i-1] + wait_time[i-1] ; //Calculo do tempo de espera
    return 0;
}


/*
Essa função calcula o tempo de retorno (turnaround time) para cada processo e o armazena no array tat[i]. 
O tempo de retorno é a soma do tempo de execução e do tempo de espera do processo.
*/
int turnaroundtime(int proc[], int n, int burst_time[], int wait_time[], int tat[]){
    int i;     // Tempo de retorno para o primeiro processo é o tempo de execução                              
    for ( i = 0; i < n ; i++)               
    tat[i] = burst_time[i] + wait_time[i]; //Calculo do tempo de retorno
    return 0;
}

/*
A função abaixo é responsável por implementar o escalonador SRT (Shortest Remaining Time).
Ela recebe os mesmos parâmetros que a função avgtime e ordena os processos de acordo com o tempo restante de execução.
Em seguida, executa o processo com o menor tempo restante primeiro.
*/
int srt(int proc[], int n, int burst_time[]) {

    int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
    int remaining_time[n];                //Tempo de execução restante de cada processo
    int smallest, time = 0, finish_time; //smallest é o processo com o menor tempo restante de execução
    int count = 0;                      //Contador de processos executados

    /*
    Inicializando o tempo de execucao restante com o tempo inicial de cada processo
    */
    for (int i = 0; i < n; i++) {
        remaining_time[i] = burst_time[i]; 
    }

    while (count != n) {
        
        //Inicializando o menor tempo restante com um valor maior que o tempo de execução de qualquer processo
        smallest = n + 1; 
        
        for (int i = 0; i < n; i++) {
            //Aqui eu verifico se o tempo de execução restante é menor que o menor tempo restante do processo atual
            if (remaining_time[i] > 0 && remaining_time[i] < remaining_time[smallest]) {
                smallest = i; //Índice do processo com o menor tempo restante de execução
            }
        }

        //Pra simular a execução do processo, eu decremento o tempo de execução restante em 1
        remaining_time[smallest]--;


        if (remaining_time[smallest] == 0) { //Se o menor processo foi totalmente executado
            
            count++;
            finish_time = time + 1;

            //Calculando o tempo de espera de cada processo
            wait_time[smallest] = finish_time - burst_time[smallest];

            //Evitando valores negativos para o tempo de espera
            if (wait_time[smallest] < 0) {
                wait_time[smallest] = 0;
            }

            //Calculando o tempo de retorno de cada processo
            tat[smallest] = burst_time[smallest] + wait_time[smallest];

            //Calculando o tempo médio de espera e o tempo médio de retorno
            total_wt += wait_time[smallest];
            total_tat += tat[smallest];
        }
        
        time++;
    }


    printf("======================== SRTF ==========================\n");
    printf("PID\t  Temp_Execução\t    Temp_Espera\t    Temp_Retorno\n"); 

    for ( int i = 0; i < n; i++) {                                   
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
    }

    srt(proc, n, burst_time); //Chamada da função que implementa o escalonador SRT e calcula o tempo medio de retorno
    return 0;
}
