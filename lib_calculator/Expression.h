#ifndef LIB_CALCULATOR_EXPRESSION_H
#define LIB_CALCULATOR_EXPRESSION_H
#include"../lib_calculator/Lexem.h"
#include"../lib_list/list.h"
#include"../lib_calculator/Parser.h"
using namespace Parser;

class Expression {
	List<Lexem> expression;
	List<Lexem> polish_expression;
public:
	Expression(std::string);
};

#endif // !LIB_CALCULATOR_EXPRESSION_H
