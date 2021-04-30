#ifndef MAZETEXTFILE_H
#define MAZETEXTFILE_H
#include "Maze.h"

class MazeTextFile: public Maze {
public:
	MazeTextFile(std::string);
	void printMaze();
	void setChar(int, int, char);
	char getChar(int, int);
	int getHeight();
	int getWidth();
	std::string findMoves(int, int);
	bool isFinished(int*);

private:
	int height;
	int width;
	std::vector<std::string> mazeVector;
	
}
#endif
