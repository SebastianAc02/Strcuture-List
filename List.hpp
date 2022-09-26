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


<<<<<<< HEAD

	void insert(int, T);
	void append(T);
	void appendSeq(T*, int);
	void removeFirstorAll(T);
=======
	int access(int);
	void insert(int, int); //index, value
	void append(int);
	void appendSeq(int*, int);
	void removeFirstorAll(int);
>>>>>>> 445ecae117d71e455e05857f88e336bcfecf0903
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
	friend const istream& operator>> (istream& in, List&);
};



