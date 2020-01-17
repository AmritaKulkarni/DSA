//#define DO_THIS
#ifdef DO_THIS

/*
Q: Reverse a stack using recursion
A: Pop all stack elements recursively on to the call stack. Then push each one back on to the original stack
   while first taking care of emptying the already existing elements on to the call stack recursively
*/


#include <iostream>
#include "StackClass.h"

using namespace std;



void insertItem(Stack& s, int item)
{
    if(s.isEmpty())
    {
        s.push(item);
        return;
    }

    int y = s.pop();
    insertItem(s,item);
    s.push(y);
}

void reverseStack(Stack& s)
{
    if(s.isEmpty())
    {
        return;
    }
    int x = s.pop();

    reverseStack(s);

    insertItem(s,x);

}


int main()
{
    Stack s(10);

    s.push(123);
    s.push(8);
    s.push(19);
    s.push(654);
    s.push(987);
    s.push(66);
    s.push(6);
    s.push(33);
    s.push(65);
    s.push(99);

    s.printStack();

    reverseStack(s);

    s.printStack();

}
#endif
