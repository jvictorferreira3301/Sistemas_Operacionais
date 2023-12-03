SUBDIRS = relatorio_1 relatorio_2 relatorio_3 relatorio_4 relatorio_5_swap relatorio_6_ext4

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

