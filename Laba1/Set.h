#pragma once
#include <iostream>
#include <string>
#include <vector>

template <class T>
class Set
{
private:
	std::vector<T> v;
public:

	auto Contain(T element)const
	{
		auto index = v.begin();
		if (*index == element) return index;
		while (*index != element)
		{
			++index;
			if (*index == element) return index;
		}
		throw "Element does not exist!";
	}

	int GetSize()const
	{
		return v.size();
	}

    void operator+(T number)
	{
		for (auto i: v)
		{
			if (*i == number) throw "Element already eixst!";
		}
		v.push_back(number);
	}

	Set<T> operator+(const Set<T>& a) const
	{
		Set<T> ResultSet = *this;
		for (int i = 0; i < a.GetSize(); i++) 
		{
			bool flag = true;
			for (auto j: v)
			{
				if (a[i] == *j)
				{
					flag = false;
					break;
				}
			}
			if (flag == true)
			{
				ResultSet + a[i];
			}
		}
		return ResultSet;
	}

	Set<T> Intersection(const Set<T>& set) const
	{
		Set<T> ResultSet;
		for (auto i: v)
		{
			for (int j = 0; j < set.GetSize(); j++)
			{
				if (*i == set[j]) ResultSet + v[i];
			}
		}
		return ResultSet;
	}
	
	T operator[](int index) const
	{
		if ((index > v.size() - 1) || (index < 0) || (v.size() == 0))throw "Incorrect index!";
		return v[index];
	}
	void operator-(T number)
	{
		if (v.size() == 0) throw "No elements exist!";
		auto index = Contain(number);
		v.erase(index);
	}
	Set<T> operator-(const Set<T>& set) const
	{
		Set<T> ResultSet;
		ResultSet = *this;
		for (auto i: v)
		{
			for (int j = 0; j < set.GetSize(); j++)
			{
				if (i == set[j])
				{
					ResultSet - set[j];
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
