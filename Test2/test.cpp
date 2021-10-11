#include "pch.h"
#include"../Laba1/Set.h"
#include"../Laba1/Set.cpp"

TEST(Set, OperatorSquareBrackets)
{
	Set<int> a;
	Set<float>b;
	Set<std::string>c;
	a + 1;
	b + 2.5;
	c + "test";
	ASSERT_EQ(1, a[0]);
	ASSERT_EQ(2.5, b[0]);
	ASSERT_EQ("test", c[0]);
}

TEST(Set, OperatorAddition)
{
	Set<int> a;
	Set<float> b;
	Set<std::string>c;
	a + 1;
	a + 2;
	a + 3;
	b + 2.5;
	b + 2.3;
	b + 22.123123;
	c + "test1";
	c + "test2";
	c + "test3";
	for (int i = 0; i < 3; i++)
	{
		ASSERT_EQ(i + 1, a[i]);
	}
	ASSERT_EQ((float)2.5, b[0]);
	ASSERT_EQ((float)2.3, b[1]);
	ASSERT_EQ((float)22.123123, b[2]);
	ASSERT_EQ("test1", c[0]);
	ASSERT_EQ("test2", c[1]);
	ASSERT_EQ("test3", c[2]);
}

TEST(Set, OperatorAssignment)
{
	Set<int> a;
	Set<int> b;
	Set<float> af;
	Set<float> bf;
	Set<std::string> as;
	Set<std::string> bs;
	a + 1;
	a + 2;
	a + 3;
	af + (float)2.5;
	af + (float)3.4;
	af + (float)5.1;
	as + "test1";
	as + "test2";
	as + "test3";
	b = a;
	bf = af;
	bs = as;
	for (int i = 0; i < 3; i++)
	{
		ASSERT_EQ(a[i], b[i]);
		ASSERT_EQ(af[i], bf[i]);
		ASSERT_EQ(as[i], bs[i]);
	}
}

TEST(Set, OperatorAssignmentOfSets)
{
	Set<int> a;
	Set<int> b;
	Set<int> c;
	Set<float>af;
	Set<float>bf;
	Set<float>cf;
	Set<std::string>as;
	Set<std::string>bs;
	Set<std::string>cs;
	a + 1;
	a + 2;
	a + 3;
	b + 4;
	b + 5;
	b + 6;
	af + (float)2.5;
	bf + (float)3.4;
	cf = af + bf;
	as + "test1";
	bs + "test2";
	cs = as + bs;
	c = a + b;
	for (int i = 0; i < 6; i++)
	{
		ASSERT_EQ(i + 1, c[i]);
	}
	ASSERT_EQ((float)2.5, cf[0]);
	ASSERT_EQ((float)3.4, cf[1]);
	ASSERT_EQ("test1", cs[0]);
	ASSERT_EQ("test2", cs[1]);
}

TEST(Set, IntersectionOfSets)
{
	Set<int> a;
	Set<int> b;
	Set<int> c;
	Set<float>af;
	Set<float>bf;
	Set<float>cf;
	Set<std::string>as;
	Set<std::string>bs;
	Set<std::string>cs;
	a + 1;
	a + 2;
	b + 2;
	b + 3;
	c = a.Intersection(b);
	af + (float)2.5;
	af + (float)3.4;
	bf + (float)3.4;
	bf + (float)5.6;
	cf = af.Intersection(bf);
	as + "test1";
	as + "test2";
	bs + "test2";
	bs + "test3";
	cs = as.Intersection(bs);
	ASSERT_EQ(2, c[0]);
	ASSERT_EQ((float)3.4, cf[0]);
	ASSERT_EQ("test2", cs[0]);
}

TEST(Set, Subtraction)
{
	Set<int> a;
	Set<float>b;
	Set<std::string>c;
	a + 1;
	a + 2;
	a - 2;
	b + 1.5;
	b + 2.4;
	b - 2.4;
	c + "test1";
	c + "test2";
	c - "test2";
	ASSERT_EQ(1, a[0]);
	ASSERT_EQ((float)1.5, b[0]);
	ASSERT_EQ("test1", c[0]);
}

TEST(Set, SubtractionOfSets)
{
	Set<int> a;
	Set<int> b;
	Set<int> c;
	Set<float>af;
	Set<float>bf;
	Set<float>cf;
	Set<std::string>as;
	Set<std::string>bs;
	Set<std::string>cs;
	a + 1;
	a + 2;
	a + 3;
	b + 4;
	b + 3;
	b + 5;
	c = a - b;
	ASSERT_EQ(1, c[0]);
	ASSERT_EQ(2, c[1]);
	af + 1.5;
	af + 3.4;
	bf + 3.4;
	bf + 5.6;
	cf = af - bf;
	ASSERT_EQ((float)1.5, cf[0]);
	as + "test1";
	as + "test2";
	bs + "test2";
	bs + "test3";
	cs = as - bs;
	ASSERT_EQ("test1", cs[0]);
}

TEST(Set, ExceptionInAdditionOperator)
{
	Set<int> a;
	Set<float>b;
	Set<std::string>c;
	a + 1;
	b + 1.5;
	c + "test";
	ASSERT_THROW(a + 1, const char*);
	ASSERT_THROW(b + 1.5, const char*);
	ASSERT_THROW(c + "test", const char*);
}

TEST(Set, ExceptionInSubtractionOperator)
{
	Set<int> a;
	Set<float>b;
	Set<std::string>c;
	ASSERT_THROW(a - 1, const char*);
}

TEST(Set, ExceptionInSquareBracketsOperator)
{
	Set<int> a;
	a + 1;
	ASSERT_THROW(a[-1], const char*);
	ASSERT_THROW(a[2], const char*);
	a - 1;
	ASSERT_THROW(a[0], const char*);
}