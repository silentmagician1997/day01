#pragma once

#define MAX_SIZE 100

class CStack
{
private:
    int stack[MAX_SIZE];
    int size=0;

public:

    bool IsFull();
    void Push(int x);
    bool IsEmpty();
    int Pop();
    
    void Show();
    int top = -1;
};
