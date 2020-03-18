#pragma once

class Project {
private:
	char* gitPath;
	int noOfBranches;
	int totalNoOfCommits;
public:
	Project();
	Project(const char*, int, int);
	Project(const Project&);
	Project& operator=(const Project&);
	char* getGitPath();
	int getNoOfBranches();
	int getTotalNoOfCommits();
	void setGitPath(const char*);
	void setNoOfBranches(int);
	void setTotalNoOfCommits(int);
	bool operator==(const Project&);
	~Project();
};