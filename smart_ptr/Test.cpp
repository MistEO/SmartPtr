#include <iostream>
#include "SmartPtr.hpp"

int main(void)
{
	SmartPtr<int> p1(new int(1));
	SmartPtr<int> p2(new int(2));
	p2 = p1;
	std::cout << *p2 << std::endl;
	return 0;
}