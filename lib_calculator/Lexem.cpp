#include"../lib_calculator/Lexem.h"

Lexem::Lexem(std::string _name, TypeLexem _type, double _value, int _priority, double(*_function)(double)) : name(_name), type(_type),
value(_value), priority(_priority), function(_function) {}