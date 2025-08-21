#include "../include/ClassManager.h"

ClassManager::ClassManager() {
	
}

bool ClassManager::classExists(std::string& name) {
	for(int i = 0; i < (int)m_classes.size(); i++) {
		if(m_classes.at(i).getName() == name) {
			return true;
		}
	}

	return false;
}

Class* ClassManager::getClass(std::string& name) {
	for(int i = 0; i < (int)m_classes.size(); i++) {
		if(m_classes.at(i).getName() == name) {
			return &m_classes.at(i);
		}
	}

	throw std::runtime_error("Assignment Group doesn't exist!\n");
}

//CD for classes
void ClassManager::createClass(Class& newClass) {
	if(!classExists(newClass.getName())) {
		m_classes.push_back(newClass);
	} else {
		throw std::runtime_error("Class name taken!\n");
	}
}

void ClassManager::removeClass(std::string& name) {
	for(int i = 0; i < (int)m_classes.size(); i++) {
		if(m_classes.at(i).getName() == name) {
			m_classes.erase(m_classes.begin() + i);
		}
	}

}

//CD for AssignmentGroups
void ClassManager::createAssignmentGroup(std::string& className, AssignmentGroup& assignmentGroup) {
	Class* myClass = getClass(className);
	myClass->createAssignmentGroup(assignmentGroup);
}

void ClassManager::removeAssignmentGroup(std::string& className, std::string& assignmentGroupName) {
	Class* myClass = getClass(className);
	myClass->removeAssignmentGroup(assignmentGroupName);
}

//CD for assignments
void ClassManager::createAssignment(std::string& className, std::string& assignmentGroupName, Assignment& assignment) {
	Class* myClass = getClass(className);
	myClass->createAssignment(assignmentGroupName, assignment);
}

void ClassManager::removeAssignment(std::string& className, std::string& assignmentGroupName, std::string assignmentName) {
	Class* myClass = getClass(className);
	myClass->removeAssignment(assignmentGroupName, assignmentName);
}

std::string ClassManager::getClassInfo(std::string& className) {
	std::string classInfo;
	Class* myClass = getClass(className);
	
	classInfo += "Class Name: " + myClass->getName() + "\nGrade: " + std::to_string(myClass->getGrade()) += "\nGroups: \n" + myClass->getAssignmentGroups();
	return classInfo;
}
