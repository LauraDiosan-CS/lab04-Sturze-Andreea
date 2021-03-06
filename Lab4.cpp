// Lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tests.h"
#include "UI.h"
#include<iostream>
using namespace std;


int main()
{
	cout << "Start tests..." << endl;
	testProject();
	testRepo();
	testServiceCRUD();
	testFilterProjects();
	testDelProjectsWithCondition();
	cout << "Tests completed!";
	Repository repo;
	Project p1("h1/a", 1, 1);
	repo.addElem(p1);
	Project p2("h2/b", 4, 0);
	repo.addElem(p2);
	Project p3("h3/c", 2, 3);
	repo.addElem(p3);
	Project p4("h4/d", 0, 1);
	repo.addElem(p4);
	Project p5("h5/e", 2, 3);
	repo.addElem(p5);
	Service serv(repo);
	UI ui(serv);
	ui.run();
    return 0;
}

