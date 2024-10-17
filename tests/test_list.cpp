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
TEST(TListTest, ReplaceTest) {

	TList<int> list;

	list.push_front(1);
	list.push_front(2);

	TNode<int> newNode(5);

	list.replace(list.find(2), &newNode);

	EXPECT_EQ(list.find(5)->value(), 5);

}

TEST(TListTest, ReplaceCanThrowTest) {
	TList<int> list;

	list.push_front(1);
	list.push_front(2);

	TNode<int> newNode(5);

	EXPECT_THROW(list.replace(list.find(4), &newNode), std::logic_error);

}

TEST(TListTest, ReplaceCanThrow2Test) {
	TList<int> list;

	list.push_front(1);
	list.push_front(2);

	TNode<int> newNode(5);
	TNode<int>* node = nullptr;

	EXPECT_THROW(list.replace(node, &newNode), std::logic_error);

}
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

// tests for insert(TNode<T>* node, const T* val):START
TEST(TListTest, InsertTest) {

	TList<int> list;

	list.push_front(2);

	TNode<int>* node = list.find(2);

	int val = 1;

	list.insert(node, &val);

	TNode<int>* head = list.getHead();
	TNode<int>* tail = list.getTail();

	EXPECT_EQ(head->value(), 2);
	EXPECT_EQ(tail->value(), 1);
	EXPECT_FALSE(list.isEmpty());
}

TEST(TListTest, InsertCanThrowTest) {

	TList<int> list;

	TNode<int>* node = list.find(2);

	int val = 1;

	EXPECT_EQ(list.getHead(), nullptr);
	EXPECT_EQ(list.getTail(), nullptr);
	EXPECT_TRUE(list.isEmpty());
	EXPECT_THROW(list.insert(node, &val), std::logic_error);
}

TEST(TListTest, InsertInBackTest) {

	TList<int> list;

	list.push_front(1);
	list.push_back(2);
	list.push_back(3);

	TNode<int>* tail = list.getTail();

	EXPECT_EQ(tail->value(), 3);

	TNode<int>* node = list.find(3);

	int val = 4;

	list.insert(node, &val);

	TNode<int>* tail_2 = list.getTail();

	EXPECT_EQ(tail_2->value(), 4);

}
// tests for insert(TNode<T>* node, const T* val):END

// tests for find:START
TEST(TListTest, FindTest) {

	TList<int> list;

	list.push_front(1);
	list.push_back(2);
	list.push_back(3);

	TNode<int>* node = list.find(2);

	ASSERT_NE(node, nullptr);
	EXPECT_EQ(node->value(), 2);

}

TEST(TListTest, FindCanAssertTest) {

	TList<int> list;

	TNode<int>* node = list.find(2);;

	EXPECT_EQ(node, nullptr);

}

TEST(TListTest, FindCantFindNonExitingElemTest) {
	TList<int> list;

	list.push_front(1);
	list.push_back(2);
	list.push_back(3);

	TNode<int>* node = list.find(4);

	EXPECT_EQ(node, nullptr);
}
// tests for find:END

// tests for void pop_back():START
TEST(TListTest, PopBackTest) {

	TList<int> list;

	list.push_front(1);
	list.push_back(2);
	list.push_back(3);

	TNode<int>* tail = list.getTail();

	EXPECT_EQ(tail->value(), 3);

	list.pop_back();

	TNode<int>* tail_2 = list.getTail();

	EXPECT_EQ(tail_2->value(), 2);

}

TEST(TListTest, PopBackCanThrowTest) {

	TList<int> list;

	EXPECT_THROW(list.pop_back(), std::logic_error);

}
// tests for void pop_back():END

// tests for void erase():START
TEST(TListTest, EraseTest) {

	TList<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	TNode<int>* node = list.find(2);

	list.erase(node);

	TNode<int>* head = list.getHead();

	EXPECT_EQ(head->next()->value(), 3);

}

TEST(TListTest, EraseFromBackTest) {

	TList<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	TNode<int>* node = list.find(3);

	list.erase(node);

	TNode<int>* tail = list.getTail();

	EXPECT_EQ(tail->value(), 2);
	EXPECT_EQ(tail->next(), nullptr);

}
// tests for void erase():END