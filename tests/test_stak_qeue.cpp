#include <gtest/gtest.h>
#include "../lib_stak_list_qeue/srak_qeue.h"

TEST(test_queue_list, constructor_test1) {
	ASSERT_NO_THROW(Qeue_list<int> Q(3));
}

TEST(test_queue_list, constructor_test3) {
	ASSERT_ANY_THROW(Qeue_list<int> Q(-1));
}

TEST(test_queue_list, push_test1) {
	Qeue_list<int> Q(5);
	Q.push(1);
	Q.push(2);
	Q.push(3);
	EXPECT_EQ(Q.ending(), 1);
}

TEST(test_queue_list, push_test2) {
	Qeue_list<int> Q(5);
	Q.push(1);
	Q.push(2);
	Q.push(3);
	Q.pop();
	EXPECT_EQ(Q.ending(), 2);
}

TEST(test_queue_list, push_test3) {
	Qeue_list<int> Q(1);
	Q.push(1);
	ASSERT_ANY_THROW(Q.push(2));
}

TEST(test_queue_list, get_count_test) {
	Qeue_list<int> Q(5);
	Q.push(1);
	Q.push(2);
	Q.push(3);
	EXPECT_EQ(Q.get_count(), 3);
}

TEST(test_queue_list, pop_test1) {
	Qeue_list<int> Q(5);
	Q.push(3);
	Q.pop();
	ASSERT_ANY_THROW(Q.pop());
}

TEST(test_queue_list, pop_test2) {
	Qeue_list<int> Q(3);
	Q.push(1);
	Q.push(2);
	Q.push(3);
	Q.pop();
	Q.pop();
	Q.push(1);
	EXPECT_EQ(Q.ending(), 3);
	EXPECT_EQ(Q.begin(), 1);
}

TEST(test_queue_list, is_full_test1) {
	Qeue_list<int> Q(5);
	EXPECT_FALSE(Q.isFull());
}

TEST(test_queue_list, is_full_test2) {
	Qeue_list<int> Q(1);
	Q.push(3);
	EXPECT_TRUE(Q.isFull());
}

TEST(test_queue_list, is_empty_test1) {
	Qeue_list<int> Q(5);
	EXPECT_TRUE(Q.isEmpty());
}

TEST(test_queue_list, is_empty_test2) {
	Qeue_list<int> Q(5);
	Q.push(3);
	EXPECT_FALSE(Q.isEmpty());
}

TEST(test_har_turtle, test1) {
	List<int> Q;
	Q.push_back(3);
	Q.push_back(3);
	Q.push_back(3);
	Q.push_back(3);
	Q.push_back(3);
	Q.ñreate_ring();

	EXPECT_TRUE(Q.har_turtle());
}

TEST(test_har_turtle, test2) {
	List<int> Q;
	Q.push_back(3);
	Q.push_back(3);
	Q.push_back(3);
	Q.push_back(3);
	Q.push_back(3);
	EXPECT_FALSE(Q.har_turtle());
}

//TEST(test_hasCycleReverse, test1) {
//	List<int> Q;
//	Q.push_back(3);
//	List<int>::Iterator it = Q.begin();
//	Q.push_back(3);
//	it++;
//	Q.push_back(3);
//	it++;
//	Q.push_back(3);
//	Q.push_back(3);
//	Q.ñreate_ring();
//	Q.push_front(3);
//	Q.push_front(3);
//	Q.push_front(3);
//	EXPECT_TRUE(Q.hasCycleReverse(), it);
//}
//
//TEST(test_hasCycleReverse, test2) {
//	List<int> Q;
//	Q.push_back(3);
//	Q.push_back(3);
//	Q.push_back(3);
//	Q.push_back(3);
//	Q.push_back(3);
//	EXPECT_FALSE(Q.hasCycleReverse(), nullptr);
//}