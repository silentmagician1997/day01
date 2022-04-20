#include <iostream>

using namespace std;

bool isLeapYear(int year);
int DayInMonth(int month, int year);
void NextDay(int day, int month, int year);
void PreviousDay(int day, int month, int year);




int main() 
{
	cout << "	CALENDAR";
	cout << "\n\n	Input dd/mm/yyyy\n";

	int day, month, year;
	cout << "	date: ";
	cin >> day;
	cout << "	month: ";
	cin >> month;
	cout << "	year: ";
	cin >> year;
	int n;

//kiem tra ngay nhap vao co dung quy tac ko
	while (year < 0 || month < 0 || month>12 || day<0 || day>DayInMonth(month, year)) 
	{
		cout << "	Invalid Date\n";
		cout << "	date: ";
		cin >> day;
		cout << "	month: ";
		cin >> month;
		cout << "	year: ";
		cin >> year;
	}

//menu chon
	do
	{
		cout << "	\n	================MENU================\n";
		cout << "	1.Find the number of month\n";
		cout << "	2.Show next day (dd/mm/yyyy)\n";
		cout << "	3.Show previous day (dd/mm/yyyy)\n";
		cout << "	Select your option: ";
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "	The number of month: " << DayInMonth(month,year); 
			break;
		case 2:
			cout << "	NextDay: ";
			NextDay(day, month, year);
			break;
		case 3:
			cout << "	PreviousDay: ";
			PreviousDay(day, month,year);
			break;
		default:
			cout << "	Invalid Choice ";
		}
	} while (1 <= n || n <= 4);
	 return 0;
}


//check nam nhuan
	bool isLeapYear(int year) 
	{
		if (year % 4 == 0 && year % 100 != 0)
			return true;
		if (year % 400 == 0)
			return true;
		return false;
	}



//Check ngay trong thang
	int DayInMonth(int month, int year) 
	{
		switch (month) 
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			if (isLeapYear(year))
				return 29;
			else
				return 28;
		default:
			break;
		}
		return 0;
	}



//Next day
	void NextDay(int day, int month, int year) 
	{
		day++;
			if (day > DayInMonth(month, year) )
			{
				day = 1;
				month ++;
					if (month > 12) 
					{
						month =1;
						year ++;
					}
			}
			cout << day << "/" << month << "/" << year << endl;
	}

//PreviosDay
	void PreviousDay(int day, int month, int year)
	{
		day--;
			if (day == 0)
			{
				month --;
				day = DayInMonth(month, year);
				if (month == 0)
				{
					month = 12;
					year--;
				}
					if (year == 0)
					{
						cout << "	invalid date!" << endl;
					}
			}
			cout << day << "/" << month << "/" << year << endl;
	}