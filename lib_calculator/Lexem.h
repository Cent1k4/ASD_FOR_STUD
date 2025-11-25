#ifndef LIB_CALCULATOR_LEXEM_H
#define LIB_CALCULATOR_LEXEM_H
#include <string>

enum TypeLexem { Constant, Variable, OpenBrecket, ClosedBrecket, Function, Operator, UnOperator, ABS };

struct Lexem {
	std::string name;
	TypeLexem type;
	double value;
	int priority;
	double (*function)(double);
	Lexem(std::string _name, TypeLexem _type, double _value = DBL_MAX, int _priority = -1, double(*_function)(double) = nullptr);
};


#endif // !LIB_CALCULATOR_LEXEM_H
