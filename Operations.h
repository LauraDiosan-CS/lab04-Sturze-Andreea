#pragma once
#include "Project.h"
#include "Repository.h"

void filterProjects(Repository &repo, int branches, int commits, vector<Project> &projectFilter);
void delProjectsWithCondition(Repository &repo);
