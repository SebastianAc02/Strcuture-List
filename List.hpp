#pragma once
#include <iostream>
using namespace std;




//template <typename T>
class List {
<<<<<<< HEAD
private:
=======
protected:
>>>>>>> b1895517ba09b77b12337cbc1d7c5ca4867f8f7d
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
<<<<<<< HEAD

	const int& operator[](int) const;
	//int operator+(int*, int size);
	friend ostream& operator<< (ostream& os, const List& x);
	friend const istream& operator>> (istream& in, const List&);
=======
	int GetLength() const;

	const int& operator[](int) const;

	friend ostream& operator<< (ostream& os, const List&);
	friend const istream& operator>> (istream& in, List&);
>>>>>>> b1895517ba09b77b12337cbc1d7c5ca4867f8f7d
};



