#include <gtest/gtest.h>
#include"../lib_calculator/Parser.h"

TEST(TestParser, test_work) {
	std::string a = "23+9*45/9^ahd6-sin(r)";
	List<Lexem> F;
	ASSERT_NO_THROW(Parser::parser(a, F));
}

TEST(TestParser, test_work_good) {
	std::string a = "23*ahd6^sin(r)";
	List<Lexem> F;
	Parser::parser(a, F);
	List<Lexem>::Iterator it = F.begin();
	Lexem A = *it;
	EXPECT_EQ(A.name, "23"); 
	EXPECT_EQ(A.value, 23);
	EXPECT_EQ(A.type, Constant);
	EXPECT_EQ(A.priority, -1);
	it++;
	A = *it;
	EXPECT_EQ(A.name, "*");
	EXPECT_EQ(A.value, 0);
	EXPECT_EQ(A.type, Operator);
	EXPECT_EQ(A.priority, 2);
	it++;
	A = *it;
	EXPECT_EQ(A.name, "ahd6");
	EXPECT_EQ(A.value, 0);
	EXPECT_EQ(A.type, Variable);
	EXPECT_EQ(A.priority, -1);
	it++;
	A = *it;
	EXPECT_EQ(A.name, "^");
	EXPECT_EQ(A.value, 0);
	EXPECT_EQ(A.type, Operator);
	EXPECT_EQ(A.priority, 3);
	it++;
	A = *it;
	EXPECT_EQ(A.name, "sin");
	EXPECT_EQ(A.value, 0);
	EXPECT_EQ(A.type, Function);
	EXPECT_EQ(A.priority, 6);
}

TEST(TestParser, test_work2) {
	std::string a = "23+9*45/9^ahd6-sin";
	List<Lexem> F;
	EXPECT_FALSE(Parser::parser(a, F));
}

TEST(TestParser, test_work3) {
	std::string a = "23+9*45/9^ahd6-(sin";
	List<Lexem> F;
	EXPECT_FALSE(Parser::parser(a, F));
}

TEST(TestParser, test_work4) {
	std::string a = "";
	List<Lexem> F;
	EXPECT_FALSE(Parser::parser(a, F));
}

TEST(TestParser, test_work5) {
	std::string a = "23+9*45/0";
	List<Lexem> F;
	EXPECT_FALSE(Parser::parser(a, F));
}
