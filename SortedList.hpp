#pragma once
#include "List.hpp"
#include <iostream>

using namespace std;

//template <typename T>
class SortedList : public List {

private:
	//	int partition(int arr[], int start, int end);
public:

	SortedList();
	SortedList(int, int);
	SortedList(int*, int);

<<<<<<< HEAD
	
	 int  Search ( int target, int low, int high)  override  ;
	
=======

	int Search(int target, int low, int high) override;

>>>>>>> 1181ddc5a5e5f24df800c04fe25e4fd58a23eef3
	//void quickSort(int arr[], int start, int end);

};

