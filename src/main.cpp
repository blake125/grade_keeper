#include "../include/AssignmentGroup.h"
#include "../include/Class.h"
#include <iostream>

int main() {
	std::string name = "Exam";
	std::string name1 = "Exam 1";
	std::string name2 = "Exaxm 2";

	std::string name3 = "Homework";
	std::string name4 = "Homework 2";
	std::string name5 = "Homework 3";

	std::string name6 = "Math";
	
	Class math(name6);

	AssignmentGroup assignmentGroup(name, .500);
	AssignmentGroup homework(name3, .500);

	math.createAssignmentGroup(assignmentGroup);
	math.createAssignmentGroup(homework);

	Assignment assignment = {100.00, 100.00, name1};
	Assignment assignment1 = {50.00, 100.00, name2};

	Assignment assignment2 = {100.00, 100.00, name4};
	Assignment assignment3 = {50.00, 100.00, name5};

	math.createAssignment(name, assignment);
	math.createAssignment(name, assignment1);
	math.createAssignment(name3, assignment2);
	math.createAssignment(name3, assignment3);

	std::cout << math.getGrade() << std::endl; 

	return 0;
}
