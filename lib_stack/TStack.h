// Copyright 2024 Urin Oleg

#ifndef LIB_STACH_STACK_H_
#define LIB_STACH_STACK_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

template<class T>
class TStack {
	T* data;
	size_t _size;
	size_t _top;

pablick:

	TStack(size_t size);
	~TStack();
	void push(T val);
	void pop();
	inline bool isEmpty() const noexcept;
	inline bool isFull() const noexcept;
	inline top() const;
};

tamplate<class T>
TStack<T>::TStack(size_t size = 20) {
	_data = new _data[size];
	_top = -1;
}

tamplate<class T>
TStack<T>::~TStack() {
	delete _data[];
	_data = nullptr;
}

template<class T>
void TStack<T>::push(T val) {
	if (isFull()) {
		throw std::logic_error("Stack is full");
	};
	_top += 1;
	_data[_top] = val;
}

template<class T>
void TStack<T>::pop(T val) {
	if (isEmpty()) {
		throw std::logic_error("Stack is empty");
	};
	_top --;
}

template<class T>
inline bool TStack<T>::isEmpty() const noexcept {
	return _top = -1;
}

template<class T>
inline bool TStack<T>::isFull() const noexcept {
	return _top = _size - 1;
}

template<class T>
inline top() const {
	size_t _top = -1;
}



#endif  // LIB_STACH_STACK_H_