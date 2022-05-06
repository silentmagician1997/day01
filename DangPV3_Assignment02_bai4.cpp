#include<iostream>
#include <limits>

using namespace std;

void InputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao phan tu a[" << i << "] : ";
        cin >> a[i];
    }
}

void OutputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout  << " " << a[i];
    }
}

int* get_even_num(int* arr, int* sz)
{
    for (size_t i = 0; i < sizeof(sz); i++)
    {
        if (arr[i] % 2 == 0)
        {
            cout << " " << arr[i];
        }
    }
    return 0;
}

int main() {
    int a[1000];
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    InputArray(a, n);
    OutputArray(a, n);

    cout << "\nCac phan tu chan: ";
    get_even_num(a, &n);
    return 0;
}
