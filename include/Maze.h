#ifndef MAZE_H
#define MAZE_H

class Maze {
	std::string mazeFile;
	std::vector<std::string> mazeVector;
	int height;
	int width;

public:
	Maze(std::string);
	void printMaze();
	void setChar(int, int);
	char getChar(int, int);

	int getHeight();
	int getWidth();

	std::string findMoves(int, int);

};
#endif
