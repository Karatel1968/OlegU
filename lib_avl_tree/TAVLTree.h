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





#endif // LIB_AVL_TREE_