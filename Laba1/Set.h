#include <iostream>
template <class T>
class Set
{
private:
	T* data;
	int size;
	int Contain(T number)const;
	int GetSize()const;
public:
	Set();
	Set(const T& a);
	~Set();
	T& operator=(const T& a);
	void operator+(T number);
	T operator+(const Set<T>& a)const;
	T Intersection(const Set<T>& set)const;
	T operator[](int index)const;
	void operator-(T number);
	T operator-(const Set<T>& set)const;
	friend std::ostream& operator<<(std::ostream& out, const Set<T>& set);
};