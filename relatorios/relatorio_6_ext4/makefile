# Makefile no subdiretório "repo1" para compilar SO3.tex

LATEX = pdflatex
BIBTEX = bibtex
CLEAN = rm -f

all: SO3.pdf

SO3.pdf: SO3.tex
	$(LATEX) SO3.tex
	$(BIBTEX) SO3
	$(LATEX) SO3.tex
	$(LATEX) SO3.tex

clean:
	$(CLEAN) SO3.aux
	$(CLEAN) SO3.log
	$(CLEAN) SO3.bbl
	$(CLEAN) SO3.blg
	$(CLEAN) SO3.out
	$(CLEAN) SO3.pdf
	$(CLEAN) SO3.fdb_latexmk
	$(CLEAN) SO3.fls
	$(CLEAN) SO3.idx
	$(CLEAN) SO3.ilg
	$(CLEAN) SO3.ind
	$(CLEAN) SO3.toc
	
	
	
	
	
	
	

