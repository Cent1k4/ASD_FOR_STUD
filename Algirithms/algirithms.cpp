#include "algirithms.h"
#include "stack.h"

bool chek_breckets(std::string A) {
	size_t raz = A.size();
	int i = 0;
	if (raz == 0) 
		 throw i; 

	Stack<char> S(raz);
	for (i; i < raz; i++) {
		if (A[i] == ' ')
			continue;

		else if (A[i] == '(' || A[i] == '{' || A[i] == '[' || A[i] == ')' || A[i] == '}' || A[i] == ']' || A[i] == '|') {

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
				else if (A[i] == '|' && S.top() == '|') {
					S.pop();
					continue;
				}
			}
			else if (A[i] == ')' || A[i] == '}' || A[i] == ']' || A[i] == '|')
				throw i;

			S.push(A[i]);
		}
		else
			continue;
	}
	if (S.empty())
		return true;
	else
		throw i;
}