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
	size_t _back;
	size_t _count;


public:

	TQueue(size_t size = 20);
	~TQueue();
	void push(T val);
	inline T front() const;
	void swap(TQueue& queue);
	void pop();
	inline bool isEmpty() const noexcept;
	inline bool isFull() const noexcept;
};

template<class T>
TQueue<T>::TQueue(size_t size) : _size(size), _front(0), _back(-1), _count(0) {
	_data = new T[size];
}

template<class T>
TQueue<T>::~TQueue() {
	delete _data;
	_data = nullptr;
}

template<class T>
inline bool TQueue<T>::isEmpty() const noexcept {
	return _count == 0;
}

template<class T>
inline bool TQueue<T>::isFull() const noexcept {
	return _count == _size;
}

template<class T>
inline T TQueue<T>::front() const {
	if (isEmpty()) {
		throw std::logic_error("TQueue is empty");
	}
	return _data[_front];
}

template<class T>
void TQueue<T>::push(T val) {
	if (isFull()) {
		throw std::logic_error("TQueue is full");
	}
	_back += 1;
	_data[_back] = val;
	_count++;
}

#endif  // LIB_STACH_STACK_H_