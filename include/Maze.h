#ifndef MAZE_H
#define MAZE_H

class Maze {
public:

	virtual int* getPos() = 0;
	virtual bool isFinished() = 0;

	virtual std::string findMoves(int, int);
protected:
	int row;
	int col;


};
#endif
