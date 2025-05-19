// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_l_stack/TLStack.h"


#define EPSILON 0.000001

TEST(TLStackTest, BaseConstructorTest) {

	TLStack<int> stack;

	EXPECT_TRUE(stack.isEmpty());

	stack.push(1);

	EXPECT_FALSE(stack.isEmpty());
}

TEST(TLStackTest, PushTest) {

	TLStack<int> stack;

	EXPECT_TRUE(stack.isEmpty());

	stack.push(1);
	stack.push(2);
	stack.push(3);

	EXPECT_EQ(stack.size(), 3);

}

TEST(TLStackTest, PopTest) {

	TLStack<int> stack;

	EXPECT_TRUE(stack.isEmpty());

	stack.push(1);
	stack.push(2);
	stack.push(3);

	stack.pop();

	EXPECT_EQ(stack.size(), 2);

	stack.pop();

	EXPECT_EQ(stack.size(), 1);
}




