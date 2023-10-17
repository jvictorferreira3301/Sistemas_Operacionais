#include <stdio.h>
// Function to find the waiting time for all processes
int waitingtime(int proc[], int n, int burst_time[], int wait_time[]) {
   wait_time[0] = 0;                        // waiting time for first process is 0
   for (int i = 1; i < n ; i++ )            // calculating waiting time
   wait_time[i] = burst_time[i-1] + wait_time[i-1] ;
   return 0;
}
// Function to calculate turn around time
int turnaroundtime(int proc[], int n, int burst_time[], int wait_time[], int tat[]){
   int i;                                   // calculating turnaround time by adding
   for ( i = 0; i < n ; i++)                // burst_time[i] + wait_time[i]
   tat[i] = burst_time[i] + wait_time[i];
   return 0;
}
//Function to calculate average time
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
// main function
int main() {
   int proc[] = {1, 2, 3};    //process id's
   int n = sizeof proc / sizeof proc[0];
   int burst_time[] = {5, 8, 12};    //Burst time of all processes
   avgtime(proc, n, burst_time);
   return 0;
}
