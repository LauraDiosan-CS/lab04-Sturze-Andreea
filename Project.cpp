#include "stdafx.h"
#include "Project.h"
#include <string.h>

Project::Project() {
	this->gitPath = NULL;
	this->noOfBranches = 0;
	this->totalNoOfCommits = 0;
}

Project::Project(const char* path, int branchesNo, int commitsNo) {
	this->gitPath = new char[strlen(path) + 1];
	strcpy_s(this->gitPath, strlen(path) + 1, path);
	this->noOfBranches = branchesNo;
	this->totalNoOfCommits = commitsNo;
}

Project::Project(const Project& p) {
	this->gitPath = new char[strlen(p.gitPath) + 1];
	strcpy_s(this->gitPath, strlen(p.gitPath) + 1, p.gitPath);
	this->noOfBranches = p.noOfBranches;
	this->totalNoOfCommits = p.totalNoOfCommits;
}

Project::~Project() {
	if (this->gitPath)
		delete[] this->gitPath;
	this->gitPath = NULL;
	this->noOfBranches = -1;
	this->totalNoOfCommits = -1;
}

char* Project::getGitPath() {
	return this->gitPath;
}

int Project::getNoOfBranches() {
	return this->noOfBranches;
}

int Project::getTotalNoOfCommits() {
	return this->totalNoOfCommits;
}

void Project::setGitPath(const char* path) {
	if (this->gitPath)
		delete[] this->gitPath;
	this->gitPath = new char[strlen(path) + 1];
	strcpy_s(this->gitPath, strlen(path) + 1, path);
}

void Project::setNoOfBranches(int branches) {
	this->noOfBranches = branches;
}

void Project::setTotalNoOfCommits(int commits) {
	this->totalNoOfCommits = commits;
}

Project& Project::operator=(const Project& p) {
	if (this == &p)
		return *this;
	if (this->gitPath)
		delete[] this->gitPath;
	this->gitPath = new char[strlen(p.gitPath) + 1];
	strcpy_s(this->gitPath, strlen(p.gitPath) + 1, p.gitPath);
	this->noOfBranches = p.noOfBranches;
	this->totalNoOfCommits = p.totalNoOfCommits;
	return *this;
}

bool Project::operator==(const Project& p) {
	return (strcmp(this->gitPath, p.gitPath) == 0 and this->noOfBranches == p.noOfBranches and this->totalNoOfCommits == p.totalNoOfCommits);
}