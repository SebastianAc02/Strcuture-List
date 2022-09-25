
#include "List.hpp"
#include <iostream>
#include <string>
using namespace std;

List::List() : length(0), list(nullptr) {}

List::List(int* arr, int arrSize) : length(arrSize), list(new int[arrSize]) {

	for (int i = 0; i < length; i++)
	{
		list[i] = arr[i];
	}

}
List::List(int n, int v) :length(n), list(new int[n]) {
	if (n < 0) {
		throw "ERROR: the number has to be a positive integer";
	}
	for (int i = 0; i < n; i++)
	{
		list[i] = v;
	}


}
List::List(List& li) { //Copy constructor
	length = li.length;
	list = new int[length];
	for (int i = 0; i < length; i++)
	{
		list[i] = li[i];
	}
}

List::List(List&& li) { //Move Constructor
	length = li.length;
	li.length = 0;
	list = li.list;
	li.list = nullptr;
}
List::~List() {
	delete[] list;
	list = nullptr;
}


int List::GetLength() const {
	return length;
}
void List::SetLength(int len) {
	length = len;
}
void List::insert(int index, const int val) {
	list[index] = val;
}
void List::removeAt(int index, int val) {
	list[index] = list[length];
	length--;
}
void List::append(int val) {
	//Ex. original size of 10
	int* tempList = new int[length + 1]; //Ex. size of 11 is 0-10th elements
	for (int i = 0; i < length; i++)
	{
		tempList[i] = list[i]; //deep copy
		//tempList now has values of original list but also one extra index for another
		//value to be inserted
	}
	//Change original list to the tempList
	delete[] list;
	list = nullptr;

	list = tempList;   //list points to tempList

	list[length] = val; // (last element of resized array) add value

	length++;  //increase number of elements
}
void List::appendSeq(int* arr, int arrSize) {
	for (int i = 0; i < arrSize; i++)
	{
		append(arr[i]);
	}

}
const int& List :: operator[](int index) const {
	return list[index];
}

void List:: operator--(int) {

	int* tempList = new int[length - 1];
	for (int i = 0; i < length - 1; i++)
	{
		tempList[i] = list[i]; //deep copy
	}
	delete[] list;
	list = nullptr;

	list = tempList;

	length--;



}

void List:: operator+(int val) {

	int* tempList = new int[length + 1];
	for (int i = 0; i < length; i++)
	{
		tempList[i] = list[i]; //deep copy
	}
	//Change original list to the tempList
	delete[] list;
	list = nullptr;

	list = tempList;   //list points to tempList

	list[length] = val; // (last element of resized array) add value

	length++;  //increase number of elements



}
void List:: operator+(int* arr) {
	/*for (int i = 0; i < (sizeof(arr)/sizeof (*arr)); i++)
	{
		append(arr[i]);
	}*/



}

const List& List::operator=(const List& li) {
	if (this != &li) {
		length = li.length;
		if (list != nullptr) {
			delete[] list;
		}
		list = new int[li.length];
		for (int i = 0; i < li.length; i++)
		{
			list[i] = li[i];
		}
	}

	return *this;
}

List& List::operator=(List&& li) {
	if (this != &li) {
		swap(list, li.list);
		swap(length, li.length);
	}
	return *this;
}


ostream& operator <<(ostream& os, const List& x) {
	os << "{";
	for (int i = 0; i < x.length; i++)
	{
		if (i != x.length - 1) //values except for the last value will have a "," after it
			os << x[i] << ", ";
		else {
			os << x[i];
		}
	}
	os << "}";
	return os;

}

const istream& operator >> (istream& in, List& x) {
	cout << "Enter length of list: \n";
	in >> x.length;
	x.list = new int[x.length];

	//Extract values one by one
	/*for (int i = 0; i < x.length; i++)
	{
		cout << "enter value " << i << " for list: ";
		in >> x.list[i];
	}
	*/

	////Other way to extract ex. 0 1 2 
	cout << "Enter values for list ex. 0 1 2 for length 3\n";
	int val;
	for (int i = 0; i < x.length; i++)
	{
		in >> val;
		if (val == ' ')
			continue;
		else
			x.list[i] = val;
	}



	return in;
}






