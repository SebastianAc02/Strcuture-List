
#include "List.hpp"
#include <iostream>
using namespace std;

List::List() : length(0), list(nullptr) {}

List::List(int* arr, int arrSize) : length(arrSize), list(nullptr) {

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
List::~List() {
	delete[] list;
	list = nullptr;
}



void List::insert(int index, const int val) {

}
void List::removeAt(int index, int val) {
	list[index] = list[length];
	length--;
}
void List::append(int val) {
	////Ex. original size of 10
	//int* tempList = new int[length + 1]; //Ex. size of 11 is 0-10th elements
	//for (int i = 0; i < length; i++)
	//{
	//	tempList[i] = list[i]; //deep copy
	//	//tempList now has values of original list but also one extra index for another
	//	//value to be inserted
	//}
	////Change original list to the tempList
	//delete[] list;
	//list = nullptr;

	//list = tempList;   //list points to tempList

	//list[length] = val; // (last element of resized array) add value

	//length++;  //increase number of elements
}
void List::appendSeq(int* arr, int arrSize) {
	/*for (int i = 0; i < arrSize; i++)
	{
		append(arr[i]);
	}*/

	int newSize = arrSize + length;
	int* tempList = new int[newSize];

	for (int i = 0; i < length; i++)
	{
		tempList[i] = list[i]; //deep copy
	}
	for (int i = length; i < arrSize + length; i++)
	{
		tempList[i] = arr[i];
	}

	delete[] list;
	list = nullptr;

	list = tempList;

	length = arrSize + length;

}
const int& List :: operator[](int index) const {
	return list[index];
}

ostream& operator <<(ostream& os, const List& x) {
	for (int i = 0; i < x.length; i++)
	{
		os << x[i];
	}

	return os;

}

const istream& operator >> (istream& in, const int& x) {

	in >> x;
	return in;

}






