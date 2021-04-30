CC = g++
IDIR = ../include
BDIR = ../build

_DEPS = Branch.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = main.o Branch.o
OBJ = $(patsubst %, $(BDIR)/%, $(_OBJ))

maze: $(OBJ)
	$(CC) -o $@ $^

$(OBJ): | $(BDIR)

$(BDIR):
	mkdir -p ../build

$(BDIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< 

.PHONY: clean

clean:
		rm -rf $(BDIR)/*.o
		rm maze
