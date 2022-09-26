#include <iostream>
#include "List.hpp"

using namespace std;


int main() {
	 
	int arr[5] = { 1, 54, 55, 54, 55 };

	List li;
	int input;
	
	li.appendSeq(arr, 5);
	cout << "List: "<< li << endl;
	
	
	int location = li.Search(55,0 ,0);
	cout << "It is in position " << location << " of the List" << endl;

	li.Sort();
	cout << "Sorted List: " << li << endl;

	cout << "Enter value to remove \n";
	cin >> input;
	li.removeFirstorAll(input);
	cout << li<< endl;

	cout << "Enter value to remove \n";
	cin >> input;
	li.removeFirstorAll(input);
	cout << li << endl;




	



}