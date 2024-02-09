// HyungJoo Yoon
// Tatiana Klimova 
// Anthony Te

#include <iostream>

using namespace std;

int numDrinks;
char drink;
int numSandwiches;
int sandwichSize;
int numCustomers;
int total = 0;
int tenPrice = 3;
int twelvePrice = 5;
int sodaPrice = 2;
int waterPrice = 1;


void readMenu() {
	cout << "-----------------7-11 Convenient Store ------------------" << endl;
	cout << "Drinks" << endl;
	cout << "\tSoda(S).............................................$2" << endl;
	cout << "\tWater(W)............................................$1" << endl;
	cout << "Sandwiches" << endl;
	cout << "\t10 inches...........................................$3" << endl;
	cout << "\t12 inches...........................................$5" << endl;
	cout << endl;

	cout << "Enter the number of customers: ";
	cin >> numCustomers;

}

void takeOrder() {
	cout << endl << "\tHow many drinks? ";
	cin >> numDrinks;

	cout << "\t\tWhat kind of drink (S=Soda, W=Water)? ";
	cin >> drink;

	cout << "\t How many Sandwiches? ";
	cin >> numSandwiches;
	cout << "\t\tWhat size of sandwich (10/12 inches)? ";
	cin >> sandwichSize;
}

void displayTotal() {
	cout << "\t\t\tYour total bill = $" << total << endl;
}

int main() {
	_asm {
		call readMenu;
	L1:
		call takeOrder;
		mov eax, numDrinks;
		cmp drink, 'w';
		Je water;
		cmp drink, 'W';
		Je water;
		cmp drink, 's';
		Je soda;
		cmp drink, 'S';
	soda:
			imul sodaPrice;
	water:
			
		mov total, eax;
		mov eax, numSandwiches;
		mov ebx, sandwichSize;

		cmp ebx, 10
		Je ten
		cmp ebx, 12
		Je twelve
	ten:
		imul tenPrice;
		Jmp done;
	twelve:
		imul twelvePrice;
	done:
		add total, eax;
		call displayTotal;
		cmp numCustomers, 0;
		dec numCustomers;
		jnz L1;
	}
	return 0;
}