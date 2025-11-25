#include"../lib_calculator/Expression.h"

Expression::Expression(std::string A) {
	Parser::parser(A, expression);

}