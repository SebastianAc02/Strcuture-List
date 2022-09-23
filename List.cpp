
#include "List.hpp"
#include <iostream>
<<<<<<< HEAD
=======
#include <string>
>>>>>>> b1895517ba09b77b12337cbc1d7c5ca4867f8f7d
using namespace std;

List::List() : length(0), list(nullptr) {}

<<<<<<< HEAD
List::List(int* arr, int arrSize) : length(arrSize), list(nullptr) {
=======
List::List(int* arr, int arrSize) : length(arrSize), list(new int[arrSize]) {
>>>>>>> b1895517ba09b77b12337cbc1d7c5ca4867f8f7d

	for (int i = 0; i < length; i++)
	{
		list[i] = arr[i];
	}

}
List::List(int n, int v) :length(n), list(new int[n]) {
	if (n < 0) {
		throw "ERROR: the number has to be a positive integer";
	}
	for (int i = 0; i < n; i++)
	{
		list[i] = v;
	}


}
List::~List() {
	delete[] list;
	list = nullptr;
}


<<<<<<< HEAD

=======
int List::GetLength() const{
	return length;
}
>>>>>>> b1895517ba09b77b12337cbc1d7c5ca4867f8f7d
void List::insert(int index, const int val) {

}
void List::removeAt(int index, int val) {
	list[index] = list[length];
	length--;
}
void List::append(int val) {
<<<<<<< HEAD
	////Ex. original size of 10
	//int* tempList = new int[length + 1]; //Ex. size of 11 is 0-10th elements
	//for (int i = 0; i < length; i++)
	//{
	//	tempList[i] = list[i]; //deep copy
	//	//tempList now has values of original list but also one extra index for another
	//	//value to be inserted
	//}
	////Change original list to the tempList
	//delete[] list;
	//list = nullptr;

	//list = tempList;   //list points to tempList

	//list[length] = val; // (last element of resized array) add value

	//length++;  //increase number of elements
=======
	//Ex. original size of 10
	int* tempList = new int[length + 1]; //Ex. size of 11 is 0-10th elements
	for (int i = 0; i < length; i++)
	{
		tempList[i] = list[i]; //deep copy
		//tempList now has values of original list but also one extra index for another
		//value to be inserted
	}
	//Change original list to the tempList
	delete[] list;
	list = nullptr;

	list = tempList;   //list points to tempList

	list[length] = val; // (last element of resized array) add value

	length++;  //increase number of elements
>>>>>>> b1895517ba09b77b12337cbc1d7c5ca4867f8f7d
}
void List::appendSeq(int* arr, int arrSize) {
	/*for (int i = 0; i < arrSize; i++)
	{
		append(arr[i]);
	}*/

	int newSize = arrSize + length;
	int* tempList = new int[newSize];

	for (int i = 0; i < length; i++)
	{
		tempList[i] = list[i]; //deep copy
	}
	for (int i = length; i < arrSize + length; i++)
	{
		tempList[i] = arr[i];
	}

	delete[] list;
	list = nullptr;

	list = tempList;

	length = arrSize + length;

}
const int& List :: operator[](int index) const {
	return list[index];
}

ostream& operator <<(ostream& os, const List& x) {
<<<<<<< HEAD
	for (int i = 0; i < x.length; i++)
	{
		os << x[i];
	}

=======
	os << "{";
	for (int i = 0; i < x.length; i++)
	{
		if(i != x.length-1) //values except for the last value will have a "," after it
			os << x[i] << ", ";
		else {
			os << x[i];
		}
	}
	os << "}";
>>>>>>> b1895517ba09b77b12337cbc1d7c5ca4867f8f7d
	return os;

}

<<<<<<< HEAD
const istream& operator >> (istream& in, const int& x) {

	in >> x;
=======
const istream& operator >> (istream& in, List& x) {
	cout << "Enter length of list: \n";
	in >> x.length;
	x.list = new int[x.length];
	
	/*for (int i = 0; i < x.length; i++)
	{
		cout << "enter value " << i << " for list: ";
		in >> x.list[i];
	}
	*/
	
	////Other way to extract ex. {0, 1, 2} 
	int val;
	for (int i = 0; i < x.length; i++)
	{
		in >> val;
		if (val == ' ') 
			continue;
		else
			x.list[i] = val;
	}
	
	

	//string input;
	//in.ignore();
	//getline(in, input);
	//int count = 0;
	//for (char& c : input) {
	//	///////////////CAN'T READ if more than one digit cant read 54
	//	if (count < x.length) {
	//		if (c == '{' || c == '}' || c == ',' || c == ' ' || c == '\0') {
	//			continue;
	//		}
	//		else {
	//			
	//			x.list[count] = c - '0';
	//			count++;
	//		}
	//	}

	//}




>>>>>>> b1895517ba09b77b12337cbc1d7c5ca4867f8f7d
	return in;

}






