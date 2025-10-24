#include <gtest/gtest.h>
#include "../lib_queue/queue.h"


TEST(test_queue, constructor_test1) {
	ASSERT_NO_THROW(Queue<int> Q(10));
}

TEST(test_queue, constructor_test2) {
	ASSERT_NO_THROW(Queue<int> Q());
}

TEST(test_queue, constructor_test3) {
	ASSERT_ANY_THROW(Queue<int> Q(-1));
}

TEST(test_queue, push_test1) {
	Queue<int> Q(5);
	Q.push(1);
	Q.push(2);
	Q.push(3);
	EXPECT_EQ(Q.front(), 1);
}

TEST(test_queue, push_test2) {
	Queue<int> Q(5);
	Q.push(1);
	Q.push(2);
	Q.push(3);
	Q.pop();
	EXPECT_EQ(Q.front(), 2);
}

TEST(test_queue, push_test3) {
	Queue<int> Q(1);
	Q.push(1);
	ASSERT_ANY_THROW(Q.push(2));
}

TEST(test_queue, get_count_test) {
	Queue<int> Q(5);
	Q.push(1);
	Q.push(2);
	Q.push(3);
	EXPECT_EQ(Q.get_count(), 3);
}

TEST(test_queue, pop_test1) {
	Queue<int> Q(5);
	ASSERT_ANY_THROW(Q.pop());
}

TEST(test_queue, pop_test2) {
	Queue<int> Q(5);
	Q.push(1);
	Q.push(2);
	Q.push(3);
	Q.pop();
	Q.pop();
	EXPECT_EQ(Q.front(), 3);
}

TEST(test_queue, is_full_test1) {
	Queue<int> Q(5);
	EXPECT_FALSE(Q.isFull());
}

TEST(test_queue, is_full_test2) {
	Queue<int> Q(1);
	Q.push(3);
	EXPECT_TRUE(Q.isFull());
}

TEST(test_queue, is_empty_test1) {
	Queue<int> Q(5);
	EXPECT_TRUE(Q.isEmpty());
}

TEST(test_queue, is_empty_test2) {
	Queue<int> Q(5);
	Q.push(3);
	EXPECT_FALSE(Q.isEmpty());
}

