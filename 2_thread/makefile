# Variáveis
CC = gcc
CFLAGS = -Wall
SRC = 2-1_processo_avo_pai_filho.c 2-2_processo_pai_2filho.c 2-3_parricidio.c 2-4_threadABC.c	2-5_VariavelVisivel.c	2-6_Vetor100.c	2-8_benchmark.c
TARGETS = $(patsubst %.c,%,$(SRC))

# Regras
all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)

.PHONY: all clean

