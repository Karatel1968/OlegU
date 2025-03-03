// Copyright 2024 Urin Oleg

#include <gtest.h>
#include <iostream>
#include <sstream>
#include <functional>
#include "../lib_algorithms/algorithms.cpp"


#define EPSILON 0.000001

//#define CYCLETEST
#ifdef CYCLETEST
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

	TNode<int>* tail = list.getTail();

	tail->setNext(list.getHead());
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
#endif

class AlgorithmsTest : public ::testing::Test {
protected:
	void captureOutput(std::function<void()> func, std::string& output) {
		std::stringstream buffer;
		std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
		func();
		std::cout.rdbuf(old);
		output = buffer.str();
	}
};

TEST_F(AlgorithmsTest, ListsMerge) {
	TList<int> list1;
	list1.push_back(4);
	list1.push_back(5);
	list1.push_back(6);
	TList<int> list2;
	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(4);

	std::string output;
	captureOutput([&]() { listMerge(list1, list2); }, output);

	EXPECT_EQ(output, "1 2 3 4 4 5 6 ");

}


