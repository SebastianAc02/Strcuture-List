#pragma once
#include <iostream>
using namespace std;




//template <typename T>
class List {
protected:
	int* list;
	int length;

public:
	List();
	List(int, int);
	List(int*, int);
	List(List&);//copy constructor
	List(List&&); //move constructor
	~List();

	void insert(int, int);
	void append(int);
	void appendSeq(int*, int);
	void removeAt(int, int);
	int GetLength() const;
	void SetLength(int);

	void operator--(int);
	void operator+(int);
	void operator+(int*);
	const List& operator=(const List&); //assignment operator
	List& operator=(List&&);
	const int& operator[](int) const;
	
	

	friend ostream& operator<< (ostream& os, const List&);
	friend const istream& operator>> (istream& in, List&);
};



