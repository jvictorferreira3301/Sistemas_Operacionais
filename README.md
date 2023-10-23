## Sistemas Operacionais

Repositório feito para as atividades de Sistemas Operacionais, disciplina ministrada no terceiro semestre na Faculdade de Computação e Telecomunicações da Universidade Federal do Pará.


### 🚀 Etapas de desenvolvimento

Ao longo da disciplina foram propostas as seguintes tarefas:

- [x] Tarefa 1 - Escolher algum problema e implementar em C e Assembly
utilizando chamadas de sistemas.
- [x] Tarefa 2 - implementação de concorrência e
sincronismo através da criação de processos via comando
fork e com o uso de threads.	
- [x] Tarefa 3 - Baixar o código sched-fcfs.c e implementar os seguintes
escalonadores:
• SJF
• SRTF
• Prioridades(fixa)
• Round Robin (dar o time-slice como entrada)
- [x] Tarefa 4 - Problemas Clássicos

### 🧰 Instruções para compilação 
Para automatizar a compilação implementamos o makefile neste repositório. 
Abaixo é descrito os comandos do makefile e o que eles fazem quando executados em cada subdiretório. 
Certifique-se de ter o makefile, o GCC e o texlive-full instalados em seu computador.
#### make 
```sh
  make 
  ```
* Na pasta **1_syscall**: compila o "soma_subtracao.c", para compilar "soma_subtracao.s", use:
  ```sh
  gcc -o subtracao_soma_s soma_subtracao.s 
  ```
* Na pasta **2_threads**: compila os códigos em C.
* Na past **3_escalonadores**: compila os códigos em C.
* Na pasta **relatorios**: compila todos os relatórios em LaTeX.  

#### make clean 
```sh
  make clean
  ```  
* Na pasta **1_syscall**: remove o executável.
* Na pasta **2_threads**: remove os executáveis.
* Na pasta **3_escalonadores**: remove os executáveis.
* Na pasta **relatorios**: remove todos os outputs LaTeX.
  
  


## Integrantes

- [João Victor Santos Brito Ferreira](https://github.com/jvictorferreira3301) 
- [Kauan Miranda Tavares](https://github.com/kkauanjjk)
- [Marco Antonio do Espirito Santo Maues Junior](https://github.com/Mauesjr)
- [Joel Tavares Miranda](https://github.com/JoeMiran)
- [David Pinheiro de Sousa](https://github.com/prodigyq)





 
