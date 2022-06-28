#include "Header.h"
#include <iostream>

using namespace std;


/************************************
*Function: Check stack is full or not
*Return  : true if stack is full
*          false if stack is not full
************************************/
bool CStack::IsFull()
{
    if (top >= MAX_SIZE - 1) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}

/************************************
*Function: Check stack is empty or not
*Return  : true if stack is full
*          false if stack is not full
************************************/
bool CStack::IsEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

/************************************
*Function: Push data into stack
*Return  : void
************************************/
void CStack::Push(int x)
{
    if (IsFull() == true)
    {
        cout << "Stack overflow\n";
    }
    else
    {
        cout << "Insert data: " << x << endl;
        ++top;
        stack[top] = x;
    }
}

/************************************
*Function: Pop data out of stack
*Return  : The top element of the stack
************************************/
int CStack::Pop() {
    if (IsEmpty() == true) {
        cout << "Stack is empty\n";
    }
    else {
        --top;
        return stack[top];
    }
}

/***************************************
*Function: show all of elements of stack
*Return  : void
***************************************/
void CStack::Show()
{
    for (int i = 0; i < (top+1); i++)
    {
        cout << "s[" << i << "] = " << stack[i] << "\n";
    }
}

int main()
{
    CStack stack;

    cout << "push data to stack: \n";
    stack.Push(123);
    stack.Push(45);
    stack.Push(67);
    stack.Push(89);
    stack.Show();

    cout << "current stack after pop: \n";
    stack.Pop();
    stack.Show();
}