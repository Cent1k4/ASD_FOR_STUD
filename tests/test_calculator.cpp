#include <gtest/gtest.h>
#include"../lib_calculator/Calculator.h"

TEST(TestALL, test_work1) {
	std::string a = "23+9*45/9";
	Expression VIO(a);
	ASSERT_NO_THROW(VIO.calculate());
}

TEST(TestALL, test_work2) {
	std::string a = "23+9*45/9";
	Expression VIO(a);
	VIO.set_variables();
	EXPECT_EQ(VIO.calculate(), 68);
}

TEST(TestALL, test_work3) {
	std::string a = "23+t*45/9";
	Expression VIO(a);
	VIO.set_variables();
	EXPECT_EQ(VIO.calculate(), 68);
}

TEST(TestALL, test_work4) {
	std::string a = "sqrt(23^2)+t*45/9";
	Expression VIO(a);
	VIO.set_variables();
	EXPECT_EQ(VIO.calculate(), 68);
}
