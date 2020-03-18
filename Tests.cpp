#include "stdafx.h"
#include "Tests.h"
#include <assert.h>
#include "Project.h"
#include "Repository.h"
#include "Operations.h"
#include <iostream>
using namespace std;


void testProject() {
	Project p("a/b/c", 3, 4);
	assert(p.getNoOfBranches() == 3);
	assert(p.getTotalNoOfCommits() == 4);
	Project p1;
	assert(p1.getGitPath() == NULL and p1.getNoOfBranches() == 0 and p1.getTotalNoOfCommits() == 0);
	Project p2(p);
	assert(p2.getNoOfBranches() == 3 and p2.getTotalNoOfCommits() == 4);
}

void testRepo() {
	Project p("a/b/c", 3, 4);
	Repository repo;
	repo.addElem(p);
	Project* v = repo.getAll();
	assert(repo.findElem(p) == 0);
	assert(v[0] == p and repo.getSize() == 1);
	repo.delElem(p);
	assert(repo.getSize() == 0);
}

void testFilterProjects() {
	Project p1("h1/path", 2, 4);
	Project p2("h2/path", 2, 3);
	Project p3("h3/path", 2, 4);
	Project p4("h4/path", 3, 0);
	Repository repo;
	repo.addElem(p1);
	repo.addElem(p2);
	repo.addElem(p3);
	repo.addElem(p4);
	Project results[100];
	int m = 0;
	filterProjects(repo, 2, 4, m ,results);
	assert(m == 2 and results[0] == p1 and results[1] == p3);
}

void testDelProjectsWithCondition() {
	Project p1("h1/path", 2, 4);
	Project p2("h2/path", 0, 3);
	Project p3("h3/path", 2, 4);
	Project p4("h4/path", 3, 0);
	Repository repo;
	repo.addElem(p1);
	repo.addElem(p2);
	repo.addElem(p3);
	repo.addElem(p4);
	vector<Project> results;
	delProjectsWithCondition(repo);
	assert(repo.getSize() == 2 and repo.findElem(p1)==0 and repo.findElem(p3)==1);
}