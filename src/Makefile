CC = g++
IDIR = ../include
BDIR = ../build

_DEPS = Branch.h Maze.h MazeTextFile.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = main.o Branch.o MazeTextFile.o
OBJ = $(patsubst %, $(BDIR)/%, $(_OBJ))

maze: $(OBJ)
	$(CC) -o $@ $^

$(OBJ): | $(BDIR)

$(BDIR):
	mkdir -p ../build

$(BDIR)/%.o: %.cpp $(DEPS)
	$(CC) -g -c -o $@ $< 

.PHONY: clean

clean:
		rm -rf $(BDIR)
		rm maze
