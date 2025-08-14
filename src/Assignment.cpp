#include "../include/Assignment.h"

AssignmentType::AssignmentType(std::string& name, float weight) {
	m_name = name;
	m_weight = weight;
}

bool AssignmentType::assignmentExists(std::string& name) {
	for(int i = 0; i < (int)m_assignments.size(); i++) {
		if(m_assignments.at(i).name == name) {
			return true;
		}
	}

	return false;
}

void AssignmentType::addAssignment(Assignment& assignment) {
	if(assignmentExists(assignment.name)) {
		std::cout << "Assignment name in use, try again!\n";
	} else {
		m_assignments.push_back(assignment);
		updateCumGrade();
	}
}

void AssignmentType::removeAssignment(std::string& name) {
	if(!assignmentExists(name)) {
		std::cout << "Assignment doesn't exist!\n";
	} else {
		for(int i = 0; i < (int)m_assignments.size(); i++) {
			if(m_assignments.at(i).name == name) {
				m_assignments.erase(m_assignments.begin() + i);	
				updateCumGrade();
			}
		}
	}
	
}

void AssignmentType::updateCumGrade() {
	float earned = 0;
	float max = 0;

	if((int)m_assignments.size() == 0) {
		m_cumGrade = 0;
		return;
	}

	for(int i = 0; i < (int)m_assignments.size(); i++) {
		earned += m_assignments.at(i).pointsEarned;
		max += m_assignments.at(i).pointsMax;
	}

	m_totalPointsEarned = earned;
	m_totalPointsMax = max;

	m_cumGrade = m_totalPointsEarned / m_totalPointsMax;
}

std::string AssignmentType::getName() {
	return m_name;
}

float AssignmentType::getWeight() {
	return m_weight;
}

float AssignmentType::getCumGrade() {
	return m_cumGrade;
}

std::string AssignmentType::getAssignmentList() {
	std::string assignmentList;
	for(int i = 0; i < (int)m_assignments.size(); i++) {
		assignmentList = assignmentList + m_assignments.at(i).name + ": " + std::to_string(m_assignments.at(i).pointsEarned) + " / " + std::to_string(m_assignments.at(i).pointsMax) + '\n'; 
	}

	return assignmentList;
}
