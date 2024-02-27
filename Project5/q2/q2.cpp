// HyungJoo Yoon
// Tatiana Klimova
// Anthony Te

#include <iostream>

using namespace std;

int i = 0;
int j = 0;

int a[5] = { 9, 3, 22, 8, 1 };

void displayArr() {
	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
}

void displayIO() {
	cout << "Sample I/O";
	cout << "\n\tOriginal array a: ";
	displayArr();
	cout << "\n\tSorted array a: ";
}



int main() {

	_asm {
		call displayIO;
		mov eax, 0;
		mov ebx, 0;
		mov ecx, 5;
	loop1:
		lea esi, [a];
		mov i, 0;
		dec ecx;
		cmp ecx, 1;
		Jl done;
	loop2:
		cmp i, ecx;
		Jge loop1;
		mov eax, [esi];
		mov ebx, [esi + 4];
		cmp eax, ebx;
		Jg swapped;
		inc i;
		add esi, 4;
		Jmp loop2;
	swapped:
		xchg [esi], ebx
		xchg [esi +4], eax;
		inc i;
		add esi, 4;
		Jmp loop2;
	done:
		call displayArr;
	}
	return 0;
}