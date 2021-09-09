#include "Set.h"
#include <stdio.h>

int Set::Contains(int number)
{
	int index = 0;
	while (data[index] != number)
	{
		index++;
		if (index > size - 1)throw "Number does not exist!";
	}
	return index;
}

Set::Set()
{
	data = NULL;
	size = 0;
}

Set::~Set()
{
	delete []data;
}

void Set::operator+(int number)
{
	int* tmp = new int[size + 1];
	for (int i = 0; i < size; i++){tmp[i] = data[i];}
	tmp[size] = number;
	delete[]data;
	data = tmp;
	size++;
}

void Set::operator+(Set& set)
{

}

int Set::operator[](int index) const
{
	if ((index > size) || (index < 0)) throw "Incorrect index!";
		return data[index];
}

void Set::operator-(int number)
{
	int* tmp = new int[size-1];
	int index = Contains(number);
	size--;
	for (int i = 0; i < index; i++) { tmp[i] = data[i]; }
	for (int i = index+1; i < size + 1; i++) { tmp[i - 1] = data[i]; }
	delete[] data;
	data = tmp;
}

int Set::GetSize() const
{
	return size;
}

std::ostream& operator<<(std::ostream& out,const Set& set)
{
	int size = set.GetSize();
	out << "{";
	for (int i = 0; i < size - 1; i++)
	{
		out << set[i] << ", ";
	}
	out << set[size - 1];
	out << "}";
	return out;
}
