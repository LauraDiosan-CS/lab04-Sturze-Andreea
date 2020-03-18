#pragma once
#include "Project.h"
#include <vector>

using namespace std;

class Repository {
private:
	vector<Project> elem;
public:
	Repository();
	void addElem(Project);
	void delElem(Project);
	void updateElem(Project, const char*, int, int);
	bool findElem(Project);
	Project getItemFromPos(int);
	vector<Project> getAll();
	int dim();
	~Repository();
};