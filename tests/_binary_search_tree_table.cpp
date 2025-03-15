// Copyright 2024 Urin Oleg

#include <gtest.h>

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

#include "../lib_binary_search_tree_table/TBSTTable.h"

#define EPSILON 0.000001

TEST(TBSTTableTest, BaseConstructor) {

	TBSTTable<int, std::string> table;

	EXPECT_EQ(table.size(), 0);
}

TEST(TBSTTableTest, ParameterizedConstructor) {

    TBinSearchTree<std::pair<int, std::string>> data;
    std::pair<int, std::string> pair(1, "one");
    
    TBSTTable<int, std::string> tableWithData(data);

    EXPECT_EQ(tableWithData.size(), 1);
}

TEST(TBSTTableTest, InsertValue) {
    TBSTTable<int, std::string> data;
    data.insert("test_value");
    EXPECT_EQ(data.size(), 1);

}

TEST(TBSTTableTest, InsertKeyValue) {
    TBSTTable<int, std::string> table;
    table.insert(2, "one");
    EXPECT_EQ(table.size(), 1);
}