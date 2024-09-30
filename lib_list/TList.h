// Copyright 2024 Urin Oleg

#ifndef LIB_STACH_STACK_H_
#define LIB_STACH_STACK_H_

#include "../lib_list/TNode.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

template<class T>
class TList {
	TList<T>* _head;
	TList<T>* _tail;

public:
	TList();
	TList(const TList<T>& list);
	~TList();
	Void push_front(const T& value) noexcept;
	void push_back(const T& value) noexcept;
	void insert(TNode<T>* node, const T* val);
	void insert(size_t pos);
	TList<T>* find(const T& value) const noexcept;
	void pop_front();
	void pop_back();
	erase(TNode<T>* node);
	erase(size_t pos);
	bool isEmpty();
	void replace(TNode<T>* node);
	void replace(size_t pos);
	void qsort(TList<T> list) noexcept;
};



#endif  // LIB_STACH_STACK_H_