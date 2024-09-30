// Copyright 2024 Urin Oleg

#ifndef LIB_STACH_LIST_H_
#define LIB_STACH_LIST_H_

#include "../lib_list/TNode.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

template<class T>
class TList {
	TNode<T>* _head;
	TNode<T>* _tail;

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

template<class T>
void TList<T>::insert(TNode<T>* node, const T* val) {
	if (node == nullptr) {
		throw std::logic_error_error("node = nullptr");
	}
	TNode<T>* new_node = new TNode<T>(val, node->next());
	node->next(new_node);
	if (node == _tail) {
		_tail = new_node;
	}
}



#endif  // LIB_STACH_LIST_H_