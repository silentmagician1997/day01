#include <iostream>
using namespace std;


float Plus(float a, float b)
{
	return (a + b);
}

float Minus(float a, float b)
{
	return (a - b);
}

float Multiply(float a, float b)
{
	return (a * b);
}

float Divide(float a, float b)
{
	if (b == 0)
	{
		cout << "Division by zero!";
		return 0;
	}
	else
	{
		return (a / b);
	}
}

void operation(float a, float b, float (*p2Func)(float, float))
{
	cout << p2Func(a, b);
}

int main()
{
	float a, b;
	cout << "a= " << endl;
	cin >> a;
	cout << "b= " << endl;
	cin >> b;

	cout << "\na + b = ";
	operation(a, b, Plus);

	cout << "\na - b = ";
	operation(a, b, Minus);

	cout << "\na * b = ";
	operation(a, b, Multiply);

	cout << "\na / b = ";
	operation(a, b, Divide);

	return 0;
}

