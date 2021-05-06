#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <stack>
#include "../include/Branch.h"
#include "../include/MazeTextFile.h"

using namespace std;

#define PRINT(STR, VAR) \
	cout << STR " = " << VAR << endl
struct CompareHeuristic {
	bool operator()(Branch* b1, Branch* b2) {
		return b1->getHeuristic() > b2->getHeuristic();
	}
};

int main(int argc, char *argv[]) {
	string nextMoves = "";
	Branch* startBranch;

	if (argc != 3) {
		cout << "Program expects a maze file and either a 'b' or a 'd'" << endl;
		return 0;
	}

	MazeTextFile maze(argv[1]);
	char searchFlag = argv[2][0];

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
		Branch* currentBranch;
		if (searchFlag == 'b') {
			currentBranch = queue[0];
			queue.erase(queue.begin());
		} else {
			currentBranch = queue.back();
			queue.pop_back();
		}

		nextMoves = currentBranch->getFirstMove();
		int pos[2];
		currentBranch->getPos(pos);
		int* row = &pos[0];
		int* col = &pos[1];

		while (nextMoves.length() == 1) {

			currentBranch->addMove(nextMoves);
			//sealing off last position so findMoves() doesn't count it as a possible move
			//maze.setChar(*row,*col,'*');
			currentBranch->updatePosition();
			currentBranch->getPos(pos);
			if (maze.isFinished(pos)) {
				string solution = currentBranch->printSolution();
				cout << solution << endl;
				return 0;
			} 
			nextMoves = maze.findMoves(*row, *col);
			nextMoves =  
		}

		for (int i = 0; i < nextMoves.size(); i++) {
			Branch* newBranch = new Branch(currentBranch, nextMoves[i]);
			queue.push_back(newBranch);
		}
	}
}
