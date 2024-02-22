// HyungJoo Yoon
// Tatiana Klimova 
// Anthony Te

#include<iostream>
using namespace std;

short digit_total, is_even, digit_count = 1, two = 2;

void validPin() {
    if (digit_count == 1) cout << "BEEF";
    if (digit_count == 2) cout << "FABE";
    if (digit_count == 3) cout << "CABE";
    if (is_even == 0) {
        cout << "  is a valid ID for the family\n";
    }
    else {
        cout << "  is not a valid ID for the family\n";
    }
}
int main() {
    _asm {
        // for BEEF
        mov ax, 0xBEEF;
        and ax, 0000000000001111b;
        add digit_total, ax;
        mov ax, 0xBEEF;
        and ax, 0000000011110000b;
        shr ax, 4;
        add digit_total, ax;
        mov ax, 0xBEEF;
        and ax, 0000111100000000b;
        shr ax, 8;
        add digit_total, ax;
        mov ax, 0xBEEF;
        and ax, 1111000000000000b;
        shr ax, 12;
        add digit_total, ax;
        mov ax, digit_total;
        cwd;
        idiv two;
        mov is_even, dx;
        call validPin;
        inc digit_count;
        // for FABE
        mov ax, 0xFABE;
        and ax, 0000000000001111b;
        add digit_total, ax;
        mov ax, 0xFABE;
        and ax, 0000000011110000b;
        shr ax, 4;
        add digit_total, ax;
        mov ax, 0xFABE;
        and ax, 0000111100000000b;
        shr ax, 8;
        add digit_total, ax;
        mov ax, 0xFABE;
        and ax, 1111000000000000b;
        shr ax, 12;
        add digit_total, ax;
        mov ax, digit_total;
        cwd;
        idiv two;
        mov is_even, dx;
        call validPin;
        inc digit_count;
        // for CABE
        mov ax, 0xCABE;
        and ax, 0000000000001111b;
        add digit_total, ax;
        mov ax, 0xCABE;
        and ax, 0000000011110000b;
        shr ax, 4;
        add digit_total, ax;
        mov ax, 0xCABE;
        and ax, 0000111100000000b;
        shr ax, 8;
        add digit_total, ax;
        mov ax, 0xCABE;
        and ax, 1111000000000000b;
        shr ax, 12;
        add digit_total, ax;
        mov ax, digit_total;
        cwd;
        idiv two;
        mov is_even, dx;
        call validPin;
    }
}