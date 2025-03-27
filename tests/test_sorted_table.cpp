// Copyright 2024 Urin Oleg

#include <gtest.h>

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

#include "../lib_sorted_table/TSTable.h"

#define EPSILON 0.000001


TEST(TSTableTest, ParameterizedConstructor) {
    TArchive<TPair<int, std::string>> data;
    data.push_back(TPair<int, std::string>(1, "val1"));
    //ASSERT_NO_THROW(TSTable<int, std::string> Table(data));
    TSTable<int, std::string> Table(data);
    EXPECT_EQ(Table.size(), 1);
}

TEST(TSTableIntStringTest, CopyConstructor) {
    TSTable<int, std::string> table;
    table.insert(1, "value1");
    TSTable<int, std::string> copyTable(table);
    EXPECT_EQ(copyTable.size(), 1);
    //EXPECT_EQ(copyTable.find(1), "value1");
}