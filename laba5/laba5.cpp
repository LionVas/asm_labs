#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <intrin.h>
#pragma intrinsic(__rdtsc)
unsigned __int64 rdtsc(){
	return __rdtsc();
}
using namespace std;
unsigned long long factorial(unsigned long long n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}	
}
inline long double summa(double x, int n) {
	long double summ = 1;
	for (int i = 1; i <= n; ++i) {
		summ += pow(x, i) / (factorial(i));
	}
	return summ;
}

int main()
{
	unsigned __int64 t1, t2, t;
	double tf;
	double min_seconds1 = 9999999, min_seconds2 = 9999999;
	long double n;
	ofstream fout("result.txt");
	fout << "Имя функции: Экспонента\n";
	fout << "Clock     RDTSC\n";
	for (int j = 0; j < 15; ++j) {
		t1 = rdtsc();
		clock_t start = clock();
		for (int i = 0; i < 400000; i++) {
			n = summa(3.0, 8);
		}
		clock_t end = clock();
		t2 = rdtsc();
		t = (t2 - t1)/2500000;
		tf = t;
		tf = tf / 1000;		
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		fout << seconds <<"     "<< tf << "\n";
		if (seconds < min_seconds1) {
			min_seconds1 = seconds;
		}
		if (tf < min_seconds2) {
			min_seconds2 = tf;
		}
	}
	fout<< "result = " << n << "\n";
	fout << "min time clock =" << min_seconds1 << "\n";
	fout << "min time rdtsc=" << min_seconds2;
	fout.close();
	cout << "done";
}


