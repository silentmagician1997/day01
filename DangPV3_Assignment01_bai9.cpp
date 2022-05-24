
#include<iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

class CFraction
{

public:
	friend CFraction operator+ (const CFraction&, const CFraction&);
	friend CFraction operator- (const CFraction&, const CFraction&);
	friend CFraction operator* (const CFraction&, const CFraction&);
	friend CFraction operator/ (const CFraction&, const CFraction&);

	void Fraction_input(CFraction& Fraction);
	void Fraction_output(CFraction& Fraction);
	int Fraction_reduce(CFraction& Fraction);
	int greatest_common_divisor(int a, int b);
private:
	int num;
	int den;


};


/*import data for the Fraction
*@ date: 20220524
*@ funtion   : Fraction_input
*@ param : CFraction& Fraction
*/
void CFraction::Fraction_input(CFraction& Fraction)
{
	cout << "input numerator: " << Fraction.num;
	cin >> Fraction.num;
	cout << "denominator: " << Fraction.den;
	cin >> Fraction.den;
	while (Fraction.den == 0)
	{
		cout << "invalid denominator";
		cin >> Fraction.den;
	}
}

/*export data after overloading
*@ date: 20220524
*@ funtion   : Fraction_ouput
*@ param : CFraction& Fraction
*/
void CFraction::Fraction_output(CFraction& Fraction)
{
	cout << "Fraction: " << Fraction.num << "/" << Fraction.den;
}

/*find greatest common divisor
*@ date: 20220524
*@ funtion   : greatest_common_divisor
*@ param : int a, int b
*/
int greatest_common_divisor(int a, int b)
{
	if (a == 0 && b == 0)
		return -1;
	else
		return (b == 0) ? a : greatest_common_divisor(b, a % b);
}

/*find greatest common divisor
*@ date: 20220524
*@ funtion   : greatest_common_divisor
*@ param : CFraction& Fraction
*/
int CFraction::Fraction_reduce(CFraction& Fraction)
{
	CFraction resFraction;
	int greatest_common_div = greatest_common_divisor(Fraction.num, Fraction.den);
	resFraction.num = resFraction.num / greatest_common_div;
	resFraction.den = resFraction.den / greatest_common_div;
	return resFraction;
}

/*Sum of two CFraction:
*@ date: 20220524
*@ funtion   : CFraction operator+ 
*@ param : const CFraction& Fraction1, const CFraction& Fraction2
*/
CFraction operator+ (const CFraction& Fraction1, const CFraction& Fraction2)
{	
	CFraction resFraction;
	resFraction.num = Fraction1.num * Fraction2.den + Fraction2.num * Fraction1.den;
	resFraction.den = Fraction1.den * Fraction2.den;
	resFraction.Fraction_reduce(resFraction);
	return resFraction;
}

/*Minus of two CFraction:
*@ date: 20220524
*@ funtion   : CFraction operator-
*@ param : const CFraction& Fraction1, const CFraction& Fraction2
*/
CFraction operator- (const CFraction& Fraction1, const CFraction& Fraction2)
{
	CFraction resFraction;
	resFraction.num = Fraction1.num * Fraction2.den - Fraction2.num * Fraction1.den;
	resFraction.den = Fraction1.den * Fraction2.den;
	resFraction.Fraction_reduce(resFraction);
	return resFraction;
}


/*Multiply of two CFraction:
*@ date: 20220524
*@ funtion   : CFraction operator-
*@ param : const CFraction& Fraction1, const CFraction& Fraction2
*/
CFraction operator* (const CFraction& Fraction1, const CFraction& Fraction2)
{
	CFraction resFraction;
	resFraction.num = Fraction1.num *Fraction2.num;
	resFraction.den = Fraction1.den * Fraction2.den;
	resFraction.Fraction_reduce(resFraction);
	return resFraction;
}

/*Minus of two CFraction:
*@ date: 20220524
*@ funtion   : CFraction operator-
*@ param : const CFraction& Fraction1, const CFraction& Fraction2
*/
CFraction operator/ (const CFraction& Fraction1, const CFraction& Fraction2)
{
	CFraction resFraction;
	resFraction.num = Fraction1.num * Fraction2.den;
	resFraction.den = Fraction1.den * Fraction2.num;
	resFraction.Fraction_reduce(resFraction);
	return resFraction;
}

int main()
{

	CFraction Fraction1, Fraction2, add, minus, multiply, divide;
	
		cout << "Enter the CFraction1:" << endl;
		Fraction1.Fraction_input(Fraction1);

		cout << "Enter the CFraction2:" << endl;
		Fraction2.Fraction_input(Fraction2);

		add = Fraction1 + Fraction2;
		cout << "Sum of two CFraction:" << endl;
		add.Fraction_output(add);

		minus = Fraction1 - Fraction2;
		cout << "Minus of two CFraction:" << endl;
		minus.Fraction_output(minus);

		multiply = Fraction1 * Fraction2;
		cout << "Multiply of two CFraction:" << endl;
		multiply.Fraction_output(multiply);

		divide = Fraction1 / Fraction2;
		cout << "Divide of two CFraction:" << endl;
		divide.Fraction_output(divide);
}



