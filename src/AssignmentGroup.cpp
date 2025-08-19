#include "../include/AssignmentGroup.h"

AssignmentGroup::AssignmentGroup(std::string& name, float weight) {
	m_name = name;
	m_weight = weight;
}

bool AssignmentGroup::assignmentExists(std::string& name) {
	for(int i = 0; i < (int)m_assignments.size(); i++) {
		if(m_assignments.at(i).name == name) {
			return true;
		}
	}

	return false;
}

void AssignmentGroup::createAssignment(Assignment& assignment) {
	if(assignmentExists(assignment.name)) {
		throw std::runtime_error("Assignment already exists!");
		return;
	} else {
		m_assignments.push_back(assignment);
		updateCumGrade();
	}
}

void AssignmentGroup::deleteAssignment(std::string& name) {
	if(!assignmentExists(name)) {
		throw std::runtime_error("Assignment doesn't exist!");
		return;
	} else {
		for(int i = 0; i < (int)m_assignments.size(); i++) {
			if(m_assignments.at(i).name == name) {
				m_assignments.erase(m_assignments.begin() + i);	
				updateCumGrade();
			}
		}
	}
	
}

void AssignmentGroup::updateCumGrade() {
	float earned = 0;
	float max = 0;

	for(int i = 0; i < (int)m_assignments.size(); i++) {
		earned += m_assignments.at(i).pointsEarned;
		max += m_assignments.at(i).pointsMax;
	}

	m_pointsEarned = earned;
	m_pointsMax = max;
}

std::string& AssignmentGroup::getName() {
	return m_name;
}

float AssignmentGroup::getWeight() {
	return m_weight;
}

float AssignmentGroup::getWeightedGrade() {
	if((int)m_assignments.size() == 0) {
		return 0;
	}

	return (m_pointsEarned / m_pointsMax) * m_weight;
}
