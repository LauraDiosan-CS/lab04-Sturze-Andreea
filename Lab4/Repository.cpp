#include "stdafx.h"
#include "Repository.h"

Repository::Repository() {

}

Repository::~Repository() {

}

void Repository::addElem(Project p) {
	this->elem.push_back(p);
}

void Repository::delElem(Project p) {
	vector<Project>::iterator it;
	it = find(elem.begin(), elem.end(), p);
	if (it != elem.end()) 
		elem.erase(it);
}

void Repository::updateElem(Project p, const char* path, int branches, int commits) {
	for(int i = 0; i < elem.size(); i++)
		if (elem[i]==p)
		{
			elem[i].setGitPath(path);
			elem[i].setNoOfBranches(branches);
			elem[i].setTotalNoOfCommits(commits);
		}
}

bool Repository::findElem(Project p) {
	vector<Project>::iterator it;
	it = find(elem.begin(), elem.end(), p);
	if (it != elem.end()) 
		return true;
	return false;
}

Project Repository::getItemFromPos(int i) {
	return elem[i];
}

vector<Project> Repository::getAll() {
	return elem;
}

int Repository::dim() {
	return elem.size();
}