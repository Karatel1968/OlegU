// Copyright 2024 Urin Oleg

#include <gtest.h>

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

#include "../lib_avl_tree/TAVLTree.h"

#define EPSILON 0.000001

TEST(AVLTreeTest, InsertIntoEmptyTree) {
    TAVLTree<int> tree;
    tree.insert(10);
    EXPECT_EQ(tree.getHead()->value(), 10);
}