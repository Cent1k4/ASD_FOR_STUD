#ifndef LIB_CALCULATOR_LEXEM_H
#define LIB_CALCULATOR_LEXEM_H
#include <string>

enum TypeLexem { Constant, Variable, OpenBrecket, ClosedBrecket, Function, Operator, UnOperator, OpenedAbs, ClosedAbs };

struct Lexem {
	std::string name;
	TypeLexem type;
	double value;
	int priority;
	double (*function)(double);
	double function_argument;
	Lexem(std::string _name, TypeLexem _type, double _value = DBL_MAX, int _priority = -1, double(*_function)(double) = nullptr, double _function_argument = 0);
};


#endif // !LIB_CALCULATOR_LEXEM_H
