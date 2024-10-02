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

