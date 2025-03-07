// Copyright 2024 Urin Oleg

#ifndef LIB_BIN_SEARCH_TREE_
#define LIB_BIN_SEARCH_TREE_

#include "../lib_binary_search_tree/BTreeNode.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>

template<class T>
class TBinSearchTree {
	TBTreeNode<T>* _head;
public:
	TBinSearchTree() { _head = nullptr };
	~TBinSearchTree() { clear() };
	TBTreeNode<T>* search(T val);
	TBTreeNode<T>* insert(T val);
	void erase(T val);
	void clear();
	void print();
};

template<class T>
TBTreeNode<T>* TBinSearchTree<T>::search(T val) {
	TBTreeNode<T>* cur = _head;
	while (cur != nullptr) {
		if (cur->value() == val) {
			return cur;
		}
		if (val > cur->value()) {
			cur = cur->right();
		}
		if (val < cur->value()) {
			cur = cur->left();
		}
	}
	throw std::logic_error("The value is not found");
}

template<class T>
TBTreeNode<T>* TBinSearchTree<T>::insert(T val) {

	if (_head == nullptr) {
		_head->value() = val;
		return _head;
	}

 	TBTreeNode<T>* cur = _head;

	while (cur != nullptr) {
		if (cur->value() == val) {
			throw std::logic_error("The value is already exists");
		}
		if (val < cur->value()) {
			if (cur->left() == nullptr) {
				cur->setLeft(val);
				return val;
			}
			cur = cur->left();
		}
		else {
			if (cur->right() == nullptr) {
				cur->setRight(val);
				return val;
			}
			cur = cur->right();
		}
	}
}

#endif  // LIB_BIN_SEARCH_TREE_