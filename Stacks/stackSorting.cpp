//#define DO_THIS
#ifdef DO_THIS

/*
Q: Sort a stack using recursion
A: Pop all stack elements recursively on to the call stack. Then push each one back on to the original stack
   while first taking care of emptying the already existing elements on to the call stack recursively. While doing
   the push each time, compare with existing element to achieve sorting
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

    if(item>y)
    {
       int temp = s.pop();
       s.push(y);
       s.push(temp);
    }
    else
    {
      s.push(y);
    }
    //s.push(y);
}

void sortStack(Stack& s)
{
    if(s.isEmpty())
    {
        return;
    }
    int x = s.pop();

    sortStack(s);

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

    sortStack(s);

    s.printStack();

}
#endif
