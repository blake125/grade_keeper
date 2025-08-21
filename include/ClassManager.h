#ifndef INCLUDE_CLASSMANAGER_H
#define INCLUDE_CLASSMANAGER_H

#include "./Class.h"

class ClassManager {
	std::vector<Class> m_classes;
	bool classExists(std::string& name);
	Class* getClass(std::string& name);

	public:
	ClassManager();
	//CD for classes
	void createClass(Class& newClass);
	void removeClass(std::string& name);
	//CD for AssignmentGroups
	void createAssignmentGroup(std::string& className, AssignmentGroup& assignmentGroup);
	void removeAssignmentGroup(std::string& className, std::string& assignmentGroupName);
	//CD for assignments
	void createAssignment(std::string& className, std::string& assignmentGroupName, Assignment& assignment);
	void removeAssignment(std::string& className, std::string& assignmentGroupName, std::string assignmentName);

	std::string getClassInfo(std::string& className);

};

#endif
