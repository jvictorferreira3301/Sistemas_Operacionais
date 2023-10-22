# Makefile no subdiretório "repo1" para compilar SO2.tex

LATEX = pdflatex
BIBTEX = bibtex
CLEAN = rm -f

all: SO2.pdf

SO2.pdf: SO2.tex
	$(LATEX) SO2.tex
	$(BIBTEX) SO2
	$(LATEX) SO2.tex
	$(LATEX) SO2.tex

clean:
	$(CLEAN) SO2.aux
	$(CLEAN) SO2.log
	$(CLEAN) SO2.bbl
	$(CLEAN) SO2.blg
	$(CLEAN) SO2.out
	$(CLEAN) SO2.pdf
	$(CLEAN) SO2.fdb_latexmk
	$(CLEAN) SO2.fls
	$(CLEAN) SO2.idx
	$(CLEAN) SO2.ilg
	$(CLEAN) SO2.ind
	$(CLEAN) SO2.toc
	
	
	
	
	
	
	

