#include <gtest/gtest.h>
#include "../lib_stak_list_qeue/stak_list.h"

TEST(test_stack_list, constructor_test2) {
	ASSERT_NO_THROW(Stack_list<int> S());
}

TEST(test_stack_list, empty_test1) {
	Stack_list<int> S;
	EXPECT_TRUE(S.SLempty());
}

TEST(test_stack_list, empty_test2) {
	Stack_list<int> S;
	S.SLpush(3);
	EXPECT_FALSE(S.SLempty());
}

TEST(test_stack_list, push_test1) {
	Stack_list<int> S;
	ASSERT_NO_THROW(S.SLpush(6));
}

TEST(test_stack_list, push_test2) {
	Stack_list<int> S;
	S.SLpush(3);
	S.SLpush(4);
	EXPECT_EQ(S.SLtop(), 4);
}

TEST(test_stack_list, pop_test1) {
	Stack_list<int> S;
	ASSERT_ANY_THROW(S.SLpop());
}

TEST(test_stack_list, pop_test2) {
	Stack_list<int> S;
	S.SLpush(4);
	ASSERT_NO_THROW(S.SLpop());
}

TEST(test_stack_list, pop_test3) {
	Stack_list<int> S;
	S.SLpush(4);
	S.SLpush(5);
	S.SLpop();
	EXPECT_EQ(S.SLtop(), 4);
}

TEST(test_stack_list, clear_test1) {
	Stack_list<int> S;
	ASSERT_NO_THROW(S.SLclear());
}

TEST(test_stack_list, clear_test2) {
	Stack_list<int> S;
	S.SLpush(4);
	S.SLpush(5);
	ASSERT_NO_THROW(S.SLclear());
}

TEST(test_stack_list, top_test1) {
	Stack_list<int> S;
	ASSERT_ANY_THROW(S.SLtop());
}

TEST(test_stack_list, top_test2) {
	Stack_list<int> S;
	S.SLpush(4);
	ASSERT_NO_THROW(S.SLtop());
}

TEST(test_stack_list, top_test3) {
	Stack_list<int> S;
	S.SLpush(4);
	S.SLpush(5);
	S.SLpop();
	EXPECT_EQ(S.SLtop(), 4);
}