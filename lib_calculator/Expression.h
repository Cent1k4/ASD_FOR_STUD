#ifndef LIB_CALCULATOR_EXPRESSION_H
#define LIB_CALCULATOR_EXPRESSION_H
#include"../lib_calculator/Lexem.h"
#include"../lib_list/list.h"
#include"../lib_calculator/Parser.h"
#include"../lib_calculator/Obr_pol.h"
#include"../lib_TVector/TVector.h"
using namespace Parser;

class Expression {
	List<Lexem> expression, polish_expression;
	std::string new_string;
	TVector<Lexem*> vec_variable;
	void chek_var();
	int col_var;
	bool flag_val;

public:
	Expression(std::string);
	Expression();

	std::string get_string();
	TVector<Lexem*> get_varibl();
	int get_col_var();
	List<Lexem>& get_polish_expression();

	void set_variables();
	double calculate();
	bool chek();
};

#endif // !LIB_CALCULATOR_EXPRESSION_H
