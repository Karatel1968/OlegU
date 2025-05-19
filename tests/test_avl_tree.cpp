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
    /*
            a				  b
          /	  \             /   \
         L	   b	->	   a	 R
        	  / \	      / \   
             C	 R       L   C
    */
    TAVLTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    EXPECT_EQ(tree.getHead()->value(), 20);
    EXPECT_EQ(tree.getHead()->getLeft()->value(), 10);
    EXPECT_EQ(tree.getHead()->getRight()->value(), 30);
}

TEST(AVLTreeTest, WideFirstCase) {
    /*
            a				  b
          /	  \             /   \
         L	   b	->	   a	 R
              / \	      / \
             C	 R       L   C
    */
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

TEST(AVLTreeTest, SecondCase) {
    /*
            a				  c
          /	  \             /   \
         L	   b	->	   a	 b
              / \	      / \   / \
             c   R       L   M N   R
            / \
           M   N
    */
    TAVLTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(12);
    EXPECT_EQ(tree.getHead()->value(), 15);
    EXPECT_EQ(tree.getHead()->getRight()->value(), 20);
    EXPECT_EQ(tree.getHead()->getRight()->getRight()->value(), 30);
    EXPECT_EQ(tree.getHead()->getLeft()->value(), 10);
    EXPECT_EQ(tree.getHead()->getLeft()->getLeft()->value(), 5);
    EXPECT_EQ(tree.getHead()->getLeft()->getRight()->value(), 12);
}

TEST(AVLTreeTest, FirdtCase) {
    /*
            a				  b
          /	  \             /   \
         b	   R	->	   L	 a
        / \     	            / \
       L   C                   C   R
    */
    TAVLTree<int> tree;
    tree.insert(30);
    tree.insert(40);
    tree.insert(20);
    tree.insert(10);
    tree.insert(25);
    tree.insert(5);
    EXPECT_EQ(tree.getHead()->value(), 20);
    EXPECT_EQ(tree.getHead()->getLeft()->value(), 10);
    EXPECT_EQ(tree.getHead()->getLeft()->getLeft()->value(), 5);
    EXPECT_EQ(tree.getHead()->getRight()->value(), 30);
    EXPECT_EQ(tree.getHead()->getRight()->getRight()->value(), 40);
    EXPECT_EQ(tree.getHead()->getRight()->getLeft()->value(), 25);
}

TEST(AVLTreeTest, BigRightRotate) {
    /*
            a				  c
          /	  \             /   \
         b	   R	->	   b	 a
        / \     	      / \   / \
       L   c             L   M N   R
          / \
         M   N
    */
    TAVLTree<int> tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);
    tree.insert(16);
    EXPECT_EQ(tree.getHead()->value(), 15);
    EXPECT_EQ(tree.getHead()->getRight()->value(), 20);
    EXPECT_EQ(tree.getHead()->getRight()->getRight()->value(), 30);
    EXPECT_EQ(tree.getHead()->getLeft()->value(), 10);
    EXPECT_EQ(tree.getHead()->getLeft()->getLeft()->value(), 5);
    EXPECT_EQ(tree.getHead()->getRight()->getLeft()->value(), 16);
}

TEST(AVLTreeTest, EraseLeafTest) {
    TAVLTree<int> tree;
    tree.insert(30);
    tree.insert(40);
    tree.insert(20);
    tree.insert(10);
    tree.insert(25);
    tree.insert(5);
    tree.erase(5);
    EXPECT_EQ(tree.getHead()->height(), 3);
    EXPECT_EQ(tree.getHead()->getLeft()->height(), 1);
    EXPECT_EQ(tree.getHead()->getLeft()->getLeft(), nullptr);
    EXPECT_EQ(tree.getHead()->getRight()->value(), 30);
    EXPECT_EQ(tree.getHead()->getRight()->getRight()->value(), 40);
    EXPECT_EQ(tree.getHead()->getRight()->getLeft()->value(), 25);
}

TEST(AVLTreeTest, EraseNodeWithRighrChildTest) {
    TAVLTree<int> tree;
    tree.insert(30);
    tree.insert(40);
    tree.insert(20);
    tree.insert(10);
    tree.insert(25);
    tree.insert(5);
    tree.insert(50);
    tree.erase(40);
    EXPECT_EQ(tree.getHead()->height(), 3);
    EXPECT_EQ(tree.getHead()->getLeft()->height(), 2);
    EXPECT_EQ(tree.getHead()->getLeft()->getLeft()->value(), 5);
    EXPECT_EQ(tree.getHead()->getRight()->value(), 30);
    EXPECT_EQ(tree.getHead()->getRight()->height(), 2);
    EXPECT_EQ(tree.getHead()->getRight()->getRight()->value(), 50);
    EXPECT_EQ(tree.getHead()->getRight()->getRight()->height(), 1);
    EXPECT_EQ(tree.getHead()->getRight()->getLeft()->value(), 25);
}

TEST(AVLTreeTest, EraseNodeWithTwoChildrenSLRotateTest) {
    TAVLTree<int> tree;
    tree.insert(30);
    tree.insert(40);
    tree.insert(20);
    tree.insert(10);
    tree.insert(25);
    tree.insert(5);
    tree.insert(50);
    tree.erase(30);
    EXPECT_EQ(tree.getHead()->height(), 3);
    EXPECT_EQ(tree.getHead()->getLeft()->height(), 2);
    EXPECT_EQ(tree.getHead()->getLeft()->getLeft()->value(), 5);
    EXPECT_EQ(tree.getHead()->getRight()->value(), 40);
    EXPECT_EQ(tree.getHead()->getRight()->height(), 2);
    EXPECT_EQ(tree.getHead()->getRight()->getRight()->value(), 50);
    EXPECT_EQ(tree.getHead()->getRight()->getRight()->height(), 1);
    EXPECT_EQ(tree.getHead()->getRight()->getLeft()->value(), 25);
}

TEST(AVLTreeTest, EraseNodeWithTwoChildrenBLRotateTest) {
    TAVLTree<int> tree;
    tree.insert(30);
    tree.insert(40);
    tree.insert(20);
    tree.insert(10);
    tree.insert(25);
    tree.insert(5);
    tree.insert(21);
    tree.erase(20);
    EXPECT_EQ(tree.getHead()->height(), 3);
    EXPECT_EQ(tree.getHead()->value(), 25);
    EXPECT_EQ(tree.getHead()->getLeft()->height(), 2);
    EXPECT_EQ(tree.getHead()->getLeft()->getLeft()->value(), 5);
    EXPECT_EQ(tree.getHead()->getRight()->value(), 30);
    EXPECT_EQ(tree.getHead()->getRight()->height(), 2);
    EXPECT_EQ(tree.getHead()->getRight()->getRight()->value(), 40);
    EXPECT_EQ(tree.getHead()->getRight()->getRight()->height(), 1);
    EXPECT_EQ(tree.getHead()->getLeft()->value(), 10);
}

TEST(AVLTreeTest, EraseNodeWithTwoChildrenSRRotateTest) {
    TAVLTree<int> tree;
    tree.insert(30);
    tree.insert(40);
    tree.insert(20);
    tree.insert(10);
    tree.insert(25);
    tree.erase(40);
    EXPECT_EQ(tree.getHead()->height(), 3);
    EXPECT_EQ(tree.getHead()->value(), 20);
    EXPECT_EQ(tree.getHead()->getLeft()->height(), 1);
    EXPECT_EQ(tree.getHead()->getLeft()->value(), 10);
    EXPECT_EQ(tree.getHead()->getRight()->value(), 30);
    EXPECT_EQ(tree.getHead()->getRight()->height(), 2);
    EXPECT_EQ(tree.getHead()->getRight()->getLeft()->value(), 25);
}

TEST(AVLTreeTest, EraseNodeWithTwoChildrenBRRotateTest) {
    TAVLTree<int> tree;
    tree.insert(30);
    tree.insert(40);
    tree.insert(20);
    tree.insert(10);
    tree.insert(25);
    tree.erase(40);
    EXPECT_EQ(tree.getHead()->height(), 3);
    EXPECT_EQ(tree.getHead()->value(), 20);
    EXPECT_EQ(tree.getHead()->getLeft()->height(), 1);
    EXPECT_EQ(tree.getHead()->getLeft()->value(), 10);
    EXPECT_EQ(tree.getHead()->getRight()->value(), 30);
    EXPECT_EQ(tree.getHead()->getRight()->height(), 2);
    EXPECT_EQ(tree.getHead()->getRight()->getLeft()->value(), 25);
}