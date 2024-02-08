#include <iostream>

using namespace std;

int main() {
	int numDrinks;
	char drink;
	int sandwiches;
	int sandwichSize;
	int customers;
	int total = 0;
	int three = 3;
	int five = 5;
	int two = 2;
	

	cout << "-----------------7-11 Convenient Store ------------------" << endl;
	cout << "Drinks" << endl;
	cout << "\tSoda(S).............................................$2" << endl;
	cout << "\tWater(W)............................................$1" << endl;
	cout << "Sandwiches" << endl;
	cout << "\t10 inches...........................................$3" << endl;
	cout << "\t12 inches...........................................$5" << endl;
	cout << endl;

	cout << "Enter the number of customers: ";
	cin >> customers;

	cout << "\tHow many drinks? ";
	cin >> numDrinks;

	cout << "\t\tWhat kind of drink (S=Soda, W=Water)?" << endl;
	cin >> drink;

	cout << "\t How many Sandwiches? ";
	cin >> sandwiches;
	cout << "\t\tWhat size of sandwich (10/12 inches)? ";
	cin >> sandwichSize;

	_asm {
		mov eax, numDrinks;
		cmp drink, 'w';
		Je water;
		cmp drink, 'W';
		Je water;
		cmp drink, 's';
		Je soda;
		cmp drink, 'S';
	soda:
			imul two;
	water:
			
		mov total, eax;
		mov eax, sandwiches;
		mov ebx, sandwichSize;

		cmp ebx, 10
		Je ten
		cmp ebx, 12
		Je twelve
	ten:
		imul three;
		Jmp done;
	twelve:
		imul five;
	done:

		add total, eax;
	}
	cout << "\t\t\tYour total bill = $" << total << endl;
}