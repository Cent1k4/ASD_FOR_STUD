#include <gtest/gtest.h>
#include "../lib_list/list.h"

TEST(Test_List, test_constructor1) {
	ASSERT_NO_THROW(List<int> A());
}

TEST(Test_List, test_is_empty1) {
	List<int>A;
	EXPECT_TRUE(A.is_empty());
}

TEST(Test_List, test_is_empty2) {
	List<int>A;
	A.push_front(3);
	EXPECT_FALSE(A.is_empty());
}

TEST(Test_List, test_copy1) {
	List<int>A;
	A.push_back(3);
	A.push_back(2);
	A.push_back(1);
	ASSERT_NO_THROW(List<int>B(A));
}

TEST(Test_List, test_copy2) {
	List<int>A;
	A.push_back(3);
	A.push_back(2);
	A.push_back(1);
	List<int>B(A);
	EXPECT_EQ(B[0], 3);
	EXPECT_EQ(B[1], 2);
	EXPECT_EQ(B[2], 1);
}

TEST(Test_List, test_copy3) {
	List<int>A;
	ASSERT_NO_THROW(List<int>B(A));
}

TEST(Test_List, test_find1) {
	List<int>A;
	A.push_back(3);
	A.push_back(2);
	A.push_back(1);
	EXPECT_EQ(A.find_pos(3), 0);
	EXPECT_EQ(A.find_pos(2), 1);
	EXPECT_EQ(A.find_pos(1), 2);
}

TEST(Test_List, test_find2) {
	List<int>A;
	ASSERT_ANY_THROW(A.find_pos(3));
}

TEST(Test_List, test_find3) {
	List<int>A;
	A.push_back(2);
	ASSERT_NO_THROW(A.find_pos(3));
}

TEST(Test_List, test_find4) {
	List<int>A;
	A.push_back(2);
	EXPECT_EQ(A.find_pos(3), -1);
}

TEST(Test_List, test_pop_front1) {
	List<int>A;
	A.push_back(2);
	ASSERT_NO_THROW(A.pop_front());
}

TEST(Test_List, test_pop_front2) {
	List<int>A;
	ASSERT_ANY_THROW(A.pop_front());
}

TEST(Test_List, test_pop_front3) {
	List<int>A;
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);
	A.pop_front();
	EXPECT_EQ(A[0], 3);
}

TEST(Test_List, test_pop_front4) {
	List<int>A;
	A.push_back(2);
	A.pop_front();
	EXPECT_TRUE(A.is_empty());
}

TEST(Test_List, test_pop_back1) {
	List<int>A;
	A.push_back(2);
	ASSERT_NO_THROW(A.pop_back());
}

TEST(Test_List, test_pop_back2) {
	List<int>A;
	ASSERT_ANY_THROW(A.pop_back());
}

TEST(Test_List, test_pop_back3) {
	List<int>A;
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);
	A.pop_back();
	ASSERT_ANY_THROW(A[2]);
}

TEST(Test_List, test_pop_back4) {
	List<int>A;
	A.push_back(2);
	A.pop_back();
	EXPECT_TRUE(A.is_empty());
}

TEST(Test_List, test_push_front1) {
	List<int>A;
	ASSERT_NO_THROW(A.push_front(1));
}

TEST(Test_List, test_push_front2) {
	List<int>A;
	A.push_front(1);
	ASSERT_NO_THROW(A.push_front(2));
}

TEST(Test_List, test_push_front3) {
	List<int>A;
	A.push_front(1);
	A.push_front(2);
	A.push_front(3);
	EXPECT_EQ(A[0], 3);
	EXPECT_EQ(A[1], 2);
	EXPECT_EQ(A[2], 1);
}

TEST(Test_List, test_push_back1) {
	List<int>A;
	ASSERT_NO_THROW(A.push_back(1));
}

TEST(Test_List, test_push_back2) {
	List<int>A;
	A.push_back(1);
	ASSERT_NO_THROW(A.push_back(2));
}

TEST(Test_List, test_push_back3) {
	List<int>A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	EXPECT_EQ(A[0], 1);
	EXPECT_EQ(A[1], 2);
	EXPECT_EQ(A[2], 3);
}

TEST(Test_List, test_erase1_1) {
	List<int>A;
	A.push_back(2);
	ASSERT_NO_THROW(A.erase(0));
}

TEST(Test_List, test_erase1_2) {
	List<int>A;
	A.push_back(2);
	A.push_back(3);
	A.erase(0);
	EXPECT_EQ(A[0], 3);
}

TEST(Test_List, test_erase1_3) {
	List<int>A;
	A.push_back(2);
	A.push_back(3);
	A.erase(1);
	ASSERT_ANY_THROW(A[1]);
}

TEST(Test_List, test_erase2_1) {
	List<int>A;
	ASSERT_ANY_THROW(A.erase(3));
}

TEST(Test_List, test_erase2_2) {
	List<int>A;
	A.push_back(3);
	ASSERT_ANY_THROW(A.erase(3));
}

TEST(Test_List, test_erase3) {
	List<int>A;
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);
	A.erase(1);
	EXPECT_EQ(A[1], 4);
}

TEST(Test_List, test_erase4) {
	List<int>A;
	A.push_back(2);
	A.pop_front();
	EXPECT_TRUE(A.is_empty());
}

TEST(Test_List, test_insert1_1) {
	List<int>A;
	ASSERT_NO_THROW(A.insert(0,1));
}

TEST(Test_List, test_insert1_2) {
	List<int>A;
	ASSERT_ANY_THROW(A.insert(1, 1));
}

TEST(Test_List, test_insert2_1) {
	List<int>A;
	A.insert(0, 1);
	A.push_back(2);
	A.insert(2, 3);
	EXPECT_EQ(A[2], 3);
}

TEST(Test_List, test_insert3) {
	List<int>A;
	A.insert(0, 1);
	A.insert(1, 2);
	A.insert(2, 3);
	EXPECT_EQ(A[0], 1);
	EXPECT_EQ(A[1], 2);
	EXPECT_EQ(A[2], 3);
}

TEST(Test_List, test_erase_Note_1_1) {
	List<int>A;
	A.push_back(2);
	Node<int>* B = new Node<int>(1, nullptr);
	ASSERT_ANY_THROW(A.erase(B));
}

TEST(Test_List, test_erase_Note_1_2) {
	List<int>A;
	Node<int>* B1 = new Node<int>(1, nullptr);
	Node<int>* B2 = new Node<int>(1, B1);
	ASSERT_ANY_THROW(A.erase(B2));
}

TEST(Test_Ierator, test_read) {
	List<int>A;
	A.push_front(3);
	A.push_front(2);
	A.push_front(1);
	int i = 1;
	for (auto it = A.begin(); it != A.end(); it++, i++) 
		EXPECT_EQ(*it, i);
	
}

TEST(Test_Ierator, test_ne_read) {
	List<int>A;
	A.push_front(1);
	A.push_front(2);
	A.push_front(3);
	List<int>::Iterator it = A.begin();
	for (int i = 1; i < 4; i++) {
		*it = i;
		it++;
	}
	List<int>::Iterator ie = A.begin();
	for (int i = 1; i < 4; i++) {
		EXPECT_EQ(*ie, i);
		ie++;
	}
}

TEST(Test_Ierator, test_0) {
	List<int>A;
	ASSERT_NO_THROW(List<int>::Iterator it = A.begin());
}