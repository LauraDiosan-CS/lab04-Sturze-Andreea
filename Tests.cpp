#include "stdafx.h"
#include "Tests.h"
#include <assert.h>
#include "Project.h"
#include "Repository.h"
#include "Service.h"
#include <iostream>
using namespace std;


void testProject() {
	Project p("a/b/c", 3, 4);
	assert(strcmp(p.getGitPath(), "a/b/c") == 0);
	assert(p.getNoOfBranches() == 3);
	assert(p.getTotalNoOfCommits() == 4);
	Project p1;
	assert(p1.getGitPath() == NULL and p1.getNoOfBranches() == 0 and p1.getTotalNoOfCommits() == 0);
	Project p2(p);
	assert(strcmp(p2.getGitPath(), "a/b/c") == 0 and p2.getNoOfBranches() == 3 and p2.getTotalNoOfCommits() == 4);
	p.setGitPath("a");
	assert(strcmp(p.getGitPath(), "a") == 0);
	p.setNoOfBranches(2);
	assert(p.getNoOfBranches() == 2);
	p.setTotalNoOfCommits(6);
	assert(p.getTotalNoOfCommits() == 6);
}

void testRepo() {
	Project p("a/b/c", 3, 4);
	Repository repo;
	repo.addElem(p);
	Project* v = repo.getAll();
	assert(repo.findElem(p) == 0);
	assert(v[0] == p and repo.getSize() == 1);
	Project p1("a/b", 2, 3);
	repo.updateElem(p, "a/b", 2, 3);
	assert(repo.getItemFromPos(0) == p1);
	repo.delElem(p1);
	assert(repo.getSize() == 0);
}

void testServiceCRUD() {
	Project p("h1/path", 2, 4);
	Project p2("h2/path", 3, 5);
	Repository repo;
	Service serv(repo);
	serv.addToRepo("h1/path", 2, 4);
	assert(serv.getFromRepo()[0] == p);
	serv.updateInRepo("h1/path", 2, 4, "h2/path", 3, 5);
	assert(serv.getFromRepo()[0] == p2);
	serv.addToRepo("h1/path", 2, 4);
	assert(serv.getFromRepo()[1] == p and serv.getRepoSize()==2);
	serv.delFromRepo("h2/path", 3, 5);
	assert(serv.getFromRepo()[0] == p);
	assert(serv.findElemInRepo(p) == 0);
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
	Service serv(repo);
	Project results[100];
	int m = 0;
	serv.filterProjects(2, 4, m ,results);
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
	Service serv(repo);
	serv.delProjectsWithCondition();
	assert(serv.getRepoSize() == 2 and serv.findElemInRepo(p1) == 0 and serv.findElemInRepo(p3) == 1);
}