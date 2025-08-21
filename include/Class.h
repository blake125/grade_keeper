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
	void removeAssignmentGroup(std::string& name);
	
	//CD for Assignments
	void createAssignment(std::string& group, Assignment& assignment);
	void removeAssignment(std::string& group, std::string& name);

	//getters and setters
	std::string& getName();
	std::string getAssignmentGroups();
	float getGrade();
};

#endif
