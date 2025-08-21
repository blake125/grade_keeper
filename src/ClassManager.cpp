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

void ClassManager::removeClass(int index) {
	if(index < 0 || index > (int)m_classes.size() - 1) {
		throw std::out_of_range("Index not in range!");
	}

	m_classes.erase(m_classes.begin() + index);
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
	
	classInfo += "Class Name: " + myClass->getName() + "\nGrade: " + std::to_string(myClass->getGrade()) += "\n\nAdvanced Overview: \n" + myClass->getAssignmentGroups();
	return classInfo;
}

std::string ClassManager::getClassInfo(Class& myClass) {
	std::string classInfo;
	
	classInfo += "Class Name: " + myClass.getName() + "\nGrade: " + std::to_string(myClass.getGrade()) /*+= "\n\nAdvanced Overview: \n" + myClass.getAssignmentGroups()*/;
	return classInfo;
}

std::string ClassManager::getAllClassInfo() {
	if(m_classes.size() == 0) {
		return "Class list is empty!\n";
	}

	std::string allClassInfo;

	int i;
	for(i = 0; i < (int)m_classes.size() - 1; i++) {
		allClassInfo += getClassInfo(m_classes.at(i)) + "\n\n";	
	}

	allClassInfo += getClassInfo(m_classes.at(i)) + '\n';	

	return allClassInfo;
}

std::string ClassManager::getClassList() {
	if(m_classes.size() == 0) {
		return "Class list is empty!\n";
	}

	std::string classList;

	int i;
	for(i = 0; i < (int)m_classes.size(); i++) {
		classList += std::to_string(i + 1) + ": " + m_classes.at(i).getName() + "\n";	
	}

	return classList;
};
