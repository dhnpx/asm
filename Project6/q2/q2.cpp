// HyungJoo Yoon
// Tatiana Klimova
// Anothony Te

#include <iostream>
#include <iomanip>

using namespace std;

float a, b, c;
float discrim;
float four = 4;
float two = 2;
float x1, x2;
float negOne = -1;

void displayPrompt() {
	cout << "To see the two real roots of aX^2 + bX + c = 0, enter the a, b, and c values: ";
	cin >> a >> b >> c;
}

void displayRoots() {
	cout << fixed << showpoint << setprecision(2);
	cout << "\tX1 = " << x1 << "\tX2 = " << x2 << endl;
}

int main() {
	_asm {
		call displayPrompt;
		fld b;
		fld b;
		fmul;
		fld four;
		fld a;
		fmul;
		fld c;
		fmul;
		fsub;
		fsqrt;
		fstp discrim;
		fld b;
		fld negOne;
		fmul;
		fld discrim;
		fadd;
		fld two;
		fld a;
		fmul;
		fdiv;
		fstp x1;
		fld b;
		fld negOne;
		fmul;
		fld discrim;
		fsub;
		fld two;
		fld a;
		fmul;
		fdiv;
		fstp x2;
		call displayRoots;
	}
}