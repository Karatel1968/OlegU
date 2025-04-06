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