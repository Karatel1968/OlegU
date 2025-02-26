// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_table/UTable.h"

#define EPSILON 0.000001

TEST(UTable, BaseConstructor) {

	UnsortedTable<int, std::string> table;

	EXPECT_EQ(table.size(), 0);
}