#ifndef LIB_CALCULATOR_LEXEM_H
#define LIB_CALCULATOR_LEXEM_H
#include <string>

enum TypeLexem { Constant, Variable, OpenBrecket, ClosedBrecket, Function, Operator, ABS, NO };

struct Lexem {
	std::string name;
	TypeLexem type;
	double value;
	int priority;
	double (*function)(double);

	Lexem();
	Lexem(const Lexem&);
	Lexem(std::string, TypeLexem, double _value = DBL_MAX, int _priority = -1, double(*_function)(double) = nullptr);

	bool operator==(const Lexem& other) const;
};


#endif // !LIB_CALCULATOR_LEXEM_H
