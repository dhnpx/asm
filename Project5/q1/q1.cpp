// HyungJoo Yoon
// Tatiana Klimova
// Anthony Te

#include <iostream>
using namespace std;

//                    S   M   L   XL
int storage[16] = { 10, 20, 30, 40, // red
                   20, 10, 40, 30, // green
                   5, 15, 20, 25,  // blue
                   30, 25, 20, 15 };// black
int total, medium, blue, shirt_count, blue_count, medium_count;

int main() {
    _asm {
        lea esi, [storage];
    totalLoop:
        cmp shirt_count, 16;
        je blueLoopStart;
        mov eax, 0;
        add eax, [esi]
            add total, eax;
        inc shirt_count;
        add esi, 4;
        jmp totalLoop;
    blueLoopStart:
        sub esi, 32;
        jmp blueLoop;
    blueLoop:
        cmp blue_count, 4;
        je mediumStart;
        mov eax, 0;
        add eax, [esi]
            add blue, eax;
        add esi, 4;
        inc blue_count;
        jmp blueLoop;
    mediumStart:
        sub esi, 44;
        jmp mediumLoop;
    mediumLoop:
        cmp medium_count, 4;
        je done;
        mov eax, 0;
        add eax, [esi];
        add medium, eax;
        add esi, 16;
        inc medium_count;
        jmp mediumLoop;
    done:
    }
    cout << "Total shirts: " << total;
    cout << "\nTotal medium shirts: " << medium;
    cout << "\nTotal blue shirts: " << blue;
}