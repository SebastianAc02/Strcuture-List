#include "Header.h"
#include <iostream>

using namespace std;

//===========================================//
//Constructors
template <typename T>
List<T>::List()
{
	cout << "constructor called\n";		//_test
	cap = 10;
	arr = new T[cap];
}

template <typename T>
List<T>::~List() {
	delete[] arr;
}

//==============================================//
//Utility func

template <typename T>
void List<T>::increaseCap(int increaseBy) {
	cap *= increaseBy;
	T* tempArr = new T[cap];
	for (int i = 0; i < size; i++)
		tempArr[i] = arr[i];

	delete[] arr;
	arr = nullptr;

	arr = tempArr;
}

template <typename T>
void List<T>::print(const T* arr, const int arrSize) {
	cout << "\narr: ";
	for (int i = 0; i < arrSize; i++)
		cout << arr[i];
}

//Sorting
template <typename T>
void List<T>::swap(T* a, T* b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <typename T>
int List<T>::partitionForQuickSort(int leftIndex, int rightIndex) {
	int pivot = arr[rightIndex];
	int i = leftIndex - 1;
	for (int j = left; i <= rightIndex; i++) {
		if (arr[j] < pivot) {
			swap(&arr[++i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[rightIndex]);
	return i + 1;
}

template <typename T>
void List<T>::quickSort(int leftIndex, int rightIndex) {
	if (leftIndex < rightIndex) {
		int partitionIndex = partitionForQuickSort(leftIndex, rightIndex);
		quickSort(leftIndex, partitionIndex - 1);
		quickSort(partitionIndex, rightIndex);
	}
}
//===============================================//
// Main func
template <typename T>
T List<T>::at(const int index)
{
	if(!search(arr[index]))
		// return ERROR; item at index doesn't exist
	return arr[index];
}

template <typename T>
void List<T>::add(const T item) {
	if (size >= cap)
		increaseSize();
	arr[size] = item;
}

template <typename T>
void List<T>::addList(const T* itemList, const int itemListSize) {
	if((itemListSize + size) > cap)
		increaseCap();	//Crate a for loop to make sure will have enough room for the whole seq

	T* tempArr = new T[cap];
	for (int i = 0; i < size; i++)
		tempArr[i] = arr[i];
	for (int i = size; i < (size + itemListSize); i++)
		tempArr[i] = itemList[i];
}

/*
 * Case1: if(0 <= index <= size) : insert in between; return true
 * Case2: if(size < index < cap): insert arr[size]; return true
 * Case3: if(index < size || index > cap) : return false
 */
template <typename T>
bool List<T>::insert(const T item, const int index) {
	if(index>size || index <= 0)
		return false;
	
	for (int i = index; i < size; i++)
		arr[i + 1] = arr[i];

	arr[index] = item;
	return true;
}

template <typename T>
void List<T>::insertList(const T* itemList, const int itemListSize, const int index) {
	if ((itemListSize + size) > cap)
		increaseCap();	// ceiling((itemListSize/size))
	
	for (int i = index, int j =0; i < ; i++, j++) {
		insert(itemList[j], i);
	}
}

template <typename T>
bool List<T>::remove(const T item, bool removeAll) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == item) {
			arr[i] = arr[size];
			size--;

			if (removeAll)
				remove(const T item, removeAll);	// recursion to find all occurrences
		}
		return true;
	}
retrun false;
}

template <typename T>
bool List<T>::removeAt(const int index) {
	if (index < 0 || index > size) {
		return false;		// index is out_of_bound
	}
	arr[index] = arr[size];
	size--;

	return true;
}

template <typename T>
void List<T>::sort() {
	if (isdigit(arr[0])) {
		//
	}
	else if (isalpha(arr[0])) {
		//
	}
	else {
		cout << "ERROR: sort() can only sort arr of alnum";
	}
}

template <typename T>
bool List<T>::search(const T item) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == item)
			return true;
	}
	return false;
}

//====================================================//
// Operator Overloading

// -- //
template <typename T>
void List<T>::operator--() {
	if (size <= 0) {
		// Error:
	}
	size--;		// by decresing size by one, the last item of the arr is inaccessible
 }

//	+	//
template <typename T>
void List<T>::operator+(const T& item) {
	add(item);
}

//	+	// list + list
template <typename T>
List<T> List<T>::operator+(const List<T>& anotherList) {
	T* tempList = new T[size + anotherList.size];
	for (unsigned int i = 0; i < size; i++) {
		tempList[i] = arr[i];
	}
	for (unsigned int i = 0, tempIndex = size; i < anotherList.size; i++, tempIndex++) {
		tempList[tempIndex] = anotherList.arr[i];
	}
	return *this;
}

//	-	//
template <typename T>
List<T> List<T>::operator-(const List<T>& anotherList) {
	if (size == 0) {
		return *arr;		// list of 0 items
	}
	else if (anotherList.size == 0) {
		return *arr;		// original list (right side List)
	}
	else {
		T* tempList = new T[(size<anotherList.size)?anotherList.size:size];	//max(size, anotherList.size);
		//?? need to declear a new arr OR use 'List result(size+ anotherList.size)' aka Parameterized Constructor ??
		for (unsigned int i = 0, tempIndex = 0; i < anotherList.size; i++) {
			if (!search(anotherList.arr[i])) {
				tempList[tempIndex++] = anotherList.arr[i];
			}
		}
	}
	return *this;	// *tempList
}

//  []  //
template <typename T>
List<T> &List<T>::operator[] (const int index) throw(runtime_error) {
	if (index < 0 || index > size) {
		throw runtime_error("Index out_of_range");	
	}
	return arr[index];
}

//	<<	//
template <typename T>
ostream& operator<< (ostream& out, const List<T>& anotherList) {
	cout << "[ ";
	for (unsigned int i = 0; i < anotherList.size; i++) {
		cout << anotherList.arr[i] << " ";
	}
	cout << "]";
	return out;
}

//	>>	//
template <typename T>
istream& operator>> (istream& in, const List<T>& anotherList) {
	for (unsigned int i = 0; i < anotherList.size; i++) {
		in >> anotherList.arr[i];
	}
	return 0;
}
