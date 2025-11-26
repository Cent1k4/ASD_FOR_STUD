#include"../lib_calculator/Calculator.h"

int Menu::max_size = 0;
int Menu::count = 0;

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
			_data[t].set_variables();
			flag = true;
			break;

		case '4':
			t = reshen();
			_data[t].calculate();
			flag = true;
			break;

		default:
			std::cout << "incorrect expression" << std::endl;
		}
	} while (!flag);
}


void Menu::add_Expression(std::string str) {
	Expression temp(str);
	if(temp.chek()){
		for (int i = 0; i < count; i++) {
			if (_data[i].chek())
				_data[i] = temp;
			else
				continue;
		}
		if (max_size < str.size())
			max_size = str.size();
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

