#include "../include/Assignment.h"

int main() {
	std::string name;

	std::cout << "Welcome to Grade Keeper!" << std::endl;
	std::cout << "Name your assignment type: ";
	std::getline(std::cin, name);

	std::string weightStr;
	std::cout << "Give your assignment type a weight (in percent): ";
	std::getline(std::cin, weightStr);
	
	float weight = std::stof(weightStr);

	std::cout << "Now that's all set up, here are your options:\n";

	AssignmentType assignmentType(name, weight);

	while(true) {
		std::string choiceStr;
		
		std::cout << "1. Add an assignment\n";
		std::cout << "2. Remove an assignment\n";
		std::cout << "3. View grade for assignment type\n";
		std::cout << "4. Get assignment list\n";
		std::cout << "0. Exit\n";

		std::getline(std::cin, choiceStr);
		int choice = std::stoi(choiceStr);

		if(choice == 0) {
			std::cout << "Thanks for trying!\n";
			break;
		} else if(choice == 1) {
			std::string name;
			std::cout << "Give your assignment a name: ";
			std::getline(std::cin, name);

			std::string pointsEarnedStr;
			std::string pointsMaxStr;

			std::cout << "How many points did you earn? ";
			std::getline(std::cin, pointsEarnedStr);

			std::cout << "How many points was the assignment worth? ";
			std::getline(std::cin, pointsMaxStr);

			float pointsEarned = std::stof(pointsEarnedStr);
			float pointsMax = std::stof(pointsMaxStr);

			Assignment assignment = {name, pointsEarned, pointsMax};
			assignmentType.addAssignment(assignment);
		} else if(choice == 2) {
			std::string name;
			std::cout << "Which assignment do you want to remove? ";
			std::getline(std::cin, name);

			assignmentType.removeAssignment(name);
		} else if(choice == 3) {
			std::cout << "Your grade is " << assignmentType.getCumGrade() * 100 << "%" << std::endl;  	
		} else if(choice == 4) {
			std::cout << assignmentType.getAssignmentList();
			std::cout << std::endl;
		}
	}

	return 0;
}
