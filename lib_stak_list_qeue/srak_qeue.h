#ifndef LIB_STAK_LIST_QEUE_QEUE_LIST_H
#define LIB_STAK_LIST_QEUE_STAK_QEUE_H
#include"../lib_list/list.h"


template<class T>
class Qeue_list {
	size_t _front, _count, _size;
	size_t get_back_index() const;
	List<T> _data;
public:
	Qeue_list();
	~Qeue_list();
	T& front() const;
	size_t get_count() const noexcept;
	void push(const T&);
	void pop();
	bool isEmpty() const noexcept;
	bool isFull() const noexcept;
};

template <class T>
Qeue_list<T>::Qeue_list() : _size(col), _data(), _front(0), _count(0) {}

template <class T>
Qeue_list<T>::~Qeue_list() {}

template <class T>
size_t Qeue_list<T>::get_count() const noexcept {
	return _count;
}

template <class T>
size_t Qeue_list<T>::get_back_index() const {
	if (isEmpty()) {
		return 0;
	}
	return (_front + _count) % _size;
}

template <class T>
bool Qeue_list<T>::isEmpty() const noexcept {
	return _count == 0;
}

template <class T>
bool Qeue_list<T> ::isFull() const noexcept {
	return _count == _size;
}

template <class T>
void Qeue_list<T>::push(const T& val) {
	if (isFull()) {
		throw std::logic_error("queue overflow");
	}
	else {
		_data.insert(get_back_index, val);
		_count++;
	}
}

template <class T>
void Qeue_list<T>::pop() {
	if (isEmpty()) {
		throw std::logic_error("you cannot delete from an empty queue");
	}
	else {
		_front = (_front + 1) % _size;
		_count--;
	}
}

template <class T>
T& Qeue_list<T>::front() const {
	if (isEmpty())
		throw std::logic_error("Qeue_list is empty");
	else
		return _data.front();
}
#endif // !LIB_STAK_LIST_QEUE_QEUE_LIST_H
