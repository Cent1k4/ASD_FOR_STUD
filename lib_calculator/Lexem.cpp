#include"../lib_calculator/Lexem.h"

Lexem::Lexem(std::string _name, TypeLexem _type, double _value, int _priority, double(*_function)(double), double _function_argument) : name(_name), type(_type), 
value(_value), priority(_priority), function(_function), function_argument(_function_argument){
	if (function != nullptr && type == Function)
		value = function(_function_argument);
}