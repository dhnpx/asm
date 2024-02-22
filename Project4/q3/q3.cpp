// HyungJoo Yoon
// Tatiana Klimova 
// Anthony Te

#include <iostream>
using namespace std;

short a;
short num;
short sprinklerDef;

void Base2()
{
    short x = 1 << 15, t;
    short n = a;
    for (int i = 1; i <= 16; ++i)
    {
        t = n & x;
        if (t == 0)
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }
        if (i % 4 == 0)
        {
            cout << " ";
        }
        n = n << 1;
    }
    a = n; //save the original value of a
    cout << endl;
}

void printCount() {

    cout << num << " sprinklers are ON" << endl;
}

void printPrefix() {
    cout << "Defective Sprinklers: ";
}

void sprinklerOff() {

    cout << sprinklerDef << " ";

}

int main() {

    short tempAA, tempBB;
    short tempA, tempB, tempC;

    _asm {
        mov ax, 0x6A2F
        mov a, ax
        call Base2

        /*mov ax, 0110101000101111b
        mov bx, 0000000000000001b*/
        mov ax, 0x6A2F
        mov bx, 0x0001
        mov cx, 16
        mov dx, 0

        mov tempA, ax
        mov tempB, bx
        mov tempC, cx

        loop_start :
        cmp cx, 0
            je end_loop

            mov tempAA, ax
            and tempAA, bx
            jz bit_is_off

            inc dx

            bit_is_off :
        shl bx, 1
            dec cx
            jmp loop_start

            end_loop :
        mov num, dx
            call printCount

            call printPrefix

            mov ax, tempA
            mov bx, tempB
            mov cx, tempC

            mov bx, 1000000000000000b
            mov cx, 16

            for_loop_cond:
        cmp cx, 0
            je end_for_loop

            mov tempBB, ax
            and tempBB, bx
            jz print_zero
            jmp for_loop_update

            print_zero :
        mov sprinklerDef, cx
            mov tempA, ax
            mov tempB, bx
            mov tempC, cx
            call sprinklerOff

            mov ax, tempA
            mov bx, tempB
            mov cx, tempC

            for_loop_update :
        shr bx, 1
            dec cx
            jmp for_loop_cond

            end_for_loop :



    }




    return 0;
}

