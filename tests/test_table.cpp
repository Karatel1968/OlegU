// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_table/UTable.h"

#define EPSILON 0.000001

TEST(UTable, BaseConstructor) {
	UnsortedTable<int, std::string> table;

	EXPECT_EQ(table.size(), 0);

	TList<TPair<int, std::string>> data(1, "jopa");

	UnsortedTable<int, std::string> table(data);

	EXPECT_EQ(table.size(), 1);
}