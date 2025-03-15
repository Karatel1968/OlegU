// Copyright 2024 Urin Oleg

#ifndef LIB_BIN_SEARCH_TREE_
#define LIB_BIN_SEARCH_TREE_

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>
#include <queue>

#include "../lib_binary_search_tree/BTreeNode.h"


template<class T>
class TBinSearchTree {
	TBTreeNode<T>* _head;
public:
	TBinSearchTree() { _head = nullptr; };
	~TBinSearchTree() { clear(); };
	TBTreeNode<T>* search(T val);
	TBTreeNode<T>* insert(T val);
	void erase(T val);
	void clear(TBTreeNode<T>* node);
	void clear();
	void print(TBTreeNode<T>* node);
	void print();
	void level(TBTreeNode<T>* root);
	TBTreeNode<T>* getHead() {
		return _head;
	}
};


template<class T>
void TBinSearchTree<T>::level(TBTreeNode<T>* root) {
	if (!root) return;

	std::queue<TBTreeNode<T>*> q;
	q.push(root);

	while (1) {
		TBTreeNode<T>* current = q.front();
		q.pop();
		std::cout << current->value() << ' ';

		if (current->left()) {

		q.push(current->left());
		}

		if (current->right()) {
		

		q.push(current->right());
		}
	}
}

template<class T>
void TBinSearchTree<T>::print() {
	print(_head);
}

template<class T>
void TBinSearchTree<T>::print(TBTreeNode<T>* node) {
	if (node == nullptr) {
		return;
	}
	
	std::cout << node->value() << " ";
	TBTreeNode<T>* cur = node;
	print(node->left());
	TBTreeNode<T>* cur = node;
	print(cur->right());
}

template<class T>
TBTreeNode<T>* TBinSearchTree<T>::search(T val) {
	TBTreeNode<T>* cur = _head;
	while (cur != nullptr) {
		if (cur->value() == val) {
			return cur;
		}
		if (val > cur->value()) {
			cur = cur->right();
		}
		else {
			cur = cur->left();
		}
	}
	throw std::logic_error("The value is not found");
}

template<class T>
TBTreeNode<T>* TBinSearchTree<T>::insert(T val) {
	TBTreeNode<T>* newNode = new TBTreeNode<T>(val);

	if (_head == nullptr) {
		_head = newNode;
		return _head;
	}

 	TBTreeNode<T>* cur = _head;
	TBTreeNode<T>* node = new TBTreeNode<T>(val);
	while (cur != nullptr) {
		if (cur->value() == val) {
			throw std::logic_error("The value is already exists");
		}
		if (val < cur->value()) {
			if (cur->left() == nullptr) {
				cur->setLeft(node);
				return node;
			}
			cur = cur->left();
		}
		else {
			if (cur->right() == nullptr) {
				cur->setRight(node);
				return node;
			}
			cur = cur->right();
		}
	}
}

template<class T>
void TBinSearchTree<T>::erase(T val) {

	if (_head == nullptr) {
		return;
	}

	TBTreeNode<T>* cur = _head;
	TBTreeNode<T>* parent = nullptr;

	while (cur != nullptr && cur->value() != val) {
		parent = cur;
		if (val > cur->value()) {
			cur = cur->right();
		}
		else {
			cur = cur->left();
		}
		
	}

	if (cur == nullptr) {
		throw std::logic_error("The value is not found");
	}

	/*if (cur == _head) {
		_head = nullptr;
	}*/
	
	if (cur->left() == nullptr && cur->right() == nullptr) {
		if (parent->left() == cur) {
			parent->setLeft(nullptr);
		}
		else {
			parent->setRight(nullptr);
		}
		delete cur;
		return;
	}

	if (cur->left() == nullptr && cur->right() != nullptr) {
		if (parent->left() == cur) {
			parent->setLeft(cur->right());
		}
		else {
			parent->setRight(cur->right());
		}
		delete cur;
		return;
	}

	if (cur->left() != nullptr && cur->right() == nullptr) {
		if (parent->left() == cur) {
			parent->setLeft(cur->left());
		}
		else {
			parent->setRight(cur->left());
		}
		delete cur;
		return;
	}

	
	TBTreeNode<T>* successor = cur->right();
	TBTreeNode<T>* successorParent = cur;

	
	while (successor->left() != nullptr) {
		successorParent = successor;
		successor = successor->left();
	}

	cur->setValue(successor->value());

	if (successorParent->left() == successor) {
		successorParent->setLeft(successor->right());
	}
	else {
		successorParent->setRight(successor->right());
	}
	delete successor;
}

template<class T>
void TBinSearchTree<T>::clear() {
	clear(_head);
	_head = nullptr;
}

template<class T>
void TBinSearchTree<T>::clear(TBTreeNode<T>* node) {
	if (node == nullptr) {
		return;
	}

	clear(node->left());
	clear(node->right());

	delete node;
}
#endif  // LIB_BIN_SEARCH_TREE_