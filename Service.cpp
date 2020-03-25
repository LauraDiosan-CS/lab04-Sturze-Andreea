#include "stdafx.h"
#include "Service.h"

Service::Service() {
}

Service::Service(const Repository& repository) {
	this->repo = repository;
}

Service::~Service() {

}

void Service::addToRepo(const char* path, int branches, int commits) {
	Project p(path, branches, commits);
	this->repo.addElem(p);
}

void Service::delFromRepo(const char* path, int branches, int commits) {
	Project p(path, branches, commits);
	this->repo.delElem(p);
}

void Service::updateInRepo(const char* path, int branches, int commits, const char* newPath, int newBranches, int newCommits) {
	Project p(path, branches, commits);
	this->repo.updateElem(p,newPath, newBranches,newCommits);
}

Project* Service::getFromRepo() {
	return this->repo.getAll();
}

int Service::getRepoSize() {
	return repo.getSize();
}

int Service::findElemInRepo(const Project& p) {
	return repo.findElem(p);
}

void Service::filterProjects( int branches, int commits,int &m, Project* projectFilter)
{
	m = 0;
	for (int i = 0; i < repo.getSize(); i++) {
		Project crtProject = repo.getItemFromPos(i);
		if (crtProject.getNoOfBranches() == branches and crtProject.getTotalNoOfCommits() == commits)
			projectFilter[m++]=crtProject;
	}
}

void Service::delProjectsWithCondition() {
	for (int i = 0; i < repo.getSize(); i++) {
		Project crtProject = repo.getItemFromPos(i);
		if (crtProject.getNoOfBranches()*crtProject.getTotalNoOfCommits() == 0)
		{
			repo.delElem(crtProject);
			i--;
		}
	}
}
