// HyungJoo Yoon
// Tatiana Klimova 
// Anthony Te

#include <iostream>

using namespace std;

char c;
int numLower = 0;
int numUpper = 0;

void askSentence() {
	cout << "Enter a sentence: ";
}

void getChar() {
	c = cin.get();
}
int main() {
	_asm {
		call askSentence;
	whileLoop:
		call getChar;
		cmp c, '\n';
		Je endLoop;
		cmp c, ' ';
		Je whileLoop;
		cmp c, 'a';
		Jge testLower;
		cmp c, 'A';
		Jl whileLoop;
	testUpper:
		cmp c, 'Z';
		Jg whileLoop;
	Upper:
		inc numUpper;
		Jmp whileLoop;
	testLower:
		cmp c, 'z';
		Jle lower;
	lower:
		inc numLower;
		Jmp whileLoop;
	endLoop:
	}
	cout << "\tNo. of uppercase letters = " << numUpper << endl;
	cout << "\tNo. of lowercase letters = " << numLower << endl;

	return 0;
}
