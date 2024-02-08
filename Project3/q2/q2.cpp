/*

Q2
*/


#include <iostream>

using namespace std;

int main() {
	int score = 0, sum = 0, count = 0, average = 0;



	while (true) {
		cout << "Enter your score (-1 to stop): ";
		cin >> score;

		if (score == -1) {
			break; //Will exit the loop if -1 is entered
		}



		_asm {
			mov eax, score; //input score into eax
			add sum, eax; // add score to sum

			inc count; //count++
		}

	}

	if (count > 0) {
		_asm {
			mov eax, sum; // get sum in eax
			cdq;		// convert to double word for division
			idiv count;  //divide by count, result remains in eax
			mov average, eax; // stores result in average eax
		}
		cout << "Your average is: " << average << endl;
	}
	else {
		cout << "No scores were entered." << endl;
	}

	return 0;
}

