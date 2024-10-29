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

public:

	TLStack();
	void push(const T& val);
	void pop();
	inline bool isEmpty() const noexcept;
	inline bool isFull() const noexcept;
};

template<class T>
TLStack<T>::TLStack() {
	TList();
}

template<class T>
void TLStack<T>::push(const T& val) {
	_data.push_front(val);
}

template<class T>
bool TLStack<T>::isEmpty() const noexcept{
	if ((_data.getHead == nullptr) and (_data.getTail == nullptr)) {
		return true
	}
	return false
}

template<class T>
bool TLStack<T>::isFull() const noexcept {
	TNode<T>* cur = _data.getHead;
	int count = 0;
	while (cur != nullptr) {
		count++;
		cur = cur->getNext();
	}
	if (count == MAX_SIZE) {
		return true;
	}
	return false
}

template<class T>
void TLStack<T>::pop() {
	_data.pop_front();
}

#endif  // LIB_STACH_STACK_H_*/