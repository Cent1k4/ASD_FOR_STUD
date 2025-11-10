#include <gtest/gtest.h>
#include "../Algirithms/algirithms.h"

TEST(ALGIRITHMS, string_skob) {
	ASSERT_NO_THROW(chek_breckets("12345678()"));
}

TEST(ALGIRITHMS, string_skob1) {
	EXPECT_TRUE(chek_breckets("()[]{}()"));
}

TEST(ALGIRITHMS, string_skob1_1) {
	EXPECT_TRUE(chek_breckets("([]{()})"));
}

TEST(ALGIRITHMS, string_skob2) {
	EXPECT_FALSE(chek_breckets("()[]{3}()"));
}

TEST(ALGIRITHMS, string_skob3) {
	EXPECT_FALSE(chek_breckets(""));
}

TEST(ALGIRITHMS, string_skob4) {
	EXPECT_FALSE(chek_breckets("()[]}()"));
}

TEST(ALGIRITHMS, string_skob5) {
	EXPECT_FALSE(chek_breckets("([]{()})("));
}