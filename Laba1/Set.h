#include <iostream>
class Set
{
private:
	int*data;
	int size;
	int Contains(int number);
public:
	Set();
	~Set();
	void operator+(int number);
	void operator+(Set&set);
	int operator[](int index)const;
	void operator-(int number);
	int GetSize()const;
	friend std::ostream& operator<<(std::ostream& out, const Set& set);
};

