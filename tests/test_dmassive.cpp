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
	size_t n = STEP_CAPACITY + 5;
	TArchive<int> archive(n, 10);

	// Проверяем, что архив не пуст
	EXPECT_FALSE(archive.empty());

	// Проверяем, что размер архива равен n
	EXPECT_EQ(archive.size(), n);
}
// tests for TArchive(size_t n, T value) END:

// tests for swap() START:
TEST(TestDinamicArray, SwapTest) {

	TArchive<int> archive1(3, 10);
	TArchive<int> archive2(5, 20);

	archive1.swap(archive2);

	const int* dataPtr1 = archive1.data();
	const int* dataPtr2 = archive2.data();

	for (size_t i = 0; i < 5; i++) {
		EXPECT_EQ(dataPtr1[i], 20);
	}

	for (size_t i = 0; i < 3; i++) {
		EXPECT_EQ(dataPtr2[i], 10);
	}
}
// tests for swap() END:

// tests for clear() START:
TEST(TestDinamicArray, ClearTest) {

	TArchive<int> archive(3, 10);

	archive.clear();

	EXPECT_TRUE(archive.empty());
}
// tests for clear() END:

// tests for resize() START:
TEST(TestDinamicArray, ResizeTestThrow) {

	TArchive<int> archive(3, 10);
	

	archive.resize(3, 20);

	EXPECT_THROW(archive.resize(3, 20), std::logic_error);

}

/*TEST(TestDinamicArray, ResizeTestIncreasesMassive) {

	TArchive<int> archive(3, 10);


	archive.resize(6, 20);

	EXPECT_EQ(archive[0], 10);
	EXPECT_EQ(archive[1], 10);
	EXPECT_EQ(archive[2], 10);
	EXPECT_EQ(archive[3], 20);
}*/
// tests for resize() END:

// tests for reserve() START:
TEST(TestDinamicArray, ReserveIncreaseTest) {
	TArchive<int> archive(5, 10);

	EXPECT_EQ(archive.capacity(), 15);

	archive.reserve(20);

	EXPECT_EQ(archive.capacity(), 20);
	EXPECT_EQ(archive.size(), 5);
	
	EXPECT_EQ(archive[0], 10);
	EXPECT_EQ(archive[4], 10);
}

TEST(TestDinamicArray, ReserveNoChangeTest) {
	TArchive<int> archive(5, 10);

	archive.reserve(3);

	
	EXPECT_EQ(archive.size(), 5);
}
// tests for reserve() END:

// tests for push_back() START:
TEST(TestDinamicArray, PushBackBasicTest) {
	TArchive<int> archive(3, 0);

	EXPECT_EQ(archive.size(), 3);

	archive.push_back(10);

	EXPECT_EQ(archive.size(), 4);

	EXPECT_EQ(archive[3], 10);

	EXPECT_EQ(archive.capacity(), 15);
}

TEST(TestDinamicArray, PushBackCapacityIncreaseTest) {
	TArchive<int> archive(2, 5);

	EXPECT_EQ(archive.size(), 2);

	archive.push_back(10);
	archive.push_back(20);

	EXPECT_GE(archive.size(), 4);

	EXPECT_EQ(archive[2], 10);
	EXPECT_EQ(archive[3], 20);
}
// tests for push_back() END:

// tests for pop_back() START:
TEST(TestDinamicArray, PopBackBasicTest) {
	TArchive<int> archive(3, 0);

	EXPECT_EQ(archive.size(), 3);

	archive.pop_back();

	EXPECT_EQ(archive.size(), 2);

	EXPECT_EQ(archive.capacity(), 15);
}

TEST(TestDinamicArray, PopBackCapacityDecreaseTest) {
	TArchive<int> archive(20, 5);

	EXPECT_EQ(archive.size(), 20);
	EXPECT_EQ(archive.capacity(), 20);

	archive.pop_back();
	archive.pop_back();

	EXPECT_EQ(archive.size(), 18);
	EXPECT_EQ(archive.capacity(), 18);
}
// tests for pop_back() END:

// tests for push_front() START:
TEST(TestDinamicArray, PushFrontBasicTest) {
	TArchive<int> archive(3, 10);

	EXPECT_EQ(archive.size(), 3);

	archive.push_front(5);

	EXPECT_EQ(archive.size(), 4);

	EXPECT_EQ(archive[0], 5);

	EXPECT_EQ(archive[1], 10);
	EXPECT_EQ(archive[2], 10);
	EXPECT_EQ(archive[3], 10);
}

TEST(TestDinamicArray, PushFrontCapacityIncreaseTest) {
	TArchive<int> archive(15, 5);

	EXPECT_EQ(archive.capacity(), 15);

	archive.push_front(10);

	EXPECT_GE(archive.capacity(), 18,75);

	EXPECT_EQ(archive[0], 10);

}
// tests for push_front() END: