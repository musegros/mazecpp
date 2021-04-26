#ifndef BRANCH_H
#define BRANCH_H
class Branch {
public:
	Branch* prevBranch;
	std::string movesMade;
	char firstMove;
	int row;
	int col;
	Branch(Branch*);
	Branch(char);
	void printBranch();
	std::string printSolution(std::string = "");
	void updatePosition();
};
#endif
