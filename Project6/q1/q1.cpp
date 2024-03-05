// HyungJoo Yoon
// Tatiana Klimova
// Anothony Te

#include <iostream>
#include <iomanip>
using namespace std;
float a, b, c, h, len, width, two = 2, tArea, tPer, rArea, rPer;

void askTri() {
    cout << "Enter the values of a, b, c, and h for the triangle: ";
}
void getTriData() {
    cin >> a >> b >> c >> h;
}
void askRec() {
    cout << "Enter the length and the width of the rectangle: ";
}
void getRecData() {
    cin >> len >> width;
}
int main() {
    _asm {
        call askTri;
        call getTriData;
        call askRec;
        call getRecData;
        // Triangle area ch/two twohc/
        fld c;
        fld h;
        fmul;
        fld two;
        fdiv;
        fstp tArea;
        // Triangle perimeter a + b + c
        fld a;
        fld b;
        fld c;
        fadd;
        fadd;
        fstp tPer;
        // Rectangle area length width
        fld len;
        fld width;
        fmul;
        fstp rArea;
        // Rectangle perimeter (length + width) * two or twolengthwidth+*
        fld two;
        fld len;
        fld width;
        fadd;
        fmul;
        fstp rPer;
    }
    cout << fixed << showpoint << setprecision(2);
    cout << "Triangle\nArea.........................................." << tArea;
    cout << "\nPerimeter................................" << tPer;
    cout << "\nRectangle\nArea........................................" << rArea;
    cout << "\nPerimeter ..............................." << rPer;
}