#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <intrin.h>
#pragma intrinsic(__rdtsc)
unsigned __int64 rdtsc() {
	return __rdtsc();
}
using namespace std;

int main()
{
	unsigned __int64 t1, t2, t;
	double tf;
	double min_seconds1 = 9999999, min_seconds2 = 9999999;
	float b;
	ofstream fout("result.txt");
	fout << "Имя функции: Экспонента\n";
	fout << "Clock     RDTSC\n";
	for (int j = 0; j < 15; ++j) {
		t1 = rdtsc();
		clock_t start = clock();
		for (int i = 0; i < 400000; i++) {
			int n = 8;
			float x = 3.0;
			int a;
			float one = 1.0;
			_asm {
				mov ecx, n;
			sumloop:
				cmp ecx, 1;
				JLE edn;
				mov ebx, ecx;
				mov eax, ecx;
			fac:
				sub ecx, 1;
				mov edx, 0;
				mul ecx;
				cmp ecx, 1;
				jg fac;
				mov a, eax;
			}

			b = a;
			_asm {
				mov ecx, ebx;
				sub ecx, 1;
				FLD x;
			powloop:
				FMUL x;
				loop powloop;
				FLD b;
				FDIV;

				mov ecx, ebx;
				loop sumloop;
			edn:
				mov ecx, n;
				sub ecx, 1;
				FADD one;
			fin:
				FADD;
				sub ecx, 1;
				cmp ecx, 1;
				JG fin
					FSTP b;
			}
		}
		clock_t end = clock();
		t2 = rdtsc();
		t = (t2 - t1) / 2500000;
		tf = t;
		tf = tf / 1000;
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		fout << seconds << "     " << tf << "\n";
		if (seconds < min_seconds1) {
			min_seconds1 = seconds;
		}
		if (tf < min_seconds2) {
			min_seconds2 = tf;
		}
	}
	fout << "result = " << b << "\n";
	fout << "min time clock =" << min_seconds1 << "\n";
	fout << "min time rdtsc=" << min_seconds2;
	fout.close();
	cout << "done";
}

