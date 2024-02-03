// HyungJoo Yoon
// Tatiana Klimova
// Anthony Te

#include <iostream>

using namespace std;

int main() {
    short drinks, sandwiches, totalBill;
    short drinkPrice = 2, sandwichPrice = 4;

    cout << "---------- MENU ----------" << endl;
    cout << "Drinks.......... $" << drinkPrice << endl;
    cout << "Sandwiches...... $" << sandwichPrice << endl;

    cout << "How many drinks? ";
    cin >> drinks;

    cout << "How many sandwiches? ";
    cin >> sandwiches;

    _asm {
        mov ax, drinks
        imul drinkPrice
        mov bx, ax

        mov ax, sandwiches
        imul sandwichPrice
        add ax, bx

        mov totalBill, ax
    }

    cout << "Your total bill $" << totalBill << endl;
    return 0;
}