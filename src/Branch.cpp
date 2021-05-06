#include <iostream>
#include <string>
#include "../include/Branch.h"

Branch::Branch(Branch* branch, char initMove) {
	row = branch->row;
	col = branch->col;
	prevBranch = branch;
	movesMade = "";
	firstMove = initMove;
	movesMade =  branch->movesMade;
}

Branch::Branch(int initRow, int initCol) {
	row = initRow;
	col = initCol;
	if (col == 0) {
		firstMove = 'R';
	}
	if (row == 0) {
		firstMove = 'D';
	}
	movesMade = "";
	prevBranch = NULL;
}

char Branch::getFirstMove() {
	return firstMove;
}

void Branch::getPos(int* posArray) {
	posArray[0] = row;
	posArray[1] = col;
}

void Branch::addMove(std::string moveToAdd) {
	movesMade.append(moveToAdd);
}

void Branch::printBranch() {
	std::cout << "position " << row << ", " << col << ". ";
	std::cout << "prevBranch " << prevBranch << std::endl;
	std::cout << "current address " << this << std::endl;
}

std::string Branch::printSolution(std::string solution) {
	return movesMade;
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
