#pragma once
#include <iostream>
template <class T>
class Set
{
private:
	T* data;
	int size;
	int Contain(T number)const
	{
		int index = 0;
		while (data[index] != number)
		{
			index++;
			if (index > size - 1)throw "Number does not exist!";
		}
		return index;
	}
	int GetSize()const
	{
		return size;
	}
public:
	Set()
	{
		data = NULL;
		size = 0;
	}
	Set(const T& a)
	{
		size = a.size;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = a.data[i];
		}
	}
	~Set()
	{
		delete[] data;
	}
	T& operator=(const T& a)
	{
		size = a.size;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = a.data[i];
		}
		return *this;
	}
    void operator+(T number)
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] == number)throw "Number already eixst!";
		}
		int* tmp = new int[size + 1];
		for (int i = 0; i < size; i++) { tmp[i] = data[i]; }
		tmp[size] = number;
		delete[] data;
		data = tmp;
		size++;
	}
	T operator+(const Set<T>& a) const
	{
		T ResultSet = *this;
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
				ResultSet + a.data[i];
			}
		}
		return ResultSet;
	}

	T Intersection(const Set<T>& set) const
	{
		T ResultSet;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < set.size; j++)
			{
				if (data[i] == set.data[j]) ResultSet + data[i];
			}
		}
		return ResultSet;
	}
	T operator[](int index) const
	{
		if ((index > size - 1) || (index < 0) || (size == 0))throw "Incorrect index!";
		return data[index];
	}
	void operator-(T number)
	{
		if (size == 0) throw "No numbers exist!";
		T* tmp = new T[size - 1];
		int index = Contain(number);
		size--;
		for (int i = 0; i < index; i++) { tmp[i] = data[i]; }
		for (int i = index + 1; i < size + 1; i++) { tmp[i - 1] = data[i]; }
		delete[] data;
		data = tmp;
	}
	T operator-(const Set<T>& set) const
	{
		T ResultSet;
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
	friend std::ostream& operator << (std::ostream& out, const Set<T>& set)
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
};