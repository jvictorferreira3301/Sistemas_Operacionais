# Variáveis
CC = gcc
CFLAGS = -Wall
SRC = sched-fcfs.c sched-prioridades.c sched-rr.c sched-sjf.c sched-srtf.c 
TARGETS = $(patsubst %.c,%,$(SRC))

# Regras
all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)

.PHONY: all clean

