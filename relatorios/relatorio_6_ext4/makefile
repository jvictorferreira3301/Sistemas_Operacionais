LATEX = pdflatex
BIBTEX = bibtex
CLEAN = rm -f

all: SO6.pdf

SO6.pdf: SO6.tex
	$(LATEX) SO6.tex
	$(BIBTEX) SO6
	$(LATEX) SO6.tex
	$(LATEX) SO6.tex

clean:
	$(CLEAN) SO6.aux
	$(CLEAN) SO6.log
	$(CLEAN) SO6.bbl
	$(CLEAN) SO6.blg
	$(CLEAN) SO6.out
	$(CLEAN) SO6.pdf
	$(CLEAN) SO6.fdb_latexmk
	$(CLEAN) SO6.fls
	$(CLEAN) SO6.idx
	$(CLEAN) SO6.ilg
	$(CLEAN) SO6.ind
	$(CLEAN) SO6.toc
	
	
	
	
	
	
	

