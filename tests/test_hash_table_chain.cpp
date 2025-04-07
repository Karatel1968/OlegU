#include <gtest.h>

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include "../Hash_table_chain.h"

#define EPSILON 0.000001

TEST(THTableCTest, DefaultConstructor) {
    THTableC<int> table;

    EXPECT_EQ(table.size(), 0);
}

TEST(THTableCTest, ParameterizedConstructor) {
    int size = 10;
    THTableC<int> table(size);

    EXPECT_EQ(table.size(), size);


    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(table.getState(i), empty);
    }
}

TEST(THTableCTest, CopyConstructor) {
    int size = 10;
    THTableC<int> original(size);

    THTableC<int> copy(original);

    EXPECT_EQ(copy.size(), original.size());

    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(copy.getState(i), original.getState(i));
    }
}