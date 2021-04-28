#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../include/Branch.h"
#include "../include/Maze.h"

using namespace std;

#define PRINT(STR, VAR) \
	cout << STR " = " << VAR << endl

int main(int argc, char *argv[]) {
	Maze maze(argv[1]);
	vector<Branch*> queue;
	string nextMoves = "";
	Branch* startBranch;
	
	if (argc != 2) {
		cout << "Program needs one argument, and that argument must be a file." << endl;
		return 0;
	}

	//find index of start location. only checks top of maze
	for (int i = 1; i < maze.getWidth()-1; i++) {
		if (maze.getChar(0, i) == ' ') {
			startBranch = new Branch(0, i);
		}
		else if (maze.getChar(i, 0) == ' ') {
			startBranch = new Branch(i, 0);
		}
	}
	queue.push_back(startBranch);

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
			maze.setChar(*row,*col);
			currentBranch->updatePosition();
			currentBranch->getPos(pos);
			if (*row == maze.getHeight()-1 || *col == maze.getWidth()-1) {
				string solution = currentBranch->printSolution();
				cout << solution << endl;;
				return 0;
			} 
			nextMoves = maze.findMoves(*row, *col);
		}

		for (int i = 0; i < nextMoves.size(); i++) {
			Branch* newBranch = new Branch(currentBranch, nextMoves[i]);
			queue.push_back(newBranch);
		}
	}
}
