#include <iostream>
#include <string>
#include "../include/Branch.h"

Branch::Branch(Branch* branch) {
	row = branch->row;
	col = branch->col;
	prevBranch = branch;
	movesMade = "";
}

Branch::Branch(char initChar) {
	firstMove = initChar;
	movesMade = "";
	prevBranch = NULL;
}

void Branch::printBranch() {
	std::cout << "position " << row << ", " << col << ". ";
	std::cout << "prevBranch " << prevBranch << std::endl;
	std::cout << "current address " << this << std::endl;
}

std::string Branch::printSolution(std::string solution) {
	solution = movesMade + solution;
	if (prevBranch == NULL) {
		return solution;
	}
	else return prevBranch->printSolution(solution);
}

void Branch::updatePosition() {
	char lastMove = movesMade.back();
	if (lastMove == 'D') {
		row++;
	}
	if (lastMove == 'U') {
		row--;
	}
	if (lastMove == 'R') {
		col++;
	}
	if (lastMove == 'L') {
		col--;
	}
	return;
}
