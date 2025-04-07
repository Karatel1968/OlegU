// Copyright 2024 Urin Oleg

#include <gtest.h>

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include "../Hash_table_open_mix.h"

#define EPSILON 0.000001


TEST(THTableOMTest, DefaultConstructor) {
    THTableOM<int> table; 

    EXPECT_EQ(table.size(), 0);
}

TEST(THTableOMTest, ParameterizedConstructor) {
    int size = 10;
    THTableOM<int> table(size); 

    EXPECT_EQ(table.size(), size);

    
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(table.getState(i), empty);
    }
}

TEST(THTableOMTest, CopyConstructor) {
    int size = 10;
    THTableOM<int> original(size); 

    THTableOM<int> copy(original);
   
    EXPECT_EQ(copy.size(), original.size());

    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(copy.getState(i), original.getState(i));
    }
}

TEST(THTableOMTest, Insert) {
    THTableOM<int> table(20);

    table.insert("pol", 100);

    EXPECT_EQ(table.getState(11), busy);
    
}

TEST(THTableOMTest, InsertCanThrow) {
    THTableOM<int> table(20);

    table.insert("pol", 100);

    EXPECT_THROW(table.insert("pol", 300), std::logic_error);

}

TEST(THTableOMTest, InsertCanDealWithCollision) {
    THTableOM<int> table(20);

    table.insert("pol", 100);

    EXPECT_NO_THROW(table.insert("ned", 300), std::logic_error);
}

TEST(THTableOMTest, Erase) {
    THTableOM<int> table(20);

    table.insert("pol", 100);
    table.insert("ned", 200);

    EXPECT_EQ(table.getState(11), busy);
    table.erase("pol");

    EXPECT_EQ(table.getState(11), deleted);
}

TEST(THTableOMTest, EraseCanThrow) {
    THTableOM<int> table(10);

    EXPECT_THROW(table.erase("key"), std::logic_error); 
}

TEST(THTableOMTest, FindCanThrow) {
    THTableOM<int> table(20);

    EXPECT_THROW(table.find("key"), std::logic_error); 
}

TEST(THTableOMTest, Find) {
    THTableOM<int> table(20);

    table.insert("pol", 100);
    table.insert("ned", 200);

    EXPECT_EQ(table.find("pol"), 100);
    EXPECT_EQ(table.find("ned"), 200);
}