#include <gtest/gtest.h>
#include"../lib_calculator/math_func.h"

#define EPSILON 0.000001

TEST(TestMathFunc, test_sin_degrees) {
    EXPECT_NEAR(my_sin(0), 0.0, EPSILON);                  
    EXPECT_NEAR(my_sin(90), 1.0, EPSILON);                   
    EXPECT_NEAR(my_sin(180), 0.0, EPSILON);    
    EXPECT_NEAR(my_sin(30), 0.5, EPSILON);                   
    EXPECT_NEAR(my_sin(1), 0.01745240643728351, EPSILON);    
}