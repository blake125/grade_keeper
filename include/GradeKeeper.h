#ifndef INCLUDE_GRADEKEEPER_H
#define INCLUDE_GRADEKEEPER_H

#include "./ClassManager.h"
#include <iostream>
#include <climits>

class GradeKeeper {
	ClassManager m_classManager;
	bool m_running;

	void showMainMenu();
	void showClassMenu(Class* myClass);
	void showAssignmentMenu(AssignmentGroup* assignmentGroup);
	int getUserInput();
	void createClass();
	void removeClass();
	void handleChoice(int choice);
	void displayClassInformation();

	public:
	GradeKeeper();
	void run();
};

#endif
