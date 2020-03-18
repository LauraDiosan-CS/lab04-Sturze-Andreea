#pragma once
#include "Project.h"
#include <vector>

using namespace std;

class Repository {
private:
	Project elem[100];
	int size;
public:
	Repository();
	void addElem(Project);
	void delElem(Project);
	void updateElem(Project, const char*, int, int);
	int findElem(Project);
	Project getItemFromPos(int);
	Project* getAll();
	int getSize();
	~Repository();
};