#include <iostream>
#include "List.hpp"

using namespace std;


int main() {
	///////////////////
	////PART 3
	///////////////////

	List li(5, 2);
	List li2(3, 1);

	List b = li + li2;

	cout << b;
	

	


	
	
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