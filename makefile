SUBDIRS = 1_syscall 2_thread 3_escalonadores 4_problemas_classicos relatorios

all:
	@for dir in $(SUBDIRS); do \
		echo "Compilando em $$dir..."; \
		$(MAKE) -C $$dir || true; \
	done

.PHONY: all

clean:
	@for dir in $(SUBDIRS); do \
		echo "Limpando em $$dir..."; \
		$(MAKE) -C $$dir clean || true; \
	done

.PHONY: clean

