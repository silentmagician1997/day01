#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int i, j , n = 5;

//Ve 5 hang dau tien
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n - i; j++) {
			cout << (" ");
		}
		for (j = 1; j <= 2*i -1; j++) {
			cout << ("*");
		}
		cout << endl;
	}
//Ve 5 hang tiep theo
	for (i = n-1 ; i >= 1; i--) {
		for (j = 1; j <= n-i ; j++) {
			cout << (" ");
		}
		for (j = 1; j <= 2 * i - 1; j++) {
			cout << ("*");
		}
		cout << endl;
	}
	return 1;
}
