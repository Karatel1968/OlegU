// Copyright 2024 Urin Oleg

#include <gtest.h>

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

#include "../lib_rad_black_tree/TRBTree.h"

#define EPSILON 0.000001

TEST(TRBTreeTest, EraseLeaf) {
    TRBTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);
    tree.erase(3);

    
    EXPECT_THROW(tree.search(3), std::logic_error);

}