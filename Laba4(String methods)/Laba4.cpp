#include <stdio.h>
#include "conio.h"
#include <iostream>
#include<cstring>
using namespace std;
int main() {
	char source[32] = "nsjg soplea dsbfs ads";
	char dest[32] = "dfsasdfsf";
	char ch1, ch2;
	int slon;
	int len;
	len = strlen(source);
	_asm {
		lea esi, source;
		lea edi, source;
	ag:
		mov ecx, len;
		mov al, ' ';
		mov ebx, esi;
		repne scasb;
		dec edi;
	/*	mov al, [edi]; юзлес строчка, пробел и так в al*/
		mov ecx, edi;
		sub ecx, ebx;
		mov eax, len;
		sub eax, ecx;
		mov len, eax;
		mov eax, ecx;
		mov edx, 0;
		mul ecx;
		mov ecx, eax;
		mov edx, esi;
		/*mov slon, ecx;*/
	rp:
		mov edi, esi;
		inc edi; 
	pr:
		mov al, [esi];
		mov bl, [edi];
		cmp cx, 0;
		jle fin;
		rep cmps
		jle pr;
		jg sw;
	sw:
		/*mov al, [esi];
		mov bl, [edi];*/
		dec esi;
		dec edi;
		cmp[edi], ' '
		je fin;
		mov al, [esi];
		mov bl, [edi];
		mov [esi], bl;
		mov [edi], al;
		mov esi, edx;
		jmp rp;
	fin:
		inc edi;
		cmp [edi],' '
		je rfin
		cmp [edi], 0
		je rfin;
		mov esi, edi
		mov al, [edi];
		//mov ch1, al;
		jmp ag;
		
	}
	rfin:
	cout << "----------" << endl;
	cout << ch1 << " " << ch2 << " " << slon<< endl;
	for (char c : source) {
		cout << c;
	}
}