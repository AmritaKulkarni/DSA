#ifndef _STACKCLASS_
#define _STACKCLASS_

#include <iostream>

using namespace std;


class Stack
{
    int maxSize = 10;
    int top = -1;
    int* arr;

public:
    Stack(int size)
    {
        maxSize = size;
        arr = new int[maxSize];
    }

    void push(int x)
    {
        if(isFull())
        {
            cout << "Stack is full!" << endl;
        }
        else
        {
            arr[++top] = x;

        }
        return;
    }

    int pop()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty!" << endl;
           return -1;
        }
        else
        {
            return arr[top--];
        }
    }

    bool isEmpty()
    {
        return(top == -1);
    }

    bool isFull()
    {
        return(top == (maxSize-1));
    }

    void printStack()
    {
        cout << "STACK: " << endl;
        for(int i=0;i<maxSize;i++)
        {
            cout << arr[i] << endl;
        }
    }

    ~Stack()
    {
        delete[] arr;
        arr = nullptr;
    }
};

#endif // _STACKCLASS_
