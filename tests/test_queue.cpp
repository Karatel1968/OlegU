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