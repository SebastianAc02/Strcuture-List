#include "SortedList.hpp"
#include "List.hpp"
 template <typename T>
SortedList<T>::SortedList() :List<T>() {}

 template <typename T>
SortedList<T>::SortedList(T* arr, int arrSize) : List<T>(arr, arrSize) {}


 template <typename T>
SortedList<T>::SortedList(int n, T v) : List<T>(n, v) {}


// low should be index 0  and high is the array length
 template <typename T>
int SortedList<T>::Search(T target, int low, int high)
{
   
    if (high >= low)
    {
        int mid = low + (high - low) / 2;

        if((this -> list[mid]) == target)
            return mid;
  
          

        //searching left side
       if((this -> list[mid] ) > target)
            return Search(target, low, mid - 1);
        
        //searching right hand
        return Search(target, mid + 1, low);

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
