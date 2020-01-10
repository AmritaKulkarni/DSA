/*
Q: Find and print (once) duplicates in a given array 0 to n
A: Mark the visited element with a negative sign
   If the current element is already visited, duplicate of the index exists
*/


#include <iostream>
#include <cstdlib> //for abs() function
using namespace std;

void printArray(int array[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

void printduplicates(int data[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        int pos = abs(data[i]);
        if (data[pos] < 0) //number already seen as it has been marked negative
        {
            cout << "Duplicated Array element : " << abs(data[pos]) << endl;
        }
        data[pos] = data[pos]* (-1); //negate the number to mark it as seen


        cout << "-----------------------------------------" << endl;
        cout << "pos: " << pos << endl;
        cout << "Array : " ;
       printArray(data,  size);
        cout << "-----------------------------------------" << endl;
    }
}

int main()
{
    int data[] = {1,2,2,4,5,6,7,7,8,8,8,9};
    int n = sizeof(data) / sizeof(data[0]);

    printduplicates(data, n);

    return 0;
}
