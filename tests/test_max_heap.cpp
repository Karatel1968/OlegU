// Copyright 2024 Urin Oleg

#include <gtest.h>

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

#define EPSILON 0.000001

#include "../lib_max_heap/TMaxHeap.h"

TEST(MaxHeap, BaseConstructor) {
    MaxHeap<int> heap;
    EXPECT_EQ(heap.is_empty(), true);
    EXPECT_EQ(heap.size(), 0);
}