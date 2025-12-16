#ifndef LIB_CALCULATOR_CALCULATOR_H
#define LIB_CALCULATOR_CALCULATOR_H
#include <iomanip>
#include"../lib_calculator/Expression.h"


class Menu {
	static int count;
	TVector<Expression*> _data;
public:
	Menu();
	void vibor();
	void add_Expression(std::string);
	void delete_Expression(int);
	int reshen();
	friend std::ostream& operator<<(std::ostream&, const Menu&);
};

void line(std::ostream&);
void title(std::ostream&);

#endif // !LIB_CALCULATOR_CALCULATOR_H