#ifndef INCLUDE_ASSIGNMENTGROUP_H
#define INCLUDE_ASSIGNMENTGROUP_H

//CD- Create and Delete
//The AssignmentGroup class acts as a CD application for Assignments. It should be able to create and delete Assignments.

#include <string>
#include <vector>
#include <stdexcept>

//Assignments are made of 3 parts. The points earned, the max point count, and the assignments name; I'm not worried about individual grades per assignment, but should I be?

struct Assignment {
	float pointsEarned;
	float pointsMax;
	std::string name;
};	

class AssignmentGroup {
	float m_pointsEarned;
	float m_pointsMax;
	float m_weight;
	std::string m_name;
	std::vector<Assignment> m_assignments;

	//helpers for CD, no use for other classes
	bool assignmentExists(std::string& name);
	void updateCumGrade();

	public:
	AssignmentGroup(std::string& name, float weight);
	//CD functionality for assignments;
	void createAssignment(Assignment& assignment);
	void deleteAssignment(std::string& name);

	//getters and setters
	std::string& getName();
	float getWeight();

	//helpers for Class
	float getWeightedGrade();
};

#endif
