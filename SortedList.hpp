#pragma once
#include "List.hpp"
#include <iostream>

using namespace std;

//template <typename T>
class SortedList: public List {

private :
	int partition(int arr[], int start, int end);
public:
	SortedList();
	SortedList(int, int);
	SortedList(int*, int);

	void Sort();
	int binarySearch( int target, int low, int high);
	
	void quickSort(int arr[], int start, int end);
	
};

