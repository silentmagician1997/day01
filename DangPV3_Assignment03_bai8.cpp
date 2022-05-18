#include <iostream>
using namespace std;


/*--------------------------------------------------------------------------*/
/*		Find sub string in parent string					            	*/
/*--------------------------------------------------------------------------*/
/*
* @date :   20220517
* @Param:   str: parent string
            sub: sub string
* @Return:  The first sub string output location in string str: or return -1 if not found sub string
*/
int findsubstr(const char* str, char* sub)
{
	const char* p = str;

    if (p = strstr(str, sub))
    {
        return (p - str);
    }
    else
    {
        return -1;
    }

}

int main()

{
	const char *str = "parent string one two three abc";
    cout << "parent string: " << str << endl;

	char sub[100];
	cout << "sub string:\n";
	cin >> sub;

    cout << "the first sub string output location in string str: " << findsubstr(str, sub);
    return 0;
}



