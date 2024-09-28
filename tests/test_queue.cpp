// Copyright 2024 Urin Oleg

#include <gtest.h>
#include "../lib_queue/TQueue.h"


#define EPSILON 0.000001

TEST(TQueueTest, BaseConstruckttorTest) {
	TQueue<int> queue(10);

	EXPECT_TRUE(queue.isEmpty());
	EXPECT_THROW(queue.front(), std::logic_error);
	EXPECT_FALSE(queue.isFull());
}

TEST(TQueueTest, PushTest) {
	TQueue<int> queue(10);

	queue.push(1);
	queue.push(2);

	EXPECT_FALSE(queue.isEmpty());
	EXPECT_EQ(queue.front(), 1);
	EXPECT_FALSE(queue.isFull());
}