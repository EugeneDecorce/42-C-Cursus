#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base* generate() {
	srand(static_cast<unsigned int>(time(0)));
	int randNum = rand() % 3;

	switch (randNum) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (std::bad_cast&) {}

	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	} catch (std::bad_cast&) {}

	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	} catch (std::bad_cast&) {}
}