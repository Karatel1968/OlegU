// Copyright 2024 Urin Oleg


#ifndef LIB_DMASSIVE
#define LIB_DMASSIVE

#pragma once
#define STEP_CAPACITY 15
#include <utility>
#include <stdexcept>
#include <iostream>

enum State { empty, busy, deleted };

namespace algorithms {
    template<typename T>
    inline void swap(T& val_1, T& val_2) noexcept {
        T tmp = val_1;
        val_1 = val_2;
        val_2 = tmp;
    }
}

template <typename T>
class TArchive {
    T* _data;
    State* _states;
    size_t _capacity;
    size_t _size;
    size_t _deleted;

     public:
    TArchive(); // +
    TArchive(const TArchive& archive); // +
    TArchive(const T* arr, size_t n); // +


    TArchive(size_t n, T value);
    // TArchive(const TArchive& archive, size_t pos, size_t n);


    ~TArchive();

    void print() const noexcept;

    inline bool empty() const noexcept; // +
    inline bool full() const noexcept; // +


    size_t size() const noexcept; // +
    size_t capacity() const noexcept; // +
    const T* data() const; // +

    void swap(TArchive& archive); // +
    // TArchive& assign(const TArchive& archive);
    inline void clear(); // +
    void resize(size_t n, T value); // !
    void reserve(size_t n); // +
    void push_back(T value); // +
    void pop_back(); // +
    void push_front(T value); // +
    void pop_front();

    // TArchive& insert(const T* arr, size_t n, size_t pos);


    TArchive& insert(T value, size_t pos);


    // TArchive& replace(size_t pos, T new_value);

    // TArchive& erase(size_t pos, size_t n);
    // TArchive& remove_all(T value);
    // TArchive& remove_first(T value);
    // TArchive& remove_last(T value);
    // TArchive& remove_by_index(size_t pos);

    // size_t* find_all(T value) const noexcept;
    // size_t find_first(T value);
    // size_t find_last(T value);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    private:
    // size_t count_value(T value);
};

template <typename T>
void TArchive<T>::pop_front() {
    if (_size == 0) {
        throw std::out_of_range("Архив пустой");
    }

    for (size_t i = 0; i < _size - 1; ++i) {
        _data[i] = _data[i + 1];
        _states[i] = _states[i + 1];
    }

    _states[_size - 1] = State::empty;

    _size--;
}

template <typename T>
void TArchive<T>::push_front(T value) {
    if (_size == _capacity) {
        reserve(_capacity + ((_capacity * 25) / 100));
    }

    for (size_t i = _size; i > 0; --i) {
        _data[i] = _data[i - 1];
        _states[i] = _states[i - 1];
    }

    _data[0] = value;
    _states[0] = State::busy;

    _size++;
}

template <typename T>
void TArchive<T>::pop_back() {
    if (_size == 0) {
        throw std::out_of_range("Архив пустой");
    }

    _size--;

    _states[_size] = State::deleted;

    if (_capacity > STEP_CAPACITY) {
        reserve(_capacity - 1);
    }
}

template <typename T>
void TArchive<T>::push_back(T value) {
    if (_size == _capacity) {
        reserve(_capacity + ((_capacity * 25)/100));
    }

    _data[_size] = value;
    _states[_size] = State::busy;

    _size++;
}

template <typename T>
const T& TArchive<T>::operator[](size_t index) const {

    if (index >= _capacity) {
        throw std::out_of_range("Index out of range");
    }

    if (_states[index] == State::empty || _states[index] == State::deleted) {
        throw std::logic_error("Accessing an empty or deleted element");
    }

    return _data[index];
}

template <typename T>
void TArchive<T>::reserve(size_t new_capacity) {

    if (new_capacity <= STEP_CAPACITY) {
        return;
    }

    T* new_data = new T[new_capacity];
    State* new_states = new State[new_capacity];

    for (size_t i = 0; i < _size; ++i) {
        new_data[i] = _data[i];
        new_states[i] = _states[i];
    }

    for (size_t i = _size; i < new_capacity; ++i) {
        new_states[i] = State::empty;
    }

    delete[] _data;
    delete[] _states;

    _data = new_data;
    _states = new_states;

    _capacity = new_capacity;
}

template <typename T>
T& TArchive<T>::operator[](size_t index) {

    if (index >= _capacity) {
        throw std::out_of_range("Index out of range");
    }

    if (_states[index] == State::empty || _states[index] == State::deleted) {
        throw std::logic_error("Accessing an empty or deleted element");
    }

    return _data[index];
}

template <typename T>
void TArchive<T>::resize(size_t new_capacity, T value) {
    if (new_capacity == _capacity) {
        throw std::logic_error("массивы равных размеров");
    }

    T* new_data = new T[new_capacity];
    State* new_states = new State[new_capacity];

    size_t elements_to_copy = (new_capacity < _size) ? new_capacity : _size;

    for (size_t i = 0; i < elements_to_copy; i++) {
        new_data[i] = _data[i];
        new_states[i] = _states[i];
    }

    for (size_t i = elements_to_copy; i < new_capacity; i++) {
        new_data[i] = value;
        new_states[i] = State::empty;
    }

    delete[] _data;
    delete[] _states;

    _data = new_data;
    _states = new_states;

    if (new_capacity < _size) {
        _size = new_capacity;
    }

    _capacity = new_capacity;
}

template <typename T>
inline void TArchive<T>::clear() {
    for (size_t i = 0; i < _capacity; ++i) {
        _states[i] = State::empty;
    }

    _size = 0;
    _deleted = 0;
}

template <typename T>
void TArchive<T>::swap(TArchive& archive) {
    T* tempData = _data;
    _data = archive._data;
    archive._data = tempData;

    State* tempStates = _states;
    _states = archive._states;
    archive._states = tempStates;

    size_t tempCapacity = _capacity;
    _capacity = archive._capacity;
    archive._capacity = tempCapacity;

    size_t tempSize = _size;
    _size = archive._size;
    archive._size = tempSize;

    size_t tempDeleted = _deleted;
    _deleted = archive._deleted;
    archive._deleted = tempDeleted;
}

template <typename T>
TArchive<T>::TArchive(size_t n, T value) {
    _size = n;
    _capacity = (n > STEP_CAPACITY) ? n : STEP_CAPACITY;
    _data = new T[_capacity];
    _states = new State[_capacity];

    for (size_t i = 0; i < n; i++) {
        _data[i] = value;
        _states[i] = State::busy;
    }

    for (size_t i = n; i < _capacity; i++) {
        _states[i] = State::empty;
    }
}

template <typename T>
const T* TArchive<T>::data() const {
    return _data;
}

template <typename T>
size_t TArchive<T>::capacity() const noexcept{
    return _capacity;
}

template <typename T>
size_t TArchive<T>::size() const noexcept {
    return _size;
}

template <typename T>
TArchive<T>::TArchive() {
    _size = 0;
    _capacity = STEP_CAPACITY;
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < STEP_CAPACITY; i++) {
        _states[i] = State::empty;
    }
}

template <typename T>
TArchive<T>::TArchive(const T* arr, size_t n) {
    _size = n;
    _capacity = n > STEP_CAPACITY ? n : STEP_CAPACITY;
    _data = new T[_capacity];
    _states = new State[_capacity];

    for (size_t i = 0; i < n; i++) {
        _data[i] = arr[i];
        _states[i] = State::busy;
    }

    for (size_t i = n; i < _capacity; i++) {
        _states[i] = State::empty;
    }
}

template <typename T>
TArchive<T>::TArchive(const TArchive& archive) {
    _size = archive._size;
    _capacity = archive._capacity;
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < _size; i++) {
        _data[i] = archive._data[i];
    }
    for (size_t i = 0; i < _capacity; i++) {
        _states[i] = archive._states[i];
    }
}

template <typename T>
TArchive<T>::~TArchive() {
    delete[] _data;
    _data = nullptr;
}

template <typename T>
inline bool TArchive<T>::empty() const noexcept {
    return _size == 0;
}

template <typename T>
inline bool TArchive<T>::full() const noexcept {
    return _size == _capacity;
}

template <typename T>
TArchive<T>& TArchive<T>::insert(T value, size_t pos) {
    if (_size < pos) {
        throw std::logic_error("Error in function \
\"TArchive<T>& insert(T value, size_t pos)\": wrong position value.");
    }


    /*
    // äåéñòâèÿ ïðè ïåðåïîëíåíèè
    if (this->full()) {
        this->reserve(size_t n);
        // + âíóòðè reserve() èñêëþ÷åíèå, åñëè äîñòèãíåì ìàñèìàëüíî
        // âîçìîæíîãî çíà÷åíèÿ _capacity
    }
    */


    for (size_t i = _size; i > pos; i--) {
        _data[i] = _data[i - 1];
    }
    _data[pos] = value;
    _states[pos] = State::busy;
    _size++;
    return *this;
}

template <typename T>
void TArchive<T>::print() const noexcept {
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] != State::deleted) {
            std::cout << _data[i] << ", ";
        }
    }
}


/*
// ïðèìåð ðåàëèçàöèè ñ âîçâðàòîì ìàññèâà íàéäåííûõ ïîçèöèé
template <typename T>
size_t* TArchive<T>::find_all (T value) const noexcept {
    size_t count = this->count_value(value);
    if (count == 0) { return nullptr; }
    int* found_positions = new int[count + 1];
    found_positions[0] = count;

    // TBD

    return found_positions;
}
*/

#endif  // LIB_DMASSIVE
