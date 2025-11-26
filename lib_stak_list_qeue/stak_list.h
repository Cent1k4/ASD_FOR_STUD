#ifndef LIB_STAK_LIST_QEUE_STAK_LIST_H
#define LIB_STAK_LIST_QEUE_STAK_LIST_H
#include"../lib_list/list.h"

template <class T>
class Stack_list {
	List<T> _data;

public:
	Stack_list();
	Stack_list(const Stack_list<T>&);

	bool SLempty() const noexcept;

	void SLpush(const T&);
	void SLpop();
	void SLclear();

	T& SLtop();
	const T& SLtop() const;
};

template<class T>
Stack_list<T>::Stack_list() {}

template<class T>
Stack_list<T>::Stack_list(const Stack_list<T>& A) : _data(A._data) {}

template<class T>
bool Stack_list<T>::SLempty() const noexcept {
	return _data.is_empty();
}

template<class T>
void Stack_list<T>::SLpush(const T& val) {
	_data.push_front(val);
}

template<class T>
void Stack_list<T>::SLpop() {
	_data.pop_front();
}

template<class T>
void Stack_list<T>::SLclear() {
	while (!_data.is_empty()) 
		_data.pop_front();
}

template<class T>
T& Stack_list<T>::SLtop() {
	if (_data.is_empty()) 
		throw std::logic_error("Stack is empty");
	else {
		typename List<T>::Iterator it = _data.begin();
		return *it;
	}
}

template<class T>
const T& Stack_list<T>::SLtop() const {
	if (_data.is_empty()) 
		throw std::logic_error("Stack is empty");
	else {
		typename List<T>::Iterator it = _data.begin();
		return *it;
	}
}
#endif // !LIB_STAK_LIST_QEUE_STAK_LIST_H
