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
	void SmallLeftRotate(TAVLTreeNode<T>* a);
	void BigLeftRotate(TAVLTreeNode<T>* a);
	void SmallRightRotate(TAVLTreeNode<T>* a);
	void BigRightRotate(TAVLTreeNode<T>* a);
	void TAVLTree<T>::fixheight(TAVLTreeNode<T>* p);
	void balancing(TAVLTreeNode<T>* p);
	int bfactor(TAVLTreeNode<T>* p)
	{
		return height(p->getRight()) - height(p->getLeft());
	}
public:
	void clear(TAVLTreeNode<T>* node);
	void clear();
	TAVLTree() { _head = nullptr; };
	~TAVLTree() { clear(); };
	T search(T val);
	T insert(T val);
	void erase(T val);
	void print(TAVLTreeNode<T>* node, std::string prefix, bool isTail);
	void print();
	inline int height(TAVLTreeNode<T>* node) {
		return node ? node->height() : 0;
	}
	TAVLTreeNode<T>* getHead() {
		return _head;
	}

};

template<class T>
T TAVLTree<T>::search(T val) {
	TAVLTreeNode<T>* cur = _head;
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
void TAVLTree<T>::erase(T val) {
	if (_head == nullptr) {
		return;
	}

	TAVLTreeNode<T>* cur = _head;

	while (cur != nullptr && cur->value() != val) {
		if (val > cur->value()) {
			cur = cur->getRight();
		}
		else {
			cur = cur->getLeft();
		}

	}

	if (cur == nullptr) {
		throw std::logic_error("The value is not found");
	}

	TAVLTreeNode<T>* parent = cur->parent();

	if (cur->getLeft() == nullptr && cur->getRight() == nullptr) {
		if (parent->getLeft() == cur) {
			parent->setLeft(nullptr);
		}
		else {
			parent->setRight(nullptr);
		}
		delete cur;
		fixheight(parent);
		return;
	}

	if (cur->getLeft() == nullptr && cur->getRight() != nullptr) {
		if (parent->left() == cur) {
			parent->setLeft(cur->getRight());
		}
		else {
			parent->setRight(cur->getRight());
		}
		delete cur;
		fixheight(parent);
		return;
	}

	if (cur->getLeft() != nullptr && cur->getRight() == nullptr) {
		if (parent->getLeft() == cur) {
			parent->setLeft(cur->getLeft());
		}
		else {
			parent->setRight(cur->getLeft());
		}
		delete cur;
		fixheight(parent);
		return;
	}


	TAVLTreeNode<T>* successor = cur->getRight();
	TAVLTreeNode<T>* successorParent = cur;


	while (successor->getLeft() != nullptr) {
		successorParent = successor;
		successor = successor->getLeft();
	}

	cur->setValue(successor->value());

	if (successorParent->getLeft() == successor) {
		successorParent->setLeft(successor->getRight());
	}
	else {
		successorParent->setRight(successor->getRight());
	}

	TAVLTreeNode<T>* sucParent = successor->parent();
	delete successor;
	erase(sucParent);

}


template<class T>
void TAVLTree<T>::SmallLeftRotate(TAVLTreeNode<T>* a) {
	TAVLTreeNode<T>* C = a->getRight()->getLeft();
	TAVLTreeNode<T>* b = a->getRight();

	a->setRight(C);
	b->setLeft(a);
	b->setParent(a->parent());
	a->setParent(b);
	if (C != nullptr) {
		C->setParent(a);
	}
	a->setHeight(std::max(height(a->getLeft()), height(C)) + 1);
	b->setHeight(std::max(height(a), height(b->getRight())) + 1);
	if (_head == a) {
		_head = b;
	}
	if (b->parent() != nullptr) {
		if (a == b->parent()->getLeft()) {
			b->parent()->setLeft(b);
		}
		else if (a == b->parent()->getRight()) {
			b->parent()->setRight(b);
		}
	}
}

template<class T>
void TAVLTree<T>::BigLeftRotate(TAVLTreeNode<T>* a) {
	TAVLTreeNode<T>* b = a->getRight();
	TAVLTreeNode<T>* c = a->getRight()->getLeft();
	TAVLTreeNode<T>* M = a->getRight()->getLeft()->getLeft();
	TAVLTreeNode<T>* N = a->getRight()->getLeft()->getRight();

	a->setRight(M);
	b->setLeft(N);
	if (M != nullptr) {
		M->setParent(a);
	}
	if (N != nullptr) {
		N->setParent(b);
	}
	c->setParent(a->parent());
	c->setRight(b);
	c->setLeft(a);
	a->setParent(c);
	b->setParent(c);
	if (_head == a) {
		_head = c;
	}
	a->setHeight(std::max(height(a->getLeft()), height(M)) + 1);
	b->setHeight(std::max(height(N), height(b->getRight())) + 1);
	c->setHeight(std::max(height(a), height(b)) + 1);
	if (c->parent() != nullptr) {
		if (a == c->parent()->getLeft()) {
			c->parent()->setLeft(c);
		}
		else if (a == c->parent()->getRight()) {
			c->parent()->setRight(c);
		}
	}
}

template<class T>
void TAVLTree<T>::SmallRightRotate(TAVLTreeNode<T>* a) {
	TAVLTreeNode<T>* C = a->getLeft()->getRight();
	TAVLTreeNode<T>* b = a->getLeft();

	a->setLeft(C);
	b->setRight(a);
	b->setParent(a->parent());
	a->setParent(b);
	if (C != nullptr) {
		C->setParent(a);
	}
	a->setHeight(std::max(height(a->getRight()), height(C)) + 1);
	b->setHeight(std::max(height(a), height(b->getLeft())) + 1);
	if (_head == a) {
		_head = b;
	}
	if (b->parent() != nullptr) {
		if (a == b->parent()->getLeft()) {
			b->parent()->setLeft(b);
		}
		else if (a == b->parent()->getRight()) {
			b->parent()->setRight(b);
		}
	}
}

template<class T>
void TAVLTree<T>::BigRightRotate(TAVLTreeNode<T>* a) {
	TAVLTreeNode<T>* b = a->getLeft();
	TAVLTreeNode<T>* c = a->getLeft()->getRight();
	TAVLTreeNode<T>* M = a->getLeft()->getRight()->getLeft();
	TAVLTreeNode<T>* N = a->getLeft()->getRight()->getRight();

	b->setRight(M);
	a->setLeft(N);
	M->setParent(b);
	N->setParent(a);
	c->setParent(a->parent());
	c->setRight(a);
	c->setLeft(b);
	a->setParent(c);
	b->setParent(c);
}

template<class T>
void TAVLTree<T>::balancing(TAVLTreeNode<T>* p) {
	int bf = bfactor(p);
	if ((height(p->getRight()->getLeft()) <= height(p->getRight()->getRight())) && p->getRight()->height() > p->getLeft()->height()) {
		SmallLeftRotate(p);
		return;
	}

	if (height(p->getRight()->getLeft()) > height(p->getRight()->getRight())) {
		BigLeftRotate(p);
		return;
	}

	if (height(p->getLeft()->getRight()) <= height(p->getLeft()->getLeft())) {
		SmallRightRotate(p);
		return;
	}

	if (p->getLeft()->getRight()->height() > p->getLeft()->getLeft()->height()) {
		BigRightRotate(p);
	}
}

//template<class T>
//void TAVLTree<T>::fixheight(TAVLTreeNode<T>* p) {
//	while (p != nullptr) {
//		if (p->) {
//			p->setHeight(p->height() + 1);
//		}	
//	}
//}


template<class T>
void TAVLTree<T>::fixheight(TAVLTreeNode<T>* p)
{
	
	if (p == nullptr) {
		return;
	}
	
	int hl = height(p->getLeft());
	int hr = height(p->getRight());
	if (hl == hr || hl - hr == 1 || hr - hl == 1) {
		p->setHeight((hl > hr ? hl : hr) + 1);
		fixheight(p->parent());
		return;
	}
	p->setHeight((hl > hr ? hl : hr) + 1);
	balancing(p);
	fixheight(p->parent());
}

template<class T>
T TAVLTree<T>::insert(T val) {
	TAVLTreeNode<T>* node = new TAVLTreeNode<T>(val);

	if (_head == nullptr) {
		_head = node;
		return _head->value();
	}

	TAVLTreeNode<T>* cur = _head;
	while (cur != nullptr) {
		if (cur->value() == val) {
			throw std::logic_error("The value is already exists");
		}
		if (val < cur->value()) {
			if (cur->getLeft() == nullptr) {
				cur->setLeft(node);
				node->setParent(cur);
				fixheight(cur);
				return node->value();
			}
			cur = cur->getLeft();
		}
		else {
			if (cur->getRight() == nullptr) {
				cur->setRight(node);
				node->setParent(cur);
				fixheight(cur);
				return node->value();
			}
			cur = cur->getRight();
		}
	}
}

template<class T>
void TAVLTree<T>::clear() {
	clear(_head);
	_head = nullptr;
}

template<class T>
void TAVLTree<T>::clear(TAVLTreeNode<T>* node) {
	if (node == nullptr) {
		return;
	}

	clear(node->getLeft());
	clear(node->getRight());

	delete node;
}

#endif // LIB_AVL_TREE_