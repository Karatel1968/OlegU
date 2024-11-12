// Copyright 2024 Urin Oleg

#ifndef LIB_STACH_STACK_H_
#define LIB_STACH_STACK_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include "../lib_list/TList.h"
#include "../lib_list/TNode.h"

#define MAX_SIZE 30

template<class T>
class TLStack {
	TList<T> _data;
	int  _size;
public:

	TLStack();
	void push(const T& val);
	void pop();
	inline bool isEmpty() const noexcept;
	inline bool isFull() const noexcept;
	int size() const noexcept;
};

template<class T>
int TLStack<T>::size() const noexcept {
	/*TNode<T>* cur = _data.getHead();
	int c = 0;
	while (cur != nullptr) {
		c++;
		cur = cur->next();
	}*/
	return _size;
}

template<class T>
TLStack<T>::TLStack() : _data() , _size(0){}

template<class T>
void TLStack<T>::push(const T& val) {
	if (!isFull()) {
		_data.push_front(val);
		_size++;
	}
	else {
		throw std::logic_error("stack is overflow");
	}
}

template<class T>
bool TLStack<T>::isEmpty() const noexcept{
	return _data.isEmpty();
}

template<class T>
bool TLStack<T>::isFull() const noexcept {
	/*TNode<T>* cur = _data.getHead();
	int count = 0;
	while (cur != nullptr) {
		count++;
		cur = cur->getNext();
	}*/
	if (_size == MAX_SIZE) {
		return true;
	}
	return false;
}

template<class T>
void TLStack<T>::pop() {
	_data.pop_front();
	_size--;
}

#endif  // LIB_STACH_STACK_H_*/