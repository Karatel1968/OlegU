// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_stack/TStack.h"

#define EPSILON 0.000001

// Для DefoultConstrucktor:START
TEST(TStackTest, DefoultConstrucktorworcks) {
	
TStack<int> stack(10);

EXPECT_TRUE(stack.isEmpty());
EXPECT_TRUE(stack.isEmpty());
}
// Для DefoultConstrucktor:END

// Для Method Push:START
TEST(TStackTest, MethodPushWorcks) {

TStack<int> stack(10);
stack.push(10);

EXPECT_FALSE(stack.isEmpty());
EXPECT_EQ(stack.top(), 10);
}

TEST(TStackTest, MethodPushThrowsTheError) {

	TStack<int> stack(3);
	stack.push(1);
	stack.push(2);
	stack.push(3);

	EXPECT_TRUE(stack.isFull());
	EXPECT_THROW(stack.push(4), std::logic_error);
}
// Для Method Push:END