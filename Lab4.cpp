// Lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tests.h"
#include<iostream>
using namespace std;


int main()
{
	cout << "start" << endl;
	testProject();
	testRepo();
	testFilterProjects();
	testDelProjectsWithCondition();
	cout << "finish";
    return 0;
}

