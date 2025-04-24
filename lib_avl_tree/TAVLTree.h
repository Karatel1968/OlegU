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
	void leftRotate(TAVLTreeNode<T>* node);
	void rightRotate(TAVLTreeNode<T>* node);
	void TAVLTree<T>::fixheight(TAVLTreeNode<T>* p);
	int bfactor(TAVLTreeNode<T>* p)
	{
		return height(p->right) - height(p->left);
	}
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
	inline int height(TAVLTreeNode<T>* node) {
		return node ? node->height() : 0;
	}
	TAVLTreeNode<T>* getHead() {
		return _head;
	}

};

template<class T>
void TAVLTree<T>::fixheight(TAVLTreeNode<T>* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height() = (hl > hr ? hl : hr) + 1;
	fixheight(p->)
}

template<class T>
T TAVLTree<T>::insert(T val) {
	TAVLTreeNode<T>* node = new TAVLTreeNode<T>(val);

	if (_head == nullptr) {
		_head = node;
		return _head;
	}

	TAVLTreeNode<T>* cur = _head;
	while (cur != nullptr) {
		if (cur->value() == val) {
			throw std::logic_error("The value is already exists");
		}
		if (val < cur->value()) {
			if (cur->getLeft() == nullptr) {
				cur->setLeft(node);
				//cur->setHeight(1 + std::max(height(node->getLeft()), height(node->getRight())));
				fixheight(cur);
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