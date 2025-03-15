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


TEST(BinSearchTreeTest, defaultcons) {

	TBinSearchTree<int> tree;

	EXPECT_EQ(tree.getHead(), nullptr);
}

//TEST(BinSearchTreeTest, Insert) {
//    TBinSearchTree<int> tree;
//
//    tree.insert(10);
//    tree.insert(5);
//    tree.insert(15);
//    tree.insert(3);
//    tree.insert(7);
//
//    testing::internal::CaptureStdout();
//    tree.level(tree.getHead());
//    std::string output = testing::internal::GetCapturedStdout();
//    EXPECT_EQ(output, "10 5 15 3 7 ");
//}

TEST(BinSearchTreeTest, InsertAndSearch) {
    TBinSearchTree<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    EXPECT_NE(tree.search(10), nullptr);
    EXPECT_NE(tree.search(5), nullptr);
    EXPECT_NE(tree.search(15), nullptr);
    EXPECT_THROW(tree.search(20), std::logic_error);
}

TEST(BinSearchTreeTest, InsertCanThrow) {
    TBinSearchTree<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    EXPECT_THROW(tree.insert(10), std::logic_error);
}

TEST(BinSearchTreeTest, EraseRoot) {
    TBinSearchTree<int> tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(7);
    tree.insert(6);
    tree.insert(9);
    tree.insert(11);

    tree.erase(4);
    EXPECT_EQ(tree.getHead()->value(), 6);
    EXPECT_EQ(tree.search(7)->left(), nullptr);
    tree.clear();
}

TEST(BinSearchTreeTest, EraseNodeWithOneChild) {
    TBinSearchTree<int> tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(7);
    tree.insert(6);
    tree.insert(9);
    tree.insert(11);

    tree.erase(9);
    EXPECT_EQ(tree.getHead()->value(), 4);
    EXPECT_EQ(tree.search(7)->right()->value(), 11);
}

TEST(BinSearchTreeTest, EraseNodeWithOneSubTree) {
    TBinSearchTree<int> tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(7);
    tree.insert(9);
    tree.insert(8);
    tree.insert(11);

    tree.erase(7);
    EXPECT_EQ(tree.getHead()->value(), 4);
    EXPECT_EQ(tree.search(4)->right()->value(), 9);
}

TEST(BinSearchTreeTest, EraseNodeWithTwoChildren) {
    TBinSearchTree<int> tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(7);
    tree.insert(9);
    tree.insert(8);
    tree.insert(11);

    tree.erase(2);
    EXPECT_EQ(tree.getHead()->value(), 4);
    EXPECT_EQ(tree.search(4)->left()->value(), 3);
}

TEST(BinSearchTreeTest, Clear) {
    TBinSearchTree<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    tree.clear();
    EXPECT_EQ(tree.getHead(), nullptr);
}