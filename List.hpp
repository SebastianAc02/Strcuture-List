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

	const int& operator[](int) const;
	//int operator+(int*, int size);
	friend ostream& operator<< (ostream& os, const List& x);
	friend const istream& operator>> (istream& in, const List&);
};



