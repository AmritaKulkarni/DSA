#define DO_THIS
#ifdef DO_THIS

/*
Q: Implement a dynamic stack where user gives the Initial Capacity (IC) and Load Factor (LF)
A:
*/


#include <iostream>
#include "StackClassDyn.h"

using namespace std;

int main()
{
    int x = (60/100.0)*18;
    cout << x << endl;
    StackDyn s(9,60);

    for(int i=1; i<15; i++)
    {
        s.push(i*11);
    }

    s.printStack();

}


#endif
