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
A função abaixo é responsável por calcular o tempo médio de espera e o tempo médio de retorno para um conjunto de processos. 
Ela também imprime na saída padrão os tempos de espera e os tempos de retorno de cada processo. 
*/
int avgtime( int proc[], int n, int burst_time[]) {

   int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
   int i; 

   waitingtime(proc, n, burst_time, wait_time);             
   turnaroundtime(proc, n, burst_time, wait_time, tat);  
   printf("PID\t  Temp_Execução\t    Temp_Espera\t    Temp_Retorno\n");  

   for ( i=0; i<n; i++) {                                   
      total_wt = total_wt + wait_time[i];                   
      total_tat = total_tat + tat[i];
      printf(" %d\t  %d\t\t %d \t%d\n", i+1, burst_time[i], wait_time[i], tat[i]);
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

   avgtime(proc, n, burst_time); //Chamada da função que calcula o tempo médio de espera e o tempo médio de retorno
   return 0;
}
