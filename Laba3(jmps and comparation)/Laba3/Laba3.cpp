#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a, x;
    char a1;
    cout << " Enter 'a' \n";
    cin >> a;
    cout << "Enter 'x' \n";
    cin >> x;
    _asm {
        mov ebx, a;
        mov eax, x;
        mov edx, 2;
        cmp al, 2;
        jg L1;
        mul edx;
        add eax, 1;
        mov ecx, eax;
        mov eax, x;
        jmp L2;
        L1:
        mul edx;
        add eax, ebx;
        mov ecx, eax;
        mov eax, x;
        L2:
        cmp al, 0;
        jg L3;
        sub ebx, 1;
        mov edx, ebx;
        jmp L4;
        L3:
        add eax, 1;
        mov edx, eax;
        L4:
        sub ecx, edx;
        mov x, ecx;
    }
    printf("%d", x);
}


