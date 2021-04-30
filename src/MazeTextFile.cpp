#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../include/MazeTextFile.h"

MazeTextFile::MazeTextFile(std::string fileName) {
		mazeFile = fileName;
		std::ifstream in (mazeFile);
		std::string line;

		while (getline(in, line)) {
			mazeVector.push_back(line);
		}
		height = mazeVector.size();
		width = mazeVector[0].size();
};

void MazeTextFile::printMaze() {
	for (int i = 0; i < height; i++) {
		std::cout << mazeVector[i] << std::endl;
	}
}

void MazeTextFile::setChar(int row, int col, char inputChar) {
	mazeVector[row][col] = inputChar;
}

char MazeTextFile::getChar(int row, int col) {
	return mazeVector[row][col];
}

int MazeTextFile::getHeight() {
	return height;
}

int MazeTextFile::getWidth() {
	return width;
}

std::string MazeTextFile::findMoves (int row, int col) {
	//currently this function returns string of valid moves
	//but maybe it should only return chars of the maze and let
	//caller figure out what that means
	std::string moves;
	if (mazeVector[row+1][col] == ' ') {
		moves.append("D");
	}
	if (mazeVector[row-1][col] == ' ') {
		moves.append("U");
	}
	if (mazeVector[row][col+1] == ' ') {
		moves.append("R");
	}
	if (mazeVector[row][col-1] == ' ') {
		moves.append("L");
	}
	return moves;
}

bool MazeTextFile::isFinished(int* pos) {
	int row = pos[0];
	int col = pos[1];
	if (row == height-1 || col == width-1) {
		return true;
	} else {
		return false;
	}
}
