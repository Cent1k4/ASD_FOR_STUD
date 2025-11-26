#include"../lib_calculator//Obr_pol.h"

void building_reverse_Polish(List<Lexem>& usual, List<Lexem>& polish, size_t size) {
	List<Lexem>::Iterator it = usual.begin();
	Stack<Lexem> stack(size);
	bool flag = true;
	while (it != usual.end()) {
		Lexem A = *it;
		if (A.type == Constant || A.type == Variable)
			polish.push_back(A);

		else if (A.type == OpenBrecket)
			stack.push(A);

		else if (A.type == ClosedBrecket) {
			while (stack.top().type != OpenBrecket) {
				polish.push_back(stack.top());
				stack.pop();
			}
			stack.pop();
		}
		else if (A.type == ABS && flag) {
			stack.push(A);
			flag = false;
		}

		else if (A.type == ABS && !flag) {
			while (stack.top().type != ABS) {
				polish.push_back(stack.top());
				stack.pop();
			}
			stack.pop();
			flag = true;
			polish.push_back(Lexem("abs", Function, 0, 6, *my_abs));
		}

		else if(A.type == Operator || A.type == Function)  {

			if (stack.empty() || A.priority <= stack.top().priority) {
				while (!stack.empty() && stack.top().type != OpenBrecket && A.priority <= stack.top().priority) {
					polish.push_back(stack.top());
					stack.pop();
				}
				
				stack.push(A);
			}

			else
				stack.push(A);
		}
		it++;
	}

	while (!stack.empty()) {
		polish.push_back(stack.top());
		stack.pop();
	}
}