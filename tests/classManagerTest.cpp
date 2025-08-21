#include "../include/GradeKeeper.h"

int main() {
	ClassManager classManager;

	std::string name = "Exam";
	std::string name1 = "Exam 1";
	std::string name2 = "Exam 2";

	std::string name3 = "Homework";
	std::string name4 = "Homework 2";
	std::string name5 = "Homework 3";

	std::string name6 = "Math";
	
	Class math(name6);

	AssignmentGroup assignmentGroup(name, .500);
	AssignmentGroup homework(name3, .500);

	classManager.createClass(math);
	classManager.createAssignmentGroup(name6, assignmentGroup);
	classManager.createAssignmentGroup(name6, homework);

	Assignment assignment = {100.00, 100.00, name1};
	Assignment assignment1 = {50.00, 100.00, name2};

	Assignment assignment2 = {100.00, 100.00, name4};
	Assignment assignment3 = {50.00, 100.00, name5};

	classManager.createAssignment(name6, name, assignment);
	classManager.createAssignment(name6, name, assignment1);
	classManager.createAssignment(name6, name3, assignment2);
	classManager.createAssignment(name6, name3, assignment3);

	std::cout << classManager.getClassInfo(name6) << std::endl; 

	return 0;
}
