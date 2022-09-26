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


	
	virtual void quickSort(int start, int end) final;
	int partition(int start, int end);

	virtual int Search(int, int, int); //returns index it is located at

	void operator-(int);
	void operator--(int);
	void operator+(int);
	List operator+(const List&);
	const List& operator=(const List&); //assignment operator
	List& operator=(List&&); //move assignment operator
	const int& operator[](int) const;



	friend ostream& operator<< (ostream& os, const List&);
	friend const istream& operator>> (istream& in, List&);
};



