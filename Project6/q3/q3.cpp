// HyungJoo Yoon
// Tatiana Klimova
// Anothony Te

#include <iostream>
#include <iomanip> 
using namespace std;

float sodaPrice{ 2.25 }, waterPrice{ 1.75 };
float smallSandwichPrice{ 3.45 }, largeSandwichPrice{ 5.25 };
float totalBill{ 0.0 };

int numDrinks, numSandwiches;

char drinkType;
int sandwichSize;

float drinkPrice{ 0.0 }, sandwichPrice{ 0.0 };


const int nameWidth{ 50 };
const int priceWidth{ 6 };

void printMenu() {
    cout << "--------------- 7 - 11 Convenient Store ---------------" << endl;

    cout << "\nDrinks\n";
    cout << left << setw(nameWidth) << setfill('.') << "Soda (S)" << right << setw(priceWidth) << "$2.25\n";
    cout << left << setw(nameWidth) << setfill('.') << "Water (W)" << right << setw(priceWidth) << "$1.75\n";

    cout << "\nSandwiches\n";
    cout << left << setw(nameWidth) << setfill('.') << "10 inches (10)" << right << setw(priceWidth) << "$3.45\n";
    cout << left << setw(nameWidth) << setfill('.') << "12 inches (12)" << right << setw(priceWidth) << "$5.25\n";
}

void takeOrder() {
    cout << endl;
    cout << "How many drinks? ";
    cin >> numDrinks;
    cout << "What kind of drink (S=Soda, W=Water)? ";
    cin >> drinkType;

    cout << "How many Sandwiches? ";
    cin >> numSandwiches;
    cout << "What size of sandwich (10/12 inches)? ";
    cin >> sandwichSize;
}

int main() {

    printMenu();
    takeOrder();


    _asm {
        mov eax, numDrinks;
        cmp drinkType, 'S';
        je label_soda;
        cmp drinkType, 's';
        je label_soda;
        // Default to water if not soda
        jmp label_water;

    label_soda:
        fld sodaPrice;
        fimul numDrinks;
        fstp drinkPrice;
        jmp calc_sandwich;

    label_water:
        fld waterPrice;
        fimul numDrinks;
        fstp drinkPrice;

    calc_sandwich:
        mov eax, numSandwiches;
        cmp sandwichSize, 10;
        je label_ten_inches;
        cmp sandwichSize, 12;
        je label_twelve_inches;
        fstp sandwichPrice;
        jmp calc_total;

    label_ten_inches:
        fld smallSandwichPrice;
        fimul numSandwiches;
        fstp sandwichPrice;
        jmp calc_total;

    label_twelve_inches:
        fld largeSandwichPrice;
        fimul numSandwiches;
        fstp sandwichPrice;

    calc_total:
        fld drinkPrice; // Load drinkPrice
        fadd sandwichPrice; // Add sandwichPrice to it
        fstp totalBill; // Store the result in totalBill
    }

    /*cout << "Your total drink amount = $" << fixed << setprecision(2) << drinkPrice << endl;
    cout << "Your total sandwich amount = $" << fixed << setprecision(2) << sandwichPrice << endl;*/
    cout << "Your total bill = $" << fixed << setprecision(2) << totalBill << endl;

    return 0;
}