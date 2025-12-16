IDIR=../include
CC=gcc
CFLAGS=-I$(IDIR) -std=c99 -Wall -lm
ODIR=obj
EXE=bin

_DEPS=defines.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o cpuInst.o system.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(EXE):
	mkdir -p $@

$(ODIR):
	mkdir -p $@

$(ODIR)/%.o: %.c $(DEPS) | $(EXE) $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ) | $(EXE) $(ODIR)
	$(CC) -o $(EXE)/cpu $^ $(CFLAGS)

.PHONY: clean all

clean: 
	rm -f $(ODIR)/*.o *~ core $(INCDIR) /*~
	rm -f $(EXE)/*

