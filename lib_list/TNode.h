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



#endif  // LIB_STACH_STACK_H_