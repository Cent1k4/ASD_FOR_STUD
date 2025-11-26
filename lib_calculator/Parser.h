#ifndef LIB_CALCULATOR_PARSER_H
#define LIB_CALCULATOR_PARSER_H
#include<string>
#include"../lib_calculator/Lexem.h"
#include"../lib_list/list.h"
#include"../lib_calculator/math_func.h"
#include"../Algirithms/algirithms.h"

namespace Parser {
	void function_check(int&, std::string&, List<Lexem>&);
	void check_constants(int&, std::string&, List<Lexem>&);
	void checking_a_operator(int&, std::string&, List<Lexem>&);
	void checking_a_variable(int&, std::string&, List<Lexem>&);
	bool parser(std::string&, List<Lexem>&);
}

#endif // !LIB_CALCULATOR_PARSER_H
