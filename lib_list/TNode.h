// Copyright 2024 Urin Oleg

#ifndef LIB_STACH_STACK_H_
#define LIB_STACH_STACK_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

template<class T>
class TNode {
	T _value;
	TNode<T>* pnext;
	
public:
	TNode<T>* next();
	TNode(T val, TNode<T>* node = nullptr);
	bool operator==(TNode<T>* node);
	TNode(const TNode<T>& node);
	TNode<T>& operator=(const TNode<T>& node);
	T value();
};

template<class T>
TNode<T>& TNode<T>::operator=(const TNode<T>& node) {
	if (this != node) {
		_value = node._value;
		pnext = node.pnext;
	}

	return *this;
}

template<class T>
TNode<T>* TNode<T>::next() {
	return pnext;
}

template<class T>
TNode<T>::TNode(T val, TNode<T>* node) {
	_value = val;
	pnext = node;
}

template<class T>
T value() {
	return _value;
}

template<class T>
TNode<T>::TNode(const TNode<T>& node) {
	_value = node._value;
	_pnext = node._pnext;
}

template<class T>
bool TNode<T>::operator==(TNode<T>* node) {
	return _value == node->_value;
}


#endif  // LIB_STACH_STACK_H_