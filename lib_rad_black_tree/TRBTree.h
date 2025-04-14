// Copyright 2024 Urin Oleg

#ifndef LIB_RAD_BLACK_TREE_
#define LIB_RAD_BLACK_TREE_

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>
#include <random>
#include "../lib_rad_black_tree/TRBTreeNode.h"

template<class T>
class TRBTree {
	TRBTreeNode<T>* _head;
public:
	TRBTree() { _head = nullptr; };
	~TRBTree() { clear(); };
	T search(T val);
	T insert(T val);
	void erase(T val);
	void clear(TRBTreeNode<T>* node);
	void clear();
	void print(TRBTreeNode<T>* node);
	void print();
	void level(TRBTreeNode<T>* root);
	TRBTreeNode<T>* getHead() {
		return _head;
	}

};

template<class T>
T TRBTree<T>::insert(T val) {
	TRBTreeNode<T>* newNode = new TRBTreeNode<T>(val);
	newNode->setColor(true);

	if (_head == nullptr) {
		_head = newNode;
		_head->setColor(false);
		return _head->value();
	}
}
#endif // LIB_RAD_BLACK_TREE_