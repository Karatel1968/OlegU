// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_dmassive/dmassive.h"

#define EPSILON 0.000001

TEST(TestDinamicArray, can_check_for_empty) {
	// Arrange
	TArchive<int> arr;

	// Act & Assert
	EXPECT_TRUE(arr.empty());
}