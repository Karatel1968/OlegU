// Copyright 2024 Urin Oleg

#include <gtest.h>

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

#include "../lib_binary_search_tree/TBinSearchTree.h"
#include "../lib_binary_search_tree/BTreeNode.h"

#define EPSILON 0.000001


TEST(BinSearchTree, defaultcons) {

	TBinSearchTree<int> tree;

	EXPECT_EQ(tree.getHead(), nullptr);
}

