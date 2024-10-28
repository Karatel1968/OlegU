// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_algorithms/algorithms.cpp"


#define EPSILON 0.000001

// Метод черепахи:START
TEST(AlgorithmsTest, TurtleTest) {
	TList<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	
	EXPECT_FALSE(isCircle_turtle(list));
}

TEST(AlgorithmsTest, TurtleHasCycleTest) {
	TList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	TNode<int>* head = list.getHead();
	TNode<int>* tail = list.getTail();

	tail->setNext(head);
	EXPECT_TRUE(isCircle_turtle(list));
	tail->setNext(nullptr);
}
// Метод черепахи:END

// Метод разворота:START
TEST(AlgorithmsTest, ReverseHasCycleTest) {
	TList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	TNode<int>* head = list.getHead();
	TNode<int>* tail = list.getTail();

	tail->setNext(head);
	EXPECT_TRUE(isCircle_reverse(list));
	tail->setNext(nullptr);
}

TEST(AlgorithmsTest, ReverseCycleTest) {
	TList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	TNode<int>* head = list.getHead();
	TNode<int>* tail = list.getTail();

	EXPECT_FALSE(isCircle_reverse(list));
}
// Метод разворота:END

