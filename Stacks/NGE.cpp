#define DO_THIS
#ifdef DO_THIS

/*
Q: Find the next greatest element
A: Use a stack to store the elements whose NGE is to be found.
   Keep comparing the next element with elements in the stack
*/


#include <iostream>
#include "StackClass.h"

using namespace std;

void printNGE(int* a, int size)
{
    Stack s(size);
    s.push(a[0]);
    int top;

    for(int i=1;i<size;i++)
    {

        if(a[i] < s.peep() || s.isEmpty())
        {
            s.push(a[i]); // a[i] is not the NGE to the top element. Hence push it on stack
        }
        else
        {
            top = s.peep();
            while(a[i] > top && !s.isEmpty())
            {

                cout << top <<  " --> " << a[i] << endl; //a[i] which is the next element is the NGE to the top element.
                s.pop();
                top = s.peep();
            }
            s.push(a[i]); // push the next element on stack as its NGE is yet to be found
        }
    }

    while(!s.isEmpty()) // All the elements left in the stack do not have NGEs
    {
        cout << s.pop() << " --> " << "-1" << endl;
    }
}

int main()
{
    int arr[] = {16,11,9,10,22,4,55,6};
    int size = sizeof(arr)/sizeof(arr[0]);

    printNGE(arr,size);
    return 0;
}

#endif
