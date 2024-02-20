#include <iostream>

using namespace std;

short numPrinters;
short numFloppy;
short sizeRam;

void displayPrinters() {
	cout << "Printer(s) connected: " << numPrinters << endl;
}

void displayFloppy() {
	cout << "Floppy Drive(s): " << numFloppy << endl;
}

void displayRAM() {
	cout << "RAM: " << sizeRam << "GB" << endl;
}

void Base2() {
	short x = 1 << 15;
	short t;
	short n = 0b1100111010011100;
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

void displaySignal() {
	cout << "The interrupt signal is ";
	Base2();
	cout << endl;
}

int main() {
	_asm {
		call displaySignal;
		//Printer
		mov ax, 1100111010011100b;
		mov bx, 1100000000000000b;
		and ax, bx;
		shr ax, 14;
		mov numPrinters, ax;
		call displayPrinters;

		//Floppy
		mov ax, 1100111010011100b;
		mov bx, 0000000000000011b;
		shr ax, 6;
		and ax, bx;
		mov numFloppy, ax;
		add numFloppy, 1;
		call displayFloppy;

		//RAM
		mov ax, 1100111010011100b;
		mov bx, 0000000000000011b;
		shr ax, 2;
		and ax, bx;
		inc ax;
		imul ax, 16;
		mov sizeRam, ax;
		call displayRAM;
	}
}