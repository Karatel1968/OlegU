// Copyright 2024 Urin Oleg

#include <gtest.h>

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

#include "../lib_binary_search_tree_table/TBSTTable.h"
#include "../lib_binary_search_tree_table/TBSTTable.cpp"
//#include "../lib_pair/pair.h"
#define EPSILON 0.000001

TEST(TBSTTableTest, BaseConstructor) {

	TBSTTable<int, std::string> table;

	EXPECT_EQ(table.size(), 0);
}

//TEST(TBSTTableTest, ParameterizedConstructor) {
//
//    TBinSearchTree<std::pair<int, std::string>> data;
//    std::pair<int, std::string> pair(1, "one");
//    
//    TBSTTable<int, std::string> tableWithData(data);
//
//    EXPECT_EQ(tableWithData.size(), 1);
//}

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

TEST(TBSTTableTest, InsertKeyValueCanThrow) {
    TBSTTable<int, std::string> table;
    table.insert(2, "one");

    EXPECT_THROW(table.insert(2, "o"), std::logic_error);
}

TEST(TBSTTableTest, FindTest) {
    TBSTTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "o");
    table.insert(3, "ne");
    table.insert(4, "e");
    table.insert(5, "oe");

    EXPECT_EQ(table.find(3), "ne");
}

TEST(TBSTTableTest, FindCanThrowTest) {
    TBSTTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "o");
    table.insert(3, "ne");
    table.insert(4, "e");
    table.insert(5, "oe");

    EXPECT_THROW(table.find(6), std::logic_error);
}

TEST(TBSTTableTest, EraseTest) {
    TBSTTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "o");
    table.insert(3, "ne");
    table.insert(4, "e");
    table.insert(5, "oe");

    table.erase(3);

    EXPECT_THROW(table.find(3), std::logic_error);
    EXPECT_EQ(table.size(), 4);
}