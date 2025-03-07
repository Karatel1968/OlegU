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

#endif  // LIB_BIN_SEARCH_TREE_