#pragma once
#include "List.hpp"
#include <iostream>

using namespace std;

//template <typename T>
class SortedList: public List {
public:
	SortedList();
	SortedList(int, int);
	SortedList(int*, int);

	int binarySearch( int target, int low, int high);

	
};
