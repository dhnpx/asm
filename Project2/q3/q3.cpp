// HyungJoo Yoon
// Tatiana Klimova
// Anthony Te

#include <iostream> 

using namespace std;

int main() {
    short C, F;
    short five = 5;
    short nine = 9;

    cout << "Enter temperature in Fahrenheit: ";
    cin >> F;

    _asm {
        mov ax, F;
        sub ax, 32;
        imul five;
        idiv nine;
        mov C, ax;
    }

    cout << F << "F is " << C << " C" << endl;
    return 0;
}