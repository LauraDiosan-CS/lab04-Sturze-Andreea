#include "stdafx.h"
#include "UI.h"
#include <iostream>
using namespace std;

UI::UI() {

}

UI::~UI() {
}

UI::UI(const Service& serv) {
	this->service = serv;
}

void UI::printMenu() {
	cout << endl;
	cout << "Menu:" << endl;
	cout << "\t 1.Add project" << endl;
	cout << "\t 2.Print projects" << endl;
	cout << "\t 3.Delete project" << endl;
	cout << "\t 4.Update project" << endl;
	cout << "\t 5.Projects that have k branches and l commits" << endl;
	cout << "\t 6.Delete projects that have 0 branches or 0 commits" << endl;
	//cout << "\t 7.Undo" << endl;
	cout << "\t 0.Exit" << endl;
	cout << "Choose option: ";
}

void UI::addProject() {
	cout << "Git Path: ";
	char* path = new char[10];
	cin >> path;
	cout << "No of branches: ";
	int branches;
	cin >> branches;
	cout << "No of commits: ";
	int commits;
	cin >> commits;
	service.addToRepo(path, branches, commits);
}

void UI::printProjects() {
	int i = 0;
	Project* projects = service.getFromRepo();
	while (i < service.getRepoSize())
	{
		cout << projects[i].getGitPath() << " " << projects[i].getNoOfBranches() << " " << projects[i].getTotalNoOfCommits() << endl;
		i++;
	}
}

void UI::deleteProject() {
	cout << "Git Path: ";
	char* path = new char[10];
	cin >> path;
	cout << "No of branches: ";
	int branches;
	cin >> branches;
	cout << "No of commits: ";
	int commits;
	cin >> commits;
	service.delFromRepo(path, branches, commits);
}

void UI::updateProject() {
	cout << "\t Project to update:" << endl;
	cout << "Git Path: ";
	char* path = new char[10];
	cin >> path;
	cout << "No of branches: ";
	int branches;
	cin >> branches;
	cout << "No of commits: ";
	int commits;
	cin >> commits;
	cout << "\t New datas:" << endl;
	cout << "Git Path: ";
	char* newPath = new char[10];
	cin >> newPath;
	cout << "No of branches: ";
	int newBranches;
	cin >> newBranches;
	cout << "No of commits: ";
	int newCommits;
	cin >> newCommits;
	service.updateInRepo(path, branches, commits, newPath, newBranches, newCommits);
}

void UI::filterProjects() {
	cout << "k = ";
	int k;
	cin >> k;
	cout << "l = ";
	int l;
	cin >> l;
	int m;
	cout << endl;
	Project result[100];
	service.filterProjects(k, l, m, result);
	for (int i = 0; i < m; i++)
		cout << result[i].getGitPath() << " " << result[i].getNoOfBranches() << " " << result[i].getTotalNoOfCommits() << endl;
}

void UI::deleteProjects() {
	service.delProjectsWithCondition();
}

void UI::run() {
	int option;
	bool works = true;
	while (works != false)
	{
		printMenu();
		cin >> option;
		switch (option)
		{
		case 1: {
			addProject();
			break;
		}
		case 2: {
			printProjects();
			break;
		}
		case 3: {
			deleteProject();
			break;
		}
		case 4: {
			updateProject();
			break;
		}
		case 5: {
			filterProjects();
			break;
		}
		case 6: {
			deleteProjects();
			break;
		}
		case 7: {
			break;
		}
		case 0: {

			works = false;
			break;
		}
		default: {
			cout << "There is no such option." << endl;
		}
		}
	}
}
