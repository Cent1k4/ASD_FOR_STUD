#ifndef LIB_CALCULATOR_CALCULATOR_H
#define LIB_CALCULATOR_CALCULATOR_H
#include"../lib_calculator/Expression.h"

class Menu {
	static int max_size;
	static int count;
	TVector<Expression> _data;
public:
	Menu();
	void vibor();
	void add_Expression(std::string);
	void delete_Expression(int);
	int reshen();
};

#endif // !LIB_CALCULATOR_CALCULATOR_H