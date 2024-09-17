// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_dmassive/dmassive.h"

#define EPSILON 0.000001

// tests for empty() START:
TEST(TestDinamicArray, can_check_for_empty) {

TArchive<int> arr;

EXPECT_TRUE(arr.empty());
}

TEST(TestDinamicArray, worksRight) {

std::string arr[] = { "ytr" };
TArchive<std::string> archive(arr, 1);

EXPECT_FALSE(archive.empty());
}
// tests for empty() END:

// tests for full() START:
TEST(TestDinamicArray, can_check_for_full) {

	int arr[] = { 1, 2 };
	TArchive<int> archive(arr, 2);

	EXPECT_FALSE(archive.full());
}

TEST(TestDinamicArray, can_check_empty_massive) {

	int arr[] = {NULL};
	TArchive<int> archive(arr, 0);

	EXPECT_FALSE(archive.full());
}

TEST(TestDinamicArray, can_identify_full_massive) {

	int arr[] = { 1, 2 , 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	TArchive<int> archive(arr, 15);

	EXPECT_TRUE(archive.full());
}
// tests for full() END:

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
// tests for TArchive(const T* arr, size_t n) END:

// tests for TArchive(const TArchive& archive) START:
TEST(TestDinamicArray, CopyconstructorWorks) {

	TArchive<int> archive;
	TArchive<int> copyarchive(archive);

	EXPECT_TRUE(copyarchive.empty());
	EXPECT_EQ(copyarchive.capacity(), archive.capacity());
}

TEST(TestDinamicArray, CopyconstructorWorksWithSeverelValues) {

	int arr[] = { 1, 2, 3, 4 };
	TArchive<int> archive(arr, 4);
	TArchive<int> copyarchive(archive);

	EXPECT_FALSE(copyarchive.empty());
	EXPECT_EQ(copyarchive.capacity(), archive.capacity());

	EXPECT_EQ(copyarchive.size(), archive.size());
}
// tests for TArchive(const TArchive& archive) END:

// tests for TArchive(size_t n, T value) START:
TEST(TestDinamicArray, ConstructorWithSizeAndValue) {
	TArchive<int> archive(5, 100);

	EXPECT_FALSE(archive.empty());

	EXPECT_EQ(archive.size(), 5);

	const int* dataPtr = archive.data();

	for (size_t i = 0; i < 5; i++) {
		EXPECT_EQ(dataPtr[i], 100);
	}
}

TEST(TestDinamicArray, ConstructorWithSizeExceedingStepCapacity) {
	size_t n = STEP_CAPACITY + 5;  // Количество элементов больше, чем STEP_CAPACITY
	TArchive<int> archive(n, 10);  // Создаем архив с n элементами, каждый равен 10

	// Проверяем, что архив не пуст
	EXPECT_FALSE(archive.empty());

	// Проверяем, что размер архива равен n
	EXPECT_EQ(archive.size(), n);
}
// tests for TArchive(size_t n, T value) END:

// tests for TArchive(size_t n, T value) START:

// tests for TArchive(size_t n, T value) END:
