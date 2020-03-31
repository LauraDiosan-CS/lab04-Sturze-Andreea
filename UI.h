#pragma once
#include "Service.h"

class UI {
private:
	Service service;
	void printMenu();
	void addProject();
	void printProjects();
	void deleteProject();
	void updateProject();
	void filterProjects();
	void deleteProjects();
	void undo();
public:
	UI();
	UI(const Service &);
	~UI();
	void run();
};