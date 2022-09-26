#ifndef SortedList_h
#define SortedList_h
#include "List.hpp"

#include <iostream>

using namespace std;

template <class T>
class SortedList : public List<T> {

private:
    //    int partition(int arr[], int start, int end);
public:

    SortedList();
    SortedList(int, T);
    SortedList(T*, int);



  
    int Search(T target, int low, int high) override;


    //void quickSort(int arr[], int start, int end);

};

#endif
