#pragma once
#include <iostream>
using namespace std;




template <typename T>
class List {

private:
	int partition(int start, int end);
protected:
	T* list;
	int length;
	


public:
	List();
	List(int, T);
	List(T*, int);
	List(List&);//copy constructor
	List(List&&); //move constructor
	~List();


	T access(int);
	void insert(int, T); //index, value
	void append(T);
	void appendSeq(T*, int);
	void removeFirstorAll(T);
	void removeAt(int);
	int GetLength() const;
	void SetLength(int);




	virtual void quickSort(int start, int end) final;
	virtual int Search(T, int, int); //returns index it is located at

	T* getList(); 
	void operator-(T);
	void operator--(T);
	void operator+(T);
	List operator+(const List&);
	const List& operator=(const List&); //assignment operator
	List& operator=(List&&); //move assignment operator
	const int& operator[](int) const;




	friend ostream& operator<< (ostream& os, const List&);
	friend const istream& operator>>  (istream& in, List&);
};



