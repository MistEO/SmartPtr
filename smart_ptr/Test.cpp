#include <iostream>
#include "SmartPtr.hpp"

int main(void)
{
	auto p1 = MakeSmart<int>(1);
	auto p2 = MakeSmart<int>(2);
	p2 = p1;
	std::cout << *p2 << std::endl;
	auto p3 = MakeSmart<int>();
	return 0;
}