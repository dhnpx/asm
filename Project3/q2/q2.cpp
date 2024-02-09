// HyungJoo Yoon
// Tatiana Klimova 
// Anthony Te

#include <iostream>

using namespace std;

int score = 0, sum = 0, numScores = 0, average = 0;

void enterScore() {
    cout << "Enter your score (-1 to stop): ";
    cin >> score;
}

int main() {
    _asm {
        jmp enterScoreLoop;         // Jump to the loop. The only way to get it to work properly.

    enterScoreLoop:
        call enterScore;            // Call enterScore to get a new score
        cmp score, -1;              // Compare score with -1
        je calculateAverage;        // If score = -1, exit the loop and go to calculateAverage

        mov eax, score;             // Move score into eax
        add sum, eax;               // Add eax = sum + score
        inc numScores;              // ++numScores
        jmp enterScoreLoop;         // Jump back to the beginning of the loop

    calculateAverage:
        cmp numScores, 0;           // Compare numScores to 0 (prevent division by 0)
        je calculationDone;         // If numScores is 0, goto average calculation
        mov eax, sum;               // eax=sum
        cdq;
        idiv numScores;             // Divide sum by numScores to get average
        mov average, eax;           // eax=average

    calculationDone:
    }

    if (numScores > 0) {
        cout << "The average score is: " << average << endl;
    }
    else {
        cout << "No scores were entered." << endl;
    }

    return 0;
}
