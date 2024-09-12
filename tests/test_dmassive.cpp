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


// tests for TArchive(const T* arr, size_t n) START:
TEST(TestDinamicArray, check_the_ability_to_keep_emty_array) {
 int arr[] = {NULL};
 TArchive<int> archive(arr, 0);

 EXPECT_TRUE(archive.empty());
 EXPECT_FALSE(archive.full());

}

TEST(TestDinamicArray, check_the_ability_to_keep_1_alement_of_array) {
 int arr[] = { 1 };
 TArchive<int> archive(arr, 1);

 EXPECT_FALSE(archive.empty());

}

TEST(TestDinamicArray, check_the_ability_to_keep_several_alements_of_array) {
 int arr[] = { 1, 2, 3, 4, 5 };
 TArchive<int> archive(arr, 5);

 EXPECT_FALSE(archive.empty());
}