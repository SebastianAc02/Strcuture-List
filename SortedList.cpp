#include "SortedList.hpp"

SortedList::SortedList() :List() {}
SortedList::SortedList(int* arr, int arrSize) : List(arr, arrSize) {}
SortedList::SortedList(int n, int v) : List(n, v) {}




// low should be index 0  and high is the array length 
int SortedList::binarySearch(int target, int low, int high)
{
	if (high >= low)
	{
		int mid = low + (high - low) / 2;

		if (list[mid] == target)
			return mid;

		//searching left side
		if (list[mid] > target)
			return binarySearch(target, low, mid - 1);

		//searching right hand
		return binarySearch(target, mid + 1, low);

	}


	return -1;




}

