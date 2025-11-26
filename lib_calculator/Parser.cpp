#include"../lib_calculator/Parser.h"

namespace Parser {

	void check_constants(int& i, std::string& line, List<Lexem>& record) {
		std::string new_str = "";
		while (i < line.size() && '0' <= line[i] && line[i] <= '9')
			new_str += line[i++];
		
		if (new_str.size() != 0) {
			if (i >= line.size() || line[i] == '*' || line[i] == '+' || line[i] == '-' || line[i] == '/' || line[i] == '^' || line[i] == ')' || line[i] == '|')
				record.push_back(Lexem(new_str, Constant, std::stoi(new_str)));
			else
				throw i;
		}
	}

	void checking_a_variable(int& i, std::string& line, List<Lexem>& record) {
		std::string new_str = "";
		while (i < line.size() && (('a' <= line[i] && line[i] <= 'z') || ('A' <= line[i] && line[i] <= 'Z') || line[i]=='_' || ('0' <= line[i] && line[i] <= '9')))
			new_str += line[i++];

		if (new_str.size() != 0) {
			if (i >= line.size() || line[i] == '*' || line[i] == '+' || line[i] == '-' || line[i] == '/' || line[i] == '^' || line[i] == ')' || line[i] == '|')
				record.push_back(Lexem(new_str, Variable, 0));
			else
				throw i;
		}
	}


	void checking_a_operator(int& i, std::string& line, List<Lexem>& record) {
		if (i <= line.size() && (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/' || line[i] == '^' || line[i] == '|' || line[i] == ')' || line[i] == '(')) {
			i++;
			if (('a' <= line[i] && line[i] <= 'z') || ('A' <= line[i] && line[i] <= 'Z') || line[i] == '_' || line[i] == '(' || line[i] == '|' || ('0' < line[i] && line[i] <= '9')) {
				if (line[i - 1] == '+')
					record.push_back(Lexem("+", Operator, 0, 1));

				else if (line[i - 1] == '-')
					record.push_back(Lexem("-", Operator, 0, 1));

				else if (line[i - 1] == '*')
					record.push_back(Lexem("*", Operator, 0, 2));

				else if (line[i - 1] == '/')
					record.push_back(Lexem("/", Operator, 0, 2));

				else if (line[i - 1] == '^')
					record.push_back(Lexem("^", Operator, 0, 3));

				else if (line[i - 1] == '|')
					record.push_back(Lexem("|", ABS, 0));

				else if (line[i - 1] == ')')
					record.push_back(Lexem(")", ClosedBrecket, 0));

				else if (line[i - 1] == '(')
					record.push_back(Lexem("(", OpenBrecket, 0));
			}

			else if ((i >= line.size() && line[i - 1] == ')') || (line[i - 1] == ')' && line[i] == ')') || (line[i - 1] == ')' && line[i] == '|'))
				record.push_back(Lexem(")", ClosedBrecket, 0));

			else if ((i >= line.size() && line[i - 1] == '|') || (line[i - 1] == '|' && line[i] == ')') || (line[i - 1] == '|' && line[i] == '|'))
				record.push_back(Lexem("|", ABS, 0));

			else
				throw i;
		}
	}

	void function_check(int& i, std::string& line, List<Lexem>& record) {
		std::string new_str = "";
		while (i < line.size() && (line[i] == 's' || line[i] == 'i' || line[i] == 'n' || line[i] == 'c' || line[i] == 'o' || line[i] == 'l' || line[i] == 'n' || line[i] == 'q' || line[i] == 'r' || line[i] == 't'))
			new_str += line[i++];

		if (new_str.size() != 0) {
			if (i >= line.size() && (new_str == "sin" || new_str == "cos" || new_str == "ln" || new_str == "sqrt" || new_str == "tg" || new_str == "ctg"))
				throw i;

			if (new_str == "sin" && line[i] == '(')
				record.push_back(Lexem(new_str, Function, 0, 6, *my_sin));

			else if (new_str == "cos" && line[i] == '(')
				record.push_back(Lexem(new_str, Function, 0, 6, *my_cos));

			else if (new_str == "ln" && line[i] == '(')
				record.push_back(Lexem(new_str, Function, 0, 6, *my_ln));

			else if (new_str == "sqrt" && line[i] == '(')
				record.push_back(Lexem(new_str, Function, 0, 6, *my_sqrt));

			else if (new_str == "tg" && line[i] == '(')
				record.push_back(Lexem(new_str, Function, 0, 6, *my_tg));

			else if (new_str == "ctg" && line[i] == '(')
				record.push_back(Lexem(new_str, Function, 0, 6, *my_ctg));
			else

				i -= new_str.size();
		}
	}

	bool parser(std::string& line, List<Lexem>& record) {
		int size = line.size();
		if (size == 0) {
			std::cout << "Exeple string" << std::endl;
			return false;
		}

		try {
			if (!chek_breckets);
		}
		catch (int num_erorr) {
			std::cout << line << std::endl;

			for (int j = 0; j < num_erorr; j++)
				std::cout << ' ';

			std::cout << '^' << std::endl;
			for (int j = 0; j < num_erorr; j++)
				std::cout << ' ';

			std::cout << '|' << std::endl;
			std::cout << "Error in function 'Parser::parse()' at " << num_erorr << " symbol: incorrect brackets" << std::endl;
			return false;
		}

		for (int i = 0; i < size; ) {
			if (line[0] == '~' && i == 0) {
				record.push_front(Lexem("0", Constant, 0.0));
				record.push_front(Lexem("-", Operator, 0.0, 1));
			}
			int chek = i;
			try {
				function_check(i, line, record);
				check_constants(i, line, record);
				checking_a_variable(i, line, record);
				checking_a_operator(i, line, record);
				if (i == chek)
					throw i;
			} 
			catch (int num_erorr) {
				std::cout << line << std::endl;

				for (int j = 0; j < num_erorr; j++)
					std::cout << ' ';

				std::cout << '^' << std::endl;
				for (int j = 0; j < num_erorr; j++)
					std::cout << ' ';

				std::cout << '|' << std::endl;
				std::cout << "Error in function 'Parser::parse()' at " << num_erorr << " symbol: incorrect expression" << std::endl;
				return false;
				break;
			}
		}
		return true;
	}
}