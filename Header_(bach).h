// Bach Vo
#pragma once
#include <iostream>
#include <ostream>

template <typename T>
class List;

template <typename T>
ostream& operator<<(ostream&, const List<T>&);

template <typename T>
class List {
private:
	T* arr;
    int cap =0;
    int size =0;
public:
//  Constructors:
List();
~List();

    //  Accessing items by their index
    T at(const int index);

    //  Appending a single item 
    void add(const T item);

    //  Appending a sequence of items 
    void addList(const T *itemList, const int itemListSize);

    //  Inserting a single item at a specific index
    bool insert(const T item, const int index);

    //  Inserting a sequence of items starting at a specific index
    void insertList(const T *itemList, const int itemListSize, const int index);

    //  Removing the first or all occurrence(s) of an item
    bool remove(const T item, bool removeAll = false);

    //  Removing an item at a specific index
    bool removeAt(const int index);

    //  Sorting the items
    void sort();

    //  Searching an item
    bool search(const T item);

    //  Inserting the list into an output stream
    friend ostream& operator<< (ostream&, const List<T>&);

    //  Extracting a list from an input stream
    friend istream& operator>> (istream&, const List<T>&);

    //Helper func
private:
    void increaseCap(int increaseBy = 2);
    void print(const T* arr, const int arrSize);

        //Utility for sorting algo
    void swap(T* a, T* b);
    void quickSort(int leftIndex, int rightIndex);
    int partitionForQuickSort(int leftIndex, int rightIndex);
    
public:
    //  "--" : Removes the last item of the list.
    void operator-- ();

    //  "+" : Appends a new item to the list.
    void operator+ (const T&);

    //  "+" : Appends a list to the list.
    List<T> operator+ (const List<T>&);

    //  "-" : Removes all the items of a list from the list.
    List<T> operator- (const List<T>&);

    //  "[]" : Implements the index access operation.
    List<T>& operator[] (const int index) throw(runtime_error);
};
