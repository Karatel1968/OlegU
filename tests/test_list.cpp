// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_list/TList.h"


#define EPSILON 0.000001

TEST(TListTest, BaseConstructorTes) {

	TList<int> list;

	EXPECT_TRUE(list.isEmpty());

	list.push_front(1);

	EXPECT_FALSE(list.isEmpty());
}

// tests for void replace(TNode<T>* node):START
/*TEST(TListTest, ReplaceTest) {

	TList<int> list;

	list.push_front(1);
	list.push_front(2);

	TNode<int> newNode(5);

	list.replace(list.find(2), &newNode);

	EXPECT_EQ(list.find(2)->value(), 5);

}*/
// tests for void replace(TNode<T>* node):END

// tests for void replace(TNode<T>* node):START
TEST(TListTest, PopFrontTest) {

	TList<int> list;

	list.push_back(1);
	list.push_back(2);

	list.pop_front();

	TNode<int>* head = list.getHead();

	EXPECT_EQ(head->value(), 2);

}
// tests for void replace(TNode<T>* node):END