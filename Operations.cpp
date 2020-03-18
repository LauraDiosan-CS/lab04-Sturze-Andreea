#include "stdafx.h"
#include "Operations.h"

void filterProjects(Repository &repo, int branches, int commits,int &m, Project* projectFilter)
{
	m = 0;
	for (int i = 0; i < repo.getSize(); i++) {
		Project crtProject = repo.getItemFromPos(i);
		if (crtProject.getNoOfBranches() == branches and crtProject.getTotalNoOfCommits() == commits)
			projectFilter[m++]=crtProject;
	}
}

void delProjectsWithCondition(Repository &repo) {
	for (int i = 0; i < repo.getSize(); i++) {
		Project crtProject = repo.getItemFromPos(i);
		if (crtProject.getNoOfBranches()*crtProject.getTotalNoOfCommits() == 0)
		{
			repo.delElem(crtProject);
			i--;
		}
	}
}
