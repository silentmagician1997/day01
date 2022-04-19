#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdio>

using namespace std;

//kiem tra day ki tu nhap vao co phai la so nguyen khong

bool CheckNumber(char s[], int n) {
	if (s[0] == '0')
		return false;
	if (n == 0)
		return false;
	for (int i = 0; i < n; i++) {
		if (s[i] < '0' || s[i] > '9')
			return false;
		}
		return true;
	}

//kiem tra so vao co phai la doi xung ko	
bool CheckPalindrome(char s[], int n) {
	int i = 0, j = n - 1;
	while (i < j) {
		if (s[i] != s[j]) {
			return false;
		}
		else {
			i++;
			j--;
		}
	}
	return true;
}

int main() {
	char s[100];
	cout << "Nhap vao so can kiem tra:";
	fgets(s, 100, stdin);
	int n = strlen(s) -1 ;
	
	

	while (CheckNumber(s, n) == false) {
		cout << "day khong phai so tu nhien" << endl;
		cout << "Nhap lai so can kiem tra:";
		fgets(s, 100, stdin);
		n = strlen(s) - 1;
		}
	

	if (CheckPalindrome(s, n) == false) {
			cout << "day ko la so doi xung" << endl;
		}
		else {
			cout << "day la so doi xung" << endl;
		}
		return 0;
	}


