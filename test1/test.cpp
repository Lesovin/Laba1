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