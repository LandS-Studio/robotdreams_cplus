#include "lesson_21.h"
#include "Observer.h"

void StartHomework_21(){
	ASubject* subject = new ASubject;
	
	Observer* observer_1 = new Observer(*subject);
	Observer* observer_2 = new Observer(*subject);
	Observer* observer_3 = new Observer(*subject);
	Observer* observer_4;
	Observer* observer_5;
	std::cout << std::endl;

	subject->CreateMessage("My name is Maksym!");
	std::cout << std::endl;

	observer_3->RemoveFromList();
	std::cout << std::endl;

	subject->CreateMessage("I did my homework today! =)");
	std::cout << std::endl;

	observer_4 = new Observer(*subject);
	std::cout << std::endl;

	observer_2->RemoveFromList();
	std::cout << std::endl;

	observer_5 = new Observer(*subject);
	std::cout << std::endl;

	subject->CreateMessage("I'm in a good mood today ;)");
	std::cout << std::endl;

	observer_5->RemoveFromList();
	std::cout << std::endl;

	observer_4->RemoveFromList();
	std::cout << std::endl;

	observer_1->RemoveFromList();
	std::cout << std::endl;

	delete observer_5;
	delete observer_4;
	delete observer_3;
	delete observer_2;
	delete observer_1;
	delete subject;
}
