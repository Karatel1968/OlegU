// Copyright 2024 Urin Oleg

#ifndef LIB_AVL_TREE_NODE_
#define LIB_AVL_TREE_NODE_

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>
#include <random>

template<class T>
class TAVLTreeNode {
	T _value;
	int _height;
	TAVLTreeNode<T>* _parent;
	TAVLTreeNode<T>* _right;
	TAVLTreeNode<T>* _left;
public:
	TAVLTreeNode() = default;
	TAVLTreeNode(T value, TAVLTreeNode<T>* left = nullptr,
		TAVLTreeNode<T>* right = nullptr, int height = 1, TAVLTreeNode<T>* parent = nullptr) : _parent(parent), _value(value), _left(left), _right(right), _height(height) {};
	T& value();
	inline TAVLTreeNode* parent() const{
		return _parent;
	}
	inline int height() {
		return _height;
	}
	inline void setParent(TAVLTreeNode<T>* parent) {
		_parent = parent;
	}
	inline void setHeight(int height) {
		_height = height;
	}
	TAVLTreeNode* getRight() const {
		return _right;
	}
	TAVLTreeNode* getLeft() const {
		return _left;
	}
	void setRight(TAVLTreeNode<T>* node) {
		_right = node;
	}
	void setLeft(TAVLTreeNode<T>* node) {
		_left = node;
	}
	void setValue(T val) {
		_value = val;
	}
};

template<class T>
T& TAVLTreeNode<T>::value() {
	return _value;
}


#endif // LIB_AVL_TREE_NODE_