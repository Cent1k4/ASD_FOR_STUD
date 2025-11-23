#include <gtest/gtest.h>
#include"../lib_calculator/math_func.h"

#define EPSILON 0.0001

TEST(TestMathFunc, test_sin_degrees1) {
    EXPECT_NEAR(my_sin(-10), sin(-10 * M_PI / 180.0), EPSILON);
}

TEST(TestMathFunc, test_sin_degrees2) {
    EXPECT_NEAR(my_sin(90), sin(90 * M_PI / 180.0), EPSILON);
}

TEST(TestMathFunc, test_sin_degrees3) {
    EXPECT_NEAR(my_sin(180), sin(180 * M_PI / 180.0), EPSILON);
}

TEST(TestMathFunc, test_sin_degrees4) {
    EXPECT_NEAR(my_sin(2000), sin(2000 * M_PI / 180.0), EPSILON);
}

TEST(TestMathFunc, test_sin_degrees5) {
    EXPECT_NEAR(my_sin(1), sin(1 * M_PI / 180.0), EPSILON);
}


TEST(TestMathFunc, test_cos_degrees1) {
    EXPECT_NEAR(my_cos(-10), cos(-10 * M_PI / 180.0), EPSILON);
}

TEST(TestMathFunc, test_cos_degrees2) {
    EXPECT_NEAR(my_cos(90), cos(90 * M_PI / 180.0), EPSILON);
}

TEST(TestMathFunc, test_cos_degrees3) {
    EXPECT_NEAR(my_cos(180), cos(180 * M_PI / 180.0), EPSILON);
}

TEST(TestMathFunc, test_cos_degrees4) {
    EXPECT_NEAR(my_cos(2000), cos(2000 * M_PI / 180.0), EPSILON);
}

TEST(TestMathFunc, test_cos_degrees5) {
    EXPECT_NEAR(my_cos(1), cos(1 * M_PI / 180.0), EPSILON);
}


TEST(TestMathFunc, test_tg_degrees1) {
    EXPECT_NEAR(my_tg(-10), sin(-10 * M_PI / 180.0) / cos(-10 * M_PI / 180.0), EPSILON);
}

TEST(TestMathFunc, test_tg_degrees2) {
    EXPECT_ANY_THROW(my_tg(90));
}

TEST(TestMathFunc, test_tg_degrees3) {
    EXPECT_NEAR(my_tg(180), sin(180 * M_PI / 180.0) / cos(180 * M_PI / 180.0), EPSILON);
}

TEST(TestMathFunc, test_tg_degrees4) {
    EXPECT_NEAR(my_tg(2000), sin(2000 * M_PI / 180.0) / cos(2000 * M_PI / 180.0), EPSILON);
}

TEST(TestMathFunc, test_tg_degrees5) {
    EXPECT_NEAR(my_tg(1), sin(1 * M_PI / 180.0) / cos(1 * M_PI / 180.0), EPSILON);
}


TEST(TestMathFunc, test_ctg_degrees1) {
    EXPECT_NEAR(my_ñtg(-10), cos(-10 * M_PI / 180.0) / sin(-10 * M_PI / 180.0), EPSILON);
}

TEST(TestMathFunc, test_ctg_degrees2) {
    EXPECT_ANY_THROW(my_ñtg(180));
}

TEST(TestMathFunc, test_ctg_degrees3) {
    EXPECT_NEAR(my_ñtg(90), cos(90 * M_PI / 180.0) / sin(90 * M_PI / 180.0), EPSILON);
}

TEST(TestMathFunc, test_ctg_degrees4) {
    EXPECT_NEAR(my_ñtg(2000), cos(2000 * M_PI / 180.0) / sin(2000 * M_PI / 180.0), EPSILON);
}

TEST(TestMathFunc, test_ctg_degrees5) {
    EXPECT_NEAR(my_ñtg(1), cos(1 * M_PI / 180.0) / sin(1 * M_PI / 180.0), EPSILON);
}


TEST(TestMathFunc, test_ln_degrees1) {
    EXPECT_NEAR(my_ln(10), log(10), EPSILON);
}

TEST(TestMathFunc, test_ln_degrees2) {
    EXPECT_ANY_THROW(my_ln(0));
}

TEST(TestMathFunc, test_ln_degrees3) {
    EXPECT_NEAR(my_ln(1), log(1), EPSILON);
}


TEST(TestMathFunc, test_sqrt_degrees1) {
    EXPECT_NEAR(my_sqrt(10), sqrt(10), EPSILON);
}

TEST(TestMathFunc, test_sqrt_degrees2) {
    EXPECT_NO_THROW(my_sqrt(0));
}

TEST(TestMathFunc, test_sqrt_degrees3) {
    EXPECT_NEAR(my_sqrt(1.44), sqrt(1.44), EPSILON);
}