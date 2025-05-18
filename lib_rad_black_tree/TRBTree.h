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
	TRBTreeNode<T>* findNode(T val); 
	TRBTreeNode<T>* minNode(TRBTreeNode<T>* node);
	TRBTreeNode<T>* maxNode(TRBTreeNode<T>* node);
	void fixErase(TRBTreeNode<T>* node, TRBTreeNode<T>* parent);
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
TRBTreeNode<T>* TRBTree<T>::findNode(T val) {
	TRBTreeNode<T>* cur = _head;
	while (cur != nullptr) {
		if (cur->value() == val) {
			return cur;
		}
		if (val < cur->value()) {
			cur = cur->left();
		}
		else {
			cur = cur->right();
		}
	}
	return nullptr;
}

template<class T>
TRBTreeNode<T>* TRBTree<T>::minNode(TRBTreeNode<T>* node) {
	while (node->left() != nullptr) {
		node = node->left();
	}
	return node;
}

template<class T>
TRBTreeNode<T>* TRBTree<T>::maxNode(TRBTreeNode<T>* node) {
	while (node->right() != nullptr) {
		node = node->right();
	}
	return node;
}


//template<class T>
//void TRBTree<T>::erase(T val) {
//	TRBTreeNode<T>* node = findNode(val);
//	if (node == nullptr) {
//		throw std::logic_error("Value not found");
//	}
//
//	TRBTreeNode<T>* replacement = nullptr;
//	bool isOriginalBlack = node->color();
//
//	if (node->left() == nullptr || node->right() == nullptr) {
//		
//		replacement = (node->left() != nullptr) ? node->left() : node->right();
//	}
//	else {
//		
//		replacement = minNode(node->right());
//		node->setValue(replacement->value());
//	}
//	
//	if (replacement != nullptr) {
//		TRBTreeNode<T>* child = (replacement->left() != nullptr) ? replacement->left() : replacement->right();
//		if (child != nullptr) {
//			child->setParent(replacement->getParent());
//		}
//
//		if (replacement->getParent() == nullptr) {
//			_head = child;
//		}
//		else if (replacement == replacement->getParent()->left()) {
//			replacement->getParent()->setLeft(child);
//		}
//		else {
//			replacement->getParent()->setRight(child);
//		}
//
//		if (replacement != node) {
//			node->setValue(replacement->value());
//		}
//
//		if (isOriginalBlack) {
//			fixErase(child, replacement->getParent());
//		}
//
//		delete replacement;
//	}
//	else {
//		fixErase(node, node->getParent());
//		if (node == node->getParent()->getLeft()) {
//			node->getParent()->setLeft(nullptr);
//		}
//		else {
//			node->getParent()->setRight(nullptr);
//		}
//		delete node;
//		
//		return;
//	}
//}

template<class T>
void TRBTree<T>::erase(T val) {
	TRBTreeNode<T>* node = findNode(val);
	if (node == nullptr) {
		throw std::logic_error("Value not found");
	}

	TRBTreeNode<T>* replacement = nullptr;
	TRBTreeNode<T>* child = nullptr;
	bool isOriginalBlack = node->color();

	if (node->left() == nullptr || node->right() == nullptr) {
		// Node has 0 or 1 child
		replacement = node;
		child = (node->left() != nullptr) ? node->left() : node->right();

		if (child != nullptr) {
			child->setParent(node->getParent());
		}

		if (node->getParent() == nullptr) {
			_head = child;
		}
		else if (node == node->getParent()->left()) {
			node->getParent()->setLeft(child);
		}
		else {
			node->getParent()->setRight(child);
		}
	}
	else {
		// Node has 2 children - find successor
		replacement = minNode(node->right());
		isOriginalBlack = replacement->color();
		child = replacement->right();

		if (replacement->getParent() == node) {
			if (child != nullptr) {
				child->setParent(replacement);
			}
		}
		else {
			// Move replacement's right child to replacement's position
			if (child != nullptr) {
				child->setParent(replacement->getParent());
			}
			replacement->getParent()->setLeft(child);
			replacement->setRight(node->right());
			node->right()->setParent(replacement);
		}

		// Replace node with replacement
		replacement->setParent(node->getParent());
		if (node->getParent() == nullptr) {
			_head = replacement;
		}
		else if (node == node->getParent()->left()) {
			node->getParent()->setLeft(replacement);
		}
		else {
			node->getParent()->setRight(replacement);
		}

		replacement->setLeft(node->left());
		node->left()->setParent(replacement);
		replacement->setColor(node->color());
	}

	if (isOriginalBlack) {
		fixErase(child, (replacement->getParent() == nullptr) ? nullptr :
			(child == nullptr) ? replacement->getParent() : child->getParent());
	}

	if (node->left() == nullptr || node->right() == nullptr) {
		delete node;
	}
	else {
		delete replacement;
	}
}

template<class T>
void TRBTree<T>::fixErase(TRBTreeNode<T>* node, TRBTreeNode<T>* parent) {
	while (node != _head && (node == nullptr || node->color() == false)) {
		if (node == parent->left()) {
			TRBTreeNode<T>* sibling = parent->right();

			if (sibling != nullptr) {
				return;
			}
			if (sibling->color() == true) {
				//1: Красный брат
				sibling->setColor(false);
				parent->setColor(true);
				leftRotate(sibling);
				sibling = parent->right();
			}

			if ((sibling->left() == nullptr || sibling->left()->color() == false) &&
				(sibling->right() == nullptr || sibling->right()->color() == false)) {
				// 2: Чёрный брат с чёрными детьми
				sibling->setColor(true);
				sibling->getParent()->setColor(false);
				node = parent;
				parent = node->getParent();
			}
			else {
				if (sibling->right() == nullptr || sibling->right()->color() == false) {
					// 3: Чёрный брат с красным левым ребёнком
					sibling->left()->setColor(false);
					sibling->setColor(true);
					rightRotate(sibling);
					sibling = parent->right();
				}

				// 4: Чёрный брат с красным правым ребёнком
				sibling->setColor(parent->color());
				parent->setColor(false);
				sibling->right()->setColor(false);
				leftRotate(parent);
				node = _head;
			}
			
		}
		else {
			TRBTreeNode<T>* sibling = parent->left();

			if (sibling->color() == true) {
				// 1: Красный брат
				sibling->setColor(false);
				parent->setColor(true);
				rightRotate(parent);
				sibling = parent->left();
			}

			if ((sibling->left() == nullptr || sibling->left()->color() == false) &&
				(sibling->right() == nullptr || sibling->right()->color() == false)) {
				// 2: Чёрный брат с чёрными детьми
				sibling->setColor(true);
				node = parent;
				parent = node->getParent();
			}
			else {
				if (sibling->left() == nullptr || sibling->left()->color() == false) {
					// 3: Чёрный брат с красным правым ребёнком
					sibling->right()->setColor(false);
					sibling->setColor(true);
					leftRotate(sibling);
					sibling = parent->left();
				}

				// 4: Чёрный брат с красным левым ребёнком
				sibling->setColor(parent->color());
				parent->setColor(false);
				sibling->left()->setColor(false);
				rightRotate(parent);
				node = _head;
			}
		}
	}

	if (node != nullptr) {
		node->setColor(false);
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

	if (G != nullptr) {
		if (P == G->getLeft()) {
			G->setLeft(X);
			X->setParent(G);
		}
		else {
			G->setRight(X);
			X->setParent(G);
		}
	}
	else {
		_head = X;
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