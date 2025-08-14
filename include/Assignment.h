#ifndef INCLUDE_ASSIGNMENT_H
#define INCLUDE_ASSIGNMENT_H

#include <vector>
#include <string>
#include <iostream>

struct Assignment {
	std::string name;
	float pointsEarned;
	float pointsMax;
};	

class AssignmentType {
	std::string m_name;
	float m_cumGrade;
	float m_totalPointsEarned;
	float m_totalPointsMax;
	float m_weight;
	std::vector<Assignment> m_assignments;

	void updateCumGrade();
	bool assignmentExists(std::string& name);

	public:
	AssignmentType(std::string& name, float weight);
	void addAssignment(Assignment& assignment);
	void removeAssignment(std::string& name);
	float getCumGrade();
	std::string getName();
	float getWeight();

	std::string getAssignmentList();
};

#endif
