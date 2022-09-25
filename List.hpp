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
	void removeFirstorAll(int);
	void removeAt(int);
	int GetLength() const;
	void SetLength(int);
<<<<<<< HEAD
=======

	void Sort();
	int Search(int); //returns index it is located at

>>>>>>> d54f4f8b76ff694bc1bcb59e4f99903584e39199
	void operator-(int);
	void operator--(int);
	void operator+(int);
	void operator+(int*);
	const List& operator=(const List&); //assignment operator
	List& operator=(List&&); //move assignment operator
	const int& operator[](int) const;



	friend ostream& operator<< (ostream& os, const List&);
	friend const istream& operator>> (istream& in, List&);
};



