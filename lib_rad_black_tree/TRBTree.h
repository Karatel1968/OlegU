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
	T search(T val);
	T insert(T val);
	void erase(T val);
	void print(TRBTreeNode<T>* node, std::string prefix, bool isTail);
	void print();
	void level(TRBTreeNode<T>* root);
	
	TRBTreeNode<T>* getHead() {
		return _head;
	}

};

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
void TRBTree<T>::leftRotate(TRBTreeNode<T>* node) {
	TRBTreeNode<T>* p = node->getParent();
	TRBTreeNode<T>* g = p->getParent();

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
void TRBTree<T>::rightRotate(TRBTreeNode<T>* node) {
	TRBTreeNode<T>* p = node->getParent();
	TRBTreeNode<T>* g = p->getParent();

	if (p == g->getLeft()) {
		g->setLeft(p->getRight());
		if (g->getLeft() != nullptr) {
			g->getLeft()->setParent(g);
		}
	}
	else {
		g->setRight(p->getLeft());
		if (g->getRight() != nullptr) {
			g->getRight()->setParent(g);
		}
	}
	
	p->setRight(g);
	p->setParent(g->getParent());
	g->setParent(p);
	
}

template<class T>
void TRBTree<T>::print(TRBTreeNode<T>* node, std::string prefix, bool isTail) {
	if (node == nullptr) {
		return;
	}

	std::cout << prefix;

	std::string color;
	std::string reset = "\033[0m";
	if (node->color()) {
		color = "\033[31m"; // Красный цвет
		std::cout << "[" << color << node->value() << reset << "]";
	}
	else {
		color = "\033[30m"; // Чёрный цвет
		std::cout << "(" << color << node->value() << reset << ")";
	}

	if (node->left() != nullptr || node->right() != nullptr) {
		std::cout << "/"
	}
	std::cout << std::endl;

	print(node->left(), prefix + (isTail ? "    " : "│   "), false);
	print(node->right(), prefix + (isTail ? "    " : "│   "), true);
}

template<class T>
void TRBTree<T>::print() {
	if (_head == nullptr) {
		std::cout << "Tree is empty." << std::endl;
		return;
	}
	print(_head, "                        ", true);
}

template<class T>
void TRBTree<T>::level(TRBTreeNode<T>* root) {
	if (!root) return;

	std::queue<TRBTreeNode<T>*> q;
	q.push(root);
	std::string color;
	std::string reset = "\033[0m";

	while (1) {
		TRBTreeNode<T>* current = q.front();
		q.pop();
		if (current->color()) {
			color = "\033[31m";
			std::cout << "[" << color << current->value() << reset << "]" << ' ';
			
		}
		else {
			//color = "\033[30m";
			std::cout << "(" << current->value() << ")" << ' ';
		}

		//if (current->left() == nullptr) {
		//	std::cout << "(" << "NIL" << ")" << ' ';
		//}
		//if (current->right() == nullptr) {
		//	std::cout << "(" << "NIL" << ")" << ' ';
		//}

		if (current->left()) {
			
			q.push(current->left());
			
		}
		else {
			std::cout << "(" << "NIL" << ")" << ' ';
		}

		if (current->right()) {


			q.push(current->right());
		}
		else {
			std::cout << "(" << "NIL" << ")" << ' ';
		}
	}
}
#endif // LIB_RAD_BLACK_TREE_