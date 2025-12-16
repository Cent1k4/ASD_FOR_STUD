#include"../lib_calculator/Calculator.h"

int Menu::count = 0;

const int MAX_ID = 5;
const int MAX_EXPR = 30;
const int MAX_VAL = 40;


Menu::Menu() :_data(10) {}

void Menu::vibor() {
	char a;
	bool flag = false;
	std::string str;
	int t;
	std::cout << "1.Ñreate an expression\n2.Delete an expression\n3.Set variables\n4.Calculator\nEnter the action number: " << std::endl;
	do{
		std::cin >> a;
		switch (a) {
		case '1':
			std::cout << "Enter the arithmetic expression:" << std::endl;
			std::cin >> str;
			add_Expression(str);
			flag = true;
			break;

		case '2':
			delete_Expression(reshen());
			flag = true;
			break;

		case '3':
			t = reshen();
			(*_data[t]).set_variables();
			flag = true;
			break;

		case '4':
			t = reshen();
			(*_data[t]).calculate();
			flag = true;
			break;

		default:
			std::cout << "incorrect expression" << std::endl;
		}
	} while (!flag);
}


void Menu::add_Expression(std::string str) {
	Expression* temp = new Expression(str);

	if(temp->chek()){
		_data.push_back(temp);
		count++;
	}
}

void Menu::delete_Expression(int str) {
	_data.erase(str);
	count--;
}

int Menu::reshen() {
	int a;
	std::cout << "which expression is being acted on?\nNumber: " << std::endl;
	do
	{
		std::cin >> a;
		if (0 <= a && a <= count)
			return a;
		else
			std::cout << "Erorr" << std::endl;
	} while (true);
}

void line(std::ostream& os) {
	os << '+';
	for (size_t i = 0; i < MAX_ID + MAX_EXPR + MAX_VAL + 2; i++)
		os << '-';
	os << '+';
	os << std::endl;
}

void title(std::ostream& os) {
	os << '|' << std::setw(MAX_ID) << "ID" << '|' << std::setw(MAX_EXPR) << "EXPRESSION" << '|' << std::setw(MAX_VAL) << "VARAIBLES VALUES" << '|' << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Menu& A) {
	line(os);
	title(os);
	line(os);
	for (int i = 0; i < A.count; i++) {
		Expression* exp = A._data[i];
		os << '|' << std::setw(MAX_ID) << i << '|' << std::setw(MAX_EXPR) << (*exp) << '|' << std::setw(MAX_VAL) << exp->varib() << '|' << std::endl;
	}
	line(os);
	os << std::endl << std::endl;
	return os;
}