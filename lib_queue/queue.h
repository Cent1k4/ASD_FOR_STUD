
#ifndef LIB_QUEUE_QUEUE_H_
#define LIB_QUEUE_QUEUE_H_
#include <iostream>

template <class T>
class Queue
{
	T* _data;
	size_t _front, _count, _size;
	size_t get_back_index() const;
public:
	Queue(size_t col = 10);
	~Queue();
	T& front() const;
	size_t get_count() const noexcept;
	void push(const T&);
	void pop();
	bool isEmpty() const noexcept;
	bool isFull() const noexcept;
};

template <class T>
Queue<T>::Queue(size_t col) : _size(col), _data(new T[col]), _front(0), _count(0){}

template <class T>
Queue<T>::~Queue() {
	delete[] _data;
}

template <class T>
size_t Queue<T>::get_count() const noexcept {
	return _count;
}

template <class T>
size_t Queue<T>::get_back_index() const {
	if (isEmpty()) {
		return 0;
	}
	return (_front + _count) % _size;
}

template <class T>
bool Queue<T>::isEmpty() const noexcept {
	return _count == 0;
}

template <class T>
bool Queue<T> ::isFull() const noexcept {
	return _count == _size;
}

template <class T>
void Queue<T>::push(const T& val) {
	if (isFull()) {
		throw std::logic_error("queue overflow");
	}
	else {
		_data[get_back_index()] = val;
		_count++;
	}
}

template <class T>
void Queue<T>::pop() {
	if (isEmpty()) {
		throw std::logic_error("you cannot delete from an empty queue");
	}
	else {
		_front = (_front + 1) % _size;
		_count--;
	}
}

template <class T>
T& Queue<T>::front() const {
	if (isEmpty())
		throw std::logic_error("Queue is empty");
	else
		return _data[_front];
}

#endif // LIB_QUEUE_QUEUE_H_