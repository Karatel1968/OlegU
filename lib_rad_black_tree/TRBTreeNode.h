// Copyright 2024 Urin Oleg

#ifndef LIB_RAD_BLACK_TREE_NODE_
#define LIB_RAD_BLACK_TREE_NODE_

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>
#include <random>

template<class T>
class TRBTreeNode {
	T _value;
	bool _color;
	TRBTreeNode<T>* _right;
	TRBTreeNode<T>* _left;
	TRBTreeNode<T>* _parent;
public:
	TRBTreeNode() = default;
	TRBTreeNode(T value, TRBTreeNode<T>* left = nullptr,
		TRBTreeNode<T>* right = nullptr, TRBTreeNode<T>* parent = nullptr) : _value(value), _left(left), _right(right), _parent(parent){};
	TRBTreeNode<T>* right();
	TRBTreeNode<T>* left();
	T& value();
	inline bool color() {
		return _color;
	}
	inline void setParent(TRBTreeNode<T>* parent) {
		_parent = parent;
	}
	const TRBTreeNode* getParent() const {
		return _parent;
	}
	inline void setColor(bool color) {
		_color = color;
	}
	const TRBTreeNode* getRight() const {
		return _right;
	}
	const TRBTreeNode* getLeft() const {
		return _left;
	}
	void setRight(TRBTreeNode<T>* node) {
		_right = node;
	}
	void setLeft(TRBTreeNode<T>* node) {
		_left = node;
	}
	void setValue(T val) {
		_value = val;
	}
};

template<class T>
TRBTreeNode<T>* TRBTreeNode<T>::right() {
	return _right;
}

template<class T>
TRBTreeNode<T>* TRBTreeNode<T>::left() {
	return _left;
}

template<class T>
T& TRBTreeNode<T>::value() {
	return _value;
}


#endif // LIB_RAD_BLACK_TREE_NODE_