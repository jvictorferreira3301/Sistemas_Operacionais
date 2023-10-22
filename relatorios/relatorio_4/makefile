# Makefile no subdiretório "repo1" para compilar SO4.tex

LATEX = pdflatex
BIBTEX = bibtex
CLEAN = rm -f

all: SO4.pdf

SO4.pdf: SO4.tex
	$(LATEX) SO4.tex
	$(BIBTEX) SO4
	$(LATEX) SO4.tex
	$(LATEX) SO4.tex

clean:
	$(CLEAN) SO4.aux
	$(CLEAN) SO4.log
	$(CLEAN) SO4.bbl
	$(CLEAN) SO4.blg
	$(CLEAN) SO4.out
	$(CLEAN) SO4.pdf
	$(CLEAN) SO4.fdb_latexmk
	$(CLEAN) SO4.fls
	$(CLEAN) SO4.idx
	$(CLEAN) SO4.ilg
	$(CLEAN) SO4.ind
	$(CLEAN) SO4.toc
	
	
	
	
	
	
	

