#ifndef _STACKCLASSDYN_
#define _STACKCLASSDYN_

#include <iostream>

using namespace std;


class StackDyn
{
    int maxCapacity = 500;
    int cap = 10;
    int top = -1;
    int lf = 75;
    int thresh = 7;
    int* arr;
    int* arr_new;

public:
    StackDyn(int initialCapacity, int loadfactor)
    {
        cap = initialCapacity;
        lf = loadfactor;
        thresh = (lf/100.0) * cap;
        arr = new int[cap];
        arr_new = arr;
        cout << "Dynamic stack constructed with threshold : " << thresh << endl;
    }

    void checkThreshold()
    {
        if(top==thresh-1)
        {
            cout << "Threshold : " << thresh << " reached!!" << endl; // time to double the capacity
            cap = cap*2;
            thresh = (lf/100.0) * cap;

            arr_new = new int[cap];
            for(int i=0; i<=top; i++) // move the old stack to new location with double capacity
            {
                arr_new[i] = arr[i];
            }
            delete[] arr; // deallocate old memory
            arr = arr_new;

            cout << "created a new stack with capacity : " << cap << endl;
            cout << "New thresh  : " << thresh << endl;
        }
    }

    void push(int x)
    {
        if(isFull())
        {
            cout << "Stack is full!" << endl;
        }
        else
        {
            checkThreshold(); // check if capacity is exceeded

            arr[++top] = x;

            cout << "pushed : " << x << "  at : " << top << endl;
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
        return(top == (maxCapacity-1));
    }

    void printStack()
    {
        cout << "STACK: " << endl;
        for(int i=0;i<cap;i++)
        {
            cout << arr[i] << endl;
        }
    }

    ~StackDyn()
    {
        delete[] arr;
        arr = nullptr;
        arr_new = nullptr;
    }
};

#endif // _STACKCLASS_

