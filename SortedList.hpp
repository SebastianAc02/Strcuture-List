#pragma once
#include "List.hpp"
#include <iostream>

using namespace std;

//template <typename T>
class SortedList: public List {

private :
//	int partition(int arr[], int start, int end);
public:

	SortedList();
	SortedList(int, int);
	SortedList(int*, int);

	
	 int  Search ( int target, int low, int high)  override  ;
	
	//void quickSort(int arr[], int start, int end);
	
};

