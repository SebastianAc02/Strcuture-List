#include <iostream>
#include "List.hpp"

using namespace std;


int main() {
	 
	int arr[5] = { 1, 4, 5, 6, 5 };

	List li;
	//cin >> li;
	li.appendSeq(arr, 5);
	li--;
	
	li + 3;
	cout << li.GetLength();
	cout << li;




}