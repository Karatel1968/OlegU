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

// tests for void pop_front():START
TEST(TListTest, PopFrontTest) {

	TList<int> list;

	list.push_back(1);
	list.push_back(2);

	list.pop_front();

	TNode<int>* head = list.getHead();
	TNode<int>* tail = list.getTail();

	EXPECT_EQ(head->value(), 2);
	EXPECT_EQ(tail->value(), 2);
	EXPECT_FALSE(list.isEmpty());
}

TEST(TListTest, PopFrontTestForSingleElem) {

	TList<int> list;

	list.push_back(1);

	list.pop_front();


	EXPECT_EQ(list.getHead(), nullptr);
	EXPECT_EQ(list.getTail(), nullptr);
	EXPECT_TRUE(list.isEmpty());
}

TEST(TListTest, PopFrontFromEmptyTest) {

	TList<int> list;

	EXPECT_THROW(list.pop_front(), std::logic_error);
	EXPECT_TRUE(list.isEmpty());
}
// tests for void pop_front():END

// tests for void push_front():START
TEST(TListTest, PushFrontTest) {

	TList<int> list;

	list.push_front(1);

	TNode<int>* head = list.getHead();
	TNode<int>* tail = list.getTail();

	EXPECT_EQ(head->value(), 1);
	EXPECT_EQ(tail->value(), 1);
	EXPECT_FALSE(list.isEmpty());
}

TEST(TListTest, PushFrontForSeveralElemTest) {

	TList<int> list;

	list.push_front(1);

	TNode<int>* head = list.getHead();
	TNode<int>* tail = list.getTail();

	EXPECT_EQ(head->value(), 1);
	EXPECT_EQ(tail->value(), 1);
	EXPECT_FALSE(list.isEmpty());

	list.push_front(2);

	TNode<int>* head_2 = list.getHead();
	TNode<int>* tail_2 = list.getTail();

	EXPECT_EQ(head_2->value(), 2);
	EXPECT_EQ(tail_2->value(), 1);
	EXPECT_FALSE(list.isEmpty());
}
// tests for void push_front():END

// tests for void push_back():START
TEST(TListTest, PushBackTest) {

	TList<int> list;

	list.push_back(1);

	TNode<int>* head = list.getHead();
	TNode<int>* tail = list.getTail();

	EXPECT_EQ(head->value(), 1);
	EXPECT_EQ(tail->value(), 1);
	EXPECT_FALSE(list.isEmpty());
}

TEST(TListTest, PushBackSeveralElemTest) {

	TList<int> list;

	list.push_back(1);

	TNode<int>* head = list.getHead();
	TNode<int>* tail = list.getTail();

	EXPECT_EQ(head->value(), 1);
	EXPECT_EQ(tail->value(), 1);
	EXPECT_FALSE(list.isEmpty());

	list.push_back(5);

	TNode<int>* head_2 = list.getHead();
	TNode<int>* tail_2 = list.getTail();

	EXPECT_EQ(head_2->value(), 1);
	EXPECT_EQ(tail_2->value(), 5);
	EXPECT_FALSE(list.isEmpty());
}
// tests for void push_back():END

