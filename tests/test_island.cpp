#include <gtest/gtest.h>
#include"../lib_island/island.h"

TEST(TestIsland, rab) {
	int* mas = new int [9] {0, 0, 1, 1, 1, 0, 1, 0, 1};
	EXPECT_EQ(counting_islands(3, 3, mas), 3);
}