#ifndef BRANCH_H
#define BRANCH_H
class Branch {
public:
	Branch(Branch*, char);
	Branch(int, int);

	char getFirstMove();
	char getDirection();
	void setDirection(char);
	void getPos(int*);
	void printBranch();
	void addMove(std::string);
	std::string printSolution(std::string = "");
	void updatePosition();

private:
	Branch* prevBranch;
	std::string movesMade;
	char firstMove;
	char direction;
	int row;
	int col;
};
#endif
