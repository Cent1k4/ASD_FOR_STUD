// Copyright 2024 Marina Usova

#ifndef LIB_EASY_EXAMPLE_EASY_EXAMPLE_H_
#define LIB_EASY_EXAMPLE_EASY_EXAMPLE_H_

#include <stdexcept>

template<class T>
class Stack {
	T* _data;
	int _size;
	int _top;

public:
	Stack();
	Stack(int size);
	Stack(const Stack<T>&);

	bool empty() const noexcept;
	bool full() const noexcept;

	inline int get_size() const noexcept;

	void push(const T&);
	void pop();
	void clear();

	T& top();
	const T& top() const;
};

template<class T>
Stack<T>::Stack() : _top(-1), _size(0), _data(nullptr) {}

template<class T>
Stack<T>::Stack(int size) : _top(-1), _size(size), _data(new T[size]){}

template<class T>
void Stack<T>::clear() {
	_size = 0;
	_top = -1;
	delete[] _data;
}

template<class T>
Stack<T>::Stack(const Stack<T>& A) {
	clear();
	_size = A._size;
	_top = A._top;
	for (int i = 0; i < _size; i++)
		_data[i] = A._data[i];
}

template<class T>
bool Stack<T>::empty() const noexcept {
	return (-1 == _top);
}

template<class T>
bool Stack<T>::full() const noexcept {
	return (_size - 1 == _top);
}

template<class T>
inline int Stack<T>::get_size() const noexcept {
	return _size;
}

template<class T>
void Stack<T>::push(const T& A) {
	if (!full())
		_data[++_top] = A;

	else
		throw std::logic_error(" overflow");
}

template<class T>
void Stack<T>::pop() {
	if (!empty())
		--_top;
	else
		throw std::logic_error(" overflow");
}

template<class T>
T& Stack<T>::top() {
	if (empty())
		throw std::logic_error("stack empty");
	return _data[_top];
}

template<class T>
const T& Stack<T>::top() const{
	if (empty())
		throw std::logic_error("stack empty");
	return _data[_top];
}
#endif  // LIB_EASY_EXAMPLE_EASY_EXAMPLE_H_