// Copyright 2024 Urin Oleg

#include "../lib_dmassive/DMassive.h"

#ifndef LIB_TVector
#define LIB_TVector

#pragma once
#define STEP_CAPACITY 15
#include <utility>
#include <stdexcept>
#include <iostream>

template <typename T>
class TVector{
	TArchive _data
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

};

template <typename T>
TVector<T>::TVector():_data() _start_index(0){
}

template <typename T>
TVector<T>::TVector(const TVector& other) : _data(other._data) _start_index(0){}

template <typename T>
TVector<T>::TVector(const T* arr, size_t n) : _data(arr, n) _start_index(0) {}

template <typename T>
TVector<T>::TVector(size_t n, T value) : _data(n, value) _start_index(0) {}

template <typename T>
TVector<T>::~TVector() {}


#endif  // LIB_TVector