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

TEST(TQueueTest, PopTest) {
	TQueue<int> queue(10);

	queue.push(1);
	queue.push(2);
	queue.push(3);

	EXPECT_EQ(queue.front(), 1);
	EXPECT_EQ(queue.back(), 3);
	
	queue.pop();

	EXPECT_EQ(queue.back(), 3);
	EXPECT_EQ(queue.front(), 2);

	queue.pop();

	EXPECT_EQ(queue.back(), 3);
	EXPECT_EQ(queue.front(), 3);

	queue.pop();

	EXPECT_THROW(queue.front(), std::logic_error);
	EXPECT_THROW(queue.back(), std::logic_error);
	EXPECT_TRUE(queue.isEmpty());
}