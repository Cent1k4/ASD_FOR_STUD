#include <gtest/gtest.h>
#include"../lib_TVector/TVector.h"

TEST(TestVector, double_cleansing_check) {
	TVector<int> T1(5);
	T1.clear();
	ASSERT_NO_THROW(T1.clear());
}

TEST(TestVector, copy_constructor_test1_and_bask) {
	TVector<int> T1(2);
	T1.push_back(59);
	T1.push_back(0);
	TVector<int> T2(T1);
	EXPECT_EQ(T2.back(), 0);
}

TEST(TestVector, copy_constructor_test2_and_front) {
	TVector<int> T1(2);
	T1.push_back(59);
	T1.push_back(0);
	TVector<int> T2(T1);
	EXPECT_EQ(T2.front(), 59);
}

TEST(TestVector, array_constructor_test1) {
	int arr[2] = { 59, 0 };
	TVector<int> T1(arr, 2);
	EXPECT_EQ(T1.back(), 0);
}

TEST(TestVector, array_constructor_test2) {
	int* arr = new int[0];
	ASSERT_ANY_THROW(TVector<int> T1(arr, 0));
}

TEST(TestVector, value_constructor_test1) {
	ASSERT_ANY_THROW(TVector<int> T1(-2));
}

TEST(TestVector, value_constructor_test2) {
	ASSERT_NO_THROW(TVector<int> T1(6));
}

TEST(TestVector, default_constructor_test) {
	ASSERT_NO_THROW(TVector<int> T1());
}

TEST(TestVector, list_constructor_test1) {
	ASSERT_NO_THROW(TVector<int> T1({ 59,44,12,77,8, 0 }));
}

TEST(TestVector, list_constructor_test2) {
	ASSERT_ANY_THROW(TVector<int> T1({}));
}

TEST(TestVector, list_constructor_test3) {
	TVector<int> T1({ 59,44,12,77,8, 0 });
	EXPECT_EQ(T1.back(), 0);
}

TEST(TestVector, list_constructor_test4) {
	TVector<int> T1({ 59,44,12,77,8, 0 });
	EXPECT_EQ(T1.front(), 59);
}

TEST(TestVector, destructor_test) {
	TVector<int> T1(1);
	ASSERT_NO_THROW(T1.clear());
}

TEST(TestVector, full_test1) {
	TVector<int> T1(4);
	EXPECT_FALSE(T1.full());
}

TEST(TestVector, full_test2) {
	TVector<int> T1({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14 });
	T1.push_back(15);
	EXPECT_TRUE(T1.full());
}

TEST(TestVector, get_capasity_test) {
	TVector<int> T1(4);
	EXPECT_EQ(T1.get_capacity(), 15);
}

TEST(TestVector, get_size_test) {
	TVector<int> T1(4);
	EXPECT_EQ(T1.get_size(), 0);
}

TEST(TestVector, regruping_test1) {
	TVector<int> T1({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 });
	T1.push_back(16);
	EXPECT_EQ(T1.get_capacity(), 30);
}

TEST(TestVector, regruping_test2) {
	TVector<int> T1({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15, 16 });
	T1.pop_back();
	T1.pop_back();
	EXPECT_EQ(T1.get_capacity(), 15);
}

TEST(TestVector, push_front_test) {
	TVector<int> T1(4);
	T1.push_front(59);
	EXPECT_EQ(T1.front(), 59);
}

TEST(TestVector, push_bask_test) {
	TVector<int> T1(4);
	T1.push_front(59);
	T1.push_back(0);
	EXPECT_EQ(T1.back(), 0);
}

TEST(TestVector, insert_test1) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	T1.insert(5, 7);
	EXPECT_EQ(T1[5], 7);
}

TEST(TestVector, insert_test2) {
	TVector<int> T1({ 4,5,6 });
	ASSERT_ANY_THROW(T1.insert(50, 5));
}

TEST(TestVector, insert2_test1) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	T1.insert((T1.get_data() + 5), 7);
	EXPECT_EQ(T1[5], 7);
}

TEST(TestVector, insert2_test2) {
	TVector<int> T1({ 4,5,6 });
	ASSERT_ANY_THROW(T1.insert(T1.get_data() + 100, 7));
}

TEST(TestVector, pop_back_test) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	T1.pop_back();
	EXPECT_EQ(T1.back(), 5);
}

TEST(TestVector, pop_front_test) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	T1.pop_front();
	EXPECT_EQ(T1.front(), 2);
}

TEST(TestVector, erase_test1) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	T1.erase(3);
	EXPECT_EQ(T1[3], 5);
}

TEST(TestVector, erase_test2) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	T1.erase(2, 2);
	EXPECT_EQ(T1[3], 6);
}

TEST(TestVector, erase_test3) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	ASSERT_ANY_THROW(T1.erase(3, 10));
}

TEST(TestVector, erase2_test1) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	T1.erase(T1.get_data() + 3);
	EXPECT_EQ(T1[3], 5);
}

TEST(TestVector, erase2_test2) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	T1.erase(T1.get_data() + 2, 2);
	EXPECT_EQ(T1[3], 6);
}

TEST(TestVector, erase2_test3) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	ASSERT_ANY_THROW(T1.erase(T1.get_data() + 3, 10));
}

TEST(TestVector, front_test) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	T1.front() = 9;
	EXPECT_EQ(T1[0], 9);
}

TEST(TestVector, back_test) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	T1.back() = 9;
	EXPECT_EQ(T1[5], 9);
}

TEST(TestVector, find_test1) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	size_t i = T1.find(5);
	EXPECT_EQ(T1[i], 5);
}

TEST(TestVector, find_test2) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	EXPECT_EQ (T1.find(10), -1);
}

TEST(TestVector, assignment_test) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	TVector<int> T2({ 4,5,7 });
	T2 = T1;
	EXPECT_EQ(T2.get_size(), T1.get_size());
	EXPECT_NE(T2.get_data(), T1.get_data());
	EXPECT_EQ(T2.get_capacity(), T1.get_capacity());
	EXPECT_EQ(T2.front(), T1.front());
	EXPECT_EQ(T2.back(), T1.back());
	EXPECT_EQ(T2[5], T1[5]);
}

TEST(TestVector, mas_test1) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	EXPECT_EQ(T1[3], 4);
}

TEST(TestVector, mas_test2) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	T1[4] = 8;
	EXPECT_EQ(T1[4], 8);
}

TEST(TestVector, mas_test3) {
	TVector<int> T1({ 1,2,3,4,5,6 });
	ASSERT_ANY_THROW(T1[101]);
}