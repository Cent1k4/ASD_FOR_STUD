#include"../lib_calculator/Lexem.h"

Lexem::Lexem(std::string _name, TypeLexem _type, double _value, int _priority, double(*_function)(double)) : name(_name), type(_type),
value(_value), priority(_priority), function(_function) {}

Lexem::Lexem() : name(""), type(NO), value(0), priority(-1), function(nullptr) {}

bool Lexem::operator==(const Lexem& other) const {
    return name == other.name && type == other.type && value == other.value && priority == other.priority &&
        function == other.function;
}

Lexem::Lexem(const Lexem& A) {
    name = A.name;
    type = A.type;
    value = A.value;
    priority = A.priority;
    function = A.function;
}

