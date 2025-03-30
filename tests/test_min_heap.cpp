// Copyright 2024 Urin Oleg

#include <gtest.h>

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

#define EPSILON 0.000001

#include "../lib_min_heap/TMinHeap.h"

TEST(MinHeapTest, BaseConstructor) {
    MinHeap<int> heap;
    EXPECT_EQ(heap.is_empty(), true);
    EXPECT_EQ(heap.size(), 0);
}

TEST(MinHeapTest, ArrayConstructor) {
    int arr[] = { 10, 20, 5, 30, 40, 3 };
    MinHeap<int> heap(6, arr);
    EXPECT_EQ(heap.is_empty(), false);
    EXPECT_EQ(heap.size(), 6);
    EXPECT_EQ(heap.minimum(), 3);

}

TEST(MinHeapTest, InsertIntoEmptyHeap) {
    MinHeap<int> heap;
    heap.insert(10);
    EXPECT_EQ(heap.minimum(), 10);
    EXPECT_EQ(heap.size(), 1);
}

TEST(MinHeapTest, InsertNewMinElement) {
    MinHeap<int> heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);
    heap.insert(40);
    heap.insert(3);
    EXPECT_EQ(heap.minimum(), 3);
    EXPECT_EQ(heap.size(), 6);
    heap.insert(1);
    EXPECT_EQ(heap.minimum(), 1);
    EXPECT_EQ(heap.data(heap.left(0)), 20);
    EXPECT_EQ(heap.data(heap.right(0)), 3);
    EXPECT_EQ(heap.size(), 7);
}

TEST(MinHeapTest, InsertWithResize) {
    MinHeap<int> heap;
    for (int i = 0; i < STEP_CAPACITY; ++i) {
        heap.insert(i);
    }
    EXPECT_EQ(heap.size(), STEP_CAPACITY);
    heap.insert(100);
    EXPECT_EQ(heap.minimum(), 0);
    EXPECT_EQ(heap.size(), 16);
    EXPECT_GT(heap.capacity(), STEP_CAPACITY);
}

/*TEST(MinHeapTest, EraseLeaf) {
    MinHeap<int> heap;
    heap.insert(30);
    heap.insert(20);
    heap.insert(10);
    heap.erase(2);
    EXPECT_EQ(heap.minimum(), 30);
    EXPECT_EQ(heap.size(), 2);
}

TEST(MinHeapTest, EraseMiddleElement) {
    MinHeap<int> heap;
    heap.insert(30);
    heap.insert(20);
    heap.insert(5);
    heap.insert(10);
    heap.insert(40);
    heap.erase(2);
    EXPECT_EQ(heap.minimum(), 40);
    EXPECT_EQ(heap.data(0), 40);
    EXPECT_EQ(heap.data(1), 30);
    EXPECT_EQ(heap.data(2), 20);
    EXPECT_EQ(heap.data(3), 10);
    EXPECT_EQ(heap.size(), 4);
}

TEST(MinHeapTest, EraseFromEmptyHeap) {
    MinHeap<int> heap;
    EXPECT_TRUE(heap.is_empty());
    EXPECT_THROW(heap.erase(2), std::logic_error);
}

TEST(MinHeapTest, RemoveMax) {
    MinHeap<int> heap;
    heap.insert(30);
    heap.insert(20);
    heap.insert(5);
    heap.insert(10);
    heap.insert(40);
    EXPECT_EQ(heap.remove_min(), 40);
    EXPECT_EQ(heap.minimum(), 30);
}*/