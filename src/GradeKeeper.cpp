#include "../include/GradeKeeper.h"

GradeKeeper::GradeKeeper() {
	m_running = true;	
}

int GradeKeeper::getUserInput() {
	int choice;
	std::string choiceStr;
	std::getline(std::cin, choiceStr);

	try {
		choice = std::stoi(choiceStr);
	} catch(std::invalid_argument& e) {
		choice = -1;
	} catch(std::out_of_range& e) {
		choice = INT_MIN;
	}

	return choice;
}

void GradeKeeper::createClass() {
	std::string choiceStr;
	std::cout << "Enter class name: ";
	std::getline(std::cin, choiceStr);
	Class myClass(choiceStr);

	try {
		m_classManager.createClass(myClass);
	} catch(std::runtime_error& e) {
		std::cout << "Class name already taken!\n";
	}
}

void GradeKeeper::removeClass() {
	std::string className;
	std::cout << "What class do you want to remove? " << '\n' << m_classManager.getClassList() << "Your choice: ";
	int choice = getUserInput();

	try {
		m_classManager.removeClass(choice - 1);
	} catch(std::out_of_range& e) {
		std::cout << "Not in range, try again?\n";
	}
}

void GradeKeeper::handleChoice(int choice) {
	switch(choice) {
		case 1: {
			createClass();
			break;
		}
		case 2:
			break;
		case 3:
			removeClass();
			break;
		case 4:
			displayClassInformation();
			break;
		case 5:
			std::cout << "See you later!\n";
			m_running = false;
			break;
		default:
			std::cout << "\nInvalid choice! Try again?\n";
			break;
	}
}


void GradeKeeper::showMainMenu() {
	std::cout << "\nOptions:\n1. Create a class\n2. Edit a class\n3. Remove a class\n4. Show all class information\n5. Exit\nYour choice: ";
}

void GradeKeeper::run() {
	std::cout << "Welcome to GradeKeeper, a command line application used to help you keep track of your grades!\nTo get you started, here are your\n";

	while(m_running) {
		showMainMenu();
		int choice = getUserInput();
		handleChoice(choice);
	}
}

void GradeKeeper::displayClassInformation() {
	std::cout << '\n' << m_classManager.getAllClassInfo();
}
