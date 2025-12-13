#ifndef LIB_TVECTOR_TVECTOR_H
#define LIB_TVECTOR_TVECTOR_H

#pragma once
#include <iostream>
#include <math.h>


template <class  T> class TVector;
template <class T> std::ostream& operator<<(std::ostream& out, const TVector<T>& dmass);

template <class  T> class TVector;
template <class  T>std::istream& operator>>(std::istream& is, TVector<T>& dmass);

template <class T>
class TVector {

protected:
    T* _data;
    size_t _capacity;
    size_t _size;

public:
    TVector();
    TVector(const TVector& other);
    TVector(const T* arr, size_t n, bool flage = true);
    TVector(size_t n, bool flag = true);
    TVector(const std::initializer_list <T> data, bool flaf = true);
    ~TVector();

    inline size_t get_capacity() const noexcept;
    inline size_t get_size()const noexcept;
    inline T* get_data()const noexcept;

    void push_front(T val);
    void push_back(T val);
    void insert(size_t pos, T val);
    void insert(T* pos, T val);
    void regruping();
    void clear();
    bool full()const noexcept;

    T pop_back();
    T pop_front();
    TVector<T> erase(size_t pos, size_t col = 1);
    TVector<T> erase(T* pos, size_t col = 1);

    T& front() noexcept;
    T& back() noexcept;
    const T& front() const noexcept;
    const T& back() const noexcept;

    size_t find(T Val) const;

    TVector& operator=(const TVector& other);

    T& operator[](size_t pos);
    const T& operator[](size_t pos) const;

    friend std::ostream& operator <<<T>(std::ostream& out, const TVector<T>& dmass);
    friend std::istream& operator >><T>(std::istream& is, TVector<T>& dmass);
};


template <class T>
TVector<T>::TVector() : _size(0), _capacity(0), _data(nullptr) {}


template <class T>
TVector<T>::TVector(const TVector<T>& other) : _size(other._size), _capacity(other._capacity), _data(new T[other._capacity]) {
    for (int i = 0; i < _size; i++)
        _data[i] = other._data[i];
}

template <class T>
TVector<T>::TVector(const T* arr, size_t n, bool flage) : _size(n), _capacity(n + 15 - (n % 15)) {
    if (n > 0) {
        if (!flage)
            _capacity = n;

        else
            _capacity = (n + 15 - (n % 15));

        _data = new T[_capacity];
        if (arr != nullptr) {
            for (size_t i = 0; i < n; i++)
                _data[i] = arr[i];
        }
    }
    else
        throw std::logic_error("Нельязя массив с 0 элементами");
}

template<class T>
TVector<T>::TVector(size_t n, bool flage) : _size(n) {
    if (n > 0) {
        if (!flage)
            _capacity = n;

        else
            _capacity = (n + 15 - (n % 15));

        _data = new T[_capacity];
        for (size_t i = 0; i < _size; i++)
            _data[i] = T();
    }
    else
        throw std::logic_error("Нельязя массив с 0 элементами");
}

template<class T>
TVector<T>::TVector(const std::initializer_list <T> data, bool flag) : _size(data.size()) {
    if (_size > 0) {
        if (!flag)
            _capacity = _size;

        else
            _capacity = (data.size()) + 15 - ((data.size()) % 15);

        _data = new T[_capacity];
        auto t = data.begin();
        for (size_t i = 0; i < _size && t != data.end(); i++, t++)
            _data[i] = *t;
    }
    else
        throw std::logic_error("Нельязя массив с 0 элементами");
}

template<class T>
TVector<T>::~TVector() {
    clear();
}

template<class T>
void TVector<T>::clear() {
    if (_data != nullptr) {
        delete[] _data;
        _data = nullptr;
    }
    _size = 0;
    _capacity = 0;
}

template<class T>
bool TVector<T>::full() const noexcept {
    if (_size == _capacity)
        return true;
    return false;
}

template<class T>
inline size_t TVector<T>::get_capacity() const noexcept {
    return _capacity;
}

template<class T>
inline size_t TVector<T>::get_size() const noexcept {
    return _size;
}

template<class T>
inline T* TVector<T>::get_data()const noexcept {
    return _data;
}

template<class T>
void TVector<T>::regruping() {
    _capacity = _size + 15 - (_size % 15);
    T* data = new T[_capacity];
    for (int i = 0; i < _size; i++)
        data[i] = _data[i];

    delete[] _data;
    _data = data;
}

template<class T>
void TVector<T>::push_front(T val) {
    if (full())
        regruping();
    for (size_t i = _size; i > 0; i--)
        _data[i] = _data[i - 1];
    _data[0] = val;
    _size++;
}

template<class T>
void TVector<T>::push_back(T val) {
    if (!full())
        _data[_size] = val;
    else {
        regruping();
        _data[_size] = val;
    }
    _size++;
}

template<class T>
void TVector<T>::insert(size_t pos, T val) {
    if (pos <= _size) {
        if (full())
            regruping();

        for (size_t i = _size; i > pos - 1; i--)
            _data[i] = _data[i - 1];
        _data[pos - 1] = val;
        _size++;
    }
    else
        throw std::logic_error("Выход за границы");
}

template<class T>
void TVector<T>::insert(T* pos, T val) {
    size_t pos_index = pos - _data - 1;
    if (pos >= _data && pos <= _data + _size) {
        if (full())
            regruping();

        for (size_t i = _size; i > pos_index; i--)
            _data[i] = _data[i - 1];
        _data[pos_index] = val;
        _size++;
    }
    else
        throw std::logic_error("Выход за границы");
}

template<class T>
T TVector<T>::pop_back() {
    T pop = _data[_size - 1];
    _size--;
    if (_size % 15 == 14)
        regruping();
    return pop;
}

template<class T>
T TVector<T>::pop_front() {
    T pop = _data[0];
    for (size_t i = 0; i < _size - 1; i++)
        _data[i] = _data[i + 1];
    --_size;
    if (_size % 15 == 14)
        regruping();
    return pop;
}

template<class T>
TVector<T> TVector<T>::erase(size_t pos, size_t col)
{
    if (col == 0 || pos + col >= _size)
        throw std::logic_error("выход за границы");

    TVector<T> pop(col);
    size_t j = 0;

    for (size_t i = pos - 1; i < _size - col + 1; i++) {
        pop.push_back(_data[i]);
        _data[i] = _data[i + col];
    }
    _size -= col;
    if (_size % 15 == 14)
        regruping();
    return pop;
}

template<class T>
TVector<T> TVector<T>::erase(T* pos, size_t col)
{
    size_t pos_index = pos - _data;
    if (col == 0 || pos_index + col > _size)
        throw std::logic_error("выход за границы");

    TVector<T> pop(col);
    size_t j = 0;

    for (size_t i = pos_index - 1; i < _size - col + 1; i++) {
        pop.push_back(_data[i]);
        _data[i] = _data[i + col];
    }

    _size -= col;
    if (_size % 15 == 14)
        regruping();
    return pop;
}

template<class T>
T& TVector<T>::front() noexcept {
    return _data[0];
}

template<class T>
T& TVector<T>::back() noexcept {
    return _data[_size - 1];
}

template<class T>
const T& TVector<T>::front() const noexcept {
    return _data[0];
}

template<class T>
const T& TVector<T>::back() const noexcept {
    return _data[_size - 1];
}

template<class T>
size_t TVector<T>::find(T Val) const {
    for (size_t i = 0; i < _size; i++)
    {
        if (_data[i] == Val)
            return i + 1;
    }
    throw  std::runtime_error("Value not found");
}

template<class T>
TVector<T>& TVector<T>::operator=(const TVector<T>& other) {
    if (this == &other)
        return *this;

    if (_data != nullptr)
        delete[] _data;

    _size = other._size;
    _capacity = other._capacity;
    _data = new T[_capacity];
    for (size_t i = 0; i < _size; i++)
        _data[i] = other._data[i];
    return *this;
}

template<class T>
T& TVector<T>::operator[](size_t pos) {
    if (pos > _size)
        throw std::out_of_range("Index out of bounds");

    return _data[pos - 1];
}

template<class T>
const T& TVector<T>::operator[](size_t pos) const {
    if (pos > _size)
        throw std::out_of_range("Index out of bounds");

    return _data[(pos - 1)];
}

template <class T>
std::ostream& operator << <T>(std::ostream& out, const TVector<T>& dmass) {
    for (size_t i = 0; i < dmass._size; i++) {
        out << dmass[i] << " ";
    }
    out << std::endl;
    return out;
}

template <class T>
std::istream& operator >> <T> (std::istream& is, TVector<T>& dmass) {

    for (size_t i = 0; i < dmass._size; i++) {
        std::cout << i << " array_element" << std::endl;
        is >> dmass._data[i];
    }
    return is;
}
#endif // !LIB_TVECTOR_TVECTOR_H
