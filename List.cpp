
#include "List.hpp"
#include <iostream>
#include <string>
using namespace std;



 template <typename T>
List<T>::List() : length(0), list(nullptr) {}

 template <typename T>
List<T>::List(T* arr, int arrSize) : length(arrSize), list(new T[arrSize]) {

	for (int i = 0; i < length; i++)
	{
		list[i] = arr[i];
	}

}
<<<<<<< HEAD
List::List(int n, int v) :length(n), list(nullptr) {
=======

 template <typename T>
List<T>::List(int n, T v) :length(n), list(new T[n]) {
>>>>>>> 870d0778a08bd099a0f095b915865bb91cd3a783
	if (n < 0) {
		const char* exception = "ERROR: the number has to be a positive integer";
		throw exception;
	}
	list = new int[n];
	for (int i = 0; i < n; i++)
	{
		list[i] = v;
	}
	

}

 template <typename T>
List<T>::List(List& li) { //Copy constructor
	length = li.length;
	list = new int[length];
	for (int i = 0; i < length; i++)
	{
		list[i] = li[i];
	}
}


 template <typename T>
List<T>::List(List&& li) { //Move Constructor
	length = li.length;
	li.length = 0;
	list = li.list;
	li.list = nullptr;
}

 template <typename T>
List<T>::~List() {
	delete[] list;
	list = nullptr;
}


 template <typename T>
int List<T>::GetLength() const {
	return length;
}
 template <typename T>
void List<T>::SetLength(int len) {
	length = len;
}

template <typename T>
T List<T>:: access(int index) {
	return list[index];
}

template <typename T>
void List<T>::insert(int index, const int val) {
	list[index] = val;
}

 template <typename T>
void List<T>::removeAt(int index) {

	for (int i = 0; i < length; i++)
	{
		if (index == i) {
			for (; i < length - 1; i++)
			{
				list[i] = list[i + 1];
			}
			list[length - 1] = 0;
			length--;
		}
	}
}

 template <typename T>
void List<T>::removeFirstorAll(T val) {
	int input;
	cout << "Remove first of an item enter 0 or Remove all occurences of an item enter 1\n";
	cin >> input;

	if (input == 0) {
		for (int i = 0; i < length; i++)
		{
			if (list[i] == val) {
				for (; i < length - 1; i++) //once it finds it, start at that index and then push it to the end
				{
					list[i] = list[i + 1];
				}
				list[length - 1] = 0;
				length--;
			}
		}
	}
	else if (input == 1) {
		for (int i = 0; i < length; i++)
		{
			if (list[i] == val) {
				for (; i < length - 1; i++)
				{
					list[i] = list[i + 1];
				}
				list[length - 1] = 0;
				length--;
				i = 0; //reset to look through the list again to find if another element contains the value.
			}

		}
	}
}


 template <typename T>
void List<T>::append(T val) {
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

 template <typename T>
void List<T>::appendSeq(T* arr, int arrSize) {

	int* tempList = new int[length + arrSize];
	for (unsigned int i = 0; i < length; i++) {
		tempList[i] = list[i];
	}
	for (unsigned int i = 0, tempIndex = length; i < arrSize; i++, tempIndex++) {
		tempList[tempIndex] = arr[i];
	}
	
	delete[] list;
	list = nullptr;

	list = tempList;

	length = length + arrSize;

	
}



 template <typename T>
int List<T>::Search(T val, int low, int high) {
	for (int i = low; i < high; i++)

	{
		if (list[i] == val) {
			return i;
		}
	}

}

 template <typename T>
void List<T>::operator- (T) {

	delete[] list;
	list = nullptr;
	length = 0;
}

 template <typename T>
const int& List<T> :: operator[](int index) const {
	return list[index];
}

 template <typename T>
void List<T>:: operator--(T) {

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

 template <typename T>
T* List<T>::getList()
{
	return list;
}

 template <typename T>
void List<T>:: operator+(T val) {

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

 template <typename T>
List<T> List<T>:: operator+(const List<T>& li) {
int* tempList = new int[length + li.length];
	for (unsigned int i = 0; i < length; i++) {
		tempList[i] = list[i];

	}
	for (unsigned int i = 0, tempIndex = length; i < li.length; i++, tempIndex++) {
		tempList[tempIndex] = li.list[i];
	}
	
	
	return List(tempList, (length+li.length));
	
}

// List <T>??&
 template <typename T>
const List<T>& List<T>::operator=(const List<T>& li) {
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

 template <typename T>
List<T>& List<T>::operator=(List<T>&& li) {
	if (this != &li) {
		swap(list, li.list);
		swap(length, li.length);
	}
	return *this;
}

 template <typename T>
ostream& operator <<(ostream& os, const List<T>& x) 
{
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

 template <typename T>
const istream& operator >> (istream& in, List<T>& x) {
	cout << "Enter length of list: \n";
	in >> x.length;
	x.list = new int[x.length];



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




 template <typename T>
int List<T>::partition(int start, int end)
{

	int pivot = list[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (list[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(list[pivotIndex], list[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (list[i] <= pivot) {
			i++;
		}

		while (list[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(list[i++], list[j--]);
		}
	}

	return pivotIndex;
}

 template <typename T>
void List<T>::quickSort(int start, int end) //end must be length-1S
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(start, end);

	// Sorting the left part
	quickSort(start, p - 1);

	// Sorting the right part
	quickSort(p + 1, end);
}

template<typename T>
void insertAt(int){
	
}


