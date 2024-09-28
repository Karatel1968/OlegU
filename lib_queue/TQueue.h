// Copyright 2024 Urin Oleg

#ifndef LIB_STACH_STACK_H_
#define LIB_STACH_STACK_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

template<class T>
class TQueue {
	T* _data;
	size_t _size;
	size_t _front;

public:

	TQueue(size_t size = 20);
	~TQueue();
	void push(T val);
	size_t front();
	size_t back();
	void swap(TQueue& queue);

	void pop();
	inline bool isEmpty() const noexcept;
	inline bool isFull() const noexcept;
	inline T top() const;
};

template<class T>
TQueue<T>::TQueue(size_t size) : _size(size), _front(-1) {
	_data = new T[size];
}

template<class T>
TQueue<T>::~TQueue() {
	delete _data;
	_data = nullptr;
}

template<class T>
void TQueue<T>::push(T val) {
	if (isFull()) {
		throw std::logic_error("Stack is full");
	}
	_top += 1;
	_data[_top] = val;
}

#endif  // LIB_STACH_STACK_H_