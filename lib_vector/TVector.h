// Copyright 2024 Urin Oleg

#ifndef LIB_TVector
#define LIB_TVector

#include "../lib_dmassive/dmassive.h"

#pragma once
#define STEP_CAPACITY 15

#include <utility>
#include <stdexcept>
#include <iostream>

template <typename T>
class TVector{
    TArchive<T> _data;
	size_t _start_index;

public:
    TVector();
    TVector(const TVector& other);
    TVector(const T* arr, size_t n);
    TVector(size_t n, T value);
    ~TVector();

    bool empty() const noexcept;
    size_t size() const;
    size_t capacity() const;
    void clear();
    void reserve(size_t n);
    void resize(size_t n, T value);
    void push_back(T value);
    void pop_back();
    void push_front(T value);
    void pop_front();
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    void insert(size_t pos, T value);
    void erase(size_t pos, size_t n);
    void remove_all(T value);
    void remove_first(T value);
    void remove_last(T value);
    size_t find_first(T value);
    size_t find_last(T value);
    void print() const noexcept;

    TVector operator+(const TVector<T>& rhs);
};

template <typename T>
TVector<T> TVector<T>::operator+(const TVector<T>& rhs) {

    if (this->size() != rhs.size()) {
        throw std::logic_error("Vectors have not equal lenths");
    }

    TVector<T> res(rhs.size(), 0);

    for (int i = 0; i < rhs.size(); i++) {
        res[i] = (*this)[i] + rhs[i];
    }

    return res;
}

template <typename T>
TVector<T>::TVector():_data() _start_index(0){
}

template <typename T>
TVector<T>::TVector(const TVector& other) : _data(other._data), _start_index(0){}

template <typename T>
TVector<T>::TVector(const T* arr, size_t n) : _data(arr, n), _start_index(0) {}

template <typename T>
TVector<T>::TVector(size_t n, T value) : _data(n, value), _start_index(0) {}

template <typename T>
TVector<T>::~TVector() {}

template <typename T>
bool TVector<T>::empty() const noexcept {
    return _data.empty();
}

template <typename T>
size_t TVector<T>::size() const {
    return _data.size();
}

template <typename T>
size_t TVector<T>::capacity() const {
    return _data.capacity();
}

template <typename T>
void TVector<T>::clear() {
    _start_index = 0;
    _data.clear();
}

template <typename T>
void TVector<T>::reserve(size_t n) {
    _data.reserve(n);
}

/*mplate <typename T>
void TVector<T>::resize(size_t n, T value) {
    _data.resize(n, value);
}*/

template <typename T>
void TVector<T>::push_back(T value) {
    _data.push_back(value);
}

template <typename T>
void TVector<T>::pop_back() {
    _data.pop_back();
}

template <typename T>
void TVector<T>::push_front(T value) {
    _data.push_front(value);
    _start_index = _data[0];
}

template <typename T>
void TVector<T>::pop_front() {
    _data.pop_front();
    _start_index = _data[0];
}

template <typename T>
T& TVector<T>::operator[](size_t index) {
    if (index >= _data.size()) {
        throw std::out_of_range("Index out of range");
    }
    return const_cast<T&>(_data.data()[index]);
}

template <typename T>
const T& TVector<T>::operator[](size_t index) const {
    if (index >= _data.size()) {
        throw std::out_of_range("Index out of range");
    }
    return _data.data()[index];
}

template <typename T>
void TVector<T>::insert(size_t pos, T value) {
    _data.insert(value, pos);
    if (pos == 0) {
        _start_index = _data[0];
    }
}

template <typename T>
void TVector<T>::erase(size_t pos, size_t n) {
    _data.erase(pos, n);
    if (pos == 0) {
        _start_index = _data[0];
    }
}

template <typename T>
void TVector<T>::remove_all(T value) {
    _data.remove_all(value);
    _start_index = 0;
}

template <typename T>
void TVector<T>::remove_first(T value) {
    _data.remove_first(value);
    _start_index = _data[0];
}

template <typename T>
void TVector<T>::remove_last(T value) {
    _data.remove_last(value);
}

template <typename T>
size_t TVector<T>::find_first(T value) {
    return _data.find_first(value);
}

template <typename T>
size_t TVector<T>::find_last(T value) {
    return _data.find_last(value);
}

template <typename T>
void TVector<T>::print() const noexcept {
    _data.print();
}
#endif  // LIB_TVector