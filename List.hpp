#pragma once
#include <iostream>
using namespace std;




//template <typename T>
class List {
private:
	int* list;
	int length;

public:
	List();
	List(int, int);
	List(int*, int);
	~List();

	void insert(int, int);
	void append(int);
	void appendSeq(int*, int);
	void removeAt(int, int);
	int GetLength() const;

	const int& operator[](int) const;

	friend ostream& operator<< (ostream& os, const List&);
	friend const istream& operator>> (istream& in, List&);
};



