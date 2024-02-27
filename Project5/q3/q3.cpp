// HyungJoo Yoon
// Tatiana Klimova
// Anthony Te

#include <iostream>
using namespace std;

int a[3][3][2] = {
		{
			{1, 2}, // Red, Small, [Short Sleeve, Long Sleeve]
			{3, 4}, // Red, Medium, [Short Sleeve, Long Sleeve]
			{5, 6}  // Red, Large, [Short Sleeve, Long Sleeve]
		},
		{
			{7, 8},  // Blue, Small, [Short Sleeve, Long Sleeve]
			{9, 10}, // Blue, Medium, [Short Sleeve, Long Sleeve]
			{11, 12} // Blue, Large, [Short Sleeve, Long Sleeve]
		},
		{
			{13, 14}, // Black, Small, [Short Sleeve, Long Sleeve]
			{15, 16}, // Black, Medium, [Short Sleeve, Long Sleeve]
			{17, 18}  // Black, Large, [Short Sleeve, Long Sleeve]
		}
};
int i, totalShirts, totalMedium, totalShortSleeve, totalRedShirt;

void printTotal() {
	cout << "Q3.A) " << totalShirts << " a total number of all shirts." << endl;
}

void printMedium() {
	cout << "Q3.B) " << totalMedium << " a total of all medium size shirts. " << endl;
}

void printShortSleeve() {
	cout << "Q3.C) " << totalShortSleeve << " a total of all short sleeves shirts. " << endl;
}

void printRedShirt() {
	cout << "Q3.D) " << totalRedShirt << " a total of all RED shirts. " << endl;
}



int main() {

	_asm {
		mov eax, 0;
		mov i, 0;
		lea esi, [a];

	total_loop:
		cmp i, 18;
		jge total_done;

		add eax, [esi];
		add esi, 4;

		inc i;

		jmp total_loop;

	total_done:
		mov totalShirts, eax;
		call printTotal;

	mediums:
		mov ebx, 0
			mov i, 0
			lea esi, [a + 8]

			mediums_loop :
			cmp i, 4
			jge mediums_done


			add ebx, [esi] //short sleeve
			add esi, 4
			add ebx, [esi] //long sleeve
			add esi, 20

			inc i

			jmp mediums_loop

			mediums_done :
		mov totalMedium, ebx
			call printMedium

			shortSleeves :
		mov ecx, 0
			mov i, 0
			lea esi, [a]

			shortSleeves_loop :
			cmp i, 9
			jge shortSleeves_done

			add ecx, [esi]
			add esi, 8
			inc i
			jmp shortSleeves_loop

			shortSleeves_done :
		mov totalShortSleeve, ecx
			call printShortSleeve

			redShirts :
		mov edx, 0
			mov i, 0
			lea esi, [a]

			redShirts_loop :
			cmp i, 6
			jge redShirts_end

			add edx, [esi]
			add esi, 24
			inc i
			jmp redShirts_loop


			redShirts_end :
		mov totalRedShirt, edx
			call printRedShirt


	}



	return 0;
}


