#include <iostream>

using namespace std;

void Base2() {
	short x = 1 << 15, t;
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