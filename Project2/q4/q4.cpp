// HyungJoo Yoon
// Tatiana Klimova
// Anthony Te

#include <iostream>
using namespace std;

int main() {
    //Q4
    int digits, hund = 100, ten = 10, sum = 0;
    cout << "Enter a three digit int number: ";
    cin >> digits;
    _asm {
        mov eax, digits;
        cdq;
        idiv hund;
        mov sum, eax;
        mov eax, edx;
        cdq;
        idiv ten;
        add sum, eax;
        mov eax, edx;
        add sum, eax;
    }
    cout << "The total of digits in " << digits << " is " << sum;
}