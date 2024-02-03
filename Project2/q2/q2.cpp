// HyungJoo Yoon
// Tatiana Klimova
// Anthony Te

#include <iostream>

using namespace std;

int main() {
    int a;
    int b;
    int c;
    int h;

    int len;
    int width;

    int tArea;
    int tPerimeter;

    int rArea;
    int rPerimeter;

    int two = 2;

    cout << "Enter the values of a, b, c, and h for the traingle: ";
    cin >> a >> b >> c >> h;

    cout << "Enter the length and the width of the rectangle: ";
    cin >> len >> width;

    _asm {
        mov eax, c;
        imul h;
        idiv two;
        mov tArea, eax;

        mov eax, a;
        add eax, b;
        add eax, c;
        mov tPerimeter, eax;

        mov eax, len;
        imul width;
        mov rArea, eax;

        mov eax, len;
        add eax, width;
        imul two;
        mov rPerimeter, eax;
    }

    cout << "\tTriangle" << endl;
    cout << "\t\tArea................." << tArea << endl;
    cout << "\t\tPerimeter............" << tPerimeter << endl;
    cout << "\tRectangle" << endl;
    cout << "\t\tArea................." << rArea << endl;
    cout << "\t\tPerimeter............" << rPerimeter << endl;

    return 0;
}