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

/*int SortedList::partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}*/

/*void SortedList::quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}*/