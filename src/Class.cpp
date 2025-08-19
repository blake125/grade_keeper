#include "../include/Class.h"

Class::Class(std::string& name) {
	m_name = name;
}

bool Class::assignmentGroupExists(std::string& name) {
	for(int i = 0; i < (int)m_assignmentGroups.size(); i++) {
		if(m_assignmentGroups.at(i).getName() == name) {
			return true;
		}
	}

	return false;
}

void Class::updateClassGrade() {
	float grade = 0.00;	

	for(int i = 0; i < (int)m_assignmentGroups.size(); i++) {
		grade += m_assignmentGroups.at(i).getWeightedGrade();
	}

	m_grade = grade;
}

void Class::createAssignmentGroup(AssignmentGroup& assignmentGroup) {
	if(!assignmentGroupExists(assignmentGroup.getName())) {
		m_assignmentGroups.push_back(assignmentGroup);
	} else {
		throw std::runtime_error("Assignment Group already exists!");
		return;
	}

}

void Class::deleteAssignmentGroup(std::string& name) {
	for(int i = 0; i < (int)m_assignmentGroups.size(); i++) {
		if(m_assignmentGroups.at(i).getName() == name) {
			m_assignmentGroups.erase(m_assignmentGroups.begin() + i);
		}
	}
}

void Class::createAssignment(std::string& group, Assignment& assignment) {
	for(int i = 0; i < (int)m_assignmentGroups.size(); i++) {
		if(m_assignmentGroups.at(i).getName() == group) {
			m_assignmentGroups.at(i).createAssignment(assignment);
			updateClassGrade();
		}
	}
}

void Class::deleteAssignment(std::string& group, std::string& name) {
	for(int i = 0; i < (int)m_assignmentGroups.size(); i++) {
		if(m_assignmentGroups.at(i).getName() == group) {
			m_assignmentGroups.at(i).deleteAssignment(name);
			updateClassGrade();
		}
	}
}

float Class::getGrade() {
	return m_grade;
}

std::string& Class::getName() {
	return m_name;
}
