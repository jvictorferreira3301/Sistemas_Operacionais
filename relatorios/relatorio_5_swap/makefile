LATEX = pdflatex
BIBTEX = bibtex
CLEAN = rm -f

all: SO5.pdf

SO5.pdf: SO5.tex
	$(LATEX) SO5.tex
	$(BIBTEX) SO5
	$(LATEX) SO5.tex
	$(LATEX) SO5.tex

clean:
	$(CLEAN) SO5.aux
	$(CLEAN) SO5.log
	$(CLEAN) SO5.bbl
	$(CLEAN) SO5.blg
	$(CLEAN) SO5.out
	$(CLEAN) SO5.pdf
	$(CLEAN) SO5.fdb_latexmk
	$(CLEAN) SO5.fls
	$(CLEAN) SO5.idx
	$(CLEAN) SO5.ilg
	$(CLEAN) SO5.ind
	$(CLEAN) SO5.toc
	
	
	
	
	
	
	
