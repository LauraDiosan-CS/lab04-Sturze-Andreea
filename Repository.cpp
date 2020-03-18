#include "stdafx.h"
#include "Repository.h"

Repository::Repository() {
	size = 0;
}

Repository::~Repository() {

}

void Repository::addElem(Project p) {
	this->elem[size++]=p;
}

void Repository::delElem(Project p) {
	int i = findElem(p);
	if (i != -1)
	{
		elem[i] = elem[size - 1];
		size--;
	}
}

void Repository::updateElem(Project p, const char* path, int branches, int commits) {
	for(int i = 0; i < size; i++)
		if (elem[i]==p)
		{
			elem[i].setGitPath(path);
			elem[i].setNoOfBranches(branches);
			elem[i].setTotalNoOfCommits(commits);
		}
}

int Repository::findElem(Project p) {
	for (int i = 0; i < size; i++)
		if (elem[i] == p)
			return i;
	return -1;
}

Project Repository::getItemFromPos(int i) {
	return elem[i];
}

Project* Repository::getAll() {
	return elem;
}

int Repository::getSize() {
	return size;
}