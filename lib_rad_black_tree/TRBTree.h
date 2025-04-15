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
	void fixinsert(TRBTreeNode<T>* node);
	TRBTreeNode<T>* getHead() {
		return _head;
	}

};

template<class T>
T TRBTree<T>::insert(T val) {
	TRBTreeNode<T>* node = new TRBTreeNode<T>(val);
	node->setColor(true);

	if (_head == nullptr) {
		_head = node;
		_head->setColor(false);
		return _head->value();
	}

	TRBTreeNode<T>* cur = _head;
	//TRBTreeNode<T>* parent = nullptr;
	while (cur != nullptr) {
		if (cur->value() == val) {
			throw std::logic_error("The value is already exists");
		}
		if (val < cur->value()) {
			if (cur->left() == nullptr) {
				if (cur->color() == false) {
					node->setColor(true);
					node->setParent(cur);
					cur->setLeft(node);
					return node;
				}
				else {
					fixInsert(node);
				}
			}
			cur = cur->left();
		}
		else {
			if (cur->right() == nullptr) {
				if (cur->color() == false) {
					node->setColor(true);
					node->setParent(cur);
					cur->setRight(node);
					return node;
				}
				else {
					fixInsert(node);
				}
			}
			cur = cur->right();
		}
	}
}

template<class T>
void TRBTree<T>::fixinsert(TRBTreeNode<T>* node) {

}
#endif // LIB_RAD_BLACK_TREE_