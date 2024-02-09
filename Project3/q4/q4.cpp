// HyungJoo Yoon
// Tatiana Klimova 
// Anthony Te

#include <iostream>

using namespace std;

int main() {
	short a, b, c, d, e, f;
	short det, det_x, det_y; //the determinants
	short x, y;

	cout << "This program solves the system" << endl;
	cout << "  aX + bY = c" << endl;
	cout << "  dX + eY = f" << endl;

	cout << "Enter the values of a, b, and c: ";
	cin >> a >> b >> c;
	cout << "Enter the values of d, e, and f: ";
	cin >> d >> e >> f;

	_asm {
		//1. calculate determinant (a*e - b*d), store in det
		mov ax, a;
		imul e;			// ax= a * e
		mov bx, ax;		// bx= a * e
		mov ax, b;
		imul d;			// ax= b * d
		sub bx, ax;		// bx = a*e - b*d
		mov det, bx;	// det = ^

		//2. calculate determinant for X (c*e - b*f), store in det_x
		mov ax, c;
		imul e;			// ax = c * e
		mov bx, ax;		// bx = ^
		mov ax, b;
		imul f;			// ax = b * f
		sub bx, ax;		// bx = c*e - b*f
		mov det_x, bx;	// det_x = ^

		//3. calculate determinant for Y (a*f - c*d), store in det_y

		mov ax, a;
		imul f;			// ax = a*f
		mov bx, ax;		// bx = ^
		mov ax, c;
		imul d;			// ax = c*d
		sub bx, ax;		// bx = a*f - c*d
		mov det_y, bx;	// det_y = ^

		//4. calculate x & y 
		// X = det_x/det

		mov ax, det_x;
		cwd;			// ax -> dx: ax for idiv
		idiv det;		// ax = det_x/det
		mov x, ax;		// result of ax in x

		// Y = det_y/ det

		mov ax, det_y;
		cwd;
		idiv det;
		mov y, ax;

	}

	cout << "  X = " << x << endl;
	cout << "  Y = " << y << endl;

	return 0;
}