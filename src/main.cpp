#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../include/Branch.h"
#include "../include/MazeTextFile.h"

using namespace std;

#define PRINT(STR, VAR) \
	cout << STR " = " << VAR << endl

int main(int argc, char *argv[]) {
	vector<Branch*> queue;
	vector<string> maze;
	string line;
	string nextMoves = "";
	Branch* startBranch;
	
	while (getline(in, line)) {
		maze.push_back(line);
	}

	MazeTextFile maze(argv[1]);

	//find index of start location. only checks top of maze
	for (int i = 1; i < mazeSize-1; i++) {
		if (maze[0][i] == ' ') {
			startBranch = new Branch(0, i);
		}
		else if (maze[i][0] == ' ') {
			startBranch = new Branch(i, 0);
		}
	}
	queue.push_back(startBranch);

	for (int i = 0; i < mazeSize; i++) {
		cout << maze[i] << endl;
	}

	while (queue.size() != 0) {
		Branch* currentBranch = queue[0];
		queue.erase(queue.begin());
		nextMoves = currentBranch->getFirstMove();
		int pos[2];
		currentBranch->getPos(pos);
		int* row = &pos[0];
		int* col = &pos[1];

		while (nextMoves.length() == 1) {

			currentBranch->addMove(nextMoves);
			//sealing off last position so findMoves() doesn't count it as a possible move
			maze.setChar(*row,*col,'*');
			currentBranch->updatePosition();
			currentBranch->getPos(pos);
			if (maze.isFinished(pos)) {
				string solution = currentBranch->printSolution();
				cout << solution << endl;;
				return 0;
			} 
			nextMoves = findMoves(maze, *row, *col);
		}

		for (int i = 0; i < nextMoves.size(); i++) {
			Branch* newBranch = new Branch(currentBranch, nextMoves[i]);
			queue.push_back(newBranch);
		}
	}
}
