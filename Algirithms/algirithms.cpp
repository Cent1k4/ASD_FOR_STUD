#include "algirithms.h"
#include "stack.h"

bool chek_breckets(std::string A) {
	size_t raz = A.size();
	if (raz == 0) {return false;}

	Stack<char> S(raz);
	for (int i = 0; i < raz; i++) {
		if (A[i] == ' ')
			continue;

		else if (A[i] == '(' || A[i] == '{' || A[i] == '[' || A[i] == ')' || A[i] == '}' || A[i] == ']') {

			if (!S.empty()) {
				if (A[i] == ')' && S.top() == '(') {
					S.pop();
					continue;
				}
				else if (A[i] == ']' && S.top() == '[') {
					S.pop();
					continue;
				}
				else if (A[i] == '}' && S.top() == '{') {
					S.pop();
					continue;
				}
			}
			else if (A[i] == ')' || A[i] == '}' || A[i] == ']')
				return false;

			S.push(A[i]);
		}
		else
			return false;
	}
	return S.empty();
}