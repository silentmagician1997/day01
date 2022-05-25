#include <iostream>

#include<string.h>

using namespace std;

class String
{
public:
	char* str;
	friend String operator + (const String&, const String&);
	friend ostream& operator << (ostream&, String&);  
	friend istream& operator >> (istream&, String&);    

};

/*input string
*@ date: 20220524
*@ funtion   : istream& operator
*@ param : istream& is , String& str
*@ return is
*/
istream& operator >> (istream& is , String& str)
{
	
	str.str = new char[100];
	memset(str.str, 0x00, 100);
	is.getline(str.str, 100);
	//is >> str.str;                      // Để kiểu này thì ko đọc đc kí tự " " //

	return is;
};

/*output string to console screen
*@ date: 20220524
*@ funtion   : ostream& operator
*@ param : ostream& out, String& str
*@ return out
*/
ostream& operator<<(ostream& out, String& str)
{
	
	out << str.str;
	return out;
}

/*overload string1
*@ date: 20220524
*@ funtion   : operator +
*@ param : const String& string1, const String& string2
*@ return string1
*/
String operator + (const String& string1, const String& string2)
{

	char i, j;

	for (i = 0; string1.str[i] != '\0'; i++);
	for (j = 0; string2.str[j] != '\0'; ++j, ++i)
	{
		string1.str[i] = string2.str[j];
	}

//	strcat(string1.str, string2.str);        //	Error	C4996	'strcat': This function or variable may be unsafe//


	return string1;
}
int main()
{
	String string1, string2, addstring;
	cout << "String 1: ";
	cin >> string1;
	cout << "String 2: ";
	cin >> string2;

	addstring = string1 + string2;
	cout << "String1 after overloading: " << addstring;
	return 0;

}
