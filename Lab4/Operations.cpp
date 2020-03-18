#include "stdafx.h"
#include "Operations.h"

void filterProjects(Repository &repo, int branches, int commits, vector<Project> &projectFilter)
{
	for (int i = 0; i < repo.dim(); i++) {
		Project crtProject = repo.getItemFromPos(i);
		if (crtProject.getNoOfBranches() == branches and crtProject.getTotalNoOfCommits() == commits)
			projectFilter.push_back(crtProject);
	}
}

void delProjectsWithCondition(Repository &repo) {
	for (int i = 0; i < repo.dim(); i++) {
		Project crtProject = repo.getItemFromPos(i);
		if (crtProject.getNoOfBranches()*crtProject.getTotalNoOfCommits() == 0)
		{
			repo.delElem(crtProject);
			i--;
		}
	}
}