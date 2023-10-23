# Variáveis
CC = gcc
CFLAGS = -Wall
SRC = 
TARGETS = $(patsubst %.c,%,$(SRC))

# Regras
all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)

.PHONY: all clean

