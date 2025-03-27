// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_table/UTable_on_mas.h"

#define EPSILON 0.000001

TEST(UTableOnMass, BaseConstructor) {

	UnsortedTableOnMass<int, std::string> table;

	EXPECT_EQ(table.size(), 0);
}

TEST(UTableOnMass, ParameterizedConstructor) {

    TArchive<std::pair<int, std::string>> data;
    std::pair<int, std::string> pair(1, "one");
    data.push_front(pair);
    UnsortedTableOnMass<int, std::string> tableWithData(data);

    EXPECT_EQ(tableWithData.size(), 1);
}

TEST(UTableOnMass, InsertValue) {
    UnsortedTableOnMass<int, std::string> data;
    data.insert("test_value");
    EXPECT_EQ(data.size(), 1);

}

TEST(UTableOnMass, InsertKeyValue) {
    UnsortedTableOnMass<int, std::string> table;
    table.insert(1, "one");
    EXPECT_EQ(table.size(), 1);

}

TEST(UTableOnMass, FindCanThrow) {
    UnsortedTableOnMass<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "on");
    EXPECT_EQ(table.find(1), "one");
    EXPECT_EQ(table.find(2), "on");
    EXPECT_THROW(table.find(3), std::logic_error);
}

TEST(UTableOnMass, EraseTest1) {
    UnsortedTableOnMass<int, int> table;
    table.insert(1, 4);
    table.insert(2, 4);
    table.insert(3, 4);
    //EXPECT_THROW(table.find(2), std::out_of_range);
    table.erase(2);
    EXPECT_THROW(table.find(2), std::logic_error);
}

TEST(UTableOnMass, CopyConstructor) {
    UnsortedTableOnMass<int, std::string> table;
    table.insert(1, "one");
    UnsortedTableOnMass<int, std::string> copiedTable(table);
    EXPECT_EQ(copiedTable.size(), 1);
    EXPECT_EQ(copiedTable.find(1), "one");
}