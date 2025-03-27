// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_table/UTable.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

#define EPSILON 0.000001

TEST(UTable, BaseConstructor) {

	UnsortedTable<int, std::string> table;

	EXPECT_EQ(table.size(), 0);
}

TEST(UTable, ParameterizedConstructor) {
    
    TList<std::pair<int, std::string>> data;
    std::pair<int, std::string> pair(1, "one");
    data.push_front(pair);
    TList<std::pair<int, std::string>> data2;
    std::pair<int, std::string> pair2(1, "two");
    data.push_front(pair);
    UnsortedTable<int, std::string> tableWithData(data);
    
    EXPECT_EQ(tableWithData.size(), 1);
}

TEST(UTable, InsertValue) {
    UnsortedTable<int, std::string> data;
    data.insert("test_value");
    EXPECT_EQ(data.size(), 1);
    
}

TEST(UTable, InsertKeyValue) {
    UnsortedTable<int, std::string> table;
    table.insert(1, "one");
    EXPECT_EQ(table.size(), 1);
    
}

TEST(UTable, FindCanThrow) {
    UnsortedTable<int, std::string> table;
    table.insert(1, "one");
    EXPECT_EQ(table.find(1), "one");
    EXPECT_THROW(table.find(2), std::logic_error);
}

TEST(UTable, EraseTest) {
    UnsortedTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "one");
    table.insert(3, "one");
    EXPECT_EQ(table.size(), 3);
    table.erase(2);
    EXPECT_EQ(table.size(), 2);
}

TEST(UTable, CopyConstructor) {
    UnsortedTable<int, std::string> table;
    table.insert(1, "one");
    UnsortedTable<int, std::string> copiedTable(table);;
    EXPECT_EQ(copiedTable.size(), 1);
    EXPECT_EQ(copiedTable.find(1), "one");
}