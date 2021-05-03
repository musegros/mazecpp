#ifndef MAZE_H
#define MAZE_H
class Maze {
public:

	virtual bool isFinished(int*) = 0;

protected:
	int row;
	int col;

};
#endif
