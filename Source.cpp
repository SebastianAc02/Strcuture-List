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

	list1.quickSort(0, list1.GetLength()-1);
	cout << "SortedList: " << list1 << endl;
	cout << "UnsortedList: " << list2 << endl;
	List list3 = list1 + list2;
	cout << list3 << endl;

	

	


	
	
<<<<<<< HEAD
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




	



=======
>>>>>>> 1181ddc5a5e5f24df800c04fe25e4fd58a23eef3
}