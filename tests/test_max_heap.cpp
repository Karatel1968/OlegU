// Copyright 2024 Urin Oleg

#include <gtest.h>

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

#define EPSILON 0.000001

#include "../lib_max_heap/TMaxHeap.h"

TEST(MaxHeapTest, BaseConstructor) {
    MaxHeap<int> heap;
    EXPECT_EQ(heap.is_empty(), true);
    EXPECT_EQ(heap.size(), 0);
}

TEST(MaxHeapTest, ArrayConstructor) {
    int arr[] = { 10, 20, 5, 30, 40, 3 };
    MaxHeap<int> heap(6, arr);
    EXPECT_EQ(heap.is_empty(), false);
    EXPECT_EQ(heap.size(), 6);
    EXPECT_EQ(heap.maximum(), 40);

    EXPECT_EQ(heap.data(0), arr[4]);
    EXPECT_EQ(heap.data(1), arr[3]);
    EXPECT_EQ(heap.data(2), arr[2]);
    EXPECT_EQ(heap.data(3), arr[0]);
    EXPECT_EQ(heap.data(4), arr[1]);
    EXPECT_EQ(heap.data(5), arr[5]);
}

TEST(MaxHeapTest, InsertIntoEmptyHeap) {
    MaxHeap<int> heap;
    heap.insert(10);
    EXPECT_EQ(heap.maximum(), 10);
    EXPECT_EQ(heap.size(), 1);
}

TEST(MaxHeapTest, InsertNewMaxElement) {
    MaxHeap<int> heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);
    heap.insert(40);
    heap.insert(3);
    EXPECT_EQ(heap.maximum(), 40);
    EXPECT_EQ(heap.size(), 6);
    heap.insert(50);
    EXPECT_EQ(heap.maximum(), 50);
    EXPECT_EQ(heap.data(heap.left(0)), 30);
    EXPECT_EQ(heap.data(heap.right(0)), 40);
    EXPECT_EQ(heap.size(), 7);
}