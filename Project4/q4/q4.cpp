#include <iostream>

using namespace std;

unsigned char floorNum = 16;

void Base2() {
	short x = 1 << 15;
	short t;
	short n = 0b1001000100001100;
	for (int i = 1; i <= 16; ++i) {
		t = n & x;
		if (t == 0) {
			cout << 0;
		}
		else {
			cout << 1;
		}
		if (i % 4 == 0) {
			cout << " ";
		}
		n = n << 1;
	}
}

void displayAX() {
	cout << "AX = ";
	Base2();
	cout << endl;
	cout << "Elevator will stop at floors no. ";
}

void displayFloor() {
	cout << (int)floorNum << " ";
}

int main() {
	_asm {
		call displayAX;
	whileLoop:
		mov cl, floorNum;
		dec cl;
		cmp cl, 0;
		Je exitLoop;
		mov ax, 1001000100001100b;
		mov bx, 0000000000000001b;
		shr ax, cl;
		and ax, bx;
		cmp ax, 0;
		Jne one;
		dec floorNum;
		Jmp whileLoop;
	one:
		call displayFloor;
		dec floorNum;
		Jmp whileLoop;
	exitLoop:
	}
}