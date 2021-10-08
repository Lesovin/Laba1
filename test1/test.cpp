#include "pch.h"
#include"../Laba1/Set.h"
#include"../Laba1/Set.cpp"
 
TEST(Set, OperatorSquareBrackets)
{
	Set a;
	a + 1;
	ASSERT_EQ(1, a[0]);
}

TEST(Set, OperatorAddition)
{
	Set a;
	a + 1;
	a + 2;
	a + 3;
	for (int i = 0; i < 3; i++)
	{
		ASSERT_EQ(i + 1, a[i]);
	}
}

TEST(Set, OperatorAssignment)
{
	Set a;
	Set b;
	a + 1;
	a + 2;
	a + 3;
	b = a;
	for (int i = 0; i < 3; i++)
	{
		ASSERT_EQ(a[i], b[i]);
	}
}

TEST(Set, OperatorAssignmentOfSets)
{
	Set a;
	Set b;
	Set c;
	a + 1;
	a + 2;
	a + 3;
	b + 4;
	b + 5;
	b + 6;
	c = a + b;
	for (int i = 0; i < 6; i++)
	{
		ASSERT_EQ(i + 1, c[i]);
	}
}

TEST(Set, IntersectionOfSets)
{
	Set a;
	Set b;
	Set c;
	a + 1;
	a + 3;
	b + 3;
	b + 4;
	c = a.Intersection(b);
	ASSERT_EQ(3, c[0]);
}

TEST(Set, Subtraction)
{
	Set a;
	a + 1;
	a + 2;
	a - 2;
	ASSERT_EQ(1, a[0]);
}

TEST(Set, SubtractionOfSets)
{
	Set a;
	Set b;
	Set c;
	a + 1;
	a + 2;
	a + 3;
	b + 4;
	b + 3;
	b + 5;
	c = a - b;
	ASSERT_EQ(1, c[0]);
	ASSERT_EQ(2, c[1]);
	c = b - a;
	ASSERT_EQ(4, c[0]);
	ASSERT_EQ(5, c[1]);
}

TEST(Set, ExceptionInAdditionOperator)
{
	Set a;
	a + 1;
	ASSERT_THROW(a + 1, const char*);
}

TEST(Set, ExceptionInSubtractionOperator)
{
	Set a;
	ASSERT_THROW(a - 1, const char*);
}

TEST(Set, ExceptionInSquareBracketsOperator)
{
	Set a;
	a + 1;
	ASSERT_THROW(a[-1], const char*);
	ASSERT_THROW(a[2], const char*);
	a - 1;
	ASSERT_THROW(a[0], const char*);
}