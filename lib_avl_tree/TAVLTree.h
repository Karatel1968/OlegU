// Copyright 2024 Urin Oleg

#ifndef LIB_AVL_TREE_
#define LIB_AVL_TREE_

#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>
#include <random>
#include "../lib_avl_tree/TAVLTreeNode.h"

template<class T>
class TAVLTree {
	TAVLTreeNode<T>* _head;
	void fixInsert(TAVLTreeNode<T>* node);
	void leftRotate(TAVLTreeNode<T>* node);
	void rightRotate(TAVLTreeNode<T>* node);
public:
	void clear(TAVLTreeNode<T>* node);
	void clear();
	TRBTree() { _head = nullptr; };
	~TAVLTree() { clear(); };
	T search(T val);
	T insert(T val);
	void erase(T val);
	void print(TAVLTreeNode<T>* node, std::string prefix, bool isTail);
	void print();
	void level(TAVLTreeNode<T>* root);

	TAVLTreeNode<T>* getHead() {
		return _head;
	}

};


template<class T>
T TAVLTree<T>::insert(T val) {
	TAVLTreeNode<T>* newNode = new TAVLTreeNode<T>(val);

	if (_head == nullptr) {
		_head = newNode;
		_head->setHeight(1);
		return _head;
	}

	TAVLTreeNode<T>* cur = _head;
	TAVLTreeNode<T>* node = new TAVLTreeNode<T>(val);
	while (cur != nullptr) {
		if (cur->value() == val) {
			throw std::logic_error("The value is already exists");
		}
		if (val < cur->value()) {
			if (cur->getLeft() == nullptr) {
				cur->setLeft(node);
				return node;
			}
			cur = cur->getLeft();
		}
		else {
			if (cur->getRight() == nullptr) {
				cur->setRight(node);
				return node;
			}
			cur = cur->getRight();
		}
	}
}


#endif // LIB_AVL_TREE_