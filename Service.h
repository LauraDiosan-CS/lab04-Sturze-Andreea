#pragma once
#include "Project.h"
#include "Repository.h"

class Service {
private:
	Repository repo;
public:
	Service();
	Service(const Repository&);
	~Service();
	void addToRepo(const char*, int, int);
	void delFromRepo(const char*, int, int);
	void updateInRepo(const char*, int, int, const char*, int, int);
	int findElemInRepo(const Project& p);
	Project* getFromRepo();
	int getRepoSize();
	void filterProjects(int branches, int commits, int &m, Project* projectFilter);
	void delProjectsWithCondition();
};
