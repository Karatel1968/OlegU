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

TEST(TRBTreeTest, EraseNodeWithTwoChild) {
    TRBTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    tree.erase(15);


    EXPECT_THROW(tree.search(15), std::logic_error);
    EXPECT_EQ(tree.getHead()->getRight()->value(), 18);

}

TEST(TRBTreeTest, EraseNodeWithOneChild) {
    TRBTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);
    EXPECT_EQ(tree.getHead()->value(), 10);
    tree.erase(3);
    EXPECT_EQ(tree.getHead()->value(), 10);
    tree.erase(5);


    EXPECT_THROW(tree.search(5), std::logic_error);
    EXPECT_EQ(tree.getHead()->getLeft()->value(), 7);
}