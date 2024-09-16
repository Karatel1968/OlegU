// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_stack/TStack.h"

#define EPSILON 0.000001

TEST(TStackTest, DefoultConstrucktorworcks) {
	
TStack<int> stack(10);

EXPECT_TRUE(stack.isEmpty());
EXPECT_TRUE(stack.isEmpty());
}

TEST(TStackTest, MethodPushWorcks) {

TStack<int> stack(10);
stack.push(10);

EXPECT_FALSE(stack.isEmpty());
EXPECT_EQ(stack.top(), 10);
}