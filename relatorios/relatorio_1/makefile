# Makefile no subdiretório "repo1" para compilar SO1.tex

LATEX = pdflatex
BIBTEX = bibtex
CLEAN = rm -f

all: SO1.pdf

SO1.pdf: SO1.tex
	$(LATEX) SO1.tex
	$(BIBTEX) SO1
	$(LATEX) SO1.tex
	$(LATEX) SO1.tex

clean:
	$(CLEAN) SO1.aux
	$(CLEAN) SO1.log
	$(CLEAN) SO1.bbl
	$(CLEAN) SO1.blg
	$(CLEAN) SO1.out
	$(CLEAN) SO1.pdf
	$(CLEAN) SO1.fdb_latexmk
	$(CLEAN) SO1.fls
	$(CLEAN) SO1.idx
	$(CLEAN) SO1.ilg
	$(CLEAN) SO1.ind
	$(CLEAN) SO1.toc
	
	
	
	
	
	
	

