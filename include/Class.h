#ifndef INCLUDE_CLASS_H
#define INCLUDE_CLASS_H

#include "AssignmentGroup.h"

class Class {
	float m_grade;
	std::string m_name;
	std::vector<AssignmentGroup> m_assignmentGroups;

	bool assignmentGroupExists(std::string& name);
	void updateClassGrade();

	public:
	Class(std::string& name);
	//CD for AssignmentGroups
	void createAssignmentGroup(AssignmentGroup& assignmentGroup);
	void deleteAssignmentGroup(std::string& name);
	
	//CD for Assignments
	void createAssignment(std::string& group, Assignment& assignment);
	void deleteAssignment(std::string& group, std::string& name);

	//getters and setters
	std::string& getName();
	float getGrade();
};

#endif
