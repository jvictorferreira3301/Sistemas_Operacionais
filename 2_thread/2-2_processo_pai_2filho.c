#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
   int pid ;
   printf("\nBom dia, eu me apresento. Sou o processo %d.\n",getpid()) ;
   pid = fork();

    if (pid == 0) {
        printf("\tOi, eu sou %d, o filho de %d.\n",getpid(),getppid()) ;
      
    }
    else{
        wait(NULL);
        if(pid != 0){
            printf("\nAlo, eu sou o processo %d, o segundo filho de %d\n",getpid(),getppid());
        }
    
    }
   
   exit(0);
}