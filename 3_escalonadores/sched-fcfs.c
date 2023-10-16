#include <stdio.h>
/*
Esta função abaixo calcula o tempo de espera para cada processo e o armazena no array wait_time. 
Ela utiliza a fórmula para calcular o tempo de espera do processo atual (i) que é igual ao tempo 
de execução do processo anterior (i-1) mais o tempo de espera do processo anterior.
*/ 
int waitingtime(int proc[], int n, int burst_time[], int wait_time[]) {
   wait_time[0] = 0;                        // waiting time for first process is 0
   for (int i = 1; i < n ; i++ )            // calculating waiting time
   wait_time[i] = burst_time[i-1] + wait_time[i-1] ;
   return 0;
}

/*
A função a seguir calcula o tempo de retorno (turnaround time) para cada processo e o armazena no array tat. 
O tempo de retorno é a soma do tempo de execução (burst time) e do tempo de espera (waiting time) do processo.
*/
int turnaroundtime(int proc[], int n, int burst_time[], int wait_time[], int tat[]){
   int i;                                   // calculating turnaround time by adding
   for ( i = 0; i < n ; i++)                // burst_time[i] + wait_time[i]
   tat[i] = burst_time[i] + wait_time[i];
   return 0;
}

/*
Calcula a média do tempo de espera e do tempo de retorno para todos os processos. Ela chama as funções waitingtime e 
turnaroundtime para calcular os tempos de espera e retorno para cada processo e, em seguida, exibe esses tempos na 
saída padrão.
*/
int avgtime( int proc[], int n, int burst_time[]) {
   int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
   int i; 
   waitingtime(proc, n, burst_time, wait_time);             //Function to find waiting time of all processes
   turnaroundtime(proc, n, burst_time, wait_time, tat);     //Display processes along with all details
   printf("Processes  Burst   Waiting Turn around \n");     // Calculate total waiting time and total turn
   for ( i=0; i<n; i++) {                                   // Calculate total waiting time and total turn
      total_wt = total_wt + wait_time[i];                   // around time
      total_tat = total_tat + tat[i];
      printf(" %d\t  %d\t\t %d \t%d\n", i+1, burst_time[i], wait_time[i], tat[i]);
   }
   printf("Average waiting time = %f\n", (float)total_wt / (float)n);
   printf("Average turn around time = %f\n", (float)total_tat / (float)n);
   return 0;
}

/*
No main da função, você define os IDs dos processos e seus tempos de execução e, em seguida, chama a função 
avgtime para calcular e imprimir os tempos de espera, os tempos de retorno e as médias.
*/
int main() {
   int proc[] = {1, 2, 3};    //process id's
   int n = sizeof proc / sizeof proc[0];
   int burst_time[] = {5, 8, 12};    //Burst time of all processes
   avgtime(proc, n, burst_time);
   return 0;
}
