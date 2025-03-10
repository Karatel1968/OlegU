// Copyright 2024 Urin Oleg

#ifndef LIB_BIN_SEARCH_TREE_NODE_
#define LIB_BIN_SEARCH_TREE_NODE_

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>

template<class T>
class TBTreeNode {
	T _value;
	TBTreeNode<T>* _right;
	TBTreeNode<T>* _left;
public:
	TBTreeNode() = default;
	TBTreeNode(T value, TBTreeNode<T>* left = nullptr,
		TBTreeNode<T>* right = nullptr): _value(value), _left(left), _right(right) {};
	TBTreeNode<T>* right();
	TBTreeNode<T>* left();
	T& value();
	const TBTreeNode* getRight() const {
		return _right;
	}
	const TBTreeNode* getLeft() const {
		return _left;
	}
	void setRight(TBTreeNode<T>* node) {
		_right = node;
	}
	void setLeft(TBTreeNode<T>* node) {
		_left = node; 
	}
	void setValue(T val) {
		_value = val;
	}
};

template<class T>
TBTreeNode<T>* TBTreeNode<T>::right() {
	return _right;
}

template<class T>
TBTreeNode<T>* TBTreeNode<T>::left() {
	return _left;
}

template<class T>
T& TBTreeNode<T>::value() {
	return _value;
}

#endif  // LIB_BIN_SEARCH_TREE_NODE_