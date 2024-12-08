#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

int main()
{
	// ポインタテスト
	Base* p;
	for (size_t i = 0; i < 5; i++) {
		p = generate();
		identify(p);
		delete p;
	}
	std::cout << std::endl;

	// 参照テスト
	A a;
	identify(a);
	(Base) a;
	std::cout << std::endl;

	// NULLテスト
	identify(NULL);
}