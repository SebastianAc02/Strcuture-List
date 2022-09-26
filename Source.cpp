#include <iostream>
#include "List.hpp"
#include "SortedList.hpp"

using namespace std;


int main() {
	///////////////////
	////PART 3
	///////////////////

	SortedList list1;
	List list2;
	

	cout << "Enter your sorted list of integers: \n";
	cin >> list1;
	cout << "Enter your unsorted list of integers: \n";
	cin	>> list2;

	list1.quickSort(0, list1.GetLength()-1); //To make it a sortedlist
	cout << "Sorted List: " << list1 << endl;
	cout << "Unsorted List: " << list2 << endl;
	List list3 = list1 + list2;
	cout << "Adding Sorted List and Unsorted List = " << list3 << endl;

	//1. Accessing items by their index
	cout << "Accessing index 1 of the List: " << list3.access(1) << endl;
	
	//2. Appending a single item 
	cout << "Appending a single item 3 to List: ";
	list3.append(3);
	cout << list3 << endl;

	//3. Appending a sequence of items
	cout << "Appending a sequence of items { 1, 2, 3} to List: ";
	int arr[3] = { 1, 2, 3 };
	list3.appendSeq(arr, 3);
	cout << list3 << endl;

	//4. Inserting a single item at a specific index 
	cout << "Inserting a single item 10 at a specific index 3: ";
	list3.insert(3, 10);
	cout << list3 << endl;

	//5. Inserting a sequence of items starting at a specific index

	//6. Removing the first or all occurrence(s) of an item
	int input;
	cout << "Removing the first or all occurrence(s) of an item: \n";
	cout << "Current List: "<< list3 << "\n Enter value to be removed: \n";
	cin >> input;
	list3.removeFirstorAll(input);
	cout << list3 << endl;

	//7. Removing an item at a specific index 
	int val, index;
	cout << "Removing an item at a specific index: \n";
	cout << "Current List: " << list3 << endl;
	cout << "Enter index: ";
	cin >> index;
	list3.removeAt(index);
	cout << list3 << endl;

	//8. Sorting the items 
	cout << "Sorting the items: " << endl;
	list3.quickSort(0, list3.GetLength());
	cout << list3 << endl;

	//9. Searching an item
	cout << "Searching for an item 1: " << endl; //note because this is a static test case must have 1 in list
	int x = list3.Search(1, 0 , list3.GetLength());
	cout << "Item is at index " << x << endl;

	//10. Inserting the list into an output stream
	cout << "Inserting the list into an output stream: " << endl;
	cout << list3 << endl;

	//11. Extracting a list from an input stream
	cout << "Extracting a list from an input stream: " << endl;
	List list4;
	cin >> list4;
	cout << list4 << endl;

	//"--": Removes the last item of the list
	cout << "--: Removes the last item of the list: " << endl;
	list3--;
	cout << list3 << endl;

	//"+": Appends a new item to the list.
	cout << "+: Appends a new item 2 to the list: " << endl;
	list3 + 2;
	cout << list3 << endl;

	//"+": Appends a list to the list. 
	cout << " + : Appends a list to the list: ";
	cout << list3 << " + " << list4 << " = " << endl;
	List list5 = list3 + list4;
	cout << list5 << endl;

	//"-": Removes all the items of a list from the list.
	cout << " - : Removes all the items of a list from the list: ";
	list3-2;
	cout << list3 << endl;

	//. "[]": Implements the index access operation.
	cout << " []: Implements the index access operation: " << endl;
	cout << "Accessing index 1 of the List: " << list3[1] << endl;

	//CONSTRUCTORS;
	//A constructor that creates an object including the elements of a C++ array
	cout << "A constructor that creates an object including the elements of a C++ array: " << endl;
	int arr1[2] = {0, 1};
	List list6(arr1, 2);

	//A constructor that creates an object including “n” occurrences of value “v”; where “n” is
	//a positive integer.An exception may be thrown by this method.

	cout << "A constructor that creates an object including “n” occurrences of value v: " << endl;
	List list7(3, 2);
	cout << "A list with 3 occurences of the value 2 "<< list7 << endl;

	//Getters and Setters
	//cout << "Length = " << list7.GetLength();
	//cout << "Set length to 3 " << endl;
	//list7.SetLength(3);
	


}