#include <gtest/gtest.h>
#include"../lib_calculator//Obr_pol.h"
#include"../lib_calculator/Parser.h"


TEST(TestObrPol, test_works) {
	std::string a = "sin(5+t^ln(6))";
	List<Lexem> F;
	List<Lexem> D;
	Parser::parser(a, F);
	building_reverse_Polish(F, D, a.size());
	List<Lexem>::Iterator it = D.begin();
	Lexem A = *it;
	EXPECT_EQ(A.name, "5");
	it++;
	A = *it;
	EXPECT_EQ(A.name, "t");
	it++;
	A = *it;
	EXPECT_EQ(A.name, "6");
	it++;
	A = *it;
	EXPECT_EQ(A.name, "ln");
	it++;
	A = *it;
	EXPECT_EQ(A.name, "^");
	it++;
	A = *it;
	EXPECT_EQ(A.name, "+");
	it++;
	A = *it;
	EXPECT_EQ(A.name, "sin");
}