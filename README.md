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
- [x] Tarefa 4 - Problemas Clássicos (Produtor x Consumidor, Leitor x Escritor, O jantar dos filósofos, O Problema do Barbeiro Dorminhoco).
- [x] Tarefa 5 - Desenvolver uma apliação que necessite de muita RAM, a executar com e sem serviços de SWAP. Utilizar, ao menos, duas capacidades de SWAP para comparar
- [x] Tarefa 6 - Escolher um Sistema de Arquivos, apresentar e realizar benchmarks (Teste de leitura sequencial e escrita sequencial e teste de leitura aleatória e escrita aleatória, com cargas 12 arquivos de  arquivo 1GB cada)  

### 🧰 Instruções para compilação 
Para automatizar a compilação implementamos o makefile neste repositório. 
Abaixo é descrito os comandos do makefile e os targets para compilar tudo ou subdiretórios específicos. 

Certifique-se de ter o makefile, o GCC e o texlive-full instalados em seu computador.
#### 1. make 
Para compilar tudo.
```sh
  make 
  ```
#### 2. make [nome do subdir]
Para compilar um subdiretório específico.
```sh
  make 1_syscall
  ```
```sh
  make 2_threads
  ```
```sh
  make 3_escalonadores
  ```
```sh
  make relatorios
  ```
* Na pasta **1_syscall**: compila somente o "soma_subtracao.c", para compilar "soma_subtracao.s", use:
  ```sh
  gcc -o subtracao_soma_s soma_subtracao.s 
  ```
* Na pasta **2_threads**: compila os códigos em C.
* Na pasta **3_escalonadores**: compila os códigos em C.
* Na pasta **relatorios**: compila todos os relatórios em LaTeX.  

#### 3. make clean 
Para limpar tudo.

```sh
  make clean
  ```
#### 4. make clean [nome do subdir]
Para limpar um subdiretório específico.

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





 
