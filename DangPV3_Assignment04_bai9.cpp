
#include<iostream>
using namespace std;

class CFraction
{

public:
	CFraction() {};
	~CFraction() {};
	friend CFraction operator+ (const CFraction&, const CFraction&);
	friend CFraction operator- (const CFraction&, const CFraction&);
	friend CFraction operator* (const CFraction&, const CFraction&);
	friend CFraction operator/ (const CFraction&, const CFraction&);

	void Fraction_input(CFraction& Fraction);
	void Fraction_output(CFraction& Fraction);
	void Fraction_reduce(CFraction& Fraction);
	
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
	cout << "input numerator: " ;
	cin >> Fraction.num;
	cout << "denominator: " ;
	cin >> Fraction.den;
	while (Fraction.den == 0)
	{
		cout << "invalid denominator" << "input denominator:  ";
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
	if (Fraction.den == 1)
	{
		cout << Fraction.num << endl;
	}
	else
	{
		cout << Fraction.num << "/" << Fraction.den << endl;
	}
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

/*reduce Fraction
*@ date: 20220524
*@ funtion   : Fraction_reduce
*@ param : CFraction& Fraction
*/
void CFraction::Fraction_reduce(CFraction& Fraction)
{

	int greatest_common_div = greatest_common_divisor(Fraction.num, Fraction.den);
	Fraction.num = Fraction.num / greatest_common_div;
	Fraction.den = Fraction.den / greatest_common_div;
}

/*Sum of two CFraction:
*@ date: 20220524
*@ funtion   : CFraction operator+ 
*@ param : const CFraction& Fraction1, const CFraction& Fraction2
*@ return :resFraction
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
*@ return :resFraction
*/
CFraction operator- (const CFraction& Fraction1, const CFraction& Fraction2)
{
	CFraction resFraction;
	resFraction.num = Fraction1.num * Fraction2.den - Fraction2.num * Fraction1.den;
	resFraction.den = Fraction1.den * Fraction2.den;
	resFraction.Fraction_reduce(resFraction);
	resFraction.Fraction_reduce(resFraction);
	return resFraction;
}


/*Multiply of two CFraction:
*@ date: 20220524
*@ funtion   : CFraction operator-
*@ param : const CFraction& Fraction1, const CFraction& Fraction2
*@ return :resFraction
*/
CFraction operator* (const CFraction& Fraction1, const CFraction& Fraction2)
{
	CFraction resFraction;
	resFraction.num = Fraction1.num *Fraction2.num;
	resFraction.den = Fraction1.den * Fraction2.den;
	resFraction.Fraction_reduce(resFraction);
	return resFraction;
}

/*Divide of two CFraction:
*@ date: 20220524
*@ funtion   : CFraction operator-
*@ param : const CFraction& Fraction1, const CFraction& Fraction2
*@ return :resFraction
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

	CFraction Fraction1, Fraction2, Sum, Minus, Multiply, Divide;
	
		cout << "CFraction1:" << endl;
		Fraction1.Fraction_input(Fraction1);

		cout << "CFraction2:" << endl;
		Fraction2.Fraction_input(Fraction2);

		Sum = Fraction1 + Fraction2;
		cout << "Sum:" << endl;
		Sum.Fraction_output(Sum);

		Minus = Fraction1 - Fraction2;
		cout << "Minus:" << endl;
		Minus.Fraction_output(Minus);

		Multiply = Fraction1 * Fraction2;
		cout << "Multiply:" << endl;
		Multiply.Fraction_output(Multiply);

		Divide = Fraction1 / Fraction2;
		cout << "Divide:" << endl;
		Divide.Fraction_output(Divide);

}



