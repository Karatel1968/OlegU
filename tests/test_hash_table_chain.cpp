#include <gtest.h>

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include "../lib_list/TList.h"
#include "../Hash_table_chain.h"
#include "../lib_pair/pair.h"

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

TEST(THTableCTest, Insert) {
    THTableC<int> table(20);

    table.insert("pol", 100);

    EXPECT_EQ(table.getState(11), busy);

}

TEST(THTableCTest, InsertCanThrow) {
    THTableC<int> table(20);

    table.insert("pol", 100);

    EXPECT_THROW(table.insert("pol", 300), std::logic_error);

}

TEST(THTableCTest, InsertCanDealWithCollision) {
    THTableC<int> table(20);

    table.insert("pol", 100);

    EXPECT_NO_THROW(table.insert("ned", 300), std::logic_error);
}

TEST(THTableCTest, Erase) {
    THTableC<int> table(20);

    table.insert("pol", 100);
    table.insert("ned", 200);

    
    EXPECT_EQ(table.getState(11), busy);
    table.erase("pol");

    EXPECT_EQ(table.getState(11), deleted);
}

TEST(THTableCTest, EraseCanThrow) {
    THTableC<int> table(10);

    EXPECT_THROW(table.erase("key"), std::logic_error);
}