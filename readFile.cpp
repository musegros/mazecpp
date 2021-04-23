#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "include/path.h"

using namespace std;

#define PRINT(STR, VAR) \
	cout << STR " = " << VAR << endl

typedef struct Branch {
	Branch* prevBranch;
	string movesMade;
	char firstMove;
	int row;
	int col;
} Branch;

string printSolution(Branch* branch, string solution) {
	string branchMoves = branch->movesMade;
	solution = branchMoves + solution;
	if (branch->prevBranch == NULL) {
		PRINT("solution", solution);
		return solution;
	}
	else return printSolution (branch->prevBranch, solution);
}

string findMoves (vector<string> maze, int row, int col) {
	string moves;
	if (maze[row+1][col] == ' ') {
		moves.append("D");
	}
	if (maze[row-1][col] == ' ') {
		moves.append("U");
	}
	if (maze[row][col+1] == ' ') {
		moves.append("R");
	}
	if (maze[row][col-1] == ' ') {
		moves.append("L");
	}
	return moves;
}

void updatePosition(Branch* branch) {
	char lastMove = branch->movesMade[branch->movesMade.size()-1];
	if (lastMove == 'D') {
		branch->row++;
	}
	if (lastMove == 'U') {
		branch->row--;
	}
	if (lastMove == 'R') {
		branch->col++;
	}
	if (lastMove == 'L') {
		branch->col--;
	}

	return;
}

int main() {
	ifstream in ("mazes/mazeSmall.txt");
	vector<Branch*> queue;
	vector<string> maze;
	string nextMoves = "";
	string line;
	Branch startBranch;
	Branch* currentBranch;
	
	while (getline(in, line)) {
		maze.push_back(line);
	}

	//assumes square maze
	int mazeSize = maze[0].size();

	//With start always at the top, first move into maze will always be down
	startBranch.firstMove = 'D';
	startBranch.movesMade = "";
	startBranch.prevBranch = NULL;
	startBranch.row = 0;

	//find index of start location. only checks top of maze
	for (int i = 0; i < mazeSize; i++) {
		if (maze[0][i] == ' ') {
			startBranch.col = i;
		}
	}
	queue.push_back(&startBranch);

	while (queue.size() != 0) {
		currentBranch = queue[0];
		queue.erase(queue.begin());
		nextMoves = currentBranch->firstMove;

		while (nextMoves.length() == 1) {
			currentBranch->movesMade.append(nextMoves);
			//sealing off last position so findMoves() doesn't count it as a possible move
			maze[currentBranch->row][currentBranch->col] = '#';
			updatePosition(currentBranch);
			if (currentBranch->row == mazeSize-1 || currentBranch->col == mazeSize-1) {
				printSolution(currentBranch, "");
				break;
			} 
			nextMoves = findMoves(maze, currentBranch->row, currentBranch->col);
		}

		for (int i = 0; i < nextMoves.size(); i++) {
			Branch* newBranch = new Branch;
			newBranch->prevBranch = currentBranch;
			newBranch->row = currentBranch->row;
			newBranch->col = currentBranch->col;
			newBranch->firstMove = nextMoves[i];
			newBranch->movesMade = "";
			queue.push_back(newBranch);
		}
	}
}
