#include <gtest/gtest.h>
#include"../lib_calculator/Lexem.h"

TEST(TestLexem, test_create) {
	ASSERT_NO_THROW(Lexem A("1", Constant, 3, 1));
}