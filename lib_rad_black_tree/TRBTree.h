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

template<class T>
class TRBTree {
	TRBTreeNode<T>* _head;
public:
	TRBTree() { _head = nullptr; };
	~TRBTree() { clear(); };
	T* search(T val);
	T* insert(T val);
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


#endif // LIB_RAD_BLACK_TREE_