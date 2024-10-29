// Copyright 2024 Urin Oleg

#ifndef LIB_TMATRIX
#define LIB_TMATRIX

#include "../lib_vector/TVector.h"

#pragma once
#define STEP_CAPACITY 15

#include <utility>
#include <stdexcept>
#include <iostream>

template <class T> class TUpperTriangularMatrix;
template <class T> std::ostream& operator<<(std::ostream& out, const TUpperTriangularMatrix<T>& m);

template<class T>
class TUpperTriangularMatrix : TVector<TVector<T>> {
private:
    using TVector<TVector<T>>::_values;
    using TVector<TVector<T>>::_start_index;
public:
    using TVector<TVector<T>>::operator[];
    using TVector<TVector<T>>::operator=;
    TUpperTriangularMatrix(size_t size = STEP_CAPACITY);
   

    TUpperTriangularMatrix(T const* const* arr, size_t size);
       

    TUpperTriangularMatrix(const TUpperTriangularMatrix& m);
    TUpperTriangularMatrix(const TVector<TVector<T>>& m);
    ~TUpperTriangularMatrix();

    size_t size() const;
};

TUpperTriangularMatrix(size_t size = STEP_CAPACITY) : TVector<TVector<T>>(size) {
    for (size_t i = 0; i < size; i++) {
        _values[i] = TVector<T>(size - i, i);
    }
}

TUpperTriangularMatrix(T const* const* arr, size_t size) : TVector<TVector<T>>(size) {
    for (size_t i = 0; i < size; i++) {
        _values[i] = TVector<T>(size - i, i);
        for (size_t j = 0; j < size - i; j++) {
            _values[i][j + i] = arr[i][j + i];
        }
    }
}

TUpperTriangularMatrix(const TUpperTriangularMatrix& m) : TVector<TVector<T>>(m) {}
TUpperTriangularMatrix(const TVector<TVector<T>>& m) : TVector<TVector<T>>(m) {}
~TUpperTriangularMatrix() {}

size_t size() const { return _values.size(); }

#endif  // LIB_TMATRIX