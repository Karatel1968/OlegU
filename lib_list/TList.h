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
	void push_front(const T& value) noexcept;
	void push_back(const T& value) noexcept;
	void insert(TNode<T>* node, const T* val);
	void insert(size_t pos);
	TNode<T>* find(const T& value) const noexcept;
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
TList<T>::TList() : _head(nullptr), _tail(nullptr){}

template<class T>
TList<T>::TList(const TList<T>& list): _head(nullptr), _tail(nullptr) {
	if (list._head == nullptr) {
		return;
	}

	head = new TNode<T>(list._head->value());
	TNode<T>* current_src = list._head->next();
	TNode<T>* current_dest = _head;

	while (current_src != nullptr) {
		TNode<T>* new_node = new TNode<T>(current_src->value());
		current_dest->setNext(new_node);
		current_dest = new_node;
		current_src = current_src->next();
	}

	_tail = current_dest;
}

template<class T>
void TList<T>::push_back(const T& value) noexcept {

	TNode<T>* new_node = new TNode<T>(value);

	if (_tail) {
		_tail->pnext = new_node;
	}
	else {
		_head = new_node;
	}
	_tail = new_node;
}

template<class T>
void TList<T>::insert(TNode<T>* node, const T* val) {
	if (node == nullptr) {
		throw std::logic_error("node = nullptr");
	}
	TNode<T>* new_node = new TNode<T>(val, node->next());
	node->next(new_node);
	if (node == _tail) {
		_tail = new_node;
	}
}

template<class T>
void TList<T>::push_front(const T& value) noexcept {
	TNode<T>* new_node = new(value);
	if (isEmpty()) {
		head = new_node;
		tail = new_node;
	}
	else {
		new_node->next(head);
		head = new_node;
	}
}




#endif  // LIB_STACH_LIST_H_