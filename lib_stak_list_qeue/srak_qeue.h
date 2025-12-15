#ifndef LIB_STAK_LIST_QEUE_QEUE_LIST_H
#define LIB_STAK_LIST_QEUE_QEUE_LIST_H
#include"../lib_list/list.h"

template<class T>
class Qeue_list {
	size_t _col;
	List<T> _data;
	typename List<T>::iterator end;
	typename List<T>::iterator start;

public:
	Qeue_list(int size = 6);
	~Qeue_list();
	const T& begin() const;
	const T& ending() const;
	T& begin();
	T& ending();
	const size_t get_count() const noexcept;
	void push(const T&);
	void pop();
	const bool isEmpty() const noexcept;
	const bool isFull() const noexcept;
};

template <class T>
Qeue_list<T>::Qeue_list(int size) : _col(0), _data(){
	if (size < 0)
		throw std::logic_error("size < 0");

	for (int i = 0; i < size; i++)
		_data.push_front(0);

	start = _data.end();
	end = _data.begin();
	_data.ñreate_ring();
}

template <class T>
Qeue_list<T>::~Qeue_list() {}

template <class T>
const size_t Qeue_list<T>::get_count() const noexcept {
	return _col;
}

template <class T>
const bool Qeue_list<T>::isEmpty() const noexcept {
	return _col == 0;
}

template <class T>
const bool Qeue_list<T> ::isFull() const noexcept {
	return _data.get_count() == _col;
}

template <class T>
void Qeue_list<T>::push(const T& val) {
	if (isFull()) 
		throw std::logic_error("queue overflow");
	
	else {
		start++;
		*start = val;
		_col++;
	}
}

template <class T>
void Qeue_list<T>::pop() {
	if (isEmpty()) {
		throw std::logic_error("you cannot delete from an empty queue");
	}
	else {
		end++;
		_col--;
	}
}

template <class T>
const T& Qeue_list<T>::begin() const {
	if (isEmpty())
		throw std::logic_error("Qeue_list is empty");
	else
		return *start;
}

template <class T>
T& Qeue_list<T>::begin(){
	if (isEmpty())
		throw std::logic_error("Qeue_list is empty");
	else
		return *start;
}

template <class T>
const T& Qeue_list<T>::ending() const {
	if (isEmpty())
		throw std::logic_error("Qeue_list is empty");
	else
		return *end;
}

template <class T>
T& Qeue_list<T>::ending(){
	if (isEmpty())
		throw std::logic_error("Qeue_list is empty");
	else
		return *end;
}
#endif // !LIB_STAK_LIST_QEUE_QEUE_LIST_H
