#include <gtest/gtest.h>
#include "../lib_stack/stack.h"

TEST(test_stack, constructor_test1) {
	ASSERT_NO_THROW(Stack<int> S(10));
}

TEST(test_stack, constructor_test2) {
	ASSERT_NO_THROW(Stack<int> S());
}

TEST(test_stack, empty_test1) {
	Stack<int> S(10);
	EXPECT_TRUE(S.empty());
}

TEST(test_stack, empty_test2) {
	Stack<int> S(10);
	S.push(3);
	EXPECT_FALSE(S.empty());
}

TEST(test_stack, fuul_test1) {
	Stack<int> S(10);
	S.push(3);
	EXPECT_FALSE(S.full());
}

TEST(test_stack, full_test2) {
	Stack<int> S(1);
	S.push(3);
	EXPECT_TRUE(S.full());
}

TEST(test_stack, get_size_test) {
	Stack<int> S(10);
	EXPECT_EQ(S.get_size(), 10);
}

TEST(test_stack, push_test1) {
	Stack<int> S(10);
	ASSERT_NO_THROW(S.push(6));
}

TEST(test_stack, push_test2) {
	Stack<int> S(10);
	S.push(3);
	S.push(4);
	EXPECT_EQ(S.top(), 4);
}

TEST(test_stack, push_test3) {
	Stack<int> S(1);
	S.push(4);
	ASSERT_ANY_THROW(S.push(6));
}

TEST(test_stack, pop_test1) {
	Stack<int> S(10);
	ASSERT_ANY_THROW(S.pop());
}

TEST(test_stack, pop_test2) {
	Stack<int> S(10);
	S.push(4);
	ASSERT_NO_THROW(S.pop());
}

TEST(test_stack, pop_test3) {
	Stack<int> S(10);
	S.push(4);
	S.push(5);
	S.pop();
	EXPECT_EQ(S.top(), 4);
}

TEST(test_stack, clear_test1) {
	Stack<int> S(10);
	ASSERT_NO_THROW(S.clear());
}

TEST(test_stack, clear_test2) {
	Stack<int> S(10);
	S.push(4);
	S.push(5);
	ASSERT_NO_THROW(S.clear());
}

TEST(test_stack, top_test1) {
	Stack<int> S(10);
	ASSERT_ANY_THROW(S.top());
}

TEST(test_stack, top_test2) {
	Stack<int> S(10);
	S.push(4);
	ASSERT_NO_THROW(S.top());
}

TEST(test_stack, top_test3) {
	Stack<int> S(10);
	S.push(4);
	S.push(5);
	S.pop();
	EXPECT_EQ(S.top(), 4);
}