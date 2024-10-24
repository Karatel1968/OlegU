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

	TStack();
	void push(const T& val);
	void pop();
	inline bool isEmpty() const noexcept;
	inline bool isFull() const noexcept;
};

template<class T>
void TLStack<T>::push(const T& val) {
	_data.push_front(val);
}

template<class T>
bool TLStack<T>::isFull() const noexcept{
	//if(_data.size() != )
}

#endif  // LIB_STACH_STACK_H_*/