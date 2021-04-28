#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../include/Maze.h"

Maze::Maze(std::string fileName) {
		mazeFile = fileName;
		std::ifstream in (mazeFile);
		std::string line;

		while (getline(in, line)) {
			mazeVector.push_back(line);
		}
		height = mazeVector.size();
		width = mazeVector[0].size();
};

void Maze::printMaze() {
	for (int i = 0; i < height; i++) {
		std::cout << mazeVector[i] << std::endl;
	}
}

void Maze::setChar(int row, int col) {
	mazeVector[row][col] = '*';
}

char Maze::getChar(int row, int col) {
	return mazeVector[row][col];
}

int Maze::getHeight() {
	return height;
}

int Maze::getWidth() {
	return width;
}

std::string Maze::findMoves (int row, int col) {
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
