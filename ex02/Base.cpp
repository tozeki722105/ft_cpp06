
#include "Base.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	static bool isFirst = true;
	if (isFirst) {
		srand((unsigned int)time(NULL));
		isFirst = false;
	}

	int num = rand() % 3;
	if (num == 0) {
		std::cout << "A generate" << std::endl;
		return new A;
	} else if (num == 1) {
		std::cout << "B generate" << std::endl;
		return new B;
	} else {
		std::cout << "C generate" << std::endl;
		return new C;
	}
}

void identify(Base* p)
{
	if (!p) {
		std::cout << "p is NULL" << std::endl;
		return;
	}

	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "Identify A" << std::endl;
	} else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "Identify B" << std::endl;
	} else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "Identify C" << std::endl;
	} else {
		std::cout << "Not identify" << std::endl;
	}
}

void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		(Base) a;
		std::cout << "Identify A" << std::endl;
		return;
	} catch (const std::bad_cast& e) {
	}
	try {
		B& b = dynamic_cast<B&>(p);
		(Base) b;
		std::cout << "Identify B" << std::endl;
		return;
	} catch (const std::bad_cast& e) {
	}
	try {
		C& c = dynamic_cast<C&>(p);
		(Base) c;
		std::cout << "Identify C" << std::endl;
		return;
	} catch (const std::bad_cast& e) {
	}
	std::cout << "Not identify" << std::endl;
}