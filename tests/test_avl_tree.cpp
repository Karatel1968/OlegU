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

TEST(AVLTreeTest, InsertExistingValue) {
    TAVLTree<int> tree;
    tree.insert(10);
    EXPECT_THROW(tree.insert(10), std::logic_error);
}

TEST(AVLTreeTest, FirstCase) {
    TAVLTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    EXPECT_EQ(tree.getHead()->value(), 20);
    EXPECT_EQ(tree.getHead()->getLeft()->value(), 10);
    EXPECT_EQ(tree.getHead()->getRight()->value(), 30);
}

TEST(AVLTreeTest, WideFirstCase) {
    TAVLTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    EXPECT_EQ(tree.getHead()->value(), 20);
    EXPECT_EQ(tree.getHead()->getLeft()->value(), 10);
    EXPECT_EQ(tree.getHead()->getRight()->value(), 40);
    EXPECT_EQ(tree.getHead()->getRight()->getRight()->value(), 50);
    EXPECT_EQ(tree.getHead()->getRight()->getLeft()->value(), 30);
}
