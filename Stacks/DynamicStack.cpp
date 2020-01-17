#define DO_THIS
#ifdef DO_THIS

/*
Q: Implement a dynamic stack where user gives the Initial Capacity (IC) and Load Factor (LF)
A: Calculate the threshold of the stack using LF and Capacity. Once the pushed element order exceeds this threshold,
   double the capacity and calculate the new threshold based on this.
*/


#include <iostream>
#include "StackClassDyn.h"

using namespace std;

int main()
{

    int ic = 9; // initial capacity of stack is 9
    int lf = 60; // load factor is 60%
    StackDyn s(ic,lf);

    for(int i=1; i<15; i++)
    {
        s.push(i*11);
    }

    s.printStack();

}


#endif
