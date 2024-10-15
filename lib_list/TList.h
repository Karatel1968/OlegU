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
	TList(); // +
	TList(const TList<T>& list);
	~TList();
	void push_front(const T& value) noexcept; // +
	void push_back(const T& value) noexcept; // +
	void insert(TNode<T>* node, const T* val); // +
	void insert(size_t pos);
	TNode<T>* find(const T& value) const noexcept; // +
	void pop_front(); // +
	void pop_back(); // !
	void erase(TNode<T>* node); // !
	void erase(size_t pos);
	bool isEmpty(); // +
	void replace(TNode<T>* node, TNode<T>* node2); // !
	void replace(size_t pos);
	void qsort(TList<T> list) noexcept;
	TNode<T>* getHead() const { return _head; }; // +
	TNode<T>* getTail() const { return _tail; }; // +
};

/*template<class T>
void TList<T>::insert(size_t pos) {
	if((list._head == nullptr) {
		throw std::logic_error("node = nullptr");
	}

	TNode<T>* new_node = 
}*/

template<class T>
TList<T>::~TList() {
	TNode<T>* cur = _head;

	while (cur != nullptr) {
		TNode<T>* next_ptr = cur->next();
		delete cur;
		cur = next_ptr;
	}

	_head = nullptr;
	_tail = nullptr;
}

/*template<class T>
void TList<T>::replace(TNode<T>* node, TNode<T>* node2) {

	if (node == nullptr) {
		throw std::logic_error("node == nullptr");
	}

	TNode<T>* cur = _head;
	while (cur != nullptr) {
		if (*cur == node) {
			cur->setValue(node2->value());
			return;
		}
		cur = cur->next();
	}

	throw std::logic_error("Node is not found");
}*/

template<class T>
bool TList<T>::isEmpty() {
	return _head == nullptr;
}

template<class T>
void TList<T>::erase(TNode<T>* node) {

	if (_head == nullptr || node == nullptr) {
		return;
	}
	
	if (node == _head) {
		pop_front();
		return;
	}


	TNode<T>* cur = _head;
	while (cur->next() != node) {
		cur = cur->next();
		/*if (cur->next() == node) {
			cur->setNext(node->next());
			delete node;
		}*/
		if (cur == nullptr) {
			return;
		}
		
	}

	if (node == _tail) {
		_tail == cur;
		cur->setNext(nullptr);
		return;
	}

	cur->setNext(node->next());

	delete node;
}

template<class T>
void TList<T>::pop_front() {

	if (_head == nullptr) {
		throw std::logic_error("node = nullptr");
	}

	else if (_head == _tail) {
		delete _head;
		_head = _tail = nullptr;
	}

	else if (_head == nullptr) {
		_tail == nullptr;
	}

	else {
		TNode<T>* old_head = _head;

		_head = _head->next();

		delete old_head;
	}
}

template<class T>
void TList<T>::pop_back() {

	if (_head == nullptr) {
		throw std::logic_error("List is empty");
	}

	TNode<T>* cur = _head;

	if (_head == _tail) {
		delete _head;
		_head = _tail = nullptr;
	}

	while (cur->next() != _tail) {
		cur = cur->next();
	}
	delete _tail;
	_tail = cur;
	_tail->setNext(nullptr);
}

template<class T>
TNode<T>* TList<T>::find(const T& value) const noexcept {

	TNode<T>* cur = _head;

	while (cur != nullptr) {
		if (cur->value() == value) {
			return cur;
		}
		cur = cur->next();
	}
	return nullptr;
}

template<class T>
TList<T>::TList() : _head(nullptr), _tail(nullptr){}

template<class T>
TList<T>::TList(const TList<T>& list): _head(nullptr), _tail(nullptr) {
	if (list._head == nullptr) {
		return;
	}

	_head = new TNode<T>(list._head->value());
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
		_tail->setNext(new_node);
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
	TNode<T>* new_node = new TNode<T>(*val);
	new_node->setNext(node->next());
	node->setNext(new_node);
	if (node == _tail) {
		_tail = new_node;
	}
}

template<class T>
void TList<T>::push_front(const T& value) noexcept {
	TNode<T>* new_node = new TNode<T>(value);
	if (isEmpty()) {
		_head = new_node;
		_tail = new_node;
	}
	else {
		new_node->setNext(_head);
		_head = new_node;
	}
}

#endif  // LIB_STACH_LIST_H_