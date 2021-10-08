#pragma once
#include <iostream>

class Set
{
private:
	int*data;
	int size;
	int Contain(int number)const;
	int GetSize()const;
public:
	Set();
	Set(const Set& a);
	~Set();
	Set& operator=(const Set& a);
	void operator+(int number);
	Set operator+(const Set& a)const;
	Set Intersection(const Set&set)const;
	int operator[](int index)const;
	void operator-(int number);
	Set operator-(const Set& set)const;
	friend std::ostream& operator<<(std::ostream& out, const Set& set);
};

