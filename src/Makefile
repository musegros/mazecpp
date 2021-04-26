CC = g++
IDIR = ../include
BDIR = ../build

_DEPS = Branch.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = main.o Branch.o
OBJ = $(patsubst %, $(BDIR)/%, $(_OBJ))

$(BDIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< 

maze: $(OBJ)
	$(CC) -o $@ $^

.PHONY: clean

clean:
		rm -f $(BDIR)/*.o
