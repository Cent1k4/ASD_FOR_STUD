#pragma once
#include "../lib_list/list.h"

template<class T>
class DoubleList : public List<T> {
public:
	DoubleList();
	void pop_front() override;
	void push_front(const T& val) noexcept override;
	void pop_back() override;
	virtual void insert(int, const T&);
	void push_back(const T& val) noexcept override;
	virtual void insert(Node<T>* A, const T&);
};


template<class T>
DoubleList<T>::DoubleList() : List<T>() {}

template<class T>
void DoubleList<T>::pop_front() {
	List<T>::pop_front();
	if (this->_head != nullptr)
		this->_head->_prev = nullptr;
}

template<class T>
void DoubleList<T>::push_front(const T& val)noexcept {
	List<T>::push_front(val);
	if (this->_head != this->_tail)
		this->_head->_next->_prev = _head;
}

template<class T>
void DoubleList<T>::pop_back() {
	if (this->is_empty())
		throw std::logic_error("list is empty");

	Node<T>* tmp = this->_tail;

	if (this->_head == this->_tail) {
		this->_head = nullptr;
		this->_tail = nullptr;
	}
	else {
		this->_tail = this->_tail->_prev;
		this->_tail->_next = nullptr;
	}
	count--;
	delete tmp;
}


template<class T>
void DoubleList<T>::push_back(const T& val) noexcept {
	Node<T>* A = new Node<T>(val, nullptr);
	if (this->is_empty())
		_head = A;

	else {
		this->_tail->_next = A;
		A->_prev = this->_tail;
	}
	this->_tail = A;
	this->count++;
}


template<class T>
void DoubleList<T>::insert(int pos, const T& val) {
	Node<T>* A = _head;
	if (pos == 0) {
		push_front(val);
	}

	else if (this->is_empty())
		throw std::logic_error("list is empty");

	else if (pos == this->count)
		push_back(val);

	else {
		while (pos != 1 && A->_next != nullptr) {
			A = A->_next;
			pos--;
		}

		if (pos == 1) {
			Node<T>* B = new Node<T>(val, A->_next, A);
			A->_next = B;
			count++;
		}
		else
			throw std::logic_error("element not found");
	}
}

template<class T>
void DoubleList<T>::insert(Node<T>* A, const T& val) {
	
	Node<T>* nextNode = A->_next;

	List<T>::insert(A, val);

	if (nextNode != nullptr) 
		nextNode->_prev = A->_next;

	A->_next->_prev = A;
}