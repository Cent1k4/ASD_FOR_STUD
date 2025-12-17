#ifndef LIB_LIST_LIST_H
#define LIB_LIST_LIST_H
#include <iostream>


template<class T>
struct Node {
	T _val;
	Node* _next;
	Node(const T, Node<T>*);
};

template<class T>
Node<T>::Node(const T val, Node<T>* next) : _val(val), _next(next) {}


template <class T>
class List
{
	Node<T> *_head, *_tail;
	size_t count;
public:
	List();
	List(const List&);
	~List();

	const size_t get_count() const noexcept;
	bool is_empty() const;
	int find_pos(const T&);
	Node<T>* find_nod(const T&);
	void ñreate_ring();
	void pop_front();
	void push_front(const T&) noexcept;
	void pop_back();
	void push_back(const T&) noexcept;
	void erase(int);
	void insert(int, const T&);
	void erase(Node<T>* A);
	void insert(Node<T>* A, const T&);
	bool har_turtle();
	Node<T>* hasCycleReverse();
	void List<T>::restoreFrom(Node<T>*);
	const T& operator [](size_t) const;
	T& operator [](size_t);

	class Iterator {
		Node<T>* _current;
	public:
		Iterator();
		Iterator(Node<T>* poc);
		Iterator(const Iterator& A);

		Iterator& operator =(const Iterator& A);
		T& operator*();
		bool operator != (const Iterator& A);
		bool operator == (const Iterator& A);
		Iterator operator ++(int);
		Iterator operator ++();
	};

	Iterator begin() { return Iterator(_head); }
	Iterator end() { return Iterator(_tail); }
	typedef Iterator iterator;
};

template<class T>
List<T>::Iterator::Iterator() : _current(nullptr) {}

template<class T>
List<T>::Iterator::Iterator(Node<T>* poc) : _current(poc) {}

template<class T>
List<T>::Iterator::Iterator(const Iterator& A) : _current(A._current) {}

template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator =(const Iterator& A) {
	this->_current = A._current;
	return (*this);
}

template<class T>
T& List<T>::Iterator::operator*() {
	return _current->_val;
}

template<class T>
bool List<T>::Iterator::operator != (const Iterator& A) {
	return _current != A._current;
}

template<class T>
bool List<T>::Iterator::operator == (const Iterator& A) {
	return _current == A._current;
}

template<class T>
typename List<T>::Iterator List<T>::Iterator::operator ++(int) {
	Iterator tmp(*this);
	_current = _current->_next;
	return tmp;
}

template<class T>
typename List<T>::Iterator List<T>::Iterator::operator ++() {
	_current = _current->_next;
	return (*this);
}

template<class T>
bool List<T>::har_turtle(){
	if (is_empty()) return false; 

	typename List<T>::Iterator tortoise = begin();
	typename List<T>::Iterator hare = begin();

	while (hare !=  nullptr) {
		++tortoise;
		++hare;

		if (hare == nullptr)
			break;
		++hare;

		if (tortoise == hare) 
			return true;
		
	}
	return false;
}

//template<class T>
//Node<T>* List<T>::hasCycleReverse() {
//	if (!_head || !_head->_next) 
//return false;
//
//	Node<T>* prev = nullptr;
//	List<int>::Iterator it = begin();
//	Node<T>* Point = nullptr;
//	Node<T>* start_reverse = nullptr;
//
//	while (it != end()) {
//		Node<T>* current = it._current;
//
//		if (current->_next == prev && prev != nullptr) {
//			Point = current;
//			restoreFrom(start_reverse);
//			return Point;
//		}
//
//		Node<T>* next = current->_next;
//		current->_next = prev;
//
//		if (!start_reverse) 
//			start_reverse = current;
//		
//		if (next) {
//			it = Iterator(next);
//			prev = current;
//		}
//
//		else 
//			break;
//	}
//	if (start_reverse) 
//		restoreFrom(start_reverse);
//	
//	return nullptr;
//}
//
//template<class T>
//void List<T>::restoreFrom(Node<T>* start) {
//	if (!start) return;
//
//	Node<T>* current = start;
//	Node<T>* prev = nullptr;
//
//	while (current) {
//		Node<T>* temp = current->_next;
//		current->_next = prev;
//		prev = current;
//		current = temp;
//	}
//}

template<class T>
const size_t List<T>::get_count() const noexcept {
	return count;
}

template<class T>
void List<T>::ñreate_ring() {
	_tail->_next = _head;
}

template<class T>
T& List<T>::operator [](size_t pos) {
	Node<T>* A = _head;
	while (pos != 0 && A->_next != nullptr) {
		A = A->_next;
		pos--;
	}
	if (pos == 0)
		return A->_val;
	else
		throw std::logic_error("element not found");
}

template<class T>
const T& List<T>::operator [](size_t pos) const {
	Node<T>* A = _head;
	while (pos != 0 && A->_next != nullptr) {
		A = A->_next;
		pos--;
	}
	if (pos == 0)
		return A->_val;
	else
		throw std::logic_error("element not found");
}

template<class T>
List<T>::List() : _head(nullptr), _tail(nullptr), count(0) {}

template<class T>
List<T>::List(const List& A){
	_head = nullptr;
	_tail = nullptr;
	Node<T> *tmp = A._head;
	while (tmp != nullptr) {
		push_back(tmp->_val);
		tmp = tmp->_next;
	}
}

template<class T>
List<T>::~List(){
	if (_tail && _tail->_next == _head) {
		_tail->_next = nullptr;
	}

	while (!is_empty()) {
		Node<T>* tmp = _head;
		_head = _head->_next;
		delete tmp;
	}
}

template<class T>
bool List<T>::is_empty() const{
	return _head == nullptr;
}

template<class T>
void List<T>::pop_front() {
	if (is_empty())
		throw std::logic_error("list is empty");
	Node<T>* tmp = _head;
	_head = _head->_next;

	if (is_empty()) {
		_tail = nullptr;
	}
	count--;
	delete tmp;
}

template<class T>
void List<T>::push_front(const T& val) noexcept {
	Node<T>* A = new Node<T>(val, _head);
	if (is_empty())
		_tail = A;
	_head = A;
	count++;
}


template<class T>
void List<T>::pop_back(){
	if (is_empty())
		throw std::logic_error("list is empty");
	Node<T>* tmp = _head;

	if (_head == _tail) {
		_head = nullptr;
		_tail = nullptr;
	}
	else {
		while (tmp->_next != _tail)
			tmp = tmp->_next;

		_tail = tmp;
		tmp = tmp->_next;
		_tail->_next = nullptr;
	}
	count--;
	delete tmp;
}


template<class T>
void List<T>::push_back(const T& val) noexcept {
	Node<T>* A = new Node<T>(val, nullptr);
	if (is_empty())
		_head = A;

	else
		_tail->_next = A;
	_tail = A;
	count++;
}


template<class T>
void List<T>::erase(int pos) {
	Node<T>* A = _head;
	if (is_empty())
		throw std::logic_error("list is empty");

	else if (pos == 0) {
		pop_front();
	}

	else if (pos == count - 1)
		pop_back();

	else {
		while (pos != 1 && A->_next != nullptr) {
			A = A->_next;
			pos--;
		}

		if (pos == 1) {
			Node<T>* B = A->_next;
			A->_next = B->_next;
			count--;
			delete B;
		}
		else
			throw std::logic_error("overrun");
	}
}


template<class T>
void List<T>::insert(int pos, const T& val) {
	Node<T>* A = _head;
	if (pos == 0) {
		push_front(val);
	}

	else if (is_empty())
		throw std::logic_error("list is empty");

	else if (pos == count)
		push_back(val);

	else{
		while (pos != 1 && A->_next != nullptr) {
			A = A->_next;
			pos--;
		}

		if (pos == 1) {
			Node<T>* B = new Node<T>(val, A->_next);
			A->_next = B;
			count++;
		}
		else
			throw std::logic_error("element not found");
	}
}


template<class T>
void List<T>::erase(Node<T>* A) {
	if (A == nullptr)
		throw std::logic_error("A = nullptr");
	Node<T>* B = _head;

	if (is_empty())
		throw std::logic_error("list is empty");

	else if (A == _head)
		pop_front();

	else if (A == _tail)
		pop_back();

	else {
		while (B->_next != A && B->_next != nullptr)
			B = B->_next;
		

		if (B->_next == A) {
			B->_next = A->_next;
			count--;
			delete A;
		}
		else
			throw std::logic_error("overrun");
	}
}


template<class T>
void List<T>::insert(Node<T>* A, const T& val) {
	if (is_empty())
		throw std::logic_error("list is empty");
	if (A == nullptr)
		throw std::logic_error("A = nullptr");
	if (A == _tail)
		push_back(val);
	else {
		Node<T>* B = new Node<T>(val, A->_next);
		A->_next = B;
		count++;
	}
}

template<class T>
int List<T>::find_pos(const T& val) {
	if (is_empty())
		throw std::logic_error("list is empty");

	size_t i = 0;
	Node<T>* B = _head;
	while (B->_val != val && B->_next != nullptr) {
		B = B->_next;
		i++;
	}
	if (B->_val == val)
		return i;
	else {
		std::cout << "element not find" << std::endl;
		return -1;
	}
}

template<class T>
Node<T>* List<T>::find_nod(const T&) {
	if (is_empty())
		throw std::logic_error("list is empty");

	size_t i = 0;
	Node<T>* B = _head;
	while (B->_val != val && B->_next != nullptr) {
		B = B->_next;
		i++;
	}
	if (B->_val == val)
		return B;
	else {
		std::cout << "element not find" << std::endl;
		return nullptr;
	}
}

#endif // !LIB_LIST_LIST_H