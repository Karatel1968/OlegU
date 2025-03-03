// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_table/UTable_on_mas.h"

#define EPSILON 0.000001

TEST(UTableOnMass, BaseConstructor) {

	UnsortedTableOnMass<int, std::string> table;

	EXPECT_EQ(table.size(), 0);
}