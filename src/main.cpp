#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../include/Branch.h"

using namespace std;

#define PRINT(STR, VAR) \
	cout << STR " = " << VAR << endl

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

int main() {
	ifstream in ("../mazes/mazeSmall.txt");
	vector<Branch*> queue;
	vector<string> maze;
	string line;
	string nextMoves = "";
	
	while (getline(in, line)) {
		maze.push_back(line);
	}

	//assumes square maze
	int mazeSize = maze[0].size();

	//With start always at the top, first move into maze will always be down
	Branch* startBranch = new Branch('D');
	startBranch->row = 0;

	//find index of start location. only checks top of maze
	for (int i = 0; i < mazeSize; i++) {
		if (maze[0][i] == ' ') {
			startBranch->col = i;
		}
	}
	queue.push_back(startBranch);

	for (int i = 0; i < mazeSize; i++) {
		cout << maze[i] << endl;
	}

	while (queue.size() != 0) {
		Branch* currentBranch = queue[0];
		queue.erase(queue.begin());
		nextMoves = currentBranch->firstMove;

		while (nextMoves.length() == 1) {

			currentBranch->movesMade.append(nextMoves);
			//sealing off last position so findMoves() doesn't count it as a possible move
			maze[currentBranch->row][currentBranch->col] = '*';
			currentBranch->updatePosition();
			if (currentBranch->row == mazeSize-1 || currentBranch->col == mazeSize-1) {
				string solution = currentBranch->printSolution();
				cout << solution << endl;;
				return 0;
			} 
			nextMoves = findMoves(maze, currentBranch->row, currentBranch->col);
		}

		for (int i = 0; i < nextMoves.size(); i++) {
			Branch* newBranch = new Branch(currentBranch);
			newBranch->firstMove = nextMoves[i];
			queue.push_back(newBranch);
		}
	}
}
