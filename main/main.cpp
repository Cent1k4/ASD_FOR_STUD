// Copyright 2024 Marina Usova

#define EASY_EXAMPLE
#ifdef EASY_EXAMPLE

#include <iostream>
#include <iomanip>
#include "../lib_calculator/Calculator.h"

int main() {
	bool t = true;
	std::string str;
	Menu A;
	do
	{
		std::cout << A;
		A.vibor();
	} while (t);
}


#endif  // EASY_EXAMPLE
