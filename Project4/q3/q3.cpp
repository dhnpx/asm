#include <iostream>

int main() {

	for (int i = 0; i < 16; i++) {
		int ax = 0b0110101000101111;
		int bx = 0b1000000000000000;
		bx = bx >> i;
		int cx = ax & bx;
		if (cx == 0) {
			std::cout << 16 - i << " ";
		}
	}

}