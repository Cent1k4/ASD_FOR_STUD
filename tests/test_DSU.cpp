#include <gtest/gtest.h>
#include "../lib_DSU/DSU.h"

TEST(TestDSU, can_div1) {
	int x = 10;
	ASSERT_NO_THROW(DSU R(x));
}

TEST(TestDSU, can_div2) {
	ASSERT_NO_THROW(DSU x);
}

TEST(TestDSU, unite1) {
	int x = 3;
	DSU A(x);
	ASSERT_NO_THROW(A.unite(0,0));
}

TEST(TestDSU, unite2) {
	int x = 3;
	DSU A(x);
	ASSERT_NO_THROW(A.unite(1,2));
}

TEST(TestDSU, unite_and_find) {
	int x = 3;
	DSU A(x);
	A.unite(1, 2);
	EXPECT_EQ(A.find(2), 1);
}

TEST(TestDSU, unite3) {
	DSU A(10);
	A.unite(0, 1);
	A.unite(0, 2);
	A.unite(0, 3);
	A.unite(0, 4);
	A.unite(5, 6);
	A.unite(5, 7);
	A.unite(5, 8);
	A.unite(4, 6);
	A.find(8);
	EXPECT_EQ(A.find(2), 0);
	EXPECT_EQ(A.find(8), 0);
	EXPECT_EQ(A.find(6), 0);
	EXPECT_EQ(A.find(7), 0);
}

TEST(TestDSU, find1) {
	int x = 3;
	DSU A(x);
	EXPECT_EQ(A.find(2), 2);
}