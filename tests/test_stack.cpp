// Copyright 2025 Marina Usova

#include <gtest/gtest.h>
#include "../lib_stack/stack.h"

#define EPSILON 0.000001

TEST(TestStackLib, can_create_stack) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(Stack<int> s(11));
}
