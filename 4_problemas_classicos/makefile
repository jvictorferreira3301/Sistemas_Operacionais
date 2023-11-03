# Variáveis
CC = gcc
CFLAGS = -Wall
SRC = barbeiro.c jantar_filosofos.c leitor_escritor.c prod_cons.c
TARGETS = $(patsubst %.c,%,$(SRC))

# Regras
all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)

.PHONY: all clean

