# Configuração do compilador C
CC = gcc
CFLAGS = -Wall -O2

# Configuração do montador (obs: não funcionou pra assembly de jeito nenhum, foi mal prof diego vai ter que compilar na labuta mesmo, erramos fomos mlks)
#AS = as
#ASFLAGS = --64

# Nomes dos arquivos fonte
C_SOURCE = soma_subtracao.c
#AS_SOURCE = soma_subtracao.s

# Nome do executável final
EXECUTABLE = soma_subtracao

all: $(C_SOURCE) $(AS_SOURCE)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $^

clean:
	rm -f $(EXECUTABLE)

.PHONY: all clean

