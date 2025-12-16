#include"../lib_calculator/Expression.h"


Expression::Expression() : new_string(""), expression(), polish_expression(), vec_variable(10), col_var(0), flag_val(false){}

Expression::Expression(std::string A) : new_string(A), col_var(0), flag_val(false), vec_variable(10){
	if (Parser::parser(A, expression)) {
		building_reverse_Polish(expression, polish_expression, new_string.size());
		chek_var();
	}
	else 
		new_string = "";
}

void Expression::chek_var(){
	List<Lexem>::Iterator it = polish_expression.begin();
	while (it != polish_expression.end()) {
		Lexem& current_lexem = *it;

		if (current_lexem.type == Variable) {
			if ((vec_variable.find(&current_lexem)) == -1) {
				vec_variable.push_back(& current_lexem);
				col_var++;
			}
		}
		it++;
	}
}

double Expression::calculate() {

	if (flag_val) {
		Stack<double> S(new_string.size());
		List<Lexem>::Iterator it = polish_expression.begin();

		while (it != polish_expression.end()) {
			double val;
			Lexem A(*it);
			if (A.type == Constant || A.type == Variable)
				S.push(A.value);

			else if (A.name == "+") {
				val = S.top();
				S.pop();
				S.top() += val;
			}
			else if (A.name == "-") {
				val = S.top();
				S.pop();
				S.top() -= val;
			}
			else if (A.name == "*") {
				val = S.top();
				S.pop();
				S.top() *= val;
			}
			else if (A.name == "/") {
				val = S.top();
				S.pop();
				S.top() /= val;
			}
			else if (A.name == "^") {
				val = S.top();
				S.pop();
				S.top() = powf(S.top(), val);
			}
			else if (A.type == Function)
				S.top() = A.function(S.top());
			it++;
		}
		return S.top();
	}

	else
		std::cout << "initialize the variables before calculating" << std::endl;
}

void Expression::set_variables() {
	for (int i = 0; i < col_var; i++) {
		if ((*vec_variable[i]).value == 0) {
			std::cout << (*vec_variable[i]).name << " = ";
			std::cin >> (*vec_variable[i]).value;

			for (int j = i + 1; j < col_var; j++) {
				if ((*vec_variable[i]).name == (*vec_variable[j]).name)
					(*vec_variable[j]).value = (*vec_variable[i]).value;
			}

			std::cout << std::endl;
		}
	}
	flag_val = true;
}

std::string Expression::get_string() { return new_string; }

TVector<Lexem*>& Expression::get_varibl() { return vec_variable; }

int Expression::get_col_var() { return col_var; }

List<Lexem>& Expression::get_polish_expression() { return polish_expression; }

bool Expression::chek() { return new_string != ""; }

std::ostream& operator<<(std::ostream& os, const Expression& A) { 
	os << A.new_string; 
	return os;
}

std::string Expression::varib() {
	std::string os = " ";
	for (int i = 0; i < col_var; i++) {
		os += (*vec_variable[i]).name;
		os += '=';
		if (flag_val) {
			os += std::to_string((*vec_variable[i]).value);
			os += ' ';
		}
		else
			os += "? ";
	}
	return os;
}
