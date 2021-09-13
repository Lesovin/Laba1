#include "Set.h"
#include <stdio.h>

int Set::Contain(int number) const
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

Set::Set(const Set& a)
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
}

Set::~Set()
{
	delete [] data;
	size = 0;
	data = NULL;
}

Set& Set::operator=(const Set& a)
{
		size = a.size;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = a.data[i];
		}
		return *this;
}

void Set::operator+(int number)
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == number)throw "Number already eixst!";
	}
	int* tmp = new int[size + 1];
	for (int i = 0; i < size; i++){tmp[i] = data[i];}
	tmp[size] = number;
	delete[] data;
	data = tmp;
	size++;
}

Set Set::operator+(const Set& a) const
{
	Set ResultSet=*this;
	for (int i = 0; i < a.size; i++) {
		bool flag = true;
		for (int j = 0; j < size; j++) 
		{
			if (a.data[i] == data[j]) 
			{
				flag = false;
				break;
			}
		}
		if (flag == true) 
		{
			ResultSet+a.data[i];
		}
	}
	return ResultSet;
}

Set Set::Intersection(const Set& set) const
{
	Set ResultSet;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < set.size; j++) 
		{
			if (data[i] == set.data[j]) ResultSet + data[i];
		}
	}
	return ResultSet;
}

int Set::operator[](int index) const
{
	if ((index > size) || (index < 0)||(size==0))throw "Incorrect index!";
		return data[index];
}

void Set::operator-(int number)
{
	int* tmp = new int[size-1];
	int index = Contain(number);
	size--;
	for (int i = 0; i < index; i++) { tmp[i] = data[i]; }
	for (int i = index+1; i < size + 1; i++) { tmp[i - 1] = data[i]; }
	delete[] data;
	data = tmp;
}

Set Set::operator-(const Set& set) const
{
	Set ResultSet;
	ResultSet = *this;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < set.size; j++)
		{
			if (data[i] == set.data[j])
			{
				ResultSet - set.data[j];
				break;
			}
		}
	}
	return ResultSet;
}

int Set::GetSize() const
{
	return size;
}

std::ostream& operator<<(std::ostream& out,const Set& set) 
{
	int size = set.GetSize();
	if (size == 0)
	{
		out << "Empty set";
		return out;
	}
	out << "{";
	for (int i = 0; i < size - 1; i++)
	{
		out << set[i] << ", ";
	}
	out << set[size - 1];
	out << "}";
	return out;
}
