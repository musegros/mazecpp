#ifndef PATH_H
#define PATH_H
#include <string>
#include <vector>

class Path {
	std::vector<char> moves;
	Path* prevPath;
	bool firstPath;
	
public:
	void addMove(char move);
	std::string printPath();
	Path();
};
#endif
