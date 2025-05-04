// Copyright 2024 Urin Oleg

#ifndef LIB_RAD_BLACK_TREE_
#define LIB_RAD_BLACK_TREE_

#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <utility>
#include <random>
#include "../lib_rad_black_tree/TRBTreeNode.h"

template<class T>
class TRBTree {
	TRBTreeNode<T>* _head;
	void fixInsert(TRBTreeNode<T>* node);
	void leftRotate(TRBTreeNode<T>* node);
	void rightRotate(TRBTreeNode<T>* node);
public:
	void clear(TRBTreeNode<T>* node);
	void clear();
	TRBTree() { _head = nullptr; };
	~TRBTree() { clear(); };
	TRBTreeNode<T>* search(T val);
	T insert(T val);
	void erase(T val);
	void print(TRBTreeNode<T>* node, std::string prefix, bool isTail);
	void print();
	
	TRBTreeNode<T>* getHead() {
		return _head;
	}

};

template<class T>
void TRBTree<T>::erase(T val) {
	if (_head == nullptr) {
		return;
	}

	TRBTreeNode<T>* cur = _head;
	TRBTreeNode<T>* parent = nullptr;

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
}

template<class T>
void TRBTree<T>::clear() {
	clear(_head);
	_head = nullptr;
}

template<class T>
void TRBTree<T>::clear(TRBTreeNode<T>* node) {
	if (node == nullptr) {
		return;
	}

	clear(node->left());
	clear(node->right());

	delete node;
}

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
					return node->value();
				}
				else {
					node->setColor(true);
					node->setParent(cur);
					cur->setLeft(node);
					fixInsert(node);
					return node->value();
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
					return node->value();
				}
				else {
					node->setColor(true);
					node->setParent(cur);
					cur->setRight(node);
					fixInsert(node);
					return node->value();
				}
			}
			cur = cur->right();
		}
	}
}

template<class T>
void TRBTree<T>::fixInsert(TRBTreeNode<T>* node) {
	node->setColor(true);

	TRBTreeNode<T>* parent = nullptr;
	TRBTreeNode<T>* grandparent = nullptr;
	TRBTreeNode<T>* uncle = nullptr;

	while (node != _head && node->getParent()->color()) {
		parent = node->getParent();
		grandparent = parent->getParent();
		if (parent == grandparent->left()) {
			uncle = grandparent->right();
		
			// 1: Дядя красный
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
			// 2: Дядя чёрный 
			else{
				// новая нода - правый ребёнок
				if (node == parent->right()) {
					leftRotate(node);
					node = parent;
					parent = node->getParent();
				}
				// новая нода - левый ребёнок
				
				rightRotate(node);
				bool tempColor = parent->color();
				parent->setColor(grandparent->color());
				grandparent->setColor(tempColor);
				node = parent;	
				
			}
		}
		else {
			uncle = grandparent->left();
			// 1: Дядя красный
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
			// 2: Дядя чёрный 
			else{
				// новая нода - левый ребёнок
				if (node == parent->left()) {
					rightRotate(node);
					node = parent;
					parent = node->getParent();
				}
				// новая нода - правый ребёнок
				
				leftRotate(node);
				bool tempColor = parent->color();
				parent->setColor(grandparent->color());
				grandparent->setColor(tempColor);
				node = parent;
				
			}
		}
	}
}

template<class T>
void TRBTree<T>::leftRotate(TRBTreeNode<T>* X) {
	/*
		    (G)				   (G)
		  /		\            /	   \
		[p]		(U)	   ->	[X]		(U)
	   /  \		/  \	   /   \    / \
	  t1  [X]  t4	t5	  [P]  t3  t4  t5
	     /   \           /   \
        t2    t3        t1   t2
	*/
	TRBTreeNode<T>* P = X->getParent();
	TRBTreeNode<T>* G = P->getParent();
	TRBTreeNode<T>* t2 = X->getLeft();
	

	if (P == G->getLeft()) {
		G->setLeft(X);
		X->setParent(G);
	}
	else {
		G->setRight(X);
		X->setParent(G);
	}
	P->setRight(t2);
	X->setLeft(P);
	P->setParent(X);
	if (t2 != nullptr) {
		t2->setParent(P);
	}
	
}

template<class T>
void TRBTree<T>::rightRotate(TRBTreeNode<T>* X) {
	/*
			(G)				   (P)
		  /		\            /	   \
		[P]		(U)	   ->	[X]		[G]
	   /  \		/  \	   /   \    / \
	  [X]  t3 t4	t5	  t1   t2  t3 (U)
	 /   \                           /   \
	t1	 t2                         t4   t5

	*/
	TRBTreeNode<T>* p = X->getParent();
	TRBTreeNode<T>* g = p->getParent();
	TRBTreeNode<T>* t3 = p->getRight();

	if (p == g->getLeft()) {
		TRBTreeNode<T>* u = g->getRight();
		g->setLeft(t3);
		if (t3 != nullptr) {
			t3->setParent(g);
		}
		g->setRight(u);
		u->setParent(g);
		p->setRight(g);

	}
	else {
		TRBTreeNode<T>* u = g->getLeft();
		g->setLeft(t3);
		if (t3 != nullptr) {
			t3->setParent(g);
		}
		g->setRight(u);
		u->setParent(g);
		p->setLeft(g);
	}
	
	p->setParent(g->getParent());
	g->setParent(p);
	
}

template<class T>
TRBTreeNode<T>* TRBTree<T>::search(T val) {
	TRBTreeNode<T>* cur = _head;
	while (cur != nullptr) {
		if (cur->value() == val) {
			return cur;
		}
		if (val > cur->value()) {
			cur = cur->getRight();
		}
		else {
			cur = cur->getLeft();
		}
	}
	throw std::logic_error("The value is not found");
}

template<class T>
void TRBTree<T>::print(TRBTreeNode<T>* node, std::string prefix, bool isLeft) {
	if (node == nullptr) {
		return;
	}

	std::cout << prefix;
	std::cout << (isLeft ? "|--" : "--");
	std::string color;
	std::string reset = "\033[0m";
	if (node->color()) {
		color = "\033[31m"; 
		std::cout << "[" << color << node->value() << reset << "]";
	}
	else {
		
		std::cout << "(" << node->value() << ")";
	}

	std::cout << std::endl;

	print(node->left(), prefix + (isLeft ? "|    " : "    "), true);
	print(node->right(), prefix + (isLeft ? "|    " : "    "), false);
}     

template<class T>
void TRBTree<T>::print() {
	if (_head == nullptr) {
		std::cout << "Tree is empty." << std::endl;
		return;
	}
	print(_head, "", false);
}


#endif // LIB_RAD_BLACK_TREE_