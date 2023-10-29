SUBDIRS = 1_syscall 2_thread 3_escalonadores 4_problemas_classicos relatorios

all: compile_all

.PHONY: all

compile_all:
	@for dir in $(SUBDIRS); do \
		echo "Compilando em $$dir..."; \
		$(MAKE) -C $$dir || true; \
	done

.PHONY: compile_all

clean: clean_all

.PHONY: clean

clean_all:
	@for dir in $(SUBDIRS); do \
		echo "Limpando em $$dir..."; \
		$(MAKE) -C $$dir clean || true; \
	done

.PHONY: clean_all

# Regras para compilar diretórios específicos
$(SUBDIRS):
	@echo "Compilando em $@..."
	$(MAKE) -C $@

.PHONY: $(SUBDIRS)

