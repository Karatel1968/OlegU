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
	void leftRotate(TRBTreeNode<T>* node);
	void rightRotate(TRBTreeNode<T>* node);
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
					node->setColor(true);
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
					node->setColor(true);
					fixInsert(node);
				}
			}
			cur = cur->right();
		}
	}
}

template<class T>
void TRBTree<T>::fixinsert(TRBTreeNode<T>* node) {
	TRBTreeNode<T>* node = new TRBTreeNode<T>(val);
	node->setColor(true);

	TRBTreeNode<T>* parent = nullptr;
	TRBTreeNode<T>* grandparent = nullptr;
	TRBTreeNode<T>* uncle = nullptr;

	while (node != _head) {
		parent = node->getParent();
		grandparent = parent->getParent();
		if (parent == grandparent->left()) {
			uncle = grandparent->right();
		
			// 1: ƒ€д€ красный
			if (uncle != nullptr && uncle->color() == true) {
				if (grandparent != _head) {
					grandparent->setColor(true);
				}
				else {
					grandparent->setColor(false);
				}
				parent->setColor(false);
				uncle->setColor(false);
				node = grandparent;
			}
			// 2: ƒ€д€ чЄрный 
			if (uncle != nullptr && uncle->color() == false) {
				// нова€ нода - правый ребЄнок
				if (node == parent->right()) {
					leftRotate(node);
					node = parent;
					parent = node->getParent();
				}
				// нова€ нода - левый ребЄнок
				
					rightRotate(node)
					bool tempColor = parent->color();
					parent->setColor(grandparent->color());
					grandparent->setColor(tempColor);
					node = parent;	
				
			}
		}
		else {
			uncle = grandparent->left();
			// 1: ƒ€д€ красный
			if (uncle != nullptr && uncle->color() == true) {
				if (grandparent != _head) {
					grandparent->setColor(true);
				}
				else {
					grandparent->setColor(false);
				}
				parent->setColor(false);
				uncle->setColor(false);
			}
			// 2: ƒ€д€ чЄрный 
			if (uncle != nullptr && uncle->color() == false) {
				// нова€ нода - левый ребЄнок
				if (node == parent->left()) {
					rightRotate(node);
					node = parent;
					parent = node->getParent();
				}
				// нова€ нода - правый ребЄнок
				
					leftRotate(node, grandparent)
					bool tempColor = parent->color();
					parent->setColor(grandparent->color());
					grandparent->setColor(tempColor);
					node = parent;
				
			}
		}
	}
}

template<class T>
void leftRotate(TRBTreeNode<T>* node) {
	TRBTreeNode<T>* p = node->getParent();
	TRBTreeNode<T>* g = p->getParent()

	if (p == g->getLeft()) {
		g->setLeft(node);
	}
	else {
		g->setRight(node);
	}
	p->setRight(node->getLeft());
	node->setLeft(p);
	node->setParent(g);
	p->setParent(node);
	if (p->getRight() != nullptr) {
		(p->getRight())->setParent(p);
	}
	
}

template<class T>
void rightRotate(TRBTreeNode<T>* node) {
	TRBTreeNode<T>* p = node->getParent();
	TRBTreeNode<T>* g = p->getParent();

	if (p == g->getLeft()) {
		g->getLeft(p->setRight());
		if (g->getLeft() != nullptr) {
			g->getLeft()->getParent(g);
		}
	}
	else {
		g->setRight(p->getLeft());
		if (g->getRight() != nullptr) {
			g->getRight()->getParent(g);
		}
	}
	
	p->setRight(g);
	p->setParent(g->getParent());
	g->setParent(p);
	
}
#endif // LIB_RAD_BLACK_TREE_